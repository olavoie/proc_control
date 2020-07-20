clc; clear;
%getSubDynamicsAndJacobian;

nx = 12;
ny = 12;
nu = 8;
nlobj = nlmpc(nx, ny, nu);

nlobj.Model.StateFcn = "AUVStateFcn";
nlobj.Jacobian.StateFcn = @AUVStateJacobianFcn;
rng(0)
validateFcns(nlobj,rand(nx,1),rand(nu,1));

Ts = 0.1;
p = 15;
m = 2;
nlobj.Ts = Ts;
nlobj.PredictionHorizon = p;
nlobj.ControlHorizon = m;

nlobj.MV = struct('Min',{-26;-26;-26;-26;-26;-26;-26;-26},...
                  'Max',{ 32; 32; 32; 32; 32; 32; 32; 32});
 
 %nlobj.MV = struct('Min',{-40;-40;-40;-40;-40;-40;-40;-40},...
                  %'Max',{ 50; 50; 50; 50; 50; 50; 50; 50})
 
nlobj.Weights.OutputVariables = [ 20 20 15 20 20 20 0 0 0 0 0 0];
nlobj.Weights.ManipulatedVariables = [0.3 0.3 0.3 0.3 0.1 0.1 0.1 0.1];
nlobj.Weights.ManipulatedVariablesRate = [0.1 0.1 0.1 0.1 0.1 0.1 0.1 0.1];

% Specify the initial conditions
x = [0;0;0;0;0;0;0;0;0;0;0;0];
% Nominal control that keeps the quadrotor floating
 nloptions = nlmpcmoveopt;
 nloptions.MVTarget = [0 0 0 0 0 0 0 0]; 
 mv = nloptions.MVTarget;


Duration = 20;
hbar = waitbar(0,'Simulation Progress');
xHistory = x';
lastMV =[0 0 0 0 0 0 0 0]; % mv;
uHistory = lastMV;
for k = 1:(Duration/Ts)
    tic;
    % Set references for previewing
    t = linspace(k*Ts, (k+p-1)*Ts,p);
    yref = QuadrotorReferenceTrajectory(t);
    % Compute the control moves with reference previewing.
    xk = xHistory(k,:);
    [uk,nloptions,info] = nlmpcmove(nlobj,xk,lastMV,yref',[],nloptions);
    uHistory(k+1,:) = uk';
    lastMV = uk;
    toc;
    % Update states.
    ODEFUN = @(t,xk) AUVStateFcn(xk,uk);
    [TOUT,YOUT] = ode45(ODEFUN,[0 Ts], xHistory(k,:)');
    xHistory(k+1,:) = YOUT(end,:);
    waitbar(k*Ts/Duration,hbar);
  
    
end
close(hbar)
