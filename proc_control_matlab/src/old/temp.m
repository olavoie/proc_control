clc;
syms ph th ps W B xb yb zb xg yg zg

                Rz = @(ph,th,ps)  [ cos(ps),-sin(ps), 0;...
                                  sin(ps), cos(ps), 0;...
                                  0      , 0      , 1];
                             
                Ry = @(ph,th,ps)[ cos(th), 0, sin(th);...
                                  0      , 1, 0      ;...
                                 -sin(th), 0, cos(th)];
                       
                Rx = @(ph,th,ps)[ 1, 0      , 0      ;...
                                  0, cos(ph),-sin(ph);...
                                  0, sin(ph), cos(ph)];
                              
               RBW = @(ph,th,ps)[Rz(ph,th,ps)*Ry(ph,th,ps)*Rx(ph,th,ps)];
               
               
               fg=@(ph,th,ps)[RBW(ph,th,ps).'*[0;0;W]]
               fb=@(ph,th,ps)[RBW(ph,th,ps).'*[0;0;-B]]
               
               rb=[xb;yb;zb];
               rg =[xg,yg,zg];
               
               
               G = @(ph,th,ps)[fb(ph,th,ps) +fg(ph,th,ps);...
                     cross(rb(ph,th,ps),fb(ph,th,ps))+ cross(rg,fg(ph,th,ps))];
                 
                 
                a=simplify(rb*(fb(ph,th,ps)).');
               b= a.';