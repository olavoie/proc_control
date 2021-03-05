classdef TrajectoryGenerator < matlab.System
    % untitled Add summary here
    %
    % This template includes the minimum set of functions required
    % to define a System object with discrete state.

    % Public, tunable properties
    properties
        avanceRapide = 1; % Vitesse Rapide
        avancePrecision = 0.5; % Vtesse Precision

        accRapide = 0.3; % acceleration Rapide
        accPrecision = 0.1; % acceleration Precision
        
        Ts;
    end
    
    % Public, tunable properties
    properties(Nontunable)
     bufferSize=6001; % Taille statique 
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

        function [pose, new] = stepImpl(this, wpts, wpt_count)
            % Implement algorithm. Calculate y as a function of input u and
            % discrete states.
%             wpts=zeros(14,7);
%             wpts(1,:)= [0 0 0 1 0 0 0];
%             wpts(2,:)= [0 0 1.5 1 0 0 0];
%             wpts(3,:)= [.5 0 2 1 0 0 0];
%             wpts(4,:)= [8.072 0 2 1 0 0 0];
%             wpts(5,:)= [11.921 -1.364 1.696 1 0 0 0];%39.23
%             wpts(6,:)= [13 -1.75 1.5 1 0 0 0];
%             wpts(7,:)= [14.217 -1.237 1.278 1 0 0 0];
%             wpts(8,:)= [14.721 0 1.186 1 0 0 0];
%             wpts(9,:)= [14.217 1.237 1.278 1 0 0 0];
%             wpts(10,:)= [13 1.75 1.5 1 0 0 0];
%             wpts(11,:)= [11.921 1.364 1.696  1 0 0 0];%180+39.23
%             wpts(12,:)= [8.072 0 2 1 0 0 0];
%             wpts(13,:)= [.5 0 2 1 0 0 0];
%             wpts(14,:)=[0 0 2 1 0 0 0];
            
            % Initialiser les tableau
            linwpts = zeros(wpt_count, 3);
            qwpts = zeros(size(wpts, 1), 4);
            %for k = 1:wpt_count
            for k = 1:wpt_count
                linwpts(k, 1:3) = wpts(k,1:3);
                qwpts(k, 1:4) = wpts(k,4:7);
            end
            quatwpts = quaternion(qwpts);
            
            %tpts = [0,15,20,40,50,55,63,70,78,85,90,100,120,140,230];

            % Gestion des vitesses et des accélérations.
            
            
            % Génération d'un vecteur de temps
            tpts = zeros(14,1);
            
            for i = 2: size(tpts, 1)  
                dist = norm(wpts(i,1:3) - wpts(i-1,1:3))
                temp = dist / this.avancePrecision + 2 * (this.avancePrecision / this.accRapide);
                tpts(i) = temp + tpts(i-1);
            end
            %tpts = [0,20,40,60,80,95,120,130,150,175,200,230,250,275,300];
            tic;
            trajectory = waypointTrajectory(linwpts, tpts,'SampleRate', 4, 'Orientation', quatwpts(1:wpt_count,:));
            pose=repmat(999,this.bufferSize, 13);
%             bufferPose = zeros(1, 3);
%             bufferQuat = quaternion([0,0,0,0]);
%             bufferVelocity = zeros(1, 3);
%             bufferAcc = zeros(1, 3);
%             bufferAngRate = zeros(1, 3);
            count=1;
            while ~isDone(trajectory)
                    count = count+1;
                   [bufferPose, bufferQuat, bufferVelocity, bufferAcc, bufferAngRate] = trajectory();
                    pose(count, 1:3) = bufferPose;
                    pose(count, 4:7) = compact(bufferQuat);
                    pose(count, 8:10) = bufferVelocity;
                    pose(count, 11:13) = bufferAngRate;
            end
            this.i = this.i + 1;
            new = [this.i, count];
        end

        function resetImpl(obj)
            % Initialize / reset discrete-state properties
        end
    end
end
