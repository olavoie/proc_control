classdef Modele_dinamique_AUV < matlab.System & handle
    % Untitled2 Add summary here
    %
    % This template includes the minimum set of functions required
    % to define a System object with discrete state.

    % Public, tunable properties
    properties
     
    end

    properties(DiscreteState)
   
    end

    % Pre-computed constants
    properties(Access = private)
    W; % force de gravitationelle
    B; % force de flotaison
    g=9.81; % constante gravitationelle
    p=998; % densitÃ© du fluide
    C; % config
    M; % MRB + MA - Matrice de masse et d'inertie.
    end

    methods(Access = protected)
        
        function setupImpl(this)
            % Perform one-time calculations, such as computing constants
            this.C = ConfigAUV8();
            
            this.W = this.C.mass*this.g; % Calcule la  force de gravite
            this.B = this.p*this.C.volume*this.g; % Calcule la force de flotaison
            this.M = this.Masse();
        end

        function Force = stepImpl(this,pos,vitesse,acc)
            % Implement algorithm. Calculate y as a function of input u and
            % discrete states.
            G=this.Gravitee(pos);
            MI = this.M;
            Co = this.Coriolis(vitesse);
            Force = G + MI * acc + Co * vitesse;
        end

        function resetImpl(this)
            % Initialize / reset discrete-state properties
        end
    end
    
    methods(Access = private)
       function G=Gravitee(this,pos)
            c=this.C;
            w=this.W;
            b=this.B;
            
            
            X  =  (w-b)*sin(pos(5));...
            Y  =  (w-b)*cos(pos(5))*sin(pos(4));...
            Z  =  (w-b)*cos(pos(5))*cos(pos(4));...
            
            Rx = -(c.RG(2)*w-c.RB(2)*b)*cos(pos(5))*cos(pos(4))+...
                  (c.RG(3)*w-c.RB(3)*b)*cos(pos(5))*sin(pos(4));
              
            Ry =  (c.RG(3)*w-c.RB(3)*b)*sin(pos(5))+...
                  (c.RG(1)*w-c.RB(1)*b)*cos(pos(5))*cos(pos(4));
              
            Rz =  (c.RG(1)*w-c.RB(1)*b)*cos(pos(5))*sin(pos(4))-...
                  (c.RG(2)*w-c.RB(2)*b)*sin(pos(5));
 
            G  = [X;Y;Z;Rx;Ry;Rz];
        end   
        
        function M = Masse(this)
            % Variables utiles pour le calcul de la matrice des masses 
            % du corp rigide.
            m = this.C.mass;
            xg = this.C.RG(1);
            yg = this.C.RG(2);
            zg = this.C.RG(3);

            % Definition des quatres matrices 3x3 pour former la matrice
            % des masses du corp rigide.
            Mrb1 = diag(repmat(this.C.mass,1,3));
            Mrb2 = [0, m * zg, -m * yg; ...
                    -m * zg, 0, m * xg; ...
                    m * yg, -m * xg, 0];
            Mrb3 = [0, -m * zg, m * yg; ...
                    m * zg, 0, -m * xg; ...
                    -m * yg, m * xg, 0];

            forme= (diag(repmat(2,1,3))-1); % diag 1 avec -1 partout
            Mrb4 = this.C.I.*forme;


            % Matrice des masses du corps rigide.
            MRB = [Mrb1, Mrb2; ... 
                   Mrb3, Mrb4];

            % Matrice des masses ajoutees.
            MA=zeros(6,6);

            % Calcul de la matrice des masses et inerties.
            M = MRB + MA;
        end
        
        function C = Coriolis(this, v)
            % Variables utiles pour la matrice.
            m = this.C.mass;
            i = this.C.I;
            
            % Définition des matrices 3x3 pour former la matrice de
            % Coriolis (corps rigide).
            crb1 = zeros(3,3);
            crb23 = [0, m*v(3), -m*v(2); ...
                     -m*v(3), 0, m*v(1); ...
                     m*v(2), -m*v(1), 0];
            crb4 = [0, i(3,3)*v(6), -i(2,2)*v(5); ...
                    -i(3,3)*v(6), 0, i(1,1)*v(4); ...
                    i(2,2)*v(5), -i(1,1)*v(4), 0];
            % Matrice de Coriolis(Corps rigide)
            CRB = [crb1, crb23; ...
                   crb23, crb4];
            
            % Matrice de Coriolis (masse ajoutée)
            CA = zeros(6,6);
            
            % Matrice de Coriolis
            C = CRB + CA;
        end
    end   
end
