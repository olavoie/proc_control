function out1 = AUVStateFcn(in1,in2)
%AUVSTATEFCN
%    OUT1 = AUVSTATEFCN(IN1,IN2)

%    This function was generated by the Symbolic Math Toolbox version 8.5.
%    29-Jul-2020 10:02:48

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
t2 = cos(theta);
t3 = phidot.^2;
t4 = psidot.^2;
t5 = thetadot.^2;
t6 = xdot.^2;
t7 = ydot.^2;
t8 = zdot.^2;
t9 = sqrt(2.0);
t10 = 6.83593446428504e+1;
t11 = 3.37017803684019e+2;
t12 = 3.387462176910615e+2;
t13 = 3.400838131990407e+2;
out1 = [xdot;ydot;zdot;phidot;thetadot;psidot;U5.*3.337106195345659e-3+U6.*3.448252983374611e-3-U7.*3.4131987930916e-3-U8.*3.37216038562867e-3-t3.*1.606187408099675e-2-t4.*2.056089676181283e-1-t5.*2.723639435848411+t6.*1.794327906105249-t7.*1.211291558103672e-4-t8.*2.771825058091401e-3-sin(theta).*2.831752577319588e-1+U1.*t9.*1.446617585937276e-2+U2.*t9.*1.447113531011994e-2+U2.*t10.*9.364591347154685e-6+U3.*t9.*1.446617585937276e-2+U4.*t9.*1.447113531011994e-2+U1.*t13.*1.872918269430937e-6-U3.*t12.*1.872918269430937e-6-U4.*t11.*1.872918269430937e-6-phidot.*psidot.*2.138790075011497e-2+phidot.*thetadot.*1.749680247302381e-3+psidot.*thetadot.*2.314899358312047e-5+psidot.*xdot.*3.745978174314053e-5+phidot.*ydot.*6.458359233686762e-4+psidot.*ydot.*1.017325190585725-phidot.*zdot.*3.745978174314053e-5-thetadot.*xdot.*6.458359233686762e-4-thetadot.*zdot.*1.017325190585725;U5.*8.714736481307841e-3-U6.*8.728763259695206e-3-U7.*8.080278455313034e-3+U8.*8.094305233700398e-3+t3.*7.701924057265474-t4.*3.395810281733368e-2+t5.*5.630341116435517e-3-t6.*6.905843394102123e-6+t7.*3.390288876814897+t8.*2.311140251291286e-2-U1.*t9.*1.398666948994022e-2+U2.*t9.*1.398867943134686e-2+U2.*t10.*1.546643414890402e-6-U3.*t9.*1.398666948994022e-2+U4.*t9.*1.398867943134686e-2+U1.*t13.*3.093286829780805e-7-U3.*t12.*3.093286829780805e-7-U4.*t11.*3.093286829780805e-7+phidot.*psidot.*4.421333286727921e-5+phidot.*thetadot.*2.889748556381228e-4-psidot.*thetadot.*1.110031056651488e-2-psidot.*xdot.*1.048463357331625-phidot.*ydot.*5.384962495630929e-3-psidot.*ydot.*3.915387161485756e-6+phidot.*zdot.*1.048463357331625+thetadot.*xdot.*5.384962495630929e-3+thetadot.*zdot.*3.915387161485756e-6+t2.*sin(phi).*2.831752577319588e-1;U5.*3.029978852919786e-2-U6.*3.055265665934165e-2+U7.*2.868368705433025e-2-U8.*2.843081892418646e-2+t3.*8.563642239213858e-1+t4.*3.842024413560268e-3+t5.*1.01501128118434e-1-t6.*1.132532343231214e-3+t7.*1.741671787316532e-2+t8.*4.294511536362475+U1.*t9.*9.199917310192881e-5-U2.*t9.*7.259918583526364e-5-U2.*t10.*1.749874482401288e-7+U3.*t9.*9.199917310192881e-5-U4.*t9.*7.259918583526364e-5-U1.*t13.*3.499748964802576e-8+U3.*t12.*3.499748964802576e-8+U4.*t11.*3.499748964802576e-8+phidot.*psidot.*7.970570647672891e-4-phidot.*thetadot.*3.269465482918566e-5-psidot.*thetadot.*1.234225210856583e-3-psidot.*xdot.*5.386204880615435e-3-phidot.*ydot.*1.000622249015195-psidot.*ydot.*6.42108768415159e-4+phidot.*zdot.*5.386204880615435e-3+thetadot.*xdot.*1.000622249015195+thetadot.*zdot.*6.42108768415159e-4+t2.*cos(phi).*2.831752577319588e-1;U5.*3.228115304015488e-1-U6.*3.233740773202024e-1-U7.*2.993078984880629e-1+U8.*2.998704454067165e-1+t3.*2.853136645631155e+2+t4.*1.163268853519008+t5.*2.258060232043226e-1-t6.*4.409049738822529e-3+t7.*5.802820181505748+t8.*8.561667997125507e-1+U1.*t9.*2.742477155121692e-2-U2.*t9.*2.741316859476679e-2-U2.*t10.*5.298182061937546e-5+U3.*t9.*2.742477155121692e-2-U4.*t9.*2.741316859476679e-2-U1.*t13.*1.059636412387509e-5+U3.*t12.*1.059636412387509e-5+U4.*t11.*1.059636412387509e-5+phidot.*psidot.*1.773185080780643e-3-phidot.*thetadot.*9.899123364524111e-3-psidot.*thetadot.*4.112050783639488e-1-psidot.*xdot.*1.794550420496631-phidot.*ydot.*1.994870758657115e-1-psidot.*ydot.*2.499786884319052e-3+phidot.*zdot.*1.794550420496631+thetadot.*xdot.*1.994870758657115e-1+thetadot.*zdot.*2.499786884319052e-3;U5.*(-1.237270634795404e-1)-U6.*1.274534259082903e-1+U7.*1.265297483216888e-1+U8.*1.246507410661419e-1+t3.*4.232302320394074e-1+t4.*3.522178530032449e-1+t5.*1.00823710048821e+2-t6.*1.119305194014747+t7.*8.257328648072372e-3+t8.*1.020934007449392e-1+U1.*t9.*9.724858448278036e-3+U2.*t9.*9.640319949036723e-3-U2.*t10.*1.604198638200241e-5+U3.*t9.*9.724858448278036e-3+U4.*t9.*9.640319949036723e-3-U1.*t13.*3.208397276400482e-6+U3.*t12.*3.208397276400482e-6+U4.*t11.*3.208397276400482e-6+phidot.*psidot.*7.917375095249471e-1-phidot.*thetadot.*2.997284735613331e-3-psidot.*thetadot.*6.099757647368405e-4-psidot.*xdot.*2.553619125542513e-3-phidot.*ydot.*2.378778759773442e-2-psidot.*ydot.*6.346094077622018e-1+phidot.*zdot.*2.553619125542513e-3+thetadot.*xdot.*2.378778759773442e-2+thetadot.*zdot.*6.346094077622018e-1;U5.*1.174839533977042e-3-U6.*2.336827950258052e-3-U7.*1.034803864665434e-3+U8.*2.196792280946444e-3+t3.*1.544885938644249+t4.*6.536636186234688e+1+t5.*4.66421510081194e-1-t6.*1.121384995541062e-1-t7.*3.393957256252894e-2+t8.*5.101079326013941e-3-U1.*t9.*4.021789132976702e-4-U2.*t9.*1.294482669185968e-3-U2.*t10.*2.97715257161354e-3-U3.*t9.*4.021789132976702e-4-U4.*t9.*1.294482669185968e-3-U1.*t13.*5.95430514322708e-4+U3.*t12.*5.95430514322708e-4+U4.*t11.*5.95430514322708e-4+phidot.*psidot.*3.662664313798159e-3-phidot.*thetadot.*5.562511864802738e-1-psidot.*thetadot.*2.226549311741924e-3+psidot.*xdot.*1.049597821550244e-2-phidot.*ydot.*1.188552743282272e-3-psidot.*ydot.*6.357885871512866e-2-phidot.*zdot.*1.049597821550244e-2+thetadot.*xdot.*1.188552743282272e-3+thetadot.*zdot.*6.357885871512866e-2];