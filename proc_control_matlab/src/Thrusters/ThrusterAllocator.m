classdef ThrusterAllocator < handle
    %THRUSTERMODEL Summary of this class goes here
    %  Detailed explanation goes here
%==========================================================================
%Propriétés.
%==========================================================================
 properties (Access= public)
     
        L; %Mapping Matrix
        D; %Fault Matrix
        TSPEC; %T200 Spec table
        T; %Vecteur classe thruster
        FT; % Force min max truster
        MLDT; % Max load all DOF théorique
        MLDR; % Max load all DOF réel
        C; % Fichier config
        fl; %Limitation mecanique du truster en %.
        CT; % Commande Truster
        OPT; % instance TrusterOptimisation
      
 end
%==========================================================================
%Accesseur/mutateur
%==========================================================================
methods 
        function value =get.L(this)
               value = this.L; 
        end

        function value =get.D(this)
               value = this.D; 
        end

        function value =get.fl(this)
               value = this.fl; 
        end

        function value =get.MLDT(this)
               value = this.MLDT; 
        end

        function value =get.MLDR(this)
               value = this.MLDR; 
        end
        
        function set.D(this,input)
         [l,c] = size(input);  
             if l==1 && c== this.C.nbt %vérifier la dimention de la matrice
                 for i=1:this.C.nbt
                    if input(i)>=0
                        if input(i)>1
                            this.D(i)= 1;
                        else
                            this.D(i)= input(i);
                        end
                    end
                 end
            end
        end
        
end
%==========================================================================
%Methodes publique 
%==========================================================================
    methods (Access= public)
        function this = ThrusterAllocator(Config)
        % Constructeur
            
           % Charger le fichier de config et les spec thrusters
           this.C=Config;
           this.TSPEC= load('T200-Spec-16V.mat').T200Spec16V ;
            
           % Initialiser les matrice pour les calculs
           this.GetMappingMatrix();
           this.GetThrusterMatrix();
           this.D= ones(1,this.C.nbt);
           this.FT = this.GetMinMax(this.TSPEC{:,6});
           
           % Trover la limation mécanique selon la limitation élé.
           this.EleMecRatio();
           
           %Calculer les forces max reel et theorique de chaque axes
           this.MLDT = this.GetMaxLoadAllAxis(this.L);
           this.MLDR = this.GetMaxLoadAllAxis(this.L*diag(this.D*this.fl));
           
           %Crée la fonction d'extrapolation pour les thrusters
           ep= this.GetRelation(this.TSPEC{:,6},this.TSPEC{:,7});
           
           % Instancie la classe ThrusterOPtimisation
           this.OPT= ThrusterOptimisation...
               (this.TSPEC{:,6},this.TSPEC{:,7},this.C.nbt,ep,this.FT);
        end

        function UpdateDampingMatrix(this, input)
             % Update la matrice defaut et recalcule les force max.
             % Arguments : changerment matrice defaut
            this.D = input;
            this.MLDR = this.GetMaxLoadAllAxis(this.L*diag(this.D));
        end
        
 
        function OT = GetNlThrusterOutput(this,command)
        % Détermine la force de chaque thruster selon le vecteur résultant.
        % Arguments : input,vecteur résultant   
        
        tic;
        LD=this.L*diag(this.D);
        %Optimise la force de chaque
        OT=this.OPT.NLoptimiseThrusterOutput(LD,command);
        [b, ER] = this.CheckFesability(OT);
        
         if b
         disp("rip");
             
         end
       toc;
        for i=1:this.C.nbt
            this.T(i).force=OT(i);
        end
        toc;
  
    end

    end
