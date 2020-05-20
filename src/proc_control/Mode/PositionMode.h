/**
 * \file	PositionMode.h
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

#ifndef PROC_CONTROL_POSITIONMODE_H
#define PROC_CONTROL_POSITIONMODE_H

#include <chrono>
#include <memory>
#include <control_library/Trajectory/Trajectory.h>
#include <control_library/ControlType.h>

#include "proc_control/RobotData/RobotState.h"
#include "proc_control/Controller/ControllerIF.h"
#include "proc_control/Mode/ControlModeIF.h"

namespace proc_control
{

    class PositionMode : public ControlModeIF
    {
    public:

        explicit PositionMode(std::shared_ptr<RobotState> & robotState, std::unique_ptr<ControllerIF> & controlAUV);

        virtual ~PositionMode() = default;

        void Process() override;

        void SetTarget(bool isGlobal, Eigen::VectorXd & targetPose) override;
        void SetDecoupledTarget(bool isGlobal, const std::vector<bool>  & keepTarget, Eigen::VectorXd & targetPose) override;

    private:

        void SetLocalTarget(Eigen::VectorXd & targetPose, const std::vector<bool> & keepTarget);

        void SetGlobalTarget(Eigen::VectorXd & targetPose, const std::vector<bool> & keepTarget);

        bool EvaluateTargetReached(Eigen::VectorXd &error);

        void CreateTrajectory(Eigen::VectorXd &actualPose, Eigen::VectorXd &desiredPose);

        void GetLocalError(Eigen::VectorXd & targetPose, Eigen::VectorXd & localError);

        void GetLocalErrorSpeed(Eigen::VectorXd &targetPose, Eigen::VectorXd & localError);

        std::shared_ptr<RobotState>   robotState_;
        std::unique_ptr<ControllerIF> controlAuv_;

        std::shared_ptr<control::Trajectory> trajectoryManager_;

        Eigen::VectorXd localError_;
        Eigen::VectorXd localDesiredError_;
        Eigen::VectorXd targetPose_;
        Eigen::VectorXd targetTwist_;

        Eigen::VectorXd actualPose_;
        Eigen::VectorXd actualTwist_;
        Eigen::VectorXd desiredPose_;
        Eigen::VectorXd desiredTwist_;

        std::chrono::steady_clock::time_point lastTime_;
        std::chrono::steady_clock::time_point targetReachedTime_;

        Eigen::Affine3d actualPoseH_;
        Eigen::Affine3d targetPoseH_;
        Eigen::Affine3d localErrorH_;

        control::TrajectoryResult trajectory_;
        control::ControllerCMD    controllerCommand_;

        std::chrono::steady_clock::time_point timeNow_;
        double deltaTimeS_;

        int stabilityCount_;
    };
}


#endif //PROC_CONTROL_POSITIONMODE_H
