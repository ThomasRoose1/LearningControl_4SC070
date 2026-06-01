%% Custom simulation of Arizona printer
clear; close all; clc;

%% Load parametric model 
load('models/P_centralized.mat'); % Assuming this is a state-space object 'P'

%% Decouple model
Tu = [0.5000   -0.3817;
      0.5000    0.3817];
Ty = [0.5000    0.5000;
     -0.3817    0.3817];
 
P_decoupled = Ty * P * Tu;

% Convert the MIMO system to Transfer Function
P_tf = tf(P_decoupled);

%% Isolate the diagonal SISO loops
Px = minreal(P_tf(1, 1)); 
Pphi = minreal(P_tf(2, 2));

%% Load ref
load('references/Reference_X_slow.mat')

% % plot reference
% figure;
% subplot(3,1,1); plot(t,phiref);
% ylabel('phi');
% xlabel('s');
% 
% subplot(3,1,2); plot(t,xref);
% ylabel('x');
% xlabel('s');
% 
% subplot(3,1,3); plot(t,yref);
% xlabel('y');
% xlabel('s');

