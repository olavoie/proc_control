classdef ControllerSystem< matlab.System
    %CONTROLLERSYSTEM Summary of this class goes here
    %   Detailed explanation goes here
    
    properties(Nontunable)
        
        %plant=coder.load('AUVPlant.mat').AUVPlant;
        MPC;
    end
    
     methods(Access = protected)
          function setupImpl(this,States,trajectory)
            % Définire les constantes
            tmax=32;
            tmin=-26;
            TMIN ={tmin; tmin; tmin; tmin; tmin; tmin; tmin; tmin};
            TMAX ={ tmax; tmax; tmax; tmax; tmax; tmax; tmax; tmax};
            OV =[ 70 70 50 70 70 70 0 0 0 0 0 0 ];  %OutputVariables
            MV =[.5 .5 .5 .5 0.1 0.1 0.1 0.1]; %ManipulatedVariables
            MVR=[.4 .4 .4 .5 .5 .5 .5 .5]; %.ManipulatedVariablesRate
            % Crée le controlleur 
            this.MPC=Controller(12,8,10,2,coder.load('AUVPlant.mat').AUVPlant,0.1);
            this.MPC.changeGain(OV,MV,MVR);
            this.MPC.changeThrusterLoad(TMIN,TMAX);
            
            %this.MPC.trajectory=trajectory;
          end
          
          function Command = stepImpl(this,States,Trajectory)
            Command=this.MPC.mpcStep(States);
          end
          
        function resetImpl(this)
            % Initialize / reset discrete-state properties
        end
     end
end

