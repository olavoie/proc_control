#ifndef PROC_CONTROL_PIDCONTROLLER_H
#define PROC_CONTROL_PIDCONTROLLER_H

#include <memory>
#include <string>
#include <control_library/ControlType.h>
#include <control_library/toolbox/ContinuousTimePid.h>
#include "ControllerIF.h"
#include "proc_control/ParametersManager/PIDParameters.h"


namespace proc_control
{
    class PIDController : public ControllerIF
    {
    public:
        PIDController(const std::string & controllerType);
        virtual ~PIDController() = default;

        Eigen::VectorXd ComputedWrenchFromError(control::ControllerCMD & command) override;

    private:

        std::list<std::unique_ptr<control::ContinuousTimePid>> pidController_;
        std::vector<std::unique_ptr<PIDParameters>>            pidParameters_;

        std::list<std::string> CommandedAxis{"x", "y", "z", "roll", "pitch", "yaw"};

    };
}

#endif //PROC_CONTROL_PIDCONTROLLER_H