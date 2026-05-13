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

%% 1.d.
% Define closed loop system
S = feedback(1, G*C); 
GS = feedback(G, C);

%% Exercise 4.a: Construct J for trial length N=100
% N_short = 100;
N_short = N;
[h, ~] = dimpulse(GS.A, GS.B, GS.C, GS.D, 1, N_short);

% Clean small elements (e.g., due to numerical noise)
h(abs(h) < 1e-12) = 0;

col = h; 
row = zeros(1, N_short); 
row(1) = h(1); % This is h_0

J = toeplitz(col, row);

% Visual inspection as requested in 4.a
figure; imagesc(J); colorbar; title('Structure of J (imagesc)');
figure; mesh(J); title('Structure of J (mesh)');

%% Exercise 4.b.
w_e = 10^3;
W_e = w_e * eye(N_short);
w_f = 10^-3;
W_f = w_f * eye(N_short);
w_Delta_f = 10^-1;
W_Delta_f = w_Delta_f * eye(N_short);

% Compute Optimal Lifted ILC Matrices
InvTerm = inv(J'*W_e*J + W_f + W_Delta_f);
L_lifted = InvTerm * J' * W_e;
Q_lifted = InvTerm * (J' * W_e * J + W_Delta_f);

% Inspect structure: diagonal plot[cite: 2]
figure; plot(diag(L_lifted, 0)); title('Main diagonal of L');

%% check (monotonic) convergence
if max(svd(Q_lifted - L_lifted*J)) < 1
    fprintf('Monotonic convergence: yes\n');
else
    fprintf('Monotonic convergence: no\n');
end



%% Save ILC filters.
if save_switch
    % Modify line below to choose which variables to save
    save('ILCController','Q_lifted','L_lifted','GS','Ts');    
    disp('Parameters saved!');
end