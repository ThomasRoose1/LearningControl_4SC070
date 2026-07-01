%% Simulation code for Arizona flatbed printer ILC SISO control
% Based on provided code by Johan Kon
%%
clear variables; close all; clc;
%% Paths
addpath(genpath('../Controllers'))
addpath(genpath('../Helper_functions'))
addpath(genpath('../Models'))
addpath(genpath('../Models_new/Models/Parametric'))
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
N_trials = 60; % 1,...,N_trial
Ts = 0.001; % sampling time                                                    
optFFmethod           = 'ILC_BF_IS';  
BadControllers        = true;
% optFFmethod           = 'ILC';  
optFFdirections       = [1,0];    % [x, phi]



%% Generate reference
cd ..
load("References\Reference_X_slow.mat")
% load("References\small_step_slow_2_1.mat")
% load('Ref_19_6_05sec_v2.mat');
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
% Pdec_sim.D = zeros(2,2);

%% Interconnection.
[S,PS] = ClosedLoopTransfers(Pdec,C_diag);
L = C_diag*Pdec;

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
    polynomial = 1;                                                         % Select 1 for input shaper off
    % order of FF and IS filters
    na_x = 0;  % Order input shaper Cy
    na_phi = 0;
    nb_x = 2;  % Order feedforward Cff
    nb_phi = 2;

    % stack em
    na_vec = [na_x; na_phi];
    nb_vec = [nb_x; nb_phi];

    % dimensions
    n_in = 2;
    n_out = 2;

    % temp
    use_coulomb_basis     = false;
    v_eps = 0;

    % init theta
    theta_j_x = zeros(na_x+nb_x, 1);
    theta_j_phi = zeros(na_phi+nb_phi, 1);

    % Weighting parameters (diagonal weighting)
    we_x = 2;                                                                     
    wf_x = 1e-10;   % Lowered so the optimizer is allowed to use feedforward
    wdf_x = 1e-6;  % Keeps the high-frequency derivatives smooth
    wry_x = 1e-15;
    wdry_x = 1e-20;
    % phi weights
    we_phi = 1;                                                                     
    wf_phi = 1e-20;   % Lowered so the optimizer is allowed to use feedforward
    wdf_phi = 1e-15;  % Keeps the high-frequency derivatives smooth
    wry_phi = 1e-4;
    wdry_phi = 1e-4;

    % Construct diagonal weighting filters
    We = blkdiag(we_x*eye(Nref), we_phi*eye(Nref));   We_sq = sqrt(We);                                           % Penelizes tracking error
    Wf = blkdiag(wf_x*eye(Nref), wf_phi*eye(Nref));   Wf_sq = sqrt(Wf);                                           % Penalizes feedforward force/input
    Wdf = blkdiag(wdf_x*eye(Nref), wdf_phi*eye(Nref));   Wdf_sq = sqrt(Wdf);                                      % Penalizes change/derivative of feedforward
    Wry = blkdiag(wry_x*eye(Nref), wry_phi*eye(Nref));   Wry_sq = sqrt(Wry);                                      % Penalizes shaped reference ry
    Wdry = blkdiag(wdry_x*eye(Nref), wdry_phi*eye(Nref));   Wdry_sq = sqrt(Wdry);    

    % Parameterize feedforward Cff x
    Psi_ff_x = tf(zeros(1,nb_x));
    for i = 1:nb_x
        num = zeros(1,i+1);
        for k = 0:i
            num(k+1) = (-1)^k * nchoosek(i,k);                                  % derivative basis function, i.e., (1-z^-1)/Ts . Feel free to play with the basis functions.
        end
        Psi_ff_x(i) = minreal(tf(num,Ts^i,Ts,'Variable','z^-1'));
    end
    % Parameterize input shaper Cy x
    Psi_y_x = tf(zeros(1,na_x));
    for i = 1:na_x
        num = zeros(1,i+1);
        for k = 0:i
            num(k+1) = (-1)^k * nchoosek(i,k);                                  % derivative basis function, i.e., (1-z^-1)/Ts . Feel free to play with the basis functions.
        end
        Psi_y_x(i) = minreal(tf(num,Ts^i,Ts,'Variable','z^-1'));
    end
    Psi_x = minreal([Psi_y_x, Psi_ff_x]);

    % Parameterize feedforward Cff phi
    Psi_ff_phi = tf(zeros(1,nb_phi));
    for i = 1:nb_phi
        num = zeros(1,i+1);
        for k = 0:i
            num(k+1) = (-1)^k * nchoosek(i,k);                                  % derivative basis function, i.e., (1-z^-1)/Ts . Feel free to play with the basis functions.
        end
        Psi_ff_phi(i) = minreal(tf(num,Ts^i,Ts,'Variable','z^-1'));
    end
    % Parameterize input shaper Cy phi
    Psi_y_phi = tf(zeros(1,na_phi));
    for i = 1:na_phi
        num = zeros(1,i+1);
        for k = 0:i
            num(k+1) = (-1)^k * nchoosek(i,k);                                  % derivative basis function, i.e., (1-z^-1)/Ts . Feel free to play with the basis functions.
        end
        Psi_y_phi(i) = minreal(tf(num,Ts^i,Ts,'Variable','z^-1'));
    end
    Psi_phi= minreal([Psi_y_phi, Psi_ff_phi]);

    % Build Psi block
    Psi_blocks = cell(n_in, 1);
    Psi_blocks{1} = Psi_x;
    Psi_blocks{2} = Psi_phi;                  
