function [e_filt,L,phd] = stable_inv(GS,e,ts)
% stable inversion
%
% Perform a stable inversion of a non-minimum phase discrete time SISO 
% state space model GS, and filter a signal e with the resulting 
% non-causal filter L = GS^-1. 
%
% e_filt = stable_inv(GS,e) has input arguments GS (the
% state space model to be inverted), e (the signal to be filtered,
% typically an error signal), and ts (the sample time of the discrete time
% system). The output is the signal e_filt, which is the signal e filtered 
% by L and shifted in time for phase compensation.
%
% AUTHORS: T. Oomen, L. Aarnoudse (Eindhoven University of Technology,
% Control Systems Technology)
% DATE: 29-04-2020

[Gnum,Gden] = ss2tf(GS.A,GS.B,GS.C,GS.D);

%% Check properness of GS and add delays if necessary

phd = order(tf(1,Gden,ts)) - order(tf(1,Gnum,ts));    %relative degree of GS  
z = tf('z',ts);

if phd ~= 0
    GS_p_tf = z^phd * tf(Gnum,Gden,ts);               %proper transfer function of GS
else
    GS_p_tf = tf(Gnum,Gden,ts);  
end

%% Invert GS to determine L

[GA, GB, GC, GD] = tf2ss(GS_p_tf.num{:},GS_p_tf.den{:});

LA = GA - GB*inv(GD)*GC;           
LB = GB*inv(GD);
LC = -inv(GD)*GC;
LD = inv(GD);

L = ss(LA,LB,LC,LD,ts);

[LS,LNS] = stabsep(L);              % stable/unstable decomposition of L


%% Solve stable part forward in time 

LS = tf(LS);                        % stable part of L

uff_S = filter(LS.num{:},LS.den{:},e);

%% Solve filtering of e through unstable part of L backward in time

[numNS,denNS] = tfdata(LNS,'v');    % unstable part of L

LNC = tf(fliplr(numNS),fliplr(denNS),1,'Variable','z^-1');  

uff_NS = flipud(filter(LNC.num{:},LNC.den{:},flipud(e)));

%% Combination of stable and unstable part and phase compensation 

out = uff_S + uff_NS;               

errorFiltL = out;

% Phase compensation: shift feedforward back over phd samples
e_filt = [errorFiltL(phd+1:end); zeros(phd,1)];


end