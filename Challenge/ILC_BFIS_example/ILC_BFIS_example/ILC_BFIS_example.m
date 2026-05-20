% This script runs an ILC loop for ILC with polynomial basis functions and
% input shaper. Please change the settings in "Settings" for running the
% script.

% You can choose to run the loop for two different systems:
% 1) a fourth-order motion system
% 2) an old model of the decoupled x-direction of the Arizona. You will
% receive new models soon.

clear variables

%% Settings
system = 'arizona_x';                                                       % Run two different systems: arizona_x / 4th_order
ref = 'coupling_analysis';

polynomial = 0;                                                             % if 1, Run ffw only, i.e., Cy=1

na = 4;                                                                     % Order input shaper Cy
nb = 4;                                                                     % Order feedforward Cff

% ILC parameters
N_trials = 4;                                                               % Amount of ILC trials
var_noise = 0*1e-7;                                                         % In case you want to add zero mean gaussian white noise to the sensors

% Weighting parameters (diagonal weighting)
we = 1;                                                                     
wf = 0*1e-14;
wdf = 0*1e-16;
wry = 0*1e-4;
wdry = 0*1*1e-2;

% Initial theta vector
theta_init = [zeros(1,na) zeros(1,nb)].';   

%% Settings (do not change)
method = 'ILC';                                                             % ILC / IFT | ILC method corresponds with Challenge description section 4. IFT --> see (Boeren,2014)
% Some additional background: the ILC approach is different to the IFT
% approach presenten in (Boeren,2014). For this challenge, we expect you to
% use the ILC approach, but feel free to test/try this IFT approach to 
% check whether this is beneficial for performance or not

%% Define the system
switch system
    case 'arizona_x'
        % Load the Arizona x models
        cd Arizona_models_old\Models\
        P = ((load('Px_fit.mat').Px_DT));
        Ts = P.Ts;
        z = tf('z',Ts);
        cd ..\Controllers
        Cfb = c2d(load('xController.mat').Cx_CT,Ts,'Tustin');
        cd ..\..

    case 'arizona_new'
        % Load the Arizona x models
        cd Arizona_models_new\Models\
        P = ((load('P_centralized.mat').Pz));
        Ts = P.Ts;
        z = tf('z',Ts);
        cd ..\Controllers
        Cfb = c2d(load('xController.mat').Cx_CT,Ts,'Tustin');
        cd ..\..

    case '4th_order'
        % Load the rational example system
        Ts = 1e-4;
        z = tf('z',Ts);
        % Define the plant and feedback controller
        P = 9.97e-9 * ((z+1)*(z^2 - 1.968*z + 0.9996)) / ((z-1)^2 * (z^2 - 1.934*z + 0.9966));      % original system
        Cfb = 1e5 * ((z-0.99)*(z-0.9833)*(z^2 - 1.924*z + 0.987)) / ((z-1)*(z-0.86)^2 * (z^2 - 1.823*z + 0.8819));
        
end

H = 0.7656 * (z-1)^2 / (z^2 - 1.475*z + 0.5869);                            % Noise model

%% Create closed loops
loops = loopsens(P,Cfb);
PS = loops.PSi;
S = loops.So;
CS = loops.CSo;