end

%% Execute trials
for jj = 1:N_trials
    % Display trial number.
    fprintf(['Trial %',num2str(numel(num2str(N_trials-1))),'d/%d finished.\n'],jj,N_trials);
    
    % Increase trial in plot
    PlotTrialDataContour(history,jj,0,1,0,0,0,0,0);
    
    % base reference and current shaped reference
    r_base_j = squeeze(history.r(jj,:,:));      % fixed, unshaped reference
    r_y_j    = squeeze(history.r_y(jj,:,:));    % shaped reference used by feedback
    f_j      = squeeze(history.f(jj,:,:));      % feedforward input

    % Simulink expects the shaped reference under the variable name r_j
    r_j = r_y_j;
        
    % Execute trial.
    cd('..\Build') % To make sure sjlpr etc. end up in that folder
    if ~isfolder('build')
        mkdir('build');
    end
    % sim('Arizona_sim_base.slx')
    sim('Arizona_sim_base_MIMO.slx')
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
        % r_jplus1 = squeeze(history.r(jj,:,:)); % set the ref same as previous ref

        % The base reference must stay fixed from trial to trial
        r_base_jplus1 = r_base_j;
    
        % Default: unshaped reference for all channels
        r_y_jplus1 = r_base_jplus1;
    
        % Default: no feedforward for all channels
        f_jplus1 = zeros(Nref, 3);
        
        if strcmp(optFFmethod, 'ILC')
            % Pass the entire MIMO closed-loop model, references, and error matrices
            f_next_raw = feedforwardUpdateSim(PS, t, r_j, e_j, f_j, Ts);
            
            % Enforce your active direction filter mask [0, 1, 0]
            % This zeros out any accidental learning bleeding into other axes
            f_jplus1 = f_next_raw .* optFFdirections; 

            % set next shaped ref as ref
            r_y_jplus1 = r_jplus1;
        end

        if strcmp(optFFmethod, 'ILC_BF_IS')
            % Identify active channel dynamically inside the loop execution
            active_ch = find(optFFdirections == 1, 1);
            
            % Extract CURRENT trial data for the active channel strictly as 1D vectors
            y_active = [squeeze(history.p(jj, :, 2))', squeeze(history.p(jj, :, 3))'];
            e_active = [squeeze(history.e(jj, :, 2))', squeeze(history.e(jj, :, 3))']; 
            r_y_active = [squeeze(history.r_y(jj, :, 2))', squeeze(history.r_y(jj, :, 3))'];
            f_active   = [squeeze(history.f(jj, :, 2))', squeeze(history.f(jj, :, 3))'];
            r_base_active   = [squeeze(history.r(jj, :, 2))', squeeze(history.r(jj, :, 3))'];
            
            % Compute erros w.r.t sh
            e_y_active =  r_y_active - y_active;

            % Call the update function passing the specific diagonal terms of the MIMO system
            [theta_delta, Phi, Psi_y_r, Psi_ff_r] = FeedforwardUpdate_ILC_BFIS_MIMO( ...
                    na_vec, nb_vec, Psi_blocks, Nref, S, PS, ...
                    We_sq, Wry_sq, Wdry_sq, Wf_sq, Wdf_sq, ...
                    e_y_active, r_y_active, f_active, r_base_active, t, Ts, ...
                    use_coulomb_basis, v_eps);

            %% update x
            %  theta update x
            theta_j_x = theta_j_x + theta_delta(1:(na_vec(1)+nb_vec(1)));

            % Seperate theta matrix into input shaper and ff in active ch
            % direction
            theta_y_x = theta_j_x(1:na_x);
            theta_ff_x = theta_j_x(na_x+1:end);

            % Seperate Psi into x part 
            Psi_y_r_x = Psi_y_r(1:N,1:na_x);
            Psi_ff_r_x = Psi_ff_r(1:N,1:nb_x);

            if polynomial
                % set IS terms of theta to 0
                theta_y_x(1:na_x) = zeros(na_x,1);   
            else
                % update IS x
                Cy_x = minreal(1 + Psi_y_x*theta_y_x);
                r_y_jplus1(:, 2) = brfus_v003(Cy_x, r_base_active(:,1), t, Ts);
            end

            % Cff_x = minreal(Psi_ff_r_x*theta_ff_x);                              % Construct feedforward
        
            % C = minreal(Cfb*Cy + Cff); 

            % ff update
            % f_jplus1_x = brfus_v003(Cff_x,r_active(:,1),t,Ts);                                        % f = Cff * r
            f_jplus1_x = Psi_ff_r_x*theta_ff_x;
            
            % Reconstruct the 3-axis MIMO f_jplus1 matrix [Nref x 3]
            f_jplus1 = zeros(Nref, ni);
            f_jplus1(:, 2) = f_jplus1_x; 

            %% update phi
            %  theta update phi
            theta_j_phi = theta_j_phi + theta_delta((na_vec(1)+nb_vec(1))+1:end);

            % Seperate theta matrix into input shaper and ff in active ch
            % direction
            theta_y_phi = theta_j_phi(1:na_phi);
            theta_ff_phi = theta_j_phi(na_phi+1:end);

            % Seperate Psi into phi part 
            Psi_y_r_phi = Psi_y_r(1:N,1:na_phi);
            Psi_ff_r_phi = Psi_ff_r(1:N,1:nb_phi);

            if polynomial
                % set IS terms of theta to 0
                theta_y_phi(1:na_phi) = zeros(na_phi,1);   
            else
                % update IS phi
                % Cy_phi = minreal(1 + Psi_y_phi*theta_y_phi);
                % r_y_jplus1_phi = brfus_v003(Cy_phi,r_active(:,2),t,Ts);
                % % r_y_jplus1_phi =  r_active(:,1) + Psi_y_r_phi*theta_y_phi;  
                % r_y_jplus1(:,3) = r_y_jplus1_phi;
            end

            % Cff_phi = minreal(Psi_ff_r_phi*theta_ff_phi);                              % Construct feedforward
        
            % C = minreal(Cfb*Cy + Cff); 

            % ff update
            % f_jplus1_phi = brfus_v003(Cff_phi,r_active(:,1),t,Ts);                                        % f = Cff * r
            f_jplus1_phi = Psi_ff_r_phi*theta_ff_phi;
            
            % Reconstruct the 3-axis MIMO f_jplus1 matrix [Nref x 3]
            f_jplus1(:, 3) = f_jplus1_phi; 
        end
        
        %%       
        % Store in FFW
        history.r(jj+1,:,:)   = r_base_jplus1;
        history.r_y(jj+1,:,:) = r_y_jplus1;
        history.f(jj+1,:,:)   = f_jplus1;
        
        PlotTrialDataContour(history,jj,0,0,0,1,0,0,1); % Plots new ffw
    end
end