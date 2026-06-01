function simulink_set_constant(block, signal)  
if length(signal) > 1
set_param(block,"Value",strcat("[",num2str(signal(:)'),"]'"));
else
    
set_param(block,"Value",num2str(signal));

end