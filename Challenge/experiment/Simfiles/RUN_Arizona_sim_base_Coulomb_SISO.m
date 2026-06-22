%% Description
%RUN_Arizona_sim_base   
% Simulation equivalent of minimum working example for working with Arizona. 
%
% Author: Johan Kon
% Date:   April 2021
%

%%
clear variables; close all; clc;
%% Paths
addpath(genpath('../Controllers'))
addpath(genpath('../Helper_functions'))
addpath(genpath('../Models'))
addpath(genpath('../Pars'))
addpath(genpath('../Plotter_functions'))
addpath(genpath('../Reference_generators'))
addpath(genpath('../References'))
addpath(genpath('./Simulink'))
addpath(genpath('../Target_interfacing'))
addpath(genpath('../Build'))
addpath(genpath('../Utility_functions'))
addpath(genpath('../ILC_updates'))
% addpath(genpath('../References'))
%% Parameters and settings
Ts = get_Arizona_pars();
N_trials = 40; % 1,...,N_trial
Ts = 0.001; % sampling time                                                    
optFFmethod           = 'ILC_BF_IS';  
BadControllers        = true;
% optFFmethod           = 'ILC';  
optFFdirections       = [0,1,0];    

%% Generate reference
% [xref, yref, phiref, t] = reference_square(Ts);
%[xref, yref, phiref, t] = reference_triangle(Ts);
% [xref, yref, phiref, t] = reference_rounded_rectangle(Ts);
% load('test_reference.mat')

% cd /Users/teunwijfjes/Downloads/experiment
load("Reference_X_slow.mat")

% load("References\small_step_slow_2_1.mat")
% xref = xref_pos;
% cd Simfiles
N = 5/Ts;
[yref, xref, phiref, t] = pad_reference_to_N_zeros(yref, xref, phiref,N, Ts);
% xref = xr ef*0;
t = t';
% traj_number = 1;    
% % size_i = length(yRefs{traj_number});
% size_i = 1;   
% times = linspace(0,size_i/Ts,size_i)';
% xref = zeros(size_i,1);
% yref = yRefs{:,traj_number};
% phiref =zeros(size_i,1);
% t = times;

Nref = length(xref);
%% Load  loop system (after decoupling) and controllers
% y translation 
load('yController.mat')
load('yControllerBad.mat');
if BadControllers
    Cy = shapeit_data.C_tf_z;
else
    Cy = Cy_DT;
end
load('Py_fit.mat')
Py = Py_DT;

% x translation
load('xController.mat');
load('xControllerBad.mat');

if BadControllers
    Cx = shapeit_data.C_tf_z;
else
    Cx = Cx_DT;
end
load('Px_fit.mat')
Px = Px_DT;

% phi rotation
load('phiController.mat');
Cphi = Cphi_DT;
load('Pphi_fit.mat')
Pphi = Pphi_DT;

% MIMO plant
C_diag =  blkdiag(Cx, Cphi);
load('P_centralized.mat');
P_zpk = Pz; % needs 1/4?

% decoupling matrices
Tu = [0.5, -0.3817;
      0.5, 0.3817];
Ty = [0.5   0.5;
      -0.3817 0.3817];

Pdec = Ty*Pz*Tu;

Pdec_sim = Pdec;

% gain correction
Cy_cl   = 0.25 * Cy;
Cx_cl   = 0.25 * Cx;
Cphi_cl = 0.25 * Cphi;

% closed loop transfers
SPy   = minreal(feedback(Py, Cy_cl));
SPx   = minreal(feedback(Px, Cx_cl));
SPphi = minreal(feedback(Pphi, Cphi_cl));

Sy = minreal(feedback(1, Py*Cy_cl));
Sx = minreal(feedback(1, Px*Cx_cl));

C_zpk = blkdiag(Cy_cl, Cx_cl, Cphi_cl);
P_zpk = blkdiag(Py, Px, Pphi);

%% Interconnection.
[S,PS] = ClosedLoopTransfers(P_zpk,C_zpk);

Stf = tf(S); PStf = tf(PS);

% [A,B,C,D] = ssdata(SP);
% Number of states, inputs and outputs.
% [no,ni] = size(D);
ni = 3;
no = 3;

%% Initialization
% history struct. All communication and plotting done through this struct.
% Order is always [y x phi]!
history.eNorm = NaN(N_trials,no,1);
history.e = NaN(N_trials,Nref,no); % [Trial, time, dim]
history.epsilon = NaN(N_trials,Nref,1);
history.epsilonNorm = NaN(N_trials,1);
history.f = NaN(N_trials,Nref,ni); % [Trial, time, dim]
history.r = NaN(N_trials,Nref,no); % [Tial, time, dim]
history.r_y = NaN(N_trials,Nref,no);  
history.p = NaN(N_trials,Nref,no);
history.t = t;
history.trials = 1:N_trials;
history.Nref = Nref;

