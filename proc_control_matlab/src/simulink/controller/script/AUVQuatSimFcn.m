function out1 = AUVQuatSimFcn(in1,in2)
%AUVQUATSIMFCN
%    OUT1 = AUVQUATSIMFCN(IN1,IN2)

%    This function was generated by the Symbolic Math Toolbox version 8.5.
%    22-Feb-2021 14:34:11

U1 = in2(1,:);
U2 = in2(2,:);
U3 = in2(3,:);
U4 = in2(4,:);
U5 = in2(5,:);
U6 = in2(6,:);
U7 = in2(7,:);
U8 = in2(8,:);
epsilon1 = in1(5,:);
epsilon2 = in1(6,:);
epsilon3 = in1(7,:);
eta = in1(4,:);
p = in1(11,:);
q = in1(12,:);
r = in1(13,:);
u = in1(8,:);
v = in1(9,:);
w = in1(10,:);
t2 = abs(p);
t3 = abs(q);
t4 = abs(r);
t5 = abs(u);
t6 = abs(v);
t7 = abs(w);
t8 = epsilon1.^2;
t9 = epsilon2.^2;
t10 = epsilon3.^2;
t11 = p.^2;
t12 = q.^2;
t13 = r.^2;
t14 = epsilon1.*epsilon2.*2.0;
t15 = epsilon1.*epsilon3.*2.0;
t16 = epsilon2.*epsilon3.*2.0;
t17 = epsilon1.*eta.*2.0;
t18 = epsilon2.*eta.*2.0;
t19 = epsilon3.*eta.*2.0;
t23 = sqrt(2.0);
t24 = 6.83593446428504e+1;
t25 = 3.37017803684019e+2;
t26 = 3.387462176910615e+2;
t27 = 3.400838131990407e+2;
t20 = t8.*2.0;
t21 = t9.*2.0;
t22 = t10.*2.0;
out1 = [-u.*(t21+t22-1.0)+w.*(t15+t18)+v.*(t14-t19);u.*(t14+t19)-v.*(t20+t22-1.0)+w.*(t16-t17);v.*(t16+t17)-w.*(t20+t21-1.0)+u.*(t15-t18);epsilon1.*p.*(-1.0./2.0)-(epsilon2.*q)./2.0-(epsilon3.*r)./2.0;(eta.*p)./2.0-(epsilon3.*q)./2.0+(epsilon2.*r)./2.0;(epsilon3.*p)./2.0+(eta.*q)./2.0-(epsilon1.*r)./2.0;epsilon2.*p.*(-1.0./2.0)+(epsilon1.*q)./2.0+(eta.*r)./2.0;U5.*1.28468811993587e-3+U6.*1.31130981286013e-3-U7.*1.313221999766361e-3-U8.*1.282775933029639e-3-p.*6.013166371795388e-5+q.*5.006056619716804e-2+r.*1.005910807053551e-2-t8.*5.168114238674699e-3-t9.*5.168114238674699e-3+t11.*6.355014767066009e-5+t12.*1.000785510287224e-3+t13.*9.349937348374131e-4-u.*1.334258261028846-v.*4.997776180445058e-5+w.*4.993428970336034e-4+U1.*t23.*1.462817415987595e-2+U2.*t23.*1.462867639842224e-2+U2.*t24.*3.353036023511837e-6+U3.*t23.*1.462817415987595e-2+U4.*t23.*1.462867639842224e-2+U1.*t27.*6.706072047023674e-7-U3.*t26.*6.706072047023674e-7-U4.*t25.*6.706072047023674e-7-epsilon1.*epsilon3.*2.37932412253096-epsilon2.*epsilon3.*1.03911833818683e-3-epsilon1.*eta.*1.03911833818683e-3+epsilon2.*eta.*2.37932412253096+p.*q.*2.854478435915099e-3-p.*r.*2.038802967430741e-2+q.*r.*1.973041560800998e-6-p.*t2.*1.463197964321609e-4+q.*t3.*1.042032139922423e-1+r.*t4.*7.509164411087042e-3-q.*w+r.*v-t5.*u.*2.077280001430589-t6.*v.*7.498296877553198e-5+t7.*w.*7.857891522825007e-4+2.584057119337349e-3;U5.*1.282467003021428e-3-U6.*1.281848672115881e-3-U7.*1.189225726086907e-3+U8.*1.18860739518136e-3-p.*7.770674208184869e-2+q.*1.192373647060661e-5+r.*3.656995509702477e-3+t8.*1.688804935817261e-2+t9.*1.688804935817261e-2-t11.*3.000496957904852e-3+t12.*6.049096727988004e-5-t13.*3.060237809075675e-3-u.*3.498257956043473e-5-v.*1.779907980287664-w.*1.631722346354116e-3-U1.*t23.*1.461853110959408e-2+U2.*t23.*1.461921481375014e-2+U2.*t24.*1.218998503234159e-6-U3.*t23.*1.461853110959408e-2+U4.*t23.*1.461921481375014e-2+U1.*t27.*2.437997006468318e-7-U3.*t26.*2.437997006468318e-7-U4.*t25.*2.437997006468318e-7-epsilon1.*epsilon3.*6.866189443643555e-4-epsilon2.*epsilon3.*2.435012555015475-epsilon1.*eta.*2.435012555015475+epsilon2.*eta.*6.866189443643555e-4-p.*q.*1.002476739431943e-3-p.*r.*1.664610602507794e-5-q.*r.*2.213679548389513e-2-p.*t2.*1.890856493868756e-1+q.*t3.*2.481976848084498e-5+r.*t4.*2.729961775974938e-3+p.*w-r.*u-t5.*u.*5.446367846604962e-5-t6.*v.*2.670443407038389-t7.*w.*2.567753996139708e-3-8.444024679086305e-3;U5.*2.95499962936627e-2-U6.*2.964607566181378e-2+U7.*2.937158266152852e-2-U8.*2.927550329337743e-2-p.*8.631855354882523e-3-q.*1.852770184731712e-3+r.*3.377327624340444e-5+t8.*1.721924120771868+t9.*1.721924120771868+t11.*2.699759107328203e-2+t12.*2.700669212561305e-2-t13.*4.285450446831067e-6+u.*3.212840082922422e-4-v.*1.398495660595942e-3-w.*2.062055466767393+U1.*t23.*1.579238941804852e-5-U2.*t23.*8.374554023872988e-6+U2.*t24.*1.125775874780148e-8+U3.*t23.*1.579238941804852e-5-U4.*t23.*8.374554023872988e-6+U1.*t27.*2.251551749560296e-9-U3.*t26.*2.251551749560296e-9-U4.*t25.*2.251551749560296e-9+epsilon1.*epsilon3.*2.434844468493164e-2-epsilon2.*epsilon3.*7.942332478126292e-2-epsilon1.*eta.*7.942332478126292e-2-epsilon2.*eta.*2.434844468493164e-2+p.*q.*5.114494288484089e-6-p.*r.*1.246737357176586e-3+q.*r.*3.540282981731623e-3-p.*t2.*2.100409734682202e-2-q.*t3.*3.856620543955547e-3-p.*v+q.*u+r.*t4.*2.521188580880639e-5+t5.*u.*5.002006468300261e-4-t6.*v.*2.098200332809708e-3-t7.*w.*3.244946161878827-8.60962060385934e-1;U5.*4.749535312950716e-2-U6.*4.747065342507792e-2-U7.*4.404230607609921e-2+U8.*4.401760637166997e-2-p.*2.877766022049595+q.*4.763028402332452e-4+r.*1.058980795405775e-2+t8.*6.254228919987668e-1+t9.*6.254228919987668e-1-t11.*8.658184179063258e-7+t12.*2.231032170251271e-3-t13.*2.230872339030302e-3-u.*1.77980835998433e-4-v.*4.662404548038507e-1-w.*6.042832343463917e-2+U1.*t23.*4.028625812385904e-3-U2.*t23.*4.028413062156026e-3+U2.*t24.*3.529935984685916e-6+U3.*t23.*4.028625812385904e-3-U4.*t23.*4.028413062156026e-3+U1.*t27.*7.059871969371832e-7-U3.*t26.*7.059871969371832e-7-U4.*t25.*7.059871969371832e-7-epsilon1.*epsilon3.*7.795098033651842e-3-epsilon2.*epsilon3.*2.647883412729234e+1-epsilon1.*eta.*2.647883412729234e+1+epsilon2.*eta.*7.795098033651842e-3+p.*q.*2.40289851856519e-3-p.*r.*5.473752471437526e-4+q.*r.*1.800267179242618e-1-p.*t2.*7.002535976731401+q.*t3.*9.914447749243671e-4+r.*t4.*7.905333996935925e-3-t5.*u.*2.770948039492404e-4-t6.*v.*6.995129874210119e-1-t7.*w.*9.509281363095557e-2-3.127114459993834e-1;U5.*(-4.757076719858019e-2)-U6.*4.858270006579488e-2+U7.*4.862857828406205e-2+U8.*4.752488898031302e-2+p.*1.442711266263134e-3-q.*1.854199093252412+r.*2.0038523812312e-3+t8.*1.915928911589784e-1+t9.*1.915928911589784e-1-t11.*2.406329262717208e-3-t12.*9.70897701380291e-7+t13.*2.40716657025984e-3+u.*3.218179508002375e-1+v.*2.257038156097029e-4-w.*1.851169399593259e-2+U1.*t23.*3.706511980890804e-3+U2.*t23.*3.710685162595089e-3+U2.*t24.*6.679507937437335e-7+U3.*t23.*3.706511980890804e-3+U4.*t23.*3.710685162595089e-3+U1.*t27.*1.335901587487467e-7-U3.*t26.*1.335901587487467e-7-U4.*t25.*1.335901587487467e-7+epsilon1.*epsilon3.*2.437182997903259e+1+epsilon2.*epsilon3.*1.317760061410965e-2+epsilon1.*eta.*1.317760061410965e-2-epsilon2.*eta.*2.437182997903259e+1-p.*q.*2.094201267211482e-3-p.*r.*2.45095231435155e-1+q.*r.*2.028279588377874e-4+p.*t2.*3.510583372183968e-3-q.*t3.*3.85959487828032+r.*t4.*1.495883817998616e-3+t5.*u.*5.010319312418738e-1+t6.*v.*3.386294533276535e-4-t7.*w.*2.913086061460094e-2-9.579644557948922e-2;U5.*(-9.246852473488011e-5)+U6.*1.410296387771424e-4+U7.*8.346203222865983e-5-U8.*1.320231462709221e-4+p.*7.059486509616421e-3+q.*9.364402156910076e-4-r.*3.371070694942918-t8.*1.631274205906405e-3-t9.*1.631274205906405e-3+t11.*4.735808075681749e-4-t12.*2.530986830957105e-4+t13.*4.255921857063476e-6+u.*3.017709698847704e-2+v.*1.462791959432953e-2+w.*1.576136188588549e-4-U1.*t23.*2.364942078743729e-4-U2.*t23.*4.414656919769748e-4-U2.*t24.*1.123690231647639e-3-U3.*t23.*2.364942078743729e-4-U4.*t23.*4.414656919769748e-4-U1.*t27.*2.247380463295279e-4+U3.*t26.*2.247380463295279e-4+U4.*t25.*2.247380463295279e-4+epsilon1.*epsilon3.*4.761512974557557e-1+epsilon2.*epsilon3.*2.277743738686231e-1+epsilon1.*eta.*2.277743738686231e-1-epsilon2.*eta.*4.761512974557557e-1+p.*q.*6.735499943320363e-2+p.*r.*1.866974352196623e-3-q.*r.*2.483132149807086e-3+p.*t2.*1.717801512773126e-2+q.*t3.*1.949240442112933e-3-r.*t4.*2.516517758057668+t5.*u.*4.698211875942013e-2+t6.*v.*2.194665784522845e-2+t7.*w.*2.480281039082092e-4+8.156371029532025e-4];
