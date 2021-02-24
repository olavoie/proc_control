//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: full_loop_types.h
//
// Code generated for Simulink model 'full_loop'.
//
// Model version                  : 1.488
// Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
// C/C++ source code generated on : Tue Feb 23 16:32:45 2021
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM 8
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_full_loop_types_h_
#define RTW_HEADER_full_loop_types_h_
#include "rtwtypes.h"
#include "zero_crossing_types.h"

// Model Code Variants
#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_ROSVariableLengthArrayInfo_
#define DEFINED_TYPEDEF_FOR_SL_Bus_ROSVariableLengthArrayInfo_

typedef struct {
  uint32_T CurrentLength;
  uint32_T ReceivedLength;
} SL_Bus_ROSVariableLengthArrayInfo;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_full_loop_sonia_common_ThrusterPwm_
#define DEFINED_TYPEDEF_FOR_SL_Bus_full_loop_sonia_common_ThrusterPwm_

// MsgType=sonia_common/ThrusterPwm
typedef struct {
  // IsVarLen=1:VarLenCategory=data:VarLenElem=Pwm_SL_Info:TruncateAction=warn
  uint16_T Pwm[128];

  // IsVarLen=1:VarLenCategory=length:VarLenElem=Pwm
  SL_Bus_ROSVariableLengthArrayInfo Pwm_SL_Info;
} SL_Bus_full_loop_sonia_common_ThrusterPwm;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_ZjQlTZzyEV0NwjMEYOpw5B_
#define DEFINED_TYPEDEF_FOR_struct_ZjQlTZzyEV0NwjMEYOpw5B_

typedef struct {
  real_T values[119392];
  real_T dimensions[2];
} struct_ZjQlTZzyEV0NwjMEYOpw5B;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_ZJL8Yi1wday5KGZ7Dm4EmE_
#define DEFINED_TYPEDEF_FOR_struct_ZJL8Yi1wday5KGZ7Dm4EmE_

typedef struct {
  real_T time[2296];
  struct_ZjQlTZzyEV0NwjMEYOpw5B signals;
} struct_ZJL8Yi1wday5KGZ7Dm4EmE;

#endif

#ifndef struct_tag_rkSooZHJZnr3Dpfu1LNqfH
#define struct_tag_rkSooZHJZnr3Dpfu1LNqfH

struct tag_rkSooZHJZnr3Dpfu1LNqfH
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
};

#endif                                 //struct_tag_rkSooZHJZnr3Dpfu1LNqfH

#ifndef typedef_ros_slros_internal_block_Publ_T
#define typedef_ros_slros_internal_block_Publ_T

typedef struct tag_rkSooZHJZnr3Dpfu1LNqfH ros_slros_internal_block_Publ_T;

#endif                                 //typedef_ros_slros_internal_block_Publ_T

// Custom Type definition for MATLAB Function: '<S29>/NLMPC'
#ifndef struct_tag_s7RdrPWkr8UPAUyTdDJkLaG
#define struct_tag_s7RdrPWkr8UPAUyTdDJkLaG

struct tag_s7RdrPWkr8UPAUyTdDJkLaG
{
  boolean_T gradOK;
  boolean_T fevalOK;
  boolean_T done;
  boolean_T stepAccepted;
  boolean_T failedLineSearch;
  int32_T stepType;
};

#endif                                 //struct_tag_s7RdrPWkr8UPAUyTdDJkLaG

#ifndef typedef_s7RdrPWkr8UPAUyTdDJkLaG_full__T
#define typedef_s7RdrPWkr8UPAUyTdDJkLaG_full__T

typedef struct tag_s7RdrPWkr8UPAUyTdDJkLaG s7RdrPWkr8UPAUyTdDJkLaG_full__T;

#endif                                 //typedef_s7RdrPWkr8UPAUyTdDJkLaG_full__T

#ifndef struct_tag_YPxmBg0IEyvIR8OEJxFTqB
#define struct_tag_YPxmBg0IEyvIR8OEJxFTqB

struct tag_YPxmBg0IEyvIR8OEJxFTqB
{
  real_T f1[13];
};

#endif                                 //struct_tag_YPxmBg0IEyvIR8OEJxFTqB

#ifndef typedef_cell_wrap_8_full_loop_T
#define typedef_cell_wrap_8_full_loop_T

