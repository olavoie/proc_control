#include "slros_busmsg_conversion.h"


// Conversions between SL_Bus_full_loop_sonia_common_ThrusterPwm and sonia_common::ThrusterPwm

void convertFromBus(sonia_common::ThrusterPwm* msgPtr, SL_Bus_full_loop_sonia_common_ThrusterPwm const* busPtr)
{
  const std::string rosMessageType("sonia_common/ThrusterPwm");

  convertFromBusVariablePrimitiveArray(msgPtr->pwm, busPtr->Pwm, busPtr->Pwm_SL_Info);
}

void convertToBus(SL_Bus_full_loop_sonia_common_ThrusterPwm* busPtr, sonia_common::ThrusterPwm const* msgPtr)
{
  const std::string rosMessageType("sonia_common/ThrusterPwm");

  convertToBusVariablePrimitiveArray(busPtr->Pwm, busPtr->Pwm_SL_Info, msgPtr->pwm, slros::EnabledWarning(rosMessageType, "pwm"));
}

