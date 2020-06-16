classdef ThrusterUtilities
    %THRUSTERUTILITIES Summary of this class goes here
    %   Detailed explanation goes here
    
    
    
    methods (Static)
       function mt = GetThrusterMaxLoad(c,sens,FT)
        % Retourne la force de la composante selon le sens du thruster
        % Arguments : c, la composante du thruster, 
        %             tf, matrice de force thruster horraire, antihorraire.
        %             sens, le sens de laxe exemple x+ ou x-
            if (c>0 && sens>=0) || (c<0 && sens<0)
               mt = abs(c*FT(1));
            else
               mt = abs(c*FT(2));
            end
        end
    end
end

