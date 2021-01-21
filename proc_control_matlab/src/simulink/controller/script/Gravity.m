function out1 = Gravity(in1)
%GRAVITY
%    OUT1 = GRAVITY(IN1)

%    This function was generated by the Symbolic Math Toolbox version 8.5.
%    19-Jan-2021 15:21:09

phi = in1(4,:);
psi = in1(6,:);
theta = in1(5,:);
z = in1(3,:);
t2 = conj(phi);
t3 = cos(phi);
t4 = conj(psi);
t5 = cos(psi);
t6 = conj(theta);
t7 = cos(theta);
t8 = sin(phi);
t9 = sin(psi);
t10 = sin(theta);
t11 = phi./2.0;
t12 = psi./2.0;
t13 = theta./2.0;
t23 = z.*(4.0e+1./3.0);
t14 = t2./2.0;
t15 = cos(t11);
t16 = t4./2.0;
t17 = cos(t12);
t18 = t6./2.0;
t19 = cos(t13);
t20 = sin(t11);
t21 = sin(t12);
t22 = sin(t13);
t30 = (t3.*t5)./4.0;
t31 = (t3.*t7)./4.0;
t32 = (t5.*t7)./4.0;
t33 = t23-2.0;
t24 = cos(t14);
t25 = cos(t16);
t26 = cos(t18);
t27 = sin(t14);
t28 = sin(t16);
t29 = sin(t18);
t34 = erf(t33);
t36 = t15.*t17.*t22;
t37 = t17.*t19.*t20;
t38 = t15.*t21.*t22;
t39 = t19.*t20.*t21;
t40 = t20.*t21.*t22.*2.0;
t41 = t15.*t17.*t19.*2.0;
t35 = t34+1.0;
t42 = -t38;
t43 = t24.*t26.*t28;
t44 = t25.*t27.*t29;
t46 = t36.*t39.*2.0;
t47 = t36+t39;
t48 = t24.*t28.*t29.*t38;
t50 = t26.*t27.*t28.*t39;
t51 = t24.*t25.*t29.*t36;
t53 = t25.*t26.*t27.*t37;
t54 = t26.*t27.*t28.*t36;
t56 = t25.*t26.*t27.*t38;
t57 = t24.*t28.*t29.*t37;
t59 = t24.*t25.*t29.*t39;
t61 = t40+t41;
t45 = -t44;
t49 = t17.*t20.*t22.*t44;
t52 = t15.*t19.*t21.*t43;
t55 = t15.*t19.*t21.*t44;
t58 = t17.*t20.*t22.*t43;
t60 = t37+t42;
t62 = t24.*t28.*t29.*t42;
t63 = -t50;
t64 = -t51;
t65 = -t53;
t66 = -t54;
t69 = -t59;
t67 = t15.*t19.*t21.*t45;
t68 = -t58;
t70 = t43+t45;
out1 = [t47.*t61.*(-3.330495e+2)+t60.*t70.*6.66099e+2+t35.*t47.*t61.*1.8112203e+2-t35.*t60.*t70.*3.6224406e+2,t47.*t70.*6.66099e+2+t60.*t61.*3.330495e+2-t35.*t47.*t70.*3.6224406e+2-t35.*t60.*t61.*1.8112203e+2,(t34.*3.6926e+1-3.0974e+1).*(-t46+t48+t50+t51-t52+t53+t54+t55-t57+t58+t59-t15.^2.*t17.^2.*t19.^2-t20.^2.*t21.^2.*t22.^2+t17.*t20.*t22.*t45+t25.*t26.*t27.*t42).*(9.81e+2./2.0e+2),(t34.*5.4336609e-1-4.5578241e-1).*(t30+t31+t32+t46+t49+t52+t56+t57+t62+t63+t64+t65+t66+t67+t68+t69+t5.*t8.*(9.0./2.0)+t7.*t8.*(9.0./2.0)+t36.*t43.*1.8e+1-t36.*t44.*1.8e+1+t39.*t43.*1.8e+1-t39.*t44.*1.8e+1-t3.*t9.*t10.*(9.0./2.0)+1.0./4.0),(t34.*1.8112203e-1-1.5192747e-1).*(t10.*(2.7e+1./2.0)+t30+t31+t32+t46+t49+t52+t56+t57+t62+t63+t64+t65+t66+t67+t68+t69+t8.*t9.*(2.7e+1./2.0)-t37.*t43.*5.4e+1+t37.*t44.*5.4e+1+t38.*t43.*5.4e+1-t38.*t44.*5.4e+1+t3.*t5.*t10.*(2.7e+1./2.0)+1.0./4.0),t47.*t61.*(-9.991485e-1)+t47.*t70.*6.66099e-1+t60.*t61.*3.330495e-1+t60.*t70.*1.998297+t35.*t47.*t61.*5.4336609e-1-t35.*t47.*t70.*3.6224406e-1-t35.*t60.*t61.*1.8112203e-1-t35.*t60.*t70.*1.08673218];