%% Plots single figure with eNorms over trials for multiple experiment recordings
clear;
clc; close all;

%% Settings
active_ch = 2; % [y, x, phi]

% select dataset, if you want to add new data, make a new entry below
dataset = 'sim_SISO_BFIS';    
dataset = 'exp_SISO_BF_vs_SISO_BFIS';   
% dataset = 'sim_SISO_BF_vs_MIMO_BF';
%% Load selected data set
custom_legend = {};
switch dataset
    case 'sim_SISO_BF'
        data_names = {'sim/1_SISO_BF/SISO_na0_nb2_1', ...
                      'sim/1_SISO_BF/SISO_na0_nb3_1', ...
                      'sim/1_SISO_BF/SISO_na0_nb4_1'};
        custom_legend = {'$r_y$', '$n_b = 2$', '$n_b = 3$', '$n_b = 4$'};
    case 'exp_SISO_BF'
        data_names = {'22_06/1_SISO_BF/SISO_na0_nb2_2', ...
                      '22_06/1_SISO_BF/SISO_na0_nb2_3', ...
                      '22_06/1_SISO_BF/SISO_na0_nb4_1p5'};
        custom_legend = {'$r_y$', '$n_b = 2$', '$n_b = 3$', '$n_b = 4$'};
    case 'sim_SISO_BFIS'
        data_names = {'sim/2_SISO_BFIS/SISO_BFIS_na1_nb2_1', ...
                      'sim/2_SISO_BFIs/SISO_BFIS_na2_nb2_2', ...
                      'sim/2_SISO_BFIs/SISO_BFIS_na3_nb2_1', ...
                      'sim/2_SISO_BFIs/SISO_BFIS_na4_nb2_1'};
        custom_legend = {'$r_y$', '$n_a = 1$', '$n_a = 2$', '$n_a = 3$', '$n_a = 4$'};
    case 'sim_SISO_BF_vs_MIMO_BF'
        data_names = {'sim/1_SISO_BF/SISO_na0_nb2_3', ...
                      'sim/3_MIMO_BF/MIMO_BF_nbx2_nbphi2_2'};
        custom_legend = {'SISO BF','MIMO BF'};
    case 'sim_SISO_BF_vs_SISO_BFIS'
        data_names = {'sim/1_SISO_BF/SISO_na0_nb2_1', ...
                      'sim/2_SISO_BFIs/SISO_BFIS_na2_nb2_2'};
        custom_legend = {'SISO BF', 'SISO BFIS'};
    case 'exp_SISO_BF_vs_MIMO_BF'
        data_names = {'22_06/1_SISO_BF/SISO_na0_nb2_3', ...
                      '22_06/3_MIMO_BF/MIMO_nbx2_nbphi2_3p1'};
        custom_legend = {'SISO BF','MIMO BF'};
    case 'exp_SISO_BF_vs_SISO_BFIS'
        data_names = {'22_06/1_SISO_BF/SISO_na0_nb2_3', ...
                      '22_06/2_SISO_BFIS/SISO_na2_nb2_2p2'};
        custom_legend = {'SISO BF', 'SISO BFIS'};
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
fig = figure('Units', 'inches', 'Position', [1, 1, 3.5, 2.5]);
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

%% Export
export_folder = 'Exports'; % Specify your folder name here

% Check if the folder exists; if not, create it
if ~exist(export_folder, 'dir')
    mkdir(export_folder);
end

% Construct the full file path safely (e.g., 'Exports/exp_SISO_BF.pdf')
file_path = fullfile(export_folder, sprintf('%s_eNorm.pdf', dataset));

% Export the figure as a vector PDF
exportgraphics(fig, file_path, 'ContentType', 'vector');