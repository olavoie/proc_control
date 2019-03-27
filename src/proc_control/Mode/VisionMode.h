#ifndef PROC_CONTROL_VISIONMODE_H
#define PROC_CONTROL_VISIONMODE_H

#include <memory>
#include <control_library/ControlType.h>
#include "proc_control/RobotData/RobotState.h"
#include "proc_control/Controller/ControllerIF.h"
#include "proc_control/Mode/ControlModeIF.h"

namespace proc_control
{
    class VisionMode : public ControlModeIF
    {
    public:

        explicit VisionMode(std::shared_ptr<RobotState> & robotState, std::unique_ptr<ControllerIF> & controlAUV);

        virtual ~VisionMode() = default;

        void Process() override;

        void SetTarget(bool isGlobal, Eigen::VectorXd & targetPose) override;
        void SetDecoupledTarget(bool isGlobal, const std::vector<bool>  & keepTarget, Eigen::VectorXd & targetPose) override;

    private:

        void GetLocalError(Eigen::VectorXd & targetPose, Eigen::VectorXd & localError);

        std::shared_ptr<RobotState>   robotState_;
        std::shared_ptr<ControllerIF> controlAUV_;

        Eigen::VectorXd desiredOffset_;
        Eigen::VectorXd actualVisionPose_;

        Eigen::Affine3d actualPoseH_;
        Eigen::Affine3d targetPoseH_;
        Eigen::Affine3d localErrorH_;

        control::ControllerCMD    controllerCommand_;
    };
}
#endif //PROC_CONTROL_VISIONMODE_H
