function [theta_delta, Phi, Psi_y_r, Psi_ff_r] = FeedforwardUpdate_ILC_BFIS_MIMO( ...
    na_vec, nb_vec, Psi_blocks, N, S, PS, ...
    We_sq, Wry_sq, Wdry_sq, Wf_sq, Wdf_sq, ...
    e_y, r_y, f, r, t, Ts, ...
    use_coulomb_basis, v_eps)

% MIMO BFIS / feedforward update with optional Coulomb basis.
%
% Inputs:
%   na_vec      : n_in x 1 vector, number of input-shaper bases per input
%   nb_vec      : n_in x 1 vector, number of feedforward bases per input
%   Psi_blocks  : cell array, Psi_blocks{i} contains basis functions for input i
%                 expected ordering:
%                 Psi_blocks{i}(1:na_i)        -> input-shaper basis
%                 Psi_blocks{i}(na_i+1:end)    -> feedforward basis
%
%   S           : MIMO sensitivity system
%   PS          : MIMO process sensitivity system
%
%   e_y, r_y    : N x n_out
%   f, r        : N x n_in
%
% Output:
%   theta_delta : stacked parameter update
%   Phi         : MIMO error-prediction regressor
%   Psi_y_r     : input-shaper basis response
%   Psi_ff_r    : feedforward basis response

%% Dimensions

n_in  = length(nb_vec);
n_out = size(e_y, 2);

if length(na_vec) ~= n_in
    error('na_vec and nb_vec must have the same length.');
end

if length(Psi_blocks) ~= n_in
    error('Psi_blocks must contain one cell per input channel.');
end

na_total = sum(na_vec);
nb_total = sum(nb_vec);

if use_coulomb_basis
    nb_total_new = nb_total + n_in;   % one Coulomb basis per input
else
    nb_total_new = nb_total;
end

n_theta = na_total + nb_total_new;

%% Vectorize signals

e_y_vec = e_y(:);
r_y_vec = r_y(:);
f_vec   = f(:);

%% Allocate regressors

Phi      = zeros(N*n_out, n_theta);
Psi_y_r  = zeros(N*n_in, na_total);
Psi_ff_r = zeros(N*n_in, nb_total_new);

%% Index counters

theta_col = 1;
na_col    = 1;
nb_col    = 1;

%% Loop over input channels

for i = 1:n_in

    na_i = na_vec(i);
    nb_i = nb_vec(i);

    Psi_i = Psi_blocks{i};

    if length(Psi_i) ~= na_i + nb_i
        error('Psi_blocks{%d} must contain na_i + nb_i basis functions.', i);
    end

    r_i = r(:,i);

    %% -------------------------------------------------------------
    %  Input-shaper basis functions for input channel i
    %  These affect output through S(:,i)
    %% -------------------------------------------------------------

    if na_i > 0

        Psi_y_i = Psi_i(1:na_i);

        for k = 1:na_i

            % Basis function acting on reference of input i
            psi_r = brfus_v003(Psi_y_i(k), r_i, t, Ts);
            psi_r = psi_r(:);

            % Store direct basis response in block structure
            row_idx_input = (i-1)*N + (1:N);
            Psi_y_r(row_idx_input, na_col) = psi_r;

            % Error-prediction response through sensitivity path
            % S(:,i) maps input i to all outputs
            G_si = S(:,i) * Psi_y_i(k);

            phi_ik = -brfus_v003(G_si, r_i, t, Ts);

            % Expected size after brfus:
            % N x n_out
            Phi(:, theta_col) = phi_ik(:);

            theta_col = theta_col + 1;
            na_col    = na_col + 1;
        end
    end

    %% -------------------------------------------------------------
    %  Feedforward basis functions for input channel i
    %  These affect output through PS(:,i)
    %% -------------------------------------------------------------

    Psi_ff_i = Psi_i(na_i+1 : na_i+nb_i);

    for k = 1:nb_i

        psi_r = brfus_v003(Psi_ff_i(k), r_i, t, Ts);
        psi_r = psi_r(:);

        % Store direct feedforward basis response in block structure
        row_idx_input = (i-1)*N + (1:N);
        Psi_ff_r(row_idx_input, nb_col) = psi_r;

        % Error-prediction response through process sensitivity
        G_psi = PS(:,i) * Psi_ff_i(k);

        phi_ik = brfus_v003(G_psi, r_i, t, Ts);

        Phi(:, theta_col) = phi_ik(:);

        theta_col = theta_col + 1;
        nb_col    = nb_col + 1;
    end

    %% -------------------------------------------------------------
    %  Coulomb basis function for input channel i
    %% -------------------------------------------------------------

    if use_coulomb_basis

        vref_i = [0; diff(r_i(:))/Ts];

        Psi_coulomb_i = tanh(vref_i / v_eps);
        Psi_coulomb_i = Psi_coulomb_i(:);

        row_idx_input = (i-1)*N + (1:N);
        Psi_ff_r(row_idx_input, nb_col) = Psi_coulomb_i;

        % Coulomb force goes through PS(:,i)
        phi_coulomb_i = brfus_v003(PS(:,i), Psi_coulomb_i, t, Ts);

        Phi(:, theta_col) = phi_coulomb_i(:);

        theta_col = theta_col + 1;
        nb_col    = nb_col + 1;
    end
end

%% Regression matrix

X = [ ...
    We_sq  * Phi;
   -Wry_sq * Psi_y_r,  zeros(N*n_in, nb_total_new);
   -Wdry_sq * Psi_y_r, zeros(N*n_in, nb_total_new);
    zeros(N*n_in, na_total), -Wf_sq  * Psi_ff_r;
    zeros(N*n_in, na_total), -Wdf_sq * Psi_ff_r ...
    ];

Y = [ ...
    We_sq * e_y_vec;
    Wry_sq * r_y_vec;
    zeros(N*n_in,1);
    Wf_sq * f_vec;
    zeros(N*n_in,1) ...
    ];

%% Scaled least-squares solve

colNorms = vecnorm(X);
colNorms(colNorms == 0) = 1;

X_scaled = X ./ colNorms;

th_scaled = X_scaled \ Y;

theta_delta = th_scaled ./ colNorms.';

%% seperate theta_delta
% theta_delta_x = theta_delta(1:(na_vec(1)+nb_vec(1)));
% theta_delta_phi = theta_delta((na_vec(1)+nb_vec(1))+1:end);
% theta_delta = [theta_delta_x, theta_delta_phi];

end