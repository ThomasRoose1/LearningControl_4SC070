%% plotting error and input data when using mass feedforward
clear; 
close all;

% Load Data
load("data_1c_1.mat");
f = history.f;
e = history.e;
u = history.u;
eNorms = history.eNorm;
Ts = 0.001;
t = (0:Ts:(length(e)-1)*Ts)'; 

%% Plotting Error and Input Data (Mass Feedforward)
% dimensions for A4 LaTeX (16cm width is a safe standard)
figWidth = 16; 
figHeight = 20; % Taller figure to accommodate 4 stacks

fig = figure('Units', 'centimeters', 'Position', [2, 2, figWidth, figHeight]);

% Use tiledlayout for tight spacing
tl = tiledlayout(4, 1, 'Padding', 'compact', 'TileSpacing', 'compact');

%% 1. Force/Input f [V]
nexttile;
plot(t, f, 'b--', 'LineWidth', 2); % Matching the dashed purple/magenta
grid on;
ylabel('$f$ [V]', 'Interpreter', 'latex');
xlabel('$t$ [s]', 'Interpreter', 'latex');
set(gca, 'TickLabelInterpreter', 'latex', 'XTickLabel', []); % Remove x-labels for middle plots

%% 2. Control Signal u [V]
nexttile;
plot(t, u(:,1), 'k', 'LineWidth', 2); hold on;
plot(t, u(:,2), 'r--', 'LineWidth', 2);
grid on;
ylabel('$u$ [V]', 'Interpreter', 'latex');
xlabel('$t$ [s]', 'Interpreter', 'latex');
set(gca, 'TickLabelInterpreter', 'latex', 'XTickLabel', []);
legend("Trial 1", "Trial 2", "Location", "southeast")

%% 3. Tracking Error e [m]
nexttile;
plot(t, e(:,1), 'k', 'LineWidth', 2); hold on;
plot(t, e(:,2), 'r--', 'LineWidth', 2);
grid on;
ylabel('$e$ [m]', 'Interpreter', 'latex');
xlabel('$t$ [s]', 'Interpreter', 'latex');
set(gca, 'TickLabelInterpreter', 'latex', 'XTickLabel', []);

%% 4. Norm Convergence ||e||_2
nexttile;
trial_idx = 0:length(eNorms)-1; % X-axis for trials
plot(trial_idx, eNorms, 'r--x', 'LineWidth', 1.5);
grid on;
ylabel('$||e||_2$ [m$^2$]', 'Interpreter', 'latex');
xlabel('Trial \#', 'Interpreter', 'latex');
set(gca, 'TickLabelInterpreter', 'latex');

%% Compute Norms for Each Trial
[numSamples, numTrials] = size(e);
e2_results = zeros(numTrials, 1);
einf_results = zeros(numTrials, 1);

for k = 1:numTrials
    % Extract current trial
    e_trial = e(:, k);
    
    % Compute norms
    e2_results(k) = norm(e_trial) * sqrt(Ts);
    einf_results(k) = norm(e_trial, inf);
end

% Create and Print Table
Trial = (1:numTrials)';

resultsTable = table(Trial, e2_results, einf_results);
fprintf('\n--- Performance Metrics per Trial ---\n');
disp(resultsTable);

%% Global Title and Export

% Export to PDF
exportgraphics(fig, "Figures/plot_1c.pdf", "ContentType", "vector", "BackgroundColor", "none")