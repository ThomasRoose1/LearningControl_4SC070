%% Perform interation analysis by using a nonparametric data to obtain an RGA
clear; clc; close all;

%% Load data
% The data consist of the transformation matrices used to decouple the
% system and the measured frd objects
load('Gantry_FRF_centralized.mat');

%% bode plots of frd objects
fig = figure('Name', 'Non-parametric FRF Grid');

% We use a single 4x2 layout: 
% Column 1 holds Input 1 (Top 2 rows = Output 1, Bottom 2 rows = Output 2)
% Column 2 holds Input 2 (Top 2 rows = Output 1, Bottom 2 rows = Output 2)
main_layout = tiledlayout(4, 2, 'TileSpacing', 'compact', 'Padding', 'compact');

% Pre-allocate an array to link x-axes later
all_axes = gobjects(1, 8);
ax_idx = 1;

% Loop through the 2x2 MIMO system
for out_idx = 1:2
    for in_idx = 1:2   
        % Extract the specific SISO channel data
        [mag, phase, w] = bode(P_carriage_left(out_idx, in_idx));

        % Squeeze out the singleton dimensions
        mag = squeeze(mag);
        phase = squeeze(phase);
        w = squeeze(w);

        % Convert frequency from rad/s to Hz
        f_hz = w / (2 * pi);
        
        % Wrap the phase tightly between -180 and 180 degrees
        phase_wrapped = mod(phase + 180, 360) - 180;

        % Calculate the exact tile indices for Mag and Phase in our 4x2 layout
        % Channel (1,1) -> Tiles 1 and 3
        % Channel (1,2) -> Tiles 2 and 4
        % Channel (2,1) -> Tiles 5 and 7
        % Channel (2,2) -> Tiles 6 and 8
        mag_tile   = (out_idx - 1) * 4 + in_idx;
        phase_tile = mag_tile + 2;

        % --- Top Subplot: Magnitude ---
        ax_mag = nexttile(main_layout, mag_tile);
        all_axes(ax_idx) = ax_mag;
        ax_idx = ax_idx + 1;
        semilogx(f_hz, 20*log10(mag), 'LineWidth', 1.5, 'Color', '#0072BD');
        grid on;
        ylabel(sprintf('|G_{%d%d}| (dB)', out_idx, in_idx)); % Updated unique label
        set(ax_mag, 'XTickLabel', []); % Completely hide X-axis numbers

        % --- Bottom Subplot: Phase ---
        ax_phase = nexttile(main_layout, phase_tile);
        all_axes(ax_idx) = ax_phase;
        ax_idx = ax_idx + 1;
        semilogx(f_hz, phase_wrapped, 'LineWidth', 1.5, 'Color', '#D95319');
        grid on;
        ylabel(sprintf('\\angle G_{%d%d} (deg)', out_idx, in_idx)); % Updated unique label
        
        % Only show the X-label on the absolute bottom row of the figure
        if out_idx == 2
            xlabel('Frequency (Hz)');
        else
            set(ax_phase, 'XTickLabel', []); 
        end
    end
end
% Link all x-axes across the entire figure so zooming/panning stays synchronized
linkaxes(all_axes, 'x')

% export
exportgraphics(fig, 'Figures/Bodeplot_original.jpeg', 'Resolution', 300);

%% Compute RGA
%Extract FRF data dimensions and points
G_data = P_carriage_left.ResponseData; 
freqs  = P_carriage_left.Frequency; % Extract the frequency vector (rad/s)
NumFreq = length(freqs);

% Pre-allocate a matrix to hold the RGA values over all frequencies
RGA_data = zeros(2, 2, NumFreq);

