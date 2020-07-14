classdef ThrusterApprox <matlab.System
    %THRUSTERAPPROX Summary of this class goes here
    %   Detailed explanation goes here
%==========================================================================
%Propriétés.
%==========================================================================
    properties
        nbt; % Nombre de thrusters
        LTF; % Limited Thruster Force (force mac avec limitation ele)
        MLDR;%Max load all DOF réel.
         
    end
    
%==========================================================================
%Accesseur/mutateur
%==========================================================================
    methods
        function set.MLDR(this,input)
            this.MLDR=input;
        end
    end
    
%==========================================================================
%Methodes publique 
%==========================================================================    
    methods
        function this = ThrusterApprox(nbt,LTF,MLDR)
            %Constructeur
            this.nbt =nbt;
            this.LTF=LTF;
            this.MLDR=MLDR;
        end
        
        function [rOutput,OLA] =ApproxThrusterOutput(this,output,command,D)
        % Détermine si la commande est feasble et la réduit au besoin.
        % Arguments : output thurtser, la commande , la matrice de défaut.
            [ok, TFACTOR] = this.CheckFesability(output,D);
            if not(ok)% Si la commande est infesable
                s = this.GetSFactor(TFACTOR);
                sOutput= this.ApplySFactor(output,s);
                OLA = this.GetOverLoadedAxis(command);
                rOutput =sOutput;
            else
                OLA=0;
                rOutput=output;
            end
            
        end
         
    end
%==========================================================================
%Methodes privées
%==========================================================================
 methods(Access= private)

     function [ok, ER] = CheckFesability(this,output,D)
        % Vérifie si les thruster ne dépasse pas leurs limite maximum
        % Arguments : output, la matrice des forces de chaques thrusters  
            EffRatio=zeros(1,this.nbt);
            f=true;
    
            for i=1:this.nbt
                % Empêche la divison par 0 si le Thruster est desactivé
                if D(i)== 0 
                    EffRatio(i)=0;
                else
                    % Calcule en % la force du thruster
                    EffRatio(i)= abs(output(i))/ThrusterUtilities...
                        .GetThrusterMaxLoad(D(i),output(i),this.LTF);
                                    
                    % Si le thruster dépasse sa capacité maximum           
                    if EffRatio(i)>1
                        f=false;
                    end                 
                end
            end    
            ok=f;
            ER=EffRatio;
     end
        
     
     function sOutput=ApplySFactor(this,command,s)
      % Applique le facteur s sur la sortie des moteurs
      % Arguments : la commande thruster, le facteur s. 
           sOutput= command*s;
     end
     
     function he= GetHeadingError(this,command,approx)
 
        c=command(:,1:3);
        a=approx(:,1:3);
        he = rad2deg(atan2(norm(cross(a,c)),dot(a,c)));
     end
     
     function s = GetSFactor(this,tl)
      % calcule le coefficient s 
      % Arguments : le % du load des thrusters.
           stl= sort(tl,'descend'); 
           s=1/stl(1);
     end
     
     function OLA= GetOverLoadedAxis(this,command)
      % Trouver l'axe qui rend la commande infesable
      % Arguments : la commande thruster. 
         Axeratio=zeros(1,6);
         Overload=-1;
         for i=1:6
             if command(i)>=0
                Axeratio(i)=command(i)/this.MLDR(i,1);
             else
                Axeratio(i)=command(i)/this.MLDR(i,2);
             end
             if Axeratio(i)>Overload
                 Overload =zeros(0,1);
                 Overload=i;
             elseif Axeratio(i) == Overload(1)
                 Overload= [overload,i];
             end
             
         end
         OLA=Overload;    
     end
     
     
 end
end

