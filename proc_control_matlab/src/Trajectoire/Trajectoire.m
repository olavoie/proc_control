classdef Trajectoire
    % Classe de faire la gestion d'une trajectoire.
    %% Propriétés.
    properties
        wpts            % Waypoints de l'utilisateur [x y z r p y]. 
        linwpts         % Waypoints des positions [x y z].
        quatwpts        % Waypoints des quaternions [w x y z].
        
        tpts            % Temps pour chaque waypoints. [sec]
        tvec            % Vecteur de temps.
        
        pose            % Matrice de poses 
        
    end
    
    methods
        %% Ctor
        function this = Trajectoire(wpts)
            
            %Trajectoire
            %   Initialise les paramètres de la trajectoire.
            this.wpts = wpts;           
            this.linwpts= zeros(3,size(this.wpts,1));
            this.quatwpts= zeros(4,size(this.wpts,1));
            
            for k = 1:size(wpts,1)
                this.linwpts(1:3,k)=wpts(k,1:3).';
                this.quatwpts(1:4,k)=eul2quat(wpts(k,4:6));
            end
            
            generatePoses();
        end
        
        %% Méthodes
        function outputArg = initSpeeds(this,inputArg)
            % Retourne le vecteur des vitesses pour chaque waypoints.
            outputArg = this.Property1 + inputArg;
        end
        
        function outputArg = initTimes(this,inputArg)
            % Retourne le vecteur des temps pour chaque waypoints.
            outputArg = this.Property1 + inputArg;
        end
        
        function outputArg = generatePoses(this,inputArg)
            
            outputArg = this.Property1 + inputArg;
        end
    end
end

