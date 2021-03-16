//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: ProcNavNode.h
//
// Code generated for Simulink model 'ProcNavNode'.
//
// Model version                  : 1.579
// Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
// C/C++ source code generated on : Mon Mar 15 23:47:32 2021
//
// Target selection: ert.tlc
// Embedded hardware selection: Intel->x86-64 (Linux 64)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_ProcNavNode_h_
#define RTW_HEADER_ProcNavNode_h_
#include <math.h>
#include <stddef.h>
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "slros_initialize.h"
#include "ProcNavNode_types.h"
#include "rt_defines.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

// Macros for accessing real-time model data structure
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

// Block signals (default storage)
typedef struct {
  SL_Bus_ProcNavNode_sonia_common_BodyVelocityDVL b_varargout_2;
  SL_Bus_ProcNavNode_sonia_common_ImuInformation In1;// '<S5>/In1'
  SL_Bus_ProcNavNode_sonia_common_ImuInformation b_varargout_2_m;
  real_T b_varargout_1[3];
  real_T VectorConcatenate[3];         // '<S19>/Vector Concatenate'
  real_T Product3;                     // '<S20>/Product3'
  real_T fcn3;                         // '<S18>/fcn3'
  real_T rtb_qS2W_idx_0;
  real_T rtb_qS2W_idx_1;
} B_ProcNavNode_T;

// Block states (default storage) for system '<Root>'
typedef struct {
  DiscontinuityCheck_ProcNavNod_T obj; // '<S9>/MATLAB System2'
  ros_slros_internal_block_Subs_T obj_i;// '<S4>/SourceBlock'
  ros_slros_internal_block_Subs_T obj_b;// '<S3>/SourceBlock'
} DW_ProcNavNode_T;

// Parameters (default storage)
struct P_ProcNavNode_T_ {
  SL_Bus_ProcNavNode_sonia_common_BodyVelocityDVL Out1_Y0;// Computed Parameter: Out1_Y0
                                                             //  Referenced by: '<S6>/Out1'

  SL_Bus_ProcNavNode_sonia_common_BodyVelocityDVL Constant_Value;// Computed Parameter: Constant_Value
                                                                    //  Referenced by: '<S4>/Constant'

  SL_Bus_ProcNavNode_sonia_common_ImuInformation Out1_Y0_h;// Computed Parameter: Out1_Y0_h
                                                              //  Referenced by: '<S5>/Out1'

  SL_Bus_ProcNavNode_sonia_common_ImuInformation Constant_Value_g;// Computed Parameter: Constant_Value_g
                                                                     //  Referenced by: '<S3>/Constant'

  real_T Constant_Value_m;             // Expression: 1
                                          //  Referenced by: '<S22>/Constant'

  real_T Constant_Value_j;             // Expression: 1
                                          //  Referenced by: '<S23>/Constant'

  real_T Gain1_Gain;                   // Expression: 1
                                          //  Referenced by: '<S2>/Gain1'

};

// Real-time Model Data Structure
struct tag_RTM_ProcNavNode_T {
  const char_T *errorStatus;
};

// Block parameters (default storage)
#ifdef __cplusplus

extern "C" {

#endif

  extern P_ProcNavNode_T ProcNavNode_P;

#ifdef __cplusplus

}
#endif

// Block signals (default storage)
#ifdef __cplusplus

extern "C" {

#endif

  extern B_ProcNavNode_T ProcNavNode_B;

#ifdef __cplusplus

}
#endif

// Block states (default storage)
extern DW_ProcNavNode_T ProcNavNode_DW;

#ifdef __cplusplus

extern "C" {

#endif

  // Model entry point functions
  extern void ProcNavNode_initialize(void);
  extern void ProcNavNode_step(void);
  extern void ProcNavNode_terminate(void);

#ifdef __cplusplus

}
#endif

// Real-time Model object
#ifdef __cplusplus

