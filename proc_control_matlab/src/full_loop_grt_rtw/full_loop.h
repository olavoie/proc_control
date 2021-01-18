/*
 * full_loop.h
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

#ifndef RTW_HEADER_full_loop_h_
#define RTW_HEADER_full_loop_h_
#include <cmath>
#include <cstring>
#include <math.h>
#include <stdio.h>
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "slros_initialize.h"
#include "full_loop_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"
#include "rt_defines.h"

/* Macros for accessing real-time model data structure */
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

/* Block signals (default storage) */
typedef struct {
  real_T Su[9600];
  real_T dv[6400];
  real_T Cm[2640];
  real_T c_Sx[2400];
  real_T c_SuJm[1920];
  real_T c_Kr[1920];
  real_T Bu[1760];
  real_T dv1[1320];
  real_T c_Hv[1320];
  real_T c_Kut[1280];
  real_T dv2[1280];
  real_T dv3[1280];
  real_T CovMat[1024];
  real_T c_Su1[960];
  real_T Sum_m[960];
  snaQeDJ4fX7UykrKyr5M8jC_full__T QRManager;
  snaQeDJ4fX7UykrKyr5M8jC_full__T b_QRManager;
  snaQeDJ4fX7UykrKyr5M8jC_full__T qrmanager;
  snaQeDJ4fX7UykrKyr5M8jC_full__T qrmanager_c;
  snaQeDJ4fX7UykrKyr5M8jC_full__T qrmanager_k;
  snaQeDJ4fX7UykrKyr5M8jC_full__T QRManager_c;
  snaQeDJ4fX7UykrKyr5M8jC_full__T d_qrmanager;
  snaQeDJ4fX7UykrKyr5M8jC_full__T qrmanager_b;
  snaQeDJ4fX7UykrKyr5M8jC_full__T qrmanager_p;
  snaQeDJ4fX7UykrKyr5M8jC_full__T QRManager_cv;
  real_T b_B[896];
  real_T b_B_f[896];
  sH6xx18cQHI5sgA7Ajla4nE_full__T WorkingSet;
  sH6xx18cQHI5sgA7Ajla4nE_full__T WorkingSet_g;
  sH6xx18cQHI5sgA7Ajla4nE_full__T WorkingSet_g1;
  sH6xx18cQHI5sgA7Ajla4nE_full__T b_WorkingSet;
  sH6xx18cQHI5sgA7Ajla4nE_full__T d_workingset;
  sH6xx18cQHI5sgA7Ajla4nE_full__T h_workingset;
  sH6xx18cQHI5sgA7Ajla4nE_full__T c_workingset;
  sH6xx18cQHI5sgA7Ajla4nE_full__T c_workingset_m;
  sH6xx18cQHI5sgA7Ajla4nE_full__T b_workingset;
  sH6xx18cQHI5sgA7Ajla4nE_full__T workingset;
  sH6xx18cQHI5sgA7Ajla4nE_full__T workingset_n;
  sH6xx18cQHI5sgA7Ajla4nE_full__T c_WorkingSet;
  sH6xx18cQHI5sgA7Ajla4nE_full__T d_WorkingSet;
  sH6xx18cQHI5sgA7Ajla4nE_full__T WorkingSet_p;
  sH6xx18cQHI5sgA7Ajla4nE_full__T c_WorkingSet_l;
  real_T gb[580];
  sVTYnQ9ljvmk9dLse9XvTT_full_l_T memspace;
  sVTYnQ9ljvmk9dLse9XvTT_full_l_T b_memspace;
  sVTYnQ9ljvmk9dLse9XvTT_full_l_T e_memspace;
  sVTYnQ9ljvmk9dLse9XvTT_full_l_T memspace_j;
  sVTYnQ9ljvmk9dLse9XvTT_full_l_T c_memspace;
  sVTYnQ9ljvmk9dLse9XvTT_full_l_T d_memspace;
  sVTYnQ9ljvmk9dLse9XvTT_full_l_T d_memspace_d;
  sVTYnQ9ljvmk9dLse9XvTT_full_l_T c_memspace_g;
  sVTYnQ9ljvmk9dLse9XvTT_full_l_T c_memspace_l;
  snl99C5je2zMbU5SzygoX6F_full__T CholManager;
  snl99C5je2zMbU5SzygoX6F_full__T CholManager_d;
  snl99C5je2zMbU5SzygoX6F_full__T cholmanager;
  real_T e_memspace_workspace_double[441];
  real_T memspace_d[441];
  real_T memspace_l[441];
  real_T memspace_o[441];
  real_T b_workspace[441];
  real_T b_workspace_b[441];
  real_T obj[441];
  real_T b_A[441];
  real_T c_memspace_workspace_double[441];
  real_T d_memspace_workspace_double[441];
  real_T obj_n[441];
  real_T b_A_b[441];
  real_T b_A_l[441];
  real_T d[441];
  real_T cholmanager_h[441];
  real_T b_obj_FMat[441];
  real_T g[441];
  real_T memspace_b[441];
  real_T obj_d[441];
  real_T obj_e[441];
  real_T c_x[441];
  real_T memspace_bj[441];
  real_T memspace_jz[441];
  real_T b_A_f[400];
  real_T Qk[400];
  real_T L_tmp[400];
  real_T L_tmp_a[400];
  real_T L_tmp_j[400];
  real_T M[400];
  real_T b_this[400];
  real_T F[400];
  real_T A2[400];
  real_T U_j[400];
  real_T V[400];
  real_T A3[400];
  real_T A4[400];
  real_T A4_o[400];
  real_T c_A[400];
  real_T c_Kx[320];
  s2CPTVnVyv153Hb6bxlki6F_full__T TrialState;
  s2CPTVnVyv153Hb6bxlki6F_full__T c_TrialState;
  s2CPTVnVyv153Hb6bxlki6F_full__T c_TrialState_n;
  s2CPTVnVyv153Hb6bxlki6F_full__T solution;
  s2CPTVnVyv153Hb6bxlki6F_full__T c_TrialState_i;
  real_T t[289];
  real_T c_Linv[289];
  real_T d_Linv[289];
  real_T b_H[289];
  real_T RLinv[289];
  real_T b_D[289];
  real_T b_H_o[289];
  real_T U_n[289];
  real_T TL[289];
  real_T QQ[289];
  real_T RR[289];
  real_T c_A_m[289];
  real_T dv4[289];
  real_T b[256];
  real_T b_SuJm[256];
  real_T b_Jm[256];
  real_T L[240];
  real_T b_C[240];
  real_T Nk[240];
  real_T Cm_c[240];
  real_T dv5[240];
  real_T CA[240];
  real_T CA_m[240];
  real_T Bv[220];
  real_T dv6[176];
  real_T c_Kv[176];
  real_T Rk[144];
  real_T c_A_m3[144];
  real_T Dv[132];
  real_T Dvm[132];
  real_T CA_j[132];
  real_T c_Ku1[128];
  real_T b_Su1[128];
  real_T b_I1[128];
  real_T g_h[126];
  real_T c_JacCeqTrans[126];
  real_T b_WorkingSet_c[126];
  real_T rseq[120];
  real_T dv7[96];
  real_T Sum_c[96];
  real_T useq[88];                     /* '<S98>/FixedHorizonOptimizer' */
  real_T b_utarget[80];
  real_T dv8[80];
  real_T r[68];
  real_T Hessian[64];
  real_T Hessian_p[64];
  real_T b_Hessian[64];
  real_T dv9[64];
  real_T dv10[48];
  SL_Bus_full_loop_gazebo_msgs_ModelState msg;/* '<S2>/MATLAB Function' */
  sJdVcLKPgejLYHLePKb6F6D_full__T QPObjective;
  sJdVcLKPgejLYHLePKb6F6D_full__T QPObjective_p;
  sJdVcLKPgejLYHLePKb6F6D_full__T objective;
  sJdVcLKPgejLYHLePKb6F6D_full__T c_objective;
  sJdVcLKPgejLYHLePKb6F6D_full__T d_objective;
  sJdVcLKPgejLYHLePKb6F6D_full__T b_objective;
  real_T dv11[44];
  real_T Opt[34];
  real_T Rhs[34];
  real_T u_a[32];
  real_T c[21];
  real_T solution_e[21];
  real_T solution_a[21];
  real_T solution_as[21];
  real_T e[21];
  real_T work[21];
  real_T c_i[21];
  real_T work_l[21];
  real_T vn1[21];
  real_T vn2[21];
  real_T work_o[21];
  real_T xk[20];
  real_T b_xoff[20];
  real_T xk_o[20];
  real_T Bu_i[20];
  real_T f[19];
  real_T VectorConcatenate_e[18];      /* '<S21>/Vector Concatenate' */
  real_T zopt[17];
  real_T f_f[17];
  real_T r_i[17];
  real_T AcRow[17];
  real_T b_Ac[17];
  real_T tau[17];
  real_T work_f[17];
  real_T work_g[17];
  real_T varargin_1[17];
  s6ICcRyulWOFjNCN0ll7VsE_full__T b_MeritFunction;
  s6ICcRyulWOFjNCN0ll7VsE_full__T r_c;
  real_T FromWorkspace1[12];           /* '<S6>/From Workspace1' */
  real_T y_innov[12];
  real_T TmpSignalConversionAtSFunct[12];/* '<S4>/check' */
  real_T dv12[12];
  real_T dv13[12];
  real_T dv14[12];
  real_T b_this_o[12];
  real_T b_this_l[12];
  real_T b_C_m[12];
  real_T vseq[11];
  int32_T e_memspace_workspace_int[21];
  int32_T c_memspace_workspace_int[21];
  int32_T c_memspace_workspace_sort[21];
  real_T b_utarget_m[10];
  int32_T ipiv[20];
  real_T Transpose[9];                 /* '<S13>/Transpose' */
  real_T rtb_Transpose_c[9];
  real_T A_f[9];
  s1TgE9KstXgkd2qJxO1bF4F_full__T expl_temp;
  s1TgE9KstXgkd2qJxO1bF4F_full__T expl_temp_p;
  s1TgE9KstXgkd2qJxO1bF4F_full__T qpoptions;
  s1TgE9KstXgkd2qJxO1bF4F_full__T qpoptions_e;
  s1TgE9KstXgkd2qJxO1bF4F_full__T qpoptions_o;
  s1TgE9KstXgkd2qJxO1bF4F_full__T qpoptions_h;
  s1TgE9KstXgkd2qJxO1bF4F_full__T qpoptions_l;
  s1TgE9KstXgkd2qJxO1bF4F_full__T qpoptions_h2;
  s1TgE9KstXgkd2qJxO1bF4F_full__T qpoptions_m;
  s1TgE9KstXgkd2qJxO1bF4F_full__T options;
  s1TgE9KstXgkd2qJxO1bF4F_full__T runTimeOptions;
  real_T b_uoff[8];
  real_T umax_scale[8];                /* '<S70>/umax_scale' */
  real_T umin_scale[8];                /* '<S70>/umin_scale' */
  real_T MATLABSystem_o3[8];           /* '<S4>/MATLAB System' */
  real_T dv15[8];
  real_T dv16[8];
  real_T dv17[8];
  real_T c_xk[8];
  real_T TrialState_m[8];
  real_T umax_incr[8];
  real_T umin_incr[8];
  real_T c_xk_h[8];
  real_T y_c[8];
  real_T y_k[8];
  real_T U_p[8];
  s_iyYBPziYRv853Phg0mcgOD_full_T FiniteDifferences;
  real_T dv18[6];
  real_T beqFiltered[6];
  real_T b_beqFiltered[6];
  real_T l[6];
  real_T d_p[6];
  real_T theta[5];
  real_T qS2W[4];                      /* '<S5>/Gain' */
  real_T Bc[4];
  real_T b_Mu1[4];
  real_T unusedU0[4];
  real_T cTol[4];
  real_T varargin_1_p[4];
  char_T cv[24];
  real_T ubvbwb[3];                    /* '<S13>/ub,vb,wb' */
  real_T BodyPosition[3];              /* '<S5>/Discrete-Time Integrator1' */
  real_T Product[3];                   /* '<S26>/Product' */
  real_T sincos_o1[3];                 /* '<S29>/sincos' */
  real_T Dynamics[3];
  real_T dv19[3];
  real_T dv20[3];
  int32_T idxDepEq[6];
  int32_T c_idxArray[6];
  int32_T x[6];
  s_8jIp3wBW8W9AJZ7lDTkICE_full_T expl_temp_a;
  s_8jIp3wBW8W9AJZ7lDTkICE_full_T b_FcnEvaluator;
  int32_T b_WorkingSet_tmp[5];
  int8_T ipiv_j[12];
  s7RdrPWkr8UPAUyTdDJkLaG_full__T b_Flags;
  real_T Output;                       /* '<S65>/Output' */
  real_T q0;                           /* '<S29>/q0' */
  real_T q1;                           /* '<S29>/q1' */
  real_T q2;                           /* '<S29>/q2' */
  real_T q3;                           /* '<S29>/q3' */
  real_T TmpSignalConversionAtq0q1q2q3In[4];
                                    /* '<S19>/Rotation Angles to Quaternions' */
  real_T Memory[4];                    /* '<S59>/Memory' */
  real_T VectorConcatenate[3];         /* '<S118>/Vector Concatenate' */
  real_T Output_j;                     /* '<S66>/Output' */
  real_T AngularRate[3];               /* '<S17>/Sum2' */
  real_T Memory5[3];                   /* '<S4>/Memory5' */
  real_T Memory3[12];                  /* '<S4>/Memory3' */
  real_T Sum;                          /* '<S107>/Sum' */
  real_T Sum_g;                        /* '<S108>/Sum' */
  real_T Sum_e;                        /* '<S109>/Sum' */
  real_T WorldPosition[3];             /* '<S5>/Discrete-Time Integrator' */
  real_T Sum_a[3];                     /* '<S6>/Sum' */
  real_T Memory_e[3];                  /* '<S6>/Memory' */
  real_T DataTypeConversion1[12];      /* '<S70>/Data Type Conversion1' */
  real_T Selector[9];                  /* '<S20>/Selector' */
  real_T Selector1[9];                 /* '<S20>/Selector1' */
  real_T Selector2[9];                 /* '<S20>/Selector2' */
  real_T Sum_ae[8];                    /* '<S4>/Sum' */
  real_T uDLookupTable1[8];            /* '<S16>/1-D Lookup Table1' */
  real_T TmpSignalConversionAtq0q1q2q3_c[4];/* '<S19>/qdot' */
  real_T Product2[3];                  /* '<S20>/Product2' */
  real_T Sum_b[3];                     /* '<S13>/Sum' */
  real_T Gain2;                        /* '<S2>/Gain2' */
  real_T Gain1;                        /* '<S2>/Gain1' */
  real_T Gain;                         /* '<S2>/Gain' */
  real_T Divide;                       /* '<S10>/Divide' */
  real_T Divide1;                      /* '<S10>/Divide1' */
  real_T Divide2;                      /* '<S10>/Divide2' */
  real_T Divide3;                      /* '<S10>/Divide3' */
  real_T y[3];                         /* '<S6>/MATLAB Function' */
  real_T checkedPose[12];              /* '<S4>/check' */
  real_T tcount[3];                    /* '<S4>/check' */
  real_T xk1[20];                      /* '<S98>/FixedHorizonOptimizer' */
  real_T u[8];                         /* '<S98>/FixedHorizonOptimizer' */
  real_T Pk1[400];                     /* '<S98>/FixedHorizonOptimizer' */
  real_T A[144];                       /* '<S4>/MATLAB System1' */
  real_T B[96];                        /* '<S4>/MATLAB System1' */
  real_T C[144];                       /* '<S4>/MATLAB System1' */
  real_T D[96];                        /* '<S4>/MATLAB System1' */
  real_T U[8];                         /* '<S4>/MATLAB System1' */
  real_T Y[12];                        /* '<S4>/MATLAB System1' */
  real_T X[12];                        /* '<S4>/MATLAB System1' */
  real_T DX[12];                       /* '<S4>/MATLAB System1' */
  real_T q[4];                         /* '<S59>/MATLAB Function' */
  real_T Merge;                        /* '<S46>/Merge' */
  real_T Merge_b;                      /* '<S120>/Merge' */
  real_T t7;
  real_T t14;
  real_T t17;
  real_T t24;
  real_T t25;
  real_T t20;
  real_T t21;
  real_T t22;
  real_T t23;
  real_T t42;
  real_T t48;
  real_T t52;
  real_T t55;
  real_T ixk;                          /* '<S58>/i x k' */
  real_T Product3_pg;                  /* '<S12>/Product3' */
  real_T Product2_fy;                  /* '<S12>/Product2' */
  real_T Sum_a_e;                      /* '<S12>/Sum' */
  real_T Sum_d;                        /* '<S137>/Sum' */
  real_T Product3_bd;                  /* '<S129>/Product3' */
  real_T Product2_h5;                  /* '<S129>/Product2' */
  real_T rtb_sincos_o2_idx_0;
  real_T rtb_sincos_o2_idx_1;
  real_T rtb_sincos_o2_idx_2;
  real_T rtb_sincos_o2_b_idx_0;
  real_T rtb_sincos_o2_b_idx_1;
  real_T Dynamics_tmp;
  real_T Dynamics_tmp_o;
  real_T Dynamics_tmp_b;
  real_T Dynamics_tmp_a;
  real_T fcn3_m;                       /* '<S103>/fcn3' */
  real_T fcn3;                         /* '<S28>/fcn3' */
  real_T b_g;
  real_T j;
  real_T beta;
  real_T rho;
  real_T b_e;
  real_T alpha;
  real_T b_f;
  real_T constrViolation_new;
  real_T constrViolation_minnormX;
  real_T constrViolation_basicX;
  real_T b_atmp;
  real_T xnorm;
  real_T scale;
  real_T absxk;
  real_T t_h;
  real_T DelBound;
  real_T d_e;
  real_T b_Kx;
  real_T b_Kr;
  real_T b_Ku1;
  real_T b_Kv;
  real_T b_Kut;
  real_T rMin;
  real_T Xnorm0;
  real_T cMin;
  real_T cVal;
  real_T zTa;
  real_T b_Linv;
  real_T b_atmp_c;
  real_T xnorm_a;
  real_T scale_d;
  real_T absxk_a;
  real_T t_p;
  real_T normA;
  real_T s;
  real_T d_m;
  real_T temp;
  real_T smax;
  real_T s_o;
  real_T constrViolation;
  real_T tol;
  real_T temp1;
  real_T temp2;
  real_T b_atmp_n;
  real_T c_l;
  real_T oldDirIdx;
  real_T a;
  real_T ssq;
  real_T c_p;
  real_T optimRelativeFactor;
  real_T c_pt;
  real_T nlpDualFeasErrorTmp;
  real_T d1;
  real_T tol_f;
  real_T c_ie;
  real_T b_Wy;
  real_T c_c;
  real_T b_s;
  real_T temp_o;
  real_T roe;
  real_T absa;
  real_T b_c;
  real_T s_k;
  real_T c_ieu;
  real_T absb;
  real_T scale_o;
  real_T ads;
  real_T bds;
  real_T temp_m;
  real_T ex;
  real_T b_H_c;
  real_T ssq_f;
  real_T d2;
  real_T t6;
  real_T t7_h;
  real_T t8;
  real_T t9;
  real_T t10;
  real_T t11;
  real_T t12;
  real_T t13;
  real_T t14_m;
  real_T t18;
  real_T t19;
  real_T t20_a;
  real_T t21_k;
  real_T t22_p;
  real_T t23_b;
  real_T t27;
  real_T t28;
  real_T t29;
  real_T t34;
  real_T t35;
  real_T t36;
  real_T t37;
  real_T t38;
  real_T t39;
  real_T t40;
  real_T t41;
  real_T t47;
  real_T t48_c;
  real_T t49;
  real_T t50;
  real_T t51;
  real_T t52_n;
  real_T t53;
  real_T t54;
  real_T t55_i;
  real_T t56;
  real_T t59;
  real_T t60;
  real_T t67;
  real_T t74;
  real_T t69;
  real_T t70;
  real_T t71;
  real_T t72;
  real_T t80;
  real_T t81;
  real_T t82;
  real_T t83;
  real_T t85;
  real_T t86;
  real_T t88;
  real_T t89;
  real_T t96;
  real_T t84;
  real_T t93;
  real_T t97;
  real_T t99;
  real_T t34_tmp;
  real_T t36_tmp;
  real_T A_tmp;
  real_T A_tmp_m;
  real_T A_tmp_j;
  real_T A_tmp_e;
  real_T A_tmp_mv;
  real_T deltaX;
  real_T b_m;
  real_T x_j;
  real_T qtb;
  real_T phi_alpha;
  real_T constrViolationEq;
  real_T t5;
  real_T t6_f;
  real_T t7_a;
  real_T t8_g;
  real_T t9_n;
  real_T t10_d;
  real_T t11_n;
  real_T t12_c;
  real_T t13_f;
  real_T t15;
  real_T t16;
  real_T t18_p;
  real_T t19_p;
  real_T t20_n;
  real_T t21_kt;
  real_T t22_n;
  real_T tol_o;
  real_T qtb_g;
  real_T denomTol;
  real_T phaseOneCorrectionX;
  real_T phaseOneCorrectionP;
  real_T pk_corrected;
  real_T ratio;
  real_T u0;
  real_T scale_c;
  real_T smax_c;
  real_T s_m;
  real_T u1;
  real_T tol_j;
  real_T c_k;
  real_T temp_mx;
  real_T c_pr;
  real_T u1_d;
  real_T c_g;
  real_T u1_c;
  real_T c_cx;
  real_T u1_i;
  real_T c_d;
  real_T c_g4;
  real_T dotSY;
  real_T curvatureS;
  real_T temp_l;
  real_T c_f;
  real_T penaltyParamTrial;
  real_T c_db;
  real_T temp_j;
  real_T nrmGradInf;
  real_T c_i3;
  real_T c_h;
  real_T c_n;
  real_T c_o;
  real_T c_ch;
  real_T temp_b;
  real_T temp_e;
  real_T c_dd;
  int16_T iAnew[4];
  int16_T iC[4];
  char_T qpoptions_SolverName[7];
  uint8_T m_vals[5];
  int32_T kBcol;
  int32_T b_jAcol;
  int32_T b_c_i;
  int32_T ix;
  int32_T b_ix;
  int32_T c_ix;
  int32_T ijA;
  int32_T i;
  int32_T nDepEq;
  int32_T i_g;
  int32_T nVar;
  int32_T mEq;
  int32_T mConstr;
  int32_T Flags_stepType;
  int32_T c_nn;
  int32_T i_l;
  int32_T WorkingSet_c;
  int32_T nVar_n;
  int32_T b_k;
  int32_T nVarOrig;
  int32_T mEq_p;
  int32_T temp_d;
  int32_T iEq0;
  int32_T iIneqEnd;
  int32_T nVar_o;
  int32_T mConstr_j;
  int32_T mEqFixed;
  int32_T activeSetChangeID;
  int32_T nVar_c;
  int32_T globalActiveConstrIdx;
  int32_T idxMinLambda;
  int32_T TYPE;
  int32_T j_h;
  int32_T nVar_d;
  int32_T mWConstr;
  int32_T nVar_c5;
  int32_T b_idx;
  int32_T b_idx_row;
  int32_T b_idx_p;
  int32_T iA0_tmp;
  int32_T minmn;
  int32_T ii;
  int32_T d_i;
  int32_T b_i;
  int32_T b_Mrows_tmp;
  int32_T c_Linv_tmp;
  int32_T i_p;
  int32_T i_a;
  int32_T c_k_o;
  int32_T f_i;
  int32_T idx;
  int32_T i_j;
  int32_T f_i_p;
  int32_T i1;
  int32_T U_tmp;
  int32_T i_o;
  int32_T b_i_l;
  int32_T e_i;
  int32_T f_i_k;
  int32_T j_j;
  int32_T i2;
  int32_T i3;
  int32_T d_i_f;
  int32_T itau;
  int32_T iaii;
  int32_T i4;
  int32_T i5;
  int32_T b_j;
  int32_T b_i_c;
  int32_T b_e_f;
  int32_T i6;
  int32_T i7;
  int32_T F_tmp;
  int32_T f_k;
  int32_T i8;
  int32_T A2_tmp;
  int32_T F_tmp_n;
  int32_T b_info;
  int32_T ip;
  int32_T b_i_i;
  int32_T kAcol;
  int32_T i9;
  int32_T b_l;
  int32_T nActiveConstr;
  int32_T nFixedConstr;
  int32_T b_idx_i;
  int32_T b_idx_k;
  int32_T iA0_tmp_f;
  int32_T minmn_a;
  int32_T nfxd;
  int32_T c_j;
  int32_T nVar_d4;
  int32_T mConstrMax;
  int32_T b_k_e;
  int32_T nVar_e;
  int32_T mNull;
  int32_T nullStartIdx;
  int32_T c_idx;
  int32_T iA0;
  int32_T iUU0;
  int32_T b_idx_b;
  int32_T k;
  int32_T b_k_a;
  int32_T j_i;
  int32_T jm1;
  int32_T idxA1j;
  int32_T idxAjj;
  int32_T mEq_f;
  int32_T mLambda;
  int32_T idx_j;
  int32_T fullRank_R;
  int32_T rankR;
  int32_T iQR_diag;
  int32_T jjA;
  int32_T i_oo;
  int32_T ix_f;
  int32_T b_o;
  int32_T b_i_ln;
  int32_T iQR0;
  int32_T b_idx_l;
  int32_T i_gf;
  int32_T iaii_d;
  int32_T b_d;
  int32_T b_tmp;
  int32_T lastv;
  int32_T nVars;
  int32_T mNull_j;
  int32_T nullStart;
  int32_T b_idx_col;
  int32_T idx_row;
  int32_T lastColC;
  int32_T mNull_f;
  int32_T nullStart_j;
  int32_T lastColC_h;
  int32_T br;
  int32_T mLinEq;
  int32_T b_idx_local;
  int32_T i_c;
  int32_T i10;
  int32_T b_idx_n;
  int32_T c_idx_k;
  int32_T ix_a;
  int32_T iy;
  int32_T minmn_f;
  int32_T ii_j;
  int32_T nmi;
  int32_T mmi;
  int32_T pvt;
  int32_T itemp;
  int32_T nVar_k;
  int32_T mTotalWorkingEq;
  int32_T b_idx_row_b;
  int32_T b_idx_col_h;
  int32_T c_idx_e;
  int32_T ix_h;
  int32_T iy_k;
  int32_T nVar_j;
  int32_T mmi_o;
  int32_T b_i_cs;
  int32_T lastv_h;
  int32_T nVar_i;
  int32_T mEq_pl;
  int32_T mLambda_f;
  int32_T idx_max;
  int32_T ix_e;
  int32_T nActiveConstr_n;
  int32_T idx_h;
  int32_T jjA_h;
  int32_T i_f;
  int32_T ix_i;
  int32_T b_f4;
  int32_T b_cy;
  int32_T k_n;
  int32_T ii_h;
  int32_T mmi_k;
  int32_T b_i_h;
  int32_T mEq_b;
  int32_T mLBOrig;
  int32_T iyend;
  int32_T iy_o;
  int32_T mLB;
  int32_T b_idx_nq;
  int32_T mLB_m;
  int32_T b_idx_ku;
  int32_T mLB_j;
  int32_T b_idx_h;
  int32_T idxFillStart;
  int32_T iAeq0;
  int32_T iATw0;
  int32_T b_f2;
  int32_T c_dy;
  int32_T nVar_l;
  int32_T mEq_k;
  int32_T i_i;
  int32_T endIdx;
  int32_T c_h5;
  int32_T b_mg;
  int32_T ixlast;
  int32_T b_idx_g;
  int32_T j_l;
  int32_T b_idx_m;
  boolean_T iAout[4];                  /* '<S98>/FixedHorizonOptimizer' */
} B_full_loop_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  TrimPlant_full_loop_T obj;           /* '<S4>/MATLAB System1' */
  KickIn_full_loop_T obj_c;            /* '<S4>/MATLAB System' */
  ros_slros_internal_block_Publ_T obj_k;/* '<S9>/SinkBlock' */
  real_T last_mv_DSTATE[8];            /* '<S70>/last_mv' */
  real_T DiscreteTimeIntegrator1_DSTATE[3];/* '<S5>/Discrete-Time Integrator1' */
  real_T DiscreteTimeIntegrator_DSTATE[3];/* '<S5>/Discrete-Time Integrator' */
  real_T Aeq[48];                      /* '<S4>/MATLAB System' */
  real_T Beq[6];                       /* '<S4>/MATLAB System' */
  real_T uMin[8];                      /* '<S4>/MATLAB System' */
  real_T uMax[8];                      /* '<S4>/MATLAB System' */
  real_T u0[8];                        /* '<S4>/MATLAB System' */
  real_T Ac[144];                      /* '<S4>/MATLAB System1' */
  real_T Bc[96];                       /* '<S4>/MATLAB System1' */
  real_T Cc[144];                      /* '<S4>/MATLAB System1' */
  real_T Dc[96];                       /* '<S4>/MATLAB System1' */
  real_T LastPcov_PreviousInput[400];  /* '<S70>/LastPcov' */
  real_T last_x_PreviousInput[20];     /* '<S70>/last_x' */
  real_T NextOutput;                   /* '<S65>/White Noise' */
  real_T Memory_PreviousInput[4];      /* '<S59>/Memory' */
  real_T NextOutput_b;                 /* '<S66>/White Noise' */
  real_T Memory5_PreviousInput[3];     /* '<S4>/Memory5' */
  real_T Memory3_PreviousInput[12];    /* '<S4>/Memory3' */
  real_T Memory_PreviousInput_p[3];    /* '<S6>/Memory' */
  real_T Memory_PreviousInput_m[8];    /* '<S4>/Memory' */
  real_T Product2_DWORK4[9];           /* '<S20>/Product2' */
  struct {
    void *TimePtr;
    void *DataPtr;
    void *RSimInfoPtr;
  } FromWorkspace1_PWORK;              /* '<S6>/From Workspace1' */

  uint32_T RandSeed;                   /* '<S65>/White Noise' */
  uint32_T RandSeed_k;                 /* '<S66>/White Noise' */
  int_T q0q1q2q3_IWORK;                /* '<S19>/q0 q1 q2 q3' */
  struct {
    int_T PrevIndex;
  } FromWorkspace1_IWORK;              /* '<S6>/From Workspace1' */

  int8_T If_ActiveSubsystem;           /* '<S46>/If' */
  int8_T If_ActiveSubsystem_j;         /* '<S120>/If' */
  boolean_T Memory_PreviousInput_d[4]; /* '<S70>/Memory' */
  boolean_T objisempty;                /* '<S4>/MATLAB System' */
  boolean_T objisempty_b;              /* '<S4>/MATLAB System1' */
  boolean_T objisempty_g;              /* '<S9>/SinkBlock' */
} DW_full_loop_T;