typedef struct tag_YPxmBg0IEyvIR8OEJxFTqB cell_wrap_8_full_loop_T;

#endif                                 //typedef_cell_wrap_8_full_loop_T

#ifndef struct_tag_rWaxBuHqZZUFMg3U4vG4HD
#define struct_tag_rWaxBuHqZZUFMg3U4vG4HD

struct tag_rWaxBuHqZZUFMg3U4vG4HD
{
  real_T f1[8];
};

#endif                                 //struct_tag_rWaxBuHqZZUFMg3U4vG4HD

#ifndef typedef_cell_wrap_9_full_loop_T
#define typedef_cell_wrap_9_full_loop_T

typedef struct tag_rWaxBuHqZZUFMg3U4vG4HD cell_wrap_9_full_loop_T;

#endif                                 //typedef_cell_wrap_9_full_loop_T

#ifndef struct_emxArray_real_T_759x759
#define struct_emxArray_real_T_759x759

struct emxArray_real_T_759x759
{
  real_T data[576081];
  int32_T size[2];
};

#endif                                 //struct_emxArray_real_T_759x759

#ifndef typedef_emxArray_real_T_759x759_full__T
#define typedef_emxArray_real_T_759x759_full__T

typedef struct emxArray_real_T_759x759 emxArray_real_T_759x759_full__T;

#endif                                 //typedef_emxArray_real_T_759x759_full__T

#ifndef struct_emxArray_real_T_406x52
#define struct_emxArray_real_T_406x52

struct emxArray_real_T_406x52
{
  real_T data[21112];
  int32_T size[2];
};

#endif                                 //struct_emxArray_real_T_406x52

#ifndef typedef_emxArray_real_T_406x52_full_l_T
#define typedef_emxArray_real_T_406x52_full_l_T

typedef struct emxArray_real_T_406x52 emxArray_real_T_406x52_full_l_T;

#endif                                 //typedef_emxArray_real_T_406x52_full_l_T

#ifndef struct_emxArray_real_T_759x406
#define struct_emxArray_real_T_759x406

struct emxArray_real_T_759x406
{
  real_T data[308154];
  int32_T size[2];
};

#endif                                 //struct_emxArray_real_T_759x406

#ifndef typedef_emxArray_real_T_759x406_full__T
#define typedef_emxArray_real_T_759x406_full__T

typedef struct emxArray_real_T_759x406 emxArray_real_T_759x406_full__T;

#endif                                 //typedef_emxArray_real_T_759x406_full__T

#ifndef struct_emxArray_real_T_406x232
#define struct_emxArray_real_T_406x232

struct emxArray_real_T_406x232
{
  real_T data[94192];
  int32_T size[2];
};

#endif                                 //struct_emxArray_real_T_406x232

#ifndef typedef_emxArray_real_T_406x232_full__T
#define typedef_emxArray_real_T_406x232_full__T

typedef struct emxArray_real_T_406x232 emxArray_real_T_406x232_full__T;

#endif                                 //typedef_emxArray_real_T_406x232_full__T

#ifndef struct_emxArray_real_T_232x1
#define struct_emxArray_real_T_232x1

struct emxArray_real_T_232x1
{
  real_T data[232];
  int32_T size[2];
};

#endif                                 //struct_emxArray_real_T_232x1

#ifndef typedef_emxArray_real_T_232x1_full_lo_T
#define typedef_emxArray_real_T_232x1_full_lo_T

typedef struct emxArray_real_T_232x1 emxArray_real_T_232x1_full_lo_T;

#endif                                 //typedef_emxArray_real_T_232x1_full_lo_T

#ifndef struct_emxArray_real_T_128x104
#define struct_emxArray_real_T_128x104

struct emxArray_real_T_128x104
{
  real_T data[13312];
  int32_T size[2];
};

#endif                                 //struct_emxArray_real_T_128x104

#ifndef typedef_emxArray_real_T_128x104_full__T
#define typedef_emxArray_real_T_128x104_full__T

typedef struct emxArray_real_T_128x104 emxArray_real_T_128x104_full__T;

#endif                                 //typedef_emxArray_real_T_128x104_full__T

#ifndef struct_tag_LKyfSwOtrjnmbulBcpoyEB
#define struct_tag_LKyfSwOtrjnmbulBcpoyEB