extern "C" {

#endif

  extern RT_MODEL_ProcNavNode_T *const ProcNavNode_M;

#ifdef __cplusplus

}
#endif

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<S2>/Discrete-Time Integrator' : Unused code path elimination
//  Block '<S2>/Discrete-Time Integrator1' : Unused code path elimination
//  Block '<S7>/Divide' : Unused code path elimination
//  Block '<S7>/Divide1' : Unused code path elimination
//  Block '<S7>/Divide2' : Unused code path elimination
//  Block '<S7>/Divide3' : Unused code path elimination
//  Block '<S10>/Unary Minus' : Unused code path elimination
//  Block '<S10>/Unary Minus1' : Unused code path elimination
//  Block '<S10>/Unary Minus2' : Unused code path elimination
//  Block '<S11>/Product' : Unused code path elimination
//  Block '<S11>/Product1' : Unused code path elimination
//  Block '<S11>/Product2' : Unused code path elimination
//  Block '<S11>/Product3' : Unused code path elimination
//  Block '<S11>/Sum' : Unused code path elimination
//  Block '<S12>/Product' : Unused code path elimination
//  Block '<S12>/Product1' : Unused code path elimination
//  Block '<S12>/Product2' : Unused code path elimination
//  Block '<S12>/Product3' : Unused code path elimination
//  Block '<S17>/Product' : Unused code path elimination
//  Block '<S17>/Product1' : Unused code path elimination
//  Block '<S17>/Product2' : Unused code path elimination
//  Block '<S17>/Product3' : Unused code path elimination
//  Block '<S17>/Sum' : Unused code path elimination
//  Block '<S16>/sqrt' : Unused code path elimination
//  Block '<S13>/Constant' : Unused code path elimination
//  Block '<S13>/Gain' : Unused code path elimination
//  Block '<S13>/Gain1' : Unused code path elimination
//  Block '<S13>/Gain2' : Unused code path elimination
//  Block '<S13>/Product' : Unused code path elimination
//  Block '<S13>/Product1' : Unused code path elimination
//  Block '<S13>/Product2' : Unused code path elimination
//  Block '<S13>/Product3' : Unused code path elimination
//  Block '<S13>/Product4' : Unused code path elimination
//  Block '<S13>/Product5' : Unused code path elimination
//  Block '<S13>/Product6' : Unused code path elimination
//  Block '<S13>/Product7' : Unused code path elimination
//  Block '<S13>/Product8' : Unused code path elimination
//  Block '<S13>/Sum' : Unused code path elimination
//  Block '<S13>/Sum1' : Unused code path elimination
//  Block '<S13>/Sum2' : Unused code path elimination
//  Block '<S13>/Sum3' : Unused code path elimination
//  Block '<S14>/Constant' : Unused code path elimination
//  Block '<S14>/Gain' : Unused code path elimination
//  Block '<S14>/Gain1' : Unused code path elimination
//  Block '<S14>/Gain2' : Unused code path elimination
//  Block '<S14>/Product' : Unused code path elimination
//  Block '<S14>/Product1' : Unused code path elimination
//  Block '<S14>/Product2' : Unused code path elimination
//  Block '<S14>/Product3' : Unused code path elimination
//  Block '<S14>/Product4' : Unused code path elimination
//  Block '<S14>/Product5' : Unused code path elimination
//  Block '<S14>/Product6' : Unused code path elimination
//  Block '<S14>/Product7' : Unused code path elimination
//  Block '<S14>/Product8' : Unused code path elimination
//  Block '<S14>/Sum' : Unused code path elimination
//  Block '<S14>/Sum1' : Unused code path elimination
//  Block '<S14>/Sum2' : Unused code path elimination
//  Block '<S14>/Sum3' : Unused code path elimination
//  Block '<S15>/Constant' : Unused code path elimination
//  Block '<S15>/Gain' : Unused code path elimination
//  Block '<S15>/Gain1' : Unused code path elimination
//  Block '<S15>/Gain2' : Unused code path elimination
//  Block '<S15>/Product' : Unused code path elimination
//  Block '<S15>/Product1' : Unused code path elimination
//  Block '<S15>/Product2' : Unused code path elimination
//  Block '<S15>/Product3' : Unused code path elimination
//  Block '<S15>/Product4' : Unused code path elimination
//  Block '<S15>/Product5' : Unused code path elimination
//  Block '<S15>/Product6' : Unused code path elimination
//  Block '<S15>/Product7' : Unused code path elimination
//  Block '<S15>/Product8' : Unused code path elimination
//  Block '<S15>/Sum' : Unused code path elimination
//  Block '<S15>/Sum1' : Unused code path elimination
//  Block '<S15>/Sum2' : Unused code path elimination
//  Block '<S15>/Sum3' : Unused code path elimination
//  Block '<S2>/Scope1' : Unused code path elimination
//  Block '<S2>/Scope2' : Unused code path elimination
//  Block '<S2>/Scope6' : Unused code path elimination
//  Block '<S9>/Display' : Unused code path elimination
//  Block '<S9>/Scope' : Unused code path elimination
//  Block '<S9>/Scope1' : Unused code path elimination


