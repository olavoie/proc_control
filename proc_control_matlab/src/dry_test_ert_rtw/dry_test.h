//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: dry_test.h
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
#ifndef RTW_HEADER_dry_test_h_
#define RTW_HEADER_dry_test_h_
#include <math.h>
#include <stddef.h>
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "slros_initialize.h"
#include "dry_test_types.h"

// Macros for accessing real-time model data structure
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               ((rtm)->Timing.t)
#endif

// Block signals (default storage)
typedef struct {
  SL_Bus_dry_test_std_msgs_UInt16MultiArray msg;// '<Root>/MATLAB Function2'
} B_dry_test_T;

// Block states (default storage) for system '<Root>'
typedef struct {
  ros_slros_internal_block_Publ_T obj; // '<S4>/SinkBlock'
} DW_dry_test_T;

// Parameters (default storage)
struct P_dry_test_T_ {
  SL_Bus_dry_test_std_msgs_UInt16MultiArray Constant_Value;// Computed Parameter: Constant_Value
                                                              //  Referenced by: '<S1>/Constant'

  real_T Constant_Value_j;             // Expression: 3
                                          //  Referenced by: '<Root>/Constant'

  real_T Constant2_Value;              // Expression: 1
                                          //  Referenced by: '<Root>/Constant2'

  real_T Constant1_Value;              // Expression: 72
                                          //  Referenced by: '<Root>/Constant1'

};

// Real-time Model Data Structure
struct tag_RTM_dry_test_T {
  const char_T *errorStatus;
  RTWSolverInfo solverInfo;

  //
  //  Timing:
  //  The following substructure contains information regarding
  //  the timing information for the model.

  struct {
    uint32_T clockTick0;
    time_T stepSize0;
    uint32_T clockTick1;
    SimTimeStep simTimeStep;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

// Block parameters (default storage)
#ifdef __cplusplus

extern "C" {

#endif

  extern P_dry_test_T dry_test_P;

#ifdef __cplusplus

}
#endif

// Block signals (default storage)
#ifdef __cplusplus

extern "C" {

#endif

  extern B_dry_test_T dry_test_B;

#ifdef __cplusplus

}
#endif

// Block states (default storage)
extern DW_dry_test_T dry_test_DW;

#ifdef __cplusplus

extern "C" {

#endif

  // Model entry point functions
  extern void dry_test_initialize(void);
  extern void dry_test_step(void);
  extern void dry_test_terminate(void);

#ifdef __cplusplus

}
#endif

// Real-time Model object
#ifdef __cplusplus

extern "C" {

#endif

  extern RT_MODEL_dry_test_T *const dry_test_M;

#ifdef __cplusplus

}
#endif

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<Root>/Scope' : Unused code path elimination


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
//  '<Root>' : 'dry_test'
//  '<S1>'   : 'dry_test/Blank Message1'
//  '<S2>'   : 'dry_test/MATLAB Function'
//  '<S3>'   : 'dry_test/MATLAB Function2'
//  '<S4>'   : 'dry_test/Publish1'

#endif                                 // RTW_HEADER_dry_test_h_

//
// File trailer for generated code.
//
// [EOF]
//
