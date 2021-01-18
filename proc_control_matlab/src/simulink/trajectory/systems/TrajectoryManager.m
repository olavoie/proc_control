classdef TrajectoryManager < matlab.System
    % untitled Add summary here
    %
    % This template includes the minimum set of functions required
    % to define a System object with discrete state.

    % Public, tunable properties
    properties(Nontunable)
     bufferSize=6001; % Taille statique 
    end

    properties(DiscreteState)
    poseBuffer;
    i;
    end

    % Pre-computed constants
    properties(Access = private)
    dummy;
    emptyArray;
    end

    methods(Access = protected)
        function  setupImpl(this, pose, Newpose, InitCond)
            % Perform one-time calculations, such as computing constants
           this.i=0;
           this.dummy=999;% Chiffre NULL
           this.emptyArray= repmat(this.dummy,12,1); % Vecteur pose NULL
           
           % Buffer trajectoire
           this.poseBuffer=repmat(this.dummy,12,this.bufferSize);
           
           % Conditions Initiales
           this.poseBuffer(:,1)=InitCond;
           
%             traj=this.GenerateTrajectory();
%             this.poseBuffer(:,1:size(traj,2))=traj;
        end

        function [position atitude velocity angularRate] = stepImpl(this, pose, newPose,InitCond)
            % Implement algorithm. Calculate y as a function of input u and
                
            if newPose>this.i
                this.poseBuffer(:,1:size(pose,2))=pose;
                this.i=this.i+1;
            end
            
            
                % Retourne la prochaine trajectoire
                position=this.poseBuffer(1:3,1).';
                atitude=this.poseBuffer(4:6,1).';
                velocity=this.poseBuffer(7:9,1).';
                angularRate=this.poseBuffer(10:12,1).';
                
                
            % Ne pas supprimer le point si c'est le dernier.
            if not(this.poseBuffer(:,2)== this.emptyArray)
           
               this.poseBuffer=[this.poseBuffer(:,2:end),this.emptyArray];
               
            end
           
          
        end

        function resetImpl(this)
            % Initialize / reset discrete-state properties
        end

      
        function pose= GenerateTrajectory(this)
            wpts=zeros(15,6);
            wpts(1,:)= [0 0 0 0 0 0];
            wpts(2,:)= [0 0 1.5 0 0 0];
            wpts(3,:)= [.5 0 2 0 0 0];
            wpts(4,:)= [8.072 0 2 0 0 0];
            wpts(5,:)= [11.921 -1.364 1.696 -deg2rad(39.23) 0 0];%39.23
            wpts(6,:)= [13 -1.75 1.5 deg2rad(0) 0 0];
            wpts(7,:)= [14.217 -1.237 1.278 deg2rad(45) 0 0];
            wpts(8,:)= [14.721 0 1.186 deg2rad(90) 0 0];
            wpts(9,:)= [14.217 1.237 1.278 deg2rad(135) 0 0];
            wpts(10,:)= [13 1.75 1.5 deg2rad(180) 0 0];
            wpts(11,:)= [11.921 1.364 1.696  deg2rad(180+39.23) 0 0];%180+39.23
            wpts(12,:)= [8.072 0 2 deg2rad(180) 0 0];
            wpts(13,:)= [.5 0 2 deg2rad(180) 0 0];
            wpts(14,:)=[0 0 2 deg2rad(180) 0 0];
            wpts(15,:)=[0 0 2 deg2rad(180) 0 0];
tic;

            linwpts= zeros(3,size(wpts,1));
            eulwpts= zeros(3,size(wpts,1));
            quatwpts= zeros(4,size(wpts,1));

            for k = 1:size(wpts,1)
                linwpts(1:3,k)=wpts(k,1:3).';
                eulwpts(1,k)=wpts(k,6);
                eulwpts(2,k)=wpts(k,5);
                eulwpts(3,k)=wpts(k,4);
                quatwpts(1:4,k)=eul2quat(wpts(k,4:6));
            end



            vpc =[0,0,.3,.4,.26,.18,.12,0,-.12,-.21,-.26,-.4,-.1,0,0;...

                  0,0,0,0,-0.15,0,.12,.2,.12,0,-0.15,0,0,0,0;...
                  0,.15,.0,0.-0.02,-.02,-.03,-.01,0,-.0,0.03,0.03,0,0,0,0] ;

            vpcr =[0,0,0,0,0,0,0,0,0,0,0,0,0,0,0;...
                   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0;...
                   0,0,0,0,0,.0965,.0965,.0965,.0965,.0965,0,0,0,0,0] ;

            tpts = [0,15,20,40,50,55,63,70,78,85,90,100,120,140,230];
            tvec = 0:0.1:230;
            pose= zeros(12,length(tvec));

            [pose(1:3,:), pose(7:9,:), qdd, pp] = cubicpolytraj(linwpts, tpts, tvec,'VelocityBoundaryCondition',vpc);

            [pose(4:6,:), pose(10:12,:), qdd, pp] = cubicpolytraj(eulwpts, tpts, tvec,'VelocityBoundaryCondition',vpcr);
            toc;
        end
    end
end
