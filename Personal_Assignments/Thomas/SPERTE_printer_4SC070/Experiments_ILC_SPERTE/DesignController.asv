%DESIGNCONTROLLER   Use this template for designing your controller.
clearvars -except p Fs Ts tsim
close all;
clc;


%% Parameters
fs = 1000;         % sample frequency
Ts = 1/fs;         % sample time
N = 4501;          % trial length
save_switch = 1;   % switch for saving ILC filters: 1 = save, 0 = no save


%% System model, system frequency response measurement and controller.
% System model and FRF measurement.
load('PrinterModel2020.mat');
G = PrinterModelSS;
Gfrf = PrinterModelFRF;

% Feedback controller.
load('PrinterController.mat');
C = minreal(shapeit_data.C_tf_z);

Gfrd = frd(Gfrf.frf,Gfrf.freq*2*pi,Ts);

%% 1.a
% Continuous or discrete? open G, it will say discrete time model
G

% sampling f? given above fs = 1000;

% Nyquist f? fs/2 = 500

% collocated or collocated? plot the bode plot
% it is non-collocated because -4 slope after resonance, it is a mass spring
% damper system
% Combined Bode Plot
h = figure('Units', 'centimeters', 'Position', [1, 1, 21, 15]); % A4 width-ish

% Generate the plot with both systems
bode(G, 'b', C, 'r'); 
grid on; title('');
legend('Plant G(z)', 'Controller C(z)', 'Location', 'southwest');

% Save as PDF
exportgraphics(h, 'Exports/Bode_G_C.pdf', 'ContentType', 'vector');

% model order? see dimention of A, it is 7

% model stable? no, double integrator means unstable
abs(eig(G.A))

% controller stable? 
abs(eig(C))

% Closed loop stable?
L_loop = G * C;  
fig2 = figure; nyquist(L_loop);
xlim([-2 1]); ylim([-2 2]);
title('')
exportgraphics(fig2, 'Exports/Nyquist.pdf', 'ContentType', 'vector')

%% Bode plots of system
           % Open-loop transfer function
S = feedback(1, L_loop); % Using feedback function
GS = feedback(G, C);
figure;
% Plot S with a solid blue line
bode(S, 'b'); 
hold on;
bode(GS, 'r');

grid on;
title('Sensitivity Function S');
legend('S','GS')

%% Iterative Learning Controller design.
% Your code here ...

GS_frd = feedback(Gfrd, C);

z = tf('z',Ts);
[~,Lc,phd] = stable_inv(GS,0,Ts);                                           % Retrieve causal Lc
L = z^phd*Lc;    

figure;
bode(GS);
hold on;
bode(L);
% Learning filter L

fN = fs/2;                                                                  % Nyquist frequency
fC = [50];                                                                    % Cut-off frequency
n = [4];                                                                     % Order Q-filter

[Qb,Qa] = butter(n,fC/fN);
Q = tf(Qb,Qa,Ts);    

% %% Own system analysis 1.a
% w = Gfrf.freq*2*pi;      % rad/s
% 
% opts = bodeoptions;
% opts.PhaseWrapping = 'on';
% 
% figure;
% hold on;
% bode(G, w, opts);               % plot model
% bode(Gfrd, w, opts);            % plot FRF data
% 
% %model order
% fprintf('Model order = %d\n', size(G.A, 2));
% 
% %Check stability
% A_eig = eigs(G.A);
% fprintf('Absolute Eigenvalues Plant:\n')
% fprintf('%.4f\n', abs(A_eig))
% lambda = 1;
% n = size(G.A, 1);
% % The number of independent eigenvectors (Geometric Multiplicity)
% num_blocks = n - rank(G.A - lambda*eye(n));
% fprintf('Number of independent Jordan blocks for lambda=1: %d\n', num_blocks);
% 
% %Check controller stability
% C_Poles = pole(C);
% disp('Poles of controller:');
% disp(abs(C_Poles));
% 
% % This computes G*C / (1 + G*C) automatically
% CL = feedback(G*C, 1); 
% CL_poles = pole(CL);
% disp('Closed-loop pole magnitudes:');
% disp(abs(CL_poles));
% 
% 
% grid on;
% legend('G (state-space)', 'Gfrf (FRF data)', 'Location','best');
% title('Frequency Response: G vs. Gfrf');
% 
% figure;
% bode(C)
% grid on;
% legend('Controller C');
% %% Margins
% % 1. Define the Open-Loop and Closed-Loop systems
% L = G * C;
% T = feedback(L, 1);
% 
% figure;
% bode(L)
% grid on;
% legend('Open loop 1/(1+L)');
% 
% % 2. Calculate Gain Margin (Gm), Phase Margin (Pm), and frequencies
% % Margin returns Gm as a absolute ratio, not dB.
% [Gm, Pm, Wcg, Wcp] = margin(L);
% Gm_dB = 20*log10(Gm);
% 
% % Display the open-loop bandwidth
% if Wcp > 0
%     fprintf('Open-Loop Bandwidth (Gain Crossover): %.4f rad/s\n', Wcp);
% else
%     fprintf('Open-Loop Bandwidth: System does not cross 0dB.\n');
% end
% 
% % 4. Calculate Modulus Margin (Sm)
% % This is the inverse of the peak of the Sensitivity Function S = 1/(1+L)
% S = feedback(1, L); 
% [max_gain, ~] = norm(S, inf); % Peak magnitude of Sensitivity
% Sm = 1 / max_gain;
% 
% % --- Display Results ---
% fprintf('\n--- Control System Analysis ---\n');
% fprintf('Bandwidth:      %.4f rad/s\n', Wcp);
% fprintf('Gain Margin:    %.4f dB (at %.4f rad/s)\n', Gm_dB, Wcg);
% fprintf('Phase Margin:   %.4f deg (at %.4f rad/s)\n', Pm, Wcp);
% fprintf('Modulus Margin: %.4f\n', Sm);
% 
% 
% 
% %% estimate mass
% %Calculate m
% w = 1;
% gain = abs(freqresp(G,w));
% m = 1/(gain*w^2);
% 
% fprintf('Estimated mass m=%.4f[Kg]\n',m);

