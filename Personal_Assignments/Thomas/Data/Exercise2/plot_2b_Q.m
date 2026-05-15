%% plotting error norm for different cuttoff f in Q
clear; 
close all;

% data formatting
file_names = ["data_2b_Q10","data_2b_Q200.mat", "data_2b_alpha0p5.mat"];
Q_values = [10, 200, 600];

% find length of data and time scale
load(file_names(1))
N_trial = size(history.e,2);
Ts = 0.001;
t = (0:Ts:(length(history.e)-1)*Ts)'; 

%% load all error norms arrays into a matrix
eNorms = zeros(length(Q_values), N_trial);
for i = 1 : length(Q_values)
    % load data
    load(file_names(i));
    eNorms(i, :) = history.eNorm; 
end

figWidth = 15; 
figHeight = 10; 
fig = figure('Units', 'centimeters', 'Position', [10, 10, figWidth, figHeight]);

% 1. Predefine colors (IEEE/Academic palette)
% Rows of RGB values: [Red, Green, Blue]
colors = [
    0.00, 0.45, 0.74;  % Blue
    0.85, 0.33, 0.10;  % Orange/Red
    0.47, 0.67, 0.19;  % Green
    0.49, 0.18, 0.56   % Purple
];

hold on;

% 2. Loop for plotting
trials = 1:N_trial;
for i = 1:length(Q_values)
    plot(trials, eNorms(i, :), ...
        'Color', colors(i, :), ...
        'LineWidth', 1.5, ...
        'Marker', 'o', 'MarkerSize', 4); % Optional markers to show discrete trials
end

% 3. Formatting
grid on;
set(gca, 'TickLabelInterpreter', 'latex', 'FontSize', 10);
xlabel('Trial \#', 'Interpreter', 'latex', 'FontSize', 11);
ylabel('$||e||_2$ [m]', 'Interpreter', 'latex', 'FontSize', 11);

% 4. Professional Legend
legendLabels = arrayfun(@(x) sprintf('$f_c = %.1f$', x), Q_values, 'UniformOutput', false);
lgd = legend(legendLabels, 'Interpreter', 'latex', 'Location', 'northeast');
% title('Error Convergence for Varying $\alpha$', 'Interpreter', 'latex', 'FontSize', 12);

% 5. Export
if ~exist('Figures', 'dir'), mkdir('Figures'); end
exportgraphics(fig, "Figures/plot_2b_Q.pdf", "ContentType", "vector")