struct tag_LKyfSwOtrjnmbulBcpoyEB
{
  emxArray_real_T_128x104_full__T f1;
};

#endif                                 //struct_tag_LKyfSwOtrjnmbulBcpoyEB

#ifndef typedef_cell_wrap_14_full_loop_T
#define typedef_cell_wrap_14_full_loop_T

typedef struct tag_LKyfSwOtrjnmbulBcpoyEB cell_wrap_14_full_loop_T;

#endif                                 //typedef_cell_wrap_14_full_loop_T

// Custom Type definition for MATLAB Function: '<S29>/NLMPC'
#ifndef struct_tag_s6ICcRyulWOFjNCN0ll7VsE
#define struct_tag_s6ICcRyulWOFjNCN0ll7VsE

struct tag_s6ICcRyulWOFjNCN0ll7VsE
{
  real_T penaltyParam;
  real_T threshold;
  int32_T nPenaltyDecreases;
  real_T linearizedConstrViol;
  real_T initFval;
  real_T initConstrViolationEq;
  real_T initConstrViolationIneq;
  real_T phi;
  real_T phiPrimePlus;
  real_T phiFullStep;
  real_T feasRelativeFactor;
  real_T nlpPrimalFeasError;
  real_T nlpDualFeasError;
  real_T nlpComplError;
  real_T firstOrderOpt;
  boolean_T hasObjective;
};

#endif                                 //struct_tag_s6ICcRyulWOFjNCN0ll7VsE

#ifndef typedef_s6ICcRyulWOFjNCN0ll7VsE_full__T
#define typedef_s6ICcRyulWOFjNCN0ll7VsE_full__T

typedef struct tag_s6ICcRyulWOFjNCN0ll7VsE s6ICcRyulWOFjNCN0ll7VsE_full__T;

#endif                                 //typedef_s6ICcRyulWOFjNCN0ll7VsE_full__T

#ifndef struct_tag_a5SYZcWNC5KFUTosoMMbl
#define struct_tag_a5SYZcWNC5KFUTosoMMbl

struct tag_a5SYZcWNC5KFUTosoMMbl
{
  emxArray_real_T_759x759_full__T FMat;
  int32_T ldm;
  int32_T ndims;
  int32_T info;
};

#endif                                 //struct_tag_a5SYZcWNC5KFUTosoMMbl

#ifndef typedef_s_a5SYZcWNC5KFUTosoMMbl_full__T
#define typedef_s_a5SYZcWNC5KFUTosoMMbl_full__T

typedef struct tag_a5SYZcWNC5KFUTosoMMbl s_a5SYZcWNC5KFUTosoMMbl_full__T;

#endif                                 //typedef_s_a5SYZcWNC5KFUTosoMMbl_full__T

#ifndef struct_tag_s1TgE9KstXgkd2qJxO1bF4F
#define struct_tag_s1TgE9KstXgkd2qJxO1bF4F

struct tag_s1TgE9KstXgkd2qJxO1bF4F
{
  char_T SolverName[7];
  int32_T MaxIterations;
  real_T StepTolerance;
  real_T OptimalityTolerance;
  real_T ConstraintTolerance;
  real_T ObjectiveLimit;
  real_T PricingTolerance;
  real_T ConstrRelTolFactor;
  real_T ProbRelTolFactor;
  boolean_T RemainFeasible;
  boolean_T IterDisplayQP;
};

#endif                                 //struct_tag_s1TgE9KstXgkd2qJxO1bF4F

#ifndef typedef_s1TgE9KstXgkd2qJxO1bF4F_full__T
#define typedef_s1TgE9KstXgkd2qJxO1bF4F_full__T

typedef struct tag_s1TgE9KstXgkd2qJxO1bF4F s1TgE9KstXgkd2qJxO1bF4F_full__T;

#endif                                 //typedef_s1TgE9KstXgkd2qJxO1bF4F_full__T

#ifndef struct_tag_sscAEMcz7TPKHyH2uh3imDC
#define struct_tag_sscAEMcz7TPKHyH2uh3imDC

struct tag_sscAEMcz7TPKHyH2uh3imDC
{
  real_T MVopt[40];
  real_T Xopt[65];
  real_T Yopt[65];
  real_T Topt[5];
  real_T Slack;
  real_T ExitFlag;
  real_T Iterations;
  real_T Cost;
};

