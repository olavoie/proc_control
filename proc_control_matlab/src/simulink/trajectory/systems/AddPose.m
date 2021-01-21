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
        
        function setupImpl(this, clearBuffer, isNew, waypoint)
            % Perform one-time calculations, such as computing constants   
            this.i = 1;
            this.poseList = repmat(999, 6, this.buffSize);
        end

        function [waypoints, count] = stepImpl(this, clearBuffer, isNew, waypoint)
            % Suppression du buffer.
            if clearBuffer == 1
                this.poseList = repmat(999, 6, this.buffSize);
                this.i = 1;
            end
            % Ajout d'un waypoint provenant de ROS.
            if isNew == 1
                if this.i < this.buffSize
                    this.poseList(:,this.i) = waypoint.';
                    this.i = this.i + 1;
                end
            end   
            
            count = this.i - 1;
            waypoints = this.poseList;
        end

        function resetImpl(this)
            % Initialize / reset discrete-state properties
        end
    end
end
