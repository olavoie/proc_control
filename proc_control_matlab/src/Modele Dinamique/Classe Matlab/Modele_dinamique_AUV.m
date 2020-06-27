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

    % Pre-computed constantsGravit
    properties(Access = private)
    W; % force de gravitationelle
    B; % force de flotaison
    g=9.81; % constante gravitationelle
    p=998; % densité du fluide
    C; % config
    end

    methods(Access = protected)
        
        function setupImpl(this)
            % Perform one-time calculations, such as computing constants
            this.C = ConfigAUV8();
            
            this.W= this.C.mass*this.g; % Calcule la  force de gravité
            this.B= this.p*this.C.volume*this.g; % Calcule la force de flotaison
            
        end

        function Force = stepImpl(this,pos,vitesse)
            % Implement algorithm. Calculate y as a function of input u and
            % discrete states.
            G=this.Gravitee(pos);
            
            Force=G;
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
         
        
    end   
end
