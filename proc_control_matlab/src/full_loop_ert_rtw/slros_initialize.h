#ifndef _SLROS_INITIALIZE_H_
#define _SLROS_INITIALIZE_H_

#include "slros_busmsg_conversion.h"
#include "slros_generic.h"

extern ros::NodeHandle * SLROSNodePtr;
extern const std::string SLROSNodeName;

// For Block full_loop/Send to Gazebo/Publish
extern SimulinkPublisher<gazebo_msgs::ModelState, SL_Bus_full_loop_gazebo_msgs_ModelState> Pub_full_loop_206;

void slros_node_init(int argc, char** argv);

#endif
