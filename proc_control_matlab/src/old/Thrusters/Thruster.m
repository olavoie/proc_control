classdef Thruster < matlab.mixin.Heterogeneous
    % THRUSTER class.
%==========================================================================
%Proprietes
%==========================================================================    
    properties
        id;
        force;
        power;
        current;
        rpm;
        pwm;
        efficiency;
    end
%==========================================================================
%Methodes
%==========================================================================
    methods
        % Construstor
        function obj = Thruster()
           
        end
        
        % Setter pour ajuster la force ainsi que les informations du
        % thruster.
        % Argument: f - Force
        function this = set.force(this, f)
           this.force = f; 
           this.pwm = this.forceToPwm(this.force);
           this.current = this.forceToCurrent(this.force);
           this.efficiency = this.forceToEfficiency(this.force);
           this.rpm = this.forceToRPM(this.force);
           this.power = this.forceToPower(this.force);
        end
    end 
%==========================================================================
%Methodes abstraites publiques
%==========================================================================        
    methods(Abstract, Access=public)
        forceToPwm(this, force);     
        forceToCurrent(this, force);
        forceToEfficiency(this, force);   
        forceToRPM(this, force);       
        forceToPower(this, force);
    end
end