% Initial FFW and reference
history.r(1,:,:) = [yref, xref, phiref]; % Order [y x phi]
history.r_y(1,:,:) = history.r(1,:,:);
history.f(1,:,:) = zeros(Nref,ni);
PlotTrialDataContour(history,0,1,0,0,1,0,0,0); % Plots initial input
PlotTrialDataContour(history,1,0,0,0,0,1,0,0); % Plots reference

%% ILC startup initialization: your code here!
% ========================================================================
% Pre-computations for ILC-BFIS (if required)
% you might want to expand the history struct with more variables
% =========================================================================
if strcmp(optFFmethod, 'ILC_BF_IS')
    polynomial = 0;                                                         % Select 1 for input shaper off
    % order of FF and IS filters
    na = 1;  % Order input shaper Cy
    nb = 2;  % Order feedforward Cff
    nc = 0;
    
    % Select if coulomb should be used
    coulomb = false;
    % Define the 'include_friction' struct
    include_friction = struct();
    include_friction.input_shaper = false; % Turn off friction for input shaper
    include_friction.feedforward  = false;  % Turn on friction for feedforward path

    alpha = 1;
    v_eps = 1e-4; 
    if coulomb
        nc = 1;
    end
    theta_j = zeros(na+nb+nc,3);


    % add na zeros in direction vector
    direction = zeros(na+nb);

    % Weighting parameters (diagonal weighting)
    % we = 1;                                                                     
    % wf = 0*1e-14;
    % wdf = 0*1e-16;
    % wry = 1e-4;
    % wdry = 1*1e-2;
    % we = 1;                                                                     
    % wf   = 1e-9;
    % wdf  = 1e-8;
    % wry  = 1e-5;
    % wdry = 1e-6;

    we = 1;                                                                     
    wf = 1e-7;   % Lowered so the optimizer is allowed to use feedforward
    wdf = 1e-6;  % Keeps the high-frequency derivatives smooth
    wry = 1e-5;
    wdry = 1e-6;

    % Construct diagonal weighting filters
    We = we*eye(N); We_sq = sqrt(We);                                           % Penalizes tracking error
    Wf = wf*eye(N); Wf_sq = sqrt(Wf);                                           % Penalizes feedforward force/input
    Wdf = wdf*eye(N); Wdf_sq = sqrt(Wdf);                                       % Penalizes change/derivative of feedforward
    Wry = wry*eye(N); Wry_sq = sqrt(Wry);                                       % Penalizes shaped reference ry
    Wdry = wdry*eye(N); Wdry_sq = sqrt(Wdry);                                   % Penalizes derivative of shaped reference 
    % Define the 'weights' struct
    % Frequently, these are diagonal penalty matrices (identity scaled by a scalar)
    weights = struct();
    weights.We   = We_sq;  % High penalty on tracking error
    weights.W_ry  = Wry_sq; % Penalty on shaper command magnitude
    weights.W_dry = Wdry_sq; % Penalty on shaper update rate
    weights.W_f   = Wf_sq ; % Penalty on feedforward force magnitude
    weights.W_df  = Wdf_sq; % Penalty on feedforward update rate

    % Parameterize feedforward Cff
    Psi_ff = tf(zeros(1,nb));
    for i = 1:nb
        num = zeros(1,i+1);
        for k = 0:i
            num(k+1) = (-1)^k * nchoosek(i,k);                                  % derivative basis function, i.e., (1-z^-1)/Ts . Feel free to play with the basis functions.
        end
        Psi_ff(i) = minreal(tf(num,Ts^i,Ts,'Variable','z^-1'));
    end

    % Parameterize input shaper Cy
    Psi_y = tf(zeros(1,na));
    for i = 1:na
        num = zeros(1,i+1);
        for k = 0:i
            num(k+1) = (-1)^k * nchoosek(i,k);                                  % derivative basis function, i.e., (1-z^-1)/Ts . Feel free to play with the basis functions.
        end
        Psi_y(i) = minreal(tf(num,Ts^i,Ts,'Variable','z^-1'));
    end
    
    Psi = minreal([Psi_y, Psi_ff]);
                    
end

% Adaptive learning-gain settings
learning_gain     = 0.4;
learning_gain_min = 0.05;
gain_down         = 0.5;

best_e_norm    = Inf;
best_trial     = NaN;
best_theta_j   = theta_j;
best_f_active  = [];
best_ry_active = [];

no_improve_count = 0;
patience = 4;

% Previous measured trial error
prev_e_norm = Inf;

    %% Execute trials
