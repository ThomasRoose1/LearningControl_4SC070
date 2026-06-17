%% load the data 
load("Arizona_models_new\Models\Nonparametric\Gantry_FRF_centralized.mat");
%% RGA analysis of coupled system
G_data = P_carriage_left.ResponseData;

Nf = size(G_data,3);
RGA_c = zeros(size(G_data));

for k = 1:Nf
    Gk = G_data(:,:,k);
    RGA_c(:,:,k) = Gk .* pinv(Gk).';
end

f = P_carriage_left.Frequency;

figure;

subplot(2,2,1)
semilogx(f, squeeze(abs(RGA_c(1,1,:))))
title('|\lambda_{11}|')
grid on

subplot(2,2,2)
semilogx(f, squeeze(abs(RGA_c(1,2,:))))
title('|\lambda_{12}|')
grid on

subplot(2,2,3)
semilogx(f, squeeze(abs(RGA_c(2,1,:))))
title('|\lambda_{21}|')
grid on

subplot(2,2,4)
semilogx(f, squeeze(abs(RGA_c(2,2,:))))
title('|\lambda_{22}|')
grid on
%% RGA analyssi of decoupled system

Nf = size(G_data,3);
for k = 1:Nf
    G_tilde(:,:,k) = Ty*G_data(:,:,k)*Tu;;
end

RGA_nc = zeros(size(G_data));
for k = 1:Nf
    Gnc = G_tilde(:,:,k);
    RGA_nc(:,:,k) = Gnc .* pinv(Gnc).';
end

figure;

subplot(2,2,1)
semilogx(f, squeeze(abs(RGA_nc(1,1,:))))
title('|\lambda_{11}|')
grid on

subplot(2,2,2)
semilogx(f, squeeze(abs(RGA_nc(1,2,:))))
title('|\lambda_{12}|')
grid on

subplot(2,2,3)
semilogx(f, squeeze(abs(RGA_nc(2,1,:))))
title('|\lambda_{21}|')
grid on

subplot(2,2,4)
semilogx(f, squeeze(abs(RGA_nc(2,2,:))))
title('|\lambda_{22}|')
grid on