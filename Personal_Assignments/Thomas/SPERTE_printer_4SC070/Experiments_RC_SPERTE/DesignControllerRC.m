%DESIGNCONTROLLERRC   Use this template for designing your repetitive controller.

clear variables;
close all;
clc;


%% Parameters
fs = 1000;         % sample frequency
Ts = 1/fs;         % sample time
save_switch = 1;   % switch for saving RC filters: 1 = save, 0 = no save


%% System model, system frequency response measurement and controller.
% System model and FRF measurement.
load('PrinterModel.mat');
G = PrinterModelSS;
Gfrf = PrinterModelFRF;
freq = Gfrf.Frequency;

% Feedback controller.
load('PrinterController.mat');
C = minreal(shapeit_data.C_tf_z);

%% Exercise 3
% Define complementary sensitivity
T = feedback(G*C, 1);
[z p k] = zpkdata(T);
% Marginally stable due to single pole on unit circle

%% Exercise 3.2: RC design.
%Required outputs:
% - L_c: causal part of L. That is, L = z^{p_L}*L_c
% - p_L: number of preview samples of L
% - Q_c: causal part of Q. That is, Q = z^{p_Q}*Q_c
% - p_Q: number of preview samples of Q

%a

T = ss(T);
[a,b,c,d,p_L]=zpetc(T.a,T.b,T.c,T.d,1);
L_c = ss(a,b,c,d,Ts);    % Causal part
z = tf('z',Ts);
L = z^p_L*L_c; 
% here p_L represents the "p+d", p is non minimum phase and d is relative
% degree, both require a preview step, in total p+d = 4 here    

figure;
bode(L,L_c);

%% b
% plot (I - T*L) and check if < 1
figure; bodemag(1 - T*L); hold on;

% Define Tfrf based on Gfrf and do the same check
Tfrf = feedback(C*Gfrf, 1);
bodemag(1 - Tfrf*L); 

yline(0, 'r--', 'Linewidth', 2, 'Label', 'Mag = 1 (0 dB)');

%% c
fC = 10;                                                                    % desired cut-off frequency
fn = 1/(2*Ts);                                                              % Nyquist frequency
M = 100;                                                                     % desired order of low-pass FIR filter

num = fir1(M,fC/fn);        % create low-pass FIR filter coefficients
Q = tf(num,1,Ts);           % create filter
Q = Q*Q';                   % use Q'*Q for zero phase shift
Q = Q/freqresp(Q,0)^2;      % scale DC gain (gain at omega=0) to 1

Q_c = Q*tf(1,[1,zeros(1,M)],Ts); % Extract causal part
p_Q=M;                      % number of preview samples

bodemag(Q)

% plot Q(1 - TL)
bodemag(Q*(1 - Tfrf*L));

% bode diagram of Q and Q*Q'
figure; 
bode(Q, Q*Q');
title("Comparasion Q and Q*Q'");
legend("Q", "Q*Q'")

%% Exercise XX: save RC filters.
if save_switch
    
    % Modify line below to choose which variables to save
    save('RCController','L_c','p_L','Q_c','p_Q');    
    disp('Parameters saved!');
end