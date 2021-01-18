classdef KickIn < matlab.System
    % Calcule la commande des moteurs pour compenser la force gravitationnelle. Etant donne que le sous marin flotte, la force gravitationelle est une condition non nulle. Il faut la calculer en dehors du controleur


     
    properties

    end

    properties(DiscreteState)
    Aeq; % Matrice Trusters
    Beq; % Matrice Gravite
    
    uMin; % Force thruster min
    uMax; % Force thruster max
    u0; % Commande precedente
    end

    % Pre-computed constants
    properties(Access = private)
    
    end

    methods(Access = protected)
        function setupImpl(this,states,Tmin,Tmax)
            % Initialiser les matrices
            this.Aeq=ThrusterMatrix().';
            this.Beq=Gravity(states).';
            
            % condition initial 
            this.u0= [0,0,0,0,-7.1,6.94,-7.49,7.65];
            
            %limites thrusters
            this.uMin=Tmin;
            this.uMax=Tmax;

        end

        function [uMin,uMax,extMV] = stepImpl(this,states,Tmin,Tmax)
            %tic;
            this.uMin=Tmin;
            this.uMax=Tmax;

            % Fonction objective.
            fun = @(x)sum(abs(-this.u0-x));

            % Retrouver la matrice gravité
            this.Beq=Gravity(states).';
            
            % Parametre du solveur fmincon
            op =optimoptions('fmincon','Algorithm','sqp',...
                'ConstraintTolerance',0.01,'OptimalityTolerance',0.01);
              
            % Optimiser la commande pour la condition initial            
            this.u0= fmincon(fun,this.u0,[],[],this.Aeq,this.Beq,[],[],[],op);
          
            extMV=-this.u0.';
            
            % Calculer la nouvelle limite thruster
            for i=1:size(extMV,1)
                if extMV(i)>0
                    this.uMax(i)= this.uMax(i)-extMV(i);
                else
                    this.uMin(i)= this.uMin(i)-extMV(i);
                end
            end
            uMin=this.uMin;
            uMax=this.uMax;
            
           % toc;
        end

        function resetImpl(this)
            % Initialize / reset discrete-state properties
        end
    end
end
