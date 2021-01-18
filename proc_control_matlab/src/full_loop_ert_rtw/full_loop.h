//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: full_loop.h
//
// Code generated for Simulink model 'full_loop'.
//
// Model version                  : 1.340
// Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
// C/C++ source code generated on : Sun Jan 17 20:33:25 2021
//
// Target selection: ert.tlc
// Embedded hardware selection: Intel->x86-64 (Linux 64)
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
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "slros_initialize.h"
#include "full_loop_types.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"
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

// Block signals (default storage)
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
  real_T useq[88];                     // '<S98>/FixedHorizonOptimizer'
  real_T b_utarget[80];
  real_T dv8[80];
  real_T r[68];
  real_T Hessian[64];
  real_T Hessian_p[64];
  real_T b_Hessian[64];
  real_T dv9[64];
  real_T dv10[48];
  SL_Bus_full_loop_gazebo_msgs_ModelState msg;// '<S2>/MATLAB Function'
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
  real_T VectorConcatenate_e[18];      // '<S21>/Vector Concatenate'
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
  real_T b_yoff[12];
  real_T TmpSignalConversionAtSFunct[12];// '<S4>/check'
  real_T DataTypeConversion1[12];
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
  real_T Transpose[9];                 // '<S13>/Transpose'
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
  real_T umax_scale[8];                // '<S70>/umax_scale'
  real_T umin_scale[8];                // '<S70>/umin_scale'
  real_T MATLABSystem_o3[8];           // '<S4>/MATLAB System'
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
  real_T qS2W[4];                      // '<S5>/Gain'
  real_T Bc[4];
  real_T b_Mu1[4];
  real_T unusedU0[4];
  real_T cTol[4];
  real_T varargin_1_p[4];
  char_T cv[24];
  real_T ubvbwb[3];                    // '<S13>/ub,vb,wb'
  real_T BodyPosition[3];              // '<S5>/Discrete-Time Integrator1'
  real_T tcount[3];                    // '<S4>/check'
  real_T xk1[20];                      // '<S98>/FixedHorizonOptimizer'
  real_T u[8];                         // '<S98>/FixedHorizonOptimizer'
  real_T Pk1[400];                     // '<S98>/FixedHorizonOptimizer'
  real_T A[144];                       // '<S4>/MATLAB System1'
  real_T B[96];                        // '<S4>/MATLAB System1'
  real_T C[144];                       // '<S4>/MATLAB System1'
  real_T D[96];                        // '<S4>/MATLAB System1'
  real_T U[8];                         // '<S4>/MATLAB System1'
  real_T Y[12];                        // '<S4>/MATLAB System1'
  real_T X[12];                        // '<S4>/MATLAB System1'
  real_T DX[12];                       // '<S4>/MATLAB System1'
  real_T q[4];                         // '<S59>/MATLAB Function'
  real_T sincos_o2_b[3];               // '<S62>/sincos'
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
  real_T Output;                       // '<S65>/Output'
  real_T q0;                           // '<S29>/q0'
  real_T q1;                           // '<S29>/q1'
  real_T q2;                           // '<S29>/q2'
  real_T q3;                           // '<S29>/q3'
  real_T Memory[4];                    // '<S59>/Memory'
  real_T Output_j;                     // '<S66>/Output'
  real_T Memory5[3];                   // '<S4>/Memory5'
  real_T Memory3[12];                  // '<S4>/Memory3'
  real_T FromWorkspace1[12];           // '<S6>/From Workspace1'
  real_T Sum;                          // '<S107>/Sum'
  real_T Sum_g;                        // '<S108>/Sum'
  real_T Sum_e;                        // '<S109>/Sum'
  real_T WorldPosition[3];             // '<S5>/Discrete-Time Integrator'
  real_T Sum_a[3];                     // '<S6>/Sum'
  real_T Memory_e[3];                  // '<S6>/Memory'
  real_T Selector[9];                  // '<S20>/Selector'
  real_T Selector1[9];                 // '<S20>/Selector1'
  real_T Selector2[9];                 // '<S20>/Selector2'
  real_T Sum_ae[8];                    // '<S4>/Sum'
  real_T uDLookupTable1[8];            // '<S16>/1-D Lookup Table1'
  real_T TmpSignalConversionAtq0q1q2q3_c[4];// '<S19>/qdot'
  real_T Product2[3];                  // '<S20>/Product2'
  real_T Sum_b[3];                     // '<S13>/Sum'
  real_T Product[3];                   // '<S26>/Product'
  real_T y[3];                         // '<S6>/MATLAB Function'
  real_T checkedPose[12];              // '<S4>/check'
  real_T Merge;                        // '<S46>/Merge'
  real_T Merge_b;                      // '<S120>/Merge'
  real_T t17;
  real_T t26;
  real_T t27;
  real_T t18;
  real_T t19;
  real_T t20;
  real_T t21;
  real_T t23;
  real_T t42;
  real_T t48;
  real_T t52;
  real_T t55;
  real_T ixk;                          // '<S58>/i x k'
  real_T Product2_fy;                  // '<S12>/Product2'
  real_T Sum_a_e;                      // '<S12>/Sum'
  real_T Sum_d;                        // '<S137>/Sum'
  real_T Product8;                     // '<S137>/Product8'
  real_T Product3_bd;                  // '<S129>/Product3'
  real_T Product2_h5;                  // '<S129>/Product2'
  real_T rtb_sincos_o1_idx_2;
  real_T rtb_sincos_o1_idx_1;
  real_T rtb_sincos_o1_idx_0;
  real_T rtb_sincos_o2_idx_0;
  real_T rtb_sincos_o2_idx_1;
  real_T rtb_sincos_o2_idx_2;
  real_T Dynamics_tmp;
  real_T Dynamics_tmp_o;
  real_T Dynamics_tmp_b;
  real_T Dynamics_tmp_a;
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
  real_T t7;
  real_T t8;
  real_T t9;
  real_T t10;
  real_T t11;
  real_T t12;
  real_T t13;
  real_T t14;
  real_T t18_h;
  real_T t19_m;
  real_T t20_a;
  real_T t21_k;
  real_T t22;
  real_T t23_p;
  real_T t27_b;
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
  real_T phi_alpha;
  real_T constrViolationEq;
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
  int32_T b_j;
  int32_T kBcol;
  int32_T b_jAcol;
  int32_T b_c_i;
  int32_T ix;
  int32_T b_ix;
  int32_T c_ix;
  int32_T ijA;
  int32_T nDepEq;
  int32_T i;
  int32_T nVar;
  int32_T mEq;
  int32_T mConstr;
  int32_T Flags_stepType;
  int32_T c_gs;
  int32_T i_n;
  int32_T WorkingSet_l;
  int32_T nVar_c;
  int32_T b_k;
  int32_T nVarOrig;
  int32_T mEq_n;
  int32_T temp_p;
  int32_T iEq0;
  int32_T iIneqEnd;
  int32_T nVar_d;
  int32_T mConstr_o;
  int32_T mEqFixed;
  int32_T activeSetChangeID;
  int32_T nVar_j;
  int32_T globalActiveConstrIdx;
  int32_T idxMinLambda;
  int32_T TYPE;
  int32_T j_c;
  int32_T nVar_h;
  int32_T mWConstr;
  int32_T nVar_da;
  int32_T b_idx;
  int32_T b_idx_row;
  int32_T b_idx_c;
  int32_T iA0_tmp;
  int32_T minmn;
  int32_T ii;
  int32_T d_i;
  int32_T b_i;
  int32_T b_Mrows_tmp;
  int32_T c_Linv_tmp;
  int32_T i_p;
  int32_T i_pi;
  int32_T c_k_a;
  int32_T f_i;
  int32_T idx;
  int32_T i_o;
  int32_T f_i_j;
  int32_T i1;
  int32_T U_tmp;
  int32_T i_pie;
  int32_T b_i_o;
  int32_T e_i;
  int32_T f_i_l;
  int32_T j_k;
  int32_T i2;
  int32_T i3;
  int32_T d_i_j;
  int32_T itau;
  int32_T iaii;
  int32_T i4;
  int32_T i5;
  int32_T b_j_f;
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
  int32_T b_i_l;
  int32_T iQR0;
  int32_T b_idx_l;
  int32_T i_g;
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
  int32_T nVar_jw;
  int32_T mmi_o;
  int32_T b_i_cs;
  int32_T lastv_h;
  int32_T nVar_i;
  int32_T mEq_p;
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
  boolean_T iAout[4];                  // '<S98>/FixedHorizonOptimizer'
} B_full_loop_T;

