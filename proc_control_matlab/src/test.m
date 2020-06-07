clc;
clear;

addpath("Thrusters");

config = Config('config_AUV8.json');
M= ThrusterAllocator(config);


disp("----------------------------------");
disp("Test TrusterModel class...");

disp("----------------------------------");


disp("----------------------------------");
disp("limitation de la  force des moteurs (%)");
disp("----------------------------------");
%disp(M.fl());

disp("----------------------------------");
disp("Matrice des coefficients des thruster");
disp("----------------------------------");
%disp(M.L);

disp("----------------------------------");
disp("Matrice de défault thruster");
disp("----------------------------------");
%disp(M.D);

disp("----------------------------------");
disp("Force maximum théorique des 6 DLL");
disp("----------------------------------");
%disp(M.MLDT);

disp("----------------------------------");
disp("Force maximum réel des 6 DLL");
disp("----------------------------------");

%disp(M.MLDR);
M.UpdateDampingMatrix([-1,-1,-1,-1,-1,-1,-1,-1]);
%disp(M.D);
command=[50,0,50,3,5,0];


NLT=M.GetNlThrusterOutput(command);


disp("----------------------------------");
disp("Simplex");
disp("----------------------------------");
disp("Solution");
%disp(LT);
disp("----------------------------------");
disp("vecteur résultant");
%disp(M.L*LT);
disp("----------------------------------");
disp("W total");
%disp(M.OPT.RealNonLinearObjFunc(LT));


disp("----------------------------------");
disp("Fmincon");
disp("----------------------------------");
disp("Solution");
disp(NLT.');
disp("----------------------------------");
disp("vecteur résultant");
%disp(M.L*NLT);
disp("----------------------------------");
disp("W total");
%disp(M.OPT.RealNonLinearObjFunc(NLT));

%disp(M.NonLinearObjFunc([0,21.02134,0,21.02134,0,-11.738,-14.5171,-10.77]));
% 
% disp("----------------------------------");
% disp("Thruster 2");
% disp("----------------------------------");
% disp("Force: " + t2.force + " N");
% disp("Pwm: " + t2.pwm + " micro sec");
% disp("Power: " + t2.power + " W");
% disp("Current:  " + t2.current + " A");
% disp("RPM: " + t2.rpm + " rpm");
% disp("Efficiency: " + t2.efficiency + " g/W");



% disp("----------------------------------");
% disp("Test Config class...");
% disp("----------------------------------");
% disp("----------------------------------");

% disp(config.z);
% disp(config.dz);
% disp(config.d14);
% disp(config.a14);
% disp(config.d58);
% disp(config.psl);
