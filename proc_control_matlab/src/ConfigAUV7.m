classdef ConfigAUV7 < Config
    %CONFIGAUV8 class.
    
    methods
        function this = ConfigAUV7()
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
           
           this.I=[1,1,1;... Ixx Ixy Ixz
                   1,1,1;... Iyx Iyy Iyz
                   1,1,1]; % Izx Izy Izz
        end
    end
end

