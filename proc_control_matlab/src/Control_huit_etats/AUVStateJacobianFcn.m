function [A,B,C,D] = AUVStateJacobianFcn(in1,in2)
%AUVSTATEJACOBIANFCN
%    [A,B,C,D] = AUVSTATEJACOBIANFCN(IN1,IN2)

%    This function was generated by the Symbolic Math Toolbox version 8.6.
%    27-Jul-2020 12:12:29

phi = in1(1,:);
phidot = in1(6,:);
psidot = in1(8,:);
theta = in1(2,:);
thetadot = in1(7,:);
xdot = in1(3,:);
ydot = in1(4,:);
zdot = in1(5,:);
t2 = cos(phi);
t3 = cos(theta);
t4 = sin(phi);
t5 = sin(theta);
A = reshape([0.0,0.0,0.0,t2.*t3.*(-2.831752577319588e-1),t3.*t4.*2.831752577319588e-1,0.0,0.0,0.0,0.0,0.0,t3.*2.831752577319588e-1,t4.*t5.*2.831752577319588e-1,t2.*t5.*2.831752577319588e-1,0.0,0.0,0.0,0.0,0.0,psidot.*3.745978174314053e-5-thetadot.*6.458359233686762e-4-xdot.*3.588655812210498,psidot.*(-1.048463357331625)+thetadot.*5.384962495630929e-3+xdot.*1.381168678820425e-5,psidot.*(-5.386204880615435e-3)+thetadot.*1.000622249015195+xdot.*2.265064686462428e-3,psidot.*(-1.794550420496631)+thetadot.*1.994870758657115e-1+xdot.*8.818099477645057e-3,psidot.*(-2.553619125542513e-3)+thetadot.*2.378778759773442e-2+xdot.*2.238610388029493,psidot.*1.049597821550244e-2+thetadot.*1.188552743282272e-3+xdot.*2.242769991082123e-1,0.0,0.0,phidot.*6.458359233686762e-4+psidot.*1.017325190585725+ydot.*2.422583116207345e-4,phidot.*(-5.384962495630929e-3)-psidot.*3.915387161485756e-6-ydot.*6.780577753629793,phidot.*(-1.000622249015195)-psidot.*6.42108768415159e-4-ydot.*3.483343574633063e-2,phidot.*(-1.994870758657115e-1)-psidot.*2.499786884319052e-3-ydot.*1.16056403630115e+1,phidot.*(-2.378778759773442e-2)-psidot.*6.346094077622018e-1-ydot.*1.651465729614474e-2,phidot.*(-1.188552743282272e-3)-psidot.*6.357885871512866e-2+ydot.*6.787914512505788e-2,0.0,0.0,phidot.*(-3.745978174314053e-5)-thetadot.*1.017325190585725+zdot.*5.543650116182802e-3,phidot.*1.048463357331625+thetadot.*3.915387161485756e-6-zdot.*4.622280502582571e-2,phidot.*5.386204880615435e-3+thetadot.*6.42108768415159e-4-zdot.*8.589023072724949,phidot.*1.794550420496631+thetadot.*2.499786884319052e-3-zdot.*1.712333599425101,phidot.*2.553619125542513e-3+thetadot.*6.346094077622018e-1-zdot.*2.041868014898785e-1,phidot.*(-1.049597821550244e-2)+thetadot.*6.357885871512866e-2-zdot.*1.020215865202788e-2,1.0,0.0,phidot.*3.21237481619935e-2-psidot.*2.138790075011497e-2+thetadot.*1.749680247302381e-3+ydot.*6.458359233686762e-4-zdot.*3.745978174314053e-5,phidot.*(-1.540384811453095e+1)+psidot.*4.421333286727921e-5+thetadot.*2.889748556381228e-4-ydot.*5.384962495630929e-3+zdot.*1.048463357331625,phidot.*(-1.712728447842772)+psidot.*7.970570647672891e-4-thetadot.*3.269465482918566e-5-ydot.*1.000622249015195+zdot.*5.386204880615435e-3,phidot.*(-5.706273291262309e+2)+psidot.*1.773185080780643e-3-thetadot.*9.899123364524111e-3-ydot.*1.994870758657115e-1+zdot.*1.794550420496631,phidot.*(-8.464604640788148e-1)+psidot.*7.917375095249471e-1-thetadot.*2.997284735613331e-3-ydot.*2.378778759773442e-2+zdot.*2.553619125542513e-3,phidot.*(-3.089771877288498)+psidot.*3.662664313798159e-3-thetadot.*5.562511864802738e-1-ydot.*1.188552743282272e-3-zdot.*1.049597821550244e-2,0.0,1.0,phidot.*1.749680247302381e-3+psidot.*2.314899358312047e-5+thetadot.*5.447278871696822-xdot.*6.458359233686762e-4-zdot.*1.017325190585725,phidot.*2.889748556381228e-4-psidot.*1.110031056651488e-2-thetadot.*1.126068223287103e-2+xdot.*5.384962495630929e-3+zdot.*3.915387161485756e-6,phidot.*(-3.269465482918566e-5)-psidot.*1.234225210856583e-3-thetadot.*2.03002256236868e-1+xdot.*1.000622249015195+zdot.*6.42108768415159e-4,phidot.*(-9.899123364524111e-3)-psidot.*4.112050783639488e-1-thetadot.*4.516120464086453e-1+xdot.*1.994870758657115e-1+zdot.*2.499786884319052e-3,phidot.*(-2.997284735613331e-3)-psidot.*6.099757647368405e-4-thetadot.*2.01647420097642e+2+xdot.*2.378778759773442e-2+zdot.*6.346094077622018e-1,phidot.*(-5.562511864802738e-1)-psidot.*2.226549311741924e-3-thetadot.*9.32843020162388e-1+xdot.*1.188552743282272e-3+zdot.*6.357885871512866e-2,0.0,0.0,phidot.*(-2.138790075011497e-2)+psidot.*4.112179352362565e-1+thetadot.*2.314899358312047e-5+xdot.*3.745978174314053e-5+ydot.*1.017325190585725,phidot.*4.421333286727921e-5+psidot.*6.791620563466735e-2-thetadot.*1.110031056651488e-2-xdot.*1.048463357331625-ydot.*3.915387161485756e-6,phidot.*7.970570647672891e-4-psidot.*7.684048827120535e-3-thetadot.*1.234225210856583e-3-xdot.*5.386204880615435e-3-ydot.*6.42108768415159e-4,phidot.*1.773185080780643e-3-psidot.*2.326537707038015-thetadot.*4.112050783639488e-1-xdot.*1.794550420496631-ydot.*2.499786884319052e-3,phidot.*7.917375095249471e-1-psidot.*7.044357060064899e-1-thetadot.*6.099757647368405e-4-xdot.*2.553619125542513e-3-ydot.*6.346094077622018e-1,phidot.*3.662664313798159e-3-psidot.*1.307327237246938e+2-thetadot.*2.226549311741924e-3+xdot.*1.049597821550244e-2-ydot.*6.357885871512866e-2],[8,8]);
if nargout > 1
    t6 = sqrt(2.0);
    t7 = 6.83593446428504e+1;
    t8 = 3.37017803684019e+2;
    t9 = 3.387462176910615e+2;
    t10 = 3.400838131990407e+2;
    t11 = t6.*7.259918583526364e-5;
    t12 = t6.*9.199917310192881e-5;
    t14 = t6.*2.741316859476679e-2;
    t15 = t6.*1.294482669185968e-3;
    t16 = t6.*4.021789132976702e-4;
    t17 = t6.*2.742477155121692e-2;
    t19 = t6.*1.398867943134686e-2;
    t20 = t6.*9.724858448278036e-3;
    t23 = t6.*9.640319949036723e-3;
    t24 = t6.*1.447113531011994e-2;
    t25 = t6.*1.446617585937276e-2;
    t26 = t6.*1.398666948994022e-2;
    t13 = -t11;
    t18 = -t14;
    t21 = -t15;
    t22 = -t16;
    t27 = -t26;
    B = reshape([0.0,0.0,t10.*1.872918269430937e-6+t25,t10.*3.093286829780805e-7+t27,t10.*(-3.499748964802576e-8)+t12,t10.*(-1.059636412387509e-5)+t17,t10.*(-3.208397276400482e-6)+t20,t10.*(-5.95430514322708e-4)+t22,0.0,0.0,t7.*9.364591347154685e-6+t24,t7.*1.546643414890402e-6+t19,t7.*(-1.749874482401288e-7)+t13,t7.*(-5.298182061937546e-5)+t18,t7.*(-1.604198638200241e-5)+t23,t7.*(-2.97715257161354e-3)+t21,0.0,0.0,t9.*(-1.872918269430937e-6)+t25,t9.*(-3.093286829780805e-7)+t27,t9.*3.499748964802576e-8+t12,t9.*1.059636412387509e-5+t17,t9.*3.208397276400482e-6+t20,t9.*5.95430514322708e-4+t22,0.0,0.0,t8.*(-1.872918269430937e-6)+t24,t8.*(-3.093286829780805e-7)+t19,t8.*3.499748964802576e-8+t13,t8.*1.059636412387509e-5+t18,t8.*3.208397276400482e-6+t23,t8.*5.95430514322708e-4+t21,0.0,0.0,3.337106195345659e-3,8.714736481307841e-3,3.029978852919786e-2,3.228115304015488e-1,-1.237270634795404e-1,1.174839533977042e-3,0.0,0.0,3.448252983374611e-3,-8.728763259695206e-3,-3.055265665934165e-2,-3.233740773202024e-1,-1.274534259082903e-1,-2.336827950258052e-3,0.0,0.0,-3.4131987930916e-3,-8.080278455313034e-3,2.868368705433025e-2,-2.993078984880629e-1,1.265297483216888e-1,-1.034803864665434e-3,0.0,0.0,-3.37216038562867e-3,8.094305233700398e-3,-2.843081892418646e-2,2.998704454067165e-1,1.246507410661419e-1,2.196792280946444e-3],[8,8]);
end
if nargout > 2
    C = reshape([0.0,0.0,0.0,1.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,1.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,1.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,1.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,1.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,1.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,1.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,1.0],[12,8]);
end
if nargout > 3
    D = reshape([0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0],[12,8]);
end
