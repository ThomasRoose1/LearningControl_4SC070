%DESIGNCONTROLLERRC   Use this template for designing your repetitive controller.

clear variables;
close all;
clc;


%% Parameters
fs = 1000;         % sample frequency
Ts = 1/fs;         % sample time
save_switch = 0;   % switch for saving RC filters: 1 = save, 0 = no save


%% System model, system frequency response measurement and controller.
% System model and FRF measurement.
load('PrinterModel.mat');
G = PrinterModelSS;
Gfrf = PrinterModelFRF;
freq = Gfrf.Frequency;

% Feedback controller.
load('PrinterController.mat');
C = minreal(shapeit_data.C_tf_z);

%% Exercise XX
% Closed-loop transfer functions

%% Exercise XX: RC design.
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

%b


%c
fC = [];                                                                    % desired cut-off frequency
fn = 1/(2*Ts);                                                              % Nyquist frequency
M = [];                                                                     % desired order of low-pass FIR filter

num = fir1(M,fC/fn);        % create low-pass FIR filter coefficients
Q = tf(num,1,Ts);           % create filter
Q = Q*Q';                   % use Q'*Q for zero phase shift
Q = Q/freqresp(Q,0)^2;      % scale DC gain (gain at omega=0) to 1

Q_c = Q*tf(1,[1,zeros(1,M)],Ts); % Extract causal part
p_Q=M;                      % number of preview samples

%% Make required plots to validate your RC design!
% Your code here ...

%% Exercise XX: save RC filters.
if save_switch
    
    % Modify line below to choose which variables to save
    save('RCController','L_c','p_L','Q_c','p_Q');    
    disp('Parameters saved!');
end