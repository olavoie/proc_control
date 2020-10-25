function [ xdesired ] = QuadrotorReferenceTrajectory( t )
% This function generates reference signal for nonlinear MPC controller
% used in the quadrotor path following example.

% Copyright 2019 The MathWorks, Inc.

%#codegen
xdesired=zeros(size(t,2),12);

P0=0;
Pf=2;
am=0.1;
Tf=30;
Tb=(Tf/2)-((am^2*Tf^2-4*am*(Pf-P0))^.5)/(2*am);
for i=1:size(t,2)
%if t(i)<=8

%x = 0*t(i); %6*sin(t/3);
%y = 0*t(i); %-6*sin(t/3).*cos(t/3);
%z = -t(i)/5; %6*cos(t/3);

%elseif t(i)<10
%x = 0*t(i); %6*sin(t/3);
%y = 0*t(i); %-6*sin(t/3).*cos(t/3);
%z = 0*t(i)-1.6; %6*cos(t/3);

%else
%x = (t(i)-10); %6*sin(t/3);
%y = 0*t(i); %-6*sin(t/3).*cos(t/3);
%z = 0*t(i)-1.6; %6*cos(t/3);

%end
% x = t/3; %6*sin(t/3);
%  y = 0*t(i); %-6*sin(t/3).*cos(t/3);
%  z = 0*t(i); %6*cos(t/3);
%Trajectoire



    if t(i)<=Tb  %Accélération
     x= P0+(am/2)*t(i)^2;
    elseif t(i) <= Tf-Tb %vitesse constante
     x=((Pf+P0-am*Tb*Tf)/2)+am*Tb*t(i);
    elseif t(i)<=Tf % Décélération
     x= Pf-((am*Tf^2)/2)+am*Tf*t(i)-(am/2)*t(i)^2;
    else %position finale
       x=Pf;
    end

y=0*t(i);
z=0*t(i);
phi =0*t(i);
theta = 0*t(i); 
psi = 0*t(i);
xdot=0*t(i);
ydot = 0*t(i);
zdot = 0+0*t(i);
phidot = 0*t(i);
thetadot = 0*t(i);
psidot = 0*t(i);

xdesired(i,:) = [x,y,z,phi,theta,psi,xdot,ydot,zdot,phidot,thetadot,psidot];
end

end

