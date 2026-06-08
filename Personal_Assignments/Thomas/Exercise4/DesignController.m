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

% % Visual inspection as requested in 4.a
% fig1 = figure; imagesc(J); colorbar; title('Structure of J (imagesc)');
% fig2 = figure; mesh(J); title('Structure of J (mesh)');
% 
% % export
% exportgraphics(fig1, "Exports/plot_4a_top.pdf", "ContentType", "vector", "BackgroundColor", "none");
% exportgraphics(fig2, "Exports/plot_4a_mesh.pdf", "ContentType", "vector", "BackgroundColor", "none");

%% Exercise 4.b.
w_e = 10^3;
W_e = w_e * eye(N_short);

w_f = 10^-3;
% w_f = 0;
W_f = w_f * eye(N_short);

w_Delta_f = 10;
W_Delta_f = w_Delta_f * eye(N_short);

% Compute Optimal Lifted ILC Matrices
InvTerm = inv(J'*W_e*J + W_f + W_Delta_f);
L_lifted = InvTerm * J' * W_e;
Q_lifted = InvTerm * (J' * W_e * J + W_Delta_f);

% % Inspect structure L
% fig1 = figure; mesh(L_lifted)
% % Inspect structure: 10 diagonals centered and colored
% fig2 = figure;
% hold on;
% num_diags = 10;
% % Select 10 diagonals centered around the main diagonal (k=0)
% % We use -4 to 5 to get exactly 10 diagonals
% diags_to_plot = -4:5; 
% colors = lines(num_diags); % Generates 10 distinct colors
% 
% for i = 1:length(diags_to_plot)
%     k = diags_to_plot(i);
%     d = diag(L_lifted, k);
% 
%     % To center/align them nicely, we plot them against their row indices.
%     % If k > 0 (upper diag), the first element is at row 1.
%     % If k < 0 (lower diag), the first element is at row 1-k.
%     row_indices = (1:length(d)) + max(0, -k);
% 
%     plot(row_indices, d, 'Color', colors(i,:), 'LineWidth', 1.5, ...
%          'DisplayName', sprintf('Diag k=%d', k));
% end
% 
% % title('10 Centered Diagonals of L_{lifted}');
% xlabel('Row Index (i)');
% ylabel('Value L(i, i+k)');
% grid on;
% legend('Location', 'northeastoutside');
% hold off;
% 
% % export
% exportgraphics(fig1, "Exports/plot_4b_Lmesh.pdf", "ContentType", "vector", "BackgroundColor", "none");
% exportgraphics(fig2, "Exports/plot_4b_Ldiag.pdf", "ContentType", "vector", "BackgroundColor", "none");
% 
% % Inspect structure Q
% fig1 = figure; mesh(Q_lifted)
% % Inspect structure: 10 diagonals centered and colored
% fig2 = figure;
% hold on;
% num_diags = 10;
% % Select 10 diagonals centered around the main diagonal (k=0)
% % We use -4 to 5 to get exactly 10 diagonals
% diags_to_plot = -4:5; 
% colors = lines(num_diags); % Generates 10 distinct colors
% 
% for i = 1:length(diags_to_plot)
%     k = diags_to_plot(i);
%     d = diag(Q_lifted, k);
% 
%     % To center/align them nicely, we plot them against their row indices.
%     % If k > 0 (upper diag), the first element is at row 1.
%     % If k < 0 (lower diag), the first element is at row 1-k.
%     row_indices = (1:length(d)) + max(0, -k);
% 
%     plot(row_indices, d, 'Color', colors(i,:), 'LineWidth', 1.5, ...
%          'DisplayName', sprintf('Diag k=%d', k));
% end
% 
% % title('10 Centered Diagonals of L_{lifted}');
% xlabel('Row Index (i)');
% ylabel('Value L(i, i+k)');
% grid on;
% legend('Location', 'northeastoutside');
% hold off;
% 
% % export
% exportgraphics(fig1, "Exports/plot_4b_Qmesh.pdf", "ContentType", "vector", "BackgroundColor", "none");
% exportgraphics(fig2, "Exports/plot_4b_Qdiag.pdf", "ContentType", "vector", "BackgroundColor", "none");

%% Convergence and monotonic convergence analysis
% Assumes J and L are already computed
% Iteration matrix
M = Q_lifted - L_lifted*J;

% 1. Convergence condition
% Convergence iff spectral radius rho(M) < 1
% -------------------------------------------------------------------------

eig_M = eig(M);
rho_M = max(abs(eig_M));

disp('Eigenvalues of (Q - LJ):');
disp(max(abs(eig_M)));

fprintf('Spectral radius rho(M) = %f\n', rho_M);

if rho_M < 1
    fprintf('=> ILC converges\n');
else
    fprintf('=> ILC does NOT converge\n');
end

% ------------------------------------------------------------------------
% 2. Monotonic convergence condition
% Monotonic convergence iff ||M||_2 < 1
% -------------------------------------------------------------------------

norm_M = norm(M,2);

fprintf('2-norm ||M||_2 = %f\n', norm_M);

if norm_M < 1
    fprintf('=> Monotonic convergence guaranteed\n');
else
    fprintf('=> Monotonic convergence NOT guaranteed\n');
end



%% Save ILC filters.
if save_switch
    % Modify line below to choose which variables to save
    save('ILCController','Q_lifted','L_lifted','GS','Ts');    
    disp('Parameters saved!');
end