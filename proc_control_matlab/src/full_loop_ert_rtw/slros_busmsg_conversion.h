#ifndef _SLROS_BUSMSG_CONVERSION_H_
#define _SLROS_BUSMSG_CONVERSION_H_

#include <ros/ros.h>
#include <sonia_common/ThrusterPwm.h>
#include "full_loop_types.h"
#include "slros_msgconvert_utils.h"


void convertFromBus(sonia_common::ThrusterPwm* msgPtr, SL_Bus_full_loop_sonia_common_ThrusterPwm const* busPtr);
void convertToBus(SL_Bus_full_loop_sonia_common_ThrusterPwm* busPtr, sonia_common::ThrusterPwm const* msgPtr);


#endif
