function out1 = AUVForceMoments(in1,in2)
%AUVFORCEMOMENTS
%    OUT1 = AUVFORCEMOMENTS(IN1,IN2)

%    This function was generated by the Symbolic Math Toolbox version 8.5.
%    09-Nov-2020 19:29:58

U1 = in2(1,:);
U2 = in2(2,:);
U3 = in2(3,:);
U4 = in2(4,:);
U5 = in2(5,:);
U6 = in2(6,:);
U7 = in2(7,:);
U8 = in2(8,:);
phi = in1(4,:);
phidot = in1(10,:);
psidot = in1(12,:);
thetadot = in1(11,:);
theta = in1(5,:);
xdot = in1(7,:);
ydot = in1(8,:);
zdot = in1(9,:);
t2 = cos(phi);
t3 = cos(theta);
t4 = sin(phi);
t5 = sin(theta);
t6 = sqrt(2.0);
t7 = U1.*t6.*(1.1e+1./4.0e+2);
t8 = U2.*t6.*(1.1e+1./4.0e+2);
t9 = U3.*t6.*(1.1e+1./4.0e+2);
t10 = U4.*t6.*(1.1e+1./4.0e+2);
out1 = [t5.*6.870924e+1-psidot.*ydot.*(6.79e+2./2.0e+1)+thetadot.*zdot.*(6.79e+2./2.0e+1)-xdot.*(xdot.^2.*(1.8e+1./2.5e+1)+1.0).*5.988e+1+(t6.*(U1+U2+U3+U4))./2.0;t6.*(U1-U2+U3-U4).*(-1.0./2.0)-t3.*t4.*6.870924e+1+psidot.*xdot.*(6.79e+2./2.0e+1)-phidot.*zdot.*(6.79e+2./2.0e+1)-ydot.*(ydot.^2.*(1.8e+1./2.5e+1)+2.0).*1.0978e+2;U5-U6+U7-U8-t2.*t3.*6.870924e+1+phidot.*ydot.*(6.79e+2./2.0e+1)-thetadot.*xdot.*(6.79e+2./2.0e+1)-zdot.*(zdot.^2.*(1.8e+1./2.5e+1)+3.0).*1.45708e+2;U5.*(8.1e+1./5.0e+2)-U6.*(8.1e+1./5.0e+2)-U7.*(3.9e+1./2.5e+2)+U8.*(3.9e+1./2.5e+2)+t7-t8+t9-t10+psidot.*thetadot.*(2.1e+1./1.0e+2)+t2.*t3.*2.0612772e-1+t3.*t4.*1.85514948-phidot.*(phidot.^2.*(1.8e+1./2.5e+1)+1.0).*1.45708e+2;U5.*(-1.805e-1)-U6.*(7.3e+1./4.0e+2)+U7.*(7.3e+1./4.0e+2)+U8.*1.805e-1+t5.*1.85514948+t7+t8+t9+t10-phidot.*psidot.*1.1442+t2.*t3.*6.870924e-2-thetadot.*(thetadot.^2.*(1.8e+1./2.5e+1)+1.0).*1.45708e+2;t5.*2.0612772e-1-(6.83593446428504e+1.*U2)./2.0e+2+(3.37017803684019e+2.*U4)./1.0e+3+(3.387462176910615e+2.*U3)./1.0e+3-(3.400838131990407e+2.*U1)./1.0e+3+phidot.*thetadot.*9.342e-1-t3.*t4.*6.870924e-2-psidot.*(psidot.^2.*(1.8e+1./2.5e+1)+1.0).*1.0978e+2];
