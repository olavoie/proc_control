classdef ThrusterOptimisation < matlab.System
    %TRUSTEROPTIMISATION Summary of this class goes here
    %   Detailed explanation goes here
%==========================================================================
%Propriétés.
%==========================================================================   
    properties
      
        f;  % Objective function
        N;  % Newton array
        W;  % Watt array
        SN; % simplify Newton array
        SW; % simplify Watt array
        nbt;% Nombre de thrusters.
        ef; % extrapole du tableau N/W
        FT; % Force min max truster
    end
%==========================================================================
%Methodes publique
%==========================================================================   
    methods (Access= public)

        function this = ThrusterOptimisation(N,W,nbt,ef,FT)
        % Constructeur
            this.N=N;
            this.W=W;
            this.ef=ef;
            this.FT=FT;
            this.nbt=nbt;
            this.ReduceArray();
            this.f = @(x) this.OptNonLinearObjFunc(x);
            
        end

        function ReduceArray(this)
    % réduit les tableau N et W pour réduire le temps de l'optimisation. 
        this.SN=this.N(2:2:end,:);
        this.SW=this.W(2:2:end,:);

        end

        function OT = NLoptimiseThrusterOutput(this,LD,command)
   % optimise la sortie des thrusters pour limiter la cosomation élé
    % Arguments : input,vecteur résultant
    %           : LD, M=matrice L X matrice D
    
       s=zeros(1,this.nbt);
       % s=this.ComputeFeasibleSolution(LD,command);
     %op=optimoptions('fmincon','Algorithm','sqp','UseParallel',true...
       %  );

     op=optimoptions('fmincon','Algorithm','sqp');
  
     [SOL, min, flag, outs]=...
           fmincon(this.f,s,[],[],LD,command,[],[],[],op);
          
     if flag ==-2
         %approx=(this.L*SOL).';
         %he=this.GetHeadingError(command, approx);
     end
   
   
    OT= SOL;
    end

        function f= OptNonLinearObjFunc(this,x)
    % fonction objective optimisé pour la minimisation non linéaire. 
    % retourne la Consomation élé total selon la force des 8 thrusters
    % Arguments : x, vecteur force des 8 thrusters
        n=0;
        for i=1:this.nbt
            if(x(i)>=this.FT(2) && x(i)<=this.FT(1))
                n=n+interp1(this.SN, this.SW, x(i), "next");   
            else
                n=n+1500;
               % n=n+this.ef(x);
            end
        end
        f=n;
    end

        function f= RealNonLinearObjFunc(this,x)
        % fonction objective réel pour la minimisation non linéaire. 
        % retourne la Consomation élé total selon la force des 8 thrusters
        % Arguments : x, vecteur force des 8 thrusters
        n=0;
        for i=1:this.nbt
        n=n+interp1(this.N, this.W, x(i), "spline");
        end
        f=n;
    end

        function s=ComputeFeasibleSolution(this,LD,command)
    % Calcule un solution fesable non optimal pour donnée les point de 
    % départ au solveur. ceci réduit le temps d'optimisation
    % Arguments: command, le vecteur résultant.
        c1=[1,0,-1,0,0,0,0,0];
        c2=[0,0,0,0,0,1,0,1];
        RM= [LD;c1;c2];
        FC= [command,0,0].';
        s=RM\FC;     
        end
    
    end
end

