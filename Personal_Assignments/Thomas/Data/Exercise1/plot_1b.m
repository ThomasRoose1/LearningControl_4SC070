%% plotting error and input data when using only feedback control
clear; 
close all;

% Load Data
load("data_1b.mat");
f = history.f;
e = history.e;
u = history.u;
eNorms = history.eNorm;
Ts = 0.001;
t = (0:Ts:(length(e)-1)*Ts)'; 

%% compute norms
e_2_norm = norm(e) * sqrt(Ts); % L2 norm (Energy)
e_inf_norm = norm(e, inf);     % L-infinity norm (Peak)

%% Figure Setup for LaTeX
% Define dimensions in centimeters (standard A4 text width is ~15-17cm)
figWidth = 15; 
figHeight = 12; 

fig = figure('Units', 'centimeters', 'Position', [10, 10, figWidth, figHeight]);

% Plotting with improved readability
s1 = subplot(2,1,1);
plot(t, e, 'b', 'LineWidth', 1.5); % Slightly thinner lines for PDF export
grid on;
ylabel('$e$ [m]', 'Interpreter', 'latex', 'FontSize', 11);
xlabel('$t$ [s]', 'Interpreter', 'latex', 'FontSize', 11);
set(gca, 'TickLabelInterpreter', 'latex', 'FontSize', 10);

s2 = subplot(2,1,2);
plot(t, u, 'r', 'LineWidth', 1.5);
grid on;
ylabel('$u$ [V]', 'Interpreter', 'latex', 'FontSize', 11);
xlabel('$t$ [s]', 'Interpreter', 'latex', 'FontSize', 11);
set(gca, 'TickLabelInterpreter', 'latex', 'FontSize', 10);

% Create the formatted string first
titleString = sprintf('$||e||_2 = %.4f, \\quad ||e||_\\infty = %.4f$', e_2_norm, e_inf_norm);

% Apply it using the 'Interpreter' name-value pair
sgtitle(titleString, 'Interpreter', 'latex', 'FontSize', 13);

%% 5. Export
if ~exist('Figures', 'dir'), mkdir('Figures'); end
exportgraphics(fig, "Figures/plot_1b.pdf", "ContentType", "vector", "BackgroundColor", "none")