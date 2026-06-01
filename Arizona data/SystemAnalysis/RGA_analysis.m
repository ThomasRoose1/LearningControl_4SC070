%% Perform interation analysis by using a nonparametric data to obtain an RGA
clear; clc; close all;

%% Load data
% The data consist of the transformation matrices used to decouple the
% system and the measured frd objects
load('Gantry_FRF_centralized.mat');

%% bode plots of frd objects
figure('Name', 'non parametric FRF')

% Create a 2x2 layout where each cell houses its own sub-layout (Mag + Phase)
main_layout = tiledlayout(2, 2, 'TileSpacing', 'compact', 'Padding', 'compact');

% Loop through the 2x2 MIMO system
for out_idx = 1:2
    for in_idx = 1:2
        
        % Select the correct tile in the 2x2 grid
        nexttile(main_layout);
        
        % Extract the specific SISO channel data
        [mag, phase, w] = bode(P_carriage_left(out_idx, in_idx));
        
        % Squeeze out the singleton dimensions MATLAB generates for MIMO data
        mag = squeeze(mag);
        phase = squeeze(phase);
        w = squeeze(w);
        
        % Create an inner 2x1 layout inside the current 2x2 cell
        % This keeps Magnitude stacked directly on top of Phase
        inner_layout = tiledlayout(main_layout, 2, 1);
        inner_layout.Layout.Tile = (out_idx-1)*2 + in_idx; 
        
        % --- Top Subplot: Magnitude ---
        ax_mag = nexttile(inner_layout);
        semilogx(w, 20*log10(mag), 'LineWidth', 1.5, 'Color', '#0072BD');
        grid on;
        ylabel('Mag (dB)');
        title(sprintf('Cell (%d,%d)', out_idx, in_idx)); % Temporary title
        set(ax_mag, 'XTickLabel', []); % Hide X-axis labels for the top plot
        
        % --- Bottom Subplot: Phase ---
        ax_phase = nexttile(inner_layout);
        semilogx(w, phase, 'LineWidth', 1.5, 'Color', '#D95319');
        grid on;
        ylabel('Phase (deg)');
        xlabel('Frequency (rad/s)');
        
        % Link the x-axes of magnitude and phase so zooming aligns them
        linkaxes([ax_mag, ax_phase], 'x');
    end
end

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
figure('Name', 'Relative Gain Array (RGA) 2x2 Analysis');
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
        loglog(freqs, abs(rga_channel), 'LineWidth', 2, 'Color', '#7E2F8E');
        grid on;
        
        % Labeling and formatting
        ylabel(sprintf('Real(\\lambda_{%d%d})', out_idx, in_idx));
        title(sprintf('RGA Element \\lambda_{%d%d}', out_idx, in_idx));
        
        % Only apply x-labels to the bottom row plots for a cleaner look
        if out_idx == 2
            xlabel('Frequency (rad/s)');
        else
            set(rga_axes(plot_idx), 'XTickLabel', []);
        end
        
        plot_idx = plot_idx + 1;
    end
end

% Link the x-axes of all 4 RGA plots so zooming tracks together perfectly
linkaxes(rga_axes, 'x');

%% decouple using the given transformation matrices
P_decoupled = Ty*P_carriage_left*Tu;

%% Makes the same plots
% Compute RGA
%Extract FRF data dimensions and points
G_data = P_decoupled.ResponseData; 
freqs  = P_decoupled.Frequency; % Extract the frequency vector (rad/s)
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
figure('Name', 'RGA decoupled');
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
        loglog(freqs, abs(rga_channel), 'LineWidth', 2, 'Color', '#7E2F8E');
        grid on;
        
        % Labeling and formatting
        ylabel(sprintf('Real(\\lambda_{%d%d})', out_idx, in_idx));
        title(sprintf('RGA Element \\lambda_{%d%d}', out_idx, in_idx));
        
        % Only apply x-labels to the bottom row plots for a cleaner look
        if out_idx == 2
            xlabel('Frequency (rad/s)');
        else
            set(rga_axes(plot_idx), 'XTickLabel', []);
        end
        
        plot_idx = plot_idx + 1;
    end
end

% Link the x-axes of all 4 RGA plots so zooming tracks together perfectly
linkaxes(rga_axes, 'x');