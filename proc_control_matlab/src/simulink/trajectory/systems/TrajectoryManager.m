classdef TrajectoryManager < matlab.System
    % untitled Add summary here
    %
    % This template includes the minimum set of functions required
    % to define a System object with discrete state.

    % Public, tunable properties
    properties(Nontunable)
     bufferSize=6001; % Taille statique 
    end

    properties
     p = 4; % Prédiction 
    end
    
    properties(DiscreteState)
    poseBuffer;
    i;
    end

    % Pre-computed constants
    properties(Access = private)
    dummy;
    emptyArray;
    end

    methods(Access = protected)
        function  setupImpl(this, pose, Newpose, InitCond)
            % Perform one-time calculations, such as computing constants
           this.i=0;
           this.dummy=999;% Chiffre NULL
           this.emptyArray= repmat(this.dummy,12,1); % Vecteur pose NULL
           
           % Buffer trajectoire
           this.poseBuffer=repmat(this.dummy,12,this.bufferSize);
           
           % Conditions Initiales
           this.poseBuffer(:,1)=InitCond;
           
%             traj=this.GenerateTrajectory();
%             this.poseBuffer(:,1:size(traj,2))=traj;
        end

        function [ref] = stepImpl(this, pose, newPose,InitCond)
            % Implement algorithm. Calculate y as a function of input u and
                
            if newPose>this.i
                this.poseBuffer(:,1:size(pose,2))=pose;
                this.i=this.i+1;
            end
            
            for i = 2:this.p
                if not(this.poseBuffer(:,i)== this.emptyArray)
                     this.poseBuffer=[this.poseBuffer(:,i:end),this.emptyArray];
                end
            end
                
                % Retourne les p prochains points.
                position=this.poseBuffer(1:3,1:this.p).';
                atitude=this.poseBuffer(4:6,1:this.p).';
                velocity=this.poseBuffer(7:9,1:this.p).';
                angularRate=this.poseBuffer(10:12,1:this.p).';
                
                ref = [position, atitude, velocity, angularRate];
                
            % Ne pas supprimer le point si c'est le dernier.
            if not(this.poseBuffer(:,2)== this.emptyArray)
               this.poseBuffer=[this.poseBuffer(:,2:end),this.emptyArray];
            end 
        end

        function resetImpl(this)
            % Initialize / reset discrete-state properties
        end
    end
end
