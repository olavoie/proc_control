/*
 * full_loop_types.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "full_loop".
 *
 * Model version              : 1.339
 * Simulink Coder version : 9.3 (R2020a) 18-Nov-2019
 * C++ source code generated on : Sun Jan 17 20:23:36 2021
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Linux 64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_full_loop_types_h_
#define RTW_HEADER_full_loop_types_h_
#include "rtwtypes.h"
#include "multiword_types.h"

/* Model Code Variants */
#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_ROSVariableLengthArrayInfo_
#define DEFINED_TYPEDEF_FOR_SL_Bus_ROSVariableLengthArrayInfo_

typedef struct {
  uint32_T CurrentLength;
  uint32_T ReceivedLength;
} SL_Bus_ROSVariableLengthArrayInfo;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_full_loop_geometry_msgs_Point_
#define DEFINED_TYPEDEF_FOR_SL_Bus_full_loop_geometry_msgs_Point_

typedef struct {
  real_T X;
  real_T Y;
  real_T Z;
} SL_Bus_full_loop_geometry_msgs_Point;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_full_loop_geometry_msgs_Quaternion_
#define DEFINED_TYPEDEF_FOR_SL_Bus_full_loop_geometry_msgs_Quaternion_

typedef struct {
  real_T X;
  real_T Y;
  real_T Z;
  real_T W;
} SL_Bus_full_loop_geometry_msgs_Quaternion;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_full_loop_geometry_msgs_Pose_
#define DEFINED_TYPEDEF_FOR_SL_Bus_full_loop_geometry_msgs_Pose_

typedef struct {
  SL_Bus_full_loop_geometry_msgs_Point Position;
  SL_Bus_full_loop_geometry_msgs_Quaternion Orientation;
} SL_Bus_full_loop_geometry_msgs_Pose;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_full_loop_geometry_msgs_Vector3_
#define DEFINED_TYPEDEF_FOR_SL_Bus_full_loop_geometry_msgs_Vector3_

typedef struct {
  real_T X;
  real_T Y;
  real_T Z;
} SL_Bus_full_loop_geometry_msgs_Vector3;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_full_loop_geometry_msgs_Twist_
#define DEFINED_TYPEDEF_FOR_SL_Bus_full_loop_geometry_msgs_Twist_

typedef struct {
  SL_Bus_full_loop_geometry_msgs_Vector3 Linear;
  SL_Bus_full_loop_geometry_msgs_Vector3 Angular;
} SL_Bus_full_loop_geometry_msgs_Twist;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_full_loop_gazebo_msgs_ModelState_
#define DEFINED_TYPEDEF_FOR_SL_Bus_full_loop_gazebo_msgs_ModelState_

typedef struct {
  uint8_T ModelName[128];
  SL_Bus_ROSVariableLengthArrayInfo ModelName_SL_Info;
  uint8_T ReferenceFrame[128];
  SL_Bus_ROSVariableLengthArrayInfo ReferenceFrame_SL_Info;
  SL_Bus_full_loop_geometry_msgs_Pose Pose;
  SL_Bus_full_loop_geometry_msgs_Twist Twist;
} SL_Bus_full_loop_gazebo_msgs_ModelState;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_qYRJtcce7MM7XuQ3AAWdMD_
#define DEFINED_TYPEDEF_FOR_struct_qYRJtcce7MM7XuQ3AAWdMD_

typedef struct {
  real_T MaxIterations;
  real_T ConstraintTolerance;
  boolean_T UseWarmStart;
} struct_qYRJtcce7MM7XuQ3AAWdMD;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_SmvKLCDySlKdToNTroAGyF_
#define DEFINED_TYPEDEF_FOR_struct_SmvKLCDySlKdToNTroAGyF_

typedef struct {
  real_T MaxIterations;
  real_T ConstraintTolerance;
  real_T OptimalityTolerance;
  real_T ComplementarityTolerance;
  real_T StepTolerance;
} struct_SmvKLCDySlKdToNTroAGyF;

#endif

#ifndef struct_tag_rkSooZHJZnr3Dpfu1LNqfH
#define struct_tag_rkSooZHJZnr3Dpfu1LNqfH

struct tag_rkSooZHJZnr3Dpfu1LNqfH
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
};

#endif                                 /*struct_tag_rkSooZHJZnr3Dpfu1LNqfH*/

#ifndef typedef_ros_slros_internal_block_Publ_T
#define typedef_ros_slros_internal_block_Publ_T