%==========================================================================
%Methodes privées
%==========================================================================
 methods(Access= private)

        function GetThrusterMatrix(this)
         % Crée le vecteur de class thruster.
         % Arguments : NA.
         this.T=T200Thruster.empty(this.C.nbt,0);
          for i=1:this.C.nbt
                this.T(i)=T200Thruster(this.TSPEC,i);
           end
        end 
        
        function GetMappingMatrix(this)
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
             a14 =this.C.a14;
             d14 =this.C.d14;
             d58=this.C.d58;
             z=this.C.z;
             dz =this.C.dz;
             % Thruster effort Mapping Matrix (L)
            %       x         y      z rx ry           rz
            l1 = [ sin(a14),-cos(a14), 0, (d14(3)+z(1)*dz)*cos(a14),...
                 (d14(3)+z(1)*dz)*sin(a14),-hypot( d14(1), d14(2))];
             
            l2 = [ sin(a14), cos(a14), 0,-(d14(3)+z(2)*dz)*cos(a14),...
                 (d14(3)+z(2)*dz)*sin(a14),-hypot(-d14(1), d14(2))];
             
            l3 = [ sin(a14),-cos(a14), 0, (d14(3)+z(3)*dz)*cos(a14),...
                 (d14(3)+z(3)*dz)*sin(a14), hypot(-d14(1),-d14(2))];
             
            l4 = [ sin(a14), cos(a14), 0,-(d14(3)+z(4)*dz)*cos(a14),...
                 (d14(3)+z(4)*dz)*sin(a14), hypot( d14(1),-d14(2))];
             
            l5 = [0, 0, 1, d58(2),-d58(1), 0];
            l6 = [0, 0,-1,-d58(2),-d58(1), 0];
            l7 = [0, 0, 1,-d58(2), d58(1), 0];
            l8 = [0, 0,-1, d58(2), d58(1), 0];

            this.L= [l1.', l2.', l3.', l4.', l5.' l6.', l7.', l8.'];
        end
        
        function lax= GetMaxLoadAllAxis(this,L)
        % Calcule la force Maximum déployer sur les thrusters pur les 6DDL.
        % Arguments : V matrice de composantes des thrusters (6DDL)
        %             tf, matrice de force thruster horraire, antihorraire
        [rows ] = size(L);
        vml=zeros(rows(1),2);
      
         for i=1:rows(1)
            V = L(i,:);
            vml(i,:)= this.GetMaxLoadOneAxis(V);
         end
         lax=vml;

        end
        
        function lxx= GetMaxLoadOneAxis(this,V)
        % Calcule la force Maximum déployer sur les thrusters sur 1 DDL.
        % Arguments : V matrice de composantes des thrusters pour 1 DDL
                   
        pf = 0; % Force dans le sens positf de l'axe
        nf = 0; % Force dans le sens négatif de l'axe
         for i = 1:numel(V)
            pf=pf+this.GetThrusterMaxLoad(V(i),1);
            nf=nf+this.GetThrusterMaxLoad(V(i),-1);  
         end
         lxx=[pf,-nf];
        end
        
        function mt = GetThrusterMaxLoad(this,c,sens)
        % Retourne la force de la composante selon le sens du thruster
        % Arguments : c, la composante du thruster, 
        %             tf, matrice de force thruster horraire, antihorraire.
        %             sens, le sens de laxe exemple x+ ou x-
            if (c>0 && sens>=0) || (c<0 && sens<0)
               mt = abs(c*this.FT(1));
            else
               mt = abs(c*this.FT(2));
            end
        end
            
        function mm= GetMinMax(this,A)
        % trouve la valeur maximum et minimum d'une matrice.
        % Arguments : N, Matrice data.
        mm=[A(end),A(1)];
        end
        
        function EleMecRatio(this)
        % transforme le % de limitation élé(A) en % limitation mec (N).
   
            %Séparer la relation newton selon watt en 2 pour pas que la
            %fonction soit complexe.
            PN=this.TSPEC{108:end,6};
            NN=this.TSPEC{1:94,6};
            PW=this.TSPEC{108:end,7};
            NW=this.TSPEC{1:94,7};
            % Trouver les min max en x ey y
            MW= this.GetMinMax(this.TSPEC{:,7});
           
            %Trouver la fonction de la parti positif(P) et négatif(N)
            TP=this.GetRelation(PW,PN);
            TN=this.GetRelation(NW,NN);
            %Trouver la force équivalent au courant maximum limité 
            LIMP=TP(MW(1)*this.C.psl);
            LIMN=TN(MW(2)*this.C.psl);
            % Mettre les nouvelle force maximal en %.
            MLP=LIMP/this.FT(1);
            MLN=LIMN/this.FT(2);
            %retourner la valeur min.
            this.fl= min(MLP,MLN);
        end
        
        function f= GetRelation(this,x,y)
        % trouve une équoition d'orde 6 pour un nuage de point donnée.
        % Arguments : x, Matrice des composante x.
        %             y, Matrice des composante y.
        opt = fitoptions('poly2','Normalize', 'on', 'Robust', 'Bisquare');
        f=fit(x,y,'poly5',opt);
        end
        
        function [b, ER] = CheckFesability(this,output)
        % Vérifie si les thruster ne dépasse pas leurs limite maximum
        % Arguments : output, la matrice des forces de chaques thrusters  
            EffRatio=zeros(1,this.C.nbt);
            f=false;
    
            for i=1:this.C.nbt
                % Empêche la divison par 0 si le Thruster est desactivé
                if this.D(i)== 0 
                    EffRatio(i)=0;
                else
                    % Calcule en % la force du thruster
                    EffRatio(i)= abs(output(i))/this.GetThrusterMaxLoad...
                                    (this.D(i)*this.fl,output(i));
                    % Si le thruster dépasse sa capacité maximum           
                    if EffRatio(i)>1
                        f=true;
                    end                 
                end
            end    
            b=f;
            ER=EffRatio;
        end

 end
end

