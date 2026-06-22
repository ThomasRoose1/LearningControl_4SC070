%% Plots single figure with eNorms over trials for multiple experiment recordings
clear;
clc; close all;

%% Settings
active_ch = 2; % [y, x, phi]
dataset = 'sim_SISO_BF';    % select dataset, if you want to add new data, make a new entry below

%% Load selected data set
custom_legend = {};
switch dataset
    case 'sim_SISO_BF'
        data_names = {'sim/1_SISO_BF/SISO_na0_nb2_1', ...
                      'sim/1_SISO_BF/SISO_na0_nb3_1', ...
                      'sim/1_SISO_BF/SISO_na0_nb4_1'};
        custom_legend = {'$n_b = 2$', '$n_b = 3$', '$n_b = 4$'};
    case 'exp_SISO_BF'
        data_names = {'22_06/1_SISO_BF/SISO_na0_nb2_2', ...
                      '22_06/1_SISO_BF/SISO_na0_nb2_3', ...
                      '22_06/1_SISO_BF/SISO_na0_nb4_1p5'};
        custom_legend = {'$n_b = 2$', '$n_b = 3$', '$n_b = 4$'};
end

num_datasets = length(data_names);

% Pre-allocate cell array to store extracted data
eNorms_all = cell(1, num_datasets);
min_trials = 50; % Starting assumption based on your prompt

%% Extract Data and Determine Minimum Valid Length
for i = 1:num_datasets
    % Load data into a structure to prevent workspace clutter
    data = load(data_names{i});
    
    % Extract eNorms data
    eNorm_current = data.history.eNorm(:, active_ch); % [trial, direction]
    
    % Find the last index that is NOT NaN
    valid_length = find(~isnan(eNorm_current), 1, 'last');
    
    % If empty (all NaNs), set to 0
    if isempty(valid_length)
        valid_length = 0;
    end
    
    % Update the minimum trial length found so far
    if valid_length < min_trials
        min_trials = valid_length;
    end
    
    % Store the full data for plotting later
    eNorms_all{i} = eNorm_current;
end

%% Make plot overlaying for each data set
% Create figure sized for standard IEEE single column (3.5 inches wide)
figure('Units', 'inches', 'Position', [1, 1, 3.5, 2.5]);
hold on;
grid on;
box on;

% Define a set of standard colors for distinction
colors = lines(num_datasets); 

for i = 1:num_datasets
    % Truncate the data to the shortest valid length across all datasets
    plot_data = eNorms_all{i}(1:min_trials);
    
    % Plot lines only, no markers, with distinct colors
    plot(1:min_trials, plot_data, ...
        'LineStyle', '-', ...
        'Marker', 'o', ...
        'LineWidth', 1.2, ...
        'Color', colors(i,:));
end

%% Formatting & IEEE Standards
xlabel('Trial Number', 'Interpreter', 'latex');
ylabel('Error Norm', 'Interpreter', 'latex');

% IEEE typical font settings
set(gca, 'FontSize', 9, 'FontName', 'Times New Roman', 'TickLabelInterpreter', 'latex'); 

% Legend - Fill in your actual names here
legend_names = custom_legend;
leg = legend(legend_names, 'Location', 'best', 'Interpreter', 'latex');
leg.ItemTokenSize = [15, 18]; % Keeps the legend lines compact

hold off;