typedef struct tag_rkSooZHJZnr3Dpfu1LNqfH ros_slros_internal_block_Publ_T;

#endif                               /*typedef_ros_slros_internal_block_Publ_T*/

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

#endif                                 /*struct_tag_s7RdrPWkr8UPAUyTdDJkLaG*/

#ifndef typedef_s7RdrPWkr8UPAUyTdDJkLaG_full__T
#define typedef_s7RdrPWkr8UPAUyTdDJkLaG_full__T

typedef struct tag_s7RdrPWkr8UPAUyTdDJkLaG s7RdrPWkr8UPAUyTdDJkLaG_full__T;

#endif                               /*typedef_s7RdrPWkr8UPAUyTdDJkLaG_full__T*/

#ifndef struct_tag_sJdVcLKPgejLYHLePKb6F6D
#define struct_tag_sJdVcLKPgejLYHLePKb6F6D

struct tag_sJdVcLKPgejLYHLePKb6F6D
{
  real_T grad[21];
  real_T Hx[20];
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

#endif                                 /*struct_tag_sJdVcLKPgejLYHLePKb6F6D*/

#ifndef typedef_sJdVcLKPgejLYHLePKb6F6D_full__T
#define typedef_sJdVcLKPgejLYHLePKb6F6D_full__T

typedef struct tag_sJdVcLKPgejLYHLePKb6F6D sJdVcLKPgejLYHLePKb6F6D_full__T;

#endif                               /*typedef_sJdVcLKPgejLYHLePKb6F6D_full__T*/

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

#endif                                 /*struct_tag_s6ICcRyulWOFjNCN0ll7VsE*/

#ifndef typedef_s6ICcRyulWOFjNCN0ll7VsE_full__T
#define typedef_s6ICcRyulWOFjNCN0ll7VsE_full__T

typedef struct tag_s6ICcRyulWOFjNCN0ll7VsE s6ICcRyulWOFjNCN0ll7VsE_full__T;

#endif                               /*typedef_s6ICcRyulWOFjNCN0ll7VsE_full__T*/

#ifndef struct_tag_koVw4sY7IfOGbh9EAnERnD
#define struct_tag_koVw4sY7IfOGbh9EAnERnD

struct tag_koVw4sY7IfOGbh9EAnERnD
{
  int32_T isInitialized;
  real_T Ac[144];
  real_T Bc[96];
  real_T Cc[144];
  real_T Dc[96];
};

#endif                                 /*struct_tag_koVw4sY7IfOGbh9EAnERnD*/

#ifndef typedef_TrimPlant_full_loop_T
#define typedef_TrimPlant_full_loop_T

typedef struct tag_koVw4sY7IfOGbh9EAnERnD TrimPlant_full_loop_T;

#endif                                 /*typedef_TrimPlant_full_loop_T*/

#ifndef struct_tag_sVTYnQ9ljvmk9dLse9XvTT
#define struct_tag_sVTYnQ9ljvmk9dLse9XvTT

struct tag_sVTYnQ9ljvmk9dLse9XvTT
{
  real_T workspace_double[441];
  int32_T workspace_int[21];
  int32_T workspace_sort[21];
};

#endif                                 /*struct_tag_sVTYnQ9ljvmk9dLse9XvTT*/

#ifndef typedef_sVTYnQ9ljvmk9dLse9XvTT_full_l_T
#define typedef_sVTYnQ9ljvmk9dLse9XvTT_full_l_T

typedef struct tag_sVTYnQ9ljvmk9dLse9XvTT sVTYnQ9ljvmk9dLse9XvTT_full_l_T;

#endif                               /*typedef_sVTYnQ9ljvmk9dLse9XvTT_full_l_T*/

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

#endif                                 /*struct_tag_s1TgE9KstXgkd2qJxO1bF4F*/

#ifndef typedef_s1TgE9KstXgkd2qJxO1bF4F_full__T
#define typedef_s1TgE9KstXgkd2qJxO1bF4F_full__T

typedef struct tag_s1TgE9KstXgkd2qJxO1bF4F s1TgE9KstXgkd2qJxO1bF4F_full__T;

#endif                               /*typedef_s1TgE9KstXgkd2qJxO1bF4F_full__T*/

#ifndef struct_tag_uWme6c6xJ74yTYP81sj1SD
#define struct_tag_uWme6c6xJ74yTYP81sj1SD

struct tag_uWme6c6xJ74yTYP81sj1SD
{
  int32_T isInitialized;
  real_T Aeq[48];
  real_T Beq[6];
  real_T uMin[8];
  real_T uMax[8];
  real_T u0[8];
};

#endif                                 /*struct_tag_uWme6c6xJ74yTYP81sj1SD*/

#ifndef typedef_KickIn_full_loop_T
#define typedef_KickIn_full_loop_T

typedef struct tag_uWme6c6xJ74yTYP81sj1SD KickIn_full_loop_T;

#endif                                 /*typedef_KickIn_full_loop_T*/

#ifndef struct_tag_s2CPTVnVyv153Hb6bxlki6F
#define struct_tag_s2CPTVnVyv153Hb6bxlki6F

struct tag_s2CPTVnVyv153Hb6bxlki6F
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
  real_T xstarsqp[8];
  real_T xstarsqp_old[8];
  real_T cEq[6];
  real_T cEq_old[6];
  real_T grad[21];
  real_T grad_old[21];
  int32_T FunctionEvaluations;
  int32_T sqpIterations;
  int32_T sqpExitFlag;
  real_T lambdasqp[19];
  real_T lambdasqp_old[19];
  real_T steplength;
  real_T delta_x[21];
  real_T socDirection[21];
  real_T lambda_old[19];
  int32_T workingset_old[19];
  real_T gradLag[21];
  real_T delta_gradLag[21];
  real_T xstar[21];
  real_T fstar;
  real_T firstorderopt;
  real_T lambda[19];
  int32_T state;
  real_T maxConstr;
  int32_T iterations;
  real_T searchDir[21];
};

