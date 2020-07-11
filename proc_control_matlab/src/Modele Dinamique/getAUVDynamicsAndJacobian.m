% Ce script défini un modèle non linéaire dans un domaine continue
% de la dynamique du sous marin. Il génere par la suit les équoitions
% d'états ainsi que la jacobienne qui seront utilisé par le controlleur.

% Alexandre Lamarre, Aleandre Desgagnié

clear; clc;
%% Création des variables Symboliques
% Position 6 DOFF selon t
syms xt(t) yt(t) zt(t) phit(t) thetat(t) psit(t)

% Vitesse 6 DOFF selon t 
syms xdott(t) ydott(t) zdott(t) phidott(t) thetadott(t) psidott(t) 

% thrusters
%syms u1 u2 u3 u4 u5 u6 u7 u8
syms ('U',[1,8])

% position et vitesse 6DOFF
syms x y z phi theta psi xdot ydot zdot phidot thetadot psidot

% distance truster x y z selon centre geommétrique
% D14 distance thruster 1 a 4.
% D58 distance thruster 5 a 8.
% a14 angle thruster 1 a 4.
% dz distance entre les increments sur le frame.
% PZ position des truster sur le frame.
syms ('D14',[1 3]); syms('D58',[1 3]) ; syms a14 dz ; syms ('PZ',[1,4])

% masse et volume du prototype
syms mass volume

% coefficient de drag
syms cd

% aire surface du sub
syms af

% matrice d'inertie
syms ('I', [3, 3]);

% centre de gravité RG et centre de flotataison RB
syms ('RG',[1 3]); syms('RB',[1 3])

%% Constantes
rho = 998;
g = 9.81;

%% Matrice de transformation 
% Angle Euler X Y Z
Rz = [ cos(psit), -sin(psit), 0;
       sin(psit),  cos(psit), 0;
       0        ,  0        , 1];
   
Ry = [ cos(thetat), 0,  sin(thetat);
       0          , 1,  0;
      -sin(thetat), 0,  cos(thetat)];
  
Rx = [1, 0        , 0;
      0, cos(phit), -sin(phit);
      0, sin(phit), cos(phit)];

% Matrice de transformation vitesse liéaire du frame sub au frame world
J1 = Rz*Ry*Rx;

