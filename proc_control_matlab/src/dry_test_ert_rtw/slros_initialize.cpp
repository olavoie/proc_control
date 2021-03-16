#include "slros_initialize.h"

ros::NodeHandle * SLROSNodePtr;
const std::string SLROSNodeName = "dry_test";

// For Block dry_test/Publish1
SimulinkPublisher<std_msgs::UInt16MultiArray, SL_Bus_dry_test_std_msgs_UInt16MultiArray> Pub_dry_test_24;

void slros_node_init(int argc, char** argv)
{
  ros::init(argc, argv, SLROSNodeName);
  SLROSNodePtr = new ros::NodeHandle();
}