#endif                                 /*struct_tag_s2CPTVnVyv153Hb6bxlki6F*/

#ifndef typedef_s2CPTVnVyv153Hb6bxlki6F_full__T
#define typedef_s2CPTVnVyv153Hb6bxlki6F_full__T

typedef struct tag_s2CPTVnVyv153Hb6bxlki6F s2CPTVnVyv153Hb6bxlki6F_full__T;

#endif                               /*typedef_s2CPTVnVyv153Hb6bxlki6F_full__T*/

#ifndef struct_tag_sH6xx18cQHI5sgA7Ajla4nE
#define struct_tag_sH6xx18cQHI5sgA7Ajla4nE

struct tag_sH6xx18cQHI5sgA7Ajla4nE
{
  int32_T mConstr;
  int32_T mConstrOrig;
  int32_T mConstrMax;
  int32_T nVar;
  int32_T nVarOrig;
  int32_T nVarMax;
  int32_T ldA;
  real_T Aeq[126];
  real_T beq[6];
  real_T lb[21];
  real_T ub[21];
  int32_T indexLB[21];
  int32_T indexUB[21];
  int32_T indexFixed[21];
  int32_T mEqRemoved;
  int32_T indexEqRemoved[6];
  real_T ATwset[399];
  real_T bwset[19];
  int32_T nActiveConstr;
  real_T maxConstrWorkspace[19];
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
  boolean_T isActiveConstr[19];
  int32_T Wid[19];
  int32_T Wlocalidx[19];
  int32_T nWConstr[5];
  int32_T probType;
  real_T SLACK0;
};

#endif                                 /*struct_tag_sH6xx18cQHI5sgA7Ajla4nE*/

#ifndef typedef_sH6xx18cQHI5sgA7Ajla4nE_full__T
#define typedef_sH6xx18cQHI5sgA7Ajla4nE_full__T

typedef struct tag_sH6xx18cQHI5sgA7Ajla4nE sH6xx18cQHI5sgA7Ajla4nE_full__T;

#endif                               /*typedef_sH6xx18cQHI5sgA7Ajla4nE_full__T*/

#ifndef struct_tag_snaQeDJ4fX7UykrKyr5M8jC
#define struct_tag_snaQeDJ4fX7UykrKyr5M8jC

struct tag_snaQeDJ4fX7UykrKyr5M8jC
{
  int32_T ldq;
  real_T QR[441];
  real_T Q[441];
  int32_T jpvt[21];
  int32_T mrows;
  int32_T ncols;
  real_T tau[21];
  int32_T minRowCol;
  boolean_T usedPivoting;
};

#endif                                 /*struct_tag_snaQeDJ4fX7UykrKyr5M8jC*/

