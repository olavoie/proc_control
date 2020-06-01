/**
 * \file	proc_control_node.h
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

#ifndef PROC_CONTROL_CONTROL_NODE_H
#define PROC_CONTROL_CONTROL_NODE_H

#include <ros/ros.h>
#include <memory>

#include "proc_control/RobotData/RobotState.h"
#include "proc_control/Controller/ControllerIF.h"
#include "proc_control/Mode/PositionMode.h"

#include <sonia_msgs/SetPositionTarget.h>
#include <sonia_msgs/SetControlMode.h>
#include <sonia_msgs/SetDecoupledTarget.h>

namespace proc_control{

    class ProcControlNode{
    public:
        const bool GlobalTarget = true;
        const bool LocalTarget = false;

        //==============================================================================
        // C / D T O R S   S E C T I O N
        //------------------------------------------------------------------------------

        ProcControlNode(const ros::NodeHandlePtr &nh);

        ~ProcControlNode();

        //==========================================================================
        // P U B L I C   M E T H O D S

        void ControlLoop();

        bool SetControlModeCallback(sonia_msgs::SetControlModeRequest &request,
                                    sonia_msgs::SetControlModeResponse &response);
        bool SetGlobalTargetPositionCallback(sonia_msgs::SetPositionTargetRequest &request,
                                             sonia_msgs::SetPositionTargetResponse &response);
        bool SetLocalTargetPositionCallback(sonia_msgs::SetPositionTargetRequest &request,
                                            sonia_msgs::SetPositionTargetResponse &response);
        bool SetGlobalDecoupledTargetPositionCallback(sonia_msgs::SetDecoupledTargetRequest &request,
                                                     sonia_msgs::SetDecoupledTargetResponse &response);
        bool SetLocalDecoupledTargetPositionCallback(sonia_msgs::SetDecoupledTargetRequest &request,
                                            sonia_msgs::SetDecoupledTargetResponse &response);


    private:
        //==========================================================================
        // P R I V A T E   M E T H O D S


        //==========================================================================
        // P R I V A T E   M E M B E R S
        ros::NodeHandlePtr nh_;

        ros::ServiceServer setControlModeServer_;
        ros::ServiceServer setLocalTargetServer_;
        ros::ServiceServer setGlobalTargetServer_;
        ros::ServiceServer setGlobalDecoupledTargetServer_;
        ros::ServiceServer setLocalDecoupledTargetServer_;

        std::shared_ptr<RobotState>    robotState_;
        std::shared_ptr<ControlModeIF> controlMode_;
        std::shared_ptr<ControlModeIF> positionModePID_;
        std::shared_ptr<ControlModeIF> positionModePPI_;
        std::shared_ptr<ControlModeIF> velocityMode_;

        enum controlMode{PositionMode_ = 0, PPIMode_, VelocityModeB_};
    };


}


#endif //PROC_CONTROL_CONTROL_NODE_H