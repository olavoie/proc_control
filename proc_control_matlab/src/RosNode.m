classdef RosNode
% Classe RosNode 
% Cette classe fait la gestion des messages et des services ROS du Proc
% Control.
%==========================================================================
% Proprietes
%==========================================================================    
    properties
        procControl;
        setForcesSub;
        setModeSrv;
        addPoseSrv;
        computeTrajectorySrv;
        clearWaypointsSrv;
    end
%==========================================================================
% Methodes
%==========================================================================    
    methods
        % Methodes publiques
        % Constructeur 
        function this = RosNode()
            
            this.procControl = ProcControl();
            
            % Subscriptions
            this.setForcesSub = rossubscriber('/proc_control_matlab/set_forces', 'proc_control_matlab/SetForces', @this.setForcesCallback);
            
            % Publications
            
            % Services serveurs
            this.setModeSrv = rossvcserver('/proc_control_matlab/set_mode', 'proc_control_matlab/SetMode', @this.setModeCallback);
            this.addPoseSrv = rossvcserver('/proc_control_matlab/add_pose', 'proc_control_matlab/AddPose', @this.addPoseCallback);
            this.computeTrajectorySrv = rossvcserver('/proc_control_matlab/compute_trajectory', 'proc_control_matlab/ComputeTrajectory', @this.computeTrajectoryCallback);
            this.clearWaypointsSrv = rossvcserver('/proc_control_matlab/clear_waypoints', 'proc_control_matlab/ClearWaypoints', @this.clearWaypointsCallback);
            
            % Services clients
        end
        
        function spinOnce(this)
            disp("Turn around");
        end
     end
     methods(Access=private)
        % Methodes privees
        function response = setModeCallback(this, srv, reqMsg, defaultRespMsg)
            this.procControl.setMode(reqMsg.Mode);
            response = defaultRespMsg;
        end
        
        function response = addPoseCallback(this, srv, reqMsg, defaultRespMsg)
            this.procControl.addPose( reqMsg.X, ...
                                      reqMsg.Y, ...
                                      reqMsg.Z, ...
                                      reqMsg.Roll, ...
                                      reqMsg.Pitch, ...
                                      reqMsg.Yaw, ...
                                      reqMsg.Frame, ...
                                      reqMsg.ZoneData);
            response = defaultRespMsg;
        end
        
        function response = computeTrajectoryCallback(this, srv, reqMsg, defaultRespMsg)
            this.procControl.computeTrajectory();
            response = defaultRespMsg;
        end
        
        function response = clearWaypointsCallback(this, srv, reqMsg, defaultRespMsg)
            this.procControl.clearWaypoints();
            response = defaultRespMsg;
        end
        
        function setForcesCallback(this, sub, msg)
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
