%FEEDFORWARDUPDATE   Compute feedforward signal for next trial.
function f_jplus1 = feedforwardUpdate(t,r,e_j,u_j,f_j, trial)
%OUT:
%f_jplus1 = feed forward signal for upcoming trial
%
%IN:
%t = trial time vector
%r = current trial position reference
%e_j = current trial tracking error
%u_j = current trial control effort
%f_j = current trial feed forward signal
%trial = trail number

% Load trajectory for feedforward exercise.
% load('trajectory.mat');

% Load Learning controller (uncomment for ILC implementation).
load('ILCController.mat'); % design in DesignController.m

% Calculate feedforward.

% mass feedforward for exercise 1.c
% m = 0.0910; %tune mass parameter
<<<<<<< Updated upstream
m = 0.07;
=======
m = 0.093;
>>>>>>> Stashed changes
f_jplus1 = m*r.a;

% Define how many samples to clear
x = 10; 
e_j(end-x+1:end) = 0;


alpha = 0.6;

% alpha_values = [0.5, 0.2, 0.1, 0.05]; % voeg hier je waarden toe
% 
% for trial = 1:length(alpha_values)
%     alpha = alpha_values(trial);
% end

% learning feedforward
<<<<<<< Updated upstream
[e_filt,~,~] = stable_inv(GS,e_j,Ts);
% f_jplus1 = Q*(f_j+e_filt);

alpha = 0.5;
f_jplus1 = filtfilt(Qb,Qa,f_j+alpha*e_filt);                                        % f_jplus1 = Q(f_j + L*e_j)
=======

% [e_filt,~,~] = stable_inv(GS,e_j,Ts);
% % f_jplus1 = Q*(f_j+alpha*e_filt);
% f_jplus1 = filtfilt(Qb,Qa,f_j+alpha*e_filt);                                        % f_jplus1 = Q(f_j + L*e_j)
>>>>>>> Stashed changes


% Make sure the feedforward is a column.
f_jplus1 = f_jplus1(:);