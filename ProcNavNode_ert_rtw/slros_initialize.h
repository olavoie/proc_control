#ifndef _SLROS_INITIALIZE_H_
#define _SLROS_INITIALIZE_H_

#include "slros_busmsg_conversion.h"
#include "slros_generic.h"

extern ros::NodeHandle * SLROSNodePtr;
extern const std::string SLROSNodeName;

// For Block ProcNavNode/ROS Input/Subscribe
extern SimulinkSubscriber<sonia_common::ImuInformation, SL_Bus_ProcNavNode_sonia_common_ImuInformation> Sub_ProcNavNode_795;

// For Block ProcNavNode/ROS Input/Subscribe1
extern SimulinkSubscriber<sonia_common::BodyVelocityDVL, SL_Bus_ProcNavNode_sonia_common_BodyVelocityDVL> Sub_ProcNavNode_796;

void slros_node_init(int argc, char** argv);

#endif
