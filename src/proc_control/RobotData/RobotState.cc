/**
 * \file	ControlModeIF.cc
 * \author	Olivier Lavoie <olavoie9507@gmail.com>
 * \date	2018
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

#include "RobotState.h"

namespace proc_control
{
     RobotState::RobotState(const ros::NodeHandlePtr &nh):
        nh_(nh),
        inputData_(nh),
        pBbox_{std::make_shared<std::vector<double>>(control::CARTESIAN_SPACE)},
        bboxParameters_("Bbox", pBbox_),
        bbox_{*pBbox_},
        trajectoryManager_{std::make_shared<control::Trajectory>()}
     {
         killSwitchSubscriber_   = nh_->subscribe("/provider_kill_mission/kill_switch_msg", 100,
                                                  &RobotState::KillMissionCallback, this);

         enableControllerServer_ = nh_->advertiseService("/proc_control/enable_control",
                                                         &RobotState::EnableControlServiceCallback, this);
         enableThrustersServer_  = nh_->advertiseService("/proc_control/enable_thrusters",
                                                         &RobotState::EnableThrustersServerCallback, this);
         clearWayPointServer_    = nh_->advertiseService("/proc_control/clear_waypoint",
                                                         &RobotState::ClearWayPointServiceCallback, this);

         setBoundingBoxServer_   = nh_->advertiseService("/proc_control/set_bounding_box",
                                                         &RobotState::SetBoundingBoxServiceCallback, this);
         resetBoundingBoxServer_ = nh->advertiseService("/proc_control/reset_bounding_box",
                                                        &RobotState::ResetBoundingBoxServiceCallback, this);

         controllerPoseErrorPublisher_  = nh_->advertise<geometry_msgs::Pose>("/proc_control/current_controller_pose_error", 100);
         controllerTwistErrorPublisher_ = nh_->advertise<geometry_msgs::Twist>("/proc_control/current_controller_twist_error", 100);
         targetErrorPublisher_          = nh_->advertise<geometry_msgs::Pose>("/proc_control/current_target_error", 100);
         targetPublisher_               = nh_->advertise<geometry_msgs::Pose>("/proc_control/current_target", 100);
         velocityTargetPublisher_        = nh_->advertise<geometry_msgs::Twist>("/proc_control/current_target_velocity", 100);
         debugTargetPublisher_          = nh_->advertise<geometry_msgs::Pose>("/proc_control/debug_current_target", 100);
         commandDebugPublisher_         = nh_->advertise<geometry_msgs::Wrench>("/provider_thruster/thruster_effort_vector", 100);
         targetIsReachedPublisher_      = nh_->advertise<proc_control::TargetReached>("/proc_control/target_reached", 100);

         enableThruster_       = true;
         enableAxisController_ = {{false, false, false, false, false, false}};

         desiredPose_          = Eigen::VectorXd::Zero(control::CARTESIAN_SPACE);
         desiredVisionOffset_  = Eigen::VectorXd::Zero(control::CARTESIAN_SPACE);
         desiredTwist_         = Eigen::VectorXd::Zero(control::CARTESIAN_SPACE);
         desiredAcceleration_  = Eigen::VectorXd::Zero(control::CARTESIAN_SPACE);

         actualPose_           = Eigen::VectorXd::Zero(control::CARTESIAN_SPACE);
         actualVisionPose_     = Eigen::VectorXd::Zero(control::CARTESIAN_SPACE);
         actualTwist_          = Eigen::VectorXd::Zero(control::CARTESIAN_SPACE);
         actualAcceleration_   = Eigen::VectorXd::Zero(control::CARTESIAN_SPACE);

         trajectoryManager_->ResetTrajectory();
     }

     RobotState::~RobotState()
     {
         killSwitchSubscriber_.shutdown();
         enableControllerServer_.shutdown();
         enableThrustersServer_.shutdown();
         clearWayPointServer_.shutdown();
         resetBoundingBoxServer_.shutdown();
         setBoundingBoxServer_.shutdown();
         resetBoundingBoxServer_.shutdown();
     }

     void RobotState::UpdateInput()
     {
         actualPose_  << inputData_.GetPosePosition(), inputData_.GetPoseOrientation();
         actualVisionPose_  << inputData_.GetVisionPosePosition(), inputData_.GetVisionPoseOrientation();
         actualTwist_ << inputData_.GetTwistLinear(), inputData_.GetTwistAngular();
     }

    void RobotState::KillMissionCallback(const provider_kill_mission::KillSwitchMsg::ConstPtr &state_in)
    {
        if(!state_in->state)
        {
            UpdateInput();
            enableAxisController_ = {{false, false, false, false, false, false}};

            desiredPose_         = actualPose_;
            desiredTwist_        = actualTwist_;
            desiredAcceleration_ = actualAcceleration_;

            trajectoryManager_->ResetTrajectory();
        }
    }

    bool RobotState::EnableControlServiceCallback(proc_control::EnableControlRequest &request, proc_control::EnableControlResponse &response)
    {
        UpdateInput();
        desiredPose_         = actualPose_;
        desiredTwist_        = Eigen::VectorXd::Zero(control::CARTESIAN_SPACE);
        desiredTwist_[2]     = actualPose_[2];
        desiredTwist_[5]     = actualPose_[5];
        desiredAcceleration_ = actualAcceleration_;

        PosePublisher(desiredPose_, targetPublisher_);
        TwistPublisher(desiredTwist_, velocityTargetPublisher_);

        trajectoryManager_->ResetTrajectory();

        HandleEnableDisableControl(request.X, 0);
        HandleEnableDisableControl(request.Y, 1);
        HandleEnableDisableControl(request.Z, 2);
        HandleEnableDisableControl(request.Z, 3);
        HandleEnableDisableControl(request.Z, 4);
        HandleEnableDisableControl(request.Z, 5);

        return true;
    }

    void RobotState::HandleEnableDisableControl(int8_t &request, int axis)
    {
         if (request != -1)
         {
             enableAxisController_[axis] = bool(request);
         }
    }

    bool RobotState::EnableThrustersServerCallback(proc_control::EnableThrustersRequest &request, proc_control::EnableThrustersResponse &response)
    {
        enableThruster_ = bool(request.isEnable);

        return true;
    }


    bool RobotState::ClearWayPointServiceCallback(proc_control::ClearWaypointRequest &request, proc_control::ClearWaypointResponse &response)
    {
        UpdateInput();
        desiredPose_         = actualPose_;
        desiredTwist_        = actualTwist_;
        desiredAcceleration_ = actualAcceleration_;

        trajectoryManager_->ResetTrajectory();

        PosePublisher(desiredPose_, targetPublisher_);

        return true;
    }

    void RobotState::PosePublisher(const Eigen::VectorXd &pose, ros::Publisher &posePublisher)
    {
        geometry_msgs::Pose poseMsg;
        EigenVectorToPoseMsg(pose, poseMsg);

        posePublisher.publish(poseMsg);
    }

    void RobotState::TargetReachedPublisher(const bool isTargetReached)
    {
        proc_control::TargetReached msg_target_reached;
        msg_target_reached.target_is_reached = static_cast<unsigned char>(isTargetReached ? 1 : 0);
        targetIsReachedPublisher_.publish(msg_target_reached);
    }


    void RobotState::TwistPublisher(const Eigen::VectorXd &twist, ros::Publisher &twistPublisher)
    {
        geometry_msgs::Twist twistMsg;
        EigenVectorToTwistMsg(twist, twistMsg);

        twistPublisher.publish(twistMsg);
    }

    void RobotState::WrenchPublisher(Eigen::VectorXd &wrench, ros::Publisher &wrenchPublisher)
    {
        for (int i = 0; i < 6; i++)
        {
            if (!enableAxisController_[i])
            {
                wrench[i] = 0.0f;
            } else
            {
                wrench[i] = std::min(std::max(wrench[i], -100.0), 100.0);
            }

        }

         if (enableThruster_)
         {
             geometry_msgs::Wrench wrenchMsg;
             EigenVectorToWrenchMsg(wrench, wrenchMsg);

             wrenchPublisher.publish(wrenchMsg);
         }
    }

    control::TrajectoryGeneratorType RobotState::CreateTrajectoryParameters(const double time, const Eigen::VectorXd &startPose, const Eigen::VectorXd &endPose)
    {
        control::TrajectoryGeneratorType trajectoryParams;

        trajectoryParams.time      = time;
        trajectoryParams.startPose = startPose;
        trajectoryParams.endPose   = endPose;

        return trajectoryParams;
    }

    std::vector<bool> RobotState::IsInBoundingBox(Eigen::VectorXd const &error)
    {
        std::vector<bool> isInBoundingBox = {std::fabs(error[0]) <= (*pBbox_)[0], std::fabs(error[1]) <= (*pBbox_)[1], std::fabs(error[2]) <= (*pBbox_)[2],
                                             std::fabs(error[3]) <= (*pBbox_)[3], std::fabs(error[4]) <= (*pBbox_)[4], std::fabs(error[5]) <= (*pBbox_)[5]};

        return isInBoundingBox;
    }

    bool RobotState::SetBoundingBoxServiceCallback(proc_control::SetBoundingBoxRequest &request, proc_control::SetBoundingBoxResponse &response)
    {
        (*pBbox_)[0] = request.X;
        (*pBbox_)[1] = request.Y;
        (*pBbox_)[2] = request.Z;
        (*pBbox_)[3] = request.ROLL;
        (*pBbox_)[4] = request.PITCH;
        (*pBbox_)[5] = request.YAW;
         return true;
    }

    bool RobotState::ResetBoundingBoxServiceCallback(proc_control::ResetBoundingBoxRequest &request, proc_control::ResetBoundingBoxResponse &response)
    {
        *pBbox_ = bbox_;
        return true;
    }

    void RobotState::ControlModeChange()
    {
        UpdateInput();
        desiredPose_         = actualPose_;
        desiredTwist_        = Eigen::VectorXd::Zero(control::CARTESIAN_SPACE);
        desiredTwist_[2]     = actualPose_[2];
        desiredTwist_[5]     = actualPose_[5];
        desiredAcceleration_ = Eigen::VectorXd::Zero(control::CARTESIAN_SPACE);

        trajectoryManager_->ResetTrajectory();

        PosePublisher(desiredPose_, targetPublisher_);
        TwistPublisher(desiredTwist_, velocityTargetPublisher_);
    }

}