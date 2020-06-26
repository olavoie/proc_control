function main
    addpath("Thrusters");
    addpath("modes");
    addpath("../../matlab_gen/msggen");

    rosshutdown;
    rosinit();
    rate = rosrate(1);

    node = ProcControlNode();

    while(true)
       node.spinOnce();
       waitfor(rate);
    end
end
