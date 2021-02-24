//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: full_loop.h
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
#ifndef RTW_HEADER_full_loop_h_
#define RTW_HEADER_full_loop_h_
#include <math.h>
#include <string.h>
#include <stddef.h>
#include <stdio.h>
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "slros_initialize.h"
#include "full_loop_types.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"
#include "rtGetNaN.h"
#include "rt_zcfcn.h"
#include "rt_defines.h"

// Macros for accessing real-time model data structure
#ifndef rtmGetContStateDisabled
# define rtmGetContStateDisabled(rtm)  ((rtm)->contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
# define rtmSetContStateDisabled(rtm, val) ((rtm)->contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
# define rtmGetContStates(rtm)         ((rtm)->contStates)
#endif

#ifndef rtmSetContStates
# define rtmSetContStates(rtm, val)    ((rtm)->contStates = (val))
#endif

#ifndef rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag
# define rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm) ((rtm)->CTOutputIncnstWithState)
#endif

#ifndef rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag
# define rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm, val) ((rtm)->CTOutputIncnstWithState = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
# define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
# define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetIntgData
# define rtmGetIntgData(rtm)           ((rtm)->intgData)
#endif

#ifndef rtmSetIntgData
# define rtmSetIntgData(rtm, val)      ((rtm)->intgData = (val))
#endif

#ifndef rtmGetOdeF
# define rtmGetOdeF(rtm)               ((rtm)->odeF)
#endif

#ifndef rtmSetOdeF
# define rtmSetOdeF(rtm, val)          ((rtm)->odeF = (val))
#endif

#ifndef rtmGetOdeY
# define rtmGetOdeY(rtm)               ((rtm)->odeY)
#endif

#ifndef rtmSetOdeY
# define rtmSetOdeY(rtm, val)          ((rtm)->odeY = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
# define rtmGetPeriodicContStateIndices(rtm) ((rtm)->periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
# define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
# define rtmGetPeriodicContStateRanges(rtm) ((rtm)->periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
# define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->periodicContStateRanges = (val))
#endif

#ifndef rtmGetZCCacheNeedsReset
# define rtmGetZCCacheNeedsReset(rtm)  ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
# define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetdX
# define rtmGetdX(rtm)                 ((rtm)->derivs)
#endif

#ifndef rtmSetdX
# define rtmSetdX(rtm, val)            ((rtm)->derivs = (val))
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               ((rtm)->Timing.t)
#endif

#ifndef ODE3_INTG
#define ODE3_INTG

// ODE3 Integration Data
typedef struct {
  real_T *y;                           // output
  real_T *f[3];                        // derivatives
} ODE3_IntgData;

#endif

// Class declaration for model full_loop
class full_loopModelClass {
  // public data and function members
 public:
  // Block signals (default storage)
  typedef struct {
    s_3RW6EhlAOINzvAvYfuaanB_full_T QRManager;
    s_Mspqy2ajbjhxqxIYYuZUwC_full_T WorkingSet;
    s_Mspqy2ajbjhxqxIYYuZUwC_full_T b_WorkingSet;
    s_ZxHOyfVSozxr6pSGbgUCkF_full_T TrialState;
    s_ZxHOyfVSozxr6pSGbgUCkF_full_T q;
    s_ZxHOyfVSozxr6pSGbgUCkF_full_T b_TrialState;
    s_ZxHOyfVSozxr6pSGbgUCkF_full_T b_solution;
    s_a5SYZcWNC5KFUTosoMMbl_full__T CholManager;
    real_T b_data[576081];
    real_T b_data_m[576081];
    real_T b_data_c[576081];
    real_T b_data_k[576081];
    s_i4ZL8C3jdkCeOA2IrFHlEF_full_T memspace;
    real_T workspace_data[308154];
    real_T c_data[308154];
    real_T f_data[94192];
    real_T k_data[94192];
    cell_wrap_14_full_loop_T reshapes[3];
    real_T l_data[21112];
    real_T A_data[10880];
    real_T varargout_3_data[7176];
    real_T Jc_data[7176];
    real_T Jc_data_c[7176];
    real_T varargout_3_data_b[7176];
    real_T Jx[5408];
    real_T Jx_data[5408];
    real_T varargin_1_data[5408];
    real_T unusedExpr[4761];
    real_T Au[4096];
    real_T Auf_data[4096];
    real_T varargout_4[3588];
    real_T Jceq[3588];
    real_T varargout_4_p[3588];
    real_T tmp_data[3328];
    real_T Jx_c[2704];
    real_T y_data[2048];
    real_T y_data_f[2048];
    s_CWBQhEwNbz3J2I47jPePeB_full_T FiniteDifferences;
    real_T Jmv[1664];
    s_siHoaqeHIV5TpidUajpsGD_full_T FcnEvaluator;
    real_T Jmv_g[832];
    s_BtE36YuCWnavoi0lGdvGZF_full_T QPObjective;
    real_T y_data_g[759];
    real_T c_data_m[759];
    real_T work_data[759];
    real_T work_data_n[759];
    real_T vn1_data[759];
    real_T vn2_data[759];
    real_T work_data_p[759];
    real_T y_data_l[759];
    real_T e_data[759];
    real_T g_data[759];
    real_T c_data_j[759];
    real_T b_data_d[759];
    real_T h_data[759];
    real_T i_data[759];
    real_T y_data_gu[759];
    real_T e_data_l[759];
    real_T y_data_d[759];
    real_T d_data[759];
    s_A0rUWcsbMx3S06V1NlippE_full_T runtimedata;
    s_A0rUWcsbMx3S06V1NlippE_full_T expl_temp;
    s_A0rUWcsbMx3S06V1NlippE_full_T expl_temp_d;
    real_T c_data_l[406];
    real_T g_data_o[406];
    real_T b_data_b[406];
    real_T d_data_n[406];
    real_T c_data_b[406];
    real_T d_data_l[406];
    int32_T b_data_h[759];
    int32_T c_data_bn[759];
    int32_T d_data_d[759];
    int32_T b_data_e[759];
    int32_T c_data_bj[759];
    int32_T d_data_j[759];
    int32_T b_data_f[759];
    int32_T c_data_a[759];
    real_T d_data_ju[232];
    real_T h_data_j[232];
    real_T c_data_o[232];
    real_T Ix[169];
    real_T Ak[169];
    real_T Ak1[169];
    real_T a[169];
    real_T Ck[169];
    real_T B_data[128];
    real_T b_Bu[128];
    sACkMJ1zT2VJOHR6eMwwEPC_full__T userdata;
    real_T varargout_1_data[104];
    real_T c_data_n[104];
    real_T Bk[104];
    real_T Bk1[104];
    real_T Bk_i[104];
    real_T varargout_1_data_o[104];
    real_T c_data_nv[104];
    real_T b_c[104];
    real_T Je_data[104];
    real_T varargout_1_data_m[104];
    real_T z0[69];
    real_T zLB[69];
    real_T zUB[69];
    real_T TrialState_c[69];
    real_T varargout_2[69];
    real_T X[65];
    real_T X_m[65];
    real_T X_m3[65];
    real_T X_j[65];
    real_T X_h[65];
    real_T As[64];
    real_T FromWorkspace[52];          // '<S26>/From Workspace'
    real_T e_a[52];
    real_T j_as[52];
    real_T d_i[52];
    real_T varargout_2_l[52];
    real_T X0[52];
    real_T dv[52];
    real_T dv1[52];
    real_T dv2[52];
    real_T varargout_2_o[52];
    real_T gfX[52];
    real_T b[52];
    real_T z[52];
    real_T gfX_o[52];
    real_T varargout_2_i[52];
    real_T X_f[52];
    real_T runtimedata_i[52];
    cell_wrap_10_full_loop_T d;
    cell_wrap_10_full_loop_T e;
    cell_wrap_10_full_loop_T h;
    cell_wrap_10_full_loop_T i;
    cell_wrap_10_full_loop_T j;
    cell_wrap_10_full_loop_T k;
    cell_wrap_10_full_loop_T d_c;
    cell_wrap_10_full_loop_T e_c;
    cell_wrap_10_full_loop_T h_p;
    cell_wrap_10_full_loop_T i_p;
    cell_wrap_10_full_loop_T j_a;
    cell_wrap_10_full_loop_T k_e;
    real_T U[40];
    real_T U_f[40];
    real_T U_g[40];
    real_T U_c[40];
    real_T Umv[40];
    real_T U_o[40];
    int32_T indexLB[69];
    int32_T indexUB[69];
    SL_Bus_full_loop_sonia_common_ThrusterPwm msg;// '<S4>/MATLAB Function1'
    real_T MV0[32];
    real_T MVMin0[32];
    real_T MVMax0[32];
    real_T dv3[32];
    real_T dv4[32];
    real_T dv5[32];
    real_T gfU[32];
    real_T c[32];
    real_T a_o[32];
    real_T gfU_h[32];
    real_T Umv_l[32];
    cell_wrap_12_full_loop_T f;
    cell_wrap_12_full_loop_T g;
    cell_wrap_12_full_loop_T l;
    cell_wrap_12_full_loop_T m;
    cell_wrap_12_full_loop_T n;
    cell_wrap_12_full_loop_T o;
    cell_wrap_12_full_loop_T p;
    cell_wrap_12_full_loop_T f_l;
    cell_wrap_12_full_loop_T g_m;
    cell_wrap_12_full_loop_T l_m;
    cell_wrap_12_full_loop_T m_c;
    cell_wrap_12_full_loop_T n_f;
    cell_wrap_12_full_loop_T o_p;
    cell_wrap_12_full_loop_T p_e;
    boolean_T icf[128];
    uint8_T ii_data[128];
    real_T b_h[16];
    real_T a_m[16];
    s6ICcRyulWOFjNCN0ll7VsE_full__T MeritFunction;
    boolean_T icf_c[104];
    int8_T Je[104];
    int8_T b_data_kl[104];
    int8_T d_data_p[104];
    int32_T ic[26];
    real_T Reshape[13];
    real_T ic_p[13];
    real_T X_p[13];
    real_T dv6[13];
    real_T dv7[13];
    real_T ic_a[13];
    real_T runtimedata_OutputMin[13];
    real_T ix[13];
    real_T wtYerr[13];
    real_T gfx[13];
    cell_wrap_8_full_loop_T b_m;
    cell_wrap_8_full_loop_T b_h3;
    boolean_T b_f[69];
    boolean_T c_h[69];
    s1TgE9KstXgkd2qJxO1bF4F_full__T expl_temp_j;
    s1TgE9KstXgkd2qJxO1bF4F_full__T expl_temp_e;
    s1TgE9KstXgkd2qJxO1bF4F_full__T qpoptions;
    s1TgE9KstXgkd2qJxO1bF4F_full__T qpoptions_o;
    s1TgE9KstXgkd2qJxO1bF4F_full__T qpoptions_b;
    s1TgE9KstXgkd2qJxO1bF4F_full__T qpoptions_a;
    s1TgE9KstXgkd2qJxO1bF4F_full__T qpoptions_g;
    s1TgE9KstXgkd2qJxO1bF4F_full__T qpoptions_e;
    real_T Memory1[8];                 // '<S26>/Memory1'
    real_T NtoPWM[8];                  // '<S10>/N to PWM'
    real_T MultiportSwitch[8];         // '<S5>/Multiport Switch'
    real_T dv8[8];
    real_T U_a[8];
    real_T iu[8];
    real_T umvk[8];
    real_T duk[8];
    real_T gfu[8];
    real_T ic_d[8];
    real_T runtimedata_a[8];
    cell_wrap_9_full_loop_T c_e;
    cell_wrap_9_full_loop_T c_c;
    int32_T gfx_tmp[13];
    boolean_T bv[52];
    boolean_T bv1[52];
    int32_T gfu_tmp[8];
    char_T cv[32];
    boolean_T icf_p[26];
    real_T InitialBodyvelocity[3];     // '<S1>/Initial Body velocity '
    real_T b_varargout_1[3];
    real_T VectorConcatenate[3];       // '<S63>/Vector Concatenate'
    int32_T x[6];
    int32_T x_tmp[6];
    uint16_T NtoPWM_m[8];              // '<S5>/N to PWM'
    boolean_T bv2[13];
    boolean_T bv3[13];
    int32_T Jx_size[3];
    s7RdrPWkr8UPAUyTdDJkLaG_full__T Flags;
    real_T Output;                     // '<S21>/Output'
    real_T Constant1[4];               // '<Root>/Constant1'
    real_T Sum;                        // '<S57>/Sum'
    real_T Sum_g;                      // '<S58>/Sum'
    real_T Sum_e;                      // '<S59>/Sum'
    real_T WorldPosition[3];           // '<S6>/Discrete-Time Integrator'
    real_T Output_d;                   // '<S22>/Output'
    real_T InitialAngularRates[3];     // '<S1>/Initial Angular Rates'
    real_T XDrift;                     // '<S9>/X Drift'
    real_T YDrift;                     // '<S9>/Y Drift'
    real_T Constant[3];                // '<Root>/Constant'
    real_T mv[8];                      // '<S29>/NLMPC'
    real_T Position_dot[3];            // '<S1>/AUV State Equation'
    real_T Quaternion_dot[4];          // '<S1>/AUV State Equation'
    real_T BodyVelocity_dot[3];        // '<S1>/AUV State Equation'
    real_T AngularRates_dot[3];        // '<S1>/AUV State Equation'
    real_T Merge;                      // '<S65>/Merge'
    real_T d_ie;
    real_T scale;
    real_T absxk;
    real_T t;
    real_T t8;
    real_T t9;
    real_T t13;
    real_T t14;
    real_T t15;
    real_T t16;
    real_T t17;
    real_T t18;
    real_T t19;
    real_T t20;
    real_T t21;
    real_T t22;
    real_T t30;
    real_T Product3_i;                 // '<S64>/Product3'
    real_T Product2_j;                 // '<S64>/Product2'
    real_T Product1_o;                 // '<S64>/Product1'
    real_T fcn2;                       // '<S62>/fcn2'
    real_T fcn4;                       // '<S62>/fcn4'
    real_T Product2_a;                 // '<S56>/Product2'
    real_T rtb_TmpSignalConversionAtSFun_o;
    real_T rtb_TmpSignalConversionAtSFun_m;
    real_T rtb_TmpSignalConversionAtSFun_c;
    real_T y_idx_0;
    real_T y_idx_1;
    real_T y_idx_2;
    real_T t15_tmp;
    real_T t16_tmp;
    real_T t17_tmp;
    real_T t18_tmp;
    real_T BodyVelocity_dot_tmp;
    real_T BodyVelocity_dot_tmp_f;
    real_T b_hc;
    real_T expl_temp_m;
    real_T expl_temp_a;
    real_T expl_temp_k;
    real_T expl_temp_p;
    real_T d_b;
    real_T beta;
    real_T rho;
    real_T b_ch;
    real_T constrViolation;
    real_T tol;
    real_T qtb;
    real_T temp2;
    real_T b_atmp;
    real_T xnorm;
    real_T scale_n;
    real_T absxk_i;
    real_T t_m;
    real_T phi_alpha;
    real_T e_j;
    real_T d_e;
    real_T t2;
    real_T t3;
    real_T t4;
    real_T t5;
    real_T t6;
    real_T t7;
    real_T t8_m;
    real_T t9_m;
    real_T t10;
    real_T t11;
    real_T t12;
    real_T t13_j;
    real_T t17_f;
    real_T t18_a;
    real_T t19_g;
    real_T t20_n;
    real_T t21_d;
    real_T t22_n;
    real_T t23;
    real_T t24;
    real_T t25;
    real_T t26;
    real_T t27;
    real_T t28;
    real_T t29;
    real_T t30_c;
    real_T t31;
    real_T t32;
    real_T t33;
    real_T t34;
    real_T t39;
    real_T t40;
    real_T t41;
    real_T t42;
    real_T t43;
    real_T t44;
    real_T t45;
    real_T t46;
    real_T t47;
    real_T t48;
    real_T t27_tmp;
    real_T t31_tmp;
    real_T t24_tmp;
    real_T t32_tmp;
    real_T t25_tmp;
    real_T t29_tmp;
    real_T oldDirIdx;
    real_T tol_f;
    real_T temp;
    real_T e_p;
    real_T tol_p;
    real_T b_atmp_n;
    real_T c_k;
    real_T normDelta;
    real_T b_n;
    real_T constrViolation_new;
    real_T constrViolation_minnormX;
    real_T constrViolation_basicX;
    real_T u1;
    real_T c_o;
    real_T c_g;
    real_T e_cq;
    real_T gfE;
    real_T t8_c;
    real_T t9_m1;
    real_T t11_j;
    real_T t12_k;
    real_T t13_m;
    real_T t14_p;
    real_T t15_d;
    real_T t16_g;
    real_T t17_c;
    real_T t18_c;
    real_T t19_i;
    real_T t20_d;
    real_T t21_g;
    real_T t22_l;
    real_T optimRelativeFactor;
    real_T nlpComplErrorTmp;
    real_T nlpComplErrorLSQ;
    real_T c_f;
    real_T d1;
    real_T tol_d;
    real_T denomTol;
    real_T phaseOneCorrectionP;
    real_T pk_corrected;
    real_T ratio;
    real_T c_j;
    real_T u0;
    real_T c_i;
    real_T c_h2;
    real_T b_c_n;
    real_T s;
    real_T c_c_o;
    real_T roe;
    real_T absa;
    real_T absb;
    real_T scale_c;
    real_T u1_b;
    real_T c_er;
    real_T c_d;
    real_T ssq;
    real_T c_ik;
    real_T u1_g;
    real_T u1_n;
    real_T c_l;
    real_T d_ce;
    real_T e_n;
    real_T c_c_p;
    real_T c_dk;
    real_T u1_o;
    real_T c_jr;
    real_T c_c2;
    real_T c_hp;
    real_T e_d;
    real_T gfE_c;
    real_T temp_p;
    real_T scale_p;
    int32_T A_size[2];
    int32_T f_size[2];
    int32_T k_size[2];
    int32_T l_size[2];
    int32_T b_size[2];
    int32_T varargout_1_size[2];
    int32_T c_size[2];
    int32_T Jc_size[2];
    int32_T b_size_o[2];
    int32_T varargout_3_size[2];
    int32_T varargout_1_size_n[2];
    int32_T c_size_l[2];
    int32_T Jc_size_p[2];
    int32_T varargout_3_size_p[2];
    int32_T varargout_1_size_f[2];
    int32_T c_size_i[2];
    int32_T b_size_ox[2];
    int32_T b_size_k[2];
    int32_T b_k;
    int32_T b_i;
    int32_T B_size;
    int32_T mIneq;
    int32_T mConstrMax;
    int32_T maxDims;
    int32_T mNonlinIneq;
    int32_T mLB;
    int32_T mUB;
    int32_T mFixed;
    int32_T c_size_a;
    int32_T d_size;
    int32_T tmp_size;
    int32_T tmp_size_o;
    int32_T nVar;
    int32_T mFixed_j;
    int32_T mIneq_p;
    int32_T mLB_o;
    int32_T mUB_l;
    int32_T mConstr;
    int32_T mLinIneq;
    int32_T qpoptions_MaxIterations;
    int32_T loop_ub;
    int32_T g_size;
    int32_T h_size;
    int32_T u1_k;
    int32_T nVar_j;
    int32_T loop_ub_f;
    int32_T b_size_c;
    int32_T d_size_f;
    int32_T e_size;
    int32_T nVarOrig;
    int32_T nVarMax;
    int32_T mIneq_n;
    int32_T temp_i;
    int32_T nArtificial;
    int32_T nVar_l;
    int32_T loop_ub_i;
    int32_T g_size_k;
    int32_T b_fc;
    int32_T c_size_al;
    int32_T mTotalWorkingEq;
    int32_T idx_row;
    int32_T b_idx_col;
    int32_T b_size_d;
    int32_T c_size_e;
    int32_T b_idx;
    int32_T ix_e;
    int32_T iy;
    int32_T k_b;
    int32_T loop_ub_a;
    int32_T c_size_il;
    int32_T d_size_fa;
    int32_T ma;
    int32_T minmana;
    int32_T minmn;
    int32_T c_j_j;
    int32_T ma_o;
    int32_T mLinIneq_f;
    int32_T evalStatus;
    int32_T nWIneq_old;
    int32_T nWLower_old;
    int32_T nWUpper_old;
    int32_T nVar_o;
    int32_T mConstrMax_l;
    int32_T b_i_l;
    int32_T nFixedConstr;
    int32_T idx;
    int32_T nDepIneq;
    int32_T b_size_g;
    int32_T c_size_d;
    int32_T b_idx_d;
    int32_T c_size_j;
    int32_T d_size_f1;
    int32_T minmn_j;
    int32_T ii;
    int32_T c_idx_row;
    int32_T c_idx_col;
    int32_T result;
    int32_T c_result;
    int32_T result_idx_0;
    int32_T partialTrueCount;
    int32_T idx_h;
    int32_T nFixedConstr_c;
    int32_T idx_n;
    int32_T nDepIneq_k;
    int32_T b_size_a;
    int32_T c_size_f;
    int32_T PROBTYPE_ORIG;
    int32_T nVar_jz;
    int32_T nVarP1;
    int32_T PHASEONE;
    int32_T mEqFixed;
    int32_T activeSetChangeID;
    int32_T nVar_k;
    int32_T globalActiveConstrIdx;
    int32_T idxMinLambda;
    int32_T TYPE;
    int32_T idx_local;
    int32_T h_size_b;
    int32_T loop_ub_h;
    int32_T d_size_e;
    int32_T i_size;
    int32_T mWConstr;
    int32_T nVar_h;
    int32_T b_idx_k;
    int32_T b_idx_row;
    int32_T b_size_j;
    int32_T mLB_oo;
    int32_T mUB_c;
    int32_T mFixed_h;
    int32_T idx_i;
    int32_T mIneq_pl;
    int32_T b_k_f;
    int32_T nVar_e;
    int32_T mFixed_n;
    int32_T mIneq_h;
    int32_T mLB_h;
    int32_T mUB_f;
    int32_T mLambda;
    int32_T nActiveConstr;
    int32_T d_size_i;
    int32_T fullRank_R;
    int32_T rankR;
    int32_T iQR_diag;
    int32_T iQR0;
    int32_T idx_f;
    int32_T n_c;
    int32_T k_n;
    int32_T i_h;
    int32_T totalIneq;
    int32_T mLB_k;
    int32_T mUB_h;
    int32_T mFixed_b;
    int32_T idx_o;
    int32_T mIneq_nq;
    int32_T b_k_m;
    int32_T nVar_ku;
    int32_T mNull;
    int32_T nullStartIdx;
    int32_T d_idx;
    int32_T loop_ub_j;
    int32_T c_size_h;
    int32_T e_size_f;
    int32_T ineqEnd;
    int32_T c_dy;
    int32_T unnamed_idx_1;
    int32_T result_l;
    int32_T result_idx_0_k;
    int32_T mIneq_i;
    int32_T mLBOrig;
    int32_T mIneq_h5;
    int32_T mIneq_m;
    int32_T idx_g;
    int32_T minmana_l;
    int32_T minmn_m;
    int32_T mNull_n;
    int32_T ldw;
    int32_T b_idx_g;
    int32_T nmi;
    int32_T b_idx_dj;
    int32_T i_m;
    int32_T nWFixed;
    ZCEventType zcEvent;
  } B_full_loop_T;

