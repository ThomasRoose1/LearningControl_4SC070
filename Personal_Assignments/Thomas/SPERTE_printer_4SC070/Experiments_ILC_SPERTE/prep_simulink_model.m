ModelName = 'SPERTE_printer';
% Check if the model is running, makes no sense to measure otherwise.
if ~strcmp(get_param(ModelName,'SimulationStatus'),'external')
   error('The model is not running, can not perform a measurement.');
   return
end

BlockPaths = find_system(ModelName);
Index_ref = find(contains(BlockPaths,'set_Ref'));
if length(Index_ref) > 1
    warning('There appear to be duplicate set_Ref blocks in your model. Please remove all duplicate blocks.');
    Index_ref = Index_ref(1);
end
Index_ff = find(contains(BlockPaths,'set_ff'));
if length(Index_ff) > 1
    warning('There appear to be duplicate set_ff blocks in your model. Please remove all duplicate blocks.');
    Index_ff = Index_ff(1);
end

Index_active = find(contains(BlockPaths,'active'));
if length(Index_active) > 1
    warning('There appear to be duplicate active blocks in your model. Please remove all duplicate blocks.');
    Index_active = Index_active(1);
end

Index_home = find(contains(BlockPaths,'force_home'));
if length(Index_home) > 1
    warning('There appear to be duplicate home blocks in your model. Please remove all duplicate blocks.');
    Index_home = Index_home(1);
end

rto_did_finish = get_param('SPERTE_printer/Reference/did_finish','RunTimeObject');
rto_measure_finish = get_param('SPERTE_printer/Measurement','RunTimeObject');

% 
set_param(BlockPaths{Index_active},"Value",'0');
set_param(BlockPaths{Index_home},"Value",'0');

pause(0.2);