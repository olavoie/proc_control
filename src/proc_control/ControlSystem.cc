//
// Created by jeremie on 11/9/16.
//

#include "ControlSystem.h"
#include <eigen3/Eigen/Eigen>
#include <eigen3/Eigen/Geometry>
#include <lib_atlas/maths/matrix.h>

ControlSystem::ControlSystem(const ros::NodeHandlePtr &nh):
    atlas::ServiceServerManager<ControlSystem>()
{
  std::string base_node_name ("/proc_control/");
  nav_odometry_subs_ = nh->subscribe("/proc_navigation/odom", 100,
                                &ControlSystem::OdomCallback, this);


  RegisterService<proc_control::SetPositionTarget>(base_node_name + "set_global_target",
                                                 &ControlSystem::GlobalTargetServiceCallback, *this);
  RegisterService<proc_control::GetPositionTarget>(base_node_name + "get_target",
                                                 &ControlSystem::GetPositionTargetServiceCallback, *this);
  RegisterService<proc_control::EnableControl>(base_node_name + "enable_control",
                               &ControlSystem::EnableControlServiceCallback, *this);
}

void ControlSystem::OdomCallback(const nav_msgs::Odometry::ConstPtr &odo_in)
{
  SetTarget(world_position_,
            odo_in->twist.twist.linear.x,
            odo_in->twist.twist.linear.y,
            odo_in->twist.twist.linear.z,
            odo_in->twist.twist.angular.x,
            odo_in->twist.twist.angular.y,
            odo_in->twist.twist.angular.z);
}

bool ControlSystem::GlobalTargetServiceCallback(proc_control::SetPositionTargetRequest & request,
                                                proc_control::SetPositionTargetResponse & response)
{
  SetTarget(targeted_position_,
            request.X,
            request.Y,
            request.Z,
            request.ROLL,
            request.PITCH,
            request.YAW);
  return true;
}

bool ControlSystem::GetPositionTargetServiceCallback(proc_control::GetPositionTargetRequest & request,
                                      proc_control::GetPositionTargetResponse & response)
{
  response.X = targeted_position_[0];
  response.Y = targeted_position_[1];
  response.Z = targeted_position_[2];
  response.ROLL = targeted_position_[3];
  response.PITCH = targeted_position_[4];
  response.YAW = targeted_position_[5];
  return true;
}

void ControlSystem::LocalTargetCallback(const nav_msgs::Odometry::ConstPtr &target_in)
{
//  Eigen::Translation3d target_translation (target_in->twist.twist.linear.x,
//                               target_in->twist.twist.linear.y,
//                               target_in->twist.twist.linear.z);
//  Eigen::Quaterniond target_quat = atlas::EulerToQuat(Eigen::Vector3d (target_in->twist.twist.angular.x,
//                                                                    target_in->twist.twist.angular.y,
//                                                                    target_in->twist.twist.angular.z));
//  Eigen::Transform<double,3,Eigen::Affine> target_position = target_translation * target_quat;
//
//
//  Eigen::Translation3d current_position_linear(world_position_[0],world_position_[1],world_position_[2]);
//  Eigen::Quaterniond current_quat = atlas::EulerToQuat(Eigen::Vector3d (world_position_[3],
//                                                                                 world_position_[4],
//                                                                                 world_position_[5]));
//  Eigen::Transform<double,3,Eigen::Affine> world_position = current_position_linear * current_quat;

}

void ControlSystem::Control()
{
  std::array<double,6> error;
  for(int i = 0; i < 6; i++)
  {
    error[i] = targeted_position_[i] - world_position_[i];
    if( !enable_control_[i])
    {
      error[i] = 0.0f;
    }
  }
  std::array<double,6> actuation = algo_manager_.GetActuationForError(error);
  std::array<double, 3> actuation_lin = {actuation[0], actuation[2], actuation[2]};
  std::array<double, 3> actuation_rot = {actuation[3], actuation[4], actuation[5]};
  thruster_manager_.Commit(actuation_lin,actuation_rot);

}