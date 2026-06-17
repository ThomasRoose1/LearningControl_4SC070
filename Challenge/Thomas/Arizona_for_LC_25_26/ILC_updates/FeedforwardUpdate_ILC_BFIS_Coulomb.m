function [theta_delta, Phi, Psi_y_r, Psi_ff_r] = FeedforwardUpdate_ILC_BFIS_Coulomb( ...
    na, nb, Psi, N, S, PS, ...
    We_sq, Wry_sq, Wdry_sq, Wf_sq, Wdf_sq, ...
    e_y, r_y, f, r, t, Ts, ...
    use_coulomb_basis, v_eps)

% Base regressor
Phi = zeros(N, na + nb);

% Input shaper basis
if na > 0
    Phi(:,1:na) = -brfus_v003((series(S, Psi(1:na))).', r, t, Ts);
    Psi_y_r = brfus_v003(Psi(1:na).', r, t, Ts);
else
    Psi_y_r = zeros(N, 0);
end
% Feedforward derivative basis
Phi(:,na+1:end) = brfus_v003((series(PS, Psi(na+1:end))).', r, t, Ts);
Psi_ff_r = brfus_v003(Psi(na+1:end).', r, t, Ts);

nb_new = nb;

% Add Coulomb friction basis to feedforward only
if use_coulomb_basis

    % Use reference velocity
    vref = [0; diff(r(:)) / Ts];

    % Smooth Coulomb basis
    Psi_coulomb_r = tanh(vref / v_eps);
    Psi_coulomb_r = Psi_coulomb_r(:);

    % Response of Coulomb basis through process sensitivity
    Phi_coulomb = brfus_v003(PS, Psi_coulomb_r, t, Ts);
    Phi_coulomb = Phi_coulomb(:);

    % Add to error-prediction regressor
    Phi = [Phi, Phi_coulomb];

    % Add to feedforward-force regressor
    Psi_ff_r = [Psi_ff_r, Psi_coulomb_r];

    nb_new = nb + 1;
end

% Create regressor matrix
X = [We_sq * Phi;
    -Wry_sq * Psi_y_r, zeros(N, nb_new);
    -Wdry_sq * Psi_y_r, zeros(N, nb_new);
    zeros(N, na),     -Wf_sq * Psi_ff_r;
    zeros(N, na),     -Wdf_sq * Psi_ff_r];

% Create response vector
Y = [We_sq * e_y;
    Wry_sq * r_y;
    zeros(N,1);
    Wf_sq * f;
    zeros(N,1)];
% Column scaling
colNorms = vecnorm(X);
colNorms(colNorms == 0) = 1;

X_scaled = X ./ colNorms;
th_scaled = X_scaled \ Y;

theta_delta = th_scaled ./ colNorms.';

end