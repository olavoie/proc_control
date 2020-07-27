function [plant,Nominal] = PlantUpdate(X,U,Ts)

% Lineariser le model dynamique

[Ac, Bc, Cc, Dc]=AUVStateJacobianFcn(X,U);

% Generate discrete-time model

nx = size(Ac,1);
nu = size(Bc,2);
M = expm([[Ac Bc]*Ts; zeros(nu,nu+nx)]);
A = M(1:nx,1:nx);
B = M(1:nx,nx+1:nx+nu);
C = Cc;
D = Dc;
plant=ss(A,B,C,D,Ts);
% cplant=ss(Ac,Bc,Cc,Dc);
% plant=c2d(cplant,Ts);
% Nominal conditions for discrete-time plant
Nominal= struct('X',X,...
                'U',U,...
                'Y',Cc*X + Dc*U,...
                'DX',plant.A*X+plant.B*U-X);

end