// Block states (default storage) for system '<Root>'
typedef struct {
  TrimPlant_full_loop_T obj;           // '<S4>/MATLAB System1'
  KickIn_full_loop_T obj_c;            // '<S4>/MATLAB System'
  ros_slros_internal_block_Publ_T obj_k;// '<S9>/SinkBlock'
  real_T last_mv_DSTATE[8];            // '<S70>/last_mv'
  real_T DiscreteTimeIntegrator1_DSTATE[3];// '<S5>/Discrete-Time Integrator1'
  real_T DiscreteTimeIntegrator_DSTATE[3];// '<S5>/Discrete-Time Integrator'
  real_T LastPcov_PreviousInput[400];  // '<S70>/LastPcov'
  real_T last_x_PreviousInput[20];     // '<S70>/last_x'
  real_T NextOutput;                   // '<S65>/White Noise'
  real_T Memory_PreviousInput[4];      // '<S59>/Memory'
  real_T NextOutput_b;                 // '<S66>/White Noise'
  real_T Memory5_PreviousInput[3];     // '<S4>/Memory5'
  real_T Memory3_PreviousInput[12];    // '<S4>/Memory3'
  real_T Memory_PreviousInput_p[3];    // '<S6>/Memory'
  real_T Memory_PreviousInput_m[8];    // '<S4>/Memory'
  real_T Product2_DWORK4[9];           // '<S20>/Product2'
  struct {
    void *TimePtr;
    void *DataPtr;
    void *RSimInfoPtr;
  } FromWorkspace1_PWORK;              // '<S6>/From Workspace1'

  uint32_T RandSeed;                   // '<S65>/White Noise'
  uint32_T RandSeed_k;                 // '<S66>/White Noise'
  int_T q0q1q2q3_IWORK;                // '<S19>/q0 q1 q2 q3'
  struct {
    int_T PrevIndex;
  } FromWorkspace1_IWORK;              // '<S6>/From Workspace1'

  int8_T If_ActiveSubsystem;           // '<S46>/If'
  int8_T If_ActiveSubsystem_j;         // '<S120>/If'
  boolean_T Memory_PreviousInput_d[4]; // '<S70>/Memory'
} DW_full_loop_T;

// Continuous states (default storage)
typedef struct {
  real_T ubvbwb_CSTATE[3];             // '<S13>/ub,vb,wb'
  real_T q0q1q2q3_CSTATE[4];           // '<S19>/q0 q1 q2 q3'
  real_T pqr_CSTATE[3];                // '<S13>/p,q,r '
  real_T Integrator_CSTATE[3];         // '<S15>/Integrator'
  real_T xeyeze_CSTATE[3];             // '<S13>/xe,ye,ze'
} X_full_loop_T;

// State derivatives (default storage)
typedef struct {
  real_T ubvbwb_CSTATE[3];             // '<S13>/ub,vb,wb'
  real_T q0q1q2q3_CSTATE[4];           // '<S19>/q0 q1 q2 q3'
  real_T pqr_CSTATE[3];                // '<S13>/p,q,r '
  real_T Integrator_CSTATE[3];         // '<S15>/Integrator'
  real_T xeyeze_CSTATE[3];             // '<S13>/xe,ye,ze'
} XDot_full_loop_T;

// State disabled
typedef struct {
  boolean_T ubvbwb_CSTATE[3];          // '<S13>/ub,vb,wb'
  boolean_T q0q1q2q3_CSTATE[4];        // '<S19>/q0 q1 q2 q3'
  boolean_T pqr_CSTATE[3];             // '<S13>/p,q,r '
  boolean_T Integrator_CSTATE[3];      // '<S15>/Integrator'
  boolean_T xeyeze_CSTATE[3];          // '<S13>/xe,ye,ze'
} XDis_full_loop_T;

#ifndef ODE3_INTG
#define ODE3_INTG

// ODE3 Integration Data
typedef struct {
  real_T *y;                           // output
  real_T *f[3];                        // derivatives
} ODE3_IntgData;

#endif

// Parameters (default storage)
struct P_full_loop_T_ {
  real_T I[9];                         // Variable: I
                                          //  Referenced by: '<S21>/Constant1'

  real_T N[201];                       // Variable: N
                                          //  Referenced by:
                                          //    '<S4>/1-D Lookup Table5'
                                          //    '<S16>/1-D Lookup Table1'

  real_T PWM[201];                     // Variable: PWM
                                          //  Referenced by:
                                          //    '<S4>/1-D Lookup Table5'
                                          //    '<S16>/1-D Lookup Table1'

  real_T TMAX[8];                      // Variable: TMAX
                                          //  Referenced by: '<S4>/Constant2'

  real_T TMIN[8];                      // Variable: TMIN
                                          //  Referenced by: '<S4>/Constant'

  real_T Ts;                           // Variable: Ts
                                          //  Referenced by: '<S4>/Constant1'

  real_T Ui[8];                        // Variable: Ui
                                          //  Referenced by: '<S4>/Memory'

  real_T Xi[12];                       // Variable: Xi
                                          //  Referenced by: '<S4>/Memory3'

  real_T mass;                         // Variable: mass
                                          //  Referenced by: '<S21>/Constant'

  real_T tmax;                         // Variable: tmax
                                          //  Referenced by: '<S4>/Saturation'

  real_T tmin;                         // Variable: tmin
                                          //  Referenced by: '<S4>/Saturation'

  real_T waPhi;                        // Variable: waPhi
                                          //  Referenced by: '<S18>/Roll Wave'

  real_T waPsi;                        // Variable: waPsi
                                          //  Referenced by: '<S18>/Yaw Wave'

  real_T waTheta;                      // Variable: waTheta
                                          //  Referenced by: '<S18>/Pitch Wave'

  real_T waX;                          // Variable: waX
                                          //  Referenced by: '<S18>/X Wave'

  real_T waY;                          // Variable: waY
                                          //  Referenced by: '<S18>/Y Wave'

  real_T waZ;                          // Variable: waZ
                                          //  Referenced by: '<S18>/Z Wave'

  real_T wfPhi;                        // Variable: wfPhi
                                          //  Referenced by: '<S18>/Roll Wave'

  real_T wfPsi;                        // Variable: wfPsi
                                          //  Referenced by: '<S18>/Yaw Wave'

  real_T wfTheta;                      // Variable: wfTheta
                                          //  Referenced by: '<S18>/Pitch Wave'

  real_T wfX;                          // Variable: wfX
                                          //  Referenced by: '<S18>/X Wave'

  real_T wfY;                          // Variable: wfY
                                          //  Referenced by: '<S18>/Y Wave'

  real_T wfZ;                          // Variable: wfZ
                                          //  Referenced by: '<S18>/Z Wave'

  real_T wpPhi;                        // Variable: wpPhi
                                          //  Referenced by: '<S18>/Roll Wave'

  real_T wpPsi;                        // Variable: wpPsi
                                          //  Referenced by: '<S18>/Yaw Wave'

  real_T wpTheta;                      // Variable: wpTheta
                                          //  Referenced by: '<S18>/Pitch Wave'

