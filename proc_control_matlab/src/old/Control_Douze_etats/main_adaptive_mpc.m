%clc; clear;
cf = ConfigAUV8();
%% Determiner les specification du système
nx = 12;  % nombre d'états
ny = 12;  % Nombre de sorties
nu = 8;   % Nombre d'entré
Ts = 0.1; % Période d'echantillionage
p = 20;   % Horizon de prediction
m =2;    % Horizon de Controle

Duration = 60;

%Forces Minmax Thrusters initailes
TMIN ={-26;-26;-26;-26;-26;-26;-26;-26};
TMAX ={ 32; 32; 32; 32; 32; 32; 32; 32};
MvTarget={0; 0; 0 ;0 ;-17.5 ;17.5 ;-17.5; 17.5};
%Vitesse Max
% VMIN ={-2;-2;-2;-2;-2;-2;-2;-2;-2;-2;-2;-2};
% VMAX ={ 2; 2; 2; 2; 2; 2; 2; 2; 2; 2; 2; 2};

% Poids du controleur initiales
OV =[ 50 50 50 10 10 10 0 0 0 0 0 0 ];  %OutputVariables
MV =[0.1 0.1 0.1 0.1 0.1 0.1 0.1 0.1]; %ManipulatedVariables
MVR=[5 5 5 5 .1 .1 .1 .1]; %.ManipulatedVariablesRate

% Constante pour bloc areospace
I=cf.I;
mass=cf.mass;

%% Initialiser le comtrolleur MPC
% Conditions initiales
Xi=[0;0;0;0;0;0;0;0;0;0;0;0];%repmat(0.01,nx,1); % états initials
Ui= [0;0;0;0;0;0;0;0];%repmat(0.0,nu,1);   % Commande initials

%liniéarisation du modèle aux conditions initales.
[A,B,C,D] = AUVStateJacobianFcn(Xi,Ui);   

% création de l'objet state space.
AUVPlant =PlantUpdate(Xi,Ui,Ts);
% Création du controleur MPC.
mpcobj =mpc(AUVPlant);

%Ajout des poids et gains
mpcobj.MV = struct('Min',TMIN,'Max',TMAX);%,'Target',MvTarget);
mpcobj.Weights.OutputVariables = OV;
mpcobj.Weights.ManipulatedVariables = MV;
mpcobj.Weights.ManipulatedVariablesRate = MVR;

% mpcobj.OutputVariables=struct('Min',VMIN,'Max',VMAX);
mpcobj.PredictionHorizon =p;
mpcobj.ControlHorizon=m;
x=mpcstate(mpcobj);
results = review(mpcobj);

options = mpcmoveopt;
options.MVTarget = [0 0 0 0 -4 4 -4 4]; 
%% Simualtion


hbar = waitbar(0,'awaille');
yHistory = zeros(1,ny);
%xHistory= Xi.';
lastMV =Ui; 
uHistory = lastMV.';
for k = 1:(Duration/Ts)
    tic;
    % Set references for previewing
    t = linspace(k*Ts, (k+p-1)*Ts,p);
    yref = QuadrotorReferenceTrajectory(t);
    % Compute the control moves with reference previewing.
    %xk = xHistory(k,:);
    yk=  yHistory(k,:);
    [Cplant, Nominal]= PlantUpdate(yk.',lastMV,Ts);
   
       [uk,info] = mpcmoveAdaptive(mpcobj,x,Cplant,Nominal,yk,yref.',[]);
     
    
     uHistory(k+1,:) = uk.';
     lastMV =  uk;
    toc;
    % Update states.
     
    ODEFUN = @(t,yk) AUVStateSimFcn(yk,uk);
    [TOUT,YOUT] = ode45(ODEFUN,[0 Ts], yHistory(k,:)');
    yHistory(k+1,:) = YOUT(end,:);
   % xHistory(k+1,:)=[yHistory(k+1,4:5),yHistory(k+1,7:12)];
    waitbar(k*Ts/Duration,hbar);

    
end
close(hbar)

