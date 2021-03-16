#ifndef _SLROS_INITIALIZE_H_
#define _SLROS_INITIALIZE_H_

#include "slros_busmsg_conversion.h"
#include "slros_generic.h"

extern ros::NodeHandle * SLROSNodePtr;
extern const std::string SLROSNodeName;

// For Block dry_test/Publish1
extern SimulinkPublisher<std_msgs::UInt16MultiArray, SL_Bus_dry_test_std_msgs_UInt16MultiArray> Pub_dry_test_24;

void slros_node_init(int argc, char** argv);

#endif
