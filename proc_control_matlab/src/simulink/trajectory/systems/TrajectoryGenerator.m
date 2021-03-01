classdef TrajectoryGenerator < matlab.System
    % untitled Add summary here
    %
    % This template includes the minimum set of functions required
    % to define a System object with discrete state.

    % Public, tunable properties
    properties

    end

    properties(DiscreteState)
    i;
    end

    % Pre-computed constants
    properties(Access = private)

    end

    methods(Access = protected)
        function setupImpl(this,wpts)
            % Perform one-time calculations, such as computing constants
            this.i=0;
        end

        function [pose, new] = stepImpl(this,wpts)
            % Implement algorithm. Calculate y as a function of input u and
            % discrete states.
            wpts=zeros(14,6);
            wpts(1,:)= [0 0 0 0 0 0];
            wpts(2,:)= [0 0 1.5 0 0 0];
            wpts(3,:)= [.5 0 2 0 0 0];
            wpts(4,:)= [8.072 0 2 0 0 0];
            wpts(5,:)= [11.921 -1.364 1.696 -deg2rad(39.23) 0 0];%39.23
            wpts(6,:)= [13 -1.75 1.5 deg2rad(0) 0 0];
            wpts(7,:)= [14.217 -1.237 1.278 deg2rad(45) 0 0];
            wpts(8,:)= [14.721 0 1.186 deg2rad(90) 0 0];
            wpts(9,:)= [14.217 1.237 1.278 deg2rad(135) 0 0];
            wpts(10,:)= [13 1.75 1.5 deg2rad(180) 0 0];
            wpts(11,:)= [11.921 1.364 1.696  deg2rad(180+39.23) 0 0];%180+39.23
            wpts(12,:)= [8.072 0 2 deg2rad(180) 0 0];
            wpts(13,:)= [.5 0 2 deg2rad(180) 0 0];
            wpts(14,:)=[0 0 2 deg2rad(180) 0 0];
            % Initialiser les tableaux
            linwpts= zeros(3,size(wpts,1)).';
            eulwpts= zeros(3,size(wpts,1)).';
            quatwpts= zeros(4,size(wpts,1)).';

            linwpts=wpts(:,1:3);
            % Convertire les angle d'euler en quaternions
            eulwpts=wpts(:,4:6);
            quatwpts=quaternion(eulwpts,'eulerd','frame');

            %tpts = [0,15,20,40,50,55,63,70,78,85,90,100,120,140,230];

            % Génération d'un vecteur de temps
            tpts = zeros(1,size(wpts,1));

            for i = 2: size(tpts, 2)  
                dist = norm(wpts(i,1:3) - wpts(i-1,1:3))
                temp = dist / avancePrecision + 2 * (avancePrecision / accRapide);
                tpts(i) = temp + tpts(i-1);
            end
            tvec = 0:Ts:tpts(end);
            %tpts = [0,20,40,60,80,95,120,130,150,175,200,230,250,275,300];

            disp(tpts);
            tic;
            trajectory = waypointTrajectory(linwpts,tpts,'SampleRate', 1/Ts,'Orientation', quatwpts);
            tInfo = waypointInfo(trajectory);

            pose = zeros(7,size(tvec,2));
            quat = zeros([1, size(tvec,2), 1], 'quaternion');
            count=1;
            while ~isDone(trajectory)
               [pose(1:3,count), quat(count)] = trajectory();
                count = count+1;
            end
            pose(4:7,:) = compact(quat).';
            this.i = this.i + 1;
            new = this.i;
        end

        function resetImpl(obj)
            % Initialize / reset discrete-state properties
        end
    end
end
