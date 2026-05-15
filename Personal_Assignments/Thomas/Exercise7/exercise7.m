%% Exercise 7: Matrix Norm Minimization
clear; close all; clc;

%% Given Data
J = [1 0; 1 1];
Q = eye(2);
alpha = 0:0.1:2;

% Preallocate result array for efficiency
results = zeros(size(alpha));

%% Calculation
for i = 1:length(alpha)
    % Store the Frobenius norm (or default 2-norm) for each alpha
    results(i) = norm(Q - alpha(i) * J);
end

%% plot
fig = figure('Color', 'w');
plot(alpha, results, 'LineWidth', 2, 'Color', [0 0.447 0.741]); hold on;
yline(1, 'k--', 'LineWidth', 2);
grid on;
xlabel('\alpha', 'Interpreter', 'latex', 'FontSize', 12);
ylabel('||Q - \alpha J||', 'Interpreter','latex' ,'FontSize', 12);

if ~exist('Figures', 'dir'), mkdir('Figures'); end
exportgraphics(fig, "Figures/plot_7p2.pdf", "ContentType", "vector")
