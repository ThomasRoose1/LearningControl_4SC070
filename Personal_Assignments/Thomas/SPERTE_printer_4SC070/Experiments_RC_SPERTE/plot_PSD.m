function [] = plot_PSD( t,r,y,i,m )
%plot_PSD Summary of this function goes here
%   Detailed explanation goes here
global psd_noRC

set(0,'defaulttextinterpreter','latex')
hFig = figure(m);
% set(hFig, 'Position', [100 50 850 850])

% Define normalized tracking error
e = (r - y);

% Tracking spectrum
fs = 1/(t(2)-t(1));
fres = 1/(t(end)+t(2));
% fres = 1/(t(end))
% F = 0:fres:fs/2;
F = fs*(0:(length(t)/2))/length(t);
Ns = length(t);

E = fft(e); E = E(1:Ns/2+1);
psd = (1/(fs*Ns)).*abs(E).^2;
psd(2:end-1) = 2*psd(2:end-1);

if i == 0
    
    semilogx(F,10*log10(psd),'color',[1 0 0],'linewidth',2); hold on

%     index = ((1/T)/fres)*(1:2:fs/2*T)+1; index = index(1:round(end*0.5));
%     index2 = ((1/T)/fres)*(2:2:(fs/2*T-1))+1; index2 = index2(1:round(end*0.5));
%     semilogx(F(index),10*log10(psd(index)),'.','color',[0 0 1],'markersize',15);
%     semilogx(F(index2),10*log10(psd(index2)),'*','color',[0 0 0],'markersize',15);

    psd_noRC = psd;
else
    semilogx(F,10*log10(psd_noRC),'color',[0.5 0.5 0.5],'linewidth',2); hold on
    semilogx(F,10*log10(psd),'color',[1 0 0],'linewidth',2); hold on
    %index = find(F == 3050);
    %semilogx(F(index),10*log10(psd(index)),'.','markersize',20,'color',[0 0 1],'markersize',15);

%     index = ((1/T)/fres)*(1:2:fs/2*T)+1; index = index(1:round(end*0.5));
%     index2 = ((1/T)/fres)*(2:2:(fs/2*T-1))+1; index2 = index2(1:round(end*0.5));
%     semilogx(F(index),10*log10(psd(index)),'.','color',[0 0 1],'markersize',15);
%     semilogx(F(index2),10*log10(psd(index2)),'*','color',[0 0 0],'markersize',15);
end
    
grid on; hold off;
set(gca,'fontsize',12)
axis([0 F(end) -250 0])

xlabel('$\omega$ [Hz]','fontsize',13); ylabel('Power/frequency [dB/Hz]','fontsize',13);

h = legend('without RC','with RC'); 
set(h,'interpreter','latex');


end

