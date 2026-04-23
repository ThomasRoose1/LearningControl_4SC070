%PLOTTRIALDATA   Plot trial during simulation/experiment.

if ~exist('norm_e_j','var');
    norm_e_j=[];
end
if ~exist('trialVec','var');
    trialVec = [];
end


% Extract data from trial j
trialVec = [trialVec,j-1];
r_j = r_extend((j-1)*N+1:j*N);
y_j = y((j-1)*N+1:j*N);
e_j = e((j-1)*N+1:j*N);
norm_e_j = [norm_e_j,norm(e_j,2)/sqrt(N)];
w_j = w((j-1)*N+1:j*N);
u_j = u((j-1)*N+1:j*N);
u_RC_j = u_RC((j-1)*N+1:j*N);


%% Initialization
if ~exist('PlotInit','var');
    
    
    figure('NumberTitle','off','Name','Trial data','Units','Normalized','Position',[0.25, 0.1, 0.5, 0.8]);
    set(gcf,'defaulttextinterpreter','latex')
    
    % Error norm.
    ax(1) = subplot(4,1,1);
    pl_eNorm = semilogy(0:N_trial-1,NaN(1,N_trial),'r--x');
    set(ax(1),'XTick',0:N_trial-1);
    xlabel('Trial \#');
    ylabel('$\|e\|_2/\sqrt{N}~[m^2]$');
    if N_trial > 1
        xlim([0,N_trial-1]);
    end
    
    % Title.
    title(ax(1),sprintf('Trial 0/%d',N_trial));
    
    % Error.
    ax(2) = subplot(4,1,2);
    xlim([0,t_j(end)]);
    hold on;
    pl_eprev = plot(t_j,NaN(N,1),'k-');
    pl_e = plot(t_j,NaN(N,1),'r--');
    xlabel('$t~[s]$');
    ylabel('$e~[m]$');
    
    % RC control input
    ax(3) = subplot(4,1,3);
    xlim([0,t_j(end)]);
    hold on;
    pl_wprev = plot(t_j,NaN(N,1),'k-');
    pl_w = plot(t_j,NaN(N,1),'r--');
    xlabel('$t~[s]$');
    ylabel('$u_{RC}~[V]$');
    ylim([-4 4]);
       
    % Feedback control input.
    ax(4) = subplot(4,1,4);
    xlim([0,t_j(end)]);
    hold on;
    pl_uprev = plot(t_j,NaN(N,1),'k-');
    pl_u = plot(t_j,NaN(N,1),'r--');
    xlabel('$t~[s]$');
    ylabel('$u_{FB}~[V]$');
    ylim([-4 4]);
    
    % Link time axes.
    linkaxes(ax(2:4),'x');
    
    % Set init done flag.
    PlotInit = 1;
    
else
    %% Update figure
    
    % Update title.
    title(ax(1),sprintf('Trial %d/%d',j,N_trial));

    % Error norm.
    set(pl_eNorm,'XData',trialVec,'YData',norm_e_j);
    
    % Error.
    set(pl_eprev,'YData',get(pl_e,'YData'));
    set(pl_e,'YData',e_j);
    
    % RC output.
    set(pl_wprev,'YData',get(pl_w,'YData'));
    set(pl_w,'YData',u_RC_j);
    
    % Control input.
    set(pl_uprev,'YData',get(pl_u,'YData'));
    set(pl_u,'YData',u_j-u_RC_j);
    
end

% Flush drawing.
drawnow;