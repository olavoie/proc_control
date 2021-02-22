classdef TrimPlant < matlab.System
    %Cette fonction linearise le modele en fonctions des etats et de la commande actuelle.

    properties(DiscreteState)
    Ac; % Matrice A domaine continue
    Bc; % Matrice B domaine continue
    Cc; % Matrice C domaine continue
    Dc; % Matrice D domaine continue
    end

    % Pre-computed constants
    properties(Access = private)

    end

    methods(Access = protected)
        function setupImpl(this,u,Ts,y)
            % Perform one-time calculations, such as computing constants
            [this.Ac, this.Bc, this.Cc, this.Dc]=AUVJacobianMatrix(y);
        end

        function [A,B,C,D,U,Y,X,DX] = stepImpl(this,u,Ts,y)
             
            % Lineariser le model dynamique
            [this.Ac, this.Bc, this.Cc, this.Dc]=AUVJacobianMatrix(y);
            
            
             this.Ac(7:12,1:6)*y(1:6)
             %Convertir le modèle dans le domaine echantillione (z)
             nx = size(this.Ac,1);
             nu = size(this.Bc,2);
             M = expm([[this.Ac this.Bc]*Ts; zeros(nu,nu+nx)]);
             A = M(1:nx,1:nx);
             B = M(1:nx,nx+1:nx+nu);
             C = this.Cc;
             D = this.Dc;
             
%              yr =zeros(12,1);
%              yr(1:3) = y(1:3);
%              yr(4:12)= y(5:13);
             yr=y;
             % Calculer les Conditions Nominal
             U=u.';
             Y=(this.Cc*yr + this.Dc*u).';
             X=yr.';
             DX=(A*yr+B*u-yr).';
             
        end

        function resetImpl(obj)
            % Initialize / reset discrete-state properties
        end
    end
end