  // Block states (default storage) for system '<Root>'
  typedef struct {
    DiscontinuityCheck_full_loop_T obj;// '<S53>/MATLAB System2'
    ros_slros_internal_block_Publ_T obj_j;// '<S25>/SinkBlock'
    real_T DiscreteTimeIntegrator_DSTATE[3];// '<S6>/Discrete-Time Integrator'
    real_T NextOutput;                 // '<S21>/White Noise'
    real_T NextOutput_k;               // '<S22>/White Noise'
    real_T Memory1_PreviousInput[8];   // '<S26>/Memory1'
    real_T XDrift_NextOutput;          // '<S9>/X Drift'
    real_T YDrift_NextOutput;          // '<S9>/Y Drift'
    struct {
      void *TimePtr;
      void *DataPtr;
      void *RSimInfoPtr;
    } FromWorkspace_PWORK;             // '<S26>/From Workspace'

    uint32_T RandSeed;                 // '<S21>/White Noise'
    uint32_T RandSeed_g;               // '<S22>/White Noise'
    uint32_T RandSeed_gl;              // '<S9>/X Drift'
    uint32_T RandSeed_n;               // '<S9>/Y Drift'
    int_T Integrator2_IWORK;           // '<S1>/Integrator2'
    int_T Integrator1_IWORK;           // '<S1>/Integrator1'
    int_T Integrator3_IWORK;           // '<S1>/Integrator3'
    struct {
      int_T PrevIndex;
    } FromWorkspace_IWORK;             // '<S26>/From Workspace'

    int_T Integrator_IWORK;            // '<S1>/Integrator'
    int8_T If_ActiveSubsystem;         // '<S65>/If'
  } DW_full_loop_T;

  // Continuous states (default storage)
  typedef struct {
    real_T Integrator2_CSTATE[3];      // '<S1>/Integrator2'
    real_T Integrator1_CSTATE[4];      // '<S1>/Integrator1'
    real_T Integrator3_CSTATE[3];      // '<S1>/Integrator3'
    real_T TransferFcn_CSTATE;         // '<S13>/Transfer Fcn'
    real_T TransferFcn_CSTATE_g;       // '<S14>/Transfer Fcn'
    real_T TransferFcn_CSTATE_p;       // '<S15>/Transfer Fcn'
    real_T TransferFcn_CSTATE_k;       // '<S16>/Transfer Fcn'
    real_T TransferFcn_CSTATE_e;       // '<S17>/Transfer Fcn'
    real_T TransferFcn_CSTATE_kk;      // '<S18>/Transfer Fcn'
    real_T TransferFcn_CSTATE_o;       // '<S19>/Transfer Fcn'
    real_T TransferFcn_CSTATE_l;       // '<S20>/Transfer Fcn'
    real_T Integrator_CSTATE[3];       // '<S1>/Integrator'
  } X_full_loop_T;

  // State derivatives (default storage)
  typedef struct {
    real_T Integrator2_CSTATE[3];      // '<S1>/Integrator2'
    real_T Integrator1_CSTATE[4];      // '<S1>/Integrator1'
    real_T Integrator3_CSTATE[3];      // '<S1>/Integrator3'
    real_T TransferFcn_CSTATE;         // '<S13>/Transfer Fcn'
    real_T TransferFcn_CSTATE_g;       // '<S14>/Transfer Fcn'
    real_T TransferFcn_CSTATE_p;       // '<S15>/Transfer Fcn'
    real_T TransferFcn_CSTATE_k;       // '<S16>/Transfer Fcn'
    real_T TransferFcn_CSTATE_e;       // '<S17>/Transfer Fcn'
    real_T TransferFcn_CSTATE_kk;      // '<S18>/Transfer Fcn'
    real_T TransferFcn_CSTATE_o;       // '<S19>/Transfer Fcn'
    real_T TransferFcn_CSTATE_l;       // '<S20>/Transfer Fcn'
    real_T Integrator_CSTATE[3];       // '<S1>/Integrator'
  } XDot_full_loop_T;

