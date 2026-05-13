%DESIGNCONTROLLERRC   Use this template for designing your repetitive controller.
clear variables;
close all;
clc;


%% Parameters
fs = 1000;         % sample frequency
Ts = 1/fs;         % sample time
save_switch = 1;   % switch for saving RC filters: 1 = save, 0 = no save


%% System model, system frequency response measurement and controller.
% System model and FRF measurement.
load('PrinterModel.mat');
G = PrinterModelSS;
Gfrf = PrinterModelFRF;
freq = Gfrf.Frequency;

% Feedback controller.
load('PrinterController.mat');
C = minreal(shapeit_data.C_tf_z);

%% Exercise 3
% Define complementary sensitivity
T = feedback(G*C, 1);
T = minreal(T);
[z p k] = zpkdata(T);
% Marginally stable due to single pole on unit circle

%% Exercise 3.2: RC design.
%Required outputs:
% - L_c: causal part of L. That is, L = z^{p_L}*L_c
% - p_L: number of preview samples of L
% - Q_c: causal part of Q. That is, Q = z^{p_Q}*Q_c
% - p_Q: number of preview samples of Q

%a

T = ss(T);
T = minreal(T);
[a,b,c,d,p_L]=zpetc(T.a,T.b,T.c,T.d,1);
alpha = 1;
L_c = alpha * ss(a,b,c,d,Ts);    % Causal part
z = tf('z',Ts);
L = z^p_L*L_c; 
% here p_L represents the "p+d", p is non minimum phase and d is relative
% degree, both require a preview step, in total p+d = 3 here    

% Combined Bode Plot
h = figure('Units', 'centimeters', 'Position', [1, 1, 21, 15]); % A4 width-ish

% Generate the plot with both systems
bode(L, 'b', L_c, 'r--'); 
grid on; title('');
legend('L', 'L_c',  'Location', 'southwest');
% ylim([-50 80]);

% Save as PDF
exportgraphics(h, 'Exports/Bode_L_L_c.pdf', 'ContentType', 'vector');

%% b
% Define Tfrf based on Gfrf and do the same check
Tfrf = feedback(C*Gfrf, 1);

% Generate the Bode plot
figWidth = 15; 
figHeight = 12; 

fig = figure('Units', 'centimeters', 'Position', [10, 10, figWidth, figHeight]);


bodemag(1 - Tfrf*L, 'r--'); 
hold on;
bodemag(1 - T*L, 'b');
grid on;
yline(1, 'k--', 'LineWidth', 1.5, 'HandleVisibility', 'off');
ylim([-150 50]);

% Create "Dummy Lines" for the legend
% These are plotted at a coordinate that isn't visible (e.g., NaN)
h1 = plot(NaN, NaN, 'r--', 'LineWidth', 1.5);
h2 = plot(NaN, NaN, 'b', 'LineWidth', 1.5);

% Clean up the internal MATLAB Bode styling
% This handles fonts and LaTeX for all labels and axes
set(findall(fig, 'Type', 'line'), 'LineWidth', 1.5);
set(findall(fig, 'Type', 'text'), 'Interpreter', 'latex', 'FontSize', 11);
set(findall(fig, 'Type', 'axes'), 'TickLabelInterpreter', 'latex', 'FontSize', 10);

% Add Legend
lgd = legend([h1, h2], '$(1 - T_\text{FRF} L)$', '$(1 - T L)$', 'Location', 'southwest');
set(lgd, 'Interpreter', 'latex');
title('');

% --- THE RELIABLE EXPORT FIX ---
% Force MATLAB to finish all pending drawing tasks (including LaTeX rendering)
drawnow; 

% Small pause to ensure the vector engine "sees" the dummy lines (common for PDFs)
pause(0.1);

% 3. Export
if ~exist('Exports', 'dir'), mkdir('Exports'); end
exportgraphics(fig, "Exports/bode_convergence.pdf", "ContentType", "vector", "BackgroundColor", "none");

%% c
fC = 10;                                                                    % desired cut-off frequency
fn = 1/(2*Ts);                                                              % Nyquist frequency
M = 50;                                                                     % desired order of low-pass FIR filter

num = fir1(M,fC/fn);        % create low-pass FIR filter coefficients
Q = tf(num,1,Ts);           % create filter
Q = Q*Q';                   % use Q'*Q for zero phase shift
Q = Q/freqresp(Q,0)^2;      % scale DC gain (gain at omega=0) to 1

Q_c = Q*tf(1,[1,zeros(1,M)],Ts); % Extract causal part
p_Q=M;                      % number of preview samples

% Plot mag of (1 - TL) for FRF version of T and Q filter and combo
fig = figure('Units', 'centimeters', 'Position', [10, 10, figWidth, figHeight]);
bodemag(1 - Tfrf*L); hold on;
bodemag(Q*(1 - Tfrf*L));
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

%% bode diagram of Q and Q*Q'
% Combined Bode Plot
h = figure('Units', 'centimeters', 'Position', [1, 1, 21, 15]); % A4 width-ish

% Create a bode options object
opts = bodeoptions;
opts.PhaseMatching = 'on';     % Ensures phase starts near 0 if applicable
% opts.PhaseWrapping = 'on';     % THIS IS THE KEY: turns on phase wrapping

% Generate the plot using the options
% Note: The 'opts' must be the last argument
bode(Q, 'b', Q*Q', 'r--', opts); 

grid on; 
title('');
legend("Q", "Q*Q'", 'Location', 'southwest');

% Save as PDF
exportgraphics(h, 'Exports/Bode_Q_QQ.pdf', 'ContentType', 'vector');

%% Exercise XX: save RC filters.
if save_switch
    % Modify line below to choose which variables to save
    save('RCController','L_c','p_L','Q_c','p_Q');    
    disp('Parameters saved!');
end