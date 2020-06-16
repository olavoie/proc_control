classdef ControlMode < matlab.mixin.Heterogeneous
    %CONTROLMODE Class.
    
    properties
        
    end
    
    methods 
        function obj = ControlMode()
            
        end
    end
    
%==========================================================================
%Methodes abstraites publiques
%==========================================================================        
    methods(Abstract, Access=public)
        process();
    end
end