  real_T wpX;                          // Variable: wpX
                                          //  Referenced by: '<S18>/X Wave'

  real_T wpY;                          // Variable: wpY
                                          //  Referenced by: '<S18>/Y Wave'

  real_T wpZ;                          // Variable: wpZ
                                          //  Referenced by: '<S18>/Z Wave'

  uint8_T modelName[4];                // Variable: modelName
                                          //  Referenced by: '<S2>/ '

  uint8_T referenceFrame[5];           // Variable: referenceFrame
                                          //  Referenced by: '<S2>/  '

  real_T BandLimitedWhiteNoise_Cov; // Mask Parameter: BandLimitedWhiteNoise_Cov
                                       //  Referenced by: '<S65>/Output'

  real_T BandLimitedWhiteNoise1_Cov;
                                   // Mask Parameter: BandLimitedWhiteNoise1_Cov
                                      //  Referenced by: '<S66>/Output'

  real_T uDOFEulerAngles_Vm_0[3];      // Mask Parameter: uDOFEulerAngles_Vm_0
                                          //  Referenced by: '<S13>/ub,vb,wb'

  real_T uDOFEulerAngles_eul_0[3];     // Mask Parameter: uDOFEulerAngles_eul_0
                                          //  Referenced by: '<S19>/Initial Euler Angles'

  real_T uDOFEulerAngles_k_quat;       // Mask Parameter: uDOFEulerAngles_k_quat
                                          //  Referenced by: '<S30>/High Gain Quaternion Normalization'

  real_T uDOFEulerAngles_pm_0[3];      // Mask Parameter: uDOFEulerAngles_pm_0
                                          //  Referenced by: '<S13>/p,q,r '

  real_T BandLimitedWhiteNoise_seed;
                                   // Mask Parameter: BandLimitedWhiteNoise_seed
                                      //  Referenced by: '<S65>/White Noise'

  real_T BandLimitedWhiteNoise1_seed;
                                  // Mask Parameter: BandLimitedWhiteNoise1_seed
                                     //  Referenced by: '<S66>/White Noise'

  real_T uDOFEulerAngles_xme_0[3];     // Mask Parameter: uDOFEulerAngles_xme_0
                                          //  Referenced by: '<S13>/xe,ye,ze'

  SL_Bus_full_loop_gazebo_msgs_ModelState Constant_Value;// Computed Parameter: Constant_Value
                                                            //  Referenced by: '<S7>/Constant'

  real_T Constant_Value_c;             // Expression: 1
                                          //  Referenced by: '<S47>/Constant'

  real_T Constant_Value_o;             // Expression: 1
                                          //  Referenced by: '<S48>/Constant'

  real_T Constant_Value_m;             // Expression: 1
                                          //  Referenced by: '<S121>/Constant'

  real_T Constant_Value_j;             // Expression: 1
                                          //  Referenced by: '<S122>/Constant'

  real_T LastPcov_InitialCondition[400];// Expression: lastPcov
                                           //  Referenced by: '<S70>/LastPcov'

  real_T last_x_InitialCondition[20];  // Expression: lastx+xoff
                                          //  Referenced by: '<S70>/last_x'

  real_T last_mv_InitialCondition[8];  // Expression: lastu+uoff
                                          //  Referenced by: '<S70>/last_mv'

  real_T DiscreteTimeIntegrator1_gainval;
                          // Computed Parameter: DiscreteTimeIntegrator1_gainval
                             //  Referenced by: '<S5>/Discrete-Time Integrator1'

  real_T DiscreteTimeIntegrator1_IC;   // Expression: 0
                                          //  Referenced by: '<S5>/Discrete-Time Integrator1'

  real_T WhiteNoise_Mean;              // Expression: 0
                                          //  Referenced by: '<S65>/White Noise'

  real_T WhiteNoise_StdDev;            // Computed Parameter: WhiteNoise_StdDev
                                          //  Referenced by: '<S65>/White Noise'

  real_T u2_Gain;                      // Expression: 0.5
                                          //  Referenced by: '<S29>/1//2'

  real_T u2_Gain_j;                    // Expression: 0.5
                                          //  Referenced by: '<S62>/1//2'

  real_T Memory_InitialCondition[4];   // Expression: [0,0,0,1]
                                          //  Referenced by: '<S59>/Memory'

  real_T WhiteNoise_Mean_m;            // Expression: 0
                                          //  Referenced by: '<S66>/White Noise'

  real_T WhiteNoise_StdDev_a;         // Computed Parameter: WhiteNoise_StdDev_a
                                         //  Referenced by: '<S66>/White Noise'

  real_T Memory5_InitialCondition[3];  // Expression: [0,0,0]
                                          //  Referenced by: '<S4>/Memory5'

  real_T Gain_Gain;                    // Expression: 1
                                          //  Referenced by: '<S5>/Gain'

  real_T Constant_Value_e;             // Expression: 0.5
                                          //  Referenced by: '<S107>/Constant'

  real_T Gain2_Gain;                   // Expression: 2
                                          //  Referenced by: '<S107>/Gain2'

  real_T Gain_Gain_c;                  // Expression: 2
                                          //  Referenced by: '<S107>/Gain'

  real_T Gain1_Gain;                   // Expression: 2
                                          //  Referenced by: '<S107>/Gain1'

  real_T Gain_Gain_ca;                 // Expression: 2
                                          //  Referenced by: '<S108>/Gain'

  real_T Constant_Value_or;            // Expression: 0.5
                                          //  Referenced by: '<S108>/Constant'

  real_T Gain2_Gain_f;                 // Expression: 2
                                          //  Referenced by: '<S108>/Gain2'

  real_T Gain1_Gain_c;                 // Expression: 2
                                          //  Referenced by: '<S108>/Gain1'

  real_T Gain_Gain_n;                  // Expression: 2
                                          //  Referenced by: '<S109>/Gain'

  real_T Gain1_Gain_d;                 // Expression: 2
                                          //  Referenced by: '<S109>/Gain1'

  real_T Constant_Value_a;             // Expression: 0.5
                                          //  Referenced by: '<S109>/Constant'

  real_T Gain2_Gain_g;                 // Expression: 2
                                          //  Referenced by: '<S109>/Gain2'

  real_T DiscreteTimeIntegrator_gainval;
                           // Computed Parameter: DiscreteTimeIntegrator_gainval
                              //  Referenced by: '<S5>/Discrete-Time Integrator'

  real_T DiscreteTimeIntegrator_IC;    // Expression: 0
                                          //  Referenced by: '<S5>/Discrete-Time Integrator'

  real_T Constant_Value_p;             // Expression: 0.5
                                          //  Referenced by: '<S136>/Constant'

  real_T Gain2_Gain_i;                 // Expression: 2
                                          //  Referenced by: '<S136>/Gain2'

  real_T Gain_Gain_m;                  // Expression: 2
                                          //  Referenced by: '<S136>/Gain'

  real_T Gain1_Gain_l;                 // Expression: 2
                                          //  Referenced by: '<S136>/Gain1'

  real_T Gain_Gain_cd;                 // Expression: 2
                                          //  Referenced by: '<S137>/Gain'

  real_T Constant_Value_l;             // Expression: 0.5
                                          //  Referenced by: '<S137>/Constant'

  real_T Gain2_Gain_m;                 // Expression: 2
                                          //  Referenced by: '<S137>/Gain2'

  real_T Gain1_Gain_h;                 // Expression: 2
                                          //  Referenced by: '<S137>/Gain1'

  real_T Gain_Gain_h;                  // Expression: 2
                                          //  Referenced by: '<S138>/Gain'

  real_T Gain1_Gain_i;                 // Expression: 2
                                          //  Referenced by: '<S138>/Gain1'

  real_T Constant_Value_k;             // Expression: 0.5
                                          //  Referenced by: '<S138>/Constant'

