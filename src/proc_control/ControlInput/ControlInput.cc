/**
 * \file	ControlInput.cc
 * \author	Olivier Lavoie <olavoie9507@gmail.com>
 * \date	10/21/17
 *
 * \copyright Copyright (c) 2017 S.O.N.I.A. AUV All rights reserved.
 *
 * \section LICENSE
 *
 * This file is part of S.O.N.I.A. software.
 *
 * S.O.N.I.A. AUV software is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * S.O.N.I.A. AUV software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with S.O.N.I.A. AUV software. If not, see <http://www.gnu.org/licenses/>.
 */

#include "ControlInput.h"

namespace proc_control{

    ControlInput::ControlInput(const ros::NodeHandlePtr &nh): nh_(nh) {

        navigationOdomSubscriber_ = nh_->subscribe("/proc_navigation/odom", 100, &ControlInput::OdometryCallback, this);

    }

    ControlInput::~ControlInput(){

        navigationOdomSubscriber_.shutdown();

    }


    void ControlInput::OdometryCallback(const nav_msgs::Odometry::ConstPtr &odomIn) {

       controlInput_.pose.position[0]    = odomIn->pose.pose.position.x;
       controlInput_.pose.position[1]    = odomIn->pose.pose.position.y;
       controlInput_.pose.position[2]    = odomIn->pose.pose.position.z;
       controlInput_.pose.orientation[0] = odomIn->pose.pose.orientation.x * DEGREE_TO_RAD;
       controlInput_.pose.orientation[1] = odomIn->pose.pose.orientation.y * DEGREE_TO_RAD;
       controlInput_.pose.orientation[2] = odomIn->pose.pose.orientation.z * DEGREE_TO_RAD;

       controlInput_.twist.linear[0] = odomIn->twist.twist.linear.x;
       controlInput_.twist.linear[1] = odomIn->twist.twist.linear.y;
       controlInput_.twist.linear[2] = odomIn->pose.pose.position.z;
       controlInput_.twist.angular[0] = odomIn->twist.twist.angular.x;
       controlInput_.twist.angular[1] = odomIn->twist.twist.angular.y;
       controlInput_.twist.angular[2] = odomIn->twist.twist.angular.z;
    }


}