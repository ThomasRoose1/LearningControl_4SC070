%% makes a plot of dwell time based
% clear; close all; 

%% load data
% load('sim/SISO_na3_nb3_tuned.mat');
% load('sim/MIMO_na0_nb3_tuned.mat')
load('22_06/2. SISO BFIS/SISO_na3_nb2_2p3.mat');

%% Extract data of the last trial
t = history.t;
r_y = squeeze(history.r_y(10,:,2:3));
y = squeeze(history.p(10,:,2:3));

%% decouple output data
% decoupling matrices
Tu = [0.5, -0.3817;
      0.5, 0.3817];
Ty = [0.5   0.5;
      -0.3817 0.3817];
y_c = y * (inv(Ty).');

%% Identify Dwell Time and Compute Errors
% Find all indices where the reference r_y(:,1) is in the dwell state (~0.1)
dwell_indices = find(r_y(:,1) >= 0.09); 

if ~isempty(dwell_indices)
    % Extract time, reference, and response specifically for the dwell window
    t_dwell = t(dwell_indices);
    ref_dwell = r_y(dwell_indices, 1);
    resp_dwell = y_c(dwell_indices, 1);
    
    % Compute the error during the dwell time
    error_dwell = ref_dwell - resp_dwell;
    
    % Calculate Peak and RMS Error
    peak_error = max(abs(error_dwell));
    rms_error = rms(error_dwell); 
    
    % Display results in the command window
    fprintf('--- Dwell Time Metrics ---\n');
    fprintf('Dwell Window: %.3f s to %.3f s\n', t_dwell(1), t_dwell(end));
    fprintf('Peak Error:   %e m\n', peak_error);
    fprintf('RMS Error:    %e m\n', rms_error);
    fprintf('--------------------------\n');
    
    %% Plot the dwell time
    figure;
    plot(t, r_y(:,1), 'LineWidth', 1.5);
    hold on; 
    plot(t, y_c(:,1), 'LineWidth', 1.5);
    
    xlabel('Time (s)');
    ylabel('Response');
    title('Dwell Time vs Response (Zoomed In)');
    grid on;
    legend('Reference (r_y)', 'Response (y_c)', 'Location', 'best');
    
    % Dynamically set x-axis limits to match the full dwell time + a small visual buffer
    buffer = 0.05; 
    xlim([t_dwell(1) - buffer, t_dwell(end) + buffer]);
    
    % Tighten the y-axis around the 0.1 mark
    ylim([0.099, 0.102]); 
else
    disp('Reference r_y(:,1) never reached the 0.1 threshold in this dataset.');
end

% %% Plot the PSD of the reference signal
% figure;
% % Calculate the sampling frequency from the time vector
% Fs = 1 / mean(diff(t)); 
% 
% % Plot the PSD using Welch's power spectral density estimate
% % Calling pwelch without output arguments automatically plots it in dB/Hz
% pwelch(r_y(:,1), [], [], [], Fs);
% title('Power Spectral Density of Reference Signal (r_y(:,1))');