  real_T Gain2_Gain_b;                 // Expression: 2
                                          //  Referenced by: '<S138>/Gain2'

  real_T Memory_InitialCondition_p;    // Expression: 0
                                          //  Referenced by: '<S6>/Memory'

  real_T Constant_Value_j4;            // Expression: 0.5
                                          //  Referenced by: '<S130>/Constant'

  real_T Gain2_Gain_mb;                // Expression: 2
                                          //  Referenced by: '<S130>/Gain2'

  real_T Gain_Gain_ha;                 // Expression: 2
                                          //  Referenced by: '<S130>/Gain'

  real_T Gain1_Gain_ln;                // Expression: 2
                                          //  Referenced by: '<S130>/Gain1'

  real_T Gain_Gain_k;                  // Expression: 2
                                          //  Referenced by: '<S131>/Gain'

  real_T Constant_Value_g;             // Expression: 0.5
                                          //  Referenced by: '<S131>/Constant'

  real_T Gain2_Gain_fi;                // Expression: 2
                                          //  Referenced by: '<S131>/Gain2'

  real_T Gain1_Gain_j;                 // Expression: 2
                                          //  Referenced by: '<S131>/Gain1'

  real_T Gain_Gain_nw;                 // Expression: 2
                                          //  Referenced by: '<S132>/Gain'

  real_T Gain1_Gain_o;                 // Expression: 2
                                          //  Referenced by: '<S132>/Gain1'

  real_T Constant_Value_ov;            // Expression: 0.5
                                          //  Referenced by: '<S132>/Constant'

  real_T Gain2_Gain_o;                 // Expression: 2
                                          //  Referenced by: '<S132>/Gain2'

  real_T md_zero_Value;                // Expression: zeros(1,1)
                                          //  Referenced by: '<S67>/md_zero'

  real_T umin_scale_Gain[8];           // Expression: RMVscale
                                          //  Referenced by: '<S70>/umin_scale'

  real_T umax_scale_Gain[8];           // Expression: RMVscale
                                          //  Referenced by: '<S70>/umax_scale'

  real_T ymin_zero_Value[12];          // Expression: zeros(12,1)
                                          //  Referenced by: '<S67>/ymin_zero'

  real_T ymin_scale_Gain[12];          // Expression: RYscale
                                          //  Referenced by: '<S70>/ymin_scale'

  real_T ymax_zero_Value[12];          // Expression: zeros(12,1)
                                          //  Referenced by: '<S67>/ymax_zero'

  real_T ymax_scale_Gain[12];          // Expression: RYscale
                                          //  Referenced by: '<S70>/ymax_scale'

  real_T E_zero_Value[8];              // Expression: zeros(1,8)
                                          //  Referenced by: '<S67>/E_zero'

  real_T umin_scale4_Gain[8];      // Expression: MVscale(:,ones(1,max(nCC,1)))'
                                      //  Referenced by: '<S70>/umin_scale4'

  real_T F_zero_Value[12];             // Expression: zeros(1,12)
                                          //  Referenced by: '<S67>/F_zero'

  real_T ymin_scale1_Gain[12];      // Expression: Yscale(:,ones(1,max(nCC,1)))'
                                       //  Referenced by: '<S70>/ymin_scale1'

  real_T G_zero_Value;                 // Expression: zeros(1,1)
                                          //  Referenced by: '<S67>/G_zero'

  real_T S_zero_Value;                 // Expression: zeros(1,1)
                                          //  Referenced by: '<S67>/S_zero'

  real_T ymin_scale2_Gain;         // Expression: MDscale(:,ones(1,max(nCC,1)))'
                                      //  Referenced by: '<S70>/ymin_scale2'

  real_T switch_zero_Value;            // Expression: zeros(1,1)
                                          //  Referenced by: '<S67>/switch_zero'

  real_T extmv_zero_Value[8];          // Expression: zeros(8,1)
                                          //  Referenced by: '<S67>/ext.mv_zero'

  real_T extmv_scale_Gain[8];          // Expression: RMVscale
                                          //  Referenced by: '<S70>/ext.mv_scale'

  real_T mvtarget_zero_Value[8];       // Expression: zeros(8,1)
                                          //  Referenced by: '<S67>/mv.target_zero'

  real_T uref_scale_Gain[8];           // Expression: RMVscale
                                          //  Referenced by: '<S70>/uref_scale'

  real_T ywt_zero_Value[12];           // Expression: zeros(12,1)
                                          //  Referenced by: '<S67>/y.wt_zero'

  real_T uwt_zero_Value[8];            // Expression: zeros(8,1)
                                          //  Referenced by: '<S67>/u.wt_zero'

  real_T duwt_zero_Value[8];           // Expression: zeros(8,1)
                                          //  Referenced by: '<S67>/du.wt_zero'

  real_T ecrwt_zero_Value;             // Expression: zeros(1,1)
                                          //  Referenced by: '<S67>/ecr.wt_zero'

  real_T Constant2_Value[9];           // Expression: zeros(3)
                                          //  Referenced by: '<S21>/Constant2'

  real_T Gain_Gain_kf;                 // Expression: 2
                                          //  Referenced by: '<S32>/Gain'

  real_T Gain_Gain_hv;                 // Expression: 2
                                          //  Referenced by: '<S33>/Gain'

  real_T Gain_Gain_l;                  // Expression: 2
                                          //  Referenced by: '<S34>/Gain'

  real_T Gain_Gain_hl;                 // Expression: 2
                                          //  Referenced by: '<S36>/Gain'

  real_T Gain_Gain_i;                  // Expression: 2
                                          //  Referenced by: '<S37>/Gain'

  real_T Gain_Gain_e;                  // Expression: 2
                                          //  Referenced by: '<S38>/Gain'

  real_T u_scale_Gain[8];              // Expression: MVscale
                                          //  Referenced by: '<S70>/u_scale'

  real_T Constant_Value_n;             // Expression: 1
                                          //  Referenced by: '<S30>/Constant'

  real_T Integrator_IC;                // Expression: 0
                                          //  Referenced by: '<S15>/Integrator'

  real_T RollWave_Bias;                // Expression: 0
                                          //  Referenced by: '<S18>/Roll Wave'

  real_T PitchWave_Bias;               // Expression: 0
                                          //  Referenced by: '<S18>/Pitch Wave'

  real_T YawWave_Bias;                 // Expression: 0
                                          //  Referenced by: '<S18>/Yaw Wave'

  real_T XWave_Bias;                   // Expression: 0
                                          //  Referenced by: '<S18>/X Wave'

  real_T YWave_Bias;                   // Expression: 0
                                          //  Referenced by: '<S18>/Y Wave'

  real_T ZWave_Bias;                   // Expression: 0
                                          //  Referenced by: '<S18>/Z Wave'

  real_T Gain2_Gain_a;                 // Expression: 1
                                          //  Referenced by: '<S2>/Gain2'

  real_T Gain1_Gain_p;                 // Expression: 1
                                          //  Referenced by: '<S2>/Gain1'

  real_T Gain_Gain_l0;                 // Expression: -1
                                          //  Referenced by: '<S2>/Gain'

  boolean_T Memory_InitialCondition_a[4];// Expression: iA
                                            //  Referenced by: '<S70>/Memory'

};

// Real-time Model Data Structure
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
    uint32_T clockTick4;
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

// Block parameters (default storage)
#ifdef __cplusplus

extern "C" {

#endif

  extern P_full_loop_T full_loop_P;

#ifdef __cplusplus

}
#endif

// Block signals (default storage)
#ifdef __cplusplus

extern "C" {

#endif

  extern B_full_loop_T full_loop_B;

#ifdef __cplusplus

}
#endif

// Continuous states (default storage)
extern X_full_loop_T full_loop_X;

