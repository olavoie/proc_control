% This script defines a continuous-time nonlinear quadrotor model and
% generates a state function and its Jacobian function used by the
% nonlinear MPC controller in the quadrotor path following example.
clc;
clear;
% Copyright 2019 The MathWorks, Inc.

% Create symbolix variables for states, MVs and parameters
syms xt(t) yt(t) zt(t) phit(t) thetat(t) psit(t) xdott(t) ydott(t)...
    zdott(t) phidott(t) thetadott(t) psidott(t) 
syms u1 u2 u3 u4 u5 u6 u7 u8 Ixx Iyy Izz k l m b g
syms x y z phi theta psi xdot ydot zdot phidot thetadot psidot

% phi: roll angle 
% theta: pitch angle 
% psi: yaw angle 
% ui:squared angular velocity of rotor i
% g: gravity
% b: drag constant
% k: lift constant
% l: distance between rotor and com
% Iii: diagonal elements of inertia matrix

cf = ConfigAUV8();
% Set values for dynamics parameters
IxxVal = 1.2; 
IyyVal = 1.2;
IzzVal = 2.3;
kVal = 1;
lVal = 0.25;
mVal = 35;
bVal = 0.2;
gVal = 9.81;
rho =998;
B = rho*cf.volume*gVal; % Calcule la force de flotaison


T = ThrustersMapping(cf); % Avoir la matrice thrusters
 
paramValues = [IxxVal IyyVal IzzVal kVal lVal mVal bVal gVal];

% Group symbolic variables
statet = {xt(t) yt(t) zt(t) phit(t) thetat(t) psit(t) xdott(t) ...
    ydott(t) zdott(t) phidott(t) thetadott(t) psidott(t)};
state = {x y z phi theta psi xdot ydot zdot phidot thetadot psidot};
state_diff = {diff(xt(t),t), diff(yt(t),t), diff(zt(t),t), ...
    diff(phit(t),t), diff(thetat(t),t), diff(psit(t),t)};
state_dot = {xdot ydot zdot phidot thetadot psidot};

% Transformation matrix for angular velocities from inertial frame 
% to body frame
W = [1, 0, -sin(thetat);
    0, cos(phit), cos(thetat)*sin(phit);
    0, -sin(phit), cos(thetat)*cos(phit)];

%R-ZYX Euler
Rz = [cos(psit), -sin(psit), 0;
    sin(psit), cos(psit), 0;
    0, 0, 1];
Ry = [cos(thetat), 0, sin(thetat);
    0, 1, 0;
    -sin(thetat), 0, cos(thetat)];
Rx = [1, 0, 0;
    0, cos(phit), -sin(phit);
    0, sin(phit), cos(phit)];

% Rotation matrix from body frame to inertial frame
R = Rz*Ry*Rx;



% Jacobian (relates body frame to inertial frame velocities)
I = [Ixx, 0, 0; 0, Iyy, 0; 0, 0, Izz];
J = W.'*I*W;

% Coriolis forces
dJ_dt = diff(J);
dJ_dt = subs(dJ_dt,[state_diff statet],[state_dot state]);
h_dot_J = [phidott(t), thetadott(t), psidott(t)]*J;
h_dot_J = subs(h_dot_J,[state_diff statet],[state_dot state]);
grad_temp_h = jacobian(h_dot_J,[phi theta psi]);
C = dJ_dt - 1/2*grad_temp_h;

% Torques in the direction of phi, theta, psi
tau_beta = [allocator(4);allocator(5);allocator(6)]/m;

% Total thrust
%T = k*(u5+u6+u7+u8);

% Dynamics
f(1) = xdott;
f(2) = ydott;
f(3) = zdott;
f(4) = phidott;
f(5) = thetadott;
f(6) = psidott;
tt=((9.81*48.1)-B)*(-1/48.1);
% Equations for COM configuration
f(7:9) = ((g*m)-B)*[0;0;-1/m] +...Ixx Iyy Izz k l m b g]
    R*[allocator(1);allocator(2);allocator(3)]/m;

% Euler Lagrange equations for angular dynamics
f(10:12) = inv(J)*(tau_beta - C*[phidott(t); thetadott(t); psidott(t)]);

% Replace parameters and drop time dependence
f = subs(f, [Ixx Iyy Izz k l m b g], paramValues);
f = subs(f,statet,state);
f = simplify(f);

% Calculate linearization
A = jacobian(f,[state{:}]);

B = jacobian(f,control);

% Create QuadrotorStateFcn.m
matlabFunction(transpose(f),'File','QuadrotorStateFcn',...
    'Vars',{transpose([state{:}]),transpose(control)})
% Create QuadrotorStateJacobianFcn.m 
matlabFunction(A, B,'File','QuadrotorStateJacobianFcn',...
    'Vars',{transpose([state{:}]),transpose(control)})

%Clear symbolic variables
%clear

function T = ThrustersMapping(C)
            % Calcule la matrice de componsates des thruster sur les 6DDL.
            % Arguments : d14, Matrice Distance x y z  des trusters 1 - 4.
            %             a14, Angles des trusters 1 - 4.
            %             d58, Matrice distance x y z des trusters 5 - 8.
            %             z,   Position des truster sur le frame.
            %             dz,  Distance entre les postions du frame.
         
             % concactener les variables pour avour une matrice lisible.
             a14 =C.a14;
             d14 =C.d14; %dist centre geo - centre masse
             d58=C.d58;  %dist centre geo - centre masse
             cm=C.RG;
             
             z=C.z;
             dz =C.dz;
             % Thruster effort Mapping Matrix (L)
            %       x         y      z      
           l1 = [ sin(a14),-cos(a14), 0,... fxyz
                (d14(3)-cm(3)+z(1)*dz)*cos(a14),... rx
                (d14(3)-cm(3)+z(1)*dz)*sin(a14),... ry
                -hypot( d14(1)-cm(1), d14(2)-cm(2))]; %rz
             
           l2 = [ sin(a14), cos(a14), 0,...fxyz
                 -(d14(3)-cm(3)+z(2)*dz)*cos(a14),...rx
                 (d14(3)-cm(3)+z(2)*dz)*sin(a14),...ry
                 -hypot( d14(1)+cm(1), d14(2)-cm(2))];%rz
             
           l3 = [ sin(a14),-cos(a14), 0,...fxyz
                (d14(3)-cm(3)+z(3)*dz)*cos(a14),...rx
                 (d14(3)-cm(3)+z(3)*dz)*sin(a14),...ry
                 hypot(d14(1)+cm(1), d14(2)+cm(2))];%rz
             
           l4 = [ sin(a14), cos(a14), 0,...fxyz
                -(d14(3)-cm(3)+z(4)*dz)*cos(a14),...rx
                 (d14(3)-cm(3)+z(4)*dz)*sin(a14),...ry
                 hypot(d14(1)-cm(1), d14(2)+cm(2))];%rz
             
            l5 = [0, 0, 1, (d58(2)-cm(2)+z(1)*dz),...
                 -(d58(1)-cm(1)+z(1)*dz), 0];
             
            l6 = [0, 0,-1,-(d58(2)-cm(2)+z(2)*dz),...
                  -(d58(1)+cm(1)+z(2)*dz), 0];
              
            l7 = [0, 0, 1,-(d58(2)+cm(2)+z(3)*dz),...
                (d58(1)+cm(1)+z(3)*dz), 0];
            
            l8 = [0, 0,-1, (d58(2)+cm(2)+z(4)*dz),...
                 (d58(1)-cm(1)+z(2)*dz), 0];

            T = [l1.', l2.', l3.', l4.', l5.' l6.', l7.', l8.'];
end
