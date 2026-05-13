%FEEDFORWARDUPDATE   Compute feedforward signal for next trial.
function f_jplus1 = feedforwardUpdate(t,r,e_j,u_j,f_j)
%OUT:
%f_jplus1 = feed forward signal for upcoming trial
%
%IN:
%t = trial time vector
%r = current trial position reference
%e_j = current trial tracking error
%u_j = current trial control effort
%f_j = current trial feed forward signal

% Load trajectory for feedforward exercise.
% load('trajectory.mat');

% Load Learning controller (uncomment for ILC implementation).
load('ILCController.mat'); % design in DesignController.m

% mass feedforward for exercise 1.c
m = 0.0888; %tune mass parameter
% f_jplus1 = m*r.a;
% f_jplus1 = f_j;

% learning feedforward
alpha = 0.5;
[e_filt,~,~] = stable_inv(GS,e_j,Ts);
f_jplus1 = filtfilt(Qb,Qa,f_j + alpha*e_filt);          % f_jplus1 = Q(f_j + L*e_j)


% set last samples of f_jplus1 to zero
f_jplus1(end-50:end) = 0;

% Make sure the feedforward is a column.
f_jplus1 = f_jplus1(:);
