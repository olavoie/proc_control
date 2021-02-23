function [Av,Bv,Cc,Dc] = AUVEulJacobianMatrix(in1)
%AUVEULJACOBIANMATRIX
%    [AV,BV,CC,DC] = AUVEULJACOBIANMATRIX(IN1)

%    This function was generated by the Symbolic Math Toolbox version 8.5.
%    22-Feb-2021 14:34:13

N_04 = in1(4,:);
N_05 = in1(5,:);
N_06 = in1(6,:);
V_01 = in1(7,:);
V_02 = in1(8,:);
V_03 = in1(9,:);
V_04 = in1(10,:);
V_05 = in1(11,:);
V_06 = in1(12,:);
t2 = cos(N_04);
t3 = cos(N_05);
t4 = cos(N_06);
t5 = abs(V_01);
t6 = abs(V_02);
t7 = abs(V_03);
t8 = abs(V_04);
t9 = abs(V_05);
t10 = abs(V_06);
t11 = sin(N_04);
t12 = sin(N_05);
t13 = sin(N_06);
t14 = sign(V_01);
t15 = sign(V_02);
t16 = sign(V_03);
t17 = sign(V_04);
t18 = sign(V_05);
t19 = sign(V_06);
Av = reshape([0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,t2.*t3.*5.195591690934148e-4+t3.*t11.*2.584057119337349e-3,t2.*t3.*1.217506277507737-t3.*t11.*8.444024679086305e-3,t2.*t3.*3.971166239063146e-2-t3.*t11.*8.60962060385934e-1,t2.*t3.*1.323941706364617e+1-t3.*t11.*3.127114459993834e-1,t2.*t3.*(-6.588800307054823e-3)-t3.*t11.*9.579644557948922e-2,t2.*t3.*(-1.138871869343115e-1)+t3.*t11.*8.156371029532025e-4,0.0,0.0,0.0,0.0,0.0,0.0,t3.*(-1.18966206126548)+t2.*t12.*2.584057119337349e-3-t11.*t12.*5.195591690934148e-4,t3.*(-3.433094721821777e-4)-t2.*t12.*8.444024679086305e-3-t11.*t12.*1.217506277507737,t3.*1.217422234246582e-2-t2.*t12.*8.60962060385934e-1-t11.*t12.*3.971166239063146e-2,t3.*(-3.897549016825921e-3)-t2.*t12.*3.127114459993834e-1-t11.*t12.*1.323941706364617e+1,t3.*1.21859149895163e+1-t2.*t12.*9.579644557948922e-2+t11.*t12.*6.588800307054823e-3,t3.*2.380756487278779e-1+t2.*t12.*8.156371029532025e-4+t11.*t12.*1.138871869343115e-1,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,t3.*t4,t3.*t13,-t12,0.0,0.0,0.0,t5.*(-2.077280001430589)-V_01.*t14.*2.077280001430589-1.334258261028846,-V_06-t5.*5.446367846604962e-5-V_01.*t14.*5.446367846604962e-5-3.498257956043473e-5,V_05+t5.*5.002006468300261e-4+V_01.*t14.*5.002006468300261e-4+3.212840082922422e-4,t5.*(-2.770948039492404e-4)-V_01.*t14.*2.770948039492404e-4-1.77980835998433e-4,t5.*5.010319312418738e-1+V_01.*t14.*5.010319312418738e-1+3.218179508002375e-1,t5.*4.698211875942013e-2+V_01.*t14.*4.698211875942013e-2+3.017709698847704e-2,-t2.*t13+t4.*t11.*t12,t2.*t4+t11.*t12.*t13,t3.*t11,0.0,0.0,0.0,V_06-t6.*7.498296877553198e-5-V_02.*t15.*7.498296877553198e-5-4.997776180445058e-5,t6.*(-2.670443407038389)-V_02.*t15.*2.670443407038389-1.779907980287664,-V_04-t6.*2.098200332809708e-3-V_02.*t15.*2.098200332809708e-3-1.398495660595942e-3,t6.*(-6.995129874210119e-1)-V_02.*t15.*6.995129874210119e-1-4.662404548038507e-1,t6.*3.386294533276535e-4+V_02.*t15.*3.386294533276535e-4+2.257038156097029e-4,t6.*2.194665784522845e-2+V_02.*t15.*2.194665784522845e-2+1.462791959432953e-2,t11.*t13+t2.*t4.*t12,-t4.*t11+t2.*t12.*t13,t2.*t3,0.0,0.0,0.0,-V_05+t7.*7.857891522825007e-4+V_03.*t16.*7.857891522825007e-4+4.993428970336034e-4,V_04-t7.*2.567753996139708e-3-V_03.*t16.*2.567753996139708e-3-1.631722346354116e-3,t7.*(-3.244946161878827)-V_03.*t16.*3.244946161878827-2.062055466767393,t7.*(-9.509281363095557e-2)-V_03.*t16.*9.509281363095557e-2-6.042832343463917e-2,t7.*(-2.913086061460094e-2)-V_03.*t16.*2.913086061460094e-2-1.851169399593259e-2,t7.*2.480281039082092e-4+V_03.*t16.*2.480281039082092e-4+1.576136188588549e-4,0.0,0.0,0.0,1.0,0.0,0.0,V_04.*1.271002953413202e-4+V_05.*2.854478435915099e-3-V_06.*2.038802967430741e-2-t8.*1.463197964321609e-4-V_04.*t17.*1.463197964321609e-4-6.013166371795388e-5,V_03-V_04.*6.000993915809703e-3-V_05.*1.002476739431943e-3-V_06.*1.664610602507794e-5-t8.*1.890856493868756e-1-V_04.*t17.*1.890856493868756e-1-7.770674208184869e-2,-V_02+V_04.*5.399518214656406e-2+V_05.*5.114494288484089e-6-V_06.*1.246737357176586e-3-t8.*2.100409734682202e-2-V_04.*t17.*2.100409734682202e-2-8.631855354882523e-3,V_04.*(-1.731636835812652e-6)+V_05.*2.40289851856519e-3-V_06.*5.473752471437526e-4-t8.*7.002535976731401-V_04.*t17.*7.002535976731401-2.877766022049595,V_04.*(-4.812658525434416e-3)-V_05.*2.094201267211482e-3-V_06.*2.45095231435155e-1+t8.*3.510583372183968e-3+V_04.*t17.*3.510583372183968e-3+1.442711266263134e-3,V_04.*9.471616151363497e-4+V_05.*6.735499943320363e-2+V_06.*1.866974352196623e-3+t8.*1.717801512773126e-2+V_04.*t17.*1.717801512773126e-2+7.059486509616421e-3,0.0,0.0,0.0,0.0,1.0,0.0,-V_03+V_04.*2.854478435915099e-3+V_05.*2.001571020574449e-3+V_06.*1.973041560800998e-6+t9.*1.042032139922423e-1+V_05.*t18.*1.042032139922423e-1+5.006056619716804e-2,V_04.*(-1.002476739431943e-3)+V_05.*1.209819345597601e-4-V_06.*2.213679548389513e-2+t9.*2.481976848084498e-5+V_05.*t18.*2.481976848084498e-5+1.192373647060661e-5,V_01+V_04.*5.114494288484089e-6+V_05.*5.40133842512261e-2+V_06.*3.540282981731623e-3-t9.*3.856620543955547e-3-V_05.*t18.*3.856620543955547e-3-1.852770184731712e-3,V_04.*2.40289851856519e-3+V_05.*4.462064340502543e-3+V_06.*1.800267179242618e-1+t9.*9.914447749243671e-4+V_05.*t18.*9.914447749243671e-4+4.763028402332452e-4,V_04.*(-2.094201267211482e-3)-V_05.*1.941795402760582e-6+V_06.*2.028279588377874e-4-t9.*3.85959487828032-V_05.*t18.*3.85959487828032-1.854199093252412,V_04.*6.735499943320363e-2-V_05.*5.061973661914209e-4-V_06.*2.483132149807086e-3+t9.*1.949240442112933e-3+V_05.*t18.*1.949240442112933e-3+9.364402156910076e-4,0.0,0.0,0.0,0.0,0.0,1.0,V_02-V_04.*2.038802967430741e-2+V_05.*1.973041560800998e-6+V_06.*1.869987469674826e-3+t10.*7.509164411087042e-3+V_06.*t19.*7.509164411087042e-3+1.005910807053551e-2,-V_01-V_04.*1.664610602507794e-5-V_05.*2.213679548389513e-2-V_06.*6.12047561815135e-3+t10.*2.729961775974938e-3+V_06.*t19.*2.729961775974938e-3+3.656995509702477e-3,V_04.*(-1.246737357176586e-3)+V_05.*3.540282981731623e-3-V_06.*8.570900893662134e-6+t10.*2.521188580880639e-5+V_06.*t19.*2.521188580880639e-5+3.377327624340444e-5,V_04.*(-5.473752471437526e-4)+V_05.*1.800267179242618e-1-V_06.*4.461744678060605e-3+t10.*7.905333996935925e-3+V_06.*t19.*7.905333996935925e-3+1.058980795405775e-2,V_04.*(-2.45095231435155e-1)+V_05.*2.028279588377874e-4+V_06.*4.814333140519679e-3+t10.*1.495883817998616e-3+V_06.*t19.*1.495883817998616e-3+2.0038523812312e-3,V_04.*1.866974352196623e-3-V_05.*2.483132149807086e-3+V_06.*8.511843714126953e-6-t10.*2.516517758057668-V_06.*t19.*2.516517758057668-3.371070694942918],[12,12]);
if nargout > 1
    t20 = sqrt(2.0);
    t21 = 6.83593446428504e+1;
    t22 = 3.37017803684019e+2;
    t23 = 3.387462176910615e+2;
    t24 = 3.400838131990407e+2;
    t25 = t20.*2.364942078743729e-4;
    t26 = t20.*1.579238941804852e-5;
    t28 = t20.*4.414656919769748e-4;
    t29 = t20.*4.028413062156026e-3;
    t30 = t20.*8.374554023872988e-6;
    t31 = t20.*4.028625812385904e-3;
    t35 = t20.*3.706511980890804e-3;
    t36 = t20.*3.710685162595089e-3;
    t37 = t20.*1.461853110959408e-2;
    t38 = t20.*1.461921481375014e-2;
    t39 = t20.*1.462817415987595e-2;
    t40 = t20.*1.462867639842224e-2;
    t27 = -t25;
    t32 = -t28;
    t33 = -t29;
    t34 = -t30;
    t41 = -t37;
    Bv = reshape([0.0,0.0,0.0,0.0,0.0,0.0,t24.*6.706072047023674e-7+t39,t24.*2.437997006468318e-7+t41,t24.*2.251551749560296e-9+t26,t24.*7.059871969371832e-7+t31,t24.*1.335901587487467e-7+t35,t24.*(-2.247380463295279e-4)+t27,0.0,0.0,0.0,0.0,0.0,0.0,t21.*3.353036023511837e-6+t40,t21.*1.218998503234159e-6+t38,t21.*1.125775874780148e-8+t34,t21.*3.529935984685916e-6+t33,t21.*6.679507937437335e-7+t36,t21.*(-1.123690231647639e-3)+t32,0.0,0.0,0.0,0.0,0.0,0.0,t23.*(-6.706072047023674e-7)+t39,t23.*(-2.437997006468318e-7)+t41,t23.*(-2.251551749560296e-9)+t26,t23.*(-7.059871969371832e-7)+t31,t23.*(-1.335901587487467e-7)+t35,t23.*2.247380463295279e-4+t27,0.0,0.0,0.0,0.0,0.0,0.0,t22.*(-6.706072047023674e-7)+t40,t22.*(-2.437997006468318e-7)+t38,t22.*(-2.251551749560296e-9)+t34,t22.*(-7.059871969371832e-7)+t33,t22.*(-1.335901587487467e-7)+t36,t22.*2.247380463295279e-4+t32,0.0,0.0,0.0,0.0,0.0,0.0,1.28468811993587e-3,1.282467003021428e-3,2.95499962936627e-2,4.749535312950716e-2,-4.757076719858019e-2,-9.246852473488011e-5,0.0,0.0,0.0,0.0,0.0,0.0,1.31130981286013e-3,-1.281848672115881e-3,-2.964607566181378e-2,-4.747065342507792e-2,-4.858270006579488e-2,1.410296387771424e-4,0.0,0.0,0.0,0.0,0.0,0.0,-1.313221999766361e-3,-1.189225726086907e-3,2.937158266152852e-2,-4.404230607609921e-2,4.862857828406205e-2,8.346203222865983e-5,0.0,0.0,0.0,0.0,0.0,0.0,-1.282775933029639e-3,1.18860739518136e-3,-2.927550329337743e-2,4.401760637166997e-2,4.752488898031302e-2,-1.320231462709221e-4],[12,8]);
end
if nargout > 2
    Cc = reshape([1.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,1.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,1.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,1.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,1.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,1.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,1.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,1.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,1.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,1.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,1.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,1.0],[12,12]);
end
if nargout > 3
    Dc = reshape([0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0],[12,8]);
end
