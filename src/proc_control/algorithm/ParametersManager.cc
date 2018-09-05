/**
 * \file	ParametersManager.cc
 * \author	Olivier Lavoie <olavoie9507@gmail.com>
 * \date	10/24/17
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

#include <fstream>
#include "ParametersManager.h"
#include "proc_control/property.h"


ParametersManager::ParametersManager(std::string &axe_name, std::string &mode , std::shared_ptr<ControllerParameters> &controller_parameters):
        ConfigManager(axe_name + "_axis" + mode + "_controller"), controller_parameters_(controller_parameters)
{

    controller_parameters_ = controller_parameters;
    file_path_ = kConfigPath + "/Controllers_parameters/" + axe_name + "_" + mode + "_controller_parameters" + kConfigExt;
    Init();

}

//==============================================================================
// M E T H O D   S E C T I O N

//-----------------------------------------------------------------------------
//

void ParametersManager::OnDynamicReconfigureChange(const ControllerConfig &config )
{

    controller_parameters_->Parameters_Map["P"] = config.P;
    controller_parameters_->Parameters_Map["I"] = config.I;
    controller_parameters_->Parameters_Map["D"] = config.D;
    controller_parameters_->Parameters_Map["I_LIMIT"] = config.I_LIMIT;
    controller_parameters_->Parameters_Map["MIN_ACTUATION"] = config.MIN_ACTUATION;
    controller_parameters_->Parameters_Map["MAX_ACTUATION"] = config.MAX_ACTUATION;
    BBox_ = config.BBox;
    constante_depth_force_ = config.CONSTANT_DEPTH_FORCE;
    lpf_beta_ = config.LPF_BETA;

    current_BBox_ = BBox_;

}

//-----------------------------------------------------------------------------
//

void ParametersManager::WriteConfigFile(const ControllerConfig &config )
{

    YAML::Emitter out;

    out << YAML::BeginMap;
    out << YAML::Key << "P";
    out << YAML::Value << controller_parameters_->Parameters_Map["P"];
    out << YAML::Key << "I";
    out << YAML::Value << controller_parameters_->Parameters_Map["I"];
    out << YAML::Key << "D";
    out << YAML::Value << controller_parameters_->Parameters_Map["D"];
    out << YAML::Key << "I_LIMIT";
    out << YAML::Value << controller_parameters_->Parameters_Map["I_LIMIT"];
    out << YAML::Key << "MIN_ACTUATION";
    out << YAML::Value << controller_parameters_->Parameters_Map["MIN_ACTUATION"];
    out << YAML::Key << "MAX_ACTUATION";
    out << YAML::Value << controller_parameters_->Parameters_Map["MAX_ACTUATION"];
    out << YAML::Key << "BBox";
    out << YAML::Value << BBox_;
    out << YAML::Key << "CONSTANT_DEPTH_FORCE";
    out << YAML::Value << constante_depth_force_;
    out << YAML::Key << "LPF_BETA";
    out << YAML::Value << lpf_beta_;

    std::ofstream fout(file_path_);
    fout << out.c_str();

}

//-----------------------------------------------------------------------------
//

void ParametersManager::ReadConfigFile(ControllerConfig &config )
{

    YAML::Node node = YAML::LoadFile(file_path_);

    if (node["P"])
        controller_parameters_->Parameters_Map["P"] = node["P"].as<double>();

    if (node["I"])
        controller_parameters_->Parameters_Map["I"] = node["I"].as<double>();

    if (node["D"])
        controller_parameters_->Parameters_Map["D"] = node["D"].as<double>();

    if (node["I_LIMIT"])
        controller_parameters_->Parameters_Map["I_LIMIT"] = node["I_LIMIT"].as<double>();

    if (node["MIN_ACTUATION"])
        controller_parameters_->Parameters_Map["MIN_ACTUATION"] = node["MIN_ACTUATION"].as<double>();

    if (node["MAX_ACTUATION"])
        controller_parameters_->Parameters_Map["MAX_ACTUATION"] = node["MAX_ACTUATION"].as<double>();

    if (node["BBox"])
        BBox_ = node["BBox"].as<double>();

    if (node["CONSTANT_DEPTH_FORCE"])
        constante_depth_force_ = node["CONSTANT_DEPTH_FORCE"].as<double>();

    if (node["LPF_BETA"])
        lpf_beta_ = node["LPF_BETA"].as<double>();

    config.P = controller_parameters_->Parameters_Map["P"];
    config.I = controller_parameters_->Parameters_Map["I"];
    config.D = controller_parameters_->Parameters_Map["D"];
    config.I_LIMIT = controller_parameters_->Parameters_Map["I_LIMIT"];
    config.MIN_ACTUATION = controller_parameters_->Parameters_Map["MIN_ACTUATION"];
    config.MAX_ACTUATION = controller_parameters_->Parameters_Map["MAX_ACTUATION"];
    config.BBox = BBox_;
    config.CONSTANT_DEPTH_FORCE= constante_depth_force_;
    config.LPF_BETA= lpf_beta_;

    current_BBox_ = BBox_;

}

double ParametersManager::GetBBox() {
    return current_BBox_;
}

void ParametersManager::GetBBox(double BBox) {
    current_BBox_ =  BBox;
}

void ParametersManager::ResetBBox(){
    current_BBox_ = BBox_;
}

double ParametersManager::GetConstanteDepthForce() {
    return constante_depth_force_;
}

double ParametersManager::GetLPFBeta() {
    return lpf_beta_;
}