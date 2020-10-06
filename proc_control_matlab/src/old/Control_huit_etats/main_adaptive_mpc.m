clc; clear;

%% Determiner les specification du système
nx = 8;  % nombre d'états
ny = 12;  % Nombre de sorties
nu = 8;   % Nombre d'entré
Ts = 0.1; % Période d'echantillionage
p = 20;   % Horizon de prediction
m =3;    % Horizon de Controle

Duration = 60;

%Forces Minmax Thrusters initailes
TMIN ={-26;-26;-26;-26;-26;-26;-26;-26};
TMAX ={ 32; 32; 32; 32; 32; 32; 32; 32};

%Vitesse Max
% VMIN ={-2;-2;-2;-2;-2;-2;-2;-2;-2;-2;-2;-2};
% VMAX ={ 2; 2; 2; 2; 2; 2; 2; 2; 2; 2; 2; 2};

% Poids du controleur initiales
OV =[ 0 0 0 0 0 0 100 100 100 50 50 50];  %OutputVariables
MV =[0.001 0.001 0.001 0.001 0.001 0.001 0.001 0.001]; %ManipulatedVariables
MVR=[5 5 5 5 5 5 5 5]; %.ManipulatedVariablesRate


%% Initialiser le comtrolleur MPC
% Conditions initiales
Xi=repmat(0.0,nx,1); % états initials
Ui=repmat(0.0,nu,1);   % Commande initials

%liniéarisation du modèle aux conditions initales.
[A,B,C,D] = AUVStateJacobianFcn(Xi,Ui);   

% création de l'objet state space.
AUVPlant =PlantUpdate(Xi,Ui,Ts);

% Création du controleur MPC.
mpcobj =mpc(AUVPlant);

%Ajout des poids et gains
mpcobj.MV = struct('Min',TMIN,'Max',TMAX);
mpcobj.Weights.OutputVariables = OV;
mpcobj.Weights.ManipulatedVariables = MV;
mpcobj.Weights.ManipulatedVariablesRate = MVR;
% mpcobj.OutputVariables=struct('Min',VMIN,'Max',VMAX);
mpcobj.PredictionHorizon =p;
mpcobj.ControlHorizon=m;
x=mpcstate(mpcobj);
results = review(mpcobj)
pole(AUVPlant)
%% Simualtion
options = mpcmoveopt;
options.MVTarget = [0 0 0 0 0 0 0 0]; 

hbar = waitbar(0,'awaille');
yHistory = zeros(1,ny);
xHistory= Xi.';
lastMV =Ui; 
uHistory = lastMV.';
for k = 1:(Duration/Ts)
    tic;
    % Set references for previewing
    t = linspace(k*Ts, (k+p-1)*Ts,p);
    yref = QuadrotorReferenceTrajectory(t);
    % Compute the control moves with reference previewing.
    xk = xHistory(k,:);
    yk=  yHistory(k,:);
    [Cplant, Nominal]= PlantUpdate(xk.',lastMV,Ts);
   
       [uk,info] = mpcmoveAdaptive(mpcobj,x,Cplant,Nominal,yk,yref.',[]);
     
    
     uHistory(k+1,:) = uk.';
     lastMV =  uk;
    toc;
    % Update states.
     
    ODEFUN = @(t,yk) AUVStateSimFcn(yk,uk);
    [TOUT,YOUT] = ode45(ODEFUN,[0 Ts], yHistory(k,:)');
    yHistory(k+1,:) = YOUT(end,:);
    xHistory(k+1,:)=[yHistory(k+1,4:5),yHistory(k+1,7:12)];
    waitbar(k*Ts/Duration,hbar);

    
end
close(hbar)

