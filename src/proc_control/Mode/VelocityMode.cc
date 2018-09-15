/**
 * \file	VelocityMode.cc
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

#include "VelocityMode.h"

namespace proc_control{

    VelocityMode::VelocityMode(const ros::NodeHandlePtr &nh): nh_(nh), inputData_(nh), control_auv_("velocity") {

        for (int i = 0; i < 6; i++){
            enable_axis_controller_[i] = true;
        }

        killSwitchSubscriber_ = nh_->subscribe("/provider_kill_mission/kill_switch_msg", 100,
                                               &VelocityMode::KillMissionCallback, this);
        enableControllerServer_ = nh_->advertiseService("/proc_control/enable_control",
                                                        &VelocityMode::enableControlServiceCallback, this);
        targetPublisher_ = nh_->advertise<proc_control::PositionTarget>("/proc_control/current_target", 100);

        twist_target_.setZero();

        UpdateInput();

        twist_target_[Z] = world_twist_[Z];
        twist_target_[YAW] = world_twist_[YAW];
    }

    VelocityMode::~VelocityMode(){
        enableControllerServer_.shutdown();
        killSwitchSubscriber_.shutdown();
    }

    void VelocityMode::Process(){

        EigenVector6d local_error = EigenVector6d::Zero();

        std::chrono::steady_clock::time_point now_time = std::chrono::steady_clock::now();

        UpdateInput();

        auto diff = now_time - last_time_;

        double deltaTime_s = double(std::chrono::duration_cast<std::chrono::nanoseconds>(diff).count()) / (double(1E9));

        if (deltaTime_s > (0.0001f)) {

            local_error = twist_target_;
            local_error[Z] = twist_target_[Z] - world_twist_[Z];

            EigenVector6d actuation = EigenVector6d::Zero();
            actuation = control_auv_.GetActuationForError(local_error);

            for (int i = 0; i < 6; i++) {
                if (!enable_axis_controller_[i]) actuation[i] = 0.0;
            }

            thrusterManager_.Commit(actuation);

        }

    }

    void VelocityMode::SetTarget(bool isGlobal, Eigen::Vector3d &translation, Eigen::Vector3d &orientation)
    {

        twist_target_ << translation, orientation;

        CurrentTargetVelocityPublisher();
    }

    void VelocityMode::SetDecoupledTarget(bool isGlobal, std::vector<bool> keepTarget, Eigen::Vector3d &translation, Eigen::Vector3d &orientation)
    {
        ROS_INFO("Not Implemented in this Mode");
    }

    void VelocityMode::UpdateInput()
    {
        world_twist_ << inputData_.GetVelocityTranslation(), inputData_.GetVelocityOrientation();
    }

    void VelocityMode::CurrentTargetVelocityPublisher()
    {
        proc_control::PositionTarget current_target;

        current_target.X = twist_target_[X];
        current_target.Y = twist_target_[Y];
        current_target.Z = twist_target_[Z];
        current_target.ROLL = twist_target_[ROLL] * RAD_TO_DEGREE;
        current_target.PITCH = twist_target_[PITCH] * RAD_TO_DEGREE;
        current_target.YAW = twist_target_[YAW] * RAD_TO_DEGREE;
        targetPublisher_.publish(current_target);
    }

    bool VelocityMode::enableControlServiceCallback(proc_control::EnableControlRequest &request,
                                                    proc_control::EnableControlResponse &response)
    {
        UpdateInput();

        if (request.X != request.DONT_CARE) {
            HandleEnableDisableControl(bool(request.X), X);
        }

        if (request.Y != request.DONT_CARE) {
            HandleEnableDisableControl(bool(request.Y), Y);
        }

        if (request.Z != request.DONT_CARE) {
            HandleEnableDisableControl(bool(request.Z), Z);
        }

        if (request.ROLL != request.DONT_CARE) {
            HandleEnableDisableControl(bool(request.ROLL), ROLL);
        }

        if (request.PITCH != request.DONT_CARE) {
            HandleEnableDisableControl(bool(request.PITCH), PITCH);
        }

        if (request.YAW != request.DONT_CARE) {
            HandleEnableDisableControl(bool(request.YAW), YAW);
        }

        std::vector<std::string> tmp{"X", "Y", "Z", "ROLL", "PITCH", "YAW"};
        ROS_INFO_STREAM("Active control : Velocity");
        for (int i = 0; i < 6; i++) {
            ROS_INFO_STREAM(tmp[i] + " : " + (enable_axis_controller_[i] ? "true" : "false"));
        }

        return true;
    }

    void VelocityMode::HandleEnableDisableControl(bool state, const size_t axis) {

        enable_axis_controller_[axis] = state;
        if (!enable_axis_controller_[axis]) world_twist_[axis] = 0.0;

    }

    void VelocityMode::KillMissionCallback(const provider_kill_mission::KillSwitchMsg::ConstPtr &state_in) {

        if (!state_in->state){
            for (int i = 0; i < 6; i++) {
                enable_axis_controller_[i] = false;
            }

            twist_target_ = EigenVector6d::Zero();
        }

    }

}