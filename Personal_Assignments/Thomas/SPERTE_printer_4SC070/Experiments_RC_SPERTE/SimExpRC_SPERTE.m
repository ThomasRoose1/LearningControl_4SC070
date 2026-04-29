%SimExpRC_SPERTE   Repetitive Control simulations & experiments.
clearvars -except p
close all; clc;

% if SPERTE_Ping_Target('Verbose', false)
%     p = SPERTE_Find_Pi;
% else
%     errordlg("Pi is not reachable! check your connection and try again!");
%     return;
% end

%% RC settings
N_trial = 10;       % number of disturbance periods. Max 20
N_RC_activate = 5;  % RC is activated after N_RC_activate periods

method = 'simulation';      % select 'simulation' or 'experiment'
% method = 'experiment';

%Load trajectory
load('trajectory_RC.mat');
N = length(r);    % period time [samples]

% %Plot reference
% figure;
% plot(repmat(r,N_trial,1));xlabel('sample');ylabel('r [m]')

% Save settings for RC simulations/experiments
save('Exp_RC_settings.mat','r','N','N_trial','N_RC_activate');

%% Run RC
   
switch lower(method)
    case 'simulation'
        % Start simulation.
        sim('PrinterRC_SIM');
        
        % Load and extract trial data.
        load('expdata.dat');
    case 'experiment'
        % Check connection to the Pi
        disp('Connecting to the Raspberry Pi target...');
        
        p = SPERTE_Find_Pi;

        
        % Load controllers
        load('Exp_RC_settings.mat');
        
        % Set the reference
        modelname = 'SPERTE_printer_RC';
        if (~bdIsLoaded(modelname))
            load_system(modelname);
        end

        BlockPaths = find_system(modelname);
        Index_ref = find(contains(BlockPaths,'set_Ref'));
        simulink_set_constant(BlockPaths{Index_ref},r);

        % Start experiment. 
        % If Simulink displays 'Failed to run the model on hardware.', then
        % run SPERTE_Restart, wait 60 seconds, reopen MATLAB and rerun this script.
        disp('Starting the model...');

        set_param(modelname, 'SimulationMode', 'external');
        set_param(modelname, 'SimulationCommand', 'start');

        disp('Waiting for the measurement to finish...');
        pause(N*N_trial*Ts);

        % Wait while the model is running
        while ~is_model_stopped(modelname); pause(0.1); end

        if ~check_target_connection(p)
            clear('p');
            p = SPERTE_Find_Pi;
        end
       
        % Load and extract trial data.
        databin = SPERTE_Get_Latest_Measurement(p,'bin',1,'measurements');
        expdata = SPERTE_Bin_To_Mat(databin,4,false,'single');
        
    otherwise
        error('incorrect method assigned!')
end

t = expdata(:,1);
w = expdata(:,2);
e = expdata(:,3);
u = expdata(:,4);

r_extend=repmat(r,N_trial,1);
y = r_extend-e;

if ~exist('C','var')
    % Feedback controller.
    load('PrinterController.mat');
    C = minreal(shapeit_data.C_tf_z);
end
u_RC = lsim(C,w,t);

%% Plot results.
t_j = t(1:N);

% Plot data of trials
clear PlotInit norm_e_j trialVec
for j = 1:N_trial
    PlotTrialData_RC;
    pause(0.5)
end

% Plot PSDs before/after RC
for j=1:2
    N_PSD=N_RC_activate-1;    % number of periods over which PSD is computed
    t_j = t(1:N_PSD*N);
    r_j = r_extend(1:N_PSD*N);
    if j == 1
        % no RC
        y_j = y(N*(N_RC_activate-N_PSD)+1:N*N_RC_activate);
    else
        % with RC
        y_j = y(N*(N_trial-N_PSD)+1:N*N_trial);
    end
    plot_PSD(t_j,r_j,y_j,j-1,3);
end

%% Helper functions
function stopped = is_model_stopped(modelname)
    stopped = strcmp(get_param(modelname, 'SimulationStatus'), 'stopped');
end

function result = check_target_connection(p)
    result = false;

    if ~isa(p,'raspi')
        warning("Invalid connection object!");
        return;
    end

    if(~SPERTE_Ping_Target(p.DeviceAddress, 'Verbose', false))
        error("Raspberry Pi target is not reachable!");
    end
    
    if (~strcmp(strip(system(p, 'echo ok')), 'ok'))
        warning("Stale connection object!");
        return;
    end
    
    result = true;
end