for jj = 1:N_trials
        % Display trial number.
        fprintf(['Trial %',num2str(numel(num2str(N_trials-1))),'d/%d finished.\n'],jj,N_trials);
        
        % Check ffw
        % Not necessary in simulation. Can be uncommented to see what's
        % happening
    %     fprintf('Waiting for key press.\n')
    %     pause;
        
        % Increase trial in plot
        PlotTrialDataContour(history,jj,0,1,0,0,0,0,0);
        
        % Set reference and feedforward. Used like this in simulink, uses the
        % shaped ref
    
        %% Teun Code
        % Fixed base reference and current shaped reference
        r_base_j = squeeze(history.r(jj,:,:));      % fixed, unshaped reference
        r_y_j    = squeeze(history.r_y(jj,:,:));    % shaped reference used by feedback
        f_j      = squeeze(history.f(jj,:,:));      % feedforward input
    
        % Simulink expects the shaped reference under the variable name r_j
        r_j = r_y_j;
                
        % Execute trial.
        if ~isfolder('..\Build')
            mkdir('..\Build');
        end
        cd('..\Build') % To make sure sjlpr etc. end up in that folder
        sim('Arizona_sim_base_MIMO.slx')
        
        % cd /Users/teunwijfjes/Downloads/experiment
        cd ../Simfiles
        
        [epsilon, epsilon_vec, refc] = estimate_contour_error(r_j(:,2), r_j(:,1), y_j(:,2), y_j(:,1), 2000, 1);
    
        % Store position and error corresponding to reference and ffw
        history.p(jj,:,:)       = y_j;
        history.e(jj,:,:)       = e_j;
        history.eNorm(jj,:,:)   = vecnorm(e_j);
        history.epsilon(jj,:)   = epsilon;
        history.epsilonNorm(jj) = vecnorm(epsilon);
        
        PlotTrialDataContour(history,jj,0,0,0,0,0,1,0); % Plots error and position
        
        % Select new reference and feedforward.
        if jj ~= N_trials
    
        % The base reference must stay fixed from trial to trial
        r_base_jplus1 = r_base_j;
    
        % Default: unshaped reference for all channels
        r_y_jplus1 = r_base_jplus1;
    
        % Default: no feedforward for all channels
        f_jplus1 = zeros(Nref, 3);
    
        if strcmp(optFFmethod, 'ILC_BF_IS')
    
            active_ch = find(optFFdirections == 1, 1);
            r0_active = squeeze(history.r(1,:,active_ch));
            rj_active = squeeze(history.r(jj,:,active_ch));
            
            fprintf('Trial %d base-reference drift: %.4e\n', ...
                jj, norm(rj_active(:) - r0_active(:)));
    
            % Extract signals as column vectors
            y_active   = squeeze(history.p(jj, :, active_ch));   y_active   = y_active(:);
            r_y_active = squeeze(history.r_y(jj, :, active_ch)); r_y_active = r_y_active(:);
            f_active   = squeeze(history.f(jj, :, active_ch));   f_active   = f_active(:);
            r_active   = squeeze(history.r(jj, :, active_ch));   r_active   = r_active(:);
    
            % error w.r.t. shaped reference
            e_y_active = r_y_active - y_active;
    
            [theta_delta, Phi, Psi_y_r, Psi_ff_r] = FeedforwardUpdate_ILC_BFIS_Teun( ...
                na, nb, Psi, Nref, ...
                S(active_ch, active_ch), PS(active_ch, active_ch), ...
                We_sq, Wry_sq, Wdry_sq, Wf_sq, Wdf_sq, ...
                e_y_active, r_y_active, f_active, r_active, t, Ts);

    
            % Parameter update
            theta_ch = theta_j(:, active_ch) + theta_delta;
            theta_j(:, active_ch) = theta_ch;
        
            theta_y  = theta_ch(1:na);
            theta_ff = theta_ch(na+1:end);
        
            % Use the fixed base reference, not the previous shaped reference
            r_base_active = r_base_jplus1(:, active_ch);
        
            if polynomial
                r_y_jplus1(:, active_ch) = r_base_active;
            else
                Cshaper = minreal(1 + Psi_y * theta_y);
                r_y_jplus1(:, active_ch) = brfus_v003(Cshaper, r_base_active, t, Ts);
            end
        
            Cff = minreal(Psi_ff * theta_ff);
            f_jplus1(:, active_ch) = brfus_v003(Cff, r_base_active, t, Ts);
        end
    
        % Store fixed reference, shaped reference, and feedforward
        history.r(jj+1,:,:)   = r_base_jplus1;
        history.r_y(jj+1,:,:) = r_y_jplus1;
        history.f(jj+1,:,:)   = f_jplus1;
    
        PlotTrialDataContour(history,jj,0,0,0,1,0,0,1);
    end
end
