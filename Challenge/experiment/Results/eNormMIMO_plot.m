%% Plots side-by-side figure with eNorms over trials for X and Phi directions
clear;
clc; close all;

%% Settings
ch_x = 2;   % x-direction channel index
ch_phi = 3; % phi-direction channel index

% Select dataset configuration
dataset = 'exp_ALL';   

% Choose how to handle varying trial lengths:
% 'max' = plot each dataset to its individual maximum valid length
% 'min' = crop all datasets to match the shortest dataset
plot_length_mode = 'max'; 

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
        data_names = {'sim/1_SISO_BF/SISO_na0_nb2_1', ...
                      'sim/3_MIMO_BF/MIMO_BF_nbx2_nbphi2_3'};
        custom_legend = {'SISO BF','MIMO BF'};
    case 'sim_SISO_BF_vs_SISO_BFIS'
        data_names = {'sim/1_SISO_BF/SISO_na0_nb2_1', ...
                      'sim/2_SISO_BFIs/SISO_BFIS_na2_nb2_2'};
        custom_legend = {'SISO BF', 'SISO BFIS'};
    case 'sim_ALL'
        data_names = {'sim/1_SISO_BF/SISO_na0_nb2_1', ...
                      'sim/2_SISO_BFIs/SISO_BFIS_na2_nb2_2', ...  
                      'sim/3_MIMO_BF/MIMO_BF_nbx2_nbphi2_3'};
        custom_legend = {'SISO BF', 'SISO BFIS', 'MIMO BF'};
    case 'exp_SISO_BF_vs_MIMO_BF'
        data_names = {'22_06/1_SISO_BF/SISO_na0_nb2_3', ...
                      '22_06/3_MIMO_BF/MIMO_nbx2_nbphi2_3p1'};
        custom_legend = {'SISO BF','MIMO BF'};
    case 'exp_SISO_BF_vs_SISO_BFIS'
        data_names = {'22_06/1_SISO_BF/SISO_na0_nb2_3', ...
                      '22_06/2_SISO_BFIS/SISO_na2_nb2_2p2'};
        custom_legend = {'SISO BF', 'SISO BFIS'};
    case 'exp_ALL'
        data_names = {'22_06/1_SISO_BF/SISO_na0_nb2_3', ...
                      '22_06/2_SISO_BFIS/SISO_na3_nb2_2p4', ...
                      '22_06/3_MIMO_BF/MIMO_nbx2_nbphi2_3p1'};
        custom_legend = {'SISO BF', 'SISO BFIS', 'MIMO BF'}; 
    case 'exp_1'
        data_names = {'22_06/1_SISO_BF/SISO_na0_nb2_3'};
        custom_legend = {'SISO BF'};    
    case 'exp_2'
        data_names = {'22_06/1_SISO_BF/SISO_na0_nb2_3', ...
                      '22_06/2_SISO_BFIS/SISO_na3_nb2_2p4'};
        custom_legend = {'SISO BF', 'SISO BFIS'};    
end

num_datasets = length(data_names);

% Pre-allocate cell arrays to store extracted data
eNorms_x = cell(1, num_datasets);
eNorms_phi = cell(1, num_datasets);
valid_lengths = zeros(1, num_datasets); % Array to store each dataset's length

%% Extract Data and Determine Valid Lengths
for i = 1:num_datasets
    % Load data into a structure to prevent workspace clutter
    data = load(data_names{i});
    
    % Extract eNorms data for both channels
    current_x = data.history.eNorm(:, ch_x);
    current_phi = data.history.eNorm(:, ch_phi);
    
    % Find the last index that is NOT NaN for both channels to be safe
    valid_length_x = find(~isnan(current_x), 1, 'last');
    valid_length_phi = find(~isnan(current_phi), 1, 'last');
    
    % Take the shortest valid length between the two channels for this specific file
    valid_length = min([valid_length_x, valid_length_phi]);
    
    if isempty(valid_length)
        valid_length = 0;
    end
    
    % Store the valid length for this specific dataset
    valid_lengths(i) = valid_length;
    
    % Store the full data for plotting later
    eNorms_x{i} = current_x;
    eNorms_phi{i} = current_phi;
