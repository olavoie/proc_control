classdef CustomMsgConsts
    %CustomMsgConsts This class stores all message types
    %   The message types are constant properties, which in turn resolve
    %   to the strings of the actual types.
    
    %   Copyright 2014-2021 The MathWorks, Inc.
    
    properties (Constant)
        proc_control_ClearWaypoint = 'proc_control/ClearWaypoint'
        proc_control_ClearWaypointRequest = 'proc_control/ClearWaypointRequest'
        proc_control_ClearWaypointResponse = 'proc_control/ClearWaypointResponse'
        proc_control_EnableControl = 'proc_control/EnableControl'
        proc_control_EnableControlRequest = 'proc_control/EnableControlRequest'
        proc_control_EnableControlResponse = 'proc_control/EnableControlResponse'
        proc_control_EnableThrusters = 'proc_control/EnableThrusters'
        proc_control_EnableThrustersRequest = 'proc_control/EnableThrustersRequest'
        proc_control_EnableThrustersResponse = 'proc_control/EnableThrustersResponse'
        proc_control_GetPositionTarget = 'proc_control/GetPositionTarget'
        proc_control_GetPositionTargetRequest = 'proc_control/GetPositionTargetRequest'
        proc_control_GetPositionTargetResponse = 'proc_control/GetPositionTargetResponse'
        proc_control_PositionTarget = 'proc_control/PositionTarget'
        proc_control_ResetBoundingBox = 'proc_control/ResetBoundingBox'
        proc_control_ResetBoundingBoxRequest = 'proc_control/ResetBoundingBoxRequest'
        proc_control_ResetBoundingBoxResponse = 'proc_control/ResetBoundingBoxResponse'
        proc_control_SetBoundingBox = 'proc_control/SetBoundingBox'
        proc_control_SetBoundingBoxRequest = 'proc_control/SetBoundingBoxRequest'
        proc_control_SetBoundingBoxResponse = 'proc_control/SetBoundingBoxResponse'
        proc_control_SetControlMode = 'proc_control/SetControlMode'
        proc_control_SetControlModeRequest = 'proc_control/SetControlModeRequest'
        proc_control_SetControlModeResponse = 'proc_control/SetControlModeResponse'
        proc_control_SetDecoupledTarget = 'proc_control/SetDecoupledTarget'
        proc_control_SetDecoupledTargetRequest = 'proc_control/SetDecoupledTargetRequest'
        proc_control_SetDecoupledTargetResponse = 'proc_control/SetDecoupledTargetResponse'
        proc_control_SetPositionTarget = 'proc_control/SetPositionTarget'
        proc_control_SetPositionTargetRequest = 'proc_control/SetPositionTargetRequest'
        proc_control_SetPositionTargetResponse = 'proc_control/SetPositionTargetResponse'
        proc_control_TargetReached = 'proc_control/TargetReached'
        proc_control_ThrustLogging = 'proc_control/ThrustLogging'
        proc_control_matlab_AddPose = 'proc_control_matlab/AddPose'
        proc_control_matlab_ClearWaypoints = 'proc_control_matlab/ClearWaypoints'
        proc_control_matlab_ComputeTrajectory = 'proc_control_matlab/ComputeTrajectory'
        proc_control_matlab_Pose = 'proc_control_matlab/Pose'
        proc_control_matlab_SetForces = 'proc_control_matlab/SetForces'
        proc_control_matlab_SetMode = 'proc_control_matlab/SetMode'
        proc_control_matlab_SetModeRequest = 'proc_control_matlab/SetModeRequest'
        proc_control_matlab_SetModeResponse = 'proc_control_matlab/SetModeResponse'
        proc_control_matlab_ThrusterCurrents = 'proc_control_matlab/ThrusterCurrents'
        proc_control_matlab_ThrusterForces = 'proc_control_matlab/ThrusterForces'
        proc_control_matlab_ThrusterRpms = 'proc_control_matlab/ThrusterRpms'
    end
    
    methods (Static, Hidden)
        function messageList = getMessageList
            %getMessageList Generate a cell array with all message types.
            %   The list will be sorted alphabetically.
            
            persistent msgList
            if isempty(msgList)
                msgList = cell(31, 1);
                msgList{1} = 'proc_control/ClearWaypointRequest';
                msgList{2} = 'proc_control/ClearWaypointResponse';
                msgList{3} = 'proc_control/EnableControlRequest';
                msgList{4} = 'proc_control/EnableControlResponse';
                msgList{5} = 'proc_control/EnableThrustersRequest';
                msgList{6} = 'proc_control/EnableThrustersResponse';
                msgList{7} = 'proc_control/GetPositionTargetRequest';
                msgList{8} = 'proc_control/GetPositionTargetResponse';
                msgList{9} = 'proc_control/PositionTarget';
                msgList{10} = 'proc_control/ResetBoundingBoxRequest';
                msgList{11} = 'proc_control/ResetBoundingBoxResponse';
                msgList{12} = 'proc_control/SetBoundingBoxRequest';
                msgList{13} = 'proc_control/SetBoundingBoxResponse';
                msgList{14} = 'proc_control/SetControlModeRequest';
                msgList{15} = 'proc_control/SetControlModeResponse';
                msgList{16} = 'proc_control/SetDecoupledTargetRequest';
                msgList{17} = 'proc_control/SetDecoupledTargetResponse';
                msgList{18} = 'proc_control/SetPositionTargetRequest';
                msgList{19} = 'proc_control/SetPositionTargetResponse';
                msgList{20} = 'proc_control/TargetReached';
                msgList{21} = 'proc_control/ThrustLogging';
                msgList{22} = 'proc_control_matlab/AddPose';
                msgList{23} = 'proc_control_matlab/ClearWaypoints';
                msgList{24} = 'proc_control_matlab/ComputeTrajectory';
                msgList{25} = 'proc_control_matlab/Pose';
                msgList{26} = 'proc_control_matlab/SetForces';
                msgList{27} = 'proc_control_matlab/SetModeRequest';
                msgList{28} = 'proc_control_matlab/SetModeResponse';
                msgList{29} = 'proc_control_matlab/ThrusterCurrents';
                msgList{30} = 'proc_control_matlab/ThrusterForces';
                msgList{31} = 'proc_control_matlab/ThrusterRpms';
            end
            
            messageList = msgList;
        end
        
        function serviceList = getServiceList
            %getServiceList Generate a cell array with all service types.
            %   The list will be sorted alphabetically.
            
            persistent svcList
            if isempty(svcList)
                svcList = cell(10, 1);
                svcList{1} = 'proc_control/ClearWaypoint';
                svcList{2} = 'proc_control/EnableControl';
                svcList{3} = 'proc_control/EnableThrusters';
                svcList{4} = 'proc_control/GetPositionTarget';
                svcList{5} = 'proc_control/ResetBoundingBox';
                svcList{6} = 'proc_control/SetBoundingBox';
                svcList{7} = 'proc_control/SetControlMode';
                svcList{8} = 'proc_control/SetDecoupledTarget';
                svcList{9} = 'proc_control/SetPositionTarget';
                svcList{10} = 'proc_control_matlab/SetMode';
            end
            
            % The message list was already sorted, so don't need to sort
            % again.
            serviceList = svcList;
        end
        
        function actionList = getActionList
            %getActionList Generate a cell array with all action types.
            %   The list will be sorted alphabetically.
            
            persistent actList
            if isempty(actList)
                actList = cell(0, 1);
            end
            
            % The message list was already sorted, so don't need to sort
            % again.
            actionList = actList;
        end
    end
end
