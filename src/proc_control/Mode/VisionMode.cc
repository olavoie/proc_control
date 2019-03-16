#include "VisionMode.h"

namespace proc_control
{

    VisionMode::VisionMode(std::shared_ptr<RobotState> &robotState, std::unique_ptr<ControllerIF> &controlAUV):
        robotState_{robotState},
        controlAUV_{std::move(controlAUV)},
        actualTwist_{Eigen::VectorXd::Zero(control::CARTESIAN_SPACE)},
        actualPose_{Eigen::VectorXd::Zero(control::CARTESIAN_SPACE)},
        desiredTwist_{Eigen::VectorXd::Zero(control::CARTESIAN_SPACE)}
    {
        controllerCommand_.errorPose     = Eigen::VectorXd::Zero(control::CARTESIAN_SPACE);
        controllerCommand_.errorVelocity = Eigen::VectorXd::Zero(control::CARTESIAN_SPACE);
        controllerCommand_.velocity      = Eigen::VectorXd::Zero(control::CARTESIAN_SPACE);
        controllerCommand_.acceleration  = Eigen::VectorXd::Zero(control::CARTESIAN_SPACE);
        controllerCommand_.orientation   = Eigen::Vector3d::Zero();
    }

    void VisionMode::Process()
    {
        actualPose_   = robotState_->GetActualPose();
        actualTwist_  = robotState_->GetActualTwist();

        desiredTwist_ = robotState_->GetDesiredTwist();

        GetLocalError(desiredTwist_, controllerCommand_.errorPose);
        controllerCommand_.errorVelocity = controllerCommand_.errorPose;
        robotState_->PosePublisher(desiredTwist_, robotState_->GetDebugTargetPublisher());

        robotState_->TwistPublisher(controllerCommand_.errorVelocity, robotState_->GetControllerTwistErrorPublisher());

        Eigen::VectorXd actuation = Eigen::VectorXd::Zero(control::CARTESIAN_SPACE);
        actuation = controlAUV_->ComputedWrenchFromError(controllerCommand_);

        robotState_->WrenchPublisher(actuation, robotState_->GetCommandDebugPublisher());
    }

    void VisionMode::SetTarget(bool isGlobal, Eigen::VectorXd &targetPose)
    {
        robotState_->SetDesiredTwist(targetPose);
        robotState_->TwistPublisher(targetPose, robotState_->GetVelocityTargetPublisher());
    }

    void VisionMode::SetDecoupledTarget(bool isGlobal, const std::vector<bool> &keepTarget, Eigen::VectorXd &targetPose)
    {
    }

    void VisionMode::GetLocalError(Eigen::VectorXd &targetPose, Eigen::VectorXd &localError)
    {
        actualPoseH_ = control::HomogeneousMatrix(actualPose_);
        targetPoseH_ = control::HomogeneousMatrix(targetPose);
        localErrorH_ = actualPoseH_.inverse() * targetPoseH_;

        localError[0]    = targetPose[0] - actualTwist_[0];
        localError[1]    = targetPose[1] - actualTwist_[1];
        localError[2]    = targetPose[2] - actualPose_[2];

        localError << localError[0], localError[1], localError[2], localErrorH_.linear().eulerAngles(0, 1, 2) * RAD_TO_DEGREE;
    }
}