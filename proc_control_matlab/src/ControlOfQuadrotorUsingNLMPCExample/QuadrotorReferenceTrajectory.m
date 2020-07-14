function [ xdesired ] = QuadrotorReferenceTrajectory( t )
% This function generates reference signal for nonlinear MPC controller
% used in the quadrotor path following example.

% Copyright 2019 The MathWorks, Inc.

%#codegen
x = 6*sin(t/3);
y = -6*sin(t/3).*cos(t/3);
z = 6*sin(t/3);

% if t <= 10 
% x = 0*t +3;%6*sin(t/3);
% y = 0*t -3;%*sin(t)-3.5;%-6*sin(t/3).*cos(t/3);
% z = (.5)*t ;%*t+x;%6*sin(t/3);
% else
% x = 1*(10-t) +3;
% y = 0*t -3;
% z=  .5*10 +0*t;
% end
phi = ones(1,length(t));
theta =ones(1,length(t));
psi = ones(1,length(t));
xdot = ones(1,length(t));
ydot = ones(1,length(t));
zdot = ones(1,length(t));
phidot = ones(1,length(t));
thetadot = ones(1,length(t));
psidot = ones(1,length(t));

xdesired = [x;y;z;phi;theta;psi;xdot;ydot;zdot;phidot;thetadot;psidot];
end

