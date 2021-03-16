//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: dry_test.cpp
//
// Code generated for Simulink model 'dry_test'.
//
// Model version                  : 1.25
// Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
// C/C++ source code generated on : Tue Mar 16 18:20:46 2021
//
// Target selection: ert.tlc
// Embedded hardware selection: Intel->x86-32 (Windows32)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "dry_test.h"
#include "dry_test_private.h"

// Block signals (default storage)
B_dry_test_T dry_test_B;

// Block states (default storage)
DW_dry_test_T dry_test_DW;

// Real-time model
RT_MODEL_dry_test_T dry_test_M_ = RT_MODEL_dry_test_T();
RT_MODEL_dry_test_T *const dry_test_M = &dry_test_M_;

// Forward declaration for local functions
static void matlabCodegenHandle_matlabCodeg(ros_slros_internal_block_Publ_T *obj);
real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

static void matlabCodegenHandle_matlabCodeg(ros_slros_internal_block_Publ_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
  }
}

// Model step function
void dry_test_step(void)
{
  real_T rtb_Clock;
  int32_T i;
  real_T rtb_out;
  real_T tmp;

  // Clock: '<Root>/Clock'
  rtb_Clock = dry_test_M->Timing.t[0];

  // MATLAB Function: '<Root>/MATLAB Function2' incorporates:
  //   Constant: '<S1>/Constant'

  dry_test_B.msg = dry_test_P.Constant_Value;
  for (i = 0; i < 8; i++) {
    // MATLAB Function: '<Root>/MATLAB Function' incorporates:
    //   Constant: '<Root>/Constant'
    //   Constant: '<Root>/Constant1'
    //   Constant: '<Root>/Constant2'

    rtb_out = 1500.0;
    tmp = (static_cast<real_T>(i) + 1.0) * dry_test_P.Constant2_Value;
    if ((rtb_Clock > ((static_cast<real_T>(i) + 1.0) - 1.0) *
         dry_test_P.Constant_Value_j + tmp) && (rtb_Clock < (static_cast<real_T>
          (i) + 1.0) * dry_test_P.Constant_Value_j + tmp)) {
      rtb_out = dry_test_P.Constant1_Value + 1500.0;
    }

    // End of MATLAB Function: '<Root>/MATLAB Function'

    // MATLAB Function: '<Root>/MATLAB Function2'
    tmp = rt_roundd_snf(rtb_out);
    if (tmp < 65536.0) {
      if (tmp >= 0.0) {
        dry_test_B.msg.Data[i] = static_cast<uint16_T>(tmp);
      } else {
        dry_test_B.msg.Data[i] = 0U;
      }
    } else {
      dry_test_B.msg.Data[i] = MAX_uint16_T;
    }
  }

  // MATLAB Function: '<Root>/MATLAB Function2'
  dry_test_B.msg.Data_SL_Info.CurrentLength = 8U;

  // Outputs for Atomic SubSystem: '<Root>/Publish1'
  // MATLABSystem: '<S4>/SinkBlock'
  Pub_dry_test_24.publish(&dry_test_B.msg);

  // End of Outputs for SubSystem: '<Root>/Publish1'

  // Update absolute time for base rate
  // The "clockTick0" counts the number of times the code of this task has
  //  been executed. The absolute time is the multiplication of "clockTick0"
  //  and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
  //  overflow during the application lifespan selected.

  dry_test_M->Timing.t[0] =
    ((time_T)(++dry_test_M->Timing.clockTick0)) * dry_test_M->Timing.stepSize0;

  {
    // Update absolute timer for sample time: [0.1s, 0.0s]
    // The "clockTick1" counts the number of times the code of this task has
    //  been executed. The resolution of this integer timer is 0.1, which is the step size
    //  of the task. Size of "clockTick1" ensures timer will not overflow during the
    //  application lifespan selected.

    dry_test_M->Timing.clockTick1++;
  }
}

// Model initialize function
void dry_test_initialize(void)
{
  // Registration code
  {
    // Setup solver object
    rtsiSetSimTimeStepPtr(&dry_test_M->solverInfo,
                          &dry_test_M->Timing.simTimeStep);
    rtsiSetTPtr(&dry_test_M->solverInfo, &rtmGetTPtr(dry_test_M));
    rtsiSetStepSizePtr(&dry_test_M->solverInfo, &dry_test_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&dry_test_M->solverInfo, (&rtmGetErrorStatus
      (dry_test_M)));
    rtsiSetRTModelPtr(&dry_test_M->solverInfo, dry_test_M);
  }

  rtsiSetSimTimeStep(&dry_test_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&dry_test_M->solverInfo,"FixedStepDiscrete");
  rtmSetTPtr(dry_test_M, &dry_test_M->Timing.tArray[0]);
  dry_test_M->Timing.stepSize0 = 0.1;

  {
    char_T tmp[32];
    int32_T i;
    static const char_T tmp_0[31] = { '/', 'p', 'r', 'o', 'v', 'i', 'd', 'e',
      'r', '_', 't', 'h', 'r', 'u', 's', 't', 'e', 'r', '/', 't', 'h', 'r', 'u',
      's', 't', 'e', 'r', '_', 'p', 'w', 'm' };

    // SystemInitialize for Atomic SubSystem: '<Root>/Publish1'
    // Start for MATLABSystem: '<S4>/SinkBlock'
    dry_test_DW.obj.matlabCodegenIsDeleted = false;
    dry_test_DW.obj.isInitialized = 1;
    for (i = 0; i < 31; i++) {
      tmp[i] = tmp_0[i];
    }

    tmp[31] = '\x00';
    Pub_dry_test_24.createPublisher(tmp, 1);
    dry_test_DW.obj.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S4>/SinkBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Publish1'
  }
}

// Model terminate function
void dry_test_terminate(void)
{
  // Terminate for Atomic SubSystem: '<Root>/Publish1'
  // Terminate for MATLABSystem: '<S4>/SinkBlock'
  matlabCodegenHandle_matlabCodeg(&dry_test_DW.obj);

  // End of Terminate for SubSystem: '<Root>/Publish1'
}

//
// File trailer for generated code.
//
// [EOF]
//
