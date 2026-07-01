%% Makes a plot of dwell time and history.f based on multiple datasets (IEEE Style)
clear; clc; 
% close all; 

%% Settings
target_trial = 10; % You can change this to 'end' if you dynamically want the last trial

% --- TIME RANGE SELECTION FOR F HISTORY ---
% Define the time range [start_time, end_time] in seconds.
% Set to [] if you want it to automatically show the full duration.
f_plot_time_range = [0.5, 1.7]; 
% -----------------------------------------------

% --- SETTLING TIME BOUND ---
% Define the absolute error bound to consider the system "settled" (in meters).
% For example, 0.002 means it has settled when the error stays within +/- 2 mm.
settling_error_band = 0.000; 
% -----------------------------------------------

% select dataset, if you want to add new data, make a new entry below
dataset = 'exp_1';

% Set window size buffers (for Dwell plot)
x_buffer = 0.05;  
y_buffer = 0.005; 

%% Load selected data set
custom_legend = {};
switch dataset
    case 'sim_SISO_BF'
        data_names = {'sim/1_SISO_BF/SISO_na0_nb2_1', ...
                      'sim/1_SISO_BF/SISO_na0_nb3_1', ...
                      'sim/1_SISO_BF/SISO_na0_nb4_1'};
        custom_legend = {'$r$', '$n_b = 2$', '$n_b = 3$', '$n_b = 4$'};
        plot_shaped_flags = [false, false, false];
        
    case 'exp_SISO_BF'
        data_names = {'22_06/1_SISO_BF/SISO_na0_nb2_2', ...
                      '22_06/1_SISO_BF/SISO_na0_nb2_3', ...
                      '22_06/1_SISO_BF/SISO_na0_nb4_1p5'};
        custom_legend = {'$r$', '$n_b = 2$', '$n_b = 3$', '$n_b = 4$'};
        plot_shaped_flags = [false, false, false];
        
    case 'sim_SISO_BFIS'
        data_names = {'sim/2_SISO_BFIS/SISO_BFIS_na1_nb2_1', ...
                      'sim/2_SISO_BFIs/SISO_BFIS_na2_nb2_2', ...
                      'sim/2_SISO_BFIs/SISO_BFIS_na3_nb2_1', ...
                      'sim/2_SISO_BFIs/SISO_BFIS_na4_nb2_1'};
        custom_legend = {'$r$', '$n_a = 1$', '$n_a = 2$', '$n_a = 3$', '$n_a = 4$'};
        plot_shaped_flags = [true, true, true, true];
        
    case 'sim_SISO_BF_vs_MIMO_BF'
        data_names = {'sim/1_SISO_BF/SISO_na0_nb2_1', ...
                      'sim/3_MIMO_BF/MIMO_BF_nbx2_nbphi2_3'};
        custom_legend = {'$r$','SISO BF','MIMO BF'};
        plot_shaped_flags = [false, false];
        
    case 'sim_SISO_BF_vs_SISO_BFIS'
        data_names = {'sim/1_SISO_BF/SISO_na0_nb2_2', ...
                      'sim/2_SISO_BFIs/SISO_BFIS_na2_nb2_1'};
        custom_legend = {'$r$', 'SISO BF', 'SISO BFIS'};
        plot_shaped_flags = [false, true];
        
    case 'sim_ALL'
        data_names = {'sim/1_SISO_BF/SISO_na0_nb2_1', ...
                      'sim/2_SISO_BFIs/SISO_BFIS_na2_nb2_2', ...  
                      'sim/3_MIMO_BF/MIMO_BF_nbx2_nbphi2_3'};
        custom_legend = {'$r$', 'SISO BF', 'SISO BFIS', 'MIMO BF'};
        plot_shaped_flags = [false, true, false];
        
    case 'exp_ALL'
        data_names = {'22_06/1_SISO_BF/SISO_na0_nb2_2', ...
                      '22_06/2_SISO_BFIS/SISO_na3_nb2_2p4', ...
                      '22_06/3_MIMO_BF/MIMO_nbx2_nbphi2_3p1'};
        custom_legend = {'$r$', 'SISO BF', 'SISO BFIS', 'MIMO BF'};
        plot_shaped_flags = [false, true, false];
    case 'exp_1'
        data_names = {'22_06/1_SISO_BF/SISO_na0_nb2_3'};
        custom_legend = {'$r$', 'SISO BF'};   
        plot_shaped_flags = [false];
    case 'exp_2'
        data_names = {'22_06/1_SISO_BF/SISO_na0_nb2_3', ...
                      '22_06/2_SISO_BFIS/SISO_na3_nb2_2p4'};
        custom_legend = {'$r$', 'SISO BF', 'SISO BFIS'};    
        plot_shaped_flags = [false, false];