/* Continuous states (default storage) */
typedef struct {
  real_T ubvbwb_CSTATE[3];             /* '<S13>/ub,vb,wb' */
  real_T q0q1q2q3_CSTATE[4];           /* '<S19>/q0 q1 q2 q3' */
  real_T pqr_CSTATE[3];                /* '<S13>/p,q,r ' */
  real_T Integrator_CSTATE[3];         /* '<S15>/Integrator' */
  real_T xeyeze_CSTATE[3];             /* '<S13>/xe,ye,ze' */
} X_full_loop_T;

/* State derivatives (default storage) */
typedef struct {
  real_T ubvbwb_CSTATE[3];             /* '<S13>/ub,vb,wb' */
  real_T q0q1q2q3_CSTATE[4];           /* '<S19>/q0 q1 q2 q3' */
  real_T pqr_CSTATE[3];                /* '<S13>/p,q,r ' */
  real_T Integrator_CSTATE[3];         /* '<S15>/Integrator' */
  real_T xeyeze_CSTATE[3];             /* '<S13>/xe,ye,ze' */
} XDot_full_loop_T;

/* State disabled  */
typedef struct {
  boolean_T ubvbwb_CSTATE[3];          /* '<S13>/ub,vb,wb' */
  boolean_T q0q1q2q3_CSTATE[4];        /* '<S19>/q0 q1 q2 q3' */
  boolean_T pqr_CSTATE[3];             /* '<S13>/p,q,r ' */
  boolean_T Integrator_CSTATE[3];      /* '<S15>/Integrator' */
  boolean_T xeyeze_CSTATE[3];          /* '<S13>/xe,ye,ze' */
} XDis_full_loop_T;

