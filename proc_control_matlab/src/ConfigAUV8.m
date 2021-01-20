classdef ConfigAUV8
    %CONFIGAUV8 class.
    properties
        z               %Position des truster sur le frame.
                        %(0 = milieu, 1= position bas, -1= postion haut)(t15,t26,t37,t48)
                        
        dz              % Distance entre les postions du frame.
        d14             % Distance x y z / angles des trusters 1 - 4. 
        a14      
        d58             % Distance x y z des trusters 5 - 8.
        psl             % Power supply limitation
        nbt             % nombre de thrusters
        RG              % Centre de masse
        RB              % Centre de flotaison
        dvlCenterDist   % Distance entre le dvl et le centre geometrique(z)
        I               % Inertie
        mass            % Masse du sous marin
        volume          % Volume du sous marin
        rho             % Densite de l'eau
        g               % Masse du sous marin
        CD
        height          % hauteur sous marin
        AF              % Aire de la surface
        referenceFrame  % Constante du frame pour Gazebo 
        modelName       % Nom du model Gazebo.
    end
    methods
        function this = ConfigAUV8()
            % Constructor
            this.z = [0, ...
                      0, ...
                      0, ...
                      0];
                  
            this.referenceFrame = uint8('world');
            this.modelName = uint8('auv8');
                  
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
           this.volume = 0.037;
           
           this.I = [0.5358, 0.001, 0.01;... Ixx Ixy Ixz 0.5358
                     0.002, 1.47, 0.005;... Iyx Iyy Iyz
                     0.01, 0.005, 1.68]; % Izx Izy Izz
           this.rho = 998;
           this.g = 9.81;
           
           this.CD={@(vx) 0.72*vx^2+1,...
                    @(vy) 0.72*vy^2+2,...
                    @(vz) 0.72*vz^2+3,...
                    @(rx) 0.72*rx^2+1,...
                    @(ry) 0.72*ry^2+1,...
                    @(rz) 0.72*rz^2+1};
           
           this.height=.3;
           
           this.AF = [0.12, 0.22, 0.292];
        end
    end
end

