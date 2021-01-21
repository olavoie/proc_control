% wpt(1,:)= [0 0 0 -deg2rad(0) 0 0];%39.23
% wpt(2,:)= [0 0 0 deg2rad(180) 0 0];%39.23
% wpt(2,:)= [0 0 0 deg2rad(180) 0 0];%39.23
% tpts=[0, 15];
% tvec = 0:0.1:15;
% quatwpts= zeros(4,size(wpt,1));
% quatwpt(1:4,1)=eul2quat(wpt(1,4:6));
% quatwpt(1:4,2)=eul2quat(wpt(2,4:6));
% [Rr,omega] = rottraj(quatwpt(:,1).',quatwpt(:,2).',tpts(:),tvec);
% % fun = @(x)abs(x(1))+abs(x(2))+abs(x(3))+abs(x(4))+abs(x(5))+abs(x(6))+abs(x(7))+abs(x(8));
% % x0 =[0,0,0,0,-16,16,-16,16].';
% % Ae=ThrusterMatrix().';
% % Be=Gravity([0,0,0,0,0,0,0,0,0,0,0,0].').';
% % op=optimoptions('fmincon','Algorithm','sqp');
% % tic;
% % r=fmincon(fun,x0,[],[],Ae,Be,[],[],[],op)
% % x0=r;
% % toc;
% % % clc;
% % % subpose= zeros(12,length(tvec));
% % % for k=2:size(pose,2)
% % %     d = pose(1:3,k)-pose(1:3,k-1);
% % %     q = eul2quat(pose(4:6,k-1).',"XYZ");
% % %     p = quatrotate(q,d.');
% % %     
% % %     subpose(1:3,k)=subpose(1:3,k-1)+p.';
% % %     subpose(4:6,k)=pose(4:6,k);
% % % end
% % % plot(tvec(), subpose(1:3,:))


% % %  d=[-1;0;0];
% % %     q = eul2quat([0,0,deg2rad(90)],"XYZ");
% % %     qrotm=quat2rotm(q);
% % %     b=quatrotate(q,d.')
% % %     H=[qrotm,d;0,0,0,1];       
% % %     hp=inv(H)
% % %     
% % %     hpp=[inv(qrotm),quatrotate(q,d.').';0,0,0,1]
% % %     
% % %     a=inv(H)*[1;0;0;1];
% % % %inv(t)*[0;0;1;1]
% % % % clc;
% % % % qq=zeros(1,4);
% % % %  
% % % %  roll=pi/4;
% % % %  pitch=pi/4;
% % % %  yaw=0;
% % % %  
% % % %  qq(1) = cos(roll/2) * cos(pitch/2) * cos(yaw/2) + sin(roll/2) * sin(pitch/2) * sin(yaw/2);
% % % %  qq(2) = sin(roll/2) * cos(pitch/2) * cos(yaw/2) - cos(roll/2) * sin(pitch/2) * sin(yaw/2);
% % % %  qq(3) = cos(roll/2) * sin(pitch/2) * cos(yaw/2) + sin(roll/2) * cos(pitch/2) * sin(yaw/2);
% % % %  qq(4) = cos(roll/2) * cos(pitch/2) * sin(yaw/2) - sin(roll/2) * sin(pitch/2) * cos(yaw/2);
% % % %  
% % % %     
% % % %  q = eul2quat([yaw,pitch,roll],"ZYX");  
% % % %  disp(qq);
% % % %  disp(q);
% % % %  
% % % %  
% % % %  s=qq(1);
% % % %  u=-qq(2:4);
% % % %  v=[0,0,-20];
% % % %  
% % % %  qp=2*dot(u,v)*u +(s^2-dot(u,u))*v + 2*s*cross(u,v);
% % % % disp(qp);
% % % %  %test= q*qUnit*qCong
% % % %  quatrotate(q,v)
% % % %  
 
syms x;
v=0.027;
dz=0.3;

a= v/2;
k=a;
b=4/dz;
h=dz/2;
ezplot(a*erf(b*(x-h))+k, [-.5, .5]);


test=@(x)a*erf(b*(x-h))+k;
test(.2)
