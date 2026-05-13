%DESIGNCONTROLLER   Use this template for designing your controller.
clearvars -except p Fs Ts tsim
close all;
clc;


%% Parameters
fs = 1000;         % sample frequency
Ts = 1/fs;         % sample time
N = 4501;          % trial length
save_switch = 1;   % switch for saving ILC filters: 1 = save, 0 = no save


%% System model, system frequency response measurement and controller.
% System model and FRF measurement.
load('PrinterModel2020.mat');
G = PrinterModelSS;
Gfrf = PrinterModelFRF;

% Feedback controller.
load('PrinterController.mat');
C = minreal(shapeit_data.C_tf_z);

Gfrd = frd(Gfrf.frf,Gfrf.freq*2*pi,Ts);

%% 1.a
% Continuous or discrete? open G, it will say discrete time model
if G.Ts == 0
    frpintf('System is Continuous, ');
else
    fprintf('System is Discrete, ');
end

% sampling f? given above fs = 1000;
fprintf("fs = %d, ", fs)

% Nyquist f? fs/2 = 500
fprintf("fn = %d, ", fs/2)

% collocated or collocated? plot the bode plot
% it is non-collocated because -4 slope after resonance, it is a mass spring
% damper system
% Combined Bode Plot
h = figure('Units', 'centimeters', 'Position', [1, 1, 21, 15]); % A4 width-ish

% Generate the plot with both systems
bode(G, 'b', C, 'r'); 
grid on; title('');
legend('Plant G(z)', 'Controller C(z)', 'Location', 'southwest');

% Save as PDF
exportgraphics(h, 'Exports/Bode_G_C.pdf', 'ContentType', 'vector');

% model order? see dimention of A, it is 7
fprintf("G order = %d\n", order(G))

% model stable? no, double integrator means unstable
lambda_G = abs(eig(G.A))

% controller stable? 
fprintf("C order = %d\n", order(C))
lambda_C = abs(eig(C))

% Closed loop stable?
L_loop = G * C;  
fig2 = figure; nyquist(L_loop);
xlim([-2 1]); ylim([-2 2]);
title('')
exportgraphics(fig2, 'Exports/Nyquist.pdf', 'ContentType', 'vector')

%% 1.c. compute mass feedforward
omega_massline = 100;
G_mag = abs(squeeze(freqresp(Gfrd, omega_massline)))
m = 1 / (G_mag*omega_massline^2)

%% 1.d.
% Define closed loop system
S = feedback(1, L_loop); 
GS = feedback(G, C);

% Compute stable inverse of GS to find L
z = tf('z',Ts);
[~,Lc,phd] = stable_inv(GS,0,Ts);                                           % Retrieve causal Lc
L = z^phd*Lc;    

% Generate the Bode plot
figWidth = 15; 
figHeight = 12; 

fig = figure('Units', 'centimeters', 'Position', [10, 10, figWidth, figHeight]);


bode(GS, 'b'); % Blue for Plant
hold on;
bode(L, 'r'); % Red dashed for Open Loop
grid on;

% Clean up the internal MATLAB Bode styling
% This handles fonts and LaTeX for all labels and axes
set(findall(fig, 'Type', 'line'), 'LineWidth', 1.5);
set(findall(fig, 'Type', 'text'), 'Interpreter', 'latex', 'FontSize', 11);
set(findall(fig, 'Type', 'axes'), 'TickLabelInterpreter', 'latex', 'FontSize', 10);

% Add Legend
lgd = legend('$GS(z)$', '$L(z)$', 'Location', 'southwest');
set(lgd, 'Interpreter', 'latex');
% Export
if ~exist('Exports', 'dir'), mkdir('Exports'); end
exportgraphics(fig, "Exports/bode_L_GS.pdf", "ContentType", "vector", "BackgroundColor", "none")