#endif                                 //struct_tag_sscAEMcz7TPKHyH2uh3imDC

#ifndef typedef_sscAEMcz7TPKHyH2uh3imDC_full__T
#define typedef_sscAEMcz7TPKHyH2uh3imDC_full__T

typedef struct tag_sscAEMcz7TPKHyH2uh3imDC sscAEMcz7TPKHyH2uh3imDC_full__T;

#endif                                 //typedef_sscAEMcz7TPKHyH2uh3imDC_full__T

#ifndef struct_tag_8PtrUTLhrChOpBxl2BsSqE
#define struct_tag_8PtrUTLhrChOpBxl2BsSqE

struct tag_8PtrUTLhrChOpBxl2BsSqE
{
  real_T f1[52];
};

#endif                                 //struct_tag_8PtrUTLhrChOpBxl2BsSqE

#ifndef typedef_cell_wrap_10_full_loop_T
#define typedef_cell_wrap_10_full_loop_T

typedef struct tag_8PtrUTLhrChOpBxl2BsSqE cell_wrap_10_full_loop_T;

#endif                                 //typedef_cell_wrap_10_full_loop_T

#ifndef struct_tag_FFwMKuSX1XhVZMmHpPZQAF
#define struct_tag_FFwMKuSX1XhVZMmHpPZQAF

struct tag_FFwMKuSX1XhVZMmHpPZQAF
{
  real_T f1[32];
};

#endif                                 //struct_tag_FFwMKuSX1XhVZMmHpPZQAF

#ifndef typedef_cell_wrap_12_full_loop_T
#define typedef_cell_wrap_12_full_loop_T

typedef struct tag_FFwMKuSX1XhVZMmHpPZQAF cell_wrap_12_full_loop_T;

#endif                                 //typedef_cell_wrap_12_full_loop_T

#ifndef struct_tag_6H4JrUjkWPrBy6FZW4fMiE
#define struct_tag_6H4JrUjkWPrBy6FZW4fMiE

struct tag_6H4JrUjkWPrBy6FZW4fMiE
{
  real_T tcount[3];
  real_T lastAngle[3];
};

#endif                                 //struct_tag_6H4JrUjkWPrBy6FZW4fMiE

#ifndef typedef_DiscontinuityCheck_full_loop_T
#define typedef_DiscontinuityCheck_full_loop_T

typedef struct tag_6H4JrUjkWPrBy6FZW4fMiE DiscontinuityCheck_full_loop_T;

#endif                                 //typedef_DiscontinuityCheck_full_loop_T

// Custom Type definition for MATLAB Function: '<S29>/NLMPC'
#ifndef struct_tag_A0rUWcsbMx3S06V1NlippE
#define struct_tag_A0rUWcsbMx3S06V1NlippE

struct tag_A0rUWcsbMx3S06V1NlippE
{
  real_T x[13];
  real_T lastMV[8];
  real_T ref[52];
  real_T OutputWeights[52];
  real_T MVWeights[32];
  real_T MVRateWeights[32];
  real_T ECRWeight;
  real_T OutputMin[52];
  real_T OutputMax[52];
  real_T StateMin[52];
  real_T StateMax[52];
  real_T MVMin[32];
  real_T MVMax[32];
  real_T MVRateMin[32];
  real_T MVRateMax[32];
  real_T MVScaledTarget[32];
};

#endif                                 //struct_tag_A0rUWcsbMx3S06V1NlippE

#ifndef typedef_s_A0rUWcsbMx3S06V1NlippE_full_T
#define typedef_s_A0rUWcsbMx3S06V1NlippE_full_T

typedef struct tag_A0rUWcsbMx3S06V1NlippE s_A0rUWcsbMx3S06V1NlippE_full_T;

#endif                                 //typedef_s_A0rUWcsbMx3S06V1NlippE_full_T

#ifndef struct_tag_sACkMJ1zT2VJOHR6eMwwEPC
#define struct_tag_sACkMJ1zT2VJOHR6eMwwEPC

struct tag_sACkMJ1zT2VJOHR6eMwwEPC
{
  real_T Ts;
  real_T CurrentStates[13];
  real_T LastMV[8];
  real_T References[52];
  real_T MVTarget[32];
  real_T PredictionHorizon;
  real_T NumOfStates;
  real_T NumOfOutputs;
  real_T NumOfInputs;
  real_T MVIndex[8];
};

