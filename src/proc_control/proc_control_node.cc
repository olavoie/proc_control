/**
 * \file	proc_control_node.cc
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

#include "proc_control_node.h"
#include "proc_control/Mode/VelocityMode.h"
#include "proc_control/Mode/VisionMode.h"
#include "proc_control/Controller/PIDController.h"
#include "proc_control/Controller/PPIController.h"
#include "proc_control/Controller/BController.h"


namespace proc_control{

    ProcControlNode::ProcControlNode(const ros::NodeHandlePtr &nh) :
        nh_(nh),
        robotState_(nullptr),
        controlMode_(nullptr),
        positionModePID_(nullptr),
        positionModePPI_(nullptr),
        velocityMode_(nullptr),
        visionMode_(nullptr)
    {

        setControlModeServer_ = nh->advertiseService("/proc_control/set_control_mode",
                                                     &ProcControlNode::SetControlModeCallback, this);
        setGlobalTargetServer_ =
                nh_->advertiseService("/proc_control/set_global_target",
                                      &ProcControlNode::SetGlobalTargetPositionCallback, this);
        setLocalTargetServer_ =
                nh_->advertiseService("/proc_control/set_local_target",
                                      &ProcControlNode::SetLocalTargetPositionCallback, this);

        setGlobalDecoupledTargetServer_ = nh_->advertiseService("/proc_control/set_global_decoupled_target",
                                                                &ProcControlNode::SetGlobalDecoupledTargetPositionCallback, this);
        setLocalDecoupledTargetServer_ = nh_->advertiseService("/proc_control/set_local_decoupled_target",
                                                                &ProcControlNode::SetLocalDecoupledTargetPositionCallback, this);

        robotState_    = std::make_shared<proc_control::RobotState>(nh_);
        std::unique_ptr<ControllerIF> pidControlAUV         = std::make_unique<PIDController>("position");
        std::unique_ptr<ControllerIF> ppiControlAUV         = std::make_unique<PPIController>();
        std::unique_ptr<ControllerIF> pidVelocityControlAUV = std::make_unique<PIDController>("velocity");
        std::unique_ptr<ControllerIF> pidVisionControlAUV   = std::make_unique<PIDController>("vision");

        positionModePID_ = std::make_shared<proc_control::PositionMode>(robotState_, pidControlAUV);
        positionModePPI_ = std::make_shared<proc_control::PositionMode>(robotState_, ppiControlAUV);
        velocityMode_    = std::make_shared<proc_control::VelocityMode>(robotState_, pidVelocityControlAUV);
        visionMode_      = std::make_shared<proc_control::VisionMode>(robotState_, pidVisionControlAUV);

        controlMode_   = positionModePID_;
    }

    ProcControlNode::~ProcControlNode()
    {
        setControlModeServer_.shutdown();
        setGlobalDecoupledTargetServer_.shutdown();
        setLocalDecoupledTargetServer_.shutdown();
        setGlobalTargetServer_.shutdown();
        setLocalTargetServer_.shutdown();
    }

    //==============================================================================
    // M E T H O D   S E C T I O N
    void ProcControlNode::ControlLoop()
    {
        robotState_->UpdateInput();
        controlMode_->Process();
    }

    bool ProcControlNode::SetControlModeCallback(proc_control::SetControlModeRequest &request,
                                                 proc_control::SetControlModeResponse &response) {

        controlMode mode = static_cast<controlMode>(request.mode);

        robotState_->ControlModeChange();

        switch (mode){
            case PositionMode_:
                controlMode_ = nullptr;
                controlMode_ = positionModePID_;
                break;
            case PPIMode_:
                controlMode_ = nullptr;
                controlMode_ = positionModePPI_;
                break;
            case VelocityModeB_:
                controlMode_ = nullptr;
                controlMode_ = velocityMode_;
                break;
            case VisionMode_:
                controlMode_ = nullptr;
                controlMode_ = visionMode_;
                break;
            default :
                controlMode_ = nullptr;
                controlMode_ = positionModePID_;
        }

        return true;

    }

    bool ProcControlNode::SetGlobalTargetPositionCallback(proc_control::SetPositionTargetRequest &request,
                                                          proc_control::SetPositionTargetResponse &response) {

        Eigen::VectorXd targetPose = Eigen::VectorXd::Zero(control::CARTESIAN_SPACE);

        targetPose    << request.X, request.Y, request.Z, 0.0, 0.0, request.YAW * DEGREE_TO_RAD;

        controlMode_->SetTarget(GlobalTarget, targetPose);

        return true;
    }

    bool ProcControlNode::SetLocalTargetPositionCallback(proc_control::SetPositionTargetRequest &request,
                                                         proc_control::SetPositionTargetResponse &response) {

        Eigen::VectorXd targetPose = Eigen::VectorXd::Zero(control::CARTESIAN_SPACE);

        targetPose    << request.X, request.Y, request.Z,  0.0, 0.0, request.YAW * DEGREE_TO_RAD;

        controlMode_->SetTarget(LocalTarget, targetPose);

        return true;

    }

    bool ProcControlNode::SetGlobalDecoupledTargetPositionCallback(proc_control::SetDecoupledTargetRequest &request,
                                                                   proc_control::SetDecoupledTargetResponse &response)
    {
        Eigen::VectorXd targetPose = Eigen::VectorXd::Zero(control::CARTESIAN_SPACE);

        std::vector<bool> keepTarget = {(bool)request.keepX, (bool)request.keepY, (bool)request.keepZ, (bool)request.keepROLL,
                                        (bool)request.keepPITCH, (bool)request.keepYAW};

        targetPose    << request.X, request.Y, request.Z,  0.0, 0.0, request.YAW * DEGREE_TO_RAD;

        controlMode_->SetDecoupledTarget(GlobalTarget, keepTarget, targetPose);

        return true;
    }

    bool ProcControlNode::SetLocalDecoupledTargetPositionCallback(proc_control::SetDecoupledTargetRequest &request,
                                                                  proc_control::SetDecoupledTargetResponse &response)
    {
        Eigen::VectorXd targetPose = Eigen::VectorXd::Zero(control::CARTESIAN_SPACE);

        std::vector<bool> keepTarget = {(bool)request.keepX, (bool)request.keepY, (bool)request.keepZ, (bool)request.keepROLL,
                                        (bool)request.keepPITCH, (bool)request.keepYAW};

        targetPose    << request.X, request.Y, request.Z, 0.0, 0.0, request.YAW * DEGREE_TO_RAD;

        controlMode_->SetDecoupledTarget(LocalTarget, keepTarget, targetPose);

        return true;
    }
}