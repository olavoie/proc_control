classdef TrajectoryManager < matlab.System
    % untitled Add summary here
    %
    % This template includes the minimum set of functions required
    % to define a System object with discrete state.

    % Public, tunable properties
    properties(Nontunable)
     SampleTime=.25;
     OffsetTime = 0; % Offset Time
 
     bufferSize=6001; % Taille statique 
     SampleTimeTypeProp (1, 1) {mustBeMember(SampleTimeTypeProp, ...
            ["Discrete","FixedInMinorStep","Controllable",...
            "Inherited","InheritedNotControllable",...
            "InheritedErrorConstant"])} = "Discrete"
    end
    
    properties(DiscreteState)
  
    poseBuffer;
    i;
    Ts
    bufferCount;
    pMax;
    end

    % Pre-computed constants
    properties(Access = private)
    dummy;
    emptyArray;
    end

    methods(Access = protected)
        function  setupImpl(this, pose, isNew, InitCond)
            % Perform one-time calculations, such as computing constants
           this.i=0;
           this.dummy=999;% Chiffre NULL
           this.emptyArray= repmat(this.dummy, 1, 13); % Vecteur pose NULL
           
           % Buffer trajectoire
           this.poseBuffer=repmat(this.dummy, this.bufferSize, 13);
           this.bufferCount = 1;
           
           % Conditions Initiales
           this.poseBuffer(1,:)=InitCond;
        end

        function [ref] = stepImpl(this, pose, isNew, InitCond)
            % Implement algorithm. Calculate y as a function of input u and
            new = isNew(1);
            count = isNew(2);
            
            in_pose = zeros(this.bufferSize, 13);
            in_pose = pose;
            
            % Insertion des nouveaux points.
            if new > this.i
                if count + this.bufferCount < this.bufferSize
                   this.poseBuffer(this.bufferCount:count + this.bufferCount,:) = in_pose(1:count+1,:);
                   this.bufferCount = count + this.bufferCount;
                   this.i=this.i+1; 
                else
                    disp("Problem");
                end    
            end

            % Vérification des prédictions.
            index = 2;
            for i = 2 : 10
                if this.poseBuffer(i,:) == this.emptyArray
                     index = i;
                     break;
                end
            end
            
            ref = zeros(10, 13);
            
            ref(1:index-1,:) = this.poseBuffer(1:index-1,:);
            
            for i = index: 10
                ref(i,:) = ref(index - 1,:);
            end   
                
            % Ne pas supprimer le point si c'est le dernier.
            if not(this.poseBuffer(2,:) == this.emptyArray)
               this.poseBuffer=[this.poseBuffer(2:end,:); this.emptyArray];
               this.bufferCount = this.bufferCount - 1;
            end 
        end

        function resetImpl(this)
            % Initialize / reset discrete-state properties
        end
        function sts = getSampleTimeImpl(obj)
            switch char(obj.SampleTimeTypeProp)
                case 'Inherited'
                    sts = createSampleTime(obj,'Type','Inherited');
                case 'InheritedNotControllable'
                    sts = createSampleTime(obj,'Type','Inherited',...
                        'AlternatePropagation','Controllable');
                case 'InheritedErrorConstant'
                    sts = createSampleTime(obj,'Type','Inherited',...
                        'ErrorOnPropagation','Constant');
                case 'FixedInMinorStep'
                    sts = createSampleTime(obj,'Type','Fixed In Minor Step');
                case 'Discrete'
                    sts = createSampleTime(obj,'Type','Discrete',...
                      'SampleTime',obj.SampleTime, ...
                      'OffsetTime',obj.OffsetTime);
              
            end
        end
    end
    
end
