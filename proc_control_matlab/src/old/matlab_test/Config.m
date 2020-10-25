classdef Config < matlab.mixin.Heterogeneous
    %CONFIG class.
    
    properties
        z        %Position des truster sur le frame.
                 %(0 = milieu, 1= position bas, -1= postion haut)(t15,t26,t37,t48)
        dz       % Distance entre les postions du frame.
        d14      % Distance x y z / angles des trusters 1 - 4. 
        a14      
        d58      % Distance x y z des trusters 5 - 8.
        psl      % Power supply limitation
        nbt      % nombre de thrusters
        RG       % Centre de masse
        RB       % Centre de flotaison
        I        % Inertie
        mass
        volume
    end
end

