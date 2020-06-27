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
    end
    methods
        function this = ConfigAUV8()
            % Constructor
            this.z = [0, ...
                      0, ...
                      0, ...
                      0];
                  
            this.dz = 0.015;
            
            this.d14 = [.0292, ...
                        0.173, ...   
                        0.082];
            this.a14 = deg2rad(45);
            
            this.d58 = [0.1815, ...
                        0.159, ...   
                        0.082];
                    
            this.psl = 0.5;
            this.nbt= 8;
            
            this.RG =[0.01,...x
                      0.02,...y
                      0.01];% z
                  
            this.RB =[0.01,...x
                      0.02,...y
                      0.01];% Z
                  
           this.mass =48.1;
           this.volume =0.055;
           
           this.I=[2,1,1;... Ixx Ixy Ixz
                   1,2,1;... Iyx Iyy Iyz
                   1,1,2]; % Izx Izy Izz
        end
    end
end

