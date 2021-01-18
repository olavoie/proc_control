classdef DiscontinuityCheck < matlab.System
    % Cette fonction vérifie et corrige au besoin la discontinuite des angles de rotation.
    %
   

    properties(DiscreteState)
    tcount;
    lastPose;
    end

    % Pre-computed constants
    properties(Access = private)

    end

    methods(Access = protected)
        function setupImpl(this,pose,IC)
            % Perform one-time calculations, such as computing constants
            this.tcount=[0,0,0];
            this.lastPose=zeros(12,1);
        end

        function [checkedPose,tour] = stepImpl(this,pose,IC)
            % Implement algorithm. Calculate y as a function of input u and
            % discrete states.
            
           checkedPose=pose;
           
          for i=4:6 % compute roll pitch yaw
              
              % appliquer la discontinuté actuelle
               if this.tcount(i-3)>0
                   checkedPose(i)=(pose(i)+pi)+(pi*this.tcount(i-3));
               elseif this.tcount<0
                   checkedPose(i)=(pose(i)-pi)+(pi*this.tcount(i-3));
               end
               
               % calculer la différence entre 2 point
               delta=this.lastPose(i)-checkedPose(i);
              
               
               % Verifier la discontinuité de laxe
               if abs (delta)>=pi 
                   % Determiner le sens de la discontinuité
                   if delta >0 
                      % Ajouter un tour
                      this.tcount(i-3)=this.tcount(i-3)+1;
                      % Recaluler l'angle
                      checkedPose(i)=(pi+pose(i))+(pi*this.tcount(i-3));
                   else
                      % Soustraire un tour
                      this.tcount(i-3)=this.tcount(i-3)-1;
                      % Recaluler l'angle
                      checkedPose(i)=(pose(i)-pi)+(pi*this.tcount(i-3));
                   end
               end   
          end
           tour=this.tcount;
        end

        function resetImpl(this)
            % Initialize / reset discrete-state properties
        end
    end
end
