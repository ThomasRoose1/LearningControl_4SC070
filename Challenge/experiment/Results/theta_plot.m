%% Plots Theta Parameters over trials for a single dataset (IEEE Style)
clear; clc; close all; 

%% Settings
active_ch = 2; % [y, x, phi]

% Specify your data file here
% data_name = 'sim/1_SISO_BF/SISO_na0_nb3_1.mat'; 
data_name = 'sim/2_SISO_BFIS/SISO_BFIS_na4_nb2_1.mat';
data_name = 'sim/2_SISO_BFIS/SISO_BFIS_na4_nb2_1.mat';

% Select parameters to include (e.g., [1:4], [1, 3], or [] for all parameters)
param_range = [1:4]; 

%% Load and Extract Data
data = load(data_name);

% Extract theta data for the active channel: [trial, param]
theta_raw = squeeze(data.history.theta(:, :, active_ch)); 

% Find the last index that is NOT NaN (checking the first parameter column)
valid_length = find(~isnan(theta_raw(:,1)), 1, 'last');
if isempty(valid_length)
    valid_length = 0; % Edge case fallback
end

% Truncate the data to drop the trailing NaNs
theta_valid = theta_raw(1:valid_length, :);

% Dynamically check how many parameters exist in total
total_params = size(theta_valid, 2); 

% Resolve the range if left empty (acts as 1:end)
if isempty(param_range)
    param_range = 1:total_params;
end

% Safety check: remove any requested indices that exceed the total parameters
param_range = param_range(param_range <= total_params);
num_selected = length(param_range);

%% Prepare Figure
% Create figure sized for standard IEEE single column (3.5 inches wide)
fig = figure('Units', 'inches', 'Position', [1, 1, 3.5, 2.5]);
hold on; grid on; box on;

% Generate distinct colors dynamically based on the number of selected parameters
colors = lines(num_selected); 

% Pre-allocate legend entries
legend_entries = cell(1, num_selected);

%% Plot Data
for k = 1:num_selected
    j = param_range(k); % The actual parameter index (e.g., 2, 3, etc.)
    
    plot(1:valid_length, theta_valid(:, j), ...
        'LineStyle', '-', ...
        'Marker', 'none', ...
        'LineWidth', 1.2, ...
        'Color', colors(k,:));
    
    % Construct dynamic legend referencing the original parameter number
    legend_entries{k} = sprintf('$\\theta_%d$', j);
end

%% Formatting & IEEE Standards
xlabel('Trial Number', 'Interpreter', 'latex');
ylabel('$\theta$ [-]', 'Interpreter', 'latex');

% IEEE typical font settings
set(gca, 'FontSize', 9, 'FontName', 'Times New Roman', 'TickLabelInterpreter', 'latex'); 

% Render the legend dynamically
leg = legend(legend_entries, 'Location', 'best', 'Interpreter', 'latex');
leg.ItemTokenSize = [15, 18]; % Keeps the legend lines compact

hold off;

%% Export Figure
export_folder = 'Exports';

% Check if the folder exists; if not, create it
if ~exist(export_folder, 'dir')
    mkdir(export_folder);
end

% Extract just the file name without the folder path or .mat extension
[~, base_name, ~] = fileparts(data_name);

% Construct the full file path safely 
file_path = fullfile(export_folder, sprintf('%s_theta.pdf', base_name));
exportgraphics(fig, file_path, 'ContentType', 'vector');