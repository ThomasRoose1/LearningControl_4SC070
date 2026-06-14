function [theta_delta, Phi] = FeedforwardUpdate_ILC_BFIS(na,nb,Psi,N,S,PS,We_sq,Wry_sq,Wdry_sq,Wf_sq,Wdf_sq,e_y,r_y,f,r,t,Ts, ntheta, use_coulomb_basis)
    %% Calculate Theta
    Phi = zeros(N, ntheta); % containts [S*Psi_y, SP*Psi_ff]
    
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

    
    % Add Coulomb friction basis function
    if use_coulomb_basis
        % Reference velocity
        vref_y = [0; diff(r_y)/Ts];

        % Smooth sign approximation for Coulomb friction
        v_eps = 1e-4;
        Psi_coulomb_r = tanh(vref_y/v_eps);
        Psi_coulomb_r = Psi_coulomb_r(:);

        % Closed-loop output/error effect of Coulomb feedforward basis
        Phi_coulomb = lsim(PS, Psi_coulomb_r, t);
        Phi_coulomb = Phi_coulomb(:);

        % Add to regression matrices
        Phi(:,end) = Phi_coulomb;
        Psi_ff_r = [Psi_ff_r, Psi_coulomb_r];
    end

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