%% 1.e.
% compute FRF based GS
GS_frd = feedback(Gfrd, C);
% Plot mag of (1 - GSL) for both parametric and FRF version of GS
fig = figure('Units', 'centimeters', 'Position', [10, 10, figWidth, figHeight]);
bodemag(1 - GS*L); hold on;
bodemag(1 - GS_frd*L);
yline(1, "k--", "LineWidth", 1.5);
grid on;
% Clean up the internal MATLAB Bode styling
% This handles fonts and LaTeX for all labels and axes
set(findall(fig, 'Type', 'line'), 'LineWidth', 1.5);
set(findall(fig, 'Type', 'text'), 'Interpreter', 'latex', 'FontSize', 11);
set(findall(fig, 'Type', 'axes'), 'TickLabelInterpreter', 'latex', 'FontSize', 10);

% Add Legend
lgd = legend('$(1 - GSL)$ parametric', '$(1 - GSL)$ FRF', 'Location', 'southwest');
set(lgd, 'Interpreter', 'latex');
% Export
if ~exist('Exports', 'dir'), mkdir('Exports'); end
exportgraphics(fig, "Exports/bode_convergence.pdf", "ContentType", "vector", "BackgroundColor", "none")

%% 1.f
fN = fs/2;                                                                  % Nyquist frequency
fC = 400 / (2*pi);                                                          % Cut-off frequency
n = [4];                                                                    % Order Q-filter

[Qb,Qa] = butter(n,fC/fN);
Q = tf(Qb,Qa,Ts); 

% Plot mag of (1 - GSL) for FRF version of GS and Q filter and combo
fig = figure('Units', 'centimeters', 'Position', [10, 10, figWidth, figHeight]);
bodemag(1 - GS_frd*L); hold on;
bodemag(Q*(1 - GS_frd*L));
bodemag(Q)
yline(1, "k--", "LineWidth", 1.5, 'HandleVisibility', 'off');
grid on;
ylim([-100 60])
% Clean up the internal MATLAB Bode styling
% This handles fonts and LaTeX for all labels and axes
set(findall(fig, 'Type', 'line'), 'LineWidth', 1.5);
set(findall(fig, 'Type', 'text'), 'Interpreter', 'latex', 'FontSize', 11);
set(findall(fig, 'Type', 'axes'), 'TickLabelInterpreter', 'latex', 'FontSize', 10);

% Add Legend
lgd = legend('$(1 - GSL)$', '$Q(1 - GSL)$', '$Q$', 'Location', 'southwest');
set(lgd, 'Interpreter', 'latex');
% Export
if ~exist('Exports', 'dir'), mkdir('Exports'); end
exportgraphics(fig, "Exports/bode_Q.pdf", "ContentType", "vector", "BackgroundColor", "none")

%% 3. Robust Convergence Analysis (Comparison Plot)
% Define the systems
Conv_no_Q = 1 - (GS_frd * L);
Conv_with_Q = Q * Conv_no_Q; % Direct multiplication of LTI/FRD objects

figure;
% Plot both systems: 'b:' for dotted blue, 'g' for solid green
bodemag(Conv_no_Q, 'b:', Conv_with_Q, 'g');
hold on;

% Define the valid frequency range (20 Hz to Nyquist)
f_min = 20; 
f_max = fs/2;
w_range = [f_min, f_max] * 2 * pi;

% Plot the 0 dB Stability Limit
line(w_range, [0 0], 'Color', 'r', 'LineStyle', '--', 'LineWidth', 1.5);

% Formatting and SNR Constraint
xlim(w_range);
ylim([-80, 40]);
grid on;
title('Robust Convergence Analysis (Q-Filter Comparison)');
legend('|1 - GSL| (No Q)', '|Q(1 - GSL)| (With Q)', 'Stability Limit', 'Location', 'southwest');

%% Save ILC filters.
if save_switch
    % Modify line below to choose which variables to save
    save('ILCController','Qb','Qa','GS','Ts');    
    disp('Parameters saved!');
end