#ifndef ODE3_INTG
#define ODE3_INTG

/* ODE3 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[3];                        /* derivatives */
} ODE3_IntgData;

#endif

/* Parameters (default storage) */
struct P_full_loop_T_ {
  real_T I[9];                         /* Variable: I
                                        * Referenced by: '<S21>/Constant1'
                                        */
  real_T N[201];                       /* Variable: N
                                        * Referenced by:
                                        *   '<S4>/1-D Lookup Table5'
                                        *   '<S16>/1-D Lookup Table1'
                                        */
  real_T PWM[201];                     /* Variable: PWM
                                        * Referenced by:
                                        *   '<S4>/1-D Lookup Table5'
                                        *   '<S16>/1-D Lookup Table1'
                                        */
  real_T TMAX[8];                      /* Variable: TMAX
                                        * Referenced by: '<S4>/Constant2'
                                        */
  real_T TMIN[8];                      /* Variable: TMIN
                                        * Referenced by: '<S4>/Constant'
                                        */
  real_T Ts;                           /* Variable: Ts
                                        * Referenced by: '<S4>/Constant1'
                                        */
  real_T Ui[8];                        /* Variable: Ui
                                        * Referenced by: '<S4>/Memory'
                                        */
  real_T Xi[12];                       /* Variable: Xi
                                        * Referenced by: '<S4>/Memory3'
                                        */
  real_T mass;                         /* Variable: mass
                                        * Referenced by: '<S21>/Constant'
                                        */
  real_T tmax;                         /* Variable: tmax
                                        * Referenced by: '<S4>/Saturation'
                                        */
  real_T tmin;                         /* Variable: tmin
                                        * Referenced by: '<S4>/Saturation'
                                        */
  real_T waPhi;                        /* Variable: waPhi
                                        * Referenced by: '<S18>/Roll Wave'
                                        */
  real_T waPsi;                        /* Variable: waPsi
                                        * Referenced by: '<S18>/Yaw Wave'
                                        */
  real_T waTheta;                      /* Variable: waTheta
                                        * Referenced by: '<S18>/Pitch Wave'
                                        */
  real_T waX;                          /* Variable: waX
                                        * Referenced by: '<S18>/X Wave'
                                        */
  real_T waY;                          /* Variable: waY
                                        * Referenced by: '<S18>/Y Wave'
                                        */
  real_T waZ;                          /* Variable: waZ
                                        * Referenced by: '<S18>/Z Wave'
                                        */
  real_T wfPhi;                        /* Variable: wfPhi
                                        * Referenced by: '<S18>/Roll Wave'
                                        */
  real_T wfPsi;                        /* Variable: wfPsi
                                        * Referenced by: '<S18>/Yaw Wave'
                                        */
  real_T wfTheta;                      /* Variable: wfTheta
                                        * Referenced by: '<S18>/Pitch Wave'
                                        */
  real_T wfX;                          /* Variable: wfX
                                        * Referenced by: '<S18>/X Wave'
                                        */
  real_T wfY;                          /* Variable: wfY
                                        * Referenced by: '<S18>/Y Wave'
                                        */
  real_T wfZ;                          /* Variable: wfZ
                                        * Referenced by: '<S18>/Z Wave'
                                        */
  real_T wpPhi;                        /* Variable: wpPhi
                                        * Referenced by: '<S18>/Roll Wave'
                                        */
  real_T wpPsi;                        /* Variable: wpPsi
                                        * Referenced by: '<S18>/Yaw Wave'
                                        */
  real_T wpTheta;                      /* Variable: wpTheta
                                        * Referenced by: '<S18>/Pitch Wave'
                                        */
  real_T wpX;                          /* Variable: wpX
                                        * Referenced by: '<S18>/X Wave'
                                        */
  real_T wpY;                          /* Variable: wpY
                                        * Referenced by: '<S18>/Y Wave'
                                        */
  real_T wpZ;                          /* Variable: wpZ
                                        * Referenced by: '<S18>/Z Wave'
                                        */
  uint8_T modelName[4];                /* Variable: modelName
                                        * Referenced by: '<S2>/ '
                                        */
  uint8_T referenceFrame[5];           /* Variable: referenceFrame
                                        * Referenced by: '<S2>/  '
                                        */
  real_T BandLimitedWhiteNoise_Cov; /* Mask Parameter: BandLimitedWhiteNoise_Cov
                                     * Referenced by: '<S65>/Output'
                                     */
  real_T BandLimitedWhiteNoise1_Cov;
                                   /* Mask Parameter: BandLimitedWhiteNoise1_Cov
                                    * Referenced by: '<S66>/Output'
                                    */
  real_T uDOFEulerAngles_Vm_0[3];      /* Mask Parameter: uDOFEulerAngles_Vm_0
                                        * Referenced by: '<S13>/ub,vb,wb'
                                        */
  real_T uDOFEulerAngles_eul_0[3];     /* Mask Parameter: uDOFEulerAngles_eul_0
                                        * Referenced by: '<S19>/Initial Euler Angles'
                                        */
  real_T uDOFEulerAngles_k_quat;       /* Mask Parameter: uDOFEulerAngles_k_quat
                                        * Referenced by: '<S30>/High Gain Quaternion Normalization'
                                        */
  real_T uDOFEulerAngles_pm_0[3];      /* Mask Parameter: uDOFEulerAngles_pm_0
                                        * Referenced by: '<S13>/p,q,r '
                                        */
  real_T BandLimitedWhiteNoise_seed;
                                   /* Mask Parameter: BandLimitedWhiteNoise_seed
                                    * Referenced by: '<S65>/White Noise'
                                    */
  real_T BandLimitedWhiteNoise1_seed;
                                  /* Mask Parameter: BandLimitedWhiteNoise1_seed
                                   * Referenced by: '<S66>/White Noise'
                                   */
  real_T uDOFEulerAngles_xme_0[3];     /* Mask Parameter: uDOFEulerAngles_xme_0
                                        * Referenced by: '<S13>/xe,ye,ze'
                                        */
  SL_Bus_full_loop_gazebo_msgs_ModelState Constant_Value;/* Computed Parameter: Constant_Value
                                                          * Referenced by: '<S7>/Constant'
                                                          */
  real_T Constant_Value_c;             /* Expression: 1
                                        * Referenced by: '<S47>/Constant'
                                        */
  real_T Constant_Value_o;             /* Expression: 1
                                        * Referenced by: '<S48>/Constant'
                                        */
  real_T Constant_Value_m;             /* Expression: 1
                                        * Referenced by: '<S121>/Constant'
                                        */
  real_T Constant_Value_j;             /* Expression: 1
                                        * Referenced by: '<S122>/Constant'
                                        */
  real_T LastPcov_InitialCondition[400];/* Expression: lastPcov
                                         * Referenced by: '<S70>/LastPcov'
                                         */
  real_T last_x_InitialCondition[20];  /* Expression: lastx+xoff
                                        * Referenced by: '<S70>/last_x'
                                        */
  real_T last_mv_InitialCondition[8];  /* Expression: lastu+uoff
                                        * Referenced by: '<S70>/last_mv'
                                        */
  real_T DiscreteTimeIntegrator1_gainval;
                          /* Computed Parameter: DiscreteTimeIntegrator1_gainval
                           * Referenced by: '<S5>/Discrete-Time Integrator1'
                           */
  real_T DiscreteTimeIntegrator1_IC;   /* Expression: 0
                                        * Referenced by: '<S5>/Discrete-Time Integrator1'
                                        */
  real_T WhiteNoise_Mean;              /* Expression: 0
                                        * Referenced by: '<S65>/White Noise'
                                        */
  real_T WhiteNoise_StdDev;            /* Computed Parameter: WhiteNoise_StdDev
                                        * Referenced by: '<S65>/White Noise'
                                        */
  real_T u2_Gain;                      /* Expression: 0.5
                                        * Referenced by: '<S29>/1//2'
                                        */
  real_T u2_Gain_j;                    /* Expression: 0.5
                                        * Referenced by: '<S62>/1//2'
                                        */
  real_T Memory_InitialCondition[4];   /* Expression: [0,0,0,1]
                                        * Referenced by: '<S59>/Memory'
                                        */
  real_T WhiteNoise_Mean_m;            /* Expression: 0
                                        * Referenced by: '<S66>/White Noise'
                                        */
  real_T WhiteNoise_StdDev_a;         /* Computed Parameter: WhiteNoise_StdDev_a
                                       * Referenced by: '<S66>/White Noise'
                                       */
  real_T Memory5_InitialCondition[3];  /* Expression: [0,0,0]
                                        * Referenced by: '<S4>/Memory5'
                                        */
  real_T Gain_Gain;                    /* Expression: 1
                                        * Referenced by: '<S5>/Gain'
                                        */
  real_T Constant_Value_e;             /* Expression: 0.5
                                        * Referenced by: '<S107>/Constant'
                                        */
  real_T Gain2_Gain;                   /* Expression: 2
                                        * Referenced by: '<S107>/Gain2'
                                        */
  real_T Gain_Gain_c;                  /* Expression: 2
                                        * Referenced by: '<S107>/Gain'
                                        */
  real_T Gain1_Gain;                   /* Expression: 2
                                        * Referenced by: '<S107>/Gain1'
                                        */
  real_T Gain_Gain_ca;                 /* Expression: 2
                                        * Referenced by: '<S108>/Gain'
                                        */
  real_T Constant_Value_or;            /* Expression: 0.5
                                        * Referenced by: '<S108>/Constant'
                                        */
  real_T Gain2_Gain_f;                 /* Expression: 2
                                        * Referenced by: '<S108>/Gain2'
                                        */
  real_T Gain1_Gain_c;                 /* Expression: 2
                                        * Referenced by: '<S108>/Gain1'
                                        */
  real_T Gain_Gain_n;                  /* Expression: 2
                                        * Referenced by: '<S109>/Gain'
                                        */
  real_T Gain1_Gain_d;                 /* Expression: 2
                                        * Referenced by: '<S109>/Gain1'
                                        */
  real_T Constant_Value_a;             /* Expression: 0.5
                                        * Referenced by: '<S109>/Constant'
                                        */
  real_T Gain2_Gain_g;                 /* Expression: 2
                                        * Referenced by: '<S109>/Gain2'
                                        */
  real_T DiscreteTimeIntegrator_gainval;
                           /* Computed Parameter: DiscreteTimeIntegrator_gainval
                            * Referenced by: '<S5>/Discrete-Time Integrator'
                            */
  real_T DiscreteTimeIntegrator_IC;    /* Expression: 0
                                        * Referenced by: '<S5>/Discrete-Time Integrator'
                                        */
  real_T Constant_Value_p;             /* Expression: 0.5
                                        * Referenced by: '<S136>/Constant'
                                        */
  real_T Gain2_Gain_i;                 /* Expression: 2
                                        * Referenced by: '<S136>/Gain2'
                                        */
  real_T Gain_Gain_m;                  /* Expression: 2
                                        * Referenced by: '<S136>/Gain'
                                        */
  real_T Gain1_Gain_l;                 /* Expression: 2
                                        * Referenced by: '<S136>/Gain1'
                                        */
  real_T Gain_Gain_cd;                 /* Expression: 2
                                        * Referenced by: '<S137>/Gain'
                                        */
  real_T Constant_Value_l;             /* Expression: 0.5
                                        * Referenced by: '<S137>/Constant'
                                        */
  real_T Gain2_Gain_m;                 /* Expression: 2
                                        * Referenced by: '<S137>/Gain2'
                                        */
  real_T Gain1_Gain_h;                 /* Expression: 2
                                        * Referenced by: '<S137>/Gain1'
                                        */
  real_T Gain_Gain_h;                  /* Expression: 2
                                        * Referenced by: '<S138>/Gain'
                                        */
  real_T Gain1_Gain_i;                 /* Expression: 2
                                        * Referenced by: '<S138>/Gain1'
                                        */
  real_T Constant_Value_k;             /* Expression: 0.5
                                        * Referenced by: '<S138>/Constant'
                                        */
  real_T Gain2_Gain_b;                 /* Expression: 2
                                        * Referenced by: '<S138>/Gain2'
                                        */
  real_T Memory_InitialCondition_p;    /* Expression: 0
                                        * Referenced by: '<S6>/Memory'
                                        */
  real_T Constant_Value_j4;            /* Expression: 0.5
                                        * Referenced by: '<S130>/Constant'
                                        */
  real_T Gain2_Gain_mb;                /* Expression: 2
                                        * Referenced by: '<S130>/Gain2'
                                        */
  real_T Gain_Gain_ha;                 /* Expression: 2
                                        * Referenced by: '<S130>/Gain'
                                        */
  real_T Gain1_Gain_ln;                /* Expression: 2
                                        * Referenced by: '<S130>/Gain1'
                                        */
  real_T Gain_Gain_k;                  /* Expression: 2
                                        * Referenced by: '<S131>/Gain'
                                        */
  real_T Constant_Value_g;             /* Expression: 0.5
                                        * Referenced by: '<S131>/Constant'
                                        */
  real_T Gain2_Gain_fi;                /* Expression: 2
                                        * Referenced by: '<S131>/Gain2'
                                        */
  real_T Gain1_Gain_j;                 /* Expression: 2
                                        * Referenced by: '<S131>/Gain1'
                                        */
  real_T Gain_Gain_nw;                 /* Expression: 2
                                        * Referenced by: '<S132>/Gain'
                                        */
  real_T Gain1_Gain_o;                 /* Expression: 2
                                        * Referenced by: '<S132>/Gain1'
                                        */
  real_T Constant_Value_ov;            /* Expression: 0.5
                                        * Referenced by: '<S132>/Constant'
                                        */
  real_T Gain2_Gain_o;                 /* Expression: 2
                                        * Referenced by: '<S132>/Gain2'
                                        */
  real_T md_zero_Value;                /* Expression: zeros(1,1)
                                        * Referenced by: '<S67>/md_zero'
                                        */
  real_T umin_scale_Gain[8];           /* Expression: RMVscale
                                        * Referenced by: '<S70>/umin_scale'
                                        */
  real_T umax_scale_Gain[8];           /* Expression: RMVscale
                                        * Referenced by: '<S70>/umax_scale'
                                        */
  real_T ymin_zero_Value[12];          /* Expression: zeros(12,1)
                                        * Referenced by: '<S67>/ymin_zero'
                                        */
  real_T ymin_scale_Gain[12];          /* Expression: RYscale
                                        * Referenced by: '<S70>/ymin_scale'
                                        */
  real_T ymax_zero_Value[12];          /* Expression: zeros(12,1)
                                        * Referenced by: '<S67>/ymax_zero'
                                        */
  real_T ymax_scale_Gain[12];          /* Expression: RYscale
                                        * Referenced by: '<S70>/ymax_scale'
                                        */
  real_T E_zero_Value[8];              /* Expression: zeros(1,8)
                                        * Referenced by: '<S67>/E_zero'
                                        */
  real_T umin_scale4_Gain[8];      /* Expression: MVscale(:,ones(1,max(nCC,1)))'
                                    * Referenced by: '<S70>/umin_scale4'
                                    */
  real_T F_zero_Value[12];             /* Expression: zeros(1,12)
                                        * Referenced by: '<S67>/F_zero'
                                        */
  real_T ymin_scale1_Gain[12];      /* Expression: Yscale(:,ones(1,max(nCC,1)))'
                                     * Referenced by: '<S70>/ymin_scale1'
                                     */
  real_T G_zero_Value;                 /* Expression: zeros(1,1)
                                        * Referenced by: '<S67>/G_zero'
                                        */
  real_T S_zero_Value;                 /* Expression: zeros(1,1)
                                        * Referenced by: '<S67>/S_zero'
                                        */
  real_T ymin_scale2_Gain;         /* Expression: MDscale(:,ones(1,max(nCC,1)))'
                                    * Referenced by: '<S70>/ymin_scale2'
                                    */
  real_T switch_zero_Value;            /* Expression: zeros(1,1)
                                        * Referenced by: '<S67>/switch_zero'
                                        */
  real_T extmv_zero_Value[8];          /* Expression: zeros(8,1)
                                        * Referenced by: '<S67>/ext.mv_zero'
                                        */
  real_T extmv_scale_Gain[8];          /* Expression: RMVscale
                                        * Referenced by: '<S70>/ext.mv_scale'
                                        */
  real_T mvtarget_zero_Value[8];       /* Expression: zeros(8,1)
                                        * Referenced by: '<S67>/mv.target_zero'
                                        */
  real_T uref_scale_Gain[8];           /* Expression: RMVscale
                                        * Referenced by: '<S70>/uref_scale'
                                        */
  real_T ywt_zero_Value[12];           /* Expression: zeros(12,1)
                                        * Referenced by: '<S67>/y.wt_zero'
                                        */
  real_T uwt_zero_Value[8];            /* Expression: zeros(8,1)
                                        * Referenced by: '<S67>/u.wt_zero'
                                        */
  real_T duwt_zero_Value[8];           /* Expression: zeros(8,1)
                                        * Referenced by: '<S67>/du.wt_zero'
                                        */
  real_T ecrwt_zero_Value;             /* Expression: zeros(1,1)
                                        * Referenced by: '<S67>/ecr.wt_zero'
                                        */
  real_T Constant2_Value[9];           /* Expression: zeros(3)
                                        * Referenced by: '<S21>/Constant2'
                                        */
  real_T Gain_Gain_kf;                 /* Expression: 2
                                        * Referenced by: '<S32>/Gain'
                                        */
  real_T Gain_Gain_hv;                 /* Expression: 2
                                        * Referenced by: '<S33>/Gain'
                                        */
  real_T Gain_Gain_l;                  /* Expression: 2
                                        * Referenced by: '<S34>/Gain'
                                        */
  real_T Gain_Gain_hl;                 /* Expression: 2
                                        * Referenced by: '<S36>/Gain'
                                        */
  real_T Gain_Gain_i;                  /* Expression: 2
                                        * Referenced by: '<S37>/Gain'
                                        */
  real_T Gain_Gain_e;                  /* Expression: 2
                                        * Referenced by: '<S38>/Gain'
                                        */
  real_T u_scale_Gain[8];              /* Expression: MVscale
                                        * Referenced by: '<S70>/u_scale'
                                        */
  real_T Constant_Value_n;             /* Expression: 1
                                        * Referenced by: '<S30>/Constant'
                                        */
  real_T Integrator_IC;                /* Expression: 0
                                        * Referenced by: '<S15>/Integrator'
                                        */
  real_T RollWave_Bias;                /* Expression: 0
                                        * Referenced by: '<S18>/Roll Wave'
                                        */
  real_T PitchWave_Bias;               /* Expression: 0
                                        * Referenced by: '<S18>/Pitch Wave'
                                        */
  real_T YawWave_Bias;                 /* Expression: 0
                                        * Referenced by: '<S18>/Yaw Wave'
                                        */
  real_T XWave_Bias;                   /* Expression: 0
                                        * Referenced by: '<S18>/X Wave'
                                        */
  real_T YWave_Bias;                   /* Expression: 0
                                        * Referenced by: '<S18>/Y Wave'
                                        */
  real_T ZWave_Bias;                   /* Expression: 0
                                        * Referenced by: '<S18>/Z Wave'
                                        */
  real_T Gain2_Gain_a;                 /* Expression: 1
                                        * Referenced by: '<S2>/Gain2'
                                        */
  real_T Gain1_Gain_p;                 /* Expression: 1
                                        * Referenced by: '<S2>/Gain1'
                                        */
  real_T Gain_Gain_l0;                 /* Expression: -1
                                        * Referenced by: '<S2>/Gain'
                                        */
  boolean_T Memory_InitialCondition_a[4];/* Expression: iA
                                          * Referenced by: '<S70>/Memory'
                                          */
};

