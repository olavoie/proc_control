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



linwpts= zeros(3,size(wpts,1));
quatwpts= zeros(4,size(wpts,1));

for k = 1:size(wpts,1)
    linwpts(1:3,k)=wpts(k,1:3).';
    quatwpts(1:4,k)=eul2quat(wpts(k,4:6));
end



vpc =[0,0,.3,.4,.26,.18,.12,0,-.12,-.21,-.26,-.4,-.1,0;...
      0,0,0,0,-0.15,0,.12,.2,.12,0,-0.15,0,0,0;...
      0,.15,.0,0.-0.02,-.02,-.03,-.01,0,-.0,0.03,0.03,0,0,0] ;
         
tpts = [0,15,20,40,50,55,63,70,78,85,90,100,120,140];
tvec = 0:0.1:140;
pose= zeros(7,length(tvec));

[pose(1:3,:), qd, qdd, pp] = cubicpolytraj(linwpts, tpts, tvec,'VelocityBoundaryCondition',vpc);
 
 count=1;
for k=1:size(wpts,1)-1
    
    tvectemp=tpts(k):0.1:tpts(k+1);
    [R,omega] = rottraj(quatwpts(:,k).',quatwpts(:,k+1).',tpts(k:k+1),tvectemp);
    pose(4:7,count:count+size(R,2)-1)= R;
    count= count+size(R,2)-1;
end

subpose= zeros(7,length(tvec));
for k=1:size(pose,2)
    subpose(1:3,k)=quatrotate(pose(4:7,k).',qd(1:3,k).').';
    subpose(4:7,k)=pose(4:7,k);
    
end
Q=zeros(3,length(tvec));
Q(1,:) = cumtrapz(tvec,subpose(1,:));
Q(2,:) = cumtrapz(tvec,subpose(2,:));
Q(3,:) = cumtrapz(tvec,subpose(3,:));
subpose(1:3,:)=Q;

display= pose(:,1:3:end);
eul= quat2eul(pose(4:7,:).');
plot(tvec, subpose(1:3,:))
hold all
plot(tpts, linwpts, 'x')
xlabel('t')
ylabel('Positions')
legend('X-positions','Y-positions')
hold off


test=plotTransforms(display(1:3,:).',display(4:7,:).')
test.YLim=[-9 9];
xlabel('X')
ylabel('Y')
zlabel('Z')