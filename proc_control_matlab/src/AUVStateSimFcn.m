function out1 = AUVStateSimFcn(in1,in2)
%AUVSTATESIMFCN
%    OUT1 = AUVSTATESIMFCN(IN1,IN2)

%    This function was generated by the Symbolic Math Toolbox version 8.5.
%    09-Nov-2020 19:57:11

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
t7 = U1.*t6.*8.100147275405007e-4;
t8 = U2.*t6.*8.100147275405007e-4;
t9 = U3.*t6.*8.100147275405007e-4;
t10 = U4.*t6.*8.100147275405007e-4;
out1 = [xdot;ydot;zdot;phidot;thetadot;psidot;t5.*2.023836229749632-psidot.*ydot+thetadot.*zdot-xdot.*(xdot.^2.*(1.8e+1./2.5e+1)+1.0).*1.763770250368189+t6.*(U1+U2+U3+U4).*(1.0e+1./6.79e+2);t6.*(U1-U2+U3-U4).*(-1.0e+1./6.79e+2)-t3.*t4.*2.023836229749632+psidot.*xdot-phidot.*zdot-ydot.*(ydot.^2.*(1.8e+1./2.5e+1)+2.0).*3.233578792341679;U5.*(2.0e+1./6.79e+2)-U6.*(2.0e+1./6.79e+2)+U7.*(2.0e+1./6.79e+2)-U8.*(2.0e+1./6.79e+2)-t2.*t3.*2.023836229749632+phidot.*ydot-thetadot.*xdot-zdot.*(zdot.^2.*(1.8e+1./2.5e+1)+3.0).*4.291840942562592;U5.*4.771723122238586e-3-U6.*4.771723122238586e-3-U7.*4.59499263622975e-3+U8.*4.59499263622975e-3+t7-t8+t9-t10+psidot.*thetadot.*(3.0./4.85e+2)+t2.*t3.*6.071508689248895e-3+t3.*t4.*5.464357820324006e-2-phidot.*(phidot.^2.*(1.8e+1./2.5e+1)+1.0).*4.291840942562592;U5.*(-5.316642120765832e-3)-U6.*5.375552282768778e-3+U7.*5.375552282768778e-3+U8.*5.316642120765832e-3+t5.*5.464357820324006e-2+t7+t8+t9+t10-phidot.*psidot.*3.370250368188513e-2+t2.*t3.*2.023836229749632e-3-thetadot.*(thetadot.^2.*(1.8e+1./2.5e+1)+1.0).*4.291840942562592;t5.*6.071508689248895e-3-(6.83593446428504e+1.*U2)./6.79e+3+(3.37017803684019e+2.*U4)./3.395e+4+(3.387462176910615e+2.*U3)./3.395e+4-(3.400838131990407e+2.*U1)./3.395e+4+phidot.*thetadot.*2.751693667157585e-2-t3.*t4.*2.023836229749632e-3-psidot.*(psidot.^2.*(1.8e+1./2.5e+1)+1.0).*3.233578792341679];