  // State disabled
  typedef struct {
    boolean_T Integrator2_CSTATE[3];   // '<S1>/Integrator2'
    boolean_T Integrator1_CSTATE[4];   // '<S1>/Integrator1'
    boolean_T Integrator3_CSTATE[3];   // '<S1>/Integrator3'
    boolean_T TransferFcn_CSTATE;      // '<S13>/Transfer Fcn'
    boolean_T TransferFcn_CSTATE_g;    // '<S14>/Transfer Fcn'
    boolean_T TransferFcn_CSTATE_p;    // '<S15>/Transfer Fcn'
    boolean_T TransferFcn_CSTATE_k;    // '<S16>/Transfer Fcn'
    boolean_T TransferFcn_CSTATE_e;    // '<S17>/Transfer Fcn'
    boolean_T TransferFcn_CSTATE_kk;   // '<S18>/Transfer Fcn'
    boolean_T TransferFcn_CSTATE_o;    // '<S19>/Transfer Fcn'
    boolean_T TransferFcn_CSTATE_l;    // '<S20>/Transfer Fcn'
    boolean_T Integrator_CSTATE[3];    // '<S1>/Integrator'
  } XDis_full_loop_T;

  // Zero-crossing (trigger) state
  typedef struct {
    ZCSigState Integrator2_Reset_ZCE;  // '<S1>/Integrator2'
    ZCSigState Integrator1_Reset_ZCE;  // '<S1>/Integrator1'
    ZCSigState Integrator3_Reset_ZCE;  // '<S1>/Integrator3'
    ZCSigState Integrator_Reset_ZCE;   // '<S1>/Integrator'
  } PrevZCX_full_loop_T;

  // Parameters (default storage)
  struct P_full_loop_T {
    real_T N[201];                     // Variable: N
                                          //  Referenced by:
                                          //    '<S5>/N to PWM'
                                          //    '<S10>/N to PWM'

    real_T dMaxX;                      // Variable: dMaxX
                                          //  Referenced by: '<S9>/X Drift'

    real_T dMaxY;                      // Variable: dMaxY
                                          //  Referenced by: '<S9>/Y Drift'

    real_T dMinX;                      // Variable: dMinX
                                          //  Referenced by: '<S9>/X Drift'

    real_T dMinY;                      // Variable: dMinY
                                          //  Referenced by: '<S9>/Y Drift'

    real_T dSeedX;                     // Variable: dSeedX
                                          //  Referenced by: '<S9>/X Drift'

    real_T dSeedY;                     // Variable: dSeedY
                                          //  Referenced by: '<S9>/Y Drift'

    real_T tmax;                       // Variable: tmax
                                          //  Referenced by: '<S26>/Constant6'

    real_T tmin;                       // Variable: tmin
                                          //  Referenced by: '<S26>/Constant'

    real_T waPhi;                      // Variable: waPhi
                                          //  Referenced by: '<S9>/Roll Wave'

    real_T waPsi;                      // Variable: waPsi
                                          //  Referenced by: '<S9>/Yaw Wave'

    real_T waTheta;                    // Variable: waTheta
                                          //  Referenced by: '<S9>/Pitch Wave'

    real_T waX;                        // Variable: waX
                                          //  Referenced by: '<S9>/X Wave'

    real_T waY;                        // Variable: waY
                                          //  Referenced by: '<S9>/Y Wave'

    real_T waZ;                        // Variable: waZ
                                          //  Referenced by: '<S9>/Z Wave'

    real_T wfPhi;                      // Variable: wfPhi
                                          //  Referenced by: '<S9>/Roll Wave'

    real_T wfPsi;                      // Variable: wfPsi
                                          //  Referenced by: '<S9>/Yaw Wave'

    real_T wfTheta;                    // Variable: wfTheta
                                          //  Referenced by: '<S9>/Pitch Wave'

    real_T wfX;                        // Variable: wfX
                                          //  Referenced by: '<S9>/X Wave'

    real_T wfY;                        // Variable: wfY
                                          //  Referenced by: '<S9>/Y Wave'

    real_T wfZ;                        // Variable: wfZ
                                          //  Referenced by: '<S9>/Z Wave'

    real_T wpPhi;                      // Variable: wpPhi
                                          //  Referenced by: '<S9>/Roll Wave'

    real_T wpPsi;                      // Variable: wpPsi
                                          //  Referenced by: '<S9>/Yaw Wave'

    real_T wpTheta;                    // Variable: wpTheta
                                          //  Referenced by: '<S9>/Pitch Wave'

    real_T wpX;                        // Variable: wpX
                                          //  Referenced by: '<S9>/X Wave'

    real_T wpY;                        // Variable: wpY
                                          //  Referenced by: '<S9>/Y Wave'

    real_T wpZ;                        // Variable: wpZ
                                          //  Referenced by: '<S9>/Z Wave'

    uint16_T PWM[201];                 // Variable: PWM
                                          //  Referenced by:
                                          //    '<S5>/N to PWM'
                                          //    '<S10>/N to PWM'

    real_T BandLimitedWhiteNoise_Cov;
                                    // Mask Parameter: BandLimitedWhiteNoise_Cov
                                       //  Referenced by: '<S21>/Output'

    real_T BandLimitedWhiteNoise1_Cov;
                                   // Mask Parameter: BandLimitedWhiteNoise1_Cov
                                      //  Referenced by: '<S22>/Output'

    real_T BandLimitedWhiteNoise_seed;
                                   // Mask Parameter: BandLimitedWhiteNoise_seed
                                      //  Referenced by: '<S21>/White Noise'

    real_T BandLimitedWhiteNoise1_seed;
                                  // Mask Parameter: BandLimitedWhiteNoise1_seed
                                     //  Referenced by: '<S22>/White Noise'

    SL_Bus_full_loop_sonia_common_ThrusterPwm Constant_Value;// Computed Parameter: Constant_Value
                                                                //  Referenced by: '<S23>/Constant'

    real_T Constant1_Value[8];         // Expression: zeros(1,8)
                                          //  Referenced by: '<S5>/Constant1'

    real_T Constant_Value_m;           // Expression: 1
                                          //  Referenced by: '<S66>/Constant'

    real_T Constant_Value_j;           // Expression: 1
                                          //  Referenced by: '<S67>/Constant'

    real_T InitialBodyvelocity_Value[3];// Expression: [0,0,0]
                                           //  Referenced by: '<S1>/Initial Body velocity '

    real_T WhiteNoise_Mean;            // Expression: 0
                                          //  Referenced by: '<S21>/White Noise'

    real_T WhiteNoise_StdDev;          // Computed Parameter: WhiteNoise_StdDev
                                          //  Referenced by: '<S21>/White Noise'

    real_T Constant1_Value_a[4];       // Expression: [1,0,0,0]
                                          //  Referenced by: '<Root>/Constant1'

    real_T Constant_Value_e;           // Expression: 0.5
                                          //  Referenced by: '<S57>/Constant'

    real_T Gain2_Gain;                 // Expression: 2
                                          //  Referenced by: '<S57>/Gain2'

    real_T Gain_Gain;                  // Expression: 2
                                          //  Referenced by: '<S57>/Gain'

    real_T Gain1_Gain;                 // Expression: 2
                                          //  Referenced by: '<S57>/Gain1'

    real_T Gain_Gain_c;                // Expression: 2
                                          //  Referenced by: '<S58>/Gain'

    real_T Constant_Value_o;           // Expression: 0.5
                                          //  Referenced by: '<S58>/Constant'

    real_T Gain2_Gain_f;               // Expression: 2
                                          //  Referenced by: '<S58>/Gain2'

    real_T Gain1_Gain_c;               // Expression: 2
                                          //  Referenced by: '<S58>/Gain1'

    real_T Gain_Gain_n;                // Expression: 2
                                          //  Referenced by: '<S59>/Gain'

    real_T Gain1_Gain_d;               // Expression: 2
                                          //  Referenced by: '<S59>/Gain1'

    real_T Constant_Value_a;           // Expression: 0.5
                                          //  Referenced by: '<S59>/Constant'

    real_T Gain2_Gain_g;               // Expression: 2
                                          //  Referenced by: '<S59>/Gain2'

    real_T DiscreteTimeIntegrator_gainval;
                           // Computed Parameter: DiscreteTimeIntegrator_gainval
                              //  Referenced by: '<S6>/Discrete-Time Integrator'

    real_T DiscreteTimeIntegrator_IC;  // Expression: 0
                                          //  Referenced by: '<S6>/Discrete-Time Integrator'

    real_T Gain1_Gain_n;               // Expression: 1
                                          //  Referenced by: '<S6>/Gain1'

    real_T WhiteNoise_Mean_n;          // Expression: 0
                                          //  Referenced by: '<S22>/White Noise'

    real_T WhiteNoise_StdDev_f;       // Computed Parameter: WhiteNoise_StdDev_f
                                         //  Referenced by: '<S22>/White Noise'

    real_T InitialAngularRates_Value[3];// Expression: [0,0,0]
                                           //  Referenced by: '<S1>/Initial Angular Rates'

    real_T Memory1_InitialCondition[8];// Expression: [0,0,0,0,0,0,0,0].'
                                          //  Referenced by: '<S26>/Memory1'

    real_T md_zero_Value;              // Expression: zeros(1,1)
                                          //  Referenced by: '<S28>/md_zero'

    real_T mvtarget_zero_Value[8];     // Expression: zeros(8,1)
                                          //  Referenced by: '<S28>/mv.target_zero'

    real_T ymin_zero_Value[13];        // Expression: zeros(13,1)
                                          //  Referenced by: '<S28>/y.min_zero'

    real_T ymax_zero_Value[13];        // Expression: zeros(13,1)
                                          //  Referenced by: '<S28>/y.max_zero'

    real_T dmvmin_zero_Value[8];       // Expression: zeros(8,1)
                                          //  Referenced by: '<S28>/dmv.min_zero'

    real_T dmvmax_zero_Value[8];       // Expression: zeros(8,1)
                                          //  Referenced by: '<S28>/dmv.max_zero'

    real_T xmin_zero_Value[13];        // Expression: zeros(13,1)
                                          //  Referenced by: '<S28>/x.min_zero'

    real_T xmax_zero_Value[13];        // Expression: zeros(13,1)
                                          //  Referenced by: '<S28>/x.max_zero'

    real_T ywt_zero_Value[13];         // Expression: zeros(13,1)
                                          //  Referenced by: '<S28>/y.wt_zero'

    real_T mvwt_zero_Value[8];         // Expression: zeros(8,1)
                                          //  Referenced by: '<S28>/mv.wt_zero'

    real_T dmvwt_zero_Value[8];        // Expression: zeros(8,1)
                                          //  Referenced by: '<S28>/dmv.wt_zero'

    real_T ecrwt_zero_Value;           // Expression: zeros(1,1)
                                          //  Referenced by: '<S28>/ecr.wt_zero'

    real_T params_zero_Value;          // Expression: zeros(1,1)
                                          //  Referenced by: '<S28>/params_zero'

    real_T Constant2_Value[8];         // Expression: zeros(1,8)
                                          //  Referenced by: '<S26>/Constant2'

    real_T Constant1_Value_p[13];// Expression: [0,0,0.2272,1,0,0,0,0,0,0,0,0,0]
                                    //  Referenced by: '<S26>/Constant1'

    real_T Zero_Value;                 // Expression: 0
                                          //  Referenced by: '<S26>/Zero'

    real_T Constant_Value_i;           // Expression: 1
                                          //  Referenced by: '<S5>/Constant'

    real_T TransferFcn_A;              // Computed Parameter: TransferFcn_A
                                          //  Referenced by: '<S13>/Transfer Fcn'

    real_T TransferFcn_C;              // Computed Parameter: TransferFcn_C
                                          //  Referenced by: '<S13>/Transfer Fcn'

    real_T TransferFcn_A_h;            // Computed Parameter: TransferFcn_A_h
                                          //  Referenced by: '<S14>/Transfer Fcn'

    real_T TransferFcn_C_m;            // Computed Parameter: TransferFcn_C_m
                                          //  Referenced by: '<S14>/Transfer Fcn'

    real_T TransferFcn_A_k;            // Computed Parameter: TransferFcn_A_k
                                          //  Referenced by: '<S15>/Transfer Fcn'

    real_T TransferFcn_C_a;            // Computed Parameter: TransferFcn_C_a
                                          //  Referenced by: '<S15>/Transfer Fcn'

    real_T TransferFcn_A_j;            // Computed Parameter: TransferFcn_A_j
                                          //  Referenced by: '<S16>/Transfer Fcn'

    real_T TransferFcn_C_j;            // Computed Parameter: TransferFcn_C_j
                                          //  Referenced by: '<S16>/Transfer Fcn'

    real_T TransferFcn_A_n;            // Computed Parameter: TransferFcn_A_n
                                          //  Referenced by: '<S17>/Transfer Fcn'

    real_T TransferFcn_C_d;            // Computed Parameter: TransferFcn_C_d
                                          //  Referenced by: '<S17>/Transfer Fcn'

    real_T TransferFcn_A_l;            // Computed Parameter: TransferFcn_A_l
                                          //  Referenced by: '<S18>/Transfer Fcn'

    real_T TransferFcn_C_k;            // Computed Parameter: TransferFcn_C_k
                                          //  Referenced by: '<S18>/Transfer Fcn'

