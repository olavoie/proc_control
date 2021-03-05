clear; 
avanceRapide =1; % Vitesse Rapide
avancePrecision=.5; % Vtesse Precision
     
accRapide=.3; % acceleration Rapide
accPrecision=.1; % acceleration Precision
 
wpts(1,:)= [0 0 0 0 0 0];
wpts(2,:)= [0 0 1.5 0 0 0];
wpts(3,:)= [.5 0 2 0 0 0];
wpts(4,:)= [8.072 0 2 0 0 0];
wpts(5,:)= [11.921 -1.364 1.696 0 0 -39.23 ];%39.23
wpts(6,:)= [13 -1.75 1.5 (0) 0 0];
wpts(7,:)= [14.217 -1.237 1.278 0 0 (45)];
wpts(8,:)= [14.721 0 1.186 0 0 (90)];
wpts(9,:)= [14.217 1.237 1.278 0 0 (135)];
wpts(10,:)= [13 1.75 1.5 0 0 (180)];
wpts(11,:)= [11.921 1.364 1.696 0 0 (180+39.23)];%180+39.23
wpts(12,:)= [8.072 0 2 0 0 (180)];
wpts(13,:)= [.5 0 2 0 0 (180)];
wpts(14,:)=[0 0 2 0 0 (180)];

% Initialiser les tableaux
linwpts= zeros(3,size(wpts,1)).';
eulwpts= zeros(3,size(wpts,1)).';
quatwpts= zeros(4,size(wpts,1)).';
pwpts = zeros(1,7);

for i=1: 14
    pwpts(i,:) = processWpt(wpts(i,:).')
end

linwpts=pwpts(:,1:3);
% % Convertire les angle d'euler en quaternions
% eulwpts=wpts(:,4:6);
quatwpts = quaternion(eulwpts,'eulerd','XYZ','frame');
% quatwpts=pwpts(:, 1:4);

%tpts = [0,15,20,40,50,55,63,70,78,85,90,100,120,140,230];

% Génération d'un vecteur de temps
tpts = zeros(1,size(wpts,1));

for i = 2: size(tpts, 2)  
    dist = norm(wpts(i,1:3) - wpts(i-1,1:3))
    temp = dist / avancePrecision + 2 * (avancePrecision / accRapide);
    tpts(i) = temp + tpts(i-1);
end

tvec = 0:0.25:tpts(end);
%tpts = [0,20,40,60,80,95,120,130,150,175,200,230,250,275,300];

disp(tpts);
tic;
trajectory = waypointTrajectory(linwpts,tpts,'SampleRate',4,'Orientation',quatwpts);
tInfo = waypointInfo(trajectory);

pose = zeros(7,size(tvec,2));

ones(1, size(tvec,2), 1, 'quaternion');
count=1;
while ~isDone(trajectory)
    count = count+1;
    [bufferPose, bufferQuat] = trajectory();
    pose(1:3,count) = bufferPose;
    pose(4:7,:) = compact(bufferQuat).';
end
toc;


figure(1);
plot(tvec, pose(4:7,:));
figure(2);
plot(tvec, pose(1:3,:));
t=1;

function pwpt = processWpt( wpt)
            % Determiner le quaternion en fonction des angles d'euler.
            % Orde de rotation : ZYX.
            % Reel
            q = zeros(4, 1);
            wpt(3:6) = deg2rad(wpt(3:6));
             q(1) = cos(wpt(6)/2) * cos(wpt(5)/2) * cos(wpt(4)/2)...
                  + sin(wpt(6)/2) * sin(wpt(5)/2) * sin(wpt(4)/2);

            % imaginaire i
             q(2) = sin(wpt(6)/2) * cos(wpt(5)/2) * cos(wpt(4)/2)...
                  - cos(wpt(6)/2) * sin(wpt(5)/2) * sin(wpt(4)/2);

            % imaginaire j
             q(3) = cos(wpt(6)/2) * sin(wpt(5)/2) * cos(wpt(4)/2)...
                  + sin(wpt(6)/2) * cos(wpt(5)/2) * sin(wpt(4)/2);

            % imaginaire k
             q(4) = cos(wpt(6)/2) * cos(wpt(5)/2) * sin(wpt(4)/2)...
                  - sin(wpt(6)/2) * sin(wpt(5)/2) * cos(wpt(4)/2);
              
             pwpt = [wpt(1:3); q];
        end