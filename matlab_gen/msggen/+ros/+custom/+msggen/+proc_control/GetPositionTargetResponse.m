classdef GetPositionTargetResponse < ros.Message
    %GetPositionTargetResponse MATLAB implementation of proc_control/GetPositionTargetResponse
    %   This class was automatically generated by
    %   ros.msg.internal.gen.MessageClassGenerator.
    
    %   Copyright 2014-2020 The MathWorks, Inc.
    
    %#ok<*INUSD>
    
    properties (Constant)
        MessageType = 'proc_control/GetPositionTargetResponse' % The ROS message type
    end
    
    properties (Constant, Hidden)
        MD5Checksum = '34adb43522d13055c055a891e43b18d4' % The MD5 Checksum of the message definition
    end
    
    properties (Access = protected)
        JavaMessage % The Java message object
    end
    
    properties (Dependent)
        X
        Y
        Z
        ROLL
        PITCH
        YAW
    end
    
    properties (Constant, Hidden)
        PropertyList = {'PITCH', 'ROLL', 'X', 'Y', 'YAW', 'Z'} % List of non-constant message properties
        ROSPropertyList = {'PITCH', 'ROLL', 'X', 'Y', 'YAW', 'Z'} % List of non-constant ROS message properties
    end
    
    methods
        function obj = GetPositionTargetResponse(msg)
            %GetPositionTargetResponse Construct the message object GetPositionTargetResponse
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
        
        function x = get.X(obj)
            %get.X Get the value for property X
            x = double(obj.JavaMessage.getX);
        end
        
        function set.X(obj, x)
            %set.X Set the value for property X
            validateattributes(x, {'numeric'}, {'nonempty', 'scalar'}, 'GetPositionTargetResponse', 'X');
            
            obj.JavaMessage.setX(x);
        end
        
        function y = get.Y(obj)
            %get.Y Get the value for property Y
            y = double(obj.JavaMessage.getY);
        end
        
        function set.Y(obj, y)
            %set.Y Set the value for property Y
            validateattributes(y, {'numeric'}, {'nonempty', 'scalar'}, 'GetPositionTargetResponse', 'Y');
            
            obj.JavaMessage.setY(y);
        end
        
        function z = get.Z(obj)
            %get.Z Get the value for property Z
            z = double(obj.JavaMessage.getZ);
        end
        
        function set.Z(obj, z)
            %set.Z Set the value for property Z
            validateattributes(z, {'numeric'}, {'nonempty', 'scalar'}, 'GetPositionTargetResponse', 'Z');
            
            obj.JavaMessage.setZ(z);
        end
        
        function roll = get.ROLL(obj)
            %get.ROLL Get the value for property ROLL
            roll = double(obj.JavaMessage.getROLL);
        end
        
        function set.ROLL(obj, roll)
            %set.ROLL Set the value for property ROLL
            validateattributes(roll, {'numeric'}, {'nonempty', 'scalar'}, 'GetPositionTargetResponse', 'ROLL');
            
            obj.JavaMessage.setROLL(roll);
        end
        
        function pitch = get.PITCH(obj)
            %get.PITCH Get the value for property PITCH
            pitch = double(obj.JavaMessage.getPITCH);
        end
        
        function set.PITCH(obj, pitch)
            %set.PITCH Set the value for property PITCH
            validateattributes(pitch, {'numeric'}, {'nonempty', 'scalar'}, 'GetPositionTargetResponse', 'PITCH');
            
            obj.JavaMessage.setPITCH(pitch);
        end
        
        function yaw = get.YAW(obj)
            %get.YAW Get the value for property YAW
            yaw = double(obj.JavaMessage.getYAW);
        end
        
        function set.YAW(obj, yaw)
            %set.YAW Set the value for property YAW
            validateattributes(yaw, {'numeric'}, {'nonempty', 'scalar'}, 'GetPositionTargetResponse', 'YAW');
            
            obj.JavaMessage.setYAW(yaw);
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
            cpObj.X = obj.X;
            cpObj.Y = obj.Y;
            cpObj.Z = obj.Z;
            cpObj.ROLL = obj.ROLL;
            cpObj.PITCH = obj.PITCH;
            cpObj.YAW = obj.YAW;
        end
        
        function reload(obj, strObj)
            %reload Called by loadobj to assign properties
            obj.X = strObj.X;
            obj.Y = strObj.Y;
            obj.Z = strObj.Z;
            obj.ROLL = strObj.ROLL;
            obj.PITCH = strObj.PITCH;
            obj.YAW = strObj.YAW;
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
            
            strObj.X = obj.X;
            strObj.Y = obj.Y;
            strObj.Z = obj.Z;
            strObj.ROLL = obj.ROLL;
            strObj.PITCH = obj.PITCH;
            strObj.YAW = obj.YAW;
        end
    end
    
    methods (Static, Access = {?matlab.unittest.TestCase, ?ros.Message})
        function obj = loadobj(strObj)
            %loadobj Implements loading of message from MAT file
            
            % Return an empty object array if the structure element is not defined
            if isempty(strObj)
                obj = ros.custom.msggen.proc_control.GetPositionTargetResponse.empty(0,1);
                return
            end
            
            % Create an empty message object
            obj = ros.custom.msggen.proc_control.GetPositionTargetResponse;
            obj.reload(strObj);
        end
    end
end
