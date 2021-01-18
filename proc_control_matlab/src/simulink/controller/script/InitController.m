%% Determiner les specification du système
    nx = 12;  % nombre d'états
    ny = 12;  % Nombre de sorties
    nu = 8;   % Nombre d'entré
    Ts = 0.1; % Période d'echantillionage
    p = 10;   % Horizon de prediction
    m =2;    % Horizon de Controle

% Modèle du thruster
    %load('T200_Identification.mat');
    load('T200-Spec-16V.mat');
% Données pour lookup table.
    N = T200Spec16V{:,6};% Force en Newton
    PWM = T200Spec16V{:,1};% PWM

%Forces Minmax Thrusters initailes
    tmax=32;
    tmin=-26;
    TMIN =[tmin; tmin; tmin; tmin; tmin; tmin; tmin; tmin];
    TMAX =[tmax; tmax; tmax; tmax; tmax; tmax; tmax; tmax];
    MvTarget={0; 0; 0 ;0 ;-17.5 ;17.5 ;-17.5; 17.5};
%Vitesse Max
    VMIN ={-2;-2;-2;-2;-2;-2;-2;-2;-2;-2;-2;-2};
    VMAX ={ 2; 2; 2; 2; 2; 2; 2; 2; 2; 2; 2; 2};

% Poids du controleur initiales
    OV =[ 70 60 60 50 50 70 0 0 0 0 0 0 ];  %OutputVariables
    MV =[.01 .01 .01 .01 0.05 0.05 0.05 0.05]; %ManipulatedVariables
    MVR=[.1,.1 .1 .1 .3 .3 .3 .3]; %.ManipulatedVariablesRate

%% Initialiser le comtrolleur MPC
% Conditions initiales
Xi=[0;0;0;0;0;0;0;0;0;0;0;0];%repmat(0.01,nx,1); % états initials
Ui= [0;0;0;0;0;0;0;0];%repmat(0.0,nu,1);   % Commande initials

%liniéarisation du modèle aux conditions initales.
[Ac,Bc,Cc,Dc] = AUVStateJacobianFcn(Xi,Ui);   

% création de l'objet state space.
% Generate discrete-time model
nx = size(Ac,1);
nu = size(Bc,2);
M = expm([[Ac Bc]*Ts; zeros(nu,nu+nx)]);
A = M(1:nx,1:nx);
B = M(1:nx,nx+1:nx+nu);
C = Cc;
D = Dc;
AUVPlant=ss(A,B,C,D,Ts);
 

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
mpcobj.Optimizer.ActiveSetOptions.ConstraintTolerance=0.01;
options = mpcmoveopt;
options.MVTarget = [0 0 0 0 -4 4 -4 4]; 