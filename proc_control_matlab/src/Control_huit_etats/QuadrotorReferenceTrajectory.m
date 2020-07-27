function [ xdesired ] = QuadrotorReferenceTrajectory( t )
% This function generates reference signal for nonlinear MPC controller
% used in the quadrotor path following example.

% Copyright 2019 The MathWorks, Inc.

%#codegen
xdesired=zeros(12,size(t,2));
for i=1:size(t,2)
if t(i)<=8

x = 0*t(1,i); %6*sin(t/3);
y = 0*t(i); %-6*sin(t/3).*cos(t/3);
z = -t(i)/5; %6*cos(t/3);

elseif t(i)<10
x = 0*t(i); %6*sin(t/3);
y = 0*t(i); %-6*sin(t/3).*cos(t/3);
z = -1.6+0*t(i); %6*cos(t/3); 
else
x = 0*t(i); %6*sin(t/3);
y = (t(i)-10)/2; %-6*sin(t/3).*cos(t/3);
z = 0*t(i)-1.6; %6*cos(t/3);

end
% x = t/3; %6*sin(t/3);
% y = 0*t; %-6*sin(t/3).*cos(t/3);
% z = 0*t; %6*cos(t/3);

phi =0*t(i);
theta = 0*t(i);
psi = 0*t(i);
xdot=0*t(i);
ydot = 0*t(i);
zdot = 0*t(i);
phidot = 0*t(i);
thetadot = 0*t(i);
psidot = 0*t(i);
xdesired(:,i) = [x;y;z;phi;theta;psi;xdot;ydot;zdot;phidot;thetadot;psidot];
end

end