#endif                                 //struct_tag_sACkMJ1zT2VJOHR6eMwwEPC

#ifndef typedef_sACkMJ1zT2VJOHR6eMwwEPC_full__T
#define typedef_sACkMJ1zT2VJOHR6eMwwEPC_full__T

typedef struct tag_sACkMJ1zT2VJOHR6eMwwEPC sACkMJ1zT2VJOHR6eMwwEPC_full__T;

#endif                                 //typedef_sACkMJ1zT2VJOHR6eMwwEPC_full__T

#ifndef struct_tag_R7ZAVntqljawiTPtjAALbB
#define struct_tag_R7ZAVntqljawiTPtjAALbB

struct tag_R7ZAVntqljawiTPtjAALbB
{
  s_A0rUWcsbMx3S06V1NlippE_full_T f1;
  sACkMJ1zT2VJOHR6eMwwEPC_full__T f2;
};

#endif                                 //struct_tag_R7ZAVntqljawiTPtjAALbB

#ifndef typedef_cell_2_full_loop_T
#define typedef_cell_2_full_loop_T

typedef struct tag_R7ZAVntqljawiTPtjAALbB cell_2_full_loop_T;

#endif                                 //typedef_cell_2_full_loop_T

#ifndef struct_tag_jOlDPQLs8I9qK3Cs0kmL3D
#define struct_tag_jOlDPQLs8I9qK3Cs0kmL3D

struct tag_jOlDPQLs8I9qK3Cs0kmL3D
{
  cell_2_full_loop_T tunableEnvironment;
};

#endif                                 //struct_tag_jOlDPQLs8I9qK3Cs0kmL3D

#ifndef typedef_c_coder_internal_anonymous_fu_T
#define typedef_c_coder_internal_anonymous_fu_T

typedef struct tag_jOlDPQLs8I9qK3Cs0kmL3D c_coder_internal_anonymous_fu_T;

#endif                                 //typedef_c_coder_internal_anonymous_fu_T

#ifndef struct_tag_siHoaqeHIV5TpidUajpsGD
#define struct_tag_siHoaqeHIV5TpidUajpsGD

struct tag_siHoaqeHIV5TpidUajpsGD
{
  c_coder_internal_anonymous_fu_T objfun;
  c_coder_internal_anonymous_fu_T nonlcon;
  int32_T nVar;
  int32_T mCineq;
  int32_T mCeq;
  boolean_T NonFiniteSupport;
  boolean_T SpecifyObjectiveGradient;
  boolean_T SpecifyConstraintGradient;
  boolean_T ScaleProblem;
};

#endif                                 //struct_tag_siHoaqeHIV5TpidUajpsGD

#ifndef typedef_s_siHoaqeHIV5TpidUajpsGD_full_T
#define typedef_s_siHoaqeHIV5TpidUajpsGD_full_T

typedef struct tag_siHoaqeHIV5TpidUajpsGD s_siHoaqeHIV5TpidUajpsGD_full_T;

#endif                                 //typedef_s_siHoaqeHIV5TpidUajpsGD_full_T

#ifndef struct_emxArray_real_T_232
#define struct_emxArray_real_T_232

struct emxArray_real_T_232
{
  real_T data[232];
  int32_T size;
};

#endif                                 //struct_emxArray_real_T_232

#ifndef typedef_emxArray_real_T_232_full_loop_T
#define typedef_emxArray_real_T_232_full_loop_T

typedef struct emxArray_real_T_232 emxArray_real_T_232_full_loop_T;

#endif                                 //typedef_emxArray_real_T_232_full_loop_T

#ifndef struct_emxArray_real_T_406
#define struct_emxArray_real_T_406

struct emxArray_real_T_406
{
  real_T data[406];
  int32_T size;
};

#endif                                 //struct_emxArray_real_T_406

#ifndef typedef_emxArray_real_T_406_full_loop_T
#define typedef_emxArray_real_T_406_full_loop_T

typedef struct emxArray_real_T_406 emxArray_real_T_406_full_loop_T;

#endif                                 //typedef_emxArray_real_T_406_full_loop_T

#ifndef struct_emxArray_real_T_759
#define struct_emxArray_real_T_759

struct emxArray_real_T_759
{
  real_T data[759];
  int32_T size;
};

#endif                                 //struct_emxArray_real_T_759

