/**
 * \file	trajectory_yaw.cc
 * \author Francis Masse <francis.masse05@gmail.com>
 * \date	25/06/17
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


#include <iostream>
#include "trajectory.h"

namespace proc_control{

//==============================================================================
// C / D T O R S   S E C T I O N

//------------------------------------------------------------------------------
//
    Trajectory::Trajectory() {
        is_spline_calculated_ = false;
        spline_time_ = 0;
    }

//------------------------------------------------------------------------------
//
    Trajectory::~Trajectory() {}

//==============================================================================
// M E T H O D   S E C T I O N

//-----------------------------------------------------------------------------
//
    bool Trajectory::IsSplineCalculated() { return is_spline_calculated_; }

//-----------------------------------------------------------------------------
//
    void Trajectory::SetLinearSplineParameters(double initial_position, double finale_position) {
        this->initial_position_ = initial_position;
        this->final_position_ = finale_position;
        this->is_spline_calculated_ = true;
    }
//-----------------------------------------------------------------------------
//
    void Trajectory::SetOrientationSplineParameters(double initial_position, double finale_position,
                                                    bool best_trajectory, bool best_rotation) {
        this->initial_position_ = initial_position;
        this->final_position_ = finale_position;
        this->best_trajectory_ = best_trajectory;
        this->best_rotation_ = best_rotation;
        this->is_spline_calculated_ = true;
        SetRotation();
    }

    void Trajectory::SetRotation(){
        if (best_rotation_){
            first_rotation_ = 0;
            second_rotation_ = 360;
        } else{
            first_rotation_ = 360;
            second_rotation_ = 0;
        }

    }

//-----------------------------------------------------------------------------
//
    double Trajectory::ComputeLinearSpline(double dt) {

        spline_time_ += dt/5;

        if (spline_time_ >= 1.0) spline_time_ = 1.0;

        ComputeHermiteCubicSpline(this->initial_position_, this->final_position_);


        return current_position_;
    }
//-----------------------------------------------------------------------------
//
    double Trajectory::ComputeOrientationSpline(double dt){

        spline_time_ += dt/10;

        if (spline_time_ >= 1.0) spline_time_ = 1.0;

        if (best_trajectory_ and spline_time_ < 0.5){
            ComputeHermiteCubicSpline(this->initial_position_, first_rotation_);
        }else if (best_trajectory_){
            ComputeHermiteCubicSpline(second_rotation_, this->final_position_);
        }else{
            ComputeHermiteCubicSpline(this->initial_position_, this->final_position_);
        }

        return current_position_;
    }
//-----------------------------------------------------------------------------
//
    double Trajectory::ComputeHermiteCubicSpline(double pO, double p1) {

        double spline_time_squared = spline_time_ * spline_time_ ;
        double spline_time_cubed = spline_time_squared * spline_time_;

        current_position_ = (2*spline_time_cubed - 3*spline_time_squared + 1) * pO
                            + (-2*spline_time_cubed + 3*spline_time_squared) * p1;

        return current_position_;

    }


//-----------------------------------------------------------------------------
//
    void Trajectory::ResetSpline() {

        spline_time_ = 0.0;
        initial_position_ = 0.0;
        final_position_ = 0.0;
        current_position_ = 0.0;
        is_spline_calculated_ = false;
        hermite_spline_solution_[0] = 0.0;
        hermite_spline_solution_[1] = 0.0;
        hermite_spline_solution_[2] = 0.0;
        hermite_spline_solution_[3] = 0.0;
    }

}
