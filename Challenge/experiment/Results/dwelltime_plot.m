%% Makes a plot of dwell time based on multiple datasets (IEEE Style)
clear; clc; 
% close all; 

%% Settings
target_trial = 10; % You can change this to 'end' if you dynamically want the last trial

% select dataset, if you want to add new data, make a new entry below
dataset = 'sim_SISO_BF_vs_SISO_BFIS';   
dataset = 'exp_ALL';

% Set window size buffers
x_buffer = 0.05;  % Buffer for the x-axis (time in seconds)
y_buffer = 0.005; % Buffer for the y-axis (response magnitude)

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
        custom_legend = {'$r$','SISO BF','MIMO BF'};
    case 'sim_SISO_BF_vs_SISO_BFIS'
        data_names = {'sim/1_SISO_BF/SISO_na0_nb2_2', ...
                      'sim/2_SISO_BFIs/SISO_BFIS_na2_nb2_1'};
        custom_legend = {'$r$', 'SISO BF', 'SISO BFIS'};
    case 'sim_ALL'
        data_names = {'sim/1_SISO_BF/SISO_na0_nb2_1', ...
                      'sim/2_SISO_BFIs/SISO_BFIS_na2_nb2_2', ...  
                      'sim/3_MIMO_BF/MIMO_BF_nbx2_nbphi2_3'};
        custom_legend = {'r', 'SISO BF', 'SISO BFIS', 'MIMO BF'};
    case 'exp_ALL'
        data_names = {'22_06/1_SISO_BF/SISO_na0_nb2_2', ...
                      '22_06/2_SISO_BFIS/SISO_na2_nb2_2p2', ...
                      '22_06/3_MIMO_BF/MIMO_nbx2_nbphi2_3p1'};
        custom_legend = {'r', 'SISO BF', 'SISO BFIS', 'MIMO BF'};
end

num_datasets = length(data_names);

%% Decoupling Matrices (Constant)
Tu = [0.5, -0.3817;
      0.5,  0.3817];
Ty = [0.5,     0.5;
     -0.3817, 0.3817];
invTy_T = inv(Ty).'; 

%% Prepare Figure
% Create figure sized for standard IEEE single column (3.5 inches wide)
fig = figure('Units', 'inches', 'Position', [1, 1, 3.5, 2.5]);
hold on; grid on; box on;

% Define colors for responses
colors = lines(num_datasets);

% Pre-allocate legend entries (1 for reference + 1 for each dataset)
legend_entries = cell(1, num_datasets + 1);
legend_entries{1} = 'Reference ($r_y$)';
ref_plotted = false;

%% Process and Plot Each Dataset
for i = 1:num_datasets
    % Load data
    data = load(data_names{i});
    
    % Extract data of the target trial
    t = data.history.t;
    r_y = squeeze(data.history.r_y(target_trial, :, 2:3));
    y = squeeze(data.history.p(target_trial, :, 2:3));
    
    % Transoform the output and ref data back to x_1 and x_2
    y_c = y * invTy_T;   
    r_c = r_y * invTy_T;
    
    % Identify Dwell Time and Compute Errors
    dwell_indices = find(r_y(:,1) >= 0.09); 
    
    if ~isempty(dwell_indices)
        t_dwell = t(dwell_indices);
        ref_dwell = r_c(dwell_indices, 1);
        resp_dwell = y_c(dwell_indices, 1);
        
        % Compute the error during the dwell time
        error_dwell = ref_dwell - resp_dwell;
        peak_error = max(abs(error_dwell));
        rms_error = rms(error_dwell); 
        
        % Display results in the command window for current dataset
        fprintf('--- Dataset %d Metrics: %s ---\n', i, data_names{i});
        fprintf('Dwell Window: %.3f s to %.3f s\n', t_dwell(1), t_dwell(end));
        fprintf('Peak Error:   %e m\n', peak_error);
        fprintf('RMS Error:    %e m\n', rms_error);
        fprintf('--------------------------------------------------\n');
        
        % Plot the reference only once to avoid overlapping clutter
        if ~ref_plotted
            plot(t, r_y(:,1), 'k--', 'LineWidth', 1.2); % Black dashed reference
            ref_plotted = true;
            
            % Dynamically set axis limits using the new buffers
            xlim([t_dwell(1) - x_buffer, t_dwell(end) + x_buffer]);
            
            % Find the general reference level (usually 0.1) and apply the y_buffer
            ref_level = mean(ref_dwell);
            ylim([ref_level - y_buffer, ref_level + y_buffer]); 
        end
        
        % Plot the specific dataset response
        plot(t, y_c(:,1), 'LineStyle', '-', 'LineWidth', 1.2, 'Color', colors(i,:));
        
        % Add placeholder for this dataset's legend name
        legend_entries{i+1} = sprintf('Dataset %d', i);
    else
        fprintf('Dataset %d: Reference r_y(:,1) never reached 0.1 threshold.\n', i);
    end
end

%% Formatting & IEEE Standards
xlabel('Time (s)', 'Interpreter', 'latex');
ylabel('Response', 'Interpreter', 'latex');

% IEEE typical font settings
set(gca, 'FontSize', 9, 'FontName', 'Times New Roman', 'TickLabelInterpreter', 'latex'); 

% Clean up the legend (remove empty cells if a dataset failed the threshold check)
legend_entries = legend_entries(~cellfun('isempty', legend_entries));

% Override legend entries if filled in
if ~isempty(custom_legend)
    legend_entries = custom_legend;
end

% Render the legend
leg = legend(legend_entries, 'Location', 'southeast', 'Interpreter', 'latex');
leg.ItemTokenSize = [15, 18]; % Keeps the legend compact

hold off;

%% Export
export_folder = 'Exports'; % Specify your folder name here

% Check if the folder exists; if not, create it
if ~exist(export_folder, 'dir')
    mkdir(export_folder);
end

% Construct the full file path safely (e.g., 'Exports/exp_SISO_BF.pdf')
file_path = fullfile(export_folder, sprintf('%s_dwell.pdf', dataset));

% Export the figure as a vector PDF
exportgraphics(fig, file_path, 'ContentType', 'vector');