% Matrice de transformation vitesse angulaire du frame sub au frame world
%J2⁻¹
J2i=[[1;0;0],Rx.'*[0;1;0],Rx.'*Ry.'*[0;0;1]];
J2=simplify(inv(J2i));

J= diag([J1,J2]);

%% Matrice de gravite
% Definition de la matrice de gravite.
w = mass * g;
b = rho * g * volume;

X  =  (w-b)*sin(thetat);...
Y  =  (w-b)*cos(thetat)*sin(phit);...
Z  =  (w-b)*cos(thetat)*cos(phit);...

Rx = -(RG2*w-RB2*b)*cos(thetat)*cos(phit)+...
      (RG3*w-RB3*b)*cos(thetat)*sin(phit);

Ry =  (RG3*w-RB3*b)*sin(thetat)+...
      (RG1*w-RB1*b)*cos(thetat)*cos(phit);

Rz =  (RG1*w-RB1*b)*cos(thetat)*sin(phit)-...
      (RG2*w-RB2*b)*sin(thetat);

G  = [X;Y;Z;Rx;Ry;Rz];

%% Matrice de masse et d'inertie
% Definition des quatres matrices 3x3 pour former la matrice
% des masses du corp rigide.
Mrb1 = diag(repmat(mass,1,3));
Mrb2 = [0, mass * RG3, -mass * RG2; ...
        -mass * RG3, 0, mass * RG1; ...
        mass * RG2, -mass * RG1, 0];
Mrb3 = [0, -mass * RG3, mass * RG2; ...
        mass * RG3, 0, -mass * RG1; ...
        -mass * RG2, mass * RG1, 0];

forme= (diag(repmat(2,1,3))-1); % diag 1 avec -1 partout
Mrb4 = I.*forme;

% Matrice des masses du corps rigide.
MRB = [Mrb1, Mrb2; ... 
       Mrb3, Mrb4];

% Matrice des masses ajoutees.
MA=zeros(6,6);

% Calcul de la matrice des masses et inerties.
M = MRB + MA;

%% Matrice des forces de Coriolis
% Définition des matrices 3x3 pour former la matrice de
% Coriolis (corps rigide).
Crb1 = zeros(3,3);
Crb23 = [0, mass * zdott, -mass * ydott; ...
         -mass * zdott, 0, mass * xdott; ...
         mass * ydott, -mass * xdott, 0];
Crb4 = [0, I3_3 * psidott, -I2_2 * thetadott; ...
        -I3_3 * psidott, 0, I1_1 * phidott; ...
        I2_2 * thetadott, -I1_1 * phidott, 0];
% Matrice de Coriolis(Corps rigide)
CRB = [Crb1, Crb23; ...
       Crb23, Crb4];

% Matrice de Coriolis (masse ajoutée)
CA = zeros(6,6);

% Matrice de Coriolis
C = CRB + CA;
    
%% Matrice des forces de drag
xu = (-(1/2) * rho * cd * af) * xdott;
yv = (-(1/2) * rho * cd * af) * ydott;
zw = (-(1/2) * rho * cd * af) * zdott;
kp = (-(1/2) * rho * cd * af) * phidott;
mq = (-(1/2) * rho * cd * af) * thetadott;
nr = (-(1/2) * rho * cd * af) * psidott;

% Matrice quadratic damping.
Dq = diag([xu yv zw kp mq nr]);

% Matrice linear damping.
Dl = zeros(6,6);

D = Dq + Dl;

%% Definir la matrice thrusters

% Thruster effort Mapping Matrix (L)
%       x         y      z      
l1 = [ sin(a14),-cos(a14), 0,... fxyz
    (D14(3)-RG(3)+PZ(1)*dz)*cos(a14),... rx
    (D14(3)-RG(3)+PZ(1)*dz)*sin(a14),... ry
    -hypot( D14(1)-RG(1), D14(2)-RG(2))]; %rz

l2 = [ sin(a14), cos(a14), 0,...fxyz
     -(D14(3)-RG(3)+PZ(2)*dz)*cos(a14),...rx
     (D14(3)-RG(3)+PZ(2)*dz)*sin(a14),...ry
     -hypot( D14(1)+RG(1), D14(2)-RG(2))];%rz

l3 = [ sin(a14),-cos(a14), 0,...fxyz
    (D14(3)-RG(3)+PZ(3)*dz)*cos(a14),...rx
     (D14(3)-RG(3)+PZ(3)*dz)*sin(a14),...ry
     hypot(D14(1)+RG(1), D14(2)+RG(2))];%rz

l4 = [ sin(a14), cos(a14), 0,...fxyz
    -(D14(3)-RG(3)+PZ(4)*dz)*cos(a14),...rx
     (D14(3)-RG(3)+PZ(4)*dz)*sin(a14),...ry
     hypot(D14(1)-RG(1), D14(2)+RG(2))];%rz

l5 = [0, 0, 1, (D58(2)-RG(2)+PZ(1)*dz),...
     -(D58(1)-RG(1)+z(1)*dz), 0];

l6 = [0, 0,-1,-(D58(2)-RG(2)+PZ(2)*dz),...
      -(D58(1)+RG(1)+PZ(2)*dz), 0];

l7 = [0, 0, 1,-(D58(2)+RG(2)+PZ(3)*dz),...
    (D58(1)+RG(1)+PZ(3)*dz), 0];

l8 = [0, 0,-1, (D58(2)+RG(2)+PZ(4)*dz),...
     (D58(1)-RG(1)+PZ(2)*dz), 0];
 
% Matrice thrusters
T = [l1.', l2.', l3.', l4.', l5.' l6.', l7.', l8.'];
% équoition input pour 6doff
allocator = simplify(sum(T*diag(U),2)); 

%% test
cf = ConfigAUV8();
D14val = cf.d14;
D58val = cf.d58;
a14val = cf.a14;
RGval  = cf.RG;
dzval  = cf.dz;
PZval  = cf.z;

y = subs(allocator, [D14 D58 a14 RG dz PZ], [D14val D58val a14val RGval dzval PZval]);
            
            
