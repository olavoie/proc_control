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
        
        Ts=.25;
    end
    
    % Public, tunable properties
    properties(Nontunable)
     bufferSize=1000; % Taille statique 
    end

    properties(DiscreteState)
        computeCount;
    end

    % Pre-computed constants
    properties(Access = private)

    end

    methods(Access = protected)
        function setupImpl(this,wpts)
            % Perform one-time calculations, such as computing constants
            this.computeCount=0;
        end

        function [pose, new] = stepImpl(this, wpts, wpt_count)
            % Implement algorithm. Calculate y as a function of input u and
            % discrete states.
        
            % Initialiser les tableau
            linwpts = wpts(:,1:3);% wpts(1:wpt_count-1,1:3);
            
            
            qwpts = zeros(size(wpts, 1), 4);
            
           
            for k = 1:size(wpts, 1)
                %linwpts(k, 1:3) = wpts(k,1:3);
                qwpts(k, 1:4) = wpts(k,4:7);
            end
            
            for i=wpt_count-1:size(wpts, 1)
                linwpts(i,:) = linwpts(wpt_count-1,:);
                qwpts(i,:) = qwpts(wpt_count-1,:);
            end
            quatwpts = quaternion(qwpts);
            
           

            % Gestion des vitesses et des accélérations.
            
            
            % Génération d'un vecteur de temps
            tpts = zeros(size(wpts, 1),1);
            
            for i = 2: wpt_count-1
                dist = norm(wpts(i,1:3) - wpts(i-1,1:3));
                temp = dist / this.avancePrecision + 2 * (this.avancePrecision / this.accRapide);
                tpts(i) = temp + tpts(i-1);
            end
            
            for i=wpt_count : size(tpts,1)
                tpts(i)=tpts(i-1)+.01 ;
            end
                
                
            %tpts = [0,20,40,60,80,95,120,130,150,175,200,230,250,275,300];
         
          
%             linwpts
%             tpts
%             quatwpts
            
            final=tpts(wpt_count-1);
            
            nbPoint=floor(final/this.Ts);
            
            trajectory = waypointTrajectory(linwpts, tpts,'SampleRate', 1/this.Ts,'SamplesPerFrame',1, 'Orientation', quatwpts);
            pose=repmat(999,this.bufferSize, 13);
            
%              bufferPose = zeros(1, 3);
%              bufferQuat = quaternion([0,0,0,0]);
%              bufferVelocity = zeros(1, 3);
%              bufferAcc = zeros(1, 3);
%              bufferAngRate = zeros(1, 3);
            
           % while ~isDone(trajectory)
           nbpts=1;
           for i=1 : nbPoint
                    
                   [bufferPose, bufferQuat, bufferVelocity , acc ,bufferAngRate] = trajectory();%, bufferVelocity, bufferAcc, bufferAngRate
                    pose(i, 1:3) = bufferPose;
                    pose(i, 4:7) = compact(bufferQuat);
                    pose(i, 8:10) = bufferVelocity;
                    pose(i, 11:13) = bufferAngRate;
                    nbpts=i;
                  
            end
            this.computeCount = this.computeCount + 1;
            new = [this.computeCount,  nbpts];
           
        end
        
      
        function resetImpl(obj)
            % Initialize / reset discrete-state properties
        end
    end
end
