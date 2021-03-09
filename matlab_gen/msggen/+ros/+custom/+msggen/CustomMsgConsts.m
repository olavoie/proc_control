classdef CustomMsgConsts
    %CustomMsgConsts This class stores all message types
    %   The message types are constant properties, which in turn resolve
    %   to the strings of the actual types.
    
    %   Copyright 2014-2021 The MathWorks, Inc.
    
    properties (Constant)
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
                msgList = cell(10, 1);
                msgList{1} = 'proc_control_matlab/AddPose';
                msgList{2} = 'proc_control_matlab/ClearWaypoints';
                msgList{3} = 'proc_control_matlab/ComputeTrajectory';
                msgList{4} = 'proc_control_matlab/Pose';
                msgList{5} = 'proc_control_matlab/SetForces';
                msgList{6} = 'proc_control_matlab/SetModeRequest';
                msgList{7} = 'proc_control_matlab/SetModeResponse';
                msgList{8} = 'proc_control_matlab/ThrusterCurrents';
                msgList{9} = 'proc_control_matlab/ThrusterForces';
                msgList{10} = 'proc_control_matlab/ThrusterRpms';
            end
            
            messageList = msgList;
        end
        
        function serviceList = getServiceList
            %getServiceList Generate a cell array with all service types.
            %   The list will be sorted alphabetically.
            
            persistent svcList
            if isempty(svcList)
                svcList = cell(1, 1);
                svcList{1} = 'proc_control_matlab/SetMode';
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
