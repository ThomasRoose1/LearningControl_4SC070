function printer_home(Index_home)
simulink_set_constant(Index_home, 1);
pause(0.2);
simulink_set_constant(Index_home, 0);
end