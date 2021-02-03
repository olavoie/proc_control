% clc;
% syms('qu',[3 1]); % partie Vectoriel
% syms('w',[1 3]); % partie Vectoriel
% syms qs % Partie scalaire 
% 
% V=[0;0;1];
% qZYX = eul2quat([0,pi/2,0]);
% qud=qZYX(2:4).';
% qsd=qZYX(1);
% 
% 
% % Méthode  fossen equation 2.24
% t=(qs^2-qu.'*qu)*eye(3)+2*qu*qu.'-2*qs*skew(qu);
% t=simplify(t)
% 
%  t= subs(t, qu, qud);
%  t=subs(t, qs, qsd);
%  double(t)
%  double(t*V)
%  
% %Methode autre
%  t4=eye(3)+2*qs*skew(qu)+2*skew(qu)^2;
%  t4=simplify(t4)
%  
%  t4= subs(t4, qu, qud);
%  t4=subs(t4, qs, qsd);
%  double(t4.'*V)
% % Méthode  fossen equation 2.26
% %https://en.wikipedia.org/wiki/Euler%E2%80%93Rodrigues_formula
% t2= [1-2*(qu2^2+qu3^2), 2*(qu1*qu2-qu3-qs), 2*(qu1*qu3-qu2-qs);
%      2*(qu1*qu2-qu3-qs), 1-2*(qu1^2+qu3^2), 2*(qu2*qu3-qu1-qs);
%      2*(qu1*qu3-qu2-qs),2*(qu2*qu3-qu1-qs), 1-2*(qu1^2+qu2^2),]
%  
%  t2= subs(t2, qu, qud);
%  t2=subs(t2, qs, qsd);
%  double(t2)
%  double(t2*V)
%  
% 
% function sm=skew(u) 
% % Convertie un vecteur 3x1 en une matrice antisymétrique 3x3
%     sm=[0,-u(3),u(2);
%         u(3), 0, -u(1);
%        -u(2), u(1), 0];
% end
syms z
  aa= 0.037/2; % Calculer l'amplitude.
    kk=aa;     % Monter la courbe pour avoi min 0 et max volume.
    bb=4/.3;  % Calculer la pente transitoire.
    hh=.3/2;  % Décaler la courbe pour avoir x(0)=0. 
    
    % Equation
    vz=aa*erf(bb*(z-hh))+kk;
    eq=(998*(aa*erf(bb*(z-hh))+kk))-(33.95)==0.034018;
    double(solve(eq,z))
    