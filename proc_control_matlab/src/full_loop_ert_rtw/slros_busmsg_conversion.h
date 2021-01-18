#ifndef _SLROS_BUSMSG_CONVERSION_H_
#define _SLROS_BUSMSG_CONVERSION_H_

#include <ros/ros.h>
#include <gazebo_msgs/ModelState.h>
#include <geometry_msgs/Point.h>
#include <geometry_msgs/Pose.h>
#include <geometry_msgs/Quaternion.h>
#include <geometry_msgs/Twist.h>
#include <geometry_msgs/Vector3.h>
#include "full_loop_types.h"
#include "slros_msgconvert_utils.h"


void convertFromBus(gazebo_msgs::ModelState* msgPtr, SL_Bus_full_loop_gazebo_msgs_ModelState const* busPtr);
void convertToBus(SL_Bus_full_loop_gazebo_msgs_ModelState* busPtr, gazebo_msgs::ModelState const* msgPtr);

void convertFromBus(geometry_msgs::Point* msgPtr, SL_Bus_full_loop_geometry_msgs_Point const* busPtr);
void convertToBus(SL_Bus_full_loop_geometry_msgs_Point* busPtr, geometry_msgs::Point const* msgPtr);

void convertFromBus(geometry_msgs::Pose* msgPtr, SL_Bus_full_loop_geometry_msgs_Pose const* busPtr);
void convertToBus(SL_Bus_full_loop_geometry_msgs_Pose* busPtr, geometry_msgs::Pose const* msgPtr);

void convertFromBus(geometry_msgs::Quaternion* msgPtr, SL_Bus_full_loop_geometry_msgs_Quaternion const* busPtr);
void convertToBus(SL_Bus_full_loop_geometry_msgs_Quaternion* busPtr, geometry_msgs::Quaternion const* msgPtr);

void convertFromBus(geometry_msgs::Twist* msgPtr, SL_Bus_full_loop_geometry_msgs_Twist const* busPtr);
void convertToBus(SL_Bus_full_loop_geometry_msgs_Twist* busPtr, geometry_msgs::Twist const* msgPtr);

void convertFromBus(geometry_msgs::Vector3* msgPtr, SL_Bus_full_loop_geometry_msgs_Vector3 const* busPtr);
void convertToBus(SL_Bus_full_loop_geometry_msgs_Vector3* busPtr, geometry_msgs::Vector3 const* msgPtr);


#endif
