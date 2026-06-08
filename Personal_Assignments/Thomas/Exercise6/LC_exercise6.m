%% Learning control Exercise 6 
clear; close all; clc; 

%% Given
J = 1;
N = 1;
Q = -0.8;
% Q = 1;
L = -0.4;
r = 1;
iter = 20;

%% Perform iterations
e = zeros(N,iter);
f = zeros(N,iter + 1);

for j = 1:iter
    % Compute next error based on convolution matrix and input
    e(j) = r - J*f(j);
    
    % Compute next feedforward signal
    f(j+1) = Q*f(j) + L*e(j);
end

%% Plot
% dimensions for A4 LaTeX (16cm width is a safe standard)
figWidth = 16; 
figHeight = 20; % Taller figure to accommodate 4 stacks

fig = figure('Units', 'centimeters', 'Position', [2, 2, figWidth, figHeight]);

% indexing
idx = 1:1:iter;

% subplot of error
subplot(3,1,1);
plot(idx, abs(e'), 'r', 'LineWidth', 2);
grid on;
ylabel('$|e_j(k)|$', 'Interpreter', 'latex');
xlabel('Trial \#', 'Interpreter', 'latex');

% subplot of feedforward
subplot(3,1,2);
plot(idx, f(1:iter)', 'b', 'LineWidth', 2);
grid on;
ylabel('$f_j(k)$', 'Interpreter', 'latex');
xlabel('Trial \#', 'Interpreter', 'latex');

% subplot of feedforward relative to steady state
subplot(3,1,3)
plot(idx, abs(f(end-1) - f(1:iter))', 'b--', 'LineWidth', 2);
grid on;
ylabel('$||f_\infty - f_j(k)||$', 'Interpreter', 'latex');
xlabel('Trial \#', 'Interpreter', 'latex');

% Export to PDF
exportgraphics(fig, "Figures/plot6.pdf", "ContentType", "vector", "BackgroundColor", "none")