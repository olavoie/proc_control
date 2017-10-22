/**
 * \file	ControlAlgorithm.h
 * \author	Jeremie St-Jules <jeremie.st.jules.prevost@gmail.com>
 * \coauthor Francis Masse <francis.masse05@gmail.com>
 * \date	10/17/16
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

#ifndef PROC_CONTROL_CONTROLALGORITHM_H
#define PROC_CONTROL_CONTROLALGORITHM_H

#include <array>
#include "proc_control/config/config_manager.h"
#include "proc_control/PID6AxisConfig.h"

class ControlAlgorithm
{
 public:
    //==========================================================================
    // C O N S T  ,  T Y P E D E F   A N D   E N U M
    enum ControllerType{PID = 0, PI, PD, P};
    //==========================================================================
    // P U B L I C   C / D T O R S
    ControlAlgorithm(int controller);

    //==========================================================================
    // P U B L I C   M E T H O D S
    virtual std::array<double, 6> CalculateActuationForError(const std::array<double, 6> &error) = 0;

    ControllerType controller_type;




};
#endif //PROC_CONTROL_CONTROLALGORITHM_H
