clear; 
Ts = 0.25
avanceRapide =  [1 1 .3 .1 .1 .1 .1]; % Vitesse Rapide
avancePrecision = [.3 .3 .1 .05 .05 .05 .05]; % Vtesse Precision

accRapide = [0.2 0.2 0.1 .02 .02 .02 .02]; % acceleration Rapide
accPrecision = [0.1 0.1 0.05 .01 .01 .01 .01]; % acceleration Precision
wpt_count = 15
wpts = [0,0,0,1,0,0,0,0;0,0,1.50000000000000,1,0,0,0,1;0.500000000000000,0,2,1,0,0,0,1;8.07200000000000,0,2,1,0,0,0,1;11.9210000000000,-1.36400000000000,1.69600000000000,0.941969599488903,0,0,-0.335698188316105,1;13,-1.75000000000000,1.50000000000000,1,0,0,0,1;14.2170000000000,-1.23700000000000,1.27800000000000,0.923879532511287,0,0,0.382683432365090,1;14.7210000000000,0,1.18600000000000,0.707106781186548,0,0,0.707106781186548,1;14.2170000000000,1.23700000000000,1.27800000000000,0.382683432365090,0,0,0.923879532511287,1;13,1.75000000000000,1.50000000000000,6.12323399573677e-17,0,0,1,1;11.9210000000000,1.36400000000000,1.69600000000000,-0.335698188316105,0,0,0.941969599488903,1;8.07200000000000,0,2,6.12323399573677e-17,0,0,1,1;0.500000000000000,0,2,6.12323399573677e-17,0,0,1,1;0,0,2,6.12323399573677e-17,0,0,1,1]

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
vpts = zeros(wpt_count, 7);

for i = 2: wpt_count
    maxTime= Ts;
    distances = zeros(1, 7);
    for j =1 : 7
        % Calcul de la distance pour chacun des axes.
        dist = List(i,j) - List(i-1,j);
        absDist = abs(dist);
        distances(j) = dist;
        if absDist > 0
            % Calcul du temps en fonction de la vitesse
            % d'avance et de l'accélération.
            temp = absDist / avanceRapide(j) + 2 * (avanceRapide(j) / accRapide(j));
            
            % Calcul de la vitesse pour chacun des axes.
            % vpts(i, j) = dist / temp;
        else
            temp=0;
        end
        if temp>maxTime
            maxTime=temp;
        end
    end
    tpts(i) = maxTime + tpts(i-1);

    % Calcul de la vitesse pour chacun des axes en fonction du temps maximum.
    for k =1 : 3
        vpts(i, k) = distances(k) / maxTime;
    end
end

for i=wpt_count+1 : size(tpts,1)
    tpts(i)=tpts(i-1)+Ts ;
end

tvec = 0:0.25:tpts(end);
tpts
vpts

[q, qd, qdd, pp] = cubicpolytraj(linwpts.', tpts, tvec,'VelocityBoundaryCondition',vpts(:,1:3).');

plot(tvec, q)
