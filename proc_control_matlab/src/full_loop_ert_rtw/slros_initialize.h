#ifndef _SLROS_INITIALIZE_H_
#define _SLROS_INITIALIZE_H_

#include "slros_busmsg_conversion.h"
#include "slros_generic.h"

extern ros::NodeHandle * SLROSNodePtr;
extern const std::string SLROSNodeName;

// For Block full_loop/Send PWM to ROS/Publish
extern SimulinkPublisher<sonia_common::ThrusterPwm, SL_Bus_full_loop_sonia_common_ThrusterPwm> Pub_full_loop_783;

void slros_node_init(int argc, char** argv);

#endif