% Calculate RGA at each frequency point
for k = 1:NumFreq
    % Get the 2x2 complex matrix at the current frequency point
    G_w = G_data(:, :, k);
    
    % Compute RGA: G .* transpose(inv(G))
    % Using Cramer's rule / matrix inversion natively handled by MATLAB
    RGA_w = G_w .* (inv(G_w).'); 
    
    % Store the result
    RGA_data(:, :, k) = RGA_w;
end

%% Plot the 2x2 RGA Grid
fig = figure('Name', 'Relative Gain Array (RGA) 2x2 Analysis');
rga_layout = tiledlayout(2, 2, 'TileSpacing', 'compact', 'Padding', 'compact');

% An array to hold the 4 axes handles for x-axis linking
rga_axes = zeros(1, 4);

plot_idx = 1;
for out_idx = 1:2
    for in_idx = 1:2
        
        % Move to the next tile in the 2x2 grid
        rga_axes(plot_idx) = nexttile(rga_layout);
        
        % Extract RGA values across frequencies for the current channel
        rga_channel = squeeze(real(RGA_data(out_idx, in_idx, :)));
        
        % Plot the real part of the RGA element
        loglog(freqs, abs(rga_channel), 'LineWidth', 2);
        grid on;
        
        % Labeling and formatting
        ylabel(sprintf('|\\Lambda_{%d%d}|', out_idx, in_idx));
        % title(sprintf('RGA Element \\lambda_{%d%d}', out_idx, in_idx));
        
        % Only apply x-labels to the bottom row plots for a cleaner look
        if out_idx == 2
            xlabel('Frequency [Hz]');
        else
            set(rga_axes(plot_idx), 'XTickLabel', []);
        end

        % add yline
        if out_idx == in_idx
            yline(1, '--', 'k--', 'LineWidth', 2); 
        else
            yline(0, '--', 'k--', 'LineWidth', 2); 
        end
        
        plot_idx = plot_idx + 1;
    end
end

% Link the x-axes of all 4 RGA plots so zooming tracks together
linkaxes(rga_axes, 'x');

% export
exportgraphics(fig, 'Figures/RGA_original.jpeg', 'Resolution', 300);

%% decouple using the given transformation matrices
P_decoupled = Ty*P_carriage_left*Tu;

%% Makes the same plots
% Compute RGA
%Extract FRF data dimensions and points
G_data_decoupled = P_decoupled.ResponseData;

% Pre-allocate a matrix to hold the RGA values over all frequencies
RGA_data_decoupled = zeros(2, 2, NumFreq);

% Calculate RGA at each frequency point
for k = 1:NumFreq
    % Get the 2x2 complex matrix at the current frequency point
    G_w = G_data_decoupled(:, :, k);
    
    % Compute RGA: G .* transpose(inv(G))
    % Using Cramer's rule / matrix inversion natively handled by MATLAB
    RGA_w = G_w .* (inv(G_w).'); 
    
    % Store the result
    RGA_data_decoupled(:, :, k) = RGA_w;
end

%% Plot the 2x2 RGA Grid
fig = figure('Name', 'Relative Gain Array (RGA) 2x2 Analysis');
rga_layout = tiledlayout(2, 2, 'TileSpacing', 'compact', 'Padding', 'compact');

% An array to hold the 4 axes handles for x-axis linking
rga_axes = zeros(1, 4);

plot_idx = 1;
for out_idx = 1:2
    for in_idx = 1:2
        
        % Move to the next tile in the 2x2 grid
        rga_axes(plot_idx) = nexttile(rga_layout);
        
        % Extract RGA values across frequencies for the current channel
        rga_channel = squeeze(real(RGA_data_decoupled(out_idx, in_idx, :)));
        
        % Plot the real part of the RGA element
        loglog(freqs, abs(rga_channel), 'LineWidth', 2);
        grid on;
        
        % Labeling and formatting
        ylabel(sprintf('|\\Lambda_{%d%d}|', out_idx, in_idx));
        % title(sprintf('RGA Element \\lambda_{%d%d}', out_idx, in_idx));
        
        % Only apply x-labels to the bottom row plots for a cleaner look
        if out_idx == 2
            xlabel('Frequency [Hz]');
        else
            set(rga_axes(plot_idx), 'XTickLabel', []);
        end

        % add yline
        if out_idx == in_idx
            yline(1, '--', 'k--', 'LineWidth', 2); 
        else
            yline(0, '--', 'k--', 'LineWidth', 2); 
        end
        
        plot_idx = plot_idx + 1;
    end
end

% Link the x-axes of all 4 RGA plots so zooming tracks together
linkaxes(rga_axes, 'x');

% export
exportgraphics(fig, 'Figures/RGA_decoupled.jpeg', 'Resolution', 300);

%% Plot the Combined 2x2 RGA Grid
fig_rga = figure('Name', 'Relative Gain Array (RGA) Comparison 2x2');
rga_layout = tiledlayout(2, 2, 'TileSpacing', 'compact', 'Padding', 'compact');
rga_axes = zeros(1, 4);
plot_idx = 1;

for out_idx = 1:2
    for in_idx = 1:2
        
        % Move to the next tile in the 2x2 grid
        rga_axes(plot_idx) = nexttile(rga_layout);
        
        % Extract RGA real values for both systems
        rga_orig = squeeze(real(RGA_data(out_idx, in_idx, :)));
        rga_dec  = squeeze(real(RGA_data_decoupled(out_idx, in_idx, :)));
        
        % Plot both datasets together on a loglog axis
        loglog(freqs, abs(rga_orig), 'b', 'LineWidth', 2'); 
        hold on;
        loglog(freqs, abs(rga_dec), 'r', 'LineWidth', 2); 
        
        grid on;
        
        % Labeling and formatting
        ylabel(sprintf('|\\Lambda_{%d%d}|', out_idx, in_idx));
        
        % Only apply x-labels to the bottom row plots for a cleaner look
        if out_idx == 2
            xlabel('Frequency [Hz]');
        else
            set(rga_axes(plot_idx), 'XTickLabel', []);
        end
        
        % Add the target interaction reference line
        if out_idx == in_idx
            yline(1, 'k--', 'LineWidth', 1.5); 
        else
            yline(0, 'k--', 'LineWidth', 1.5); 
        end
        
        % Add a legend to just the first cell to prevent cluttering the layout
        if out_idx == 1 && in_idx == 1
            legend('Original System', 'Decoupled System', 'Location', 'best');
        end
        
        hold off;
        plot_idx = plot_idx + 1;
    end
end

% Link the x-axes of all 4 RGA plots so zooming tracks together
linkaxes(rga_axes, 'x');
% export
exportgraphics(fig_rga, 'Figures/RGA_Comparison.png', 'Resolution', 300);