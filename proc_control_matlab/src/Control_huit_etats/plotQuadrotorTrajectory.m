% This script plots the closed-loop responses of the nonlinear MPC
% controller used in the quadrotor path following example.

% Copyright 2019 The MathWorks, Inc.

% Plot the closed-loop response.
time = 0:Ts:Duration;
yreftot = QuadrotorReferenceTrajectory(time)';

% Plot the states.
figure('Name','States')

subplot(2,3,1)
hold on
plot(time,yHistory(:,1))
plot(time,yreftot(:,1))
grid on
xlabel('time')
ylabel('x')
legend('actual','reference','Location','southeast')
title('Qruadrotor x position')

subplot(2,3,2)
hold on
plot(time,yHistory(:,2))
plot(time,yreftot(:,2))
grid on
xlabel('time')
ylabel('y')
legend('actual','reference','Location','southeast')
title('Qruadrotor y position')

subplot(2,3,3)
hold on
plot(time,yHistory(:,3))
plot(time,yreftot(:,3))
grid on
xlabel('time')
ylabel('z')
legend('actual','reference','Location','southeast')
title('Qruadrotor z position')

subplot(2,3,4)
hold on
plot(time,yHistory(:,4))
plot(time,yreftot(:,4))
grid on
xlabel('time')
ylabel('phi')
legend('actual','reference','Location','southeast')
title('Qruadrotor phi angle')

subplot(2,3,5)
hold on
plot(time,yHistory(:,9))
plot(time,yreftot(:,9))
grid on
xlabel('time')
ylabel('theta')
legend('actual','reference','Location','southeast')
title('Qruadrotor theta angle')

subplot(2,3,6)
hold on
plot(time,yHistory(:,7))
plot(time,yreftot(:,7))
grid on
xlabel('time')
ylabel('psi')
legend('actual','reference','Location','southeast')
title('Qruadrotor psi angle')

% Plot the manipulated variables.
figure('Name','Control Inputs')

subplot(2,4,1)
hold on
stairs(time,uHistory(:,1))
ylim([-26,30])
plot(time,nloptions.MVTarget(2)*ones(1,length(time)))
grid on
xlabel('time')
legend('actual','reference')
title('Input 1')

subplot(2,4,2)
hold on
stairs(time,uHistory(:,2))
ylim([-26,30])
plot(time,nloptions.MVTarget(2)*ones(1,length(time)))
grid on
xlabel('time')
title('Input 2')
legend('actual','reference')

subplot(2,4,3)
hold on
stairs(time,uHistory(:,3))
ylim([-26,30])
plot(time,nloptions.MVTarget(2)*ones(1,length(time)))
grid on
xlabel('time')
title('Input 3')
legend('actual','reference')

subplot(2,4,4)
hold on
stairs(time,uHistory(:,4))
ylim([-26,30])
plot(time,nloptions.MVTarget(2)*ones(1,length(time)))
grid on
xlabel('time')
title('Input 4')
legend('actual','reference')

subplot(2,4,5)
hold on
stairs(time,uHistory(:,5))
ylim([-26,30])
plot(time,nloptions.MVTarget(2)*ones(1,length(time)))
grid on
xlabel('time')
title('Input 5')
legend('actual','reference')

subplot(2,4,6)
hold on
stairs(time,uHistory(:,6))
ylim([-26,30])
plot(time,nloptions.MVTarget(2)*ones(1,length(time)))
grid on
xlabel('time')
title('Input 6')
legend('actual','reference')

subplot(2,4,7)
hold on
stairs(time,uHistory(:,7))
ylim([-26,30])
plot(time,nloptions.MVTarget(2)*ones(1,length(time)))
grid on
xlabel('time')
title('Input 7')
legend('actual','reference')

subplot(2,4,8)
hold on
stairs(time,uHistory(:,8))
ylim([-26,30])
plot(time,nloptions.MVTarget(2)*ones(1,length(time)))
grid on
xlabel('time')
title('Input 8')
legend('actual','reference')
