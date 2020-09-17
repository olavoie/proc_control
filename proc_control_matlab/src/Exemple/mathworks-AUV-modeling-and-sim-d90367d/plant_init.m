load('T200-Spec-16V.mat');

% Angle des moteurs.
a=zeros(3,8);

%     Z  Y  X
a = [ 0 90 45;
      0 90 -45;
      0 90 45;
      0 90 -45;
      0 180 0;
      0 0 0;
      0 180 0;
      0 0 0
];
a_rad = deg2rad(a);

% Données pour lookup table.
N = T200Spec16V{:,6};% Force en Newton
PWM = T200Spec16V{:,1};% PWM

