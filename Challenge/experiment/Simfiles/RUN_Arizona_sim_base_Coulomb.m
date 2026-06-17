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
addpath(genpath('./Simulink'))
addpath(genpath('../Target_interfacing'))
addpath(genpath('../Build'))
addpath(genpath('../Utility_functions'))
addpath(genpath('../ILC_updates'))
%% Parameters and settings
Ts = get_Arizona_pars();
N_trials = 15; % 1,...,N_trial
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
cd ..
load("References\Reference_X_slow.mat")
% load("References\small_step_slow_2_1.mat")
% xref = xref_pos;
cd Simfiles
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

% Interconnection.
% Process sensitivity
SPy = minreal(feedback(Py, Cy));
SPx = minreal(feedback(Px, Cx));
SPphi = minreal(feedback(Pphi, Cphi));

% Sensitivity
Sy = minreal(feedback(1, Py*Cy));
Sx = minreal(feedback(1, Px*Cx));
   
% Stack for MIMO, add 0.25 to mirror real setup
C_zpk = 0.25 * blkdiag(Cy, Cx, Cphi);
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
    na = 3;  % Order input shaper Cy
    nb = 3;  % Order feedforward Cff
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
    we = 1;                                                                     
    wf = 1e-12;   % Lowered so the optimizer is allowed to use feedforward
    wdf = 1e-14;  % Keeps the high-frequency derivatives smooth
    wry = 1e-4;
    wdry = 1e-4;
    % Construct diagonal weighting filters
    We = we*eye(N); We_sq = sqrt(We);                                           % Penelizes tracking error
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
    f_j = squeeze(history.f(jj,:,:));
    r_j = squeeze(history.r_y(jj,:,:));  
        
    % Execute trial.
    if ~isfolder('..\Build')
        mkdir('..\Build');
    end
    cd('..\Build') % To make sure sjlpr etc. end up in that folder
    sim('Arizona_sim_base.slx')
    cd('..\Simfiles')
    
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
        r_jplus1 = r_j; % Reference is trial-invariant here

        if strcmp(optFFmethod, 'ILC_BF_IS')
            % Identify active channel dynamically inside the loop execution
            active_ch = find(optFFdirections == 1, 1);
            
            % Extract CURRENT trial data for the active channel strictly as 1D vectors
            e_y_active = squeeze(history.e(jj, :, active_ch))'; 
            r_y_active = squeeze(history.r_y(jj, :, active_ch))';
            f_active   = squeeze(history.f(jj, :, active_ch))';
            r_active   = squeeze(history.r(jj, :, active_ch))';
            
            % Call the update function passing the specific diagonal terms of the MIMO system
            [theta_delta, Phi, Psi_y_r, Psi_ff_r] = FeedforwardUpdate_ILC_BFIS_Coulomb(na, nb, Psi, Nref, ...
                Sx, SPx, ...
                We_sq, Wry_sq, Wdry_sq, Wf_sq, Wdf_sq, ...
                e_y_active, r_y_active, f_active, r_active, t, Ts, coulomb, v_eps);
           

            % seperate Phi matrix into input shaper and ff
            % Phi_y = Phi(:,1:na);
            % Phi_ff = Phi(:,na+1:end);

            % theta update
            theta_ch = theta_j*optFFdirections' + theta_delta;
            theta_j(:,active_ch) = theta_ch; 

            theta_y = theta_ch(1:na);
            theta_ff = theta_ch(na+1:end);

            r_y_jplus1 = r_j;
            if polynomial
                % set IS terms of theta to 0
                theta_y(1:na) = zeros(na,1);   
            else
                % update IS x
                Cy = minreal(1 + Psi_y*theta_y);
                r_y_jplus1(:,active_ch) = brfus_v003(Cy,r_active,t,Ts);
                % r_y_jplus1_x =  r_active + Psi_y_r_x*theta_y_x;  
                %r_y_jplus1(:,active_ch) = r_y_jplus1;
            end            
            
            Cff = minreal(Psi_ff*theta_ff);     
            f_jplus1_ch = brfus_v003(Cff,r_active,t,Ts);   
            f_jplus1 = zeros(Nref, 3);
            f_jplus1(:, active_ch) = f_jplus1_ch;
        end


        %%       
        % Store in FFW
        history.r(jj+1,:,:) = r_jplus1;
        history.r_y(jj+1,:,:) = r_y_jplus1;
        history.f(jj+1,:,:) = f_jplus1;
        
        PlotTrialDataContour(history,jj,0,0,0,1,0,0,1); % Plots new ffw
    end
end