%% Plot ILC Convergence against FRF Data
f_vec = Gfrf.freq;          % Frequencies from your measurement data [Hz]
w_vec = f_vec * 2 * pi;     % [rad/s]

% 1. Compute the "True" Closed Loop using the FRF data
% This handles the (G*C)/(1+G*C) math for FRD objects properly
S_true = feedback(1,Gfrd*C);
GS_true = Gfrd * S_true;

Convergence_system = 1 - (Gfrd * S_true * L);

figure;
% Use bodemag to plot the magnitude
bodemag(Convergence_system, 'b'); 
hold on;
% 2. Define the frequency range (Starting at 20 Hz due to poor SNR)
f_min = 0.1; 
f_max = fs/2;
w_range = [f_min, f_max] * 2 * pi; % Convert to rad/s

% 3. Plot the 0 dB Stability Limit across the valid range
line(w_range, [0 0], 'Color', 'r', 'LineStyle', '--', 'LineWidth', 1.5);

% 4. Apply the x-axis limits
% This avoids the log(0) issue and hides the noisy <20Hz data
xlim(w_range); 

grid on;
title('ILC Convergence Magnitude (Valid > 20 Hz)');
legend('Convergence Response', '0 dB Limit');
%% Plot ILC Convergence against State-Space Model (Ideal Case)
% 1. Define the ideal convergence system object
% Since GS and L are LTI objects, we can perform direct subtraction
Convergence_model = 1 - (GS * L);

% 2. Create the Plot
figure;
% Plot magnitude in black ('k') as per original style
bodemag(Convergence_model, 'k'); 
hold on;

% 3. Define the valid frequency range (20 Hz to Nyquist)
% We avoid 0 Hz due to logarithmic scaling limits
f_min = 20; 
f_max = fs/2;
w_range = [f_min, f_max] * 2 * pi; % [rad/s]

% 4. Plot the 0 dB Stability Limit
line(w_range, [0 0], 'Color', 'r', 'LineStyle', '--', 'LineWidth', 1.5);

% 5. Formatting and SNR Constraint
xlim(w_range);
grid on;

% Note: bodemag handles ylabel (Magnitude dB) and x-scale automatically
title('|1 - G_{model}SL| (Ideal Model-Based Convergence)');
legend('Model Response', '0 dB Limit', 'Location', 'southwest');

%% 3. Robust Convergence Analysis (Comparison Plot)
% Define the systems
Conv_no_Q = 1 - (GS_frd * L);
Conv_with_Q = Q * Conv_no_Q; % Direct multiplication of LTI/FRD objects

figure;
% Plot both systems: 'b:' for dotted blue, 'g' for solid green
bodemag(Conv_no_Q, 'b:', Conv_with_Q, 'g');
hold on;

% Define the valid frequency range (20 Hz to Nyquist)
f_min = 20; 
f_max = fs/2;
w_range = [f_min, f_max] * 2 * pi;

% Plot the 0 dB Stability Limit
line(w_range, [0 0], 'Color', 'r', 'LineStyle', '--', 'LineWidth', 1.5);

% Formatting and SNR Constraint
xlim(w_range);
ylim([-80, 40]);
grid on;
title('Robust Convergence Analysis (Q-Filter Comparison)');
legend('|1 - GSL| (No Q)', '|Q(1 - GSL)| (With Q)', 'Stability Limit', 'Location', 'southwest');

%% Save ILC filters.
if save_switch
    % Modify line below to choose which variables to save
    save('ILCController','Qb','Qa','GS','Ts');    
    disp('Parameters saved!');
end