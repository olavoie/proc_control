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
wpts(15,:)=[0 0 2 0 0 (180)];

% Initialiser les tableaux
linwpts= zeros(3,size(wpts,1)).';
eulwpts= zeros(3,size(wpts,1)).';
quatwpts= zeros(4,size(wpts,1)).';

tvec = 0:0.1:300;

linwpts=wpts(:,1:3);
% Convertire les angle d'euler en quaternions
eulwpts=wpts(:,4:6);
quatwpts=quaternion(eulwpts,'eulerd','XYZ','frame');

%tpts = [0,15,20,40,50,55,63,70,78,85,90,100,120,140,230];

% Génération d'un vecteur de temps
tpts = zeros(1,size(wpts,1));

for i = 2: size(tpts, 2) - 1 
    dist = norm(wpts(i,1:3) - wpts(i-1,1:3));
    temp = dist / avancePrecision;
    tpts(i) = temp + tpts(i-1);
end

%tpts = [0,20,40,60,80,95,120,130,150,175,200,230,250,275,300];

disp(tpts);
tic;
trajectory = waypointTrajectory(linwpts,tpts,'SampleRate',10,'Orientation',quatwpts);
tInfo = waypointInfo(trajectory);

pose =zeros(7,size(tvec,2));
count=1;
while ~isDone(trajectory)
    tic;
   [pose(1:3,count), quat(count)] = trajectory();
   toc;

   count = count+1;
end
toc;

plot(tvec,pose);

t=1;