classdef AddPose < matlab.System
    % untitled Add summary here
    %
    % This template includes the minimum set of functions required
    % to define a System object with discrete state.

    % Public, tunable properties
    properties (Nontunable)
        buffSize = 21;
    end

    properties(DiscreteState)
        i;
        poseList;
    end

    % Pre-computed constants
    properties(Access = private)

    end

    methods(Access = protected)
%% Fonction appeler a l'initialisation
        function setupImpl(this, compute, clearBuffer, isNew, waypoint,initCond)
            % Perform one-time calculations, such as computing constants   
           
            this.poseList = repmat(999, this.buffSize, 7);
            this.poseList(1,:)=[0,0,0,1,0,0,0];%initCond(1,1:7);
            this.i = 2;
        end
%% Main appeller à chaque exécution
        function [waypoints, count] = stepImpl(this, compute, clearBuffer, isNew, waypoint,initCond)
            % Suppression du buffer.
            this.CheckEvent(compute, clearBuffer, isNew,waypoint);
            
            count = this.i;
            waypoints = this.poseList;
        end
%% Fonction qui interprete les message ROS
        
        function CheckEvent(this,compute, clearBuffer, isNew,waypoint )
        
        if   compute == 1
            this.poseList(1,:)= this.poseList(this.i-1,:);
            this.poseList(2:end,:) = repmat(999, this.buffSize-1, 7);
            this.i = 2;
        end
            
        if clearBuffer == 1

                this.poseList(2:end,:) = repmat(999, this.buffSize-1, 7);
                this.i = 1;
                
        end
            % Ajout d'un waypoint provenant de ROS.
        if isNew == 1
           if this.i < this.buffSize
                    
                    this.poseList(this.i,:) = this.processWpt(waypoint.').';
                    this.i = this.i + 1;
           end
        end   
            
           
        end
%% Fonction qui interprete les waypoints reçu par ROS
        function pwpt = processWpt(this, wpt)
            % Determiner le quaternion en fonction des angles d'euler.
            % Orde de rotation : ZYX.
            % Reel
            q = zeros(1, 4);
            wpt(4:6) = deg2rad(wpt(4:6));
             q(1) = cos(wpt(6)/2) * cos(wpt(5)/2) * cos(wpt(4)/2)...
                  + sin(wpt(6)/2) * sin(wpt(5)/2) * sin(wpt(4)/2);

            % imaginaire i
             q(2) = sin(wpt(6)/2) * cos(wpt(5)/2) * cos(wpt(4)/2)...
                  - cos(wpt(6)/2) * sin(wpt(5)/2) * sin(wpt(4)/2);

            % imaginaire j
             q(3) = cos(wpt(6)/2) * sin(wpt(5)/2) * cos(wpt(4)/2)...
                  + sin(wpt(6)/2) * cos(wpt(5)/2) * sin(wpt(4)/2);

            % imaginaire k
             q(4) = cos(wpt(6)/2) * cos(wpt(5)/2) * sin(wpt(4)/2)...
                  - sin(wpt(6)/2) * sin(wpt(5)/2) * cos(wpt(4)/2);
              
             pwpt = [wpt(1:3) q];
        end
      
        
       
        
        %%
        function resetImpl(this)
            % Initialize / reset discrete-state properties
        end
    end
end
