/**
 * \file	PositionMode.cc
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


#include <control_library/toolbox/Transformation.h>
#include "PositionMode.h"

namespace proc_control {

    PositionMode::PositionMode(std::shared_ptr<RobotState> & robotState, std::unique_ptr<ControllerIF> & controlAUV) :
        ControlModeIF(),
        robotState_(robotState),
        controlAuv_{std::move(controlAUV)},
        trajectoryManager_{robotState_->GetTrajectoryManager()},
        localError_{Eigen::VectorXd::Zero(control::CARTESIAN_SPACE)},
        localDesiredError_{Eigen::VectorXd::Zero(control::CARTESIAN_SPACE)},
        targetPose_{Eigen::VectorXd::Zero(control::CARTESIAN_SPACE)},
        actualPose_{Eigen::VectorXd::Zero(control::CARTESIAN_SPACE)},
        actualTwist_{Eigen::VectorXd::Zero(control::CARTESIAN_SPACE)},
        desiredPose_{Eigen::VectorXd::Zero(control::CARTESIAN_SPACE)},
        lastTime_{std::chrono::steady_clock::now()},
        targetReachedTime_{std::chrono::steady_clock::now()},
        timeNow_{std::chrono::steady_clock::now()},
        deltaTimeS_{0.0},
        stabilityCount_{0}
    {
        controllerCommand_.errorPose     = Eigen::VectorXd::Zero(control::CARTESIAN_SPACE);
        controllerCommand_.errorVelocity = Eigen::VectorXd::Zero(control::CARTESIAN_SPACE);
        controllerCommand_.velocity      = Eigen::VectorXd::Zero(control::CARTESIAN_SPACE);
        controllerCommand_.acceleration  = Eigen::VectorXd::Zero(control::CARTESIAN_SPACE);
        controllerCommand_.orientation   = Eigen::Vector3d::Zero();
    }

    void PositionMode::Process()
    {
        actualPose_  = robotState_->GetActualPose();
        actualTwist_ = robotState_->GetActualTwist();

        targetPose_ = robotState_->GetDesiredPose();
        targetTwist_ = robotState_->GetDesiredTwist();

        timeNow_ = std::chrono::steady_clock::now();

        deltaTimeS_ = double(std::chrono::duration_cast<std::chrono::nanoseconds>(timeNow_ - lastTime_).count()) / (double(1E9));

        if (deltaTimeS_ > (0.01f))
        {
            if (trajectoryManager_->IsTrajectoryComputed())
            {
                trajectory_ = trajectoryManager_->GetSpeedTrajectory(); //change value
                targetPose_ = trajectory_.pose;
                targetTwist_ = trajectory_.twist;
            }

            GetLocalError(targetPose_, controllerCommand_.errorPose);
            GetLocalErrorSpeed(targetTwist_, controllerCommand_.errorVelocity);
            
            //robotState_->PosePublisher(controllerCommand_.errorPose * DEGREE_TO_RAD, robotState_->GetControllerPoseErrorPublisher());
            robotState_->TwistPublisher(controllerCommand_.errorVelocity, robotState_->GetControllerTwistErrorPublisher());

            /*robotState_->PosePublisher(targetPose_, robotState_->GetDebugTargetPublisher());

            GetLocalError(targetPose_, controllerCommand_.errorPose);
            robotState_->PosePublisher(controllerCommand_.errorPose * DEGREE_TO_RAD, robotState_->GetControllerPoseErrorPublisher());
            GetLocalError(desiredPose_, localDesiredError_);
            robotState_->TargetReachedPublisher(EvaluateTargetReached(localDesiredError_));*/

            controllerCommand_.velocity = actualTwist_;
            // Calculate required actuation
            Eigen::VectorXd actuation = Eigen::VectorXd::Zero(control::CARTESIAN_SPACE);
            actuation = controlAuv_->ComputedWrenchFromError(controllerCommand_);

            robotState_->WrenchPublisher(actuation, robotState_->GetCommandDebugPublisher());

        }
        lastTime_ = timeNow_;
    }

    void PositionMode::SetTarget(bool isGlobal, Eigen::VectorXd & targetPose)
    {
        actualPose_ = robotState_->GetActualPose();

        std::vector<bool> keepTarget = {false, false, false, false, false, false};
        if (isGlobal)
        {
            SetGlobalTarget(targetPose, keepTarget);
        }
        else
        {
            SetLocalTarget(targetPose, keepTarget);
        }
        robotState_->SetDesiredPose(desiredPose_);
    }

    void PositionMode::SetDecoupledTarget(bool isGlobal, const std::vector<bool>  & keepTarget, Eigen::VectorXd & targetPose)
    {
        actualPose_ = robotState_->GetActualPose();

        if (isGlobal)
        {
            SetGlobalTarget(targetPose, keepTarget);
        }
        else
        {
            SetLocalTarget(targetPose, keepTarget);
        }

        robotState_->SetDesiredPose(desiredPose_);
    }

    void PositionMode::SetGlobalTarget(Eigen::VectorXd & targetPose, const std::vector<bool> & keepTarget)
    {

        trajectoryManager_->ResetTrajectory();

        targetReachedTime_ = std::chrono::steady_clock::now();

        for (size_t i = 0; i < control::CARTESIAN_SPACE; i++)
        {
            if (!keepTarget[i])
                desiredPose_[i] = targetPose[i];
        }

        CreateTrajectory(actualPose_, desiredPose_);

        robotState_->PosePublisher(desiredPose_, robotState_->GetTargetPublisher());
    }

    void PositionMode::SetLocalTarget(Eigen::VectorXd & targetPose, const std::vector<bool> & keepTarget)
    {

        trajectoryManager_->ResetTrajectory();

        targetReachedTime_ = std::chrono::steady_clock::now();

        Eigen::Affine3d localAskPoseH;

        for (int i = 0; i < control::CARTESIAN_SPACE; i++)
        {
            if (keepTarget[i])
                actualPose_[i]    = desiredPose_[i];
        }

        targetPoseH_ = control::HomogeneousMatrix(targetPose);
        actualPoseH_ = control::HomogeneousMatrix(actualPose_);

        localAskPoseH = actualPoseH_ * targetPoseH_;

        desiredPose_ << localAskPoseH.translation(), localAskPoseH.linear().eulerAngles(0, 1, 2);

        CreateTrajectory(actualPose_, desiredPose_);

        robotState_->PosePublisher(desiredPose_, robotState_->GetTargetPublisher());
    }

    void PositionMode::CreateTrajectory(Eigen::VectorXd &actualPose, Eigen::VectorXd &desiredPose)
    {
        control::TrajectoryGeneratorType trajectoryParams = robotState_->CreateTrajectoryParameters(1, actualPose, desiredPose);
        trajectoryManager_->SpeedGenerateTrajectory(trajectoryParams); // changed value
    }

    void PositionMode::GetLocalError(Eigen::VectorXd & targetPose, Eigen::VectorXd & localError)
    {
        actualPoseH_ = control::HomogeneousMatrix(actualPose_);
        targetPoseH_ = control::HomogeneousMatrix(targetPose);
        localErrorH_  = actualPoseH_.inverse() * targetPoseH_;

        localError << localErrorH_.translation(), localErrorH_.linear().eulerAngles(0, 1, 2) * RAD_TO_DEGREE;
    }

    void PositionMode::GetLocalErrorSpeed(Eigen::VectorXd &targetPose, Eigen::VectorXd &localError)
    {
        actualPoseH_ = control::HomogeneousMatrix(actualPose_);
        targetPoseH_ = control::HomogeneousMatrix(targetPose);
        localErrorH_ = actualPoseH_.inverse() * targetPoseH_;

        localError[0]    = targetPose[0] - actualTwist_[0];
        localError[1]    = targetPose[1] - actualTwist_[1];
        localError[2]    = targetPose[2] - actualPose_[2];

        localError << localError[0], localError[1], localError[2], localErrorH_.linear().eulerAngles(0, 1, 2) * RAD_TO_DEGREE;
    }

    bool PositionMode::EvaluateTargetReached(Eigen::VectorXd &error)
    {
        bool targetIsReached = false;

        double deltaTime_s = double(std::chrono::duration_cast<std::chrono::nanoseconds>(timeNow_ - targetReachedTime_).count()) / (double(1E9));

        std::vector<bool>  isTargetReached = robotState_->IsInBoundingBox(error);

        if (isTargetReached[0] && isTargetReached[1] && isTargetReached[2] && isTargetReached[3] && isTargetReached[4] && isTargetReached[5])
        {
            stabilityCount_++;
        }
        else
        {
            stabilityCount_ = 0;
        }

        if (stabilityCount_ > 14 || deltaTime_s > 30.0){
            targetIsReached = true;
        }

        return targetIsReached;

    }
}


