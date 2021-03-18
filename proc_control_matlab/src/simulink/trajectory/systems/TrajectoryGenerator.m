classdef TrajectoryGenerator < matlab.System
    % untitled Add summary here
    %
    % This template includes the minimum set of functions required
    % to define a System object with discrete state.

    % Public, tunable properties
    properties
        avanceRapide =  [1 1 .3 .1 .1 .1 .1]; % Vitesse Rapide
        avancePrecision = [.3 .3 .1 .05 .05 .05 .05]; % Vtesse Precision

        accRapide = [0.2 0.2 0.1 .02 .02 .02 .02]; % acceleration Rapide
        accPrecision = [0.1 0.1 0.05 .01 .01 .01 .01]; % acceleration Precision
        
        Ts=.25;
    end
    
    % Public, tunable properties
    properties(Nontunable)
     bufferSize=1000; % Taille statique 
    end

    properties(DiscreteState)
        computeCount;
    end

    % Pre-computed constants
    properties(Access = private)

    end

    methods(Access = protected)
        function setupImpl(this,wpts)
            % Perform one-time calculations, such as computing constants
            this.computeCount=0;
        end

        function [pose, new] = stepImpl(this, wpts, wpt_count)
            % Implement algorithm. Calculate y as a function of input u and
            % discrete states.
        
            % Initialiser les tableau
            List = [ wpts(1,:); wpts(:,:)];
            
            
            
            % Remplire les tablau avec le dernier waypoint
            for i=wpt_count:size(List,1)
                List(i,:) = List(wpt_count,:);
            end
            
            linwpts =List(:,1:3);% wpts(1:wpt_count-1,1:3);
            qwpts = List(:,4:7);
            quatwpts = quaternion(qwpts);
            

            % Gestion des vitesses et des accélérations.
 
            % Génération d'un vecteur de temps
            tpts = zeros(size(linwpts, 1),1);
            
            for i = 2: wpt_count
                maxTime= this.Ts;
                for j =1 : 7
                    dist = abs(List(i,j) - List(i-1,j));
                    if dist >0
                        temp = dist / this.avanceRapide(j) + 2 * (this.avanceRapide(j) / this.accRapide(j));
                    else
                        temp=0;
                    end
                    if temp>maxTime
                        maxTime=temp;
                    end
                end
                
                tpts(i) = maxTime + tpts(i-1);
            end
            
            for i=wpt_count+1 : size(tpts,1)
                tpts(i)=tpts(i-1)+this.Ts ;
            end

             linwpts
             tpts
             quatwpts
            
            final=tpts(wpt_count);
            
            nbPoint=floor(final/this.Ts);
            
            trajectory = waypointTrajectory(linwpts, tpts,'SampleRate', 1/this.Ts,'SamplesPerFrame',1, 'Orientation', quatwpts);
            pose=repmat(999,this.bufferSize, 13);
                        
           % while ~isDone(trajectory)
           nbpts=1;
           for i=1 : nbPoint
                    
                   [bufferPose, bufferQuat, bufferVelocity , acc ,bufferAngRate] = trajectory();%, bufferVelocity, bufferAcc, bufferAngRate
                    pose(i, 1:3) = bufferPose;
                    pose(i, 4:7) = compact(bufferQuat);
                    pose(i, 8:10) = bufferVelocity;
                    pose(i, 11:13) = bufferAngRate;
                    nbpts=i;
                  
           end
           
            this.computeCount = this.computeCount + 1;
            new = [this.computeCount,  nbpts];
           
        end
 %% Definire outputs       
%       function [pose, new] = getOutputSizeImpl(this)
%       pose = [1000 13];
%       new = [1 2];
%       end 
%       
%       function [pose, new] = isOutputFixedSizeImpl(this)
%       pose = true;
%       new=true;
%       end
%       function [pose, new] = getOutputDataTypeImpl(this)
%           pose = "double";
%           new = "double";
%       end
%    
%         function resetImpl(this)
%             % Initialize / reset discrete-state properties
%         end
    end
end