#ifndef typedef_emxArray_real_T_759_full_loop_T
#define typedef_emxArray_real_T_759_full_loop_T

typedef struct emxArray_real_T_759 emxArray_real_T_759_full_loop_T;

#endif                                 //typedef_emxArray_real_T_759_full_loop_T

#ifndef struct_emxArray_int32_T_759
#define struct_emxArray_int32_T_759

struct emxArray_int32_T_759
{
  int32_T data[759];
  int32_T size;
};

#endif                                 //struct_emxArray_int32_T_759

#ifndef typedef_emxArray_int32_T_759_full_loo_T
#define typedef_emxArray_int32_T_759_full_loo_T

typedef struct emxArray_int32_T_759 emxArray_int32_T_759_full_loo_T;

#endif                                 //typedef_emxArray_int32_T_759_full_loo_T

// Custom Type definition for MATLAB Function: '<S29>/NLMPC'
#ifndef struct_tag_i4ZL8C3jdkCeOA2IrFHlEF
#define struct_tag_i4ZL8C3jdkCeOA2IrFHlEF

struct tag_i4ZL8C3jdkCeOA2IrFHlEF
{
  emxArray_real_T_759x406_full__T workspace_double;
  emxArray_int32_T_759_full_loo_T workspace_int;
  emxArray_int32_T_759_full_loo_T workspace_sort;
};

#endif                                 //struct_tag_i4ZL8C3jdkCeOA2IrFHlEF

#ifndef typedef_s_i4ZL8C3jdkCeOA2IrFHlEF_full_T
#define typedef_s_i4ZL8C3jdkCeOA2IrFHlEF_full_T

typedef struct tag_i4ZL8C3jdkCeOA2IrFHlEF s_i4ZL8C3jdkCeOA2IrFHlEF_full_T;

#endif                                 //typedef_s_i4ZL8C3jdkCeOA2IrFHlEF_full_T

#ifndef struct_emxArray_int32_T_406
#define struct_emxArray_int32_T_406

struct emxArray_int32_T_406
{
  int32_T data[406];
  int32_T size;
};

#endif                                 //struct_emxArray_int32_T_406

#ifndef typedef_emxArray_int32_T_406_full_loo_T
#define typedef_emxArray_int32_T_406_full_loo_T

typedef struct emxArray_int32_T_406 emxArray_int32_T_406_full_loo_T;

#endif                                 //typedef_emxArray_int32_T_406_full_loo_T

#ifndef struct_emxArray_boolean_T_759
#define struct_emxArray_boolean_T_759

struct emxArray_boolean_T_759
{
  boolean_T data[759];
  int32_T size;
};

#endif                                 //struct_emxArray_boolean_T_759

#ifndef typedef_emxArray_boolean_T_759_full_l_T
#define typedef_emxArray_boolean_T_759_full_l_T

typedef struct emxArray_boolean_T_759 emxArray_boolean_T_759_full_l_T;

#endif                                 //typedef_emxArray_boolean_T_759_full_l_T

#ifndef struct_emxArray_real_T_104
#define struct_emxArray_real_T_104

struct emxArray_real_T_104
{
  real_T data[104];
  int32_T size;
};

#endif                                 //struct_emxArray_real_T_104

#ifndef typedef_emxArray_real_T_104_full_loop_T
#define typedef_emxArray_real_T_104_full_loop_T

typedef struct emxArray_real_T_104 emxArray_real_T_104_full_loop_T;

#endif                                 //typedef_emxArray_real_T_104_full_loop_T

#ifndef struct_emxArray_real_T_405
#define struct_emxArray_real_T_405

struct emxArray_real_T_405
{
  real_T data[405];
  int32_T size;
};

#endif                                 //struct_emxArray_real_T_405

#ifndef typedef_emxArray_real_T_405_full_loop_T
#define typedef_emxArray_real_T_405_full_loop_T

typedef struct emxArray_real_T_405 emxArray_real_T_405_full_loop_T;

#endif                                 //typedef_emxArray_real_T_405_full_loop_T

// Custom Type definition for MATLAB Function: '<S29>/NLMPC'
#ifndef struct_tag_ZxHOyfVSozxr6pSGbgUCkF
#define struct_tag_ZxHOyfVSozxr6pSGbgUCkF