/* Real-time Model Data Structure */
struct tag_RTM_full_loop_T {
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
  real_T odeY[16];
  real_T odeF[3][16];
  ODE3_IntgData intgData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numSampTimes;
  } Sizes;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    uint32_T clockTick4;
    uint32_T clockTickH4;
    boolean_T firstInitCondFlag;
    struct {
      uint8_T TID[5];
    } TaskCounters;

    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[5];
  } Timing;
};

/* Class declaration for model full_loop */
class full_loopModelClass {
  /* public data and function members */
 public:
  /* model initialize function */
  void initialize();

  /* model step function */
  void step();

  /* model terminate function */
  void terminate();

  /* Constructor */
  full_loopModelClass();

  /* Destructor */
  ~full_loopModelClass();

  /* Real-Time Model get method */
  RT_MODEL_full_loop_T * getRTM();

  /* private data and function members */
 private:
  /* Tunable parameters */
  static P_full_loop_T full_loop_P;

  /* Block signals */
  B_full_loop_T full_loop_B;

  /* Block states */
  DW_full_loop_T full_loop_DW;
  X_full_loop_T full_loop_X;           /* Block continuous states */

  /* Real-Time Model */
  RT_MODEL_full_loop_T full_loop_M;

  /* private member function(s) for subsystem '<S46>/If Action Subsystem2'*/
  void full_loop_IfActionSubsystem2(real_T rtu_In, real_T *rty_OutOrig);

