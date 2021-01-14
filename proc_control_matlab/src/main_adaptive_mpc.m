%clc; clear;
cf = ConfigAUV8();

%run('trajec.m');

%% Determiner les specification du système
    nx = 12;  % nombre d'états
    ny = 12;  % Nombre de sorties
    nu = 8;   % Nombre d'entré
    Ts = 0.1; % Période d'echantillionage
    p = 10;   % Horizon de prediction
    m =2;    % Horizon de Controle

% Modèle du thruster
    load('T200_Identification.mat');
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
    OV =[ 70 50 60 50 50 70 0 0 0 0 0 0 ];  %OutputVariables
    MV =[.1 .1 .1 .1 0.1 0.1 0.1 0.1]; %ManipulatedVariables
    MVR=[.1,.1 .1 .1 .3 .3 .3 .3]; %.ManipulatedVariablesRate

% Constante pour bloc areospace
    I=cf.I;
    mass=cf.mass;

% Perturbations des vages
    %Vages X
    waX=2;          % Amplitude
    wfX=pi/2;         % Frequence
    wpX=0;          % Phase
    %Vages Y
    waY=3;          % Amplitude
    wfY=pi/2;         % Frequence
    wpY=pi/2;       % Phase
    %Vages Z
    waZ= 4;         % Amplitude
    wfZ=pi/2;         % Frequence
    wpZ=pi;         % Phase
    %Vages RX (Roll)
    waPhi= .5;      % Amplitude
    wfPhi= pi/2;      % Frequence
    wpPhi=0;        % Phase
    %Vages Ry (Pitch)
    waTheta=.25;    % Amplitude
    wfTheta=pi/2;     % Frequence
    wpTheta=pi/2;   % Phase
    %Vages Rz (Yaw)
    waPsi=.5;       % Amplitude
    wfPsi=pi/2;       % Frequence
    wpPsi=pi;       % Phase

% Parametres Messages ROS
    Duration = 229;
    gazeboStep=1/50;
    telemetryStep=1/30;
    referenceFrame = cf.referenceFrame;
    modelName = cf.modelName;
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
mpcobj.Optimizer.ActiveSetOptions.ConstraintTolerance=0.01;
options = mpcmoveopt;
options.MVTarget = [0 0 0 0 -4 4 -4 4]; 
%% Constantes pour Gazebo.


%% Initialiser le comtrolleur non linéaire MPC
% nlobj = nlmpc(nx, ny, nu);
% 
% nlobj.Model.StateFcn = "AUVStateSimFcn";
% nlobj.Jacobian.StateFcn = @AUVStateJacobianFcn;
% rng(0)
% validateFcns(nlobj,rand(nx,1),rand(nu,1));
% 
% nlobj.Ts = Ts;
% nlobj.PredictionHorizon = p;
% nlobj.ControlHorizon = m;
% 
% nlobj.MV = struct('Min',TMIN,'Max',TMAX);%,'Target',MvTarget);
% nlobj.Weights.OutputVariables = OV;
% nlobj.Weights.ManipulatedVariables = MV;
% nlobj.Weights.ManipulatedVariablesRate = MVR;
%% Trajectoire



% %Trajectoire avec prédiction Beta!!!
% trajectoire = repmat(zeros(p,ny),[1 1 (Duration/Ts)+1]);
% for k = 1:(Duration/Ts)+1
%     %t = linspace(k*Ts, (k+p-1)*Ts,p);
%     trajectoire(:,:,k)= subpose(:,k:k+p-1).';
% end
% tt =0:0.1:Duration;% linspace(0, (Duration-1)*Ts,Duration/Ts);
% data.time=tt.';
% data.signals.values=trajectoire;
% data.signals.dimensions=[p ny];



% Trajectoire sans prédiction
% T=Duration;
% P0=0;
% Pf=10;
% am=0.3;
% Tf=30;
% Tb=(Tf/2)-((am^2*Tf^2-4*am*(Pf-P0))^.5)/(2*am);
% 
% pd=zeros(1,Duration/Ts);
% time=linspace(Ts,T,Duration/Ts);
% for i=1:Duration/Ts
%    
%     if time(i)<=Tb  %Accélération
%      pd(i)= P0+(am/2)*time(i)^2;
%     elseif time(i) <= Tf-Tb %vitesse constante
%      pd(i)=((Pf+P0-am*Tb*Tf)/2)+am*Tb*time(i);
%     elseif time(i)<=Tf % Décélération
%      pd(i)= Pf-((am*Tf^2)/2)+am*Tf*time(i)-(am/2)*time(i)^2;
%     else %position finale
%        pd(i)=Pf;
%     end
% end
% %Afficher la courbe
% plot(time,pd);
% title('Trajectoire désirée ');
% xlabel('Temps (sec)');
% ylabel('Distance (m)');



%% Open simulink model
msgbox("Le simulink load. Attend Criss!")
open_system('plant')
