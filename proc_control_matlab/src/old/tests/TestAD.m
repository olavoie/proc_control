clc;
clear;

TSPEC = load('T200-Spec-16V.mat').T200Spec16V ;
config = Config('config_AUV8.json');

t2 = T200Thruster(TSPEC, 2);
t2.force = 30;
disp("----------------------------------");
disp("Thruster 2");
disp("----------------------------------");
disp("Id: " + t2.id);
disp("Force: " + t2.force + " N");
disp("Pwm: " + t2.pwm + " micro sec");
disp("Power: " + t2.power + " W");
disp("Current:  " + t2.current + " A");disp("RPM: " + t2.rpm + " rpm");
disp("Efficiency: " + t2.efficiency + " g/W");




disp("----------------------------------");
disp("Test Config class...");
disp("----------------------------------");
disp("----------------------------------");

disp(config.z);
disp(config.dz);
disp(config.d14);
disp(config.a14);
disp(config.d58);
disp(config.psl);
