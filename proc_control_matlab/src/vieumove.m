clc;
v = [0.5 0.5 1 0 0 0.1];
x=diag(repmat(2,1,3))-1

C= ConfigAUV8

 m = C.mass;
 i = C.I;
            xg = C.RG(1);
            yg = C.RG(2);
            zg = C.RG(3);
            
            % Definition des quatres matrices 6x6 pour former la matrice
            % des masses du corp rigide.
            Mrb1 = diag(repmat(C.mass,1,3));
            Mrb2 = [0, m * zg, -m * yg; ...
                    -m * zg, 0, m * xg; ...
                    m * yg, -m * xg, 0];
            Mrb3 = [0, -m * zg, m * yg; ...
                    m * zg, 0, -m * xg; ...
                    -m * yg, m * xg, 0];
                
            forme= (diag(repmat(2,1,3))-1); %diag 1 avec -1 partout
            Mrb4 = (C.I.*forme);
            
            
            % Matrice des masses du corps rigide.
            MRB = [Mrb1, Mrb2; ... 
                   Mrb3, Mrb4];
               
            % Matrice des masses ajout�es.
            MA=zeros(6,6);
            
            % Calcul de la matrice des masses et inerties.
            M = MRB + MA
            
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
            C = CRB + CA