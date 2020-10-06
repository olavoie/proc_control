classdef ProcControlNode
    %ProcControlNode class
%==========================================================================
%Proprietes
%==========================================================================    
    properties
        controlMode;
        setForcesSub;
    end
%==========================================================================
%Methodes
%==========================================================================    
    methods
        function this = ProcControlNode()
            this.controlMode = PositionMode();
            this.setForcesSub = rossubscriber('/proc_control_matlab/set_forces', 'proc_control_matlab/SetForces', @this.setForcesCallback);
        end
        
        function spinOnce(this)
            disp("Ok");
            this.controlMode.process();
        end
        
        function setForcesCallback(node, sub, msg)
            disp("Force input:");
            disp("X: " + msg.X);
            disp("Y: " + msg.Y);
            disp("Z: " + msg.Z);
            disp("Yaw: " + msg.Yaw);
            disp("Roll: " + msg.Roll);
            disp("Pitch: " + msg.Pitch);
        end
    end
end

