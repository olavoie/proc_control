% wpt(1,:)= [0 0 0 -deg2rad(0) 0 0];%39.23
% wpt(2,:)= [0 0 0 deg2rad(180) 0 0];%39.23
% wpt(2,:)= [0 0 0 deg2rad(180) 0 0];%39.23
% tpts=[0, 15];
% tvec = 0:0.1:15;
% quatwpts= zeros(4,size(wpt,1));
% quatwpt(1:4,1)=eul2quat(wpt(1,4:6));
% quatwpt(1:4,2)=eul2quat(wpt(2,4:6));
% [Rr,omega] = rottraj(quatwpt(:,1).',quatwpt(:,2).',tpts(:),tvec);
fun = @(x)abs(x(1))+abs(x(2))+abs(x(3))+abs(x(4))+abs(x(5))+abs(x(6))+abs(x(7))+abs(x(8));
x0 =[0,0,0,0,-16,16,-16,16].';
Ae=ThrusterMatrix().';
Be=Gravity([0,0,0,0,0,0,0,0,0,0,0,0].').';
op=optimoptions('fmincon','Algorithm','sqp');
tic;
r=fmincon(fun,x0,[],[],Ae,Be,[],[],[],op)
x0=r;
toc;