end
num_datasets = length(data_names);

%% Decoupling Matrices (Constant)
Tu = [0.5, -0.3817;
      0.5,  0.3817];
Ty = [0.5,     0.5;
     -0.3817, 0.3817];
invTy_T = inv(Ty).'; 

%% Prepare Figures
% Figure 1: Dwell Time Performance
fig1 = figure('Units', 'inches', 'Position', [1, 1, 3.5, 2.5]);
hold on; grid on; box on;

% Figure 2: Last Non-NaN f history
fig2 = figure('Units', 'inches', 'Position', [5, 1, 3.5, 2.5]);
hold on; grid on; box on;

% Define colors for responses
colors = lines(num_datasets);

% Pre-allocate legend entries
legend_entries_dwell = cell(1, num_datasets + 1);
legend_entries_dwell{1} = 'Reference ($r$)';
legend_entries_f = cell(1, num_datasets);
ref_plotted = false;

%% Process and Plot Each Dataset
for i = 1:num_datasets
    % Load data
    data = load(data_names{i});
    t = data.history.t;
    
    % Read the manual hardcoded flag for this specific dataset
    plot_shaped_ref = plot_shaped_flags(i);
    
    % ---------------------------------------------------------
    % 1. Extract and Plot Dwell Data (Figure 1)
    % ---------------------------------------------------------
    figure(fig1);
    
    r_raw = squeeze(data.history.r(target_trial, :, 2:3)); % Normal reference
    r_y   = squeeze(data.history.r_y(target_trial, :, 2:3)); % Shaped reference
    y     = squeeze(data.history.p(target_trial, :, 2:3)); % Actual position
    
    % Transform the output and normal ref data back to x_1 and x_2
    y_c = y * invTy_T;   
    r_c = r_raw * invTy_T; 
    
    % Identify Dwell Time and Compute Errors against the NORMAL ref
    dwell_indices = find(r_raw(:,1) >= 0.09); 
    
    if ~isempty(dwell_indices)
        t_dwell = t(dwell_indices);
        ref_dwell = r_c(dwell_indices, 1);
        resp_dwell = y_c(dwell_indices, 1);
        
        error_dwell = ref_dwell - resp_dwell;
        peak_error = max(abs(error_dwell));
        rms_error = rms(error_dwell); 
        
        % --- COMPUTE SETTLING TIME ---
        unsettled_idx = find(abs(error_dwell) > settling_error_band, 1, 'last');
        
        if isempty(unsettled_idx)
            settling_time = 0; 
        elseif unsettled_idx == length(error_dwell)
            settling_time = NaN; 
        else
            settling_time = t_dwell(unsettled_idx + 1) - t_dwell(1);
        end
        % -----------------------------
        
        fprintf('--- Dataset %d Metrics: %s ---\n', i, data_names{i});
        fprintf('Dwell Window:  %.3f s to %.3f s\n', t_dwell(1), t_dwell(end));
        fprintf('Peak Error:    %e m\n', peak_error);
        fprintf('RMS Error:     %e m\n', rms_error);
        
        if isnan(settling_time)
            fprintf('Settling Time: FAILED to settle within +/- %.4f m band\n', settling_error_band);
        else
            fprintf('Settling Time: %.3f s\n', settling_time);
        end
        fprintf('--------------------------------------------------\n');
        
        % Plot References
        if ~ref_plotted
            % Plot the main normal reference line
            plot(t, r_raw(:,1), 'k--', 'LineWidth', 1.2); 
            
            % Plot the settling band boundaries
            plot(t, r_raw(:,1) + settling_error_band, 'k:', 'LineWidth', 1.0, 'HandleVisibility', 'off');
            plot(t, r_raw(:,1) - settling_error_band, 'k:', 'LineWidth', 1.0, 'HandleVisibility', 'off');
            
            ref_plotted = true;
            xlim([t_dwell(1) - x_buffer, t_dwell(end) + x_buffer]);
            ref_level = mean(ref_dwell);
            ylim([ref_level - y_buffer, ref_level + y_buffer]); 
        end
        
        % Plot the dataset's actual response
        plot(t, y_c(:,1), 'LineStyle', '-', 'LineWidth', 1.2, 'Color', colors(i,:));
        legend_entries_dwell{i+1} = sprintf('Dataset %d', i);
        
        % Plot the shaped reference if the flag is true
        if plot_shaped_ref
            plot(t, r_y(:,1), 'LineStyle', '-.', 'LineWidth', 1.2, 'Color', colors(i,:), 'HandleVisibility', 'off');
        end
        
    else
        fprintf('Dataset %d: Reference r(:,1) never reached 0.09 threshold.\n', i);
    end
    
    % ---------------------------------------------------------
    % 2. Extract and Plot Last Valid f Data (Figure 2)
    % ---------------------------------------------------------
    figure(fig2);
    
    f_all = data.history.f;
    num_trials_f = size(f_all, 1);
    last_valid_trial = num_trials_f; 
    
    % Loop backwards to find the first trial that actually contains data
    for tr = num_trials_f:-1:1
        f_trial = squeeze(f_all(tr, :, :));
        if ~all(isnan(f_trial(:))) && ~all(f_trial(:) == 0)
            last_valid_trial = tr;
            break;
        end
    end
    
    % Extract channel 2
    if ndims(f_all) >= 3 && size(f_all, 3) >= 2
        f_plot = squeeze(f_all(last_valid_trial, :, 2));
    else
        f_plot = squeeze(f_all(last_valid_trial, :));
    end
    
    plot(t, f_plot, 'LineStyle', '-', 'LineWidth', 1.2, 'Color', colors(i,:));
    
    if ~isempty(custom_legend)
        legend_entries_f{i} = custom_legend{i+1};
    else
        legend_entries_f{i} = sprintf('Dataset %d', i);
    end
