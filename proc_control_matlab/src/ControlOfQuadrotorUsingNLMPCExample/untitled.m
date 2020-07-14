clc;clear;
getQuadrotorDynamicsAndJacobian;
nx = 12;
ny = 12;
nu = 4;
nlobj = nlmpc(nx, ny, nu);
nlobj.Model.StateFcn = "QuadrotorStateFcn";
nlobj.Jacobian.StateFcn = @QuadrotorStateJacobianFcn;
rng(0)
validateFcns(nlobj,rand(nx,1),rand(nu,1));


%op=optimoptions('StepTolerance',0.001,'MaxIterations',50);
%nlobj.Optimization.SolverOptions =op;
nlobj.Optimization.UseSuboptimalSolution =true;
nlobj.Optimization.SolverOptions.MaxIter=70;

Ts = 0.1;
p = 18;
m = 2;
nlobj.Ts = Ts;
nlobj.PredictionHorizon = p;
nlobj.ControlHorizon = m;
nlobj.MV = struct('Min',{0;0;0;0},'Max',{12;12;12;12});
nlobj.Weights.OutputVariables = [1 1 1 1 1 1 0 0 0 0 0 0];
nlobj.Weights.ManipulatedVariables = [0.5 0.5 0.5 0.5];
nlobj.Weights.ManipulatedVariablesRate = [.3 .3 .3 .3];
% Specify the initial conditions
x = [3;-3;0;0;0;0;0;0;0;0;0;0];
% Nominal control that keeps the quadrotor floating
nloptions = nlmpcmoveopt;
nloptions.MVTarget = [4.9 4.9 4.9 4.9]; 
mv = nloptions.MVTarget;
Duration = 20;
hbar = waitbar(0,'Simulation Progress');
xHistory = x';
lastMV = mv;
uHistory = lastMV;
for k = 1:(Duration/Ts)
    % Set references for previewing
    t = linspace(k*Ts, (k+p-1)*Ts,p);
    yref = QuadrotorReferenceTrajectory(t);
    % Compute the control moves with reference previewing.
    xk = xHistory(k,:);
    [uk,nloptions,info] = nlmpcmove(nlobj,xk,lastMV,yref',[],nloptions);
    uHistory(k+1,:) = uk';
    lastMV = uk;
    % Update states.
    ODEFUN = @(t,xk) QuadrotorStateFcn(xk,uk);
    [TOUT,YOUT] = ode45(ODEFUN,[0 Ts], xHistory(k,:)');
    xHistory(k+1,:) = YOUT(end,:);
    waitbar(k*Ts/Duration,hbar);
end
close(hbar)