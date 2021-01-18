#include "slros_initialize.h"

ros::NodeHandle * SLROSNodePtr;
const std::string SLROSNodeName = "full_loop";

// For Block full_loop/Send to Gazebo/Publish
SimulinkPublisher<gazebo_msgs::ModelState, SL_Bus_full_loop_gazebo_msgs_ModelState> Pub_full_loop_206;

void slros_node_init(int argc, char** argv)
{
  ros::init(argc, argv, SLROSNodeName);
  SLROSNodePtr = new ros::NodeHandle();
}

