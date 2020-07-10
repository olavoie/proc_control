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

%distance truster x y z selon centre geommétrique
% D14 distance thruster 1 a 4.
% D58 distance thruster 5 a 8.
% a14 angle thruster 1 a 4.
% dz distance entre les increments sur le frame.
% PZ position des truster sur le frame.
syms ('D14',[1 3]); syms('D58',[1 3]) ; syms a14 dz ; syms ('PZ',[1,4])

% centre de gravité RG et centre de flotataison RB
syms ('RG',[1 3]); syms('RB',[1 3])

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

%% Definire la matrice thrusters

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
            
            