struct tag_ZxHOyfVSozxr6pSGbgUCkF
{
  int32_T nVarMax;
  int32_T mNonlinIneq;
  int32_T mNonlinEq;
  int32_T mIneq;
  int32_T mEq;
  int32_T iNonIneq0;
  int32_T iNonEq0;
  real_T sqpFval;
  real_T sqpFval_old;
  real_T xstarsqp[69];
  real_T xstarsqp_old[69];
  emxArray_real_T_232_full_loop_T cIneq;
  emxArray_real_T_232_full_loop_T cIneq_old;
  real_T cEq[52];
  real_T cEq_old[52];
  emxArray_real_T_406_full_loop_T grad;
  emxArray_real_T_406_full_loop_T grad_old;
  int32_T FunctionEvaluations;
  int32_T sqpIterations;
  int32_T sqpExitFlag;
  emxArray_real_T_759_full_loop_T lambdasqp;
  emxArray_real_T_759_full_loop_T lambdasqp_old;
  real_T steplength;
  emxArray_real_T_406_full_loop_T delta_x;
  emxArray_real_T_406_full_loop_T socDirection;
  emxArray_real_T_759_full_loop_T lambda_old;
  emxArray_int32_T_759_full_loo_T workingset_old;
  emxArray_real_T_759x759_full__T JacCineqTrans_old;
  emxArray_real_T_406x52_full_l_T JacCeqTrans_old;
  emxArray_real_T_406_full_loop_T gradLag;
  emxArray_real_T_406_full_loop_T delta_gradLag;
  emxArray_real_T_406_full_loop_T xstar;
  real_T fstar;
  real_T firstorderopt;
  emxArray_real_T_759_full_loop_T lambda;
  int32_T state;
  real_T maxConstr;
  int32_T iterations;
  emxArray_real_T_406_full_loop_T searchDir;
};

#endif                                 //struct_tag_ZxHOyfVSozxr6pSGbgUCkF

#ifndef typedef_s_ZxHOyfVSozxr6pSGbgUCkF_full_T
#define typedef_s_ZxHOyfVSozxr6pSGbgUCkF_full_T

typedef struct tag_ZxHOyfVSozxr6pSGbgUCkF s_ZxHOyfVSozxr6pSGbgUCkF_full_T;

#endif                                 //typedef_s_ZxHOyfVSozxr6pSGbgUCkF_full_T

#ifndef struct_tag_Mspqy2ajbjhxqxIYYuZUwC
#define struct_tag_Mspqy2ajbjhxqxIYYuZUwC

struct tag_Mspqy2ajbjhxqxIYYuZUwC
{
  int32_T mConstr;
  int32_T mConstrOrig;
  int32_T mConstrMax;
  int32_T nVar;
  int32_T nVarOrig;
  int32_T nVarMax;
  int32_T ldA;
  emxArray_real_T_406x232_full__T Aineq;
  emxArray_real_T_232x1_full_lo_T bineq;
  emxArray_real_T_406x52_full_l_T Aeq;
  real_T beq[52];
  emxArray_real_T_406_full_loop_T lb;
  emxArray_real_T_406_full_loop_T ub;
  emxArray_int32_T_406_full_loo_T indexLB;
  emxArray_int32_T_406_full_loo_T indexUB;
  emxArray_int32_T_406_full_loo_T indexFixed;
  int32_T mEqRemoved;
  int32_T indexEqRemoved[52];
  emxArray_real_T_759x759_full__T ATwset;
  emxArray_real_T_759_full_loop_T bwset;
  int32_T nActiveConstr;
  emxArray_real_T_759_full_loop_T maxConstrWorkspace;
  int32_T sizes[5];
  int32_T sizesNormal[5];
  int32_T sizesPhaseOne[5];
  int32_T sizesRegularized[5];
  int32_T sizesRegPhaseOne[5];
  int32_T isActiveIdx[6];
  int32_T isActiveIdxNormal[6];
  int32_T isActiveIdxPhaseOne[6];
  int32_T isActiveIdxRegularized[6];
  int32_T isActiveIdxRegPhaseOne[6];
  emxArray_boolean_T_759_full_l_T isActiveConstr;
  emxArray_int32_T_759_full_loo_T Wid;
  emxArray_int32_T_759_full_loo_T Wlocalidx;
  int32_T nWConstr[5];
  int32_T probType;
  real_T SLACK0;
};

