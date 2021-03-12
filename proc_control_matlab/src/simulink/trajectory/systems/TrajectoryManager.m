classdef TrajectoryManager < matlab.System
    % untitled Add summary here
    %
    % This template includes the minimum set of functions required
    % to define a System object with discrete state.

    % Public, tunable properties
    properties(Nontunable)
     SampleTime=.25;
     OffsetTime = 0; % Offset Time
     prediction =4;  % prediction controlleur
     bufferSize=6001; % Taille statique 
    
     SampleTimeTypeProp (1, 1) {mustBeMember(SampleTimeTypeProp, ...
            ["Discrete","FixedInMinorStep","Controllable",...
            "Inherited","InheritedNotControllable",...
            "InheritedErrorConstant"])} = "Discrete"
    end
    
    properties 
     linearConvergence= .2;    % Metre
     quaternionConvergence=.1; % Radian
     TargetThreshold = 3;      % seconde
    end
    
    properties(DiscreteState)
  
    poseBuffer;
    generationNumber;
    bufferCount;
    pMax;
    done;
    targetReachedCount;
    end

    % Pre-computed constants
    properties(Access = private)
    dummy;
    emptyArray;
    end

    methods(Access = protected)
        function  setupImpl(this, pose, isNew, InitCond)
            
            % Perform one-time calculations, such as computing constants
           this.generationNumber=0;
           this.dummy=999;% Chiffre NULL
           this.emptyArray= repmat(this.dummy, 1, 13); % Vecteur pose NULL
           this.targetReachedCount=0;
           % Buffer trajectoire
           this.poseBuffer=repmat(this.dummy, this.bufferSize, 13);
           this.bufferCount =1;
           this.done=false;
           
           % Conditions Initiales
           this.poseBuffer(1,:)=[0,0,0,1,0,0,0,0,0,0,0,0,0];%InitCond;
           
           
        end
%% Main execute a chaque iteration.
        function [currentPose, isReached] = stepImpl(this,mesuredPose, poses, isNew, InitCond)
            % Implement algorithm. Calculate y as a function of input u and
            new = isNew(1);
            count = isNew(2);
            mp =zeros(1,7);
            mp=mesuredPose
            this.processNewPoses(poses,count,new);
            
            currentPose=this.SendCurrentPoses();
            
            isReached= this.targetReached(mp);
           
        end

%% Fonction reset
        function resetImpl(this)
            % Initialize / reset discrete-state properties
        end
      
        
%% Fonction qui traites les nouveau poses.
        function processNewPoses(this,pose,count,new)
           % Insertion des nouveaux points.
            if new > this.generationNumber
                
                if count + this.bufferCount < this.bufferSize
                   this.poseBuffer(this.bufferCount:count + this.bufferCount,:) = pose(1:count+1,:);
                   this.bufferCount = count + this.bufferCount;
                   this.generationNumber = this.generationNumber+1; 
                else
                    disp("Problem");
                end    
            end  
        end
%% Fonction qui retourne la pose actuelle
    function currPose = SendCurrentPoses(this)
         % Vérification des prédictions.
            index = 2;
            isempty =false;
            
            for i = 2 : this.prediction
                index = i;
                if this.poseBuffer(i,:) == this.emptyArray
                    isempty =true;
                     break;
                end
            end
            
            currPose = zeros(this.prediction, 13);
            
            currPose(1:index,:) = this.poseBuffer(1:index,:);
            
            if isempty
                for i = index: this.prediction
                    currPose(i,:) = currPose(index - 1,:);
                end  
            end
                
            % Ne pas supprimer le point si c'est le dernier.
            if not(this.poseBuffer(2,:) == this.emptyArray)
               this.poseBuffer=[this.poseBuffer(2:end,:); this.emptyArray];
               this.bufferCount = this.bufferCount - 1;
               this.done=false;
            else
                this.done=true;
            end 
    end
%% Fonction qui verifi le target reached

function isReached= targetReached(this, mesuredPose)
    
    isReached = false;
    
    % vérifier le traget reached si la trajectoire est terminé
    if this.done
        
         % calcule de l'erreur de langle en 3D avec le quaternion
         qRel = quatmultiply(quatconj(this.poseBuffer(1,4:7)),mesuredPose(4:7));
         errAngle = 2 * atan2(norm(qRel(2:4)),qRel(1));
        
        % vérifier si le sub est dans la zone de convergence (sphérique / conique)
        if norm(this.poseBuffer(1,1:3) - mesuredPose(1:3)) < this.linearConvergence ...
           &&  errAngle < this.quaternionConvergence
       
           this.targetReachedCount = this.targetReachedCount+1;
           
           if this.targetReachedCount * this.SampleTime >= this.TargetThreshold
                isReached = true;    
           end
            
       end    
           
           
    else
        this.targetReachedCount = 0;
  
    end
end
 %% Fonction qui gere le sample time  
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
