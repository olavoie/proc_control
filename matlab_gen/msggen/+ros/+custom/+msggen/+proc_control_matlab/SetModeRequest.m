classdef SetModeRequest < ros.Message
    %SetModeRequest MATLAB implementation of proc_control_matlab/SetModeRequest
    %   This class was automatically generated by
    %   ros.msg.internal.gen.MessageClassGenerator.
    
    %   Copyright 2014-2021 The MathWorks, Inc.
    
    %#ok<*INUSD>
    
    properties (Constant)
        MessageType = 'proc_control_matlab/SetModeRequest' % The ROS message type
    end
    
    properties (Constant, Hidden)
        MD5Checksum = '0d805792b7f49b5f4455f5d838369883' % The MD5 Checksum of the message definition
    end
    
    properties (Access = protected)
        JavaMessage % The Java message object
    end
    
    properties (Dependent)
        Mode
    end
    
    properties (Constant, Hidden)
        PropertyList = {'Mode'} % List of non-constant message properties
        ROSPropertyList = {'Mode'} % List of non-constant ROS message properties
    end
    
    methods
        function obj = SetModeRequest(msg)
            %SetModeRequest Construct the message object SetModeRequest
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
        
        function mode = get.Mode(obj)
            %get.Mode Get the value for property Mode
            mode = int64(obj.JavaMessage.getMode);
        end
        
        function set.Mode(obj, mode)
            %set.Mode Set the value for property Mode
            validateattributes(mode, {'numeric'}, {'nonempty', 'scalar'}, 'SetModeRequest', 'Mode');
            
            obj.JavaMessage.setMode(mode);
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
            cpObj.Mode = obj.Mode;
        end
        
        function reload(obj, strObj)
            %reload Called by loadobj to assign properties
            obj.Mode = strObj.Mode;
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
            
            strObj.Mode = obj.Mode;
        end
    end
    
    methods (Static, Access = {?matlab.unittest.TestCase, ?ros.Message})
        function obj = loadobj(strObj)
            %loadobj Implements loading of message from MAT file
            
            % Return an empty object array if the structure element is not defined
            if isempty(strObj)
                obj = ros.custom.msggen.proc_control_matlab.SetModeRequest.empty(0,1);
                return
            end
            
            % Create an empty message object
            obj = ros.custom.msggen.proc_control_matlab.SetModeRequest;
            obj.reload(strObj);
        end
    end
end
