/**
 * \file	ControlInput.h
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

#ifndef PROC_CONTROL_CONTROLINPUT_H
#define PROC_CONTROL_CONTROLINPUT_H

#include <ros/ros.h>
#include <eigen3/Eigen/Eigen>
#include <nav_msgs/Odometry.h>
#include <geometry_msgs/Pose.h>

#include "proc_control/EnableControl.h"
#include "provider_kill_mission/KillSwitchMsg.h"
#include "proc_control/property.h"



namespace proc_control {

    class ControlInput {
    public:

        const double DEGREE_TO_RAD = M_PI / 180.0;

        //==============================================================================
        // C / D T O R S   S E C T I O N
        //------------------------------------------------------------------------------
        ControlInput(const ros::NodeHandlePtr &nh);
        ~ControlInput();

        //==========================================================================
        // P U B L I C   M E T H O D S

        void OdometryCallback(const nav_msgs::Odometry::ConstPtr &odomIn);
        void VisionCallback(const geometry_msgs::Pose &visionIn);

        Eigen::Vector3d GetPosePosition()    const { return controlInput_.pose.position; };
        Eigen::Vector3d GetVisionPosePosition()    const { return controlInput_.vision.position; };
        Eigen::Vector3d GetTwistLinear()     const { return controlInput_.twist.linear; };
        Eigen::Vector3d GetPoseOrientation() const { return controlInput_.pose.orientation; };
        Eigen::Vector3d GetVisionPoseOrientation() const { return controlInput_.vision.orientation; };
        Eigen::Vector3d GetTwistAngular()    const { return controlInput_.twist.angular; };


    private:

        //==========================================================================
        // P R I V A T E   M E M B E R S

        ros::NodeHandlePtr nh_;

        // Subscriber
        ros::Subscriber navigationOdomSubscriber_;
        ros::Subscriber navigationVisionSubscriber_;

        struct tPose
        {
            Eigen::Vector3d position;
            Eigen::Vector3d orientation;
        };

        struct tTwist
        {
            Eigen::Vector3d linear;
            Eigen::Vector3d angular;
        };

        struct tControlInput
        {
            tPose  pose;
            tPose  vision;
            tTwist twist;
        };

        tControlInput controlInput_;
    };
}


#endif //PROC_CONTROL_CONTROLINPUT_H
