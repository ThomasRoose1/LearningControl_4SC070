clear all; close all; clc;

%% Switches
save_switch = 1;
sim_switch = 0;

%% Parameters
fs = 1000;         % sample frequency\\
Ts = 1/fs;         % sample time

%% System model, system frequency response measurement and controller.
% System model and FRF measurement.
load('PrinterModel2020.mat');
G = PrinterModelSS;
Gfrf = PrinterModelFRF;

% Feedback controller.
load('PrinterController.mat');
C = minreal(shapeit_data.C_tf_z);

Gfrd = frd(Gfrf.frf,Gfrf.freq*2*pi,Ts);

%% 4.1a
N = 4501;
GS = feedback(G, C);
GS = minreal(GS);

% Discrete impulse response of GS
[g, t] = dimpulse(GS.A, GS.B, GS.C, GS.D,1,N);

% Construct lifted matrix J
J = toeplitz(g, [g(1); zeros(N-1,1)]);

% Remove very small numerical entries
J(abs(J) < 1e-8) = 0;

% Inspect structure
% figure;
% mesh(J);
% title('Mesh plot of J');
% 
% figure;
% imagesc(J);
% colorbar;
% title('Imagesc of J');

%% 4.1b
we  = 1e3;
wf  = 1e-3;
wdf = 5e-1;

We  = we  * eye(N);
Wf  = wf  * eye(N);
Wdf = wdf * eye(N);

% Compute lifted ILC matrices
L = (J'*We*J + Wf + Wdf)\(J'*We);

Q = (J'*We*J + Wf + Wdf)\(J'*We*J + Wdf);

% figure;
% hold on;
% for k = -5:5
%     plot(diag(L,k));
% end
% title('Diagonals of L');
% grid on;

% figure;
% hold on;
% for k = -5:5
%     plot(diag(Q,k));
% end
% title('Diagonals of Q');
% grid on;
% 
% figure;
% mesh(L);
% xlabel('Column index');
% ylabel('Row index');
% zlabel('Amplitude');
% title('Mesh plot of lifted ILC matrix L');
% 
% figure;
% imagesc(L);
% colorbar;
% xlabel('Column index');
% ylabel('Row index');
% title('Imagesc of lifted ILC matrix L');
% 
% figure;
% mesh(Q);
% xlabel('Column index');
% ylabel('Row index');
% zlabel('Amplitude');
% title('Mesh plot of lifted ILC matrix Q');
% 
% figure;
% imagesc(Q);
% colorbar;
% xlabel('Column index');
% ylabel('Row index');
% title('Imagesc of lifted ILC matrix Q');

%% Convergence and monotonic convergence analysis
% Assumes J and L are already computed
% Iteration matrix
M = Q - L*J;

%% ------------------------------------------------------------------------
% 1. Convergence condition
% Convergence iff spectral radius rho(M) < 1
% -------------------------------------------------------------------------

% eig_M = eig(M);
% rho_M = max(abs(eig_M));
% 
% disp('Eigenvalues of (Q - LJ):');
% disp(max(abs(eig_M)));
% 
% fprintf('Spectral radius rho(M) = %f\n', rho_M);
% 
% if rho_M < 1
%     fprintf('=> ILC converges\n');
% else
%     fprintf('=> ILC does NOT converge\n');
% end

%% ------------------------------------------------------------------------
% 2. Monotonic convergence condition
% Monotonic convergence iff ||M||_2 < 1
% -------------------------------------------------------------------------

% norm_M = norm(M,2);
% 
% fprintf('2-norm ||M||_2 = %f\n', norm_M);
% 
% if norm_M < 1
%     fprintf('=> Monotonic convergence guaranteed\n');
% else
%     fprintf('=> Monotonic convergence NOT guaranteed\n');
% end


%% ================================================================
% SIMULATION OF ILC
% ================================================================
if sim_switch
    nIter = 30;
    
    % Reference signal (use same length as lifted system)
    load('trajectory.mat');
    r = x_ref(1:N);
    
    % initial feedforward
    f_j = zeros(N,1);
    
    error_norm = zeros(nIter,1);
    
    for k = 1:nIter
    
        % simulate system (lifted)
        y_j = J * f_j;
    
        % error
        e_j = r - y_j;
    
        error_norm(k) = norm(e_j,2);
    
        % ============================================================
        % LIFTED ILC UPDATE
        % ============================================================
        f_jplus1 = Q*f_j + L*e_j;
    
        % optional smoothing interpretation (regularization effect visible)
        % f_jplus1 = f_j + L*e_j;
    
        f_j = f_jplus1;
    
    end
    
    
    figure;
    semilogy(1:nIter, error_norm, 'o-');
    xlabel('Iteration');
    ylabel('||e_j||_2');
    title('Lifted ILC Convergence (N = 4501)');
    grid on;
end

%% save
if save_switch
    % Get folder of this script/function
    thisFile = mfilename('fullpath');
    thisDir  = fileparts(thisFile);

    % Build save path in same directory
    savePath = fullfile(thisDir, 'LiftedILC.mat');

    % Save variables
    save(savePath, 'Q', 'L');

    disp(['Parameters saved to: ', savePath]);
end
