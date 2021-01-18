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
        waypointPub;
        thrusterForcesPub;
        thrusterRpmsPub;
        thrusterCurrentsPub;
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
            this.setForcesSub = rossubscriber('/proc_control_matlab/set_forces', ...
                                              'proc_control_matlab/SetForces', ...
                                              @this.setForcesCallback);
            
            % Publications
            this.waypointPub = rospublisher('/proc_control_matlab/waypoint', ...
                                            'proc_control_matlab/Waypoint');
            % this.thrusterForcesPub = rospublisher('/proc_control_matlab/thruster_forces', ...
            %                                       'proc_control_matlab/thrusterForces');
            % this.thrusterRpmsPub = rospublisher('/proc_control_matlab/thruster_rpms', ...
            %                                     'proc_control_matlab/thrusterRpms');
            % this.thrusterCurrentsPub = rospublisher('/proc_control_matlab/thruster_currents', ...
            %                                         'proc_control_matlab/thrusterCurrents');
            
            % Services serveurs
            this.setModeSrv = rossvcserver('/proc_control_matlab/set_mode', ...
                                           'proc_control_matlab/SetMode', ...
                                           @this.setModeCallback);
            this.addPoseSrv = rossvcserver('/proc_control_matlab/add_pose', ...
                                           'proc_control_matlab/AddPose', ...
                                           @this.addPoseCallback);
            this.computeTrajectorySrv = rossvcserver('/proc_control_matlab/compute_trajectory', ...
                                                     'proc_control_matlab/ComputeTrajectory', ...
                                                     @this.computeTrajectoryCallback);
            this.clearWaypointsSrv = rossvcserver('/proc_control_matlab/clear_waypoints', ...
                                                  'proc_control_matlab/ClearWaypoints', ...
                                                  @this.clearWaypointsCallback);
            
            % Services clients
            
        end
        
        function publishWaypoint(this, wpt)
            msg = rosmessage(this.waypointPub);
            msg.X = wpt.x;
            msg.Y = wpt.y;
            msg.Z = wpt.z;
            msg.Roll = wpt.roll;
            msg.Pitch = wpt.pitch;
            msg.Yaw = wpt.yaw;
            msg.Frame = wpt.frame;
            msg.ZoneData = wpt.zoneData;
            send(this.waypointPub, msg);
        end
        
        function spinOnce(this)
            disp("Turn around");
            wpt = Waypoint(0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1, 1);
            this.publishWaypoint(wpt);
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
