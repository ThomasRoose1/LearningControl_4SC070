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

% Calculate feedforward.

% mass feedforward for exercise 1.c
m = 0.091; %tune mass parameter
% f_jplus1 = m*r.a;
% f_jplus1 = f_j;

% [Qnum, Qden] = tfdata(Q_lifted, 'v')

% learning feedforward
alpha = 1;                            
e_filt = L_lifted * e_j;
% f_jplus1 = filtfilt(Qnum,Qden,f_j + alpha*e_filt);
f_jplus1 = Q_lifted * f_j + alpha* e_filt;


% set last samples of f_jplus1 to zero
f_jplus1(end-50:end) = 0;

% Make sure the feedforward is a column.
f_jplus1 = f_jplus1(:);