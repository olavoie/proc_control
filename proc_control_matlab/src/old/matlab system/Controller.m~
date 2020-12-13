classdef Controller<matlab.System
    %CONTROLLER Summary of this class goes here
    %   Detailed explanation goes here
    
    properties
        %% specification du système
        nu;          % Nombre de Thruster
        nx;          % nombre d'états
        hPrediction; % Horizon de prediction
        hControl;    % Horizon de Controle
        ts;          % Période d'echantillionage
        AUVPlant;    % Modele d'etats du sous-marin
        
        %% Gain Controlleur
        OV;   % OutputVariables
        MV;   % ManipulatedVariables
        MRV;  % ManipulatedVariablesRate
        Tmin; % Force thruster minimum
        Tmax; % Force thruster maximum       
        TMIN; % Vecteur de force min
        TMAX; % Vecteur de force max
        
        %% Variable d'execution
        mpcObj;         % Object mpc
        mpcInfo;        % Information sur generation de commande
        mpcState;       % 
        trajectory;     % Tampon de la trajectoire
        currentCommand; % Commande actuelle
        currentState;   % Etats actuelle
        currentPlant;   % Modele linearize actuelle
        nominal;        % Nominale du modele linearise
        tourCount;      % Nombre de tour pour la discontinuité
        lastPose;       % last pose comptuted by the controller
        
        
        
        
    end
    %% Methodes publiques
    methods
         function obj = Controller(inputArg1,inputArg2)
            %CONTROLLER Construct an instance of this class
            %   Detailed explanation goes here
            obj.Property1 = inputArg1 + inputArg2;
         end
        
         function command = mpcStep(state)
         end
    end
    %% Methodes privées
    methods(Access= private)
             
        function checkedAngle = discontinuityCheck(this,pose)
           % Cette fonction vérifie et corrrige au besoin la discontinuite
           % des angles de rotation.
           
           checkedAngle=pose;
           
           % calculer la différence entre 2 point
           deltaYaw=this.lastPose(3:6)-pose(3:6);
           
           % Verifier la discontinuité du Yaw
           if abs (deltaYaw(6))>pi 
               % Compter le nouveau tours
               if deltaYaw >0
                  this.tourCount=this.tourCount+1;
                  checkedAngle(6)=(pi+pose(6))+(pi*this.tourCount);
               else
                  this.tourCount=this.tourCount-1;
                  checkedAngle(6)=-(pi-pose(6))+(pi*this.tourCount);
               end
            
           end
           
            
        end
        
        function trimPlant(this)
            % Cette fonction linearise le modele en fonctions des etats et
            % de la commande actuelle.
            
            % Lineariser le model dynamique
            [Ac, Bc, Cc, Dc]=AUVStateJacobianFcn(this.currentState,...
                                                 this.currentCommand);
            
            % Convertir le modèle dans le domaine echantillione (z)
            M = expm([[Ac Bc]*this.ts; zeros(this.nu,this.nu+this.nx)]);
            A = M(1:this.nx,1:this.nx);
            B = M(1: this.nx,this.nx+1:this.nx+this.nu);
            C = Cc;
            D = Dc;
            this.currentPlant=ss(A,B,C,D,Ts);
            
            % Calculer les Conditions Nominal
            this.nominal=struct('X',this.currentState,...
                                'U',this.currentCommand,...
                                'Y',Cc*this.currentState +...
                                    Dc*this.currentCommand,...
                                'DX',this.currentPlant.A*...
                                     this.currentState+...
                                     this.currentPlant.B*...
                                     this.currentCommand-...
                                     this.currentState);

        end
        
        function mpcAdvance(this)
            % Cette fonction calcule la prochaine commande 
            
            % Recevoir la trajectoire
            traj= trajectoryAdvance();
            
            % Calculer la nouvelle commande
            [this.currentCommand,this.mpcinfo] = mpcmoveAdaptive...
                (this.mpcobj,this.mpcState,this.currentPlant,...
                 this.nominal,this.currentState,traj,[]); 
             
            % Mettre à jour la derniere pose calculé
            this.lastPose=traj(:,1);
        end
        
        function output=trajectoryAdvance(this)
            % Cette donne la trajectoire nécéssaire pour que le mpc
            % calcule sa prochaine commande.
            
            nbPoint=size(this.trajectory,2);
            output =repmat(this.trajectory(:,1),1,this.hPrediction);
   
            % Ne pas supprimer le point si c'est le dernier.
            if nbPoint>1 
                this.trajectory(:,1)=[]; % supprimer le premier elements
            end
            
        end
        
    end
    end

