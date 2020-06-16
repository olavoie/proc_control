

classdef ProcControlNode
    %ProcControlNode class
%==========================================================================
%Proprietes
%==========================================================================    
    properties
        controlMode;
        setForcesServer;
    end
%==========================================================================
%Methodes
%==========================================================================    
    methods
        function this = ProcControlNode()
            this.controlMode = PositionMode();
            this.setForcesServer = rossvcserver('/proc_control_matlab/set_forces', 'proc_control_matlab/SetForces', @setForcesCallback);
        end
        
        function spinOnce(this)
            disp("Ok");
            this.controlMode.process();
        end
    end
    
    methods(Access=private)
        function response = setForcesCallback(src, req, defaultRespMsg)
            disp('Service called');
        end
    end
end

