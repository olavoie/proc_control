#include "slros_busmsg_conversion.h"


// Conversions between SL_Bus_ProcNavNode_geometry_msgs_Accel and geometry_msgs::Accel

void convertFromBus(geometry_msgs::Accel* msgPtr, SL_Bus_ProcNavNode_geometry_msgs_Accel const* busPtr)
{
  const std::string rosMessageType("geometry_msgs/Accel");

  convertFromBus(&msgPtr->angular, &busPtr->Angular);
  convertFromBus(&msgPtr->linear, &busPtr->Linear);
}

void convertToBus(SL_Bus_ProcNavNode_geometry_msgs_Accel* busPtr, geometry_msgs::Accel const* msgPtr)
{
  const std::string rosMessageType("geometry_msgs/Accel");

  convertToBus(&busPtr->Angular, &msgPtr->angular);
  convertToBus(&busPtr->Linear, &msgPtr->linear);
}


// Conversions between SL_Bus_ProcNavNode_geometry_msgs_Quaternion and geometry_msgs::Quaternion

void convertFromBus(geometry_msgs::Quaternion* msgPtr, SL_Bus_ProcNavNode_geometry_msgs_Quaternion const* busPtr)
{
  const std::string rosMessageType("geometry_msgs/Quaternion");

  msgPtr->w =  busPtr->W;
  msgPtr->x =  busPtr->X;
  msgPtr->y =  busPtr->Y;
  msgPtr->z =  busPtr->Z;
}

void convertToBus(SL_Bus_ProcNavNode_geometry_msgs_Quaternion* busPtr, geometry_msgs::Quaternion const* msgPtr)
{
  const std::string rosMessageType("geometry_msgs/Quaternion");

  busPtr->W =  msgPtr->w;
  busPtr->X =  msgPtr->x;
  busPtr->Y =  msgPtr->y;
  busPtr->Z =  msgPtr->z;
}


// Conversions between SL_Bus_ProcNavNode_geometry_msgs_Vector3 and geometry_msgs::Vector3

void convertFromBus(geometry_msgs::Vector3* msgPtr, SL_Bus_ProcNavNode_geometry_msgs_Vector3 const* busPtr)
{
  const std::string rosMessageType("geometry_msgs/Vector3");

  msgPtr->x =  busPtr->X;
  msgPtr->y =  busPtr->Y;
  msgPtr->z =  busPtr->Z;
}

void convertToBus(SL_Bus_ProcNavNode_geometry_msgs_Vector3* busPtr, geometry_msgs::Vector3 const* msgPtr)
{
  const std::string rosMessageType("geometry_msgs/Vector3");

  busPtr->X =  msgPtr->x;
  busPtr->Y =  msgPtr->y;
  busPtr->Z =  msgPtr->z;
}


// Conversions between SL_Bus_ProcNavNode_ros_time_Time and ros::Time

void convertFromBus(ros::Time* msgPtr, SL_Bus_ProcNavNode_ros_time_Time const* busPtr)
{
  const std::string rosMessageType("ros_time/Time");

  msgPtr->sec =  busPtr->Sec;
  msgPtr->nsec =  busPtr->Nsec;
}

void convertToBus(SL_Bus_ProcNavNode_ros_time_Time* busPtr, ros::Time const* msgPtr)
{
  const std::string rosMessageType("ros_time/Time");

  busPtr->Sec =  msgPtr->sec;
  busPtr->Nsec =  msgPtr->nsec;
}


// Conversions between SL_Bus_ProcNavNode_sonia_common_BodyVelocityDVL and sonia_common::BodyVelocityDVL

void convertFromBus(sonia_common::BodyVelocityDVL* msgPtr, SL_Bus_ProcNavNode_sonia_common_BodyVelocityDVL const* busPtr)
{
  const std::string rosMessageType("sonia_common/BodyVelocityDVL");

  msgPtr->eVelBtm =  busPtr->EVelBtm;
  convertFromBus(&msgPtr->header, &busPtr->Header);
  msgPtr->xVelBtm =  busPtr->XVelBtm;
  msgPtr->yVelBtm =  busPtr->YVelBtm;
  msgPtr->zVelBtm =  busPtr->ZVelBtm;
}

void convertToBus(SL_Bus_ProcNavNode_sonia_common_BodyVelocityDVL* busPtr, sonia_common::BodyVelocityDVL const* msgPtr)
{
  const std::string rosMessageType("sonia_common/BodyVelocityDVL");

  busPtr->EVelBtm =  msgPtr->eVelBtm;
  convertToBus(&busPtr->Header, &msgPtr->header);
  busPtr->XVelBtm =  msgPtr->xVelBtm;
  busPtr->YVelBtm =  msgPtr->yVelBtm;
  busPtr->ZVelBtm =  msgPtr->zVelBtm;
}


// Conversions between SL_Bus_ProcNavNode_sonia_common_ImuInformation and sonia_common::ImuInformation

void convertFromBus(sonia_common::ImuInformation* msgPtr, SL_Bus_ProcNavNode_sonia_common_ImuInformation const* busPtr)
{
  const std::string rosMessageType("sonia_common/ImuInformation");

  convertFromBus(&msgPtr->acceleration, &busPtr->Acceleration);
  convertFromBus(&msgPtr->magnetometer, &busPtr->Magnetometer);
  convertFromBus(&msgPtr->quaternion, &busPtr->Quaternion);
}

void convertToBus(SL_Bus_ProcNavNode_sonia_common_ImuInformation* busPtr, sonia_common::ImuInformation const* msgPtr)
{
  const std::string rosMessageType("sonia_common/ImuInformation");

  convertToBus(&busPtr->Acceleration, &msgPtr->acceleration);
  convertToBus(&busPtr->Magnetometer, &msgPtr->magnetometer);
  convertToBus(&busPtr->Quaternion, &msgPtr->quaternion);
}


// Conversions between SL_Bus_ProcNavNode_std_msgs_Header and std_msgs::Header

void convertFromBus(std_msgs::Header* msgPtr, SL_Bus_ProcNavNode_std_msgs_Header const* busPtr)
{
  const std::string rosMessageType("std_msgs/Header");

  convertFromBusVariablePrimitiveArray(msgPtr->frame_id, busPtr->FrameId, busPtr->FrameId_SL_Info);
  msgPtr->seq =  busPtr->Seq;
  convertFromBus(&msgPtr->stamp, &busPtr->Stamp);
}

void convertToBus(SL_Bus_ProcNavNode_std_msgs_Header* busPtr, std_msgs::Header const* msgPtr)
{
  const std::string rosMessageType("std_msgs/Header");

  convertToBusVariablePrimitiveArray(busPtr->FrameId, busPtr->FrameId_SL_Info, msgPtr->frame_id, slros::EnabledWarning(rosMessageType, "frame_id"));
  busPtr->Seq =  msgPtr->seq;
  convertToBus(&busPtr->Stamp, &msgPtr->stamp);
}

