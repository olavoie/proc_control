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
    p=998; % densite du fluide
    Cd = 1;
    Af = 10;
    C; % config
    M; % MRB + MA - Matrice de masse et d'inertie.
    T; % matrice thrusters
    end

    methods(Access = protected)
        
        function setupImpl(this)
            % Perform one-time calculations, such as computing constants
            this.C = ConfigAUV8();
            
            this.W = this.C.mass*this.g; % Calcule la  force de gravite
            this.B = this.p*this.C.volume*this.g; % Calcule la force de flotaison
            this.M = this.Masse();
            this.T = this.ThrustersMapping();
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
       
       function D = Drag(this, v)
           % Variables utiles pour le calcul de la matrice de drag.
           X =  (-(1/2) * this.p * this.Cd * this.Af) * v(1);
           Y =  (-(1/2) * this.p * this.Cd * this.Af) * v(2);
           Z =  (-(1/2) * this.p * this.Cd * this.Af) * v(3);
           Kp = (-(1/2) * this.p * this.Cd * this.Af) * v(4);
           Kq = (-(1/2) * this.p * this.Cd * this.Af) * v(5);
           N =  (-(1/2) * this.p * this.Cd * this.Af) * v(6);
           
           % Matrice quadratic damping.
           Dq = diag([X Y Z Kp Kq N]);
           
           % Matrice linear damping.
           Dl = zeros(6,6);
           
           D = Dq + Dl;
       end
        
       function T = ThrustersMapping(this)
            % Calcule la matrice de componsates des thruster sur les 6DDL.
            % Arguments : d14, Matrice Distance x y z  des trusters 1 - 4.
            %             a14, Angles des trusters 1 - 4.
            %             d58, Matrice distance x y z des trusters 5 - 8.
            %             z,   Position des truster sur le frame.
            %             dz,  Distance entre les postions du frame.
         
             % concactener les variables pour avour une matrice lisible.
             a14 =this.C.a14;
             d14 =this.C.d14; %dist centre geo - centre masse
             d58=this.C.d58;  %dist centre geo - centre masse
             cm=this.C.RG;
             
             z=this.C.z;
             dz =this.C.dz;
             % Thruster effort Mapping Matrix (L)
            %       x         y      z      
           l1 = [ sin(a14),-cos(a14), 0,... fxyz
                (d14(3)-cm(3)+z(1)*dz)*cos(a14),... rx
                (d14(3)-cm(3)+z(1)*dz)*sin(a14),... ry
                -hypot( d14(1)-cm(1), d14(2)-cm(2))]; %rz
             
           l2 = [ sin(a14), cos(a14), 0,...fxyz
                 -(d14(3)-cm(3)+z(2)*dz)*cos(a14),...rx
                 (d14(3)-cm(3)+z(2)*dz)*sin(a14),...ry
                 -hypot( d14(1)+cm(1), d14(2)-cm(2))];%rz
             
           l3 = [ sin(a14),-cos(a14), 0,...fxyz
                (d14(3)-cm(3)+z(3)*dz)*cos(a14),...rx
                 (d14(3)-cm(3)+z(3)*dz)*sin(a14),...ry
                 hypot(d14(1)+cm(1), d14(2)+cm(2))];%rz
             
           l4 = [ sin(a14), cos(a14), 0,...fxyz
                -(d14(3)-cm(3)+z(4)*dz)*cos(a14),...rx
                 (d14(3)-cm(3)+z(4)*dz)*sin(a14),...ry
                 hypot(d14(1)-cm(1), d14(2)+cm(2))];%rz
             
            l5 = [0, 0, 1, (d58(2)-cm(2)+z(1)*dz),...
                 -(d58(1)-cm(1)+z(1)*dz), 0];
             
            l6 = [0, 0,-1,-(d58(2)-cm(2)+z(2)*dz),...
                  -(d58(1)+cm(1)+z(2)*dz), 0];
              
            l7 = [0, 0, 1,-(d58(2)+cm(2)+z(3)*dz),...
                (d58(1)+cm(1)+z(3)*dz), 0];
            
            l8 = [0, 0,-1, (d58(2)+cm(2)+z(4)*dz),...
                 (d58(1)-cm(1)+z(2)*dz), 0];

            T = [l1.', l2.', l3.', l4.', l5.' l6.', l7.', l8.'];
        end
    end   
end
