#ifndef PROC_CONTROL_TARGETMODE_H
#define PROC_CONTROL_TARGETMODE_H

#include <memory>
#include <control_library/ControlType.h>
#include "proc_control/RobotData/RobotState.h"
#include "proc_control/Controller/ControllerIF.h"
#include "proc_control/Mode/ControlModeIF.h"

namespace proc_control
{
    class TargetMode : public ControlModeIF
    {
    public:

        explicit TargetMode(std::shared_ptr<RobotState> & robotState, std::unique_ptr<ControllerIF> & controlAUV);

        virtual ~TargetMode() = default;

        void Process() override;

        void SetTarget(bool isGlobal, Eigen::VectorXd & targetPose) override;
        void SetDecoupledTarget(bool isGlobal, const std::vector<bool>  & keepTarget, Eigen::VectorXd & targetPose) override;

    private:

        void GetLocalError(Eigen::VectorXd & targetPose, Eigen::VectorXd & localError);

        std::shared_ptr<RobotState>   robotState_;
        std::shared_ptr<ControllerIF> controlAUV_;

        Eigen::VectorXd actualTwist_;
        Eigen::VectorXd actualPose_;
        Eigen::VectorXd desiredTwist_;

        Eigen::Affine3d actualPoseH_;
        Eigen::Affine3d targetPoseH_;
        Eigen::Affine3d localErrorH_;

        control::ControllerCMD    controllerCommand_;
    };
}
#endif //PROC_CONTROL_TARGETMODE_H