    real_T TransferFcn_A_j1;           // Computed Parameter: TransferFcn_A_j1
                                          //  Referenced by: '<S19>/Transfer Fcn'

    real_T TransferFcn_C_g;            // Computed Parameter: TransferFcn_C_g
                                          //  Referenced by: '<S19>/Transfer Fcn'

    real_T TransferFcn_A_d;            // Computed Parameter: TransferFcn_A_d
                                          //  Referenced by: '<S20>/Transfer Fcn'

    real_T TransferFcn_C_c;            // Computed Parameter: TransferFcn_C_c
                                          //  Referenced by: '<S20>/Transfer Fcn'

    real_T ZDrift_Value;               // Expression: 0
                                          //  Referenced by: '<S9>/Z Drift'

    real_T XWave_Bias;                 // Expression: 0
                                          //  Referenced by: '<S9>/X Wave'

    real_T YWave_Bias;                 // Expression: 0
                                          //  Referenced by: '<S9>/Y Wave'

    real_T ZWave_Bias;                 // Expression: 0
                                          //  Referenced by: '<S9>/Z Wave'

    real_T RollWave_Bias;              // Expression: 0
                                          //  Referenced by: '<S9>/Roll Wave'

    real_T PitchWave_Bias;             // Expression: 0
                                          //  Referenced by: '<S9>/Pitch Wave'

    real_T YawWave_Bias;               // Expression: 0
                                          //  Referenced by: '<S9>/Yaw Wave'

    real_T Constant_Value_c[3];        // Expression: [0,0,.2272]
                                          //  Referenced by: '<Root>/Constant'

  };

  // Real-time Model Data Structure
  struct RT_MODEL_full_loop_T {
    const char_T *errorStatus;
    RTWSolverInfo solverInfo;
    X_full_loop_T *contStates;
    int_T *periodicContStateIndices;
    real_T *periodicContStateRanges;
    real_T *derivs;
    boolean_T *contStateDisabled;
    boolean_T zCCacheNeedsReset;
    boolean_T derivCacheNeedsReset;
    boolean_T CTOutputIncnstWithState;
    real_T odeY[21];
    real_T odeF[3][21];
    ODE3_IntgData intgData;

    //
    //  Sizes:
    //  The following substructure contains sizes information
    //  for many of the model attributes such as inputs, outputs,
    //  dwork, sample times, etc.

    struct {
      int_T numContStates;
      int_T numPeriodicContStates;
      int_T numSampTimes;
    } Sizes;

    //
    //  Timing:
    //  The following substructure contains information regarding
    //  the timing information for the model.

    struct {
      uint32_T clockTick0;
      time_T stepSize0;
      uint32_T clockTick1;
      boolean_T firstInitCondFlag;
      struct {
        uint16_T TID[5];
      } TaskCounters;

      SimTimeStep simTimeStep;
      boolean_T stopRequestedFlag;
      time_T *t;
      time_T tArray[5];
    } Timing;
  };

  // model initialize function
  void initialize();

  // model step function
  void step();

  // model terminate function
  void terminate();

  // Constructor
  full_loopModelClass();

  // Destructor
  ~full_loopModelClass();

  // Real-Time Model get method
  full_loopModelClass::RT_MODEL_full_loop_T * getRTM();

  // private data and function members
 private:
  // Tunable parameters
  static P_full_loop_T full_loop_P;

  // Block signals
  B_full_loop_T full_loop_B;

  // Block states
  DW_full_loop_T full_loop_DW;
  X_full_loop_T full_loop_X;           // Block continuous states
  PrevZCX_full_loop_T full_loop_PrevZCX;// Triggered events

  // Real-Time Model
  RT_MODEL_full_loop_T full_loop_M;

