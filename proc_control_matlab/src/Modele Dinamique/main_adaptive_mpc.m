clc; clear;

%% Determiner les specification du système
nx = 12;  % nombre d'états
ny = 12;  % Nombre de sorties
nu = 8;   % Nombre d'entré
Ts = 0.1; % Période d'echantillionage
p = 15;   % Horizon de prediction
m = 2;    % Horizon de Controle

%Forces Minmax Thrusters initailes
TMIN =[-26;-26;-26;-26;-26;-26;-26;-26];
TMAX =[ 32; 32; 32; 32; 32; 32; 32; 32];

% Poids du controleur initiales
OV =[ 20 20 15 20 20 20 0 0 0 0 0 0];  %OutputVariables
MV =[0.3 0.3 0.3 0.3 0.1 0.1 0.1 0.1]; %ManipulatedVariables
MVR=[0.1 0.1 0.1 0.1 0.1 0.1 0.1 0.1]; %.ManipulatedVariablesRate

%% Initialiser le comtrolleur MPC
% Conditions initiales
Xi= zeros(12,1); % états initials
Ui=zeros(8,1);   % Commande initials

%liniéarisation du modèle aux conditions initales.
[A,B,C,D] = AUVStateJacobianFcn(Xi,Ui);   

% création de l'objet state space.
AUVPlant = ss(A,B,C,D);

% Création du controleur MPC.
mpcobj =mpc(AUVPlant,Ts);

%Ajout des poids et gains
mpcobj.MV = struct('Min',TMIN,'Max',TMAX);
mpcobj.Weights.OutputVariables = OV;
mpcobj.Weights.ManipulatedVariables = MV;
mpcobj.Weights.ManipulatedVariablesRate = MVR;


%% Simualtion
% Specify the initial conditions
x = [0;0;0;0;0;0;0;0;0;0;0;0];
% Nominal control that keeps the quadrotor floating
 nloptions = nlmpcmoveopt;
 nloptions.MVTarget = [0 0 0 0 0 0 0 0]; 
 mv = nloptions.MVTarget;


Duration = 20;
hbar = waitbar(0,'Simulation Progress');
xHistory = x';
lastMV =[0 0 0 0 0 0 0 0]; % mv;
uHistory = lastMV;
for k = 1:(Duration/Ts)
    tic;
    % Set references for previewing
    t = linspace(k*Ts, (k+p-1)*Ts,p);
    yref = QuadrotorReferenceTrajectory(t);
    % Compute the control moves with reference previewing.
    xk = xHistory(k,:);
    [uk,nloptions,info] = nlmpcmove(nlobj,xk,lastMV,yref',[],nloptions);
    uHistory(k+1,:) = uk';
    lastMV = uk;
    toc;
    % Update states.
    ODEFUN = @(t,xk) AUVStateFcn(xk,uk);
    [TOUT,YOUT] = ode45(ODEFUN,[0 Ts], xHistory(k,:)');
    xHistory(k+1,:) = YOUT(end,:);
    waitbar(k*Ts/Duration,hbar);
  
    
end
close(hbar)