%% Create the reference (these are example references. You receive the reference for the Arizona experiments later.
% Reference is a fourth order motion profile.
switch ref
    case {'arizona_x'}
        Npad = 500;
        Npad_start = 10;
        [ty,ddy] = make4(0.1,1,1,1e5,1e7,Ts); % my reference
        [~,~,s,j,a,v,r,tt] = profile4(ty,ddy(1),Ts);
        r = [zeros(Npad_start,1); r; r(end)*ones(Npad,1)];
        v = [zeros(Npad_start,1);v;zeros(Npad,1)];
        a = [zeros(Npad_start,1);a;zeros(Npad,1)];
        j = [zeros(Npad_start,1);j;zeros(Npad,1)];
        s = [zeros(Npad_start,1);s;zeros(Npad,1)];
        N = length(r);
        t = 0:Ts:(N-1)*Ts;
        rendidx = find(t>=tt(end),1)+Npad_start;               % Index snap is zero, so reference ends here

    case '4th_order'
        Npad = 500;
        [ty,ddy] = make4(0.01,0.25,30,1e5,1e9,Ts); % my reference
        [~,~,s,j,a,v,r,tt] = profile4(ty,ddy(1),Ts);
        r = [r; r(end)*ones(Npad,1)]; % zeros, forward, zeros,backward, zeros
        v = [v;zeros(Npad,1)];
        a = [a;zeros(Npad,1)];
        j = [j;zeros(Npad,1)];
        s = [s;zeros(Npad,1)];
        N = length(r);
        t = 0:Ts:(N-1)*Ts;
        rendidx = find(t>=tt(end),1);               % Index snap is zero, so reference ends here

    case {'coupling_analysis'}
    % Define your target frequency range to test tracking bounds
    freqs = [1, 5, 10, 20, 30, 40, 50, 60, 80, 100, 150, 200]; % Frequencies in Hz
    cycles_per_freq = 5;                                      % Cycles to track per step
    amplitude = 0.05;                                         % Reference amplitude
    
    % Build the continuous stepping reference profile
    r = [];
    for f = freqs
        t_chunk = 0:Ts:(cycles_per_freq/f);
        r_chunk = amplitude * sin(2*pi*f*t_chunk)';
        r = [r; r_chunk(1:end-1)]; % stitch smoothly at zero-crossings
    end
    
    % Padding setup matching your framework structure
    Npad_start = 50; 
    Npad = 500;
    r = [zeros(Npad_start,1); r; zeros(Npad,1)];
    
    % Generate analytical derivatives so your basis functions (Psi) map perfectly
    v = [0; diff(r)/Ts];
    a = [0; diff(v)/Ts];
    j = [0; diff(a)/Ts];
    s = [0; diff(j)/Ts];
    
    N = length(r);
    t = 0:Ts:(N-1)*Ts;
    
    % Store index metadata to isolate frequencies during post-processing
    freq_indices = struct();
    idx_curr = Npad_start + 1;
    for i = 1:length(freqs)
        num_samples = round((cycles_per_freq/freqs(i))/Ts);
        freq_indices(i).name = freqs(i);
        freq_indices(i).range = idx_curr : min(idx_curr + num_samples - 1, N);
        idx_curr = idx_curr + num_samples;
    end
    rendidx = Npad_start + 1; % Redefining start index window for evaluation
end

%% Construct diagonal weighting filters
We = we*eye(N); We_sq = sqrt(We);
Wf = wf*eye(N); Wf_sq = sqrt(Wf);
Wdf = wdf*eye(N); Wdf_sq = sqrt(Wdf);
Wry = wry*eye(N); Wry_sq = sqrt(Wry);
Wdry = wdry*eye(N); Wdry_sq = sqrt(Wdry);

%% Parameterize input shaper Cy
Psi_y = tf(zeros(1,na));
for i = 1:na
    num = zeros(1,i+1);
    for k = 0:i
        num(k+1) = (-1)^k * nchoosek(i,k);                                  % derivative basis function, i.e., (1-z^-1)/Ts . Feel free to play with the basis functions.
    end
    Psi_y(i) = minreal(tf(num,Ts^i,Ts,'Variable','z^-1'));
end

%% Parameterize feedforward Cff
Psi_ff = tf(zeros(1,nb));
for i = 1:nb
    num = zeros(1,i+1);
    for k = 0:i
        num(k+1) = (-1)^k * nchoosek(i,k);                                  % derivative basis function, i.e., (1-z^-1)/Ts . Feel free to play with the basis functions.
    end
    Psi_ff(i) = minreal(tf(num,Ts^i,Ts,'Variable','z^-1'));
end

Psi = minreal([Psi_y, Psi_ff]);                                             % Create tranfer function with all basis functions

%% Run the ILC loop                                

% Theoretical limitation
Ndelay = na;                                                                % r_y = r for t in [T1 + n_a, end]

theta = NaN(na+nb,N_trials);
e_y   = NaN(N,N_trials);
e     = NaN(N,N_trials);
r_y   = NaN(N,N_trials);
f     = NaN(N,N_trials);
theta(:,1) = theta_init;                                                   
for j = 1:N_trials

    if polynomial
        theta(1:na,j) = zeros(na,1);                                        % basically turning off the input shaper, i.e., Cy=1
    end

    Cy  = minreal(1 + Psi_y*theta(1:na,j));                                 % Construct input shaper
    Cff = minreal(Psi_ff*theta(na+1:na+nb,j));                              % Construct feedforward

    C = minreal(Cfb*Cy + Cff);                                              

    % Simulate the system
    noise = var_noise*randn(N,1);
    r_y(:,j) = brfus_v003(Cy,r,t,Ts);                                       % r_y = Cy * r
    f(:,j) = brfus_v003(Cff,r,t,Ts);                                        % f = Cff * r
    y = lsim(PS,f(:,j),t) + lsim(series(PS,Cfb),r_y(:,j),t) + lsim(series(S,H),noise,t);
    u = lsim(S,f(:,j),t) + lsim(series(S,Cfb),r_y(:,j),t) + lsim(series(CS,H),noise,t);
    e_y(:,j) = r_y(:,j)-y;                                                  % loop error
    e(:,j) = r-y;                                                           % Actual error

    theta_delta = FeedforwardUpdate_BFIS(method,na,nb,Psi,C,N,S,PS,We_sq,Wry_sq,Wdry_sq,Wf_sq,Wdf_sq,e_y(:,j),u,y,r_y(:,j),f(:,j),r,t,Ts);

    theta(:,j+1) = theta(:,j) + theta_delta;

end
e_ynorm = vecnorm(e_y);
e_norm  = vecnorm(e(rendidx:end,:));                                        % Calculate error norm for k in [T1, T2]

%% Post Processing
plot_trial = N_trials;

figure(1);clf
nexttile;
semilogy(e_ynorm,'k--'); hold on
semilogy(e_norm,'r--')
xticks([1:N_trials])
xlabel('Trials')
legend('$e_y$','$e$')
ylabel('Error norm')

nexttile;
plot(t,r); hold on
plot(t,r_y(:,plot_trial))
xline(t(rendidx),'-','$r = \bar{r}$','Interpreter','latex','FontSize',16)
xlim([t(rendidx-50) t(rendidx+200)])
ylim(max(r)*0.1*[9.9 10.05])
legend('$r$','$r_y$')
xlabel('Time')
ylabel('Reference')

nexttile;
plot(t,e(:,1)); hold on
plot(t,e(:,plot_trial));
xline(t(rendidx),'-','$r = \bar{r}$','LabelHorizontalAlignment','left','Interpreter','latex','FontSize',16)
xline(t(rendidx+Ndelay),'-','$T_1 + n_a$','Interpreter','latex','FontSize',16)
xlim([t(rendidx-50) t(rendidx+200)])
legend('$e_1$','$e_{' + string(plot_trial)+ '}$')
xlabel('Time')
ylabel('error')


figure(2);clf
subplot(121)
bodemag(Cff,Cy)
legend('location','northwest')

subplot(122)
bodemag(P); hold on
bodemag(Cy/Cff,'r--')
legend('$P$','$C\_y / C\_{ff}$','location','northeast','interpreter','latex')

%% Frequency Evaluation Tracking Breakdown Plot
if strcmp(ref,'coupling_analysis')
    figure(3); clf;
    hold on;
    
    % Track initial behavior (Trial 1) vs Final learned optimization behavior
    trials_to_plot = [1, N_trials]; 
    colors = {'#D95319', '#0072BD'}; % Red-orange for initial, Blue for final
    markers = {'o-', 's-'};
    
    for t_idx = 1:length(trials_to_plot)
        trial = trials_to_plot(t_idx);
        max_errors = zeros(length(freqs), 1);
        
        for i = 1:length(freqs)
            % Isolate the specific time-slice belonging to this frequency segment
            segment_error = e(freq_indices(i).range, trial);
            
            % Drop the first cycle of the segment to ignore transient switching shocks
            samples_per_cycle = round((1/freqs(i))/Ts);
            settled_error = segment_error(min(samples_per_cycle, length(segment_error)):end);
            
            if ~isempty(settled_error)
                max_errors(i) = max(abs(settled_error));
            else
                max_errors(i) = max(abs(segment_error));
            end
        end
        
        plot(freqs, max_errors, markers{t_idx}, 'Color', colors{t_idx}, ...
             'LineWidth', 2, 'MarkerSize', 8, ...
             'DisplayName', sprintf('Trial %d Error', trial));
    end
    
    set(gca, 'XScale', 'log', 'YScale', 'log');
    grid on; box on;
    xlabel('Excitation Frequency (Hz)', 'FontSize', 12);
    ylabel('Max Settled Tracking Error [Magnitude]', 'FontSize', 12);
    title('Tracking Deterioration Threshold Matrix', 'FontSize', 14);
    legend('Location', 'NorthWest');
    
    % Highlight the structural breakdown bound visually
    y_limits = ylim;
    line([1/(2*pi*Ts) 1/(2*pi*Ts)], y_limits, 'Color', 'r', 'LineStyle', '--', ...
         'LineWidth', 1.5, 'DisplayName', 'Theoretical Nyquist Bound');
end