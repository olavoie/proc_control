clc;

x=diag(repmat(2,1,3))-1

C= ConfigAUV8

 m = C.mass;
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