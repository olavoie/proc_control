classdef Config
    %CONFIG class.
    
%==========================================================================
%Proprietes
%==========================================================================
    properties
        z        %Position des truster sur le frame.
                 %(0 = milieu, 1= position bas, -1= postion haut)(t15,t26,t37,t48)
        dz       % Distance entre les postions du frame.
        d14      % Distance x y z / angles des trusters 1 - 4. 
        a14      
        d58      % Distance x y z des trusters 5 - 8.
        psl      % Power supply limitation
        nbt      % nombre de thrusters
        CM       % Centre de masse
    end
%==========================================================================
%Methodes
%==========================================================================
    % Constructor
    % Argument: filename: nom du fichier de configuration
    methods
        function this = Config(filename)
            % Lecture des informations du fichier.
            folder = pwd;
            absoluteFileName = fullfile(folder, '../config/', filename);
            cf = json_decode(fileread(absoluteFileName));
            disp(cf);
            this.z = [cf.z_frame_pos.t15, ...
                      cf.z_frame_pos.t26, ...
                      cf.z_frame_pos.t37, ...
                      cf.z_frame_pos.t48];
            this.dz = cf.dist_btw_frame_positions;
            this.d14 = [cf.dist_t1_t4.x, ...
                        cf.dist_t1_t4.y, ...   
                        cf.dist_t1_t4.z];
            this.a14 = deg2rad(cf.angle_t1_t4);
            this.d58 = [cf.dist_t5_t8.x, ...
                        cf.dist_t5_t8.y, ...   
                        cf.dist_t5_t8.z];
            this.psl = cf.ps_limitation;
            this.nbt= cf.nb_thrusters;
            this.CM =[cf.centre_masse.x,...
                      cf.centre_masse.y,...
                      cf.centre_masse.z];
        end
    end
end

