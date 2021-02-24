function main
    addpath("Thrusters");
    addpath("../../matlab_gen/msggen");

    rosshutdown;
    rosinit();
    rate = rosrate(1);

    node = RosNode();

    while(true)
       node.spinOnce();
       waitfor(rate);
    end
end
