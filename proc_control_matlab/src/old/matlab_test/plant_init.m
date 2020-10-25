%clc;clear;
load('T200-Spec-16V.mat');
%% Constantes du Plant
% z;        %Position des truster sur le frame.
%           %(0 = milieu, 1= position bas, -1= postion haut)(t15,t26,t37,t48)
% dz;       % Distance entre les postions du frame.
% d14;      % Distance x y z / angles des trusters 1 - 4. 
% a14;      
% d58;      % Distance x y z des trusters 5 - 8.
% psl;      % Power supply limitation
% nbt;      % nombre de thrusters
% RG;       % Centre de masse
% RB;       % Centre de flotaison
% I;        % Inertie
% mass;
% volume;
% rho;
% g;
% CD;       % Coefficient de drag
% AF;       % Aire de la surface

RB =[ 0.001,... x
     -0.003,... y
      0.027]; % z
  
PZ = [ 0, ...
      0, ...
      0, ...
      0];

dz = 0.015;

D14 = [ 0.292, ...
        0.173, ...   
        0.082];

D58 = [ 0.1815, ...
        0.159, ...   
        0.082];

psl = 0.5;
nbt = 8;

RG =[ 0.001,... x
     -0.003,... y
      0.027]; % z

RB =[ 0.001,... x
     -0.003,... y
      0.027]; % z

mass = 33.95;
volume = 0.027;

I = [0.5358, 0.001, 0.01;... Ixx Ixy Ixz 0.5358
     0.002, 1.47, 0.005;... Iyx Iyy Iyz
     0.01, 0.005, 1.68]; % Izx Izy Izz
rho = 998;
g = 9.81;
CD = [1, 1, 1, 1, 1, 1];
AF = [0.12, 0.22, 0.292];

% Angle des moteurs.
a=zeros(3,8);

%     Z  Y  X
a = [ 0 90 45;
      0 90 -45;
      0 90 45;
      0 90 -45;
      0 0 0;
      0 180 0;
      0 0 0;
      0 180 0];
a_rad = deg2rad(a);

l1 = [(D14(3)-RB(3)+PZ(1)*dz),... rx
    (D14(3)-RB(3)+PZ(1)*dz),... ry
    -hypot( D14(1)-RB(1), D14(2)-RB(2))]; %rz

l2 = [-(D14(3)-RB(3)+PZ(2)*dz),...rx
     (D14(3)-RB(3)+PZ(2)*dz),...ry
     -hypot( D14(1)+RB(1), D14(2)-RB(2))];%rz

l3 = [(D14(3)-RB(3)+PZ(3)*dz),...rx
     (D14(3)-RB(3)+PZ(3)*dz),...ry
     hypot(D14(1)+RB(1), D14(2)+RB(2))];%rz

l4 = [-(D14(3)-RB(3)+PZ(4)*dz),...rx
     (D14(3)-RB(3)+PZ(4)*dz),...ry
     hypot(D14(1)-RB(1), D14(2)+RB(2))];%rz

l5 = [(D58(2)-RB(2)+PZ(1)*dz),...
     -(D58(1)-RB(1)+PZ(1)*dz), 0];

l6 = [-(D58(2)-RB(2)+PZ(2)*dz),...
      -(D58(1)+RB(1)+PZ(2)*dz), 0];

l7 = [-(D58(2)+RB(2)+PZ(3)*dz),...
    (D58(1)+RB(1)+PZ(3)*dz), 0];

l8 = [(D58(2)+RB(2)+PZ(4)*dz),...
     (D58(1)-RB(1)+PZ(2)*dz), 0];
 
% Conditions initiales
% Initial position in inertial axes [Xe,Ye,Ze]:
IP = [0.01 .01 .01];
% Initial velocity in body axes [U,v,w]:
IV = [0.01 0.01 0.001];
% Initial Euler orientation [roll, pitch, yaw]:
IE = [0.001 0.001 0.001];
% Initial body rotation rates [p,q,r]:
IB = [0.001 0.001 0.001];

%% Constante d'IMU
IMU_POSE = [0 0 0]; % xyz
update_rate = 1/40; % s


%% Données des moteurs
% Données pour lookup table.
N = T200Spec16V{:,6};% Force en Newton
PWM = T200Spec16V{:,1};% PWM

%% Données pour le contrôleur MPC
% %% Determiner les specification du système
% 
  Ts = 0.1; % Période d'echantillionage
%  p = 15;   % Horizon de prediction
%  m = 2;    % Horizon de Controle
% % 
% % %Forces Minmax Thrusters initailes
%  TMIN =[-26;-26;-26;-26;-26;-26;-26;-26];
%  TMAX =[ 32; 32; 32; 32; 32; 32; 32; 32];
% % 
% % % Poids du controleur initiales
%  OV =[ 20 20 15 20 20 20 0 0 0 0 0 0];  % OutputVariables
%  MV =[0.3 0.3 0.3 0.3 0.1 0.1 0.1 0.1]; % ManipulatedVariables
%  MVR=[0.1 0.1 0.1 0.1 0.1 0.1 0.1 0.1]; % ManipulatedVariablesRate
% 
% %% Initialiser le comtrolleur MPC
% % Conditions initiales
% Xi= zeros(12,1); % états initials
% Ui=zeros(8,1);   % Commande initials
% 
% %liniéarisation du modèle aux conditions initales.
% [A,B,C,D] = AUVStateJacobianFcn(Xi,Ui);   
% 
% % création de l'objet state space.
% AUVPlant = ss(A,B,C,D);
% 
% % Création du controleur MPC.
% mpcobj = mpc(AUVPlant,Ts);
% 
% %Ajout des poids et gains
% mpcobj.MV = struct('Min',TMIN,'Max',TMAX);
% mpcobj.Weights.OutputVariables = OV;
% mpcobj.Weights.ManipulatedVariables = MV;
% mpcobj.Weights.ManipulatedVariablesRate = MVR;

%% Génération de trajectoire
%Trajectoire
T=25;
P0=0;
Pf=3;
am=0.1;
Tf=20;
Tb=(Tf/2)-((am^2*Tf^2-4*am*(Pf-P0))^.5)/(2*am);

pd=zeros(1,T/Ts);
t=linspace(Ts,T,T/Ts);

for i=1:T/Ts
   
    if t(i)<=Tb  %Accélération
     pd(i)= P0+(am/2)*t(i)^2;
    elseif t(i) <= Tf-Tb %vitesse constante
     pd(i)=((Pf+P0-am*Tb*Tf)/2)+am*Tb*t(i);
    elseif t(i)<=Tf % Décélération
     pd(i)= Pf-((am*Tf^2)/2)+am*Tf*t(i)-(am/2)*t(i)^2;
    else %position finale
       pd(i)=Pf;
    end
end
Position_Data=0
plot(t,pd);
title('Trajectoire désirée ');
xlabel('Temps (sec)');
ylabel('Distance (m)');