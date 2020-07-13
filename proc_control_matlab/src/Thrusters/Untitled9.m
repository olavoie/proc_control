classdef Untitled9 < matlab.System
    % Untitled9 Add summary here
    %
    % NOTE: When renaming the class name Untitled9, the file name
    % and constructor name must be updated to use the class name.
    %
    % obj template includes most, but not all, possible properties,
    % attributes, and methods that you can implement for a System object.

    % Public, tunable properties
    properties
        L; %Mapping Matrix
        D; %Fault Matrix
        TSPEC; %T200 Spec table
        T; %Vecteur classe thruster
        FT; % Force min max truster
        MLDT; % Max load all DOF théorique
        MLDR; % Max load all DOF réel
       
        fl; %Limitation mecanique du truster en %.
        CT; % Commande Truster
        OPT; % instance TrusterOptimisation
        APX; % Instance ThrusterApprox
    end

    % Public, non-tunable properties
    properties(Nontunable)
      C; % Fichier config
    end

    properties(DiscreteState)
    
    end

    % Pre-computed constants
    properties(Access = private)

    end

    methods
        % Constructor
        function obj = Untitled9(varargin)
            % Constructeur
            
           % Charger le fichier de config et les spec thrusters
           
           obj.TSPEC= load('T200-Spec-16V.mat').T200Spec16V ;
       
        end
       
    end

    methods(Access = protected)
        %% Common functions
        function setupImpl(obj,dummy,config)
            % Perform one-time calculations, such as computing constants
            
             % Charger le fichier de config et les spec thrusters
           obj.C=varargin;
           obj.TSPEC= load('T200-Spec-16V.mat').T200Spec16V ;
           
            % Initialiser les matrice pour les calculs
           obj.GetMappingMatrix();
           obj.GetThrusterMatrix();
           obj.D= ones(1,obj.C.nbt);
           obj.FT = obj.GetMinMax(obj.TSPEC{:,6});
           
           % Trouver la limation mecanique selon la limitation élé.
           obj.EleMecRatio();
           
           %Calculer les forces max reel et theorique de chaque axes
           obj.MLDT = obj.GetMaxLoadAllAxis(obj.L);
           obj.MLDR = obj.GetMaxLoadAllAxis(obj.L*diag(obj.D*obj.fl));
           
           %Crée la fonction d'extrapolation pour les thrusters
           ep= obj.GetRelation(obj.TSPEC{:,6},obj.TSPEC{:,7});
           
           % Instancie la classe ThrusterOPtimisation
             obj.OPT= ThrusterOptimisation...
              (obj.TSPEC{:,6},obj.TSPEC{:,7},obj.C.nbt,ep,obj.FT);
           obj.APX= ThrusterApprox(obj.C.nbt,obj.FT*obj.fl,obj.MLDR);
        end

        function [t1,t2,t3,t4,t5,t6,t7,t8] = stepImpl(obj,commande,config)
            % Détermine la force de chaque thruster selon le vecteur résultant.
        % Arguments : input,vecteur résultant   
        
        tic;
        LD=obj.L*diag(obj.D);
        %Optimise la force de chaque thruster
        OT=obj.OPT.NLoptimiseThrusterOutput(LD,commande);
        % vérifie la fesabilitée et reduit la commande au besoin
        [rot, OLA]=obj.APX.ApproxThrusterOutput(OT,commande,obj.D);
        
        %Si un axe est surcharger
        if OLA(1)>0
         %Calculer le vecteur résultant réduit.
         LAC= obj.L*diag(obj.D)*rot.'; 
         SV=obj.GetAxisSaturation(LAC,OLA);
        end
        toc;
        oft=rot;
        end

        function resetImpl(obj)
            % Initialize / reset discrete-state properties
        end
      
         function GetThrusterMatrix(obj)
         % Crée le vecteur de class thruster.
         % Arguments : NA.
         obj.T=T200Thruster.empty(obj.C.nbt,0);
          for i=1:obj.C.nbt
                obj.T(i)=T200Thruster(obj.TSPEC,i);
           end
        end 
        
        function GetMappingMatrix(obj)
            % Calcule la matrice de componsates des thruster sur les 6DDL.
            % Arguments : d14, Matrice Distance x y z  des trusters 1 - 4.
            %             a14, Angles des trusters 1 - 4.
            %             d58, Matrice distance x y z des trusters 5 - 8.
            %             z,   Position des truster sur le frame.
            %             dz,  Distance entre les postions du frame.
            if ~exist('dz','var') %paramètre optionelle
              dz = 0;
            end
             if ~exist('z','var')
              z=[0,0,0,0];
             end
             % concactener les variables pour avour une matrice lisible.
             a14 =obj.C.a14;
             d14 =obj.C.d14; %dist centre geo - centre masse
             d58=obj.C.d58;  %dist centre geo - centre masse
             M=obj.C.CM;
             
             z=obj.C.z;
             dz =obj.C.dz;
             % Thruster effort Mapping Matrix (L)
            %       x         y      z      
           l1 = [ sin(a14),-cos(a14), 0,... fxyz
                (d14(3)-M(3)+z(1)*dz)*cos(a14),... rx
                (d14(3)-M(3)+z(1)*dz)*sin(a14),... ry
                -hypot( d14(1)-M(1), d14(2)-M(2))]; %rx
             
           l2 = [ sin(a14), cos(a14), 0,...fxyz
                 -(d14(3)-M(3)+z(2)*dz)*cos(a14),...rx
                 (d14(3)-M(3)+z(2)*dz)*sin(a14),...ry
                 -hypot( d14(1)+M(1), d14(2)-M(2))];%rx
             
           l3 = [ sin(a14),-cos(a14), 0,...fxyz
                (d14(3)-M(3)+z(3)*dz)*cos(a14),...rx
                 (d14(3)-M(3)+z(3)*dz)*sin(a14),...ry
                 hypot(d14(1)+M(1), d14(2)+M(2))];
             
           l4 = [ sin(a14), cos(a14), 0,...fxyz
                -(d14(3)-M(3)+z(4)*dz)*cos(a14),...rx
                 (d14(3)-M(3)+z(4)*dz)*sin(a14),...ry
                 hypot(d14(1)-M(1), d14(2)+M(2))];%rx
             
            l5 = [0, 0, 1, (d58(2)-M(2)+z(1)*dz),...
                 -(d58(1)-M(1)+z(1)*dz), 0];
             
            l6 = [0, 0,-1,-(d58(2)-M(2)+z(2)*dz),...
                  -(d58(1)+M(1)+z(2)*dz), 0];
              
            l7 = [0, 0, 1,-(d58(2)+M(2)+z(3)*dz),...
                (d58(1)+M(1)+z(3)*dz), 0];
            
            l8 = [0, 0,-1, (d58(2)+M(2)+z(4)*dz),...
                 (d58(1)-M(1)+z(2)*dz), 0];

            obj.L= [l1.', l2.', l3.', l4.', l5.' l6.', l7.', l8.'];
            disp(obj.L);
        end
        
        function lax= GetMaxLoadAllAxis(obj,L)
        % Calcule la force Maximum déployer sur les thrusters pur les 6DDL.
        % Arguments : V matrice de composantes des thrusters (6DDL)
        %             tf, matrice de force thruster horraire, antihorraire
        [rows ] = size(L);
        vml=zeros(rows(1),2);
      
         for i=1:rows(1)
            V = L(i,:);
            vml(i,:)= obj.GetMaxLoadOneAxis(V);
         end
         lax=vml;

        end
        
        function lxx= GetMaxLoadOneAxis(obj,V)
        % Calcule la force Maximum déployer sur les thrusters sur 1 DDL.
        % Arguments : V matrice de composantes des thrusters pour 1 DDL
                   
        pf = 0; % Force dans le sens positf de l'axe
        nf = 0; % Force dans le sens négatif de l'axe
         for i = 1:numel(V)
            pf=pf+ThrusterUtilities.GetThrusterMaxLoad(V(i),1,obj.FT);
            nf=nf+ThrusterUtilities.GetThrusterMaxLoad(V(i),-1,obj.FT);  
         end
         lxx=[pf,-nf];
        end
            
        function mm= GetMinMax(obj,A)
        % trouve la valeur maximum et minimum d'une matrice.
        % Arguments : N, Matrice data.
        mm=[A(end),A(1)];
        end
        
        function EleMecRatio(obj)
        % transforme le % de limitation élé(A) en % limitation mec (N).
   
            %Séparer la relation newton selon watt en 2 pour pas que la
            %fonction soit complexe.
            PN=obj.TSPEC{108:end,6};
            NN=obj.TSPEC{1:94,6};
            PW=obj.TSPEC{108:end,7};
            NW=obj.TSPEC{1:94,7};
            % Trouver les min max en x ey y
            MW= obj.GetMinMax(obj.TSPEC{:,7});
           
            %Trouver la fonction de la parti positif(P) et négatif(N)
            TP=obj.GetRelation(PW,PN);
            TN=obj.GetRelation(NW,NN);
            %Trouver la force équivalent au courant maximum limité 
            LIMP=TP(MW(1)*obj.C.psl);
            LIMN=TN(MW(2)*obj.C.psl);
            % Mettre les nouvelle force maximal en %.
            MLP=LIMP/obj.FT(1);
            MLN=LIMN/obj.FT(2);
            %retourner la valeur min.
            obj.fl= min(MLP,MLN);
        end
        
        function f= GetRelation(obj,x,y)
        % trouve une équoition d'orde 6 pour un nuage de point donnée.
        % Arguments : x, Matrice des composante x.
        %             y, Matrice des composante y.
        opt = fitoptions('poly2','Normalize', 'on', 'Robust', 'Bisquare');
        f=fit(x,y,'poly5',opt);
        end
        
        function SV= GetAxisSaturation(obj,LAC,OLA)
        % Calcule le vecteur saturation pour limiter un ou plusieurs axe.
         % Arguments : LAC.
            SV=zeros(1,6);
            for i=1:6
                if ismember(i,OLA)
                    SV(i)=LAC(i);
                end
            end
        end 
    end
end
