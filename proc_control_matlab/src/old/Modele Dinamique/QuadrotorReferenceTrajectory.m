function [ xdesired ] = QuadrotorReferenceTrajectory( t )
% This function generates reference signal for nonlinear MPC controller
% used in the quadrotor path following example.

% Copyright 2019 The MathWorks, Inc.

%#codegen

%if t<=8
% 
% x = 0*t; %6*sin(t/3);
% y = 0*t; %-6*sin(t/3).*cos(t/3);
% z = -t/5; %6*cos(t/3);
% elseif t<12
% x = 0*t; %6*sin(t/3);
% y = 0*t; %-6*sin(t/3).*cos(t/3);
% z = -1.6+0*t; %6*cos(t/3); 
% else
% x = (t-12); %6*sin(t/3);
% y = 0*t; %-6*sin(t/3).*cos(t/3);
% z = 0*t-1.6; %6*cos(t/3);
% end
x = t/3; %6*sin(t/3);
y = 0*t; %-6*sin(t/3).*cos(t/3);
z = 0*t; %6*cos(t/3);
phi = t/3;zeros(1,length(t));
theta = zeros(1,length(t));
psi = zeros(1,length(t));
xdot = zeros(1,length(t));
ydot = zeros(1,length(t));
zdot = zeros(1,length(t));
phidot = zeros(1,length(t));
thetadot = zeros(1,length(t));
psidot = zeros(1,length(t));

xdesired = [x;y;z;phi;theta;psi;xdot;ydot;zdot;phidot;thetadot;psidot];
end