// Block states (default storage)
extern DW_full_loop_T full_loop_DW;

#ifdef __cplusplus

extern "C" {

#endif

  // Model entry point functions
  extern void full_loop_initialize(void);
  extern void full_loop_step(void);
  extern void full_loop_terminate(void);

#ifdef __cplusplus

}
#endif

// Real-time Model object
#ifdef __cplusplus

extern "C" {

#endif

  extern RT_MODEL_full_loop_T *const full_loop_M;

#ifdef __cplusplus

}
#endif

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<S1>/Scope' : Unused code path elimination
//  Block '<S1>/Scope1' : Unused code path elimination
//  Block '<S1>/Scope2' : Unused code path elimination
//  Block '<S1>/Scope3' : Unused code path elimination
//  Block '<S1>/Scope4' : Unused code path elimination
//  Block '<S24>/Unit Conversion' : Unused code path elimination
//  Block '<S25>/Unit Conversion' : Unused code path elimination
//  Block '<S15>/Random Number' : Unused code path elimination
//  Block '<S15>/Scope1' : Unused code path elimination
//  Block '<S15>/Scope2' : Unused code path elimination
//  Block '<S15>/Scope4' : Unused code path elimination
//  Block '<S18>/Scope' : Unused code path elimination
//  Block '<S70>/Data Type Conversion22' : Unused code path elimination
//  Block '<S70>/Data Type Conversion23' : Unused code path elimination
//  Block '<S71>/Matrix Dimension Check' : Unused code path elimination
//  Block '<S72>/Matrix Dimension Check' : Unused code path elimination
//  Block '<S73>/Matrix Dimension Check' : Unused code path elimination
//  Block '<S74>/Matrix Dimension Check' : Unused code path elimination
//  Block '<S75>/Matrix Dimension Check' : Unused code path elimination
//  Block '<S76>/Matrix Dimension Check' : Unused code path elimination
//  Block '<S77>/Matrix Dimension Check' : Unused code path elimination
//  Block '<S78>/Matrix Dimension Check' : Unused code path elimination
//  Block '<S79>/Matrix Dimension Check' : Unused code path elimination
//  Block '<S80>/Matrix Dimension Check' : Unused code path elimination
//  Block '<S81>/Matrix Dimension Check' : Unused code path elimination
//  Block '<S82>/Matrix Dimension Check' : Unused code path elimination
//  Block '<S83>/Matrix Dimension Check' : Unused code path elimination
//  Block '<S84>/Matrix Dimension Check' : Unused code path elimination
//  Block '<S85>/Matrix Dimension Check' : Unused code path elimination
//  Block '<S86>/Matrix Dimension Check' : Unused code path elimination
//  Block '<S87>/Vector Dimension Check' : Unused code path elimination
//  Block '<S88>/Vector Dimension Check' : Unused code path elimination
//  Block '<S89>/Vector Dimension Check' : Unused code path elimination
//  Block '<S90>/Vector Dimension Check' : Unused code path elimination
//  Block '<S91>/Vector Dimension Check' : Unused code path elimination
//  Block '<S92>/Vector Dimension Check' : Unused code path elimination
//  Block '<S93>/Vector Dimension Check' : Unused code path elimination
//  Block '<S94>/Vector Dimension Check' : Unused code path elimination
//  Block '<S95>/Vector Dimension Check' : Unused code path elimination
//  Block '<S96>/Vector Dimension Check' : Unused code path elimination
//  Block '<S97>/Vector Dimension Check' : Unused code path elimination
//  Block '<S70>/useq_scale' : Unused code path elimination
//  Block '<S70>/useq_scale1' : Unused code path elimination
//  Block '<S70>/ym_zero' : Unused code path elimination
//  Block '<S67>/m_zero' : Unused code path elimination
//  Block '<S67>/p_zero' : Unused code path elimination
//  Block '<S4>/Display' : Unused code path elimination
//  Block '<S4>/Scope2' : Unused code path elimination
//  Block '<S4>/Scope3' : Unused code path elimination
//  Block '<S5>/Memory' : Unused code path elimination
//  Block '<S5>/Memory1' : Unused code path elimination
//  Block '<S112>/Product' : Unused code path elimination
//  Block '<S112>/Product1' : Unused code path elimination
//  Block '<S112>/Product2' : Unused code path elimination
//  Block '<S112>/Product3' : Unused code path elimination
//  Block '<S117>/Product' : Unused code path elimination
//  Block '<S117>/Product1' : Unused code path elimination
//  Block '<S117>/Product2' : Unused code path elimination
//  Block '<S117>/Product3' : Unused code path elimination
//  Block '<S117>/Sum' : Unused code path elimination
//  Block '<S116>/sqrt' : Unused code path elimination
//  Block '<S113>/Constant' : Unused code path elimination
//  Block '<S113>/Gain' : Unused code path elimination
//  Block '<S113>/Gain1' : Unused code path elimination
//  Block '<S113>/Gain2' : Unused code path elimination
//  Block '<S113>/Product' : Unused code path elimination
//  Block '<S113>/Product1' : Unused code path elimination
//  Block '<S113>/Product2' : Unused code path elimination
//  Block '<S113>/Product3' : Unused code path elimination
//  Block '<S113>/Product4' : Unused code path elimination
//  Block '<S113>/Product5' : Unused code path elimination
//  Block '<S113>/Product6' : Unused code path elimination
//  Block '<S113>/Product7' : Unused code path elimination
//  Block '<S113>/Product8' : Unused code path elimination
//  Block '<S113>/Sum' : Unused code path elimination
//  Block '<S113>/Sum1' : Unused code path elimination
//  Block '<S113>/Sum2' : Unused code path elimination
//  Block '<S113>/Sum3' : Unused code path elimination
//  Block '<S114>/Constant' : Unused code path elimination
//  Block '<S114>/Gain' : Unused code path elimination
//  Block '<S114>/Gain1' : Unused code path elimination
//  Block '<S114>/Gain2' : Unused code path elimination
//  Block '<S114>/Product' : Unused code path elimination
//  Block '<S114>/Product1' : Unused code path elimination
//  Block '<S114>/Product2' : Unused code path elimination
//  Block '<S114>/Product3' : Unused code path elimination
//  Block '<S114>/Product4' : Unused code path elimination
//  Block '<S114>/Product5' : Unused code path elimination
//  Block '<S114>/Product6' : Unused code path elimination
//  Block '<S114>/Product7' : Unused code path elimination
//  Block '<S114>/Product8' : Unused code path elimination
//  Block '<S114>/Sum' : Unused code path elimination
//  Block '<S114>/Sum1' : Unused code path elimination
//  Block '<S114>/Sum2' : Unused code path elimination
//  Block '<S114>/Sum3' : Unused code path elimination
//  Block '<S115>/Constant' : Unused code path elimination
//  Block '<S115>/Gain' : Unused code path elimination
//  Block '<S115>/Gain1' : Unused code path elimination
//  Block '<S115>/Gain2' : Unused code path elimination
//  Block '<S115>/Product' : Unused code path elimination
//  Block '<S115>/Product1' : Unused code path elimination
//  Block '<S115>/Product2' : Unused code path elimination
//  Block '<S115>/Product3' : Unused code path elimination
//  Block '<S115>/Product4' : Unused code path elimination
//  Block '<S115>/Product5' : Unused code path elimination
//  Block '<S115>/Product6' : Unused code path elimination
//  Block '<S115>/Product7' : Unused code path elimination
//  Block '<S115>/Product8' : Unused code path elimination
//  Block '<S115>/Sum' : Unused code path elimination
//  Block '<S115>/Sum1' : Unused code path elimination
//  Block '<S115>/Sum2' : Unused code path elimination
//  Block '<S115>/Sum3' : Unused code path elimination
//  Block '<S5>/Scope' : Unused code path elimination
//  Block '<S5>/Scope1' : Unused code path elimination
//  Block '<S5>/Scope10' : Unused code path elimination
//  Block '<S5>/Scope2' : Unused code path elimination
//  Block '<S5>/Scope3' : Unused code path elimination
//  Block '<S5>/Scope4' : Unused code path elimination
//  Block '<S5>/Scope5' : Unused code path elimination
//  Block '<S5>/Scope6' : Unused code path elimination
//  Block '<S5>/Scope7' : Unused code path elimination
//  Block '<S5>/Scope8' : Unused code path elimination
//  Block '<S5>/Scope9' : Unused code path elimination
//  Block '<S5>/Sum' : Unused code path elimination
//  Block '<S5>/Sum1' : Unused code path elimination
//  Block '<S6>/Memory1' : Unused code path elimination
//  Block '<S6>/Scope' : Unused code path elimination
//  Block '<S6>/Scope1' : Unused code path elimination
//  Block '<S6>/Scope2' : Unused code path elimination
//  Block '<S6>/Scope3' : Unused code path elimination
//  Block '<S40>/Reshape (9) to [3x3] column-major' : Reshape block reduction
//  Block '<S53>/Reshape1' : Reshape block reduction
//  Block '<S53>/Reshape2' : Reshape block reduction
//  Block '<S54>/Reshape1' : Reshape block reduction
//  Block '<S54>/Reshape2' : Reshape block reduction
//  Block '<S20>/Reshape' : Reshape block reduction
//  Block '<S20>/Reshape1' : Reshape block reduction
//  Block '<S23>/Unit Conversion' : Eliminated nontunable gain of 1
//  Block '<S26>/Reshape1' : Reshape block reduction
//  Block '<S26>/Reshape2' : Reshape block reduction
//  Block '<S70>/Data Type Conversion10' : Eliminate redundant data type conversion
//  Block '<S70>/Data Type Conversion11' : Eliminate redundant data type conversion
//  Block '<S70>/Data Type Conversion12' : Eliminate redundant data type conversion
//  Block '<S70>/Data Type Conversion13' : Eliminate redundant data type conversion
//  Block '<S70>/Data Type Conversion14' : Eliminate redundant data type conversion
//  Block '<S70>/Data Type Conversion15' : Eliminate redundant data type conversion
//  Block '<S70>/Data Type Conversion16' : Eliminate redundant data type conversion
//  Block '<S70>/Data Type Conversion17' : Eliminate redundant data type conversion
//  Block '<S70>/Data Type Conversion18' : Eliminate redundant data type conversion
//  Block '<S70>/Data Type Conversion19' : Eliminate redundant data type conversion
//  Block '<S70>/Data Type Conversion2' : Eliminate redundant data type conversion
//  Block '<S70>/Data Type Conversion20' : Eliminate redundant data type conversion
//  Block '<S70>/Data Type Conversion21' : Eliminate redundant data type conversion
//  Block '<S70>/Data Type Conversion3' : Eliminate redundant data type conversion
//  Block '<S70>/Data Type Conversion4' : Eliminate redundant data type conversion
//  Block '<S70>/Data Type Conversion5' : Eliminate redundant data type conversion
//  Block '<S70>/Data Type Conversion6' : Eliminate redundant data type conversion
//  Block '<S70>/Data Type Conversion7' : Eliminate redundant data type conversion
//  Block '<S70>/Data Type Conversion8' : Eliminate redundant data type conversion
//  Block '<S70>/Data Type Conversion9' : Eliminate redundant data type conversion
//  Block '<S70>/E Conversion' : Eliminate redundant data type conversion
//  Block '<S70>/F Conversion' : Eliminate redundant data type conversion
//  Block '<S70>/G Conversion' : Eliminate redundant data type conversion
//  Block '<S70>/Reshape' : Reshape block reduction
//  Block '<S70>/Reshape1' : Reshape block reduction
//  Block '<S70>/Reshape2' : Reshape block reduction
//  Block '<S70>/Reshape3' : Reshape block reduction
//  Block '<S70>/Reshape4' : Reshape block reduction
//  Block '<S70>/Reshape5' : Reshape block reduction
//  Block '<S70>/S Conversion' : Eliminate redundant data type conversion
//  Block '<S70>/mo or x Conversion' : Eliminate redundant data type conversion


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
//  '<S1>'   : 'full_loop/Plot values'
//  '<S2>'   : 'full_loop/Send to Gazebo'
//  '<S3>'   : 'full_loop/Subsystem AUVPlant'
//  '<S4>'   : 'full_loop/Subsystem Controller'
//  '<S5>'   : 'full_loop/Subsystem ProcNav'
//  '<S6>'   : 'full_loop/Subsystem Trajectory'
//  '<S7>'   : 'full_loop/Send to Gazebo/   '
//  '<S8>'   : 'full_loop/Send to Gazebo/MATLAB Function'
//  '<S9>'   : 'full_loop/Send to Gazebo/Publish'
//  '<S10>'  : 'full_loop/Send to Gazebo/Quaternion Inverse'
//  '<S11>'  : 'full_loop/Send to Gazebo/Quaternion Inverse/Quaternion Conjugate'
//  '<S12>'  : 'full_loop/Send to Gazebo/Quaternion Inverse/Quaternion Norm'
//  '<S13>'  : 'full_loop/Subsystem AUVPlant/6DOF (Euler Angles)'
//  '<S14>'  : 'full_loop/Subsystem AUVPlant/Forces and torques'
//  '<S15>'  : 'full_loop/Subsystem AUVPlant/Post Prossessing'
//  '<S16>'  : 'full_loop/Subsystem AUVPlant/Pre Prossessing'
//  '<S17>'  : 'full_loop/Subsystem AUVPlant/Sensor Noise'
//  '<S18>'  : 'full_loop/Subsystem AUVPlant/Wave'
//  '<S19>'  : 'full_loop/Subsystem AUVPlant/6DOF (Euler Angles)/Calculate DCM & Euler Angles'
//  '<S20>'  : 'full_loop/Subsystem AUVPlant/6DOF (Euler Angles)/Calculate omega_dot'
//  '<S21>'  : 'full_loop/Subsystem AUVPlant/6DOF (Euler Angles)/Determine Force,  Mass & Inertia'
//  '<S22>'  : 'full_loop/Subsystem AUVPlant/6DOF (Euler Angles)/Vbxw'
//  '<S23>'  : 'full_loop/Subsystem AUVPlant/6DOF (Euler Angles)/Velocity Conversion'
//  '<S24>'  : 'full_loop/Subsystem AUVPlant/6DOF (Euler Angles)/Velocity Conversion1'
//  '<S25>'  : 'full_loop/Subsystem AUVPlant/6DOF (Euler Angles)/Velocity Conversion2'
//  '<S26>'  : 'full_loop/Subsystem AUVPlant/6DOF (Euler Angles)/transform to Inertial axes '
//  '<S27>'  : 'full_loop/Subsystem AUVPlant/6DOF (Euler Angles)/Calculate DCM & Euler Angles/Quaternions to  Direction Cosine Matrix'
//  '<S28>'  : 'full_loop/Subsystem AUVPlant/6DOF (Euler Angles)/Calculate DCM & Euler Angles/Quaternions to Rotation Angles'
//  '<S29>'  : 'full_loop/Subsystem AUVPlant/6DOF (Euler Angles)/Calculate DCM & Euler Angles/Rotation Angles to Quaternions'
//  '<S30>'  : 'full_loop/Subsystem AUVPlant/6DOF (Euler Angles)/Calculate DCM & Euler Angles/qdot'
//  '<S31>'  : 'full_loop/Subsystem AUVPlant/6DOF (Euler Angles)/Calculate DCM & Euler Angles/Quaternions to  Direction Cosine Matrix/A11'
//  '<S32>'  : 'full_loop/Subsystem AUVPlant/6DOF (Euler Angles)/Calculate DCM & Euler Angles/Quaternions to  Direction Cosine Matrix/A12'
//  '<S33>'  : 'full_loop/Subsystem AUVPlant/6DOF (Euler Angles)/Calculate DCM & Euler Angles/Quaternions to  Direction Cosine Matrix/A13'
//  '<S34>'  : 'full_loop/Subsystem AUVPlant/6DOF (Euler Angles)/Calculate DCM & Euler Angles/Quaternions to  Direction Cosine Matrix/A21'
//  '<S35>'  : 'full_loop/Subsystem AUVPlant/6DOF (Euler Angles)/Calculate DCM & Euler Angles/Quaternions to  Direction Cosine Matrix/A22'
//  '<S36>'  : 'full_loop/Subsystem AUVPlant/6DOF (Euler Angles)/Calculate DCM & Euler Angles/Quaternions to  Direction Cosine Matrix/A23'
//  '<S37>'  : 'full_loop/Subsystem AUVPlant/6DOF (Euler Angles)/Calculate DCM & Euler Angles/Quaternions to  Direction Cosine Matrix/A31'
//  '<S38>'  : 'full_loop/Subsystem AUVPlant/6DOF (Euler Angles)/Calculate DCM & Euler Angles/Quaternions to  Direction Cosine Matrix/A32'
//  '<S39>'  : 'full_loop/Subsystem AUVPlant/6DOF (Euler Angles)/Calculate DCM & Euler Angles/Quaternions to  Direction Cosine Matrix/A33'
//  '<S40>'  : 'full_loop/Subsystem AUVPlant/6DOF (Euler Angles)/Calculate DCM & Euler Angles/Quaternions to  Direction Cosine Matrix/Create 3x3 Matrix'
//  '<S41>'  : 'full_loop/Subsystem AUVPlant/6DOF (Euler Angles)/Calculate DCM & Euler Angles/Quaternions to  Direction Cosine Matrix/Quaternion Normalize'
//  '<S42>'  : 'full_loop/Subsystem AUVPlant/6DOF (Euler Angles)/Calculate DCM & Euler Angles/Quaternions to  Direction Cosine Matrix/Quaternion Normalize/Quaternion Modulus'
//  '<S43>'  : 'full_loop/Subsystem AUVPlant/6DOF (Euler Angles)/Calculate DCM & Euler Angles/Quaternions to  Direction Cosine Matrix/Quaternion Normalize/Quaternion Modulus/Quaternion Norm'
//  '<S44>'  : 'full_loop/Subsystem AUVPlant/6DOF (Euler Angles)/Calculate DCM & Euler Angles/Quaternions to Rotation Angles/Angle Calculation'
//  '<S45>'  : 'full_loop/Subsystem AUVPlant/6DOF (Euler Angles)/Calculate DCM & Euler Angles/Quaternions to Rotation Angles/Quaternion Normalize'
//  '<S46>'  : 'full_loop/Subsystem AUVPlant/6DOF (Euler Angles)/Calculate DCM & Euler Angles/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input'
//  '<S47>'  : 'full_loop/Subsystem AUVPlant/6DOF (Euler Angles)/Calculate DCM & Euler Angles/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input/If Action Subsystem'
//  '<S48>'  : 'full_loop/Subsystem AUVPlant/6DOF (Euler Angles)/Calculate DCM & Euler Angles/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input/If Action Subsystem1'
//  '<S49>'  : 'full_loop/Subsystem AUVPlant/6DOF (Euler Angles)/Calculate DCM & Euler Angles/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input/If Action Subsystem2'
//  '<S50>'  : 'full_loop/Subsystem AUVPlant/6DOF (Euler Angles)/Calculate DCM & Euler Angles/Quaternions to Rotation Angles/Quaternion Normalize/Quaternion Modulus'
//  '<S51>'  : 'full_loop/Subsystem AUVPlant/6DOF (Euler Angles)/Calculate DCM & Euler Angles/Quaternions to Rotation Angles/Quaternion Normalize/Quaternion Modulus/Quaternion Norm'
//  '<S52>'  : 'full_loop/Subsystem AUVPlant/6DOF (Euler Angles)/Calculate omega_dot/3x3 Cross Product'
//  '<S53>'  : 'full_loop/Subsystem AUVPlant/6DOF (Euler Angles)/Calculate omega_dot/I x w'
//  '<S54>'  : 'full_loop/Subsystem AUVPlant/6DOF (Euler Angles)/Calculate omega_dot/I x w1'
//  '<S55>'  : 'full_loop/Subsystem AUVPlant/6DOF (Euler Angles)/Calculate omega_dot/3x3 Cross Product/Subsystem'
//  '<S56>'  : 'full_loop/Subsystem AUVPlant/6DOF (Euler Angles)/Calculate omega_dot/3x3 Cross Product/Subsystem1'
//  '<S57>'  : 'full_loop/Subsystem AUVPlant/6DOF (Euler Angles)/Vbxw/Subsystem'
//  '<S58>'  : 'full_loop/Subsystem AUVPlant/6DOF (Euler Angles)/Vbxw/Subsystem1'
//  '<S59>'  : 'full_loop/Subsystem AUVPlant/Post Prossessing/Subsystem'
//  '<S60>'  : 'full_loop/Subsystem AUVPlant/Post Prossessing/Subsystem/MATLAB Function'
//  '<S61>'  : 'full_loop/Subsystem AUVPlant/Post Prossessing/Subsystem/Quaternion Inverse'
//  '<S62>'  : 'full_loop/Subsystem AUVPlant/Post Prossessing/Subsystem/Rotation Angles to Quaternions'
//  '<S63>'  : 'full_loop/Subsystem AUVPlant/Post Prossessing/Subsystem/Quaternion Inverse/Quaternion Conjugate'
//  '<S64>'  : 'full_loop/Subsystem AUVPlant/Post Prossessing/Subsystem/Quaternion Inverse/Quaternion Norm'
//  '<S65>'  : 'full_loop/Subsystem AUVPlant/Sensor Noise/Band-Limited White Noise'
//  '<S66>'  : 'full_loop/Subsystem AUVPlant/Sensor Noise/Band-Limited White Noise1'
//  '<S67>'  : 'full_loop/Subsystem Controller/Adaptive MPC Controller'
//  '<S68>'  : 'full_loop/Subsystem Controller/Bus2Mux'
//  '<S69>'  : 'full_loop/Subsystem Controller/check'
//  '<S70>'  : 'full_loop/Subsystem Controller/Adaptive MPC Controller/MPC'
//  '<S71>'  : 'full_loop/Subsystem Controller/Adaptive MPC Controller/MPC/MPC Matrix Signal Check'
//  '<S72>'  : 'full_loop/Subsystem Controller/Adaptive MPC Controller/MPC/MPC Matrix Signal Check A'
//  '<S73>'  : 'full_loop/Subsystem Controller/Adaptive MPC Controller/MPC/MPC Matrix Signal Check B'
//  '<S74>'  : 'full_loop/Subsystem Controller/Adaptive MPC Controller/MPC/MPC Matrix Signal Check C'
//  '<S75>'  : 'full_loop/Subsystem Controller/Adaptive MPC Controller/MPC/MPC Matrix Signal Check D'
//  '<S76>'  : 'full_loop/Subsystem Controller/Adaptive MPC Controller/MPC/MPC Matrix Signal Check DX'
//  '<S77>'  : 'full_loop/Subsystem Controller/Adaptive MPC Controller/MPC/MPC Matrix Signal Check U'
//  '<S78>'  : 'full_loop/Subsystem Controller/Adaptive MPC Controller/MPC/MPC Matrix Signal Check X'
//  '<S79>'  : 'full_loop/Subsystem Controller/Adaptive MPC Controller/MPC/MPC Matrix Signal Check Y'
//  '<S80>'  : 'full_loop/Subsystem Controller/Adaptive MPC Controller/MPC/MPC Matrix Signal Check1'
//  '<S81>'  : 'full_loop/Subsystem Controller/Adaptive MPC Controller/MPC/MPC Matrix Signal Check2'
//  '<S82>'  : 'full_loop/Subsystem Controller/Adaptive MPC Controller/MPC/MPC Preview Signal Check'
//  '<S83>'  : 'full_loop/Subsystem Controller/Adaptive MPC Controller/MPC/MPC Preview Signal Check1'
//  '<S84>'  : 'full_loop/Subsystem Controller/Adaptive MPC Controller/MPC/MPC Preview Signal Check2'
//  '<S85>'  : 'full_loop/Subsystem Controller/Adaptive MPC Controller/MPC/MPC Preview Signal Check3'
//  '<S86>'  : 'full_loop/Subsystem Controller/Adaptive MPC Controller/MPC/MPC Preview Signal Check4'
//  '<S87>'  : 'full_loop/Subsystem Controller/Adaptive MPC Controller/MPC/MPC Scalar Signal Check'
//  '<S88>'  : 'full_loop/Subsystem Controller/Adaptive MPC Controller/MPC/MPC Scalar Signal Check1'
//  '<S89>'  : 'full_loop/Subsystem Controller/Adaptive MPC Controller/MPC/MPC Scalar Signal Check2'
//  '<S90>'  : 'full_loop/Subsystem Controller/Adaptive MPC Controller/MPC/MPC Vector Signal Check'
//  '<S91>'  : 'full_loop/Subsystem Controller/Adaptive MPC Controller/MPC/MPC Vector Signal Check1'
//  '<S92>'  : 'full_loop/Subsystem Controller/Adaptive MPC Controller/MPC/MPC Vector Signal Check11'
//  '<S93>'  : 'full_loop/Subsystem Controller/Adaptive MPC Controller/MPC/MPC Vector Signal Check2'
//  '<S94>'  : 'full_loop/Subsystem Controller/Adaptive MPC Controller/MPC/MPC Vector Signal Check3'
//  '<S95>'  : 'full_loop/Subsystem Controller/Adaptive MPC Controller/MPC/MPC Vector Signal Check4'
//  '<S96>'  : 'full_loop/Subsystem Controller/Adaptive MPC Controller/MPC/MPC Vector Signal Check5'
//  '<S97>'  : 'full_loop/Subsystem Controller/Adaptive MPC Controller/MPC/MPC Vector Signal Check6'
//  '<S98>'  : 'full_loop/Subsystem Controller/Adaptive MPC Controller/MPC/optimizer'
//  '<S99>'  : 'full_loop/Subsystem Controller/Adaptive MPC Controller/MPC/optimizer/FixedHorizonOptimizer'
//  '<S100>' : 'full_loop/Subsystem ProcNav/Quaternion Inverse1'
//  '<S101>' : 'full_loop/Subsystem ProcNav/Quaternion Rotation'
//  '<S102>' : 'full_loop/Subsystem ProcNav/Quaternion Rotation1'
//  '<S103>' : 'full_loop/Subsystem ProcNav/Quaternions to Rotation Angles'
//  '<S104>' : 'full_loop/Subsystem ProcNav/Quaternion Inverse1/Quaternion Conjugate'
//  '<S105>' : 'full_loop/Subsystem ProcNav/Quaternion Inverse1/Quaternion Norm'
//  '<S106>' : 'full_loop/Subsystem ProcNav/Quaternion Rotation/Quaternion Normalize'
//  '<S107>' : 'full_loop/Subsystem ProcNav/Quaternion Rotation/V1'
//  '<S108>' : 'full_loop/Subsystem ProcNav/Quaternion Rotation/V2'
//  '<S109>' : 'full_loop/Subsystem ProcNav/Quaternion Rotation/V3'
//  '<S110>' : 'full_loop/Subsystem ProcNav/Quaternion Rotation/Quaternion Normalize/Quaternion Modulus'
//  '<S111>' : 'full_loop/Subsystem ProcNav/Quaternion Rotation/Quaternion Normalize/Quaternion Modulus/Quaternion Norm'
//  '<S112>' : 'full_loop/Subsystem ProcNav/Quaternion Rotation1/Quaternion Normalize'
//  '<S113>' : 'full_loop/Subsystem ProcNav/Quaternion Rotation1/V1'
//  '<S114>' : 'full_loop/Subsystem ProcNav/Quaternion Rotation1/V2'
//  '<S115>' : 'full_loop/Subsystem ProcNav/Quaternion Rotation1/V3'
//  '<S116>' : 'full_loop/Subsystem ProcNav/Quaternion Rotation1/Quaternion Normalize/Quaternion Modulus'
//  '<S117>' : 'full_loop/Subsystem ProcNav/Quaternion Rotation1/Quaternion Normalize/Quaternion Modulus/Quaternion Norm'
//  '<S118>' : 'full_loop/Subsystem ProcNav/Quaternions to Rotation Angles/Angle Calculation'
//  '<S119>' : 'full_loop/Subsystem ProcNav/Quaternions to Rotation Angles/Quaternion Normalize'
//  '<S120>' : 'full_loop/Subsystem ProcNav/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input'
//  '<S121>' : 'full_loop/Subsystem ProcNav/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input/If Action Subsystem'
//  '<S122>' : 'full_loop/Subsystem ProcNav/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input/If Action Subsystem1'
//  '<S123>' : 'full_loop/Subsystem ProcNav/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input/If Action Subsystem2'
//  '<S124>' : 'full_loop/Subsystem ProcNav/Quaternions to Rotation Angles/Quaternion Normalize/Quaternion Modulus'
//  '<S125>' : 'full_loop/Subsystem ProcNav/Quaternions to Rotation Angles/Quaternion Normalize/Quaternion Modulus/Quaternion Norm'
//  '<S126>' : 'full_loop/Subsystem Trajectory/MATLAB Function'
//  '<S127>' : 'full_loop/Subsystem Trajectory/Quaternion Rotation'
//  '<S128>' : 'full_loop/Subsystem Trajectory/Quaternion Rotation1'
//  '<S129>' : 'full_loop/Subsystem Trajectory/Quaternion Rotation/Quaternion Normalize'
//  '<S130>' : 'full_loop/Subsystem Trajectory/Quaternion Rotation/V1'
//  '<S131>' : 'full_loop/Subsystem Trajectory/Quaternion Rotation/V2'
//  '<S132>' : 'full_loop/Subsystem Trajectory/Quaternion Rotation/V3'
//  '<S133>' : 'full_loop/Subsystem Trajectory/Quaternion Rotation/Quaternion Normalize/Quaternion Modulus'
//  '<S134>' : 'full_loop/Subsystem Trajectory/Quaternion Rotation/Quaternion Normalize/Quaternion Modulus/Quaternion Norm'
//  '<S135>' : 'full_loop/Subsystem Trajectory/Quaternion Rotation1/Quaternion Normalize'
//  '<S136>' : 'full_loop/Subsystem Trajectory/Quaternion Rotation1/V1'
//  '<S137>' : 'full_loop/Subsystem Trajectory/Quaternion Rotation1/V2'
//  '<S138>' : 'full_loop/Subsystem Trajectory/Quaternion Rotation1/V3'
//  '<S139>' : 'full_loop/Subsystem Trajectory/Quaternion Rotation1/Quaternion Normalize/Quaternion Modulus'
//  '<S140>' : 'full_loop/Subsystem Trajectory/Quaternion Rotation1/Quaternion Normalize/Quaternion Modulus/Quaternion Norm'

#endif                                 // RTW_HEADER_full_loop_h_

//
// File trailer for generated code.
//
// [EOF]
//
