classdef ThrusterRpms < ros.Message
    %ThrusterRpms MATLAB implementation of proc_control_matlab/ThrusterRpms
    %   This class was automatically generated by
    %   ros.msg.internal.gen.MessageClassGenerator.
    
    %   Copyright 2014-2021 The MathWorks, Inc.
    
    %#ok<*INUSD>
    
    properties (Constant)
        MessageType = 'proc_control_matlab/ThrusterRpms' % The ROS message type
    end
    
    properties (Constant, Hidden)
        MD5Checksum = 'e25a893751aa46da4bc905f57bd35033' % The MD5 Checksum of the message definition
    end
    
    properties (Access = protected)
        JavaMessage % The Java message object
    end
    
    properties (Dependent)
        T1Rpm
        T2Rpm
        T3Rpm
        T4Rpm
        T5Rpm
        T6Rpm
        T7Rpm
        T8Rpm
    end
    
    properties (Constant, Hidden)
        PropertyList = {'T1Rpm', 'T2Rpm', 'T3Rpm', 'T4Rpm', 'T5Rpm', 'T6Rpm', 'T7Rpm', 'T8Rpm'} % List of non-constant message properties
        ROSPropertyList = {'T1_Rpm', 'T2_Rpm', 'T3_Rpm', 'T4_Rpm', 'T5_Rpm', 'T6_Rpm', 'T7_Rpm', 'T8_Rpm'} % List of non-constant ROS message properties
    end
    
    methods
        function obj = ThrusterRpms(msg)
            %ThrusterRpms Construct the message object ThrusterRpms
            import com.mathworks.toolbox.ros.message.MessageInfo;
            
            % Support default constructor
            if nargin == 0
                obj.JavaMessage = obj.createNewJavaMessage;
                return;
            end
            
            % Construct appropriate empty array
            if isempty(msg)
                obj = obj.empty(0,1);
                return;
            end
            
            % Make scalar construction fast
            if isscalar(msg)
                % Check for correct input class
                if ~MessageInfo.compareTypes(msg(1), obj.MessageType)
                    error(message('ros:mlros:message:NoTypeMatch', obj.MessageType, ...
                        char(MessageInfo.getType(msg(1))) ));
                end
                obj.JavaMessage = msg(1);
                return;
            end
            
            % Check that this is a vector of scalar messages. Since this
            % is an object array, use arrayfun to verify.
            if ~all(arrayfun(@isscalar, msg))
                error(message('ros:mlros:message:MessageArraySizeError'));
            end
            
            % Check that all messages in the array have the correct type
            if ~all(arrayfun(@(x) MessageInfo.compareTypes(x, obj.MessageType), msg))
                error(message('ros:mlros:message:NoTypeMatchArray', obj.MessageType));
            end
            
            % Construct array of objects if necessary
            objType = class(obj);
            for i = 1:length(msg)
                obj(i,1) = feval(objType, msg(i)); %#ok<AGROW>
            end
        end
        
        function t1rpm = get.T1Rpm(obj)
            %get.T1Rpm Get the value for property T1Rpm
            t1rpm = int32(obj.JavaMessage.getT1Rpm);
        end
        
        function set.T1Rpm(obj, t1rpm)
            %set.T1Rpm Set the value for property T1Rpm
            validateattributes(t1rpm, {'numeric'}, {'nonempty', 'scalar'}, 'ThrusterRpms', 'T1Rpm');
            
            obj.JavaMessage.setT1Rpm(t1rpm);
        end
        
        function t2rpm = get.T2Rpm(obj)
            %get.T2Rpm Get the value for property T2Rpm
            t2rpm = int32(obj.JavaMessage.getT2Rpm);
        end
        
        function set.T2Rpm(obj, t2rpm)
            %set.T2Rpm Set the value for property T2Rpm
            validateattributes(t2rpm, {'numeric'}, {'nonempty', 'scalar'}, 'ThrusterRpms', 'T2Rpm');
            
            obj.JavaMessage.setT2Rpm(t2rpm);
        end
        
        function t3rpm = get.T3Rpm(obj)
            %get.T3Rpm Get the value for property T3Rpm
            t3rpm = int32(obj.JavaMessage.getT3Rpm);
        end
        
        function set.T3Rpm(obj, t3rpm)
            %set.T3Rpm Set the value for property T3Rpm
            validateattributes(t3rpm, {'numeric'}, {'nonempty', 'scalar'}, 'ThrusterRpms', 'T3Rpm');
            
            obj.JavaMessage.setT3Rpm(t3rpm);
        end
        
        function t4rpm = get.T4Rpm(obj)
            %get.T4Rpm Get the value for property T4Rpm
            t4rpm = int32(obj.JavaMessage.getT4Rpm);
        end
        
        function set.T4Rpm(obj, t4rpm)
            %set.T4Rpm Set the value for property T4Rpm
            validateattributes(t4rpm, {'numeric'}, {'nonempty', 'scalar'}, 'ThrusterRpms', 'T4Rpm');
            
            obj.JavaMessage.setT4Rpm(t4rpm);
        end
        
        function t5rpm = get.T5Rpm(obj)
            %get.T5Rpm Get the value for property T5Rpm
            t5rpm = int32(obj.JavaMessage.getT5Rpm);
        end
        
        function set.T5Rpm(obj, t5rpm)
            %set.T5Rpm Set the value for property T5Rpm
            validateattributes(t5rpm, {'numeric'}, {'nonempty', 'scalar'}, 'ThrusterRpms', 'T5Rpm');
            
            obj.JavaMessage.setT5Rpm(t5rpm);
        end
        
        function t6rpm = get.T6Rpm(obj)
            %get.T6Rpm Get the value for property T6Rpm
            t6rpm = int32(obj.JavaMessage.getT6Rpm);
        end
        
        function set.T6Rpm(obj, t6rpm)
            %set.T6Rpm Set the value for property T6Rpm
            validateattributes(t6rpm, {'numeric'}, {'nonempty', 'scalar'}, 'ThrusterRpms', 'T6Rpm');
            
            obj.JavaMessage.setT6Rpm(t6rpm);
        end
        
        function t7rpm = get.T7Rpm(obj)
            %get.T7Rpm Get the value for property T7Rpm
            t7rpm = int32(obj.JavaMessage.getT7Rpm);
        end
        
        function set.T7Rpm(obj, t7rpm)
            %set.T7Rpm Set the value for property T7Rpm
            validateattributes(t7rpm, {'numeric'}, {'nonempty', 'scalar'}, 'ThrusterRpms', 'T7Rpm');
            
            obj.JavaMessage.setT7Rpm(t7rpm);
        end
        
        function t8rpm = get.T8Rpm(obj)
            %get.T8Rpm Get the value for property T8Rpm
            t8rpm = int32(obj.JavaMessage.getT8Rpm);
        end
        
        function set.T8Rpm(obj, t8rpm)
            %set.T8Rpm Set the value for property T8Rpm
            validateattributes(t8rpm, {'numeric'}, {'nonempty', 'scalar'}, 'ThrusterRpms', 'T8Rpm');
            
            obj.JavaMessage.setT8Rpm(t8rpm);
        end
    end
    
    methods (Access = protected)
        function cpObj = copyElement(obj)
            %copyElement Implements deep copy behavior for message
            
            % Call default copy method for shallow copy
            cpObj = copyElement@ros.Message(obj);
            
            % Create a new Java message object
            cpObj.JavaMessage = obj.createNewJavaMessage;
            
            % Iterate over all primitive properties
            cpObj.T1Rpm = obj.T1Rpm;
            cpObj.T2Rpm = obj.T2Rpm;
            cpObj.T3Rpm = obj.T3Rpm;
            cpObj.T4Rpm = obj.T4Rpm;
            cpObj.T5Rpm = obj.T5Rpm;
            cpObj.T6Rpm = obj.T6Rpm;
            cpObj.T7Rpm = obj.T7Rpm;
            cpObj.T8Rpm = obj.T8Rpm;
        end
        
        function reload(obj, strObj)
            %reload Called by loadobj to assign properties
            obj.T1Rpm = strObj.T1Rpm;
            obj.T2Rpm = strObj.T2Rpm;
            obj.T3Rpm = strObj.T3Rpm;
            obj.T4Rpm = strObj.T4Rpm;
            obj.T5Rpm = strObj.T5Rpm;
            obj.T6Rpm = strObj.T6Rpm;
            obj.T7Rpm = strObj.T7Rpm;
            obj.T8Rpm = strObj.T8Rpm;
        end
    end
    
    methods (Access = ?ros.Message)
        function strObj = saveobj(obj)
            %saveobj Implements saving of message to MAT file
            
            % Return an empty element if object array is empty
            if isempty(obj)
                strObj = struct.empty;
                return
            end
            
            strObj.T1Rpm = obj.T1Rpm;
            strObj.T2Rpm = obj.T2Rpm;
            strObj.T3Rpm = obj.T3Rpm;
            strObj.T4Rpm = obj.T4Rpm;
            strObj.T5Rpm = obj.T5Rpm;
            strObj.T6Rpm = obj.T6Rpm;
            strObj.T7Rpm = obj.T7Rpm;
            strObj.T8Rpm = obj.T8Rpm;
        end
    end
    
    methods (Static, Access = {?matlab.unittest.TestCase, ?ros.Message})
        function obj = loadobj(strObj)
            %loadobj Implements loading of message from MAT file
            
            % Return an empty object array if the structure element is not defined
            if isempty(strObj)
                obj = ros.custom.msggen.proc_control_matlab.ThrusterRpms.empty(0,1);
                return
            end
            
            % Create an empty message object
            obj = ros.custom.msggen.proc_control_matlab.ThrusterRpms;
            obj.reload(strObj);
        end
    end
end