#ifndef typedef_snaQeDJ4fX7UykrKyr5M8jC_full__T
#define typedef_snaQeDJ4fX7UykrKyr5M8jC_full__T

typedef struct tag_snaQeDJ4fX7UykrKyr5M8jC snaQeDJ4fX7UykrKyr5M8jC_full__T;

#endif                               /*typedef_snaQeDJ4fX7UykrKyr5M8jC_full__T*/

#ifndef struct_tag_snl99C5je2zMbU5SzygoX6F
#define struct_tag_snl99C5je2zMbU5SzygoX6F

struct tag_snl99C5je2zMbU5SzygoX6F
{
  real_T FMat[441];
  int32_T ldm;
  int32_T ndims;
  int32_T info;
};

#endif                                 /*struct_tag_snl99C5je2zMbU5SzygoX6F*/

#ifndef typedef_snl99C5je2zMbU5SzygoX6F_full__T
#define typedef_snl99C5je2zMbU5SzygoX6F_full__T

typedef struct tag_snl99C5je2zMbU5SzygoX6F snl99C5je2zMbU5SzygoX6F_full__T;

#endif                               /*typedef_snl99C5je2zMbU5SzygoX6F_full__T*/

#ifndef struct_tag_rKzBmc4e22TKbrUwtySqBB
#define struct_tag_rKzBmc4e22TKbrUwtySqBB

struct tag_rKzBmc4e22TKbrUwtySqBB
{
  KickIn_full_loop_T *tunableEnvironment;
};

#endif                                 /*struct_tag_rKzBmc4e22TKbrUwtySqBB*/

#ifndef typedef_c_coder_internal_anonymous_fu_T
#define typedef_c_coder_internal_anonymous_fu_T

typedef struct tag_rKzBmc4e22TKbrUwtySqBB c_coder_internal_anonymous_fu_T;

#endif                               /*typedef_c_coder_internal_anonymous_fu_T*/

#ifndef struct_tag_iyYBPziYRv853Phg0mcgOD
#define struct_tag_iyYBPziYRv853Phg0mcgOD

struct tag_iyYBPziYRv853Phg0mcgOD
{
  c_coder_internal_anonymous_fu_T objfun;
  real_T f_1;
  real_T f_2;
  int32_T nVar;
  int32_T mIneq;
  int32_T mEq;
  int32_T numEvals;
  boolean_T SpecifyObjectiveGradient;
  boolean_T SpecifyConstraintGradient;
  boolean_T hasLB[8];
  boolean_T hasUB[8];
  boolean_T hasBounds;
  int32_T FiniteDifferenceType;
};

#endif                                 /*struct_tag_iyYBPziYRv853Phg0mcgOD*/

#ifndef typedef_s_iyYBPziYRv853Phg0mcgOD_full_T
#define typedef_s_iyYBPziYRv853Phg0mcgOD_full_T

typedef struct tag_iyYBPziYRv853Phg0mcgOD s_iyYBPziYRv853Phg0mcgOD_full_T;

#endif                               /*typedef_s_iyYBPziYRv853Phg0mcgOD_full_T*/

#ifndef struct_tag_8jIp3wBW8W9AJZ7lDTkICE
#define struct_tag_8jIp3wBW8W9AJZ7lDTkICE

struct tag_8jIp3wBW8W9AJZ7lDTkICE
{
  c_coder_internal_anonymous_fu_T objfun;
  int32_T nVar;
  int32_T mCineq;
  int32_T mCeq;
  boolean_T NonFiniteSupport;
  boolean_T SpecifyObjectiveGradient;
  boolean_T SpecifyConstraintGradient;
  boolean_T ScaleProblem;
};

#endif                                 /*struct_tag_8jIp3wBW8W9AJZ7lDTkICE*/

#ifndef typedef_s_8jIp3wBW8W9AJZ7lDTkICE_full_T
#define typedef_s_8jIp3wBW8W9AJZ7lDTkICE_full_T

typedef struct tag_8jIp3wBW8W9AJZ7lDTkICE s_8jIp3wBW8W9AJZ7lDTkICE_full_T;

#endif                               /*typedef_s_8jIp3wBW8W9AJZ7lDTkICE_full_T*/

/* Parameters (default storage) */
typedef struct P_full_loop_T_ P_full_loop_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_full_loop_T RT_MODEL_full_loop_T;

#endif                                 /* RTW_HEADER_full_loop_types_h_ */