end

%% Resolve Plot Limits Based on Mode
if strcmp(plot_length_mode, 'min')
    % Force all plots to be as short as the shortest dataset
    target_lengths = repmat(min(valid_lengths), 1, num_datasets);
else
    % Let each plot go to its own maximum length
    target_lengths = valid_lengths;
end

max_plot_len = max(target_lengths); % Used to draw the horizontal converged lines across the plot

%% Make plot overlaying for each data set
% Create figure sized for standard IEEE DOUBLE column (7.16 inches wide)
fig = figure('Units', 'inches', 'Position', [1, 1, 7.16, 2.5]);

% Define a set of standard colors for distinction
colors = lines(num_datasets); 

% --- Subplot 1: X Direction ---
subplot(1, 2, 1);
hold on; grid on; box on;

for i = 1:num_datasets
    len = target_lengths(i); % Get the dynamic length for this iteration
    if len > 0
        plot_data_x = eNorms_x{i}(1:len);
        
        % Plot Main Data Line
        plot(1:len, plot_data_x, ...
            'LineStyle', '-', ...
            'Marker', 'o', ...
            'LineWidth', 1.2, ...
            'Color', colors(i,:));
            
        % Plot Converged Error Line
        converged_val_x = plot_data_x(end);
        plot([1, max_plot_len], [converged_val_x, converged_val_x], ...
            'LineStyle', '--', ...
            'Marker', 'none', ...
            'LineWidth', 1, ...
            'Color', colors(i,:));
    end
end

xlabel('Trial Number', 'Interpreter', 'latex');
ylabel('$||e_x||_2$', 'Interpreter', 'latex');
xlim([0, 50]);
ylim([0.005, 0.045]);
set(gca, 'FontSize', 9, 'FontName', 'Times New Roman', 'TickLabelInterpreter', 'latex'); 
hold off;

% --- Subplot 2: Phi Direction ---
subplot(1, 2, 2);
hold on; grid on; box on;

h_main = gobjects(1, num_datasets); % Pre-allocate graphic handles for the legend

for i = 1:num_datasets
    len = target_lengths(i); % Get the dynamic length for this iteration
    if len > 0
        plot_data_phi = eNorms_phi{i}(1:len);
        
        % Plot Main Data Line and store the handle for the legend
        h_main(i) = plot(1:len, plot_data_phi, ...
            'LineStyle', '-', ...
            'Marker', 'o', ...
            'LineWidth', 1.2, ...
            'Color', colors(i,:));
            
        % Plot Converged Error Line (handle not stored so it avoids cluttering legend)
        converged_val_phi = plot_data_phi(end);
        plot([1, max_plot_len], [converged_val_phi, converged_val_phi], ...
            'LineStyle', '--', ...
            'Marker', 'none', ...
            'LineWidth', 1, ...
            'Color', colors(i,:));
    end
end

xlabel('Trial Number', 'Interpreter', 'latex');
ylabel('$||e_\phi||_2$', 'Interpreter', 'latex');
xlim([0, 50]);
ylim([2.7e-3, 3.4e-3]);
set(gca, 'FontSize', 9, 'FontName', 'Times New Roman', 'TickLabelInterpreter', 'latex'); 


% Create a dummy plot for the 'Converged Error' legend entry (black dashed line)
h_dummy = plot(NaN, NaN, 'LineStyle', '--', 'Marker', 'none', 'Color', 'k', 'LineWidth', 1);

% Combine original dataset legends with the new Converged Error label
final_legend_entries = [custom_legend, {'Converged Error'}];
leg = legend([h_main, h_dummy], final_legend_entries, 'Location', 'best', 'Interpreter', 'latex');
leg.ItemTokenSize = [15, 18]; % Keeps the legend lines compact

hold off;

%% Export
export_folder = 'Exports'; % Specify your folder name here

% Check if the folder exists; if not, create it
if ~exist(export_folder, 'dir')
    mkdir(export_folder);
end

% Construct the full file path safely
file_path = fullfile(export_folder, sprintf('%s_eNormMIMO.pdf', dataset));

% Export the figure as a vector PDF
exportgraphics(fig, file_path, 'ContentType', 'vector');