  /* private member function(s) for subsystem '<Root>'*/
  void full_loop_Gravity(const real_T in1[12], real_T out1[6]);
  void full_loop_AUVStateJacobianFcn(const real_T in1[12], real_T A[144], real_T
    B[96], real_T C[144], real_T D[96]);
  s_iyYBPziYRv853Phg0mcgOD_full_T full_loop_factoryConstruct_p
    (KickIn_full_loop_T **objfun_tunableEnvironment);
  void full_loop_factoryConstruct_p4(const real_T Aeq[48],
    sH6xx18cQHI5sgA7Ajla4nE_full__T *obj);
  void full_loop_xswap(int32_T n, const real_T x[441], int32_T ix0, int32_T iy0,
                       real_T b_x[441]);
  real_T full_loop_xnrm2(int32_T n, const real_T x[441], int32_T ix0);
  void full_loop_xzlarfg(int32_T n, real_T alpha1, const real_T x[441], int32_T
    ix0, real_T *b_alpha1, real_T b_x[441], real_T *tau);
  void full_loop_xzlarf_p4(int32_T m, int32_T n, int32_T iv0, real_T tau, const
    real_T C[441], int32_T ic0, real_T work[21], real_T b_C[441]);
  void full_loop_qrf_p(const real_T A[441], int32_T m, int32_T n, int32_T nfxd,
                       real_T tau[21], real_T b_A[441]);
  int32_T full_loop_ixamax(int32_T n, const real_T x[21], int32_T ix0);
  void full_loop_qrpf_p(const real_T A[441], int32_T m, int32_T n, int32_T nfxd,
                        real_T tau[21], int32_T jpvt[21], real_T b_A[441]);
  void full_loop_xgeqp3_p(const real_T A[441], int32_T m, int32_T n, int32_T
    jpvt[21], real_T b_A[441], real_T tau[21]);
  void full_loop_factorQRE(const snaQeDJ4fX7UykrKyr5M8jC_full__T *obj, int32_T
    mrows, int32_T ncols, snaQeDJ4fX7UykrKyr5M8jC_full__T *b_obj);
  void full_loop_xzlarf_p43(int32_T m, int32_T n, int32_T iv0, real_T tau, const
    real_T C[441], int32_T ic0, real_T work[21], real_T b_C[441]);
  void full_loop_computeQ__p(snaQeDJ4fX7UykrKyr5M8jC_full__T *obj, int32_T nrows);
  int32_T full__ComputeNumDependentEq__p4(snaQeDJ4fX7UykrKyr5M8jC_full__T
    *qrmanager, const real_T beqf[19]);
  void full_loo_IndexOfDependentEq__p4(int32_T depIdx[6], int32_T nDep,
    snaQeDJ4fX7UykrKyr5M8jC_full__T *qrmanager);
  void full_loop_countsort_p4(int32_T x[6], int32_T xLen, int32_T workspace[21]);
  void full__removeDependentLinearEq_p(const real_T Aeq[48], real_T beq[6],
    int32_T idxArray[6], sVTYnQ9ljvmk9dLse9XvTT_full_l_T *memspace,
    s2CPTVnVyv153Hb6bxlki6F_full__T *TrialState, sH6xx18cQHI5sgA7Ajla4nE_full__T
    *WorkingSet, sJdVcLKPgejLYHLePKb6F6D_full__T *QPObjective, int32_T *nDepInd,
    snaQeDJ4fX7UykrKyr5M8jC_full__T *QRManager);
  void full_loop_computeObjective_(KickIn_full_loop_T
    **obj_objfun_tunableEnvironment, const real_T x[8], real_T *fval, int32_T
    *status);
  void evalObjAndConstrAndDerivative_p(KickIn_full_loop_T
    **obj_objfun_tunableEnvironment, const real_T x[8], const real_T
    JacEqTrans_workspace[126], real_T *fval, real_T b_JacEqTrans_workspace[126],
    int32_T *status);
  void full_loop_finDiffEvalAndChkErr(KickIn_full_loop_T
    **obj_objfun_tunableEnvironment, int32_T dim, real_T delta, const real_T xk
    [8], boolean_T *evalOK, real_T *b_fplus, real_T b_xk[8]);
  void ful_computeForwardDifferences_p(s_iyYBPziYRv853Phg0mcgOD_full_T *obj,
    real_T fCurrent, const real_T xk[8], real_T gradf[21], const real_T
    JacCeqTrans[126], boolean_T *evalOK, real_T b_JacCeqTrans[126], real_T b_xk
    [8]);
  void full__computeLinearResiduals_p4(const real_T x[8], real_T workspaceEq[6],
    int32_T mLinEq, const real_T AeqT[126], const real_T beq[6]);
  void ful_updateWorkingSetForNewQP_p4(sH6xx18cQHI5sgA7Ajla4nE_full__T
    *WorkingSet, int32_T mEq, const real_T cEq[6]);
  void full_loop_setProblemType(const sH6xx18cQHI5sgA7Ajla4nE_full__T *obj,
    int32_T PROBLEM_TYPE, sH6xx18cQHI5sgA7Ajla4nE_full__T *b_obj);
  void full_loop_initActiveSet(const sH6xx18cQHI5sgA7Ajla4nE_full__T *obj,
    sH6xx18cQHI5sgA7Ajla4nE_full__T *b_obj);
  void full_loop_factoryConstruct_p43(real_T fval, const real_T Ceq_workspace[6],
    int32_T mNonlinEq, s6ICcRyulWOFjNCN0ll7VsE_full__T *obj);
  void full_loop_computeGradLag_p4(real_T workspace[21], int32_T nVar, const
    real_T grad[21], int32_T mEq, const real_T AeqTrans[126], const int32_T
    finiteLB[21], int32_T mLB, const real_T lambda[19]);
  void full_loop_computeDualFeasError(int32_T nVar, const real_T gradLag[21],
    boolean_T *gradOK, real_T *val);
  void full_loop_test_exit_p4(s6ICcRyulWOFjNCN0ll7VsE_full__T *MeritFunction,
    const sH6xx18cQHI5sgA7Ajla4nE_full__T *WorkingSet, const
    s2CPTVnVyv153Hb6bxlki6F_full__T *TrialState, s7RdrPWkr8UPAUyTdDJkLaG_full__T
    *Flags, s2CPTVnVyv153Hb6bxlki6F_full__T *b_TrialState);
  void full_loop_saveState(const s2CPTVnVyv153Hb6bxlki6F_full__T *obj,
    s2CPTVnVyv153Hb6bxlki6F_full__T *b_obj);
  void fu_updateWorkingSetForNewQP_p43(sH6xx18cQHI5sgA7Ajla4nE_full__T
    *WorkingSet, int32_T mEq, const real_T cEq[6]);
  void full_loop_updateWorkingSet_p(sH6xx18cQHI5sgA7Ajla4nE_full__T *WorkingSet,
    const s2CPTVnVyv153Hb6bxlki6F_full__T *TrialState);
  void full_loop_snap_bounds_p(s2CPTVnVyv153Hb6bxlki6F_full__T *solution, const
    sH6xx18cQHI5sgA7Ajla4nE_full__T *workingset);
  int32_T full_ComputeNumDependentEq__p43(snaQeDJ4fX7UykrKyr5M8jC_full__T
    *qrmanager, const real_T beqf[19], int32_T mConstr, int32_T nVar);
  void full_loop_factorQRE_p4(snaQeDJ4fX7UykrKyr5M8jC_full__T *obj, const real_T
    A[399], int32_T mrows, int32_T ncols);
  void full_lo_IndexOfDependentEq__p43(int32_T depIdx[21], int32_T mFixed,
    int32_T nDep, snaQeDJ4fX7UykrKyr5M8jC_full__T *qrmanager, const real_T
    AeqfPrime[399], int32_T mRows, int32_T nCols);
  void full_loop_countsort_p43(int32_T x[21], int32_T xLen, int32_T workspace[21],
    int32_T xMin, int32_T xMax);
  void full_loop_removeConstr_p(sH6xx18cQHI5sgA7Ajla4nE_full__T *obj, int32_T
    idx_global);
  void full_loop_removeEqConstr_p(sH6xx18cQHI5sgA7Ajla4nE_full__T *obj, int32_T
    idx_global);
  void full_loop_RemoveDependentEq__p(const real_T memspace_workspace_double[441],
    int32_T memspace_workspace_int[21], int32_T memspace_workspace_sort[21],
    sH6xx18cQHI5sgA7Ajla4nE_full__T *workingset, snaQeDJ4fX7UykrKyr5M8jC_full__T
    *qrmanager, int32_T *nDepInd, real_T b_memspace_workspace_double[441]);
  void full_loop_removeAllIneqConstr(const sH6xx18cQHI5sgA7Ajla4nE_full__T *obj,
    sH6xx18cQHI5sgA7Ajla4nE_full__T *b_obj);
  void full_loo_RemoveDependentIneq__p(sH6xx18cQHI5sgA7Ajla4nE_full__T
    *workingset, snaQeDJ4fX7UykrKyr5M8jC_full__T *qrmanager, const real_T
    memspace_workspace_double[441], int32_T memspace_workspace_int[21], int32_T
    memspace_workspace_sort[21], real_T tolfactor, real_T
    b_memspace_workspace_double[441]);
  void full_loop_xgemv_p(int32_T m, int32_T n, const real_T A[399], const real_T
    x[21], const real_T y[441], real_T b_y[441]);
  void full_loop_xgeqrf(const real_T A[441], int32_T m, int32_T n, real_T b_A
                        [441], real_T tau[21]);
  void full_loop_factorQR_p4(snaQeDJ4fX7UykrKyr5M8jC_full__T *obj, const real_T
    A[399], int32_T mrows, int32_T ncols);
  void full_loop_xtrsm_p(int32_T m, const real_T A[441], const real_T B[441],
    real_T b_B[441]);
  void full_loop_xgemm_p(int32_T m, int32_T k, const real_T A[441], const real_T
    B[441], const real_T C[441], real_T b_C[441]);
  void full_loop_factorQR(const snaQeDJ4fX7UykrKyr5M8jC_full__T *obj, int32_T
    mrows, int32_T ncols, snaQeDJ4fX7UykrKyr5M8jC_full__T *b_obj);
  void full_loop_xgemm(int32_T m, int32_T k, const real_T A[441], const real_T
                       B[441], const real_T C[441], real_T b_C[441]);
  void full_loop_xtrsm(int32_T m, const real_T A[441], const real_T B[441],
                       real_T b_B[441]);
  void full_loop_xaxpy(int32_T n, const real_T x[21], const real_T y[441],
                       real_T b_y[441]);
  void maxConstraintViolation_AMats_no(const sH6xx18cQHI5sgA7Ajla4nE_full__T
    *obj, const real_T x[441], real_T *v, sH6xx18cQHI5sgA7Ajla4nE_full__T *b_obj);
  void maxConstraintViolation_AMats_re(const sH6xx18cQHI5sgA7Ajla4nE_full__T
    *obj, const real_T x[441], real_T *v, sH6xx18cQHI5sgA7Ajla4nE_full__T *b_obj);
  void full_loo_maxConstraintViolation(const sH6xx18cQHI5sgA7Ajla4nE_full__T
    *obj, const real_T x[441], real_T *v, sH6xx18cQHI5sgA7Ajla4nE_full__T *b_obj);
  void maxConstraintViolation_AMats_p4(const sH6xx18cQHI5sgA7Ajla4nE_full__T
    *obj, const real_T x[441], real_T *v, sH6xx18cQHI5sgA7Ajla4nE_full__T *b_obj);
  void maxConstraintViolation_AMats__p(const sH6xx18cQHI5sgA7Ajla4nE_full__T
    *obj, const real_T x[441], real_T *v, sH6xx18cQHI5sgA7Ajla4nE_full__T *b_obj);
  void full_l_maxConstraintViolation_p(const sH6xx18cQHI5sgA7Ajla4nE_full__T
    *obj, const real_T x[441], real_T *v, sH6xx18cQHI5sgA7Ajla4nE_full__T *b_obj);
  boolean_T full_loop_isfinite(real_T x);
  void full__feasibleX0ForWorkingSet_p(const real_T workspace[441], real_T
    xCurrent[21], sH6xx18cQHI5sgA7Ajla4nE_full__T *workingset,
    snaQeDJ4fX7UykrKyr5M8jC_full__T *qrmanager, boolean_T *nonDegenerateWset,
    real_T b_workspace[441]);
  void maxConstraintViolation_AMa_p43r(const sH6xx18cQHI5sgA7Ajla4nE_full__T
    *obj, const real_T x[21], real_T *v, sH6xx18cQHI5sgA7Ajla4nE_full__T *b_obj);
  void maxConstraintViolation_AMat_p43(const sH6xx18cQHI5sgA7Ajla4nE_full__T
    *obj, const real_T x[21], real_T *v, sH6xx18cQHI5sgA7Ajla4nE_full__T *b_obj);
  void full__maxConstraintViolation_p4(const sH6xx18cQHI5sgA7Ajla4nE_full__T
    *obj, const real_T x[21], real_T *v, sH6xx18cQHI5sgA7Ajla4nE_full__T *b_obj);
  void full_loop_PresolveWorkingSet_p(const s2CPTVnVyv153Hb6bxlki6F_full__T
    *solution, const sVTYnQ9ljvmk9dLse9XvTT_full_l_T *memspace, const
    sH6xx18cQHI5sgA7Ajla4nE_full__T *workingset, const
    snaQeDJ4fX7UykrKyr5M8jC_full__T *qrmanager, s2CPTVnVyv153Hb6bxlki6F_full__T *
    b_solution, sVTYnQ9ljvmk9dLse9XvTT_full_l_T *b_memspace,
    sH6xx18cQHI5sgA7Ajla4nE_full__T *b_workingset,
    snaQeDJ4fX7UykrKyr5M8jC_full__T *b_qrmanager);
  void full_loop_setPhaseOne(const sJdVcLKPgejLYHLePKb6F6D_full__T *obj, int32_T
    NumVars, sJdVcLKPgejLYHLePKb6F6D_full__T *b_obj);
  void full_loop_linearForm_(boolean_T obj_hasLinear, int32_T obj_nvar, const
    real_T workspace[441], const real_T H[64], const real_T f[21], const real_T
    x[21], real_T b_workspace[441]);
  void full_loop_computeFval_p(const sJdVcLKPgejLYHLePKb6F6D_full__T *obj, const
    real_T workspace[441], const real_T H[64], const real_T f[21], const real_T
    x[21], real_T *val, real_T b_workspace[441]);
  void full_loop_xgemv_p43ri(int32_T m, int32_T n, const real_T A[64], int32_T
    lda, const real_T x[21], real_T y[20]);
  void full_loop_computeGrad_StoreHx_p(sJdVcLKPgejLYHLePKb6F6D_full__T *obj,
    const real_T H[64], const real_T f[21], const real_T x[21]);
  void full_loop_computeFval_ReuseHx_p(const sJdVcLKPgejLYHLePKb6F6D_full__T
    *obj, const real_T workspace[441], const real_T f[21], const real_T x[21],
    real_T *val, real_T b_workspace[441]);
  void full_loop_xrotg(real_T a, real_T b, real_T *b_a, real_T *b_b, real_T *c,
                       real_T *s);
  void full_loop_squareQ_appendCol_p(snaQeDJ4fX7UykrKyr5M8jC_full__T *obj, const
    real_T vec[399], int32_T iv0);
  void full_loop_xrot_p(int32_T n, const real_T x[441], int32_T ix0, int32_T iy0,
                        real_T c, real_T s, real_T b_x[441]);
  void full_loop_xrot(int32_T n, const real_T x[441], int32_T ix0, int32_T iy0,
                      real_T c, real_T s, real_T b_x[441]);
  void full_loop_deleteColMoveEnd_p(snaQeDJ4fX7UykrKyr5M8jC_full__T *obj,
    int32_T idx);
  void full_loop_xgemm_p4(int32_T m, int32_T n, int32_T k, const real_T A[64],
    int32_T lda, const real_T B[441], int32_T ib0, const real_T C[441], real_T
    b_C[441]);
  void full_loop_xgemm_p43(int32_T m, int32_T n, int32_T k, const real_T A[441],
    int32_T ia0, const real_T B[441], const real_T C[441], real_T b_C[441]);
  void computeProjectedHessian_regul_p(real_T beta, const real_T H[64], int32_T
    nVarOrig, snl99C5je2zMbU5SzygoX6F_full__T *cholmanager, const
    snaQeDJ4fX7UykrKyr5M8jC_full__T *qrmanager, sVTYnQ9ljvmk9dLse9XvTT_full_l_T *
    memspace);
  void full__computeProjectedHessian_p(const real_T H[64],
    snl99C5je2zMbU5SzygoX6F_full__T *cholmanager, const
    snaQeDJ4fX7UykrKyr5M8jC_full__T *qrmanager, sVTYnQ9ljvmk9dLse9XvTT_full_l_T *
    memspace);
  void full_loop_xpotrf(int32_T n, const real_T A[441], real_T b_A[441], int32_T
                        *info);
  void full_loop_factor_p(const real_T obj_FMat[441], int32_T ndims, real_T
    b_obj_FMat[441], int32_T *b_obj_ndims, int32_T *b_obj_info);
  void full_loop_xgemv_p43r(int32_T m, int32_T n, const real_T A[441], int32_T
    ia0, const real_T x[21], const real_T y[441], real_T b_y[441]);
  void full_loop_solve_p(const real_T obj_FMat[441], int32_T obj_ndims, int32_T
    obj_info, const real_T rhs[441], real_T b_rhs[441], real_T b_obj_FMat[441],
    int32_T *b_obj_ndims, int32_T *b_obj_info);
  void full_loop_xgemv_p43rio(int32_T m, int32_T n, const real_T A[441], int32_T
    ia0, const real_T x[441], real_T y[21]);
  void full_loop_factor(const real_T obj_FMat[441], const real_T A[64], int32_T
                        ndims, int32_T ldA, real_T b_obj_FMat[441], int32_T
                        *b_obj_ndims, int32_T *b_obj_info);
  void full_loop_solve_p4(const real_T obj_FMat[441], int32_T obj_ndims, int32_T
    obj_info, real_T rhs[21], real_T b_obj_FMat[441], int32_T *b_obj_ndims,
    int32_T *b_obj_info);
  void full_loop_compute_deltax_p(const real_T H[64],
    s2CPTVnVyv153Hb6bxlki6F_full__T *solution, sVTYnQ9ljvmk9dLse9XvTT_full_l_T
    *memspace, const snaQeDJ4fX7UykrKyr5M8jC_full__T *qrmanager,
    snl99C5je2zMbU5SzygoX6F_full__T *cholmanager, const
    sJdVcLKPgejLYHLePKb6F6D_full__T *objective, snaQeDJ4fX7UykrKyr5M8jC_full__T *
    b_qrmanager);
  real_T full_loop_xnrm2_p4(int32_T n, const real_T x[21]);
  void full_loop_feasibleratiotest(const real_T solution_xstar[21], const real_T
    solution_searchDir[21], const real_T workspace[441], int32_T workingset_nVar,
    const real_T workingset_lb[21], const int32_T workingset_indexLB[21], const
    int32_T workingset_sizes[5], const int32_T workingset_isActiveIdx[6], const
    boolean_T workingset_isActiveConstr[19], const int32_T workingset_nWConstr[5],
    boolean_T isPhaseOne, real_T *alpha, boolean_T *newBlocking, int32_T
    *constrType, int32_T *constrIdx, real_T b_workspace[441]);
  void full_checkUnboundedOrIllPosed_p(s2CPTVnVyv153Hb6bxlki6F_full__T *solution,
    const sJdVcLKPgejLYHLePKb6F6D_full__T *objective);
  void full_addBoundToActiveSetMatrix_(const sH6xx18cQHI5sgA7Ajla4nE_full__T
    *obj, int32_T TYPE, int32_T idx_local, sH6xx18cQHI5sgA7Ajla4nE_full__T
    *b_obj);
  void full_loop_addAineqConstr(const sH6xx18cQHI5sgA7Ajla4nE_full__T *obj,
    int32_T idx_local, sH6xx18cQHI5sgA7Ajla4nE_full__T *b_obj);
  void full_loop_xaxpy_p4(int32_T n, real_T a, const real_T x[21], real_T y[21]);
  void full_loop_xgemv(int32_T m, int32_T n, const real_T A[441], const real_T
                       x[21], const real_T y[441], real_T b_y[441]);
  void full_loop_compute_lambda_p(const real_T workspace[441],
    s2CPTVnVyv153Hb6bxlki6F_full__T *solution, const
    sJdVcLKPgejLYHLePKb6F6D_full__T *objective, const
    snaQeDJ4fX7UykrKyr5M8jC_full__T *qrmanager, real_T b_workspace[441]);
  int32_T full_loop_find_neg_lambda(const s2CPTVnVyv153Hb6bxlki6F_full__T
    *solution, int32_T workingset_nActiveConstr, const int32_T
    workingset_nWConstr[5]);
  int32_T full_loop_mod(int32_T x);
  void fu_checkStoppingAndUpdateFval_p(int32_T activeSetChangeID, const real_T
    f[21], s2CPTVnVyv153Hb6bxlki6F_full__T *solution,
    sVTYnQ9ljvmk9dLse9XvTT_full_l_T *memspace, const
    sJdVcLKPgejLYHLePKb6F6D_full__T *objective, sH6xx18cQHI5sgA7Ajla4nE_full__T *
    workingset, snaQeDJ4fX7UykrKyr5M8jC_full__T *qrmanager, const
    s1TgE9KstXgkd2qJxO1bF4F_full__T *options, const
    s1TgE9KstXgkd2qJxO1bF4F_full__T *runTimeOptions, boolean_T updateFval,
    int32_T *b_activeSetChangeID, sJdVcLKPgejLYHLePKb6F6D_full__T *b_objective);
  void full_loop_iterate_p(const real_T H[64], const real_T f[21],
    s2CPTVnVyv153Hb6bxlki6F_full__T *solution, sVTYnQ9ljvmk9dLse9XvTT_full_l_T
    *memspace, sH6xx18cQHI5sgA7Ajla4nE_full__T *workingset,
    snaQeDJ4fX7UykrKyr5M8jC_full__T *qrmanager, snl99C5je2zMbU5SzygoX6F_full__T *
    cholmanager, const sJdVcLKPgejLYHLePKb6F6D_full__T *objective, const
    s1TgE9KstXgkd2qJxO1bF4F_full__T *options, const
    s1TgE9KstXgkd2qJxO1bF4F_full__T *runTimeOptions,
    sJdVcLKPgejLYHLePKb6F6D_full__T *b_objective);
  void full_loop_restoreFromPhaseOne(const sJdVcLKPgejLYHLePKb6F6D_full__T *obj,
    sJdVcLKPgejLYHLePKb6F6D_full__T *b_obj);
  void full_loop_phaseone_p(const real_T H[64], const real_T f[21],
    s2CPTVnVyv153Hb6bxlki6F_full__T *solution, sVTYnQ9ljvmk9dLse9XvTT_full_l_T
    *memspace, const sH6xx18cQHI5sgA7Ajla4nE_full__T *workingset, const
    snaQeDJ4fX7UykrKyr5M8jC_full__T *qrmanager, const
    snl99C5je2zMbU5SzygoX6F_full__T *cholmanager, const
    sJdVcLKPgejLYHLePKb6F6D_full__T *objective, s1TgE9KstXgkd2qJxO1bF4F_full__T *
    options, const s1TgE9KstXgkd2qJxO1bF4F_full__T *runTimeOptions,
    sH6xx18cQHI5sgA7Ajla4nE_full__T *b_workingset,
    snaQeDJ4fX7UykrKyr5M8jC_full__T *b_qrmanager,
    snl99C5je2zMbU5SzygoX6F_full__T *b_cholmanager,
    sJdVcLKPgejLYHLePKb6F6D_full__T *b_objective);
  void full_loop_driver_p43(const real_T H[64], const real_T f[21],
    s2CPTVnVyv153Hb6bxlki6F_full__T *solution, const
    sVTYnQ9ljvmk9dLse9XvTT_full_l_T *memspace, const
    sH6xx18cQHI5sgA7Ajla4nE_full__T *workingset, const
    snaQeDJ4fX7UykrKyr5M8jC_full__T *qrmanager, snl99C5je2zMbU5SzygoX6F_full__T *
    cholmanager, sJdVcLKPgejLYHLePKb6F6D_full__T *objective,
    s1TgE9KstXgkd2qJxO1bF4F_full__T *options, s1TgE9KstXgkd2qJxO1bF4F_full__T
    *runTimeOptions, sVTYnQ9ljvmk9dLse9XvTT_full_l_T *b_memspace,
    sH6xx18cQHI5sgA7Ajla4nE_full__T *b_workingset,
    snaQeDJ4fX7UykrKyr5M8jC_full__T *b_qrmanager);
  void full_loop_restoreWorkingSet_p(sH6xx18cQHI5sgA7Ajla4nE_full__T *WorkingSet,
    const s2CPTVnVyv153Hb6bxlki6F_full__T *TrialState);
  void full_loop_sortLambdaQP_p(real_T lambda[19], int32_T
    WorkingSet_nActiveConstr, const int32_T WorkingSet_sizes[5], const int32_T
    WorkingSet_isActiveIdx[6], const int32_T WorkingSet_Wid[19], const int32_T
    WorkingSet_Wlocalidx[19], const real_T workspace[441], real_T b_workspace
    [441]);
  void full_loop_addAeqConstr(const sH6xx18cQHI5sgA7Ajla4nE_full__T *obj,
    int32_T idx_local, sH6xx18cQHI5sgA7Ajla4nE_full__T *b_obj);
  void full_loop_soc_p(const real_T Hessian[64], const real_T grad[21],
                       s2CPTVnVyv153Hb6bxlki6F_full__T *TrialState, const
                       sVTYnQ9ljvmk9dLse9XvTT_full_l_T *memspace, const
                       sH6xx18cQHI5sgA7Ajla4nE_full__T *WorkingSet, const
                       snaQeDJ4fX7UykrKyr5M8jC_full__T *QRManager, const
                       snl99C5je2zMbU5SzygoX6F_full__T *CholManager, const
                       sJdVcLKPgejLYHLePKb6F6D_full__T *QPObjective, const
                       s1TgE9KstXgkd2qJxO1bF4F_full__T *qpoptions, boolean_T
                       *success, real_T b_Hessian[64],
                       sVTYnQ9ljvmk9dLse9XvTT_full_l_T *b_memspace,
                       sH6xx18cQHI5sgA7Ajla4nE_full__T *b_WorkingSet,
                       snaQeDJ4fX7UykrKyr5M8jC_full__T *b_QRManager,
                       snl99C5je2zMbU5SzygoX6F_full__T *b_CholManager,
                       sJdVcLKPgejLYHLePKb6F6D_full__T *b_QPObjective);
  void full_loop_updatePenaltyParam_p4(s6ICcRyulWOFjNCN0ll7VsE_full__T *obj,
    real_T fval, const real_T eq_workspace[6], int32_T mEq, int32_T sqpiter,
    real_T qpval);
  void full_loop_normal_p(const real_T Hessian[64], const real_T grad[21], const
    s2CPTVnVyv153Hb6bxlki6F_full__T *TrialState, s6ICcRyulWOFjNCN0ll7VsE_full__T
    *MeritFunction, const sVTYnQ9ljvmk9dLse9XvTT_full_l_T *memspace, const
    sH6xx18cQHI5sgA7Ajla4nE_full__T *WorkingSet, const
    snaQeDJ4fX7UykrKyr5M8jC_full__T *QRManager, const
    snl99C5je2zMbU5SzygoX6F_full__T *CholManager, const
    sJdVcLKPgejLYHLePKb6F6D_full__T *QPObjective, const
    s1TgE9KstXgkd2qJxO1bF4F_full__T *qpoptions, real_T b_Hessian[64],
    s2CPTVnVyv153Hb6bxlki6F_full__T *b_TrialState,
    sVTYnQ9ljvmk9dLse9XvTT_full_l_T *b_memspace, sH6xx18cQHI5sgA7Ajla4nE_full__T
    *b_WorkingSet, snaQeDJ4fX7UykrKyr5M8jC_full__T *b_QRManager,
    snl99C5je2zMbU5SzygoX6F_full__T *b_CholManager,
    sJdVcLKPgejLYHLePKb6F6D_full__T *b_QPObjective);
  void full__assignResidualsToXSlack_p(int32_T nVarOrig,
    sH6xx18cQHI5sgA7Ajla4nE_full__T *WorkingSet, s2CPTVnVyv153Hb6bxlki6F_full__T
    *TrialState, sVTYnQ9ljvmk9dLse9XvTT_full_l_T *memspace);
  void full_loop_setRegularized_p(sJdVcLKPgejLYHLePKb6F6D_full__T *obj, int32_T
    numQuadVars, real_T beta, real_T rho);
  void full_findActiveSlackLowerBounds(const sVTYnQ9ljvmk9dLse9XvTT_full_l_T
    *memspace, const sH6xx18cQHI5sgA7Ajla4nE_full__T *WorkingSet, int32_T
    *nActiveLBArtificial, real_T b_memspace_workspace_double[441], int32_T
    b_memspace_workspace_int[21], int32_T b_memspace_workspace_sort[21]);
  real_T full_loop_xasum(int32_T n, const real_T x[21], int32_T ix0);
  real_T full_loop_xdot(int32_T n, const real_T x[21], int32_T ix0, const real_T
                        y[21], int32_T iy0);
  void full_loo_updatePenaltyParam_p43(s6ICcRyulWOFjNCN0ll7VsE_full__T *obj,
    real_T fval, const real_T eq_workspace[6], int32_T mEq, int32_T sqpiter,
    real_T qpval, const real_T x[21], int32_T iReg0, int32_T nRegularized);
  void removeActiveSlackLowerBounds_p(int32_T nActiveLBArtificial,
    s2CPTVnVyv153Hb6bxlki6F_full__T *TrialState, const
    sH6xx18cQHI5sgA7Ajla4nE_full__T *WorkingSet, sH6xx18cQHI5sgA7Ajla4nE_full__T
    *b_WorkingSet);
  void full_loop_setQuadratic_p(sJdVcLKPgejLYHLePKb6F6D_full__T *obj, int32_T
    NumVars);
  int32_T full_loop_ixamax_p4(int32_T n, const real_T x[19]);
  int32_T full_loop_ixamax_p(int32_T n, const real_T x[21]);
  void full_loop_relaxed_p(const real_T Hessian[64], const real_T grad[21],
    const s2CPTVnVyv153Hb6bxlki6F_full__T *TrialState,
    s6ICcRyulWOFjNCN0ll7VsE_full__T *MeritFunction, const
    sVTYnQ9ljvmk9dLse9XvTT_full_l_T *memspace, const
    sH6xx18cQHI5sgA7Ajla4nE_full__T *WorkingSet, const
    snaQeDJ4fX7UykrKyr5M8jC_full__T *QRManager, const
    snl99C5je2zMbU5SzygoX6F_full__T *CholManager, const
    sJdVcLKPgejLYHLePKb6F6D_full__T *QPObjective,
    s1TgE9KstXgkd2qJxO1bF4F_full__T *qpoptions, real_T b_Hessian[64],
    s2CPTVnVyv153Hb6bxlki6F_full__T *b_TrialState,
    sVTYnQ9ljvmk9dLse9XvTT_full_l_T *b_memspace, sH6xx18cQHI5sgA7Ajla4nE_full__T
    *b_WorkingSet, snaQeDJ4fX7UykrKyr5M8jC_full__T *b_QRManager,
    snl99C5je2zMbU5SzygoX6F_full__T *b_CholManager,
    sJdVcLKPgejLYHLePKb6F6D_full__T *b_QPObjective);
  void full_loop_BFGSReset(const real_T Hessian[64], const real_T grad[21],
    const real_T searchDir[21], real_T b_Hessian[64]);
  void full_loop_step_p4(int32_T STEP_TYPE, const real_T Hessian[64],
    s2CPTVnVyv153Hb6bxlki6F_full__T *TrialState, s6ICcRyulWOFjNCN0ll7VsE_full__T
    *MeritFunction, sVTYnQ9ljvmk9dLse9XvTT_full_l_T *memspace,
    sH6xx18cQHI5sgA7Ajla4nE_full__T *WorkingSet, snaQeDJ4fX7UykrKyr5M8jC_full__T
    *QRManager, snl99C5je2zMbU5SzygoX6F_full__T *CholManager,
    sJdVcLKPgejLYHLePKb6F6D_full__T *QPObjective,
    s1TgE9KstXgkd2qJxO1bF4F_full__T *qpoptions, boolean_T *stepSuccess, int32_T *
    b_STEP_TYPE, real_T b_Hessian[64]);
  void full_loop_evalObjAndConstr_p(KickIn_full_loop_T
    **obj_objfun_tunableEnvironment, const real_T x[8], real_T *fval, int32_T
    *status);
  void full_computeLinearResiduals_p43(const real_T x[8], int32_T nVar, real_T
    workspaceEq[6], int32_T mLinEq, const real_T AeqT[126], const real_T beq[6]);
  real_T full_loop_computeMeritFcn(real_T obj_penaltyParam, real_T fval, const
    real_T Ceq_workspace[6], int32_T mEq, boolean_T evalWellDefined);
  void full_loop_linesearch_p(boolean_T evalWellDefined, const real_T beq[6],
    const sH6xx18cQHI5sgA7Ajla4nE_full__T *WorkingSet,
    s2CPTVnVyv153Hb6bxlki6F_full__T *TrialState, const
    s6ICcRyulWOFjNCN0ll7VsE_full__T *MeritFunction, const
    s_8jIp3wBW8W9AJZ7lDTkICE_full_T FcnEvaluator, boolean_T socTaken, real_T
    *alpha, int32_T *exitflag, boolean_T *b_evalWellDefined);
  void full_loop_revertSolution(const s2CPTVnVyv153Hb6bxlki6F_full__T *obj,
    s2CPTVnVyv153Hb6bxlki6F_full__T *b_obj);
  real_T full_loo_computePrimalFeasError(int32_T mLinEq, const real_T cEq[6]);
  void full_loop_computeGradLag_p(const real_T workspace[441], int32_T nVar,
    const real_T grad[21], int32_T mEq, const real_T AeqTrans[126], const
    int32_T finiteLB[21], int32_T mLB, const real_T lambda[19], real_T
    b_workspace[441]);
  void full_loo_computeDualFeasError_p(int32_T nVar, const real_T gradLag[441],
    boolean_T *gradOK, real_T *val);
  boolean_T full_loop_isDeltaXTooSmall(const real_T xCurrent[8], const real_T
    delta_x[21], int32_T nVar);
  void full_loop_computeLambdaLSQ_p(int32_T nVar, int32_T mConstr, const
    snaQeDJ4fX7UykrKyr5M8jC_full__T *QRManager, const real_T ATwset[399], const
    real_T grad[21], real_T lambdaLSQ[19], const real_T workspace[441],
    snaQeDJ4fX7UykrKyr5M8jC_full__T *b_QRManager, real_T b_workspace[441]);
  void full_loop_test_exit_p43(boolean_T Flags_fevalOK, boolean_T
    Flags_stepAccepted, boolean_T Flags_failedLineSearch, int32_T Flags_stepType,
    sVTYnQ9ljvmk9dLse9XvTT_full_l_T *memspace, s6ICcRyulWOFjNCN0ll7VsE_full__T
    *MeritFunction, const sH6xx18cQHI5sgA7Ajla4nE_full__T *WorkingSet, const
    s2CPTVnVyv153Hb6bxlki6F_full__T *TrialState, snaQeDJ4fX7UykrKyr5M8jC_full__T
    *QRManager, s7RdrPWkr8UPAUyTdDJkLaG_full__T *b_Flags,
    s2CPTVnVyv153Hb6bxlki6F_full__T *b_TrialState);
  void full_loop_computeDeltaLag_p(int32_T nVar, real_T workspace[21], const
    real_T grad[21], const real_T grad_old[21]);
  void full_loop_BFGSUpdate_p(int32_T nvar, const real_T Bk[64], const real_T
    sk[21], real_T yk[21], const real_T workspace[441], boolean_T *success,
    real_T b_Bk[64], real_T b_workspace[441]);
  void full_loop_driver_p4(const real_T beq[6], s2CPTVnVyv153Hb6bxlki6F_full__T *
    TrialState, const s6ICcRyulWOFjNCN0ll7VsE_full__T *MeritFunction,
    s_8jIp3wBW8W9AJZ7lDTkICE_full_T FcnEvaluator,
    s_iyYBPziYRv853Phg0mcgOD_full_T *FiniteDifferences, const
    sVTYnQ9ljvmk9dLse9XvTT_full_l_T *memspace, const
    sH6xx18cQHI5sgA7Ajla4nE_full__T *WorkingSet, const
    snaQeDJ4fX7UykrKyr5M8jC_full__T *QRManager, sJdVcLKPgejLYHLePKb6F6D_full__T *
    QPObjective, real_T Hessian[64], s6ICcRyulWOFjNCN0ll7VsE_full__T
    *b_MeritFunction, s_8jIp3wBW8W9AJZ7lDTkICE_full_T *b_FcnEvaluator,
    sVTYnQ9ljvmk9dLse9XvTT_full_l_T *b_memspace, sH6xx18cQHI5sgA7Ajla4nE_full__T
    *b_WorkingSet, snaQeDJ4fX7UykrKyr5M8jC_full__T *b_QRManager,
    snl99C5je2zMbU5SzygoX6F_full__T *CholManager);
  void full_loop_fmincon(KickIn_full_loop_T **fun_tunableEnvironment, const
    real_T x0[8], const real_T Aeq[48], const real_T beq[6], real_T x[8]);
  void full_loop_xgetrf(const real_T A[400], real_T b_A[400], int32_T ipiv[20],
                        int32_T *info);
  void full_loop_lusolve(const real_T A[400], const real_T B[400], real_T X[400]);
  void full_lo_PadeApproximantOfDegree(const real_T A[400], uint8_T m, real_T F
    [400]);
  void full_loop_expm(real_T A[400], real_T F[400]);
  void full_loop_TrimPlant_stepImpl(TrimPlant_full_loop_T *b_this, const real_T
    u[8], real_T Ts, const real_T y[12], real_T A[144], real_T B[96], real_T C
    [144], real_T D[96], real_T U[8], real_T Y[12], real_T X[12], real_T DX[12]);
  void full_loop_SystemCore_step(TrimPlant_full_loop_T *obj, const real_T
    varargin_1[8], real_T varargin_2, const real_T varargin_3[12], real_T
    varargout_1[144], real_T varargout_2[96], real_T varargout_3[144], real_T
    varargout_4[96], real_T varargout_5[8], real_T varargout_6[12], real_T
    varargout_7[12], real_T varargout_8[12]);
  void full_loop_mpc_plantupdate(const real_T a[144], real_T b[96], const real_T
    c[144], real_T b_A[400], real_T b_B[580], real_T b_C[240], const real_T b_D
    [348], const real_T b_mvindex[8], const real_T b_myindex[12], const real_T
    b_Uscale[8], const real_T b_Yscale[12], real_T Bu[160], real_T Bv[20],
    real_T Cm[240], real_T Dv[12], real_T Dvm[12], real_T QQ[400], real_T RR[144],
    real_T NN[240]);
  real_T full_loop_mod_id(real_T x);
  real_T full_loop_mod_i(real_T x);
  void full_loop_mpc_updateFromNominal(real_T b_Mlim[4], const real_T b_Mrows[4],
    const real_T U0[8], const real_T b_Uscale[8], const real_T old_mvoff[8],
    const real_T b_mvindex[8], real_T b_utarget[80], const real_T Y0[12], const
    real_T b_Yscale[12], const real_T old_yoff[12], const real_T b_myindex[12],
    const real_T X0[12], real_T b_xoff[20], const real_T DX0[12], real_T Bv[220],
    real_T new_mvoff[8], real_T new_yoff[12], real_T new_myoff[12]);
  void full_loop_mpcblock_refmd(const real_T ref[12], const real_T b_yoff[12],
    const real_T b_RYscale[12], real_T rseq[120], real_T vseq[11], real_T *v);
  void full_loop_eye(real_T b_I[144]);
  void full_loop_mpc_constraintcoef(const real_T b_A[400], const real_T Bu[1760],
    const real_T Bv[220], const real_T b_C[240], const real_T Dv[132], const
    real_T b_Jm[1280], real_T b_SuJm[1920], real_T b_Sx[2400], real_T b_Su1[960],
    real_T b_Hv[1320]);
  void full_loop_eye_c(real_T b_I[64]);
  void full_loop_kron(const real_T b_A[100], const real_T b_B[64], real_T K[6400]);
  void full_loop_WtMult(const real_T W[8], const real_T M[1280], real_T nwt,
                        real_T WM[1280]);
  void full_loop_mpc_calculatehessian(const real_T b_Wy[12], const real_T b_Wu[8],
    const real_T b_Wdu[8], const real_T b_SuJm[1920], const real_T I2Jm[1280],
    const real_T b_Jm[1280], const real_T b_I1[640], const real_T b_Su1[960],
    const real_T b_Sx[2400], const real_T b_Hv[1320], real_T nmv, real_T b_ny,
    real_T b_H[256], real_T b_Ku1[128], real_T b_Kut[1280], real_T b_Kx[320],
    real_T b_Kv[176], real_T b_Kr[1920]);
  int32_T full_loop_xpotrf_j(real_T b_A[289]);
  void full_loop_diag(const real_T v[289], real_T d[17]);
  real_T full_loop_norm(const real_T x[289]);
  void full_loop_eye_cb(real_T b_I[289]);
  void full_loop_mpc_checkhessian(real_T b_H[289], real_T L[289], real_T *BadH);
  void full_loop_eye_cbt(real_T b_I[289]);
  void full_loop_trisolve(const real_T b_A[289], real_T b_B[289]);
  void full_loop_linsolve(const real_T b_A[289], const real_T b_B[289], real_T
    b_C[289]);
  void full_loop_Unconstrained(const real_T b_Hinv[289], const real_T f[17],
    real_T x[17], int16_T n);
  real_T full_loop_norm_i(const real_T x[17]);
  void full_loop_abs(const real_T x[17], real_T y[17]);
  void full_loop_abs_d(const real_T x[4], real_T y[4]);
  real_T full_loop_xnrm2_a(int32_T n, const real_T x[289], int32_T ix0);
  real_T full_loop_xzlarfg_j(int32_T n, real_T *alpha1, real_T x[289], int32_T
    ix0);
  void full_loop_xgemv_pz(int32_T m, int32_T n, const real_T b_A[289], int32_T
    ia0, const real_T x[289], int32_T ix0, real_T y[17]);
  void full_loop_xgerc(int32_T m, int32_T n, real_T alpha1, int32_T ix0, const
                       real_T y[17], real_T b_A[289], int32_T ia0);
  void full_loop_xzlarf_d(int32_T m, int32_T n, int32_T iv0, real_T tau, real_T
    b_C[289], int32_T ic0, real_T work[17]);
  void full_loop_qrf_l(real_T b_A[289], int32_T ia0, int32_T m, int32_T n,
                       int32_T nfxd, real_T tau[17]);
  void full_loop_xgeqrf_l(real_T b_A[289], real_T tau[17]);
  void full_loop_qr(const real_T b_A[289], real_T Q[289], real_T R[289]);
  real_T full_loop_KWIKfactor(const real_T b_Ac[68], const int16_T iC[4],
    int16_T nA, const real_T b_Linv[289], real_T RLinv[289], real_T b_D[289],
    real_T b_H[289], int16_T n);
  void full_loop_DropConstraint(int16_T kDrop, int16_T iA[4], int16_T *nA,
    int16_T iC[4]);
  void full_loop_qpkwik(const real_T b_Linv[289], const real_T b_Hinv[289],
                        const real_T f[17], const real_T b_Ac[68], const real_T
                        b[4], int16_T iA[4], int16_T maxiter, real_T FeasTol,
                        real_T x[17], real_T lambda[4], real_T *status);
  void full_loop_mpc_solveQP(const real_T xQP[20], const real_T b_Kx[320], const
    real_T b_Kr[1920], const real_T rseq[120], const real_T b_Ku1[128], const
    real_T old_u[8], const real_T b_Kv[176], const real_T vseq[11], const real_T
    b_Kut[1280], const real_T b_utarget[80], const real_T b_Linv[289], const
    real_T b_Hinv[289], const real_T b_Ac[68], const real_T Bc[4], boolean_T iA
    [4], real_T zopt[17], real_T f[17], real_T *status);
  void full_loop_mpcblock_optimizer(const real_T rseq[120], const real_T vseq[11],
    const real_T umin[8], const real_T umax[8], const real_T x[20], const real_T
    old_u[8], const boolean_T iA[4], const real_T b_Mlim[4], real_T b_Mx[80],
    real_T b_Mu1[32], real_T b_Mv[44], const real_T b_utarget[80], const real_T
    b_uoff[8], real_T b_H[289], real_T b_Ac[68], const real_T b_Wy[12], const
    real_T b_Wdu[8], const real_T b_Jm[1280], const real_T b_Wu[8], const real_T
    b_I1[640], const real_T b_A[400], const real_T Bu[1760], const real_T Bv[220],
    const real_T b_C[240], const real_T Dv[132], const real_T b_Mrows[4], real_T
    u[8], real_T useq[88], real_T *status, boolean_T iAout[4]);
  void rt_mrdivide_U1d1x3_U2d_9vOrDY_p(const real_T u0[3], const real_T u1[9],
    real_T y[3]);
  void matlabCodegenHandle_matlabCodeg(ros_slros_internal_block_Publ_T *obj);

