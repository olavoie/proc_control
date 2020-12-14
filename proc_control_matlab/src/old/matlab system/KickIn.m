classdef KickIn< matlab.System
    %KICKIN Summary of this class goes here
    %   Detailed explanation goes here
    
    properties (Nontunable)
        Aeq=ThrusterMatrix().';
        
    end
      properties (DiscreteState)
        u0;
        
      end
  methods
      function this=KickIn()
         
      end
  
  end
  
      
    methods(Access = protected)
          function setupImpl(this,States)
              %Constructeur
              %retrouver la matrice thruster
              %this.Aeq=ThrusterMatrix().';
              
              % Determiner les options du solveur
              %(sqp tres rapide pour les petit problemes )
              %this.op=optimoptions('fmincon','Algorithm','sqp');
              
              % Determiner la fonction objective
              %this.cf=@(x) this.costFunc(x);
              
             %definire le state (k-1)
              pStates=[0;0;0;0;0;0;0;0;0;0;0;0];
              this.u0=[0,0,0,0,-7.1,6.94,-7.49,7.65];
              %this.u0=this.runOptimisation(pStates);
          end
    
      function kickIn = stepImpl(this,states)
            % Step fonction
            kickIn=this.runOptimisation(states).';
            this.u0=kickIn.';
          end
          
        function resetImpl(this)
            % Initialize / reset discrete-state properties
        end
        
        function kickin = runOptimisation(this,states)
            % Cette fonction optimise la forces des thruster
            % pour la condition initial.
            cf=@(x) this.costFunc(x);
             uu=[0,0,0,0,-7.1,6.94,-7.49,7.65];
            op=optimoptions('fmincon','Algorithm','sqp');
            Beq=Gravity(states).';
            kickin=-fmincon...
                   (cf,uu,[],[],this.Aeq,Beq,[],[],[],op);
        end
    end
    methods(Access = private)
        
        
            
        function cost =costFunc(this,x)
            % Fonction Objective
             cost=abs(this.u0(1)-x(1))+abs(this.u0(2)-x(2))+...
                  abs(this.u0(3)-x(3))+abs(this.u0(4)-x(4))+...
                  abs(this.u0(5)-x(5))+abs(this.u0(6)-x(6))+...
                  abs(this.u0(7)-x(7))+abs(this.u0(8)-x(8));

        end
    end
end

