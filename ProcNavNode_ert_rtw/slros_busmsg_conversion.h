#ifndef _SLROS_BUSMSG_CONVERSION_H_
#define _SLROS_BUSMSG_CONVERSION_H_

#include <ros/ros.h>
#include <geometry_msgs/Accel.h>
#include <geometry_msgs/Quaternion.h>
#include <geometry_msgs/Vector3.h>
#include <ros/time.h>
#include <sonia_common/BodyVelocityDVL.h>
#include <sonia_common/ImuInformation.h>
#include <std_msgs/Header.h>
#include "ProcNavNode_types.h"
#include "slros_msgconvert_utils.h"


void convertFromBus(geometry_msgs::Accel* msgPtr, SL_Bus_ProcNavNode_geometry_msgs_Accel const* busPtr);
void convertToBus(SL_Bus_ProcNavNode_geometry_msgs_Accel* busPtr, geometry_msgs::Accel const* msgPtr);

void convertFromBus(geometry_msgs::Quaternion* msgPtr, SL_Bus_ProcNavNode_geometry_msgs_Quaternion const* busPtr);
void convertToBus(SL_Bus_ProcNavNode_geometry_msgs_Quaternion* busPtr, geometry_msgs::Quaternion const* msgPtr);

void convertFromBus(geometry_msgs::Vector3* msgPtr, SL_Bus_ProcNavNode_geometry_msgs_Vector3 const* busPtr);
void convertToBus(SL_Bus_ProcNavNode_geometry_msgs_Vector3* busPtr, geometry_msgs::Vector3 const* msgPtr);

void convertFromBus(ros::Time* msgPtr, SL_Bus_ProcNavNode_ros_time_Time const* busPtr);
void convertToBus(SL_Bus_ProcNavNode_ros_time_Time* busPtr, ros::Time const* msgPtr);

void convertFromBus(sonia_common::BodyVelocityDVL* msgPtr, SL_Bus_ProcNavNode_sonia_common_BodyVelocityDVL const* busPtr);
void convertToBus(SL_Bus_ProcNavNode_sonia_common_BodyVelocityDVL* busPtr, sonia_common::BodyVelocityDVL const* msgPtr);

void convertFromBus(sonia_common::ImuInformation* msgPtr, SL_Bus_ProcNavNode_sonia_common_ImuInformation const* busPtr);
void convertToBus(SL_Bus_ProcNavNode_sonia_common_ImuInformation* busPtr, sonia_common::ImuInformation const* msgPtr);

void convertFromBus(std_msgs::Header* msgPtr, SL_Bus_ProcNavNode_std_msgs_Header const* busPtr);
void convertToBus(SL_Bus_ProcNavNode_std_msgs_Header* busPtr, std_msgs::Header const* msgPtr);


#endif
