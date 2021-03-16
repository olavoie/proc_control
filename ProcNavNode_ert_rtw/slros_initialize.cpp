#include "slros_initialize.h"

ros::NodeHandle * SLROSNodePtr;
const std::string SLROSNodeName = "ProcNavNode";

// For Block ProcNavNode/ROS Input/Subscribe
SimulinkSubscriber<sonia_common::ImuInformation, SL_Bus_ProcNavNode_sonia_common_ImuInformation> Sub_ProcNavNode_795;

// For Block ProcNavNode/ROS Input/Subscribe1
SimulinkSubscriber<sonia_common::BodyVelocityDVL, SL_Bus_ProcNavNode_sonia_common_BodyVelocityDVL> Sub_ProcNavNode_796;

void slros_node_init(int argc, char** argv)
{
  ros::init(argc, argv, SLROSNodeName);
  SLROSNodePtr = new ros::NodeHandle();
}

