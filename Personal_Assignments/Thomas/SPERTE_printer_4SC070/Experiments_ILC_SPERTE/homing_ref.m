close all

N=600; 
t = 0:Ts:N*Ts-Ts;

a = zeros(N,1);
a(1:200) = 1;
a(400:600) = -1;
s = tf('s');
v = lsim(c2d(1/s,Ts,'zoh'),a,t);
r = lsim(c2d(1/s,Ts,'zoh'),v,t);
r = r / max(r);
figure;
plot(r)


%% Send to model
ModelName = 'SPERTE_printer';
% Check if the model is running, makes no sense to measure otherwise.
if ~strcmp(get_param(ModelName,'SimulationStatus'),'external')
   error('The model is not running, can not perform a measurement.');
   return
end

BlockPaths = find_system(ModelName);
Index_home = find(contains(BlockPaths,'homing_ref'));
if length(Index_home) > 1
    warning('There appear to be duplicate set_Ref blocks in your model. Please remove all duplicate blocks.');
    Index_home = Index_home(1);
end

%%

set_param(BlockPaths{Index_home},"Value",strcat("[",num2str(r'),"]'"));