end

%% Formatting & IEEE Standards (Figure 1 - Dwell)
figure(fig1);
xlabel('Time (s)', 'Interpreter', 'latex');
ylabel('Response', 'Interpreter', 'latex');
set(gca, 'FontSize', 9, 'FontName', 'Times New Roman', 'TickLabelInterpreter', 'latex'); 

legend_entries_dwell = legend_entries_dwell(~cellfun('isempty', legend_entries_dwell));
if ~isempty(custom_legend)
    legend_entries_dwell = custom_legend;
end

leg1 = legend(legend_entries_dwell, 'Location', 'southeast', 'Interpreter', 'latex');
leg1.ItemTokenSize = [15, 18]; 
hold off;

%% Formatting & IEEE Standards (Figure 2 - f History)
figure(fig2);
xlabel('Time (s)', 'Interpreter', 'latex');
ylabel('Feedforward Signal ($f$)', 'Interpreter', 'latex');
set(gca, 'FontSize', 9, 'FontName', 'Times New Roman', 'TickLabelInterpreter', 'latex'); 

% Apply the time range selection if it is not empty
if ~isempty(f_plot_time_range)
    xlim(f_plot_time_range);
end

legend_entries_f = legend_entries_f(~cellfun('isempty', legend_entries_f));

leg2 = legend(legend_entries_f, 'Location', 'best', 'Interpreter', 'latex');
leg2.ItemTokenSize = [15, 18];
hold off;

%% Export
export_folder = 'Exports'; 
if ~exist(export_folder, 'dir')
    mkdir(export_folder);
end

% Export Dwell Plot
file_path_dwell = fullfile(export_folder, sprintf('%s_dwell.pdf', dataset));
exportgraphics(fig1, file_path_dwell, 'ContentType', 'vector');

% Export f History Plot
file_path_f = fullfile(export_folder, sprintf('%s_f_history.pdf', dataset));
exportgraphics(fig2, file_path_f, 'ContentType', 'vector');