//-
//  The generated code includes comments that allow you to trace directly
//  back to the appropriate location in the model.  The basic format
//  is <system>/block_name, where system is the system number (uniquely
//  assigned by Simulink) and block_name is the name of the block.
//
//  Use the MATLAB hilite_system command to trace the generated code back
//  to the model.  For example,
//
//  hilite_system('<S3>')    - opens system 3
//  hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
//
//  Here is the system hierarchy for this model
//
//  '<Root>' : 'ProcNavNode'
//  '<S1>'   : 'ProcNavNode/ROS Input'
//  '<S2>'   : 'ProcNavNode/Subsystem ProcNav'
//  '<S3>'   : 'ProcNavNode/ROS Input/Subscribe'
//  '<S4>'   : 'ProcNavNode/ROS Input/Subscribe1'
//  '<S5>'   : 'ProcNavNode/ROS Input/Subscribe/Enabled Subsystem'
//  '<S6>'   : 'ProcNavNode/ROS Input/Subscribe1/Enabled Subsystem'
//  '<S7>'   : 'ProcNavNode/Subsystem ProcNav/Quaternion Inverse1'
//  '<S8>'   : 'ProcNavNode/Subsystem ProcNav/Quaternion Rotation'
//  '<S9>'   : 'ProcNavNode/Subsystem ProcNav/Subsystem'
//  '<S10>'  : 'ProcNavNode/Subsystem ProcNav/Quaternion Inverse1/Quaternion Conjugate'
//  '<S11>'  : 'ProcNavNode/Subsystem ProcNav/Quaternion Inverse1/Quaternion Norm'
//  '<S12>'  : 'ProcNavNode/Subsystem ProcNav/Quaternion Rotation/Quaternion Normalize'
//  '<S13>'  : 'ProcNavNode/Subsystem ProcNav/Quaternion Rotation/V1'
//  '<S14>'  : 'ProcNavNode/Subsystem ProcNav/Quaternion Rotation/V2'
//  '<S15>'  : 'ProcNavNode/Subsystem ProcNav/Quaternion Rotation/V3'
//  '<S16>'  : 'ProcNavNode/Subsystem ProcNav/Quaternion Rotation/Quaternion Normalize/Quaternion Modulus'
//  '<S17>'  : 'ProcNavNode/Subsystem ProcNav/Quaternion Rotation/Quaternion Normalize/Quaternion Modulus/Quaternion Norm'
//  '<S18>'  : 'ProcNavNode/Subsystem ProcNav/Subsystem/Quaternions to Rotation Angles'
//  '<S19>'  : 'ProcNavNode/Subsystem ProcNav/Subsystem/Quaternions to Rotation Angles/Angle Calculation'
//  '<S20>'  : 'ProcNavNode/Subsystem ProcNav/Subsystem/Quaternions to Rotation Angles/Quaternion Normalize'
//  '<S21>'  : 'ProcNavNode/Subsystem ProcNav/Subsystem/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input'
//  '<S22>'  : 'ProcNavNode/Subsystem ProcNav/Subsystem/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input/If Action Subsystem'
//  '<S23>'  : 'ProcNavNode/Subsystem ProcNav/Subsystem/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input/If Action Subsystem1'
//  '<S24>'  : 'ProcNavNode/Subsystem ProcNav/Subsystem/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input/If Action Subsystem2'
//  '<S25>'  : 'ProcNavNode/Subsystem ProcNav/Subsystem/Quaternions to Rotation Angles/Quaternion Normalize/Quaternion Modulus'
//  '<S26>'  : 'ProcNavNode/Subsystem ProcNav/Subsystem/Quaternions to Rotation Angles/Quaternion Normalize/Quaternion Modulus/Quaternion Norm'

#endif                                 // RTW_HEADER_ProcNavNode_h_

//
// File trailer for generated code.
//
// [EOF]
//
