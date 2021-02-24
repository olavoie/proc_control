%% Determiner les specification du système
    nx = 12;  % nombre d'états
    ny = 12;  % Nombre de sorties
    nu = 8;   % Nombre d'entré
    Ts = 0.25; % Période d'echantillionage
    p = 10;   % Horizon de prediction
    m =5;    % Horizon de Controle

% Modèle du thruster
    %load('T200_Identification.mat');
    load('T200-Spec-16V.mat');
% Données pour lookup table.
    N = T200Spec16V{:,6};% Force en Newton
    PWM = T200Spec16V{:,1};% PWM
    RPM = T200Spec16V{:,2}; % RPM

%Forces Minmax Thrusters initailes
    tmax=32;
    tmin=-26;
    TMIN ={tmin; tmin; tmin; tmin; tmin; tmin; tmin; tmin};
    TMAX ={tmax; tmax; tmax; tmax; tmax; tmax; tmax; tmax};
    MvTarget={0; 0; 0 ;0 ;-17.5 ;17.5 ;-17.5; 17.5};
%Vitesse Max
    VMIN ={-2;-2;-2;-2;-2;-2;-2;-2;-2;-2;-2;-2};
    VMAX ={ 2; 2; 2; 2; 2; 2; 2; 2; 2; 2; 2; 2};

% Poids du controleur initiales
    OV =[ 70 60 70 50 50 50 0 0 0 0 0 0 ];  %OutputVariables
    MV =[.2 .2 0.2 .2 0.2 0.2 0.2 0.2]; %ManipulatedVariables
    MVR=[.1,.1 .1 .1 .3 .3 .3 .3]; %.ManipulatedVariablesRate

%% Initialiser le comtrolleur MPC
% Conditions initiales
Xi=[0;0;.31;0;0;0;0;0;0;0;0;0];%repmat(0.01,nx,1); % états initials
Ui= [0;0;0;0;0;0;0;0];%repmat(0.0,nu,1);   % Commande initials

%liniéarisation du modèle aux conditions initales.
[Ac,Bc,Cc,Dc] = AUVJacobianMatrix(Xi);   
 rank(ctrb(Ac,Bc))
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
pole(AUVPlant)

% Création du controleur MPC.
mpcobj =mpc(AUVPlant);
mpcobj.PredictionHorizon =p;
mpcobj.ControlHorizon=m;
%Ajout des poids et gains

mpcobj.Weights.OutputVariables = OV;
mpcobj.Weights.ManipulatedVariables = MV;
mpcobj.Weights.ManipulatedVariablesRate = MVR;
mpcobj.MV = struct('Min',TMIN,'Max',TMAX);%,'Target',MvTarget);
% mpcobj.OutputVariables=struct('Min',VMIN,'Max',VMAX);

xss=mpcstate(mpcobj);
results = review(mpcobj);
mpcobj.Optimizer.ActiveSetOptions.ConstraintTolerance=0.01;
options = mpcmoveopt;
%options.MVTarget = [0 0 0 0 -4 4 -4 4]; 


%% Initialiser le comtrolleur MPC non lineaire

OVnl =[ 70 60 70 50 50 50 50 0 0 0 0 0 0 ];  %OutputVariables
Xinl=[0;0;-.2270;1;0;0;0;0;0;0;0;0;0];
nlobj = nlmpc(13, 13, nu);

nlobj.Model.StateFcn = "AUVQuatSimFcn";
nlobj.Jacobian.OutputFcn="AUVQuatSimFcn";
nlobj.Jacobian.StateFcn = @AUVQuatJacobianMatrix;



nlobj.Ts = Ts;
nlobj.PredictionHorizon = 4;
nlobj.ControlHorizon = 2;

nlobj.MV = struct('Min',TMIN,'Max',TMAX);%,'Target',MvTarget);
nlobj.Weights.OutputVariables = OVnl;
nlobj.Weights.ManipulatedVariables = MV;
nlobj.Weights.ManipulatedVariablesRate = MVR;

% Parametre du solver
nlobj.Optimization.SolverOptions.ConstraintTolerance = 0.02;
nlobj.Optimization.SolverOptions.OptimalityTolerance = 0.02;
nlobj.Optimization.SolverOptions.FunctionTolerance = 0.02;
nlobj.Optimization.SolverOptions.StepTolerance=0.1;
nlobj.Optimization.SolverOptions.UseParallel=true();
nlobj.Optimization.SolverOptions.Algorithm='sqp';
nlobj.Optimization.RunAsLinearMPC='adaptive';%'timevarying';
nlobj.Optimization.MVInterpolationOrder=1;
%nlobj.Optimization.SolverOptions.HessianApproximation='finite-difference';
%nlobj.Optimization.UseSuboptimalSolution=true();
%nlobj.Optimization.SolverOptions.SubproblemAlgorithm='direct';
%nlobj.Optimization.SolverOptions.MaxIterations=2;

validateFcns(nlobj,Xinl,Ui);