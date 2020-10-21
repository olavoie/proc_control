%% create MPC controller object with sample time
mpc2 = mpc(plant, 0.1);
%% specify prediction horizon
mpc2.PredictionHorizon = 10;
%% specify control horizon
mpc2.ControlHorizon = 2;
%% specify nominal values for inputs and outputs
mpc2.Model.Nominal.U = [0;0;0;0;0;0;0;0];
mpc2.Model.Nominal.Y = [0.01;0.01;0.01;0.001;0.001;0.001;0.00999100100549467;0.0100089910040025;0.000999998995000335;0.001;0.001;0.001];
%% specify weights
mpc2.Weights.MV = [0.1 0.1 0.1 0.1 0.1 0.1 0.1 0.2];
mpc2.Weights.MVRate = [0.1 0.1 0.1 0.1 0.1 0.1 0.1 0.1];
mpc2.Weights.OV = [1 1 1 3 3 1 1 1 0 0 0 0];
mpc2.Weights.ECR = 100000;
%% specify simulation options
options = mpcsimopt();
options.RefLookAhead = 'off';
options.MDLookAhead = 'off';
options.Constraints = 'on';
options.OpenLoop = 'off';
%% run simulation
%sim(mpc2, 101, mpc2_RefSignal, mpc2_MDSignal, options);
