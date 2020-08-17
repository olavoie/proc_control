classdef ConfigAUV8
    %CONFIGAUV8 class.
    properties
        z        %Position des truster sur le frame.
                 %(0 = milieu, 1= position bas, -1= postion haut)(t15,t26,t37,t48)
        dz       % Distance entre les postions du frame.
        d14      % Distance x y z / angles des trusters 1 - 4. 
        a14      
        d58      % Distance x y z des trusters 5 - 8.
        psl      % Power supply limitation
        nbt      % nombre de thrusters
        RG       % Centre de masse
        RB       % Centre de flotaison
        I        % Inertie
        mass
        volume
        rho
        g
        CD       % Coefficient de drag
        AF       % Aire de la surface
    end
    methods
        function this = ConfigAUV8()
            % Constructor
            this.z = [0, ...
                      0, ...
                      0, ...
                      0];
                  
            this.dz = 0.015;
            
            this.d14 = [0.292, ...
                        0.173, ...   
                        0.082];
            this.a14 = deg2rad(45);
            
            this.d58 = [0.1815, ...
                        0.159, ...   
                        0.082];
                    
            this.psl = 0.5;
            this.nbt = 8;
            
            this.RG =[0.001,... x
                     -0.003,... y
                      0.027]; % z
                  
            this.RB =[0.001,... x
                     -0.003,... y
                      0.027]; % z
                  
           this.mass = 33.95;
           this.volume = 0.027;
           
           this.I = [0.5358, 0.001, 0.01;... Ixx Ixy Ixz 0.5358
                     0.002, 1.47, 0.005;... Iyx Iyy Iyz
                     0.01, 0.005, 1.68]; % Izx Izy Izz
           this.rho = 998;
           this.g = 9.81;
           this.CD = [1, 1, 1, 1, 1, 1];
           this.AF = [0.12, 0.22, 0.292];
        end
    end
end

