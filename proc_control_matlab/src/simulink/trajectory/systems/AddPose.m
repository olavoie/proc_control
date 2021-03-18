classdef AddPose < matlab.System
    % untitled Add summary here
    %
    % This template includes the minimum set of functions required
    % to define a System object with discrete state.

    % Public, tunable properties
    properties (Nontunable)
        buffSize = 21;
        elementSize=8;
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
        function setupImpl(this, compute, clearBuffer, isNew, waypoint,initCond, reset)
            % Perform one-time calculations, such as computing constants   
           
            this.poseList = repmat(999, this.buffSize, this.elementSize);
            this.poseList(1,:)=[0,0,0,1,0,0,0,0];%initCond(1,1:7);
            this.i = 2;
        end
%% Main appeller à chaque exécution
        function [waypoints, count] = stepImpl(this, compute, clearBuffer, isNew, waypoint,initCond, reset)
            % Suppression du buffer.
            this.CheckEvent(compute, clearBuffer, isNew,waypoint, initCond, reset);
            
            count = this.i;
            waypoints = this.poseList;
        end
%% Fonction qui interprete les message ROS
        
        function CheckEvent(this,compute, clearBuffer, isNew,waypoint,initCond, reset )
        
            if   compute == 1
                this.poseList(1,:)= this.poseList(this.i-1,:);
                this.poseList(2:end,:) = repmat(999, this.buffSize-1, this.elementSize);
                this.i = 2;
            end
            
            if clearBuffer == 1

                    this.poseList(2:end,:) = repmat(999, this.buffSize-1, this.elementSize);
                    this.i = 1;

            end
            % Ajout d'un waypoint provenant de ROS.
            if isNew == 1
               if this.i < this.buffSize

                        this.poseList(this.i,:) = this.processWpt(waypoint.').';
                        this.i = this.i + 1;
               end
            end   
        
            if reset == 1
                this.poseList(2:end,:) = repmat(999, this.buffSize-1, this.elementSize);
                this.poseList(1,:) = [initCond,0];
                this.i = 1;
            end
        end
%% Fonction qui interprete les waypoints reçu par ROS
        function pwpt = processWpt(this, wpt)
            % Determiner le quaternion en fonction des angles d'euler.
            % Orde de rotation : ZYX.
            % Reel
            q = zeros(1, 4);
            q = eul2quat(deg2rad(wpt(4:6)),'ZYX');    
            
            pwpt = [wpt(1:3) q,wpt(8)];
        end
      
        
       
        
        %%
        function resetImpl(this)
            % Initialize / reset discrete-state properties
        end
    end
end