  // private member function(s) for subsystem '<Root>'
  void full_loop_znlmpc_setDecisions(const real_T X[52], const real_T Umv[32],
    real_T e, real_T z[69]);
  void full__structConstructorHelper_o(const cell_wrap_8_full_loop_T *varargin_2,
    const cell_wrap_9_full_loop_T *varargin_4, const cell_wrap_10_full_loop_T
    *varargin_6, const cell_wrap_10_full_loop_T *varargin_10, const
    cell_wrap_12_full_loop_T *varargin_12, const cell_wrap_12_full_loop_T
    *varargin_14, const cell_wrap_10_full_loop_T *varargin_18, const
    cell_wrap_10_full_loop_T *varargin_20, const cell_wrap_10_full_loop_T
    *varargin_22, const cell_wrap_10_full_loop_T *varargin_24, const
    cell_wrap_12_full_loop_T *varargin_26, const cell_wrap_12_full_loop_T
    *varargin_28, const cell_wrap_12_full_loop_T *varargin_30, const
    cell_wrap_12_full_loop_T *varargin_32, const cell_wrap_12_full_loop_T
    *varargin_34, s_A0rUWcsbMx3S06V1NlippE_full_T *s);
  void full_lo_structConstructorHelper(const real_T varargin_2[13], const real_T
    varargin_4[8], const real_T varargin_6[52], const real_T varargin_10[52],
    const real_T varargin_12[32], const real_T varargin_14[32], const real_T
    varargin_18[52], const real_T varargin_20[52], const real_T varargin_22[52],
    const real_T varargin_24[52], const real_T varargin_26[32], const real_T
    varargin_28[32], const real_T varargin_30[32], const real_T varargin_32[32],
    const real_T varargin_34[32], s_A0rUWcsbMx3S06V1NlippE_full_T *s);
  void full_znlmpc_generateRuntimeData(const real_T x[13], const real_T lastMV[8],
    const real_T ref0[52], const real_T MVMin0[8], const real_T MVMax0[8], const
    real_T X0[13], const real_T MV0[8], real_T Slack0,
    s_A0rUWcsbMx3S06V1NlippE_full_T *runtimedata,
    sACkMJ1zT2VJOHR6eMwwEPC_full__T *userdata, real_T z0[69]);
  void full_loop_znlmpc_getZBounds(const s_A0rUWcsbMx3S06V1NlippE_full_T
    *runtimedata, real_T zLB[69], real_T zUB[69]);
  void full_loop_diag(real_T d[64]);
  void full_loop_isfinite_m(const real_T x[8], boolean_T b[8]);
  void full_loop_znlmpc_getUBounds(const s_A0rUWcsbMx3S06V1NlippE_full_T
    *runtimedata, real_T A_data[], int32_T A_size[2], real_T Bu_data[], int32_T *
    Bu_size);
  void full_loop_znlmpc_getDecisions(const real_T z[69], real_T X[52], real_T
    Umv[32], real_T *e);
  void full_loop_znlmpc_getXUe(const real_T z[69], const real_T x[13], real_T X
    [65], real_T U[40], real_T *e);
  void full_loop_eye(real_T b_I[169]);
  void full_loop_AUVQuatJacobianMatrix(const real_T in1[13], real_T Anqv[169],
    real_T Bnqv[104]);
  void full_loop_AUVQuatSimFcn(const real_T in1[13], const real_T in2[8], real_T
    out1[13]);
  void full_loop_stateEvolution(const real_T X[65], const real_T U[40], real_T
    c[52], real_T J[3588]);
  void full_loop_all(const boolean_T x[52], boolean_T y[13]);
  boolean_T full_loop_all_l(const boolean_T x[13]);
  void full_loop_isfinite_mo(const real_T x[13], boolean_T b[13]);
  boolean_T full_loop_any(const boolean_T x[26]);
  void full_loop_znlmpc_reformJacobian(const real_T Jx_data[], const int32_T
    Jx_size[3], const real_T Jmv_data[], const real_T Je_data[], const int32_T
    *Je_size, real_T Jc_data[], int32_T Jc_size[2]);
  void full_loop_outputBounds(const real_T runtimedata_OutputMin[52], const
    real_T runtimedata_OutputMax[52], const real_T X[65], real_T e, real_T
    c_data[], int32_T c_size[2], real_T Jc_data[], int32_T Jc_size[2]);
  void full_loop___anon_fcn(const real_T runtimedata_x[13], const real_T
    runtimedata_OutputMin[52], const real_T runtimedata_OutputMax[52], const
    real_T z[69], real_T varargout_1_data[], int32_T varargout_1_size[2], real_T
    varargout_2[52], real_T varargout_3_data[], int32_T varargout_3_size[2],
    real_T varargout_4[3588]);
  int32_T full_loop_checkNonlinearInputs(const real_T x0[69], const real_T
    nonlcon_tunableEnvironment_f1_x[13], const real_T
    nonlcon_tunableEnvironment_f1_O[52], const real_T
    nonlcon_tunableEnvironment_f1_0[52]);
  void full_loop_factoryConstruct(int32_T nVarMax, int32_T mConstrMax, int32_T
    mIneq, int32_T mNonlinIneq, s_ZxHOyfVSozxr6pSGbgUCkF_full_T *obj);
  void full_loop_xcopy(const real_T x[69], real_T y[69]);
  void full_loop_factoryConstruct_c(const s_A0rUWcsbMx3S06V1NlippE_full_T
    *objfun_tunableEnvironment_f1, const sACkMJ1zT2VJOHR6eMwwEPC_full__T
    *objfun_tunableEnvironment_f2, const s_A0rUWcsbMx3S06V1NlippE_full_T
    *nonlcon_tunableEnvironment_f1, const sACkMJ1zT2VJOHR6eMwwEPC_full__T
    *nonlcon_tunableEnvironment_f2, int32_T mCineq,
    s_siHoaqeHIV5TpidUajpsGD_full_T *obj);
  void full_loop_compressBounds(int32_T indexLB[69], const real_T lb[69],
    int32_T *mLB, int32_T *mUB, int32_T *mFixed);
  void full_lo_factoryConstruct_cntp2b(int32_T mIneq, int32_T mLinIneq, const
    real_T Aineq_data[], const int32_T Aineq_size[2], int32_T mLB, const int32_T
    indexLB[69], int32_T mUB, const int32_T indexUB[69], int32_T mFixed, const
    int32_T indexFixed[69], int32_T nVarMax, int32_T mConstrMax,
    s_Mspqy2ajbjhxqxIYYuZUwC_full_T *obj);
  void full_loop_quadraticObjective(const real_T runtimedata_lastMV[8], const
    real_T runtimedata_ref[52], const real_T runtimedata_OutputWeights[52],
    const real_T runtimedata_MVWeights[32], const real_T
    runtimedata_MVRateWeights[32], const real_T runtimedata_MVScaledTarget[32],
    const real_T X[65], const real_T U[40], real_T e, real_T *f, real_T gfx[52],
    real_T gfu[32], real_T *gfe);
  void full_loop___anon_fcn_b(const real_T runtimedata_x[13], const real_T
    runtimedata_lastMV[8], const real_T runtimedata_ref[52], const real_T
    runtimedata_OutputWeights[52], const real_T runtimedata_MVWeights[32], const
    real_T runtimedata_MVRateWeights[32], const real_T
    runtimedata_MVScaledTarget[32], const real_T z[69], real_T *varargout_1,
    real_T varargout_2[69]);
  void computeObjectiveAndUserGradient(const real_T
    obj_objfun_tunableEnvironment_f[13], const real_T
    obj_objfun_tunableEnvironment_0[8], const real_T
    obj_objfun_tunableEnvironment_1[52], const real_T
    obj_objfun_tunableEnvironment_2[52], const real_T
    obj_objfun_tunableEnvironment_3[32], const real_T
    obj_objfun_tunableEnvironment_4[32], const real_T
    obj_objfun_tunableEnvironment_5[32], const real_T x[69], real_T
    grad_workspace_data[], real_T *fval, int32_T *status);
  void full_loop_xcopy_gpr(const real_T x[52], real_T y[52]);
  void full_loop_xcopy_gp(int32_T n, const real_T x_data[], real_T y_data[],
    int32_T iy0);
  int32_T full_loop_checkVectorNonFinite(int32_T N, const real_T vec_data[],
    int32_T iv0);
  int32_T full_loo_checkVectorNonFinite_e(const real_T vec[52]);
  int32_T full_loop_checkMatrixNonFinite(int32_T ncols, const real_T mat_data[],
    const int32_T mat_size[2], int32_T col0);
  int32_T full_loo_checkMatrixNonFinite_n(const real_T mat_data[], const int32_T
    mat_size[2]);
  int32_T computeConstraintsAndUserJacobi(const real_T
    obj_nonlcon_tunableEnvironment_[13], const real_T
    obj_nonlcon_tunableEnvironmen_0[52], const real_T
    obj_nonlcon_tunableEnvironmen_1[52], int32_T obj_mCineq, const real_T x[69],
    real_T Cineq_workspace_data[], int32_T ineq0, real_T Ceq_workspace[52],
    real_T JacIneqTrans_workspace_data[], const int32_T
    JacIneqTrans_workspace_size[2], int32_T iJI_col, real_T
    JacEqTrans_workspace_data[], const int32_T JacEqTrans_workspace_size[2]);
  void evalObjAndConstrAndDerivatives(const real_T
    obj_objfun_tunableEnvironment_f[13], const real_T
    obj_objfun_tunableEnvironment_0[8], const real_T
    obj_objfun_tunableEnvironment_1[52], const real_T
    obj_objfun_tunableEnvironment_2[52], const real_T
    obj_objfun_tunableEnvironment_3[32], const real_T
    obj_objfun_tunableEnvironment_4[32], const real_T
    obj_objfun_tunableEnvironment_5[32], const real_T
    obj_nonlcon_tunableEnvironment_[13], const real_T
    obj_nonlcon_tunableEnvironmen_0[52], const real_T
    obj_nonlcon_tunableEnvironmen_1[52], int32_T obj_mCineq, const real_T x[69],
    real_T grad_workspace_data[], real_T Cineq_workspace_data[], int32_T ineq0,
    real_T Ceq_workspace[52], real_T JacIneqTrans_workspace_data[], const
    int32_T JacIneqTrans_workspace_size[2], int32_T iJI_col, real_T
    JacEqTrans_workspace_data[], const int32_T JacEqTrans_workspace_size[2],
    real_T *fval, int32_T *status);
  void full_loo_computeLinearResiduals(const real_T x[69], real_T
    workspaceIneq_data[], const int32_T *workspaceIneq_size, int32_T mLinIneq,
    const real_T AineqT_data[], const real_T bineq_data[], int32_T ldAi);
  void full_l_updateWorkingSetForNewQP(const real_T xk[69],
    s_Mspqy2ajbjhxqxIYYuZUwC_full_T *WorkingSet, int32_T mIneq, const real_T
    cIneq_data[], const real_T cEq[52], int32_T mLB, const real_T lb[69],
    int32_T mUB, int32_T mFixed);
  void full_lo_modifyOverheadPhaseOne_(s_Mspqy2ajbjhxqxIYYuZUwC_full_T *obj);
  void full_modifyOverheadRegularized_(s_Mspqy2ajbjhxqxIYYuZUwC_full_T *obj);
  void full_loop_setProblemType(s_Mspqy2ajbjhxqxIYYuZUwC_full_T *obj, int32_T
    PROBLEM_TYPE);
  void full_loop_initActiveSet(s_Mspqy2ajbjhxqxIYYuZUwC_full_T *obj);
  void full_l_factoryConstruct_cntp2b1(real_T fval, const real_T
    Cineq_workspace_data[], int32_T mNonlinIneq, const real_T Ceq_workspace[52],
    s6ICcRyulWOFjNCN0ll7VsE_full__T *obj);
  void full_loop_factoryConstruct_cn(const s_A0rUWcsbMx3S06V1NlippE_full_T
    *objfun_tunableEnvironment_f1, const sACkMJ1zT2VJOHR6eMwwEPC_full__T
    *objfun_tunableEnvironment_f2, const s_A0rUWcsbMx3S06V1NlippE_full_T
    *nonlin_tunableEnvironment_f1, const sACkMJ1zT2VJOHR6eMwwEPC_full__T
    *nonlin_tunableEnvironment_f2, int32_T mCineq, const real_T lb[69],
    s_CWBQhEwNbz3J2I47jPePeB_full_T *obj);
  void full_loop_factoryConstruct_cnt(int32_T maxRows, int32_T maxCols,
    s_3RW6EhlAOINzvAvYfuaanB_full_T *obj);
  void full_loop_factoryConstruct_cntp(int32_T MaxDims, int32_T obj_FMat_size[2],
    int32_T *obj_ldm, int32_T *obj_ndims, int32_T *obj_info);
  void full_loo_factoryConstruct_cntp2(int32_T MaxVars,
    s_BtE36YuCWnavoi0lGdvGZF_full_T *obj);
  void full_loop_setQuadratic(s_BtE36YuCWnavoi0lGdvGZF_full_T *obj, int32_T
    NumVars);
  void full_loop_computeGradLag(real_T workspace_data[], int32_T ldA, int32_T
    nVar, const real_T grad_data[], int32_T mIneq, const real_T AineqTrans_data[],
    const real_T AeqTrans_data[], const int32_T finiteFixed_data[], int32_T
    mFixed, const int32_T finiteLB_data[], int32_T mLB, const int32_T
    finiteUB_data[], int32_T mUB, const real_T lambda_data[]);
  real_T full_loo_computePrimalFeasError(const real_T x[69], int32_T mLinIneq,
    int32_T mNonlinIneq, const real_T cIneq_data[], const real_T cEq[52], const
    int32_T finiteLB_data[], int32_T mLB, const real_T lb[69], const int32_T
    finiteUB_data[], int32_T mUB);
  void full_loop_computeDualFeasError(int32_T nVar, const real_T gradLag_data[],
    boolean_T *gradOK, real_T *val);
  int32_T full_loop_ixamax(int32_T n, const real_T x_data[]);
  void full_loop_test_exit(s6ICcRyulWOFjNCN0ll7VsE_full__T *MeritFunction, const
    s_Mspqy2ajbjhxqxIYYuZUwC_full_T *WorkingSet, s_ZxHOyfVSozxr6pSGbgUCkF_full_T
    *TrialState, const real_T lb[69], boolean_T *Flags_gradOK, boolean_T
    *Flags_fevalOK, boolean_T *Flags_done, boolean_T *Flags_stepAccepted,
    boolean_T *Flags_failedLineSearch, int32_T *Flags_stepType);
  void full_loop_saveJacobian(s_ZxHOyfVSozxr6pSGbgUCkF_full_T *obj, int32_T nVar,
    int32_T mIneq, const real_T JacCineqTrans_data[], int32_T ineqCol0, const
    real_T JacCeqTrans_data[], int32_T ldJ);
  void full_loop_saveState(s_ZxHOyfVSozxr6pSGbgUCkF_full_T *obj);
  void full_loop_revertSolution(s_ZxHOyfVSozxr6pSGbgUCkF_full_T *obj);
  boolean_T full_loop_isfinite(real_T x);
  real_T full_loop_computeComplError(const int32_T
    *fscales_lineq_constraint_size, const int32_T *fscales_cineq_constraint_size,
    const real_T xCurrent[69], int32_T mIneq, const real_T cIneq_data[], const
    int32_T finiteLB_data[], int32_T mLB, const real_T lb[69], const int32_T
    finiteUB_data[], int32_T mUB, const real_T lambda_data[], int32_T iL0);
  void full_loop_xcopy_gprn(int32_T n, const real_T x_data[], real_T y_data[]);
  void full_loop_computeGradLag_a(real_T workspace_data[], int32_T ldA, int32_T
    nVar, const real_T grad_data[], int32_T mIneq, const real_T AineqTrans_data[],
    const real_T AeqTrans_data[], const int32_T finiteFixed_data[], int32_T
    mFixed, const int32_T finiteLB_data[], int32_T mLB, const int32_T
    finiteUB_data[], int32_T mUB, const real_T lambda_data[]);
  void full_loo_computeDualFeasError_m(int32_T nVar, const real_T gradLag_data[],
    boolean_T *gradOK, real_T *val);
  boolean_T full_loop_isDeltaXTooSmall(const real_T xCurrent[69], const real_T
    delta_x_data[], int32_T nVar);
  void full_updateWorkingSetForNewQP_h(const real_T xk[69],
    s_Mspqy2ajbjhxqxIYYuZUwC_full_T *WorkingSet, int32_T mIneq, int32_T
    mNonlinIneq, const real_T cIneq_data[], const real_T cEq[52], int32_T mLB,
    const real_T lb[69], int32_T mUB, int32_T mFixed);
  real_T full_loop_xnrm2(int32_T n, const real_T x_data[], int32_T ix0);
  real_T full_loop_xzlarfg(int32_T n, real_T *alpha1, real_T x_data[], int32_T
    ix0);
  int32_T full_loop_ilazlc(int32_T m, int32_T n, const real_T A_data[], int32_T
    ia0, int32_T lda);
  void full_loop_xgemv(int32_T m, int32_T n, const real_T A_data[], int32_T ia0,
                       int32_T lda, const real_T x_data[], int32_T ix0, real_T
                       y_data[]);
  void full_loop_xgerc(int32_T m, int32_T n, real_T alpha1, int32_T ix0, const
                       real_T y_data[], real_T A_data[], int32_T ia0, int32_T
                       lda);
  void full_loop_xzlarf(int32_T m, int32_T n, int32_T iv0, real_T tau, real_T
                        C_data[], int32_T ic0, int32_T ldc, real_T work_data[]);
  void full_loop_qrf(real_T A_data[], const int32_T A_size[2], int32_T m,
                     int32_T n, int32_T nfxd, real_T tau_data[]);
  int32_T full_loop_ixamax_l(int32_T n, const real_T x_data[], int32_T ix0);
  void full_loop_xswap(int32_T n, real_T x_data[], int32_T ix0, int32_T iy0);
  void full_loop_qrpf(real_T A_data[], const int32_T A_size[2], int32_T m,
                      int32_T n, int32_T nfxd, real_T tau_data[], int32_T
                      jpvt_data[]);
  void full_loop_xgeqp3(real_T A_data[], const int32_T A_size[2], int32_T m,
                        int32_T n, int32_T jpvt_data[], real_T tau_data[],
                        int32_T *tau_size);
  void full_loop_xcopy_gprnb(int32_T n, const real_T x_data[], int32_T ix0,
    real_T y_data[], int32_T iy0);
  void full_loop_factorQRE(s_3RW6EhlAOINzvAvYfuaanB_full_T *obj, const real_T
    A_data[], const int32_T A_size[2], int32_T mrows, int32_T ncols);
  void full_loop_xscal(int32_T n, real_T a, real_T x_data[], int32_T ix0);
  void full_loop_xorgqr(int32_T m, int32_T n, int32_T k, real_T A_data[], const
                        int32_T A_size[2], int32_T lda, const real_T tau_data[]);
  void full_loop_computeQ_(s_3RW6EhlAOINzvAvYfuaanB_full_T *obj, int32_T nrows);
  void full_loop_xgemv_j(int32_T m, int32_T n, const real_T A_data[], int32_T
    lda, const real_T x_data[], real_T y_data[]);
  void full_loop_xtrsv(int32_T n, const real_T A_data[], int32_T lda, real_T
                       x_data[]);
  void full_loop_computeLambdaLSQ(int32_T nVar, int32_T mConstr,
    s_3RW6EhlAOINzvAvYfuaanB_full_T *QRManager, const real_T ATwset_data[],
    const int32_T ATwset_size[2], const real_T grad_data[], real_T
    lambdaLSQ_data[], real_T workspace_data[]);
  void full_loop_sortLambdaQP(real_T lambda_data[], int32_T
    WorkingSet_nActiveConstr, const int32_T WorkingSet_sizes[5], const int32_T
    WorkingSet_isActiveIdx[6], const int32_T WorkingSet_Wid_data[], const
    int32_T WorkingSet_Wlocalidx_data[], real_T workspace_data[]);
  void full_loop_test_exit_a(s7RdrPWkr8UPAUyTdDJkLaG_full__T *Flags,
    s_i4ZL8C3jdkCeOA2IrFHlEF_full_T *memspace, s6ICcRyulWOFjNCN0ll7VsE_full__T
    *MeritFunction, const int32_T *fscales_lineq_constraint_size, const int32_T *
    fscales_cineq_constraint_size, s_Mspqy2ajbjhxqxIYYuZUwC_full_T *WorkingSet,
    s_ZxHOyfVSozxr6pSGbgUCkF_full_T *TrialState, s_3RW6EhlAOINzvAvYfuaanB_full_T
    *QRManager, const real_T lb[69]);
  void full_loop_computeDeltaLag(int32_T nVar, int32_T ldJ, int32_T mNonlinIneq,
    real_T workspace_data[], const real_T grad_data[], const real_T
    JacIneqTrans_data[], int32_T ineqJ0, const real_T JacEqTrans_data[], const
    real_T grad_old_data[], const real_T JacIneqTrans_old_data[], const real_T
    JacEqTrans_old_data[], const real_T lambda_data[], int32_T ineqL0, int32_T
    eqL0);
  boolean_T full_loop_BFGSUpdate(int32_T nvar, real_T Bk[4761], const real_T
    sk_data[], real_T yk_data[], real_T workspace_data[]);
  void full_loop_xcopy_g(int32_T n, const real_T x[69], real_T y_data[]);
  void full_addBoundToActiveSetMatrix_(s_Mspqy2ajbjhxqxIYYuZUwC_full_T *obj,
    int32_T TYPE, int32_T idx_local);
  void full_loop_makeBoundFeasible(real_T xk_data[],
    s_Mspqy2ajbjhxqxIYYuZUwC_full_T *WorkingSet);
  void full_loop_xcopy_gprnbz1rec(int32_T n, const real_T x[69], real_T y[69]);
  void full_loop_updateWorkingSet(s_Mspqy2ajbjhxqxIYYuZUwC_full_T *WorkingSet,
    const real_T TrialState_cIneq_data[], const real_T TrialState_cEq[52], const
    real_T TrialState_searchDir_data[], int32_T workspace_int_data[]);
  void full_loop_snap_bounds(s_ZxHOyfVSozxr6pSGbgUCkF_full_T *solution, const
    real_T workingset_lb_data[], const real_T workingset_ub_data[], const
    int32_T workingset_indexLB_data[], const int32_T workingset_indexUB_data[],
    const int32_T workingset_indexFixed_data[], const int32_T workingset_sizes[5],
    const int32_T workingset_isActiveIdx[6], const boolean_T
    workingset_isActiveConstr_data[]);
  void full_loop_factorQRE_n(s_3RW6EhlAOINzvAvYfuaanB_full_T *obj, int32_T mrows,
    int32_T ncols);
  int32_T full_loo_ComputeNumDependentEq_(s_3RW6EhlAOINzvAvYfuaanB_full_T
    *qrmanager, const real_T beqf_data[], int32_T mConstr, int32_T nVar);
  void full_loop_IndexOfDependentEq_(int32_T depIdx_data[], int32_T mFixed,
    int32_T nDep, s_3RW6EhlAOINzvAvYfuaanB_full_T *qrmanager, const real_T
    AeqfPrime_data[], const int32_T AeqfPrime_size[2], int32_T mRows, int32_T
    nCols);
  void full_loop_countsort(int32_T x_data[], int32_T xLen, int32_T
    workspace_data[], int32_T xMin, int32_T xMax);
  void full_loop_removeConstr(s_Mspqy2ajbjhxqxIYYuZUwC_full_T *obj, int32_T
    idx_global);
  void full_loop_removeEqConstr(s_Mspqy2ajbjhxqxIYYuZUwC_full_T *obj, int32_T
    idx_global);
  int32_T full_loop_RemoveDependentEq_(s_i4ZL8C3jdkCeOA2IrFHlEF_full_T *memspace,
    s_Mspqy2ajbjhxqxIYYuZUwC_full_T *workingset, s_3RW6EhlAOINzvAvYfuaanB_full_T
    *qrmanager);
  void full_loop_removeAllIneqConstr(s_Mspqy2ajbjhxqxIYYuZUwC_full_T *obj);
  void full_loop_RemoveDependentIneq_(s_Mspqy2ajbjhxqxIYYuZUwC_full_T
    *workingset, s_3RW6EhlAOINzvAvYfuaanB_full_T *qrmanager,
    s_i4ZL8C3jdkCeOA2IrFHlEF_full_T *memspace);
  void full_loop_xgemv_jh(int32_T m, int32_T n, const real_T A_data[], int32_T
    lda, const real_T x_data[], real_T y_data[]);
  void full_loop_xgeqrf(real_T A_data[], const int32_T A_size[2], int32_T m,
                        int32_T n, real_T tau_data[], int32_T *tau_size);
  void full_loop_factorQR_i(s_3RW6EhlAOINzvAvYfuaanB_full_T *obj, const real_T
    A_data[], const int32_T A_size[2], int32_T mrows, int32_T ncols);
  void full_loop_xtrsm_k(int32_T m, const real_T A_data[], int32_T lda, real_T
    B_data[], int32_T ldb);
  void full_loop_xgemm_g(int32_T m, int32_T k, const real_T A_data[], int32_T
    lda, const real_T B_data[], int32_T ldb, real_T C_data[], int32_T ldc);
  void full_loop_factorQR(s_3RW6EhlAOINzvAvYfuaanB_full_T *obj, int32_T mrows,
    int32_T ncols);
  void full_loop_xgemm(int32_T m, int32_T k, const real_T A_data[], int32_T lda,
                       const real_T B_data[], int32_T ldb, real_T C_data[],
                       int32_T ldc);
  void full_loop_xtrsm(int32_T m, const real_T A_data[], int32_T lda, real_T
                       B_data[], int32_T ldb);
  void full_loop_xaxpy(int32_T n, const real_T x_data[], real_T y_data[]);
  void full_loop_xgemv_jhg(int32_T m, const real_T A_data[], int32_T lda, const
    real_T x_data[], real_T y_data[]);
  real_T maxConstraintViolation_AMats_no(s_Mspqy2ajbjhxqxIYYuZUwC_full_T *obj,
    const real_T x_data[]);
  real_T maxConstraintViolation_AMats_re(s_Mspqy2ajbjhxqxIYYuZUwC_full_T *obj,
    const real_T x_data[]);
  real_T full_loo_maxConstraintViolation(s_Mspqy2ajbjhxqxIYYuZUwC_full_T *obj,
    const real_T x_data[]);
  void full_loop_xgemv_jhgj(int32_T m, int32_T n, const real_T A_data[], int32_T
    lda, const real_T x_data[], int32_T ix0, real_T y_data[]);
  void full_loop_xgemv_jhgj1(int32_T m, const real_T A_data[], int32_T lda,
    const real_T x_data[], int32_T ix0, real_T y_data[]);
  real_T maxConstraintViolation_AMats__e(s_Mspqy2ajbjhxqxIYYuZUwC_full_T *obj,
    const real_T x_data[], int32_T ix0);
  real_T maxConstraintViolation_AMats__g(s_Mspqy2ajbjhxqxIYYuZUwC_full_T *obj,
    const real_T x_data[], int32_T ix0);
  real_T full_l_maxConstraintViolation_a(s_Mspqy2ajbjhxqxIYYuZUwC_full_T *obj,
    const real_T x_data[], int32_T ix0);
  void full_loop_xcopy_gprnbz1r(int32_T n, const real_T x_data[], int32_T ix0,
    real_T y_data[]);
  void full_loop_xcopy_gprnbz1(int32_T n, const real_T x_data[], real_T y_data[]);
  boolean_T full_lo_feasibleX0ForWorkingSet(real_T workspace_data[], const
    int32_T workspace_size[2], real_T xCurrent_data[], int32_T *xCurrent_size,
    s_Mspqy2ajbjhxqxIYYuZUwC_full_T *workingset, s_3RW6EhlAOINzvAvYfuaanB_full_T
    *qrmanager);
  void full_loo_RemoveDependentIneq__d(s_Mspqy2ajbjhxqxIYYuZUwC_full_T
    *workingset, s_3RW6EhlAOINzvAvYfuaanB_full_T *qrmanager,
    s_i4ZL8C3jdkCeOA2IrFHlEF_full_T *memspace);
  void full_loop_xgemv_jhgj1v(int32_T m, const real_T A_data[], int32_T lda,
    const real_T x_data[], real_T y_data[]);
  real_T maxConstraintViolation_AMats_ev(s_Mspqy2ajbjhxqxIYYuZUwC_full_T *obj,
    const real_T x_data[]);
  real_T maxConstraintViolation_AMats_g3(s_Mspqy2ajbjhxqxIYYuZUwC_full_T *obj,
    const real_T x_data[]);
  real_T full__maxConstraintViolation_ae(s_Mspqy2ajbjhxqxIYYuZUwC_full_T *obj,
    const real_T x_data[]);
  void full_loop_PresolveWorkingSet(s_ZxHOyfVSozxr6pSGbgUCkF_full_T *solution,
    s_i4ZL8C3jdkCeOA2IrFHlEF_full_T *memspace, s_Mspqy2ajbjhxqxIYYuZUwC_full_T
    *workingset, s_3RW6EhlAOINzvAvYfuaanB_full_T *qrmanager);
  void full_loop_xgemv_jhgj1v0(int32_T m, int32_T n, const real_T A[4761],
    int32_T lda, const real_T x_data[], real_T y_data[]);
  void full_loop_computeGrad_StoreHx(s_BtE36YuCWnavoi0lGdvGZF_full_T *obj, const
    real_T H[4761], const real_T f_data[], const real_T x_data[]);
  real_T full_loop_computeFval_ReuseHx(const s_BtE36YuCWnavoi0lGdvGZF_full_T
    *obj, real_T workspace_data[], const real_T f_data[], const real_T x_data[]);
  void full_loop_xcopy_gprnbz(int32_T n, real_T y_data[]);
  void full_loop_xrotg(real_T *a, real_T *b, real_T *c, real_T *s);
  void full_loop_xrot(int32_T n, real_T x_data[], int32_T ix0, int32_T iy0,
                      real_T c, real_T s);
  void full_loop_squareQ_appendCol(s_3RW6EhlAOINzvAvYfuaanB_full_T *obj, const
    real_T vec_data[], int32_T iv0);
  void full_loop_xrot_i(int32_T n, real_T x_data[], int32_T ix0, int32_T incx,
                        int32_T iy0, int32_T incy, real_T c, real_T s);
  void full_loop_deleteColMoveEnd(s_3RW6EhlAOINzvAvYfuaanB_full_T *obj, int32_T
    idx);
  void full_loop_xgemm_gu(int32_T m, int32_T n, int32_T k, const real_T A[4761],
    int32_T lda, const real_T B_data[], int32_T ib0, int32_T ldb, real_T C_data[],
    int32_T ldc);
  void full_loop_xgemm_gu5(int32_T m, int32_T n, int32_T k, const real_T A_data[],
    int32_T ia0, int32_T lda, const real_T B_data[], int32_T ldb, real_T C_data[],
    int32_T ldc);
  void computeProjectedHessian_regular(real_T beta, const real_T H[4761],
    int32_T nVarOrig, s_a5SYZcWNC5KFUTosoMMbl_full__T *cholmanager, const
    s_3RW6EhlAOINzvAvYfuaanB_full_T *qrmanager, s_i4ZL8C3jdkCeOA2IrFHlEF_full_T *
    memspace);
  void full_lo_computeProjectedHessian(const real_T H[4761],
    s_a5SYZcWNC5KFUTosoMMbl_full__T *cholmanager, const
    s_3RW6EhlAOINzvAvYfuaanB_full_T *qrmanager, s_i4ZL8C3jdkCeOA2IrFHlEF_full_T *
    memspace);
  int32_T full_loop_xpotrf(int32_T n, real_T A_data[], int32_T lda);
  void full_loop_factor_a(s_a5SYZcWNC5KFUTosoMMbl_full__T *obj, int32_T ndims);
  void full_loop_xgemv_jhgj1v0ny(int32_T m, int32_T n, const real_T A_data[],
    int32_T ia0, int32_T lda, const real_T x_data[], real_T y_data[]);
  void full_loop_solve_k(const s_a5SYZcWNC5KFUTosoMMbl_full__T *obj, real_T
    rhs_data[]);
  void full_loop_xgemv_jhgj1v0n(int32_T m, int32_T n, const real_T A_data[],
    int32_T ia0, int32_T lda, const real_T x_data[], real_T y_data[]);
  void full_loop_xcopy_gprnbz1re(int32_T n, const real_T x[4761], int32_T ix0,
    real_T y_data[], int32_T iy0);
  void full_loop_factor(s_a5SYZcWNC5KFUTosoMMbl_full__T *obj, const real_T A
                        [4761], int32_T ndims, int32_T ldA);
  void full_loop_solve(const s_a5SYZcWNC5KFUTosoMMbl_full__T *obj, real_T
                       rhs_data[]);
  void full_loop_xscal_n(int32_T n, real_T a, real_T x_data[], int32_T ix0);
  void full_loop_compute_deltax(const real_T H[4761],
    s_ZxHOyfVSozxr6pSGbgUCkF_full_T *solution, s_i4ZL8C3jdkCeOA2IrFHlEF_full_T
    *memspace, const s_3RW6EhlAOINzvAvYfuaanB_full_T *qrmanager,
    s_a5SYZcWNC5KFUTosoMMbl_full__T *cholmanager, const
    s_BtE36YuCWnavoi0lGdvGZF_full_T *objective);
  real_T full_loop_xnrm2_n(int32_T n, const real_T x_data[]);
  void full_loop_xgemv_jhgj1v0ny5(int32_T m, int32_T n, const real_T A_data[],
    int32_T lda, const real_T x_data[], real_T y_data[]);
  void full_loop_feasibleratiotest(const real_T solution_xstar_data[], const
    real_T solution_searchDir_data[], real_T workspace_data[], const int32_T
    workspace_size[2], int32_T workingset_nVar, int32_T workingset_ldA, const
    real_T workingset_Aineq_data[], const real_T workingset_bineq_data[], const
    real_T workingset_lb_data[], const real_T workingset_ub_data[], const
    int32_T workingset_indexLB_data[], const int32_T workingset_indexUB_data[],
    const int32_T workingset_sizes[5], const int32_T workingset_isActiveIdx[6],
    const boolean_T workingset_isActiveConstr_data[], const int32_T
    workingset_nWConstr[5], boolean_T isPhaseOne, real_T *alpha, boolean_T
    *newBlocking, int32_T *constrType, int32_T *constrIdx);
  void full_l_checkUnboundedOrIllPosed(s_ZxHOyfVSozxr6pSGbgUCkF_full_T *solution,
    const s_BtE36YuCWnavoi0lGdvGZF_full_T *objective);
  void full_loop_addAineqConstr(s_Mspqy2ajbjhxqxIYYuZUwC_full_T *obj, int32_T
    idx_local);
  void full_loop_xaxpy_k(int32_T n, real_T a, const real_T x_data[], real_T
    y_data[]);
  void full_loop_compute_lambda(real_T workspace_data[],
    s_ZxHOyfVSozxr6pSGbgUCkF_full_T *solution, const
    s_BtE36YuCWnavoi0lGdvGZF_full_T *objective, const
    s_3RW6EhlAOINzvAvYfuaanB_full_T *qrmanager);
  int32_T full_loop_find_neg_lambda(const real_T solution_lambda_data[], int32_T
    workingset_nActiveConstr, const int32_T workingset_nWConstr[5]);
  int32_T full_loop_mod(int32_T x);
  void full_checkStoppingAndUpdateFval(int32_T *activeSetChangeID, const real_T
    f_data[], s_ZxHOyfVSozxr6pSGbgUCkF_full_T *solution,
    s_i4ZL8C3jdkCeOA2IrFHlEF_full_T *memspace, const
    s_BtE36YuCWnavoi0lGdvGZF_full_T *objective, s_Mspqy2ajbjhxqxIYYuZUwC_full_T *
    workingset, s_3RW6EhlAOINzvAvYfuaanB_full_T *qrmanager, real_T
    options_ObjectiveLimit, int32_T runTimeOptions_MaxIterations, boolean_T
    updateFval);
  void full_loop_iterate(const real_T H[4761], const real_T f_data[],
    s_ZxHOyfVSozxr6pSGbgUCkF_full_T *solution, s_i4ZL8C3jdkCeOA2IrFHlEF_full_T
    *memspace, s_Mspqy2ajbjhxqxIYYuZUwC_full_T *workingset,
    s_3RW6EhlAOINzvAvYfuaanB_full_T *qrmanager, s_a5SYZcWNC5KFUTosoMMbl_full__T *
    cholmanager, s_BtE36YuCWnavoi0lGdvGZF_full_T *objective, real_T
    options_StepTolerance, real_T options_ObjectiveLimit, int32_T
    runTimeOptions_MaxIterations);
  void full_loop_setPhaseOne(s_BtE36YuCWnavoi0lGdvGZF_full_T *obj, int32_T
    NumVars);
  void full_loop_linearForm_(boolean_T obj_hasLinear, int32_T obj_nvar, real_T
    workspace_data[], const real_T H[4761], const real_T f_data[], const real_T
    x_data[]);
  real_T full_loop_computeFval(const s_BtE36YuCWnavoi0lGdvGZF_full_T *obj,
    real_T workspace_data[], const real_T H[4761], const real_T f_data[], const
    real_T x_data[]);
  void full_loop_restoreFromPhaseOne(s_BtE36YuCWnavoi0lGdvGZF_full_T *obj);
  void full_loop_phaseone(const real_T H[4761], const real_T f_data[],
    s_ZxHOyfVSozxr6pSGbgUCkF_full_T *solution, s_i4ZL8C3jdkCeOA2IrFHlEF_full_T
    *memspace, s_Mspqy2ajbjhxqxIYYuZUwC_full_T *workingset,
    s_3RW6EhlAOINzvAvYfuaanB_full_T *qrmanager, s_a5SYZcWNC5KFUTosoMMbl_full__T *
    cholmanager, s_BtE36YuCWnavoi0lGdvGZF_full_T *objective,
    s1TgE9KstXgkd2qJxO1bF4F_full__T *options, const
    s1TgE9KstXgkd2qJxO1bF4F_full__T *runTimeOptions);
  void full_loop_driver_e(const real_T H[4761], const real_T f_data[],
    s_ZxHOyfVSozxr6pSGbgUCkF_full_T *solution, s_i4ZL8C3jdkCeOA2IrFHlEF_full_T
    *memspace, s_Mspqy2ajbjhxqxIYYuZUwC_full_T *workingset,
    s_3RW6EhlAOINzvAvYfuaanB_full_T *qrmanager, s_a5SYZcWNC5KFUTosoMMbl_full__T *
    cholmanager, s_BtE36YuCWnavoi0lGdvGZF_full_T *objective,
    s1TgE9KstXgkd2qJxO1bF4F_full__T *options, s1TgE9KstXgkd2qJxO1bF4F_full__T
    *runTimeOptions);
  void full_loop_restoreWorkingSet(boolean_T stepSuccess, int32_T nWIneq_old,
    int32_T nWLower_old, int32_T nWUpper_old, s_Mspqy2ajbjhxqxIYYuZUwC_full_T
    *WorkingSet, const real_T TrialState_cIneq_data[], const real_T
    TrialState_cEq[52], const int32_T workspace_int_data[]);
  void full_loop_addAeqConstr(s_Mspqy2ajbjhxqxIYYuZUwC_full_T *obj, int32_T
    idx_local);
  boolean_T full_loop_soc(const real_T Hessian[4761], const real_T grad_data[],
    s_ZxHOyfVSozxr6pSGbgUCkF_full_T *TrialState, s_i4ZL8C3jdkCeOA2IrFHlEF_full_T
    *memspace, s_Mspqy2ajbjhxqxIYYuZUwC_full_T *WorkingSet,
    s_3RW6EhlAOINzvAvYfuaanB_full_T *QRManager, s_a5SYZcWNC5KFUTosoMMbl_full__T *
    CholManager, s_BtE36YuCWnavoi0lGdvGZF_full_T *QPObjective, const
    s1TgE9KstXgkd2qJxO1bF4F_full__T *qpoptions);
  void full_loop_updatePenaltyParam(s6ICcRyulWOFjNCN0ll7VsE_full__T *obj, real_T
    fval, const real_T ineq_workspace_data[], int32_T mIneq, const real_T
    eq_workspace[52], int32_T sqpiter, real_T qpval);
  void full_loop_normal(const real_T Hessian[4761], const real_T grad_data[],
                        s_ZxHOyfVSozxr6pSGbgUCkF_full_T *TrialState,
                        s6ICcRyulWOFjNCN0ll7VsE_full__T *MeritFunction,
                        s_i4ZL8C3jdkCeOA2IrFHlEF_full_T *memspace,
                        s_Mspqy2ajbjhxqxIYYuZUwC_full_T *WorkingSet,
                        s_3RW6EhlAOINzvAvYfuaanB_full_T *QRManager,
                        s_a5SYZcWNC5KFUTosoMMbl_full__T *CholManager,
                        s_BtE36YuCWnavoi0lGdvGZF_full_T *QPObjective, const
                        s1TgE9KstXgkd2qJxO1bF4F_full__T *qpoptions);
  void full_loop_setRegularized(s_BtE36YuCWnavoi0lGdvGZF_full_T *obj, int32_T
    numQuadVars, real_T beta, real_T rho);
  void full_lo_assignResidualsToXSlack(int32_T nVarOrig,
    s_Mspqy2ajbjhxqxIYYuZUwC_full_T *WorkingSet, s_ZxHOyfVSozxr6pSGbgUCkF_full_T
    *TrialState, s_i4ZL8C3jdkCeOA2IrFHlEF_full_T *memspace);
  int32_T full_findActiveSlackLowerBounds(s_i4ZL8C3jdkCeOA2IrFHlEF_full_T
    *memspace, const int32_T WorkingSet_sizes[5], const int32_T
    WorkingSet_isActiveIdx[6], const boolean_T WorkingSet_isActiveConstr_data[]);
  real_T full_loop_xasum(int32_T n, const real_T x_data[], int32_T ix0);
  real_T full_loop_xdot(int32_T n, const real_T x_data[], int32_T ix0, const
                        real_T y_data[], int32_T iy0);
  void full_loop_updatePenaltyParam_o(s6ICcRyulWOFjNCN0ll7VsE_full__T *obj,
    real_T fval, const real_T ineq_workspace_data[], int32_T mIneq, const real_T
    eq_workspace[52], int32_T sqpiter, real_T qpval, const real_T x_data[],
    int32_T iReg0, int32_T nRegularized);
  void fu_removeActiveSlackLowerBounds(int32_T nActiveLBArtificial,
    s_ZxHOyfVSozxr6pSGbgUCkF_full_T *TrialState, s_Mspqy2ajbjhxqxIYYuZUwC_full_T
    *WorkingSet);
  void full_loop_relaxed(const real_T Hessian[4761], const real_T grad_data[],
    s_ZxHOyfVSozxr6pSGbgUCkF_full_T *TrialState, s6ICcRyulWOFjNCN0ll7VsE_full__T
    *MeritFunction, s_i4ZL8C3jdkCeOA2IrFHlEF_full_T *memspace,
    s_Mspqy2ajbjhxqxIYYuZUwC_full_T *WorkingSet, s_3RW6EhlAOINzvAvYfuaanB_full_T
    *QRManager, s_a5SYZcWNC5KFUTosoMMbl_full__T *CholManager,
    s_BtE36YuCWnavoi0lGdvGZF_full_T *QPObjective,
    s1TgE9KstXgkd2qJxO1bF4F_full__T *qpoptions);
  void full_loop_BFGSReset(real_T Hessian[4761], const real_T grad_data[], const
    real_T searchDir_data[]);
  void full_loop_saturateDirection(const real_T xk[69], real_T delta_x_data[],
    real_T xstarqp_data[], const int32_T indexLB_data[], int32_T mLB, const
    real_T lb[69]);
  boolean_T full_loop_step_n(int32_T *STEP_TYPE, real_T Hessian[4761], const
    real_T lb[69], s_ZxHOyfVSozxr6pSGbgUCkF_full_T *TrialState,
    s6ICcRyulWOFjNCN0ll7VsE_full__T *MeritFunction,
    s_i4ZL8C3jdkCeOA2IrFHlEF_full_T *memspace, s_Mspqy2ajbjhxqxIYYuZUwC_full_T
    *WorkingSet, s_3RW6EhlAOINzvAvYfuaanB_full_T *QRManager,
    s_a5SYZcWNC5KFUTosoMMbl_full__T *CholManager,
    s_BtE36YuCWnavoi0lGdvGZF_full_T *QPObjective,
    s1TgE9KstXgkd2qJxO1bF4F_full__T *qpoptions);
  void full_loop_computeObjective_(const real_T obj_objfun_tunableEnvironment_f
    [13], const real_T obj_objfun_tunableEnvironment_0[8], const real_T
    obj_objfun_tunableEnvironment_1[52], const real_T
    obj_objfun_tunableEnvironment_2[52], const real_T
    obj_objfun_tunableEnvironment_3[32], const real_T
    obj_objfun_tunableEnvironment_4[32], const real_T
    obj_objfun_tunableEnvironment_5[32], const real_T x[69], real_T *fval,
    int32_T *status);
  void full_loop___anon_fcn_bv(const real_T runtimedata_x[13], const real_T
    runtimedata_OutputMin[52], const real_T runtimedata_OutputMax[52], const
    real_T z[69], real_T varargout_1_data[], int32_T varargout_1_size[2], real_T
    varargout_2[52]);
  int32_T full_loop_computeConstraints_(const real_T
    obj_nonlcon_tunableEnvironment_[13], const real_T
    obj_nonlcon_tunableEnvironmen_0[52], const real_T
    obj_nonlcon_tunableEnvironmen_1[52], int32_T obj_mCineq, const real_T x[69],
    real_T Cineq_workspace_data[], int32_T ineq0, real_T Ceq_workspace[52]);
  void full_loop_evalObjAndConstr(const real_T obj_objfun_tunableEnvironment_f
    [13], const real_T obj_objfun_tunableEnvironment_0[8], const real_T
    obj_objfun_tunableEnvironment_1[52], const real_T
    obj_objfun_tunableEnvironment_2[52], const real_T
    obj_objfun_tunableEnvironment_3[32], const real_T
    obj_objfun_tunableEnvironment_4[32], const real_T
    obj_objfun_tunableEnvironment_5[32], const real_T
    obj_nonlcon_tunableEnvironment_[13], const real_T
    obj_nonlcon_tunableEnvironmen_0[52], const real_T
    obj_nonlcon_tunableEnvironmen_1[52], int32_T obj_mCineq, const real_T x[69],
    real_T Cineq_workspace_data[], int32_T ineq0, real_T Ceq_workspace[52],
    real_T *fval, int32_T *status);
  void full_l_computeLinearResiduals_l(const real_T x[69], int32_T nVar, real_T
    workspaceIneq_data[], const int32_T *workspaceIneq_size, int32_T mLinIneq,
    const real_T AineqT_data[], const real_T bineq_data[], int32_T ldAi);
  real_T full_loop_computeMeritFcn(real_T obj_penaltyParam, real_T fval, const
    real_T Cineq_workspace_data[], int32_T mIneq, const real_T Ceq_workspace[52],
    boolean_T evalWellDefined);
  void full_loop_linesearch(boolean_T *evalWellDefined, const real_T bineq_data[],
    int32_T WorkingSet_nVar, int32_T WorkingSet_ldA, const real_T
    WorkingSet_Aineq_data[], s_ZxHOyfVSozxr6pSGbgUCkF_full_T *TrialState, real_T
    MeritFunction_penaltyParam, real_T MeritFunction_phi, real_T
    MeritFunction_phiPrimePlus, real_T MeritFunction_phiFullStep, const
    s_A0rUWcsbMx3S06V1NlippE_full_T *FcnEvaluator_objfun_tunableEnvi, const
    s_A0rUWcsbMx3S06V1NlippE_full_T *FcnEvaluator_nonlcon_tunableEnv, int32_T
    FcnEvaluator_mCineq, boolean_T socTaken, real_T *alpha, int32_T *exitflag);
  void full_loop_driver(const real_T bineq_data[], const real_T lb[69],
                        s_ZxHOyfVSozxr6pSGbgUCkF_full_T *TrialState,
                        s6ICcRyulWOFjNCN0ll7VsE_full__T *MeritFunction, const
                        s_siHoaqeHIV5TpidUajpsGD_full_T *FcnEvaluator,
                        s_i4ZL8C3jdkCeOA2IrFHlEF_full_T *memspace,
                        s_Mspqy2ajbjhxqxIYYuZUwC_full_T *WorkingSet,
                        s_3RW6EhlAOINzvAvYfuaanB_full_T *QRManager,
                        s_a5SYZcWNC5KFUTosoMMbl_full__T *CholManager,
                        s_BtE36YuCWnavoi0lGdvGZF_full_T *QPObjective, const
                        int32_T *fscales_lineq_constraint_size, const int32_T
                        *fscales_cineq_constraint_size, real_T Hessian[4761]);
  void full_loop_fillOutputStruct(int32_T TrialState_FunctionEvaluations,
    int32_T TrialState_sqpIterations, real_T TrialState_steplength, const real_T
    TrialState_delta_x_data[], real_T MeritFunction_nlpPrimalFeasErro, real_T
    MeritFunction_firstOrderOpt, real_T *output_iterations, real_T
    *output_funcCount, char_T output_algorithm[3], real_T
    *output_constrviolation, real_T *output_stepsize, real_T
    *output_lssteplength, real_T *output_firstorderopt);
  void full_loop_fmincon(const s_A0rUWcsbMx3S06V1NlippE_full_T
    *fun_tunableEnvironment_f1, const sACkMJ1zT2VJOHR6eMwwEPC_full__T
    *fun_tunableEnvironment_f2, const real_T x0[69], const real_T Aineq_data[],
    const int32_T Aineq_size[2], const real_T bineq_data[], const int32_T
    *bineq_size, const real_T lb[69], const s_A0rUWcsbMx3S06V1NlippE_full_T
    *nonlcon_tunableEnvironment_f1, const sACkMJ1zT2VJOHR6eMwwEPC_full__T
    *nonlcon_tunableEnvironment_f2, real_T x[69], real_T *fval, real_T *exitflag,
    real_T *output_constrviolation);
  real_T full_loop_erf(real_T x);
  void matlabCodegenHandle_matlabCodeg(ros_slros_internal_block_Publ_T *obj);

