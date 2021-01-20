
% Retrouver le paramètre de AUV8
cf = ConfigAUV8();

% Constante pour bloc areospace
    I=cf.I;
    mass=cf.mass;

% Perturbations des vages
    %Vages X
    waX=2;          % Amplitude
    wfX=pi/2;         % Frequence
    wpX=0;          % Phase
    %Vages Y
    waY=3;          % Amplitude
    wfY=pi/2;         % Frequence
    wpY=pi/2;       % Phase
    %Vages Z
    waZ= 4;         % Amplitude
    wfZ=pi/2;         % Frequence
    wpZ=pi;         % Phase
    %Vages RX (Roll)
    waPhi= .5;      % Amplitude
    wfPhi= pi/2;      % Frequence
    wpPhi=0;        % Phase
    %Vages Ry (Pitch)
    waTheta=.25;    % Amplitude
    wfTheta=pi/2;     % Frequence
    wpTheta=pi/2;   % Phase
    %Vages Rz (Yaw)
    waPsi=.5;       % Amplitude
    wfPsi=pi/2;       % Frequence
    wpPsi=pi;       % Phase
    
% Perturbation Drift

    dts=5; % Temp d'échantillionage des perturbation
    
    % Perturbation x
    dMinX=-1; % Valeur minimum x
    dMaxX=1;  % Valeur maximum x
    dSeedX=round(rand*10);
    
    % Perturbation y
    dMinY=-3; % Valeur minimum  y
    dMaxY=3;  % Valeur maximumx y
    dSeedY=round(rand*10);