%% Makes a plot of dwell time based on multiple datasets (IEEE Style)
clear; clc; close all; 

%% Settings
target_trial = 10; % You can change this to 'end' if you dynamically want the last trial
dataset = 'exp_SISO_BF';    % select dataset, if you want to add new data, make a new entry below

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
figure('Units', 'inches', 'Position', [1, 1, 3.5, 2.5]);
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
    
    % Decouple output data
    y_c = y * invTy_T;   
    
    % Identify Dwell Time and Compute Errors
    dwell_indices = find(r_y(:,1) >= 0.09); 
    
    if ~isempty(dwell_indices)
        t_dwell = t(dwell_indices);
        ref_dwell = r_y(dwell_indices, 1);
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
            
            % Dynamically set axis limits based on the first dataset's dwell time
            buffer = 0.05; 
            xlim([t_dwell(1) - buffer, t_dwell(end) + buffer]);
            ylim([0.099, 0.102]); 
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
leg = legend(legend_entries, 'Location', 'best', 'Interpreter', 'latex');
leg.ItemTokenSize = [15, 18]; % Keeps the legend compact

hold off;