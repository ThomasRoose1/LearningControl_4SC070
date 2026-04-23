%SIMILC   Iterative Learning Control simulations.
clearvars -except p Fs Ts tsim
close all; clc;
Ts = 1/1000;

% Number of trials.
N_trial = 10;

% Load trajectory.
load('trajectory.mat');
t = t_ref; r.p = x_ref; r.v = v_ref; r.a = a_ref;
r.j = [ 0 ; diff(r.a)/Ts ];
r.s = [ 0 ; diff(r.j)/Ts ];
r.p( r.p<1e-15 )=0; % make low values equal to zero
N = length(t);

% Initial feedforward.
f_jplus1 = zeros(N,1);

% Initialize plotting.
PlotTrialData;

% Initialize storage variables.
history.f     = NaN(N,N_trial);
history.u     = NaN(N,N_trial);
history.e     = NaN(N,N_trial);
history.eNorm = NaN(1,N_trial);

%%%%%%%%%%%%%
% Start ILC %
%%%%%%%%%%%%%
for trial = 1:N_trial
    rng(trial);
    
    % Update index.
    f_j = f_jplus1;
    
    loaddata = [f_j, r.p];
    fp = fopen('loaddata.dat','w');
    fprintf(fp,'%25.18f\t%25.18f\n',loaddata.');
    fclose(fp);
    
    % Start simulation.
    sim('PrinterILC_sim');
    
    % Display trial number.
    fprintf('Experiment nr. %d/%d finished.\n',trial,N_trial);
    
    % Load and extract trial data.
    load('expdata.dat');
    
    e_j = expdata(:,3);
    u_j = expdata(:,4);
    
    % Store trial data.
    history.f(:,trial)     = f_j;
    history.u(:,trial)     = u_j;
    history.e(:,trial)     = e_j;
    history.eNorm(:,trial) = norm(e_j,2);
    
    % Calculate new feedforward.
    f_jplus1 = feedforwardUpdate(t,r,e_j,u_j,f_j);
    
    % Plot results.
    PlotTrialData;
    
end

% End.
disp('Done!');