#endif                                 //struct_tag_Mspqy2ajbjhxqxIYYuZUwC

#ifndef typedef_s_Mspqy2ajbjhxqxIYYuZUwC_full_T
#define typedef_s_Mspqy2ajbjhxqxIYYuZUwC_full_T

typedef struct tag_Mspqy2ajbjhxqxIYYuZUwC s_Mspqy2ajbjhxqxIYYuZUwC_full_T;

#endif                                 //typedef_s_Mspqy2ajbjhxqxIYYuZUwC_full_T

#ifndef struct_tag_3RW6EhlAOINzvAvYfuaanB
#define struct_tag_3RW6EhlAOINzvAvYfuaanB

struct tag_3RW6EhlAOINzvAvYfuaanB
{
  int32_T ldq;
  emxArray_real_T_759x759_full__T QR;
  emxArray_real_T_759x759_full__T Q;
  emxArray_int32_T_759_full_loo_T jpvt;
  int32_T mrows;
  int32_T ncols;
  emxArray_real_T_759_full_loop_T tau;
  int32_T minRowCol;
  boolean_T usedPivoting;
};

#endif                                 //struct_tag_3RW6EhlAOINzvAvYfuaanB

#ifndef typedef_s_3RW6EhlAOINzvAvYfuaanB_full_T
#define typedef_s_3RW6EhlAOINzvAvYfuaanB_full_T

typedef struct tag_3RW6EhlAOINzvAvYfuaanB s_3RW6EhlAOINzvAvYfuaanB_full_T;

#endif                                 //typedef_s_3RW6EhlAOINzvAvYfuaanB_full_T

#ifndef struct_tag_BtE36YuCWnavoi0lGdvGZF
#define struct_tag_BtE36YuCWnavoi0lGdvGZF

struct tag_BtE36YuCWnavoi0lGdvGZF
{
  emxArray_real_T_406_full_loop_T grad;
  emxArray_real_T_405_full_loop_T Hx;
  boolean_T hasLinear;
  int32_T nvar;
  int32_T maxVar;
  real_T beta;
  real_T rho;
  int32_T objtype;
  int32_T prev_objtype;
  int32_T prev_nvar;
  boolean_T prev_hasLinear;
  real_T gammaScalar;
};

#endif                                 //struct_tag_BtE36YuCWnavoi0lGdvGZF

#ifndef typedef_s_BtE36YuCWnavoi0lGdvGZF_full_T
#define typedef_s_BtE36YuCWnavoi0lGdvGZF_full_T

typedef struct tag_BtE36YuCWnavoi0lGdvGZF s_BtE36YuCWnavoi0lGdvGZF_full_T;

#endif                                 //typedef_s_BtE36YuCWnavoi0lGdvGZF_full_T

#ifndef struct_tag_CWBQhEwNbz3J2I47jPePeB
#define struct_tag_CWBQhEwNbz3J2I47jPePeB

struct tag_CWBQhEwNbz3J2I47jPePeB
{
  c_coder_internal_anonymous_fu_T objfun;
  c_coder_internal_anonymous_fu_T nonlin;
  real_T f_1;
  emxArray_real_T_104_full_loop_T cIneq_1;
  real_T cEq_1[52];
  real_T f_2;
  emxArray_real_T_104_full_loop_T cIneq_2;
  real_T cEq_2[52];
  int32_T nVar;
  int32_T mIneq;
  int32_T mEq;
  int32_T numEvals;
  boolean_T SpecifyObjectiveGradient;
  boolean_T SpecifyConstraintGradient;
  boolean_T hasLB[69];
  boolean_T hasUB[69];
  boolean_T hasBounds;
  int32_T FiniteDifferenceType;
};

#endif                                 //struct_tag_CWBQhEwNbz3J2I47jPePeB

#ifndef typedef_s_CWBQhEwNbz3J2I47jPePeB_full_T
#define typedef_s_CWBQhEwNbz3J2I47jPePeB_full_T

typedef struct tag_CWBQhEwNbz3J2I47jPePeB s_CWBQhEwNbz3J2I47jPePeB_full_T;

#endif                                 //typedef_s_CWBQhEwNbz3J2I47jPePeB_full_T
#endif                                 // RTW_HEADER_full_loop_types_h_

//
// File trailer for generated code.
//
// [EOF]
//
