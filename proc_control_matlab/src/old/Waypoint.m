classdef Waypoint
% Classe Waypoint
% Cette classe définit un Waypoint
%==========================================================================
%Proprietes
%==========================================================================
    properties
        x
        y
        z
        roll
        pitch
        yaw
        frame
        zoneData
    end
%==========================================================================
%Methodes
%==========================================================================    
    methods
        % Constructeur
        function this = Waypoint(x, y, z, roll, pitch, yaw, frame, zoneData)
            this.x = x;
            this.y = y;
            this.z = z;
            this.roll = roll;
            this.pitch = pitch;
            this.yaw = yaw;
            this.frame = frame;
            this.zoneData = zoneData;
        end
    end
end
