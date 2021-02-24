#include "slros_initialize.h"

ros::NodeHandle * SLROSNodePtr;
const std::string SLROSNodeName = "full_loop";

// For Block full_loop/Send PWM to ROS/Publish
SimulinkPublisher<sonia_common::ThrusterPwm, SL_Bus_full_loop_sonia_common_ThrusterPwm> Pub_full_loop_783;

void slros_node_init(int argc, char** argv)
{
  ros::init(argc, argv, SLROSNodeName);
  SLROSNodePtr = new ros::NodeHandle();
}

