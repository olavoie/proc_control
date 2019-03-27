#include "VisionMode.h"

namespace proc_control
{

    VisionMode::VisionMode(std::shared_ptr<RobotState> &robotState, std::unique_ptr<ControllerIF> &controlAUV):
        robotState_{robotState},
        controlAUV_{std::move(controlAUV)},
        actualVisionPose_{Eigen::VectorXd::Zero(control::CARTESIAN_SPACE)},
        desiredOffset_{Eigen::VectorXd::Zero(control::CARTESIAN_SPACE)}
    {
        controllerCommand_.errorPose     = Eigen::VectorXd::Zero(control::CARTESIAN_SPACE);
        controllerCommand_.errorVelocity = Eigen::VectorXd::Zero(control::CARTESIAN_SPACE);
        controllerCommand_.velocity      = Eigen::VectorXd::Zero(control::CARTESIAN_SPACE);
        controllerCommand_.acceleration  = Eigen::VectorXd::Zero(control::CARTESIAN_SPACE);
        controllerCommand_.orientation   = Eigen::Vector3d::Zero();
    }

    void VisionMode::Process()
    {
        actualVisionPose_   = robotState_->GetActualVisionPose();

        desiredOffset_ = robotState_->GetDesiredVisionOffset();

        GetLocalError(desiredOffset_, controllerCommand_.errorPose);
        robotState_->PosePublisher(desiredOffset_, robotState_->GetDebugTargetPublisher());

        robotState_->TwistPublisher(controllerCommand_.errorPose, robotState_->GetControllerTwistErrorPublisher()); //débogage

        Eigen::VectorXd actuation = Eigen::VectorXd::Zero(control::CARTESIAN_SPACE);
        actuation = controlAUV_->ComputedWrenchFromError(controllerCommand_);

        robotState_->WrenchPublisher(actuation, robotState_->GetCommandDebugPublisher());
    }

    void VisionMode::SetTarget(bool isGlobal, Eigen::VectorXd &targetPose)
    {
        robotState_->SetDesiredVisionOffset(targetPose);
    }

    void VisionMode::SetDecoupledTarget(bool isGlobal, const std::vector<bool> &keepTarget, Eigen::VectorXd &targetPose)
    {
    }

    void VisionMode::GetLocalError(Eigen::VectorXd &targetPose, Eigen::VectorXd &localError)
    {
        actualPoseH_ = control::HomogeneousMatrix(actualVisionPose_);
        targetPoseH_ = control::HomogeneousMatrix(targetPose);
        localErrorH_ = actualPoseH_.inverse() * targetPoseH_;

        localError << localErrorH_.translation(), localErrorH_.linear().eulerAngles(0, 1, 2) * RAD_TO_DEGREE;
    }
}