classdef DiscontinuityCheck < matlab.System
    % Cette fonction vérifie et corrige au besoin la discontinuite des angles de rotation.
    %
   

    properties(DiscreteState)
    tcount; % Nombre de tours
    lastAngle; % Dernière de Position
    end

    % Pre-computed constants
    properties(Access = private)

    end

    methods(Access = protected)
        function setupImpl(this,pose)
            % Perform one-time calculations, such as computing constants
            this.tcount=[0,0,0];
            this.lastAngle=zeros(3,1);
        end

        function [checkedAngle,tour] = stepImpl(this,angle)
            % Implement algorithm. Calculate y as a function of input u and
            % discrete states.
            
           checkedAngle=angle;
           
          for i=1:3 % compute roll pitch yaw
              
              % appliquer la discontinuté actuelle
               if this.tcount(i)>0
                   checkedAngle(i)=(angle(i)+pi)+(pi*this.tcount(i));
               elseif this.tcount<0
                   checkedAngle(i)=(angle(i)-pi)+(pi*this.tcount(i));
               end
               
               % calculer la différence entre 2 point
               delta=this.lastAngle(i)-checkedAngle(i);
              
               
               % Verifier la discontinuité de laxe
               if abs (delta)>=pi 
                   % Determiner le sens de la discontinuité
                   if delta >0 
                      % Ajouter un tour
                      this.tcount(i)=this.tcount(i)+1;
                      % Recaluler l'angle
                      if this.tcount(i)==0
                        checkedAngle(i)=angle(i);
                      else
                        checkedAngle(i)=(pi+angle(i))+(pi*this.tcount(i));
                      end
                   else
                      % Soustraire un tour
                      this.tcount(i)=this.tcount(i)-1;
                      % Recaluler l'angle
                      if this.tcount(i)==0
                        checkedAngle(i)=angle(i);
                      else
                      checkedAngle(i)=(angle(i)-pi)+(pi*this.tcount(i));
                      end
                   end
               end   
          end
           tour=this.tcount;
           this.lastAngle= checkedAngle;
        end

        function resetImpl(this)
            % Initialize / reset discrete-state properties
        end
    end
end
