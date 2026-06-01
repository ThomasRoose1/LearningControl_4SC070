% % FeedforwardUpdate for ILC with polynomial basis functions and input
% % shaper
% function [theta_delta, Phi] = FeedforwardUpdate_ILC_BFIS(na,nb,Psi,N,S,PS,We_sq,Wry_sq,Wdry_sq,Wf_sq,Wdf_sq,e_y,r_y,f,r,t,Ts)
% % % Setup
% % if polynomial
% %     theta(1:na) = zeros(na,1);                                        % basically turning off the input shaper, i.e., Cy=1
% % end
% %
% % Cy  = minreal(1 + Psi_y*theta(1:na));                                 % Construct input shaper
% % Cff = minreal(Psi_ff*theta(na+1:na+nb));                              % Construct feedforward
% % C = minreal(Cfb*Cy + Cff);                                              
% % %% Simulate the system
% % % noise = var_noise*randn(N,1);
% % r_y(:) = brfus_v003(Cy,r,t,Ts);                                             % r_y = Cy * r
% % f(:) = brfus_v003(Cff,r,t,Ts);                                              % f = Cff * r
% % % y = lsim(PS,f(:,j),t) + lsim(series(PS,Cfb),r_y(:,j),t) + lsim(series(S,H),noise,t);
% % % u = lsim(S,f(:,j),t) + lsim(series(S,Cfb),r_y(:,j),t) + lsim(series(CS,H),noise,t);
% % e_y(:) = r_y(:)-y;                                                          % loop error --> HOW DO WE GET Y FROM THE SYSTEM?
% % e(:) = r-y;                                                                 % Actual error
% %%  Calculate Theta
% Phi = zeros(N,na+nb);
% Phi(:,1:na) = -brfus_v003((series(S,Psi(1:na))).',r,t,Ts);
% Phi(:,na+1:end) = brfus_v003((series(PS,Psi(na+1:end))).',r,t,Ts);          % FF
% Psi_y_r = brfus_v003(Psi(1:na).',r,t,Ts);                                   %
% Psi_ff_r = brfus_v003(Psi(na+1:end).',r,t,Ts);
% % Create regressor matrix
% X = [We_sq*Phi;
%     -Wry_sq*Psi_y_r, zeros(N,nb);
%     -Wdry_sq*Psi_y_r, zeros(N,nb);
%     zeros(N,na), -Wf_sq*Psi_ff_r;
%     zeros(N,na), -Wdf_sq*Psi_ff_r];
% % Create response vector
% Y = [We_sq*e_y;
%     Wry_sq*r_y;
%     zeros(N,1);
%     Wf_sq*f;
%     zeros(N,1)];
% X_scaled = X ./ vecnorm(X);                                                 % For better conditioning
% th_scaled = X_scaled \ Y;
% theta_delta = th_scaled ./ vecnorm(X).';       
% theta(:,j+1) = theta(:,j) + theta_delta;
% % % Trim vector
% % f_jplus1 = f_jplus1_(N_finite_time_fix+1:end-N_finite_time_fix, :);
% %
% %
% % update = update_(N_finite_time_fix+1:end-N_finite_time_fix, :);
% % theta_delta = zeros(na+nb,1);
% end

function [theta_delta, Phi] = FeedforwardUpdate_ILC_BFIS(na,nb,Psi,N,S,PS,We_sq,Wry_sq,Wdry_sq,Wf_sq,Wdf_sq,e_y,r_y,f,r,t,Ts)
    %% Calculate Theta
    Phi = zeros(N, na+nb);
    
    % Only evaluate the input shaper basis functions if na > 0
    if na > 0
        Phi(:,1:na) = -brfus_v003((series(S,Psi(1:na))).', r, t, Ts);
        Psi_y_r = brfus_v003(Psi(1:na).', r, t, Ts); 
    else
        Psi_y_r = zeros(N, 0);
    end
    
    % Evaluate feedforward basis functions
    Phi(:,na+1:end) = brfus_v003((series(PS,Psi(na+1:end))).', r, t, Ts);          
    Psi_ff_r = brfus_v003(Psi(na+1:end).', r, t, Ts);

    % Create regressor matrix
    X = [We_sq*Phi;
        -Wry_sq*Psi_y_r, zeros(N,nb);
        -Wdry_sq*Psi_y_r, zeros(N,nb);
        zeros(N,na), -Wf_sq*Psi_ff_r;
        zeros(N,na), -Wdf_sq*Psi_ff_r];
        
    % Create response vector
    Y = [We_sq*e_y;
        Wry_sq*r_y;
        zeros(N,1);
        Wf_sq*f;
        zeros(N,1)];
        
    % Scale and solve via Least-Squares
    X_scaled = X ./ vecnorm(X);                                                 
    th_scaled = X_scaled \ Y;
    
    % Unscale the resulting parameter delta
    theta_delta = th_scaled ./ vecnorm(X).';       
end