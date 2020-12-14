classdef Controller
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
        MVR;  % ManipulatedVariablesRate
        Tmin; % Force thruster minimum
        Tmax; % Force thruster maximum       
        TMIN; % Vecteur de force min
        TMAX; % Vecteur de force max
        
        %% Variable d'execution
        mpcObj;         % Object mpc
        mpcInfo;        % Information sur generation de commande
        mpcState;       % Object state pour le controlleur
        coreData;
        stateData;
        onlineData;
        trajectory;     % Tampon de la trajectoire
        currentCommand; % Commande actuelle
        currentState;   % Etats actuelle
        currentPlant;   % Modele linearize actuelle
        nominal;        % Nominale du modele linearise
        poseTourCount;  % Nombre de tour pour la discontinuité de la pose
        stateTourCount; % Nombre de tour pour la discontinuité des states
        lastPose;       % last pose comptuted by the controller
        lastState;      % State of previous commands
        
   
    end
    %% Methodes publiques
    methods
         function this = Controller(nx,nu,hp,hc,plant,ts)
            %CONTROLLER Construct an instance of this class
            %   Detailed explanation goes here
            this.nx=nx;
            this.nu=nu;
%           this.hPrediction=hp;
%           this.hControl=hc;
            this.AUVPlant=plant;
            this.ts=ts;
          
            % Création du controleur MPC.
            this.mpcObj =mpc(this.AUVPlant);
            
            % Ajouts des spécifications système
            this.mpcObj.PredictionHorizon =hp;
            this.mpcObj.ControlHorizon=hc;
            %this.mpcState=mpcstate(this.mpcObj);
          
            % Calculer les structure du controlleur
            [this.coreData,this.stateData,this.onlineData] =...
                getCodeGenerationData(this.mpcObj);
         end
         
         function changeGain(this,ov,mv,mvr)
             % Ajouts des gains dans le controleur
             this.onlineData.Weights.y = ov;
             this.onlineData.Weights.u = mv;
             this.onlineData.Weights.du = mvr;
             
         end
         
         function changeThrusterLoad(this,tmin, tmax)
             this.onlineData.limits.umin=tmin;
             this.onlineData.limits.umax=tmax;
             
             % Ajouts des limites thruster dans le controleur
            % this.mpcObj.MV = struct('Min',tmin,'Max',tmax);
             
         end
         function command = mpcStep(this,state)
             
             this.onlineData.signals.ym, this.stateTourCount...
                 =discontinuityCheck(state,this.stateTourCount);
            
             trimPlant();
             mpcAdvance();
             this.lastState= this.currentState;
             command=this.currentCommand;
         end
    end
    %% Methodes privées
    methods(Access= private)
             
        function[checkedPose,tcount]= discontinuityCheck(this,pose,tcount)
           % Cette fonction vérifie et corrige au besoin la discontinuite
           % des angles de rotation.
           
           checkedPose=pose+(pi*tcount);
           checkedPose(3:6)=pose(3:6)+(pi*tcount);
           % calculer la différence entre 2 point
           deltaYaw=this.lastPose(3:6)-pose(3:6);
           
           % Verifier la discontinuité du Yaw
           if abs (deltaYaw(6))>pi 
               % Compter le nouveau tours
               if deltaYaw >0
                  tcount=this.tcount+1;
                  checkedPose(6)=(pi+pose(6))+(pi*tcount);
               else
                  tcount=this.tcount-1;
                  checkedPose(6)=-(pi-pose(6))+(pi*tcount);
               end
            
           end
           
            
        end
        
        function trimPlant(this)
            % Cette fonction linearise le modele en fonctions des etats et
            % de la commande actuelle.
            
            % Lineariser le model dynamique
            [Ac, Bc, Cc, Dc]=AUVStateJacobianFcn(this.currentState,...
                                                 this.currentCommand);
            
            %% Convertir le modèle dans le domaine echantillione (z)
            M = expm([[Ac Bc]*this.ts; zeros(this.nu,this.nu+this.nx)]);
            A = M(1:this.nx,1:this.nx);
            B = M(1: this.nx,this.nx+1:this.nx+this.nu);
            C = Cc;
            D = Dc;
            
            this.onlineData.model.A=A;
            this.onlineData.model.B=B;
            this.onlineData.model.C=C;
            this.onlineData.model.D=D;
            
           % this.currentPlant=ss(A,B,C,D,Ts);
           %this.currentPlant=struct('A',A,'B',B,'C',C,'D',D);
            
            %% Calculer les Conditions Nominal
            this.onlineData.model.X=this.currentState;
            this.onlineData.model.U=this.currentCommand;
            this.onlineData.model.Y=Cc*this.currentState +...
                                    Dc*this.currentCommand;
            this.onlineData.model.DX= this.currentPlant.A*...
                                     this.currentState+...
                                     this.currentPlant.B*...
                                     this.currentCommand-...
                                     this.currentState;     
                                 
%             this.nominal=struct('X',this.currentState,...
%                                 'U',this.currentCommand,...
%                                 'Y',Cc*this.currentState +...
%                                     Dc*this.currentCommand,...
%                                 'DX',this.currentPlant.A*...
%                                      this.currentState+...
%                                      this.currentPlant.B*...
%                                      this.currentCommand-...
%                                      this.currentState);

        end
        
        function mpcAdvance(this)
            % Cette fonction calcule la prochaine commande 
            
            % Recevoir la trajectoire
            trajectoryAdvance();
            
            % Calculer la nouvelle commande
            [this.currentCommand,this.stateData,this.mpcInfo]...
                = mpcmoveCodeGeneration...
                (this.coreData,this.stateData,this.onlineData);
            
%             [this.currentCommand,this.mpcinfo] = mpcmoveAdaptive...
%                 (this.mpcobj,this.mpcState,this.currentPlant,...
%                  this.nominal,this.currentState,traj,[]); 
             
            % Mettre à jour la derniere pose calculé
            this.lastPose=this.onlineData.signals.ref;
        end
        
        function trajectoryAdvance(this)
            % Cette donne la trajectoire nécéssaire pour que le mpc
            % calcule sa prochaine commande.
            
            nbPoint=size(this.trajectory,2);
            
            [output, this.poseTourCount] =discontinuityCheck...
                    (this.trajectory(:,1),this.poseTourCount);
                
           this.onlineData.signals.ref=output;
   
            % Ne pas supprimer le point si c'est le dernier.
            if nbPoint>1 
                this.trajectory(:,1)=[]; % supprimer le premier elements
            end
            
        end
        
    end
end