  /* Continuous states update member function*/
  void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si );

  /* Derivatives member function */
  void full_loop_derivatives();
};

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S1>/Scope' : Unused code path elimination
 * Block '<S1>/Scope1' : Unused code path elimination
 * Block '<S1>/Scope2' : Unused code path elimination
 * Block '<S1>/Scope3' : Unused code path elimination
 * Block '<S1>/Scope4' : Unused code path elimination
 * Block '<S24>/Unit Conversion' : Unused code path elimination
 * Block '<S25>/Unit Conversion' : Unused code path elimination
 * Block '<S15>/Random Number' : Unused code path elimination
 * Block '<S15>/Scope1' : Unused code path elimination
 * Block '<S15>/Scope2' : Unused code path elimination
 * Block '<S15>/Scope4' : Unused code path elimination
 * Block '<S18>/Scope' : Unused code path elimination
 * Block '<S70>/Data Type Conversion22' : Unused code path elimination
 * Block '<S70>/Data Type Conversion23' : Unused code path elimination
 * Block '<S71>/Matrix Dimension Check' : Unused code path elimination
 * Block '<S72>/Matrix Dimension Check' : Unused code path elimination
 * Block '<S73>/Matrix Dimension Check' : Unused code path elimination
 * Block '<S74>/Matrix Dimension Check' : Unused code path elimination
 * Block '<S75>/Matrix Dimension Check' : Unused code path elimination
 * Block '<S76>/Matrix Dimension Check' : Unused code path elimination
 * Block '<S77>/Matrix Dimension Check' : Unused code path elimination
 * Block '<S78>/Matrix Dimension Check' : Unused code path elimination
 * Block '<S79>/Matrix Dimension Check' : Unused code path elimination
 * Block '<S80>/Matrix Dimension Check' : Unused code path elimination
 * Block '<S81>/Matrix Dimension Check' : Unused code path elimination
 * Block '<S82>/Matrix Dimension Check' : Unused code path elimination
 * Block '<S83>/Matrix Dimension Check' : Unused code path elimination
 * Block '<S84>/Matrix Dimension Check' : Unused code path elimination
 * Block '<S85>/Matrix Dimension Check' : Unused code path elimination
 * Block '<S86>/Matrix Dimension Check' : Unused code path elimination
 * Block '<S87>/Vector Dimension Check' : Unused code path elimination
 * Block '<S88>/Vector Dimension Check' : Unused code path elimination
 * Block '<S89>/Vector Dimension Check' : Unused code path elimination
 * Block '<S90>/Vector Dimension Check' : Unused code path elimination
 * Block '<S91>/Vector Dimension Check' : Unused code path elimination
 * Block '<S92>/Vector Dimension Check' : Unused code path elimination
 * Block '<S93>/Vector Dimension Check' : Unused code path elimination
 * Block '<S94>/Vector Dimension Check' : Unused code path elimination
 * Block '<S95>/Vector Dimension Check' : Unused code path elimination
 * Block '<S96>/Vector Dimension Check' : Unused code path elimination
 * Block '<S97>/Vector Dimension Check' : Unused code path elimination
 * Block '<S70>/useq_scale' : Unused code path elimination
 * Block '<S70>/useq_scale1' : Unused code path elimination
 * Block '<S70>/ym_zero' : Unused code path elimination
 * Block '<S67>/m_zero' : Unused code path elimination
 * Block '<S67>/p_zero' : Unused code path elimination
 * Block '<S4>/Display' : Unused code path elimination
 * Block '<S4>/Scope2' : Unused code path elimination
 * Block '<S4>/Scope3' : Unused code path elimination
 * Block '<S5>/Memory' : Unused code path elimination
 * Block '<S5>/Memory1' : Unused code path elimination
 * Block '<S112>/Product' : Unused code path elimination
 * Block '<S112>/Product1' : Unused code path elimination
 * Block '<S112>/Product2' : Unused code path elimination
 * Block '<S112>/Product3' : Unused code path elimination
 * Block '<S117>/Product' : Unused code path elimination
 * Block '<S117>/Product1' : Unused code path elimination
 * Block '<S117>/Product2' : Unused code path elimination
 * Block '<S117>/Product3' : Unused code path elimination
 * Block '<S117>/Sum' : Unused code path elimination
 * Block '<S116>/sqrt' : Unused code path elimination
 * Block '<S113>/Constant' : Unused code path elimination
 * Block '<S113>/Gain' : Unused code path elimination
 * Block '<S113>/Gain1' : Unused code path elimination
 * Block '<S113>/Gain2' : Unused code path elimination
 * Block '<S113>/Product' : Unused code path elimination
 * Block '<S113>/Product1' : Unused code path elimination
 * Block '<S113>/Product2' : Unused code path elimination
 * Block '<S113>/Product3' : Unused code path elimination
 * Block '<S113>/Product4' : Unused code path elimination
 * Block '<S113>/Product5' : Unused code path elimination
 * Block '<S113>/Product6' : Unused code path elimination
 * Block '<S113>/Product7' : Unused code path elimination
 * Block '<S113>/Product8' : Unused code path elimination
 * Block '<S113>/Sum' : Unused code path elimination
 * Block '<S113>/Sum1' : Unused code path elimination
 * Block '<S113>/Sum2' : Unused code path elimination
 * Block '<S113>/Sum3' : Unused code path elimination
 * Block '<S114>/Constant' : Unused code path elimination
 * Block '<S114>/Gain' : Unused code path elimination
 * Block '<S114>/Gain1' : Unused code path elimination
 * Block '<S114>/Gain2' : Unused code path elimination
 * Block '<S114>/Product' : Unused code path elimination
 * Block '<S114>/Product1' : Unused code path elimination
 * Block '<S114>/Product2' : Unused code path elimination
 * Block '<S114>/Product3' : Unused code path elimination
 * Block '<S114>/Product4' : Unused code path elimination
 * Block '<S114>/Product5' : Unused code path elimination
 * Block '<S114>/Product6' : Unused code path elimination
 * Block '<S114>/Product7' : Unused code path elimination
 * Block '<S114>/Product8' : Unused code path elimination
 * Block '<S114>/Sum' : Unused code path elimination
 * Block '<S114>/Sum1' : Unused code path elimination
 * Block '<S114>/Sum2' : Unused code path elimination
 * Block '<S114>/Sum3' : Unused code path elimination
 * Block '<S115>/Constant' : Unused code path elimination
 * Block '<S115>/Gain' : Unused code path elimination
 * Block '<S115>/Gain1' : Unused code path elimination
 * Block '<S115>/Gain2' : Unused code path elimination
 * Block '<S115>/Product' : Unused code path elimination
 * Block '<S115>/Product1' : Unused code path elimination
 * Block '<S115>/Product2' : Unused code path elimination
 * Block '<S115>/Product3' : Unused code path elimination
 * Block '<S115>/Product4' : Unused code path elimination
 * Block '<S115>/Product5' : Unused code path elimination
 * Block '<S115>/Product6' : Unused code path elimination
 * Block '<S115>/Product7' : Unused code path elimination
 * Block '<S115>/Product8' : Unused code path elimination
 * Block '<S115>/Sum' : Unused code path elimination
 * Block '<S115>/Sum1' : Unused code path elimination
 * Block '<S115>/Sum2' : Unused code path elimination
 * Block '<S115>/Sum3' : Unused code path elimination
 * Block '<S5>/Scope' : Unused code path elimination
 * Block '<S5>/Scope1' : Unused code path elimination
 * Block '<S5>/Scope10' : Unused code path elimination
 * Block '<S5>/Scope2' : Unused code path elimination
 * Block '<S5>/Scope3' : Unused code path elimination
 * Block '<S5>/Scope4' : Unused code path elimination
 * Block '<S5>/Scope5' : Unused code path elimination
 * Block '<S5>/Scope6' : Unused code path elimination
 * Block '<S5>/Scope7' : Unused code path elimination
 * Block '<S5>/Scope8' : Unused code path elimination
 * Block '<S5>/Scope9' : Unused code path elimination
 * Block '<S5>/Sum' : Unused code path elimination
 * Block '<S5>/Sum1' : Unused code path elimination
 * Block '<S6>/Memory1' : Unused code path elimination
 * Block '<S6>/Scope' : Unused code path elimination
 * Block '<S6>/Scope1' : Unused code path elimination
 * Block '<S6>/Scope2' : Unused code path elimination
 * Block '<S6>/Scope3' : Unused code path elimination
 * Block '<S40>/Reshape (9) to [3x3] column-major' : Reshape block reduction
 * Block '<S53>/Reshape1' : Reshape block reduction
 * Block '<S53>/Reshape2' : Reshape block reduction
 * Block '<S54>/Reshape1' : Reshape block reduction
 * Block '<S54>/Reshape2' : Reshape block reduction
 * Block '<S20>/Reshape' : Reshape block reduction
 * Block '<S20>/Reshape1' : Reshape block reduction
 * Block '<S23>/Unit Conversion' : Eliminated nontunable gain of 1
 * Block '<S26>/Reshape1' : Reshape block reduction
 * Block '<S26>/Reshape2' : Reshape block reduction
 * Block '<S70>/Data Type Conversion10' : Eliminate redundant data type conversion
 * Block '<S70>/Data Type Conversion11' : Eliminate redundant data type conversion
 * Block '<S70>/Data Type Conversion12' : Eliminate redundant data type conversion
 * Block '<S70>/Data Type Conversion13' : Eliminate redundant data type conversion
 * Block '<S70>/Data Type Conversion14' : Eliminate redundant data type conversion
 * Block '<S70>/Data Type Conversion15' : Eliminate redundant data type conversion
 * Block '<S70>/Data Type Conversion16' : Eliminate redundant data type conversion
 * Block '<S70>/Data Type Conversion17' : Eliminate redundant data type conversion
 * Block '<S70>/Data Type Conversion18' : Eliminate redundant data type conversion
 * Block '<S70>/Data Type Conversion19' : Eliminate redundant data type conversion
 * Block '<S70>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S70>/Data Type Conversion20' : Eliminate redundant data type conversion
 * Block '<S70>/Data Type Conversion21' : Eliminate redundant data type conversion
 * Block '<S70>/Data Type Conversion3' : Eliminate redundant data type conversion
 * Block '<S70>/Data Type Conversion4' : Eliminate redundant data type conversion
 * Block '<S70>/Data Type Conversion5' : Eliminate redundant data type conversion
 * Block '<S70>/Data Type Conversion6' : Eliminate redundant data type conversion
 * Block '<S70>/Data Type Conversion7' : Eliminate redundant data type conversion
 * Block '<S70>/Data Type Conversion8' : Eliminate redundant data type conversion
 * Block '<S70>/Data Type Conversion9' : Eliminate redundant data type conversion
 * Block '<S70>/E Conversion' : Eliminate redundant data type conversion
 * Block '<S70>/F Conversion' : Eliminate redundant data type conversion
 * Block '<S70>/G Conversion' : Eliminate redundant data type conversion
 * Block '<S70>/Reshape' : Reshape block reduction
 * Block '<S70>/Reshape1' : Reshape block reduction
 * Block '<S70>/Reshape2' : Reshape block reduction
 * Block '<S70>/Reshape3' : Reshape block reduction
 * Block '<S70>/Reshape4' : Reshape block reduction
 * Block '<S70>/Reshape5' : Reshape block reduction
 * Block '<S70>/S Conversion' : Eliminate redundant data type conversion
 * Block '<S70>/mo or x Conversion' : Eliminate redundant data type conversion
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'full_loop'
 * '<S1>'   : 'full_loop/Plot values'
 * '<S2>'   : 'full_loop/Send to Gazebo'
 * '<S3>'   : 'full_loop/Subsystem AUVPlant'
 * '<S4>'   : 'full_loop/Subsystem Controller'
 * '<S5>'   : 'full_loop/Subsystem ProcNav'
 * '<S6>'   : 'full_loop/Subsystem Trajectory'
 * '<S7>'   : 'full_loop/Send to Gazebo/   '
 * '<S8>'   : 'full_loop/Send to Gazebo/MATLAB Function'
 * '<S9>'   : 'full_loop/Send to Gazebo/Publish'
 * '<S10>'  : 'full_loop/Send to Gazebo/Quaternion Inverse'
 * '<S11>'  : 'full_loop/Send to Gazebo/Quaternion Inverse/Quaternion Conjugate'
 * '<S12>'  : 'full_loop/Send to Gazebo/Quaternion Inverse/Quaternion Norm'
 * '<S13>'  : 'full_loop/Subsystem AUVPlant/6DOF (Euler Angles)'
 * '<S14>'  : 'full_loop/Subsystem AUVPlant/Forces and torques'
 * '<S15>'  : 'full_loop/Subsystem AUVPlant/Post Prossessing'
 * '<S16>'  : 'full_loop/Subsystem AUVPlant/Pre Prossessing'
 * '<S17>'  : 'full_loop/Subsystem AUVPlant/Sensor Noise'
 * '<S18>'  : 'full_loop/Subsystem AUVPlant/Wave'
 * '<S19>'  : 'full_loop/Subsystem AUVPlant/6DOF (Euler Angles)/Calculate DCM & Euler Angles'
 * '<S20>'  : 'full_loop/Subsystem AUVPlant/6DOF (Euler Angles)/Calculate omega_dot'
 * '<S21>'  : 'full_loop/Subsystem AUVPlant/6DOF (Euler Angles)/Determine Force,  Mass & Inertia'
 * '<S22>'  : 'full_loop/Subsystem AUVPlant/6DOF (Euler Angles)/Vbxw'
 * '<S23>'  : 'full_loop/Subsystem AUVPlant/6DOF (Euler Angles)/Velocity Conversion'
 * '<S24>'  : 'full_loop/Subsystem AUVPlant/6DOF (Euler Angles)/Velocity Conversion1'
 * '<S25>'  : 'full_loop/Subsystem AUVPlant/6DOF (Euler Angles)/Velocity Conversion2'
 * '<S26>'  : 'full_loop/Subsystem AUVPlant/6DOF (Euler Angles)/transform to Inertial axes '
 * '<S27>'  : 'full_loop/Subsystem AUVPlant/6DOF (Euler Angles)/Calculate DCM & Euler Angles/Quaternions to  Direction Cosine Matrix'
 * '<S28>'  : 'full_loop/Subsystem AUVPlant/6DOF (Euler Angles)/Calculate DCM & Euler Angles/Quaternions to Rotation Angles'
 * '<S29>'  : 'full_loop/Subsystem AUVPlant/6DOF (Euler Angles)/Calculate DCM & Euler Angles/Rotation Angles to Quaternions'
 * '<S30>'  : 'full_loop/Subsystem AUVPlant/6DOF (Euler Angles)/Calculate DCM & Euler Angles/qdot'
 * '<S31>'  : 'full_loop/Subsystem AUVPlant/6DOF (Euler Angles)/Calculate DCM & Euler Angles/Quaternions to  Direction Cosine Matrix/A11'
 * '<S32>'  : 'full_loop/Subsystem AUVPlant/6DOF (Euler Angles)/Calculate DCM & Euler Angles/Quaternions to  Direction Cosine Matrix/A12'
 * '<S33>'  : 'full_loop/Subsystem AUVPlant/6DOF (Euler Angles)/Calculate DCM & Euler Angles/Quaternions to  Direction Cosine Matrix/A13'
 * '<S34>'  : 'full_loop/Subsystem AUVPlant/6DOF (Euler Angles)/Calculate DCM & Euler Angles/Quaternions to  Direction Cosine Matrix/A21'
 * '<S35>'  : 'full_loop/Subsystem AUVPlant/6DOF (Euler Angles)/Calculate DCM & Euler Angles/Quaternions to  Direction Cosine Matrix/A22'
 * '<S36>'  : 'full_loop/Subsystem AUVPlant/6DOF (Euler Angles)/Calculate DCM & Euler Angles/Quaternions to  Direction Cosine Matrix/A23'
 * '<S37>'  : 'full_loop/Subsystem AUVPlant/6DOF (Euler Angles)/Calculate DCM & Euler Angles/Quaternions to  Direction Cosine Matrix/A31'
 * '<S38>'  : 'full_loop/Subsystem AUVPlant/6DOF (Euler Angles)/Calculate DCM & Euler Angles/Quaternions to  Direction Cosine Matrix/A32'
 * '<S39>'  : 'full_loop/Subsystem AUVPlant/6DOF (Euler Angles)/Calculate DCM & Euler Angles/Quaternions to  Direction Cosine Matrix/A33'
 * '<S40>'  : 'full_loop/Subsystem AUVPlant/6DOF (Euler Angles)/Calculate DCM & Euler Angles/Quaternions to  Direction Cosine Matrix/Create 3x3 Matrix'
 * '<S41>'  : 'full_loop/Subsystem AUVPlant/6DOF (Euler Angles)/Calculate DCM & Euler Angles/Quaternions to  Direction Cosine Matrix/Quaternion Normalize'
 * '<S42>'  : 'full_loop/Subsystem AUVPlant/6DOF (Euler Angles)/Calculate DCM & Euler Angles/Quaternions to  Direction Cosine Matrix/Quaternion Normalize/Quaternion Modulus'
 * '<S43>'  : 'full_loop/Subsystem AUVPlant/6DOF (Euler Angles)/Calculate DCM & Euler Angles/Quaternions to  Direction Cosine Matrix/Quaternion Normalize/Quaternion Modulus/Quaternion Norm'
 * '<S44>'  : 'full_loop/Subsystem AUVPlant/6DOF (Euler Angles)/Calculate DCM & Euler Angles/Quaternions to Rotation Angles/Angle Calculation'
 * '<S45>'  : 'full_loop/Subsystem AUVPlant/6DOF (Euler Angles)/Calculate DCM & Euler Angles/Quaternions to Rotation Angles/Quaternion Normalize'
 * '<S46>'  : 'full_loop/Subsystem AUVPlant/6DOF (Euler Angles)/Calculate DCM & Euler Angles/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input'
 * '<S47>'  : 'full_loop/Subsystem AUVPlant/6DOF (Euler Angles)/Calculate DCM & Euler Angles/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input/If Action Subsystem'
 * '<S48>'  : 'full_loop/Subsystem AUVPlant/6DOF (Euler Angles)/Calculate DCM & Euler Angles/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input/If Action Subsystem1'
 * '<S49>'  : 'full_loop/Subsystem AUVPlant/6DOF (Euler Angles)/Calculate DCM & Euler Angles/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input/If Action Subsystem2'
 * '<S50>'  : 'full_loop/Subsystem AUVPlant/6DOF (Euler Angles)/Calculate DCM & Euler Angles/Quaternions to Rotation Angles/Quaternion Normalize/Quaternion Modulus'
 * '<S51>'  : 'full_loop/Subsystem AUVPlant/6DOF (Euler Angles)/Calculate DCM & Euler Angles/Quaternions to Rotation Angles/Quaternion Normalize/Quaternion Modulus/Quaternion Norm'
 * '<S52>'  : 'full_loop/Subsystem AUVPlant/6DOF (Euler Angles)/Calculate omega_dot/3x3 Cross Product'
 * '<S53>'  : 'full_loop/Subsystem AUVPlant/6DOF (Euler Angles)/Calculate omega_dot/I x w'
 * '<S54>'  : 'full_loop/Subsystem AUVPlant/6DOF (Euler Angles)/Calculate omega_dot/I x w1'
 * '<S55>'  : 'full_loop/Subsystem AUVPlant/6DOF (Euler Angles)/Calculate omega_dot/3x3 Cross Product/Subsystem'
 * '<S56>'  : 'full_loop/Subsystem AUVPlant/6DOF (Euler Angles)/Calculate omega_dot/3x3 Cross Product/Subsystem1'
 * '<S57>'  : 'full_loop/Subsystem AUVPlant/6DOF (Euler Angles)/Vbxw/Subsystem'
 * '<S58>'  : 'full_loop/Subsystem AUVPlant/6DOF (Euler Angles)/Vbxw/Subsystem1'
 * '<S59>'  : 'full_loop/Subsystem AUVPlant/Post Prossessing/Subsystem'
 * '<S60>'  : 'full_loop/Subsystem AUVPlant/Post Prossessing/Subsystem/MATLAB Function'
 * '<S61>'  : 'full_loop/Subsystem AUVPlant/Post Prossessing/Subsystem/Quaternion Inverse'
 * '<S62>'  : 'full_loop/Subsystem AUVPlant/Post Prossessing/Subsystem/Rotation Angles to Quaternions'
 * '<S63>'  : 'full_loop/Subsystem AUVPlant/Post Prossessing/Subsystem/Quaternion Inverse/Quaternion Conjugate'
 * '<S64>'  : 'full_loop/Subsystem AUVPlant/Post Prossessing/Subsystem/Quaternion Inverse/Quaternion Norm'
 * '<S65>'  : 'full_loop/Subsystem AUVPlant/Sensor Noise/Band-Limited White Noise'
 * '<S66>'  : 'full_loop/Subsystem AUVPlant/Sensor Noise/Band-Limited White Noise1'
 * '<S67>'  : 'full_loop/Subsystem Controller/Adaptive MPC Controller'
 * '<S68>'  : 'full_loop/Subsystem Controller/Bus2Mux'
 * '<S69>'  : 'full_loop/Subsystem Controller/check'
 * '<S70>'  : 'full_loop/Subsystem Controller/Adaptive MPC Controller/MPC'
 * '<S71>'  : 'full_loop/Subsystem Controller/Adaptive MPC Controller/MPC/MPC Matrix Signal Check'
 * '<S72>'  : 'full_loop/Subsystem Controller/Adaptive MPC Controller/MPC/MPC Matrix Signal Check A'
 * '<S73>'  : 'full_loop/Subsystem Controller/Adaptive MPC Controller/MPC/MPC Matrix Signal Check B'
 * '<S74>'  : 'full_loop/Subsystem Controller/Adaptive MPC Controller/MPC/MPC Matrix Signal Check C'
 * '<S75>'  : 'full_loop/Subsystem Controller/Adaptive MPC Controller/MPC/MPC Matrix Signal Check D'
 * '<S76>'  : 'full_loop/Subsystem Controller/Adaptive MPC Controller/MPC/MPC Matrix Signal Check DX'
 * '<S77>'  : 'full_loop/Subsystem Controller/Adaptive MPC Controller/MPC/MPC Matrix Signal Check U'
 * '<S78>'  : 'full_loop/Subsystem Controller/Adaptive MPC Controller/MPC/MPC Matrix Signal Check X'
 * '<S79>'  : 'full_loop/Subsystem Controller/Adaptive MPC Controller/MPC/MPC Matrix Signal Check Y'
 * '<S80>'  : 'full_loop/Subsystem Controller/Adaptive MPC Controller/MPC/MPC Matrix Signal Check1'
 * '<S81>'  : 'full_loop/Subsystem Controller/Adaptive MPC Controller/MPC/MPC Matrix Signal Check2'
 * '<S82>'  : 'full_loop/Subsystem Controller/Adaptive MPC Controller/MPC/MPC Preview Signal Check'
 * '<S83>'  : 'full_loop/Subsystem Controller/Adaptive MPC Controller/MPC/MPC Preview Signal Check1'
 * '<S84>'  : 'full_loop/Subsystem Controller/Adaptive MPC Controller/MPC/MPC Preview Signal Check2'
 * '<S85>'  : 'full_loop/Subsystem Controller/Adaptive MPC Controller/MPC/MPC Preview Signal Check3'
 * '<S86>'  : 'full_loop/Subsystem Controller/Adaptive MPC Controller/MPC/MPC Preview Signal Check4'
 * '<S87>'  : 'full_loop/Subsystem Controller/Adaptive MPC Controller/MPC/MPC Scalar Signal Check'
 * '<S88>'  : 'full_loop/Subsystem Controller/Adaptive MPC Controller/MPC/MPC Scalar Signal Check1'
 * '<S89>'  : 'full_loop/Subsystem Controller/Adaptive MPC Controller/MPC/MPC Scalar Signal Check2'
 * '<S90>'  : 'full_loop/Subsystem Controller/Adaptive MPC Controller/MPC/MPC Vector Signal Check'
 * '<S91>'  : 'full_loop/Subsystem Controller/Adaptive MPC Controller/MPC/MPC Vector Signal Check1'
 * '<S92>'  : 'full_loop/Subsystem Controller/Adaptive MPC Controller/MPC/MPC Vector Signal Check11'
 * '<S93>'  : 'full_loop/Subsystem Controller/Adaptive MPC Controller/MPC/MPC Vector Signal Check2'
 * '<S94>'  : 'full_loop/Subsystem Controller/Adaptive MPC Controller/MPC/MPC Vector Signal Check3'
 * '<S95>'  : 'full_loop/Subsystem Controller/Adaptive MPC Controller/MPC/MPC Vector Signal Check4'
 * '<S96>'  : 'full_loop/Subsystem Controller/Adaptive MPC Controller/MPC/MPC Vector Signal Check5'
 * '<S97>'  : 'full_loop/Subsystem Controller/Adaptive MPC Controller/MPC/MPC Vector Signal Check6'
 * '<S98>'  : 'full_loop/Subsystem Controller/Adaptive MPC Controller/MPC/optimizer'
 * '<S99>'  : 'full_loop/Subsystem Controller/Adaptive MPC Controller/MPC/optimizer/FixedHorizonOptimizer'
 * '<S100>' : 'full_loop/Subsystem ProcNav/Quaternion Inverse1'
 * '<S101>' : 'full_loop/Subsystem ProcNav/Quaternion Rotation'
 * '<S102>' : 'full_loop/Subsystem ProcNav/Quaternion Rotation1'
 * '<S103>' : 'full_loop/Subsystem ProcNav/Quaternions to Rotation Angles'
 * '<S104>' : 'full_loop/Subsystem ProcNav/Quaternion Inverse1/Quaternion Conjugate'
 * '<S105>' : 'full_loop/Subsystem ProcNav/Quaternion Inverse1/Quaternion Norm'
 * '<S106>' : 'full_loop/Subsystem ProcNav/Quaternion Rotation/Quaternion Normalize'
 * '<S107>' : 'full_loop/Subsystem ProcNav/Quaternion Rotation/V1'
 * '<S108>' : 'full_loop/Subsystem ProcNav/Quaternion Rotation/V2'
 * '<S109>' : 'full_loop/Subsystem ProcNav/Quaternion Rotation/V3'
 * '<S110>' : 'full_loop/Subsystem ProcNav/Quaternion Rotation/Quaternion Normalize/Quaternion Modulus'
 * '<S111>' : 'full_loop/Subsystem ProcNav/Quaternion Rotation/Quaternion Normalize/Quaternion Modulus/Quaternion Norm'
 * '<S112>' : 'full_loop/Subsystem ProcNav/Quaternion Rotation1/Quaternion Normalize'
 * '<S113>' : 'full_loop/Subsystem ProcNav/Quaternion Rotation1/V1'
 * '<S114>' : 'full_loop/Subsystem ProcNav/Quaternion Rotation1/V2'
 * '<S115>' : 'full_loop/Subsystem ProcNav/Quaternion Rotation1/V3'
 * '<S116>' : 'full_loop/Subsystem ProcNav/Quaternion Rotation1/Quaternion Normalize/Quaternion Modulus'
 * '<S117>' : 'full_loop/Subsystem ProcNav/Quaternion Rotation1/Quaternion Normalize/Quaternion Modulus/Quaternion Norm'
 * '<S118>' : 'full_loop/Subsystem ProcNav/Quaternions to Rotation Angles/Angle Calculation'
 * '<S119>' : 'full_loop/Subsystem ProcNav/Quaternions to Rotation Angles/Quaternion Normalize'
 * '<S120>' : 'full_loop/Subsystem ProcNav/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input'
 * '<S121>' : 'full_loop/Subsystem ProcNav/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input/If Action Subsystem'
 * '<S122>' : 'full_loop/Subsystem ProcNav/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input/If Action Subsystem1'
 * '<S123>' : 'full_loop/Subsystem ProcNav/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input/If Action Subsystem2'
 * '<S124>' : 'full_loop/Subsystem ProcNav/Quaternions to Rotation Angles/Quaternion Normalize/Quaternion Modulus'
 * '<S125>' : 'full_loop/Subsystem ProcNav/Quaternions to Rotation Angles/Quaternion Normalize/Quaternion Modulus/Quaternion Norm'
 * '<S126>' : 'full_loop/Subsystem Trajectory/MATLAB Function'
 * '<S127>' : 'full_loop/Subsystem Trajectory/Quaternion Rotation'
 * '<S128>' : 'full_loop/Subsystem Trajectory/Quaternion Rotation1'
 * '<S129>' : 'full_loop/Subsystem Trajectory/Quaternion Rotation/Quaternion Normalize'
 * '<S130>' : 'full_loop/Subsystem Trajectory/Quaternion Rotation/V1'
 * '<S131>' : 'full_loop/Subsystem Trajectory/Quaternion Rotation/V2'
 * '<S132>' : 'full_loop/Subsystem Trajectory/Quaternion Rotation/V3'
 * '<S133>' : 'full_loop/Subsystem Trajectory/Quaternion Rotation/Quaternion Normalize/Quaternion Modulus'
 * '<S134>' : 'full_loop/Subsystem Trajectory/Quaternion Rotation/Quaternion Normalize/Quaternion Modulus/Quaternion Norm'
 * '<S135>' : 'full_loop/Subsystem Trajectory/Quaternion Rotation1/Quaternion Normalize'
 * '<S136>' : 'full_loop/Subsystem Trajectory/Quaternion Rotation1/V1'
 * '<S137>' : 'full_loop/Subsystem Trajectory/Quaternion Rotation1/V2'
 * '<S138>' : 'full_loop/Subsystem Trajectory/Quaternion Rotation1/V3'
 * '<S139>' : 'full_loop/Subsystem Trajectory/Quaternion Rotation1/Quaternion Normalize/Quaternion Modulus'
 * '<S140>' : 'full_loop/Subsystem Trajectory/Quaternion Rotation1/Quaternion Normalize/Quaternion Modulus/Quaternion Norm'
 */
#endif                                 /* RTW_HEADER_full_loop_h_ */
