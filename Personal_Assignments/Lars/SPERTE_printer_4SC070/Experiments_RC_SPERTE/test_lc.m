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



T = minreal(feedback(G*C,1));
T_ss = ss(T);

[a,b,c,d,p_L]=zpetc(T.a,T.b,T.c,T.d,1);