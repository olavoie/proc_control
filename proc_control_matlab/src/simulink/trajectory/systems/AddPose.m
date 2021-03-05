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
            this.poseList = repmat(999, this.buffSize, 7);
        end

        function [waypoints, count] = stepImpl(this, clearBuffer, isNew, waypoint)
            % Suppression du buffer.
            if clearBuffer == 1
                this.poseList = repmat(999, this.buffSize, 7);
                this.i = 1;
            end
            % Ajout d'un waypoint provenant de ROS.
            if isNew == 1
                if this.i < this.buffSize
                    this.poseList(this.i,:) = this.processWpt(waypoint.').';
                    this.i = this.i + 1;
                end
            end   
            
            count = this.i;
            waypoints = this.poseList;
        end
        
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
        
        function resetImpl(this)
            % Initialize / reset discrete-state properties
        end
    end
end