  // Continuous states update member function
  void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si );

  // Derivatives member function
  void full_loop_derivatives();
};

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<S9>/Scope' : Unused code path elimination
//  Block '<S9>/Scope1' : Unused code path elimination
//  Block '<S2>/Scope' : Unused code path elimination
//  Block '<S2>/Scope2' : Unused code path elimination
//  Block '<S2>/Scope3' : Unused code path elimination
//  Block '<S2>/Scope4' : Unused code path elimination
//  Block '<S3>/ROS output' : Unused code path elimination
//  Block '<S5>/N to RPM' : Unused code path elimination
//  Block '<S30>/Matrix Dimension Check' : Unused code path elimination
//  Block '<S31>/Matrix Dimension Check' : Unused code path elimination
//  Block '<S32>/Matrix Dimension Check' : Unused code path elimination
//  Block '<S33>/Matrix Dimension Check' : Unused code path elimination
//  Block '<S34>/Matrix Dimension Check' : Unused code path elimination
//  Block '<S35>/Matrix Dimension Check' : Unused code path elimination
//  Block '<S36>/Matrix Dimension Check' : Unused code path elimination
//  Block '<S37>/Matrix Dimension Check' : Unused code path elimination
//  Block '<S38>/Matrix Dimension Check' : Unused code path elimination
//  Block '<S39>/Matrix Dimension Check' : Unused code path elimination
//  Block '<S40>/Matrix Dimension Check' : Unused code path elimination
//  Block '<S41>/Matrix Dimension Check' : Unused code path elimination
//  Block '<S42>/Matrix Dimension Check' : Unused code path elimination
//  Block '<S43>/Matrix Dimension Check' : Unused code path elimination
//  Block '<S44>/Matrix Dimension Check' : Unused code path elimination
//  Block '<S45>/Matrix Dimension Check' : Unused code path elimination
//  Block '<S46>/Vector Dimension Check' : Unused code path elimination
//  Block '<S47>/Vector Dimension Check' : Unused code path elimination
//  Block '<S48>/Vector Dimension Check' : Unused code path elimination
//  Block '<S49>/Vector Dimension Check' : Unused code path elimination
//  Block '<S26>/Scope' : Unused code path elimination
//  Block '<S5>/Scope' : Unused code path elimination
//  Block '<S5>/Scope1' : Unused code path elimination
//  Block '<S5>/Scope4' : Unused code path elimination
//  Block '<S6>/Discrete-Time Integrator1' : Unused code path elimination
//  Block '<S6>/Scope1' : Unused code path elimination
//  Block '<S6>/Scope2' : Unused code path elimination
//  Block '<S6>/Scope6' : Unused code path elimination
//  Block '<S53>/Display' : Unused code path elimination
//  Block '<S53>/Scope' : Unused code path elimination
//  Block '<S53>/Scope1' : Unused code path elimination
//  Block '<S29>/Reshape1' : Reshape block reduction
//  Block '<S29>/mo or x Conversion' : Eliminate redundant data type conversion
//  Block '<S29>/mo or x Conversion1' : Eliminate redundant data type conversion
//  Block '<S29>/mo or x Conversion10' : Eliminate redundant data type conversion
//  Block '<S29>/mo or x Conversion11' : Eliminate redundant data type conversion
//  Block '<S29>/mo or x Conversion12' : Eliminate redundant data type conversion
//  Block '<S29>/mo or x Conversion13' : Eliminate redundant data type conversion
//  Block '<S29>/mo or x Conversion14' : Eliminate redundant data type conversion
//  Block '<S29>/mo or x Conversion15' : Eliminate redundant data type conversion
//  Block '<S29>/mo or x Conversion16' : Eliminate redundant data type conversion
//  Block '<S29>/mo or x Conversion17' : Eliminate redundant data type conversion
//  Block '<S29>/mo or x Conversion18' : Eliminate redundant data type conversion
//  Block '<S29>/mo or x Conversion19' : Eliminate redundant data type conversion
//  Block '<S29>/mo or x Conversion2' : Eliminate redundant data type conversion
//  Block '<S29>/mo or x Conversion3' : Eliminate redundant data type conversion
//  Block '<S29>/mo or x Conversion4' : Eliminate redundant data type conversion
//  Block '<S29>/mo or x Conversion5' : Eliminate redundant data type conversion
//  Block '<S29>/mo or x Conversion6' : Eliminate redundant data type conversion
//  Block '<S29>/mo or x Conversion7' : Eliminate redundant data type conversion
//  Block '<S29>/mo or x Conversion8' : Eliminate redundant data type conversion
//  Block '<S29>/mo or x Conversion9' : Eliminate redundant data type conversion


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
//  '<Root>' : 'full_loop'
//  '<S1>'   : 'full_loop/Modèle Physique'
//  '<S2>'   : 'full_loop/Plot values'
//  '<S3>'   : 'full_loop/ROS Output'
//  '<S4>'   : 'full_loop/Send PWM to ROS'
//  '<S5>'   : 'full_loop/Subsystem Controller'
//  '<S6>'   : 'full_loop/Subsystem ProcNav'
//  '<S7>'   : 'full_loop/Subsystem Trajectory'
//  '<S8>'   : 'full_loop/Modèle Physique/AUV State Equation'
//  '<S9>'   : 'full_loop/Modèle Physique/Disturbances'
//  '<S10>'  : 'full_loop/Modèle Physique/Modele Thruster'
//  '<S11>'  : 'full_loop/Modèle Physique/Quaternion Normalise'
//  '<S12>'  : 'full_loop/Modèle Physique/Sensor Noise'
//  '<S13>'  : 'full_loop/Modèle Physique/Modele Thruster/T1'
//  '<S14>'  : 'full_loop/Modèle Physique/Modele Thruster/T2'
//  '<S15>'  : 'full_loop/Modèle Physique/Modele Thruster/T3'
//  '<S16>'  : 'full_loop/Modèle Physique/Modele Thruster/T4'
//  '<S17>'  : 'full_loop/Modèle Physique/Modele Thruster/T5'
//  '<S18>'  : 'full_loop/Modèle Physique/Modele Thruster/T6'
//  '<S19>'  : 'full_loop/Modèle Physique/Modele Thruster/T7'
//  '<S20>'  : 'full_loop/Modèle Physique/Modele Thruster/T8'
//  '<S21>'  : 'full_loop/Modèle Physique/Sensor Noise/Band-Limited White Noise'
//  '<S22>'  : 'full_loop/Modèle Physique/Sensor Noise/Band-Limited White Noise1'
//  '<S23>'  : 'full_loop/Send PWM to ROS/Blank Message'
//  '<S24>'  : 'full_loop/Send PWM to ROS/MATLAB Function1'
//  '<S25>'  : 'full_loop/Send PWM to ROS/Publish'
//  '<S26>'  : 'full_loop/Subsystem Controller/Quaternion Non linear MPC'
//  '<S27>'  : 'full_loop/Subsystem Controller/Quaternion Non linear MPC/Bus2Mux'
//  '<S28>'  : 'full_loop/Subsystem Controller/Quaternion Non linear MPC/Nonlinear MPC Controller'
//  '<S29>'  : 'full_loop/Subsystem Controller/Quaternion Non linear MPC/Nonlinear MPC Controller/MPC'
//  '<S30>'  : 'full_loop/Subsystem Controller/Quaternion Non linear MPC/Nonlinear MPC Controller/MPC/MPC Preview Signal Check'
//  '<S31>'  : 'full_loop/Subsystem Controller/Quaternion Non linear MPC/Nonlinear MPC Controller/MPC/MPC Preview Signal Check1'
//  '<S32>'  : 'full_loop/Subsystem Controller/Quaternion Non linear MPC/Nonlinear MPC Controller/MPC/MPC Preview Signal Check10'
//  '<S33>'  : 'full_loop/Subsystem Controller/Quaternion Non linear MPC/Nonlinear MPC Controller/MPC/MPC Preview Signal Check11'
//  '<S34>'  : 'full_loop/Subsystem Controller/Quaternion Non linear MPC/Nonlinear MPC Controller/MPC/MPC Preview Signal Check12'
//  '<S35>'  : 'full_loop/Subsystem Controller/Quaternion Non linear MPC/Nonlinear MPC Controller/MPC/MPC Preview Signal Check13'
//  '<S36>'  : 'full_loop/Subsystem Controller/Quaternion Non linear MPC/Nonlinear MPC Controller/MPC/MPC Preview Signal Check14'
//  '<S37>'  : 'full_loop/Subsystem Controller/Quaternion Non linear MPC/Nonlinear MPC Controller/MPC/MPC Preview Signal Check15'
//  '<S38>'  : 'full_loop/Subsystem Controller/Quaternion Non linear MPC/Nonlinear MPC Controller/MPC/MPC Preview Signal Check16'
//  '<S39>'  : 'full_loop/Subsystem Controller/Quaternion Non linear MPC/Nonlinear MPC Controller/MPC/MPC Preview Signal Check3'
//  '<S40>'  : 'full_loop/Subsystem Controller/Quaternion Non linear MPC/Nonlinear MPC Controller/MPC/MPC Preview Signal Check4'
//  '<S41>'  : 'full_loop/Subsystem Controller/Quaternion Non linear MPC/Nonlinear MPC Controller/MPC/MPC Preview Signal Check5'
//  '<S42>'  : 'full_loop/Subsystem Controller/Quaternion Non linear MPC/Nonlinear MPC Controller/MPC/MPC Preview Signal Check6'
//  '<S43>'  : 'full_loop/Subsystem Controller/Quaternion Non linear MPC/Nonlinear MPC Controller/MPC/MPC Preview Signal Check7'
//  '<S44>'  : 'full_loop/Subsystem Controller/Quaternion Non linear MPC/Nonlinear MPC Controller/MPC/MPC Preview Signal Check8'
//  '<S45>'  : 'full_loop/Subsystem Controller/Quaternion Non linear MPC/Nonlinear MPC Controller/MPC/MPC Preview Signal Check9'
//  '<S46>'  : 'full_loop/Subsystem Controller/Quaternion Non linear MPC/Nonlinear MPC Controller/MPC/MPC Scalar Signal Check1'
//  '<S47>'  : 'full_loop/Subsystem Controller/Quaternion Non linear MPC/Nonlinear MPC Controller/MPC/MPC Scalar Signal Check2'
//  '<S48>'  : 'full_loop/Subsystem Controller/Quaternion Non linear MPC/Nonlinear MPC Controller/MPC/MPC Vector Signal Check1'
//  '<S49>'  : 'full_loop/Subsystem Controller/Quaternion Non linear MPC/Nonlinear MPC Controller/MPC/MPC Vector Signal Check11'
//  '<S50>'  : 'full_loop/Subsystem Controller/Quaternion Non linear MPC/Nonlinear MPC Controller/MPC/NLMPC'
//  '<S51>'  : 'full_loop/Subsystem ProcNav/Quaternion Inverse1'
//  '<S52>'  : 'full_loop/Subsystem ProcNav/Quaternion Rotation'
//  '<S53>'  : 'full_loop/Subsystem ProcNav/Subsystem'
//  '<S54>'  : 'full_loop/Subsystem ProcNav/Quaternion Inverse1/Quaternion Conjugate'
//  '<S55>'  : 'full_loop/Subsystem ProcNav/Quaternion Inverse1/Quaternion Norm'
//  '<S56>'  : 'full_loop/Subsystem ProcNav/Quaternion Rotation/Quaternion Normalize'
//  '<S57>'  : 'full_loop/Subsystem ProcNav/Quaternion Rotation/V1'
//  '<S58>'  : 'full_loop/Subsystem ProcNav/Quaternion Rotation/V2'
//  '<S59>'  : 'full_loop/Subsystem ProcNav/Quaternion Rotation/V3'
//  '<S60>'  : 'full_loop/Subsystem ProcNav/Quaternion Rotation/Quaternion Normalize/Quaternion Modulus'
//  '<S61>'  : 'full_loop/Subsystem ProcNav/Quaternion Rotation/Quaternion Normalize/Quaternion Modulus/Quaternion Norm'
//  '<S62>'  : 'full_loop/Subsystem ProcNav/Subsystem/Quaternions to Rotation Angles'
//  '<S63>'  : 'full_loop/Subsystem ProcNav/Subsystem/Quaternions to Rotation Angles/Angle Calculation'
//  '<S64>'  : 'full_loop/Subsystem ProcNav/Subsystem/Quaternions to Rotation Angles/Quaternion Normalize'
//  '<S65>'  : 'full_loop/Subsystem ProcNav/Subsystem/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input'
//  '<S66>'  : 'full_loop/Subsystem ProcNav/Subsystem/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input/If Action Subsystem'
//  '<S67>'  : 'full_loop/Subsystem ProcNav/Subsystem/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input/If Action Subsystem1'
//  '<S68>'  : 'full_loop/Subsystem ProcNav/Subsystem/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input/If Action Subsystem2'
//  '<S69>'  : 'full_loop/Subsystem ProcNav/Subsystem/Quaternions to Rotation Angles/Quaternion Normalize/Quaternion Modulus'
//  '<S70>'  : 'full_loop/Subsystem ProcNav/Subsystem/Quaternions to Rotation Angles/Quaternion Normalize/Quaternion Modulus/Quaternion Norm'

#endif                                 // RTW_HEADER_full_loop_h_

//
// File trailer for generated code.
//
// [EOF]
//
