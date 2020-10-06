clc; clear;
nx = 8;  % nombre d'états
ny = 12;  % Nombre de sorties
nu = 8;   % Nombre d'entré

Xi=repmat(1,nx,1); % états initials
Ui=repmat(0.0,nu,1);   % Commande initials
[A, B, C, D]=AUVStateJacobianFcn(Xi,Ui);
CPlant=ss(A,B,C,D);
co = ctrb(CPlant);
controllability = rank(co)
unco = length(A) - rank(co)

Q=C'*C;
R=1;

K = lqr(A,B,Q,R);

Ac = [(A-B*K)];
Bc = [B];
Cc = [C];
Dc = [D];
sys_cl = ss(Ac,Bc,Cc,Dc);
t = 0:0.01:8;
r =repmat(10,801,8);
[y,t,x]=lsim(sys_cl,r,t)
[AX,H1,H2] = plotyy(t,y(:,1),t,y(:,2),'plot');
set(get(AX(1),'Ylabel'),'String','cart position (m)')
set(get(AX(2),'Ylabel'),'String','pendulum angle (radians)')
title('Step Response with LQR Control')