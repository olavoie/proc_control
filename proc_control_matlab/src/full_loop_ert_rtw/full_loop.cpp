//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: full_loop.cpp
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
#include "full_loop.h"
#include "full_loop_private.h"

// Named constants for MATLAB Function: '<S98>/FixedHorizonOptimizer'
const real_T full_loop_nu = 8.0;
const real_T full_loop_ny = 12.0;

// Block signals (default storage)
B_full_loop_T full_loop_B;

// Continuous states
X_full_loop_T full_loop_X;

// Block states (default storage)
DW_full_loop_T full_loop_DW;

// Real-time model
RT_MODEL_full_loop_T full_loop_M_ = RT_MODEL_full_loop_T();
RT_MODEL_full_loop_T *const full_loop_M = &full_loop_M_;

// Forward declaration for local functions
static void full_loop_Gravity(const real_T in1[12], real_T out1[6]);
static s_iyYBPziYRv853Phg0mcgOD_full_T full_loop_factoryConstruct_p
  (KickIn_full_loop_T **objfun_tunableEnvironment);
static void full_loop_factoryConstruct_p4(const real_T Aeq[48],
  sH6xx18cQHI5sgA7Ajla4nE_full__T *obj);
static void full_loop_xswap(int32_T n, const real_T x[441], int32_T ix0, int32_T
  iy0, real_T b_x[441]);
static real_T full_loop_xnrm2(int32_T n, const real_T x[441], int32_T ix0);
static void full_loop_xzlarfg(int32_T n, real_T alpha1, const real_T x[441],
  int32_T ix0, real_T *b_alpha1, real_T b_x[441], real_T *tau);
static void full_loop_xzlarf_p4(int32_T m, int32_T n, int32_T iv0, real_T tau,
  const real_T C[441], int32_T ic0, real_T work[21], real_T b_C[441]);
static void full_loop_qrf_p(const real_T A[441], int32_T m, int32_T n, int32_T
  nfxd, real_T tau[21], real_T b_A[441]);
static int32_T full_loop_ixamax(int32_T n, const real_T x[21], int32_T ix0);
static void full_loop_qrpf_p(const real_T A[441], int32_T m, int32_T n, int32_T
  nfxd, real_T tau[21], int32_T jpvt[21], real_T b_A[441]);
static void full_loop_xgeqp3_p(const real_T A[441], int32_T m, int32_T n,
  int32_T jpvt[21], real_T b_A[441], real_T tau[21]);
static void full_loop_factorQRE(const snaQeDJ4fX7UykrKyr5M8jC_full__T *obj,
  int32_T mrows, int32_T ncols, snaQeDJ4fX7UykrKyr5M8jC_full__T *b_obj);
static void full_loop_xzlarf_p43(int32_T m, int32_T n, int32_T iv0, real_T tau,
  const real_T C[441], int32_T ic0, real_T work[21], real_T b_C[441]);
static void full_loop_computeQ__p(snaQeDJ4fX7UykrKyr5M8jC_full__T *obj, int32_T
  nrows);
static int32_T full__ComputeNumDependentEq__p4(snaQeDJ4fX7UykrKyr5M8jC_full__T
  *qrmanager, const real_T beqf[19]);
static void full_loo_IndexOfDependentEq__p4(int32_T depIdx[6], int32_T nDep,
  snaQeDJ4fX7UykrKyr5M8jC_full__T *qrmanager);
static void full_loop_countsort_p4(int32_T x[6], int32_T xLen, int32_T
  workspace[21]);
static void full__removeDependentLinearEq_p(const real_T Aeq[48], real_T beq[6],
  int32_T idxArray[6], sVTYnQ9ljvmk9dLse9XvTT_full_l_T *memspace,
  s2CPTVnVyv153Hb6bxlki6F_full__T *TrialState, sH6xx18cQHI5sgA7Ajla4nE_full__T
  *WorkingSet, sJdVcLKPgejLYHLePKb6F6D_full__T *QPObjective, int32_T *nDepInd,
  snaQeDJ4fX7UykrKyr5M8jC_full__T *QRManager);
static void full_loop_computeObjective_(KickIn_full_loop_T
  **obj_objfun_tunableEnvironment, const real_T x[8], real_T *fval, int32_T
  *status);
static void evalObjAndConstrAndDerivative_p(KickIn_full_loop_T
  **obj_objfun_tunableEnvironment, const real_T x[8], const real_T
  JacEqTrans_workspace[126], real_T *fval, real_T b_JacEqTrans_workspace[126],
  int32_T *status);
static void full_loop_finDiffEvalAndChkErr(KickIn_full_loop_T
  **obj_objfun_tunableEnvironment, int32_T dim, real_T delta, const real_T xk[8],
  boolean_T *evalOK, real_T *b_fplus, real_T b_xk[8]);
static void ful_computeForwardDifferences_p(s_iyYBPziYRv853Phg0mcgOD_full_T *obj,
  real_T fCurrent, const real_T xk[8], real_T gradf[21], const real_T
  JacCeqTrans[126], boolean_T *evalOK, real_T b_JacCeqTrans[126], real_T b_xk[8]);
static void full__computeLinearResiduals_p4(const real_T x[8], real_T
  workspaceEq[6], int32_T mLinEq, const real_T AeqT[126], const real_T beq[6]);
static void ful_updateWorkingSetForNewQP_p4(sH6xx18cQHI5sgA7Ajla4nE_full__T
  *WorkingSet, int32_T mEq, const real_T cEq[6]);
static void full_loop_setProblemType(const sH6xx18cQHI5sgA7Ajla4nE_full__T *obj,
  int32_T PROBLEM_TYPE, sH6xx18cQHI5sgA7Ajla4nE_full__T *b_obj);
static void full_loop_initActiveSet(const sH6xx18cQHI5sgA7Ajla4nE_full__T *obj,
  sH6xx18cQHI5sgA7Ajla4nE_full__T *b_obj);
static void full_loop_factoryConstruct_p43(real_T fval, const real_T
  Ceq_workspace[6], int32_T mNonlinEq, s6ICcRyulWOFjNCN0ll7VsE_full__T *obj);
static void full_loop_computeGradLag_p4(real_T workspace[21], int32_T nVar,
  const real_T grad[21], int32_T mEq, const real_T AeqTrans[126], const int32_T
  finiteLB[21], int32_T mLB, const real_T lambda[19]);
static void full_loop_computeDualFeasError(int32_T nVar, const real_T gradLag[21],
  boolean_T *gradOK, real_T *val);
static void full_loop_test_exit_p4(s6ICcRyulWOFjNCN0ll7VsE_full__T
  *MeritFunction, const sH6xx18cQHI5sgA7Ajla4nE_full__T *WorkingSet, const
  s2CPTVnVyv153Hb6bxlki6F_full__T *TrialState, s7RdrPWkr8UPAUyTdDJkLaG_full__T
  *Flags, s2CPTVnVyv153Hb6bxlki6F_full__T *b_TrialState);
static void full_loop_saveState(const s2CPTVnVyv153Hb6bxlki6F_full__T *obj,
  s2CPTVnVyv153Hb6bxlki6F_full__T *b_obj);
static void fu_updateWorkingSetForNewQP_p43(sH6xx18cQHI5sgA7Ajla4nE_full__T
  *WorkingSet, int32_T mEq, const real_T cEq[6]);
static void full_loop_updateWorkingSet_p(sH6xx18cQHI5sgA7Ajla4nE_full__T
  *WorkingSet, const s2CPTVnVyv153Hb6bxlki6F_full__T *TrialState);
static void full_loop_snap_bounds_p(s2CPTVnVyv153Hb6bxlki6F_full__T *solution,
  const sH6xx18cQHI5sgA7Ajla4nE_full__T *workingset);
static int32_T full_ComputeNumDependentEq__p43(snaQeDJ4fX7UykrKyr5M8jC_full__T
  *qrmanager, const real_T beqf[19], int32_T mConstr, int32_T nVar);
static void full_loop_factorQRE_p4(snaQeDJ4fX7UykrKyr5M8jC_full__T *obj, const
  real_T A[399], int32_T mrows, int32_T ncols);
static void full_lo_IndexOfDependentEq__p43(int32_T depIdx[21], int32_T mFixed,
  int32_T nDep, snaQeDJ4fX7UykrKyr5M8jC_full__T *qrmanager, const real_T
  AeqfPrime[399], int32_T mRows, int32_T nCols);
static void full_loop_countsort_p43(int32_T x[21], int32_T xLen, int32_T
  workspace[21], int32_T xMin, int32_T xMax);
static void full_loop_removeConstr_p(sH6xx18cQHI5sgA7Ajla4nE_full__T *obj,
  int32_T idx_global);
static void full_loop_removeEqConstr_p(sH6xx18cQHI5sgA7Ajla4nE_full__T *obj,
  int32_T idx_global);
static void full_loop_RemoveDependentEq__p(const real_T
  memspace_workspace_double[441], int32_T memspace_workspace_int[21], int32_T
  memspace_workspace_sort[21], sH6xx18cQHI5sgA7Ajla4nE_full__T *workingset,
  snaQeDJ4fX7UykrKyr5M8jC_full__T *qrmanager, int32_T *nDepInd, real_T
  b_memspace_workspace_double[441]);
static void full_loop_removeAllIneqConstr(const sH6xx18cQHI5sgA7Ajla4nE_full__T *
  obj, sH6xx18cQHI5sgA7Ajla4nE_full__T *b_obj);
static void full_loo_RemoveDependentIneq__p(sH6xx18cQHI5sgA7Ajla4nE_full__T
  *workingset, snaQeDJ4fX7UykrKyr5M8jC_full__T *qrmanager, const real_T
  memspace_workspace_double[441], int32_T memspace_workspace_int[21], int32_T
  memspace_workspace_sort[21], real_T tolfactor, real_T
  b_memspace_workspace_double[441]);
static void full_loop_xgemv_p(int32_T m, int32_T n, const real_T A[399], const
  real_T x[21], const real_T y[441], real_T b_y[441]);
static void full_loop_xgeqrf(const real_T A[441], int32_T m, int32_T n, real_T
  b_A[441], real_T tau[21]);
static void full_loop_factorQR_p4(snaQeDJ4fX7UykrKyr5M8jC_full__T *obj, const
  real_T A[399], int32_T mrows, int32_T ncols);
static void full_loop_xtrsm_p(int32_T m, const real_T A[441], const real_T B[441],
  real_T b_B[441]);
static void full_loop_xgemm_p(int32_T m, int32_T k, const real_T A[441], const
  real_T B[441], const real_T C[441], real_T b_C[441]);
static void full_loop_factorQR(const snaQeDJ4fX7UykrKyr5M8jC_full__T *obj,
  int32_T mrows, int32_T ncols, snaQeDJ4fX7UykrKyr5M8jC_full__T *b_obj);
static void full_loop_xgemm(int32_T m, int32_T k, const real_T A[441], const
  real_T B[441], const real_T C[441], real_T b_C[441]);
static void full_loop_xtrsm(int32_T m, const real_T A[441], const real_T B[441],
  real_T b_B[441]);
static void full_loop_xaxpy(int32_T n, const real_T x[21], const real_T y[441],
  real_T b_y[441]);
static void maxConstraintViolation_AMats_no(const
  sH6xx18cQHI5sgA7Ajla4nE_full__T *obj, const real_T x[441], real_T *v,
  sH6xx18cQHI5sgA7Ajla4nE_full__T *b_obj);
static void maxConstraintViolation_AMats_re(const
  sH6xx18cQHI5sgA7Ajla4nE_full__T *obj, const real_T x[441], real_T *v,
  sH6xx18cQHI5sgA7Ajla4nE_full__T *b_obj);
static void full_loo_maxConstraintViolation(const
  sH6xx18cQHI5sgA7Ajla4nE_full__T *obj, const real_T x[441], real_T *v,
  sH6xx18cQHI5sgA7Ajla4nE_full__T *b_obj);
static void maxConstraintViolation_AMats_p4(const
  sH6xx18cQHI5sgA7Ajla4nE_full__T *obj, const real_T x[441], real_T *v,
  sH6xx18cQHI5sgA7Ajla4nE_full__T *b_obj);
static void maxConstraintViolation_AMats__p(const
  sH6xx18cQHI5sgA7Ajla4nE_full__T *obj, const real_T x[441], real_T *v,
  sH6xx18cQHI5sgA7Ajla4nE_full__T *b_obj);
static void full_l_maxConstraintViolation_p(const
  sH6xx18cQHI5sgA7Ajla4nE_full__T *obj, const real_T x[441], real_T *v,
  sH6xx18cQHI5sgA7Ajla4nE_full__T *b_obj);
static boolean_T full_loop_isfinite(real_T x);
static void full__feasibleX0ForWorkingSet_p(const real_T workspace[441], real_T
  xCurrent[21], sH6xx18cQHI5sgA7Ajla4nE_full__T *workingset,
  snaQeDJ4fX7UykrKyr5M8jC_full__T *qrmanager, boolean_T *nonDegenerateWset,
  real_T b_workspace[441]);
static void maxConstraintViolation_AMa_p43r(const
  sH6xx18cQHI5sgA7Ajla4nE_full__T *obj, const real_T x[21], real_T *v,
  sH6xx18cQHI5sgA7Ajla4nE_full__T *b_obj);
static void maxConstraintViolation_AMat_p43(const
  sH6xx18cQHI5sgA7Ajla4nE_full__T *obj, const real_T x[21], real_T *v,
  sH6xx18cQHI5sgA7Ajla4nE_full__T *b_obj);
static void full__maxConstraintViolation_p4(const
  sH6xx18cQHI5sgA7Ajla4nE_full__T *obj, const real_T x[21], real_T *v,
  sH6xx18cQHI5sgA7Ajla4nE_full__T *b_obj);
static void full_loop_PresolveWorkingSet_p(const s2CPTVnVyv153Hb6bxlki6F_full__T
  *solution, const sVTYnQ9ljvmk9dLse9XvTT_full_l_T *memspace, const
  sH6xx18cQHI5sgA7Ajla4nE_full__T *workingset, const
  snaQeDJ4fX7UykrKyr5M8jC_full__T *qrmanager, s2CPTVnVyv153Hb6bxlki6F_full__T
  *b_solution, sVTYnQ9ljvmk9dLse9XvTT_full_l_T *b_memspace,
  sH6xx18cQHI5sgA7Ajla4nE_full__T *b_workingset, snaQeDJ4fX7UykrKyr5M8jC_full__T
  *b_qrmanager);
static void full_loop_setPhaseOne(const sJdVcLKPgejLYHLePKb6F6D_full__T *obj,
  int32_T NumVars, sJdVcLKPgejLYHLePKb6F6D_full__T *b_obj);
static void full_loop_linearForm_(boolean_T obj_hasLinear, int32_T obj_nvar,
  const real_T workspace[441], const real_T H[64], const real_T f[21], const
  real_T x[21], real_T b_workspace[441]);
static void full_loop_computeFval_p(const sJdVcLKPgejLYHLePKb6F6D_full__T *obj,
  const real_T workspace[441], const real_T H[64], const real_T f[21], const
  real_T x[21], real_T *val, real_T b_workspace[441]);
static void full_loop_xgemv_p43ri(int32_T m, int32_T n, const real_T A[64],
  int32_T lda, const real_T x[21], real_T y[20]);
static void full_loop_computeGrad_StoreHx_p(sJdVcLKPgejLYHLePKb6F6D_full__T *obj,
  const real_T H[64], const real_T f[21], const real_T x[21]);
static void full_loop_computeFval_ReuseHx_p(const
  sJdVcLKPgejLYHLePKb6F6D_full__T *obj, const real_T workspace[441], const
  real_T f[21], const real_T x[21], real_T *val, real_T b_workspace[441]);
static void full_loop_xrotg(real_T a, real_T b, real_T *b_a, real_T *b_b, real_T
  *c, real_T *s);
static void full_loop_squareQ_appendCol_p(snaQeDJ4fX7UykrKyr5M8jC_full__T *obj,
  const real_T vec[399], int32_T iv0);
static void full_loop_xrot_p(int32_T n, const real_T x[441], int32_T ix0,
  int32_T iy0, real_T c, real_T s, real_T b_x[441]);
static void full_loop_xrot(int32_T n, const real_T x[441], int32_T ix0, int32_T
  iy0, real_T c, real_T s, real_T b_x[441]);
static void full_loop_deleteColMoveEnd_p(snaQeDJ4fX7UykrKyr5M8jC_full__T *obj,
  int32_T idx);
static void full_loop_xgemm_p4(int32_T m, int32_T n, int32_T k, const real_T A
  [64], int32_T lda, const real_T B[441], int32_T ib0, const real_T C[441],
  real_T b_C[441]);
static void full_loop_xgemm_p43(int32_T m, int32_T n, int32_T k, const real_T A
  [441], int32_T ia0, const real_T B[441], const real_T C[441], real_T b_C[441]);
static void computeProjectedHessian_regul_p(real_T beta, const real_T H[64],
  int32_T nVarOrig, snl99C5je2zMbU5SzygoX6F_full__T *cholmanager, const
  snaQeDJ4fX7UykrKyr5M8jC_full__T *qrmanager, sVTYnQ9ljvmk9dLse9XvTT_full_l_T
  *memspace);
static void full__computeProjectedHessian_p(const real_T H[64],
  snl99C5je2zMbU5SzygoX6F_full__T *cholmanager, const
  snaQeDJ4fX7UykrKyr5M8jC_full__T *qrmanager, sVTYnQ9ljvmk9dLse9XvTT_full_l_T
  *memspace);
static void full_loop_xpotrf(int32_T n, const real_T A[441], real_T b_A[441],
  int32_T *info);
static void full_loop_factor_p(const real_T obj_FMat[441], int32_T ndims, real_T
  b_obj_FMat[441], int32_T *b_obj_ndims, int32_T *b_obj_info);
static void full_loop_xgemv_p43r(int32_T m, int32_T n, const real_T A[441],
  int32_T ia0, const real_T x[21], const real_T y[441], real_T b_y[441]);
static void full_loop_solve_p(const real_T obj_FMat[441], int32_T obj_ndims,
  int32_T obj_info, const real_T rhs[441], real_T b_rhs[441], real_T b_obj_FMat
  [441], int32_T *b_obj_ndims, int32_T *b_obj_info);
static void full_loop_xgemv_p43rio(int32_T m, int32_T n, const real_T A[441],
  int32_T ia0, const real_T x[441], real_T y[21]);
static void full_loop_factor(const real_T obj_FMat[441], const real_T A[64],
  int32_T ndims, int32_T ldA, real_T b_obj_FMat[441], int32_T *b_obj_ndims,
  int32_T *b_obj_info);
static void full_loop_solve_p4(const real_T obj_FMat[441], int32_T obj_ndims,
  int32_T obj_info, real_T rhs[21], real_T b_obj_FMat[441], int32_T *b_obj_ndims,
  int32_T *b_obj_info);
static void full_loop_compute_deltax_p(const real_T H[64],
  s2CPTVnVyv153Hb6bxlki6F_full__T *solution, sVTYnQ9ljvmk9dLse9XvTT_full_l_T
  *memspace, const snaQeDJ4fX7UykrKyr5M8jC_full__T *qrmanager,
  snl99C5je2zMbU5SzygoX6F_full__T *cholmanager, const
  sJdVcLKPgejLYHLePKb6F6D_full__T *objective, snaQeDJ4fX7UykrKyr5M8jC_full__T
  *b_qrmanager);
static real_T full_loop_xnrm2_p4(int32_T n, const real_T x[21]);
static void full_loop_feasibleratiotest(const real_T solution_xstar[21], const
  real_T solution_searchDir[21], const real_T workspace[441], int32_T
  workingset_nVar, const real_T workingset_lb[21], const int32_T
  workingset_indexLB[21], const int32_T workingset_sizes[5], const int32_T
  workingset_isActiveIdx[6], const boolean_T workingset_isActiveConstr[19],
  const int32_T workingset_nWConstr[5], boolean_T isPhaseOne, real_T *alpha,
  boolean_T *newBlocking, int32_T *constrType, int32_T *constrIdx, real_T
  b_workspace[441]);
static void full_checkUnboundedOrIllPosed_p(s2CPTVnVyv153Hb6bxlki6F_full__T
  *solution, const sJdVcLKPgejLYHLePKb6F6D_full__T *objective);
static void full_addBoundToActiveSetMatrix_(const
  sH6xx18cQHI5sgA7Ajla4nE_full__T *obj, int32_T TYPE, int32_T idx_local,
  sH6xx18cQHI5sgA7Ajla4nE_full__T *b_obj);
static void full_loop_addAineqConstr(const sH6xx18cQHI5sgA7Ajla4nE_full__T *obj,
  int32_T idx_local, sH6xx18cQHI5sgA7Ajla4nE_full__T *b_obj);
static void full_loop_xaxpy_p4(int32_T n, real_T a, const real_T x[21], real_T
  y[21]);
static void full_loop_xgemv(int32_T m, int32_T n, const real_T A[441], const
  real_T x[21], const real_T y[441], real_T b_y[441]);
static void full_loop_compute_lambda_p(const real_T workspace[441],
  s2CPTVnVyv153Hb6bxlki6F_full__T *solution, const
  sJdVcLKPgejLYHLePKb6F6D_full__T *objective, const
  snaQeDJ4fX7UykrKyr5M8jC_full__T *qrmanager, real_T b_workspace[441]);
static int32_T full_loop_find_neg_lambda(const s2CPTVnVyv153Hb6bxlki6F_full__T
  *solution, int32_T workingset_nActiveConstr, const int32_T
  workingset_nWConstr[5]);
static int32_T full_loop_mod(int32_T x);
static void fu_checkStoppingAndUpdateFval_p(int32_T activeSetChangeID, const
  real_T f[21], s2CPTVnVyv153Hb6bxlki6F_full__T *solution,
  sVTYnQ9ljvmk9dLse9XvTT_full_l_T *memspace, const
  sJdVcLKPgejLYHLePKb6F6D_full__T *objective, sH6xx18cQHI5sgA7Ajla4nE_full__T
  *workingset, snaQeDJ4fX7UykrKyr5M8jC_full__T *qrmanager, const
  s1TgE9KstXgkd2qJxO1bF4F_full__T *options, const
  s1TgE9KstXgkd2qJxO1bF4F_full__T *runTimeOptions, boolean_T updateFval, int32_T
  *b_activeSetChangeID, sJdVcLKPgejLYHLePKb6F6D_full__T *b_objective);
static void full_loop_iterate_p(const real_T H[64], const real_T f[21],
  s2CPTVnVyv153Hb6bxlki6F_full__T *solution, sVTYnQ9ljvmk9dLse9XvTT_full_l_T
  *memspace, sH6xx18cQHI5sgA7Ajla4nE_full__T *workingset,
  snaQeDJ4fX7UykrKyr5M8jC_full__T *qrmanager, snl99C5je2zMbU5SzygoX6F_full__T
  *cholmanager, const sJdVcLKPgejLYHLePKb6F6D_full__T *objective, const
  s1TgE9KstXgkd2qJxO1bF4F_full__T *options, const
  s1TgE9KstXgkd2qJxO1bF4F_full__T *runTimeOptions,
  sJdVcLKPgejLYHLePKb6F6D_full__T *b_objective);
static void full_loop_restoreFromPhaseOne(const sJdVcLKPgejLYHLePKb6F6D_full__T *
  obj, sJdVcLKPgejLYHLePKb6F6D_full__T *b_obj);
static void full_loop_phaseone_p(const real_T H[64], const real_T f[21],
  s2CPTVnVyv153Hb6bxlki6F_full__T *solution, sVTYnQ9ljvmk9dLse9XvTT_full_l_T
  *memspace, const sH6xx18cQHI5sgA7Ajla4nE_full__T *workingset, const
  snaQeDJ4fX7UykrKyr5M8jC_full__T *qrmanager, const
  snl99C5je2zMbU5SzygoX6F_full__T *cholmanager, const
  sJdVcLKPgejLYHLePKb6F6D_full__T *objective, s1TgE9KstXgkd2qJxO1bF4F_full__T
  *options, const s1TgE9KstXgkd2qJxO1bF4F_full__T *runTimeOptions,
  sH6xx18cQHI5sgA7Ajla4nE_full__T *b_workingset, snaQeDJ4fX7UykrKyr5M8jC_full__T
  *b_qrmanager, snl99C5je2zMbU5SzygoX6F_full__T *b_cholmanager,
  sJdVcLKPgejLYHLePKb6F6D_full__T *b_objective);
static void full_loop_driver_p43(const real_T H[64], const real_T f[21],
  s2CPTVnVyv153Hb6bxlki6F_full__T *solution, const
  sVTYnQ9ljvmk9dLse9XvTT_full_l_T *memspace, const
  sH6xx18cQHI5sgA7Ajla4nE_full__T *workingset, const
  snaQeDJ4fX7UykrKyr5M8jC_full__T *qrmanager, snl99C5je2zMbU5SzygoX6F_full__T
  *cholmanager, sJdVcLKPgejLYHLePKb6F6D_full__T *objective,
  s1TgE9KstXgkd2qJxO1bF4F_full__T *options, s1TgE9KstXgkd2qJxO1bF4F_full__T
  *runTimeOptions, sVTYnQ9ljvmk9dLse9XvTT_full_l_T *b_memspace,
  sH6xx18cQHI5sgA7Ajla4nE_full__T *b_workingset, snaQeDJ4fX7UykrKyr5M8jC_full__T
  *b_qrmanager);
static void full_loop_restoreWorkingSet_p(sH6xx18cQHI5sgA7Ajla4nE_full__T
  *WorkingSet, const s2CPTVnVyv153Hb6bxlki6F_full__T *TrialState);
static void full_loop_sortLambdaQP_p(real_T lambda[19], int32_T
  WorkingSet_nActiveConstr, const int32_T WorkingSet_sizes[5], const int32_T
  WorkingSet_isActiveIdx[6], const int32_T WorkingSet_Wid[19], const int32_T
  WorkingSet_Wlocalidx[19], const real_T workspace[441], real_T b_workspace[441]);
static void full_loop_addAeqConstr(const sH6xx18cQHI5sgA7Ajla4nE_full__T *obj,
  int32_T idx_local, sH6xx18cQHI5sgA7Ajla4nE_full__T *b_obj);
static void full_loop_soc_p(const real_T Hessian[64], const real_T grad[21],
  s2CPTVnVyv153Hb6bxlki6F_full__T *TrialState, const
  sVTYnQ9ljvmk9dLse9XvTT_full_l_T *memspace, const
  sH6xx18cQHI5sgA7Ajla4nE_full__T *WorkingSet, const
  snaQeDJ4fX7UykrKyr5M8jC_full__T *QRManager, const
  snl99C5je2zMbU5SzygoX6F_full__T *CholManager, const
  sJdVcLKPgejLYHLePKb6F6D_full__T *QPObjective, const
  s1TgE9KstXgkd2qJxO1bF4F_full__T *qpoptions, boolean_T *success, real_T
  b_Hessian[64], sVTYnQ9ljvmk9dLse9XvTT_full_l_T *b_memspace,
  sH6xx18cQHI5sgA7Ajla4nE_full__T *b_WorkingSet, snaQeDJ4fX7UykrKyr5M8jC_full__T
  *b_QRManager, snl99C5je2zMbU5SzygoX6F_full__T *b_CholManager,
  sJdVcLKPgejLYHLePKb6F6D_full__T *b_QPObjective);
static void full_loop_updatePenaltyParam_p4(s6ICcRyulWOFjNCN0ll7VsE_full__T *obj,
  real_T fval, const real_T eq_workspace[6], int32_T mEq, int32_T sqpiter,
  real_T qpval);
static void full_loop_normal_p(const real_T Hessian[64], const real_T grad[21],
  const s2CPTVnVyv153Hb6bxlki6F_full__T *TrialState,
  s6ICcRyulWOFjNCN0ll7VsE_full__T *MeritFunction, const
  sVTYnQ9ljvmk9dLse9XvTT_full_l_T *memspace, const
  sH6xx18cQHI5sgA7Ajla4nE_full__T *WorkingSet, const
  snaQeDJ4fX7UykrKyr5M8jC_full__T *QRManager, const
  snl99C5je2zMbU5SzygoX6F_full__T *CholManager, const
  sJdVcLKPgejLYHLePKb6F6D_full__T *QPObjective, const
  s1TgE9KstXgkd2qJxO1bF4F_full__T *qpoptions, real_T b_Hessian[64],
  s2CPTVnVyv153Hb6bxlki6F_full__T *b_TrialState, sVTYnQ9ljvmk9dLse9XvTT_full_l_T
  *b_memspace, sH6xx18cQHI5sgA7Ajla4nE_full__T *b_WorkingSet,
  snaQeDJ4fX7UykrKyr5M8jC_full__T *b_QRManager, snl99C5je2zMbU5SzygoX6F_full__T *
  b_CholManager, sJdVcLKPgejLYHLePKb6F6D_full__T *b_QPObjective);
static void full__assignResidualsToXSlack_p(int32_T nVarOrig,
  sH6xx18cQHI5sgA7Ajla4nE_full__T *WorkingSet, s2CPTVnVyv153Hb6bxlki6F_full__T
  *TrialState, sVTYnQ9ljvmk9dLse9XvTT_full_l_T *memspace);
static void full_loop_setRegularized_p(sJdVcLKPgejLYHLePKb6F6D_full__T *obj,
  int32_T numQuadVars, real_T beta, real_T rho);
static void full_findActiveSlackLowerBounds(const
  sVTYnQ9ljvmk9dLse9XvTT_full_l_T *memspace, const
  sH6xx18cQHI5sgA7Ajla4nE_full__T *WorkingSet, int32_T *nActiveLBArtificial,
  real_T b_memspace_workspace_double[441], int32_T b_memspace_workspace_int[21],
  int32_T b_memspace_workspace_sort[21]);
static real_T full_loop_xasum(int32_T n, const real_T x[21], int32_T ix0);
static real_T full_loop_xdot(int32_T n, const real_T x[21], int32_T ix0, const
  real_T y[21], int32_T iy0);
static void full_loo_updatePenaltyParam_p43(s6ICcRyulWOFjNCN0ll7VsE_full__T *obj,
  real_T fval, const real_T eq_workspace[6], int32_T mEq, int32_T sqpiter,
  real_T qpval, const real_T x[21], int32_T iReg0, int32_T nRegularized);
static void removeActiveSlackLowerBounds_p(int32_T nActiveLBArtificial,
  s2CPTVnVyv153Hb6bxlki6F_full__T *TrialState, const
  sH6xx18cQHI5sgA7Ajla4nE_full__T *WorkingSet, sH6xx18cQHI5sgA7Ajla4nE_full__T
  *b_WorkingSet);
static void full_loop_setQuadratic_p(sJdVcLKPgejLYHLePKb6F6D_full__T *obj,
  int32_T NumVars);
static int32_T full_loop_ixamax_p4(int32_T n, const real_T x[19]);
static int32_T full_loop_ixamax_p(int32_T n, const real_T x[21]);
static void full_loop_relaxed_p(const real_T Hessian[64], const real_T grad[21],
  const s2CPTVnVyv153Hb6bxlki6F_full__T *TrialState,
  s6ICcRyulWOFjNCN0ll7VsE_full__T *MeritFunction, const
  sVTYnQ9ljvmk9dLse9XvTT_full_l_T *memspace, const
  sH6xx18cQHI5sgA7Ajla4nE_full__T *WorkingSet, const
  snaQeDJ4fX7UykrKyr5M8jC_full__T *QRManager, const
  snl99C5je2zMbU5SzygoX6F_full__T *CholManager, const
  sJdVcLKPgejLYHLePKb6F6D_full__T *QPObjective, s1TgE9KstXgkd2qJxO1bF4F_full__T *
  qpoptions, real_T b_Hessian[64], s2CPTVnVyv153Hb6bxlki6F_full__T *b_TrialState,
  sVTYnQ9ljvmk9dLse9XvTT_full_l_T *b_memspace, sH6xx18cQHI5sgA7Ajla4nE_full__T
  *b_WorkingSet, snaQeDJ4fX7UykrKyr5M8jC_full__T *b_QRManager,
  snl99C5je2zMbU5SzygoX6F_full__T *b_CholManager,
  sJdVcLKPgejLYHLePKb6F6D_full__T *b_QPObjective);
static void full_loop_BFGSReset(const real_T Hessian[64], const real_T grad[21],
  const real_T searchDir[21], real_T b_Hessian[64]);
static void full_loop_step_p4(int32_T STEP_TYPE, const real_T Hessian[64],
  s2CPTVnVyv153Hb6bxlki6F_full__T *TrialState, s6ICcRyulWOFjNCN0ll7VsE_full__T
  *MeritFunction, sVTYnQ9ljvmk9dLse9XvTT_full_l_T *memspace,
  sH6xx18cQHI5sgA7Ajla4nE_full__T *WorkingSet, snaQeDJ4fX7UykrKyr5M8jC_full__T
  *QRManager, snl99C5je2zMbU5SzygoX6F_full__T *CholManager,
  sJdVcLKPgejLYHLePKb6F6D_full__T *QPObjective, s1TgE9KstXgkd2qJxO1bF4F_full__T *
  qpoptions, boolean_T *stepSuccess, int32_T *b_STEP_TYPE, real_T b_Hessian[64]);
static void full_loop_evalObjAndConstr_p(KickIn_full_loop_T
  **obj_objfun_tunableEnvironment, const real_T x[8], real_T *fval, int32_T
  *status);
static void full_computeLinearResiduals_p43(const real_T x[8], int32_T nVar,
  real_T workspaceEq[6], int32_T mLinEq, const real_T AeqT[126], const real_T
  beq[6]);
static real_T full_loop_computeMeritFcn(real_T obj_penaltyParam, real_T fval,
  const real_T Ceq_workspace[6], int32_T mEq, boolean_T evalWellDefined);
static void full_loop_linesearch_p(boolean_T evalWellDefined, const real_T beq[6],
  const sH6xx18cQHI5sgA7Ajla4nE_full__T *WorkingSet,
  s2CPTVnVyv153Hb6bxlki6F_full__T *TrialState, const
  s6ICcRyulWOFjNCN0ll7VsE_full__T *MeritFunction, const
  s_8jIp3wBW8W9AJZ7lDTkICE_full_T FcnEvaluator, boolean_T socTaken, real_T
  *alpha, int32_T *exitflag, boolean_T *b_evalWellDefined);
static void full_loop_revertSolution(const s2CPTVnVyv153Hb6bxlki6F_full__T *obj,
  s2CPTVnVyv153Hb6bxlki6F_full__T *b_obj);
static real_T full_loo_computePrimalFeasError(int32_T mLinEq, const real_T cEq[6]);
static void full_loop_computeGradLag_p(const real_T workspace[441], int32_T nVar,
  const real_T grad[21], int32_T mEq, const real_T AeqTrans[126], const int32_T
  finiteLB[21], int32_T mLB, const real_T lambda[19], real_T b_workspace[441]);
static void full_loo_computeDualFeasError_p(int32_T nVar, const real_T gradLag
  [441], boolean_T *gradOK, real_T *val);
static boolean_T full_loop_isDeltaXTooSmall(const real_T xCurrent[8], const
  real_T delta_x[21], int32_T nVar);
static void full_loop_computeLambdaLSQ_p(int32_T nVar, int32_T mConstr, const
  snaQeDJ4fX7UykrKyr5M8jC_full__T *QRManager, const real_T ATwset[399], const
  real_T grad[21], real_T lambdaLSQ[19], const real_T workspace[441],
  snaQeDJ4fX7UykrKyr5M8jC_full__T *b_QRManager, real_T b_workspace[441]);
static void full_loop_test_exit_p43(boolean_T Flags_fevalOK, boolean_T
  Flags_stepAccepted, boolean_T Flags_failedLineSearch, int32_T Flags_stepType,
  sVTYnQ9ljvmk9dLse9XvTT_full_l_T *memspace, s6ICcRyulWOFjNCN0ll7VsE_full__T
  *MeritFunction, const sH6xx18cQHI5sgA7Ajla4nE_full__T *WorkingSet, const
  s2CPTVnVyv153Hb6bxlki6F_full__T *TrialState, snaQeDJ4fX7UykrKyr5M8jC_full__T
  *QRManager, s7RdrPWkr8UPAUyTdDJkLaG_full__T *b_Flags,
  s2CPTVnVyv153Hb6bxlki6F_full__T *b_TrialState);
static void full_loop_computeDeltaLag_p(int32_T nVar, real_T workspace[21],
  const real_T grad[21], const real_T grad_old[21]);
static void full_loop_BFGSUpdate_p(int32_T nvar, const real_T Bk[64], const
  real_T sk[21], real_T yk[21], const real_T workspace[441], boolean_T *success,
  real_T b_Bk[64], real_T b_workspace[441]);
static void full_loop_driver_p4(const real_T beq[6],
  s2CPTVnVyv153Hb6bxlki6F_full__T *TrialState, const
  s6ICcRyulWOFjNCN0ll7VsE_full__T *MeritFunction,
  s_8jIp3wBW8W9AJZ7lDTkICE_full_T FcnEvaluator, s_iyYBPziYRv853Phg0mcgOD_full_T *
  FiniteDifferences, const sVTYnQ9ljvmk9dLse9XvTT_full_l_T *memspace, const
  sH6xx18cQHI5sgA7Ajla4nE_full__T *WorkingSet, const
  snaQeDJ4fX7UykrKyr5M8jC_full__T *QRManager, sJdVcLKPgejLYHLePKb6F6D_full__T
  *QPObjective, real_T Hessian[64], s6ICcRyulWOFjNCN0ll7VsE_full__T
  *b_MeritFunction, s_8jIp3wBW8W9AJZ7lDTkICE_full_T *b_FcnEvaluator,
  sVTYnQ9ljvmk9dLse9XvTT_full_l_T *b_memspace, sH6xx18cQHI5sgA7Ajla4nE_full__T
  *b_WorkingSet, snaQeDJ4fX7UykrKyr5M8jC_full__T *b_QRManager,
  snl99C5je2zMbU5SzygoX6F_full__T *CholManager);
static void full_loop_fmincon(KickIn_full_loop_T **fun_tunableEnvironment, const
  real_T x0[8], const real_T Aeq[48], const real_T beq[6], real_T x[8]);
static void full_loop_AUVStateJacobianFcn(const real_T in1[12], real_T A[144],
  real_T B[96], real_T C[144], real_T D[96]);
static void full_loop_xgetrf(const real_T A[400], real_T b_A[400], int32_T ipiv
  [20], int32_T *info);
static void full_loop_lusolve(const real_T A[400], const real_T B[400], real_T
  X[400]);
static void full_lo_PadeApproximantOfDegree(const real_T A[400], uint8_T m,
  real_T F[400]);
static void full_loop_expm(real_T A[400], real_T F[400]);
static void full_loop_TrimPlant_stepImpl(TrimPlant_full_loop_T *b_this, const
  real_T u[8], real_T Ts, const real_T y[12], real_T A[144], real_T B[96],
  real_T C[144], real_T D[96], real_T U[8], real_T Y[12], real_T X[12], real_T
  DX[12]);
static void full_loop_SystemCore_step(TrimPlant_full_loop_T *obj, const real_T
  varargin_1[8], real_T varargin_2, const real_T varargin_3[12], real_T
  varargout_1[144], real_T varargout_2[96], real_T varargout_3[144], real_T
  varargout_4[96], real_T varargout_5[8], real_T varargout_6[12], real_T
  varargout_7[12], real_T varargout_8[12]);
static void full_loop_mpc_plantupdate(const real_T a[144], real_T b[96], const
  real_T c[144], real_T b_A[400], real_T b_B[580], real_T b_C[240], const real_T
  b_D[348], const real_T b_mvindex[8], const real_T b_myindex[12], const real_T
  b_Uscale[8], const real_T b_Yscale[12], real_T Bu[160], real_T Bv[20], real_T
  Cm[240], real_T Dv[12], real_T Dvm[12], real_T QQ[400], real_T RR[144], real_T
  NN[240]);
static real_T full_loop_mod_id(real_T x);
static real_T full_loop_mod_i(real_T x);
static void full_loop_mpc_updateFromNominal(real_T b_Mlim[4], const real_T
  b_Mrows[4], const real_T U0[8], const real_T b_Uscale[8], const real_T
  old_mvoff[8], const real_T b_mvindex[8], real_T b_utarget[80], const real_T
  Y0[12], const real_T b_Yscale[12], const real_T old_yoff[12], const real_T
  b_myindex[12], const real_T X0[12], real_T b_xoff[20], const real_T DX0[12],
  real_T Bv[220], real_T new_mvoff[8], real_T new_yoff[12], real_T new_myoff[12]);
static void full_loop_mpcblock_refmd(const real_T ref[12], const real_T b_yoff
  [12], const real_T b_RYscale[12], real_T rseq[120], real_T vseq[11], real_T *v);
static void full_loop_eye(real_T b_I[144]);
static void full_loop_mpc_constraintcoef(const real_T b_A[400], const real_T Bu
  [1760], const real_T Bv[220], const real_T b_C[240], const real_T Dv[132],
  const real_T b_Jm[1280], real_T b_SuJm[1920], real_T b_Sx[2400], real_T b_Su1
  [960], real_T b_Hv[1320]);
static void full_loop_eye_c(real_T b_I[64]);
static void full_loop_kron(const real_T b_A[100], const real_T b_B[64], real_T
  K[6400]);
static void full_loop_WtMult(const real_T W[8], const real_T M[1280], real_T nwt,
  real_T WM[1280]);
static void full_loop_mpc_calculatehessian(const real_T b_Wy[12], const real_T
  b_Wu[8], const real_T b_Wdu[8], const real_T b_SuJm[1920], const real_T I2Jm
  [1280], const real_T b_Jm[1280], const real_T b_I1[640], const real_T b_Su1
  [960], const real_T b_Sx[2400], const real_T b_Hv[1320], real_T nmv, real_T
  b_ny, real_T b_H[256], real_T b_Ku1[128], real_T b_Kut[1280], real_T b_Kx[320],
  real_T b_Kv[176], real_T b_Kr[1920]);
static int32_T full_loop_xpotrf_j(real_T b_A[289]);
static void full_loop_diag(const real_T v[289], real_T d[17]);
static real_T full_loop_norm(const real_T x[289]);
static void full_loop_eye_cb(real_T b_I[289]);
static void full_loop_mpc_checkhessian(real_T b_H[289], real_T L[289], real_T
  *BadH);
static void full_loop_eye_cbt(real_T b_I[289]);
static void full_loop_trisolve(const real_T b_A[289], real_T b_B[289]);
static void full_loop_linsolve(const real_T b_A[289], const real_T b_B[289],
  real_T b_C[289]);
static void full_loop_Unconstrained(const real_T b_Hinv[289], const real_T f[17],
  real_T x[17], int16_T n);
static real_T full_loop_norm_i(const real_T x[17]);
static void full_loop_abs(const real_T x[17], real_T y[17]);
static void full_loop_abs_d(const real_T x[4], real_T y[4]);
static real_T full_loop_xnrm2_a(int32_T n, const real_T x[289], int32_T ix0);
static real_T full_loop_xzlarfg_j(int32_T n, real_T *alpha1, real_T x[289],
  int32_T ix0);
static void full_loop_xgemv_pz(int32_T m, int32_T n, const real_T b_A[289],
  int32_T ia0, const real_T x[289], int32_T ix0, real_T y[17]);
static void full_loop_xgerc(int32_T m, int32_T n, real_T alpha1, int32_T ix0,
  const real_T y[17], real_T b_A[289], int32_T ia0);
static void full_loop_xzlarf_d(int32_T m, int32_T n, int32_T iv0, real_T tau,
  real_T b_C[289], int32_T ic0, real_T work[17]);
static void full_loop_qrf_l(real_T b_A[289], int32_T ia0, int32_T m, int32_T n,
  int32_T nfxd, real_T tau[17]);
static void full_loop_xgeqrf_l(real_T b_A[289], real_T tau[17]);
static void full_loop_qr(const real_T b_A[289], real_T Q[289], real_T R[289]);
static real_T full_loop_KWIKfactor(const real_T b_Ac[68], const int16_T iC[4],
  int16_T nA, const real_T b_Linv[289], real_T RLinv[289], real_T b_D[289],
  real_T b_H[289], int16_T n);
static void full_loop_DropConstraint(int16_T kDrop, int16_T iA[4], int16_T *nA,
  int16_T iC[4]);
static void full_loop_qpkwik(const real_T b_Linv[289], const real_T b_Hinv[289],
  const real_T f[17], const real_T b_Ac[68], const real_T b[4], int16_T iA[4],
  int16_T maxiter, real_T FeasTol, real_T x[17], real_T lambda[4], real_T
  *status);
static void full_loop_mpc_solveQP(const real_T xQP[20], const real_T b_Kx[320],
  const real_T b_Kr[1920], const real_T rseq[120], const real_T b_Ku1[128],
  const real_T old_u[8], const real_T b_Kv[176], const real_T vseq[11], const
  real_T b_Kut[1280], const real_T b_utarget[80], const real_T b_Linv[289],
  const real_T b_Hinv[289], const real_T b_Ac[68], const real_T Bc[4], boolean_T
  iA[4], real_T zopt[17], real_T f[17], real_T *status);
static void full_loop_mpcblock_optimizer(const real_T rseq[120], const real_T
  vseq[11], const real_T umin[8], const real_T umax[8], const real_T x[20],
  const real_T old_u[8], const boolean_T iA[4], const real_T b_Mlim[4], real_T
  b_Mx[80], real_T b_Mu1[32], real_T b_Mv[44], const real_T b_utarget[80], const
  real_T b_uoff[8], real_T b_H[289], real_T b_Ac[68], const real_T b_Wy[12],
  const real_T b_Wdu[8], const real_T b_Jm[1280], const real_T b_Wu[8], const
  real_T b_I1[640], const real_T b_A[400], const real_T Bu[1760], const real_T
  Bv[220], const real_T b_C[240], const real_T Dv[132], const real_T b_Mrows[4],
  real_T u[8], real_T useq[88], real_T *status, boolean_T iAout[4]);
static void rt_mrdivide_U1d1x3_U2d_9vOrDY_p(const real_T u0[3], const real_T u1
  [9], real_T y[3]);
static void matlabCodegenHandle_matlabCodeg(ros_slros_internal_block_Publ_T *obj);
static void rate_scheduler(void);
uint32_T plook_u32d_binckan(real_T u, const real_T bp[], uint32_T maxIndex)
{
  uint32_T bpIndex;

  // Prelookup - Index only
  // Index Search method: 'binary'
  // Interpolation method: 'Use nearest'
  // Extrapolation method: 'Clip'
  // Use previous index: 'off'
  // Use last breakpoint for index at or above upper limit: 'on'
  // Remove protection against out-of-range input in generated code: 'off'

  if (u <= bp[0U]) {
    bpIndex = 0U;
  } else if (u < bp[maxIndex]) {
    bpIndex = binsearch_u32d(u, bp, maxIndex >> 1U, maxIndex);
    if ((bpIndex < maxIndex) && (bp[bpIndex + 1U] - u <= u - bp[bpIndex])) {
      bpIndex++;
    }
  } else {
    bpIndex = maxIndex;
  }

  return bpIndex;
}

uint32_T binsearch_u32d(real_T u, const real_T bp[], uint32_T startIndex,
  uint32_T maxIndex)
{
  uint32_T bpIndex;
  uint32_T iRght;
  uint32_T bpIdx;

  // Binary Search
  bpIdx = startIndex;
  bpIndex = 0U;
  iRght = maxIndex;
  while (iRght - bpIndex > 1U) {
    if (u < bp[bpIdx]) {
      iRght = bpIdx;
    } else {
      bpIndex = bpIdx;
    }

    bpIdx = (iRght + bpIndex) >> 1U;
  }

  return bpIndex;
}

//
//   This function updates active task flag for each subrate.
// The function is called at model base rate, hence the
// generated code self-manages all its subrates.
//
static void rate_scheduler(void)
{
  // Compute which subrates run during the next base time step.  Subrates
  //  are an integer multiple of the base rate counter.  Therefore, the subtask
  //  counter is reset when it reaches its limit (zero means run).

  (full_loop_M->Timing.TaskCounters.TID[2])++;
  if ((full_loop_M->Timing.TaskCounters.TID[2]) > 1) {// Sample time: [0.01s, 0.0s] 
    full_loop_M->Timing.TaskCounters.TID[2] = 0;
  }

  (full_loop_M->Timing.TaskCounters.TID[3])++;
  if ((full_loop_M->Timing.TaskCounters.TID[3]) > 3) {// Sample time: [0.02s, 0.0s] 
    full_loop_M->Timing.TaskCounters.TID[3] = 0;
  }

  (full_loop_M->Timing.TaskCounters.TID[4])++;
  if ((full_loop_M->Timing.TaskCounters.TID[4]) > 19) {// Sample time: [0.1s, 0.0s] 
    full_loop_M->Timing.TaskCounters.TID[4] = 0;
  }
}

//
// This function updates continuous states using the ODE3 fixed-step
// solver algorithm
//
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  // Solver Matrices
  static const real_T rt_ODE3_A[3] = {
    1.0/2.0, 3.0/4.0, 1.0
  };

  static const real_T rt_ODE3_B[3][3] = {
    { 1.0/2.0, 0.0, 0.0 },

    { 0.0, 3.0/4.0, 0.0 },

    { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE3_IntgData *id = static_cast<ODE3_IntgData *>(rtsiGetSolverData(si));
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T hB[3];
  int_T i;
  int_T nXc = 16;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  // Save the state values at time t in y, we'll use x as ynew.
  (void) memcpy(y, x,
                static_cast<uint_T>(nXc)*sizeof(real_T));

  // Assumes that rtsiSetT and ModelOutputs are up-to-date
  // f0 = f(t,y)
  rtsiSetdX(si, f0);
  full_loop_derivatives();

  // f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*));
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  full_loop_step();
  full_loop_derivatives();

  // f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*));
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  full_loop_step();
  full_loop_derivatives();

  // tnew = t + hA(3);
  // ynew = y + f*hB(:,3);
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

real_T rt_atan2d_snf(real_T u0, real_T u1)
{
  real_T y;
  int32_T u0_0;
  int32_T u1_0;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else if (rtIsInf(u0) && rtIsInf(u1)) {
    if (u0 > 0.0) {
      u0_0 = 1;
    } else {
      u0_0 = -1;
    }

    if (u1 > 0.0) {
      u1_0 = 1;
    } else {
      u1_0 = -1;
    }

    y = atan2(static_cast<real_T>(u0_0), static_cast<real_T>(u1_0));
  } else if (u1 == 0.0) {
    if (u0 > 0.0) {
      y = RT_PI / 2.0;
    } else if (u0 < 0.0) {
      y = -(RT_PI / 2.0);
    } else {
      y = 0.0;
    }
  } else {
    y = atan2(u0, u1);
  }

  return y;
}

static void full_loop_Gravity(const real_T in1[12], real_T out1[6])
{
  real_T t36;
  real_T t40;
  real_T t43;
  real_T t47;
  real_T t50;
  real_T out1_tmp;

  // GRAVITY
  //     OUT1 = GRAVITY(IN1)
  //     This function was generated by the Symbolic Math Toolbox version 8.5.
  //     15-Jan-2021 09:02:27
  full_loop_B.t5 = in1[3] / 2.0;
  full_loop_B.t6_f = in1[5] / 2.0;
  full_loop_B.t7_a = in1[4] / 2.0;
  full_loop_B.t8_g = in1[3] / 2.0;
  full_loop_B.t9_n = cos(full_loop_B.t5);
  full_loop_B.t10_d = in1[5] / 2.0;
  full_loop_B.t11_n = cos(full_loop_B.t6_f);
  full_loop_B.t12_c = in1[4] / 2.0;
  full_loop_B.t13_f = cos(full_loop_B.t7_a);
  full_loop_B.t5 = sin(full_loop_B.t5);
  full_loop_B.t15 = sin(full_loop_B.t6_f);
  full_loop_B.t16 = sin(full_loop_B.t7_a);
  full_loop_B.t6_f = cos(full_loop_B.t8_g);
  full_loop_B.t18_p = cos(full_loop_B.t10_d);
  full_loop_B.t19_p = cos(full_loop_B.t12_c);
  full_loop_B.t20_n = sin(full_loop_B.t8_g);
  full_loop_B.t21_kt = sin(full_loop_B.t10_d);
  full_loop_B.t22_n = sin(full_loop_B.t12_c);
  t36 = full_loop_B.t9_n * full_loop_B.t11_n;
  full_loop_B.t10_d = t36 * full_loop_B.t16;
  full_loop_B.t12_c = full_loop_B.t9_n * full_loop_B.t13_f * full_loop_B.t15;
  full_loop_B.t8_g = full_loop_B.t11_n * full_loop_B.t13_f * full_loop_B.t5;
  full_loop_B.t9_n = full_loop_B.t9_n * full_loop_B.t15 * full_loop_B.t16;
  full_loop_B.t11_n = full_loop_B.t11_n * full_loop_B.t5 * full_loop_B.t16;
  full_loop_B.t7_a = full_loop_B.t13_f * full_loop_B.t5 * full_loop_B.t15;
  full_loop_B.t5 = full_loop_B.t5 * full_loop_B.t15 * full_loop_B.t16;
  full_loop_B.t15 = t36 * full_loop_B.t13_f;
  full_loop_B.t16 = full_loop_B.t6_f * full_loop_B.t18_p * full_loop_B.t22_n;
  t36 = full_loop_B.t6_f * full_loop_B.t19_p * full_loop_B.t21_kt;
  full_loop_B.t13_f = full_loop_B.t18_p * full_loop_B.t19_p * full_loop_B.t20_n;
  full_loop_B.t6_f = full_loop_B.t6_f * full_loop_B.t21_kt * full_loop_B.t22_n;
  full_loop_B.t18_p = full_loop_B.t18_p * full_loop_B.t20_n * full_loop_B.t22_n;
  t40 = full_loop_B.t19_p * full_loop_B.t20_n * full_loop_B.t21_kt;
  t43 = full_loop_B.t10_d + full_loop_B.t7_a;
  full_loop_B.t20_n = full_loop_B.t5 + full_loop_B.t15;
  full_loop_B.t19_p = full_loop_B.t8_g + -full_loop_B.t9_n;
  t47 = full_loop_B.t5 * 2.0 + full_loop_B.t15 * 2.0;
  full_loop_B.t20_n *= full_loop_B.t20_n;
  t50 = t36 + -full_loop_B.t18_p;
  full_loop_B.t21_kt = t43 * t47;
  full_loop_B.t22_n = full_loop_B.t19_p * t50;
  out1[0] = full_loop_B.t21_kt * 29.19456 - full_loop_B.t22_n * 58.38912;
  out1_tmp = t43 * t50;
  t47 *= full_loop_B.t19_p;
  out1[1] = out1_tmp * -58.38912 - t47 * 29.19456;
  out1[2] = (((((((((((((full_loop_B.t10_d * full_loop_B.t7_a * -58.38912 +
    full_loop_B.t10_d * full_loop_B.t16 * 29.19456) - full_loop_B.t12_c * t36 *
                        29.19456) + full_loop_B.t8_g * full_loop_B.t13_f *
                       29.19456) + full_loop_B.t10_d * t40 * 29.19456) +
                     full_loop_B.t12_c * full_loop_B.t18_p * 29.19456) -
                    full_loop_B.t8_g * full_loop_B.t6_f * 29.19456) -
                   full_loop_B.t9_n * full_loop_B.t13_f * 29.19456) +
                  full_loop_B.t11_n * t36 * 29.19456) + full_loop_B.t7_a *
                 full_loop_B.t16 * 29.19456) + full_loop_B.t9_n *
                full_loop_B.t6_f * 29.19456) - full_loop_B.t11_n *
               full_loop_B.t18_p * 29.19456) + full_loop_B.t7_a * t40 * 29.19456)
             - full_loop_B.t5 * full_loop_B.t5 * 29.19456) - full_loop_B.t15 *
    full_loop_B.t15 * 29.19456;
  full_loop_B.t10_d = t43 * (full_loop_B.t16 + t40);
  full_loop_B.t12_c = (full_loop_B.t12_c + -full_loop_B.t11_n) * t50;
  full_loop_B.t8_g = full_loop_B.t19_p * (full_loop_B.t13_f + -full_loop_B.t6_f);
  out1[3] = ((((full_loop_B.t20_n * 0.08758368 - full_loop_B.t10_d * 0.08758368)
               + out1_tmp * 1.57650624) + t47 * 0.78825312) + full_loop_B.t12_c *
             0.08758368) - full_loop_B.t8_g * 0.08758368;
  out1[4] = ((((full_loop_B.t21_kt * 0.78825312 + full_loop_B.t20_n * 0.02919456)
               - full_loop_B.t10_d * 0.02919456) + full_loop_B.t12_c *
              0.02919456) - full_loop_B.t22_n * 1.57650624) - full_loop_B.t8_g *
    0.02919456;
  out1[5] = ((full_loop_B.t21_kt * 0.08758368 - out1_tmp * 0.05838912) - t47 *
             0.02919456) - full_loop_B.t22_n * 0.17516736;
}

static s_iyYBPziYRv853Phg0mcgOD_full_T full_loop_factoryConstruct_p
  (KickIn_full_loop_T **objfun_tunableEnvironment)
{
  s_iyYBPziYRv853Phg0mcgOD_full_T obj;
  int32_T idx;
  obj.objfun.tunableEnvironment = *objfun_tunableEnvironment;
  obj.f_1 = 0.0;
  obj.f_2 = 0.0;
  obj.nVar = 8;
  obj.mIneq = 0;
  obj.mEq = 0;
  obj.numEvals = 0;
  obj.SpecifyObjectiveGradient = false;
  obj.SpecifyConstraintGradient = false;
  obj.FiniteDifferenceType = 0;
  for (idx = 0; idx < 8; idx++) {
    obj.hasLB[idx] = false;
    obj.hasUB[idx] = false;
  }

  obj.hasBounds = false;
  return obj;
}

static void full_loop_factoryConstruct_p4(const real_T Aeq[48],
  sH6xx18cQHI5sgA7Ajla4nE_full__T *obj)
{
  int32_T b_idx_row;
  int32_T x[6];
  int8_T obj_tmp[5];
  int32_T i;
  static const int8_T tmp[6] = { 1, 0, 6, 0, 0, 0 };

  static const int8_T tmp_0[6] = { 1, 0, 6, 0, 1, 0 };

  static const int8_T tmp_1[6] = { 1, 0, 6, 0, 12, 0 };

  static const int8_T tmp_2[6] = { 1, 0, 6, 0, 13, 0 };

  obj->mConstr = 6;
  obj->mConstrOrig = 6;
  obj->mConstrMax = 19;
  obj->nVar = 8;
  obj->nVarOrig = 8;
  obj->nVarMax = 21;
  obj->ldA = 21;
  obj->mEqRemoved = 0;
  obj->nActiveConstr = 0;
  obj_tmp[0] = 0;
  obj_tmp[1] = 6;
  obj_tmp[2] = 0;
  obj_tmp[3] = 0;
  obj_tmp[4] = 0;
  for (i = 0; i < 5; i++) {
    obj->sizes[i] = obj_tmp[i];
    obj->sizesNormal[i] = obj_tmp[i];
  }

  obj->sizesPhaseOne[0] = 0;
  obj->sizesPhaseOne[1] = 6;
  obj->sizesPhaseOne[2] = 0;
  obj->sizesPhaseOne[3] = 1;
  obj->sizesPhaseOne[4] = 0;
  obj->sizesRegularized[0] = 0;
  obj->sizesRegularized[1] = 6;
  obj->sizesRegularized[2] = 0;
  obj->sizesRegularized[3] = 12;
  obj->sizesRegularized[4] = 0;
  obj->sizesRegPhaseOne[0] = 0;
  obj->sizesRegPhaseOne[1] = 6;
  obj->sizesRegPhaseOne[2] = 0;
  obj->sizesRegPhaseOne[3] = 13;
  obj->sizesRegPhaseOne[4] = 0;
  for (i = 0; i < 6; i++) {
    x[i] = tmp[i];
  }

  for (i = 0; i < 5; i++) {
    x[i + 1] += x[i];
  }

  for (i = 0; i < 6; i++) {
    obj->isActiveIdx[i] = x[i];
    x[i] = tmp[i];
  }

  for (i = 0; i < 5; i++) {
    x[i + 1] += x[i];
  }

  for (i = 0; i < 6; i++) {
    obj->isActiveIdxNormal[i] = x[i];
    x[i] = tmp_0[i];
  }

  for (i = 0; i < 5; i++) {
    x[i + 1] += x[i];
  }

  for (i = 0; i < 6; i++) {
    obj->isActiveIdxPhaseOne[i] = x[i];
    x[i] = tmp_1[i];
  }

  for (i = 0; i < 5; i++) {
    x[i + 1] += x[i];
  }

  for (i = 0; i < 6; i++) {
    obj->isActiveIdxRegularized[i] = x[i];
    x[i] = tmp_2[i];
  }

  for (i = 0; i < 5; i++) {
    x[i + 1] += x[i];
  }

  for (i = 0; i < 6; i++) {
    obj->isActiveIdxRegPhaseOne[i] = x[i];
  }

  for (i = 0; i < 5; i++) {
    obj->nWConstr[i] = 0;
  }

  obj->probType = 3;
  obj->SLACK0 = 1.0E-5;
  for (i = 0; i < 6; i++) {
    for (b_idx_row = 0; b_idx_row < 8; b_idx_row++) {
      obj->Aeq[b_idx_row + 21 * i] = Aeq[6 * b_idx_row + i];
    }
  }
}

static void full_loop_xswap(int32_T n, const real_T x[441], int32_T ix0, int32_T
  iy0, real_T b_x[441])
{
  int32_T ix;
  int32_T iy;
  real_T temp;
  int32_T k;
  memcpy(&b_x[0], &x[0], 441U * sizeof(real_T));
  ix = ix0 - 1;
  iy = iy0 - 1;
  for (k = 0; k < n; k++) {
    temp = b_x[ix];
    b_x[ix] = b_x[iy];
    b_x[iy] = temp;
    ix++;
    iy++;
  }
}

static real_T full_loop_xnrm2(int32_T n, const real_T x[441], int32_T ix0)
{
  real_T y;
  int32_T kend;
  int32_T k;
  y = 0.0;
  if (n >= 1) {
    if (n == 1) {
      y = fabs(x[ix0 - 1]);
    } else {
      full_loop_B.scale = 3.3121686421112381E-170;
      kend = ix0 + n;
      for (k = ix0; k < kend; k++) {
        full_loop_B.absxk = fabs(x[k - 1]);
        if (full_loop_B.absxk > full_loop_B.scale) {
          full_loop_B.t_h = full_loop_B.scale / full_loop_B.absxk;
          y = y * full_loop_B.t_h * full_loop_B.t_h + 1.0;
          full_loop_B.scale = full_loop_B.absxk;
        } else {
          full_loop_B.t_h = full_loop_B.absxk / full_loop_B.scale;
          y += full_loop_B.t_h * full_loop_B.t_h;
        }
      }

      y = full_loop_B.scale * sqrt(y);
    }
  }

  return y;
}

real_T rt_hypotd_snf(real_T u0, real_T u1)
{
  real_T y;
  real_T a;
  a = fabs(u0);
  y = fabs(u1);
  if (a < y) {
    a /= y;
    y *= sqrt(a * a + 1.0);
  } else if (a > y) {
    y /= a;
    y = sqrt(y * y + 1.0) * a;
  } else {
    if (!rtIsNaN(y)) {
      y = a * 1.4142135623730951;
    }
  }

  return y;
}

static void full_loop_xzlarfg(int32_T n, real_T alpha1, const real_T x[441],
  int32_T ix0, real_T *b_alpha1, real_T b_x[441], real_T *tau)
{
  int32_T knt;
  int32_T k;
  int32_T b_tmp;
  memcpy(&b_x[0], &x[0], 441U * sizeof(real_T));
  *b_alpha1 = alpha1;
  *tau = 0.0;
  if (n > 0) {
    full_loop_B.xnorm = full_loop_xnrm2(n - 1, x, ix0);
    if (full_loop_B.xnorm != 0.0) {
      full_loop_B.xnorm = rt_hypotd_snf(alpha1, full_loop_B.xnorm);
      if (alpha1 >= 0.0) {
        full_loop_B.xnorm = -full_loop_B.xnorm;
      }

      if (fabs(full_loop_B.xnorm) < 1.0020841800044864E-292) {
        knt = -1;
        b_tmp = ix0 + n;
        do {
          knt++;
          for (k = ix0; k <= b_tmp - 2; k++) {
            b_x[k - 1] *= 9.9792015476736E+291;
          }

          full_loop_B.xnorm *= 9.9792015476736E+291;
          *b_alpha1 *= 9.9792015476736E+291;
        } while (!(fabs(full_loop_B.xnorm) >= 1.0020841800044864E-292));

        full_loop_B.xnorm = rt_hypotd_snf(*b_alpha1, full_loop_xnrm2(n - 1, b_x,
          ix0));
        if (*b_alpha1 >= 0.0) {
          full_loop_B.xnorm = -full_loop_B.xnorm;
        }

        *tau = (full_loop_B.xnorm - *b_alpha1) / full_loop_B.xnorm;
        *b_alpha1 = 1.0 / (*b_alpha1 - full_loop_B.xnorm);
        for (k = ix0; k <= b_tmp - 2; k++) {
          b_x[k - 1] *= *b_alpha1;
        }

        for (k = 0; k <= knt; k++) {
          full_loop_B.xnorm *= 1.0020841800044864E-292;
        }

        *b_alpha1 = full_loop_B.xnorm;
      } else {
        *tau = (full_loop_B.xnorm - alpha1) / full_loop_B.xnorm;
        *b_alpha1 = 1.0 / (alpha1 - full_loop_B.xnorm);
        knt = ix0 + n;
        for (k = ix0; k <= knt - 2; k++) {
          b_x[k - 1] *= *b_alpha1;
        }

        *b_alpha1 = full_loop_B.xnorm;
      }
    }
  }
}

static void full_loop_xzlarf_p4(int32_T m, int32_T n, int32_T iv0, real_T tau,
  const real_T C[441], int32_T ic0, real_T work[21], real_T b_C[441])
{
  int32_T lastc;
  int32_T coltop;
  int32_T ia;
  int32_T iac;
  int32_T d;
  int32_T jA;
  int32_T jy;
  int32_T exitg1;
  boolean_T exitg2;
  memcpy(&b_C[0], &C[0], 441U * sizeof(real_T));
  if (tau != 0.0) {
    full_loop_B.lastv_h = m;
    lastc = (iv0 + m) - 2;
    while ((full_loop_B.lastv_h > 0) && (C[lastc] == 0.0)) {
      full_loop_B.lastv_h--;
      lastc--;
    }

    lastc = n;
    exitg2 = false;
    while ((!exitg2) && (lastc > 0)) {
      coltop = (lastc - 1) * 21 + ic0;
      ia = coltop;
      do {
        exitg1 = 0;
        if (ia <= (coltop + full_loop_B.lastv_h) - 1) {
          if (C[ia - 1] != 0.0) {
            exitg1 = 1;
          } else {
            ia++;
          }
        } else {
          lastc--;
          exitg1 = 2;
        }
      } while (exitg1 == 0);

      if (exitg1 == 1) {
        exitg2 = true;
      }
    }

    lastc--;
  } else {
    full_loop_B.lastv_h = 0;
    lastc = -1;
  }

  if (full_loop_B.lastv_h > 0) {
    if (lastc + 1 != 0) {
      if (0 <= lastc) {
        memset(&work[0], 0, (lastc + 1) * sizeof(real_T));
      }

      jA = 0;
      jy = 21 * lastc + ic0;
      for (iac = ic0; iac <= jy; iac += 21) {
        coltop = iv0 - 1;
        full_loop_B.c_l = 0.0;
        d = iac + full_loop_B.lastv_h;
        for (ia = iac; ia < d; ia++) {
          full_loop_B.c_l += b_C[ia - 1] * b_C[coltop];
          coltop++;
        }

        work[jA] += full_loop_B.c_l;
        jA++;
      }
    }

    if (!(-tau == 0.0)) {
      jA = ic0;
      jy = 0;
      for (ia = 0; ia <= lastc; ia++) {
        if (work[jy] != 0.0) {
          full_loop_B.c_l = work[jy] * -tau;
          coltop = iv0 - 1;
          d = (full_loop_B.lastv_h + jA) - 1;
          for (iac = jA; iac <= d; iac++) {
            b_C[iac - 1] += b_C[coltop] * full_loop_B.c_l;
            coltop++;
          }
        }

        jy++;
        jA += 21;
      }
    }
  }
}

static void full_loop_qrf_p(const real_T A[441], int32_T m, int32_T n, int32_T
  nfxd, real_T tau[21], real_T b_A[441])
{
  memcpy(&b_A[0], &A[0], 441U * sizeof(real_T));
  memset(&full_loop_B.work[0], 0, 21U * sizeof(real_T));
  for (full_loop_B.b_i_cs = 0; full_loop_B.b_i_cs < nfxd; full_loop_B.b_i_cs++)
  {
    full_loop_B.ii = full_loop_B.b_i_cs * 21 + full_loop_B.b_i_cs;
    full_loop_B.mmi_o = m - full_loop_B.b_i_cs;
    if (full_loop_B.b_i_cs + 1 < m) {
      memcpy(&full_loop_B.b_A[0], &b_A[0], 441U * sizeof(real_T));
      full_loop_xzlarfg(full_loop_B.mmi_o, b_A[full_loop_B.ii], full_loop_B.b_A,
                        full_loop_B.ii + 2, &full_loop_B.b_atmp, b_A,
                        &tau[full_loop_B.b_i_cs]);
      b_A[full_loop_B.ii] = full_loop_B.b_atmp;
    } else {
      tau[full_loop_B.b_i_cs] = 0.0;
    }

    if (full_loop_B.b_i_cs + 1 < n) {
      full_loop_B.b_atmp = b_A[full_loop_B.ii];
      b_A[full_loop_B.ii] = 1.0;
      memcpy(&full_loop_B.b_A[0], &b_A[0], 441U * sizeof(real_T));
      full_loop_xzlarf_p4(full_loop_B.mmi_o, (n - full_loop_B.b_i_cs) - 1,
                          full_loop_B.ii + 1, tau[full_loop_B.b_i_cs],
                          full_loop_B.b_A, full_loop_B.ii + 22, full_loop_B.work,
                          b_A);
      b_A[full_loop_B.ii] = full_loop_B.b_atmp;
    }
  }
}

static int32_T full_loop_ixamax(int32_T n, const real_T x[21], int32_T ix0)
{
  int32_T idxmax;
  int32_T ix;
  real_T smax;
  real_T s;
  int32_T k;
  if (n < 1) {
    idxmax = 0;
  } else {
    idxmax = 1;
    if (n > 1) {
      ix = ix0 - 1;
      smax = fabs(x[ix0 - 1]);
      for (k = 2; k <= n; k++) {
        ix++;
        s = fabs(x[ix]);
        if (s > smax) {
          idxmax = k;
          smax = s;
        }
      }
    }
  }

  return idxmax;
}

static void full_loop_qrpf_p(const real_T A[441], int32_T m, int32_T n, int32_T
  nfxd, real_T tau[21], int32_T jpvt[21], real_T b_A[441])
{
  memcpy(&b_A[0], &A[0], 441U * sizeof(real_T));
  if (m < n) {
    full_loop_B.minmn_f = m;
  } else {
    full_loop_B.minmn_f = n;
  }

  memset(&full_loop_B.work_l[0], 0, 21U * sizeof(real_T));
  memset(&full_loop_B.vn1[0], 0, 21U * sizeof(real_T));
  memset(&full_loop_B.vn2[0], 0, 21U * sizeof(real_T));
  for (full_loop_B.j_l = nfxd + 1; full_loop_B.j_l <= n; full_loop_B.j_l++) {
    full_loop_B.vn1[full_loop_B.j_l - 1] = full_loop_xnrm2(m - nfxd, A,
      ((full_loop_B.j_l - 1) * 21 + nfxd) + 1);
    full_loop_B.vn2[full_loop_B.j_l - 1] = full_loop_B.vn1[full_loop_B.j_l - 1];
  }

  for (full_loop_B.j_l = nfxd + 1; full_loop_B.j_l <= full_loop_B.minmn_f;
       full_loop_B.j_l++) {
    full_loop_B.itemp = (full_loop_B.j_l - 1) * 21;
    full_loop_B.ii_j = (full_loop_B.itemp + full_loop_B.j_l) - 1;
    full_loop_B.nmi = n - full_loop_B.j_l;
    full_loop_B.mmi = (m - full_loop_B.j_l) + 1;
    full_loop_B.pvt = (full_loop_ixamax(full_loop_B.nmi + 1, full_loop_B.vn1,
      full_loop_B.j_l) + full_loop_B.j_l) - 2;
    if (full_loop_B.pvt + 1 != full_loop_B.j_l) {
      memcpy(&full_loop_B.b_A_l[0], &b_A[0], 441U * sizeof(real_T));
      full_loop_xswap(m, full_loop_B.b_A_l, full_loop_B.pvt * 21 + 1,
                      full_loop_B.itemp + 1, b_A);
      full_loop_B.itemp = jpvt[full_loop_B.pvt];
      jpvt[full_loop_B.pvt] = jpvt[full_loop_B.j_l - 1];
      jpvt[full_loop_B.j_l - 1] = full_loop_B.itemp;
      full_loop_B.vn1[full_loop_B.pvt] = full_loop_B.vn1[full_loop_B.j_l - 1];
      full_loop_B.vn2[full_loop_B.pvt] = full_loop_B.vn2[full_loop_B.j_l - 1];
    }

    if (full_loop_B.j_l < m) {
      memcpy(&full_loop_B.b_A_l[0], &b_A[0], 441U * sizeof(real_T));
      full_loop_xzlarfg(full_loop_B.mmi, b_A[full_loop_B.ii_j],
                        full_loop_B.b_A_l, full_loop_B.ii_j + 2,
                        &full_loop_B.b_atmp_n, b_A, &tau[full_loop_B.j_l - 1]);
      b_A[full_loop_B.ii_j] = full_loop_B.b_atmp_n;
    } else {
      tau[full_loop_B.j_l - 1] = 0.0;
    }

    if (full_loop_B.j_l < n) {
      full_loop_B.b_atmp_n = b_A[full_loop_B.ii_j];
      b_A[full_loop_B.ii_j] = 1.0;
      memcpy(&full_loop_B.b_A_l[0], &b_A[0], 441U * sizeof(real_T));
      full_loop_xzlarf_p4(full_loop_B.mmi, full_loop_B.nmi, full_loop_B.ii_j + 1,
                          tau[full_loop_B.j_l - 1], full_loop_B.b_A_l,
                          full_loop_B.ii_j + 22, full_loop_B.work_l, b_A);
      b_A[full_loop_B.ii_j] = full_loop_B.b_atmp_n;
    }

    for (full_loop_B.ii_j = full_loop_B.j_l + 1; full_loop_B.ii_j <= n;
         full_loop_B.ii_j++) {
      full_loop_B.nmi = ((full_loop_B.ii_j - 1) * 21 + full_loop_B.j_l) - 1;
      full_loop_B.b_atmp_n = full_loop_B.vn1[full_loop_B.ii_j - 1];
      if (full_loop_B.b_atmp_n != 0.0) {
        full_loop_B.temp1 = fabs(b_A[full_loop_B.nmi]) / full_loop_B.b_atmp_n;
        full_loop_B.temp1 = 1.0 - full_loop_B.temp1 * full_loop_B.temp1;
        if (full_loop_B.temp1 < 0.0) {
          full_loop_B.temp1 = 0.0;
        }

        full_loop_B.temp2 = full_loop_B.b_atmp_n /
          full_loop_B.vn2[full_loop_B.ii_j - 1];
        full_loop_B.temp2 = full_loop_B.temp2 * full_loop_B.temp2 *
          full_loop_B.temp1;
        if (full_loop_B.temp2 <= 1.4901161193847656E-8) {
          if (full_loop_B.j_l < m) {
            full_loop_B.vn1[full_loop_B.ii_j - 1] = full_loop_xnrm2
              (full_loop_B.mmi - 1, b_A, full_loop_B.nmi + 2);
            full_loop_B.vn2[full_loop_B.ii_j - 1] =
              full_loop_B.vn1[full_loop_B.ii_j - 1];
          } else {
            full_loop_B.vn1[full_loop_B.ii_j - 1] = 0.0;
            full_loop_B.vn2[full_loop_B.ii_j - 1] = 0.0;
          }
        } else {
          full_loop_B.vn1[full_loop_B.ii_j - 1] = full_loop_B.b_atmp_n * sqrt
            (full_loop_B.temp1);
        }
      }
    }
  }
}

static void full_loop_xgeqp3_p(const real_T A[441], int32_T m, int32_T n,
  int32_T jpvt[21], real_T b_A[441], real_T tau[21])
{
  memcpy(&b_A[0], &A[0], 441U * sizeof(real_T));
  if (m < n) {
    full_loop_B.minmn_a = m;
  } else {
    full_loop_B.minmn_a = n;
  }

  memset(&tau[0], 0, 21U * sizeof(real_T));
  if (full_loop_B.minmn_a < 1) {
    for (full_loop_B.c_j = 0; full_loop_B.c_j < n; full_loop_B.c_j++) {
      jpvt[full_loop_B.c_j] = full_loop_B.c_j + 1;
    }
  } else {
    full_loop_B.nfxd = -1;
    for (full_loop_B.c_j = 0; full_loop_B.c_j < n; full_loop_B.c_j++) {
      if (jpvt[full_loop_B.c_j] != 0) {
        full_loop_B.nfxd++;
        if (full_loop_B.c_j + 1 != full_loop_B.nfxd + 1) {
          memcpy(&full_loop_B.b_A_b[0], &b_A[0], 441U * sizeof(real_T));
          full_loop_xswap(m, full_loop_B.b_A_b, full_loop_B.c_j * 21 + 1,
                          full_loop_B.nfxd * 21 + 1, b_A);
          jpvt[full_loop_B.c_j] = jpvt[full_loop_B.nfxd];
          jpvt[full_loop_B.nfxd] = full_loop_B.c_j + 1;
        } else {
          jpvt[full_loop_B.c_j] = full_loop_B.c_j + 1;
        }
      } else {
        jpvt[full_loop_B.c_j] = full_loop_B.c_j + 1;
      }
    }

    full_loop_B.nfxd++;
    if (full_loop_B.nfxd >= full_loop_B.minmn_a) {
      full_loop_B.nfxd = full_loop_B.minmn_a;
    }

    memset(&tau[0], 0, 21U * sizeof(real_T));
    full_loop_qrf_p(b_A, m, n, full_loop_B.nfxd, tau, full_loop_B.b_A_b);
    memcpy(&b_A[0], &full_loop_B.b_A_b[0], 441U * sizeof(real_T));
    if (full_loop_B.nfxd < full_loop_B.minmn_a) {
      full_loop_qrpf_p(full_loop_B.b_A_b, m, n, full_loop_B.nfxd, tau, jpvt, b_A);
    }
  }
}

static void full_loop_factorQRE(const snaQeDJ4fX7UykrKyr5M8jC_full__T *obj,
  int32_T mrows, int32_T ncols, snaQeDJ4fX7UykrKyr5M8jC_full__T *b_obj)
{
  *b_obj = *obj;
  if (mrows * ncols == 0) {
    b_obj->mrows = mrows;
    b_obj->ncols = ncols;
    b_obj->minRowCol = 0;
  } else {
    b_obj->usedPivoting = true;
    b_obj->mrows = mrows;
    b_obj->ncols = ncols;
    if (mrows < ncols) {
      b_obj->minRowCol = mrows;
    } else {
      b_obj->minRowCol = ncols;
    }

    memcpy(&b_obj->jpvt[0], &obj->jpvt[0], 21U * sizeof(int32_T));
    full_loop_xgeqp3_p(obj->QR, mrows, ncols, b_obj->jpvt, b_obj->QR, b_obj->tau);
  }
}

static void full_loop_xzlarf_p43(int32_T m, int32_T n, int32_T iv0, real_T tau,
  const real_T C[441], int32_T ic0, real_T work[21], real_T b_C[441])
{
  int32_T lastc;
  int32_T coltop;
  int32_T ia;
  int32_T iac;
  int32_T d;
  int32_T jA;
  int32_T jy;
  int32_T exitg1;
  boolean_T exitg2;
  memcpy(&b_C[0], &C[0], 441U * sizeof(real_T));
  if (tau != 0.0) {
    full_loop_B.lastv = m;
    lastc = (iv0 + m) - 2;
    while ((full_loop_B.lastv > 0) && (C[lastc] == 0.0)) {
      full_loop_B.lastv--;
      lastc--;
    }

    lastc = n;
    exitg2 = false;
    while ((!exitg2) && (lastc > 0)) {
      coltop = (lastc - 1) * 21 + ic0;
      ia = coltop;
      do {
        exitg1 = 0;
        if (ia <= (coltop + full_loop_B.lastv) - 1) {
          if (C[ia - 1] != 0.0) {
            exitg1 = 1;
          } else {
            ia++;
          }
        } else {
          lastc--;
          exitg1 = 2;
        }
      } while (exitg1 == 0);

      if (exitg1 == 1) {
        exitg2 = true;
      }
    }

    lastc--;
  } else {
    full_loop_B.lastv = 0;
    lastc = -1;
  }

  if (full_loop_B.lastv > 0) {
    if (lastc + 1 != 0) {
      if (0 <= lastc) {
        memset(&work[0], 0, (lastc + 1) * sizeof(real_T));
      }

      jA = 0;
      jy = 21 * lastc + ic0;
      for (iac = ic0; iac <= jy; iac += 21) {
        coltop = iv0 - 1;
        full_loop_B.c_ie = 0.0;
        d = iac + full_loop_B.lastv;
        for (ia = iac; ia < d; ia++) {
          full_loop_B.c_ie += b_C[ia - 1] * b_C[coltop];
          coltop++;
        }

        work[jA] += full_loop_B.c_ie;
        jA++;
      }
    }

    if (!(-tau == 0.0)) {
      jA = ic0;
      jy = 0;
      for (ia = 0; ia <= lastc; ia++) {
        if (work[jy] != 0.0) {
          full_loop_B.c_ie = work[jy] * -tau;
          coltop = iv0 - 1;
          d = (full_loop_B.lastv + jA) - 1;
          for (iac = jA; iac <= d; iac++) {
            b_C[iac - 1] += b_C[coltop] * full_loop_B.c_ie;
            coltop++;
          }
        }

        jy++;
        jA += 21;
      }
    }
  }
}

static void full_loop_computeQ__p(snaQeDJ4fX7UykrKyr5M8jC_full__T *obj, int32_T
  nrows)
{
  full_loop_B.b_tmp = obj->minRowCol - 1;
  for (full_loop_B.b_idx_l = 0; full_loop_B.b_idx_l <= full_loop_B.b_tmp;
       full_loop_B.b_idx_l++) {
    full_loop_B.iQR0 = 21 * full_loop_B.b_idx_l + full_loop_B.b_idx_l;
    full_loop_B.i_g = (obj->mrows - full_loop_B.b_idx_l) - 2;
    if (0 <= full_loop_B.i_g) {
      memcpy(&obj->Q[full_loop_B.iQR0 + 1], &obj->QR[full_loop_B.iQR0 + 1],
             (((full_loop_B.i_g + full_loop_B.iQR0) - full_loop_B.iQR0) + 1) *
             sizeof(real_T));
    }
  }

  full_loop_B.b_idx_l = obj->mrows;
  full_loop_B.b_tmp = obj->minRowCol;
  if (nrows >= 1) {
    for (full_loop_B.iQR0 = full_loop_B.b_tmp; full_loop_B.iQR0 < nrows;
         full_loop_B.iQR0++) {
      full_loop_B.i_g = full_loop_B.iQR0 * 21;
      if (0 <= full_loop_B.b_idx_l - 1) {
        memset(&obj->Q[full_loop_B.i_g], 0, ((full_loop_B.b_idx_l +
                 full_loop_B.i_g) - full_loop_B.i_g) * sizeof(real_T));
      }

      obj->Q[full_loop_B.i_g + full_loop_B.iQR0] = 1.0;
    }

    full_loop_B.iQR0 = obj->minRowCol - 1;
    memset(&full_loop_B.work_o[0], 0, 21U * sizeof(real_T));
    full_loop_B.i_g = obj->minRowCol;
    while (full_loop_B.i_g >= 1) {
      full_loop_B.iaii_d = (full_loop_B.i_g - 1) * 21 + full_loop_B.i_g;
      if (full_loop_B.i_g < nrows) {
        obj->Q[full_loop_B.iaii_d - 1] = 1.0;
        memcpy(&full_loop_B.obj_d[0], &obj->Q[0], 441U * sizeof(real_T));
        full_loop_xzlarf_p43((full_loop_B.b_idx_l - full_loop_B.i_g) + 1, nrows
                             - full_loop_B.i_g, full_loop_B.iaii_d, obj->
                             tau[full_loop_B.iQR0], full_loop_B.obj_d,
                             full_loop_B.iaii_d + 21, full_loop_B.work_o, obj->Q);
      }

      if (full_loop_B.i_g < full_loop_B.b_idx_l) {
        full_loop_B.b_d = (full_loop_B.iaii_d + full_loop_B.b_idx_l) -
          full_loop_B.i_g;
        for (full_loop_B.b_tmp = full_loop_B.iaii_d + 1; full_loop_B.b_tmp <=
             full_loop_B.b_d; full_loop_B.b_tmp++) {
          obj->Q[full_loop_B.b_tmp - 1] *= -obj->tau[full_loop_B.iQR0];
        }
      }

      obj->Q[full_loop_B.iaii_d - 1] = 1.0 - obj->tau[full_loop_B.iQR0];
      full_loop_B.b_d = full_loop_B.i_g - 2;
      for (full_loop_B.b_tmp = 0; full_loop_B.b_tmp <= full_loop_B.b_d;
           full_loop_B.b_tmp++) {
        obj->Q[(full_loop_B.iaii_d - full_loop_B.b_tmp) - 2] = 0.0;
      }

      full_loop_B.iQR0--;
      full_loop_B.i_g--;
    }
  }
}

static int32_T full__ComputeNumDependentEq__p4(snaQeDJ4fX7UykrKyr5M8jC_full__T
  *qrmanager, const real_T beqf[19])
{
  int32_T numDependent;
  boolean_T exitg1;
  numDependent = 0;
  for (full_loop_B.b_idx_n = 0; full_loop_B.b_idx_n < 8; full_loop_B.b_idx_n++)
  {
    qrmanager->jpvt[full_loop_B.b_idx_n] = 0;
  }

  full_loop_B.qrmanager = *qrmanager;
  full_loop_factorQRE(&full_loop_B.qrmanager, 6, 8, qrmanager);
  full_loop_B.b_idx_n = 5;
  while ((full_loop_B.b_idx_n + 1 > 0) && (fabs(qrmanager->QR[21 *
           full_loop_B.b_idx_n + full_loop_B.b_idx_n]) < 1.7763568394002505E-13))
  {
    full_loop_B.b_idx_n--;
    numDependent++;
  }

  if (numDependent > 0) {
    full_loop_computeQ__p(qrmanager, qrmanager->mrows);
    full_loop_B.c_idx_k = 1;
    exitg1 = false;
    while ((!exitg1) && (full_loop_B.c_idx_k - 1 <= numDependent - 1)) {
      full_loop_B.qtb = 0.0;
      full_loop_B.ix_a = (6 - full_loop_B.c_idx_k) * 21;
      full_loop_B.iy = 0;
      for (full_loop_B.b_idx_n = 0; full_loop_B.b_idx_n < 6; full_loop_B.b_idx_n
           ++) {
        full_loop_B.qtb += qrmanager->Q[full_loop_B.ix_a] * beqf[full_loop_B.iy];
        full_loop_B.ix_a++;
        full_loop_B.iy++;
      }

      if (fabs(full_loop_B.qtb) >= 1.7763568394002505E-13) {
        numDependent = -1;
        exitg1 = true;
      } else {
        full_loop_B.c_idx_k++;
      }
    }
  }

  return numDependent;
}

static void full_loo_IndexOfDependentEq__p4(int32_T depIdx[6], int32_T nDep,
  snaQeDJ4fX7UykrKyr5M8jC_full__T *qrmanager)
{
  int32_T b_idx;
  for (b_idx = 0; b_idx < 6; b_idx++) {
    qrmanager->jpvt[b_idx] = 0;
  }

  full_loop_B.qrmanager_c = *qrmanager;
  full_loop_factorQRE(&full_loop_B.qrmanager_c, 8, 6, qrmanager);
  for (b_idx = 0; b_idx < nDep; b_idx++) {
    depIdx[b_idx] = qrmanager->jpvt[(b_idx - nDep) + 6];
  }
}

static void full_loop_countsort_p4(int32_T x[6], int32_T xLen, int32_T
  workspace[21])
{
  int32_T idxStart;
  int32_T idxEnd;
  int32_T b_idx;
  int32_T idxFill;
  if (xLen > 1) {
    for (b_idx = 0; b_idx < 6; b_idx++) {
      workspace[b_idx] = 0;
    }

    for (b_idx = 0; b_idx < xLen; b_idx++) {
      workspace[x[b_idx] - 1]++;
    }

    idxStart = 1;
    idxEnd = workspace[0];
    for (b_idx = 0; b_idx < 5; b_idx++) {
      workspace[b_idx + 1] += workspace[b_idx];
      for (idxFill = idxStart; idxFill <= idxEnd; idxFill++) {
        x[idxFill - 1] = b_idx + 1;
      }

      idxStart = workspace[b_idx] + 1;
      idxEnd = workspace[b_idx + 1];
    }

    for (b_idx = idxStart; b_idx <= idxEnd; b_idx++) {
      x[b_idx - 1] = 6;
    }
  }
}

static void full__removeDependentLinearEq_p(const real_T Aeq[48], real_T beq[6],
  int32_T idxArray[6], sVTYnQ9ljvmk9dLse9XvTT_full_l_T *memspace,
  s2CPTVnVyv153Hb6bxlki6F_full__T *TrialState, sH6xx18cQHI5sgA7Ajla4nE_full__T
  *WorkingSet, sJdVcLKPgejLYHLePKb6F6D_full__T *QPObjective, int32_T *nDepInd,
  snaQeDJ4fX7UykrKyr5M8jC_full__T *QRManager)
{
  QRManager->ldq = 21;
  memset(&QRManager->QR[0], 0, 441U * sizeof(real_T));
  memset(&QRManager->Q[0], 0, 441U * sizeof(real_T));
  QRManager->mrows = 0;
  QRManager->ncols = 0;
  memset(&QRManager->jpvt[0], 0, 21U * sizeof(int32_T));
  memset(&QRManager->tau[0], 0, 21U * sizeof(real_T));
  QRManager->minRowCol = 0;
  QRManager->usedPivoting = false;
  full_loop_B.mLinEq = 5;
  for (full_loop_B.b_idx_local = 0; full_loop_B.b_idx_local < 6;
       full_loop_B.b_idx_local++) {
    for (full_loop_B.i_c = 0; full_loop_B.i_c < 8; full_loop_B.i_c++) {
      QRManager->QR[full_loop_B.b_idx_local + full_loop_B.i_c * 21] =
        Aeq[full_loop_B.i_c * 6 + full_loop_B.b_idx_local];
    }

    WorkingSet->bwset[full_loop_B.b_idx_local] = beq[full_loop_B.b_idx_local];
  }

  *nDepInd = full__ComputeNumDependentEq__p4(QRManager, WorkingSet->bwset);
  if (*nDepInd > 0) {
    for (full_loop_B.i_c = 0; full_loop_B.i_c < 6; full_loop_B.i_c++) {
      full_loop_B.b_idx_local = 21 * full_loop_B.i_c - 1;
      memcpy(&QRManager->QR[full_loop_B.b_idx_local + 1], &WorkingSet->
             Aeq[full_loop_B.b_idx_local + 1], sizeof(real_T) << 3U);
      full_loop_B.c_idxArray[full_loop_B.i_c] = idxArray[full_loop_B.i_c];
    }

    full_loo_IndexOfDependentEq__p4(full_loop_B.c_idxArray, *nDepInd, QRManager);
    for (full_loop_B.i_c = 0; full_loop_B.i_c < 6; full_loop_B.i_c++) {
      idxArray[full_loop_B.i_c] = full_loop_B.c_idxArray[full_loop_B.i_c];
    }

    full_loop_countsort_p4(idxArray, *nDepInd, memspace->workspace_sort);
    for (full_loop_B.i_c = *nDepInd; full_loop_B.i_c >= 1; full_loop_B.i_c--) {
      full_loop_B.i10 = idxArray[full_loop_B.i_c - 1];
      if (full_loop_B.i10 < full_loop_B.mLinEq + 1) {
        for (full_loop_B.b_idx_local = 0; full_loop_B.b_idx_local < 8;
             full_loop_B.b_idx_local++) {
          WorkingSet->Aeq[full_loop_B.b_idx_local + 21 *
            (idxArray[full_loop_B.i_c - 1] - 1)] = WorkingSet->Aeq[21 *
            full_loop_B.mLinEq + full_loop_B.b_idx_local];
        }

        beq[full_loop_B.i10 - 1] = beq[full_loop_B.mLinEq];
      }

      full_loop_B.mLinEq--;
    }

    full_loop_B.b_WorkingSet_tmp[0] = 0;
    full_loop_B.b_WorkingSet_tmp[1] = 6 - *nDepInd;
    full_loop_B.b_WorkingSet_tmp[2] = 0;
    full_loop_B.b_WorkingSet_tmp[3] = 0;
    full_loop_B.b_WorkingSet_tmp[4] = 0;
    for (full_loop_B.i_c = 0; full_loop_B.i_c < 5; full_loop_B.i_c++) {
      WorkingSet->sizes[full_loop_B.i_c] =
        full_loop_B.b_WorkingSet_tmp[full_loop_B.i_c];
      WorkingSet->sizesNormal[full_loop_B.i_c] =
        full_loop_B.b_WorkingSet_tmp[full_loop_B.i_c];
    }

    WorkingSet->sizesPhaseOne[0] = 0;
    WorkingSet->sizesPhaseOne[1] = 6 - *nDepInd;
    WorkingSet->sizesPhaseOne[2] = 0;
    WorkingSet->sizesPhaseOne[3] = 1;
    WorkingSet->sizesPhaseOne[4] = 0;
    WorkingSet->sizesRegularized[0] = 0;
    WorkingSet->sizesRegularized[1] = 6 - *nDepInd;
    WorkingSet->sizesRegularized[2] = 0;
    WorkingSet->sizesRegularized[3] = (6 - *nDepInd) << 1;
    WorkingSet->sizesRegularized[4] = 0;
    WorkingSet->sizesRegPhaseOne[0] = 0;
    WorkingSet->sizesRegPhaseOne[1] = 6 - *nDepInd;
    WorkingSet->sizesRegPhaseOne[2] = 0;
    WorkingSet->sizesRegPhaseOne[3] = ((6 - *nDepInd) << 1) + 1;
    WorkingSet->sizesRegPhaseOne[4] = 0;
    full_loop_B.c_idxArray[0] = 1;
    full_loop_B.c_idxArray[1] = 0;
    full_loop_B.c_idxArray[2] = 6 - *nDepInd;
    full_loop_B.c_idxArray[3] = 0;
    full_loop_B.c_idxArray[4] = 0;
    full_loop_B.c_idxArray[5] = 0;
    for (full_loop_B.i_c = 0; full_loop_B.i_c < 6; full_loop_B.i_c++) {
      full_loop_B.x[full_loop_B.i_c] = full_loop_B.c_idxArray[full_loop_B.i_c];
    }

    for (full_loop_B.i_c = 0; full_loop_B.i_c < 5; full_loop_B.i_c++) {
      full_loop_B.x[full_loop_B.i_c + 1] += full_loop_B.x[full_loop_B.i_c];
    }

    for (full_loop_B.i_c = 0; full_loop_B.i_c < 6; full_loop_B.i_c++) {
      WorkingSet->isActiveIdx[full_loop_B.i_c] = full_loop_B.x[full_loop_B.i_c];
    }

    for (full_loop_B.i_c = 0; full_loop_B.i_c < 5; full_loop_B.i_c++) {
      full_loop_B.c_idxArray[full_loop_B.i_c + 1] +=
        full_loop_B.c_idxArray[full_loop_B.i_c];
    }

    for (full_loop_B.i_c = 0; full_loop_B.i_c < 6; full_loop_B.i_c++) {
      WorkingSet->isActiveIdxNormal[full_loop_B.i_c] =
        full_loop_B.c_idxArray[full_loop_B.i_c];
    }

    full_loop_B.x[0] = 1;
    full_loop_B.x[1] = 0;
    full_loop_B.x[2] = 6 - *nDepInd;
    full_loop_B.x[3] = 0;
    full_loop_B.x[4] = 1;
    full_loop_B.x[5] = 0;
    for (full_loop_B.i_c = 0; full_loop_B.i_c < 5; full_loop_B.i_c++) {
      full_loop_B.x[full_loop_B.i_c + 1] += full_loop_B.x[full_loop_B.i_c];
    }

    for (full_loop_B.i_c = 0; full_loop_B.i_c < 6; full_loop_B.i_c++) {
      WorkingSet->isActiveIdxPhaseOne[full_loop_B.i_c] =
        full_loop_B.x[full_loop_B.i_c];
    }

    full_loop_B.x[0] = 1;
    full_loop_B.x[1] = 0;
    full_loop_B.x[2] = 6 - *nDepInd;
    full_loop_B.x[3] = 0;
    full_loop_B.x[4] = (6 - *nDepInd) << 1;
    full_loop_B.x[5] = 0;
    for (full_loop_B.i_c = 0; full_loop_B.i_c < 5; full_loop_B.i_c++) {
      full_loop_B.x[full_loop_B.i_c + 1] += full_loop_B.x[full_loop_B.i_c];
    }

    for (full_loop_B.i_c = 0; full_loop_B.i_c < 6; full_loop_B.i_c++) {
      WorkingSet->isActiveIdxRegularized[full_loop_B.i_c] =
        full_loop_B.x[full_loop_B.i_c];
    }

    full_loop_B.x[0] = 1;
    full_loop_B.x[1] = 0;
    full_loop_B.x[2] = 6 - *nDepInd;
    full_loop_B.x[3] = 0;
    full_loop_B.x[4] = ((6 - *nDepInd) << 1) + 1;
    full_loop_B.x[5] = 0;
    for (full_loop_B.i_c = 0; full_loop_B.i_c < 5; full_loop_B.i_c++) {
      full_loop_B.x[full_loop_B.i_c + 1] += full_loop_B.x[full_loop_B.i_c];
    }

    for (full_loop_B.i_c = 0; full_loop_B.i_c < 6; full_loop_B.i_c++) {
      WorkingSet->isActiveIdxRegPhaseOne[full_loop_B.i_c] =
        full_loop_B.x[full_loop_B.i_c];
    }

    WorkingSet->nVarMax = 21 - (*nDepInd << 1);
    WorkingSet->mConstr = 6 - *nDepInd;
    WorkingSet->mConstrMax = 19 - 3 * *nDepInd;
    WorkingSet->mConstrOrig = 6 - *nDepInd;
    QPObjective->maxVar = 21 - (*nDepInd << 1);
    TrialState->nVarMax = 21 - (*nDepInd << 1);
    TrialState->mEq = 6 - *nDepInd;
    TrialState->iNonEq0 = 7 - *nDepInd;
  }
}

static void full_loop_computeObjective_(KickIn_full_loop_T
  **obj_objfun_tunableEnvironment, const real_T x[8], real_T *fval, int32_T
  *status)
{
  int32_T b_k;
  real_T x_0;
  for (b_k = 0; b_k < 8; b_k++) {
    x_0 = -(*obj_objfun_tunableEnvironment)->u0[b_k] - x[b_k];
    full_loop_B.y_k[b_k] = fabs(x_0);
  }

  *fval = full_loop_B.y_k[0];
  for (b_k = 0; b_k < 7; b_k++) {
    *fval += full_loop_B.y_k[b_k + 1];
  }

  *status = 1;
  if (rtIsInf(*fval) || rtIsNaN(*fval)) {
    if (rtIsNaN(*fval)) {
      *status = -6;
    } else {
      *status = -5;
    }
  }
}

static void evalObjAndConstrAndDerivative_p(KickIn_full_loop_T
  **obj_objfun_tunableEnvironment, const real_T x[8], const real_T
  JacEqTrans_workspace[126], real_T *fval, real_T b_JacEqTrans_workspace[126],
  int32_T *status)
{
  memcpy(&b_JacEqTrans_workspace[0], &JacEqTrans_workspace[0], 126U * sizeof
         (real_T));
  full_loop_computeObjective_(obj_objfun_tunableEnvironment, x, fval, status);
  if (*status == 1) {
    *status = 1;
  }
}

static void full_loop_finDiffEvalAndChkErr(KickIn_full_loop_T
  **obj_objfun_tunableEnvironment, int32_T dim, real_T delta, const real_T xk[8],
  boolean_T *evalOK, real_T *b_fplus, real_T b_xk[8])
{
  int32_T b_k;
  real_T b_xk_tmp;
  memcpy(&b_xk[0], &xk[0], sizeof(real_T) << 3U);
  b_xk_tmp = xk[dim - 1];
  b_xk[dim - 1] = b_xk_tmp + delta;
  for (b_k = 0; b_k < 8; b_k++) {
    full_loop_B.x_j = -(*obj_objfun_tunableEnvironment)->u0[b_k] - b_xk[b_k];
    full_loop_B.y_c[b_k] = fabs(full_loop_B.x_j);
  }

  *b_fplus = full_loop_B.y_c[0];
  for (b_k = 0; b_k < 7; b_k++) {
    *b_fplus += full_loop_B.y_c[b_k + 1];
  }

  *evalOK = ((!rtIsInf(*b_fplus)) && (!rtIsNaN(*b_fplus)));
  if (*evalOK) {
    b_xk[dim - 1] = b_xk_tmp;
  }
}

static void ful_computeForwardDifferences_p(s_iyYBPziYRv853Phg0mcgOD_full_T *obj,
  real_T fCurrent, const real_T xk[8], real_T gradf[21], const real_T
  JacCeqTrans[126], boolean_T *evalOK, real_T b_JacCeqTrans[126], real_T b_xk[8])
{
  int32_T idx;
  int32_T b_idx;
  KickIn_full_loop_T *obj_0;
  boolean_T exitg1;
  boolean_T guard1 = false;
  memcpy(&b_xk[0], &xk[0], sizeof(real_T) << 3U);
  memcpy(&b_JacCeqTrans[0], &JacCeqTrans[0], 126U * sizeof(real_T));
  *evalOK = true;
  obj->numEvals = 0;
  b_idx = 1;
  exitg1 = false;
  while ((!exitg1) && (b_idx - 1 < 8)) {
    idx = b_idx - 1;
    full_loop_B.deltaX = fabs(b_xk[idx]);
    if (!(full_loop_B.deltaX > 1.0)) {
      full_loop_B.deltaX = 1.0;
    }

    full_loop_B.deltaX *= (1.0 - static_cast<real_T>(b_xk[idx] < 0.0) * 2.0) *
      1.4901161193847656E-8;
    full_loop_finDiffEvalAndChkErr(&obj->objfun.tunableEnvironment, idx + 1,
      full_loop_B.deltaX, b_xk, evalOK, &full_loop_B.b_m, full_loop_B.c_xk_h);
    obj->f_1 = full_loop_B.b_m;
    memcpy(&b_xk[0], &full_loop_B.c_xk_h[0], sizeof(real_T) << 3U);
    obj->numEvals++;
    guard1 = false;
    if (!*evalOK) {
      full_loop_B.deltaX = -full_loop_B.deltaX;
      obj_0 = obj->objfun.tunableEnvironment;
      full_loop_finDiffEvalAndChkErr(&obj_0, idx + 1, full_loop_B.deltaX,
        full_loop_B.c_xk_h, evalOK, &obj->f_1, b_xk);
      obj->numEvals++;
      if (!*evalOK) {
        exitg1 = true;
      } else {
        guard1 = true;
      }
    } else {
      guard1 = true;
    }

    if (guard1) {
      gradf[idx] = (obj->f_1 - fCurrent) / full_loop_B.deltaX;
      b_idx++;
    }
  }
}

static void full__computeLinearResiduals_p4(const real_T x[8], real_T
  workspaceEq[6], int32_T mLinEq, const real_T AeqT[126], const real_T beq[6])
{
  int32_T b_k;
  int32_T iy;
  int32_T ix;
  real_T c;
  int32_T b;
  int32_T ia;
  if (mLinEq > 0) {
    for (b_k = 0; b_k < mLinEq; b_k++) {
      workspaceEq[b_k] = beq[b_k];
      workspaceEq[b_k] = -workspaceEq[b_k];
    }

    iy = 0;
    b = (mLinEq - 1) * 21;
    for (b_k = 1; b_k <= b + 1; b_k += 21) {
      ix = 0;
      c = 0.0;
      for (ia = b_k; ia <= b_k + 7; ia++) {
        c += AeqT[ia - 1] * x[ix];
        ix++;
      }

      workspaceEq[iy] += c;
      iy++;
    }
  }
}

static void ful_updateWorkingSetForNewQP_p4(sH6xx18cQHI5sgA7Ajla4nE_full__T
  *WorkingSet, int32_T mEq, const real_T cEq[6])
{
  int32_T b_idx;
  for (b_idx = 0; b_idx < mEq; b_idx++) {
    WorkingSet->beq[b_idx] = -cEq[b_idx];
    WorkingSet->bwset[b_idx] = WorkingSet->beq[b_idx];
  }
}

static void full_loop_setProblemType(const sH6xx18cQHI5sgA7Ajla4nE_full__T *obj,
  int32_T PROBLEM_TYPE, sH6xx18cQHI5sgA7Ajla4nE_full__T *b_obj)
{
  int32_T idxStartIneq;
  int32_T offsetEq2;
  int32_T idx_col;
  int32_T idxGlobalColStart;
  int32_T b_idx_col;
  int32_T g;
  int32_T m;
  int32_T i;
  *b_obj = *obj;
  switch (PROBLEM_TYPE) {
   case 3:
    b_obj->nVar = 8;
    b_obj->mConstr = obj->mConstrOrig;
    for (i = 0; i < 5; i++) {
      b_obj->sizes[i] = obj->sizesNormal[i];
    }

    for (i = 0; i < 6; i++) {
      b_obj->isActiveIdx[i] = obj->isActiveIdxNormal[i];
    }
    break;

   case 1:
    b_obj->nVar = 9;
    b_obj->mConstr = obj->mConstrOrig + 1;
    for (i = 0; i < 5; i++) {
      b_obj->sizes[i] = obj->sizesPhaseOne[i];
    }

    for (i = 0; i < 6; i++) {
      b_obj->isActiveIdx[i] = obj->isActiveIdxPhaseOne[i];
    }

    i = obj->sizesPhaseOne[1] - 1;
    for (idxStartIneq = 0; idxStartIneq <= i; idxStartIneq++) {
      b_obj->Aeq[21 * idxStartIneq + 8] = 0.0;
      b_obj->ATwset[21 * ((obj->isActiveIdxPhaseOne[1] + idxStartIneq) - 1) + 8]
        = 0.0;
    }

    b_obj->indexLB[obj->sizesPhaseOne[3] - 1] = 9;
    b_obj->lb[8] = 1.0E-5;
    idxStartIneq = obj->isActiveIdxPhaseOne[2];
    i = obj->nActiveConstr;
    for (offsetEq2 = idxStartIneq; offsetEq2 <= i; offsetEq2++) {
      b_obj->ATwset[21 * (offsetEq2 - 1) + 8] = -1.0;
    }
    break;

   case 2:
    b_obj->nVar = obj->nVarMax - 1;
    b_obj->mConstr = obj->mConstrMax - 1;
    for (i = 0; i < 5; i++) {
      b_obj->sizes[i] = obj->sizesRegularized[i];
    }

    for (i = 0; i < 6; i++) {
      b_obj->isActiveIdx[i] = obj->isActiveIdxRegularized[i];
    }

    if (obj->probType != 4) {
      idxStartIneq = obj->sizesRegularized[1] + 7;
      offsetEq2 = obj->sizesRegularized[1];
      idxGlobalColStart = obj->isActiveIdxRegularized[1] - 2;
      for (b_idx_col = 0; b_idx_col <= idxStartIneq - 8; b_idx_col++) {
        idx_col = b_idx_col + 1;
        if (9 <= idx_col + 7) {
          memset(&b_obj->Aeq[idx_col * 21 + -13], 0, (((idx_col + idx_col * 21)
                   - idx_col * 21) + -1) * sizeof(real_T));
          memset(&b_obj->ATwset[(idxGlobalColStart + idx_col) * 21 + 8], 0,
                 (((idx_col + (idxGlobalColStart + idx_col) * 21) -
                   (idxGlobalColStart + idx_col) * 21) + -1) * sizeof(real_T));
        }

        i = 21 * (idx_col - 1);
        b_obj->Aeq[(idx_col + i) + 7] = -1.0;
        m = 21 * (idxGlobalColStart + idx_col);
        b_obj->ATwset[(idx_col + m) + 7] = -1.0;
        if (idx_col + 9 <= offsetEq2 + 8) {
          memset(&b_obj->Aeq[(idx_col + i) + 8], 0, (((offsetEq2 + i) - idx_col)
                  - i) * sizeof(real_T));
          memset(&b_obj->ATwset[(idx_col + m) + 8], 0, (((offsetEq2 + m) -
                   idx_col) - m) * sizeof(real_T));
        }

        idx_col += idxStartIneq;
        if (idxStartIneq + 2 <= idx_col) {
          memset(&b_obj->Aeq[(idxStartIneq + i) + 1], 0, ((((idx_col + i) -
                    idxStartIneq) - i) + -1) * sizeof(real_T));
          memset(&b_obj->ATwset[(idxStartIneq + m) + 1], 0, ((((idx_col + m) -
                    idxStartIneq) - m) + -1) * sizeof(real_T));
        }

        b_obj->Aeq[idx_col + i] = 1.0;
        b_obj->ATwset[idx_col + m] = 1.0;
        g = b_obj->nVar;
        if (idx_col + 2 <= b_obj->nVar) {
          memset(&b_obj->Aeq[(idx_col + i) + 1], 0, ((((b_obj->nVar + i) -
                    idx_col) - i) + -1) * sizeof(real_T));
          memset(&b_obj->ATwset[(idx_col + m) + 1], 0, ((((g + m) - idx_col) - m)
                  + -1) * sizeof(real_T));
        }
      }

      i = 8;
      idxStartIneq = obj->sizesRegularized[3];
      for (offsetEq2 = 1; offsetEq2 <= idxStartIneq; offsetEq2++) {
        i++;
        b_obj->indexLB[offsetEq2 - 1] = i;
      }

      i = obj->sizesRegularized[1] << 1;
      if (9 <= i + 8) {
        memset(&b_obj->lb[8], 0, i * sizeof(real_T));
      }

      idxStartIneq = obj->isActiveIdxRegularized[2];
      offsetEq2 = obj->nActiveConstr;
      for (idxGlobalColStart = idxStartIneq; idxGlobalColStart <= offsetEq2;
           idxGlobalColStart++) {
        if (obj->Wid[idxGlobalColStart - 1] == 3) {
          b_idx_col = obj->Wlocalidx[idxGlobalColStart - 1];
          if (9 <= b_idx_col + 7) {
            memset(&b_obj->ATwset[idxGlobalColStart * 21 + -13], 0, (b_idx_col +
                    -1) * sizeof(real_T));
          }

          i = 21 * (idxGlobalColStart - 1);
          b_obj->ATwset[(b_idx_col + i) + 7] = -1.0;
          if (b_idx_col + 9 <= b_obj->nVar) {
            memset(&b_obj->ATwset[(b_idx_col + i) + 8], 0, ((((b_obj->nVar + i)
                      - b_idx_col) - i) + -8) * sizeof(real_T));
          }
        } else {
          if (9 <= b_obj->nVar) {
            memset(&b_obj->ATwset[idxGlobalColStart * 21 + -13], 0, (b_obj->nVar
                    + -8) * sizeof(real_T));
          }
        }
      }
    }
    break;

   default:
    b_obj->nVar = obj->nVarMax;
    b_obj->mConstr = obj->mConstrMax;
    for (i = 0; i < 5; i++) {
      b_obj->sizes[i] = obj->sizesRegPhaseOne[i];
    }

    for (i = 0; i < 6; i++) {
      b_obj->isActiveIdx[i] = obj->isActiveIdxRegPhaseOne[i];
    }

    i = obj->sizesRegPhaseOne[1] - 1;
    for (idxStartIneq = 0; idxStartIneq <= i; idxStartIneq++) {
      b_obj->Aeq[(b_obj->nVar + 21 * idxStartIneq) - 1] = 0.0;
      b_obj->ATwset[(b_obj->nVar + 21 * ((obj->isActiveIdxRegPhaseOne[1] +
        idxStartIneq) - 1)) - 1] = 0.0;
    }

    b_obj->indexLB[obj->sizesRegPhaseOne[3] - 1] = obj->nVarMax;
    b_obj->lb[obj->nVarMax - 1] = 1.0E-5;
    idxStartIneq = obj->isActiveIdxRegPhaseOne[2];
    i = obj->nActiveConstr;
    for (offsetEq2 = idxStartIneq; offsetEq2 <= i; offsetEq2++) {
      b_obj->ATwset[(b_obj->nVar + 21 * (offsetEq2 - 1)) - 1] = -1.0;
    }
    break;
  }

  b_obj->probType = PROBLEM_TYPE;
}

static void full_loop_initActiveSet(const sH6xx18cQHI5sgA7Ajla4nE_full__T *obj,
  sH6xx18cQHI5sgA7Ajla4nE_full__T *b_obj)
{
  int32_T i;
  full_loop_setProblemType(obj, 3, b_obj);
  full_loop_B.idxFillStart = b_obj->isActiveIdx[2];
  full_loop_B.b_f2 = b_obj->mConstrMax;
  if (full_loop_B.idxFillStart <= full_loop_B.b_f2) {
    memset(&b_obj->isActiveConstr[full_loop_B.idxFillStart + -1], 0,
           ((full_loop_B.b_f2 - full_loop_B.idxFillStart) + 1) * sizeof
           (boolean_T));
  }

  b_obj->nWConstr[0] = 0;
  b_obj->nWConstr[1] = b_obj->sizes[1];
  b_obj->nWConstr[2] = 0;
  b_obj->nWConstr[3] = 0;
  b_obj->nWConstr[4] = 0;
  b_obj->nActiveConstr = b_obj->nWConstr[1];
  full_loop_B.idxFillStart = b_obj->sizes[1] - 1;
  for (full_loop_B.b_f2 = 0; full_loop_B.b_f2 <= full_loop_B.idxFillStart;
       full_loop_B.b_f2++) {
    b_obj->Wid[full_loop_B.b_f2] = 2;
    b_obj->Wlocalidx[full_loop_B.b_f2] = full_loop_B.b_f2 + 1;
    b_obj->isActiveConstr[full_loop_B.b_f2] = true;
    full_loop_B.iAeq0 = 21 * full_loop_B.b_f2;
    full_loop_B.iATw0 = 21 * full_loop_B.b_f2;
    full_loop_B.c_dy = b_obj->nVar;
    for (i = 0; i < full_loop_B.c_dy; i++) {
      b_obj->ATwset[full_loop_B.iATw0 + i] = b_obj->Aeq[full_loop_B.iAeq0 + i];
    }

    b_obj->bwset[full_loop_B.b_f2] = b_obj->beq[full_loop_B.b_f2];
  }
}

static void full_loop_factoryConstruct_p43(real_T fval, const real_T
  Ceq_workspace[6], int32_T mNonlinEq, s6ICcRyulWOFjNCN0ll7VsE_full__T *obj)
{
  real_T normResid;
  int32_T b_k;
  obj->penaltyParam = 1.0;
  obj->threshold = 0.0001;
  obj->nPenaltyDecreases = 0;
  obj->linearizedConstrViol = 0.0;
  obj->initFval = fval;
  normResid = 0.0;
  if (mNonlinEq >= 1) {
    for (b_k = 0; b_k < mNonlinEq; b_k++) {
      normResid += fabs(Ceq_workspace[b_k]);
    }
  }

  obj->initConstrViolationEq = normResid;
  obj->initConstrViolationIneq = 0.0;
  obj->phi = 0.0;
  obj->phiPrimePlus = 0.0;
  obj->phiFullStep = 0.0;
  obj->feasRelativeFactor = 0.0;
  obj->nlpPrimalFeasError = 0.0;
  obj->nlpDualFeasError = 0.0;
  obj->nlpComplError = 0.0;
  obj->firstOrderOpt = 0.0;
  obj->hasObjective = true;
}

static void full_loop_computeGradLag_p4(real_T workspace[21], int32_T nVar,
  const real_T grad[21], int32_T mEq, const real_T AeqTrans[126], const int32_T
  finiteLB[21], int32_T mLB, const real_T lambda[19])
{
  int32_T iL0;
  int32_T ix;
  int32_T iy;
  int32_T b;
  int32_T iac;
  int32_T d;
  if (0 <= nVar - 1) {
    memcpy(&workspace[0], &grad[0], nVar * sizeof(real_T));
  }

  if ((nVar == 0) || (mEq == 0)) {
  } else {
    ix = 0;
    b = (mEq - 1) * 21;
    for (iac = 1; iac <= b + 1; iac += 21) {
      iy = 0;
      d = iac + nVar;
      for (iL0 = iac; iL0 < d; iL0++) {
        workspace[iy] += AeqTrans[iL0 - 1] * lambda[ix];
        iy++;
      }

      ix++;
    }
  }

  iL0 = mEq;
  for (iac = 0; iac < mLB; iac++) {
    workspace[finiteLB[iac] - 1] -= lambda[iL0];
    iL0++;
  }
}

static void full_loop_computeDualFeasError(int32_T nVar, const real_T gradLag[21],
  boolean_T *gradOK, real_T *val)
{
  int32_T idx;
  int32_T b_idx;
  real_T u1;
  boolean_T exitg1;
  *gradOK = true;
  *val = 0.0;
  b_idx = 1;
  exitg1 = false;
  while ((!exitg1) && (b_idx - 1 <= nVar - 1)) {
    idx = b_idx - 1;
    *gradOK = ((!rtIsInf(gradLag[idx])) && (!rtIsNaN(gradLag[idx])));
    if (!*gradOK) {
      exitg1 = true;
    } else {
      u1 = fabs(gradLag[idx]);
      if ((!(*val > u1)) && (!rtIsNaN(u1))) {
        *val = u1;
      }

      b_idx++;
    }
  }
}

static void full_loop_test_exit_p4(s6ICcRyulWOFjNCN0ll7VsE_full__T
  *MeritFunction, const sH6xx18cQHI5sgA7Ajla4nE_full__T *WorkingSet, const
  s2CPTVnVyv153Hb6bxlki6F_full__T *TrialState, s7RdrPWkr8UPAUyTdDJkLaG_full__T
  *Flags, s2CPTVnVyv153Hb6bxlki6F_full__T *b_TrialState)
{
  boolean_T isFeasible;
  boolean_T b;
  int32_T k;
  static const s7RdrPWkr8UPAUyTdDJkLaG_full__T tmp = { true,// gradOK
    true,                              // fevalOK
    false,                             // done
    false,                             // stepAccepted
    false,                             // failedLineSearch
    1                                  // stepType
  };

  *b_TrialState = *TrialState;
  *Flags = tmp;
  full_loop_B.nVar_i = WorkingSet->nVar;
  full_loop_B.mEq_p = WorkingSet->sizes[1] - 1;
  full_loop_B.mLambda_f = (WorkingSet->sizes[1] + WorkingSet->sizes[3]) - 1;
  memcpy(&b_TrialState->gradLag[0], &TrialState->gradLag[0], 21U * sizeof(real_T));
  full_loop_computeGradLag_p4(b_TrialState->gradLag, WorkingSet->nVar,
    TrialState->grad, WorkingSet->sizes[1], WorkingSet->Aeq, WorkingSet->indexLB,
    WorkingSet->sizes[3], TrialState->lambdasqp);
  if (WorkingSet->nVar < 1) {
    full_loop_B.idx_max = -1;
  } else {
    full_loop_B.idx_max = 0;
    if (WorkingSet->nVar > 1) {
      full_loop_B.ix_e = 0;
      full_loop_B.smax_c = fabs(TrialState->grad[0]);
      for (k = 2; k <= full_loop_B.nVar_i; k++) {
        full_loop_B.ix_e++;
        full_loop_B.s_m = fabs(TrialState->grad[full_loop_B.ix_e]);
        if (full_loop_B.s_m > full_loop_B.smax_c) {
          full_loop_B.idx_max = k - 1;
          full_loop_B.smax_c = full_loop_B.s_m;
        }
      }
    }
  }

  full_loop_B.smax_c = fabs(TrialState->grad[full_loop_B.idx_max]);
  if ((1.0 > full_loop_B.smax_c) || rtIsNaN(full_loop_B.smax_c)) {
    full_loop_B.smax_c = 1.0;
  }

  if (rtIsInf(full_loop_B.smax_c)) {
    full_loop_B.smax_c = 1.0;
  }

  full_loop_B.s_m = 0.0;
  for (k = 0; k <= full_loop_B.mEq_p; k++) {
    full_loop_B.u1 = fabs(TrialState->cEq[k]);
    if ((!(full_loop_B.s_m > full_loop_B.u1)) && (!rtIsNaN(full_loop_B.u1))) {
      full_loop_B.s_m = full_loop_B.u1;
    }
  }

  MeritFunction->nlpPrimalFeasError = full_loop_B.s_m;
  if ((1.0 > full_loop_B.s_m) || rtIsNaN(full_loop_B.s_m)) {
    full_loop_B.u1 = 1.0;
  } else {
    full_loop_B.u1 = full_loop_B.s_m;
  }

  MeritFunction->feasRelativeFactor = full_loop_B.u1;
  isFeasible = (full_loop_B.s_m <= 0.01 * full_loop_B.u1);
  full_loop_computeDualFeasError(WorkingSet->nVar, b_TrialState->gradLag, &b,
    &full_loop_B.s_m);
  Flags->gradOK = b;
  MeritFunction->nlpDualFeasError = full_loop_B.s_m;
  if (!b) {
    Flags->done = true;
    if (isFeasible) {
      b_TrialState->sqpExitFlag = 2;
    } else {
      b_TrialState->sqpExitFlag = -2;
    }
  } else {
    MeritFunction->nlpComplError = 0.0;
    if (full_loop_B.s_m > 0.0) {
      MeritFunction->firstOrderOpt = full_loop_B.s_m;
    } else {
      MeritFunction->firstOrderOpt = 0.0;
    }

    memcpy(&b_TrialState->lambdasqp_old[0], &TrialState->lambdasqp_old[0], 19U *
           sizeof(real_T));
    if (0 <= full_loop_B.mLambda_f) {
      memcpy(&b_TrialState->lambdasqp_old[0], &TrialState->lambdasqp[0],
             (full_loop_B.mLambda_f + 1) * sizeof(real_T));
    }

    if (isFeasible && (full_loop_B.s_m <= 0.01 * full_loop_B.smax_c)) {
      Flags->done = true;
      b_TrialState->sqpExitFlag = 1;
    } else {
      Flags->done = false;
      if (TrialState->FunctionEvaluations >= 800) {
        Flags->done = true;
        b_TrialState->sqpExitFlag = 0;
      }
    }
  }
}

static void full_loop_saveState(const s2CPTVnVyv153Hb6bxlki6F_full__T *obj,
  s2CPTVnVyv153Hb6bxlki6F_full__T *b_obj)
{
  int32_T i;
  int32_T b_k;
  *b_obj = *obj;
  b_obj->sqpFval_old = obj->sqpFval;
  for (b_k = 0; b_k < 8; b_k++) {
    b_obj->xstarsqp_old[b_k] = obj->xstarsqp_old[b_k];
    b_obj->xstarsqp_old[b_k] = obj->xstarsqp[b_k];
    b_obj->grad_old[b_k] = obj->grad[b_k];
  }

  b_k = obj->mEq - 1;
  for (i = 0; i < 6; i++) {
    b_obj->cEq_old[i] = obj->cEq_old[i];
  }

  if (0 <= b_k) {
    memcpy(&b_obj->cEq_old[0], &obj->cEq[0], (b_k + 1) * sizeof(real_T));
  }
}

static void fu_updateWorkingSetForNewQP_p43(sH6xx18cQHI5sgA7Ajla4nE_full__T
  *WorkingSet, int32_T mEq, const real_T cEq[6])
{
  int32_T ineqStart;
  int32_T b_idx;
  int32_T b;
  for (b_idx = 0; b_idx < mEq; b_idx++) {
    WorkingSet->beq[b_idx] = -cEq[b_idx];
    WorkingSet->bwset[b_idx] = WorkingSet->beq[b_idx];
  }

  if (WorkingSet->nActiveConstr > mEq) {
    if (1 < mEq + 1) {
      ineqStart = mEq + 1;
    } else {
      ineqStart = 1;
    }

    b = WorkingSet->nActiveConstr;
    for (b_idx = ineqStart; b_idx <= b; b_idx++) {
      switch (WorkingSet->Wid[b_idx - 1]) {
       case 4:
        WorkingSet->bwset[b_idx - 1] = WorkingSet->lb[WorkingSet->
          Wlocalidx[b_idx - 1] - 1];
        break;

       case 5:
        WorkingSet->bwset[b_idx - 1] = WorkingSet->ub[WorkingSet->
          Wlocalidx[b_idx - 1] - 1];
        break;
      }
    }
  }
}

static void full_loop_updateWorkingSet_p(sH6xx18cQHI5sgA7Ajla4nE_full__T
  *WorkingSet, const s2CPTVnVyv153Hb6bxlki6F_full__T *TrialState)
{
  int32_T mEq;
  int32_T b_idx;
  int32_T ix;
  int32_T iy;
  int32_T b;
  int32_T d;
  int32_T ia;
  mEq = WorkingSet->sizes[1] - 1;
  if (WorkingSet->sizes[1] > 0) {
    for (b_idx = 0; b_idx <= mEq; b_idx++) {
      WorkingSet->beq[b_idx] = -TrialState->cEq[b_idx];
    }

    if (WorkingSet->nVar != 0) {
      iy = 0;
      b = (WorkingSet->sizes[1] - 1) * 21;
      for (b_idx = 1; b_idx <= b + 1; b_idx += 21) {
        ix = 0;
        full_loop_B.c_ch = 0.0;
        d = b_idx + WorkingSet->nVar;
        for (ia = b_idx; ia < d; ia++) {
          full_loop_B.c_ch += WorkingSet->Aeq[ia - 1] * TrialState->searchDir[ix];
          ix++;
        }

        WorkingSet->beq[iy] += full_loop_B.c_ch;
        iy++;
      }
    }

    if (0 <= mEq) {
      memcpy(&WorkingSet->bwset[0], &WorkingSet->beq[0], (mEq + 1) * sizeof
             (real_T));
    }
  }
}

static void full_loop_snap_bounds_p(s2CPTVnVyv153Hb6bxlki6F_full__T *solution,
  const sH6xx18cQHI5sgA7Ajla4nE_full__T *workingset)
{
  int32_T b;
  int32_T b_idx;
  b = workingset->sizes[3] - 1;
  for (b_idx = 0; b_idx <= b; b_idx++) {
    if (workingset->isActiveConstr[(workingset->isActiveIdx[3] + b_idx) - 1]) {
      solution->xstar[workingset->indexLB[b_idx] - 1] = -workingset->
        lb[workingset->indexLB[b_idx] - 1];
    }
  }
}

static int32_T full_ComputeNumDependentEq__p43(snaQeDJ4fX7UykrKyr5M8jC_full__T
  *qrmanager, const real_T beqf[19], int32_T mConstr, int32_T nVar)
{
  int32_T numDependent;
  boolean_T exitg1;
  numDependent = mConstr - nVar;
  if (0 > numDependent) {
    numDependent = 0;
  }

  if (0 <= nVar - 1) {
    memset(&qrmanager->jpvt[0], 0, nVar * sizeof(int32_T));
  }

  full_loop_B.qrmanager_k = *qrmanager;
  full_loop_factorQRE(&full_loop_B.qrmanager_k, mConstr, nVar, qrmanager);
  full_loop_B.tol_o = 100.0 * static_cast<real_T>(nVar) * 2.2204460492503131E-16;
  if (nVar < mConstr) {
    full_loop_B.nVar_jw = nVar;
  } else {
    full_loop_B.nVar_jw = mConstr;
  }

  full_loop_B.nVar_jw--;
  while ((full_loop_B.nVar_jw + 1 > 0) && (fabs(qrmanager->QR[21 *
           full_loop_B.nVar_jw + full_loop_B.nVar_jw]) < full_loop_B.tol_o)) {
    full_loop_B.nVar_jw--;
    numDependent++;
  }

  if (numDependent > 0) {
    full_loop_computeQ__p(qrmanager, qrmanager->mrows);
    full_loop_B.c_idx_e = 1;
    exitg1 = false;
    while ((!exitg1) && (full_loop_B.c_idx_e - 1 <= numDependent - 1)) {
      full_loop_B.qtb_g = 0.0;
      full_loop_B.ix_h = (mConstr - full_loop_B.c_idx_e) * 21;
      full_loop_B.iy_k = 0;
      for (full_loop_B.nVar_jw = 0; full_loop_B.nVar_jw < mConstr;
           full_loop_B.nVar_jw++) {
        full_loop_B.qtb_g += qrmanager->Q[full_loop_B.ix_h] *
          beqf[full_loop_B.iy_k];
        full_loop_B.ix_h++;
        full_loop_B.iy_k++;
      }

      if (fabs(full_loop_B.qtb_g) >= full_loop_B.tol_o) {
        numDependent = -1;
        exitg1 = true;
      } else {
        full_loop_B.c_idx_e++;
      }
    }
  }

  return numDependent;
}

static void full_loop_factorQRE_p4(snaQeDJ4fX7UykrKyr5M8jC_full__T *obj, const
  real_T A[399], int32_T mrows, int32_T ncols)
{
  boolean_T guard1 = false;
  full_loop_B.b_idx_k = mrows * ncols;
  guard1 = false;
  if (full_loop_B.b_idx_k > 0) {
    for (full_loop_B.b_idx_k = 0; full_loop_B.b_idx_k < ncols;
         full_loop_B.b_idx_k++) {
      full_loop_B.iA0_tmp_f = 21 * full_loop_B.b_idx_k - 1;
      if (0 <= mrows - 1) {
        memcpy(&obj->QR[full_loop_B.iA0_tmp_f + 1], &A[full_loop_B.iA0_tmp_f + 1],
               ((mrows + full_loop_B.iA0_tmp_f) - full_loop_B.iA0_tmp_f) *
               sizeof(real_T));
      }
    }

    guard1 = true;
  } else if (full_loop_B.b_idx_k == 0) {
    obj->mrows = mrows;
    obj->ncols = ncols;
    obj->minRowCol = 0;
  } else {
    guard1 = true;
  }

  if (guard1) {
    obj->usedPivoting = true;
    obj->mrows = mrows;
    obj->ncols = ncols;
    if (mrows < ncols) {
      obj->minRowCol = mrows;
    } else {
      obj->minRowCol = ncols;
    }

    memcpy(&full_loop_B.obj_n[0], &obj->QR[0], 441U * sizeof(real_T));
    full_loop_xgeqp3_p(full_loop_B.obj_n, mrows, ncols, obj->jpvt, obj->QR,
                       obj->tau);
  }
}

static void full_lo_IndexOfDependentEq__p43(int32_T depIdx[21], int32_T mFixed,
  int32_T nDep, snaQeDJ4fX7UykrKyr5M8jC_full__T *qrmanager, const real_T
  AeqfPrime[399], int32_T mRows, int32_T nCols)
{
  for (full_loop_B.b_idx_g = 0; full_loop_B.b_idx_g < mFixed;
       full_loop_B.b_idx_g++) {
    qrmanager->jpvt[full_loop_B.b_idx_g] = 1;
  }

  if (mFixed + 1 <= nCols) {
    memset(&qrmanager->jpvt[mFixed], 0, (nCols - mFixed) * sizeof(int32_T));
  }

  full_loop_factorQRE_p4(qrmanager, AeqfPrime, mRows, nCols);
  for (full_loop_B.b_idx_g = 0; full_loop_B.b_idx_g < nDep; full_loop_B.b_idx_g
       ++) {
    depIdx[full_loop_B.b_idx_g] = qrmanager->jpvt[(nCols - nDep) +
      full_loop_B.b_idx_g];
  }
}

static void full_loop_countsort_p43(int32_T x[21], int32_T xLen, int32_T
  workspace[21], int32_T xMin, int32_T xMax)
{
  int32_T idxStart;
  int32_T idxEnd;
  int32_T c;
  int32_T idxFill;
  int32_T b_tmp;
  if ((xLen <= 1) || (xMax <= xMin)) {
  } else {
    b_tmp = xMax - xMin;
    if (0 <= b_tmp) {
      memset(&workspace[0], 0, (b_tmp + 1) * sizeof(int32_T));
    }

    for (idxStart = 0; idxStart < xLen; idxStart++) {
      idxEnd = x[idxStart] - xMin;
      workspace[idxEnd]++;
    }

    for (idxStart = 2; idxStart <= b_tmp + 1; idxStart++) {
      workspace[idxStart - 1] += workspace[idxStart - 2];
    }

    idxStart = 1;
    idxEnd = workspace[0];
    c = b_tmp - 1;
    for (b_tmp = 0; b_tmp <= c; b_tmp++) {
      for (idxFill = idxStart; idxFill <= idxEnd; idxFill++) {
        x[idxFill - 1] = b_tmp + xMin;
      }

      idxStart = workspace[b_tmp] + 1;
      idxEnd = workspace[b_tmp + 1];
    }

    for (b_tmp = idxStart; b_tmp <= idxEnd; b_tmp++) {
      x[b_tmp - 1] = xMax;
    }
  }
}

static void full_loop_removeConstr_p(sH6xx18cQHI5sgA7Ajla4nE_full__T *obj,
  int32_T idx_global)
{
  int32_T b;
  int32_T b_idx;
  int32_T TYPE_tmp;
  TYPE_tmp = obj->Wid[idx_global - 1] - 1;
  obj->isActiveConstr[(obj->isActiveIdx[TYPE_tmp] + obj->Wlocalidx[idx_global -
                       1]) - 2] = false;
  obj->Wid[idx_global - 1] = obj->Wid[obj->nActiveConstr - 1];
  obj->Wlocalidx[idx_global - 1] = obj->Wlocalidx[obj->nActiveConstr - 1];
  b = obj->nVar - 1;
  for (b_idx = 0; b_idx <= b; b_idx++) {
    obj->ATwset[b_idx + 21 * (idx_global - 1)] = obj->ATwset[(obj->nActiveConstr
      - 1) * 21 + b_idx];
  }

  obj->bwset[idx_global - 1] = obj->bwset[obj->nActiveConstr - 1];
  obj->nActiveConstr--;
  obj->nWConstr[TYPE_tmp]--;
}

static void full_loop_removeEqConstr_p(sH6xx18cQHI5sgA7Ajla4nE_full__T *obj,
  int32_T idx_global)
{
  int32_T totalEq;
  int32_T b_idx;
  int32_T TYPE_tmp;
  int32_T b_tmp;
  totalEq = (obj->nWConstr[0] + obj->nWConstr[1]) - 1;
  if ((totalEq + 1 == 0) || (idx_global > totalEq + 1)) {
  } else if ((totalEq + 1 == obj->nActiveConstr) || (totalEq + 1 == idx_global))
  {
    obj->mEqRemoved++;
    obj->indexEqRemoved[obj->mEqRemoved - 1] = obj->Wlocalidx[idx_global - 1];
    full_loop_removeConstr_p(obj, idx_global);
  } else {
    obj->mEqRemoved++;
    TYPE_tmp = obj->Wid[idx_global - 1] - 1;
    obj->indexEqRemoved[obj->mEqRemoved - 1] = obj->Wlocalidx[idx_global - 1];
    obj->isActiveConstr[(obj->isActiveIdx[obj->Wid[idx_global - 1] - 1] +
                         obj->Wlocalidx[idx_global - 1]) - 2] = false;
    obj->Wid[idx_global - 1] = obj->Wid[totalEq];
    obj->Wlocalidx[idx_global - 1] = obj->Wlocalidx[totalEq];
    b_tmp = obj->nVar - 1;
    for (b_idx = 0; b_idx <= b_tmp; b_idx++) {
      obj->ATwset[b_idx + 21 * (idx_global - 1)] = obj->ATwset[21 * totalEq +
        b_idx];
    }

    obj->bwset[idx_global - 1] = obj->bwset[totalEq];
    obj->Wid[totalEq] = obj->Wid[obj->nActiveConstr - 1];
    obj->Wlocalidx[totalEq] = obj->Wlocalidx[obj->nActiveConstr - 1];
    b_tmp = obj->nVar - 1;
    for (b_idx = 0; b_idx <= b_tmp; b_idx++) {
      obj->ATwset[b_idx + 21 * totalEq] = obj->ATwset[(obj->nActiveConstr - 1) *
        21 + b_idx];
    }

    obj->bwset[totalEq] = obj->bwset[obj->nActiveConstr - 1];
    obj->nActiveConstr--;
    obj->nWConstr[TYPE_tmp]--;
  }
}

static void full_loop_RemoveDependentEq__p(const real_T
  memspace_workspace_double[441], int32_T memspace_workspace_int[21], int32_T
  memspace_workspace_sort[21], sH6xx18cQHI5sgA7Ajla4nE_full__T *workingset,
  snaQeDJ4fX7UykrKyr5M8jC_full__T *qrmanager, int32_T *nDepInd, real_T
  b_memspace_workspace_double[441])
{
  memcpy(&b_memspace_workspace_double[0], &memspace_workspace_double[0], 441U *
         sizeof(real_T));
  full_loop_B.nVar_k = workingset->nVar - 1;
  full_loop_B.mTotalWorkingEq = workingset->nWConstr[1] + workingset->nWConstr[0];
  *nDepInd = 0;
  if (full_loop_B.mTotalWorkingEq > 0) {
    for (full_loop_B.b_idx_row_b = 0; full_loop_B.b_idx_row_b <
         full_loop_B.mTotalWorkingEq; full_loop_B.b_idx_row_b++) {
      for (full_loop_B.b_idx_col_h = 0; full_loop_B.b_idx_col_h <=
           full_loop_B.nVar_k; full_loop_B.b_idx_col_h++) {
        qrmanager->QR[full_loop_B.b_idx_row_b + 21 * full_loop_B.b_idx_col_h] =
          workingset->ATwset[21 * full_loop_B.b_idx_row_b +
          full_loop_B.b_idx_col_h];
      }
    }

    *nDepInd = full_ComputeNumDependentEq__p43(qrmanager, workingset->bwset,
      full_loop_B.mTotalWorkingEq, workingset->nVar);
    if (*nDepInd > 0) {
      full_lo_IndexOfDependentEq__p43(memspace_workspace_int,
        workingset->nWConstr[0], *nDepInd, qrmanager, workingset->ATwset,
        workingset->nVar, full_loop_B.mTotalWorkingEq);
      full_loop_countsort_p43(memspace_workspace_int, *nDepInd,
        memspace_workspace_sort, 1, full_loop_B.mTotalWorkingEq);
      for (full_loop_B.b_idx_row_b = *nDepInd; full_loop_B.b_idx_row_b >= 1;
           full_loop_B.b_idx_row_b--) {
        full_loop_removeEqConstr_p(workingset,
          memspace_workspace_int[full_loop_B.b_idx_row_b - 1]);
      }
    }
  }
}

static void full_loop_removeAllIneqConstr(const sH6xx18cQHI5sgA7Ajla4nE_full__T *
  obj, sH6xx18cQHI5sgA7Ajla4nE_full__T *b_obj)
{
  int32_T idxEndIneq;
  int32_T idx_global;
  int32_T idxStartIneq_tmp;
  *b_obj = *obj;
  idxStartIneq_tmp = obj->nWConstr[0] + obj->nWConstr[1];
  idxEndIneq = obj->nActiveConstr;
  for (idx_global = idxStartIneq_tmp + 1; idx_global <= idxEndIneq; idx_global++)
  {
    b_obj->isActiveConstr[(obj->isActiveIdx[obj->Wid[idx_global - 1] - 1] +
      obj->Wlocalidx[idx_global - 1]) - 2] = false;
  }

  b_obj->nWConstr[2] = 0;
  b_obj->nWConstr[3] = 0;
  b_obj->nWConstr[4] = 0;
  b_obj->nActiveConstr = idxStartIneq_tmp;
}

static void full_loo_RemoveDependentIneq__p(sH6xx18cQHI5sgA7Ajla4nE_full__T
  *workingset, snaQeDJ4fX7UykrKyr5M8jC_full__T *qrmanager, const real_T
  memspace_workspace_double[441], int32_T memspace_workspace_int[21], int32_T
  memspace_workspace_sort[21], real_T tolfactor, real_T
  b_memspace_workspace_double[441])
{
  memcpy(&b_memspace_workspace_double[0], &memspace_workspace_double[0], 441U *
         sizeof(real_T));
  full_loop_B.nActiveConstr = workingset->nActiveConstr;
  full_loop_B.nFixedConstr = (workingset->nWConstr[1] + workingset->nWConstr[0])
    + 1;
  if ((workingset->nWConstr[2] + workingset->nWConstr[3]) + workingset->
      nWConstr[4] > 0) {
    full_loop_B.tol = tolfactor * static_cast<real_T>(workingset->nVar) *
      2.2204460492503131E-16;
    for (full_loop_B.b_idx_i = 0; full_loop_B.b_idx_i <=
         full_loop_B.nFixedConstr - 2; full_loop_B.b_idx_i++) {
      qrmanager->jpvt[full_loop_B.b_idx_i] = 1;
    }

    if (full_loop_B.nFixedConstr <= full_loop_B.nActiveConstr) {
      memset(&qrmanager->jpvt[full_loop_B.nFixedConstr + -1], 0,
             ((full_loop_B.nActiveConstr - full_loop_B.nFixedConstr) + 1) *
             sizeof(int32_T));
    }

    full_loop_factorQRE_p4(qrmanager, workingset->ATwset, workingset->nVar,
      workingset->nActiveConstr);
    full_loop_B.nActiveConstr = -1;
    full_loop_B.b_idx_i = workingset->nActiveConstr - 1;
    while (full_loop_B.b_idx_i + 1 > workingset->nVar) {
      full_loop_B.nActiveConstr++;
      memspace_workspace_int[full_loop_B.nActiveConstr] = qrmanager->
        jpvt[full_loop_B.b_idx_i];
      full_loop_B.b_idx_i--;
    }

    if (full_loop_B.b_idx_i + 1 <= workingset->nVar) {
      while ((full_loop_B.b_idx_i + 1 > full_loop_B.nFixedConstr - 1) && (fabs
              (qrmanager->QR[21 * full_loop_B.b_idx_i + full_loop_B.b_idx_i]) <
              full_loop_B.tol)) {
        full_loop_B.nActiveConstr++;
        memspace_workspace_int[full_loop_B.nActiveConstr] = qrmanager->
          jpvt[full_loop_B.b_idx_i];
        full_loop_B.b_idx_i--;
      }
    }

    full_loop_countsort_p43(memspace_workspace_int, full_loop_B.nActiveConstr +
      1, memspace_workspace_sort, full_loop_B.nFixedConstr,
      workingset->nActiveConstr);
    for (full_loop_B.b_idx_i = full_loop_B.nActiveConstr + 1;
         full_loop_B.b_idx_i >= 1; full_loop_B.b_idx_i--) {
      full_loop_removeConstr_p(workingset,
        memspace_workspace_int[full_loop_B.b_idx_i - 1]);
    }
  }
}

static void full_loop_xgemv_p(int32_T m, int32_T n, const real_T A[399], const
  real_T x[21], const real_T y[441], real_T b_y[441])
{
  int32_T ix;
  int32_T iy;
  int32_T b;
  int32_T iac;
  int32_T d;
  int32_T ia;
  memcpy(&b_y[0], &y[0], 441U * sizeof(real_T));
  if ((m == 0) || (n == 0)) {
  } else {
    iy = 0;
    b = (n - 1) * 21;
    for (iac = 1; iac <= b + 1; iac += 21) {
      ix = 0;
      full_loop_B.c_o = 0.0;
      d = iac + m;
      for (ia = iac; ia < d; ia++) {
        full_loop_B.c_o += A[ia - 1] * x[ix];
        ix++;
      }

      b_y[iy] += -full_loop_B.c_o;
      iy++;
    }
  }
}

static void full_loop_xgeqrf(const real_T A[441], int32_T m, int32_T n, real_T
  b_A[441], real_T tau[21])
{
  memcpy(&b_A[0], &A[0], 441U * sizeof(real_T));
  if (m < n) {
    full_loop_B.minmn = m;
  } else {
    full_loop_B.minmn = n;
  }

  memset(&tau[0], 0, 21U * sizeof(real_T));
  if (full_loop_B.minmn >= 1) {
    full_loop_qrf_p(A, m, n, full_loop_B.minmn, tau, b_A);
  }
}

static void full_loop_factorQR_p4(snaQeDJ4fX7UykrKyr5M8jC_full__T *obj, const
  real_T A[399], int32_T mrows, int32_T ncols)
{
  boolean_T guard1 = false;
  full_loop_B.b_idx_c = mrows * ncols;
  guard1 = false;
  if (full_loop_B.b_idx_c > 0) {
    for (full_loop_B.b_idx_c = 0; full_loop_B.b_idx_c < ncols;
         full_loop_B.b_idx_c++) {
      full_loop_B.iA0_tmp = 21 * full_loop_B.b_idx_c - 1;
      if (0 <= mrows - 1) {
        memcpy(&obj->QR[full_loop_B.iA0_tmp + 1], &A[full_loop_B.iA0_tmp + 1],
               ((mrows + full_loop_B.iA0_tmp) - full_loop_B.iA0_tmp) * sizeof
               (real_T));
      }
    }

    guard1 = true;
  } else if (full_loop_B.b_idx_c == 0) {
    obj->mrows = mrows;
    obj->ncols = ncols;
    obj->minRowCol = 0;
  } else {
    guard1 = true;
  }

  if (guard1) {
    obj->usedPivoting = false;
    obj->mrows = mrows;
    obj->ncols = ncols;
    for (full_loop_B.b_idx_c = 0; full_loop_B.b_idx_c < ncols;
         full_loop_B.b_idx_c++) {
      obj->jpvt[full_loop_B.b_idx_c] = full_loop_B.b_idx_c + 1;
    }

    if (mrows < ncols) {
      obj->minRowCol = mrows;
    } else {
      obj->minRowCol = ncols;
    }

    memcpy(&full_loop_B.obj[0], &obj->QR[0], 441U * sizeof(real_T));
    full_loop_xgeqrf(full_loop_B.obj, mrows, ncols, obj->QR, obj->tau);
  }
}

static void full_loop_xtrsm_p(int32_T m, const real_T A[441], const real_T B[441],
  real_T b_B[441])
{
  real_T temp;
  int32_T iAcol;
  int32_T b_i;
  int32_T b;
  int32_T b_k;
  memcpy(&b_B[0], &B[0], 441U * sizeof(real_T));
  for (b_i = 0; b_i < m; b_i++) {
    iAcol = 21 * b_i;
    temp = b_B[b_i];
    b = b_i - 1;
    for (b_k = 0; b_k <= b; b_k++) {
      temp -= A[b_k + iAcol] * b_B[b_k];
    }

    b_B[b_i] = temp / A[b_i + iAcol];
  }

  for (b_i = 0; b_i < m; b_i++) {
    iAcol = 21 * b_i;
    temp = b_B[b_i + 21];
    b = b_i - 1;
    for (b_k = 0; b_k <= b; b_k++) {
      temp -= A[b_k + iAcol] * b_B[b_k + 21];
    }

    b_B[b_i + 21] = temp / A[b_i + iAcol];
  }
}

static void full_loop_xgemm_p(int32_T m, int32_T k, const real_T A[441], const
  real_T B[441], const real_T C[441], real_T b_C[441])
{
  int32_T ar;
  int32_T ia;
  int32_T e;
  int32_T ib;
  int32_T g;
  int32_T b_ic;
  memcpy(&b_C[0], &C[0], 441U * sizeof(real_T));
  if (m != 0) {
    if (1 <= m) {
      memset(&b_C[0], 0, m * sizeof(real_T));
    }

    ar = m + 21;
    if (22 <= ar) {
      memset(&b_C[21], 0, (ar + -21) * sizeof(real_T));
    }

    ar = 0;
    for (ib = 1; ib <= k; ib++) {
      ia = ar - 1;
      for (b_ic = 1; b_ic <= m; b_ic++) {
        ia++;
        b_C[b_ic - 1] += B[ib - 1] * A[ia];
      }

      ar += 21;
    }

    ar = 0;
    e = k + 21;
    for (ib = 22; ib <= e; ib++) {
      ia = ar - 1;
      g = m + 21;
      for (b_ic = 22; b_ic <= g; b_ic++) {
        ia++;
        b_C[b_ic - 1] += B[ib - 1] * A[ia];
      }

      ar += 21;
    }
  }
}

static void full_loop_factorQR(const snaQeDJ4fX7UykrKyr5M8jC_full__T *obj,
  int32_T mrows, int32_T ncols, snaQeDJ4fX7UykrKyr5M8jC_full__T *b_obj)
{
  *b_obj = *obj;
  if (mrows * ncols == 0) {
    b_obj->mrows = mrows;
    b_obj->ncols = ncols;
    b_obj->minRowCol = 0;
  } else {
    b_obj->usedPivoting = false;
    b_obj->mrows = mrows;
    b_obj->ncols = ncols;
    for (full_loop_B.b_idx_m = 0; full_loop_B.b_idx_m < ncols;
         full_loop_B.b_idx_m++) {
      b_obj->jpvt[full_loop_B.b_idx_m] = full_loop_B.b_idx_m + 1;
    }

    if (mrows < ncols) {
      b_obj->minRowCol = mrows;
    } else {
      b_obj->minRowCol = ncols;
    }

    full_loop_xgeqrf(obj->QR, mrows, ncols, b_obj->QR, b_obj->tau);
  }
}

static void full_loop_xgemm(int32_T m, int32_T k, const real_T A[441], const
  real_T B[441], const real_T C[441], real_T b_C[441])
{
  int32_T w;
  int32_T ar;
  real_T temp;
  int32_T e;
  int32_T b_ic;
  int32_T b_w;
  memcpy(&b_C[0], &C[0], 441U * sizeof(real_T));
  if (m != 0) {
    if (1 <= m) {
      memset(&b_C[0], 0, m * sizeof(real_T));
    }

    ar = m + 21;
    if (22 <= ar) {
      memset(&b_C[21], 0, (ar + -21) * sizeof(real_T));
    }

    ar = -1;
    for (b_ic = 1; b_ic <= m; b_ic++) {
      temp = 0.0;
      for (b_w = 0; b_w < k; b_w++) {
        w = b_w + 1;
        temp += A[w + ar] * B[w + -1];
      }

      b_C[b_ic - 1] += temp;
      ar += 21;
    }

    ar = -1;
    e = m + 21;
    for (b_ic = 22; b_ic <= e; b_ic++) {
      temp = 0.0;
      for (b_w = 0; b_w < k; b_w++) {
        w = b_w + 1;
        temp += A[w + ar] * B[w + 20];
      }

      b_C[b_ic - 1] += temp;
      ar += 21;
    }
  }
}

static void full_loop_xtrsm(int32_T m, const real_T A[441], const real_T B[441],
  real_T b_B[441])
{
  int32_T kAcol;
  int32_T i;
  int32_T k;
  int32_T b;
  int32_T b_i;
  real_T tmp;
  memcpy(&b_B[0], &B[0], 441U * sizeof(real_T));
  for (k = m; k >= 1; k--) {
    kAcol = (k - 1) * 21 - 1;
    tmp = b_B[k + -1];
    if (tmp != 0.0) {
      b_B[k + -1] = tmp / A[k + kAcol];
      b = k - 2;
      for (b_i = 0; b_i <= b; b_i++) {
        i = b_i + 1;
        b_B[i + -1] -= b_B[k + -1] * A[i + kAcol];
      }
    }
  }

  for (k = m; k >= 1; k--) {
    kAcol = (k - 1) * 21 - 1;
    tmp = b_B[k + 20];
    if (tmp != 0.0) {
      b_B[k + 20] = tmp / A[k + kAcol];
      b = k - 2;
      for (b_i = 0; b_i <= b; b_i++) {
        i = b_i + 1;
        b_B[i + 20] -= b_B[k + 20] * A[i + kAcol];
      }
    }
  }
}

static void full_loop_xaxpy(int32_T n, const real_T x[21], const real_T y[441],
  real_T b_y[441])
{
  int32_T k;
  memcpy(&b_y[0], &y[0], 441U * sizeof(real_T));
  if (n >= 1) {
    for (k = 0; k < n; k++) {
      b_y[k] += x[k];
    }
  }
}

static void maxConstraintViolation_AMats_no(const
  sH6xx18cQHI5sgA7Ajla4nE_full__T *obj, const real_T x[441], real_T *v,
  sH6xx18cQHI5sgA7Ajla4nE_full__T *b_obj)
{
  int32_T mEq;
  int32_T iyend;
  int32_T ix;
  int32_T b_iy;
  int32_T iac;
  int32_T d;
  int32_T ia;
  *b_obj = *obj;
  *v = 0.0;
  mEq = obj->sizes[1] - 1;
  memcpy(&b_obj->maxConstrWorkspace[0], &obj->maxConstrWorkspace[0], 19U *
         sizeof(real_T));
  if (0 <= mEq) {
    memcpy(&b_obj->maxConstrWorkspace[0], &obj->beq[0], (mEq + 1) * sizeof
           (real_T));
  }

  if ((obj->nVar == 0) || (obj->sizes[1] == 0)) {
  } else {
    iyend = obj->sizes[1] - 1;
    for (b_iy = 0; b_iy <= iyend; b_iy++) {
      b_obj->maxConstrWorkspace[b_iy] = -b_obj->maxConstrWorkspace[b_iy];
    }

    iyend = 0;
    b_iy = (obj->sizes[1] - 1) * 21;
    for (iac = 1; iac <= b_iy + 1; iac += 21) {
      ix = 0;
      full_loop_B.c_d = 0.0;
      d = iac + obj->nVar;
      for (ia = iac; ia < d; ia++) {
        full_loop_B.c_d += obj->Aeq[ia - 1] * x[ix];
        ix++;
      }

      b_obj->maxConstrWorkspace[iyend] += full_loop_B.c_d;
      iyend++;
    }
  }

  for (iyend = 0; iyend <= mEq; iyend++) {
    full_loop_B.c_d = fabs(b_obj->maxConstrWorkspace[iyend]);
    if ((!(*v > full_loop_B.c_d)) && (!rtIsNaN(full_loop_B.c_d))) {
      *v = full_loop_B.c_d;
    }
  }
}

static void maxConstraintViolation_AMats_re(const
  sH6xx18cQHI5sgA7Ajla4nE_full__T *obj, const real_T x[441], real_T *v,
  sH6xx18cQHI5sgA7Ajla4nE_full__T *b_obj)
{
  int32_T mEq;
  int32_T iyend;
  int32_T ix;
  int32_T b_iy;
  int32_T iac;
  int32_T ia;
  *b_obj = *obj;
  *v = 0.0;
  mEq = obj->sizes[1] - 1;
  memcpy(&b_obj->maxConstrWorkspace[0], &obj->maxConstrWorkspace[0], 19U *
         sizeof(real_T));
  if (0 <= mEq) {
    memcpy(&b_obj->maxConstrWorkspace[0], &obj->beq[0], (mEq + 1) * sizeof
           (real_T));
  }

  if (obj->sizes[1] != 0) {
    iyend = obj->sizes[1] - 1;
    for (b_iy = 0; b_iy <= iyend; b_iy++) {
      b_obj->maxConstrWorkspace[b_iy] = -b_obj->maxConstrWorkspace[b_iy];
    }

    iyend = 0;
    b_iy = (obj->sizes[1] - 1) * 21;
    for (iac = 1; iac <= b_iy + 1; iac += 21) {
      ix = 0;
      full_loop_B.c_n = 0.0;
      for (ia = iac; ia <= iac + 7; ia++) {
        full_loop_B.c_n += obj->Aeq[ia - 1] * x[ix];
        ix++;
      }

      b_obj->maxConstrWorkspace[iyend] += full_loop_B.c_n;
      iyend++;
    }
  }

  for (iyend = 0; iyend <= mEq; iyend++) {
    b_obj->maxConstrWorkspace[iyend] = (b_obj->maxConstrWorkspace[iyend] -
      x[iyend + 8]) + x[(mEq + iyend) + 9];
    full_loop_B.c_n = fabs(b_obj->maxConstrWorkspace[iyend]);
    if ((!(*v > full_loop_B.c_n)) && (!rtIsNaN(full_loop_B.c_n))) {
      *v = full_loop_B.c_n;
    }
  }
}

static void full_loo_maxConstraintViolation(const
  sH6xx18cQHI5sgA7Ajla4nE_full__T *obj, const real_T x[441], real_T *v,
  sH6xx18cQHI5sgA7Ajla4nE_full__T *b_obj)
{
  full_loop_B.mLB_j = obj->sizes[3] - 1;
  if (obj->probType == 2) {
    maxConstraintViolation_AMats_re(obj, x, v, b_obj);
  } else {
    maxConstraintViolation_AMats_no(obj, x, v, b_obj);
  }

  if (obj->sizes[3] > 0) {
    for (full_loop_B.b_idx_h = 0; full_loop_B.b_idx_h <= full_loop_B.mLB_j;
         full_loop_B.b_idx_h++) {
      full_loop_B.u1_i = -x[b_obj->indexLB[full_loop_B.b_idx_h] - 1] - b_obj->
        lb[b_obj->indexLB[full_loop_B.b_idx_h] - 1];
      if ((!(*v > full_loop_B.u1_i)) && (!rtIsNaN(full_loop_B.u1_i))) {
        *v = full_loop_B.u1_i;
      }
    }
  }
}

static void maxConstraintViolation_AMats_p4(const
  sH6xx18cQHI5sgA7Ajla4nE_full__T *obj, const real_T x[441], real_T *v,
  sH6xx18cQHI5sgA7Ajla4nE_full__T *b_obj)
{
  int32_T mEq;
  int32_T iyend;
  int32_T ix;
  int32_T b_iy;
  int32_T iac;
  int32_T d;
  int32_T ia;
  *b_obj = *obj;
  *v = 0.0;
  mEq = obj->sizes[1] - 1;
  memcpy(&b_obj->maxConstrWorkspace[0], &obj->maxConstrWorkspace[0], 19U *
         sizeof(real_T));
  if (0 <= mEq) {
    memcpy(&b_obj->maxConstrWorkspace[0], &obj->beq[0], (mEq + 1) * sizeof
           (real_T));
  }

  if ((obj->nVar == 0) || (obj->sizes[1] == 0)) {
  } else {
    iyend = obj->sizes[1] - 1;
    for (b_iy = 0; b_iy <= iyend; b_iy++) {
      b_obj->maxConstrWorkspace[b_iy] = -b_obj->maxConstrWorkspace[b_iy];
    }

    iyend = 0;
    b_iy = (obj->sizes[1] - 1) * 21;
    for (iac = 1; iac <= b_iy + 1; iac += 21) {
      ix = 21;
      full_loop_B.c_cx = 0.0;
      d = iac + obj->nVar;
      for (ia = iac; ia < d; ia++) {
        full_loop_B.c_cx += obj->Aeq[ia - 1] * x[ix];
        ix++;
      }

      b_obj->maxConstrWorkspace[iyend] += full_loop_B.c_cx;
      iyend++;
    }
  }

  for (iyend = 0; iyend <= mEq; iyend++) {
    full_loop_B.c_cx = fabs(b_obj->maxConstrWorkspace[iyend]);
    if ((!(*v > full_loop_B.c_cx)) && (!rtIsNaN(full_loop_B.c_cx))) {
      *v = full_loop_B.c_cx;
    }
  }
}

static void maxConstraintViolation_AMats__p(const
  sH6xx18cQHI5sgA7Ajla4nE_full__T *obj, const real_T x[441], real_T *v,
  sH6xx18cQHI5sgA7Ajla4nE_full__T *b_obj)
{
  int32_T mEq;
  int32_T iyend;
  int32_T ix;
  int32_T b_iy;
  int32_T iac;
  int32_T ia;
  *b_obj = *obj;
  *v = 0.0;
  mEq = obj->sizes[1] - 1;
  memcpy(&b_obj->maxConstrWorkspace[0], &obj->maxConstrWorkspace[0], 19U *
         sizeof(real_T));
  if (0 <= mEq) {
    memcpy(&b_obj->maxConstrWorkspace[0], &obj->beq[0], (mEq + 1) * sizeof
           (real_T));
  }

  if (obj->sizes[1] != 0) {
    iyend = obj->sizes[1] - 1;
    for (b_iy = 0; b_iy <= iyend; b_iy++) {
      b_obj->maxConstrWorkspace[b_iy] = -b_obj->maxConstrWorkspace[b_iy];
    }

    iyend = 0;
    b_iy = (obj->sizes[1] - 1) * 21;
    for (iac = 1; iac <= b_iy + 1; iac += 21) {
      ix = 21;
      full_loop_B.c_h = 0.0;
      for (ia = iac; ia <= iac + 7; ia++) {
        full_loop_B.c_h += obj->Aeq[ia - 1] * x[ix];
        ix++;
      }

      b_obj->maxConstrWorkspace[iyend] += full_loop_B.c_h;
      iyend++;
    }
  }

  for (iyend = 0; iyend <= mEq; iyend++) {
    b_obj->maxConstrWorkspace[iyend] = (b_obj->maxConstrWorkspace[iyend] -
      x[iyend + 29]) + x[(mEq + iyend) + 30];
    full_loop_B.c_h = fabs(b_obj->maxConstrWorkspace[iyend]);
    if ((!(*v > full_loop_B.c_h)) && (!rtIsNaN(full_loop_B.c_h))) {
      *v = full_loop_B.c_h;
    }
  }
}

static void full_l_maxConstraintViolation_p(const
  sH6xx18cQHI5sgA7Ajla4nE_full__T *obj, const real_T x[441], real_T *v,
  sH6xx18cQHI5sgA7Ajla4nE_full__T *b_obj)
{
  full_loop_B.mLB_m = obj->sizes[3] - 1;
  if (obj->probType == 2) {
    maxConstraintViolation_AMats__p(obj, x, v, b_obj);
  } else {
    maxConstraintViolation_AMats_p4(obj, x, v, b_obj);
  }

  if (obj->sizes[3] > 0) {
    for (full_loop_B.b_idx_ku = 0; full_loop_B.b_idx_ku <= full_loop_B.mLB_m;
         full_loop_B.b_idx_ku++) {
      full_loop_B.u1_c = -x[b_obj->indexLB[full_loop_B.b_idx_ku] + 20] -
        b_obj->lb[b_obj->indexLB[full_loop_B.b_idx_ku] - 1];
      if ((!(*v > full_loop_B.u1_c)) && (!rtIsNaN(full_loop_B.u1_c))) {
        *v = full_loop_B.u1_c;
      }
    }
  }
}

static boolean_T full_loop_isfinite(real_T x)
{
  return (!rtIsInf(x)) && (!rtIsNaN(x));
}

static void full__feasibleX0ForWorkingSet_p(const real_T workspace[441], real_T
  xCurrent[21], sH6xx18cQHI5sgA7Ajla4nE_full__T *workingset,
  snaQeDJ4fX7UykrKyr5M8jC_full__T *qrmanager, boolean_T *nonDegenerateWset,
  real_T b_workspace[441])
{
  int32_T exitg1;
  memcpy(&b_workspace[0], &workspace[0], 441U * sizeof(real_T));
  full_loop_B.mWConstr = workingset->nActiveConstr - 1;
  full_loop_B.nVar_da = workingset->nVar - 1;
  *nonDegenerateWset = true;
  if (workingset->nActiveConstr != 0) {
    for (full_loop_B.b_idx = 0; full_loop_B.b_idx <= full_loop_B.mWConstr;
         full_loop_B.b_idx++) {
      b_workspace[full_loop_B.b_idx] = workingset->bwset[full_loop_B.b_idx];
      b_workspace[full_loop_B.b_idx + 21] = workingset->bwset[full_loop_B.b_idx];
    }

    memcpy(&full_loop_B.b_workspace_b[0], &b_workspace[0], 441U * sizeof(real_T));
    full_loop_xgemv_p(workingset->nVar, workingset->nActiveConstr,
                      workingset->ATwset, xCurrent, full_loop_B.b_workspace_b,
                      b_workspace);
    if (workingset->nActiveConstr >= workingset->nVar) {
      for (full_loop_B.b_idx = 0; full_loop_B.b_idx <= full_loop_B.nVar_da;
           full_loop_B.b_idx++) {
        for (full_loop_B.b_idx_row = 0; full_loop_B.b_idx_row <=
             full_loop_B.mWConstr; full_loop_B.b_idx_row++) {
          qrmanager->QR[full_loop_B.b_idx_row + 21 * full_loop_B.b_idx] =
            workingset->ATwset[21 * full_loop_B.b_idx_row + full_loop_B.b_idx];
        }
      }

      full_loop_B.qrmanager_b = *qrmanager;
      full_loop_factorQR(&full_loop_B.qrmanager_b, workingset->nActiveConstr,
                         workingset->nVar, qrmanager);
      full_loop_computeQ__p(qrmanager, qrmanager->mrows);
      memcpy(&full_loop_B.b_workspace_b[0], &b_workspace[0], 441U * sizeof
             (real_T));
      memcpy(&full_loop_B.b_workspace[0], &b_workspace[0], 441U * sizeof(real_T));
      full_loop_xgemm(workingset->nVar, workingset->nActiveConstr, qrmanager->Q,
                      full_loop_B.b_workspace_b, full_loop_B.b_workspace,
                      b_workspace);
      memcpy(&full_loop_B.b_workspace_b[0], &b_workspace[0], 441U * sizeof
             (real_T));
      full_loop_xtrsm(workingset->nVar, qrmanager->QR, full_loop_B.b_workspace_b,
                      b_workspace);
    } else {
      full_loop_factorQR_p4(qrmanager, workingset->ATwset, workingset->nVar,
                            workingset->nActiveConstr);
      full_loop_computeQ__p(qrmanager, qrmanager->minRowCol);
      memcpy(&full_loop_B.b_workspace_b[0], &b_workspace[0], 441U * sizeof
             (real_T));
      full_loop_xtrsm_p(workingset->nActiveConstr, qrmanager->QR,
                        full_loop_B.b_workspace_b, b_workspace);
      memcpy(&full_loop_B.b_workspace_b[0], &b_workspace[0], 441U * sizeof
             (real_T));
      memcpy(&full_loop_B.b_workspace[0], &b_workspace[0], 441U * sizeof(real_T));
      full_loop_xgemm_p(workingset->nVar, workingset->nActiveConstr,
                        qrmanager->Q, full_loop_B.b_workspace_b,
                        full_loop_B.b_workspace, b_workspace);
    }

    full_loop_B.b_idx = 1;
    do {
      exitg1 = 0;
      if (full_loop_B.b_idx - 1 <= full_loop_B.nVar_da) {
        full_loop_B.b_idx_row = full_loop_B.b_idx - 1;
        if ((!full_loop_isfinite(b_workspace[full_loop_B.b_idx_row])) ||
            (!full_loop_isfinite(b_workspace[full_loop_B.b_idx_row + 21]))) {
          *nonDegenerateWset = false;
          exitg1 = 1;
        } else {
          full_loop_B.b_idx++;
        }
      } else {
        memcpy(&full_loop_B.b_workspace_b[0], &b_workspace[0], 441U * sizeof
               (real_T));
        full_loop_xaxpy(full_loop_B.nVar_da + 1, xCurrent,
                        full_loop_B.b_workspace_b, b_workspace);
        full_loo_maxConstraintViolation(workingset, b_workspace,
          &full_loop_B.constrViolation_minnormX, &full_loop_B.c_workingset_m);
        full_l_maxConstraintViolation_p(&full_loop_B.c_workingset_m, b_workspace,
          &full_loop_B.constrViolation_basicX, workingset);
        if ((full_loop_B.constrViolation_minnormX <= 2.2204460492503131E-16) ||
            (full_loop_B.constrViolation_minnormX <
             full_loop_B.constrViolation_basicX)) {
          if (0 <= full_loop_B.nVar_da) {
            memcpy(&xCurrent[0], &b_workspace[0], (full_loop_B.nVar_da + 1) *
                   sizeof(real_T));
          }
        } else {
          if (0 <= full_loop_B.nVar_da) {
            memcpy(&xCurrent[0], &b_workspace[21], (full_loop_B.nVar_da + 1) *
                   sizeof(real_T));
          }
        }

        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
}

static void maxConstraintViolation_AMa_p43r(const
  sH6xx18cQHI5sgA7Ajla4nE_full__T *obj, const real_T x[21], real_T *v,
  sH6xx18cQHI5sgA7Ajla4nE_full__T *b_obj)
{
  int32_T mEq;
  int32_T iyend;
  int32_T ix;
  int32_T b_iy;
  int32_T iac;
  int32_T d;
  int32_T ia;
  *b_obj = *obj;
  *v = 0.0;
  mEq = obj->sizes[1] - 1;
  memcpy(&b_obj->maxConstrWorkspace[0], &obj->maxConstrWorkspace[0], 19U *
         sizeof(real_T));
  if (0 <= mEq) {
    memcpy(&b_obj->maxConstrWorkspace[0], &obj->beq[0], (mEq + 1) * sizeof
           (real_T));
  }

  if ((obj->nVar == 0) || (obj->sizes[1] == 0)) {
  } else {
    iyend = obj->sizes[1] - 1;
    for (b_iy = 0; b_iy <= iyend; b_iy++) {
      b_obj->maxConstrWorkspace[b_iy] = -b_obj->maxConstrWorkspace[b_iy];
    }

    iyend = 0;
    b_iy = (obj->sizes[1] - 1) * 21;
    for (iac = 1; iac <= b_iy + 1; iac += 21) {
      ix = 0;
      full_loop_B.c_g = 0.0;
      d = iac + obj->nVar;
      for (ia = iac; ia < d; ia++) {
        full_loop_B.c_g += obj->Aeq[ia - 1] * x[ix];
        ix++;
      }

      b_obj->maxConstrWorkspace[iyend] += full_loop_B.c_g;
      iyend++;
    }
  }

  for (iyend = 0; iyend <= mEq; iyend++) {
    full_loop_B.c_g = fabs(b_obj->maxConstrWorkspace[iyend]);
    if ((!(*v > full_loop_B.c_g)) && (!rtIsNaN(full_loop_B.c_g))) {
      *v = full_loop_B.c_g;
    }
  }
}

static void maxConstraintViolation_AMat_p43(const
  sH6xx18cQHI5sgA7Ajla4nE_full__T *obj, const real_T x[21], real_T *v,
  sH6xx18cQHI5sgA7Ajla4nE_full__T *b_obj)
{
  int32_T mEq;
  int32_T iyend;
  int32_T ix;
  int32_T b_iy;
  int32_T iac;
  int32_T ia;
  *b_obj = *obj;
  *v = 0.0;
  mEq = obj->sizes[1] - 1;
  memcpy(&b_obj->maxConstrWorkspace[0], &obj->maxConstrWorkspace[0], 19U *
         sizeof(real_T));
  if (0 <= mEq) {
    memcpy(&b_obj->maxConstrWorkspace[0], &obj->beq[0], (mEq + 1) * sizeof
           (real_T));
  }

  if (obj->sizes[1] != 0) {
    iyend = obj->sizes[1] - 1;
    for (b_iy = 0; b_iy <= iyend; b_iy++) {
      b_obj->maxConstrWorkspace[b_iy] = -b_obj->maxConstrWorkspace[b_iy];
    }

    iyend = 0;
    b_iy = (obj->sizes[1] - 1) * 21;
    for (iac = 1; iac <= b_iy + 1; iac += 21) {
      ix = 0;
      full_loop_B.c_i3 = 0.0;
      for (ia = iac; ia <= iac + 7; ia++) {
        full_loop_B.c_i3 += obj->Aeq[ia - 1] * x[ix];
        ix++;
      }

      b_obj->maxConstrWorkspace[iyend] += full_loop_B.c_i3;
      iyend++;
    }
  }

  for (iyend = 0; iyend <= mEq; iyend++) {
    b_obj->maxConstrWorkspace[iyend] = (b_obj->maxConstrWorkspace[iyend] -
      x[iyend + 8]) + x[(mEq + iyend) + 9];
    full_loop_B.c_i3 = fabs(b_obj->maxConstrWorkspace[iyend]);
    if ((!(*v > full_loop_B.c_i3)) && (!rtIsNaN(full_loop_B.c_i3))) {
      *v = full_loop_B.c_i3;
    }
  }
}

static void full__maxConstraintViolation_p4(const
  sH6xx18cQHI5sgA7Ajla4nE_full__T *obj, const real_T x[21], real_T *v,
  sH6xx18cQHI5sgA7Ajla4nE_full__T *b_obj)
{
  full_loop_B.mLB = obj->sizes[3] - 1;
  if (obj->probType == 2) {
    maxConstraintViolation_AMat_p43(obj, x, v, b_obj);
  } else {
    maxConstraintViolation_AMa_p43r(obj, x, v, b_obj);
  }

  if (obj->sizes[3] > 0) {
    for (full_loop_B.b_idx_nq = 0; full_loop_B.b_idx_nq <= full_loop_B.mLB;
         full_loop_B.b_idx_nq++) {
      full_loop_B.u1_d = -x[b_obj->indexLB[full_loop_B.b_idx_nq] - 1] -
        b_obj->lb[b_obj->indexLB[full_loop_B.b_idx_nq] - 1];
      if ((!(*v > full_loop_B.u1_d)) && (!rtIsNaN(full_loop_B.u1_d))) {
        *v = full_loop_B.u1_d;
      }
    }
  }
}

static void full_loop_PresolveWorkingSet_p(const s2CPTVnVyv153Hb6bxlki6F_full__T
  *solution, const sVTYnQ9ljvmk9dLse9XvTT_full_l_T *memspace, const
  sH6xx18cQHI5sgA7Ajla4nE_full__T *workingset, const
  snaQeDJ4fX7UykrKyr5M8jC_full__T *qrmanager, s2CPTVnVyv153Hb6bxlki6F_full__T
  *b_solution, sVTYnQ9ljvmk9dLse9XvTT_full_l_T *b_memspace,
  sH6xx18cQHI5sgA7Ajla4nE_full__T *b_workingset, snaQeDJ4fX7UykrKyr5M8jC_full__T
  *b_qrmanager)
{
  boolean_T b_okWorkingSet;
  boolean_T guard1 = false;
  *b_solution = *solution;
  b_solution->state = 82;
  memcpy(&full_loop_B.c_memspace_workspace_int[0], &memspace->workspace_int[0],
         21U * sizeof(int32_T));
  memcpy(&full_loop_B.c_memspace_workspace_sort[0], &memspace->workspace_sort[0],
         21U * sizeof(int32_T));
  full_loop_B.c_workingset = *workingset;
  *b_qrmanager = *qrmanager;
  full_loop_RemoveDependentEq__p(memspace->workspace_double,
    full_loop_B.c_memspace_workspace_int, full_loop_B.c_memspace_workspace_sort,
    &full_loop_B.c_workingset, b_qrmanager, &full_loop_B.b_l,
    full_loop_B.c_memspace_workspace_double);
  memcpy(&b_memspace->workspace_double[0],
         &full_loop_B.c_memspace_workspace_double[0], 441U * sizeof(real_T));
  memcpy(&b_memspace->workspace_int[0], &full_loop_B.c_memspace_workspace_int[0],
         21U * sizeof(int32_T));
  memcpy(&b_memspace->workspace_sort[0], &full_loop_B.c_memspace_workspace_sort
         [0], 21U * sizeof(int32_T));
  if (full_loop_B.b_l != -1) {
    full_loo_RemoveDependentIneq__p(&full_loop_B.c_workingset, b_qrmanager,
      full_loop_B.c_memspace_workspace_double,
      full_loop_B.c_memspace_workspace_int,
      full_loop_B.c_memspace_workspace_sort, 100.0,
      full_loop_B.d_memspace_workspace_double);
    memcpy(&b_memspace->workspace_int[0], &full_loop_B.c_memspace_workspace_int
           [0], 21U * sizeof(int32_T));
    memcpy(&b_memspace->workspace_sort[0],
           &full_loop_B.c_memspace_workspace_sort[0], 21U * sizeof(int32_T));
    memcpy(&full_loop_B.c_i[0], &solution->xstar[0], 21U * sizeof(real_T));
    *b_workingset = full_loop_B.c_workingset;
    full__feasibleX0ForWorkingSet_p(full_loop_B.d_memspace_workspace_double,
      full_loop_B.c_i, b_workingset, b_qrmanager, &b_okWorkingSet,
      full_loop_B.c_memspace_workspace_double);
    memcpy(&b_solution->xstar[0], &full_loop_B.c_i[0], 21U * sizeof(real_T));
    memcpy(&b_memspace->workspace_double[0],
           &full_loop_B.c_memspace_workspace_double[0], 441U * sizeof(real_T));
    guard1 = false;
    if (!b_okWorkingSet) {
      memcpy(&b_memspace->workspace_int[0],
             &full_loop_B.c_memspace_workspace_int[0], 21U * sizeof(int32_T));
      memcpy(&b_memspace->workspace_sort[0],
             &full_loop_B.c_memspace_workspace_sort[0], 21U * sizeof(int32_T));
      full_loo_RemoveDependentIneq__p(b_workingset, b_qrmanager,
        full_loop_B.c_memspace_workspace_double, b_memspace->workspace_int,
        b_memspace->workspace_sort, 1000.0,
        full_loop_B.d_memspace_workspace_double);
      memcpy(&b_solution->xstar[0], &full_loop_B.c_i[0], 21U * sizeof(real_T));
      full__feasibleX0ForWorkingSet_p(full_loop_B.d_memspace_workspace_double,
        b_solution->xstar, b_workingset, b_qrmanager, &b_okWorkingSet,
        b_memspace->workspace_double);
      if (!b_okWorkingSet) {
        b_solution->state = -7;
      } else {
        guard1 = true;
      }
    } else {
      guard1 = true;
    }

    if (guard1) {
      if (b_workingset->nWConstr[0] + b_workingset->nWConstr[1] ==
          b_workingset->nVar) {
        full_loop_B.c_workingset = *b_workingset;
        full__maxConstraintViolation_p4(&full_loop_B.c_workingset,
          b_solution->xstar, &full_loop_B.constrViolation, b_workingset);
        if (full_loop_B.constrViolation > 0.01) {
          b_solution->state = -2;
        }
      }
    }
  } else {
    b_solution->state = -3;
    full_loop_removeAllIneqConstr(&full_loop_B.c_workingset, b_workingset);
  }
}

static void full_loop_setPhaseOne(const sJdVcLKPgejLYHLePKb6F6D_full__T *obj,
  int32_T NumVars, sJdVcLKPgejLYHLePKb6F6D_full__T *b_obj)
{
  *b_obj = *obj;
  b_obj->prev_objtype = obj->objtype;
  b_obj->prev_nvar = obj->nvar;
  b_obj->prev_hasLinear = obj->hasLinear;
  b_obj->objtype = 5;
  b_obj->nvar = NumVars;
  b_obj->gammaScalar = 1.0;
  b_obj->hasLinear = true;
}

static void full_loop_linearForm_(boolean_T obj_hasLinear, int32_T obj_nvar,
  const real_T workspace[441], const real_T H[64], const real_T f[21], const
  real_T x[21], real_T b_workspace[441])
{
  int32_T fMultiplier;
  int32_T iy;
  int32_T b;
  int32_T iac;
  int32_T d;
  int32_T ia;
  memcpy(&b_workspace[0], &workspace[0], 441U * sizeof(real_T));
  fMultiplier = 0;
  if (obj_hasLinear) {
    if (0 <= obj_nvar - 1) {
      memcpy(&b_workspace[0], &f[0], obj_nvar * sizeof(real_T));
    }

    fMultiplier = 1;
  }

  if ((obj_nvar == 0) || (obj_nvar == 0)) {
  } else {
    if ((fMultiplier != 1) && (0 <= obj_nvar - 1)) {
      memset(&b_workspace[0], 0, obj_nvar * sizeof(real_T));
    }

    fMultiplier = 0;
    b = (obj_nvar - 1) * obj_nvar;
    for (iac = 1; obj_nvar < 0 ? iac >= b + 1 : iac <= b + 1; iac += obj_nvar) {
      full_loop_B.c_f = 0.5 * x[fMultiplier];
      iy = 0;
      d = iac + obj_nvar;
      for (ia = iac; ia < d; ia++) {
        b_workspace[iy] += H[ia - 1] * full_loop_B.c_f;
        iy++;
      }

      fMultiplier++;
    }
  }
}

static void full_loop_computeFval_p(const sJdVcLKPgejLYHLePKb6F6D_full__T *obj,
  const real_T workspace[441], const real_T H[64], const real_T f[21], const
  real_T x[21], real_T *val, real_T b_workspace[441])
{
  int32_T ixlast;
  int32_T b_k;
  memcpy(&b_workspace[0], &workspace[0], 441U * sizeof(real_T));
  *val = 0.0;
  switch (obj->objtype) {
   case 5:
    *val = x[obj->nvar - 1] * obj->gammaScalar;
    break;

   case 3:
    full_loop_linearForm_(obj->hasLinear, obj->nvar, workspace, H, f, x,
                          b_workspace);
    if (obj->nvar >= 1) {
      ixlast = obj->nvar - 1;
      for (b_k = 0; b_k <= ixlast; b_k++) {
        *val += x[b_k] * b_workspace[b_k];
      }
    }
    break;

   case 4:
    full_loop_linearForm_(obj->hasLinear, obj->nvar, workspace, H, f, x,
                          b_workspace);
    ixlast = obj->nvar;
    full_loop_B.c_h5 = obj->maxVar;
    for (b_k = ixlast + 1; b_k < full_loop_B.c_h5; b_k++) {
      b_workspace[b_k - 1] = 0.5 * obj->beta * x[b_k - 1] + obj->rho;
    }

    if (obj->maxVar - 1 >= 1) {
      ixlast = obj->maxVar - 2;
      for (b_k = 0; b_k <= ixlast; b_k++) {
        *val += x[b_k] * b_workspace[b_k];
      }
    }
    break;
  }
}

static void full_loop_xgemv_p43ri(int32_T m, int32_T n, const real_T A[64],
  int32_T lda, const real_T x[21], real_T y[20])
{
  int32_T iy;
  int32_T ix;
  int32_T b;
  int32_T iac;
  int32_T d;
  int32_T ia;
  if ((m == 0) || (n == 0)) {
  } else {
    if (0 <= m - 1) {
      memset(&y[0], 0, m * sizeof(real_T));
    }

    ix = 0;
    b = (n - 1) * lda;
    for (iac = 1; lda < 0 ? iac >= b + 1 : iac <= b + 1; iac += lda) {
      iy = 0;
      d = iac + m;
      for (ia = iac; ia < d; ia++) {
        y[iy] += A[ia - 1] * x[ix];
        iy++;
      }

      ix++;
    }
  }
}

static void full_loop_computeGrad_StoreHx_p(sJdVcLKPgejLYHLePKb6F6D_full__T *obj,
  const real_T H[64], const real_T f[21], const real_T x[21])
{
  int32_T iy;
  switch (obj->objtype) {
   case 5:
    full_loop_B.b_mg = obj->nvar - 2;
    if (0 <= full_loop_B.b_mg) {
      memset(&obj->grad[0], 0, (full_loop_B.b_mg + 1) * sizeof(real_T));
    }

    obj->grad[obj->nvar - 1] = obj->gammaScalar;
    break;

   case 3:
    full_loop_xgemv_p43ri(obj->nvar, obj->nvar, H, obj->nvar, x, obj->Hx);
    full_loop_B.b_mg = obj->nvar - 1;
    if (0 <= full_loop_B.b_mg) {
      memcpy(&obj->grad[0], &obj->Hx[0], (full_loop_B.b_mg + 1) * sizeof(real_T));
    }

    if (obj->hasLinear && (obj->nvar >= 1)) {
      full_loop_B.ixlast = obj->nvar;
      for (full_loop_B.b_mg = 0; full_loop_B.b_mg < full_loop_B.ixlast;
           full_loop_B.b_mg++) {
        obj->grad[full_loop_B.b_mg] += f[full_loop_B.b_mg];
      }
    }
    break;

   case 4:
    full_loop_B.ixlast = obj->maxVar - 2;
    full_loop_xgemv_p43ri(obj->nvar, obj->nvar, H, obj->nvar, x, obj->Hx);
    iy = obj->nvar;
    for (full_loop_B.b_mg = iy + 1; full_loop_B.b_mg <= full_loop_B.ixlast + 1;
         full_loop_B.b_mg++) {
      obj->Hx[full_loop_B.b_mg - 1] = x[full_loop_B.b_mg - 1] * obj->beta;
    }

    if (0 <= full_loop_B.ixlast) {
      memcpy(&obj->grad[0], &obj->Hx[0], (full_loop_B.ixlast + 1) * sizeof
             (real_T));
    }

    if (obj->hasLinear && (obj->nvar >= 1)) {
      full_loop_B.ixlast = obj->nvar;
      for (full_loop_B.b_mg = 0; full_loop_B.b_mg < full_loop_B.ixlast;
           full_loop_B.b_mg++) {
        obj->grad[full_loop_B.b_mg] += f[full_loop_B.b_mg];
      }
    }

    full_loop_B.ixlast = (obj->maxVar - obj->nvar) - 2;
    if (full_loop_B.ixlast + 1 >= 1) {
      iy = obj->nvar;
      for (full_loop_B.b_mg = 0; full_loop_B.b_mg <= full_loop_B.ixlast;
           full_loop_B.b_mg++) {
        obj->grad[iy] += obj->rho;
        iy++;
      }
    }
    break;
  }
}

static void full_loop_computeFval_ReuseHx_p(const
  sJdVcLKPgejLYHLePKb6F6D_full__T *obj, const real_T workspace[441], const
  real_T f[21], const real_T x[21], real_T *val, real_T b_workspace[441])
{
  int32_T e;
  int32_T ixlast;
  int32_T b_k;
  memcpy(&b_workspace[0], &workspace[0], 441U * sizeof(real_T));
  *val = 0.0;
  switch (obj->objtype) {
   case 5:
    *val = x[obj->nvar - 1] * obj->gammaScalar;
    break;

   case 3:
    if (obj->hasLinear) {
      ixlast = obj->nvar - 1;
      for (b_k = 0; b_k <= ixlast; b_k++) {
        b_workspace[b_k] = 0.5 * obj->Hx[b_k] + f[b_k];
      }

      if (obj->nvar >= 1) {
        for (b_k = 0; b_k <= ixlast; b_k++) {
          *val += x[b_k] * b_workspace[b_k];
        }
      }
    } else {
      if (obj->nvar >= 1) {
        ixlast = obj->nvar - 1;
        for (b_k = 0; b_k <= ixlast; b_k++) {
          *val += x[b_k] * obj->Hx[b_k];
        }
      }

      *val *= 0.5;
    }
    break;

   case 4:
    ixlast = obj->maxVar - 2;
    if (obj->hasLinear) {
      b_k = obj->nvar - 1;
      if (0 <= b_k) {
        memcpy(&b_workspace[0], &f[0], (b_k + 1) * sizeof(real_T));
      }

      e = (obj->maxVar - obj->nvar) - 2;
      for (b_k = 0; b_k <= e; b_k++) {
        b_workspace[obj->nvar + b_k] = obj->rho;
      }

      for (b_k = 0; b_k <= ixlast; b_k++) {
        b_workspace[b_k] += 0.5 * obj->Hx[b_k];
      }

      if (obj->maxVar - 1 >= 1) {
        for (b_k = 0; b_k <= ixlast; b_k++) {
          *val += x[b_k] * b_workspace[b_k];
        }
      }
    } else {
      if (obj->maxVar - 1 >= 1) {
        for (b_k = 0; b_k <= ixlast; b_k++) {
          *val += x[b_k] * obj->Hx[b_k];
        }
      }

      *val *= 0.5;
      e = obj->nvar;
      for (b_k = e + 1; b_k <= ixlast + 1; b_k++) {
        *val += x[b_k - 1] * obj->rho;
      }
    }
    break;
  }
}

static void full_loop_xrotg(real_T a, real_T b, real_T *b_a, real_T *b_b, real_T
  *c, real_T *s)
{
  full_loop_B.roe = b;
  full_loop_B.absa = fabs(a);
  full_loop_B.absb = fabs(b);
  if (full_loop_B.absa > full_loop_B.absb) {
    full_loop_B.roe = a;
  }

  full_loop_B.scale_o = full_loop_B.absa + full_loop_B.absb;
  if (full_loop_B.scale_o == 0.0) {
    *s = 0.0;
    *c = 1.0;
    *b_a = 0.0;
    *b_b = 0.0;
  } else {
    full_loop_B.ads = full_loop_B.absa / full_loop_B.scale_o;
    full_loop_B.bds = full_loop_B.absb / full_loop_B.scale_o;
    *b_a = sqrt(full_loop_B.ads * full_loop_B.ads + full_loop_B.bds *
                full_loop_B.bds) * full_loop_B.scale_o;
    if (full_loop_B.roe < 0.0) {
      *b_a = -*b_a;
    }

    *c = a / *b_a;
    *s = b / *b_a;
    if (full_loop_B.absa > full_loop_B.absb) {
      *b_b = *s;
    } else if (*c != 0.0) {
      *b_b = 1.0 / *c;
    } else {
      *b_b = 1.0;
    }
  }
}

static void full_loop_squareQ_appendCol_p(snaQeDJ4fX7UykrKyr5M8jC_full__T *obj,
  const real_T vec[399], int32_T iv0)
{
  int32_T iQR0;
  int32_T Qk0;
  int32_T iyend;
  int32_T ix;
  int32_T b;
  int32_T d;
  iQR0 = obj->ncols + 1;
  if (obj->mrows < iQR0) {
    obj->minRowCol = obj->mrows;
  } else {
    obj->minRowCol = iQR0;
  }

  iQR0 = 21 * obj->ncols;
  if ((obj->mrows == 0) || (obj->mrows == 0)) {
  } else {
    iyend = iQR0 + obj->mrows;
    if (iQR0 + 1 <= iyend) {
      memset(&obj->QR[iQR0], 0, (iyend - iQR0) * sizeof(real_T));
    }

    b = (obj->mrows - 1) * 21;
    for (iyend = 1; iyend <= b + 1; iyend += 21) {
      ix = iv0 - 1;
      full_loop_B.c_ieu = 0.0;
      d = iyend + obj->mrows;
      for (Qk0 = iyend; Qk0 < d; Qk0++) {
        full_loop_B.c_ieu += obj->Q[Qk0 - 1] * vec[ix];
        ix++;
      }

      obj->QR[iQR0] += full_loop_B.c_ieu;
      iQR0++;
    }
  }

  obj->ncols++;
  obj->jpvt[obj->ncols - 1] = obj->ncols;
  for (iyend = obj->mrows - 2; iyend + 2 > obj->ncols; iyend--) {
    full_loop_xrotg(obj->QR[iyend + 21 * (obj->ncols - 1)], obj->QR[(iyend + 21 *
      (obj->ncols - 1)) + 1], &obj->QR[iyend + 21 * (obj->ncols - 1)],
                    &full_loop_B.c_ieu, &full_loop_B.b_c, &full_loop_B.s_k);
    obj->QR[(iyend + 21 * (obj->ncols - 1)) + 1] = full_loop_B.c_ieu;
    Qk0 = 21 * iyend;
    b = obj->mrows - 1;
    memcpy(&full_loop_B.c_x[0], &obj->Q[0], 441U * sizeof(real_T));
    if (obj->mrows >= 1) {
      ix = Qk0 + 21;
      for (iQR0 = 0; iQR0 <= b; iQR0++) {
        full_loop_B.c_ieu = full_loop_B.b_c * full_loop_B.c_x[Qk0] +
          full_loop_B.s_k * full_loop_B.c_x[ix];
        full_loop_B.c_x[ix] = full_loop_B.b_c * full_loop_B.c_x[ix] -
          full_loop_B.s_k * full_loop_B.c_x[Qk0];
        full_loop_B.c_x[Qk0] = full_loop_B.c_ieu;
        ix++;
        Qk0++;
      }
    }

    memcpy(&obj->Q[0], &full_loop_B.c_x[0], 441U * sizeof(real_T));
  }
}

static void full_loop_xrot_p(int32_T n, const real_T x[441], int32_T ix0,
  int32_T iy0, real_T c, real_T s, real_T b_x[441])
{
  int32_T ix;
  int32_T iy;
  int32_T k;
  memcpy(&b_x[0], &x[0], 441U * sizeof(real_T));
  if (n >= 1) {
    ix = ix0 - 1;
    iy = iy0 - 1;
    for (k = 0; k < n; k++) {
      full_loop_B.temp_j = c * b_x[ix] + s * b_x[iy];
      b_x[iy] = c * b_x[iy] - s * b_x[ix];
      b_x[ix] = full_loop_B.temp_j;
      iy += 21;
      ix += 21;
    }
  }
}

static void full_loop_xrot(int32_T n, const real_T x[441], int32_T ix0, int32_T
  iy0, real_T c, real_T s, real_T b_x[441])
{
  int32_T ix;
  int32_T iy;
  int32_T k;
  memcpy(&b_x[0], &x[0], 441U * sizeof(real_T));
  if (n >= 1) {
    ix = ix0 - 1;
    iy = iy0 - 1;
    for (k = 0; k < n; k++) {
      full_loop_B.temp_l = c * b_x[ix] + s * b_x[iy];
      b_x[iy] = c * b_x[iy] - s * b_x[ix];
      b_x[ix] = full_loop_B.temp_l;
      iy++;
      ix++;
    }
  }
}

static void full_loop_deleteColMoveEnd_p(snaQeDJ4fX7UykrKyr5M8jC_full__T *obj,
  int32_T idx)
{
  int32_T QRk0;
  int32_T c_k;
  int32_T ix;
  int32_T iy;
  if (obj->usedPivoting) {
    full_loop_B.i_i = 1;
    while ((full_loop_B.i_i <= obj->ncols) && (obj->jpvt[full_loop_B.i_i - 1] !=
            idx)) {
      full_loop_B.i_i++;
    }

    idx = full_loop_B.i_i;
  }

  if (idx >= obj->ncols) {
    obj->ncols--;
  } else {
    obj->jpvt[idx - 1] = obj->jpvt[obj->ncols - 1];
    full_loop_B.endIdx = obj->minRowCol - 1;
    for (full_loop_B.i_i = 0; full_loop_B.i_i <= full_loop_B.endIdx;
         full_loop_B.i_i++) {
      obj->QR[full_loop_B.i_i + 21 * (idx - 1)] = obj->QR[(obj->ncols - 1) * 21
        + full_loop_B.i_i];
    }

    obj->ncols--;
    if (obj->mrows < obj->ncols) {
      obj->minRowCol = obj->mrows;
    } else {
      obj->minRowCol = obj->ncols;
    }

    if (idx < obj->mrows) {
      full_loop_B.endIdx = obj->mrows - 1;
      if (full_loop_B.endIdx >= obj->ncols) {
        full_loop_B.endIdx = obj->ncols;
      }

      full_loop_B.i_i = full_loop_B.endIdx;
      while (full_loop_B.i_i >= idx) {
        full_loop_xrotg(obj->QR[(full_loop_B.i_i + 21 * (idx - 1)) - 1], obj->
                        QR[full_loop_B.i_i + 21 * (idx - 1)], &obj->QR
                        [(full_loop_B.i_i + 21 * (idx - 1)) - 1],
                        &full_loop_B.c_c, &full_loop_B.b_s, &full_loop_B.temp_o);
        obj->QR[full_loop_B.i_i + 21 * (idx - 1)] = full_loop_B.c_c;
        c_k = 21 * (full_loop_B.i_i - 1);
        obj->QR[full_loop_B.i_i + c_k] = 0.0;
        QRk0 = 21 * idx + full_loop_B.i_i;
        memcpy(&full_loop_B.obj_e[0], &obj->QR[0], 441U * sizeof(real_T));
        full_loop_xrot_p(obj->ncols - idx, full_loop_B.obj_e, QRk0, QRk0 + 1,
                         full_loop_B.b_s, full_loop_B.temp_o, obj->QR);
        memcpy(&full_loop_B.obj_e[0], &obj->Q[0], 441U * sizeof(real_T));
        full_loop_xrot(obj->mrows, full_loop_B.obj_e, c_k + 1, c_k + 22,
                       full_loop_B.b_s, full_loop_B.temp_o, obj->Q);
        full_loop_B.i_i--;
      }

      for (c_k = idx + 1; c_k <= full_loop_B.endIdx; c_k++) {
        full_loop_xrotg(obj->QR[(c_k + 21 * (c_k - 1)) - 1], obj->QR[c_k + 21 *
                        (c_k - 1)], &obj->QR[(c_k + 21 * (c_k - 1)) - 1],
                        &full_loop_B.temp_o, &full_loop_B.c_c, &full_loop_B.b_s);
        ix = 21 * (c_k - 1);
        obj->QR[c_k + ix] = full_loop_B.temp_o;
        QRk0 = c_k * 22;
        memcpy(&full_loop_B.obj_e[0], &obj->QR[0], 441U * sizeof(real_T));
        full_loop_xrot_p(obj->ncols - c_k, full_loop_B.obj_e, QRk0, QRk0 + 1,
                         full_loop_B.c_c, full_loop_B.b_s, obj->QR);
        QRk0 = obj->mrows - 1;
        memcpy(&full_loop_B.obj_e[0], &obj->Q[0], 441U * sizeof(real_T));
        if (obj->mrows >= 1) {
          iy = ix + 21;
          for (full_loop_B.i_i = 0; full_loop_B.i_i <= QRk0; full_loop_B.i_i++)
          {
            full_loop_B.temp_o = full_loop_B.c_c * full_loop_B.obj_e[ix] +
              full_loop_B.b_s * full_loop_B.obj_e[iy];
            full_loop_B.obj_e[iy] = full_loop_B.c_c * full_loop_B.obj_e[iy] -
              full_loop_B.b_s * full_loop_B.obj_e[ix];
            full_loop_B.obj_e[ix] = full_loop_B.temp_o;
            iy++;
            ix++;
          }
        }

        memcpy(&obj->Q[0], &full_loop_B.obj_e[0], 441U * sizeof(real_T));
      }
    }
  }
}

static void full_loop_xgemm_p4(int32_T m, int32_T n, int32_T k, const real_T A
  [64], int32_T lda, const real_T B[441], int32_T ib0, const real_T C[441],
  real_T b_C[441])
{
  int32_T ar;
  int32_T ia;
  int32_T c;
  int32_T e;
  int32_T ib;
  int32_T g;
  int32_T b_ic;
  memcpy(&b_C[0], &C[0], 441U * sizeof(real_T));
  if ((m == 0) || (n == 0)) {
  } else {
    full_loop_B.lastColC_h = (n - 1) * 21;
    for (full_loop_B.br = 0; full_loop_B.br <= full_loop_B.lastColC_h;
         full_loop_B.br += 21) {
      c = full_loop_B.br + m;
      for (ar = full_loop_B.br + 1; ar <= c; ar++) {
        b_C[ar - 1] = 0.0;
      }
    }

    full_loop_B.br = ib0;
    for (c = 0; c <= full_loop_B.lastColC_h; c += 21) {
      ar = 0;
      e = (full_loop_B.br + k) - 1;
      for (ib = full_loop_B.br; ib <= e; ib++) {
        ia = ar - 1;
        g = c + m;
        for (b_ic = c + 1; b_ic <= g; b_ic++) {
          ia++;
          b_C[b_ic - 1] += B[ib - 1] * A[ia];
        }

        ar += lda;
      }

      full_loop_B.br += 21;
    }
  }
}

static void full_loop_xgemm_p43(int32_T m, int32_T n, int32_T k, const real_T A
  [441], int32_T ia0, const real_T B[441], const real_T C[441], real_T b_C[441])
{
  int32_T w;
  int32_T br;
  int32_T ar;
  int32_T c;
  int32_T e;
  int32_T b_ic;
  int32_T b_w;
  memcpy(&b_C[0], &C[0], 441U * sizeof(real_T));
  if ((m == 0) || (n == 0)) {
  } else {
    full_loop_B.lastColC = (n - 1) * 21;
    for (br = 0; br <= full_loop_B.lastColC; br += 21) {
      c = br + m;
      for (ar = br + 1; ar <= c; ar++) {
        b_C[ar - 1] = 0.0;
      }
    }

    br = -1;
    for (c = 0; c <= full_loop_B.lastColC; c += 21) {
      ar = ia0 - 2;
      e = c + m;
      for (b_ic = c + 1; b_ic <= e; b_ic++) {
        full_loop_B.temp_m = 0.0;
        for (b_w = 0; b_w < k; b_w++) {
          w = b_w + 1;
          full_loop_B.temp_m += A[w + ar] * B[w + br];
        }

        b_C[b_ic - 1] += full_loop_B.temp_m;
        ar += 21;
      }

      br += 21;
    }
  }
}

static void computeProjectedHessian_regul_p(real_T beta, const real_T H[64],
  int32_T nVarOrig, snl99C5je2zMbU5SzygoX6F_full__T *cholmanager, const
  snaQeDJ4fX7UykrKyr5M8jC_full__T *qrmanager, sVTYnQ9ljvmk9dLse9XvTT_full_l_T
  *memspace)
{
  full_loop_B.nVars = qrmanager->mrows;
  full_loop_B.mNull_j = qrmanager->mrows - qrmanager->ncols;
  full_loop_B.nullStart = 21 * qrmanager->ncols + 1;
  memcpy(&full_loop_B.memspace_bj[0], &memspace->workspace_double[0], 441U *
         sizeof(real_T));
  full_loop_xgemm_p4(nVarOrig, full_loop_B.mNull_j, nVarOrig, H, nVarOrig,
                     qrmanager->Q, full_loop_B.nullStart,
                     full_loop_B.memspace_bj, memspace->workspace_double);
  for (full_loop_B.b_idx_col = 0; full_loop_B.b_idx_col < full_loop_B.mNull_j;
       full_loop_B.b_idx_col++) {
    for (full_loop_B.idx_row = nVarOrig + 1; full_loop_B.idx_row <=
         full_loop_B.nVars; full_loop_B.idx_row++) {
      memspace->workspace_double[(full_loop_B.idx_row + 21 *
        full_loop_B.b_idx_col) - 1] = qrmanager->Q[((full_loop_B.b_idx_col +
        qrmanager->ncols) * 21 + full_loop_B.idx_row) - 1] * beta;
    }
  }

  memcpy(&full_loop_B.memspace_bj[0], &cholmanager->FMat[0], 441U * sizeof
         (real_T));
  full_loop_xgemm_p43(full_loop_B.mNull_j, full_loop_B.mNull_j, qrmanager->mrows,
                      qrmanager->Q, full_loop_B.nullStart,
                      memspace->workspace_double, full_loop_B.memspace_bj,
                      cholmanager->FMat);
}

static void full__computeProjectedHessian_p(const real_T H[64],
  snl99C5je2zMbU5SzygoX6F_full__T *cholmanager, const
  snaQeDJ4fX7UykrKyr5M8jC_full__T *qrmanager, sVTYnQ9ljvmk9dLse9XvTT_full_l_T
  *memspace)
{
  full_loop_B.mNull_f = qrmanager->mrows - qrmanager->ncols;
  full_loop_B.nullStart_j = 21 * qrmanager->ncols + 1;
  memcpy(&full_loop_B.memspace_jz[0], &memspace->workspace_double[0], 441U *
         sizeof(real_T));
  full_loop_xgemm_p4(qrmanager->mrows, full_loop_B.mNull_f, qrmanager->mrows, H,
                     qrmanager->mrows, qrmanager->Q, full_loop_B.nullStart_j,
                     full_loop_B.memspace_jz, memspace->workspace_double);
  memcpy(&full_loop_B.memspace_jz[0], &cholmanager->FMat[0], 441U * sizeof
         (real_T));
  full_loop_xgemm_p43(full_loop_B.mNull_f, full_loop_B.mNull_f, qrmanager->mrows,
                      qrmanager->Q, full_loop_B.nullStart_j,
                      memspace->workspace_double, full_loop_B.memspace_jz,
                      cholmanager->FMat);
}

static void full_loop_xpotrf(int32_T n, const real_T A[441], real_T b_A[441],
  int32_T *info)
{
  int32_T nmj;
  int32_T b_j;
  int32_T iac;
  int32_T d;
  int32_T ia;
  int32_T ix;
  int32_T iy;
  boolean_T exitg1;
  memcpy(&b_A[0], &A[0], 441U * sizeof(real_T));
  *info = 0;
  b_j = 1;
  exitg1 = false;
  while ((!exitg1) && (b_j - 1 <= n - 1)) {
    full_loop_B.j_i = b_j - 1;
    full_loop_B.jm1 = full_loop_B.j_i - 1;
    full_loop_B.idxA1j = full_loop_B.j_i * 21 + 1;
    full_loop_B.idxAjj = (full_loop_B.idxA1j + full_loop_B.j_i) - 1;
    full_loop_B.ssq = 0.0;
    if (full_loop_B.j_i >= 1) {
      ix = full_loop_B.idxA1j - 1;
      iy = full_loop_B.idxA1j - 1;
      for (nmj = 0; nmj <= full_loop_B.jm1; nmj++) {
        full_loop_B.ssq += b_A[ix] * b_A[iy];
        ix++;
        iy++;
      }
    }

    full_loop_B.ssq = b_A[full_loop_B.idxAjj] - full_loop_B.ssq;
    if (full_loop_B.ssq > 0.0) {
      full_loop_B.ssq = sqrt(full_loop_B.ssq);
      b_A[full_loop_B.idxAjj] = full_loop_B.ssq;
      if (full_loop_B.j_i + 1 < n) {
        nmj = (n - full_loop_B.j_i) - 2;
        if ((full_loop_B.j_i == 0) || (nmj + 1 == 0)) {
        } else {
          iy = full_loop_B.idxAjj + 21;
          full_loop_B.jm1 = 21 * nmj + full_loop_B.idxA1j;
          for (iac = full_loop_B.idxA1j + 21; iac <= full_loop_B.jm1 + 21; iac +=
               21) {
            ix = full_loop_B.idxA1j - 1;
            full_loop_B.c_p = 0.0;
            d = iac + full_loop_B.j_i;
            for (ia = iac; ia < d; ia++) {
              full_loop_B.c_p += b_A[ia - 1] * b_A[ix];
              ix++;
            }

            b_A[iy] += -full_loop_B.c_p;
            iy += 21;
          }
        }

        full_loop_B.ssq = 1.0 / full_loop_B.ssq;
        full_loop_B.jm1 = 21 * nmj + full_loop_B.idxAjj;
        for (nmj = full_loop_B.idxAjj + 22; nmj <= full_loop_B.jm1 + 22; nmj +=
             21) {
          b_A[nmj - 1] *= full_loop_B.ssq;
        }
      }

      b_j++;
    } else {
      b_A[full_loop_B.idxAjj] = full_loop_B.ssq;
      *info = full_loop_B.j_i + 1;
      exitg1 = true;
    }
  }
}

static void full_loop_factor_p(const real_T obj_FMat[441], int32_T ndims, real_T
  b_obj_FMat[441], int32_T *b_obj_ndims, int32_T *b_obj_info)
{
  *b_obj_ndims = ndims;
  full_loop_xpotrf(ndims, obj_FMat, b_obj_FMat, b_obj_info);
}

static void full_loop_xgemv_p43r(int32_T m, int32_T n, const real_T A[441],
  int32_T ia0, const real_T x[21], const real_T y[441], real_T b_y[441])
{
  int32_T ix;
  int32_T iy;
  int32_T b;
  int32_T iac;
  int32_T d;
  int32_T ia;
  memcpy(&b_y[0], &y[0], 441U * sizeof(real_T));
  if (m != 0) {
    if (0 <= n - 1) {
      memset(&b_y[0], 0, n * sizeof(real_T));
    }

    iy = 0;
    b = (n - 1) * 21 + ia0;
    for (iac = ia0; iac <= b; iac += 21) {
      ix = 0;
      full_loop_B.c_dd = 0.0;
      d = iac + m;
      for (ia = iac; ia < d; ia++) {
        full_loop_B.c_dd += A[ia - 1] * x[ix];
        ix++;
      }

      b_y[iy] += -full_loop_B.c_dd;
      iy++;
    }
  }
}

static void full_loop_solve_p(const real_T obj_FMat[441], int32_T obj_ndims,
  int32_T obj_info, const real_T rhs[441], real_T b_rhs[441], real_T b_obj_FMat
  [441], int32_T *b_obj_ndims, int32_T *b_obj_info)
{
  int32_T b_j;
  int32_T b;
  int32_T b_i;
  int32_T jjA;
  int32_T i;
  int32_T ix;
  *b_obj_ndims = obj_ndims;
  *b_obj_info = obj_info;
  memcpy(&b_obj_FMat[0], &obj_FMat[0], 441U * sizeof(real_T));
  memcpy(&b_rhs[0], &rhs[0], 441U * sizeof(real_T));
  for (b_j = 0; b_j < obj_ndims; b_j++) {
    jjA = b_j * 21 - 1;
    full_loop_B.temp_e = b_rhs[b_j];
    b = b_j - 1;
    for (b_i = 0; b_i <= b; b_i++) {
      full_loop_B.temp_e -= obj_FMat[(jjA + b_i) + 1] * b_rhs[b_i];
    }

    b_rhs[b_j] = full_loop_B.temp_e / obj_FMat[b_j * 21 + b_j];
  }

  if (obj_ndims != 0) {
    for (b_j = obj_ndims; b_j >= 1; b_j--) {
      jjA = ((b_j - 1) * 21 + b_j) - 1;
      b_rhs[b_j - 1] /= obj_FMat[jjA];
      b = b_j - 2;
      for (b_i = 0; b_i <= b; b_i++) {
        i = b_i + 1;
        ix = (b_j - i) - 1;
        b_rhs[ix] -= b_rhs[b_j - 1] * obj_FMat[jjA - i];
      }
    }
  }
}

static void full_loop_xgemv_p43rio(int32_T m, int32_T n, const real_T A[441],
  int32_T ia0, const real_T x[441], real_T y[21])
{
  int32_T iy;
  int32_T ix;
  int32_T b;
  int32_T iac;
  int32_T d;
  int32_T ia;
  if (m != 0) {
    if (0 <= m - 1) {
      memset(&y[0], 0, m * sizeof(real_T));
    }

    ix = 0;
    b = (n - 1) * 21 + ia0;
    for (iac = ia0; iac <= b; iac += 21) {
      iy = 0;
      d = iac + m;
      for (ia = iac; ia < d; ia++) {
        y[iy] += A[ia - 1] * x[ix];
        iy++;
      }

      ix++;
    }
  }
}

static void full_loop_factor(const real_T obj_FMat[441], const real_T A[64],
  int32_T ndims, int32_T ldA, real_T b_obj_FMat[441], int32_T *b_obj_ndims,
  int32_T *b_obj_info)
{
  memcpy(&b_obj_FMat[0], &obj_FMat[0], 441U * sizeof(real_T));
  *b_obj_ndims = ndims;
  for (full_loop_B.b_idx_b = 0; full_loop_B.b_idx_b < ndims; full_loop_B.b_idx_b
       ++) {
    full_loop_B.iA0 = ldA * full_loop_B.b_idx_b - 1;
    full_loop_B.iUU0 = 21 * full_loop_B.b_idx_b - 1;
    for (full_loop_B.b_k_a = 0; full_loop_B.b_k_a < ndims; full_loop_B.b_k_a++)
    {
      full_loop_B.k = full_loop_B.b_k_a + 1;
      b_obj_FMat[full_loop_B.iUU0 + full_loop_B.k] = A[full_loop_B.iA0 +
        full_loop_B.k];
    }
  }

  memcpy(&full_loop_B.b_obj_FMat[0], &b_obj_FMat[0], 441U * sizeof(real_T));
  full_loop_xpotrf(ndims, full_loop_B.b_obj_FMat, b_obj_FMat, b_obj_info);
}

static void full_loop_solve_p4(const real_T obj_FMat[441], int32_T obj_ndims,
  int32_T obj_info, real_T rhs[21], real_T b_obj_FMat[441], int32_T *b_obj_ndims,
  int32_T *b_obj_info)
{
  int32_T b_j;
  int32_T b;
  int32_T b_i;
  int32_T jjA;
  int32_T i;
  int32_T ix;
  memcpy(&b_obj_FMat[0], &obj_FMat[0], 441U * sizeof(real_T));
  *b_obj_ndims = obj_ndims;
  *b_obj_info = obj_info;
  if (obj_ndims != 0) {
    for (b_j = 0; b_j < obj_ndims; b_j++) {
      jjA = b_j * 21 - 1;
      full_loop_B.temp_b = rhs[b_j];
      b = b_j - 1;
      for (b_i = 0; b_i <= b; b_i++) {
        full_loop_B.temp_b -= obj_FMat[(jjA + b_i) + 1] * rhs[b_i];
      }

      rhs[b_j] = full_loop_B.temp_b / obj_FMat[b_j * 21 + b_j];
    }

    for (b_j = obj_ndims; b_j >= 1; b_j--) {
      jjA = ((b_j - 1) * 21 + b_j) - 1;
      rhs[b_j - 1] /= obj_FMat[jjA];
      b = b_j - 2;
      for (b_i = 0; b_i <= b; b_i++) {
        i = b_i + 1;
        ix = (b_j - i) - 1;
        rhs[ix] -= rhs[b_j - 1] * obj_FMat[jjA - i];
      }
    }
  }
}

static void full_loop_compute_deltax_p(const real_T H[64],
  s2CPTVnVyv153Hb6bxlki6F_full__T *solution, sVTYnQ9ljvmk9dLse9XvTT_full_l_T
  *memspace, const snaQeDJ4fX7UykrKyr5M8jC_full__T *qrmanager,
  snl99C5je2zMbU5SzygoX6F_full__T *cholmanager, const
  sJdVcLKPgejLYHLePKb6F6D_full__T *objective, snaQeDJ4fX7UykrKyr5M8jC_full__T
  *b_qrmanager)
{
  *b_qrmanager = *qrmanager;
  full_loop_B.nVar_e = qrmanager->mrows - 1;
  full_loop_B.mNull = qrmanager->mrows - qrmanager->ncols;
  if (full_loop_B.mNull <= 0) {
    if (0 <= full_loop_B.nVar_e) {
      memset(&solution->searchDir[0], 0, (full_loop_B.nVar_e + 1) * sizeof
             (real_T));
    }
  } else {
    for (full_loop_B.c_idx = 0; full_loop_B.c_idx <= full_loop_B.nVar_e;
         full_loop_B.c_idx++) {
      solution->searchDir[full_loop_B.c_idx] = -objective->
        grad[full_loop_B.c_idx];
    }

    if (qrmanager->ncols <= 0) {
      switch (objective->objtype) {
       case 5:
        break;

       case 3:
        memcpy(&full_loop_B.cholmanager_h[0], &cholmanager->FMat[0], 441U *
               sizeof(real_T));
        full_loop_factor(full_loop_B.cholmanager_h, H, qrmanager->mrows,
                         qrmanager->mrows, cholmanager->FMat,
                         &cholmanager->ndims, &cholmanager->info);
        if (cholmanager->info != 0) {
          solution->state = -6;
        } else {
          memcpy(&full_loop_B.cholmanager_h[0], &cholmanager->FMat[0], 441U *
                 sizeof(real_T));
          full_loop_solve_p4(full_loop_B.cholmanager_h, cholmanager->ndims,
                             cholmanager->info, solution->searchDir,
                             cholmanager->FMat, &cholmanager->ndims,
                             &cholmanager->info);
        }
        break;

       case 4:
        memcpy(&full_loop_B.cholmanager_h[0], &cholmanager->FMat[0], 441U *
               sizeof(real_T));
        full_loop_factor(full_loop_B.cholmanager_h, H, objective->nvar,
                         objective->nvar, cholmanager->FMat, &cholmanager->ndims,
                         &cholmanager->info);
        if (cholmanager->info != 0) {
          solution->state = -6;
        } else {
          memcpy(&full_loop_B.cholmanager_h[0], &cholmanager->FMat[0], 441U *
                 sizeof(real_T));
          full_loop_solve_p4(full_loop_B.cholmanager_h, cholmanager->ndims,
                             cholmanager->info, solution->searchDir,
                             cholmanager->FMat, &cholmanager->ndims,
                             &cholmanager->info);
          full_loop_B.a = 1.0 / objective->beta;
          full_loop_B.nVar_e = objective->nvar;
          full_loop_B.mNull = qrmanager->mrows;
          for (full_loop_B.c_idx = full_loop_B.nVar_e + 1; full_loop_B.c_idx <=
               full_loop_B.mNull; full_loop_B.c_idx++) {
            solution->searchDir[full_loop_B.c_idx - 1] *= full_loop_B.a;
          }
        }
        break;
      }
    } else {
      full_loop_B.nullStartIdx = 21 * qrmanager->ncols + 1;
      if (objective->objtype == 5) {
        for (full_loop_B.c_idx = 0; full_loop_B.c_idx < full_loop_B.mNull;
             full_loop_B.c_idx++) {
          memspace->workspace_double[full_loop_B.c_idx] = -qrmanager->Q
            [(qrmanager->ncols + full_loop_B.c_idx) * 21 + full_loop_B.nVar_e];
        }

        full_loop_xgemv_p43rio(qrmanager->mrows, full_loop_B.mNull, qrmanager->Q,
          full_loop_B.nullStartIdx, memspace->workspace_double,
          solution->searchDir);
      } else {
        if (objective->objtype == 3) {
          full__computeProjectedHessian_p(H, cholmanager, qrmanager, memspace);
        } else {
          computeProjectedHessian_regul_p(objective->beta, H, objective->nvar,
            cholmanager, qrmanager, memspace);
        }

        memcpy(&full_loop_B.cholmanager_h[0], &cholmanager->FMat[0], 441U *
               sizeof(real_T));
        full_loop_factor_p(full_loop_B.cholmanager_h, full_loop_B.mNull,
                           cholmanager->FMat, &cholmanager->ndims,
                           &cholmanager->info);
        if (cholmanager->info != 0) {
          solution->state = -6;
        } else {
          memcpy(&full_loop_B.cholmanager_h[0], &memspace->workspace_double[0],
                 441U * sizeof(real_T));
          full_loop_xgemv_p43r(qrmanager->mrows, full_loop_B.mNull, qrmanager->Q,
                               full_loop_B.nullStartIdx, objective->grad,
                               full_loop_B.cholmanager_h,
                               memspace->workspace_double);
          memcpy(&full_loop_B.cholmanager_h[0], &cholmanager->FMat[0], 441U *
                 sizeof(real_T));
          full_loop_solve_p(full_loop_B.cholmanager_h, cholmanager->ndims,
                            cholmanager->info, memspace->workspace_double,
                            full_loop_B.d, cholmanager->FMat,
                            &cholmanager->ndims, &cholmanager->info);
          memcpy(&memspace->workspace_double[0], &full_loop_B.d[0], 441U *
                 sizeof(real_T));
          full_loop_xgemv_p43rio(qrmanager->mrows, full_loop_B.mNull,
            qrmanager->Q, full_loop_B.nullStartIdx, full_loop_B.d,
            solution->searchDir);
        }
      }
    }
  }
}

static real_T full_loop_xnrm2_p4(int32_T n, const real_T x[21])
{
  real_T y;
  real_T absxk;
  real_T t;
  int32_T b_k;
  y = 0.0;
  if (n >= 1) {
    if (n == 1) {
      y = fabs(x[0]);
    } else {
      full_loop_B.scale_c = 3.3121686421112381E-170;
      for (b_k = 0; b_k < n; b_k++) {
        absxk = fabs(x[b_k]);
        if (absxk > full_loop_B.scale_c) {
          t = full_loop_B.scale_c / absxk;
          y = y * t * t + 1.0;
          full_loop_B.scale_c = absxk;
        } else {
          t = absxk / full_loop_B.scale_c;
          y += t * t;
        }
      }

      y = full_loop_B.scale_c * sqrt(y);
    }
  }

  return y;
}

static void full_loop_feasibleratiotest(const real_T solution_xstar[21], const
  real_T solution_searchDir[21], const real_T workspace[441], int32_T
  workingset_nVar, const real_T workingset_lb[21], const int32_T
  workingset_indexLB[21], const int32_T workingset_sizes[5], const int32_T
  workingset_isActiveIdx[6], const boolean_T workingset_isActiveConstr[19],
  const int32_T workingset_nWConstr[5], boolean_T isPhaseOne, real_T *alpha,
  boolean_T *newBlocking, int32_T *constrType, int32_T *constrIdx, real_T
  b_workspace[441])
{
  int32_T b;
  int32_T b_idx;
  memcpy(&b_workspace[0], &workspace[0], 441U * sizeof(real_T));
  *alpha = 1.0E+30;
  *newBlocking = false;
  *constrType = 0;
  *constrIdx = 0;
  full_loop_B.denomTol = 2.2204460492503131E-13 * full_loop_xnrm2_p4
    (workingset_nVar, solution_searchDir);
  if (workingset_nWConstr[3] < workingset_sizes[3]) {
    full_loop_B.phaseOneCorrectionX = solution_xstar[workingset_nVar - 1] *
      static_cast<real_T>(isPhaseOne);
    full_loop_B.phaseOneCorrectionP = solution_searchDir[workingset_nVar - 1] *
      static_cast<real_T>(isPhaseOne);
    b = workingset_sizes[3] - 2;
    for (b_idx = 0; b_idx <= b; b_idx++) {
      full_loop_B.pk_corrected = -solution_searchDir[workingset_indexLB[b_idx] -
        1] - full_loop_B.phaseOneCorrectionP;
      if ((full_loop_B.pk_corrected > full_loop_B.denomTol) &&
          (!workingset_isActiveConstr[(workingset_isActiveIdx[3] + b_idx) - 1]))
      {
        full_loop_B.ratio = (-solution_xstar[workingset_indexLB[b_idx] - 1] -
                             workingset_lb[workingset_indexLB[b_idx] - 1]) -
          full_loop_B.phaseOneCorrectionX;
        full_loop_B.u0 = fabs(full_loop_B.ratio);
        if ((!(full_loop_B.u0 < 0.01 - full_loop_B.ratio)) && (!rtIsNaN(0.01 -
              full_loop_B.ratio))) {
          full_loop_B.u0 = 0.01 - full_loop_B.ratio;
        }

        full_loop_B.pk_corrected = full_loop_B.u0 / full_loop_B.pk_corrected;
        if (full_loop_B.pk_corrected < *alpha) {
          *alpha = full_loop_B.pk_corrected;
          *constrType = 4;
          *constrIdx = b_idx + 1;
          *newBlocking = true;
        }
      }
    }

    b = workingset_indexLB[workingset_sizes[3] - 1] - 1;
    if ((-solution_searchDir[b] > full_loop_B.denomTol) &&
        (!workingset_isActiveConstr[(workingset_isActiveIdx[3] +
          workingset_sizes[3]) - 2])) {
      full_loop_B.ratio = -solution_xstar[b] - workingset_lb[b];
      full_loop_B.u0 = fabs(full_loop_B.ratio);
      if ((!(full_loop_B.u0 < 0.01 - full_loop_B.ratio)) && (!rtIsNaN(0.01 -
            full_loop_B.ratio))) {
        full_loop_B.u0 = 0.01 - full_loop_B.ratio;
      }

      full_loop_B.pk_corrected = full_loop_B.u0 / -solution_searchDir[b];
      if (full_loop_B.pk_corrected < *alpha) {
        *alpha = full_loop_B.pk_corrected;
        *constrType = 4;
        *constrIdx = workingset_sizes[3];
        *newBlocking = true;
      }
    }
  }

  if (!isPhaseOne) {
    if ((*newBlocking) && (*alpha > 1.0)) {
      *newBlocking = false;
    }

    if (!(*alpha < 1.0)) {
      *alpha = 1.0;
    }
  }
}

static void full_checkUnboundedOrIllPosed_p(s2CPTVnVyv153Hb6bxlki6F_full__T
  *solution, const sJdVcLKPgejLYHLePKb6F6D_full__T *objective)
{
  if (objective->objtype == 5) {
    if (full_loop_xnrm2_p4(objective->nvar, solution->searchDir) > 100.0 *
        static_cast<real_T>(objective->nvar) * 1.4901161193847656E-8) {
      solution->state = 3;
    } else {
      solution->state = 4;
    }
  }
}

static void full_addBoundToActiveSetMatrix_(const
  sH6xx18cQHI5sgA7Ajla4nE_full__T *obj, int32_T TYPE, int32_T idx_local,
  sH6xx18cQHI5sgA7Ajla4nE_full__T *b_obj)
{
  int32_T idx_global;
  int32_T idx_bnd_local;
  int32_T b;
  *b_obj = *obj;
  b_obj->nWConstr[TYPE - 1] = obj->nWConstr[TYPE - 1] + 1;
  b_obj->isActiveConstr[(obj->isActiveIdx[TYPE - 1] + idx_local) - 2] = true;
  b_obj->nActiveConstr = obj->nActiveConstr + 1;
  b_obj->Wid[obj->nActiveConstr] = TYPE;
  b_obj->Wlocalidx[obj->nActiveConstr] = idx_local;
  idx_global = obj->nActiveConstr;
  if (TYPE == 5) {
    idx_bnd_local = obj->indexUB[idx_local - 1] - 1;
    b_obj->bwset[obj->nActiveConstr] = obj->ub[idx_bnd_local];
  } else {
    idx_bnd_local = obj->indexLB[idx_local - 1] - 1;
    b_obj->bwset[obj->nActiveConstr] = obj->lb[idx_bnd_local];
  }

  b = idx_bnd_local - 1;
  if (0 <= b) {
    memset(&b_obj->ATwset[idx_global * 21], 0, (((b + idx_global * 21) -
             idx_global * 21) + 1) * sizeof(real_T));
  }

  b = 21 * obj->nActiveConstr;
  b_obj->ATwset[idx_bnd_local + b] = static_cast<real_T>(TYPE == 5) * 2.0 - 1.0;
  if (idx_bnd_local + 2 <= obj->nVar) {
    memset(&b_obj->ATwset[(idx_bnd_local + idx_global * 21) + 1], 0,
           ((((obj->nVar + idx_global * 21) - idx_bnd_local) - idx_global * 21)
            + -1) * sizeof(real_T));
  }

  switch (obj->probType) {
   case 3:
   case 2:
    break;

   default:
    b_obj->ATwset[(obj->nVar + b) - 1] = -1.0;
    break;
  }
}

static void full_loop_addAineqConstr(const sH6xx18cQHI5sgA7Ajla4nE_full__T *obj,
  int32_T idx_local, sH6xx18cQHI5sgA7Ajla4nE_full__T *b_obj)
{
  *b_obj = *obj;
  b_obj->nWConstr[2] = obj->nWConstr[2] + 1;
  b_obj->isActiveConstr[(obj->isActiveIdx[2] + idx_local) - 2] = true;
  b_obj->nActiveConstr = obj->nActiveConstr + 1;
  b_obj->Wid[obj->nActiveConstr] = 3;
  b_obj->Wlocalidx[obj->nActiveConstr] = idx_local;
  memcpy(&b_obj->ATwset[0], &obj->ATwset[0], 399U * sizeof(real_T));
}

static void full_loop_xaxpy_p4(int32_T n, real_T a, const real_T x[21], real_T
  y[21])
{
  int32_T k;
  if ((n < 1) || (a == 0.0)) {
  } else {
    for (k = 0; k < n; k++) {
      y[k] += a * x[k];
    }
  }
}

static void full_loop_xgemv(int32_T m, int32_T n, const real_T A[441], const
  real_T x[21], const real_T y[441], real_T b_y[441])
{
  int32_T ix;
  int32_T iy;
  int32_T b;
  int32_T iac;
  int32_T d;
  int32_T ia;
  memcpy(&b_y[0], &y[0], 441U * sizeof(real_T));
  if ((m == 0) || (n == 0)) {
  } else {
    if (0 <= n - 1) {
      memset(&b_y[0], 0, n * sizeof(real_T));
    }

    iy = 0;
    b = (n - 1) * 21;
    for (iac = 1; iac <= b + 1; iac += 21) {
      ix = 0;
      full_loop_B.c_k = 0.0;
      d = iac + m;
      for (ia = iac; ia < d; ia++) {
        full_loop_B.c_k += A[ia - 1] * x[ix];
        ix++;
      }

      b_y[iy] += full_loop_B.c_k;
      iy++;
    }
  }
}

static void full_loop_compute_lambda_p(const real_T workspace[441],
  s2CPTVnVyv153Hb6bxlki6F_full__T *solution, const
  sJdVcLKPgejLYHLePKb6F6D_full__T *objective, const
  snaQeDJ4fX7UykrKyr5M8jC_full__T *qrmanager, real_T b_workspace[441])
{
  boolean_T nonDegenerate;
  int32_T b_i;
  boolean_T guard1 = false;
  memcpy(&b_workspace[0], &workspace[0], 441U * sizeof(real_T));
  full_loop_B.nActiveConstr_n = qrmanager->ncols;
  if (qrmanager->ncols > 0) {
    full_loop_B.tol_j = 100.0 * static_cast<real_T>(qrmanager->mrows) *
      2.2204460492503131E-16;
    if ((qrmanager->mrows > 0) && (qrmanager->ncols > 0)) {
      nonDegenerate = true;
    } else {
      nonDegenerate = false;
    }

    if (nonDegenerate) {
      full_loop_B.idx_h = qrmanager->ncols;
      guard1 = false;
      if (qrmanager->mrows < qrmanager->ncols) {
        while ((full_loop_B.idx_h > qrmanager->mrows) && (fabs(qrmanager->QR
                 [((full_loop_B.idx_h - 1) * 21 + qrmanager->mrows) - 1]) >=
                full_loop_B.tol_j)) {
          full_loop_B.idx_h--;
        }

        nonDegenerate = (full_loop_B.idx_h == qrmanager->mrows);
        if (!nonDegenerate) {
        } else {
          guard1 = true;
        }
      } else {
        guard1 = true;
      }

      if (guard1) {
        while ((full_loop_B.idx_h >= 1) && (fabs(qrmanager->QR
                 [((full_loop_B.idx_h - 1) * 21 + full_loop_B.idx_h) - 1]) >=
                full_loop_B.tol_j)) {
          full_loop_B.idx_h--;
        }

        nonDegenerate = (full_loop_B.idx_h == 0);
      }
    }

    if (!nonDegenerate) {
      solution->state = -7;
    } else {
      full_loop_xgemv(qrmanager->mrows, qrmanager->ncols, qrmanager->Q,
                      objective->grad, workspace, b_workspace);
      if (qrmanager->ncols != 0) {
        for (full_loop_B.idx_h = full_loop_B.nActiveConstr_n; full_loop_B.idx_h >=
             1; full_loop_B.idx_h--) {
          full_loop_B.jjA_h = ((full_loop_B.idx_h - 1) * 21 + full_loop_B.idx_h)
            - 1;
          b_workspace[full_loop_B.idx_h - 1] /= qrmanager->QR[full_loop_B.jjA_h];
          full_loop_B.b_f4 = full_loop_B.idx_h - 2;
          for (b_i = 0; b_i <= full_loop_B.b_f4; b_i++) {
            full_loop_B.i_f = b_i + 1;
            full_loop_B.ix_i = (full_loop_B.idx_h - full_loop_B.i_f) - 1;
            b_workspace[full_loop_B.ix_i] -= b_workspace[full_loop_B.idx_h - 1] *
              qrmanager->QR[full_loop_B.jjA_h - full_loop_B.i_f];
          }
        }
      }

      for (full_loop_B.idx_h = 0; full_loop_B.idx_h <
           full_loop_B.nActiveConstr_n; full_loop_B.idx_h++) {
        solution->lambda[full_loop_B.idx_h] = -b_workspace[full_loop_B.idx_h];
      }
    }
  }
}

static int32_T full_loop_find_neg_lambda(const s2CPTVnVyv153Hb6bxlki6F_full__T
  *solution, int32_T workingset_nActiveConstr, const int32_T
  workingset_nWConstr[5])
{
  int32_T idxMinLambda;
  real_T minLambda;
  int32_T b;
  int32_T idx;
  real_T tmp;
  idxMinLambda = 0;
  minLambda = 0.0;
  b = workingset_nWConstr[0] + workingset_nWConstr[1];
  for (idx = b + 1; idx <= workingset_nActiveConstr; idx++) {
    tmp = solution->lambda[idx - 1];
    if (tmp < minLambda) {
      minLambda = tmp;
      idxMinLambda = idx;
    }
  }

  return idxMinLambda;
}

static int32_T full_loop_mod(int32_T x)
{
  return x - x / 50 * 50;
}

static void fu_checkStoppingAndUpdateFval_p(int32_T activeSetChangeID, const
  real_T f[21], s2CPTVnVyv153Hb6bxlki6F_full__T *solution,
  sVTYnQ9ljvmk9dLse9XvTT_full_l_T *memspace, const
  sJdVcLKPgejLYHLePKb6F6D_full__T *objective, sH6xx18cQHI5sgA7Ajla4nE_full__T
  *workingset, snaQeDJ4fX7UykrKyr5M8jC_full__T *qrmanager, const
  s1TgE9KstXgkd2qJxO1bF4F_full__T *options, const
  s1TgE9KstXgkd2qJxO1bF4F_full__T *runTimeOptions, boolean_T updateFval, int32_T
  *b_activeSetChangeID, sJdVcLKPgejLYHLePKb6F6D_full__T *b_objective)
{
  boolean_T nonDegenerateWset;
  *b_activeSetChangeID = activeSetChangeID;
  solution->iterations++;
  full_loop_B.nVar_h = objective->nvar - 1;
  *b_objective = *objective;
  if ((solution->iterations >= runTimeOptions->MaxIterations) &&
      (!((solution->state == 1) && (objective->objtype != 5)))) {
    solution->state = 0;
  }

  if (full_loop_mod(solution->iterations) == 0) {
    full_loop_B.workingset_n = *workingset;
    full__maxConstraintViolation_p4(&full_loop_B.workingset_n, solution->xstar,
      &full_loop_B.b_f, workingset);
    solution->maxConstr = full_loop_B.b_f;
    if (full_loop_B.b_f > 0.01) {
      if (0 <= full_loop_B.nVar_h) {
        memcpy(&solution->searchDir[0], &solution->xstar[0], (full_loop_B.nVar_h
                + 1) * sizeof(real_T));
      }

      memcpy(&full_loop_B.e[0], &solution->searchDir[0], 21U * sizeof(real_T));
      full_loop_B.workingset_n = *workingset;
      memcpy(&full_loop_B.memspace_o[0], &memspace->workspace_double[0], 441U *
             sizeof(real_T));
      full__feasibleX0ForWorkingSet_p(full_loop_B.memspace_o, full_loop_B.e,
        &full_loop_B.workingset_n, qrmanager, &nonDegenerateWset,
        memspace->workspace_double);
      memcpy(&solution->searchDir[0], &full_loop_B.e[0], 21U * sizeof(real_T));
      if ((!nonDegenerateWset) && (solution->state != 0)) {
        solution->state = -2;
      }

      *b_activeSetChangeID = 0;
      full__maxConstraintViolation_p4(&full_loop_B.workingset_n, full_loop_B.e,
        &full_loop_B.constrViolation_new, workingset);
      if (full_loop_B.constrViolation_new < full_loop_B.b_f) {
        if (0 <= full_loop_B.nVar_h) {
          memcpy(&solution->xstar[0], &full_loop_B.e[0], (full_loop_B.nVar_h + 1)
                 * sizeof(real_T));
        }

        solution->maxConstr = full_loop_B.constrViolation_new;
      }
    }
  }

  if ((options->ObjectiveLimit > (rtMinusInf)) && updateFval) {
    memcpy(&full_loop_B.memspace_o[0], &memspace->workspace_double[0], 441U *
           sizeof(real_T));
    full_loop_computeFval_ReuseHx_p(objective, full_loop_B.memspace_o, f,
      solution->xstar, &full_loop_B.b_f, memspace->workspace_double);
    solution->fstar = full_loop_B.b_f;
    if ((full_loop_B.b_f < options->ObjectiveLimit) && (!((solution->state == 0)
          && (objective->objtype == 5)))) {
      solution->state = 2;
    }
  }
}

static void full_loop_iterate_p(const real_T H[64], const real_T f[21],
  s2CPTVnVyv153Hb6bxlki6F_full__T *solution, sVTYnQ9ljvmk9dLse9XvTT_full_l_T
  *memspace, sH6xx18cQHI5sgA7Ajla4nE_full__T *workingset,
  snaQeDJ4fX7UykrKyr5M8jC_full__T *qrmanager, snl99C5je2zMbU5SzygoX6F_full__T
  *cholmanager, const sJdVcLKPgejLYHLePKb6F6D_full__T *objective, const
  s1TgE9KstXgkd2qJxO1bF4F_full__T *options, const
  s1TgE9KstXgkd2qJxO1bF4F_full__T *runTimeOptions,
  sJdVcLKPgejLYHLePKb6F6D_full__T *b_objective)
{
  boolean_T subProblemChanged;
  boolean_T updateFval;
  int32_T exitg1;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  subProblemChanged = true;
  updateFval = true;
  full_loop_B.activeSetChangeID = 0;
  full_loop_B.TYPE = objective->objtype;
  full_loop_B.nVar_j = workingset->nVar;
  full_loop_B.globalActiveConstrIdx = 0;
  *b_objective = *objective;
  full_loop_computeGrad_StoreHx_p(b_objective, H, f, solution->xstar);
  memcpy(&full_loop_B.memspace_l[0], &memspace->workspace_double[0], 441U *
         sizeof(real_T));
  memcpy(&full_loop_B.solution_as[0], &solution->xstar[0], 21U * sizeof(real_T));
  full_loop_computeFval_ReuseHx_p(b_objective, full_loop_B.memspace_l, f,
    full_loop_B.solution_as, &solution->fstar, memspace->workspace_double);
  if (solution->iterations < runTimeOptions->MaxIterations) {
    solution->state = -5;
  } else {
    solution->state = 0;
  }

  full_loop_B.idxMinLambda = workingset->mConstrMax - 1;
  if (0 <= full_loop_B.idxMinLambda) {
    memset(&solution->lambda[0], 0, (full_loop_B.idxMinLambda + 1) * sizeof
           (real_T));
  }

  do {
    exitg1 = 0;
    if (solution->state == -5) {
      guard1 = false;
      guard2 = false;
      if (subProblemChanged) {
        switch (full_loop_B.activeSetChangeID) {
         case 1:
          full_loop_squareQ_appendCol_p(qrmanager, workingset->ATwset, 21 *
            (workingset->nActiveConstr - 1) + 1);
          break;

         case -1:
          full_loop_deleteColMoveEnd_p(qrmanager,
            full_loop_B.globalActiveConstrIdx);
          break;

         default:
          full_loop_factorQR_p4(qrmanager, workingset->ATwset,
                                full_loop_B.nVar_j, workingset->nActiveConstr);
          full_loop_computeQ__p(qrmanager, qrmanager->mrows);
          break;
        }

        full_loop_B.qrmanager_p = *qrmanager;
        full_loop_compute_deltax_p(H, solution, memspace,
          &full_loop_B.qrmanager_p, cholmanager, b_objective, qrmanager);
        if (solution->state != -5) {
          exitg1 = 1;
        } else if ((full_loop_xnrm2_p4(full_loop_B.nVar_j, solution->searchDir) <
                    options->StepTolerance) || (workingset->nActiveConstr >=
                    full_loop_B.nVar_j)) {
          guard2 = true;
        } else {
          memcpy(&full_loop_B.memspace_l[0], &memspace->workspace_double[0],
                 441U * sizeof(real_T));
          full_loop_feasibleratiotest(solution->xstar, solution->searchDir,
            full_loop_B.memspace_l, workingset->nVar, workingset->lb,
            workingset->indexLB, workingset->sizes, workingset->isActiveIdx,
            workingset->isActiveConstr, workingset->nWConstr, full_loop_B.TYPE ==
            5, &full_loop_B.alpha, &updateFval, &full_loop_B.idxMinLambda,
            &full_loop_B.j_c, memspace->workspace_double);
          if (updateFval) {
            switch (full_loop_B.idxMinLambda) {
             case 3:
              full_loop_B.workingset = *workingset;
              full_loop_addAineqConstr(&full_loop_B.workingset, full_loop_B.j_c,
                workingset);
              break;

             case 4:
              full_loop_B.workingset = *workingset;
              full_addBoundToActiveSetMatrix_(&full_loop_B.workingset, 4,
                full_loop_B.j_c, workingset);
              break;

             default:
              full_loop_B.workingset = *workingset;
              full_addBoundToActiveSetMatrix_(&full_loop_B.workingset, 5,
                full_loop_B.j_c, workingset);
              break;
            }

            full_loop_B.activeSetChangeID = 1;
          } else {
            full_checkUnboundedOrIllPosed_p(solution, b_objective);
            subProblemChanged = false;
            if (workingset->nActiveConstr == 0) {
              solution->state = 1;
            }
          }

          full_loop_xaxpy_p4(full_loop_B.nVar_j, full_loop_B.alpha,
                             solution->searchDir, solution->xstar);
          full_loop_computeGrad_StoreHx_p(b_objective, H, f, solution->xstar);
          updateFval = true;
          guard1 = true;
        }
      } else {
        if (0 <= full_loop_B.nVar_j - 1) {
          memset(&solution->searchDir[0], 0, full_loop_B.nVar_j * sizeof(real_T));
        }

        guard2 = true;
      }

      if (guard2) {
        memcpy(&full_loop_B.memspace_l[0], &memspace->workspace_double[0], 441U *
               sizeof(real_T));
        full_loop_compute_lambda_p(full_loop_B.memspace_l, solution, b_objective,
          qrmanager, memspace->workspace_double);
        if (solution->state != -7) {
          full_loop_B.idxMinLambda = full_loop_find_neg_lambda(solution,
            workingset->nActiveConstr, workingset->nWConstr);
          if (full_loop_B.idxMinLambda == 0) {
            solution->state = 1;
          } else {
            full_loop_B.activeSetChangeID = -1;
            full_loop_B.globalActiveConstrIdx = full_loop_B.idxMinLambda;
            subProblemChanged = true;
            full_loop_removeConstr_p(workingset, full_loop_B.idxMinLambda);
            solution->lambda[full_loop_B.idxMinLambda - 1] = 0.0;
          }
        } else {
          full_loop_B.idxMinLambda = workingset->nActiveConstr - 1;
          full_loop_B.activeSetChangeID = 0;
          full_loop_B.globalActiveConstrIdx = workingset->nActiveConstr;
          subProblemChanged = true;
          full_loop_removeConstr_p(workingset, workingset->nActiveConstr);
          solution->lambda[full_loop_B.idxMinLambda] = 0.0;
        }

        updateFval = false;
        guard1 = true;
      }

      if (guard1) {
        full_loop_B.b_objective = *b_objective;
        fu_checkStoppingAndUpdateFval_p(full_loop_B.activeSetChangeID, f,
          solution, memspace, &full_loop_B.b_objective, workingset, qrmanager,
          options, runTimeOptions, updateFval, &full_loop_B.activeSetChangeID,
          b_objective);
      }
    } else {
      if (!updateFval) {
        memcpy(&full_loop_B.memspace_l[0], &memspace->workspace_double[0], 441U *
               sizeof(real_T));
        memcpy(&full_loop_B.solution_as[0], &solution->xstar[0], 21U * sizeof
               (real_T));
        full_loop_computeFval_ReuseHx_p(b_objective, full_loop_B.memspace_l, f,
          full_loop_B.solution_as, &solution->fstar, memspace->workspace_double);
      }

      exitg1 = 1;
    }
  } while (exitg1 == 0);
}

static void full_loop_restoreFromPhaseOne(const sJdVcLKPgejLYHLePKb6F6D_full__T *
  obj, sJdVcLKPgejLYHLePKb6F6D_full__T *b_obj)
{
  *b_obj = *obj;
  b_obj->objtype = obj->prev_objtype;
  b_obj->nvar = obj->prev_nvar;
  b_obj->hasLinear = obj->prev_hasLinear;
}

static void full_loop_phaseone_p(const real_T H[64], const real_T f[21],
  s2CPTVnVyv153Hb6bxlki6F_full__T *solution, sVTYnQ9ljvmk9dLse9XvTT_full_l_T
  *memspace, const sH6xx18cQHI5sgA7Ajla4nE_full__T *workingset, const
  snaQeDJ4fX7UykrKyr5M8jC_full__T *qrmanager, const
  snl99C5je2zMbU5SzygoX6F_full__T *cholmanager, const
  sJdVcLKPgejLYHLePKb6F6D_full__T *objective, s1TgE9KstXgkd2qJxO1bF4F_full__T
  *options, const s1TgE9KstXgkd2qJxO1bF4F_full__T *runTimeOptions,
  sH6xx18cQHI5sgA7Ajla4nE_full__T *b_workingset, snaQeDJ4fX7UykrKyr5M8jC_full__T
  *b_qrmanager, snl99C5je2zMbU5SzygoX6F_full__T *b_cholmanager,
  sJdVcLKPgejLYHLePKb6F6D_full__T *b_objective)
{
  boolean_T exitg1;
  solution->xstar[workingset->nVar] = solution->maxConstr + 1.0;
  options->ObjectiveLimit = 0.01;
  options->StepTolerance = 1.4901161193847657E-10;
  full_loop_setPhaseOne(objective, workingset->nVar + 1,
                        &full_loop_B.c_objective);
  memcpy(&full_loop_B.memspace_d[0], &memspace->workspace_double[0], 441U *
         sizeof(real_T));
  memcpy(&full_loop_B.solution_a[0], &solution->xstar[0], 21U * sizeof(real_T));
  full_loop_computeFval_p(&full_loop_B.c_objective, full_loop_B.memspace_d, H, f,
    full_loop_B.solution_a, &solution->fstar, memspace->workspace_double);
  solution->state = 5;
  if (workingset->probType == 3) {
    full_loop_B.mConstr_o = 1;
  } else {
    full_loop_B.mConstr_o = 4;
  }

  full_loop_removeAllIneqConstr(workingset, &full_loop_B.b_workingset);
  full_loop_setProblemType(&full_loop_B.b_workingset, full_loop_B.mConstr_o,
    b_workingset);
  *b_qrmanager = *qrmanager;
  *b_cholmanager = *cholmanager;
  full_loop_iterate_p(H, f, solution, memspace, b_workingset, b_qrmanager,
                      b_cholmanager, &full_loop_B.c_objective, options,
                      runTimeOptions, &full_loop_B.d_objective);
  if (b_workingset->isActiveConstr[(b_workingset->isActiveIdx[3] +
       b_workingset->sizes[3]) - 2]) {
    full_loop_B.mConstr_o = b_workingset->sizes[1];
    exitg1 = false;
    while ((!exitg1) && (full_loop_B.mConstr_o + 1 <=
                         b_workingset->nActiveConstr)) {
      if ((b_workingset->Wid[full_loop_B.mConstr_o] == 4) &&
          (b_workingset->Wlocalidx[full_loop_B.mConstr_o] == b_workingset->
           sizes[3])) {
        full_loop_removeConstr_p(b_workingset, full_loop_B.mConstr_o + 1);
        exitg1 = true;
      } else {
        full_loop_B.mConstr_o++;
      }
    }
  }

  full_loop_B.mConstr_o = b_workingset->nActiveConstr;
  full_loop_B.mEqFixed = b_workingset->sizes[1];
  while ((full_loop_B.mConstr_o > full_loop_B.mEqFixed) &&
         (full_loop_B.mConstr_o > workingset->nVar)) {
    full_loop_removeConstr_p(b_workingset, full_loop_B.mConstr_o);
    full_loop_B.mConstr_o--;
  }

  solution->maxConstr = solution->xstar[workingset->nVar];
  full_loop_B.b_workingset = *b_workingset;
  full_loop_setProblemType(&full_loop_B.b_workingset, workingset->probType,
    b_workingset);
  full_loop_restoreFromPhaseOne(&full_loop_B.d_objective, b_objective);
  options->ObjectiveLimit = -1.0E+20;
  options->StepTolerance = 1.0E-6;
}

static void full_loop_driver_p43(const real_T H[64], const real_T f[21],
  s2CPTVnVyv153Hb6bxlki6F_full__T *solution, const
  sVTYnQ9ljvmk9dLse9XvTT_full_l_T *memspace, const
  sH6xx18cQHI5sgA7Ajla4nE_full__T *workingset, const
  snaQeDJ4fX7UykrKyr5M8jC_full__T *qrmanager, snl99C5je2zMbU5SzygoX6F_full__T
  *cholmanager, sJdVcLKPgejLYHLePKb6F6D_full__T *objective,
  s1TgE9KstXgkd2qJxO1bF4F_full__T *options, s1TgE9KstXgkd2qJxO1bF4F_full__T
  *runTimeOptions, sVTYnQ9ljvmk9dLse9XvTT_full_l_T *b_memspace,
  sH6xx18cQHI5sgA7Ajla4nE_full__T *b_workingset, snaQeDJ4fX7UykrKyr5M8jC_full__T
  *b_qrmanager)
{
  boolean_T guard1 = false;
  solution->iterations = 0;
  runTimeOptions->RemainFeasible = true;
  full_loop_B.nVar_d = workingset->nVar - 1;
  full_loop_snap_bounds_p(solution, workingset);
  full_loop_B.solution = *solution;
  full_loop_PresolveWorkingSet_p(&full_loop_B.solution, memspace, workingset,
    qrmanager, solution, b_memspace, b_workingset, b_qrmanager);
  if (solution->state >= 0) {
    solution->iterations = 0;
    full__maxConstraintViolation_p4(b_workingset, solution->xstar,
      &full_loop_B.b_e, &full_loop_B.d_workingset);
    solution->maxConstr = full_loop_B.b_e;
    *b_workingset = full_loop_B.d_workingset;
    guard1 = false;
    if (full_loop_B.b_e > 0.01) {
      full_loop_B.d_memspace_d = *b_memspace;
      full_loop_B.cholmanager = *cholmanager;
      full_loop_B.objective = *objective;
      full_loop_phaseone_p(H, f, solution, &full_loop_B.d_memspace_d,
                           &full_loop_B.d_workingset, b_qrmanager,
                           &full_loop_B.cholmanager, &full_loop_B.objective,
                           options, runTimeOptions, b_workingset,
                           &full_loop_B.d_qrmanager, cholmanager, objective);
      *b_memspace = full_loop_B.d_memspace_d;
      *b_qrmanager = full_loop_B.d_qrmanager;
      if (solution->state == 0) {
      } else {
        full__maxConstraintViolation_p4(b_workingset, solution->xstar,
          &full_loop_B.b_e, &full_loop_B.d_workingset);
        solution->maxConstr = full_loop_B.b_e;
        *b_workingset = full_loop_B.d_workingset;
        if (full_loop_B.b_e > 0.01) {
          full_loop_B.nVar_d = full_loop_B.d_workingset.mConstrMax - 1;
          if (0 <= full_loop_B.nVar_d) {
            memset(&solution->lambda[0], 0, (full_loop_B.nVar_d + 1) * sizeof
                   (real_T));
          }

          memcpy(&full_loop_B.solution_e[0], &solution->xstar[0], 21U * sizeof
                 (real_T));
          full_loop_computeFval_p(objective,
            full_loop_B.d_memspace_d.workspace_double, H, f,
            full_loop_B.solution_e, &solution->fstar,
            b_memspace->workspace_double);
          solution->state = -2;
        } else {
          if (full_loop_B.b_e > 0.0) {
            if (0 <= full_loop_B.nVar_d) {
              memcpy(&solution->searchDir[0], &solution->xstar[0],
                     (full_loop_B.nVar_d + 1) * sizeof(real_T));
            }

            full_loop_PresolveWorkingSet_p(solution, &full_loop_B.d_memspace_d,
              &full_loop_B.d_workingset, &full_loop_B.d_qrmanager,
              &full_loop_B.solution, b_memspace, &full_loop_B.h_workingset,
              b_qrmanager);
            *solution = full_loop_B.solution;
            full__maxConstraintViolation_p4(&full_loop_B.h_workingset,
              full_loop_B.solution.xstar, &full_loop_B.b_e, b_workingset);
            if (full_loop_B.b_e >= full_loop_B.solution.maxConstr) {
              solution->maxConstr = full_loop_B.b_e;
              memcpy(&solution->xstar[0], &full_loop_B.solution.xstar[0], 21U *
                     sizeof(real_T));
              if (0 <= full_loop_B.nVar_d) {
                memcpy(&solution->xstar[0], &full_loop_B.solution.searchDir[0],
                       (full_loop_B.nVar_d + 1) * sizeof(real_T));
              }
            }
          }

          guard1 = true;
        }
      }
    } else {
      guard1 = true;
    }

    if (guard1) {
      full_loop_B.objective = *objective;
      full_loop_iterate_p(H, f, solution, b_memspace, b_workingset, b_qrmanager,
                          cholmanager, &full_loop_B.objective, options,
                          runTimeOptions, objective);
    }
  }
}

static void full_loop_restoreWorkingSet_p(sH6xx18cQHI5sgA7Ajla4nE_full__T
  *WorkingSet, const s2CPTVnVyv153Hb6bxlki6F_full__T *TrialState)
{
  int32_T mEq;
  int32_T b_idx;
  mEq = WorkingSet->sizes[1] - 1;
  if (WorkingSet->sizes[1] > 0) {
    for (b_idx = 0; b_idx <= mEq; b_idx++) {
      WorkingSet->beq[b_idx] = -TrialState->cEq[b_idx];
      WorkingSet->bwset[b_idx] = WorkingSet->beq[b_idx];
    }
  }
}

static void full_loop_sortLambdaQP_p(real_T lambda[19], int32_T
  WorkingSet_nActiveConstr, const int32_T WorkingSet_sizes[5], const int32_T
  WorkingSet_isActiveIdx[6], const int32_T WorkingSet_Wid[19], const int32_T
  WorkingSet_Wlocalidx[19], const real_T workspace[441], real_T b_workspace[441])
{
  int32_T mAll;
  int32_T currentMplier;
  int32_T idxOffset;
  memcpy(&b_workspace[0], &workspace[0], 441U * sizeof(real_T));
  if (WorkingSet_nActiveConstr != 0) {
    mAll = (WorkingSet_sizes[1] + WorkingSet_sizes[3]) - 1;
    for (currentMplier = 0; currentMplier <= mAll; currentMplier++) {
      b_workspace[currentMplier] = lambda[currentMplier];
      lambda[currentMplier] = 0.0;
    }

    currentMplier = 0;
    mAll = 0;
    while ((mAll + 1 <= WorkingSet_nActiveConstr) && (WorkingSet_Wid[mAll] <= 2))
    {
      if (WorkingSet_Wid[mAll] == 1) {
        idxOffset = -1;
      } else {
        idxOffset = WorkingSet_isActiveIdx[1] - 2;
      }

      lambda[idxOffset + WorkingSet_Wlocalidx[mAll]] = b_workspace[currentMplier];
      currentMplier++;
      mAll++;
    }

    while (mAll + 1 <= WorkingSet_nActiveConstr) {
      switch (WorkingSet_Wid[mAll]) {
       case 3:
        idxOffset = WorkingSet_isActiveIdx[2];
        break;

       case 4:
        idxOffset = WorkingSet_isActiveIdx[3];
        break;

       default:
        idxOffset = WorkingSet_isActiveIdx[4];
        break;
      }

      lambda[(idxOffset + WorkingSet_Wlocalidx[mAll]) - 2] =
        b_workspace[currentMplier];
      currentMplier++;
      mAll++;
    }
  }
}

static void full_loop_addAeqConstr(const sH6xx18cQHI5sgA7Ajla4nE_full__T *obj,
  int32_T idx_local, sH6xx18cQHI5sgA7Ajla4nE_full__T *b_obj)
{
  int32_T totalEq;
  int32_T iAeq0;
  int32_T iAw0;
  int32_T idx;
  int32_T b;
  int32_T b_idx;
  *b_obj = *obj;
  totalEq = b_obj->nWConstr[0] + b_obj->nWConstr[1];
  if ((b_obj->nActiveConstr == totalEq) && (idx_local > b_obj->nWConstr[1])) {
    b_obj->nWConstr[1] = obj->nWConstr[1] + 1;
    b_obj->isActiveConstr[(obj->isActiveIdx[1] + idx_local) - 2] = true;
    b_obj->nActiveConstr = obj->nActiveConstr + 1;
    b_obj->Wid[obj->nActiveConstr] = 2;
    b_obj->Wlocalidx[obj->nActiveConstr] = idx_local;
    iAeq0 = (idx_local - 1) * 21 - 1;
    iAw0 = 21 * obj->nActiveConstr - 1;
    b = obj->nVar - 1;
    for (b_idx = 0; b_idx <= b; b_idx++) {
      idx = b_idx + 1;
      b_obj->ATwset[iAw0 + idx] = obj->Aeq[iAeq0 + idx];
    }

    b_obj->bwset[obj->nActiveConstr] = obj->beq[idx_local - 1];
  } else {
    b_obj->nActiveConstr++;
    b_obj->Wid[b_obj->nActiveConstr - 1] = b_obj->Wid[totalEq];
    b_obj->Wlocalidx[b_obj->nActiveConstr - 1] = b_obj->Wlocalidx[totalEq];
    b = b_obj->nVar - 1;
    for (b_idx = 0; b_idx <= b; b_idx++) {
      b_obj->ATwset[b_idx + 21 * (b_obj->nActiveConstr - 1)] = b_obj->ATwset[21 *
        totalEq + b_idx];
    }

    b_obj->bwset[b_obj->nActiveConstr - 1] = b_obj->bwset[totalEq];
    b_obj->nWConstr[1]++;
    b_obj->isActiveConstr[(b_obj->isActiveIdx[1] + idx_local) - 2] = true;
    b_obj->Wid[totalEq] = 2;
    b_obj->Wlocalidx[totalEq] = idx_local;
    iAeq0 = (idx_local - 1) * 21 - 1;
    iAw0 = 21 * totalEq - 1;
    b = b_obj->nVar - 1;
    for (b_idx = 0; b_idx <= b; b_idx++) {
      idx = b_idx + 1;
      b_obj->ATwset[iAw0 + idx] = b_obj->Aeq[iAeq0 + idx];
    }

    b_obj->bwset[totalEq] = b_obj->beq[idx_local - 1];
  }
}

static void full_loop_soc_p(const real_T Hessian[64], const real_T grad[21],
  s2CPTVnVyv153Hb6bxlki6F_full__T *TrialState, const
  sVTYnQ9ljvmk9dLse9XvTT_full_l_T *memspace, const
  sH6xx18cQHI5sgA7Ajla4nE_full__T *WorkingSet, const
  snaQeDJ4fX7UykrKyr5M8jC_full__T *QRManager, const
  snl99C5je2zMbU5SzygoX6F_full__T *CholManager, const
  sJdVcLKPgejLYHLePKb6F6D_full__T *QPObjective, const
  s1TgE9KstXgkd2qJxO1bF4F_full__T *qpoptions, boolean_T *success, real_T
  b_Hessian[64], sVTYnQ9ljvmk9dLse9XvTT_full_l_T *b_memspace,
  sH6xx18cQHI5sgA7Ajla4nE_full__T *b_WorkingSet, snaQeDJ4fX7UykrKyr5M8jC_full__T
  *b_QRManager, snl99C5je2zMbU5SzygoX6F_full__T *b_CholManager,
  sJdVcLKPgejLYHLePKb6F6D_full__T *b_QPObjective)
{
  boolean_T exitg1;
  memcpy(&b_Hessian[0], &Hessian[0], sizeof(real_T) << 6U);
  full_loop_B.nVar_d4 = WorkingSet->nVar - 1;
  full_loop_B.mConstrMax = WorkingSet->mConstrMax - 1;
  for (full_loop_B.b_k_e = 0; full_loop_B.b_k_e <= full_loop_B.nVar_d4;
       full_loop_B.b_k_e++) {
    TrialState->xstarsqp[full_loop_B.b_k_e] = TrialState->
      xstarsqp_old[full_loop_B.b_k_e];
    TrialState->socDirection[full_loop_B.b_k_e] = TrialState->
      xstar[full_loop_B.b_k_e];
  }

  if (0 <= full_loop_B.mConstrMax) {
    memcpy(&TrialState->lambda_old[0], &TrialState->lambda[0],
           (full_loop_B.mConstrMax + 1) * sizeof(real_T));
  }

  full_loop_B.c_WorkingSet_l = *WorkingSet;
  full_loop_updateWorkingSet_p(&full_loop_B.c_WorkingSet_l, TrialState);
  if (0 <= full_loop_B.nVar_d4) {
    memcpy(&TrialState->xstar[0], &TrialState->xstarsqp[0], (full_loop_B.nVar_d4
            + 1) * sizeof(real_T));
  }

  *b_CholManager = *CholManager;
  *b_QPObjective = *QPObjective;
  full_loop_B.qpoptions_h2 = *qpoptions;
  full_loop_B.qpoptions_m = *qpoptions;
  full_loop_driver_p43(Hessian, grad, TrialState, memspace,
                       &full_loop_B.c_WorkingSet_l, QRManager, b_CholManager,
                       b_QPObjective, &full_loop_B.qpoptions_h2,
                       &full_loop_B.qpoptions_m, &full_loop_B.c_memspace_l,
                       b_WorkingSet, b_QRManager);
  *b_memspace = full_loop_B.c_memspace_l;
  exitg1 = false;
  while ((!exitg1) && (b_WorkingSet->mEqRemoved > 0)) {
    full_loop_B.b_k_e = b_WorkingSet->mEqRemoved - 1;
    if (b_WorkingSet->indexEqRemoved[full_loop_B.b_k_e] >= TrialState->iNonEq0)
    {
      full_loop_B.c_WorkingSet_l = *b_WorkingSet;
      full_loop_addAeqConstr(&full_loop_B.c_WorkingSet_l,
        b_WorkingSet->indexEqRemoved[full_loop_B.b_k_e], b_WorkingSet);
      b_WorkingSet->mEqRemoved--;
    } else {
      exitg1 = true;
    }
  }

  for (full_loop_B.b_k_e = 0; full_loop_B.b_k_e <= full_loop_B.nVar_d4;
       full_loop_B.b_k_e++) {
    full_loop_B.oldDirIdx = TrialState->socDirection[full_loop_B.b_k_e];
    TrialState->socDirection[full_loop_B.b_k_e] = TrialState->
      xstar[full_loop_B.b_k_e] - TrialState->socDirection[full_loop_B.b_k_e];
    TrialState->xstar[full_loop_B.b_k_e] = full_loop_B.oldDirIdx;
  }

  *success = (full_loop_xnrm2_p4(WorkingSet->nVar, TrialState->socDirection) <=
              2.0 * full_loop_xnrm2_p4(WorkingSet->nVar, TrialState->xstar));
  full_loop_restoreWorkingSet_p(b_WorkingSet, TrialState);
  if (!*success) {
    if (0 <= full_loop_B.mConstrMax) {
      memcpy(&TrialState->lambda[0], &TrialState->lambda_old[0],
             (full_loop_B.mConstrMax + 1) * sizeof(real_T));
    }
  } else {
    full_loop_sortLambdaQP_p(TrialState->lambda, b_WorkingSet->nActiveConstr,
      b_WorkingSet->sizes, b_WorkingSet->isActiveIdx, b_WorkingSet->Wid,
      b_WorkingSet->Wlocalidx, full_loop_B.c_memspace_l.workspace_double,
      b_memspace->workspace_double);
  }
}

static void full_loop_updatePenaltyParam_p4(s6ICcRyulWOFjNCN0ll7VsE_full__T *obj,
  real_T fval, const real_T eq_workspace[6], int32_T mEq, int32_T sqpiter,
  real_T qpval)
{
  real_T penaltyParamTrial;
  real_T constrViolationEq;
  real_T linearizedConstrViolPrev;
  int32_T b_k;
  penaltyParamTrial = obj->penaltyParam;
  constrViolationEq = 0.0;
  if (mEq >= 1) {
    for (b_k = 0; b_k < mEq; b_k++) {
      constrViolationEq += fabs(eq_workspace[b_k]);
    }
  }

  linearizedConstrViolPrev = obj->linearizedConstrViol;
  obj->linearizedConstrViol = 0.0;
  linearizedConstrViolPrev += constrViolationEq;
  if ((linearizedConstrViolPrev > 2.2204460492503131E-16) && (qpval > 0.0)) {
    if (fval == 0.0) {
      penaltyParamTrial = 1.0;
    } else {
      penaltyParamTrial = 1.5;
    }

    penaltyParamTrial = penaltyParamTrial * qpval / linearizedConstrViolPrev;
  }

  if (penaltyParamTrial < obj->penaltyParam) {
    obj->phi = penaltyParamTrial * constrViolationEq + fval;
    if ((penaltyParamTrial * obj->initConstrViolationEq + obj->initFval) -
        obj->phi > static_cast<real_T>(obj->nPenaltyDecreases) * obj->threshold)
    {
      obj->nPenaltyDecreases++;
      if ((obj->nPenaltyDecreases << 1) > sqpiter) {
        obj->threshold *= 10.0;
      }

      if (penaltyParamTrial > 1.0E-10) {
        obj->penaltyParam = penaltyParamTrial;
      } else {
        obj->penaltyParam = 1.0E-10;
      }
    } else {
      obj->phi = obj->penaltyParam * constrViolationEq + fval;
    }
  } else {
    if (!(penaltyParamTrial > 1.0E-10)) {
      penaltyParamTrial = 1.0E-10;
    }

    obj->penaltyParam = penaltyParamTrial;
    obj->phi = penaltyParamTrial * constrViolationEq + fval;
  }

  constrViolationEq = qpval - obj->penaltyParam * constrViolationEq;
  if (constrViolationEq < 0.0) {
    obj->phiPrimePlus = constrViolationEq;
  } else {
    obj->phiPrimePlus = 0.0;
  }
}

static void full_loop_normal_p(const real_T Hessian[64], const real_T grad[21],
  const s2CPTVnVyv153Hb6bxlki6F_full__T *TrialState,
  s6ICcRyulWOFjNCN0ll7VsE_full__T *MeritFunction, const
  sVTYnQ9ljvmk9dLse9XvTT_full_l_T *memspace, const
  sH6xx18cQHI5sgA7Ajla4nE_full__T *WorkingSet, const
  snaQeDJ4fX7UykrKyr5M8jC_full__T *QRManager, const
  snl99C5je2zMbU5SzygoX6F_full__T *CholManager, const
  sJdVcLKPgejLYHLePKb6F6D_full__T *QPObjective, const
  s1TgE9KstXgkd2qJxO1bF4F_full__T *qpoptions, real_T b_Hessian[64],
  s2CPTVnVyv153Hb6bxlki6F_full__T *b_TrialState, sVTYnQ9ljvmk9dLse9XvTT_full_l_T
  *b_memspace, sH6xx18cQHI5sgA7Ajla4nE_full__T *b_WorkingSet,
  snaQeDJ4fX7UykrKyr5M8jC_full__T *b_QRManager, snl99C5je2zMbU5SzygoX6F_full__T *
  b_CholManager, sJdVcLKPgejLYHLePKb6F6D_full__T *b_QPObjective)
{
  boolean_T exitg1;
  memcpy(&b_Hessian[0], &Hessian[0], sizeof(real_T) << 6U);
  full_loop_B.c_TrialState_i = *TrialState;
  *b_CholManager = *CholManager;
  *b_QPObjective = *QPObjective;
  full_loop_B.qpoptions_h = *qpoptions;
  full_loop_B.qpoptions_l = *qpoptions;
  full_loop_driver_p43(Hessian, grad, &full_loop_B.c_TrialState_i, memspace,
                       WorkingSet, QRManager, b_CholManager, b_QPObjective,
                       &full_loop_B.qpoptions_h, &full_loop_B.qpoptions_l,
                       &full_loop_B.c_memspace_g, b_WorkingSet, b_QRManager);
  *b_TrialState = full_loop_B.c_TrialState_i;
  *b_memspace = full_loop_B.c_memspace_g;
  if (full_loop_B.c_TrialState_i.state > 0) {
    full_loop_updatePenaltyParam_p4(MeritFunction,
      full_loop_B.c_TrialState_i.sqpFval, full_loop_B.c_TrialState_i.cEq,
      b_WorkingSet->sizes[1], full_loop_B.c_TrialState_i.sqpIterations,
      full_loop_B.c_TrialState_i.fstar);
  }

  memcpy(&b_TrialState->lambda[0], &full_loop_B.c_TrialState_i.lambda[0], 19U *
         sizeof(real_T));
  full_loop_sortLambdaQP_p(b_TrialState->lambda, b_WorkingSet->nActiveConstr,
    b_WorkingSet->sizes, b_WorkingSet->isActiveIdx, b_WorkingSet->Wid,
    b_WorkingSet->Wlocalidx, full_loop_B.c_memspace_g.workspace_double,
    b_memspace->workspace_double);
  exitg1 = false;
  while ((!exitg1) && (b_WorkingSet->mEqRemoved > 0)) {
    full_loop_B.i9 = b_WorkingSet->mEqRemoved - 1;
    if (b_WorkingSet->indexEqRemoved[full_loop_B.i9] >=
        full_loop_B.c_TrialState_i.iNonEq0) {
      full_loop_B.b_WorkingSet = *b_WorkingSet;
      full_loop_addAeqConstr(&full_loop_B.b_WorkingSet,
        b_WorkingSet->indexEqRemoved[full_loop_B.i9], b_WorkingSet);
      b_WorkingSet->mEqRemoved--;
    } else {
      exitg1 = true;
    }
  }
}

static void full__assignResidualsToXSlack_p(int32_T nVarOrig,
  sH6xx18cQHI5sgA7Ajla4nE_full__T *WorkingSet, s2CPTVnVyv153Hb6bxlki6F_full__T
  *TrialState, sVTYnQ9ljvmk9dLse9XvTT_full_l_T *memspace)
{
  int32_T ix;
  int32_T b_iy;
  int32_T b;
  int32_T d;
  full_loop_B.mEq_b = WorkingSet->sizes[1] - 1;
  full_loop_B.mLBOrig = WorkingSet->sizes[3] - (WorkingSet->sizes[1] << 1);
  if (0 <= full_loop_B.mEq_b) {
    memcpy(&memspace->workspace_double[0], &WorkingSet->beq[0],
           (full_loop_B.mEq_b + 1) * sizeof(real_T));
  }

  if ((nVarOrig == 0) || (WorkingSet->sizes[1] == 0)) {
  } else {
    full_loop_B.iyend = WorkingSet->sizes[1] - 1;
    for (b_iy = 0; b_iy <= full_loop_B.iyend; b_iy++) {
      memspace->workspace_double[b_iy] = -memspace->workspace_double[b_iy];
    }

    full_loop_B.iy_o = 0;
    b = (WorkingSet->sizes[1] - 1) * 21;
    for (b_iy = 1; b_iy <= b + 1; b_iy += 21) {
      ix = 0;
      full_loop_B.c_pr = 0.0;
      d = b_iy + nVarOrig;
      for (full_loop_B.iyend = b_iy; full_loop_B.iyend < d; full_loop_B.iyend++)
      {
        full_loop_B.c_pr += WorkingSet->Aeq[full_loop_B.iyend - 1] *
          TrialState->xstar[ix];
        ix++;
      }

      memspace->workspace_double[full_loop_B.iy_o] += full_loop_B.c_pr;
      full_loop_B.iy_o++;
    }
  }

  for (b_iy = 0; b_iy <= full_loop_B.mEq_b; b_iy++) {
    full_loop_B.iyend = (full_loop_B.mEq_b + b_iy) + 2;
    if (memspace->workspace_double[b_iy] <= 0.0) {
      TrialState->xstar[nVarOrig + b_iy] = 0.0;
      TrialState->xstar[(nVarOrig + full_loop_B.iyend) - 1] =
        -memspace->workspace_double[b_iy];
      full_loop_B.WorkingSet_p = *WorkingSet;
      full_addBoundToActiveSetMatrix_(&full_loop_B.WorkingSet_p, 4,
        (full_loop_B.mLBOrig + b_iy) + 1, WorkingSet);
      if (memspace->workspace_double[b_iy] >= -0.01) {
        full_loop_B.WorkingSet_p = *WorkingSet;
        full_addBoundToActiveSetMatrix_(&full_loop_B.WorkingSet_p, 4,
          full_loop_B.mLBOrig + full_loop_B.iyend, WorkingSet);
      }
    } else {
      TrialState->xstar[nVarOrig + b_iy] = memspace->workspace_double[b_iy];
      TrialState->xstar[(nVarOrig + full_loop_B.iyend) - 1] = 0.0;
      full_loop_B.WorkingSet_p = *WorkingSet;
      full_addBoundToActiveSetMatrix_(&full_loop_B.WorkingSet_p, 4,
        full_loop_B.mLBOrig + full_loop_B.iyend, WorkingSet);
      if (memspace->workspace_double[b_iy] <= 0.01) {
        full_loop_B.WorkingSet_p = *WorkingSet;
        full_addBoundToActiveSetMatrix_(&full_loop_B.WorkingSet_p, 4,
          (full_loop_B.mLBOrig + b_iy) + 1, WorkingSet);
      }
    }
  }
}

static void full_loop_setRegularized_p(sJdVcLKPgejLYHLePKb6F6D_full__T *obj,
  int32_T numQuadVars, real_T beta, real_T rho)
{
  obj->hasLinear = true;
  obj->nvar = numQuadVars;
  obj->objtype = 4;
  obj->beta = beta;
  obj->rho = rho;
}

static void full_findActiveSlackLowerBounds(const
  sVTYnQ9ljvmk9dLse9XvTT_full_l_T *memspace, const
  sH6xx18cQHI5sgA7Ajla4nE_full__T *WorkingSet, int32_T *nActiveLBArtificial,
  real_T b_memspace_workspace_double[441], int32_T b_memspace_workspace_int[21],
  int32_T b_memspace_workspace_sort[21])
{
  int32_T mEq;
  int32_T mFiniteLB;
  int32_T b_idx;
  boolean_T tf;
  boolean_T tf_0;
  int32_T tf_tmp;
  memcpy(&b_memspace_workspace_double[0], &memspace->workspace_double[0], 441U *
         sizeof(real_T));
  memcpy(&b_memspace_workspace_int[0], &memspace->workspace_int[0], 21U * sizeof
         (int32_T));
  memcpy(&b_memspace_workspace_sort[0], &memspace->workspace_sort[0], 21U *
         sizeof(int32_T));
  mEq = WorkingSet->sizes[1] - 1;
  mFiniteLB = WorkingSet->sizes[3] - 3;
  *nActiveLBArtificial = 0;
  for (b_idx = 0; b_idx <= mEq; b_idx++) {
    tf_tmp = WorkingSet->isActiveIdx[3] + mFiniteLB;
    tf = WorkingSet->isActiveConstr[((tf_tmp - ((mEq + 1) << 1)) + b_idx) + 2];
    tf_0 = WorkingSet->isActiveConstr[((tf_tmp - mEq) + b_idx) + 1];
    b_memspace_workspace_int[b_idx] = tf;
    b_memspace_workspace_int[(b_idx + mEq) + 1] = tf_0;
    *nActiveLBArtificial = (*nActiveLBArtificial + tf) + tf_0;
  }
}

static real_T full_loop_xasum(int32_T n, const real_T x[21], int32_T ix0)
{
  real_T y;
  int32_T kend;
  int32_T k;
  y = 0.0;
  if (n >= 1) {
    kend = ix0 + n;
    for (k = ix0; k < kend; k++) {
      y += fabs(x[k - 1]);
    }
  }

  return y;
}

static real_T full_loop_xdot(int32_T n, const real_T x[21], int32_T ix0, const
  real_T y[21], int32_T iy0)
{
  real_T d;
  int32_T ix;
  int32_T iy;
  int32_T k;
  d = 0.0;
  if (n >= 1) {
    ix = ix0 - 1;
    iy = iy0 - 1;
    for (k = 0; k < n; k++) {
      d += x[ix] * y[iy];
      ix++;
      iy++;
    }
  }

  return d;
}

static void full_loo_updatePenaltyParam_p43(s6ICcRyulWOFjNCN0ll7VsE_full__T *obj,
  real_T fval, const real_T eq_workspace[6], int32_T mEq, int32_T sqpiter,
  real_T qpval, const real_T x[21], int32_T iReg0, int32_T nRegularized)
{
  real_T constrViolationEq;
  real_T linearizedConstrViolPrev;
  real_T y;
  int32_T kend;
  int32_T b_k;
  full_loop_B.penaltyParamTrial = obj->penaltyParam;
  constrViolationEq = 0.0;
  if (mEq >= 1) {
    for (b_k = 0; b_k < mEq; b_k++) {
      constrViolationEq += fabs(eq_workspace[b_k]);
    }
  }

  linearizedConstrViolPrev = obj->linearizedConstrViol;
  y = 0.0;
  if (nRegularized >= 1) {
    kend = iReg0 + nRegularized;
    for (b_k = iReg0; b_k < kend; b_k++) {
      y += fabs(x[b_k - 1]);
    }
  }

  obj->linearizedConstrViol = y;
  linearizedConstrViolPrev = (constrViolationEq + linearizedConstrViolPrev) - y;
  if ((linearizedConstrViolPrev > 2.2204460492503131E-16) && (qpval > 0.0)) {
    if (fval == 0.0) {
      full_loop_B.penaltyParamTrial = 1.0;
    } else {
      full_loop_B.penaltyParamTrial = 1.5;
    }

    full_loop_B.penaltyParamTrial = full_loop_B.penaltyParamTrial * qpval /
      linearizedConstrViolPrev;
  }

  if (full_loop_B.penaltyParamTrial < obj->penaltyParam) {
    obj->phi = full_loop_B.penaltyParamTrial * constrViolationEq + fval;
    if ((full_loop_B.penaltyParamTrial * obj->initConstrViolationEq +
         obj->initFval) - obj->phi > static_cast<real_T>(obj->nPenaltyDecreases)
        * obj->threshold) {
      obj->nPenaltyDecreases++;
      if ((obj->nPenaltyDecreases << 1) > sqpiter) {
        obj->threshold *= 10.0;
      }

      if (full_loop_B.penaltyParamTrial > 1.0E-10) {
        obj->penaltyParam = full_loop_B.penaltyParamTrial;
      } else {
        obj->penaltyParam = 1.0E-10;
      }
    } else {
      obj->phi = obj->penaltyParam * constrViolationEq + fval;
    }
  } else {
    if (!(full_loop_B.penaltyParamTrial > 1.0E-10)) {
      full_loop_B.penaltyParamTrial = 1.0E-10;
    }

    obj->penaltyParam = full_loop_B.penaltyParamTrial;
    obj->phi = full_loop_B.penaltyParamTrial * constrViolationEq + fval;
  }

  constrViolationEq = qpval - obj->penaltyParam * constrViolationEq;
  if (constrViolationEq < 0.0) {
    obj->phiPrimePlus = constrViolationEq;
  } else {
    obj->phiPrimePlus = 0.0;
  }
}

static void removeActiveSlackLowerBounds_p(int32_T nActiveLBArtificial,
  s2CPTVnVyv153Hb6bxlki6F_full__T *TrialState, const
  sH6xx18cQHI5sgA7Ajla4nE_full__T *WorkingSet, sH6xx18cQHI5sgA7Ajla4nE_full__T
  *b_WorkingSet)
{
  int32_T mFiniteLBOrig;
  int32_T idx;
  real_T tmp;
  int32_T tmp_tmp;
  *b_WorkingSet = *WorkingSet;
  mFiniteLBOrig = WorkingSet->sizes[3] - (WorkingSet->sizes[1] << 1);
  idx = WorkingSet->nActiveConstr - 1;
  while ((idx + 1 > WorkingSet->sizes[1]) && (nActiveLBArtificial > 0)) {
    if ((b_WorkingSet->Wid[idx] == 4) && (b_WorkingSet->Wlocalidx[idx] >
         mFiniteLBOrig)) {
      tmp_tmp = b_WorkingSet->nActiveConstr - 1;
      tmp = TrialState->lambda[tmp_tmp];
      TrialState->lambda[tmp_tmp] = 0.0;
      TrialState->lambda[idx] = tmp;
      full_loop_removeConstr_p(b_WorkingSet, idx + 1);
      nActiveLBArtificial--;
    }

    idx--;
  }
}

static void full_loop_setQuadratic_p(sJdVcLKPgejLYHLePKb6F6D_full__T *obj,
  int32_T NumVars)
{
  obj->hasLinear = true;
  obj->nvar = NumVars;
  obj->objtype = 3;
}

static int32_T full_loop_ixamax_p4(int32_T n, const real_T x[19])
{
  int32_T idxmax;
  int32_T ix;
  real_T smax;
  real_T s;
  int32_T k;
  if (n < 1) {
    idxmax = 0;
  } else {
    idxmax = 1;
    if (n > 1) {
      ix = 0;
      smax = fabs(x[0]);
      for (k = 2; k <= n; k++) {
        ix++;
        s = fabs(x[ix]);
        if (s > smax) {
          idxmax = k;
          smax = s;
        }
      }
    }
  }

  return idxmax;
}

static int32_T full_loop_ixamax_p(int32_T n, const real_T x[21])
{
  int32_T idxmax;
  int32_T ix;
  real_T smax;
  real_T s;
  int32_T k;
  if (n < 1) {
    idxmax = 0;
  } else {
    idxmax = 1;
    if (n > 1) {
      ix = 0;
      smax = fabs(x[0]);
      for (k = 2; k <= n; k++) {
        ix++;
        s = fabs(x[ix]);
        if (s > smax) {
          idxmax = k;
          smax = s;
        }
      }
    }
  }

  return idxmax;
}

static void full_loop_relaxed_p(const real_T Hessian[64], const real_T grad[21],
  const s2CPTVnVyv153Hb6bxlki6F_full__T *TrialState,
  s6ICcRyulWOFjNCN0ll7VsE_full__T *MeritFunction, const
  sVTYnQ9ljvmk9dLse9XvTT_full_l_T *memspace, const
  sH6xx18cQHI5sgA7Ajla4nE_full__T *WorkingSet, const
  snaQeDJ4fX7UykrKyr5M8jC_full__T *QRManager, const
  snl99C5je2zMbU5SzygoX6F_full__T *CholManager, const
  sJdVcLKPgejLYHLePKb6F6D_full__T *QPObjective, s1TgE9KstXgkd2qJxO1bF4F_full__T *
  qpoptions, real_T b_Hessian[64], s2CPTVnVyv153Hb6bxlki6F_full__T *b_TrialState,
  sVTYnQ9ljvmk9dLse9XvTT_full_l_T *b_memspace, sH6xx18cQHI5sgA7Ajla4nE_full__T
  *b_WorkingSet, snaQeDJ4fX7UykrKyr5M8jC_full__T *b_QRManager,
  snl99C5je2zMbU5SzygoX6F_full__T *b_CholManager,
  sJdVcLKPgejLYHLePKb6F6D_full__T *b_QPObjective)
{
  boolean_T isAeqActive;
  memcpy(&b_Hessian[0], &Hessian[0], sizeof(real_T) << 6U);
  full_loop_B.nVarOrig = WorkingSet->nVar - 1;
  full_loop_B.mEq_n = WorkingSet->sizes[1] - 1;
  full_loop_B.beta = 0.0;
  for (full_loop_B.temp_p = 0; full_loop_B.temp_p <= full_loop_B.nVarOrig;
       full_loop_B.temp_p++) {
    full_loop_B.beta += Hessian[(full_loop_B.temp_p << 3) + full_loop_B.temp_p];
  }

  full_loop_B.beta /= static_cast<real_T>(WorkingSet->nVar);
  if (TrialState->sqpIterations <= 1) {
    full_loop_B.rho = fabs(grad[full_loop_ixamax_p(QPObjective->nvar, grad) - 1]);
    if ((1.0 > full_loop_B.rho) || rtIsNaN(full_loop_B.rho)) {
      full_loop_B.rho = 1.0;
    }

    full_loop_B.rho *= 100.0;
  } else {
    full_loop_B.rho = fabs(TrialState->lambdasqp[full_loop_ixamax_p4
      (WorkingSet->mConstr, TrialState->lambdasqp) - 1]);
  }

  full_loop_setProblemType(WorkingSet, 2, &full_loop_B.c_WorkingSet);
  *b_TrialState = *TrialState;
  full_loop_B.c_memspace = *memspace;
  full__assignResidualsToXSlack_p(WorkingSet->nVar, &full_loop_B.c_WorkingSet,
    b_TrialState, &full_loop_B.c_memspace);
  full_loop_B.temp_p = qpoptions->MaxIterations;
  qpoptions->MaxIterations = (qpoptions->MaxIterations +
    full_loop_B.c_WorkingSet.nVar) - WorkingSet->nVar;
  *b_QPObjective = *QPObjective;
  full_loop_setRegularized_p(b_QPObjective, WorkingSet->nVar, full_loop_B.beta,
    full_loop_B.rho);
  *b_CholManager = *CholManager;
  full_loop_B.qpoptions = *qpoptions;
  full_loop_B.qpoptions_e = *qpoptions;
  full_loop_driver_p43(Hessian, grad, b_TrialState, &full_loop_B.c_memspace,
                       &full_loop_B.c_WorkingSet, QRManager, b_CholManager,
                       b_QPObjective, &full_loop_B.qpoptions,
                       &full_loop_B.qpoptions_e, &full_loop_B.d_memspace,
                       &full_loop_B.d_WorkingSet, b_QRManager);
  qpoptions->MaxIterations = full_loop_B.temp_p;
  full_findActiveSlackLowerBounds(&full_loop_B.d_memspace,
    &full_loop_B.d_WorkingSet, &full_loop_B.temp_p,
    full_loop_B.e_memspace_workspace_double,
    full_loop_B.e_memspace_workspace_int, b_memspace->workspace_sort);
  memcpy(&b_memspace->workspace_int[0], &full_loop_B.e_memspace_workspace_int[0],
         21U * sizeof(int32_T));
  if (b_TrialState->state != -6) {
    full_loop_B.nVarOrig = (full_loop_B.d_WorkingSet.nVarMax - WorkingSet->nVar)
      - 1;
    full_loo_updatePenaltyParam_p43(MeritFunction, b_TrialState->sqpFval,
      b_TrialState->cEq, WorkingSet->sizes[1], b_TrialState->sqpIterations,
      (b_TrialState->fstar - full_loop_B.rho * full_loop_xasum
       (full_loop_B.nVarOrig, b_TrialState->xstar, WorkingSet->nVar + 1)) -
      full_loop_B.beta / 2.0 * full_loop_xdot(full_loop_B.nVarOrig,
      b_TrialState->xstar, WorkingSet->nVar + 1, b_TrialState->xstar,
      WorkingSet->nVar + 1), b_TrialState->xstar, WorkingSet->nVar + 1,
      (WorkingSet->nVarMax - WorkingSet->nVar) - 1);
    full_loop_B.iEq0 = full_loop_B.d_WorkingSet.isActiveIdx[1] - 2;
    for (full_loop_B.nVarOrig = 0; full_loop_B.nVarOrig <= full_loop_B.mEq_n;
         full_loop_B.nVarOrig++) {
      full_loop_B.iIneqEnd = full_loop_B.nVarOrig + 1;
      if ((full_loop_B.e_memspace_workspace_int[full_loop_B.iIneqEnd - 1] != 0) &&
          (full_loop_B.e_memspace_workspace_int[full_loop_B.iIneqEnd +
           full_loop_B.mEq_n] != 0)) {
        isAeqActive = true;
      } else {
        isAeqActive = false;
      }

      full_loop_B.iIneqEnd += full_loop_B.iEq0;
      b_TrialState->lambda[full_loop_B.iIneqEnd] *= static_cast<real_T>
        (isAeqActive);
    }

    full_loop_B.iEq0 = full_loop_B.d_WorkingSet.isActiveIdx[2];
    full_loop_B.iIneqEnd = full_loop_B.d_WorkingSet.nActiveConstr;
    for (full_loop_B.nVarOrig = full_loop_B.iEq0; full_loop_B.nVarOrig <=
         full_loop_B.iIneqEnd; full_loop_B.nVarOrig++) {
      if (full_loop_B.d_WorkingSet.Wid[full_loop_B.nVarOrig - 1] == 3) {
        b_TrialState->lambda[full_loop_B.nVarOrig - 1] *= static_cast<real_T>
          (full_loop_B.e_memspace_workspace_int[(((full_loop_B.mEq_n + 1) << 1)
            + full_loop_B.d_WorkingSet.Wlocalidx[full_loop_B.nVarOrig - 1]) - 1]);
      }
    }
  }

  removeActiveSlackLowerBounds_p(full_loop_B.temp_p, b_TrialState,
    &full_loop_B.d_WorkingSet, &full_loop_B.c_WorkingSet);
  full_loop_setQuadratic_p(b_QPObjective, WorkingSet->nVar);
  full_loop_setProblemType(&full_loop_B.c_WorkingSet, 3, b_WorkingSet);
  full_loop_sortLambdaQP_p(b_TrialState->lambda, b_WorkingSet->nActiveConstr,
    b_WorkingSet->sizes, b_WorkingSet->isActiveIdx, b_WorkingSet->Wid,
    b_WorkingSet->Wlocalidx, full_loop_B.e_memspace_workspace_double,
    b_memspace->workspace_double);
}

static void full_loop_BFGSReset(const real_T Hessian[64], const real_T grad[21],
  const real_T searchDir[21], real_T b_Hessian[64])
{
  real_T nrmDirInf;
  int32_T iH0;
  int32_T b_idx;
  int32_T n;
  real_T u1;
  memcpy(&b_Hessian[0], &Hessian[0], sizeof(real_T) << 6U);
  full_loop_B.nrmGradInf = 0.0;
  nrmDirInf = 1.0;
  for (b_idx = 0; b_idx < 8; b_idx++) {
    u1 = fabs(grad[b_idx]);
    if ((!(full_loop_B.nrmGradInf > u1)) && (!rtIsNaN(u1))) {
      full_loop_B.nrmGradInf = u1;
    }

    u1 = fabs(searchDir[b_idx]);
    if ((!(nrmDirInf > u1)) && (!rtIsNaN(u1))) {
      nrmDirInf = u1;
    }
  }

  full_loop_B.nrmGradInf /= nrmDirInf;
  if ((2.2204460492503131E-16 > full_loop_B.nrmGradInf) || rtIsNaN
      (full_loop_B.nrmGradInf)) {
    full_loop_B.nrmGradInf = 2.2204460492503131E-16;
  }

  for (b_idx = 0; b_idx < 8; b_idx++) {
    iH0 = b_idx << 3;
    n = b_idx - 1;
    if (0 <= n) {
      memset(&b_Hessian[iH0], 0, (((n + iH0) - iH0) + 1) * sizeof(real_T));
    }

    b_Hessian[b_idx + iH0] = full_loop_B.nrmGradInf;
    iH0 = (iH0 + b_idx) + 1;
    n = 6 - b_idx;
    if (0 <= n) {
      memset(&b_Hessian[iH0], 0, (((n + iH0) - iH0) + 1) * sizeof(real_T));
    }
  }
}

static void full_loop_step_p4(int32_T STEP_TYPE, const real_T Hessian[64],
  s2CPTVnVyv153Hb6bxlki6F_full__T *TrialState, s6ICcRyulWOFjNCN0ll7VsE_full__T
  *MeritFunction, sVTYnQ9ljvmk9dLse9XvTT_full_l_T *memspace,
  sH6xx18cQHI5sgA7Ajla4nE_full__T *WorkingSet, snaQeDJ4fX7UykrKyr5M8jC_full__T
  *QRManager, snl99C5je2zMbU5SzygoX6F_full__T *CholManager,
  sJdVcLKPgejLYHLePKb6F6D_full__T *QPObjective, s1TgE9KstXgkd2qJxO1bF4F_full__T *
  qpoptions, boolean_T *stepSuccess, int32_T *b_STEP_TYPE, real_T b_Hessian[64])
{
  int32_T exitg1;
  boolean_T guard1 = false;
  memcpy(&b_Hessian[0], &Hessian[0], sizeof(real_T) << 6U);
  *b_STEP_TYPE = STEP_TYPE;
  *stepSuccess = true;
  full_loop_B.nVar_c = WorkingSet->nVar - 1;
  for (full_loop_B.b_k = 0; full_loop_B.b_k <= full_loop_B.nVar_c;
       full_loop_B.b_k++) {
    if (STEP_TYPE != 3) {
      TrialState->xstar[full_loop_B.b_k] = TrialState->xstarsqp[full_loop_B.b_k];
    } else {
      TrialState->searchDir[full_loop_B.b_k] = TrialState->xstar[full_loop_B.b_k];
    }
  }

  do {
    exitg1 = 0;
    guard1 = false;
    switch (*b_STEP_TYPE) {
     case 1:
      memcpy(&full_loop_B.b_Hessian[0], &b_Hessian[0], sizeof(real_T) << 6);
      full_loop_B.memspace_j = *memspace;
      full_loop_B.WorkingSet_g1 = *WorkingSet;
      full_loop_B.QRManager_c = *QRManager;
      full_loop_B.CholManager_d = *CholManager;
      full_loop_B.QPObjective_p = *QPObjective;
      full_loop_normal_p(full_loop_B.b_Hessian, TrialState->grad, TrialState,
                         MeritFunction, &full_loop_B.memspace_j,
                         &full_loop_B.WorkingSet_g1, &full_loop_B.QRManager_c,
                         &full_loop_B.CholManager_d, &full_loop_B.QPObjective_p,
                         qpoptions, b_Hessian, &full_loop_B.c_TrialState_n,
                         memspace, WorkingSet, QRManager, CholManager,
                         QPObjective);
      *TrialState = full_loop_B.c_TrialState_n;
      if ((full_loop_B.c_TrialState_n.state <= 0) &&
          (full_loop_B.c_TrialState_n.state != -6)) {
        *b_STEP_TYPE = 2;
      } else {
        memcpy(&TrialState->delta_x[0], &full_loop_B.c_TrialState_n.delta_x[0],
               21U * sizeof(real_T));
        if (0 <= full_loop_B.nVar_c) {
          memcpy(&TrialState->delta_x[0], &full_loop_B.c_TrialState_n.xstar[0],
                 (full_loop_B.nVar_c + 1) * sizeof(real_T));
        }

        guard1 = true;
      }
      break;

     case 2:
      memcpy(&full_loop_B.b_Hessian[0], &b_Hessian[0], sizeof(real_T) << 6);
      full_loop_B.memspace_j = *memspace;
      full_loop_B.WorkingSet_g1 = *WorkingSet;
      full_loop_B.QRManager_c = *QRManager;
      full_loop_B.CholManager_d = *CholManager;
      full_loop_B.QPObjective_p = *QPObjective;
      full_loop_relaxed_p(full_loop_B.b_Hessian, TrialState->grad, TrialState,
                          MeritFunction, &full_loop_B.memspace_j,
                          &full_loop_B.WorkingSet_g1, &full_loop_B.QRManager_c,
                          &full_loop_B.CholManager_d, &full_loop_B.QPObjective_p,
                          qpoptions, b_Hessian, &full_loop_B.c_TrialState_n,
                          memspace, WorkingSet, QRManager, CholManager,
                          QPObjective);
      *TrialState = full_loop_B.c_TrialState_n;
      memcpy(&TrialState->delta_x[0], &full_loop_B.c_TrialState_n.delta_x[0],
             21U * sizeof(real_T));
      if (0 <= full_loop_B.nVar_c) {
        memcpy(&TrialState->delta_x[0], &full_loop_B.c_TrialState_n.xstar[0],
               (full_loop_B.nVar_c + 1) * sizeof(real_T));
      }

      guard1 = true;
      break;

     default:
      full_loop_B.c_TrialState_n = *TrialState;
      memcpy(&full_loop_B.b_Hessian[0], &b_Hessian[0], sizeof(real_T) << 6);
      full_loop_B.memspace_j = *memspace;
      full_loop_B.WorkingSet_g1 = *WorkingSet;
      full_loop_B.QRManager_c = *QRManager;
      full_loop_B.CholManager_d = *CholManager;
      full_loop_B.QPObjective_p = *QPObjective;
      full_loop_soc_p(full_loop_B.b_Hessian, TrialState->grad,
                      &full_loop_B.c_TrialState_n, &full_loop_B.memspace_j,
                      &full_loop_B.WorkingSet_g1, &full_loop_B.QRManager_c,
                      &full_loop_B.CholManager_d, &full_loop_B.QPObjective_p,
                      qpoptions, stepSuccess, b_Hessian, memspace, WorkingSet,
                      QRManager, CholManager, QPObjective);
      *TrialState = full_loop_B.c_TrialState_n;
      if ((*stepSuccess) && (full_loop_B.c_TrialState_n.state != -6)) {
        for (full_loop_B.b_k = 0; full_loop_B.b_k <= full_loop_B.nVar_c;
             full_loop_B.b_k++) {
          TrialState->delta_x[full_loop_B.b_k] =
            full_loop_B.c_TrialState_n.xstar[full_loop_B.b_k] +
            full_loop_B.c_TrialState_n.socDirection[full_loop_B.b_k];
        }
      }

      guard1 = true;
      break;
    }

    if (guard1) {
      if (TrialState->state != -6) {
        exitg1 = 1;
      } else {
        memcpy(&full_loop_B.b_Hessian[0], &b_Hessian[0], sizeof(real_T) << 6);
        full_loop_BFGSReset(full_loop_B.b_Hessian, TrialState->grad,
                            TrialState->xstar, b_Hessian);
      }
    }
  } while (exitg1 == 0);
}

static void full_loop_evalObjAndConstr_p(KickIn_full_loop_T
  **obj_objfun_tunableEnvironment, const real_T x[8], real_T *fval, int32_T
  *status)
{
  full_loop_computeObjective_(obj_objfun_tunableEnvironment, x, fval, status);
  if (*status == 1) {
    *status = 1;
  }
}

static void full_computeLinearResiduals_p43(const real_T x[8], int32_T nVar,
  real_T workspaceEq[6], int32_T mLinEq, const real_T AeqT[126], const real_T
  beq[6])
{
  int32_T iy;
  int32_T ix;
  int32_T b_iy;
  int32_T b;
  int32_T d;
  int32_T ia;
  if (mLinEq > 0) {
    if (0 <= mLinEq - 1) {
      memcpy(&workspaceEq[0], &beq[0], mLinEq * sizeof(real_T));
    }

    if (nVar != 0) {
      for (b_iy = 0; b_iy < mLinEq; b_iy++) {
        workspaceEq[b_iy] = -workspaceEq[b_iy];
      }

      iy = 0;
      b = (mLinEq - 1) * 21;
      for (b_iy = 1; b_iy <= b + 1; b_iy += 21) {
        ix = 0;
        full_loop_B.c_g4 = 0.0;
        d = b_iy + nVar;
        for (ia = b_iy; ia < d; ia++) {
          full_loop_B.c_g4 += AeqT[ia - 1] * x[ix];
          ix++;
        }

        workspaceEq[iy] += full_loop_B.c_g4;
        iy++;
      }
    }
  }
}

static real_T full_loop_computeMeritFcn(real_T obj_penaltyParam, real_T fval,
  const real_T Ceq_workspace[6], int32_T mEq, boolean_T evalWellDefined)
{
  real_T val;
  real_T constrViolationEq;
  int32_T b_k;
  if (evalWellDefined) {
    constrViolationEq = 0.0;
    if (mEq >= 1) {
      for (b_k = 0; b_k < mEq; b_k++) {
        constrViolationEq += fabs(Ceq_workspace[b_k]);
      }
    }

    val = obj_penaltyParam * constrViolationEq + fval;
  } else {
    val = (rtInf);
  }

  return val;
}

static void full_loop_linesearch_p(boolean_T evalWellDefined, const real_T beq[6],
  const sH6xx18cQHI5sgA7Ajla4nE_full__T *WorkingSet,
  s2CPTVnVyv153Hb6bxlki6F_full__T *TrialState, const
  s6ICcRyulWOFjNCN0ll7VsE_full__T *MeritFunction, const
  s_8jIp3wBW8W9AJZ7lDTkICE_full_T FcnEvaluator, boolean_T socTaken, real_T
  *alpha, int32_T *exitflag, boolean_T *b_evalWellDefined)
{
  boolean_T tooSmallX;
  int32_T idx;
  int32_T i;
  int32_T exitg1;
  boolean_T exitg2;
  *b_evalWellDefined = evalWellDefined;
  full_loop_B.nVar_l = WorkingSet->nVar - 1;
  full_loop_B.mEq_k = TrialState->mEq;
  *alpha = 1.0;
  *exitflag = 1;
  full_loop_B.phi_alpha = MeritFunction->phiFullStep;
  if (0 <= full_loop_B.nVar_l) {
    memcpy(&TrialState->searchDir[0], &TrialState->delta_x[0],
           (full_loop_B.nVar_l + 1) * sizeof(real_T));
  }

  do {
    exitg1 = 0;
    if (TrialState->FunctionEvaluations < 800) {
      if ((*b_evalWellDefined) && (full_loop_B.phi_alpha <= *alpha * 0.0001 *
           MeritFunction->phiPrimePlus + MeritFunction->phi)) {
        exitg1 = 1;
      } else {
        *alpha *= 0.7;
        for (i = 0; i <= full_loop_B.nVar_l; i++) {
          TrialState->delta_x[i] = *alpha * TrialState->xstar[i];
        }

        if (socTaken) {
          full_loop_B.phi_alpha = *alpha * *alpha;
          if ((full_loop_B.nVar_l + 1 < 1) || (full_loop_B.phi_alpha == 0.0)) {
          } else {
            for (i = 0; i <= full_loop_B.nVar_l; i++) {
              TrialState->delta_x[i] += full_loop_B.phi_alpha *
                TrialState->socDirection[i];
            }
          }
        }

        tooSmallX = true;
        i = 1;
        exitg2 = false;
        while ((!exitg2) && (i - 1 <= full_loop_B.nVar_l)) {
          idx = i - 1;
          full_loop_B.phi_alpha = fabs(TrialState->xstarsqp[idx]);
          if ((1.0 > full_loop_B.phi_alpha) || rtIsNaN(full_loop_B.phi_alpha)) {
            full_loop_B.phi_alpha = 1.0;
          }

          if (1.0E-6 * full_loop_B.phi_alpha <= fabs(TrialState->delta_x[idx]))
          {
            tooSmallX = false;
            exitg2 = true;
          } else {
            i++;
          }
        }

        if (tooSmallX) {
          *exitflag = -2;
          exitg1 = 1;
        } else {
          for (i = 0; i <= full_loop_B.nVar_l; i++) {
            TrialState->xstarsqp[i] = TrialState->xstarsqp_old[i] +
              TrialState->delta_x[i];
          }

          for (i = 0; i < 6; i++) {
            full_loop_B.d_p[i] = TrialState->cEq[i];
          }

          full_loop_computeObjective_(&FcnEvaluator.objfun.tunableEnvironment,
            TrialState->xstarsqp, &full_loop_B.phi_alpha, &idx);
          if (idx == 1) {
            idx = 1;
          }

          TrialState->sqpFval = full_loop_B.phi_alpha;
          full_computeLinearResiduals_p43(TrialState->xstarsqp,
            full_loop_B.nVar_l + 1, full_loop_B.d_p, full_loop_B.mEq_k,
            WorkingSet->Aeq, beq);
          for (i = 0; i < 6; i++) {
            TrialState->cEq[i] = full_loop_B.d_p[i];
          }

          TrialState->FunctionEvaluations++;
          *b_evalWellDefined = (idx == 1);
          if (*b_evalWellDefined) {
            full_loop_B.constrViolationEq = 0.0;
            if (full_loop_B.mEq_k >= 1) {
              for (i = 0; i < full_loop_B.mEq_k; i++) {
                full_loop_B.constrViolationEq += fabs(full_loop_B.d_p[i]);
              }
            }

            full_loop_B.phi_alpha += MeritFunction->penaltyParam *
              full_loop_B.constrViolationEq;
          } else {
            full_loop_B.phi_alpha = (rtInf);
          }
        }
      }
    } else {
      *exitflag = 0;
      exitg1 = 1;
    }
  } while (exitg1 == 0);
}

static void full_loop_revertSolution(const s2CPTVnVyv153Hb6bxlki6F_full__T *obj,
  s2CPTVnVyv153Hb6bxlki6F_full__T *b_obj)
{
  int32_T i;
  int32_T b_k;
  *b_obj = *obj;
  b_obj->sqpFval = obj->sqpFval_old;
  for (b_k = 0; b_k < 8; b_k++) {
    b_obj->xstarsqp[b_k] = obj->xstarsqp[b_k];
    b_obj->xstarsqp[b_k] = obj->xstarsqp_old[b_k];
  }

  b_k = obj->mEq - 1;
  for (i = 0; i < 6; i++) {
    b_obj->cEq[i] = obj->cEq[i];
  }

  if (0 <= b_k) {
    memcpy(&b_obj->cEq[0], &obj->cEq_old[0], (b_k + 1) * sizeof(real_T));
  }
}

static real_T full_loo_computePrimalFeasError(int32_T mLinEq, const real_T cEq[6])
{
  real_T feasError;
  int32_T b_idx;
  real_T u1;
  feasError = 0.0;
  for (b_idx = 0; b_idx < mLinEq; b_idx++) {
    u1 = fabs(cEq[b_idx]);
    if ((!(feasError > u1)) && (!rtIsNaN(u1))) {
      feasError = u1;
    }
  }

  return feasError;
}

static void full_loop_computeGradLag_p(const real_T workspace[441], int32_T nVar,
  const real_T grad[21], int32_T mEq, const real_T AeqTrans[126], const int32_T
  finiteLB[21], int32_T mLB, const real_T lambda[19], real_T b_workspace[441])
{
  int32_T ix;
  int32_T iy;
  int32_T b;
  int32_T iac;
  int32_T d;
  int32_T ia;
  memcpy(&b_workspace[0], &workspace[0], 441U * sizeof(real_T));
  if (0 <= nVar - 1) {
    memcpy(&b_workspace[0], &grad[0], nVar * sizeof(real_T));
  }

  if ((nVar == 0) || (mEq == 0)) {
  } else {
    ix = 0;
    b = (mEq - 1) * 21;
    for (iac = 1; iac <= b + 1; iac += 21) {
      iy = 0;
      d = iac + nVar;
      for (ia = iac; ia < d; ia++) {
        b_workspace[iy] += AeqTrans[ia - 1] * lambda[ix];
        iy++;
      }

      ix++;
    }
  }

  ix = mEq;
  for (b = 0; b < mLB; b++) {
    b_workspace[finiteLB[b] - 1] -= lambda[ix];
    ix++;
  }
}

static void full_loo_computeDualFeasError_p(int32_T nVar, const real_T gradLag
  [441], boolean_T *gradOK, real_T *val)
{
  int32_T idx;
  int32_T b_idx;
  real_T u1;
  boolean_T exitg1;
  *gradOK = true;
  *val = 0.0;
  b_idx = 1;
  exitg1 = false;
  while ((!exitg1) && (b_idx - 1 <= nVar - 1)) {
    idx = b_idx - 1;
    *gradOK = ((!rtIsInf(gradLag[idx])) && (!rtIsNaN(gradLag[idx])));
    if (!*gradOK) {
      exitg1 = true;
    } else {
      u1 = fabs(gradLag[idx]);
      if ((!(*val > u1)) && (!rtIsNaN(u1))) {
        *val = u1;
      }

      b_idx++;
    }
  }
}

static boolean_T full_loop_isDeltaXTooSmall(const real_T xCurrent[8], const
  real_T delta_x[21], int32_T nVar)
{
  boolean_T tf;
  int32_T idx;
  int32_T b_idx;
  real_T u1;
  boolean_T exitg1;
  tf = true;
  b_idx = 1;
  exitg1 = false;
  while ((!exitg1) && (b_idx - 1 <= nVar - 1)) {
    idx = b_idx - 1;
    u1 = fabs(xCurrent[idx]);
    if ((1.0 > u1) || rtIsNaN(u1)) {
      u1 = 1.0;
    }

    if (1.0E-6 * u1 <= fabs(delta_x[idx])) {
      tf = false;
      exitg1 = true;
    } else {
      b_idx++;
    }
  }

  return tf;
}

static void full_loop_computeLambdaLSQ_p(int32_T nVar, int32_T mConstr, const
  snaQeDJ4fX7UykrKyr5M8jC_full__T *QRManager, const real_T ATwset[399], const
  real_T grad[21], real_T lambdaLSQ[19], const real_T workspace[441],
  snaQeDJ4fX7UykrKyr5M8jC_full__T *b_QRManager, real_T b_workspace[441])
{
  if (0 <= mConstr - 1) {
    memset(&lambdaLSQ[0], 0, mConstr * sizeof(real_T));
  }

  *b_QRManager = *QRManager;
  full_loop_factorQRE_p4(b_QRManager, ATwset, nVar, mConstr);
  full_loop_computeQ__p(b_QRManager, b_QRManager->mrows);
  if (nVar > mConstr) {
    full_loop_B.fullRank_R = nVar;
  } else {
    full_loop_B.fullRank_R = mConstr;
  }

  full_loop_B.tol_f = static_cast<real_T>(full_loop_B.fullRank_R) *
    2.2204460492503131E-16;
  if (1.4901161193847656E-8 < full_loop_B.tol_f) {
    full_loop_B.tol_f = 1.4901161193847656E-8;
  }

  full_loop_B.tol_f *= fabs(b_QRManager->QR[0]);
  if (nVar < mConstr) {
    full_loop_B.fullRank_R = nVar;
  } else {
    full_loop_B.fullRank_R = mConstr;
  }

  full_loop_B.rankR = 0;
  full_loop_B.iQR_diag = 0;
  while ((full_loop_B.rankR < full_loop_B.fullRank_R) && (fabs(b_QRManager->
           QR[full_loop_B.iQR_diag]) > full_loop_B.tol_f)) {
    full_loop_B.rankR++;
    full_loop_B.iQR_diag += 22;
  }

  full_loop_xgemv(nVar, nVar, b_QRManager->Q, grad, workspace, b_workspace);
  if (full_loop_B.rankR != 0) {
    for (full_loop_B.iQR_diag = full_loop_B.rankR; full_loop_B.iQR_diag >= 1;
         full_loop_B.iQR_diag--) {
      full_loop_B.jjA = ((full_loop_B.iQR_diag - 1) * 21 + full_loop_B.iQR_diag)
        - 1;
      b_workspace[full_loop_B.iQR_diag - 1] /= b_QRManager->QR[full_loop_B.jjA];
      full_loop_B.b_o = full_loop_B.iQR_diag - 2;
      for (full_loop_B.b_i_l = 0; full_loop_B.b_i_l <= full_loop_B.b_o;
           full_loop_B.b_i_l++) {
        full_loop_B.i_oo = full_loop_B.b_i_l + 1;
        full_loop_B.ix_f = (full_loop_B.iQR_diag - full_loop_B.i_oo) - 1;
        b_workspace[full_loop_B.ix_f] -= b_workspace[full_loop_B.iQR_diag - 1] *
          b_QRManager->QR[full_loop_B.jjA - full_loop_B.i_oo];
      }
    }
  }

  if (mConstr < full_loop_B.fullRank_R) {
    full_loop_B.fullRank_R = mConstr;
  }

  full_loop_B.rankR = full_loop_B.fullRank_R - 1;
  for (full_loop_B.fullRank_R = 0; full_loop_B.fullRank_R <= full_loop_B.rankR;
       full_loop_B.fullRank_R++) {
    lambdaLSQ[b_QRManager->jpvt[full_loop_B.fullRank_R] - 1] =
      b_workspace[full_loop_B.fullRank_R];
  }
}

static void full_loop_test_exit_p43(boolean_T Flags_fevalOK, boolean_T
  Flags_stepAccepted, boolean_T Flags_failedLineSearch, int32_T Flags_stepType,
  sVTYnQ9ljvmk9dLse9XvTT_full_l_T *memspace, s6ICcRyulWOFjNCN0ll7VsE_full__T
  *MeritFunction, const sH6xx18cQHI5sgA7Ajla4nE_full__T *WorkingSet, const
  s2CPTVnVyv153Hb6bxlki6F_full__T *TrialState, snaQeDJ4fX7UykrKyr5M8jC_full__T
  *QRManager, s7RdrPWkr8UPAUyTdDJkLaG_full__T *b_Flags,
  s2CPTVnVyv153Hb6bxlki6F_full__T *b_TrialState)
{
  boolean_T isFeasible;
  boolean_T b;
  boolean_T guard1 = false;
  *b_TrialState = *TrialState;
  b_Flags->fevalOK = Flags_fevalOK;
  b_Flags->stepAccepted = Flags_stepAccepted;
  b_Flags->failedLineSearch = Flags_failedLineSearch;
  b_Flags->stepType = Flags_stepType;
  full_loop_B.mEq_f = WorkingSet->sizes[1];
  full_loop_B.mLambda = (WorkingSet->sizes[1] + WorkingSet->sizes[3]) - 1;
  memcpy(&b_TrialState->gradLag[0], &TrialState->gradLag[0], 21U * sizeof(real_T));
  full_loop_computeGradLag_p4(b_TrialState->gradLag, WorkingSet->nVar,
    TrialState->grad, WorkingSet->sizes[1], WorkingSet->Aeq, WorkingSet->indexLB,
    WorkingSet->sizes[3], TrialState->lambdasqp);
  full_loop_B.optimRelativeFactor = fabs(TrialState->grad[full_loop_ixamax_p
    (WorkingSet->nVar, TrialState->grad) - 1]);
  if ((1.0 > full_loop_B.optimRelativeFactor) || rtIsNaN
      (full_loop_B.optimRelativeFactor)) {
    full_loop_B.optimRelativeFactor = 1.0;
  }

  if (!full_loop_isfinite(full_loop_B.optimRelativeFactor)) {
    full_loop_B.optimRelativeFactor = 1.0;
  }

  MeritFunction->nlpPrimalFeasError = full_loo_computePrimalFeasError
    (WorkingSet->sizes[1], TrialState->cEq);
  if (TrialState->sqpIterations == 0) {
    if ((1.0 > MeritFunction->nlpPrimalFeasError) || rtIsNaN
        (MeritFunction->nlpPrimalFeasError)) {
      MeritFunction->feasRelativeFactor = 1.0;
    } else {
      MeritFunction->feasRelativeFactor = MeritFunction->nlpPrimalFeasError;
    }
  }

  isFeasible = (MeritFunction->nlpPrimalFeasError <= 0.01 *
                MeritFunction->feasRelativeFactor);
  full_loop_computeDualFeasError(WorkingSet->nVar, b_TrialState->gradLag, &b,
    &full_loop_B.c_pt);
  b_Flags->gradOK = b;
  MeritFunction->nlpDualFeasError = full_loop_B.c_pt;
  if (!b) {
    b_Flags->done = true;
    if (isFeasible) {
      b_TrialState->sqpExitFlag = 2;
    } else {
      b_TrialState->sqpExitFlag = -2;
    }
  } else {
    MeritFunction->nlpComplError = 0.0;
    if (!(full_loop_B.c_pt > 0.0)) {
      full_loop_B.c_pt = 0.0;
    }

    MeritFunction->firstOrderOpt = full_loop_B.c_pt;
    if (TrialState->sqpIterations > 1) {
      memcpy(&full_loop_B.memspace_b[0], &memspace->workspace_double[0], 441U *
             sizeof(real_T));
      full_loop_computeGradLag_p(full_loop_B.memspace_b, WorkingSet->nVar,
        TrialState->grad, WorkingSet->sizes[1], WorkingSet->Aeq,
        WorkingSet->indexLB, WorkingSet->sizes[3], TrialState->lambdasqp_old,
        memspace->workspace_double);
      full_loo_computeDualFeasError_p(WorkingSet->nVar,
        memspace->workspace_double, &b, &full_loop_B.nlpDualFeasErrorTmp);
      if (full_loop_B.nlpDualFeasErrorTmp > 0.0) {
        full_loop_B.d1 = full_loop_B.nlpDualFeasErrorTmp;
      } else {
        full_loop_B.d1 = 0.0;
      }

      if (full_loop_B.d1 < full_loop_B.c_pt) {
        MeritFunction->nlpDualFeasError = full_loop_B.nlpDualFeasErrorTmp;
        MeritFunction->nlpComplError = 0.0;
        MeritFunction->firstOrderOpt = full_loop_B.d1;
        if (0 <= full_loop_B.mLambda) {
          memcpy(&b_TrialState->lambdasqp[0], &TrialState->lambdasqp_old[0],
                 (full_loop_B.mLambda + 1) * sizeof(real_T));
        }
      } else {
        if (0 <= full_loop_B.mLambda) {
          memcpy(&b_TrialState->lambdasqp_old[0], &TrialState->lambdasqp[0],
                 (full_loop_B.mLambda + 1) * sizeof(real_T));
        }
      }
    } else {
      if (0 <= full_loop_B.mLambda) {
        memcpy(&b_TrialState->lambdasqp_old[0], &TrialState->lambdasqp[0],
               (full_loop_B.mLambda + 1) * sizeof(real_T));
      }
    }

    if (isFeasible && (MeritFunction->nlpDualFeasError <= 0.01 *
                       full_loop_B.optimRelativeFactor)) {
      b_Flags->done = true;
      b_TrialState->sqpExitFlag = 1;
    } else {
      b_Flags->done = false;
      guard1 = false;
      if ((TrialState->sqpIterations > 0) && full_loop_isDeltaXTooSmall
          (TrialState->xstarsqp, TrialState->delta_x, WorkingSet->nVar)) {
        if (!isFeasible) {
          if (Flags_stepType != 2) {
            b_Flags->stepType = 2;
            b_Flags->failedLineSearch = false;
            b_Flags->stepAccepted = false;
            guard1 = true;
          } else {
            b_Flags->done = true;
            b_TrialState->sqpExitFlag = -2;
          }
        } else if (WorkingSet->nActiveConstr > 0) {
          memcpy(&b_TrialState->lambda[0], &TrialState->lambda[0], 19U * sizeof
                 (real_T));
          full_loop_B.QRManager_cv = *QRManager;
          full_loop_computeLambdaLSQ_p(WorkingSet->nVar,
            WorkingSet->nActiveConstr, &full_loop_B.QRManager_cv,
            WorkingSet->ATwset, TrialState->grad, b_TrialState->lambda,
            memspace->workspace_double, QRManager, full_loop_B.memspace_b);
          for (full_loop_B.idx_j = 1; full_loop_B.idx_j <= full_loop_B.mEq_f;
               full_loop_B.idx_j++) {
            b_TrialState->lambda[full_loop_B.idx_j - 1] = -b_TrialState->
              lambda[full_loop_B.idx_j - 1];
          }

          memcpy(&full_loop_B.f[0], &b_TrialState->lambda[0], 19U * sizeof
                 (real_T));
          full_loop_sortLambdaQP_p(full_loop_B.f, WorkingSet->nActiveConstr,
            WorkingSet->sizes, WorkingSet->isActiveIdx, WorkingSet->Wid,
            WorkingSet->Wlocalidx, full_loop_B.memspace_b, full_loop_B.g);
          memcpy(&b_TrialState->lambda[0], &full_loop_B.f[0], 19U * sizeof
                 (real_T));
          full_loop_computeGradLag_p(full_loop_B.g, WorkingSet->nVar,
            TrialState->grad, WorkingSet->sizes[1], WorkingSet->Aeq,
            WorkingSet->indexLB, WorkingSet->sizes[3], full_loop_B.f,
            memspace->workspace_double);
          full_loo_computeDualFeasError_p(WorkingSet->nVar,
            memspace->workspace_double, &isFeasible, &full_loop_B.c_pt);
          if (full_loop_B.c_pt <= 0.01 * full_loop_B.optimRelativeFactor) {
            MeritFunction->nlpDualFeasError = full_loop_B.c_pt;
            MeritFunction->nlpComplError = 0.0;
            if (full_loop_B.c_pt > 0.0) {
              MeritFunction->firstOrderOpt = full_loop_B.c_pt;
            } else {
              MeritFunction->firstOrderOpt = 0.0;
            }

            if (0 <= full_loop_B.mLambda) {
              memcpy(&b_TrialState->lambdasqp[0], &full_loop_B.f[0],
                     (full_loop_B.mLambda + 1) * sizeof(real_T));
            }

            b_Flags->done = true;
            b_TrialState->sqpExitFlag = 1;
          } else {
            b_Flags->done = true;
            b_TrialState->sqpExitFlag = 2;
          }
        } else {
          b_Flags->done = true;
          b_TrialState->sqpExitFlag = 2;
        }
      } else {
        guard1 = true;
      }

      if (guard1) {
        if (TrialState->sqpIterations >= 400) {
          b_Flags->done = true;
          b_TrialState->sqpExitFlag = 0;
        } else {
          if (TrialState->FunctionEvaluations >= 800) {
            b_Flags->done = true;
            b_TrialState->sqpExitFlag = 0;
          }
        }
      }
    }
  }
}

static void full_loop_computeDeltaLag_p(int32_T nVar, real_T workspace[21],
  const real_T grad[21], const real_T grad_old[21])
{
  int32_T b_i;
  for (b_i = 0; b_i < nVar; b_i++) {
    workspace[b_i] = grad[b_i];
    if (nVar >= 1) {
      workspace[b_i] += -grad_old[b_i];
    }
  }
}

static void full_loop_BFGSUpdate_p(int32_T nvar, const real_T Bk[64], const
  real_T sk[21], real_T yk[21], const real_T workspace[441], boolean_T *success,
  real_T b_Bk[64], real_T b_workspace[441])
{
  int32_T ix;
  int32_T iac;
  int32_T d;
  int32_T ia;
  int32_T jA;
  int32_T jy;
  real_T temp;
  memcpy(&b_Bk[0], &Bk[0], sizeof(real_T) << 6U);
  full_loop_B.dotSY = 0.0;
  if (nvar >= 1) {
    for (ix = 0; ix < nvar; ix++) {
      full_loop_B.dotSY += sk[ix] * yk[ix];
    }
  }

  memcpy(&b_workspace[0], &workspace[0], 441U * sizeof(real_T));
  if ((nvar == 0) || (nvar == 0)) {
  } else {
    if (0 <= nvar - 1) {
      memset(&b_workspace[0], 0, nvar * sizeof(real_T));
    }

    ix = 0;
    jA = (nvar - 1) << 3;
    for (iac = 1; iac <= jA + 1; iac += 8) {
      jy = 0;
      d = iac + nvar;
      for (ia = iac; ia < d; ia++) {
        b_workspace[jy] += Bk[ia - 1] * sk[ix];
        jy++;
      }

      ix++;
    }
  }

  full_loop_B.curvatureS = 0.0;
  if (nvar >= 1) {
    for (ix = 0; ix < nvar; ix++) {
      full_loop_B.curvatureS += sk[ix] * b_workspace[ix];
    }
  }

  if (full_loop_B.dotSY < 0.2 * full_loop_B.curvatureS) {
    full_loop_B.dotSY = 0.8 * full_loop_B.curvatureS / (full_loop_B.curvatureS -
      full_loop_B.dotSY);
    for (ix = 0; ix < nvar; ix++) {
      yk[ix] *= full_loop_B.dotSY;
    }

    full_loop_B.dotSY = 1.0 - full_loop_B.dotSY;
    if ((nvar < 1) || (full_loop_B.dotSY == 0.0)) {
    } else {
      for (ix = 0; ix < nvar; ix++) {
        yk[ix] += full_loop_B.dotSY * b_workspace[ix];
      }
    }

    full_loop_B.dotSY = 0.0;
    if (nvar >= 1) {
      for (ix = 0; ix < nvar; ix++) {
        full_loop_B.dotSY += sk[ix] * yk[ix];
      }
    }
  }

  if ((full_loop_B.curvatureS > 2.2204460492503131E-16) && (full_loop_B.dotSY >
       2.2204460492503131E-16)) {
    *success = true;
  } else {
    *success = false;
  }

  if (*success) {
    full_loop_B.curvatureS = -1.0 / full_loop_B.curvatureS;
    if (!(full_loop_B.curvatureS == 0.0)) {
      jA = 1;
      jy = 0;
      for (iac = 0; iac < nvar; iac++) {
        if (b_workspace[jy] != 0.0) {
          temp = b_workspace[jy] * full_loop_B.curvatureS;
          ix = 0;
          d = (nvar + jA) - 1;
          for (ia = jA; ia <= d; ia++) {
            b_Bk[ia - 1] += b_workspace[ix] * temp;
            ix++;
          }
        }

        jy++;
        jA += 8;
      }
    }

    full_loop_B.curvatureS = 1.0 / full_loop_B.dotSY;
    if (!(full_loop_B.curvatureS == 0.0)) {
      jA = 1;
      jy = 0;
      for (iac = 0; iac < nvar; iac++) {
        if (yk[jy] != 0.0) {
          temp = yk[jy] * full_loop_B.curvatureS;
          ix = 0;
          d = (nvar + jA) - 1;
          for (ia = jA; ia <= d; ia++) {
            b_Bk[ia - 1] += yk[ix] * temp;
            ix++;
          }
        }

        jy++;
        jA += 8;
      }
    }
  }
}

static void full_loop_driver_p4(const real_T beq[6],
  s2CPTVnVyv153Hb6bxlki6F_full__T *TrialState, const
  s6ICcRyulWOFjNCN0ll7VsE_full__T *MeritFunction,
  s_8jIp3wBW8W9AJZ7lDTkICE_full_T FcnEvaluator, s_iyYBPziYRv853Phg0mcgOD_full_T *
  FiniteDifferences, const sVTYnQ9ljvmk9dLse9XvTT_full_l_T *memspace, const
  sH6xx18cQHI5sgA7Ajla4nE_full__T *WorkingSet, const
  snaQeDJ4fX7UykrKyr5M8jC_full__T *QRManager, sJdVcLKPgejLYHLePKb6F6D_full__T
  *QPObjective, real_T Hessian[64], s6ICcRyulWOFjNCN0ll7VsE_full__T
  *b_MeritFunction, s_8jIp3wBW8W9AJZ7lDTkICE_full_T *b_FcnEvaluator,
  sVTYnQ9ljvmk9dLse9XvTT_full_l_T *b_memspace, sH6xx18cQHI5sgA7Ajla4nE_full__T
  *b_WorkingSet, snaQeDJ4fX7UykrKyr5M8jC_full__T *b_QRManager,
  snl99C5je2zMbU5SzygoX6F_full__T *CholManager)
{
  boolean_T Flags_fevalOK;
  boolean_T Flags_done;
  boolean_T Flags_failedLineSearch;
  boolean_T unusedU0;
  boolean_T b;
  static const int8_T tmp[64] = { 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,
    0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0,
    0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 };

  static const char_T tmp_0[7] = { 'f', 'm', 'i', 'n', 'c', 'o', 'n' };

  memset(&CholManager->FMat[0], 0, 441U * sizeof(real_T));
  CholManager->ldm = 21;
  CholManager->ndims = 0;
  CholManager->info = 0;
  *b_FcnEvaluator = FcnEvaluator;
  for (full_loop_B.i_n = 0; full_loop_B.i_n < 64; full_loop_B.i_n++) {
    Hessian[full_loop_B.i_n] = tmp[full_loop_B.i_n];
  }

  full_loop_B.nVar = WorkingSet->nVar;
  full_loop_B.mEq = WorkingSet->sizes[1];
  full_loop_B.mConstr = (WorkingSet->sizes[1] + WorkingSet->sizes[3]) - 1;
  for (full_loop_B.i_n = 0; full_loop_B.i_n < 7; full_loop_B.i_n++) {
    full_loop_B.qpoptions_SolverName[full_loop_B.i_n] = tmp_0[full_loop_B.i_n];
  }

  if (WorkingSet->nVar > WorkingSet->sizes[3]) {
    full_loop_B.WorkingSet_l = WorkingSet->nVar;
  } else {
    full_loop_B.WorkingSet_l = WorkingSet->sizes[3];
  }

  full_loop_B.WorkingSet_l *= 10;
  TrialState->steplength = 1.0;
  *b_memspace = *memspace;
  *b_MeritFunction = *MeritFunction;
  *b_WorkingSet = *WorkingSet;
  *b_QRManager = *QRManager;
  full_loop_test_exit_p4(b_MeritFunction, b_WorkingSet, TrialState,
    &full_loop_B.b_Flags, &full_loop_B.c_TrialState);
  Flags_fevalOK = full_loop_B.b_Flags.fevalOK;
  Flags_done = full_loop_B.b_Flags.done;
  b = full_loop_B.b_Flags.stepAccepted;
  Flags_failedLineSearch = full_loop_B.b_Flags.failedLineSearch;
  full_loop_B.Flags_stepType = full_loop_B.b_Flags.stepType;
  full_loop_saveState(&full_loop_B.c_TrialState, TrialState);
  if (!full_loop_B.b_Flags.done) {
    TrialState->sqpIterations = 1;
  }

  while (!Flags_done) {
    while (!(b || Flags_failedLineSearch)) {
      fu_updateWorkingSetForNewQP_p43(b_WorkingSet, full_loop_B.mEq,
        TrialState->cEq);
      full_loop_B.expl_temp.IterDisplayQP = false;
      full_loop_B.expl_temp.RemainFeasible = false;
      full_loop_B.expl_temp.ProbRelTolFactor = 1.0;
      full_loop_B.expl_temp.ConstrRelTolFactor = 1.0;
      full_loop_B.expl_temp.PricingTolerance = 0.0;
      full_loop_B.expl_temp.ObjectiveLimit = -1.0E+20;
      full_loop_B.expl_temp.ConstraintTolerance = 0.01;
      full_loop_B.expl_temp.OptimalityTolerance = 2.2204460492503131E-14;
      full_loop_B.expl_temp.StepTolerance = 1.0E-6;
      full_loop_B.expl_temp.MaxIterations = full_loop_B.WorkingSet_l;
      for (full_loop_B.i_n = 0; full_loop_B.i_n < 7; full_loop_B.i_n++) {
        full_loop_B.expl_temp.SolverName[full_loop_B.i_n] =
          full_loop_B.qpoptions_SolverName[full_loop_B.i_n];
      }

      memcpy(&full_loop_B.Hessian_p[0], &Hessian[0], sizeof(real_T) << 6);
      full_loop_B.expl_temp_p = full_loop_B.expl_temp;
      full_loop_step_p4(full_loop_B.Flags_stepType, full_loop_B.Hessian_p,
                        TrialState, b_MeritFunction, b_memspace, b_WorkingSet,
                        b_QRManager, CholManager, QPObjective,
                        &full_loop_B.expl_temp_p, &b, &full_loop_B.c_gs, Hessian);
      full_loop_B.Flags_stepType = full_loop_B.c_gs;
      if (b) {
        for (full_loop_B.i_n = 0; full_loop_B.i_n < full_loop_B.nVar;
             full_loop_B.i_n++) {
          TrialState->xstarsqp[full_loop_B.i_n] += TrialState->
            delta_x[full_loop_B.i_n];
        }

        for (full_loop_B.i_n = 0; full_loop_B.i_n < 6; full_loop_B.i_n++) {
          full_loop_B.l[full_loop_B.i_n] = TrialState->cEq[full_loop_B.i_n];
        }

        full_loop_evalObjAndConstr_p(&FcnEvaluator.objfun.tunableEnvironment,
          TrialState->xstarsqp, &full_loop_B.j, &full_loop_B.i_n);
        TrialState->sqpFval = full_loop_B.j;
        Flags_fevalOK = (full_loop_B.i_n == 1);
        TrialState->FunctionEvaluations++;
        full_computeLinearResiduals_p43(TrialState->xstarsqp, full_loop_B.nVar,
          full_loop_B.l, full_loop_B.mEq, b_WorkingSet->Aeq, beq);
        for (full_loop_B.i_n = 0; full_loop_B.i_n < 6; full_loop_B.i_n++) {
          TrialState->cEq[full_loop_B.i_n] = full_loop_B.l[full_loop_B.i_n];
        }

        b_MeritFunction->phiFullStep = full_loop_computeMeritFcn
          (b_MeritFunction->penaltyParam, full_loop_B.j, full_loop_B.l,
           full_loop_B.mEq, Flags_fevalOK);
      }

      if ((full_loop_B.c_gs == 1) && b && Flags_fevalOK && (b_MeritFunction->phi
           < b_MeritFunction->phiFullStep) && (TrialState->sqpFval <
           TrialState->sqpFval_old)) {
        full_loop_B.Flags_stepType = 3;
        b = false;
      } else {
        if ((full_loop_B.c_gs == 3) && b) {
          Flags_done = true;
        } else {
          Flags_done = false;
        }

        full_loop_linesearch_p(Flags_fevalOK, beq, b_WorkingSet, TrialState,
          b_MeritFunction, FcnEvaluator, Flags_done, &full_loop_B.j,
          &full_loop_B.i_n, &Flags_fevalOK);
        TrialState->steplength = full_loop_B.j;
        if (full_loop_B.i_n > 0) {
          b = true;
        } else {
          Flags_failedLineSearch = true;
        }
      }
    }

    if (b && (!Flags_failedLineSearch)) {
      for (full_loop_B.i_n = 0; full_loop_B.i_n < full_loop_B.nVar;
           full_loop_B.i_n++) {
        TrialState->xstarsqp[full_loop_B.i_n] = TrialState->
          xstarsqp_old[full_loop_B.i_n] + TrialState->delta_x[full_loop_B.i_n];
      }

      for (full_loop_B.i_n = 0; full_loop_B.i_n <= full_loop_B.mConstr;
           full_loop_B.i_n++) {
        TrialState->lambdasqp[full_loop_B.i_n] += (TrialState->
          lambda[full_loop_B.i_n] - TrialState->lambdasqp[full_loop_B.i_n]) *
          TrialState->steplength;
      }

      full_loop_B.c_TrialState = *TrialState;
      full_loop_saveState(&full_loop_B.c_TrialState, TrialState);
      memcpy(&full_loop_B.TrialState_m[0], &TrialState->xstarsqp[0], sizeof
             (real_T) << 3);
      memcpy(&full_loop_B.b_WorkingSet_c[0], &b_WorkingSet->Aeq[0], 126U *
             sizeof(real_T));
      ful_computeForwardDifferences_p(FiniteDifferences, TrialState->sqpFval,
        full_loop_B.TrialState_m, TrialState->grad, full_loop_B.b_WorkingSet_c,
        &Flags_done, b_WorkingSet->Aeq, TrialState->xstarsqp);
      TrialState->FunctionEvaluations += FiniteDifferences->numEvals;
    } else {
      full_loop_B.c_TrialState = *TrialState;
      full_loop_revertSolution(&full_loop_B.c_TrialState, TrialState);
    }

    full_loop_B.e_memspace = *b_memspace;
    full_loop_B.c_TrialState = *TrialState;
    full_loop_test_exit_p43(Flags_fevalOK, b, Flags_failedLineSearch,
      full_loop_B.Flags_stepType, &full_loop_B.e_memspace, b_MeritFunction,
      b_WorkingSet, &full_loop_B.c_TrialState, b_QRManager, &full_loop_B.b_Flags,
      TrialState);
    Flags_fevalOK = full_loop_B.b_Flags.fevalOK;
    Flags_done = full_loop_B.b_Flags.done;
    b = full_loop_B.b_Flags.stepAccepted;
    Flags_failedLineSearch = full_loop_B.b_Flags.failedLineSearch;
    full_loop_B.Flags_stepType = full_loop_B.b_Flags.stepType;
    *b_memspace = full_loop_B.e_memspace;
    if ((!full_loop_B.b_Flags.done) && full_loop_B.b_Flags.stepAccepted) {
      b = false;
      full_loop_B.Flags_stepType = 1;
      Flags_failedLineSearch = false;
      full_loop_computeDeltaLag_p(full_loop_B.nVar, TrialState->delta_gradLag,
        TrialState->grad, TrialState->grad_old);
      memcpy(&full_loop_B.Hessian_p[0], &Hessian[0], sizeof(real_T) << 6);
      full_loop_BFGSUpdate_p(full_loop_B.nVar, full_loop_B.Hessian_p,
        TrialState->delta_x, TrialState->delta_gradLag,
        full_loop_B.e_memspace.workspace_double, &unusedU0, Hessian,
        b_memspace->workspace_double);
      TrialState->sqpIterations++;
    }
  }
}

static void full_loop_fmincon(KickIn_full_loop_T **fun_tunableEnvironment, const
  real_T x0[8], const real_T Aeq[48], const real_T beq[6], real_T x[8])
{
  KickIn_full_loop_T *FcnEvaluator_objfun_tunableEnvi;
  boolean_T b_evalOK;
  static const s2CPTVnVyv153Hb6bxlki6F_full__T tmp = { 21,// nVarMax
    0,                                 // mNonlinIneq
    0,                                 // mNonlinEq
    0,                                 // mIneq
    6,                                 // mEq
    1,                                 // iNonIneq0
    7,                                 // iNonEq0
    0.0,                               // sqpFval
    0.0,                               // sqpFval_old
    { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },// xstarsqp
    { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },// xstarsqp_old
    { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },  // cEq
    { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },  // cEq_old
    { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },  // grad
    { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },  // grad_old
    0,                                 // FunctionEvaluations
    0,                                 // sqpIterations
    0,                                 // sqpExitFlag
    { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0 },            // lambdasqp
    { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0 },            // lambdasqp_old
    1.0,                               // steplength
    { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },  // delta_x
    { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },  // socDirection
    { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0 },            // lambda_old
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },// workingset_old 
    { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },  // gradLag
    { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },  // delta_gradLag
    { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },  // xstar
    0.0,                               // fstar
    0.0,                               // firstorderopt
    { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0 },            // lambda
    0,                                 // state
    0.0,                               // maxConstr
    0,                                 // iterations
    { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0 }   // searchDir
  };

  static const sJdVcLKPgejLYHLePKb6F6D_full__T tmp_0 = { { 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0 },                      // grad
    { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0 },       // Hx
    true,                              // hasLinear
    8,                                 // nvar
    21,                                // maxVar
    0.0,                               // beta
    0.0,                               // rho
    3,                                 // objtype
    3,                                 // prev_objtype
    0,                                 // prev_nvar
    false,                             // prev_hasLinear
    0.0                                // gammaScalar
  };

  KickIn_full_loop_T *fun_tunableEnvironment_0;
  full_loop_B.TrialState = tmp;
  for (full_loop_B.nDepEq = 0; full_loop_B.nDepEq < 8; full_loop_B.nDepEq++) {
    full_loop_B.TrialState.xstarsqp[full_loop_B.nDepEq] = 0.0;
    full_loop_B.TrialState.xstarsqp[full_loop_B.nDepEq] = x0[full_loop_B.nDepEq];
  }

  FcnEvaluator_objfun_tunableEnvi = *fun_tunableEnvironment;
  fun_tunableEnvironment_0 = *fun_tunableEnvironment;
  full_loop_B.FiniteDifferences = full_loop_factoryConstruct_p
    (&fun_tunableEnvironment_0);
  full_loop_factoryConstruct_p4(Aeq, &full_loop_B.WorkingSet);
  full_loop_B.b_memspace = full_loop_B.memspace;
  full_loop_B.QPObjective = tmp_0;
  for (full_loop_B.nDepEq = 0; full_loop_B.nDepEq < 6; full_loop_B.nDepEq++) {
    full_loop_B.b_beqFiltered[full_loop_B.nDepEq] = beq[full_loop_B.nDepEq];
  }

  full__removeDependentLinearEq_p(Aeq, full_loop_B.b_beqFiltered,
    full_loop_B.idxDepEq, &full_loop_B.b_memspace, &full_loop_B.TrialState,
    &full_loop_B.WorkingSet, &full_loop_B.QPObjective, &full_loop_B.nDepEq,
    &full_loop_B.QRManager);
  if (full_loop_B.nDepEq < 0) {
    full_loop_B.nDepEq = 0;
  }

  memcpy(&full_loop_B.c[0], &full_loop_B.TrialState.grad[0], 21U * sizeof(real_T));
  for (full_loop_B.i = 0; full_loop_B.i < 6; full_loop_B.i++) {
    full_loop_B.beqFiltered[full_loop_B.i] =
      full_loop_B.TrialState.cEq[full_loop_B.i];
  }

  evalObjAndConstrAndDerivative_p(&FcnEvaluator_objfun_tunableEnvi,
    full_loop_B.TrialState.xstarsqp, full_loop_B.WorkingSet.Aeq,
    &full_loop_B.b_g, full_loop_B.g_h, &full_loop_B.i);
  full_loop_B.TrialState.sqpFval = full_loop_B.b_g;
  memcpy(&full_loop_B.TrialState.grad[0], &full_loop_B.c[0], 21U * sizeof(real_T));
  ful_computeForwardDifferences_p(&full_loop_B.FiniteDifferences,
    full_loop_B.b_g, full_loop_B.TrialState.xstarsqp,
    full_loop_B.TrialState.grad, full_loop_B.g_h, &b_evalOK,
    full_loop_B.c_JacCeqTrans, full_loop_B.c_xk);
  memcpy(&full_loop_B.WorkingSet.Aeq[0], &full_loop_B.c_JacCeqTrans[0], 126U *
         sizeof(real_T));
  memcpy(&full_loop_B.TrialState.xstarsqp[0], &full_loop_B.c_xk[0], sizeof
         (real_T) << 3U);
  full_loop_B.TrialState.FunctionEvaluations =
    full_loop_B.FiniteDifferences.numEvals + 1;
  full__computeLinearResiduals_p4(full_loop_B.c_xk, full_loop_B.beqFiltered, 6 -
    full_loop_B.nDepEq, full_loop_B.c_JacCeqTrans, full_loop_B.b_beqFiltered);
  for (full_loop_B.i = 0; full_loop_B.i < 6; full_loop_B.i++) {
    full_loop_B.TrialState.cEq[full_loop_B.i] =
      full_loop_B.beqFiltered[full_loop_B.i];
  }

  ful_updateWorkingSetForNewQP_p4(&full_loop_B.WorkingSet, 6 -
    full_loop_B.nDepEq, full_loop_B.beqFiltered);
  full_loop_B.WorkingSet_g = full_loop_B.WorkingSet;
  full_loop_initActiveSet(&full_loop_B.WorkingSet_g, &full_loop_B.WorkingSet);
  full_loop_B.expl_temp_a.objfun.tunableEnvironment = *fun_tunableEnvironment;
  full_loop_factoryConstruct_p43(full_loop_B.b_g, full_loop_B.beqFiltered, 6 -
    full_loop_B.nDepEq, &full_loop_B.r_c);
  full_loop_driver_p4(full_loop_B.b_beqFiltered, &full_loop_B.TrialState,
                      &full_loop_B.r_c, full_loop_B.expl_temp_a,
                      &full_loop_B.FiniteDifferences, &full_loop_B.b_memspace,
                      &full_loop_B.WorkingSet, &full_loop_B.QRManager,
                      &full_loop_B.QPObjective, full_loop_B.Hessian,
                      &full_loop_B.b_MeritFunction, &full_loop_B.b_FcnEvaluator,
                      &full_loop_B.memspace, &full_loop_B.WorkingSet_g,
                      &full_loop_B.b_QRManager, &full_loop_B.CholManager);
  memcpy(&x[0], &full_loop_B.TrialState.xstarsqp[0], sizeof(real_T) << 3U);
}

static void full_loop_AUVStateJacobianFcn(const real_T in1[12], real_T A[144],
  real_T B[96], real_T C[144], real_T D[96])
{
  static const real_T tmp[96] = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.020827887516540428, -0.020827887516540428, 0.0, 0.0011455338134097235,
    0.0011455338134097235, -0.010017196265067472, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.020827887516540428, 0.020827887516540428, 0.0, -0.0011455338134097235,
    0.0011455338134097235, -0.010067650168313758, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.020827887516540428, -0.020827887516540428, 0.0, 0.0011455338134097235,
    0.0011455338134097235, 0.0099777972810327388, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.020827887516540428, 0.020827887516540428, 0.0, -0.0011455338134097235,
    0.0011455338134097235, 0.0099268867064512215, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.029455081001472753, 0.0047717231222385859,
    -0.0053166421207658321, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    -0.029455081001472753, -0.0047717231222385859, -0.0053755522827687776, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.029455081001472753,
    -0.00459499263622975, 0.0053755522827687776, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, -0.029455081001472753, 0.00459499263622975,
    0.0053166421207658321, 0.0 };

  int32_T i;
  real_T A_tmp;
  real_T A_tmp_0;
  real_T A_tmp_1;
  real_T A_tmp_2;
  real_T A_tmp_3;
  real_T t35_tmp;
  static const int8_T tmp_0[144] = { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 };

  // AUVSTATEJACOBIANFCN
  //     [A,B,C,D] = AUVSTATEJACOBIANFCN(IN1,IN2)
  //     This function was generated by the Symbolic Math Toolbox version 8.5.
  //     15-Jan-2021 09:02:25
  full_loop_B.t6 = in1[3] / 2.0;
  full_loop_B.t7 = in1[5] / 2.0;
  full_loop_B.t8 = in1[4] / 2.0;
  full_loop_B.t9 = in1[3] / 2.0;
  full_loop_B.t10 = cos(full_loop_B.t6);
  full_loop_B.t11 = in1[5] / 2.0;
  full_loop_B.t12 = cos(full_loop_B.t7);
  full_loop_B.t13 = in1[4] / 2.0;
  full_loop_B.t14 = cos(full_loop_B.t8);
  full_loop_B.t6 = sin(full_loop_B.t6);
  full_loop_B.t7 = sin(full_loop_B.t7);
  full_loop_B.t8 = sin(full_loop_B.t8);
  full_loop_B.t18_h = cos(full_loop_B.t9);
  full_loop_B.t19_m = cos(full_loop_B.t11);
  full_loop_B.t20_a = cos(full_loop_B.t13);
  full_loop_B.t21_k = sin(full_loop_B.t9);
  full_loop_B.t22 = sin(full_loop_B.t11);
  full_loop_B.t23_p = sin(full_loop_B.t13);
  full_loop_B.t13 = full_loop_B.t10 * full_loop_B.t10;
  full_loop_B.t11 = full_loop_B.t12 * full_loop_B.t12;
  full_loop_B.t9 = full_loop_B.t14 * full_loop_B.t14;
  full_loop_B.t27_b = full_loop_B.t6 * full_loop_B.t6;
  full_loop_B.t28 = full_loop_B.t7 * full_loop_B.t7;
  full_loop_B.t29 = full_loop_B.t8 * full_loop_B.t8;
  full_loop_B.t34_tmp = full_loop_B.t10 * full_loop_B.t12;
  full_loop_B.t34 = full_loop_B.t34_tmp * full_loop_B.t8;
  t35_tmp = full_loop_B.t10 * full_loop_B.t14;
  full_loop_B.t35 = t35_tmp * full_loop_B.t7;
  full_loop_B.t36_tmp = full_loop_B.t12 * full_loop_B.t14;
  full_loop_B.t36 = full_loop_B.t36_tmp * full_loop_B.t6;
  full_loop_B.t37 = full_loop_B.t10 * full_loop_B.t7 * full_loop_B.t8;
  full_loop_B.t38 = full_loop_B.t12 * full_loop_B.t6 * full_loop_B.t8;
  full_loop_B.t39 = full_loop_B.t14 * full_loop_B.t6 * full_loop_B.t7;
  full_loop_B.t40 = full_loop_B.t6 * full_loop_B.t7 * full_loop_B.t8;
  full_loop_B.t41 = full_loop_B.t34_tmp * full_loop_B.t14;
  full_loop_B.t47 = full_loop_B.t34 / 2.0;
  full_loop_B.t48_c = full_loop_B.t35 / 2.0;
  full_loop_B.t49 = full_loop_B.t36 / 2.0;
  full_loop_B.t50 = full_loop_B.t37 / 2.0;
  full_loop_B.t51 = full_loop_B.t38 / 2.0;
  full_loop_B.t52_n = full_loop_B.t39 / 2.0;
  full_loop_B.t53 = full_loop_B.t40 / 2.0;
  full_loop_B.t70 = full_loop_B.t18_h * full_loop_B.t19_m;
  full_loop_B.t54 = full_loop_B.t70 * full_loop_B.t23_p;
  full_loop_B.t55_i = full_loop_B.t18_h * full_loop_B.t20_a * full_loop_B.t22;
  full_loop_B.t56 = full_loop_B.t19_m * full_loop_B.t20_a * full_loop_B.t21_k;
  full_loop_B.t18_h = full_loop_B.t18_h * full_loop_B.t22 * full_loop_B.t23_p;
  full_loop_B.t19_m = full_loop_B.t19_m * full_loop_B.t21_k * full_loop_B.t23_p;
  full_loop_B.t59 = full_loop_B.t20_a * full_loop_B.t21_k * full_loop_B.t22;
  full_loop_B.t60 = full_loop_B.t41 / 2.0;
  full_loop_B.t20_a *= full_loop_B.t70;
  full_loop_B.t67 = full_loop_B.t20_a / 2.0;
  full_loop_B.t21_k = full_loop_B.t21_k * full_loop_B.t22 * full_loop_B.t23_p;
  full_loop_B.t74 = full_loop_B.t21_k / 2.0;
  full_loop_B.t22 = full_loop_B.t34 + full_loop_B.t39;
  full_loop_B.t23_p = full_loop_B.t40 + full_loop_B.t41;
  full_loop_B.t69 = full_loop_B.t55_i / 2.0;
  full_loop_B.t70 = full_loop_B.t56 / 2.0;
  full_loop_B.t71 = full_loop_B.t18_h / 2.0;
  full_loop_B.t72 = full_loop_B.t19_m / 2.0;
  full_loop_B.t80 = full_loop_B.t34 + -full_loop_B.t39;
  full_loop_B.t81 = full_loop_B.t35 + -full_loop_B.t38;
  full_loop_B.t82 = full_loop_B.t36 + -full_loop_B.t37;
  full_loop_B.t83 = full_loop_B.t40 * 2.0 + full_loop_B.t41 * 2.0;
  full_loop_B.t85 = full_loop_B.t47 + full_loop_B.t52_n;
  full_loop_B.t86 = full_loop_B.t48_c + full_loop_B.t51;
  full_loop_B.t88 = full_loop_B.t53 + full_loop_B.t60;
  full_loop_B.t89 = full_loop_B.t54 + full_loop_B.t59;
  full_loop_B.t96 = full_loop_B.t67 + full_loop_B.t74;
  full_loop_B.t84 = full_loop_B.t82 * full_loop_B.t82;
  full_loop_B.t48_c += -full_loop_B.t51;
  full_loop_B.t51 = full_loop_B.t49 + -full_loop_B.t50;
  full_loop_B.t93 = full_loop_B.t53 + -full_loop_B.t60;
  full_loop_B.t53 = full_loop_B.t55_i + -full_loop_B.t19_m;
  full_loop_B.t60 = full_loop_B.t56 + -full_loop_B.t18_h;
  full_loop_B.t97 = full_loop_B.t54 / 2.0 + full_loop_B.t59 / 2.0;
  full_loop_B.t99 = full_loop_B.t70 + full_loop_B.t71;
  memset(&A[0], 0, 42U * sizeof(real_T));
  full_loop_B.A_tmp_e = full_loop_B.t22 * full_loop_B.t82;
  full_loop_B.A_tmp_mv = full_loop_B.t83 * full_loop_B.t48_c;
  A_tmp_0 = full_loop_B.t82 * full_loop_B.t97;
  A_tmp_3 = full_loop_B.t88 * full_loop_B.t53;
  A[42] = ((full_loop_B.A_tmp_e * -0.85992812960235643 + full_loop_B.A_tmp_mv *
            0.85992812960235643) + A_tmp_0 * 1.7198562592047131) - A_tmp_3 *
    1.7198562592047131;
  full_loop_B.A_tmp = full_loop_B.t83 * full_loop_B.t88;
  full_loop_B.A_tmp_m = full_loop_B.t22 * full_loop_B.t97;
  full_loop_B.A_tmp_j = full_loop_B.t48_c * full_loop_B.t53;
  A[43] = ((full_loop_B.t84 * 0.85992812960235643 - full_loop_B.A_tmp *
            0.85992812960235643) + full_loop_B.A_tmp_m * 1.7198562592047131) -
    full_loop_B.A_tmp_j * 1.7198562592047131;
  full_loop_B.t10 *= full_loop_B.t6;
  full_loop_B.t36_tmp = full_loop_B.t36_tmp * full_loop_B.t7 * full_loop_B.t8;
  A[44] = ((((((((((((((((((full_loop_B.t34 * full_loop_B.t55_i *
    0.85992812960235643 + full_loop_B.t35 * full_loop_B.t54 *
    0.85992812960235643) - full_loop_B.t34 * full_loop_B.t19_m *
    0.85992812960235643) - full_loop_B.t38 * full_loop_B.t54 *
    0.85992812960235643) + full_loop_B.t35 * full_loop_B.t59 *
    0.85992812960235643) + full_loop_B.t39 * full_loop_B.t55_i *
                        0.85992812960235643) + full_loop_B.t40 * full_loop_B.t56
                       * 0.42996406480117821) - full_loop_B.t38 *
                      full_loop_B.t59 * 0.85992812960235643) - full_loop_B.t39 *
                     full_loop_B.t19_m * 0.85992812960235643) - full_loop_B.t40 *
                    full_loop_B.t18_h * 0.42996406480117821) + full_loop_B.t41 *
                   full_loop_B.t56 * 0.42996406480117821) - full_loop_B.t41 *
                  full_loop_B.t18_h * 0.42996406480117821) + full_loop_B.t10 *
                 full_loop_B.t11 * full_loop_B.t9 * 0.85992812960235643) -
                full_loop_B.t10 * full_loop_B.t28 * full_loop_B.t29 *
                0.85992812960235643) + full_loop_B.t20_a * full_loop_B.t36 *
               0.42996406480117821) - full_loop_B.t20_a * full_loop_B.t37 *
              0.42996406480117821) + full_loop_B.t21_k * full_loop_B.t36 *
             0.42996406480117821) - full_loop_B.t21_k * full_loop_B.t37 *
            0.42996406480117821) - full_loop_B.t36_tmp * full_loop_B.t13 *
           0.85992812960235643) + full_loop_B.t36_tmp * full_loop_B.t27_b *
    0.85992812960235643;
  full_loop_B.t10 = full_loop_B.t23_p * full_loop_B.t51;
  full_loop_B.t36_tmp = full_loop_B.t81 * full_loop_B.t97;
  full_loop_B.t97 = full_loop_B.t82 * full_loop_B.t96;
  A_tmp = full_loop_B.t22 * (full_loop_B.t69 + -full_loop_B.t72);
  A_tmp_1 = full_loop_B.t85 * full_loop_B.t53;
  A_tmp_2 = full_loop_B.t89 * full_loop_B.t48_c;
  full_loop_B.t88 *= full_loop_B.t60;
  A[45] = (((((((((full_loop_B.t84 * -0.023218059499263619 - full_loop_B.t10 *
                   0.0051595687776141378) + full_loop_B.A_tmp *
                  0.023218059499263619) - full_loop_B.A_tmp_m *
                 0.046436118998527252) - full_loop_B.t36_tmp *
                0.0025797843888070689) - full_loop_B.t97 * 0.0025797843888070689)
              - A_tmp * 0.0025797843888070689) - A_tmp_1 * 0.0025797843888070689)
            - A_tmp_2 * 0.0025797843888070689) - full_loop_B.t88 *
           0.0025797843888070689) + full_loop_B.A_tmp_j * 0.046436118998527252;
  A[46] = (((((((((full_loop_B.A_tmp_e * -0.023218059499263619 - full_loop_B.t10
                   * 0.0017198562592047131) + full_loop_B.A_tmp_mv *
                  0.023218059499263619) - full_loop_B.t36_tmp *
                 0.00085992812960235645) - full_loop_B.t97 *
                0.00085992812960235645) - A_tmp * 0.00085992812960235645) +
              A_tmp_0 * 0.046436118998527252) - A_tmp_1 * 0.00085992812960235645)
            - A_tmp_2 * 0.00085992812960235645) - A_tmp_3 * 0.046436118998527252)
    - full_loop_B.t88 * 0.00085992812960235645;
  A[47] = ((((((full_loop_B.t84 * 0.00085992812960235645 - full_loop_B.A_tmp_e *
                0.0025797843888070689) - full_loop_B.A_tmp *
               0.00085992812960235645) + full_loop_B.A_tmp_mv *
              0.0025797843888070689) + full_loop_B.A_tmp_m *
             0.0017198562592047131) + A_tmp_0 * 0.0051595687776141378) - A_tmp_3
           * 0.0051595687776141378) - full_loop_B.A_tmp_j *
    0.0017198562592047131;
  A[48] = 0.0;
  A[49] = 0.0;
  A[50] = 0.0;
  A[51] = 0.0;
  A[52] = 0.0;
  A[53] = 0.0;
  full_loop_B.A_tmp_e = full_loop_B.t22 * full_loop_B.t80;
  full_loop_B.A_tmp_mv = full_loop_B.t83 * full_loop_B.t93;
  full_loop_B.A_tmp = full_loop_B.t86 * full_loop_B.t53;
  full_loop_B.A_tmp_m = full_loop_B.t82 * full_loop_B.t99;
  A[54] = ((full_loop_B.A_tmp_e * -0.85992812960235643 - full_loop_B.A_tmp_mv *
            0.85992812960235643) + full_loop_B.A_tmp * 1.7198562592047131) +
    full_loop_B.A_tmp_m * 1.7198562592047131;
  full_loop_B.A_tmp_j = full_loop_B.t80 * full_loop_B.t82;
  full_loop_B.t10 = full_loop_B.t83 * full_loop_B.t86;
  full_loop_B.t36_tmp = full_loop_B.t22 * full_loop_B.t99;
  A_tmp = full_loop_B.t93 * full_loop_B.t53;
  A[55] = ((full_loop_B.A_tmp_j * 0.85992812960235643 + full_loop_B.t10 *
            0.85992812960235643) + full_loop_B.t36_tmp * 1.7198562592047131) +
    A_tmp * 1.7198562592047131;
  A_tmp_2 = full_loop_B.t14 * full_loop_B.t8;
  full_loop_B.t88 = full_loop_B.t34_tmp * full_loop_B.t6 * full_loop_B.t7;
  A[56] = ((((((((((((((full_loop_B.t35 * full_loop_B.t18_h *
                        0.85992812960235643 + full_loop_B.t37 *
                        full_loop_B.t55_i * 0.85992812960235643) -
                       full_loop_B.t36 * full_loop_B.t19_m * 0.85992812960235643)
                      - full_loop_B.t38 * full_loop_B.t56 * 0.85992812960235643)
                     - full_loop_B.t40 * full_loop_B.t54 * 0.42996406480117821)
                    + full_loop_B.t41 * full_loop_B.t54 * 0.42996406480117821) -
                   full_loop_B.t40 * full_loop_B.t59 * 0.42996406480117821) +
                  full_loop_B.t41 * full_loop_B.t59 * 0.42996406480117821) +
                 A_tmp_2 * full_loop_B.t13 * full_loop_B.t11 *
                 0.85992812960235643) - A_tmp_2 * full_loop_B.t27_b *
                full_loop_B.t28 * 0.85992812960235643) + full_loop_B.t20_a *
               full_loop_B.t34 * 0.42996406480117821) + full_loop_B.t20_a *
              full_loop_B.t39 * 0.42996406480117821) - full_loop_B.t21_k *
             full_loop_B.t34 * 0.42996406480117821) - full_loop_B.t21_k *
            full_loop_B.t39 * 0.42996406480117821) - full_loop_B.t88 *
           full_loop_B.t9 * 0.85992812960235643) + full_loop_B.t88 *
    full_loop_B.t29 * 0.85992812960235643;
  A_tmp_2 = full_loop_B.t23_p * (full_loop_B.t47 + -full_loop_B.t52_n);
  full_loop_B.t88 = full_loop_B.t22 * (full_loop_B.t67 + -full_loop_B.t74);
  full_loop_B.t14 = full_loop_B.t81 * full_loop_B.t99;
  full_loop_B.t34_tmp = full_loop_B.t82 * (full_loop_B.t69 + full_loop_B.t72);
  full_loop_B.t34 = full_loop_B.t86 * full_loop_B.t60;
  full_loop_B.t49 = (full_loop_B.t49 + full_loop_B.t50) * full_loop_B.t53;
  full_loop_B.t50 = full_loop_B.t89 * full_loop_B.t93;
  A[57] = (((((((((full_loop_B.A_tmp_j * -0.023218059499263619 - A_tmp_2 *
                   0.0051595687776141378) - full_loop_B.t10 *
                  0.023218059499263619) - full_loop_B.t36_tmp *
                 0.046436118998527252) - full_loop_B.t88 * 0.0025797843888070689)
               - full_loop_B.t14 * 0.0025797843888070689) + full_loop_B.t34_tmp *
              0.0025797843888070689) + full_loop_B.t34 * 0.0025797843888070689)
            - full_loop_B.t49 * 0.0025797843888070689) + full_loop_B.t50 *
           0.0025797843888070689) - A_tmp * 0.046436118998527252;
  A[58] = (((((((((full_loop_B.A_tmp_e * -0.023218059499263619 - A_tmp_2 *
                   0.0017198562592047131) - full_loop_B.A_tmp_mv *
                  0.023218059499263619) - full_loop_B.t88 *
                 0.00085992812960235645) - full_loop_B.t14 *
                0.00085992812960235645) + full_loop_B.t34_tmp *
               0.00085992812960235645) + full_loop_B.A_tmp *
              0.046436118998527252) + full_loop_B.A_tmp_m * 0.046436118998527252)
            + full_loop_B.t34 * 0.00085992812960235645) - full_loop_B.t49 *
           0.00085992812960235645) + full_loop_B.t50 * 0.00085992812960235645;
  A[59] = ((((((full_loop_B.A_tmp_e * -0.0025797843888070689 +
                full_loop_B.A_tmp_j * 0.00085992812960235645) + full_loop_B.t10 *
               0.00085992812960235645) - full_loop_B.A_tmp_mv *
              0.0025797843888070689) + full_loop_B.t36_tmp *
             0.0017198562592047131) + full_loop_B.A_tmp * 0.0051595687776141378)
           + full_loop_B.A_tmp_m * 0.0051595687776141378) + A_tmp *
    0.0017198562592047131;
  A[60] = 0.0;
  A[61] = 0.0;
  A[62] = 0.0;
  A[63] = 0.0;
  A[64] = 0.0;
  A[65] = 0.0;
  full_loop_B.A_tmp_e = full_loop_B.t22 * full_loop_B.t81;
  full_loop_B.A_tmp_mv = full_loop_B.t83 * full_loop_B.t51;
  A[66] = ((full_loop_B.A_tmp_e * -0.85992812960235643 + full_loop_B.A_tmp_mv *
            0.85992812960235643) - full_loop_B.t97 * 1.7198562592047131) +
    A_tmp_1 * 1.7198562592047131;
  full_loop_B.A_tmp = full_loop_B.t81 * full_loop_B.t82;
  full_loop_B.A_tmp_m = full_loop_B.t83 * full_loop_B.t85;
  full_loop_B.A_tmp_j = full_loop_B.t22 * full_loop_B.t96;
  full_loop_B.t10 = full_loop_B.t51 * full_loop_B.t53;
  A[67] = ((full_loop_B.A_tmp * 0.85992812960235643 + full_loop_B.A_tmp_m *
            0.85992812960235643) - full_loop_B.A_tmp_j * 1.7198562592047131) -
    full_loop_B.t10 * 1.7198562592047131;
  full_loop_B.t36_tmp = full_loop_B.t12 * full_loop_B.t7;
  A_tmp = t35_tmp * full_loop_B.t6 * full_loop_B.t8;
  A[68] = ((((((((((full_loop_B.t40 * full_loop_B.t55_i * -0.42996406480117821 -
                    full_loop_B.t41 * full_loop_B.t55_i * 0.42996406480117821) +
                   full_loop_B.t40 * full_loop_B.t19_m * 0.42996406480117821) +
                  full_loop_B.t41 * full_loop_B.t19_m * 0.42996406480117821) +
                 full_loop_B.t36_tmp * full_loop_B.t13 * full_loop_B.t9 *
                 0.85992812960235643) - full_loop_B.t36_tmp * full_loop_B.t27_b *
                full_loop_B.t29 * 0.85992812960235643) - full_loop_B.t20_a *
               full_loop_B.t35 * 0.42996406480117821) + full_loop_B.t20_a *
              full_loop_B.t38 * 0.42996406480117821) - full_loop_B.t21_k *
             full_loop_B.t35 * 0.42996406480117821) + full_loop_B.t21_k *
            full_loop_B.t38 * 0.42996406480117821) - A_tmp * full_loop_B.t11 *
           0.85992812960235643) + A_tmp * full_loop_B.t28 * 0.85992812960235643;
  full_loop_B.t36_tmp = full_loop_B.t23_p * full_loop_B.t48_c;
  A_tmp = full_loop_B.t81 * full_loop_B.t96;
  A_tmp_2 = full_loop_B.t22 * (full_loop_B.t70 + -full_loop_B.t71);
  full_loop_B.t88 = full_loop_B.t85 * full_loop_B.t60;
  full_loop_B.t14 = full_loop_B.t89 * full_loop_B.t51;
  A[69] = (((((((((full_loop_B.A_tmp * -0.023218059499263619 -
                   full_loop_B.A_tmp_m * 0.023218059499263619) -
                  full_loop_B.t36_tmp * 0.0051595687776141378) +
                 full_loop_B.A_tmp_j * 0.046436118998527252) + A_tmp *
                0.0025797843888070689) + A_tmp_0 * 0.0025797843888070689) -
              A_tmp_2 * 0.0025797843888070689) + full_loop_B.t88 *
             0.0025797843888070689) - full_loop_B.t14 * 0.0025797843888070689) +
           A_tmp_3 * 0.0025797843888070689) + full_loop_B.t10 *
    0.046436118998527252;
  A[70] = (((((((((full_loop_B.A_tmp_e * -0.023218059499263619 -
                   full_loop_B.t36_tmp * 0.0017198562592047131) +
                  full_loop_B.A_tmp_mv * 0.023218059499263619) + A_tmp *
                 0.00085992812960235645) - full_loop_B.t97 *
                0.046436118998527252) + A_tmp_0 * 0.00085992812960235645) +
              A_tmp_1 * 0.046436118998527252) - A_tmp_2 * 0.00085992812960235645)
            + full_loop_B.t88 * 0.00085992812960235645) - full_loop_B.t14 *
           0.00085992812960235645) + A_tmp_3 * 0.00085992812960235645;
  A[71] = ((((((full_loop_B.A_tmp_e * -0.0025797843888070689 + full_loop_B.A_tmp
                * 0.00085992812960235645) + full_loop_B.A_tmp_m *
               0.00085992812960235645) - full_loop_B.A_tmp_j *
              0.0017198562592047131) + full_loop_B.A_tmp_mv *
             0.0025797843888070689) - full_loop_B.t97 * 0.0051595687776141378) +
           A_tmp_1 * 0.0051595687776141378) - full_loop_B.t10 *
    0.0017198562592047131;
  A[72] = 1.0;
  A[73] = 0.0;
  A[74] = 0.0;
  A[75] = 0.0;
  A[76] = 0.0;
  A[77] = 0.0;
  A[78] = in1[6] * in1[6] * -3.809743740795287 - 1.7637702503681889;
  A[79] = in1[11];
  A[80] = -in1[10];
  A[81] = 0.0;
  A[82] = 0.0;
  A[83] = 0.0;
  A[84] = 0.0;
  A[85] = 1.0;
  A[86] = 0.0;
  A[87] = 0.0;
  A[88] = 0.0;
  A[89] = 0.0;
  A[90] = -in1[11];
  A[91] = in1[7] * in1[7] * -6.9845301914580267 - 6.467157584683358;
  A[92] = in1[9];
  A[93] = 0.0;
  A[94] = 0.0;
  A[95] = 0.0;
  A[96] = 0.0;
  A[97] = 0.0;
  A[98] = 1.0;
  A[99] = 0.0;
  A[100] = 0.0;
  A[101] = 0.0;
  A[102] = in1[10];
  A[103] = -in1[9];
  A[104] = in1[8] * in1[8] * -9.2703764359352 - 12.87552282768778;
  A[105] = 0.0;
  A[106] = 0.0;
  A[107] = 0.0;
  A[108] = 0.0;
  A[109] = 0.0;
  A[110] = 0.0;
  A[111] = 1.0;
  A[112] = 0.0;
  A[113] = 0.0;
  A[114] = 0.0;
  A[115] = -in1[8];
  A[116] = in1[7];
  A[117] = in1[9] * in1[9] * -9.2703764359352 - 4.2918409425625921;
  A[118] = in1[11] * -0.033702503681885133;
  A[119] = in1[10] * 0.027516936671575849;
  A[120] = 0.0;
  A[121] = 0.0;
  A[122] = 0.0;
  A[123] = 0.0;
  A[124] = 1.0;
  A[125] = 0.0;
  A[126] = in1[8];
  A[127] = 0.0;
  A[128] = -in1[6];
  A[129] = in1[11] * 0.0061855670103092781;
  A[130] = in1[10] * in1[10] * -9.2703764359352 - 4.2918409425625921;
  A[131] = in1[9] * 0.027516936671575849;
  A[132] = 0.0;
  A[133] = 0.0;
  A[134] = 0.0;
  A[135] = 0.0;
  A[136] = 0.0;
  A[137] = 1.0;
  A[138] = -in1[7];
  A[139] = in1[6];
  A[140] = 0.0;
  A[141] = in1[10] * 0.0061855670103092781;
  A[142] = in1[9] * -0.033702503681885133;
  A[143] = in1[11] * in1[11] * -6.9845301914580267 - 3.233578792341679;
  memcpy(&B[0], &tmp[0], 96U * sizeof(real_T));
  for (i = 0; i < 144; i++) {
    C[i] = tmp_0[i];
  }

  memset(&D[0], 0, 96U * sizeof(real_T));
}

real_T rt_powd_snf(real_T u0, real_T u1)
{
  real_T y;
  real_T tmp;
  real_T tmp_0;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else {
    tmp = fabs(u0);
    tmp_0 = fabs(u1);
    if (rtIsInf(u1)) {
      if (tmp == 1.0) {
        y = 1.0;
      } else if (tmp > 1.0) {
        if (u1 > 0.0) {
          y = (rtInf);
        } else {
          y = 0.0;
        }
      } else if (u1 > 0.0) {
        y = 0.0;
      } else {
        y = (rtInf);
      }
    } else if (tmp_0 == 0.0) {
      y = 1.0;
    } else if (tmp_0 == 1.0) {
      if (u1 > 0.0) {
        y = u0;
      } else {
        y = 1.0 / u0;
      }
    } else if (u1 == 2.0) {
      y = u0 * u0;
    } else if ((u1 == 0.5) && (u0 >= 0.0)) {
      y = sqrt(u0);
    } else if ((u0 < 0.0) && (u1 > floor(u1))) {
      y = (rtNaN);
    } else {
      y = pow(u0, u1);
    }
  }

  return y;
}

static void full_loop_xgetrf(const real_T A[400], real_T b_A[400], int32_T ipiv
  [20], int32_T *info)
{
  int32_T jj;
  int32_T b_j;
  int32_T c;
  int32_T idxmax;
  int32_T ix;
  int32_T iy;
  int32_T jy;
  int32_T c_0;
  int32_T ijA;
  memcpy(&b_A[0], &A[0], 400U * sizeof(real_T));
  for (b_j = 0; b_j < 20; b_j++) {
    ipiv[b_j] = b_j + 1;
  }

  *info = 0;
  for (b_j = 0; b_j < 19; b_j++) {
    c = b_j * 21 + 2;
    jj = b_j * 21;
    iy = 20 - b_j;
    idxmax = 1;
    ix = c - 2;
    full_loop_B.smax = fabs(b_A[jj]);
    for (jy = 2; jy <= iy; jy++) {
      ix++;
      full_loop_B.s_o = fabs(b_A[ix]);
      if (full_loop_B.s_o > full_loop_B.smax) {
        idxmax = jy;
        full_loop_B.smax = full_loop_B.s_o;
      }
    }

    if (b_A[(c + idxmax) - 3] != 0.0) {
      if (idxmax - 1 != 0) {
        iy = b_j + idxmax;
        ipiv[b_j] = iy;
        ix = b_j;
        iy--;
        for (jy = 0; jy < 20; jy++) {
          full_loop_B.smax = b_A[ix];
          b_A[ix] = b_A[iy];
          b_A[iy] = full_loop_B.smax;
          ix += 20;
          iy += 20;
        }
      }

      ix = c - b_j;
      for (iy = c; iy <= ix + 18; iy++) {
        b_A[iy - 1] /= b_A[jj];
      }
    } else {
      *info = b_j + 1;
    }

    iy = 18 - b_j;
    jy = jj + 20;
    for (idxmax = 0; idxmax <= iy; idxmax++) {
      if (b_A[jy] != 0.0) {
        full_loop_B.smax = -b_A[jy];
        ix = c - 1;
        c_0 = jj - b_j;
        for (ijA = jj + 22; ijA <= c_0 + 40; ijA++) {
          b_A[ijA - 1] += b_A[ix] * full_loop_B.smax;
          ix++;
        }
      }

      jy += 20;
      jj += 20;
    }
  }

  if ((*info == 0) && (!(b_A[399] != 0.0))) {
    *info = 20;
  }
}

static void full_loop_lusolve(const real_T A[400], const real_T B[400], real_T
  X[400])
{
  int32_T i;
  int32_T b;
  int32_T X_tmp;
  int32_T tmp;
  full_loop_xgetrf(A, full_loop_B.c_A, full_loop_B.ipiv, &full_loop_B.b_info);
  memcpy(&X[0], &B[0], 400U * sizeof(real_T));
  for (full_loop_B.b_i_i = 0; full_loop_B.b_i_i < 19; full_loop_B.b_i_i++) {
    if (full_loop_B.b_i_i + 1 != full_loop_B.ipiv[full_loop_B.b_i_i]) {
      full_loop_B.ip = full_loop_B.ipiv[full_loop_B.b_i_i] - 1;
      for (full_loop_B.b_info = 0; full_loop_B.b_info < 20; full_loop_B.b_info++)
      {
        full_loop_B.kAcol = 20 * full_loop_B.b_info + full_loop_B.b_i_i;
        full_loop_B.temp = X[full_loop_B.kAcol];
        X_tmp = 20 * full_loop_B.b_info + full_loop_B.ip;
        X[full_loop_B.kAcol] = X[X_tmp];
        X[X_tmp] = full_loop_B.temp;
      }
    }
  }

  for (full_loop_B.b_info = 0; full_loop_B.b_info < 20; full_loop_B.b_info++) {
    full_loop_B.ip = 20 * full_loop_B.b_info - 1;
    for (full_loop_B.b_i_i = 0; full_loop_B.b_i_i < 20; full_loop_B.b_i_i++) {
      full_loop_B.kAcol = 20 * full_loop_B.b_i_i - 1;
      tmp = (full_loop_B.b_i_i + full_loop_B.ip) + 1;
      if (X[tmp] != 0.0) {
        for (i = full_loop_B.b_i_i + 2; i < 21; i++) {
          X_tmp = i + full_loop_B.ip;
          X[X_tmp] -= X[tmp] * full_loop_B.c_A[i + full_loop_B.kAcol];
        }
      }
    }
  }

  for (full_loop_B.b_info = 0; full_loop_B.b_info < 20; full_loop_B.b_info++) {
    full_loop_B.ip = 20 * full_loop_B.b_info;
    for (i = 19; i >= 0; i--) {
      full_loop_B.kAcol = 20 * i;
      tmp = i + full_loop_B.ip;
      if (X[tmp] != 0.0) {
        X[tmp] /= full_loop_B.c_A[i + full_loop_B.kAcol];
        b = i - 1;
        for (full_loop_B.b_i_i = 0; full_loop_B.b_i_i <= b; full_loop_B.b_i_i++)
        {
          X_tmp = full_loop_B.b_i_i + full_loop_B.ip;
          X[X_tmp] -= X[tmp] * full_loop_B.c_A[full_loop_B.b_i_i +
            full_loop_B.kAcol];
        }
      }
    }
  }
}

static void full_lo_PadeApproximantOfDegree(const real_T A[400], uint8_T m,
  real_T F[400])
{
  for (full_loop_B.f_k = 0; full_loop_B.f_k < 20; full_loop_B.f_k++) {
    for (full_loop_B.F_tmp_n = 0; full_loop_B.F_tmp_n < 20; full_loop_B.F_tmp_n
         ++) {
      full_loop_B.A2_tmp = full_loop_B.F_tmp_n + 20 * full_loop_B.f_k;
      full_loop_B.A2[full_loop_B.A2_tmp] = 0.0;
      for (full_loop_B.i8 = 0; full_loop_B.i8 < 20; full_loop_B.i8++) {
        full_loop_B.A2[full_loop_B.A2_tmp] += A[20 * full_loop_B.i8 +
          full_loop_B.F_tmp_n] * A[20 * full_loop_B.f_k + full_loop_B.i8];
      }
    }
  }

  if (m == 3) {
    memcpy(&full_loop_B.U_j[0], &full_loop_B.A2[0], 400U * sizeof(real_T));
    for (full_loop_B.f_k = 0; full_loop_B.f_k < 20; full_loop_B.f_k++) {
      full_loop_B.A2_tmp = 20 * full_loop_B.f_k + full_loop_B.f_k;
      full_loop_B.U_j[full_loop_B.A2_tmp] += 60.0;
    }

    for (full_loop_B.f_k = 0; full_loop_B.f_k < 20; full_loop_B.f_k++) {
      for (full_loop_B.F_tmp_n = 0; full_loop_B.F_tmp_n < 20;
           full_loop_B.F_tmp_n++) {
        full_loop_B.A2_tmp = full_loop_B.F_tmp_n + 20 * full_loop_B.f_k;
        full_loop_B.A4_o[full_loop_B.A2_tmp] = 0.0;
        for (full_loop_B.i8 = 0; full_loop_B.i8 < 20; full_loop_B.i8++) {
          full_loop_B.A4_o[full_loop_B.A2_tmp] += A[20 * full_loop_B.i8 +
            full_loop_B.F_tmp_n] * full_loop_B.U_j[20 * full_loop_B.f_k +
            full_loop_B.i8];
        }
      }
    }

    for (full_loop_B.f_k = 0; full_loop_B.f_k < 400; full_loop_B.f_k++) {
      full_loop_B.U_j[full_loop_B.f_k] = full_loop_B.A4_o[full_loop_B.f_k];
      full_loop_B.V[full_loop_B.f_k] = 12.0 * full_loop_B.A2[full_loop_B.f_k];
    }

    full_loop_B.d_m = 120.0;
  } else {
    for (full_loop_B.f_k = 0; full_loop_B.f_k < 20; full_loop_B.f_k++) {
      for (full_loop_B.F_tmp_n = 0; full_loop_B.F_tmp_n < 20;
           full_loop_B.F_tmp_n++) {
        full_loop_B.A2_tmp = full_loop_B.F_tmp_n + 20 * full_loop_B.f_k;
        full_loop_B.A3[full_loop_B.A2_tmp] = 0.0;
        for (full_loop_B.i8 = 0; full_loop_B.i8 < 20; full_loop_B.i8++) {
          full_loop_B.A3[full_loop_B.A2_tmp] += full_loop_B.A2[20 *
            full_loop_B.i8 + full_loop_B.F_tmp_n] * full_loop_B.A2[20 *
            full_loop_B.f_k + full_loop_B.i8];
        }
      }
    }

    if (m == 5) {
      for (full_loop_B.f_k = 0; full_loop_B.f_k < 400; full_loop_B.f_k++) {
        full_loop_B.U_j[full_loop_B.f_k] = 420.0 *
          full_loop_B.A2[full_loop_B.f_k] + full_loop_B.A3[full_loop_B.f_k];
      }

      for (full_loop_B.f_k = 0; full_loop_B.f_k < 20; full_loop_B.f_k++) {
        full_loop_B.A2_tmp = 20 * full_loop_B.f_k + full_loop_B.f_k;
        full_loop_B.U_j[full_loop_B.A2_tmp] += 15120.0;
      }

      for (full_loop_B.f_k = 0; full_loop_B.f_k < 20; full_loop_B.f_k++) {
        for (full_loop_B.F_tmp_n = 0; full_loop_B.F_tmp_n < 20;
             full_loop_B.F_tmp_n++) {
          full_loop_B.A2_tmp = full_loop_B.F_tmp_n + 20 * full_loop_B.f_k;
          full_loop_B.A4_o[full_loop_B.A2_tmp] = 0.0;
          for (full_loop_B.i8 = 0; full_loop_B.i8 < 20; full_loop_B.i8++) {
            full_loop_B.A4_o[full_loop_B.A2_tmp] += A[20 * full_loop_B.i8 +
              full_loop_B.F_tmp_n] * full_loop_B.U_j[20 * full_loop_B.f_k +
              full_loop_B.i8];
          }
        }
      }

      for (full_loop_B.f_k = 0; full_loop_B.f_k < 400; full_loop_B.f_k++) {
        full_loop_B.U_j[full_loop_B.f_k] = full_loop_B.A4_o[full_loop_B.f_k];
        full_loop_B.V[full_loop_B.f_k] = 30.0 * full_loop_B.A3[full_loop_B.f_k]
          + 3360.0 * full_loop_B.A2[full_loop_B.f_k];
      }

      full_loop_B.d_m = 30240.0;
    } else {
      for (full_loop_B.f_k = 0; full_loop_B.f_k < 20; full_loop_B.f_k++) {
        for (full_loop_B.F_tmp_n = 0; full_loop_B.F_tmp_n < 20;
             full_loop_B.F_tmp_n++) {
          full_loop_B.A2_tmp = full_loop_B.F_tmp_n + 20 * full_loop_B.f_k;
          full_loop_B.A4[full_loop_B.A2_tmp] = 0.0;
          for (full_loop_B.i8 = 0; full_loop_B.i8 < 20; full_loop_B.i8++) {
            full_loop_B.A4[full_loop_B.A2_tmp] += full_loop_B.A3[20 *
              full_loop_B.i8 + full_loop_B.F_tmp_n] * full_loop_B.A2[20 *
              full_loop_B.f_k + full_loop_B.i8];
          }
        }
      }

      if (m == 7) {
        for (full_loop_B.f_k = 0; full_loop_B.f_k < 400; full_loop_B.f_k++) {
          full_loop_B.U_j[full_loop_B.f_k] = (1512.0 *
            full_loop_B.A3[full_loop_B.f_k] + full_loop_B.A4[full_loop_B.f_k]) +
            277200.0 * full_loop_B.A2[full_loop_B.f_k];
        }

        for (full_loop_B.f_k = 0; full_loop_B.f_k < 20; full_loop_B.f_k++) {
          full_loop_B.A2_tmp = 20 * full_loop_B.f_k + full_loop_B.f_k;
          full_loop_B.U_j[full_loop_B.A2_tmp] += 8.64864E+6;
        }

        for (full_loop_B.f_k = 0; full_loop_B.f_k < 20; full_loop_B.f_k++) {
          for (full_loop_B.F_tmp_n = 0; full_loop_B.F_tmp_n < 20;
               full_loop_B.F_tmp_n++) {
            full_loop_B.A2_tmp = full_loop_B.F_tmp_n + 20 * full_loop_B.f_k;
            full_loop_B.A4_o[full_loop_B.A2_tmp] = 0.0;
            for (full_loop_B.i8 = 0; full_loop_B.i8 < 20; full_loop_B.i8++) {
              full_loop_B.A4_o[full_loop_B.A2_tmp] += A[20 * full_loop_B.i8 +
                full_loop_B.F_tmp_n] * full_loop_B.U_j[20 * full_loop_B.f_k +
                full_loop_B.i8];
            }
          }
        }

        for (full_loop_B.f_k = 0; full_loop_B.f_k < 400; full_loop_B.f_k++) {
          full_loop_B.U_j[full_loop_B.f_k] = full_loop_B.A4_o[full_loop_B.f_k];
          full_loop_B.V[full_loop_B.f_k] = (56.0 *
            full_loop_B.A4[full_loop_B.f_k] + 25200.0 *
            full_loop_B.A3[full_loop_B.f_k]) + 1.99584E+6 *
            full_loop_B.A2[full_loop_B.f_k];
        }

        full_loop_B.d_m = 1.729728E+7;
      } else if (m == 9) {
        for (full_loop_B.f_k = 0; full_loop_B.f_k < 20; full_loop_B.f_k++) {
          for (full_loop_B.F_tmp_n = 0; full_loop_B.F_tmp_n < 20;
               full_loop_B.F_tmp_n++) {
            full_loop_B.A2_tmp = full_loop_B.F_tmp_n + 20 * full_loop_B.f_k;
            full_loop_B.V[full_loop_B.A2_tmp] = 0.0;
            for (full_loop_B.i8 = 0; full_loop_B.i8 < 20; full_loop_B.i8++) {
              full_loop_B.V[full_loop_B.A2_tmp] += full_loop_B.A4[20 *
                full_loop_B.i8 + full_loop_B.F_tmp_n] * full_loop_B.A2[20 *
                full_loop_B.f_k + full_loop_B.i8];
            }
          }
        }

        for (full_loop_B.f_k = 0; full_loop_B.f_k < 400; full_loop_B.f_k++) {
          full_loop_B.U_j[full_loop_B.f_k] = ((3960.0 *
            full_loop_B.A4[full_loop_B.f_k] + full_loop_B.V[full_loop_B.f_k]) +
            2.16216E+6 * full_loop_B.A3[full_loop_B.f_k]) + 3.027024E+8 *
            full_loop_B.A2[full_loop_B.f_k];
        }

        for (full_loop_B.f_k = 0; full_loop_B.f_k < 20; full_loop_B.f_k++) {
          full_loop_B.A2_tmp = 20 * full_loop_B.f_k + full_loop_B.f_k;
          full_loop_B.U_j[full_loop_B.A2_tmp] += 8.8216128E+9;
        }

        for (full_loop_B.f_k = 0; full_loop_B.f_k < 20; full_loop_B.f_k++) {
          for (full_loop_B.F_tmp_n = 0; full_loop_B.F_tmp_n < 20;
               full_loop_B.F_tmp_n++) {
            full_loop_B.A2_tmp = full_loop_B.F_tmp_n + 20 * full_loop_B.f_k;
            full_loop_B.A4_o[full_loop_B.A2_tmp] = 0.0;
            for (full_loop_B.i8 = 0; full_loop_B.i8 < 20; full_loop_B.i8++) {
              full_loop_B.A4_o[full_loop_B.A2_tmp] += A[20 * full_loop_B.i8 +
                full_loop_B.F_tmp_n] * full_loop_B.U_j[20 * full_loop_B.f_k +
                full_loop_B.i8];
            }
          }
        }

        for (full_loop_B.f_k = 0; full_loop_B.f_k < 400; full_loop_B.f_k++) {
          full_loop_B.U_j[full_loop_B.f_k] = full_loop_B.A4_o[full_loop_B.f_k];
          full_loop_B.V[full_loop_B.f_k] = ((90.0 *
            full_loop_B.V[full_loop_B.f_k] + 110880.0 *
            full_loop_B.A4[full_loop_B.f_k]) + 3.027024E+7 *
            full_loop_B.A3[full_loop_B.f_k]) + 2.0756736E+9 *
            full_loop_B.A2[full_loop_B.f_k];
        }

        full_loop_B.d_m = 1.76432256E+10;
      } else {
        for (full_loop_B.f_k = 0; full_loop_B.f_k < 400; full_loop_B.f_k++) {
          full_loop_B.U_j[full_loop_B.f_k] = (3.352212864E+10 *
            full_loop_B.A4[full_loop_B.f_k] + 1.05594705216E+13 *
            full_loop_B.A3[full_loop_B.f_k]) + 1.1873537964288E+15 *
            full_loop_B.A2[full_loop_B.f_k];
        }

        for (full_loop_B.f_k = 0; full_loop_B.f_k < 20; full_loop_B.f_k++) {
          full_loop_B.A2_tmp = 20 * full_loop_B.f_k + full_loop_B.f_k;
          full_loop_B.U_j[full_loop_B.A2_tmp] += 3.238237626624E+16;
        }

        for (full_loop_B.f_k = 0; full_loop_B.f_k < 400; full_loop_B.f_k++) {
          full_loop_B.V[full_loop_B.f_k] = (16380.0 *
            full_loop_B.A3[full_loop_B.f_k] + full_loop_B.A4[full_loop_B.f_k]) +
            4.08408E+7 * full_loop_B.A2[full_loop_B.f_k];
        }

        for (full_loop_B.f_k = 0; full_loop_B.f_k < 20; full_loop_B.f_k++) {
          for (full_loop_B.F_tmp_n = 0; full_loop_B.F_tmp_n < 20;
               full_loop_B.F_tmp_n++) {
            full_loop_B.d_m = 0.0;
            for (full_loop_B.i8 = 0; full_loop_B.i8 < 20; full_loop_B.i8++) {
              full_loop_B.d_m += full_loop_B.A4[20 * full_loop_B.i8 +
                full_loop_B.f_k] * full_loop_B.V[20 * full_loop_B.F_tmp_n +
                full_loop_B.i8];
            }

            full_loop_B.A2_tmp = 20 * full_loop_B.F_tmp_n + full_loop_B.f_k;
            full_loop_B.A4_o[full_loop_B.A2_tmp] =
              full_loop_B.U_j[full_loop_B.A2_tmp] + full_loop_B.d_m;
          }
        }

        for (full_loop_B.f_k = 0; full_loop_B.f_k < 20; full_loop_B.f_k++) {
          for (full_loop_B.F_tmp_n = 0; full_loop_B.F_tmp_n < 20;
               full_loop_B.F_tmp_n++) {
            full_loop_B.A2_tmp = full_loop_B.F_tmp_n + 20 * full_loop_B.f_k;
            full_loop_B.U_j[full_loop_B.A2_tmp] = 0.0;
            for (full_loop_B.i8 = 0; full_loop_B.i8 < 20; full_loop_B.i8++) {
              full_loop_B.U_j[full_loop_B.A2_tmp] += A[20 * full_loop_B.i8 +
                full_loop_B.F_tmp_n] * full_loop_B.A4_o[20 * full_loop_B.f_k +
                full_loop_B.i8];
            }
          }
        }

        for (full_loop_B.f_k = 0; full_loop_B.f_k < 400; full_loop_B.f_k++) {
          full_loop_B.A4_o[full_loop_B.f_k] = (182.0 *
            full_loop_B.A4[full_loop_B.f_k] + 960960.0 *
            full_loop_B.A3[full_loop_B.f_k]) + 1.32324192E+9 *
            full_loop_B.A2[full_loop_B.f_k];
        }

        for (full_loop_B.f_k = 0; full_loop_B.f_k < 20; full_loop_B.f_k++) {
          for (full_loop_B.F_tmp_n = 0; full_loop_B.F_tmp_n < 20;
               full_loop_B.F_tmp_n++) {
            full_loop_B.d_m = 0.0;
            for (full_loop_B.i8 = 0; full_loop_B.i8 < 20; full_loop_B.i8++) {
              full_loop_B.d_m += full_loop_B.A4[20 * full_loop_B.i8 +
                full_loop_B.f_k] * full_loop_B.A4_o[20 * full_loop_B.F_tmp_n +
                full_loop_B.i8];
            }

            full_loop_B.A2_tmp = 20 * full_loop_B.F_tmp_n + full_loop_B.f_k;
            full_loop_B.V[full_loop_B.A2_tmp] =
              ((full_loop_B.A4[full_loop_B.A2_tmp] * 6.704425728E+11 +
                full_loop_B.d_m) + full_loop_B.A3[full_loop_B.A2_tmp] *
               1.29060195264E+14) + full_loop_B.A2[full_loop_B.A2_tmp] *
              7.7717703038976E+15;
          }
        }

        full_loop_B.d_m = 6.476475253248E+16;
      }
    }
  }

  for (full_loop_B.f_k = 0; full_loop_B.f_k < 20; full_loop_B.f_k++) {
    full_loop_B.A2_tmp = 20 * full_loop_B.f_k + full_loop_B.f_k;
    full_loop_B.V[full_loop_B.A2_tmp] += full_loop_B.d_m;
  }

  for (full_loop_B.f_k = 0; full_loop_B.f_k < 400; full_loop_B.f_k++) {
    full_loop_B.V[full_loop_B.f_k] -= full_loop_B.U_j[full_loop_B.f_k];
    full_loop_B.U_j[full_loop_B.f_k] *= 2.0;
  }

  full_loop_lusolve(full_loop_B.V, full_loop_B.U_j, F);
  for (full_loop_B.f_k = 0; full_loop_B.f_k < 20; full_loop_B.f_k++) {
    full_loop_B.F_tmp_n = 20 * full_loop_B.f_k + full_loop_B.f_k;
    F[full_loop_B.F_tmp_n]++;
  }
}

static void full_loop_expm(real_T A[400], real_T F[400])
{
  static const uint8_T tmp[5] = { 3U, 5U, 7U, 9U, 13U };

  boolean_T exitg1;
  for (full_loop_B.b_j_f = 0; full_loop_B.b_j_f < 5; full_loop_B.b_j_f++) {
    full_loop_B.m_vals[full_loop_B.b_j_f] = tmp[full_loop_B.b_j_f];
  }

  full_loop_B.theta[0] = 0.01495585217958292;
  full_loop_B.theta[1] = 0.253939833006323;
  full_loop_B.theta[2] = 0.95041789961629319;
  full_loop_B.theta[3] = 2.097847961257068;
  full_loop_B.theta[4] = 5.3719203511481517;
  full_loop_B.normA = 0.0;
  full_loop_B.b_j_f = 0;
  exitg1 = false;
  while ((!exitg1) && (full_loop_B.b_j_f < 20)) {
    full_loop_B.s = 0.0;
    for (full_loop_B.b_i_c = 0; full_loop_B.b_i_c < 20; full_loop_B.b_i_c++) {
      full_loop_B.s += fabs(A[20 * full_loop_B.b_j_f + full_loop_B.b_i_c]);
    }

    if (rtIsNaN(full_loop_B.s)) {
      full_loop_B.normA = (rtNaN);
      exitg1 = true;
    } else {
      if (full_loop_B.s > full_loop_B.normA) {
        full_loop_B.normA = full_loop_B.s;
      }

      full_loop_B.b_j_f++;
    }
  }

  if (full_loop_B.normA <= 5.3719203511481517) {
    full_loop_B.b_i_c = 0;
    exitg1 = false;
    while ((!exitg1) && (full_loop_B.b_i_c < 5)) {
      if (full_loop_B.normA <= full_loop_B.theta[full_loop_B.b_i_c]) {
        full_lo_PadeApproximantOfDegree(A, full_loop_B.m_vals[full_loop_B.b_i_c],
          F);
        exitg1 = true;
      } else {
        full_loop_B.b_i_c++;
      }
    }
  } else {
    full_loop_B.normA /= 5.3719203511481517;
    if ((!rtIsInf(full_loop_B.normA)) && (!rtIsNaN(full_loop_B.normA))) {
      full_loop_B.normA = frexp(full_loop_B.normA, &full_loop_B.b_e_f);
    } else {
      full_loop_B.b_e_f = 0;
    }

    full_loop_B.s = full_loop_B.b_e_f;
    if (full_loop_B.normA == 0.5) {
      full_loop_B.s = static_cast<real_T>(full_loop_B.b_e_f) - 1.0;
    }

    full_loop_B.normA = rt_powd_snf(2.0, full_loop_B.s);
    for (full_loop_B.b_j_f = 0; full_loop_B.b_j_f < 400; full_loop_B.b_j_f++) {
      A[full_loop_B.b_j_f] /= full_loop_B.normA;
    }

    full_lo_PadeApproximantOfDegree(A, 13, F);
    full_loop_B.b_e_f = static_cast<int32_T>(full_loop_B.s) - 1;
    for (full_loop_B.b_i_c = 0; full_loop_B.b_i_c <= full_loop_B.b_e_f;
         full_loop_B.b_i_c++) {
      for (full_loop_B.b_j_f = 0; full_loop_B.b_j_f < 20; full_loop_B.b_j_f++) {
        for (full_loop_B.i6 = 0; full_loop_B.i6 < 20; full_loop_B.i6++) {
          full_loop_B.F_tmp = full_loop_B.b_j_f + 20 * full_loop_B.i6;
          full_loop_B.F[full_loop_B.F_tmp] = 0.0;
          for (full_loop_B.i7 = 0; full_loop_B.i7 < 20; full_loop_B.i7++) {
            full_loop_B.F[full_loop_B.F_tmp] += F[20 * full_loop_B.i7 +
              full_loop_B.b_j_f] * F[20 * full_loop_B.i6 + full_loop_B.i7];
          }
        }
      }

      memcpy(&F[0], &full_loop_B.F[0], 400U * sizeof(real_T));
    }
  }
}

static void full_loop_TrimPlant_stepImpl(TrimPlant_full_loop_T *b_this, const
  real_T u[8], real_T Ts, const real_T y[12], real_T A[144], real_T B[96],
  real_T C[144], real_T D[96], real_T U[8], real_T Y[12], real_T X[12], real_T
  DX[12])
{
  //  Lineariser le model dynamique
  full_loop_AUVStateJacobianFcn(y, b_this->Ac, b_this->Bc, b_this->Cc,
    b_this->Dc);

  // Convertir le modèle dans le domaine echantillione (z)
  for (full_loop_B.i5 = 0; full_loop_B.i5 < 12; full_loop_B.i5++) {
    for (full_loop_B.i4 = 0; full_loop_B.i4 < 12; full_loop_B.i4++) {
      full_loop_B.b_this[full_loop_B.i4 + 20 * full_loop_B.i5] = b_this->Ac[12 *
        full_loop_B.i5 + full_loop_B.i4] * Ts;
    }
  }

  for (full_loop_B.i5 = 0; full_loop_B.i5 < 8; full_loop_B.i5++) {
    for (full_loop_B.i4 = 0; full_loop_B.i4 < 12; full_loop_B.i4++) {
      full_loop_B.b_this[full_loop_B.i4 + 20 * (full_loop_B.i5 + 12)] =
        b_this->Bc[12 * full_loop_B.i5 + full_loop_B.i4] * Ts;
    }
  }

  for (full_loop_B.i5 = 0; full_loop_B.i5 < 20; full_loop_B.i5++) {
    memset(&full_loop_B.b_this[full_loop_B.i5 * 20 + 12], 0, sizeof(real_T) <<
           3U);
  }

  full_loop_expm(full_loop_B.b_this, full_loop_B.M);
  for (full_loop_B.i5 = 0; full_loop_B.i5 < 12; full_loop_B.i5++) {
    memcpy(&A[full_loop_B.i5 * 12], &full_loop_B.M[full_loop_B.i5 * 20], 12U *
           sizeof(real_T));
  }

  for (full_loop_B.i5 = 0; full_loop_B.i5 < 8; full_loop_B.i5++) {
    memcpy(&B[full_loop_B.i5 * 12], &full_loop_B.M[full_loop_B.i5 * 20 + 240],
           12U * sizeof(real_T));
  }

  memcpy(&C[0], &b_this->Cc[0], 144U * sizeof(real_T));
  memcpy(&D[0], &b_this->Dc[0], 96U * sizeof(real_T));

  //  Calculer les Conditions Nominal
  memcpy(&U[0], &u[0], sizeof(real_T) << 3U);
  for (full_loop_B.i5 = 0; full_loop_B.i5 < 12; full_loop_B.i5++) {
    full_loop_B.b_this_o[full_loop_B.i5] = 0.0;
    for (full_loop_B.i4 = 0; full_loop_B.i4 < 12; full_loop_B.i4++) {
      full_loop_B.b_this_o[full_loop_B.i5] += b_this->Cc[12 * full_loop_B.i4 +
        full_loop_B.i5] * y[full_loop_B.i4];
    }

    full_loop_B.b_this_l[full_loop_B.i5] = 0.0;
    for (full_loop_B.i4 = 0; full_loop_B.i4 < 8; full_loop_B.i4++) {
      full_loop_B.b_this_l[full_loop_B.i5] += b_this->Dc[12 * full_loop_B.i4 +
        full_loop_B.i5] * u[full_loop_B.i4];
    }

    Y[full_loop_B.i5] = full_loop_B.b_this_o[full_loop_B.i5] +
      full_loop_B.b_this_l[full_loop_B.i5];
    X[full_loop_B.i5] = y[full_loop_B.i5];
  }

  for (full_loop_B.i5 = 0; full_loop_B.i5 < 12; full_loop_B.i5++) {
    full_loop_B.b_this_o[full_loop_B.i5] = 0.0;
    for (full_loop_B.i4 = 0; full_loop_B.i4 < 12; full_loop_B.i4++) {
      full_loop_B.b_this_o[full_loop_B.i5] += full_loop_B.M[20 * full_loop_B.i4
        + full_loop_B.i5] * y[full_loop_B.i4];
    }

    full_loop_B.b_this_l[full_loop_B.i5] = 0.0;
    for (full_loop_B.i4 = 0; full_loop_B.i4 < 8; full_loop_B.i4++) {
      full_loop_B.b_this_l[full_loop_B.i5] += full_loop_B.M[(full_loop_B.i4 + 12)
        * 20 + full_loop_B.i5] * u[full_loop_B.i4];
    }

    DX[full_loop_B.i5] = (full_loop_B.b_this_o[full_loop_B.i5] +
                          full_loop_B.b_this_l[full_loop_B.i5]) -
      y[full_loop_B.i5];
  }
}

static void full_loop_SystemCore_step(TrimPlant_full_loop_T *obj, const real_T
  varargin_1[8], real_T varargin_2, const real_T varargin_3[12], real_T
  varargout_1[144], real_T varargout_2[96], real_T varargout_3[144], real_T
  varargout_4[96], real_T varargout_5[8], real_T varargout_6[12], real_T
  varargout_7[12], real_T varargout_8[12])
{
  full_loop_TrimPlant_stepImpl(obj, varargin_1, varargin_2, varargin_3,
    varargout_1, varargout_2, varargout_3, varargout_4, varargout_5, varargout_6,
    varargout_7, varargout_8);
}

// Function for MATLAB Function: '<S98>/FixedHorizonOptimizer'
static void full_loop_mpc_plantupdate(const real_T a[144], real_T b[96], const
  real_T c[144], real_T b_A[400], real_T b_B[580], real_T b_C[240], const real_T
  b_D[348], const real_T b_mvindex[8], const real_T b_myindex[12], const real_T
  b_Uscale[8], const real_T b_Yscale[12], real_T Bu[160], real_T Bv[20], real_T
  Cm[240], real_T Dv[12], real_T Dvm[12], real_T QQ[400], real_T RR[144], real_T
  NN[240])
{
  int8_T UnknownIn[28];
  int32_T i;
  int32_T i_0;
  int32_T b_tmp;
  int32_T CovMat_tmp;
  for (i_0 = 0; i_0 < 8; i_0++) {
    for (i = 0; i < 12; i++) {
      b_tmp = 12 * i_0 + i;
      b[b_tmp] *= b_Uscale[i_0];
    }
  }

  for (i_0 = 0; i_0 < 12; i_0++) {
    for (i = 0; i < 12; i++) {
      b_tmp = 12 * i_0 + i;
      b_C[b_tmp] = c[b_tmp] / b_Yscale[i];
      b_A[i + 20 * i_0] = a[b_tmp];
    }
  }

  for (i_0 = 0; i_0 < 8; i_0++) {
    for (i = 0; i < 12; i++) {
      b_B[i + 20 * i_0] = b[(static_cast<int32_T>(b_mvindex[i_0]) - 1) * 12 + i];
    }

    memcpy(&Bu[i_0 * 20], &b_B[i_0 * 20], 20U * sizeof(real_T));
  }

  for (i_0 = 0; i_0 < 20; i_0++) {
    Bv[i_0] = b_B[i_0 + 160];
    for (i = 0; i < 12; i++) {
      Cm[i + 12 * i_0] = b_C[(12 * i_0 + static_cast<int32_T>(b_myindex[i])) - 1];
    }
  }

  for (i_0 = 0; i_0 < 12; i_0++) {
    Dv[i_0] = b_D[i_0 + 96];
    Dvm[i_0] = b_D[static_cast<int32_T>(b_myindex[i_0]) + 95];
  }

  for (i_0 = 0; i_0 < 28; i_0++) {
    UnknownIn[i_0] = 0;
  }

  for (i_0 = 0; i_0 < 8; i_0++) {
    UnknownIn[i_0] = static_cast<int8_T>(i_0 + 1);
  }

  for (i_0 = 0; i_0 < 20; i_0++) {
    UnknownIn[i_0 + 8] = static_cast<int8_T>(i_0 + 10);
  }

  for (i_0 = 0; i_0 < 28; i_0++) {
    for (i = 0; i < 20; i++) {
      full_loop_B.b_B[i + (i_0 << 5)] = b_B[(UnknownIn[i_0] - 1) * 20 + i];
    }

    for (i = 0; i < 12; i++) {
      full_loop_B.b_B[(i + (i_0 << 5)) + 20] = b_D[((UnknownIn[i_0] - 1) * 12 +
        static_cast<int32_T>(b_myindex[i])) - 1];
    }
  }

  for (i_0 = 0; i_0 < 20; i_0++) {
    for (i = 0; i < 28; i++) {
      full_loop_B.b_B_f[i + 28 * i_0] = b_B[(UnknownIn[i] - 1) * 20 + i_0];
    }
  }

  for (i_0 = 0; i_0 < 12; i_0++) {
    for (i = 0; i < 28; i++) {
      full_loop_B.b_B_f[i + 28 * (i_0 + 20)] = b_D[((UnknownIn[i] - 1) * 12 +
        static_cast<int32_T>(b_myindex[i_0])) - 1];
    }
  }

  for (i_0 = 0; i_0 < 32; i_0++) {
    for (i = 0; i < 32; i++) {
      CovMat_tmp = i + (i_0 << 5);
      full_loop_B.CovMat[CovMat_tmp] = 0.0;
      for (b_tmp = 0; b_tmp < 28; b_tmp++) {
        full_loop_B.CovMat[CovMat_tmp] += full_loop_B.b_B[(b_tmp << 5) + i] *
          full_loop_B.b_B_f[28 * i_0 + b_tmp];
      }
    }
  }

  for (i_0 = 0; i_0 < 20; i_0++) {
    memcpy(&QQ[i_0 * 20], &full_loop_B.CovMat[i_0 << 5], 20U * sizeof(real_T));
  }

  for (i_0 = 0; i_0 < 12; i_0++) {
    memcpy(&RR[i_0 * 12], &full_loop_B.CovMat[(i_0 << 5) + 660], 12U * sizeof
           (real_T));
    memcpy(&NN[i_0 * 20], &full_loop_B.CovMat[(i_0 << 5) + 640], 20U * sizeof
           (real_T));
  }
}

// Function for MATLAB Function: '<S98>/FixedHorizonOptimizer'
static real_T full_loop_mod_id(real_T x)
{
  real_T r;
  if (rtIsNaN(x)) {
    r = (rtNaN);
  } else if (rtIsInf(x)) {
    r = (rtNaN);
  } else if (x == 0.0) {
    r = 0.0;
  } else {
    r = fmod(x, full_loop_nu);
    if (r == 0.0) {
      r = 0.0;
    } else {
      if (x < 0.0) {
        r += full_loop_nu;
      }
    }
  }

  return r;
}

// Function for MATLAB Function: '<S98>/FixedHorizonOptimizer'
static real_T full_loop_mod_i(real_T x)
{
  real_T r;
  if (rtIsNaN(x)) {
    r = (rtNaN);
  } else if (rtIsInf(x)) {
    r = (rtNaN);
  } else if (x == 0.0) {
    r = 0.0;
  } else {
    r = fmod(x, full_loop_ny);
    if (r == 0.0) {
      r = 0.0;
    } else {
      if (x < 0.0) {
        r += full_loop_ny;
      }
    }
  }

  return r;
}

// Function for MATLAB Function: '<S98>/FixedHorizonOptimizer'
static void full_loop_mpc_updateFromNominal(real_T b_Mlim[4], const real_T
  b_Mrows[4], const real_T U0[8], const real_T b_Uscale[8], const real_T
  old_mvoff[8], const real_T b_mvindex[8], real_T b_utarget[80], const real_T
  Y0[12], const real_T b_Yscale[12], const real_T old_yoff[12], const real_T
  b_myindex[12], const real_T X0[12], real_T b_xoff[20], const real_T DX0[12],
  real_T Bv[220], real_T new_mvoff[8], real_T new_yoff[12], real_T new_myoff[12])
{
  int32_T i;
  real_T U;
  int32_T new_mvoff_tmp;
  for (i = 0; i < 8; i++) {
    full_loop_B.U_p[i] = U0[i] / b_Uscale[i];
  }

  for (i = 0; i < 12; i++) {
    new_yoff[i] = Y0[i] / b_Yscale[i];
  }

  for (i = 0; i < 8; i++) {
    new_mvoff_tmp = static_cast<int32_T>(b_mvindex[i]) - 1;
    new_mvoff[i] = U0[new_mvoff_tmp] / b_Uscale[new_mvoff_tmp];
  }

  for (i = 0; i < 12; i++) {
    new_myoff[i] = new_yoff[static_cast<int32_T>(b_myindex[i]) - 1];
  }

  if (b_Mrows[0] <= 120.0) {
    i = static_cast<int32_T>(full_loop_mod_i(b_Mrows[0] - 1.0) + 1.0) - 1;
    b_Mlim[0] += old_yoff[i] - new_yoff[i];
  } else if (b_Mrows[0] <= 240.0) {
    i = static_cast<int32_T>(full_loop_mod_i((b_Mrows[0] - 120.0) - 1.0) + 1.0)
      - 1;
    b_Mlim[0] -= old_yoff[i] - new_yoff[i];
  } else if (b_Mrows[0] <= 320.0) {
    i = static_cast<int32_T>(full_loop_mod_id((b_Mrows[0] - 240.0) - 1.0) + 1.0)
      - 1;
    b_Mlim[0] += old_mvoff[i] - full_loop_B.U_p[static_cast<int32_T>(b_mvindex[i])
      - 1];
  } else {
    if (b_Mrows[0] <= 400.0) {
      i = static_cast<int32_T>(full_loop_mod_id(((b_Mrows[0] - 240.0) - 80.0) -
        1.0) + 1.0) - 1;
      b_Mlim[0] -= old_mvoff[i] - full_loop_B.U_p[static_cast<int32_T>
        (b_mvindex[i]) - 1];
    }
  }

  if (b_Mrows[1] <= 120.0) {
    i = static_cast<int32_T>(full_loop_mod_i(b_Mrows[1] - 1.0) + 1.0) - 1;
    b_Mlim[1] += old_yoff[i] - new_yoff[i];
  } else if (b_Mrows[1] <= 240.0) {
    i = static_cast<int32_T>(full_loop_mod_i((b_Mrows[1] - 120.0) - 1.0) + 1.0)
      - 1;
    b_Mlim[1] -= old_yoff[i] - new_yoff[i];
  } else if (b_Mrows[1] <= 320.0) {
    i = static_cast<int32_T>(full_loop_mod_id((b_Mrows[1] - 240.0) - 1.0) + 1.0)
      - 1;
    b_Mlim[1] += old_mvoff[i] - full_loop_B.U_p[static_cast<int32_T>(b_mvindex[i])
      - 1];
  } else {
    if (b_Mrows[1] <= 400.0) {
      i = static_cast<int32_T>(full_loop_mod_id(((b_Mrows[1] - 240.0) - 80.0) -
        1.0) + 1.0) - 1;
      b_Mlim[1] -= old_mvoff[i] - full_loop_B.U_p[static_cast<int32_T>
        (b_mvindex[i]) - 1];
    }
  }

  if (b_Mrows[2] <= 120.0) {
    i = static_cast<int32_T>(full_loop_mod_i(b_Mrows[2] - 1.0) + 1.0) - 1;
    b_Mlim[2] += old_yoff[i] - new_yoff[i];
  } else if (b_Mrows[2] <= 240.0) {
    i = static_cast<int32_T>(full_loop_mod_i((b_Mrows[2] - 120.0) - 1.0) + 1.0)
      - 1;
    b_Mlim[2] -= old_yoff[i] - new_yoff[i];
  } else if (b_Mrows[2] <= 320.0) {
    i = static_cast<int32_T>(full_loop_mod_id((b_Mrows[2] - 240.0) - 1.0) + 1.0)
      - 1;
    b_Mlim[2] += old_mvoff[i] - full_loop_B.U_p[static_cast<int32_T>(b_mvindex[i])
      - 1];
  } else {
    if (b_Mrows[2] <= 400.0) {
      i = static_cast<int32_T>(full_loop_mod_id(((b_Mrows[2] - 240.0) - 80.0) -
        1.0) + 1.0) - 1;
      b_Mlim[2] -= old_mvoff[i] - full_loop_B.U_p[static_cast<int32_T>
        (b_mvindex[i]) - 1];
    }
  }

  if (b_Mrows[3] <= 120.0) {
    i = static_cast<int32_T>(full_loop_mod_i(b_Mrows[3] - 1.0) + 1.0) - 1;
    b_Mlim[3] += old_yoff[i] - new_yoff[i];
  } else if (b_Mrows[3] <= 240.0) {
    i = static_cast<int32_T>(full_loop_mod_i((b_Mrows[3] - 120.0) - 1.0) + 1.0)
      - 1;
    b_Mlim[3] -= old_yoff[i] - new_yoff[i];
  } else if (b_Mrows[3] <= 320.0) {
    i = static_cast<int32_T>(full_loop_mod_id((b_Mrows[3] - 240.0) - 1.0) + 1.0)
      - 1;
    b_Mlim[3] += old_mvoff[i] - full_loop_B.U_p[static_cast<int32_T>(b_mvindex[i])
      - 1];
  } else {
    if (b_Mrows[3] <= 400.0) {
      i = static_cast<int32_T>(full_loop_mod_id(((b_Mrows[3] - 240.0) - 80.0) -
        1.0) + 1.0) - 1;
      b_Mlim[3] -= old_mvoff[i] - full_loop_B.U_p[static_cast<int32_T>
        (b_mvindex[i]) - 1];
    }
  }

  for (new_mvoff_tmp = 0; new_mvoff_tmp < 8; new_mvoff_tmp++) {
    U = full_loop_B.U_p[static_cast<int32_T>(b_mvindex[new_mvoff_tmp]) - 1];
    for (i = 0; i < 10; i++) {
      full_loop_B.b_utarget_m[i] = (b_utarget[(i << 3) + new_mvoff_tmp] +
        old_mvoff[new_mvoff_tmp]) - U;
    }

    for (i = 0; i < 10; i++) {
      b_utarget[(i << 3) + new_mvoff_tmp] = full_loop_B.b_utarget_m[i];
    }
  }

  memcpy(&b_xoff[0], &X0[0], 12U * sizeof(real_T));
  memcpy(&Bv[0], &DX0[0], 12U * sizeof(real_T));
}

// Function for MATLAB Function: '<S98>/FixedHorizonOptimizer'
static void full_loop_mpcblock_refmd(const real_T ref[12], const real_T b_yoff
  [12], const real_T b_RYscale[12], real_T rseq[120], real_T vseq[11], real_T *v)
{
  int32_T i;
  int32_T j;
  for (i = 0; i < 11; i++) {
    vseq[i] = 1.0;
  }

  for (i = 0; i < 10; i++) {
    for (j = 0; j < 12; j++) {
      rseq[j + i * 12] = ref[j] * b_RYscale[j] - b_yoff[j];
    }
  }

  *v = 1.0;
}

// Function for MATLAB Function: '<S98>/FixedHorizonOptimizer'
static void full_loop_eye(real_T b_I[144])
{
  int32_T k;
  memset(&b_I[0], 0, 144U * sizeof(real_T));
  for (k = 0; k < 12; k++) {
    b_I[k + 12 * k] = 1.0;
  }
}

// Function for MATLAB Function: '<S98>/FixedHorizonOptimizer'
static void full_loop_mpc_constraintcoef(const real_T b_A[400], const real_T Bu
  [1760], const real_T Bv[220], const real_T b_C[240], const real_T Dv[132],
  const real_T b_Jm[1280], real_T b_SuJm[1920], real_T b_Sx[2400], real_T b_Su1
  [960], real_T b_Hv[1320])
{
  int8_T rows[12];
  int32_T i;
  int8_T i_0;
  int32_T i_1;
  int32_T i_2;
  int32_T i_3;
  real_T tmp;
  int32_T CA_tmp;
  for (i_1 = 0; i_1 < 12; i_1++) {
    for (i_2 = 0; i_2 < 20; i_2++) {
      CA_tmp = i_1 + 12 * i_2;
      full_loop_B.CA[CA_tmp] = 0.0;
      for (i_3 = 0; i_3 < 20; i_3++) {
        full_loop_B.CA[CA_tmp] += b_C[12 * i_3 + i_1] * b_A[20 * i_2 + i_3];
      }
    }

    for (i_2 = 0; i_2 < 8; i_2++) {
      CA_tmp = i_1 + 12 * i_2;
      full_loop_B.Sum_c[CA_tmp] = 0.0;
      for (i_3 = 0; i_3 < 20; i_3++) {
        full_loop_B.Sum_c[CA_tmp] += b_C[12 * i_3 + i_1] * Bu[20 * i_2 + i_3];
      }
    }

    full_loop_B.b_C_m[i_1] = 0.0;
    for (i_2 = 0; i_2 < 20; i_2++) {
      full_loop_B.b_C_m[i_1] += b_C[12 * i_2 + i_1] * Bv[i_2];
    }

    b_Hv[i_1] = full_loop_B.b_C_m[i_1];
    b_Hv[i_1 + 120] = Dv[i_1];
  }

  for (i_1 = 0; i_1 < 9; i_1++) {
    memset(&b_Hv[i_1 * 120 + 240], 0, 12U * sizeof(real_T));
  }

  for (i_1 = 0; i_1 < 11; i_1++) {
    memset(&b_Hv[i_1 * 120 + 12], 0, 108U * sizeof(real_T));
  }

  for (i_1 = 0; i_1 < 20; i_1++) {
    memcpy(&b_Sx[i_1 * 120], &full_loop_B.CA[i_1 * 12], 12U * sizeof(real_T));
    memset(&b_Sx[i_1 * 120 + 12], 0, 108U * sizeof(real_T));
  }

  for (i_1 = 0; i_1 < 8; i_1++) {
    memcpy(&b_Su1[i_1 * 120], &full_loop_B.Sum_c[i_1 * 12], 12U * sizeof(real_T));
    memset(&b_Su1[i_1 * 120 + 12], 0, 108U * sizeof(real_T));
    memcpy(&full_loop_B.Su[i_1 * 120], &full_loop_B.Sum_c[i_1 * 12], 12U *
           sizeof(real_T));
  }

  for (i_1 = 0; i_1 < 72; i_1++) {
    memset(&full_loop_B.Su[i_1 * 120 + 960], 0, 12U * sizeof(real_T));
  }

  for (i_1 = 0; i_1 < 80; i_1++) {
    memset(&full_loop_B.Su[i_1 * 120 + 12], 0, 108U * sizeof(real_T));
  }

  for (i = 0; i < 9; i++) {
    i_0 = static_cast<int8_T>((i + 1) * 12 + 1);
    for (i_1 = 0; i_1 < 12; i_1++) {
      rows[i_1] = static_cast<int8_T>(i_1 + i_0);
      for (i_2 = 0; i_2 < 8; i_2++) {
        tmp = 0.0;
        for (i_3 = 0; i_3 < 20; i_3++) {
          tmp += full_loop_B.CA[12 * i_3 + i_1] * Bu[20 * i_2 + i_3];
        }

        CA_tmp = 12 * i_2 + i_1;
        full_loop_B.Sum_c[CA_tmp] += tmp;
      }
    }

    for (i_1 = 0; i_1 < 8; i_1++) {
      for (i_2 = 0; i_2 < 12; i_2++) {
        CA_tmp = 12 * i_1 + i_2;
        b_Su1[(rows[i_2] + 120 * i_1) - 1] = full_loop_B.Sum_c[CA_tmp];
        full_loop_B.Sum_m[CA_tmp] = full_loop_B.Sum_c[CA_tmp];
      }
    }

    for (i_1 = 0; i_1 < 72; i_1++) {
      for (i_2 = 0; i_2 < 12; i_2++) {
        full_loop_B.Sum_m[i_2 + 12 * (i_1 + 8)] = full_loop_B.Su[(120 * i_1 +
          rows[i_2]) - 13];
      }
    }

    for (i_1 = 0; i_1 < 80; i_1++) {
      for (i_2 = 0; i_2 < 12; i_2++) {
        full_loop_B.Su[(rows[i_2] + 120 * i_1) - 1] = full_loop_B.Sum_m[12 * i_1
          + i_2];
      }
    }

    for (i_1 = 0; i_1 < 12; i_1++) {
      full_loop_B.b_C_m[i_1] = 0.0;
      for (i_2 = 0; i_2 < 20; i_2++) {
        full_loop_B.b_C_m[i_1] += full_loop_B.CA[12 * i_2 + i_1] * Bv[i_2];
      }

      full_loop_B.CA_j[i_1] = full_loop_B.b_C_m[i_1];
    }

    for (i_1 = 0; i_1 < 10; i_1++) {
      for (i_2 = 0; i_2 < 12; i_2++) {
        full_loop_B.CA_j[i_2 + 12 * (i_1 + 1)] = b_Hv[(120 * i_1 + rows[i_2]) -
          13];
      }
    }

    for (i_1 = 0; i_1 < 11; i_1++) {
      for (i_2 = 0; i_2 < 12; i_2++) {
        b_Hv[(rows[i_2] + 120 * i_1) - 1] = full_loop_B.CA_j[12 * i_1 + i_2];
      }
    }

    for (i_1 = 0; i_1 < 12; i_1++) {
      for (i_2 = 0; i_2 < 20; i_2++) {
        CA_tmp = i_1 + 12 * i_2;
        full_loop_B.CA_m[CA_tmp] = 0.0;
        for (i_3 = 0; i_3 < 20; i_3++) {
          full_loop_B.CA_m[CA_tmp] += full_loop_B.CA[12 * i_3 + i_1] * b_A[20 *
            i_2 + i_3];
        }
      }
    }

    memcpy(&full_loop_B.CA[0], &full_loop_B.CA_m[0], 240U * sizeof(real_T));
    for (i_1 = 0; i_1 < 20; i_1++) {
      for (i_2 = 0; i_2 < 12; i_2++) {
        b_Sx[(rows[i_2] + 120 * i_1) - 1] = full_loop_B.CA[12 * i_1 + i_2];
      }
    }
  }

  for (i_1 = 0; i_1 < 16; i_1++) {
    for (i_2 = 0; i_2 < 120; i_2++) {
      i = i_2 + 120 * i_1;
      b_SuJm[i] = 0.0;
      for (i_3 = 0; i_3 < 80; i_3++) {
        b_SuJm[i] += full_loop_B.Su[120 * i_3 + i_2] * b_Jm[80 * i_1 + i_3];
      }
    }
  }
}

// Function for MATLAB Function: '<S98>/FixedHorizonOptimizer'
static void full_loop_eye_c(real_T b_I[64])
{
  int32_T k;
  memset(&b_I[0], 0, sizeof(real_T) << 6U);
  for (k = 0; k < 8; k++) {
    b_I[k + (k << 3)] = 1.0;
  }
}

// Function for MATLAB Function: '<S98>/FixedHorizonOptimizer'
static void full_loop_kron(const real_T b_A[100], const real_T b_B[64], real_T
  K[6400])
{
  int32_T kidx;
  int32_T b_j1;
  int32_T j2;
  int32_T i1;
  int32_T i2;
  kidx = -1;
  for (b_j1 = 0; b_j1 < 10; b_j1++) {
    for (j2 = 0; j2 < 8; j2++) {
      for (i1 = 0; i1 < 10; i1++) {
        for (i2 = 0; i2 < 8; i2++) {
          kidx++;
          K[kidx] = b_A[10 * b_j1 + i1] * b_B[(j2 << 3) + i2];
        }
      }
    }
  }
}

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

// Function for MATLAB Function: '<S98>/FixedHorizonOptimizer'
static void full_loop_WtMult(const real_T W[8], const real_T M[1280], real_T nwt,
  real_T WM[1280])
{
  int16_T ixw;
  int32_T i;
  real_T W_0;
  int32_T i_0;
  int32_T WM_tmp;
  ixw = 1;
  for (i = 0; i < 80; i++) {
    W_0 = W[ixw - 1];
    for (i_0 = 0; i_0 < 16; i_0++) {
      WM_tmp = 80 * i_0 + i;
      WM[WM_tmp] = M[WM_tmp] * W_0;
    }

    i_0 = ixw + 1;
    if (i_0 > 32767) {
      i_0 = 32767;
    }

    ixw = static_cast<int16_T>(i_0);
    if (static_cast<int16_T>(i_0) > 8) {
      W_0 = rt_roundd_snf(8.0 - nwt);
      if (W_0 < 32768.0) {
        if (W_0 >= -32768.0) {
          ixw = static_cast<int16_T>(W_0);
        } else {
          ixw = MIN_int16_T;
        }
      } else {
        ixw = MAX_int16_T;
      }

      i_0 = ixw + 1;
      if (i_0 > 32767) {
        i_0 = 32767;
      }

      ixw = static_cast<int16_T>(i_0);
    }
  }
}

// Function for MATLAB Function: '<S98>/FixedHorizonOptimizer'
static void full_loop_mpc_calculatehessian(const real_T b_Wy[12], const real_T
  b_Wu[8], const real_T b_Wdu[8], const real_T b_SuJm[1920], const real_T I2Jm
  [1280], const real_T b_Jm[1280], const real_T b_I1[640], const real_T b_Su1
  [960], const real_T b_Sx[2400], const real_T b_Hv[1320], real_T nmv, real_T
  b_ny, real_T b_H[256], real_T b_Ku1[128], real_T b_Kut[1280], real_T b_Kx[320],
  real_T b_Kv[176], real_T b_Kr[1920])
{
  int16_T ixw;
  int32_T i;
  int32_T i_0;
  int32_T b_Kr_tmp;
  int32_T b_SuJm_tmp;
  int32_T tmp;
  int32_T tmp_0;
  ixw = 1;
  for (i = 0; i < 120; i++) {
    full_loop_B.b_Wy = b_Wy[ixw - 1];
    for (i_0 = 0; i_0 < 16; i_0++) {
      b_Kr_tmp = 120 * i_0 + i;
      b_Kr[b_Kr_tmp] = b_SuJm[b_Kr_tmp] * full_loop_B.b_Wy;
    }

    i_0 = ixw + 1;
    if (i_0 > 32767) {
      i_0 = 32767;
    }

    ixw = static_cast<int16_T>(i_0);
    if (static_cast<int16_T>(i_0) > 12) {
      full_loop_B.b_Wy = rt_roundd_snf(12.0 - b_ny);
      if (full_loop_B.b_Wy < 32768.0) {
        if (full_loop_B.b_Wy >= -32768.0) {
          ixw = static_cast<int16_T>(full_loop_B.b_Wy);
        } else {
          ixw = MIN_int16_T;
        }
      } else {
        ixw = MAX_int16_T;
      }

      i_0 = ixw + 1;
      if (i_0 > 32767) {
        i_0 = 32767;
      }

      ixw = static_cast<int16_T>(i_0);
    }
  }

  full_loop_WtMult(b_Wu, I2Jm, nmv, b_Kut);
  full_loop_WtMult(b_Wdu, b_Jm, nmv, full_loop_B.dv3);
  for (i_0 = 0; i_0 < 16; i_0++) {
    for (i = 0; i < 16; i++) {
      b_SuJm_tmp = i_0 + (i << 4);
      full_loop_B.b_SuJm[b_SuJm_tmp] = 0.0;
      for (b_Kr_tmp = 0; b_Kr_tmp < 120; b_Kr_tmp++) {
        full_loop_B.b_SuJm[b_SuJm_tmp] += b_SuJm[120 * i_0 + b_Kr_tmp] * b_Kr
          [120 * i + b_Kr_tmp];
      }

      full_loop_B.b_Jm[b_SuJm_tmp] = 0.0;
      full_loop_B.b_Wy = 0.0;
      for (b_Kr_tmp = 0; b_Kr_tmp < 80; b_Kr_tmp++) {
        tmp = 80 * i_0 + b_Kr_tmp;
        tmp_0 = 80 * i + b_Kr_tmp;
        full_loop_B.b_Wy += I2Jm[tmp] * b_Kut[tmp_0];
        full_loop_B.b_Jm[b_SuJm_tmp] += b_Jm[tmp] * full_loop_B.dv3[tmp_0];
      }

      b_H[b_SuJm_tmp] = (full_loop_B.b_SuJm[b_SuJm_tmp] +
                         full_loop_B.b_Jm[b_SuJm_tmp]) + full_loop_B.b_Wy;
    }
  }

  for (i_0 = 0; i_0 < 8; i_0++) {
    for (i = 0; i < 16; i++) {
      b_SuJm_tmp = i_0 + (i << 3);
      full_loop_B.b_Su1[b_SuJm_tmp] = 0.0;
      for (b_Kr_tmp = 0; b_Kr_tmp < 120; b_Kr_tmp++) {
        full_loop_B.b_Su1[b_SuJm_tmp] += b_Su1[120 * i_0 + b_Kr_tmp] * b_Kr[120 *
          i + b_Kr_tmp];
      }

      full_loop_B.b_I1[b_SuJm_tmp] = 0.0;
      for (b_Kr_tmp = 0; b_Kr_tmp < 80; b_Kr_tmp++) {
        full_loop_B.b_I1[b_SuJm_tmp] += b_I1[80 * i_0 + b_Kr_tmp] * b_Kut[80 * i
          + b_Kr_tmp];
      }
    }
  }

  for (i_0 = 0; i_0 < 128; i_0++) {
    b_Ku1[i_0] = full_loop_B.b_Su1[i_0] + full_loop_B.b_I1[i_0];
  }

  for (i_0 = 0; i_0 < 1280; i_0++) {
    b_Kut[i_0] = -b_Kut[i_0];
  }

  for (i_0 = 0; i_0 < 20; i_0++) {
    for (i = 0; i < 16; i++) {
      b_SuJm_tmp = i_0 + 20 * i;
      b_Kx[b_SuJm_tmp] = 0.0;
      for (b_Kr_tmp = 0; b_Kr_tmp < 120; b_Kr_tmp++) {
        b_Kx[b_SuJm_tmp] += b_Sx[120 * i_0 + b_Kr_tmp] * b_Kr[120 * i + b_Kr_tmp];
      }
    }
  }

  for (i_0 = 0; i_0 < 11; i_0++) {
    for (i = 0; i < 16; i++) {
      b_SuJm_tmp = i_0 + 11 * i;
      b_Kv[b_SuJm_tmp] = 0.0;
      for (b_Kr_tmp = 0; b_Kr_tmp < 120; b_Kr_tmp++) {
        b_Kv[b_SuJm_tmp] += b_Hv[120 * i_0 + b_Kr_tmp] * b_Kr[120 * i + b_Kr_tmp];
      }
    }
  }

  for (i_0 = 0; i_0 < 1920; i_0++) {
    b_Kr[i_0] = -b_Kr[i_0];
  }
}

// Function for MATLAB Function: '<S98>/FixedHorizonOptimizer'
static int32_T full_loop_xpotrf_j(real_T b_A[289])
{
  int32_T info;
  int32_T idxAjj;
  int32_T j;
  real_T c;
  int32_T iy;
  int32_T d;
  int32_T ia;
  int32_T b_ix;
  int32_T b_iy;
  int32_T b_k;
  boolean_T exitg1;
  info = 0;
  j = 0;
  exitg1 = false;
  while ((!exitg1) && (j < 17)) {
    idxAjj = j * 17 + j;
    full_loop_B.ssq_f = 0.0;
    if (j >= 1) {
      b_ix = j;
      b_iy = j;
      for (b_k = 0; b_k < j; b_k++) {
        full_loop_B.ssq_f += b_A[b_ix] * b_A[b_iy];
        b_ix += 17;
        b_iy += 17;
      }
    }

    full_loop_B.ssq_f = b_A[idxAjj] - full_loop_B.ssq_f;
    if (full_loop_B.ssq_f > 0.0) {
      full_loop_B.ssq_f = sqrt(full_loop_B.ssq_f);
      b_A[idxAjj] = full_loop_B.ssq_f;
      if (j + 1 < 17) {
        if (j != 0) {
          b_ix = j;
          b_iy = ((j - 1) * 17 + j) + 2;
          for (b_k = j + 2; b_k <= b_iy; b_k += 17) {
            c = -b_A[b_ix];
            iy = idxAjj + 1;
            d = (b_k - j) + 15;
            for (ia = b_k; ia <= d; ia++) {
              b_A[iy] += b_A[ia - 1] * c;
              iy++;
            }

            b_ix += 17;
          }
        }

        full_loop_B.ssq_f = 1.0 / full_loop_B.ssq_f;
        b_ix = (idxAjj - j) + 17;
        for (idxAjj++; idxAjj < b_ix; idxAjj++) {
          b_A[idxAjj] *= full_loop_B.ssq_f;
        }
      }

      j++;
    } else {
      b_A[idxAjj] = full_loop_B.ssq_f;
      info = j + 1;
      exitg1 = true;
    }
  }

  return info;
}

// Function for MATLAB Function: '<S98>/FixedHorizonOptimizer'
static void full_loop_diag(const real_T v[289], real_T d[17])
{
  int32_T k;
  for (k = 0; k < 17; k++) {
    d[k] = v[17 * k + k];
  }
}

// Function for MATLAB Function: '<S98>/FixedHorizonOptimizer'
static real_T full_loop_norm(const real_T x[289])
{
  real_T y;
  real_T s;
  int32_T i;
  int32_T j;
  boolean_T exitg1;
  y = 0.0;
  i = 0;
  exitg1 = false;
  while ((!exitg1) && (i < 17)) {
    s = 0.0;
    for (j = 0; j < 17; j++) {
      s += fabs(x[17 * j + i]);
    }

    if (rtIsNaN(s)) {
      y = (rtNaN);
      exitg1 = true;
    } else {
      if (s > y) {
        y = s;
      }

      i++;
    }
  }

  return y;
}

// Function for MATLAB Function: '<S98>/FixedHorizonOptimizer'
static void full_loop_eye_cb(real_T b_I[289])
{
  int32_T k;
  memset(&b_I[0], 0, 289U * sizeof(real_T));
  for (k = 0; k < 17; k++) {
    b_I[k + 17 * k] = 1.0;
  }
}

// Function for MATLAB Function: '<S98>/FixedHorizonOptimizer'
static void full_loop_mpc_checkhessian(real_T b_H[289], real_T L[289], real_T
  *BadH)
{
  int32_T idx;
  int32_T b_idx;
  int32_T c_k;
  boolean_T exitg1;
  boolean_T exitg2;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  *BadH = 0.0;
  memcpy(&L[0], &b_H[0], 289U * sizeof(real_T));
  idx = full_loop_xpotrf_j(L);
  guard1 = false;
  if (idx == 0) {
    full_loop_diag(L, full_loop_B.varargin_1);
    if (!rtIsNaN(full_loop_B.varargin_1[0])) {
      idx = 1;
    } else {
      idx = 0;
      b_idx = 2;
      exitg2 = false;
      while ((!exitg2) && (b_idx < 18)) {
        if (!rtIsNaN(full_loop_B.varargin_1[b_idx - 1])) {
          idx = b_idx;
          exitg2 = true;
        } else {
          b_idx++;
        }
      }
    }

    if (idx == 0) {
      full_loop_B.ex = full_loop_B.varargin_1[0];
    } else {
      full_loop_B.ex = full_loop_B.varargin_1[idx - 1];
      while (idx + 1 <= 17) {
        if (full_loop_B.ex > full_loop_B.varargin_1[idx]) {
          full_loop_B.ex = full_loop_B.varargin_1[idx];
        }

        idx++;
      }
    }

    if (full_loop_B.ex > 1.4901161193847656E-7) {
    } else {
      guard1 = true;
    }
  } else {
    guard1 = true;
  }

  if (guard1) {
    if (full_loop_norm(b_H) >= 1.0E+10) {
      *BadH = 2.0;
    } else {
      idx = 0;
      exitg1 = false;
      while ((!exitg1) && (idx <= 4)) {
        full_loop_B.ex = rt_powd_snf(10.0, static_cast<real_T>(idx)) *
          1.4901161193847656E-7;
        full_loop_eye_cb(full_loop_B.dv4);
        for (b_idx = 0; b_idx < 289; b_idx++) {
          full_loop_B.b_H_c = full_loop_B.ex * full_loop_B.dv4[b_idx] +
            b_H[b_idx];
          L[b_idx] = full_loop_B.b_H_c;
          b_H[b_idx] = full_loop_B.b_H_c;
        }

        b_idx = full_loop_xpotrf_j(L);
        guard2 = false;
        if (b_idx == 0) {
          full_loop_diag(L, full_loop_B.varargin_1);
          if (!rtIsNaN(full_loop_B.varargin_1[0])) {
            b_idx = 1;
          } else {
            b_idx = 0;
            c_k = 2;
            exitg2 = false;
            while ((!exitg2) && (c_k < 18)) {
              if (!rtIsNaN(full_loop_B.varargin_1[c_k - 1])) {
                b_idx = c_k;
                exitg2 = true;
              } else {
                c_k++;
              }
            }
          }

          if (b_idx == 0) {
            full_loop_B.ex = full_loop_B.varargin_1[0];
          } else {
            full_loop_B.ex = full_loop_B.varargin_1[b_idx - 1];
            while (b_idx + 1 <= 17) {
              if (full_loop_B.ex > full_loop_B.varargin_1[b_idx]) {
                full_loop_B.ex = full_loop_B.varargin_1[b_idx];
              }

              b_idx++;
            }
          }

          if (full_loop_B.ex > 1.4901161193847656E-7) {
            *BadH = 1.0;
            exitg1 = true;
          } else {
            guard2 = true;
          }
        } else {
          guard2 = true;
        }

        if (guard2) {
          *BadH = 3.0;
          idx++;
        }
      }
    }
  }
}

// Function for MATLAB Function: '<S98>/FixedHorizonOptimizer'
static void full_loop_eye_cbt(real_T b_I[289])
{
  int32_T k;
  memset(&b_I[0], 0, 289U * sizeof(real_T));
  for (k = 0; k < 17; k++) {
    b_I[k + 17 * k] = 1.0;
  }
}

// Function for MATLAB Function: '<S98>/FixedHorizonOptimizer'
static void full_loop_trisolve(const real_T b_A[289], real_T b_B[289])
{
  int32_T jBcol;
  int32_T kAcol;
  int32_T j;
  int32_T k;
  int32_T i;
  int32_T tmp;
  int32_T tmp_0;
  for (j = 0; j < 17; j++) {
    jBcol = 17 * j;
    for (k = 0; k < 17; k++) {
      kAcol = 17 * k;
      tmp = k + jBcol;
      if (b_B[tmp] != 0.0) {
        b_B[tmp] /= b_A[k + kAcol];
        for (i = k + 2; i < 18; i++) {
          tmp_0 = (i + jBcol) - 1;
          b_B[tmp_0] -= b_A[(i + kAcol) - 1] * b_B[tmp];
        }
      }
    }
  }
}

// Function for MATLAB Function: '<S98>/FixedHorizonOptimizer'
static void full_loop_linsolve(const real_T b_A[289], const real_T b_B[289],
  real_T b_C[289])
{
  int32_T j;
  for (j = 0; j < 17; j++) {
    memcpy(&b_C[j * 17], &b_B[j * 17], 17U * sizeof(real_T));
  }

  full_loop_trisolve(b_A, b_C);
}

// Function for MATLAB Function: '<S98>/FixedHorizonOptimizer'
static void full_loop_Unconstrained(const real_T b_Hinv[289], const real_T f[17],
  real_T x[17], int16_T n)
{
  int32_T i;
  int32_T i_0;
  real_T b_Hinv_0;
  int32_T i_1;
  for (i = 1; i - 1 < n; i++) {
    i_0 = static_cast<int16_T>(i);
    b_Hinv_0 = 0.0;
    for (i_1 = 0; i_1 < 17; i_1++) {
      b_Hinv_0 += -b_Hinv[(17 * i_1 + i_0) - 1] * f[i_1];
    }

    x[static_cast<int16_T>(i) - 1] = b_Hinv_0;
  }
}

// Function for MATLAB Function: '<S98>/FixedHorizonOptimizer'
static real_T full_loop_norm_i(const real_T x[17])
{
  real_T y;
  real_T scale;
  real_T absxk;
  real_T t;
  int32_T k;
  y = 0.0;
  scale = 3.3121686421112381E-170;
  for (k = 0; k < 17; k++) {
    absxk = fabs(x[k]);
    if (absxk > scale) {
      t = scale / absxk;
      y = y * t * t + 1.0;
      scale = absxk;
    } else {
      t = absxk / scale;
      y += t * t;
    }
  }

  return scale * sqrt(y);
}

// Function for MATLAB Function: '<S98>/FixedHorizonOptimizer'
static void full_loop_abs(const real_T x[17], real_T y[17])
{
  int32_T k;
  for (k = 0; k < 17; k++) {
    y[k] = fabs(x[k]);
  }
}

// Function for MATLAB Function: '<S98>/FixedHorizonOptimizer'
static void full_loop_abs_d(const real_T x[4], real_T y[4])
{
  y[0] = fabs(x[0]);
  y[1] = fabs(x[1]);
  y[2] = fabs(x[2]);
  y[3] = fabs(x[3]);
}

// Function for MATLAB Function: '<S98>/FixedHorizonOptimizer'
static real_T full_loop_xnrm2_a(int32_T n, const real_T x[289], int32_T ix0)
{
  real_T y;
  int32_T kend;
  int32_T k;
  y = 0.0;
  if (n >= 1) {
    if (n == 1) {
      y = fabs(x[ix0 - 1]);
    } else {
      full_loop_B.scale_d = 3.3121686421112381E-170;
      kend = (ix0 + n) - 1;
      for (k = ix0; k <= kend; k++) {
        full_loop_B.absxk_a = fabs(x[k - 1]);
        if (full_loop_B.absxk_a > full_loop_B.scale_d) {
          full_loop_B.t_p = full_loop_B.scale_d / full_loop_B.absxk_a;
          y = y * full_loop_B.t_p * full_loop_B.t_p + 1.0;
          full_loop_B.scale_d = full_loop_B.absxk_a;
        } else {
          full_loop_B.t_p = full_loop_B.absxk_a / full_loop_B.scale_d;
          y += full_loop_B.t_p * full_loop_B.t_p;
        }
      }

      y = full_loop_B.scale_d * sqrt(y);
    }
  }

  return y;
}

// Function for MATLAB Function: '<S98>/FixedHorizonOptimizer'
static real_T full_loop_xzlarfg_j(int32_T n, real_T *alpha1, real_T x[289],
  int32_T ix0)
{
  real_T tau;
  int32_T knt;
  int32_T b_k;
  int32_T c_k;
  tau = 0.0;
  if (n > 0) {
    full_loop_B.xnorm_a = full_loop_xnrm2_a(n - 1, x, ix0);
    if (full_loop_B.xnorm_a != 0.0) {
      full_loop_B.xnorm_a = rt_hypotd_snf(*alpha1, full_loop_B.xnorm_a);
      if (*alpha1 >= 0.0) {
        full_loop_B.xnorm_a = -full_loop_B.xnorm_a;
      }

      if (fabs(full_loop_B.xnorm_a) < 1.0020841800044864E-292) {
        knt = -1;
        c_k = (ix0 + n) - 2;
        do {
          knt++;
          for (b_k = ix0; b_k <= c_k; b_k++) {
            x[b_k - 1] *= 9.9792015476736E+291;
          }

          full_loop_B.xnorm_a *= 9.9792015476736E+291;
          *alpha1 *= 9.9792015476736E+291;
        } while (!(fabs(full_loop_B.xnorm_a) >= 1.0020841800044864E-292));

        full_loop_B.xnorm_a = rt_hypotd_snf(*alpha1, full_loop_xnrm2_a(n - 1, x,
          ix0));
        if (*alpha1 >= 0.0) {
          full_loop_B.xnorm_a = -full_loop_B.xnorm_a;
        }

        tau = (full_loop_B.xnorm_a - *alpha1) / full_loop_B.xnorm_a;
        *alpha1 = 1.0 / (*alpha1 - full_loop_B.xnorm_a);
        for (b_k = ix0; b_k <= c_k; b_k++) {
          x[b_k - 1] *= *alpha1;
        }

        for (c_k = 0; c_k <= knt; c_k++) {
          full_loop_B.xnorm_a *= 1.0020841800044864E-292;
        }

        *alpha1 = full_loop_B.xnorm_a;
      } else {
        tau = (full_loop_B.xnorm_a - *alpha1) / full_loop_B.xnorm_a;
        *alpha1 = 1.0 / (*alpha1 - full_loop_B.xnorm_a);
        knt = (ix0 + n) - 2;
        for (c_k = ix0; c_k <= knt; c_k++) {
          x[c_k - 1] *= *alpha1;
        }

        *alpha1 = full_loop_B.xnorm_a;
      }
    }
  }

  return tau;
}

// Function for MATLAB Function: '<S98>/FixedHorizonOptimizer'
static void full_loop_xgemv_pz(int32_T m, int32_T n, const real_T b_A[289],
  int32_T ia0, const real_T x[289], int32_T ix0, real_T y[17])
{
  int32_T ix;
  int32_T b_iy;
  int32_T b;
  int32_T iac;
  int32_T d;
  int32_T ia;
  if ((m != 0) && (n != 0)) {
    for (b_iy = 0; b_iy < n; b_iy++) {
      y[b_iy] = 0.0;
    }

    b_iy = 0;
    b = (n - 1) * 17 + ia0;
    for (iac = ia0; iac <= b; iac += 17) {
      ix = ix0;
      full_loop_B.c_db = 0.0;
      d = (iac + m) - 1;
      for (ia = iac; ia <= d; ia++) {
        full_loop_B.c_db += b_A[ia - 1] * x[ix - 1];
        ix++;
      }

      y[b_iy] += full_loop_B.c_db;
      b_iy++;
    }
  }
}

// Function for MATLAB Function: '<S98>/FixedHorizonOptimizer'
static void full_loop_xgerc(int32_T m, int32_T n, real_T alpha1, int32_T ix0,
  const real_T y[17], real_T b_A[289], int32_T ia0)
{
  int32_T jA;
  int32_T jy;
  int32_T ix;
  int32_T j;
  int32_T b;
  int32_T ijA;
  if (!(alpha1 == 0.0)) {
    jA = ia0 - 1;
    jy = 0;
    for (j = 0; j < n; j++) {
      if (y[jy] != 0.0) {
        full_loop_B.temp_mx = y[jy] * alpha1;
        ix = ix0;
        b = m + jA;
        for (ijA = jA; ijA < b; ijA++) {
          b_A[ijA] += b_A[ix - 1] * full_loop_B.temp_mx;
          ix++;
        }
      }

      jy++;
      jA += 17;
    }
  }
}

// Function for MATLAB Function: '<S98>/FixedHorizonOptimizer'
static void full_loop_xzlarf_d(int32_T m, int32_T n, int32_T iv0, real_T tau,
  real_T b_C[289], int32_T ic0, real_T work[17])
{
  int32_T lastv;
  int32_T lastc;
  int32_T coltop;
  int32_T ia;
  int32_T exitg1;
  boolean_T exitg2;
  if (tau != 0.0) {
    lastv = m;
    lastc = iv0 + m;
    while ((lastv > 0) && (b_C[lastc - 2] == 0.0)) {
      lastv--;
      lastc--;
    }

    lastc = n;
    exitg2 = false;
    while ((!exitg2) && (lastc > 0)) {
      coltop = (lastc - 1) * 17 + ic0;
      ia = coltop;
      do {
        exitg1 = 0;
        if (ia <= (coltop + lastv) - 1) {
          if (b_C[ia - 1] != 0.0) {
            exitg1 = 1;
          } else {
            ia++;
          }
        } else {
          lastc--;
          exitg1 = 2;
        }
      } while (exitg1 == 0);

      if (exitg1 == 1) {
        exitg2 = true;
      }
    }
  } else {
    lastv = 0;
    lastc = 0;
  }

  if (lastv > 0) {
    full_loop_xgemv_pz(lastv, lastc, b_C, ic0, b_C, iv0, work);
    full_loop_xgerc(lastv, lastc, -tau, iv0, work, b_C, ic0);
  }
}

// Function for MATLAB Function: '<S98>/FixedHorizonOptimizer'
static void full_loop_qrf_l(real_T b_A[289], int32_T ia0, int32_T m, int32_T n,
  int32_T nfxd, real_T tau[17])
{
  memset(&full_loop_B.work_g[0], 0, 17U * sizeof(real_T));
  full_loop_B.b_i_h = 0;
  while (full_loop_B.b_i_h <= nfxd - 1) {
    full_loop_B.ii_h = ((full_loop_B.b_i_h * 17 + ia0) + full_loop_B.b_i_h) - 1;
    full_loop_B.mmi_k = m - full_loop_B.b_i_h;
    if (full_loop_B.b_i_h + 1 < m) {
      full_loop_B.b_atmp_c = b_A[full_loop_B.ii_h];
      tau[full_loop_B.b_i_h] = full_loop_xzlarfg_j(full_loop_B.mmi_k,
        &full_loop_B.b_atmp_c, b_A, full_loop_B.ii_h + 2);
      b_A[full_loop_B.ii_h] = full_loop_B.b_atmp_c;
    } else {
      tau[full_loop_B.b_i_h] = 0.0;
    }

    if (full_loop_B.b_i_h + 1 < n) {
      full_loop_B.b_atmp_c = b_A[full_loop_B.ii_h];
      b_A[full_loop_B.ii_h] = 1.0;
      full_loop_xzlarf_d(full_loop_B.mmi_k, (n - full_loop_B.b_i_h) - 1,
                         full_loop_B.ii_h + 1, tau[full_loop_B.b_i_h], b_A,
                         full_loop_B.ii_h + 18, full_loop_B.work_g);
      b_A[full_loop_B.ii_h] = full_loop_B.b_atmp_c;
    }

    full_loop_B.b_i_h++;
  }
}

// Function for MATLAB Function: '<S98>/FixedHorizonOptimizer'
static void full_loop_xgeqrf_l(real_T b_A[289], real_T tau[17])
{
  memset(&tau[0], 0, 17U * sizeof(real_T));
  full_loop_qrf_l(b_A, 1, 17, 17, 17, tau);
}

// Function for MATLAB Function: '<S98>/FixedHorizonOptimizer'
static void full_loop_qr(const real_T b_A[289], real_T Q[289], real_T R[289])
{
  memcpy(&full_loop_B.c_A_m[0], &b_A[0], 289U * sizeof(real_T));
  full_loop_xgeqrf_l(full_loop_B.c_A_m, full_loop_B.tau);
  full_loop_B.itau = 16;
  for (full_loop_B.d_i_j = 0; full_loop_B.d_i_j < 17; full_loop_B.d_i_j++) {
    full_loop_B.iaii = 0;
    while (full_loop_B.iaii <= full_loop_B.d_i_j) {
      R[full_loop_B.iaii + 17 * full_loop_B.d_i_j] = full_loop_B.c_A_m[17 *
        full_loop_B.d_i_j + full_loop_B.iaii];
      full_loop_B.iaii++;
    }

    full_loop_B.iaii = full_loop_B.d_i_j + 1;
    while (full_loop_B.iaii + 1 < 18) {
      R[full_loop_B.iaii + 17 * full_loop_B.d_i_j] = 0.0;
      full_loop_B.iaii++;
    }

    full_loop_B.work_f[full_loop_B.d_i_j] = 0.0;
  }

  for (full_loop_B.d_i_j = 16; full_loop_B.d_i_j >= 0; full_loop_B.d_i_j--) {
    full_loop_B.iaii = full_loop_B.d_i_j * 17 + full_loop_B.d_i_j;
    if (full_loop_B.d_i_j + 1 < 17) {
      full_loop_B.c_A_m[full_loop_B.iaii] = 1.0;
      full_loop_xzlarf_d(17 - full_loop_B.d_i_j, 16 - full_loop_B.d_i_j,
                         full_loop_B.iaii + 1, full_loop_B.tau[full_loop_B.itau],
                         full_loop_B.c_A_m, full_loop_B.iaii + 18,
                         full_loop_B.work_f);
      full_loop_B.b_cy = (full_loop_B.iaii - full_loop_B.d_i_j) + 17;
      full_loop_B.k_n = full_loop_B.iaii + 1;
      while (full_loop_B.k_n + 1 <= full_loop_B.b_cy) {
        full_loop_B.c_A_m[full_loop_B.k_n] *= -full_loop_B.tau[full_loop_B.itau];
        full_loop_B.k_n++;
      }
    }

    full_loop_B.c_A_m[full_loop_B.iaii] = 1.0 - full_loop_B.tau[full_loop_B.itau];
    full_loop_B.b_cy = 0;
    while (full_loop_B.b_cy <= full_loop_B.d_i_j - 1) {
      full_loop_B.c_A_m[(full_loop_B.iaii - full_loop_B.b_cy) - 1] = 0.0;
      full_loop_B.b_cy++;
    }

    full_loop_B.itau--;
  }

  for (full_loop_B.itau = 0; full_loop_B.itau < 17; full_loop_B.itau++) {
    memcpy(&Q[full_loop_B.itau * 17], &full_loop_B.c_A_m[full_loop_B.itau * 17],
           17U * sizeof(real_T));
  }
}

// Function for MATLAB Function: '<S98>/FixedHorizonOptimizer'
static real_T full_loop_KWIKfactor(const real_T b_Ac[68], const int16_T iC[4],
  int16_T nA, const real_T b_Linv[289], real_T RLinv[289], real_T b_D[289],
  real_T b_H[289], int16_T n)
{
  real_T Status;
  int16_T b_j;
  int16_T c_k;
  int32_T exitg1;
  int32_T exitg2;
  Status = 1.0;
  memset(&RLinv[0], 0, 289U * sizeof(real_T));
  full_loop_B.i_pie = 1;
  do {
    exitg1 = 0;
    full_loop_B.i2 = nA - 1;
    if (full_loop_B.i_pie - 1 <= full_loop_B.i2) {
      full_loop_B.e_i = static_cast<int16_T>(full_loop_B.i_pie) - 1;
      for (full_loop_B.i2 = 0; full_loop_B.i2 < 17; full_loop_B.i2++) {
        full_loop_B.i3 = full_loop_B.i2 + 17 * full_loop_B.e_i;
        RLinv[full_loop_B.i3] = 0.0;
        for (full_loop_B.b_i_o = 0; full_loop_B.b_i_o < 17; full_loop_B.b_i_o++)
        {
          RLinv[full_loop_B.i3] += b_Ac[((full_loop_B.b_i_o << 2) +
            iC[full_loop_B.e_i]) - 1] * b_Linv[17 * full_loop_B.b_i_o +
            full_loop_B.i2];
        }
      }

      full_loop_B.i_pie++;
    } else {
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  full_loop_qr(RLinv, full_loop_B.QQ, full_loop_B.RR);
  full_loop_B.b_i_o = 1;
  do {
    exitg1 = 0;
    if (full_loop_B.b_i_o - 1 <= full_loop_B.i2) {
      if (fabs(full_loop_B.RR[((static_cast<int16_T>(full_loop_B.b_i_o) - 1) *
            17 + static_cast<int16_T>(full_loop_B.b_i_o)) - 1]) < 1.0E-12) {
        Status = -2.0;
        exitg1 = 1;
      } else {
        full_loop_B.b_i_o++;
      }
    } else {
      full_loop_B.i_pie = 1;
      do {
        exitg2 = 0;
        full_loop_B.i3 = n - 1;
        if (full_loop_B.i_pie - 1 <= full_loop_B.i3) {
          full_loop_B.e_i = 1;
          while (full_loop_B.e_i - 1 <= full_loop_B.i3) {
            full_loop_B.f_i_l = static_cast<int16_T>(full_loop_B.i_pie);
            full_loop_B.j_k = static_cast<int16_T>(full_loop_B.e_i);
            full_loop_B.b_Linv = 0.0;
            for (full_loop_B.b_i_o = 0; full_loop_B.b_i_o < 17;
                 full_loop_B.b_i_o++) {
              full_loop_B.b_Linv += b_Linv[(full_loop_B.f_i_l - 1) * 17 +
                full_loop_B.b_i_o] * full_loop_B.QQ[(full_loop_B.j_k - 1) * 17 +
                full_loop_B.b_i_o];
            }

            full_loop_B.TL[(static_cast<int16_T>(full_loop_B.i_pie) + 17 * (
              static_cast<int16_T>(full_loop_B.e_i) - 1)) - 1] =
              full_loop_B.b_Linv;
            full_loop_B.e_i++;
          }

          full_loop_B.i_pie++;
        } else {
          exitg2 = 1;
        }
      } while (exitg2 == 0);

      memset(&RLinv[0], 0, 289U * sizeof(real_T));
      b_j = nA;
      while (b_j > 0) {
        full_loop_B.b_i_o = b_j - 1;
        full_loop_B.i_pie = 17 * full_loop_B.b_i_o;
        full_loop_B.e_i = (b_j + full_loop_B.i_pie) - 1;
        RLinv[full_loop_B.e_i] = 1.0;
        for (c_k = b_j; c_k <= nA; c_k = static_cast<int16_T>(c_k + 1)) {
          full_loop_B.j_k = ((c_k - 1) * 17 + b_j) - 1;
          RLinv[full_loop_B.j_k] /= full_loop_B.RR[full_loop_B.e_i];
        }

        if (b_j > 1) {
          full_loop_B.f_i_l = 1;
          while (full_loop_B.f_i_l - 1 <= b_j - 2) {
            for (c_k = b_j; c_k <= nA; c_k = static_cast<int16_T>(c_k + 1)) {
              full_loop_B.e_i = (c_k - 1) * 17;
              full_loop_B.j_k = (full_loop_B.e_i + static_cast<int16_T>
                                 (full_loop_B.f_i_l)) - 1;
              RLinv[full_loop_B.j_k] -= full_loop_B.RR[(full_loop_B.i_pie +
                static_cast<int16_T>(full_loop_B.f_i_l)) - 1] * RLinv
                [(full_loop_B.e_i + b_j) - 1];
            }

            full_loop_B.f_i_l++;
          }
        }

        b_j = static_cast<int16_T>(full_loop_B.b_i_o);
      }

      full_loop_B.e_i = 1;
      while (full_loop_B.e_i - 1 <= full_loop_B.i3) {
        for (b_j = static_cast<int16_T>(full_loop_B.e_i); b_j <= n; b_j =
             static_cast<int16_T>(b_j + 1)) {
          full_loop_B.b_i_o = (static_cast<int16_T>(full_loop_B.e_i) + 17 * (b_j
            - 1)) - 1;
          b_H[full_loop_B.b_i_o] = 0.0;
          full_loop_B.i_pie = nA + 1;
          if (full_loop_B.i_pie > 32767) {
            full_loop_B.i_pie = 32767;
          }

          for (c_k = static_cast<int16_T>(full_loop_B.i_pie); c_k <= n; c_k =
               static_cast<int16_T>(c_k + 1)) {
            full_loop_B.i_pie = (c_k - 1) * 17;
            b_H[full_loop_B.b_i_o] -= full_loop_B.TL[(full_loop_B.i_pie +
              static_cast<int16_T>(full_loop_B.e_i)) - 1] * full_loop_B.TL
              [(full_loop_B.i_pie + b_j) - 1];
          }

          b_H[(b_j + 17 * (static_cast<int16_T>(full_loop_B.e_i) - 1)) - 1] =
            b_H[full_loop_B.b_i_o];
        }

        full_loop_B.e_i++;
      }

      full_loop_B.e_i = 1;
      while (full_loop_B.e_i - 1 <= full_loop_B.i2) {
        full_loop_B.f_i_l = 1;
        while (full_loop_B.f_i_l - 1 <= full_loop_B.i3) {
          full_loop_B.b_i_o = (static_cast<int16_T>(full_loop_B.f_i_l) + 17 * (
            static_cast<int16_T>(full_loop_B.e_i) - 1)) - 1;
          b_D[full_loop_B.b_i_o] = 0.0;
          for (b_j = static_cast<int16_T>(full_loop_B.e_i); b_j <= nA; b_j =
               static_cast<int16_T>(b_j + 1)) {
            full_loop_B.i_pie = (b_j - 1) * 17;
            b_D[full_loop_B.b_i_o] += full_loop_B.TL[(full_loop_B.i_pie +
              static_cast<int16_T>(full_loop_B.f_i_l)) - 1] * RLinv
              [(full_loop_B.i_pie + static_cast<int16_T>(full_loop_B.e_i)) - 1];
          }

          full_loop_B.f_i_l++;
        }

        full_loop_B.e_i++;
      }

      exitg1 = 1;
    }
  } while (exitg1 == 0);

  return Status;
}

// Function for MATLAB Function: '<S98>/FixedHorizonOptimizer'
static void full_loop_DropConstraint(int16_T kDrop, int16_T iA[4], int16_T *nA,
  int16_T iC[4])
{
  int16_T i;
  int32_T tmp;
  iA[iC[kDrop - 1] - 1] = 0;
  if (kDrop < *nA) {
    tmp = *nA - 1;
    if (tmp < -32768) {
      tmp = -32768;
    }

    for (i = kDrop; i <= static_cast<int16_T>(tmp); i = static_cast<int16_T>(i +
          1)) {
      iC[i - 1] = iC[i];
    }
  }

  tmp = *nA - 1;
  iC[tmp] = 0;
  if (tmp < -32768) {
    tmp = -32768;
  }

  *nA = static_cast<int16_T>(tmp);
}

// Function for MATLAB Function: '<S98>/FixedHorizonOptimizer'
static void full_loop_qpkwik(const real_T b_Linv[289], const real_T b_Hinv[289],
  const real_T f[17], const real_T b_Ac[68], const real_T b[4], int16_T iA[4],
  int16_T maxiter, real_T FeasTol, real_T x[17], real_T lambda[4], real_T
  *status)
{
  boolean_T cTolComputed;
  int16_T nA;
  boolean_T DualFeasible;
  boolean_T ColdReset;
  int16_T kDrop;
  int16_T kNext;
  int32_T exitg1;
  int32_T exitg2;
  int32_T exitg3;
  boolean_T exitg4;
  int32_T exitg5;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  *status = 1.0;
  lambda[0] = 0.0;
  lambda[1] = 0.0;
  lambda[2] = 0.0;
  lambda[3] = 0.0;
  memset(&x[0], 0, 17U * sizeof(real_T));
  memset(&full_loop_B.r_i[0], 0, 17U * sizeof(real_T));
  full_loop_B.rMin = 0.0;
  cTolComputed = false;
  full_loop_B.cTol[0] = 1.0;
  full_loop_B.iC[0] = 0;
  full_loop_B.cTol[1] = 1.0;
  full_loop_B.iC[1] = 0;
  full_loop_B.cTol[2] = 1.0;
  full_loop_B.iC[2] = 0;
  full_loop_B.cTol[3] = 1.0;
  full_loop_B.iC[3] = 0;
  nA = 0;
  if (iA[0] == 1) {
    nA = 1;
    full_loop_B.iC[0] = 1;
  }

  if (iA[1] == 1) {
    full_loop_B.i_o = nA + 1;
    nA = static_cast<int16_T>(full_loop_B.i_o);
    full_loop_B.iC[static_cast<int16_T>(full_loop_B.i_o) - 1] = 2;
  }

  if (iA[2] == 1) {
    full_loop_B.i_o = nA + 1;
    nA = static_cast<int16_T>(full_loop_B.i_o);
    full_loop_B.iC[static_cast<int16_T>(full_loop_B.i_o) - 1] = 3;
  }

  if (iA[3] == 1) {
    full_loop_B.i_o = nA + 1;
    nA = static_cast<int16_T>(full_loop_B.i_o);
    full_loop_B.iC[static_cast<int16_T>(full_loop_B.i_o) - 1] = 4;
  }

  guard1 = false;
  if (nA > 0) {
    memset(&full_loop_B.Opt[0], 0, 34U * sizeof(real_T));
    for (full_loop_B.i_o = 0; full_loop_B.i_o < 17; full_loop_B.i_o++) {
      full_loop_B.Rhs[full_loop_B.i_o] = f[full_loop_B.i_o];
      full_loop_B.Rhs[full_loop_B.i_o + 17] = 0.0;
    }

    DualFeasible = false;
    ColdReset = false;
    do {
      exitg3 = 0;
      if ((!DualFeasible) && (nA > 0) && (static_cast<int32_T>(*status) <=
           maxiter)) {
        full_loop_B.Xnorm0 = full_loop_KWIKfactor(b_Ac, full_loop_B.iC, nA,
          b_Linv, full_loop_B.RLinv, full_loop_B.b_D, full_loop_B.b_H_o, 17);
        if (full_loop_B.Xnorm0 < 0.0) {
          if (ColdReset) {
            *status = -2.0;
            exitg3 = 2;
          } else {
            nA = 0;
            iA[0] = 0;
            full_loop_B.iC[0] = 0;
            iA[1] = 0;
            full_loop_B.iC[1] = 0;
            iA[2] = 0;
            full_loop_B.iC[2] = 0;
            iA[3] = 0;
            full_loop_B.iC[3] = 0;
            ColdReset = true;
          }
        } else {
          full_loop_B.f_i = 1;
          do {
            exitg5 = 0;
            full_loop_B.i_o = nA - 1;
            if (full_loop_B.f_i - 1 <= full_loop_B.i_o) {
              full_loop_B.idx = static_cast<int16_T>(full_loop_B.f_i) + 17;
              if (full_loop_B.idx > 32767) {
                full_loop_B.idx = 32767;
              }

              full_loop_B.f_i_j = static_cast<int16_T>(full_loop_B.f_i) - 1;
              full_loop_B.Rhs[full_loop_B.idx - 1] =
                b[full_loop_B.iC[full_loop_B.f_i_j] - 1];
              for (kNext = static_cast<int16_T>(full_loop_B.f_i); kNext <= nA;
                   kNext = static_cast<int16_T>(kNext + 1)) {
                full_loop_B.idx = (kNext + 17 * full_loop_B.f_i_j) - 1;
                full_loop_B.U_n[full_loop_B.idx] = 0.0;
                full_loop_B.c_k_a = 1;
                while (full_loop_B.c_k_a - 1 <= full_loop_B.i_o) {
                  full_loop_B.U_tmp = (static_cast<int16_T>(full_loop_B.c_k_a) -
                                       1) * 17;
                  full_loop_B.U_n[full_loop_B.idx] += full_loop_B.RLinv
                    [(full_loop_B.U_tmp + kNext) - 1] * full_loop_B.RLinv
                    [(full_loop_B.U_tmp + static_cast<int16_T>(full_loop_B.f_i))
                    - 1];
                  full_loop_B.c_k_a++;
                }

                full_loop_B.U_n[(static_cast<int16_T>(full_loop_B.f_i) + 17 *
                                 (kNext - 1)) - 1] =
                  full_loop_B.U_n[full_loop_B.idx];
              }

              full_loop_B.f_i++;
            } else {
              exitg5 = 1;
            }
          } while (exitg5 == 0);

          for (full_loop_B.f_i = 0; full_loop_B.f_i < 17; full_loop_B.f_i++) {
            full_loop_B.f_i_j = full_loop_B.f_i + 1;
            full_loop_B.Xnorm0 = 0.0;
            for (full_loop_B.idx = 0; full_loop_B.idx < 17; full_loop_B.idx++) {
              full_loop_B.Xnorm0 += full_loop_B.b_H_o[(17 * full_loop_B.idx +
                full_loop_B.f_i_j) - 1] * full_loop_B.Rhs[full_loop_B.idx];
            }

            full_loop_B.Opt[full_loop_B.f_i] = full_loop_B.Xnorm0;
            full_loop_B.f_i_j = 1;
            while (full_loop_B.f_i_j - 1 <= full_loop_B.i_o) {
              full_loop_B.idx = static_cast<int16_T>(full_loop_B.f_i_j) + 17;
              if (full_loop_B.idx > 32767) {
                full_loop_B.idx = 32767;
              }

              full_loop_B.Opt[full_loop_B.f_i] += full_loop_B.b_D
                [(static_cast<int16_T>(full_loop_B.f_i_j) - 1) * 17 +
                full_loop_B.f_i] * full_loop_B.Rhs[full_loop_B.idx - 1];
              full_loop_B.f_i_j++;
            }
          }

          full_loop_B.f_i = 1;
          while (full_loop_B.f_i - 1 <= full_loop_B.i_o) {
            full_loop_B.f_i_j = static_cast<int16_T>(full_loop_B.f_i);
            full_loop_B.Xnorm0 = 0.0;
            for (full_loop_B.idx = 0; full_loop_B.idx < 17; full_loop_B.idx++) {
              full_loop_B.Xnorm0 += full_loop_B.b_D[(full_loop_B.f_i_j - 1) * 17
                + full_loop_B.idx] * full_loop_B.Rhs[full_loop_B.idx];
            }

            full_loop_B.idx = static_cast<int16_T>(full_loop_B.f_i) + 17;
            full_loop_B.f_i_j = full_loop_B.idx;
            if (full_loop_B.idx > 32767) {
              full_loop_B.f_i_j = 32767;
            }

            full_loop_B.Opt[full_loop_B.f_i_j - 1] = full_loop_B.Xnorm0;
            full_loop_B.c_k_a = 1;
            while (full_loop_B.c_k_a - 1 <= full_loop_B.i_o) {
              full_loop_B.f_i_j = full_loop_B.idx;
              if (full_loop_B.idx > 32767) {
                full_loop_B.f_i_j = 32767;
              }

              full_loop_B.U_tmp = full_loop_B.idx;
              if (full_loop_B.idx > 32767) {
                full_loop_B.U_tmp = 32767;
              }

              full_loop_B.i1 = static_cast<int16_T>(full_loop_B.c_k_a) + 17;
              if (full_loop_B.i1 > 32767) {
                full_loop_B.i1 = 32767;
              }

              full_loop_B.Opt[full_loop_B.f_i_j - 1] = full_loop_B.U_n[((
                static_cast<int16_T>(full_loop_B.c_k_a) - 1) * 17 +
                static_cast<int16_T>(full_loop_B.f_i)) - 1] *
                full_loop_B.Rhs[full_loop_B.i1 - 1] +
                full_loop_B.Opt[full_loop_B.U_tmp - 1];
              full_loop_B.c_k_a++;
            }

            full_loop_B.f_i++;
          }

          full_loop_B.Xnorm0 = -1.0E-12;
          kDrop = 0;
          full_loop_B.f_i = 1;
          while (full_loop_B.f_i - 1 <= full_loop_B.i_o) {
            full_loop_B.idx = static_cast<int16_T>(full_loop_B.f_i) + 17;
            full_loop_B.f_i_j = full_loop_B.idx;
            if (full_loop_B.idx > 32767) {
              full_loop_B.f_i_j = 32767;
            }

            lambda[full_loop_B.iC[static_cast<int16_T>(full_loop_B.f_i) - 1] - 1]
              = full_loop_B.Opt[full_loop_B.f_i_j - 1];
            full_loop_B.f_i_j = full_loop_B.idx;
            if (full_loop_B.idx > 32767) {
              full_loop_B.f_i_j = 32767;
            }

            if ((full_loop_B.Opt[full_loop_B.f_i_j - 1] < full_loop_B.Xnorm0) &&
                (static_cast<int16_T>(full_loop_B.f_i) <= nA)) {
              kDrop = static_cast<int16_T>(full_loop_B.f_i);
              if (full_loop_B.idx > 32767) {
                full_loop_B.idx = 32767;
              }

              full_loop_B.Xnorm0 = full_loop_B.Opt[full_loop_B.idx - 1];
            }

            full_loop_B.f_i++;
          }

          if (kDrop <= 0) {
            DualFeasible = true;
            memcpy(&x[0], &full_loop_B.Opt[0], 17U * sizeof(real_T));
          } else {
            (*status)++;
            if (static_cast<int32_T>(*status) > 5) {
              nA = 0;
              iA[0] = 0;
              full_loop_B.iC[0] = 0;
              iA[1] = 0;
              full_loop_B.iC[1] = 0;
              iA[2] = 0;
              full_loop_B.iC[2] = 0;
              iA[3] = 0;
              full_loop_B.iC[3] = 0;
              ColdReset = true;
            } else {
              lambda[full_loop_B.iC[kDrop - 1] - 1] = 0.0;
              full_loop_DropConstraint(kDrop, iA, &nA, full_loop_B.iC);
            }
          }
        }
      } else {
        if (nA <= 0) {
          lambda[0] = 0.0;
          lambda[1] = 0.0;
          lambda[2] = 0.0;
          lambda[3] = 0.0;
          full_loop_Unconstrained(b_Hinv, f, x, 17);
        }

        exitg3 = 1;
      }
    } while (exitg3 == 0);

    if (exitg3 == 1) {
      guard1 = true;
    }
  } else {
    full_loop_Unconstrained(b_Hinv, f, x, 17);
    guard1 = true;
  }

  if (guard1) {
    full_loop_B.Xnorm0 = full_loop_norm_i(x);
    do {
      exitg2 = 0;
      full_loop_B.i_o = static_cast<int32_T>(*status);
      if (full_loop_B.i_o <= maxiter) {
        full_loop_B.cMin = -FeasTol;
        kNext = 0;
        for (full_loop_B.f_i = 0; full_loop_B.f_i < 4; full_loop_B.f_i++) {
          if (!cTolComputed) {
            full_loop_B.f_i_j = full_loop_B.f_i + 1;
            for (full_loop_B.idx = 0; full_loop_B.idx < 17; full_loop_B.idx++) {
              full_loop_B.b_Ac[full_loop_B.idx] = b_Ac[((full_loop_B.idx << 2) +
                full_loop_B.f_i_j) - 1] * x[full_loop_B.idx];
            }

            full_loop_abs(full_loop_B.b_Ac, full_loop_B.AcRow);
            if (!rtIsNaN(full_loop_B.AcRow[0])) {
              full_loop_B.idx = 1;
            } else {
              full_loop_B.idx = 0;
              full_loop_B.f_i_j = 2;
              exitg4 = false;
              while ((!exitg4) && (full_loop_B.f_i_j < 18)) {
                if (!rtIsNaN(full_loop_B.AcRow[full_loop_B.f_i_j - 1])) {
                  full_loop_B.idx = full_loop_B.f_i_j;
                  exitg4 = true;
                } else {
                  full_loop_B.f_i_j++;
                }
              }
            }

            if (full_loop_B.idx == 0) {
              full_loop_B.cVal = full_loop_B.AcRow[0];
            } else {
              full_loop_B.cVal = full_loop_B.AcRow[full_loop_B.idx - 1];
              while (full_loop_B.idx + 1 <= 17) {
                if (full_loop_B.cVal < full_loop_B.AcRow[full_loop_B.idx]) {
                  full_loop_B.cVal = full_loop_B.AcRow[full_loop_B.idx];
                }

                full_loop_B.idx++;
              }
            }

            if ((!(full_loop_B.cTol[full_loop_B.f_i] > full_loop_B.cVal)) &&
                (!rtIsNaN(full_loop_B.cVal))) {
              full_loop_B.cTol[full_loop_B.f_i] = full_loop_B.cVal;
            }
          }

          if (iA[full_loop_B.f_i] == 0) {
            full_loop_B.f_i_j = full_loop_B.f_i + 1;
            full_loop_B.cVal = 0.0;
            for (full_loop_B.idx = 0; full_loop_B.idx < 17; full_loop_B.idx++) {
              full_loop_B.cVal += b_Ac[((full_loop_B.idx << 2) +
                full_loop_B.f_i_j) - 1] * x[full_loop_B.idx];
            }

            full_loop_B.cVal = (full_loop_B.cVal - b[full_loop_B.f_i]) /
              full_loop_B.cTol[full_loop_B.f_i];
            if (full_loop_B.cVal < full_loop_B.cMin) {
              full_loop_B.cMin = full_loop_B.cVal;
              kNext = static_cast<int16_T>(full_loop_B.f_i + 1);
            }
          }
        }

        cTolComputed = true;
        if (kNext <= 0) {
          exitg2 = 1;
        } else if (full_loop_B.i_o == maxiter) {
          *status = 0.0;
          exitg2 = 1;
        } else {
          do {
            exitg1 = 0;
            if ((kNext > 0) && (static_cast<int32_T>(*status) <= maxiter)) {
              guard2 = false;
              if (nA == 0) {
                for (full_loop_B.i_o = 0; full_loop_B.i_o < 17; full_loop_B.i_o
                     ++) {
                  full_loop_B.AcRow[full_loop_B.i_o] = 0.0;
                  for (full_loop_B.idx = 0; full_loop_B.idx < 17;
                       full_loop_B.idx++) {
                    full_loop_B.AcRow[full_loop_B.i_o] += b_Ac[((full_loop_B.idx
                      << 2) + kNext) - 1] * b_Hinv[17 * full_loop_B.idx +
                      full_loop_B.i_o];
                  }
                }

                guard2 = true;
              } else {
                full_loop_B.cMin = full_loop_KWIKfactor(b_Ac, full_loop_B.iC, nA,
                  b_Linv, full_loop_B.RLinv, full_loop_B.b_D, full_loop_B.b_H_o,
                  17);
                if (full_loop_B.cMin <= 0.0) {
                  *status = -2.0;
                  exitg1 = 1;
                } else {
                  for (full_loop_B.i_o = 0; full_loop_B.i_o < 289;
                       full_loop_B.i_o++) {
                    full_loop_B.U_n[full_loop_B.i_o] =
                      -full_loop_B.b_H_o[full_loop_B.i_o];
                  }

                  for (full_loop_B.i_o = 0; full_loop_B.i_o < 17;
                       full_loop_B.i_o++) {
                    full_loop_B.AcRow[full_loop_B.i_o] = 0.0;
                    for (full_loop_B.idx = 0; full_loop_B.idx < 17;
                         full_loop_B.idx++) {
                      full_loop_B.AcRow[full_loop_B.i_o] += b_Ac
                        [((full_loop_B.idx << 2) + kNext) - 1] *
                        full_loop_B.U_n[17 * full_loop_B.idx + full_loop_B.i_o];
                    }
                  }

                  full_loop_B.idx = 1;
                  while (full_loop_B.idx - 1 <= nA - 1) {
                    full_loop_B.f_i = static_cast<int16_T>(full_loop_B.idx);
                    full_loop_B.cVal = 0.0;
                    for (full_loop_B.i_o = 0; full_loop_B.i_o < 17;
                         full_loop_B.i_o++) {
                      full_loop_B.cVal += b_Ac[((full_loop_B.i_o << 2) + kNext)
                        - 1] * full_loop_B.b_D[(full_loop_B.f_i - 1) * 17 +
                        full_loop_B.i_o];
                    }

                    full_loop_B.r_i[static_cast<int16_T>(full_loop_B.idx) - 1] =
                      full_loop_B.cVal;
                    full_loop_B.idx++;
                  }

                  guard2 = true;
                }
              }

              if (guard2) {
                kDrop = 0;
                full_loop_B.cMin = 0.0;
                DualFeasible = true;
                ColdReset = true;
                if (nA > 0) {
                  full_loop_B.i_o = 0;
                  exitg4 = false;
                  while ((!exitg4) && (full_loop_B.i_o <= nA - 1)) {
                    if (full_loop_B.r_i[full_loop_B.i_o] >= 1.0E-12) {
                      ColdReset = false;
                      exitg4 = true;
                    } else {
                      full_loop_B.i_o++;
                    }
                  }
                }

                if ((nA != 0) && (!ColdReset)) {
                  full_loop_B.idx = 1;
                  while (full_loop_B.idx - 1 <= nA - 1) {
                    full_loop_B.i_o = static_cast<int16_T>(full_loop_B.idx) - 1;
                    if (full_loop_B.r_i[full_loop_B.i_o] > 1.0E-12) {
                      full_loop_B.cVal = lambda[full_loop_B.iC[full_loop_B.i_o]
                        - 1] / full_loop_B.r_i[full_loop_B.i_o];
                      if ((kDrop == 0) || (full_loop_B.cVal < full_loop_B.rMin))
                      {
                        full_loop_B.rMin = full_loop_B.cVal;
                        kDrop = static_cast<int16_T>(full_loop_B.idx);
                      }
                    }

                    full_loop_B.idx++;
                  }

                  if (kDrop > 0) {
                    full_loop_B.cMin = full_loop_B.rMin;
                    DualFeasible = false;
                  }
                }

                full_loop_B.zTa = 0.0;
                for (full_loop_B.i_o = 0; full_loop_B.i_o < 17; full_loop_B.i_o
                     ++) {
                  full_loop_B.zTa += b_Ac[((full_loop_B.i_o << 2) + kNext) - 1] *
                    full_loop_B.AcRow[full_loop_B.i_o];
                }

                if (full_loop_B.zTa <= 0.0) {
                  full_loop_B.cVal = 0.0;
                  ColdReset = true;
                } else {
                  full_loop_B.cVal = 0.0;
                  for (full_loop_B.i_o = 0; full_loop_B.i_o < 17;
                       full_loop_B.i_o++) {
                    full_loop_B.cVal += b_Ac[((full_loop_B.i_o << 2) + kNext) -
                      1] * x[full_loop_B.i_o];
                  }

                  full_loop_B.cVal = (b[kNext - 1] - full_loop_B.cVal) /
                    full_loop_B.zTa;
                  ColdReset = false;
                }

                if (DualFeasible && ColdReset) {
                  *status = -1.0;
                  exitg1 = 1;
                } else {
                  if (ColdReset) {
                    full_loop_B.zTa = full_loop_B.cMin;
                  } else if (DualFeasible) {
                    full_loop_B.zTa = full_loop_B.cVal;
                  } else if ((full_loop_B.cMin < full_loop_B.cVal) || rtIsNaN
                             (full_loop_B.cVal)) {
                    full_loop_B.zTa = full_loop_B.cMin;
                  } else {
                    full_loop_B.zTa = full_loop_B.cVal;
                  }

                  full_loop_B.i_o = 1;
                  while (full_loop_B.i_o - 1 <= nA - 1) {
                    full_loop_B.f_i = static_cast<int16_T>(full_loop_B.i_o) - 1;
                    full_loop_B.idx = full_loop_B.iC[full_loop_B.f_i] - 1;
                    lambda[full_loop_B.idx] -= full_loop_B.r_i[full_loop_B.f_i] *
                      full_loop_B.zTa;
                    if ((full_loop_B.iC[full_loop_B.f_i] <= 4) &&
                        (lambda[full_loop_B.idx] < 0.0)) {
                      lambda[full_loop_B.idx] = 0.0;
                    }

                    full_loop_B.i_o++;
                  }

                  full_loop_B.f_i = kNext - 1;
                  lambda[full_loop_B.f_i] += full_loop_B.zTa;
                  if (full_loop_B.zTa == full_loop_B.cMin) {
                    full_loop_DropConstraint(kDrop, iA, &nA, full_loop_B.iC);
                  }

                  if (!ColdReset) {
                    for (full_loop_B.i_o = 0; full_loop_B.i_o < 17;
                         full_loop_B.i_o++) {
                      x[full_loop_B.i_o] += full_loop_B.zTa *
                        full_loop_B.AcRow[full_loop_B.i_o];
                    }

                    if (full_loop_B.zTa == full_loop_B.cVal) {
                      if (nA == 17) {
                        *status = -1.0;
                        exitg1 = 1;
                      } else {
                        full_loop_B.i_o = nA + 1;
                        if (full_loop_B.i_o > 32767) {
                          full_loop_B.i_o = 32767;
                        }

                        nA = static_cast<int16_T>(full_loop_B.i_o);
                        full_loop_B.iC[static_cast<int16_T>(full_loop_B.i_o) - 1]
                          = kNext;
                        kNext = static_cast<int16_T>(full_loop_B.i_o);
                        exitg4 = false;
                        while ((!exitg4) && (kNext > 1)) {
                          full_loop_B.i_o = kNext - 1;
                          full_loop_B.idx = kNext - 2;
                          if (full_loop_B.iC[full_loop_B.i_o] >
                              full_loop_B.iC[full_loop_B.idx]) {
                            exitg4 = true;
                          } else {
                            kNext = full_loop_B.iC[full_loop_B.i_o];
                            full_loop_B.iC[full_loop_B.i_o] =
                              full_loop_B.iC[full_loop_B.idx];
                            full_loop_B.iC[full_loop_B.idx] = kNext;
                            kNext = static_cast<int16_T>(full_loop_B.i_o);
                          }
                        }

                        iA[full_loop_B.f_i] = 1;
                        kNext = 0;
                        (*status)++;
                      }
                    } else {
                      (*status)++;
                    }
                  } else {
                    (*status)++;
                  }
                }
              }
            } else {
              full_loop_B.cMin = full_loop_norm_i(x);
              if (fabs(full_loop_B.cMin - full_loop_B.Xnorm0) > 0.001) {
                full_loop_B.Xnorm0 = full_loop_B.cMin;
                full_loop_abs_d(b, full_loop_B.varargin_1_p);
                if (full_loop_B.varargin_1_p[0] > 1.0) {
                  full_loop_B.cTol[0] = full_loop_B.varargin_1_p[0];
                } else {
                  full_loop_B.cTol[0] = 1.0;
                }

                if (full_loop_B.varargin_1_p[1] > 1.0) {
                  full_loop_B.cTol[1] = full_loop_B.varargin_1_p[1];
                } else {
                  full_loop_B.cTol[1] = 1.0;
                }

                if (full_loop_B.varargin_1_p[2] > 1.0) {
                  full_loop_B.cTol[2] = full_loop_B.varargin_1_p[2];
                } else {
                  full_loop_B.cTol[2] = 1.0;
                }

                if (full_loop_B.varargin_1_p[3] > 1.0) {
                  full_loop_B.cTol[3] = full_loop_B.varargin_1_p[3];
                } else {
                  full_loop_B.cTol[3] = 1.0;
                }

                cTolComputed = false;
              }

              exitg1 = 2;
            }
          } while (exitg1 == 0);

          if (exitg1 == 1) {
            exitg2 = 1;
          }
        }
      } else {
        exitg2 = 1;
      }
    } while (exitg2 == 0);
  }
}

// Function for MATLAB Function: '<S98>/FixedHorizonOptimizer'
static void full_loop_mpc_solveQP(const real_T xQP[20], const real_T b_Kx[320],
  const real_T b_Kr[1920], const real_T rseq[120], const real_T b_Ku1[128],
  const real_T old_u[8], const real_T b_Kv[176], const real_T vseq[11], const
  real_T b_Kut[1280], const real_T b_utarget[80], const real_T b_Linv[289],
  const real_T b_Hinv[289], const real_T b_Ac[68], const real_T Bc[4], boolean_T
  iA[4], real_T zopt[17], real_T f[17], real_T *status)
{
  memset(&f[0], 0, 17U * sizeof(real_T));
  for (full_loop_B.i_p = 0; full_loop_B.i_p < 16; full_loop_B.i_p++) {
    full_loop_B.b_Kx = 0.0;
    for (full_loop_B.i_pi = 0; full_loop_B.i_pi < 20; full_loop_B.i_pi++) {
      full_loop_B.b_Kx += b_Kx[20 * full_loop_B.i_p + full_loop_B.i_pi] *
        xQP[full_loop_B.i_pi];
    }

    full_loop_B.b_Kr = 0.0;
    for (full_loop_B.i_pi = 0; full_loop_B.i_pi < 120; full_loop_B.i_pi++) {
      full_loop_B.b_Kr += b_Kr[120 * full_loop_B.i_p + full_loop_B.i_pi] *
        rseq[full_loop_B.i_pi];
    }

    full_loop_B.b_Ku1 = 0.0;
    for (full_loop_B.i_pi = 0; full_loop_B.i_pi < 8; full_loop_B.i_pi++) {
      full_loop_B.b_Ku1 += b_Ku1[(full_loop_B.i_p << 3) + full_loop_B.i_pi] *
        old_u[full_loop_B.i_pi];
    }

    full_loop_B.b_Kv = 0.0;
    for (full_loop_B.i_pi = 0; full_loop_B.i_pi < 11; full_loop_B.i_pi++) {
      full_loop_B.b_Kv += b_Kv[11 * full_loop_B.i_p + full_loop_B.i_pi] *
        vseq[full_loop_B.i_pi];
    }

    full_loop_B.b_Kut = 0.0;
    for (full_loop_B.i_pi = 0; full_loop_B.i_pi < 80; full_loop_B.i_pi++) {
      full_loop_B.b_Kut += b_Kut[80 * full_loop_B.i_p + full_loop_B.i_pi] *
        b_utarget[full_loop_B.i_pi];
    }

    f[full_loop_B.i_p] = (((full_loop_B.b_Kx + full_loop_B.b_Kr) +
      full_loop_B.b_Ku1) + full_loop_B.b_Kv) + full_loop_B.b_Kut;
  }

  full_loop_B.iAnew[0] = iA[0];
  full_loop_B.iAnew[1] = iA[1];
  full_loop_B.iAnew[2] = iA[2];
  full_loop_B.iAnew[3] = iA[3];
  full_loop_qpkwik(b_Linv, b_Hinv, f, b_Ac, Bc, full_loop_B.iAnew, 120, 0.01,
                   zopt, full_loop_B.unusedU0, status);
  iA[0] = (full_loop_B.iAnew[0] != 0);
  iA[1] = (full_loop_B.iAnew[1] != 0);
  iA[2] = (full_loop_B.iAnew[2] != 0);
  iA[3] = (full_loop_B.iAnew[3] != 0);
  if ((*status < 0.0) || (*status == 0.0)) {
    memset(&zopt[0], 0, 17U * sizeof(real_T));
  }
}

// Function for MATLAB Function: '<S98>/FixedHorizonOptimizer'
static void full_loop_mpcblock_optimizer(const real_T rseq[120], const real_T
  vseq[11], const real_T umin[8], const real_T umax[8], const real_T x[20],
  const real_T old_u[8], const boolean_T iA[4], const real_T b_Mlim[4], real_T
  b_Mx[80], real_T b_Mu1[32], real_T b_Mv[44], const real_T b_utarget[80], const
  real_T b_uoff[8], real_T b_H[289], real_T b_Ac[68], const real_T b_Wy[12],
  const real_T b_Wdu[8], const real_T b_Jm[1280], const real_T b_Wu[8], const
  real_T b_I1[640], const real_T b_A[400], const real_T Bu[1760], const real_T
  Bv[220], const real_T b_C[240], const real_T Dv[132], const real_T b_Mrows[4],
  real_T u[8], real_T useq[88], real_T *status, boolean_T iAout[4])
{
  static const real_T c[100] = { 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 0.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.0, 0.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.0, 0.0, 0.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 1.0, 1.0,
    1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 1.0, 1.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 1.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    1.0 };

  boolean_T exitg1;
  boolean_T guard1 = false;
  memset(&useq[0], 0, 88U * sizeof(real_T));
  iAout[0] = false;
  iAout[1] = false;
  iAout[2] = false;
  iAout[3] = false;
  full_loop_mpc_constraintcoef(b_A, Bu, Bv, b_C, Dv, b_Jm, full_loop_B.c_SuJm,
    full_loop_B.c_Sx, full_loop_B.c_Su1, full_loop_B.c_Hv);
  if (b_Mrows[0] > 0.0) {
    full_loop_B.b_i = 0;
    exitg1 = false;
    while ((!exitg1) && (full_loop_B.b_i < 4)) {
      if (b_Mrows[full_loop_B.b_i] <= 120.0) {
        full_loop_B.b_Mrows_tmp = static_cast<int32_T>(b_Mrows[full_loop_B.b_i]);
        for (full_loop_B.d_i = 0; full_loop_B.d_i < 16; full_loop_B.d_i++) {
          b_Ac[full_loop_B.b_i + (full_loop_B.d_i << 2)] = -full_loop_B.c_SuJm
            [(120 * full_loop_B.d_i + full_loop_B.b_Mrows_tmp) - 1];
        }

        for (full_loop_B.d_i = 0; full_loop_B.d_i < 20; full_loop_B.d_i++) {
          b_Mx[full_loop_B.b_i + (full_loop_B.d_i << 2)] = -full_loop_B.c_Sx
            [(120 * full_loop_B.d_i + full_loop_B.b_Mrows_tmp) - 1];
        }

        for (full_loop_B.d_i = 0; full_loop_B.d_i < 8; full_loop_B.d_i++) {
          b_Mu1[full_loop_B.b_i + (full_loop_B.d_i << 2)] = -full_loop_B.c_Su1
            [(120 * full_loop_B.d_i + full_loop_B.b_Mrows_tmp) - 1];
        }

        for (full_loop_B.d_i = 0; full_loop_B.d_i < 11; full_loop_B.d_i++) {
          b_Mv[full_loop_B.b_i + (full_loop_B.d_i << 2)] = -full_loop_B.c_Hv
            [(120 * full_loop_B.d_i + full_loop_B.b_Mrows_tmp) - 1];
        }

        full_loop_B.b_i++;
      } else if (b_Mrows[full_loop_B.b_i] <= 240.0) {
        full_loop_B.b_Mrows_tmp = static_cast<int32_T>(b_Mrows[full_loop_B.b_i]
          - 120.0);
        for (full_loop_B.d_i = 0; full_loop_B.d_i < 16; full_loop_B.d_i++) {
          b_Ac[full_loop_B.b_i + (full_loop_B.d_i << 2)] = full_loop_B.c_SuJm
            [(120 * full_loop_B.d_i + full_loop_B.b_Mrows_tmp) - 1];
        }

        for (full_loop_B.d_i = 0; full_loop_B.d_i < 20; full_loop_B.d_i++) {
          b_Mx[full_loop_B.b_i + (full_loop_B.d_i << 2)] = full_loop_B.c_Sx[(120
            * full_loop_B.d_i + full_loop_B.b_Mrows_tmp) - 1];
        }

        for (full_loop_B.d_i = 0; full_loop_B.d_i < 8; full_loop_B.d_i++) {
          b_Mu1[full_loop_B.b_i + (full_loop_B.d_i << 2)] = full_loop_B.c_Su1
            [(120 * full_loop_B.d_i + full_loop_B.b_Mrows_tmp) - 1];
        }

        for (full_loop_B.d_i = 0; full_loop_B.d_i < 11; full_loop_B.d_i++) {
          b_Mv[full_loop_B.b_i + (full_loop_B.d_i << 2)] = full_loop_B.c_Hv[(120
            * full_loop_B.d_i + full_loop_B.b_Mrows_tmp) - 1];
        }

        full_loop_B.b_i++;
      } else {
        exitg1 = true;
      }
    }
  }

  full_loop_eye_c(full_loop_B.dv9);
  full_loop_kron(c, full_loop_B.dv9, full_loop_B.dv);
  for (full_loop_B.d_i = 0; full_loop_B.d_i < 16; full_loop_B.d_i++) {
    for (full_loop_B.b_i = 0; full_loop_B.b_i < 80; full_loop_B.b_i++) {
      full_loop_B.b_Mrows_tmp = full_loop_B.b_i + 80 * full_loop_B.d_i;
      full_loop_B.dv2[full_loop_B.b_Mrows_tmp] = 0.0;
      for (full_loop_B.c_Linv_tmp = 0; full_loop_B.c_Linv_tmp < 80;
           full_loop_B.c_Linv_tmp++) {
        full_loop_B.dv2[full_loop_B.b_Mrows_tmp] += full_loop_B.dv[80 *
          full_loop_B.c_Linv_tmp + full_loop_B.b_i] * b_Jm[80 * full_loop_B.d_i
          + full_loop_B.c_Linv_tmp];
      }
    }
  }

  full_loop_mpc_calculatehessian(b_Wy, b_Wu, b_Wdu, full_loop_B.c_SuJm,
    full_loop_B.dv2, b_Jm, b_I1, full_loop_B.c_Su1, full_loop_B.c_Sx,
    full_loop_B.c_Hv, full_loop_nu, full_loop_ny, full_loop_B.b,
    full_loop_B.c_Ku1, full_loop_B.c_Kut, full_loop_B.c_Kx, full_loop_B.c_Kv,
    full_loop_B.c_Kr);
  for (full_loop_B.d_i = 0; full_loop_B.d_i < 16; full_loop_B.d_i++) {
    memcpy(&b_H[full_loop_B.d_i * 17], &full_loop_B.b[full_loop_B.d_i << 4],
           sizeof(real_T) << 4U);
  }

  memcpy(&full_loop_B.b_H[0], &b_H[0], 289U * sizeof(real_T));
  full_loop_mpc_checkhessian(full_loop_B.b_H, full_loop_B.d_Linv,
    &full_loop_B.DelBound);
  if (full_loop_B.DelBound > 1.0) {
    for (full_loop_B.b_i = 0; full_loop_B.b_i < 8; full_loop_B.b_i++) {
      u[full_loop_B.b_i] = old_u[full_loop_B.b_i] + b_uoff[full_loop_B.b_i];
      for (full_loop_B.d_i = 0; full_loop_B.d_i < 11; full_loop_B.d_i++) {
        useq[full_loop_B.d_i + 11 * full_loop_B.b_i] = u[full_loop_B.b_i];
      }
    }

    *status = -2.0;
  } else {
    full_loop_eye_cbt(full_loop_B.b_H);
    full_loop_linsolve(full_loop_B.d_Linv, full_loop_B.b_H, full_loop_B.c_Linv);
    for (full_loop_B.d_i = 0; full_loop_B.d_i < 4; full_loop_B.d_i++) {
      full_loop_B.DelBound = 0.0;
      for (full_loop_B.b_i = 0; full_loop_B.b_i < 20; full_loop_B.b_i++) {
        full_loop_B.DelBound += b_Mx[(full_loop_B.b_i << 2) + full_loop_B.d_i] *
          x[full_loop_B.b_i];
      }

      full_loop_B.b_Mu1[full_loop_B.d_i] = 0.0;
      for (full_loop_B.b_i = 0; full_loop_B.b_i < 8; full_loop_B.b_i++) {
        full_loop_B.b_Mu1[full_loop_B.d_i] += b_Mu1[(full_loop_B.b_i << 2) +
          full_loop_B.d_i] * old_u[full_loop_B.b_i];
      }

      full_loop_B.d_e = 0.0;
      for (full_loop_B.b_i = 0; full_loop_B.b_i < 11; full_loop_B.b_i++) {
        full_loop_B.d_e += b_Mv[(full_loop_B.b_i << 2) + full_loop_B.d_i] *
          vseq[full_loop_B.b_i];
      }

      full_loop_B.Bc[full_loop_B.d_i] = -(((b_Mlim[full_loop_B.d_i] +
        full_loop_B.DelBound) + full_loop_B.b_Mu1[full_loop_B.d_i]) +
        full_loop_B.d_e);
    }

    for (full_loop_B.d_i = 0; full_loop_B.d_i < 8; full_loop_B.d_i++) {
      full_loop_B.umax_incr[full_loop_B.d_i] = (rtNaN);
      full_loop_B.umin_incr[full_loop_B.d_i] = (rtNaN);
    }

    if (b_Mrows[0] > 0.0) {
      full_loop_B.b_i = 0;
      exitg1 = false;
      while ((!exitg1) && (full_loop_B.b_i < 4)) {
        full_loop_B.DelBound = 0.0;
        guard1 = false;
        if ((b_Mrows[full_loop_B.b_i] <= 120.0) || (b_Mrows[full_loop_B.b_i] <=
             240.0)) {
          guard1 = true;
        } else if (b_Mrows[full_loop_B.b_i] <= 320.0) {
          full_loop_B.d_i = static_cast<int32_T>(full_loop_mod_id
            ((b_Mrows[full_loop_B.b_i] - 240.0) - 1.0) + 1.0) - 1;
          if (rtIsNaN(full_loop_B.umax_incr[full_loop_B.d_i])) {
            full_loop_B.DelBound = -(umax[full_loop_B.d_i] -
              b_uoff[full_loop_B.d_i]) - (-b_Mlim[full_loop_B.b_i]);
          } else {
            full_loop_B.DelBound = full_loop_B.umax_incr[full_loop_B.d_i];
          }

          full_loop_B.umax_incr[full_loop_B.d_i] = full_loop_B.DelBound;
          guard1 = true;
        } else if (b_Mrows[full_loop_B.b_i] <= 400.0) {
          full_loop_B.d_i = static_cast<int32_T>(full_loop_mod_id
            (((b_Mrows[full_loop_B.b_i] - 240.0) - 80.0) - 1.0) + 1.0) - 1;
          if (rtIsNaN(full_loop_B.umin_incr[full_loop_B.d_i])) {
            full_loop_B.DelBound = (umin[full_loop_B.d_i] -
              b_uoff[full_loop_B.d_i]) - (-b_Mlim[full_loop_B.b_i]);
          } else {
            full_loop_B.DelBound = full_loop_B.umin_incr[full_loop_B.d_i];
          }

          full_loop_B.umin_incr[full_loop_B.d_i] = full_loop_B.DelBound;
          guard1 = true;
        } else {
          exitg1 = true;
        }

        if (guard1) {
          full_loop_B.Bc[full_loop_B.b_i] += full_loop_B.DelBound;
          full_loop_B.b_i++;
        }
      }
    }

    iAout[0] = iA[0];
    iAout[1] = iA[1];
    iAout[2] = iA[2];
    iAout[3] = iA[3];
    for (full_loop_B.d_i = 0; full_loop_B.d_i < 17; full_loop_B.d_i++) {
      for (full_loop_B.b_i = 0; full_loop_B.b_i < 17; full_loop_B.b_i++) {
        full_loop_B.c_Linv_tmp = full_loop_B.d_i + 17 * full_loop_B.b_i;
        full_loop_B.d_Linv[full_loop_B.c_Linv_tmp] = 0.0;
        for (full_loop_B.b_Mrows_tmp = 0; full_loop_B.b_Mrows_tmp < 17;
             full_loop_B.b_Mrows_tmp++) {
          full_loop_B.d_Linv[full_loop_B.c_Linv_tmp] += full_loop_B.c_Linv[17 *
            full_loop_B.d_i + full_loop_B.b_Mrows_tmp] * full_loop_B.c_Linv[17 *
            full_loop_B.b_i + full_loop_B.b_Mrows_tmp];
        }
      }
    }

    full_loop_mpc_solveQP(x, full_loop_B.c_Kx, full_loop_B.c_Kr, rseq,
                          full_loop_B.c_Ku1, old_u, full_loop_B.c_Kv, vseq,
                          full_loop_B.c_Kut, b_utarget, full_loop_B.c_Linv,
                          full_loop_B.d_Linv, b_Ac, full_loop_B.Bc, iAout,
                          full_loop_B.zopt, full_loop_B.f_f, status);
    for (full_loop_B.d_i = 0; full_loop_B.d_i < 8; full_loop_B.d_i++) {
      u[full_loop_B.d_i] = (old_u[full_loop_B.d_i] +
                            full_loop_B.zopt[full_loop_B.d_i]) +
        b_uoff[full_loop_B.d_i];
    }
  }
}

static void rt_mrdivide_U1d1x3_U2d_9vOrDY_p(const real_T u0[3], const real_T u1
  [9], real_T y[3])
{
  int32_T r1;
  int32_T r2;
  int32_T r3;
  real_T maxval;
  real_T a21;
  int32_T rtemp;
  memcpy(&full_loop_B.A_f[0], &u1[0], 9U * sizeof(real_T));
  r1 = 0;
  r2 = 1;
  r3 = 2;
  maxval = fabs(u1[0]);
  a21 = fabs(u1[1]);
  if (a21 > maxval) {
    maxval = a21;
    r1 = 1;
    r2 = 0;
  }

  if (fabs(u1[2]) > maxval) {
    r1 = 2;
    r2 = 1;
    r3 = 0;
  }

  full_loop_B.A_f[r2] = u1[r2] / u1[r1];
  full_loop_B.A_f[r3] /= full_loop_B.A_f[r1];
  full_loop_B.A_f[r2 + 3] -= full_loop_B.A_f[r1 + 3] * full_loop_B.A_f[r2];
  full_loop_B.A_f[r3 + 3] -= full_loop_B.A_f[r1 + 3] * full_loop_B.A_f[r3];
  full_loop_B.A_f[r2 + 6] -= full_loop_B.A_f[r1 + 6] * full_loop_B.A_f[r2];
  full_loop_B.A_f[r3 + 6] -= full_loop_B.A_f[r1 + 6] * full_loop_B.A_f[r3];
  if (fabs(full_loop_B.A_f[r3 + 3]) > fabs(full_loop_B.A_f[r2 + 3])) {
    rtemp = r2 + 1;
    r2 = r3;
    r3 = rtemp - 1;
  }

  full_loop_B.A_f[r3 + 3] /= full_loop_B.A_f[r2 + 3];
  full_loop_B.A_f[r3 + 6] -= full_loop_B.A_f[r3 + 3] * full_loop_B.A_f[r2 + 6];
  y[r1] = u0[0] / full_loop_B.A_f[r1];
  y[r2] = u0[1] - full_loop_B.A_f[r1 + 3] * y[r1];
  y[r3] = u0[2] - full_loop_B.A_f[r1 + 6] * y[r1];
  y[r2] /= full_loop_B.A_f[r2 + 3];
  y[r3] -= full_loop_B.A_f[r2 + 6] * y[r2];
  y[r3] /= full_loop_B.A_f[r3 + 6];
  y[r2] -= full_loop_B.A_f[r3 + 3] * y[r3];
  y[r1] -= y[r3] * full_loop_B.A_f[r3];
  y[r1] -= y[r2] * full_loop_B.A_f[r2];
}

real_T rt_urand_Upu32_Yd_f_pw_snf(uint32_T *u)
{
  uint32_T lo;
  uint32_T hi;

  // Uniform random number generator (random number between 0 and 1)

  // #define IA      16807                      magic multiplier = 7^5
  // #define IM      2147483647                 modulus = 2^31-1
  // #define IQ      127773                     IM div IA
  // #define IR      2836                       IM modulo IA
  // #define S       4.656612875245797e-10      reciprocal of 2^31-1
  // test = IA * (seed % IQ) - IR * (seed/IQ)
  // seed = test < 0 ? (test + IM) : test
  // return (seed*S)

  lo = *u % 127773U * 16807U;
  hi = *u / 127773U * 2836U;
  if (lo < hi) {
    *u = 2147483647U - (hi - lo);
  } else {
    *u = lo - hi;
  }

  return static_cast<real_T>(*u) * 4.6566128752457969E-10;
}

real_T rt_nrand_Upu32_Yd_f_pw_snf(uint32_T *u)
{
  real_T y;
  real_T sr;
  real_T si;

  // Normal (Gaussian) random number generator
  do {
    sr = 2.0 * rt_urand_Upu32_Yd_f_pw_snf(u) - 1.0;
    si = 2.0 * rt_urand_Upu32_Yd_f_pw_snf(u) - 1.0;
    si = sr * sr + si * si;
  } while (si > 1.0);

  y = sqrt(-2.0 * log(si) / si) * sr;
  return y;
}

static void matlabCodegenHandle_matlabCodeg(ros_slros_internal_block_Publ_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
  }
}

// Model step function
void full_loop_step(void)
{
  static const real_T hb[400] = { 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -0.003505211357712782, 0.0,
    1.0001011234817523, 0.0, -3.8714377485932475E-6, 0.0, -0.063327057959395652,
    0.0, 0.0018878810295490144, 0.0, -7.3477213177624033E-5, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0040576930676494271, 0.0, 0.0, 0.0, 1.0001011234817523,
    1.1614313245779743E-5, 0.078838973859500838, 0.0, 0.0, 0.0,
    0.0018878810295490144, 0.00022043163953287204, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.091677550978548614, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.83830186295742293, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.073639288055160623, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.52376311972338552, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.056234967408341538, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.27594539341962043, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, -0.00011037601451439658, 0.0, 0.081310887742745711, 0.0,
    -1.1917993059659676E-7, 0.0, -0.0030314950595430111, 0.0,
    0.65112772639132543, 0.0, -3.3599364429270056E-6, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.00012356415888092328, 0.0, 0.0, 0.0, 0.081310887742745711,
    3.5753979178979024E-7, 0.0035273753515309711, 0.0, 0.0, 0.0,
    0.65112772639132543, 1.0079809328781016E-5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.085442542837713659, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.72371480551622369, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0 };

  KickIn_full_loop_T *tunableEnvironment;
  boolean_T y;
  static const int8_T fb[240] = { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0,
    0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 };

  static const real_T gb[580] = { 9.8281202243112736E-5, -8.48996598775658E-5,
    0.0, 4.9892355423045837E-6, 4.9892355423045837E-6, -4.509705560864235E-5,
    0.0019095912664952347, -0.0015338772478678197, 0.0, 9.3144371307677436E-5,
    9.3144371307677436E-5, -0.00085589444794253186, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 9.8281202243112736E-5, 8.48996598775658E-5, 0.0,
    -4.9892355423045837E-6, 4.9892355423045837E-6, -4.5324190211065575E-5,
    0.0019095912664952347, 0.0015338772478678197, 0.0, -9.3144371307677436E-5,
    9.3144371307677436E-5, -0.00086020508468270189, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 9.8281202243112736E-5, -8.48996598775658E-5, 0.0,
    4.9892355423045837E-6, 4.9892355423045837E-6, 4.4919696943336E-5,
    0.0019095912664952347, -0.0015338772478678197, 0.0, 9.3144371307677436E-5,
    9.3144371307677436E-5, 0.00085252864465994356, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 9.8281202243112736E-5, 8.48996598775658E-5, 0.0,
    -4.9892355423045837E-6, 4.9892355423045837E-6, 4.4690506422740732E-5,
    0.0019095912664952347, 0.0015338772478678197, 0.0, -9.3144371307677436E-5,
    9.3144371307677436E-5, 0.00084817898875965011, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, -1.6916258124432826E-8, -1.3871401991420668E-8,
    0.00010012040654747496, 2.0782669460141204E-5, -2.3155998997256098E-5,
    -6.4057814186153289E-11, -6.569464117233183E-7, -5.26683780598888E-7,
    0.00165640552012788, 0.00038799304313180574, -0.00043230089064994403,
    -2.4696047474140147E-9, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    -1.7103695887584432E-8, 1.3871401991420668E-8, -0.00010012040654747496,
    -2.0782669460141204E-5, -2.3412575163430679E-5, -3.5102043168105315E-11,
    -6.6422559634075111E-7, 5.26683780598888E-7, -0.00165640552012788,
    -0.00038799304313180574, -0.00043709092821947248, -1.3532802134017093E-9,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.7103695887584432E-8,
    1.3357646362108793E-8, 0.00010012040654747498, -2.0012940961617463E-5,
    2.3412575163430679E-5, 6.40578141861533E-11, 6.6422559634075111E-7,
    5.0717697391004044E-7, 0.0016564055201278801, -0.0003736229304232204,
    0.00043709092821947248, 2.4696047474140151E-9, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 1.6916258124432826E-8, -1.3357646362108793E-8,
    -0.00010012040654747498, 2.0012940961617463E-5, 2.3155998997256098E-5,
    3.5102043168105309E-11, 6.569464117233183E-7, -5.0717697391004044E-7,
    -0.0016564055201278801, 0.0003736229304232204, 0.00043230089064994403,
    1.3532802134017093E-9, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.1,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.1, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.1, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.1, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.1, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.1,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.1, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.1, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };

  static const real_T eb[348] = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0 };

  static const real_T e[4] = { 241.0, 249.0, 321.0, 329.0 };

  static const real_T u[32] = { -1.0, -1.0, 1.0, 1.0, -0.0, -0.0, 0.0, 0.0, -0.0,
    -0.0, 0.0, 0.0, -0.0, -0.0, 0.0, 0.0, -0.0, -0.0, 0.0, 0.0, -0.0, -0.0, 0.0,
    0.0, -0.0, -0.0, 0.0, 0.0, -0.0, -0.0, 0.0, 0.0 };

  static const real_T t[289] = { 0.72869342989345887, 0.53620983223724572,
    0.57429540326563933, 0.39281508071767463, -0.0041366110471868075,
    -0.0086647470470476058, 0.00428969018839374, 0.0085116679058406738,
    0.58267092692229894, 0.43007457452149217, 0.46418562560878973,
    0.31249195877206815, -0.0027910879024702845, -0.0063139237338553011,
    0.0029055619683943353, 0.00619944966793125, 0.0, 0.53620983223724561,
    0.72941773935053245, 0.39209072755699886, 0.57430192624744059,
    -0.008591716421625, -0.0042095998863708106, 0.0085797906602919864,
    0.0042215256477038231, 0.43007448309694024, 0.583264927100763,
    0.31189792389316728, 0.46419106696498236, -0.0062620517099419787,
    -0.0028429313981479872, 0.0062479708782042136, 0.0028570122298857527, 0.0,
    0.57429540326563933, 0.39209072755699886, 0.72813179129173211,
    0.53492385330226666, -0.0041473280974851125, -0.0086706197164008337,
    0.0043004072386920453, 0.0085175405751939017, 0.46418544219546787,
    0.31189764849107537, 0.58221024557383039, 0.42901977682279574,
    -0.0027984048957948029, -0.0063179332589819552, 0.0029128789617188537,
    0.0062034591930579053, 0.0, 0.39281508071767463, 0.57430192624744059,
    0.53492385330226666, 0.72740745316942323, -0.0086024332271535491,
    -0.0042154724215964761, 0.0085905074658205356, 0.0042273981829294887,
    0.31249168393838339, 0.46419070014671659, 0.42901986881575471,
    0.581616223603785, -0.0062693685361516092, -0.002846940831699959,
    0.0062552877044138432, 0.0028610216634377245, 0.0, -0.0041366110471868075,
    -0.008591716421625, -0.0041473280974851125, -0.0086024332271535491,
    0.18592015333223227, -0.056111639212658958, 0.044523316911037072,
    -0.059331831030610349, -0.003366353562071087, -0.0070968790016139325,
    -0.0033753294442569253, -0.0071058546787970481, 0.082274478495408518,
    -0.047542208215918924, 0.037961789030443518, -0.050194059309933092, 0.0,
    -0.0086647470470476058, -0.00420959988637081, -0.0086706197164008337,
    -0.0042154724215964752, -0.056111639212658958, 0.1860842362768399,
    -0.059495914282032165, 0.044523317217851258, -0.0071569522614639159,
    -0.00342639181399035, -0.0071618708152416553, -0.003431310255431844,
    -0.047542208215918924, 0.082410015897288344, -0.05032959692551995,
    0.03796178924415055, 0.0, 0.00428969018839374, 0.0085797906602919864,
    0.0043004072386920453, 0.0085905074658205356, 0.044523316911037072,
    -0.059495914282032165, 0.18565503946871265, -0.055682442097717548,
    0.0034934557835369726, 0.0070858127766035605, 0.0035024316657228109,
    0.0070947884537866752, 0.037961789030443512, -0.05032959692551995,
    0.082055185775905773, -0.047187377880829322, 0.0, 0.0085116679058406738,
    0.0042215256477038231, 0.0085175405751939017, 0.0042273981829294887,
    -0.059331831030610349, 0.044523317217851258, -0.055682442097717548,
    0.18549095591047665, 0.00702985003999803, 0.0034374580390007224,
    0.00703476859377577, 0.0034423764804422164, -0.050194059309933092,
    0.03796178924415055, -0.047187377880829322, 0.081919647946611884, 0.0,
    0.58267092692229894, 0.43007448309694035, 0.46418544219546787,
    0.3124916839383835, -0.0033663535620710875, -0.0071569522614639159,
    0.0034934557835369726, 0.0070298500399980307, 0.48528464551485978,
    0.34670895563052312, 0.37736568170418328, 0.24969220766350983,
    -0.0022803854268768054, -0.005242846720773223, 0.0023759285376479151,
    0.0051473036100021128, 0.0, 0.43007457452149223, 0.583264927100763,
    0.31189764849107549, 0.46419070014671654, -0.0070968790016139333,
    -0.0034263918139903504, 0.0070858127766035605, 0.0034374580390007219,
    0.34670895563052306, 0.48577481436106495, 0.24920201070430911,
    0.37737009642365354, -0.0051999607126169906, -0.00232324742909574,
    0.0051873708310285456, 0.0023358373106841831, 0.0, 0.46418562560878973,
    0.31189792389316734, 0.5822102455738305, 0.42901986881575482,
    -0.0033753294442569249, -0.0071618708152416553, 0.00350243166572281,
    0.00703476859377577, 0.37736568170418328, 0.24920201070430911,
    0.48490441525524836, 0.34583853709589779, -0.0022865406319259448,
    -0.0052462196156508973, 0.0023820837426970546, 0.0051506765048797871, 0.0,
    0.31249195877206826, 0.4641910669649823, 0.4290197768227958,
    0.58161622360378507, -0.0071058546787970481, -0.0034313102554318444,
    0.0070947884537866752, 0.003442376480442216, 0.24969220766350983,
    0.37737009642365354, 0.34583853709589779, 0.48441422994272254,
    -0.0052061157770856535, -0.0023266202469389096, 0.0051935258954972094,
    0.0023392101285273528, 0.0, -0.0027910879024702845, -0.0062620517099419787,
    -0.0027984048957948029, -0.0062693685361516092, 0.082274478495408518,
    -0.047542208215918924, 0.037961789030443518, -0.050194059309933092,
    -0.0022803854268768054, -0.0051999607126169906, -0.0022865406319259448,
    -0.0052061157770856535, 0.16324501895826316, -0.040572979329823282,
    0.032600526842953691, -0.042772566471393526, 0.0, -0.0063139237338553011,
    -0.0028429313981479872, -0.0063179332589819552, -0.002846940831699959,
    -0.047542208215918924, 0.082410015897288344, -0.05032959692551995,
    0.03796178924415055, -0.005242846720773223, -0.0023232474290957395,
    -0.0052462196156508973, -0.0023266202469389092, -0.040572979329823282,
    0.1633577283854461, -0.042885276048098865, 0.032600526992476064, 0.0,
    0.0029055619683943353, 0.0062479708782042136, 0.0029128789617188537,
    0.0062552877044138432, 0.037961789030443518, -0.05032959692551995,
    0.082055185775905773, -0.047187377880829322, 0.0023759285376479151,
    0.0051873708310285456, 0.0023820837426970546, 0.0051935258954972094,
    0.032600526842953691, -0.042885276048098865, 0.16306245252051377,
    -0.04027770331536857, 0.0, 0.00619944966793125, 0.0028570122298857527,
    0.0062034591930579053, 0.0028610216634377245, -0.050194059309933092,
    0.03796178924415055, -0.047187377880829322, 0.081919647946611884,
    0.0051473036100021128, 0.0023358373106841831, 0.0051506765048797871,
    0.0023392101285273528, -0.042772566471393526, 0.032600526992476064,
    -0.04027770331536857, 0.16294974279428603, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 100000.0 };

  static const real_T r[68] = { -1.0, -1.0, 1.0, 1.0, -0.0, -0.0, 0.0, 0.0, -0.0,
    -0.0, 0.0, 0.0, -0.0, -0.0, 0.0, 0.0, -0.0, -0.0, 0.0, 0.0, -0.0, -0.0, 0.0,
    0.0, -0.0, -0.0, 0.0, 0.0, -0.0, -0.0, 0.0, 0.0, -0.0, -1.0, 0.0, 1.0, -0.0,
    -0.0, 0.0, 0.0, -0.0, -0.0, 0.0, 0.0, -0.0, -0.0, 0.0, 0.0, -0.0, -0.0, 0.0,
    0.0, -0.0, -0.0, 0.0, 0.0, -0.0, -0.0, 0.0, 0.0, -0.0, -0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0 };

  static const real_T q[12] = { 4900.0, 3600.0, 3600.0, 2500.0, 2500.0, 4900.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };

  static const real_T o[8] = { 0.010000000000000002, 0.010000000000000002,
    0.010000000000000002, 0.010000000000000002, 0.09, 0.09, 0.09, 0.09 };

  static const real_T n[1280] = { 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };

  static const real_T g[8] = { 0.0001, 0.0001, 0.0001, 0.0001,
    0.0025000000000000005, 0.0025000000000000005, 0.0025000000000000005,
    0.0025000000000000005 };

  static const real_T f[640] = { 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    1.0 };

  boolean_T exitg1;
  if (rtmIsMajorTimeStep(full_loop_M)) {
    // set solver stop time
    rtsiSetSolverStopTime(&full_loop_M->solverInfo,
                          ((full_loop_M->Timing.clockTick0+1)*
      full_loop_M->Timing.stepSize0));
  }                                    // end MajorTimeStep

  // Update absolute time of base rate at minor time step
  if (rtmIsMinorTimeStep(full_loop_M)) {
    full_loop_M->Timing.t[0] = rtsiGetT(&full_loop_M->solverInfo);
  }

  // Integrator: '<S13>/ub,vb,wb'
  full_loop_B.ubvbwb[0] = full_loop_X.ubvbwb_CSTATE[0];
  full_loop_B.ubvbwb[1] = full_loop_X.ubvbwb_CSTATE[1];
  full_loop_B.ubvbwb[2] = full_loop_X.ubvbwb_CSTATE[2];
  if (rtmIsMajorTimeStep(full_loop_M) &&
      full_loop_M->Timing.TaskCounters.TID[1] == 0) {
    // DiscreteIntegrator: '<S5>/Discrete-Time Integrator1'
    full_loop_B.BodyPosition[0] = full_loop_P.DiscreteTimeIntegrator1_gainval *
      full_loop_B.ubvbwb[0] + full_loop_DW.DiscreteTimeIntegrator1_DSTATE[0];
    full_loop_B.BodyPosition[1] = full_loop_P.DiscreteTimeIntegrator1_gainval *
      full_loop_B.ubvbwb[1] + full_loop_DW.DiscreteTimeIntegrator1_DSTATE[1];
    full_loop_B.BodyPosition[2] = full_loop_P.DiscreteTimeIntegrator1_gainval *
      full_loop_B.ubvbwb[2] + full_loop_DW.DiscreteTimeIntegrator1_DSTATE[2];

    // Gain: '<S29>/1//2' incorporates:
    //   Constant: '<S19>/Initial Euler Angles'

    full_loop_B.rtb_sincos_o1_idx_0 = full_loop_P.u2_Gain *
      full_loop_P.uDOFEulerAngles_eul_0[2];
    full_loop_B.rtb_sincos_o1_idx_1 = full_loop_P.u2_Gain *
      full_loop_P.uDOFEulerAngles_eul_0[1];
    full_loop_B.rtb_sincos_o1_idx_2 = full_loop_P.u2_Gain *
      full_loop_P.uDOFEulerAngles_eul_0[0];

    // Trigonometry: '<S29>/sincos'
    full_loop_B.rtb_sincos_o2_idx_0 = cos(full_loop_B.rtb_sincos_o1_idx_0);
    full_loop_B.rtb_sincos_o1_idx_0 = sin(full_loop_B.rtb_sincos_o1_idx_0);
    full_loop_B.rtb_sincos_o2_idx_1 = cos(full_loop_B.rtb_sincos_o1_idx_1);
    full_loop_B.rtb_sincos_o1_idx_1 = sin(full_loop_B.rtb_sincos_o1_idx_1);
    full_loop_B.rtb_sincos_o2_idx_2 = cos(full_loop_B.rtb_sincos_o1_idx_2);
    full_loop_B.t26 = sin(full_loop_B.rtb_sincos_o1_idx_2);

    // Fcn: '<S29>/q0' incorporates:
    //   Fcn: '<S29>/q1'

    full_loop_B.t27 = full_loop_B.rtb_sincos_o2_idx_0 *
      full_loop_B.rtb_sincos_o2_idx_1;
    full_loop_B.rtb_sincos_o1_idx_2 = full_loop_B.rtb_sincos_o1_idx_0 *
      full_loop_B.rtb_sincos_o1_idx_1;
    full_loop_B.q0 = full_loop_B.t27 * full_loop_B.rtb_sincos_o2_idx_2 +
      full_loop_B.rtb_sincos_o1_idx_2 * full_loop_B.t26;

    // Fcn: '<S29>/q1'
    full_loop_B.q1 = full_loop_B.t27 * full_loop_B.t26 -
      full_loop_B.rtb_sincos_o1_idx_2 * full_loop_B.rtb_sincos_o2_idx_2;

    // Fcn: '<S29>/q2' incorporates:
    //   Fcn: '<S29>/q3'

    full_loop_B.rtb_sincos_o1_idx_0 *= full_loop_B.rtb_sincos_o2_idx_1;
    full_loop_B.rtb_sincos_o1_idx_1 *= full_loop_B.rtb_sincos_o2_idx_0;
    full_loop_B.q2 = full_loop_B.rtb_sincos_o1_idx_1 *
      full_loop_B.rtb_sincos_o2_idx_2 + full_loop_B.rtb_sincos_o1_idx_0 *
      full_loop_B.t26;

    // Fcn: '<S29>/q3'
    full_loop_B.q3 = full_loop_B.rtb_sincos_o1_idx_0 *
      full_loop_B.rtb_sincos_o2_idx_2 - full_loop_B.rtb_sincos_o1_idx_1 *
      full_loop_B.t26;
  }

  if (rtmIsMajorTimeStep(full_loop_M) &&
      full_loop_M->Timing.TaskCounters.TID[2] == 0) {
    // Gain: '<S65>/Output' incorporates:
    //   RandomNumber: '<S65>/White Noise'

    full_loop_B.Output = sqrt(full_loop_P.BandLimitedWhiteNoise_Cov) / 0.1 *
      full_loop_DW.NextOutput;
  }

  // Integrator: '<S19>/q0 q1 q2 q3' incorporates:
  //   SignalConversion generated from: '<S19>/q0 q1 q2 q3'

  if (full_loop_DW.q0q1q2q3_IWORK != 0) {
    full_loop_X.q0q1q2q3_CSTATE[0] = full_loop_B.q0;
    full_loop_X.q0q1q2q3_CSTATE[1] = full_loop_B.q1;
    full_loop_X.q0q1q2q3_CSTATE[2] = full_loop_B.q2;
    full_loop_X.q0q1q2q3_CSTATE[3] = full_loop_B.q3;
  }

  // Sqrt: '<S50>/sqrt' incorporates:
  //   Integrator: '<S19>/q0 q1 q2 q3'
  //   Product: '<S51>/Product'
  //   Product: '<S51>/Product1'
  //   Product: '<S51>/Product2'
  //   Product: '<S51>/Product3'
  //   Sqrt: '<S42>/sqrt'
  //   Sum: '<S51>/Sum'

  full_loop_B.Sum_a_e = sqrt(((full_loop_X.q0q1q2q3_CSTATE[0] *
    full_loop_X.q0q1q2q3_CSTATE[0] + full_loop_X.q0q1q2q3_CSTATE[1] *
    full_loop_X.q0q1q2q3_CSTATE[1]) + full_loop_X.q0q1q2q3_CSTATE[2] *
    full_loop_X.q0q1q2q3_CSTATE[2]) + full_loop_X.q0q1q2q3_CSTATE[3] *
    full_loop_X.q0q1q2q3_CSTATE[3]);

  // Product: '<S45>/Product' incorporates:
  //   Integrator: '<S19>/q0 q1 q2 q3'
  //   Sqrt: '<S50>/sqrt'

  full_loop_B.rtb_sincos_o2_idx_1 = full_loop_X.q0q1q2q3_CSTATE[0] /
    full_loop_B.Sum_a_e;

  // Product: '<S45>/Product1' incorporates:
  //   Integrator: '<S19>/q0 q1 q2 q3'
  //   Sqrt: '<S50>/sqrt'

  full_loop_B.Product2_h5 = full_loop_X.q0q1q2q3_CSTATE[1] / full_loop_B.Sum_a_e;

  // Product: '<S45>/Product2' incorporates:
  //   Integrator: '<S19>/q0 q1 q2 q3'
  //   Product: '<S41>/Product2'
  //   Sqrt: '<S50>/sqrt'

  full_loop_B.t26 = full_loop_X.q0q1q2q3_CSTATE[2] / full_loop_B.Sum_a_e;

  // Product: '<S45>/Product3' incorporates:
  //   Integrator: '<S19>/q0 q1 q2 q3'
  //   Product: '<S41>/Product3'
  //   Sqrt: '<S50>/sqrt'

  full_loop_B.t27 = full_loop_X.q0q1q2q3_CSTATE[3] / full_loop_B.Sum_a_e;

  // Fcn: '<S28>/fcn2' incorporates:
  //   Fcn: '<S28>/fcn5'
  //   Product: '<S45>/Product2'
  //   Product: '<S45>/Product3'

  full_loop_B.rtb_sincos_o1_idx_2 = full_loop_B.rtb_sincos_o2_idx_1 *
    full_loop_B.rtb_sincos_o2_idx_1;
  full_loop_B.rtb_sincos_o2_idx_2 = full_loop_B.Product2_h5 *
    full_loop_B.Product2_h5;
  full_loop_B.rtb_sincos_o2_idx_0 = full_loop_B.t26 * full_loop_B.t26;
  full_loop_B.Product3_bd = full_loop_B.t27 * full_loop_B.t27;

  // Trigonometry: '<S44>/Trigonometric Function1' incorporates:
  //   Fcn: '<S28>/fcn1'
  //   Fcn: '<S28>/fcn2'
  //   Product: '<S45>/Product2'
  //   Product: '<S45>/Product3'

  full_loop_B.rtb_sincos_o1_idx_0 = rt_atan2d_snf((full_loop_B.Product2_h5 *
    full_loop_B.t26 + full_loop_B.rtb_sincos_o2_idx_1 * full_loop_B.t27) * 2.0,
    ((full_loop_B.rtb_sincos_o1_idx_2 + full_loop_B.rtb_sincos_o2_idx_2) -
     full_loop_B.rtb_sincos_o2_idx_0) - full_loop_B.Product3_bd);

  // Fcn: '<S28>/fcn3' incorporates:
  //   Product: '<S45>/Product2'
  //   Product: '<S45>/Product3'

  full_loop_B.rtb_sincos_o1_idx_1 = (full_loop_B.Product2_h5 * full_loop_B.t27 -
    full_loop_B.rtb_sincos_o2_idx_1 * full_loop_B.t26) * -2.0;

  // If: '<S46>/If' incorporates:
  //   Constant: '<S47>/Constant'
  //   Constant: '<S48>/Constant'
  //   Inport: '<S49>/In'

  if (rtmIsMajorTimeStep(full_loop_M)) {
    if (full_loop_B.rtb_sincos_o1_idx_1 > 1.0) {
      full_loop_DW.If_ActiveSubsystem = 0;
    } else if (full_loop_B.rtb_sincos_o1_idx_1 < -1.0) {
      full_loop_DW.If_ActiveSubsystem = 1;
    } else {
      full_loop_DW.If_ActiveSubsystem = 2;
    }
  }

  switch (full_loop_DW.If_ActiveSubsystem) {
   case 0:
    // Outputs for IfAction SubSystem: '<S46>/If Action Subsystem' incorporates:
    //   ActionPort: '<S47>/Action Port'

    if (rtmIsMajorTimeStep(full_loop_M) &&
        full_loop_M->Timing.TaskCounters.TID[1] == 0) {
      full_loop_B.Merge = full_loop_P.Constant_Value_c;
    }

    // End of Outputs for SubSystem: '<S46>/If Action Subsystem'
    break;

   case 1:
    // Outputs for IfAction SubSystem: '<S46>/If Action Subsystem1' incorporates:
    //   ActionPort: '<S48>/Action Port'

    if (rtmIsMajorTimeStep(full_loop_M) &&
        full_loop_M->Timing.TaskCounters.TID[1] == 0) {
      full_loop_B.Merge = full_loop_P.Constant_Value_o;
    }

    // End of Outputs for SubSystem: '<S46>/If Action Subsystem1'
    break;

   case 2:
    // Outputs for IfAction SubSystem: '<S46>/If Action Subsystem2' incorporates:
    //   ActionPort: '<S49>/Action Port'

    full_loop_B.Merge = full_loop_B.rtb_sincos_o1_idx_1;

    // End of Outputs for SubSystem: '<S46>/If Action Subsystem2'
    break;
  }

  // End of If: '<S46>/If'

  // Trigonometry: '<S44>/trigFcn'
  if (full_loop_B.Merge > 1.0) {
    full_loop_B.Sum_d = 1.0;
  } else if (full_loop_B.Merge < -1.0) {
    full_loop_B.Sum_d = -1.0;
  } else {
    full_loop_B.Sum_d = full_loop_B.Merge;
  }

  full_loop_B.rtb_sincos_o1_idx_1 = asin(full_loop_B.Sum_d);

  // End of Trigonometry: '<S44>/trigFcn'

  // Trigonometry: '<S44>/Trigonometric Function3' incorporates:
  //   Fcn: '<S28>/fcn4'
  //   Fcn: '<S28>/fcn5'
  //   Product: '<S45>/Product2'
  //   Product: '<S45>/Product3'

  full_loop_B.rtb_sincos_o1_idx_2 = rt_atan2d_snf((full_loop_B.t26 *
    full_loop_B.t27 + full_loop_B.rtb_sincos_o2_idx_1 * full_loop_B.Product2_h5)
    * 2.0, ((full_loop_B.rtb_sincos_o1_idx_2 - full_loop_B.rtb_sincos_o2_idx_2)
            - full_loop_B.rtb_sincos_o2_idx_0) + full_loop_B.Product3_bd);

  // Gain: '<S62>/1//2'
  full_loop_B.rtb_sincos_o2_idx_0 = full_loop_P.u2_Gain_j *
    full_loop_B.rtb_sincos_o1_idx_2;
  full_loop_B.rtb_sincos_o2_idx_1 = full_loop_P.u2_Gain_j *
    full_loop_B.rtb_sincos_o1_idx_1;
  full_loop_B.rtb_sincos_o2_idx_2 = full_loop_P.u2_Gain_j *
    full_loop_B.rtb_sincos_o1_idx_0;

  // Trigonometry: '<S62>/sincos'
  full_loop_B.sincos_o2_b[0] = cos(full_loop_B.rtb_sincos_o2_idx_0);
  full_loop_B.rtb_sincos_o2_idx_0 = sin(full_loop_B.rtb_sincos_o2_idx_0);
  full_loop_B.sincos_o2_b[1] = cos(full_loop_B.rtb_sincos_o2_idx_1);
  full_loop_B.rtb_sincos_o2_idx_1 = sin(full_loop_B.rtb_sincos_o2_idx_1);
  full_loop_B.sincos_o2_b[2] = cos(full_loop_B.rtb_sincos_o2_idx_2);
  full_loop_B.Product2_h5 = sin(full_loop_B.rtb_sincos_o2_idx_2);

  // Fcn: '<S62>/q0' incorporates:
  //   Fcn: '<S62>/q3'

  full_loop_B.rtb_sincos_o2_idx_2 = full_loop_B.sincos_o2_b[0] *
    full_loop_B.sincos_o2_b[1];
  full_loop_B.Product3_bd = full_loop_B.rtb_sincos_o2_idx_0 *
    full_loop_B.rtb_sincos_o2_idx_1;
  full_loop_B.Sum_d = full_loop_B.rtb_sincos_o2_idx_2 * full_loop_B.sincos_o2_b
    [2] - full_loop_B.Product3_bd * full_loop_B.Product2_h5;

  // Fcn: '<S62>/q1' incorporates:
  //   Fcn: '<S62>/q2'

  full_loop_B.rtb_sincos_o2_idx_1 *= full_loop_B.sincos_o2_b[0];
  full_loop_B.Product8 = full_loop_B.rtb_sincos_o2_idx_0 *
    full_loop_B.sincos_o2_b[1];
  full_loop_B.rtb_sincos_o2_idx_0 = full_loop_B.rtb_sincos_o2_idx_1 *
    full_loop_B.Product2_h5 + full_loop_B.Product8 * full_loop_B.sincos_o2_b[2];

  // Fcn: '<S62>/q2'
  full_loop_B.rtb_sincos_o2_idx_1 = full_loop_B.rtb_sincos_o2_idx_1 *
    full_loop_B.sincos_o2_b[2] - full_loop_B.Product8 * full_loop_B.Product2_h5;

  // Fcn: '<S62>/q3'
  full_loop_B.Product2_h5 = full_loop_B.rtb_sincos_o2_idx_2 *
    full_loop_B.Product2_h5 + full_loop_B.Product3_bd * full_loop_B.sincos_o2_b
    [2];

  // Sum: '<S64>/Sum' incorporates:
  //   Product: '<S64>/Product'
  //   Product: '<S64>/Product1'
  //   Product: '<S64>/Product2'
  //   Product: '<S64>/Product3'

  full_loop_B.Product3_bd = ((full_loop_B.Sum_d * full_loop_B.Sum_d +
    full_loop_B.rtb_sincos_o2_idx_0 * full_loop_B.rtb_sincos_o2_idx_0) +
    full_loop_B.rtb_sincos_o2_idx_1 * full_loop_B.rtb_sincos_o2_idx_1) +
    full_loop_B.Product2_h5 * full_loop_B.Product2_h5;
  if (rtmIsMajorTimeStep(full_loop_M) &&
      full_loop_M->Timing.TaskCounters.TID[1] == 0) {
    // Memory: '<S59>/Memory'
    full_loop_B.Memory[0] = full_loop_DW.Memory_PreviousInput[0];
    full_loop_B.Memory[1] = full_loop_DW.Memory_PreviousInput[1];
    full_loop_B.Memory[2] = full_loop_DW.Memory_PreviousInput[2];
    full_loop_B.Memory[3] = full_loop_DW.Memory_PreviousInput[3];
  }

  // SignalConversion generated from: '<S60>/ SFunction ' incorporates:
  //   MATLAB Function: '<S59>/MATLAB Function'
  //   Product: '<S61>/Divide'
  //   Product: '<S61>/Divide1'
  //   Product: '<S61>/Divide2'
  //   Product: '<S61>/Divide3'
  //   UnaryMinus: '<S63>/Unary Minus'
  //   UnaryMinus: '<S63>/Unary Minus1'
  //   UnaryMinus: '<S63>/Unary Minus2'

  full_loop_B.q[0] = full_loop_B.Sum_d / full_loop_B.Product3_bd;
  full_loop_B.q[1] = -full_loop_B.rtb_sincos_o2_idx_0 / full_loop_B.Product3_bd;
  full_loop_B.q[2] = -full_loop_B.rtb_sincos_o2_idx_1 / full_loop_B.Product3_bd;
  full_loop_B.q[3] = -full_loop_B.Product2_h5 / full_loop_B.Product3_bd;

  // MATLAB Function: '<S59>/MATLAB Function'
  y = (((full_loop_B.Memory[0] * full_loop_B.q[0] + full_loop_B.Memory[1] *
         full_loop_B.q[1]) + full_loop_B.Memory[2] * full_loop_B.q[2]) +
       full_loop_B.Memory[3] * full_loop_B.q[3] < 0.0);
  if (y) {
    full_loop_B.q[0] = -full_loop_B.q[0];
  }

  // Sum: '<S17>/Sum1'
  full_loop_B.qS2W[0] = full_loop_B.q[0] + full_loop_B.Output;

  // MATLAB Function: '<S59>/MATLAB Function'
  if (y) {
    full_loop_B.q[1] = -full_loop_B.q[1];
  }

  // Sum: '<S17>/Sum1'
  full_loop_B.qS2W[1] = full_loop_B.q[1] + full_loop_B.Output;

  // MATLAB Function: '<S59>/MATLAB Function'
  if (y) {
    full_loop_B.q[2] = -full_loop_B.q[2];
  }

  // Sum: '<S17>/Sum1'
  full_loop_B.qS2W[2] = full_loop_B.q[2] + full_loop_B.Output;

  // MATLAB Function: '<S59>/MATLAB Function'
  if (y) {
    full_loop_B.q[3] = -full_loop_B.q[3];
  }

  // Sum: '<S17>/Sum1'
  full_loop_B.qS2W[3] = full_loop_B.q[3] + full_loop_B.Output;

  // Sum: '<S105>/Sum' incorporates:
  //   Product: '<S105>/Product'
  //   Product: '<S105>/Product1'
  //   Product: '<S105>/Product2'
  //   Product: '<S105>/Product3'

  full_loop_B.Sum_d = ((full_loop_B.qS2W[0] * full_loop_B.qS2W[0] +
                        full_loop_B.qS2W[1] * full_loop_B.qS2W[1]) +
                       full_loop_B.qS2W[2] * full_loop_B.qS2W[2]) +
    full_loop_B.qS2W[3] * full_loop_B.qS2W[3];

  // Product: '<S100>/Divide'
  full_loop_B.rtb_sincos_o2_idx_0 = full_loop_B.qS2W[0] / full_loop_B.Sum_d;

  // Product: '<S100>/Divide1' incorporates:
  //   UnaryMinus: '<S104>/Unary Minus'

  full_loop_B.rtb_sincos_o2_idx_1 = -full_loop_B.qS2W[1] / full_loop_B.Sum_d;

  // Product: '<S100>/Divide2' incorporates:
  //   UnaryMinus: '<S104>/Unary Minus1'

  full_loop_B.Product2_h5 = -full_loop_B.qS2W[2] / full_loop_B.Sum_d;

  // Product: '<S100>/Divide3' incorporates:
  //   UnaryMinus: '<S104>/Unary Minus2'

  full_loop_B.Product3_bd = -full_loop_B.qS2W[3] / full_loop_B.Sum_d;

  // Sqrt: '<S124>/sqrt' incorporates:
  //   Product: '<S125>/Product'
  //   Product: '<S125>/Product1'
  //   Product: '<S125>/Product2'
  //   Product: '<S125>/Product3'
  //   Sqrt: '<S133>/sqrt'
  //   Sqrt: '<S139>/sqrt'
  //   Sum: '<S125>/Sum'

  full_loop_B.rtb_sincos_o2_idx_2 = sqrt(((full_loop_B.rtb_sincos_o2_idx_0 *
    full_loop_B.rtb_sincos_o2_idx_0 + full_loop_B.rtb_sincos_o2_idx_1 *
    full_loop_B.rtb_sincos_o2_idx_1) + full_loop_B.Product2_h5 *
    full_loop_B.Product2_h5) + full_loop_B.Product3_bd * full_loop_B.Product3_bd);

  // Product: '<S119>/Product' incorporates:
  //   Product: '<S129>/Product'
  //   Product: '<S135>/Product'
  //   Sqrt: '<S124>/sqrt'

  full_loop_B.rtb_sincos_o2_idx_0 /= full_loop_B.rtb_sincos_o2_idx_2;

  // Product: '<S119>/Product1' incorporates:
  //   Product: '<S129>/Product1'
  //   Sqrt: '<S124>/sqrt'

  full_loop_B.rtb_sincos_o2_idx_1 /= full_loop_B.rtb_sincos_o2_idx_2;

  // Product: '<S119>/Product2' incorporates:
  //   Product: '<S129>/Product2'
  //   Product: '<S135>/Product2'
  //   Sqrt: '<S124>/sqrt'

  full_loop_B.Product2_h5 /= full_loop_B.rtb_sincos_o2_idx_2;

  // Product: '<S119>/Product3' incorporates:
  //   Product: '<S129>/Product3'
  //   Product: '<S135>/Product3'
  //   Sqrt: '<S124>/sqrt'

  full_loop_B.rtb_sincos_o2_idx_2 = full_loop_B.Product3_bd /
    full_loop_B.rtb_sincos_o2_idx_2;

  // Fcn: '<S103>/fcn2' incorporates:
  //   Fcn: '<S103>/fcn5'
  //   Product: '<S119>/Product'
  //   Product: '<S119>/Product1'
  //   Product: '<S119>/Product2'
  //   Product: '<S119>/Product3'
  //   Product: '<S137>/Product6'
  //   Product: '<S138>/Product6'

  full_loop_B.Product8 = full_loop_B.rtb_sincos_o2_idx_0 *
    full_loop_B.rtb_sincos_o2_idx_0;
  full_loop_B.Product3_bd = full_loop_B.rtb_sincos_o2_idx_1 *
    full_loop_B.rtb_sincos_o2_idx_1;
  full_loop_B.t17 = full_loop_B.Product2_h5 * full_loop_B.Product2_h5;
  full_loop_B.t42 = full_loop_B.rtb_sincos_o2_idx_2 *
    full_loop_B.rtb_sincos_o2_idx_2;

  // Trigonometry: '<S118>/Trigonometric Function1' incorporates:
  //   Fcn: '<S103>/fcn1'
  //   Fcn: '<S103>/fcn2'
  //   Product: '<S119>/Product'
  //   Product: '<S119>/Product1'
  //   Product: '<S119>/Product2'
  //   Product: '<S119>/Product3'

  full_loop_B.sincos_o2_b[0] = rt_atan2d_snf((full_loop_B.Product2_h5 *
    full_loop_B.rtb_sincos_o2_idx_2 - full_loop_B.rtb_sincos_o2_idx_0 *
    full_loop_B.rtb_sincos_o2_idx_1) * -2.0, ((full_loop_B.Product8 -
    full_loop_B.Product3_bd) - full_loop_B.t17) + full_loop_B.t42);

  // Fcn: '<S103>/fcn3' incorporates:
  //   Product: '<S119>/Product'
  //   Product: '<S119>/Product1'
  //   Product: '<S119>/Product2'
  //   Product: '<S119>/Product3'

  full_loop_B.Sum_d = (full_loop_B.rtb_sincos_o2_idx_1 *
                       full_loop_B.rtb_sincos_o2_idx_2 +
                       full_loop_B.rtb_sincos_o2_idx_0 * full_loop_B.Product2_h5)
    * 2.0;

  // If: '<S120>/If' incorporates:
  //   Constant: '<S121>/Constant'
  //   Constant: '<S122>/Constant'
  //   Inport: '<S123>/In'

  if (rtmIsMajorTimeStep(full_loop_M)) {
    if (full_loop_B.Sum_d > 1.0) {
      full_loop_DW.If_ActiveSubsystem_j = 0;
    } else if (full_loop_B.Sum_d < -1.0) {
      full_loop_DW.If_ActiveSubsystem_j = 1;
    } else {
      full_loop_DW.If_ActiveSubsystem_j = 2;
    }
  }

  switch (full_loop_DW.If_ActiveSubsystem_j) {
   case 0:
    // Outputs for IfAction SubSystem: '<S120>/If Action Subsystem' incorporates:
    //   ActionPort: '<S121>/Action Port'

    if (rtmIsMajorTimeStep(full_loop_M) &&
        full_loop_M->Timing.TaskCounters.TID[1] == 0) {
      full_loop_B.Merge_b = full_loop_P.Constant_Value_m;
    }

    // End of Outputs for SubSystem: '<S120>/If Action Subsystem'
    break;

   case 1:
    // Outputs for IfAction SubSystem: '<S120>/If Action Subsystem1' incorporates:
    //   ActionPort: '<S122>/Action Port'

    if (rtmIsMajorTimeStep(full_loop_M) &&
        full_loop_M->Timing.TaskCounters.TID[1] == 0) {
      full_loop_B.Merge_b = full_loop_P.Constant_Value_j;
    }

    // End of Outputs for SubSystem: '<S120>/If Action Subsystem1'
    break;

   case 2:
    // Outputs for IfAction SubSystem: '<S120>/If Action Subsystem2' incorporates:
    //   ActionPort: '<S123>/Action Port'

    full_loop_B.Merge_b = full_loop_B.Sum_d;

    // End of Outputs for SubSystem: '<S120>/If Action Subsystem2'
    break;
  }

  // End of If: '<S120>/If'

  // Trigonometry: '<S118>/trigFcn'
  if (full_loop_B.Merge_b > 1.0) {
    full_loop_B.Sum_d = 1.0;
  } else if (full_loop_B.Merge_b < -1.0) {
    full_loop_B.Sum_d = -1.0;
  } else {
    full_loop_B.Sum_d = full_loop_B.Merge_b;
  }

  full_loop_B.sincos_o2_b[1] = asin(full_loop_B.Sum_d);

  // Fcn: '<S103>/fcn4' incorporates:
  //   Product: '<S119>/Product'
  //   Product: '<S119>/Product1'
  //   Product: '<S119>/Product2'
  //   Product: '<S119>/Product3'

  full_loop_B.Product2_fy = (full_loop_B.rtb_sincos_o2_idx_1 *
    full_loop_B.Product2_h5 - full_loop_B.rtb_sincos_o2_idx_0 *
    full_loop_B.rtb_sincos_o2_idx_2) * -2.0;

  // Fcn: '<S103>/fcn5'
  full_loop_B.Product8 = ((full_loop_B.Product8 + full_loop_B.Product3_bd) -
    full_loop_B.t17) - full_loop_B.t42;

  // Trigonometry: '<S118>/Trigonometric Function3'
  full_loop_B.sincos_o2_b[2] = rt_atan2d_snf(full_loop_B.Product2_fy,
    full_loop_B.Product8);
  if (rtmIsMajorTimeStep(full_loop_M) &&
      full_loop_M->Timing.TaskCounters.TID[2] == 0) {
    // Gain: '<S66>/Output' incorporates:
    //   RandomNumber: '<S66>/White Noise'

    full_loop_B.Output_j = sqrt(full_loop_P.BandLimitedWhiteNoise1_Cov) / 0.1 *
      full_loop_DW.NextOutput_b;
  }

  if (rtmIsMajorTimeStep(full_loop_M) &&
      full_loop_M->Timing.TaskCounters.TID[1] == 0) {
    // Memory: '<S4>/Memory5'
    full_loop_B.Memory5[0] = full_loop_DW.Memory5_PreviousInput[0];
    full_loop_B.Memory5[1] = full_loop_DW.Memory5_PreviousInput[1];
    full_loop_B.Memory5[2] = full_loop_DW.Memory5_PreviousInput[2];

    // Memory: '<S4>/Memory3'
    memcpy(&full_loop_B.Memory3[0], &full_loop_DW.Memory3_PreviousInput[0], 12U *
           sizeof(real_T));
  }

  if (rtmIsMajorTimeStep(full_loop_M) &&
      full_loop_M->Timing.TaskCounters.TID[4] == 0) {
    // SignalConversion generated from: '<S69>/ SFunction ' incorporates:
    //   Integrator: '<S13>/p,q,r '
    //   MATLAB Function: '<S4>/check'
    //   Sum: '<S17>/Sum2'

    full_loop_B.TmpSignalConversionAtSFunct[0] = full_loop_B.BodyPosition[0];
    full_loop_B.TmpSignalConversionAtSFunct[3] = full_loop_B.sincos_o2_b[0];
    full_loop_B.TmpSignalConversionAtSFunct[6] = full_loop_B.ubvbwb[0];
    full_loop_B.TmpSignalConversionAtSFunct[9] = full_loop_X.pqr_CSTATE[0] +
      full_loop_B.Output_j;

    // MATLAB Function: '<S4>/check'
    full_loop_B.tcount[0] = full_loop_B.Memory5[0];

    // SignalConversion generated from: '<S69>/ SFunction ' incorporates:
    //   MATLAB Function: '<S4>/check'

    full_loop_B.TmpSignalConversionAtSFunct[1] = full_loop_B.BodyPosition[1];

    // Trigonometry: '<S118>/trigFcn'
    if (full_loop_B.Merge_b > 1.0) {
      full_loop_B.Sum_d = 1.0;
    } else if (full_loop_B.Merge_b < -1.0) {
      full_loop_B.Sum_d = -1.0;
    } else {
      full_loop_B.Sum_d = full_loop_B.Merge_b;
    }

    // SignalConversion generated from: '<S69>/ SFunction ' incorporates:
    //   Integrator: '<S13>/p,q,r '
    //   MATLAB Function: '<S4>/check'
    //   Sum: '<S17>/Sum2'
    //   Trigonometry: '<S118>/trigFcn'

    full_loop_B.TmpSignalConversionAtSFunct[4] = asin(full_loop_B.Sum_d);
    full_loop_B.TmpSignalConversionAtSFunct[7] = full_loop_B.ubvbwb[1];
    full_loop_B.TmpSignalConversionAtSFunct[10] = full_loop_X.pqr_CSTATE[1] +
      full_loop_B.Output_j;

    // MATLAB Function: '<S4>/check'
    full_loop_B.tcount[1] = full_loop_B.Memory5[1];

    // SignalConversion generated from: '<S69>/ SFunction ' incorporates:
    //   Integrator: '<S13>/p,q,r '
    //   MATLAB Function: '<S4>/check'
    //   Sum: '<S17>/Sum2'
    //   Trigonometry: '<S118>/Trigonometric Function3'

    full_loop_B.TmpSignalConversionAtSFunct[2] = full_loop_B.BodyPosition[2];
    full_loop_B.TmpSignalConversionAtSFunct[5] = rt_atan2d_snf
      (full_loop_B.Product2_fy, full_loop_B.Product8);
    full_loop_B.TmpSignalConversionAtSFunct[8] = full_loop_B.ubvbwb[2];
    full_loop_B.TmpSignalConversionAtSFunct[11] = full_loop_X.pqr_CSTATE[2] +
      full_loop_B.Output_j;

    // MATLAB Function: '<S4>/check' incorporates:
    //   SignalConversion generated from: '<S69>/ SFunction '

    full_loop_B.tcount[2] = full_loop_B.Memory5[2];
    memcpy(&full_loop_B.checkedPose[0],
           &full_loop_B.TmpSignalConversionAtSFunct[0], 12U * sizeof(real_T));
    if (full_loop_B.tcount[0] > 0.0) {
      full_loop_B.checkedPose[3] = (full_loop_B.sincos_o2_b[0] +
        3.1415926535897931) + 3.1415926535897931 * full_loop_B.tcount[0];
    } else {
      y = true;
      full_loop_B.b_jAcol = 0;
      exitg1 = false;
      while ((!exitg1) && (full_loop_B.b_jAcol < 3)) {
        if (!(full_loop_B.tcount[full_loop_B.b_jAcol] < 0.0)) {
          y = false;
          exitg1 = true;
        } else {
          full_loop_B.b_jAcol++;
        }
      }

      if (y) {
        full_loop_B.checkedPose[3] = (full_loop_B.sincos_o2_b[0] -
          3.1415926535897931) + 3.1415926535897931 * full_loop_B.tcount[0];
      }
    }

    full_loop_B.Sum_d = full_loop_B.Memory3[3] - full_loop_B.checkedPose[3];
    if (fabs(full_loop_B.Sum_d) >= 3.1415926535897931) {
      if (full_loop_B.Sum_d > 0.0) {
        full_loop_B.tcount[0]++;
        full_loop_B.checkedPose[3] = (full_loop_B.sincos_o2_b[0] +
          3.1415926535897931) + 3.1415926535897931 * full_loop_B.tcount[0];
      } else {
        full_loop_B.tcount[0]--;
        full_loop_B.checkedPose[3] = (full_loop_B.sincos_o2_b[0] -
          3.1415926535897931) + 3.1415926535897931 * full_loop_B.tcount[0];
      }
    }

    if (full_loop_B.tcount[1] > 0.0) {
      full_loop_B.checkedPose[4] = (full_loop_B.sincos_o2_b[1] +
        3.1415926535897931) + 3.1415926535897931 * full_loop_B.tcount[1];
    } else {
      y = true;
      full_loop_B.b_jAcol = 0;
      exitg1 = false;
      while ((!exitg1) && (full_loop_B.b_jAcol < 3)) {
        if (!(full_loop_B.tcount[full_loop_B.b_jAcol] < 0.0)) {
          y = false;
          exitg1 = true;
        } else {
          full_loop_B.b_jAcol++;
        }
      }

      if (y) {
        full_loop_B.checkedPose[4] = (full_loop_B.sincos_o2_b[1] -
          3.1415926535897931) + 3.1415926535897931 * full_loop_B.tcount[1];
      }
    }

    full_loop_B.Sum_d = full_loop_B.Memory3[4] - full_loop_B.checkedPose[4];
    if (fabs(full_loop_B.Sum_d) >= 3.1415926535897931) {
      if (full_loop_B.Sum_d > 0.0) {
        full_loop_B.tcount[1]++;
        full_loop_B.checkedPose[4] = (full_loop_B.sincos_o2_b[1] +
          3.1415926535897931) + 3.1415926535897931 * full_loop_B.tcount[1];
      } else {
        full_loop_B.tcount[1]--;
        full_loop_B.checkedPose[4] = (full_loop_B.sincos_o2_b[1] -
          3.1415926535897931) + 3.1415926535897931 * full_loop_B.tcount[1];
      }
    }

    if (full_loop_B.tcount[2] > 0.0) {
      full_loop_B.checkedPose[5] = (full_loop_B.sincos_o2_b[2] +
        3.1415926535897931) + 3.1415926535897931 * full_loop_B.tcount[2];
    } else {
      y = true;
      full_loop_B.b_jAcol = 0;
      exitg1 = false;
      while ((!exitg1) && (full_loop_B.b_jAcol < 3)) {
        if (!(full_loop_B.tcount[full_loop_B.b_jAcol] < 0.0)) {
          y = false;
          exitg1 = true;
        } else {
          full_loop_B.b_jAcol++;
        }
      }

      if (y) {
        full_loop_B.checkedPose[5] = (full_loop_B.sincos_o2_b[2] -
          3.1415926535897931) + 3.1415926535897931 * full_loop_B.tcount[2];
      }
    }

    full_loop_B.Sum_d = full_loop_B.Memory3[5] - full_loop_B.checkedPose[5];
    if (fabs(full_loop_B.Sum_d) >= 3.1415926535897931) {
      if (full_loop_B.Sum_d > 0.0) {
        full_loop_B.tcount[2]++;
        full_loop_B.checkedPose[5] = (full_loop_B.sincos_o2_b[2] +
          3.1415926535897931) + 3.1415926535897931 * full_loop_B.tcount[2];
      } else {
        full_loop_B.tcount[2]--;
        full_loop_B.checkedPose[5] = (full_loop_B.sincos_o2_b[2] -
          3.1415926535897931) + 3.1415926535897931 * full_loop_B.tcount[2];
      }
    }

    // FromWorkspace: '<S6>/From Workspace1'
    {
      real_T t = ((full_loop_M->Timing.clockTick4) * 0.1);
      real_T *pTimeValues = static_cast<real_T *>
        (full_loop_DW.FromWorkspace1_PWORK.TimePtr);
      real_T *pDataValues = static_cast<real_T *>
        (full_loop_DW.FromWorkspace1_PWORK.DataPtr);
      if (t < pTimeValues[0]) {
        {
          int_T elIdx;
          for (elIdx = 0; elIdx < 12; ++elIdx) {
            (&full_loop_B.FromWorkspace1[0])[elIdx] = 0.0;
          }
        }
      } else if (t >= pTimeValues[2300]) {
        {
          int_T elIdx;
          for (elIdx = 0; elIdx < 12; ++elIdx) {
            (&full_loop_B.FromWorkspace1[0])[elIdx] = pDataValues[2300];
            pDataValues += 2301;
          }
        }
      } else {
        int_T currTimeIndex = full_loop_DW.FromWorkspace1_IWORK.PrevIndex;
        if (t < pTimeValues[currTimeIndex]) {
          while (t < pTimeValues[currTimeIndex]) {
            currTimeIndex--;
          }
        } else {
          while (t >= pTimeValues[currTimeIndex + 1]) {
            currTimeIndex++;
          }
        }

        {
          int_T elIdx;
          for (elIdx = 0; elIdx < 12; ++elIdx) {
            (&full_loop_B.FromWorkspace1[0])[elIdx] = pDataValues[currTimeIndex];
            pDataValues += 2301;
          }
        }

        full_loop_DW.FromWorkspace1_IWORK.PrevIndex = currTimeIndex;
      }
    }
  }

  // Gain: '<S5>/Gain'
  full_loop_B.qS2W[0] *= full_loop_P.Gain_Gain;
  full_loop_B.qS2W[1] *= full_loop_P.Gain_Gain;
  full_loop_B.qS2W[2] *= full_loop_P.Gain_Gain;
  full_loop_B.Sum_d = full_loop_P.Gain_Gain * full_loop_B.qS2W[3];

  // Sqrt: '<S110>/sqrt' incorporates:
  //   Product: '<S111>/Product'
  //   Product: '<S111>/Product1'
  //   Product: '<S111>/Product2'
  //   Product: '<S111>/Product3'
  //   Sum: '<S111>/Sum'

  full_loop_B.Product2_fy = sqrt(((full_loop_B.qS2W[0] * full_loop_B.qS2W[0] +
    full_loop_B.qS2W[1] * full_loop_B.qS2W[1]) + full_loop_B.qS2W[2] *
    full_loop_B.qS2W[2]) + full_loop_B.Sum_d * full_loop_B.Sum_d);

  // Product: '<S106>/Product2'
  full_loop_B.Product8 = full_loop_B.qS2W[2] / full_loop_B.Product2_fy;

  // Product: '<S106>/Product3'
  full_loop_B.ixk = full_loop_B.Sum_d / full_loop_B.Product2_fy;

  // Product: '<S106>/Product1'
  full_loop_B.Sum_d = full_loop_B.qS2W[1] / full_loop_B.Product2_fy;

  // Product: '<S106>/Product'
  full_loop_B.Product2_fy = full_loop_B.qS2W[0] / full_loop_B.Product2_fy;

  // Product: '<S107>/Product7' incorporates:
  //   Product: '<S108>/Product7'

  full_loop_B.t19 = full_loop_B.ixk * full_loop_B.ixk;

  // Product: '<S107>/Product' incorporates:
  //   Product: '<S108>/Product'

  full_loop_B.t20 = full_loop_B.Sum_d * full_loop_B.Product8;

  // Product: '<S107>/Product1' incorporates:
  //   Product: '<S108>/Product1'

  full_loop_B.t21 = full_loop_B.Product2_fy * full_loop_B.ixk;

  // Product: '<S107>/Product3' incorporates:
  //   Product: '<S109>/Product'

  full_loop_B.t17 = full_loop_B.Sum_d * full_loop_B.ixk;

  // Product: '<S107>/Product2' incorporates:
  //   Product: '<S109>/Product1'

  full_loop_B.t42 = full_loop_B.Product2_fy * full_loop_B.Product8;

  // Product: '<S107>/Product6' incorporates:
  //   Product: '<S109>/Product7'

  full_loop_B.t18 = full_loop_B.Product8 * full_loop_B.Product8;

  // Sum: '<S107>/Sum' incorporates:
  //   Constant: '<S107>/Constant'
  //   Gain: '<S107>/Gain'
  //   Gain: '<S107>/Gain1'
  //   Gain: '<S107>/Gain2'
  //   Product: '<S107>/Product'
  //   Product: '<S107>/Product1'
  //   Product: '<S107>/Product2'
  //   Product: '<S107>/Product3'
  //   Product: '<S107>/Product4'
  //   Product: '<S107>/Product5'
  //   Product: '<S107>/Product6'
  //   Product: '<S107>/Product7'
  //   Product: '<S107>/Product8'
  //   Sum: '<S107>/Sum1'
  //   Sum: '<S107>/Sum2'
  //   Sum: '<S107>/Sum3'

  full_loop_B.Sum = (((full_loop_P.Constant_Value_e - full_loop_B.t18) -
                      full_loop_B.t19) * full_loop_P.Gain2_Gain *
                     full_loop_B.ubvbwb[0] + (full_loop_B.t20 + full_loop_B.t21)
                     * full_loop_P.Gain_Gain_c * full_loop_B.ubvbwb[1]) +
    (full_loop_B.t17 - full_loop_B.t42) * full_loop_P.Gain1_Gain *
    full_loop_B.ubvbwb[2];

  // Product: '<S108>/Product3' incorporates:
  //   Product: '<S109>/Product3'

  full_loop_B.Product8 *= full_loop_B.ixk;

  // Product: '<S108>/Product2' incorporates:
  //   Product: '<S109>/Product2'

  full_loop_B.Product2_fy *= full_loop_B.Sum_d;

  // Product: '<S108>/Product6' incorporates:
  //   Product: '<S109>/Product6'

  full_loop_B.Sum_d *= full_loop_B.Sum_d;

  // Sum: '<S108>/Sum' incorporates:
  //   Constant: '<S108>/Constant'
  //   Gain: '<S108>/Gain'
  //   Gain: '<S108>/Gain1'
  //   Gain: '<S108>/Gain2'
  //   Product: '<S108>/Product2'
  //   Product: '<S108>/Product3'
  //   Product: '<S108>/Product4'
  //   Product: '<S108>/Product5'
  //   Product: '<S108>/Product6'
  //   Product: '<S108>/Product8'
  //   Sum: '<S108>/Sum1'
  //   Sum: '<S108>/Sum2'
  //   Sum: '<S108>/Sum3'

  full_loop_B.Sum_g = (((full_loop_P.Constant_Value_or - full_loop_B.Sum_d) -
                        full_loop_B.t19) * full_loop_P.Gain2_Gain_f *
                       full_loop_B.ubvbwb[1] + (full_loop_B.t20 -
    full_loop_B.t21) * full_loop_P.Gain_Gain_ca * full_loop_B.ubvbwb[0]) +
    (full_loop_B.Product2_fy + full_loop_B.Product8) * full_loop_P.Gain1_Gain_c *
    full_loop_B.ubvbwb[2];

  // Sum: '<S109>/Sum' incorporates:
  //   Constant: '<S109>/Constant'
  //   Gain: '<S109>/Gain'
  //   Gain: '<S109>/Gain1'
  //   Gain: '<S109>/Gain2'
  //   Product: '<S109>/Product4'
  //   Product: '<S109>/Product5'
  //   Product: '<S109>/Product8'
  //   Sum: '<S109>/Sum1'
  //   Sum: '<S109>/Sum2'
  //   Sum: '<S109>/Sum3'

  full_loop_B.Sum_e = ((full_loop_B.t17 + full_loop_B.t42) *
                       full_loop_P.Gain_Gain_n * full_loop_B.ubvbwb[0] +
                       (full_loop_B.Product8 - full_loop_B.Product2_fy) *
                       full_loop_P.Gain1_Gain_d * full_loop_B.ubvbwb[1]) +
    ((full_loop_P.Constant_Value_a - full_loop_B.Sum_d) - full_loop_B.t18) *
    full_loop_P.Gain2_Gain_g * full_loop_B.ubvbwb[2];
  if (rtmIsMajorTimeStep(full_loop_M) &&
      full_loop_M->Timing.TaskCounters.TID[1] == 0) {
    // DiscreteIntegrator: '<S5>/Discrete-Time Integrator'
    full_loop_B.WorldPosition[0] = full_loop_P.DiscreteTimeIntegrator_gainval *
      full_loop_B.Sum + full_loop_DW.DiscreteTimeIntegrator_DSTATE[0];
    full_loop_B.WorldPosition[1] = full_loop_P.DiscreteTimeIntegrator_gainval *
      full_loop_B.Sum_g + full_loop_DW.DiscreteTimeIntegrator_DSTATE[1];
    full_loop_B.WorldPosition[2] = full_loop_P.DiscreteTimeIntegrator_gainval *
      full_loop_B.Sum_e + full_loop_DW.DiscreteTimeIntegrator_DSTATE[2];

    // Sum: '<S6>/Sum'
    full_loop_B.Sum_a[0] = full_loop_B.FromWorkspace1[0] -
      full_loop_B.WorldPosition[0];
    full_loop_B.Sum_a[1] = full_loop_B.FromWorkspace1[1] -
      full_loop_B.WorldPosition[1];
    full_loop_B.Sum_a[2] = full_loop_B.FromWorkspace1[2] -
      full_loop_B.WorldPosition[2];

    // Memory: '<S6>/Memory'
    full_loop_B.Memory_e[0] = full_loop_DW.Memory_PreviousInput_p[0];
    full_loop_B.Memory_e[1] = full_loop_DW.Memory_PreviousInput_p[1];
    full_loop_B.Memory_e[2] = full_loop_DW.Memory_PreviousInput_p[2];
  }

  if (rtmIsMajorTimeStep(full_loop_M) &&
      full_loop_M->Timing.TaskCounters.TID[4] == 0) {
    // MATLAB Function: '<S6>/MATLAB Function'
    full_loop_B.y[0] = full_loop_B.FromWorkspace1[3];
    full_loop_B.y[1] = full_loop_B.FromWorkspace1[4];
    full_loop_B.y[2] = full_loop_B.FromWorkspace1[5];
    if (fabs(full_loop_B.Memory_e[2] - full_loop_B.FromWorkspace1[5]) >
        3.1415926535897931) {
      full_loop_B.y[2] = (full_loop_B.FromWorkspace1[5] + 3.1415926535897931) +
        3.1415926535897931;
    }

    // End of MATLAB Function: '<S6>/MATLAB Function'
  }

  // Product: '<S130>/Product7' incorporates:
  //   Product: '<S131>/Product7'

  full_loop_B.Sum_d = full_loop_B.rtb_sincos_o2_idx_2 *
    full_loop_B.rtb_sincos_o2_idx_2;

  // Product: '<S130>/Product' incorporates:
  //   Product: '<S131>/Product'

  full_loop_B.Product8 = full_loop_B.rtb_sincos_o2_idx_1 *
    full_loop_B.Product2_h5;

  // Product: '<S130>/Product1' incorporates:
  //   Product: '<S131>/Product1'

  full_loop_B.Product2_fy = full_loop_B.rtb_sincos_o2_idx_0 *
    full_loop_B.rtb_sincos_o2_idx_2;

  // Product: '<S130>/Product3' incorporates:
  //   Product: '<S132>/Product'

  full_loop_B.t17 = full_loop_B.rtb_sincos_o2_idx_1 *
    full_loop_B.rtb_sincos_o2_idx_2;

  // Product: '<S130>/Product2' incorporates:
  //   Product: '<S132>/Product1'

  full_loop_B.t42 = full_loop_B.rtb_sincos_o2_idx_0 * full_loop_B.Product2_h5;

  // Product: '<S130>/Product6' incorporates:
  //   Product: '<S132>/Product7'

  full_loop_B.t18 = full_loop_B.Product2_h5 * full_loop_B.Product2_h5;

  // DataTypeConversion: '<S70>/Data Type Conversion1' incorporates:
  //   Constant: '<S130>/Constant'
  //   Gain: '<S130>/Gain'
  //   Gain: '<S130>/Gain1'
  //   Gain: '<S130>/Gain2'
  //   Product: '<S130>/Product'
  //   Product: '<S130>/Product1'
  //   Product: '<S130>/Product2'
  //   Product: '<S130>/Product3'
  //   Product: '<S130>/Product4'
  //   Product: '<S130>/Product5'
  //   Product: '<S130>/Product6'
  //   Product: '<S130>/Product7'
  //   Product: '<S130>/Product8'
  //   Sum: '<S130>/Sum'
  //   Sum: '<S130>/Sum1'
  //   Sum: '<S130>/Sum2'
  //   Sum: '<S130>/Sum3'

  full_loop_B.DataTypeConversion1[6] = (((full_loop_P.Constant_Value_j4 -
    full_loop_B.t18) - full_loop_B.Sum_d) * full_loop_P.Gain2_Gain_mb *
    full_loop_B.FromWorkspace1[6] + (full_loop_B.Product8 +
    full_loop_B.Product2_fy) * full_loop_P.Gain_Gain_ha *
    full_loop_B.FromWorkspace1[7]) + (full_loop_B.t17 - full_loop_B.t42) *
    full_loop_P.Gain1_Gain_ln * full_loop_B.FromWorkspace1[8];

  // Product: '<S131>/Product3' incorporates:
  //   Product: '<S132>/Product3'

  full_loop_B.t19 = full_loop_B.Product2_h5 * full_loop_B.rtb_sincos_o2_idx_2;

  // Product: '<S131>/Product2' incorporates:
  //   Product: '<S132>/Product2'

  full_loop_B.t20 = full_loop_B.rtb_sincos_o2_idx_0 *
    full_loop_B.rtb_sincos_o2_idx_1;

  // Product: '<S131>/Product6' incorporates:
  //   Product: '<S132>/Product6'

  full_loop_B.t21 = full_loop_B.rtb_sincos_o2_idx_1 *
    full_loop_B.rtb_sincos_o2_idx_1;

  // DataTypeConversion: '<S70>/Data Type Conversion1' incorporates:
  //   Constant: '<S131>/Constant'
  //   Constant: '<S132>/Constant'
  //   Gain: '<S131>/Gain'
  //   Gain: '<S131>/Gain1'
  //   Gain: '<S131>/Gain2'
  //   Gain: '<S132>/Gain'
  //   Gain: '<S132>/Gain1'
  //   Gain: '<S132>/Gain2'
  //   Product: '<S131>/Product2'
  //   Product: '<S131>/Product3'
  //   Product: '<S131>/Product4'
  //   Product: '<S131>/Product5'
  //   Product: '<S131>/Product6'
  //   Product: '<S131>/Product8'
  //   Product: '<S132>/Product4'
  //   Product: '<S132>/Product5'
  //   Product: '<S132>/Product8'
  //   Sum: '<S131>/Sum'
  //   Sum: '<S131>/Sum1'
  //   Sum: '<S131>/Sum2'
  //   Sum: '<S131>/Sum3'
  //   Sum: '<S132>/Sum'
  //   Sum: '<S132>/Sum1'
  //   Sum: '<S132>/Sum2'
  //   Sum: '<S132>/Sum3'

  full_loop_B.DataTypeConversion1[7] = (((full_loop_P.Constant_Value_g -
    full_loop_B.t21) - full_loop_B.Sum_d) * full_loop_P.Gain2_Gain_fi *
    full_loop_B.FromWorkspace1[7] + (full_loop_B.Product8 -
    full_loop_B.Product2_fy) * full_loop_P.Gain_Gain_k *
    full_loop_B.FromWorkspace1[6]) + (full_loop_B.t20 + full_loop_B.t19) *
    full_loop_P.Gain1_Gain_j * full_loop_B.FromWorkspace1[8];
  full_loop_B.DataTypeConversion1[8] = ((full_loop_B.t17 + full_loop_B.t42) *
    full_loop_P.Gain_Gain_nw * full_loop_B.FromWorkspace1[6] + (full_loop_B.t19
    - full_loop_B.t20) * full_loop_P.Gain1_Gain_o * full_loop_B.FromWorkspace1[7])
    + ((full_loop_P.Constant_Value_ov - full_loop_B.t21) - full_loop_B.t18) *
    full_loop_P.Gain2_Gain_o * full_loop_B.FromWorkspace1[8];

  // Product: '<S136>/Product7' incorporates:
  //   Product: '<S137>/Product7'

  full_loop_B.Sum_d = full_loop_B.rtb_sincos_o2_idx_2 *
    full_loop_B.rtb_sincos_o2_idx_2;

  // Product: '<S136>/Product' incorporates:
  //   Product: '<S119>/Product1'
  //   Product: '<S137>/Product'

  full_loop_B.Product8 = full_loop_B.rtb_sincos_o2_idx_1 *
    full_loop_B.Product2_h5;

  // Product: '<S136>/Product1' incorporates:
  //   Product: '<S137>/Product1'

  full_loop_B.Product2_fy = full_loop_B.rtb_sincos_o2_idx_0 *
    full_loop_B.rtb_sincos_o2_idx_2;

  // Product: '<S136>/Product3' incorporates:
  //   Product: '<S119>/Product1'
  //   Product: '<S138>/Product'

  full_loop_B.t17 = full_loop_B.rtb_sincos_o2_idx_1 *
    full_loop_B.rtb_sincos_o2_idx_2;

  // Product: '<S136>/Product2' incorporates:
  //   Product: '<S138>/Product1'

  full_loop_B.t42 = full_loop_B.rtb_sincos_o2_idx_0 * full_loop_B.Product2_h5;

  // Product: '<S136>/Product6' incorporates:
  //   Product: '<S138>/Product7'

  full_loop_B.t18 = full_loop_B.Product2_h5 * full_loop_B.Product2_h5;

  // DataTypeConversion: '<S70>/Data Type Conversion1' incorporates:
  //   Constant: '<S136>/Constant'
  //   Gain: '<S136>/Gain'
  //   Gain: '<S136>/Gain1'
  //   Gain: '<S136>/Gain2'
  //   Product: '<S136>/Product'
  //   Product: '<S136>/Product1'
  //   Product: '<S136>/Product2'
  //   Product: '<S136>/Product3'
  //   Product: '<S136>/Product4'
  //   Product: '<S136>/Product5'
  //   Product: '<S136>/Product6'
  //   Product: '<S136>/Product7'
  //   Product: '<S136>/Product8'
  //   Sum: '<S136>/Sum'
  //   Sum: '<S136>/Sum1'
  //   Sum: '<S136>/Sum2'
  //   Sum: '<S136>/Sum3'
  //   Sum: '<S6>/Sum1'

  full_loop_B.DataTypeConversion1[0] = ((((full_loop_P.Constant_Value_p -
    full_loop_B.t18) - full_loop_B.Sum_d) * full_loop_P.Gain2_Gain_i *
    full_loop_B.Sum_a[0] + (full_loop_B.Product8 + full_loop_B.Product2_fy) *
    full_loop_P.Gain_Gain_m * full_loop_B.Sum_a[1]) + (full_loop_B.t17 -
    full_loop_B.t42) * full_loop_P.Gain1_Gain_l * full_loop_B.Sum_a[2]) +
    full_loop_B.BodyPosition[0];
  full_loop_B.DataTypeConversion1[3] = full_loop_B.y[0];
  full_loop_B.DataTypeConversion1[9] = full_loop_B.FromWorkspace1[9];

  // Product: '<S137>/Product3' incorporates:
  //   Product: '<S138>/Product3'

  full_loop_B.t19 = full_loop_B.Product2_h5 * full_loop_B.rtb_sincos_o2_idx_2;

  // Product: '<S137>/Product2' incorporates:
  //   Product: '<S119>/Product1'
  //   Product: '<S138>/Product2'

  full_loop_B.t20 = full_loop_B.rtb_sincos_o2_idx_0 *
    full_loop_B.rtb_sincos_o2_idx_1;

  // DataTypeConversion: '<S70>/Data Type Conversion1' incorporates:
  //   Constant: '<S137>/Constant'
  //   Constant: '<S138>/Constant'
  //   Gain: '<S137>/Gain'
  //   Gain: '<S137>/Gain1'
  //   Gain: '<S137>/Gain2'
  //   Gain: '<S138>/Gain'
  //   Gain: '<S138>/Gain1'
  //   Gain: '<S138>/Gain2'
  //   Product: '<S137>/Product2'
  //   Product: '<S137>/Product3'
  //   Product: '<S137>/Product4'
  //   Product: '<S137>/Product5'
  //   Product: '<S137>/Product8'
  //   Product: '<S138>/Product4'
  //   Product: '<S138>/Product5'
  //   Product: '<S138>/Product8'
  //   Sum: '<S137>/Sum'
  //   Sum: '<S137>/Sum1'
  //   Sum: '<S137>/Sum2'
  //   Sum: '<S137>/Sum3'
  //   Sum: '<S138>/Sum'
  //   Sum: '<S138>/Sum1'
  //   Sum: '<S138>/Sum2'
  //   Sum: '<S138>/Sum3'
  //   Sum: '<S6>/Sum1'

  full_loop_B.DataTypeConversion1[1] = ((((full_loop_P.Constant_Value_l -
    full_loop_B.Product3_bd) - full_loop_B.Sum_d) * full_loop_P.Gain2_Gain_m *
    full_loop_B.Sum_a[1] + (full_loop_B.Product8 - full_loop_B.Product2_fy) *
    full_loop_P.Gain_Gain_cd * full_loop_B.Sum_a[0]) + (full_loop_B.t20 +
    full_loop_B.t19) * full_loop_P.Gain1_Gain_h * full_loop_B.Sum_a[2]) +
    full_loop_B.BodyPosition[1];
  full_loop_B.DataTypeConversion1[4] = full_loop_B.y[1];
  full_loop_B.DataTypeConversion1[10] = full_loop_B.FromWorkspace1[10];
  full_loop_B.DataTypeConversion1[2] = (((full_loop_B.t17 + full_loop_B.t42) *
    full_loop_P.Gain_Gain_h * full_loop_B.Sum_a[0] + (full_loop_B.t19 -
    full_loop_B.t20) * full_loop_P.Gain1_Gain_i * full_loop_B.Sum_a[1]) +
    ((full_loop_P.Constant_Value_k - full_loop_B.Product3_bd) - full_loop_B.t18)
    * full_loop_P.Gain2_Gain_b * full_loop_B.Sum_a[2]) +
    full_loop_B.BodyPosition[2];
  full_loop_B.DataTypeConversion1[5] = full_loop_B.y[2];
  full_loop_B.DataTypeConversion1[11] = full_loop_B.FromWorkspace1[11];
  if (rtmIsMajorTimeStep(full_loop_M) &&
      full_loop_M->Timing.TaskCounters.TID[4] == 0) {
    // MATLABSystem: '<S4>/MATLAB System' incorporates:
    //   Constant: '<S4>/Constant'
    //   Constant: '<S4>/Constant2'

    // tic;
    memcpy(&full_loop_DW.obj_c.uMin[0], &full_loop_P.TMIN[0], sizeof(real_T) <<
           3U);
    memcpy(&full_loop_DW.obj_c.uMax[0], &full_loop_P.TMAX[0], sizeof(real_T) <<
           3U);

    //  Fonction objective.
    tunableEnvironment = &full_loop_DW.obj_c;

    //  Retrouver la matrice gravité
    full_loop_Gravity(full_loop_B.checkedPose, full_loop_DW.obj_c.Beq);

    //  Parametre du solveur fmincon
    //  Optimiser la commande pour la condition initial
    memcpy(&full_loop_B.dv17[0], &full_loop_DW.obj_c.u0[0], sizeof(real_T) << 3);
    memcpy(&full_loop_B.dv10[0], &full_loop_DW.obj_c.Aeq[0], 48U * sizeof(real_T));
    for (full_loop_B.b_jAcol = 0; full_loop_B.b_jAcol < 6; full_loop_B.b_jAcol++)
    {
      full_loop_B.dv18[full_loop_B.b_jAcol] =
        full_loop_DW.obj_c.Beq[full_loop_B.b_jAcol];
    }

    full_loop_fmincon(&tunableEnvironment, full_loop_B.dv17, full_loop_B.dv10,
                      full_loop_B.dv18, full_loop_B.MATLABSystem_o3);
    memcpy(&full_loop_DW.obj_c.u0[0], &full_loop_B.MATLABSystem_o3[0], sizeof
           (real_T) << 3U);
    for (full_loop_B.b_j = 0; full_loop_B.b_j < 8; full_loop_B.b_j++) {
      full_loop_B.MATLABSystem_o3[full_loop_B.b_j] =
        -full_loop_DW.obj_c.u0[full_loop_B.b_j];
    }

    //  Calculer la nouvelle limite thruster
    for (full_loop_B.b_ix = 0; full_loop_B.b_ix < 8; full_loop_B.b_ix++) {
      if (full_loop_B.MATLABSystem_o3[full_loop_B.b_ix] > 0.0) {
        full_loop_DW.obj_c.uMax[full_loop_B.b_ix] -=
          full_loop_B.MATLABSystem_o3[full_loop_B.b_ix];
      } else {
        full_loop_DW.obj_c.uMin[full_loop_B.b_ix] -=
          full_loop_B.MATLABSystem_o3[full_loop_B.b_ix];
      }
    }

    memcpy(&full_loop_B.umin_scale[0], &full_loop_DW.obj_c.uMin[0], sizeof
           (real_T) << 3U);
    memcpy(&full_loop_B.umax_scale[0], &full_loop_DW.obj_c.uMax[0], sizeof
           (real_T) << 3U);

    //  toc;
    for (full_loop_B.b_j = 0; full_loop_B.b_j < 8; full_loop_B.b_j++) {
      // Gain: '<S70>/umin_scale' incorporates:
      //   MATLABSystem: '<S4>/MATLAB System'

      full_loop_B.umin_scale[full_loop_B.b_j] *=
        full_loop_P.umin_scale_Gain[full_loop_B.b_j];

      // Gain: '<S70>/umax_scale' incorporates:
      //   MATLABSystem: '<S4>/MATLAB System'

      full_loop_B.umax_scale[full_loop_B.b_j] *=
        full_loop_P.umax_scale_Gain[full_loop_B.b_j];
    }
  }

  if (rtmIsMajorTimeStep(full_loop_M) &&
      full_loop_M->Timing.TaskCounters.TID[1] == 0) {
    // MATLABSystem: '<S4>/MATLAB System1' incorporates:
    //   Constant: '<S4>/Constant1'
    //   Memory: '<S4>/Memory'

    full_loop_SystemCore_step(&full_loop_DW.obj,
      full_loop_DW.Memory_PreviousInput_m, full_loop_P.Ts,
      full_loop_B.checkedPose, full_loop_B.A, full_loop_B.B, full_loop_B.C,
      full_loop_B.D, full_loop_B.U, full_loop_B.Y, full_loop_B.X, full_loop_B.DX);
  }

  if (rtmIsMajorTimeStep(full_loop_M) &&
      full_loop_M->Timing.TaskCounters.TID[4] == 0) {
    // MATLAB Function: '<S98>/FixedHorizonOptimizer' incorporates:
    //   Memory: '<S70>/Memory'
    //   UnitDelay: '<S70>/last_mv'

    memset(&full_loop_B.Bu[0], 0, 1760U * sizeof(real_T));
    memset(&full_loop_B.Bv[0], 0, 220U * sizeof(real_T));
    memset(&full_loop_B.Dv[0], 0, 132U * sizeof(real_T));
    memset(&full_loop_B.Dvm[0], 0, 132U * sizeof(real_T));
    memset(&full_loop_B.Cm[0], 0, 2640U * sizeof(real_T));
    memcpy(&full_loop_B.b_A_f[0], &hb[0], 400U * sizeof(real_T));
    for (full_loop_B.b_j = 0; full_loop_B.b_j < 240; full_loop_B.b_j++) {
      full_loop_B.b_C[full_loop_B.b_j] = fb[full_loop_B.b_j];
    }

    for (full_loop_B.b_j = 0; full_loop_B.b_j < 8; full_loop_B.b_j++) {
      full_loop_B.dv17[full_loop_B.b_j] = static_cast<real_T>(full_loop_B.b_j) +
        1.0;
    }

    for (full_loop_B.b_j = 0; full_loop_B.b_j < 12; full_loop_B.b_j++) {
      full_loop_B.dv12[full_loop_B.b_j] = static_cast<real_T>(full_loop_B.b_j) +
        1.0;
    }

    for (full_loop_B.b_j = 0; full_loop_B.b_j < 8; full_loop_B.b_j++) {
      full_loop_B.dv15[full_loop_B.b_j] = 1.0;
    }

    for (full_loop_B.b_j = 0; full_loop_B.b_j < 12; full_loop_B.b_j++) {
      full_loop_B.dv13[full_loop_B.b_j] = 1.0;
    }

    memcpy(&full_loop_B.dv7[0], &full_loop_B.B[0], 96U * sizeof(real_T));
    memcpy(&full_loop_B.gb[0], &gb[0], 580U * sizeof(real_T));
    full_loop_mpc_plantupdate(full_loop_B.A, full_loop_B.dv7, full_loop_B.C,
      full_loop_B.b_A_f, full_loop_B.gb, full_loop_B.b_C, eb, full_loop_B.dv17,
      full_loop_B.dv12, full_loop_B.dv15, full_loop_B.dv13, &full_loop_B.Bu[0],
      &full_loop_B.Bv[0], full_loop_B.L, &full_loop_B.Dv[0], &full_loop_B.Dvm[0],
      full_loop_B.Qk, full_loop_B.Rk, full_loop_B.Nk);
    for (full_loop_B.b_j = 0; full_loop_B.b_j < 20; full_loop_B.b_j++) {
      memcpy(&full_loop_B.Cm[full_loop_B.b_j * 12],
             &full_loop_B.L[full_loop_B.b_j * 12], 12U * sizeof(real_T));
    }

    full_loop_B.qS2W[0] = 32.0;
    full_loop_B.qS2W[1] = 32.0;
    full_loop_B.qS2W[2] = 26.0;
    full_loop_B.qS2W[3] = 26.0;
    memset(&full_loop_B.b_utarget[0], 0, 80U * sizeof(real_T));
    memset(&full_loop_B.b_xoff[0], 0, 20U * sizeof(real_T));
    for (full_loop_B.b_j = 0; full_loop_B.b_j < 8; full_loop_B.b_j++) {
      full_loop_B.dv17[full_loop_B.b_j] = 1.0;
      full_loop_B.dv15[full_loop_B.b_j] = 0.0;
      full_loop_B.dv16[full_loop_B.b_j] = static_cast<real_T>(full_loop_B.b_j) +
        1.0;
    }

    for (full_loop_B.b_j = 0; full_loop_B.b_j < 12; full_loop_B.b_j++) {
      full_loop_B.dv12[full_loop_B.b_j] = 1.0;
      full_loop_B.dv13[full_loop_B.b_j] = 0.0;
      full_loop_B.dv14[full_loop_B.b_j] = static_cast<real_T>(full_loop_B.b_j) +
        1.0;
    }

    full_loop_mpc_updateFromNominal(full_loop_B.qS2W, e, full_loop_B.U,
      full_loop_B.dv17, full_loop_B.dv15, full_loop_B.dv16,
      full_loop_B.b_utarget, full_loop_B.Y, full_loop_B.dv12, full_loop_B.dv13,
      full_loop_B.dv14, full_loop_B.X, full_loop_B.b_xoff, full_loop_B.DX,
      full_loop_B.Bv, full_loop_B.b_uoff, full_loop_B.b_yoff,
      full_loop_B.TmpSignalConversionAtSFunct);
    for (full_loop_B.b_j = 0; full_loop_B.b_j < 12; full_loop_B.b_j++) {
      full_loop_B.dv12[full_loop_B.b_j] = 1.0;
    }

    full_loop_mpcblock_refmd(full_loop_B.DataTypeConversion1, full_loop_B.b_yoff,
      full_loop_B.dv12, full_loop_B.rseq, full_loop_B.vseq,
      &full_loop_B.rtb_sincos_o2_idx_2);
    for (full_loop_B.b_j = 0; full_loop_B.b_j < 12; full_loop_B.b_j++) {
      for (full_loop_B.b_c_i = 0; full_loop_B.b_c_i < 20; full_loop_B.b_c_i++) {
        full_loop_B.ix = 12 * full_loop_B.b_c_i + full_loop_B.b_j;
        full_loop_B.L[full_loop_B.b_c_i + 20 * full_loop_B.b_j] =
          full_loop_B.Cm[full_loop_B.ix];
        full_loop_B.Cm_c[full_loop_B.ix] = 0.0;
        for (full_loop_B.b_ix = 0; full_loop_B.b_ix < 20; full_loop_B.b_ix++) {
          full_loop_B.Cm_c[full_loop_B.ix] += full_loop_B.Cm[12 *
            full_loop_B.b_ix + full_loop_B.b_j] *
            full_loop_DW.LastPcov_PreviousInput[20 * full_loop_B.b_c_i +
            full_loop_B.b_ix];
        }
      }
    }

    for (full_loop_B.b_j = 0; full_loop_B.b_j < 12; full_loop_B.b_j++) {
      for (full_loop_B.b_c_i = 0; full_loop_B.b_c_i < 12; full_loop_B.b_c_i++) {
        full_loop_B.Sum_d = 0.0;
        for (full_loop_B.b_ix = 0; full_loop_B.b_ix < 20; full_loop_B.b_ix++) {
          full_loop_B.Sum_d += full_loop_B.Cm_c[12 * full_loop_B.b_ix +
            full_loop_B.b_j] * full_loop_B.L[20 * full_loop_B.b_c_i +
            full_loop_B.b_ix];
        }

        full_loop_B.b_ix = 12 * full_loop_B.b_c_i + full_loop_B.b_j;
        full_loop_B.c_A_m3[full_loop_B.b_ix] = full_loop_B.Rk[full_loop_B.b_ix]
          + full_loop_B.Sum_d;
      }

      full_loop_B.ipiv_j[full_loop_B.b_j] = static_cast<int8_T>(full_loop_B.b_j
        + 1);
    }

    for (full_loop_B.b_j = 0; full_loop_B.b_j < 11; full_loop_B.b_j++) {
      full_loop_B.b_c_i = full_loop_B.b_j * 13;
      full_loop_B.b_ix = 0;
      full_loop_B.ix = full_loop_B.b_c_i;
      full_loop_B.rtb_sincos_o2_idx_0 = fabs
        (full_loop_B.c_A_m3[full_loop_B.b_c_i]);
      full_loop_B.b_jAcol = 2;
      while (full_loop_B.b_jAcol <= 12 - full_loop_B.b_j) {
        full_loop_B.ix++;
        full_loop_B.rtb_sincos_o2_idx_1 = fabs(full_loop_B.c_A_m3[full_loop_B.ix]);
        if (full_loop_B.rtb_sincos_o2_idx_1 > full_loop_B.rtb_sincos_o2_idx_0) {
          full_loop_B.b_ix = full_loop_B.b_jAcol - 1;
          full_loop_B.rtb_sincos_o2_idx_0 = full_loop_B.rtb_sincos_o2_idx_1;
        }

        full_loop_B.b_jAcol++;
      }

      if (full_loop_B.c_A_m3[full_loop_B.b_c_i + full_loop_B.b_ix] != 0.0) {
        if (full_loop_B.b_ix != 0) {
          full_loop_B.ix = full_loop_B.b_j + full_loop_B.b_ix;
          full_loop_B.ipiv_j[full_loop_B.b_j] = static_cast<int8_T>
            (full_loop_B.ix + 1);
          full_loop_B.b_ix = full_loop_B.b_j;
          for (full_loop_B.b_jAcol = 0; full_loop_B.b_jAcol < 12;
               full_loop_B.b_jAcol++) {
            full_loop_B.rtb_sincos_o2_idx_0 =
              full_loop_B.c_A_m3[full_loop_B.b_ix];
            full_loop_B.c_A_m3[full_loop_B.b_ix] =
              full_loop_B.c_A_m3[full_loop_B.ix];
            full_loop_B.c_A_m3[full_loop_B.ix] = full_loop_B.rtb_sincos_o2_idx_0;
            full_loop_B.b_ix += 12;
            full_loop_B.ix += 12;
          }
        }

        full_loop_B.ix = (full_loop_B.b_c_i - full_loop_B.b_j) + 12;
        full_loop_B.b_ix = full_loop_B.b_c_i + 1;
        while (full_loop_B.b_ix + 1 <= full_loop_B.ix) {
          full_loop_B.c_A_m3[full_loop_B.b_ix] /=
            full_loop_B.c_A_m3[full_loop_B.b_c_i];
          full_loop_B.b_ix++;
        }
      }

      full_loop_B.b_ix = full_loop_B.b_c_i;
      full_loop_B.ix = full_loop_B.b_c_i + 12;
      full_loop_B.b_jAcol = 0;
      while (full_loop_B.b_jAcol <= 10 - full_loop_B.b_j) {
        if (full_loop_B.c_A_m3[full_loop_B.ix] != 0.0) {
          full_loop_B.rtb_sincos_o2_idx_0 = -full_loop_B.c_A_m3[full_loop_B.ix];
          full_loop_B.c_ix = full_loop_B.b_c_i + 1;
          full_loop_B.kBcol = (full_loop_B.b_ix - full_loop_B.b_j) + 24;
          full_loop_B.ijA = full_loop_B.b_ix + 13;
          while (full_loop_B.ijA + 1 <= full_loop_B.kBcol) {
            full_loop_B.c_A_m3[full_loop_B.ijA] +=
              full_loop_B.c_A_m3[full_loop_B.c_ix] *
              full_loop_B.rtb_sincos_o2_idx_0;
            full_loop_B.c_ix++;
            full_loop_B.ijA++;
          }
        }

        full_loop_B.ix += 12;
        full_loop_B.b_ix += 12;
        full_loop_B.b_jAcol++;
      }
    }

    full_loop_eye(full_loop_B.Rk);
    for (full_loop_B.b_ix = 0; full_loop_B.b_ix < 12; full_loop_B.b_ix++) {
      full_loop_B.ix = 12 * full_loop_B.b_ix;
      full_loop_B.c_ix = 12 * full_loop_B.b_ix;
      full_loop_B.b_jAcol = 0;
      while (full_loop_B.b_jAcol <= full_loop_B.b_ix - 1) {
        full_loop_B.kBcol = 12 * full_loop_B.b_jAcol;
        full_loop_B.b_j = full_loop_B.b_jAcol + full_loop_B.c_ix;
        if (full_loop_B.c_A_m3[full_loop_B.b_j] != 0.0) {
          for (full_loop_B.ijA = 0; full_loop_B.ijA < 12; full_loop_B.ijA++) {
            full_loop_B.b_c_i = full_loop_B.ijA + full_loop_B.ix;
            full_loop_B.Rk[full_loop_B.b_c_i] -=
              full_loop_B.c_A_m3[full_loop_B.b_j] *
              full_loop_B.Rk[full_loop_B.ijA + full_loop_B.kBcol];
          }
        }

        full_loop_B.b_jAcol++;
      }

      full_loop_B.rtb_sincos_o2_idx_0 = 1.0 /
        full_loop_B.c_A_m3[full_loop_B.b_ix + full_loop_B.c_ix];
      for (full_loop_B.b_j = 0; full_loop_B.b_j < 12; full_loop_B.b_j++) {
        full_loop_B.b_c_i = full_loop_B.b_j + full_loop_B.ix;
        full_loop_B.Rk[full_loop_B.b_c_i] *= full_loop_B.rtb_sincos_o2_idx_0;
      }
    }

    for (full_loop_B.b_ix = 11; full_loop_B.b_ix >= 0; full_loop_B.b_ix--) {
      full_loop_B.ix = 12 * full_loop_B.b_ix;
      full_loop_B.b_jAcol = 12 * full_loop_B.b_ix - 1;
      full_loop_B.c_ix = full_loop_B.b_ix + 2;
      while (full_loop_B.c_ix < 13) {
        full_loop_B.kBcol = (full_loop_B.c_ix - 1) * 12;
        full_loop_B.b_j = full_loop_B.c_ix + full_loop_B.b_jAcol;
        if (full_loop_B.c_A_m3[full_loop_B.b_j] != 0.0) {
          for (full_loop_B.ijA = 0; full_loop_B.ijA < 12; full_loop_B.ijA++) {
            full_loop_B.b_c_i = full_loop_B.ijA + full_loop_B.ix;
            full_loop_B.Rk[full_loop_B.b_c_i] -=
              full_loop_B.c_A_m3[full_loop_B.b_j] *
              full_loop_B.Rk[full_loop_B.ijA + full_loop_B.kBcol];
          }
        }

        full_loop_B.c_ix++;
      }
    }

    for (full_loop_B.b_j = 10; full_loop_B.b_j >= 0; full_loop_B.b_j--) {
      if (full_loop_B.b_j + 1 != full_loop_B.ipiv_j[full_loop_B.b_j]) {
        full_loop_B.b_ix = full_loop_B.ipiv_j[full_loop_B.b_j] - 1;
        for (full_loop_B.ix = 0; full_loop_B.ix < 12; full_loop_B.ix++) {
          full_loop_B.b_jAcol = 12 * full_loop_B.b_j + full_loop_B.ix;
          full_loop_B.rtb_sincos_o2_idx_0 = full_loop_B.Rk[full_loop_B.b_jAcol];
          full_loop_B.b_c_i = 12 * full_loop_B.b_ix + full_loop_B.ix;
          full_loop_B.Rk[full_loop_B.b_jAcol] = full_loop_B.Rk[full_loop_B.b_c_i];
          full_loop_B.Rk[full_loop_B.b_c_i] = full_loop_B.rtb_sincos_o2_idx_0;
        }
      }
    }

    for (full_loop_B.b_j = 0; full_loop_B.b_j < 20; full_loop_B.b_j++) {
      for (full_loop_B.b_c_i = 0; full_loop_B.b_c_i < 20; full_loop_B.b_c_i++) {
        full_loop_B.ix = full_loop_B.b_j + 20 * full_loop_B.b_c_i;
        full_loop_B.L_tmp[full_loop_B.ix] = 0.0;
        for (full_loop_B.b_ix = 0; full_loop_B.b_ix < 20; full_loop_B.b_ix++) {
          full_loop_B.L_tmp[full_loop_B.ix] += full_loop_B.b_A_f[20 *
            full_loop_B.b_ix + full_loop_B.b_j] *
            full_loop_DW.LastPcov_PreviousInput[20 * full_loop_B.b_c_i +
            full_loop_B.b_ix];
        }
      }

      for (full_loop_B.b_c_i = 0; full_loop_B.b_c_i < 12; full_loop_B.b_c_i++) {
        full_loop_B.Sum_d = 0.0;
        for (full_loop_B.b_ix = 0; full_loop_B.b_ix < 20; full_loop_B.b_ix++) {
          full_loop_B.Sum_d += full_loop_B.L_tmp[20 * full_loop_B.b_ix +
            full_loop_B.b_j] * full_loop_B.L[20 * full_loop_B.b_c_i +
            full_loop_B.b_ix];
        }

        full_loop_B.ix = 20 * full_loop_B.b_c_i + full_loop_B.b_j;
        full_loop_B.Cm_c[full_loop_B.ix] = full_loop_B.Nk[full_loop_B.ix] +
          full_loop_B.Sum_d;
      }
    }

    for (full_loop_B.b_j = 0; full_loop_B.b_j < 20; full_loop_B.b_j++) {
      for (full_loop_B.b_c_i = 0; full_loop_B.b_c_i < 12; full_loop_B.b_c_i++) {
        full_loop_B.ix = full_loop_B.b_j + 20 * full_loop_B.b_c_i;
        full_loop_B.L[full_loop_B.ix] = 0.0;
        for (full_loop_B.b_ix = 0; full_loop_B.b_ix < 12; full_loop_B.b_ix++) {
          full_loop_B.L[full_loop_B.ix] += full_loop_B.Cm_c[20 *
            full_loop_B.b_ix + full_loop_B.b_j] * full_loop_B.Rk[12 *
            full_loop_B.b_c_i + full_loop_B.b_ix];
        }
      }

      full_loop_B.Sum_d = 0.0;
      for (full_loop_B.b_c_i = 0; full_loop_B.b_c_i < 8; full_loop_B.b_c_i++) {
        full_loop_B.Sum_d += full_loop_B.Bu[20 * full_loop_B.b_c_i +
          full_loop_B.b_j] * 0.0;
      }

      full_loop_B.xk[full_loop_B.b_j] =
        (full_loop_DW.last_x_PreviousInput[full_loop_B.b_j] -
         full_loop_B.b_xoff[full_loop_B.b_j]) + full_loop_B.Sum_d;
    }

    for (full_loop_B.b_j = 0; full_loop_B.b_j < 12; full_loop_B.b_j++) {
      full_loop_B.Sum_d = 0.0;
      for (full_loop_B.b_c_i = 0; full_loop_B.b_c_i < 20; full_loop_B.b_c_i++) {
        full_loop_B.Sum_d += full_loop_B.Cm[12 * full_loop_B.b_c_i +
          full_loop_B.b_j] * full_loop_B.xk[full_loop_B.b_c_i];
      }

      full_loop_B.DataTypeConversion1[full_loop_B.b_j] =
        (full_loop_B.checkedPose[full_loop_B.b_j] -
         full_loop_B.TmpSignalConversionAtSFunct[full_loop_B.b_j]) -
        (full_loop_B.Dvm[full_loop_B.b_j] * full_loop_B.rtb_sincos_o2_idx_2 +
         full_loop_B.Sum_d);
    }

    for (full_loop_B.b_j = 0; full_loop_B.b_j < 20; full_loop_B.b_j++) {
      for (full_loop_B.b_c_i = 0; full_loop_B.b_c_i < 12; full_loop_B.b_c_i++) {
        full_loop_B.b_ix = full_loop_B.b_j + 20 * full_loop_B.b_c_i;
        full_loop_B.Nk[full_loop_B.b_ix] = 0.0;
        for (full_loop_B.ix = 0; full_loop_B.ix < 20; full_loop_B.ix++) {
          full_loop_B.Nk[full_loop_B.b_ix] +=
            full_loop_DW.LastPcov_PreviousInput[20 * full_loop_B.ix +
            full_loop_B.b_j] * full_loop_B.Cm[12 * full_loop_B.ix +
            full_loop_B.b_c_i];
        }
      }

      full_loop_B.Sum_d = 0.0;
      for (full_loop_B.b_c_i = 0; full_loop_B.b_c_i < 12; full_loop_B.b_c_i++) {
        full_loop_B.b_ix = full_loop_B.b_j + 20 * full_loop_B.b_c_i;
        full_loop_B.dv5[full_loop_B.b_ix] = 0.0;
        for (full_loop_B.ix = 0; full_loop_B.ix < 12; full_loop_B.ix++) {
          full_loop_B.dv5[full_loop_B.b_ix] += full_loop_B.Nk[20 *
            full_loop_B.ix + full_loop_B.b_j] * full_loop_B.Rk[12 *
            full_loop_B.b_c_i + full_loop_B.ix];
        }

        full_loop_B.Sum_d += full_loop_B.dv5[full_loop_B.b_ix] *
          full_loop_B.DataTypeConversion1[full_loop_B.b_c_i];
      }

      full_loop_B.xk_o[full_loop_B.b_j] = full_loop_B.xk[full_loop_B.b_j] +
        full_loop_B.Sum_d;
    }

    for (full_loop_B.b_j = 0; full_loop_B.b_j < 8; full_loop_B.b_j++) {
      full_loop_B.dv17[full_loop_B.b_j] =
        full_loop_DW.last_mv_DSTATE[full_loop_B.b_j] -
        full_loop_B.b_uoff[full_loop_B.b_j];
    }

    memset(&full_loop_B.dv6[0], 0, 176U * sizeof(real_T));
    memset(&full_loop_B.dv8[0], 0, 80U * sizeof(real_T));
    memset(&full_loop_B.dv11[0], 0, 44U * sizeof(real_T));
    memset(&full_loop_B.dv1[0], 0, 1320U * sizeof(real_T));
    memcpy(&full_loop_B.u_a[0], &u[0], sizeof(real_T) << 5);
    memcpy(&full_loop_B.t[0], &t[0], 289U * sizeof(real_T));
    memcpy(&full_loop_B.r[0], &r[0], 68U * sizeof(real_T));
    full_loop_mpcblock_optimizer(full_loop_B.rseq, full_loop_B.vseq,
      full_loop_B.umin_scale, full_loop_B.umax_scale, full_loop_B.xk_o,
      full_loop_B.dv17, full_loop_DW.Memory_PreviousInput_d, full_loop_B.qS2W,
      full_loop_B.dv8, full_loop_B.u_a, full_loop_B.dv11, full_loop_B.b_utarget,
      full_loop_B.b_uoff, full_loop_B.t, full_loop_B.r, q, o, n, g, f,
      full_loop_B.b_A_f, full_loop_B.Bu, full_loop_B.Bv, full_loop_B.b_C,
      full_loop_B.Dv, e, full_loop_B.u, full_loop_B.useq,
      &full_loop_B.rtb_sincos_o2_idx_0, full_loop_B.iAout);
    for (full_loop_B.b_j = 0; full_loop_B.b_j < 20; full_loop_B.b_j++) {
      for (full_loop_B.b_c_i = 0; full_loop_B.b_c_i < 20; full_loop_B.b_c_i++) {
        full_loop_B.ix = full_loop_B.b_j + 20 * full_loop_B.b_c_i;
        full_loop_B.L_tmp_a[full_loop_B.ix] = 0.0;
        for (full_loop_B.b_ix = 0; full_loop_B.b_ix < 20; full_loop_B.b_ix++) {
          full_loop_B.L_tmp_a[full_loop_B.ix] += full_loop_B.L_tmp[20 *
            full_loop_B.b_ix + full_loop_B.b_j] * full_loop_B.b_A_f[20 *
            full_loop_B.b_ix + full_loop_B.b_c_i];
        }

        full_loop_B.L_tmp_j[full_loop_B.ix] = 0.0;
        for (full_loop_B.b_ix = 0; full_loop_B.b_ix < 12; full_loop_B.b_ix++) {
          full_loop_B.L_tmp_j[full_loop_B.ix] += full_loop_B.Cm_c[20 *
            full_loop_B.b_ix + full_loop_B.b_j] * full_loop_B.L[20 *
            full_loop_B.b_ix + full_loop_B.b_c_i];
        }
      }
    }

    for (full_loop_B.b_j = 0; full_loop_B.b_j < 400; full_loop_B.b_j++) {
      full_loop_B.L_tmp[full_loop_B.b_j] = (full_loop_B.L_tmp_a[full_loop_B.b_j]
        - full_loop_B.L_tmp_j[full_loop_B.b_j]) + full_loop_B.Qk[full_loop_B.b_j];
    }

    for (full_loop_B.b_j = 0; full_loop_B.b_j < 8; full_loop_B.b_j++) {
      full_loop_B.dv17[full_loop_B.b_j] = full_loop_B.u[full_loop_B.b_j] -
        full_loop_B.b_uoff[full_loop_B.b_j];
    }

    for (full_loop_B.b_j = 0; full_loop_B.b_j < 20; full_loop_B.b_j++) {
      full_loop_B.xk_o[full_loop_B.b_j] = 0.0;
      for (full_loop_B.b_c_i = 0; full_loop_B.b_c_i < 20; full_loop_B.b_c_i++) {
        full_loop_B.xk_o[full_loop_B.b_j] += full_loop_B.b_A_f[20 *
          full_loop_B.b_c_i + full_loop_B.b_j] *
          full_loop_B.xk[full_loop_B.b_c_i];
      }

      full_loop_B.Bu_i[full_loop_B.b_j] = 0.0;
      for (full_loop_B.b_c_i = 0; full_loop_B.b_c_i < 8; full_loop_B.b_c_i++) {
        full_loop_B.Bu_i[full_loop_B.b_j] += full_loop_B.Bu[20 *
          full_loop_B.b_c_i + full_loop_B.b_j] *
          full_loop_B.dv17[full_loop_B.b_c_i];
      }

      full_loop_B.Sum_d = 0.0;
      for (full_loop_B.b_c_i = 0; full_loop_B.b_c_i < 12; full_loop_B.b_c_i++) {
        full_loop_B.Sum_d += full_loop_B.L[20 * full_loop_B.b_c_i +
          full_loop_B.b_j] * full_loop_B.DataTypeConversion1[full_loop_B.b_c_i];
      }

      full_loop_B.xk1[full_loop_B.b_j] = (((full_loop_B.xk_o[full_loop_B.b_j] +
        full_loop_B.Bu_i[full_loop_B.b_j]) + full_loop_B.Bv[full_loop_B.b_j] *
        full_loop_B.rtb_sincos_o2_idx_2) + full_loop_B.Sum_d) +
        full_loop_B.b_xoff[full_loop_B.b_j];
      for (full_loop_B.b_c_i = 0; full_loop_B.b_c_i < 20; full_loop_B.b_c_i++) {
        full_loop_B.b_ix = 20 * full_loop_B.b_j + full_loop_B.b_c_i;
        full_loop_B.Pk1[full_loop_B.b_ix] = (full_loop_B.L_tmp[full_loop_B.b_ix]
          + full_loop_B.L_tmp[20 * full_loop_B.b_c_i + full_loop_B.b_j]) * 0.5;
      }
    }

    // End of MATLAB Function: '<S98>/FixedHorizonOptimizer'
  }

  if (rtmIsMajorTimeStep(full_loop_M) &&
      full_loop_M->Timing.TaskCounters.TID[1] == 0) {
    for (full_loop_B.b_j = 0; full_loop_B.b_j < 3; full_loop_B.b_j++) {
      // Concatenate: '<S21>/Vector Concatenate' incorporates:
      //   Constant: '<S21>/Constant1'
      //   Constant: '<S21>/Constant2'
      //   Selector: '<S20>/Selector1'

      full_loop_B.VectorConcatenate_e[6 * full_loop_B.b_j] = full_loop_P.I[3 *
        full_loop_B.b_j];
      full_loop_B.b_c_i = 6 * full_loop_B.b_j + 3;
      full_loop_B.VectorConcatenate_e[full_loop_B.b_c_i] =
        full_loop_P.Constant2_Value[3 * full_loop_B.b_j];

      // Selector: '<S20>/Selector' incorporates:
      //   Selector: '<S20>/Selector2'

      full_loop_B.rtb_sincos_o2_idx_2 = full_loop_B.VectorConcatenate_e[6 *
        full_loop_B.b_j];
      full_loop_B.Selector[3 * full_loop_B.b_j] =
        full_loop_B.rtb_sincos_o2_idx_2;

      // Selector: '<S20>/Selector1'
      full_loop_B.Selector1[3 * full_loop_B.b_j] =
        full_loop_B.VectorConcatenate_e[full_loop_B.b_c_i];

      // Selector: '<S20>/Selector2'
      full_loop_B.Selector2[3 * full_loop_B.b_j] =
        full_loop_B.rtb_sincos_o2_idx_2;

      // Concatenate: '<S21>/Vector Concatenate' incorporates:
      //   Constant: '<S21>/Constant1'
      //   Constant: '<S21>/Constant2'
      //   Selector: '<S20>/Selector'
      //   Selector: '<S20>/Selector1'
      //   Selector: '<S20>/Selector2'

      full_loop_B.b_c_i = 3 * full_loop_B.b_j + 1;
      full_loop_B.b_ix = 6 * full_loop_B.b_j + 1;
      full_loop_B.VectorConcatenate_e[full_loop_B.b_ix] =
        full_loop_P.I[full_loop_B.b_c_i];
      full_loop_B.ix = 6 * full_loop_B.b_j + 4;
      full_loop_B.VectorConcatenate_e[full_loop_B.ix] =
        full_loop_P.Constant2_Value[full_loop_B.b_c_i];

      // Selector: '<S20>/Selector'
      full_loop_B.Selector[full_loop_B.b_c_i] =
        full_loop_B.VectorConcatenate_e[full_loop_B.b_ix];

      // Selector: '<S20>/Selector1'
      full_loop_B.Selector1[full_loop_B.b_c_i] =
        full_loop_B.VectorConcatenate_e[full_loop_B.ix];

      // Selector: '<S20>/Selector2'
      full_loop_B.Selector2[full_loop_B.b_c_i] =
        full_loop_B.VectorConcatenate_e[full_loop_B.b_ix];

      // Concatenate: '<S21>/Vector Concatenate' incorporates:
      //   Constant: '<S21>/Constant1'
      //   Constant: '<S21>/Constant2'
      //   Selector: '<S20>/Selector'
      //   Selector: '<S20>/Selector1'
      //   Selector: '<S20>/Selector2'

      full_loop_B.b_c_i = 3 * full_loop_B.b_j + 2;
      full_loop_B.b_ix = 6 * full_loop_B.b_j + 2;
      full_loop_B.VectorConcatenate_e[full_loop_B.b_ix] =
        full_loop_P.I[full_loop_B.b_c_i];
      full_loop_B.ix = 6 * full_loop_B.b_j + 5;
      full_loop_B.VectorConcatenate_e[full_loop_B.ix] =
        full_loop_P.Constant2_Value[full_loop_B.b_c_i];

      // Selector: '<S20>/Selector'
      full_loop_B.Selector[full_loop_B.b_c_i] =
        full_loop_B.VectorConcatenate_e[full_loop_B.b_ix];

      // Selector: '<S20>/Selector1'
      full_loop_B.Selector1[full_loop_B.b_c_i] =
        full_loop_B.VectorConcatenate_e[full_loop_B.ix];

      // Selector: '<S20>/Selector2'
      full_loop_B.Selector2[full_loop_B.b_c_i] =
        full_loop_B.VectorConcatenate_e[full_loop_B.b_ix];
    }
  }

  // Product: '<S41>/Product1' incorporates:
  //   Integrator: '<S19>/q0 q1 q2 q3'

  full_loop_B.Product8 = full_loop_X.q0q1q2q3_CSTATE[1] / full_loop_B.Sum_a_e;

  // Product: '<S41>/Product' incorporates:
  //   Integrator: '<S19>/q0 q1 q2 q3'

  full_loop_B.Sum_a_e = full_loop_X.q0q1q2q3_CSTATE[0] / full_loop_B.Sum_a_e;

  // Product: '<S31>/Product3' incorporates:
  //   Product: '<S35>/Product3'

  full_loop_B.rtb_sincos_o2_idx_2 = full_loop_B.Sum_a_e * full_loop_B.Sum_a_e;

  // Product: '<S31>/Product2' incorporates:
  //   Product: '<S35>/Product2'

  full_loop_B.rtb_sincos_o2_idx_0 = full_loop_B.Product8 * full_loop_B.Product8;

  // Product: '<S31>/Product1' incorporates:
  //   Product: '<S35>/Product1'
  //   Product: '<S39>/Product1'

  full_loop_B.rtb_sincos_o2_idx_1 = full_loop_B.t26 * full_loop_B.t26;

  // Product: '<S31>/Product' incorporates:
  //   Product: '<S35>/Product'
  //   Product: '<S39>/Product'

  full_loop_B.Product2_h5 = full_loop_B.t27 * full_loop_B.t27;

  // Sum: '<S31>/Sum' incorporates:
  //   Product: '<S31>/Product'
  //   Product: '<S31>/Product1'
  //   Product: '<S31>/Product2'
  //   Product: '<S31>/Product3'

  full_loop_B.Transpose[0] = ((full_loop_B.rtb_sincos_o2_idx_2 +
    full_loop_B.rtb_sincos_o2_idx_0) - full_loop_B.rtb_sincos_o2_idx_1) -
    full_loop_B.Product2_h5;

  // Product: '<S32>/Product2' incorporates:
  //   Product: '<S34>/Product2'

  full_loop_B.Product3_bd = full_loop_B.Product8 * full_loop_B.t26;

  // Product: '<S32>/Product3' incorporates:
  //   Product: '<S34>/Product3'

  full_loop_B.Sum_d = full_loop_B.t27 * full_loop_B.Sum_a_e;

  // Gain: '<S32>/Gain' incorporates:
  //   Product: '<S32>/Product2'
  //   Product: '<S32>/Product3'
  //   Sum: '<S32>/Sum'

  full_loop_B.Transpose[3] = (full_loop_B.Sum_d + full_loop_B.Product3_bd) *
    full_loop_P.Gain_Gain_kf;

  // Product: '<S33>/Product1' incorporates:
  //   Product: '<S37>/Product1'

  full_loop_B.Product2_fy = full_loop_B.Sum_a_e * full_loop_B.t26;

  // Product: '<S33>/Product2' incorporates:
  //   Product: '<S37>/Product2'

  full_loop_B.t17 = full_loop_B.Product8 * full_loop_B.t27;

  // Gain: '<S33>/Gain' incorporates:
  //   Product: '<S33>/Product1'
  //   Product: '<S33>/Product2'
  //   Sum: '<S33>/Sum'

  full_loop_B.Transpose[6] = (full_loop_B.t17 - full_loop_B.Product2_fy) *
    full_loop_P.Gain_Gain_hv;

  // Gain: '<S34>/Gain' incorporates:
  //   Sum: '<S34>/Sum'

  full_loop_B.Transpose[1] = (full_loop_B.Product3_bd - full_loop_B.Sum_d) *
    full_loop_P.Gain_Gain_l;

  // Sum: '<S35>/Sum' incorporates:
  //   Sum: '<S39>/Sum'

  full_loop_B.rtb_sincos_o2_idx_2 -= full_loop_B.rtb_sincos_o2_idx_0;
  full_loop_B.Transpose[4] = (full_loop_B.rtb_sincos_o2_idx_2 +
    full_loop_B.rtb_sincos_o2_idx_1) - full_loop_B.Product2_h5;

  // Product: '<S36>/Product2' incorporates:
  //   Product: '<S38>/Product2'

  full_loop_B.rtb_sincos_o2_idx_0 = full_loop_B.t26 * full_loop_B.t27;

  // Product: '<S36>/Product1' incorporates:
  //   Product: '<S38>/Product1'

  full_loop_B.Product3_bd = full_loop_B.Sum_a_e * full_loop_B.Product8;

  // Gain: '<S36>/Gain' incorporates:
  //   Product: '<S36>/Product1'
  //   Product: '<S36>/Product2'
  //   Sum: '<S36>/Sum'

  full_loop_B.Transpose[7] = (full_loop_B.Product3_bd +
    full_loop_B.rtb_sincos_o2_idx_0) * full_loop_P.Gain_Gain_hl;

  // Gain: '<S37>/Gain' incorporates:
  //   Sum: '<S37>/Sum'

  full_loop_B.Transpose[2] = (full_loop_B.Product2_fy + full_loop_B.t17) *
    full_loop_P.Gain_Gain_i;

  // Gain: '<S38>/Gain' incorporates:
  //   Sum: '<S38>/Sum'

  full_loop_B.Transpose[5] = (full_loop_B.rtb_sincos_o2_idx_0 -
    full_loop_B.Product3_bd) * full_loop_P.Gain_Gain_e;

  // Sum: '<S39>/Sum'
  full_loop_B.Transpose[8] = (full_loop_B.rtb_sincos_o2_idx_2 -
    full_loop_B.rtb_sincos_o2_idx_1) + full_loop_B.Product2_h5;

  // Math: '<S13>/Transpose'
  for (full_loop_B.b_j = 0; full_loop_B.b_j < 3; full_loop_B.b_j++) {
    full_loop_B.rtb_Transpose_c[3 * full_loop_B.b_j] =
      full_loop_B.Transpose[full_loop_B.b_j];
    full_loop_B.rtb_Transpose_c[3 * full_loop_B.b_j + 1] =
      full_loop_B.Transpose[full_loop_B.b_j + 3];
    full_loop_B.rtb_Transpose_c[3 * full_loop_B.b_j + 2] =
      full_loop_B.Transpose[full_loop_B.b_j + 6];
  }

  memcpy(&full_loop_B.Transpose[0], &full_loop_B.rtb_Transpose_c[0], 9U * sizeof
         (real_T));

  // End of Math: '<S13>/Transpose'
  if (rtmIsMajorTimeStep(full_loop_M) &&
      full_loop_M->Timing.TaskCounters.TID[4] == 0) {
    for (full_loop_B.ix = 0; full_loop_B.ix < 8; full_loop_B.ix++) {
      // Sum: '<S4>/Sum' incorporates:
      //   Gain: '<S70>/u_scale'

      full_loop_B.Sum_ae[full_loop_B.ix] =
        full_loop_P.u_scale_Gain[full_loop_B.ix] * full_loop_B.u[full_loop_B.ix]
        + full_loop_B.MATLABSystem_o3[full_loop_B.ix];

      // Saturate: '<S4>/Saturation'
      if (full_loop_B.Sum_ae[full_loop_B.ix] > full_loop_P.tmax) {
        full_loop_B.t26 = full_loop_P.tmax;
      } else if (full_loop_B.Sum_ae[full_loop_B.ix] < full_loop_P.tmin) {
        full_loop_B.t26 = full_loop_P.tmin;
      } else {
        full_loop_B.t26 = full_loop_B.Sum_ae[full_loop_B.ix];
      }

      full_loop_B.MATLABSystem_o3[full_loop_B.ix] = full_loop_B.t26;

      // End of Saturate: '<S4>/Saturation'
    }

    for (full_loop_B.b_j = 0; full_loop_B.b_j < 8; full_loop_B.b_j++) {
      // Lookup_n-D: '<S4>/1-D Lookup Table5'
      full_loop_B.t26 = full_loop_P.PWM[plook_u32d_binckan
        (full_loop_B.MATLABSystem_o3[full_loop_B.b_j], full_loop_P.N, 200U)];

      // Lookup_n-D: '<S16>/1-D Lookup Table1'
      full_loop_B.uDLookupTable1[full_loop_B.b_j] =
        full_loop_P.N[plook_u32d_binckan(full_loop_B.t26, full_loop_P.PWM, 200U)];

      // Lookup_n-D: '<S4>/1-D Lookup Table5'
      full_loop_B.MATLABSystem_o3[full_loop_B.b_j] = full_loop_B.t26;
    }
  }

  // Gain: '<S30>/High Gain Quaternion Normalization' incorporates:
  //   Constant: '<S30>/Constant'
  //   DotProduct: '<S30>/Dot Product'
  //   Integrator: '<S19>/q0 q1 q2 q3'
  //   Sum: '<S30>/Sum'

  full_loop_B.Sum_a_e = (full_loop_P.Constant_Value_n -
    (((full_loop_X.q0q1q2q3_CSTATE[0] * full_loop_X.q0q1q2q3_CSTATE[0] +
       full_loop_X.q0q1q2q3_CSTATE[1] * full_loop_X.q0q1q2q3_CSTATE[1]) +
      full_loop_X.q0q1q2q3_CSTATE[2] * full_loop_X.q0q1q2q3_CSTATE[2]) +
     full_loop_X.q0q1q2q3_CSTATE[3] * full_loop_X.q0q1q2q3_CSTATE[3])) *
    full_loop_P.uDOFEulerAngles_k_quat;

  // SignalConversion generated from: '<S19>/q0 q1 q2 q3' incorporates:
  //   Fcn: '<S30>/q0dot'
  //   Fcn: '<S30>/q1dot'
  //   Fcn: '<S30>/q2dot'
  //   Fcn: '<S30>/q3dot'
  //   Integrator: '<S13>/p,q,r '
  //   Integrator: '<S19>/q0 q1 q2 q3'

  full_loop_B.TmpSignalConversionAtq0q1q2q3_c[0] =
    ((full_loop_X.q0q1q2q3_CSTATE[1] * full_loop_X.pqr_CSTATE[0] +
      full_loop_X.q0q1q2q3_CSTATE[2] * full_loop_X.pqr_CSTATE[1]) +
     full_loop_X.q0q1q2q3_CSTATE[3] * full_loop_X.pqr_CSTATE[2]) * -0.5 +
    full_loop_B.Sum_a_e * full_loop_X.q0q1q2q3_CSTATE[0];
  full_loop_B.TmpSignalConversionAtq0q1q2q3_c[1] =
    ((full_loop_X.q0q1q2q3_CSTATE[0] * full_loop_X.pqr_CSTATE[0] +
      full_loop_X.q0q1q2q3_CSTATE[2] * full_loop_X.pqr_CSTATE[2]) -
     full_loop_X.q0q1q2q3_CSTATE[3] * full_loop_X.pqr_CSTATE[1]) * 0.5 +
    full_loop_B.Sum_a_e * full_loop_X.q0q1q2q3_CSTATE[1];
  full_loop_B.TmpSignalConversionAtq0q1q2q3_c[2] =
    ((full_loop_X.q0q1q2q3_CSTATE[0] * full_loop_X.pqr_CSTATE[1] +
      full_loop_X.q0q1q2q3_CSTATE[3] * full_loop_X.pqr_CSTATE[0]) -
     full_loop_X.q0q1q2q3_CSTATE[1] * full_loop_X.pqr_CSTATE[2]) * 0.5 +
    full_loop_B.Sum_a_e * full_loop_X.q0q1q2q3_CSTATE[2];
  full_loop_B.TmpSignalConversionAtq0q1q2q3_c[3] =
    ((full_loop_X.q0q1q2q3_CSTATE[0] * full_loop_X.pqr_CSTATE[2] +
      full_loop_X.q0q1q2q3_CSTATE[1] * full_loop_X.pqr_CSTATE[1]) -
     full_loop_X.q0q1q2q3_CSTATE[2] * full_loop_X.pqr_CSTATE[0]) * 0.5 +
    full_loop_B.Sum_a_e * full_loop_X.q0q1q2q3_CSTATE[3];

  // SignalConversion generated from: '<S14>/ SFunction ' incorporates:
  //   MATLAB Function: '<S3>/Forces and torques'

  full_loop_B.TmpSignalConversionAtSFunct[3] = full_loop_B.rtb_sincos_o1_idx_2;
  full_loop_B.TmpSignalConversionAtSFunct[4] = full_loop_B.rtb_sincos_o1_idx_1;
  full_loop_B.TmpSignalConversionAtSFunct[5] = full_loop_B.rtb_sincos_o1_idx_0;

  // MATLAB Function: '<S3>/Forces and torques'
  full_loop_B.rtb_sincos_o1_idx_0 = full_loop_B.uDLookupTable1[0] *
    1.4142135623730951 * 0.0275;
  full_loop_B.rtb_sincos_o1_idx_1 = full_loop_B.uDLookupTable1[1] *
    1.4142135623730951 * 0.0275;
  full_loop_B.t26 = full_loop_B.uDLookupTable1[2] * 1.4142135623730951 * 0.0275;
  full_loop_B.t27 = full_loop_B.uDLookupTable1[3] * 1.4142135623730951 * 0.0275;

  // Sin: '<S18>/Roll Wave' incorporates:
  //   Sin: '<S18>/Pitch Wave'
  //   Sin: '<S18>/X Wave'
  //   Sin: '<S18>/Y Wave'
  //   Sin: '<S18>/Yaw Wave'
  //   Sin: '<S18>/Z Wave'

  full_loop_B.rtb_sincos_o1_idx_2 = full_loop_M->Timing.t[0];
  for (full_loop_B.ix = 0; full_loop_B.ix < 3; full_loop_B.ix++) {
    // SignalConversion generated from: '<S14>/ SFunction ' incorporates:
    //   Integrator: '<S13>/p,q,r '
    //   Integrator: '<S15>/Integrator'
    //   MATLAB Function: '<S3>/Forces and torques'

    full_loop_B.TmpSignalConversionAtSFunct[full_loop_B.ix] =
      full_loop_X.Integrator_CSTATE[full_loop_B.ix];
    full_loop_B.TmpSignalConversionAtSFunct[full_loop_B.ix + 6] =
      full_loop_B.ubvbwb[full_loop_B.ix];
    full_loop_B.TmpSignalConversionAtSFunct[full_loop_B.ix + 9] =
      full_loop_X.pqr_CSTATE[full_loop_B.ix];

    // Product: '<S53>/Product' incorporates:
    //   Integrator: '<S13>/p,q,r '

    full_loop_B.sincos_o2_b[full_loop_B.ix] =
      full_loop_B.Selector[full_loop_B.ix + 6] * full_loop_X.pqr_CSTATE[2] +
      (full_loop_B.Selector[full_loop_B.ix + 3] * full_loop_X.pqr_CSTATE[1] +
       full_loop_B.Selector[full_loop_B.ix] * full_loop_X.pqr_CSTATE[0]);
  }

  // MATLAB Function: '<S3>/Forces and torques'
  full_loop_B.Sum_d = full_loop_B.TmpSignalConversionAtSFunct[3] / 2.0;
  full_loop_B.Product2_fy = full_loop_B.TmpSignalConversionAtSFunct[5] / 2.0;
  full_loop_B.Product3_bd = full_loop_B.TmpSignalConversionAtSFunct[4] / 2.0;
  full_loop_B.rtb_sincos_o2_idx_0 = full_loop_B.TmpSignalConversionAtSFunct[3] /
    2.0;
  full_loop_B.rtb_sincos_o2_idx_1 = cos(full_loop_B.Sum_d);
  full_loop_B.rtb_sincos_o2_idx_2 = full_loop_B.TmpSignalConversionAtSFunct[5] /
    2.0;
  full_loop_B.Product2_h5 = cos(full_loop_B.Product2_fy);
  full_loop_B.Sum_a_e = full_loop_B.TmpSignalConversionAtSFunct[4] / 2.0;
  full_loop_B.Product8 = cos(full_loop_B.Product3_bd);
  full_loop_B.Sum_d = sin(full_loop_B.Sum_d);
  full_loop_B.Product2_fy = sin(full_loop_B.Product2_fy);
  full_loop_B.t17 = sin(full_loop_B.Product3_bd);
  full_loop_B.t18 = cos(full_loop_B.rtb_sincos_o2_idx_0);
  full_loop_B.t19 = cos(full_loop_B.rtb_sincos_o2_idx_2);
  full_loop_B.t20 = cos(full_loop_B.Sum_a_e);
  full_loop_B.t21 = sin(full_loop_B.rtb_sincos_o2_idx_0);
  full_loop_B.ixk = sin(full_loop_B.rtb_sincos_o2_idx_2);
  full_loop_B.t23 = sin(full_loop_B.Sum_a_e);
  full_loop_B.t42 = full_loop_B.rtb_sincos_o2_idx_1 * full_loop_B.Product2_h5;
  full_loop_B.Sum_a_e = full_loop_B.t42 * full_loop_B.t17;
  full_loop_B.rtb_sincos_o2_idx_2 = full_loop_B.rtb_sincos_o2_idx_1 *
    full_loop_B.Product8 * full_loop_B.Product2_fy;
  full_loop_B.rtb_sincos_o2_idx_0 = full_loop_B.Product2_h5 *
    full_loop_B.Product8 * full_loop_B.Sum_d;
  full_loop_B.rtb_sincos_o2_idx_1 = full_loop_B.rtb_sincos_o2_idx_1 *
    full_loop_B.Product2_fy * full_loop_B.t17;
  full_loop_B.Product2_h5 = full_loop_B.Product2_h5 * full_loop_B.Sum_d *
    full_loop_B.t17;
  full_loop_B.Product3_bd = full_loop_B.Product8 * full_loop_B.Sum_d *
    full_loop_B.Product2_fy;
  full_loop_B.Sum_d = full_loop_B.Sum_d * full_loop_B.Product2_fy *
    full_loop_B.t17;
  full_loop_B.Product8 *= full_loop_B.t42;
  full_loop_B.Product2_fy = full_loop_B.t18 * full_loop_B.t19 * full_loop_B.t23;
  full_loop_B.t17 = full_loop_B.t18 * full_loop_B.t20 * full_loop_B.ixk;
  full_loop_B.t42 = full_loop_B.t19 * full_loop_B.t20 * full_loop_B.t21;
  full_loop_B.t18 = full_loop_B.t18 * full_loop_B.ixk * full_loop_B.t23;
  full_loop_B.t19 = full_loop_B.t19 * full_loop_B.t21 * full_loop_B.t23;
  full_loop_B.t20 = full_loop_B.t20 * full_loop_B.t21 * full_loop_B.ixk;
  full_loop_B.t48 = full_loop_B.Sum_a_e + full_loop_B.Product3_bd;
  full_loop_B.ixk = full_loop_B.Sum_d + full_loop_B.Product8;
  full_loop_B.t21 = full_loop_B.rtb_sincos_o2_idx_0 +
    -full_loop_B.rtb_sincos_o2_idx_1;
  full_loop_B.t52 = full_loop_B.Sum_d * 2.0 + full_loop_B.Product8 * 2.0;
  full_loop_B.ixk *= full_loop_B.ixk;
  full_loop_B.t55 = full_loop_B.t17 + -full_loop_B.t19;
  full_loop_B.t23 = full_loop_B.t48 * (full_loop_B.Product2_fy + full_loop_B.t20);
  full_loop_B.Dynamics_tmp = (full_loop_B.rtb_sincos_o2_idx_2 +
    -full_loop_B.Product2_h5) * full_loop_B.t55;
  full_loop_B.Dynamics_tmp_o = full_loop_B.t21 * (full_loop_B.t42 +
    -full_loop_B.t18);
  full_loop_B.Dynamics_tmp_b = full_loop_B.t48 * full_loop_B.t55;
  full_loop_B.Dynamics_tmp_a = full_loop_B.t21 * full_loop_B.t52;

  // Sum: '<S18>/Sum1' incorporates:
  //   MATLAB Function: '<S3>/Forces and torques'
  //   Sin: '<S18>/Roll Wave'

  full_loop_B.Dynamics[0] = (((((((((((((((full_loop_B.uDLookupTable1[4] * 0.162
    - full_loop_B.uDLookupTable1[5] * 0.162) - full_loop_B.uDLookupTable1[6] *
    0.156) + full_loop_B.uDLookupTable1[7] * 0.156) +
    full_loop_B.rtb_sincos_o1_idx_0) - full_loop_B.rtb_sincos_o1_idx_1) +
    full_loop_B.t26) - full_loop_B.t27) + full_loop_B.ixk * 0.08758368) +
    full_loop_B.TmpSignalConversionAtSFunct[11] *
    full_loop_B.TmpSignalConversionAtSFunct[10] * 0.21) - full_loop_B.t23 *
    0.08758368) + full_loop_B.Dynamics_tmp_b * 1.57650624) +
    full_loop_B.Dynamics_tmp_a * 0.78825312) + full_loop_B.Dynamics_tmp *
    0.08758368) - full_loop_B.Dynamics_tmp_o * 0.08758368) -
    (full_loop_B.TmpSignalConversionAtSFunct[9] *
     full_loop_B.TmpSignalConversionAtSFunct[9] * 0.72 + 1.0) *
    full_loop_B.TmpSignalConversionAtSFunct[9] * 145.708) + (sin
    (full_loop_P.wfPhi * full_loop_B.rtb_sincos_o1_idx_2 + full_loop_P.wpPhi) *
    full_loop_P.waPhi + full_loop_P.RollWave_Bias);

  // MATLAB Function: '<S3>/Forces and torques'
  full_loop_B.t48 *= full_loop_B.t52;
  full_loop_B.t21 *= full_loop_B.t55;

  // Sum: '<S18>/Sum1' incorporates:
  //   MATLAB Function: '<S3>/Forces and torques'
  //   Sin: '<S18>/Pitch Wave'
  //   Sin: '<S18>/Yaw Wave'

  full_loop_B.Dynamics[1] = (((((((((((((((full_loop_B.uDLookupTable1[4] *
    -0.1805 - full_loop_B.uDLookupTable1[5] * 0.1825) +
    full_loop_B.uDLookupTable1[6] * 0.1825) + full_loop_B.uDLookupTable1[7] *
    0.1805) + full_loop_B.rtb_sincos_o1_idx_0) + full_loop_B.rtb_sincos_o1_idx_1)
    + full_loop_B.t26) + full_loop_B.t27) + full_loop_B.ixk * 0.02919456) -
    full_loop_B.TmpSignalConversionAtSFunct[9] *
    full_loop_B.TmpSignalConversionAtSFunct[11] * 1.1442) + full_loop_B.t48 *
    0.78825312) - full_loop_B.t23 * 0.02919456) + full_loop_B.Dynamics_tmp *
    0.02919456) - full_loop_B.t21 * 1.57650624) - full_loop_B.Dynamics_tmp_o *
    0.02919456) - (full_loop_B.TmpSignalConversionAtSFunct[10] *
                   full_loop_B.TmpSignalConversionAtSFunct[10] * 0.72 + 1.0) *
    full_loop_B.TmpSignalConversionAtSFunct[10] * 145.708) + (sin
    (full_loop_P.wfTheta * full_loop_B.rtb_sincos_o1_idx_2 + full_loop_P.wpTheta)
    * full_loop_P.waTheta + full_loop_P.PitchWave_Bias);
  full_loop_B.Dynamics[2] = (((((((((68.3593446428504 *
    full_loop_B.uDLookupTable1[1] * -0.005 + 337.017803684019 *
    full_loop_B.uDLookupTable1[3] / 1000.0) + 338.74621769106147 *
    full_loop_B.uDLookupTable1[2] / 1000.0) - 340.08381319904072 *
    full_loop_B.uDLookupTable1[0] / 1000.0) +
    full_loop_B.TmpSignalConversionAtSFunct[9] *
    full_loop_B.TmpSignalConversionAtSFunct[10] * 0.9342) + full_loop_B.t48 *
    0.08758368) - full_loop_B.Dynamics_tmp_b * 0.05838912) -
    full_loop_B.Dynamics_tmp_a * 0.02919456) - full_loop_B.t21 * 0.17516736) -
    (full_loop_B.TmpSignalConversionAtSFunct[11] *
     full_loop_B.TmpSignalConversionAtSFunct[11] * 0.72 + 1.0) *
    full_loop_B.TmpSignalConversionAtSFunct[11] * 109.78) + (sin
    (full_loop_P.wfPsi * full_loop_B.rtb_sincos_o1_idx_2 + full_loop_P.wpPsi) *
    full_loop_P.waPsi + full_loop_P.YawWave_Bias);

  // Sum: '<S52>/Sum' incorporates:
  //   Integrator: '<S13>/p,q,r '
  //   Product: '<S55>/i x j'
  //   Product: '<S55>/j x k'
  //   Product: '<S55>/k x i'
  //   Product: '<S56>/i x k'
  //   Product: '<S56>/j x i'
  //   Product: '<S56>/k x j'

  full_loop_B.dv19[0] = full_loop_X.pqr_CSTATE[1] * full_loop_B.sincos_o2_b[2];
  full_loop_B.dv19[1] = full_loop_X.pqr_CSTATE[2] * full_loop_B.sincos_o2_b[0];
  full_loop_B.dv19[2] = full_loop_X.pqr_CSTATE[0] * full_loop_B.sincos_o2_b[1];
  full_loop_B.dv20[0] = full_loop_X.pqr_CSTATE[2] * full_loop_B.sincos_o2_b[1];
  full_loop_B.dv20[1] = full_loop_X.pqr_CSTATE[0] * full_loop_B.sincos_o2_b[2];
  full_loop_B.dv20[2] = full_loop_X.pqr_CSTATE[1] * full_loop_B.sincos_o2_b[0];
  for (full_loop_B.b_j = 0; full_loop_B.b_j < 3; full_loop_B.b_j++) {
    // Sum: '<S20>/Sum2' incorporates:
    //   Integrator: '<S13>/p,q,r '
    //   Product: '<S54>/Product'
    //   Sum: '<S52>/Sum'

    full_loop_B.sincos_o2_b[full_loop_B.b_j] =
      (full_loop_B.Dynamics[full_loop_B.b_j] -
       (full_loop_B.Selector1[full_loop_B.b_j + 6] * full_loop_X.pqr_CSTATE[2] +
        (full_loop_B.Selector1[full_loop_B.b_j + 3] * full_loop_X.pqr_CSTATE[1]
         + full_loop_B.Selector1[full_loop_B.b_j] * full_loop_X.pqr_CSTATE[0])))
      - (full_loop_B.dv19[full_loop_B.b_j] - full_loop_B.dv20[full_loop_B.b_j]);
  }

  // Product: '<S20>/Product2'
  rt_mrdivide_U1d1x3_U2d_9vOrDY_p(full_loop_B.sincos_o2_b, full_loop_B.Selector2,
    full_loop_B.Product2);

  // Sum: '<S13>/Sum' incorporates:
  //   Constant: '<S21>/Constant'
  //   Integrator: '<S13>/p,q,r '
  //   MATLAB Function: '<S3>/Forces and torques'
  //   Product: '<S13>/Product'
  //   Product: '<S57>/i x j'
  //   Product: '<S57>/j x k'
  //   Product: '<S57>/k x i'
  //   Product: '<S58>/i x k'
  //   Product: '<S58>/j x i'
  //   Product: '<S58>/k x j'
  //   Sin: '<S18>/X Wave'
  //   Sin: '<S18>/Y Wave'
  //   Sin: '<S18>/Z Wave'
  //   Sum: '<S18>/Sum'
  //   Sum: '<S22>/Sum'

  full_loop_B.Sum_b[0] = ((((((full_loop_B.t48 * 29.19456 - full_loop_B.t21 *
    58.38912) - full_loop_B.TmpSignalConversionAtSFunct[11] *
    full_loop_B.TmpSignalConversionAtSFunct[7] * 33.95) +
    full_loop_B.TmpSignalConversionAtSFunct[10] *
    full_loop_B.TmpSignalConversionAtSFunct[8] * 33.95) -
    (full_loop_B.TmpSignalConversionAtSFunct[6] *
     full_loop_B.TmpSignalConversionAtSFunct[6] * 0.72 + 1.0) *
    full_loop_B.TmpSignalConversionAtSFunct[6] * 59.88) +
    (((full_loop_B.uDLookupTable1[0] + full_loop_B.uDLookupTable1[1]) +
      full_loop_B.uDLookupTable1[2]) + full_loop_B.uDLookupTable1[3]) *
    1.4142135623730951 / 2.0) + (sin(full_loop_P.wfX *
    full_loop_B.rtb_sincos_o1_idx_2 + full_loop_P.wpX) * full_loop_P.waX +
    full_loop_P.XWave_Bias)) / full_loop_P.mass + (full_loop_B.ubvbwb[1] *
    full_loop_X.pqr_CSTATE[2] - full_loop_B.ubvbwb[2] * full_loop_X.pqr_CSTATE[1]);
  full_loop_B.Sum_b[1] = (((((((((full_loop_B.uDLookupTable1[0] -
    full_loop_B.uDLookupTable1[1]) + full_loop_B.uDLookupTable1[2]) -
    full_loop_B.uDLookupTable1[3]) * 1.4142135623730951 * -0.5 -
    full_loop_B.Dynamics_tmp_b * 58.38912) - full_loop_B.Dynamics_tmp_a *
    29.19456) + full_loop_B.TmpSignalConversionAtSFunct[11] *
    full_loop_B.TmpSignalConversionAtSFunct[6] * 33.95) -
    full_loop_B.TmpSignalConversionAtSFunct[9] *
    full_loop_B.TmpSignalConversionAtSFunct[8] * 33.95) -
    (full_loop_B.TmpSignalConversionAtSFunct[7] *
     full_loop_B.TmpSignalConversionAtSFunct[7] * 0.72 + 2.0) *
    full_loop_B.TmpSignalConversionAtSFunct[7] * 109.78) + (sin(full_loop_P.wfY *
    full_loop_B.rtb_sincos_o1_idx_2 + full_loop_P.wpY) * full_loop_P.waY +
    full_loop_P.YWave_Bias)) / full_loop_P.mass + (full_loop_B.ubvbwb[2] *
    full_loop_X.pqr_CSTATE[0] - full_loop_B.ubvbwb[0] * full_loop_X.pqr_CSTATE[2]);
  full_loop_B.Sum_b[2] = ((((((((((((((((((((((full_loop_B.uDLookupTable1[4] -
    full_loop_B.uDLookupTable1[5]) + full_loop_B.uDLookupTable1[6]) -
    full_loop_B.uDLookupTable1[7]) - full_loop_B.Sum_a_e *
    full_loop_B.Product3_bd * 58.38912) + full_loop_B.Sum_a_e *
    full_loop_B.Product2_fy * 29.19456) - full_loop_B.rtb_sincos_o2_idx_2 *
    full_loop_B.t17 * 29.19456) + full_loop_B.rtb_sincos_o2_idx_0 *
    full_loop_B.t42 * 29.19456) + full_loop_B.Sum_a_e * full_loop_B.t20 *
    29.19456) + full_loop_B.rtb_sincos_o2_idx_2 * full_loop_B.t19 * 29.19456) -
    full_loop_B.rtb_sincos_o2_idx_0 * full_loop_B.t18 * 29.19456) -
    full_loop_B.rtb_sincos_o2_idx_1 * full_loop_B.t42 * 29.19456) +
    full_loop_B.Product2_h5 * full_loop_B.t17 * 29.19456) +
    full_loop_B.Product3_bd * full_loop_B.Product2_fy * 29.19456) +
    full_loop_B.rtb_sincos_o2_idx_1 * full_loop_B.t18 * 29.19456) -
    full_loop_B.Product2_h5 * full_loop_B.t19 * 29.19456) +
    full_loop_B.Product3_bd * full_loop_B.t20 * 29.19456) +
    full_loop_B.TmpSignalConversionAtSFunct[9] *
    full_loop_B.TmpSignalConversionAtSFunct[7] * 33.95) -
    full_loop_B.TmpSignalConversionAtSFunct[10] *
    full_loop_B.TmpSignalConversionAtSFunct[6] * 33.95) -
    (full_loop_B.TmpSignalConversionAtSFunct[8] *
     full_loop_B.TmpSignalConversionAtSFunct[8] * 0.72 + 3.0) *
    full_loop_B.TmpSignalConversionAtSFunct[8] * 145.708) - full_loop_B.Sum_d *
    full_loop_B.Sum_d * 29.19456) - full_loop_B.Product8 * full_loop_B.Product8 *
    29.19456) + (sin(full_loop_P.wfZ * full_loop_B.rtb_sincos_o1_idx_2 +
                     full_loop_P.wpZ) * full_loop_P.waZ + full_loop_P.ZWave_Bias))
    / full_loop_P.mass + (full_loop_B.ubvbwb[0] * full_loop_X.pqr_CSTATE[1] -
    full_loop_B.ubvbwb[1] * full_loop_X.pqr_CSTATE[0]);

  // Product: '<S26>/Product'
  for (full_loop_B.b_j = 0; full_loop_B.b_j < 3; full_loop_B.b_j++) {
    full_loop_B.Product[full_loop_B.b_j] = 0.0;
    full_loop_B.Product[full_loop_B.b_j] +=
      full_loop_B.Transpose[full_loop_B.b_j] * full_loop_B.ubvbwb[0];
    full_loop_B.Product[full_loop_B.b_j] +=
      full_loop_B.Transpose[full_loop_B.b_j + 3] * full_loop_B.ubvbwb[1];
    full_loop_B.Product[full_loop_B.b_j] +=
      full_loop_B.Transpose[full_loop_B.b_j + 6] * full_loop_B.ubvbwb[2];
  }

  // End of Product: '<S26>/Product'

  // Sum: '<S12>/Sum' incorporates:
  //   Product: '<S12>/Product'
  //   Product: '<S12>/Product1'
  //   Product: '<S12>/Product2'
  //   Product: '<S12>/Product3'

  full_loop_B.Sum_a_e = ((full_loop_B.q[0] * full_loop_B.q[0] + full_loop_B.q[1]
    * full_loop_B.q[1]) + full_loop_B.q[2] * full_loop_B.q[2]) + full_loop_B.q[3]
    * full_loop_B.q[3];
  if (rtmIsMajorTimeStep(full_loop_M) &&
      full_loop_M->Timing.TaskCounters.TID[3] == 0) {
    // MATLAB Function: '<S2>/MATLAB Function' incorporates:
    //   Constant: '<S2>/ '
    //   Constant: '<S2>/  '
    //   Constant: '<S7>/Constant'
    //   Gain: '<S2>/Gain'
    //   Gain: '<S2>/Gain1'
    //   Gain: '<S2>/Gain2'
    //   Integrator: '<S13>/xe,ye,ze'
    //   Product: '<S10>/Divide'
    //   Product: '<S10>/Divide1'
    //   Product: '<S10>/Divide2'
    //   Product: '<S10>/Divide3'
    //   UnaryMinus: '<S11>/Unary Minus'
    //   UnaryMinus: '<S11>/Unary Minus1'
    //   UnaryMinus: '<S11>/Unary Minus2'

    full_loop_B.msg = full_loop_P.Constant_Value;
    full_loop_B.msg.ModelName[0] = full_loop_P.modelName[0];
    full_loop_B.msg.ModelName[1] = full_loop_P.modelName[1];
    full_loop_B.msg.ModelName[2] = full_loop_P.modelName[2];
    full_loop_B.msg.ModelName[3] = full_loop_P.modelName[3];
    full_loop_B.msg.ModelName_SL_Info.CurrentLength = 4U;
    for (full_loop_B.ix = 0; full_loop_B.ix < 5; full_loop_B.ix++) {
      full_loop_B.msg.ReferenceFrame[full_loop_B.ix] =
        full_loop_P.referenceFrame[full_loop_B.ix];
    }

    full_loop_B.msg.ReferenceFrame_SL_Info.CurrentLength = 5U;
    full_loop_B.msg.Pose.Position.X = full_loop_P.Gain2_Gain_a *
      full_loop_X.xeyeze_CSTATE[0];
    full_loop_B.msg.Pose.Position.Y = full_loop_P.Gain1_Gain_p *
      full_loop_X.xeyeze_CSTATE[1];
    full_loop_B.msg.Pose.Position.Z = full_loop_P.Gain_Gain_l0 *
      full_loop_X.xeyeze_CSTATE[2];
    full_loop_B.msg.Pose.Orientation.X = -full_loop_B.q[1] / full_loop_B.Sum_a_e;
    full_loop_B.msg.Pose.Orientation.Y = -full_loop_B.q[2] / full_loop_B.Sum_a_e;
    full_loop_B.msg.Pose.Orientation.Z = -full_loop_B.q[3] / full_loop_B.Sum_a_e;
    full_loop_B.msg.Pose.Orientation.W = full_loop_B.q[0] / full_loop_B.Sum_a_e;

    // End of MATLAB Function: '<S2>/MATLAB Function'

    // Outputs for Atomic SubSystem: '<S2>/Publish'
    // MATLABSystem: '<S9>/SinkBlock'
    Pub_full_loop_206.publish(&full_loop_B.msg);

    // End of Outputs for SubSystem: '<S2>/Publish'
  }

  if (rtmIsMajorTimeStep(full_loop_M)) {
    if (rtmIsMajorTimeStep(full_loop_M) &&
        full_loop_M->Timing.TaskCounters.TID[4] == 0) {
      // Update for Memory: '<S70>/LastPcov'
      memcpy(&full_loop_DW.LastPcov_PreviousInput[0], &full_loop_B.Pk1[0], 400U *
             sizeof(real_T));

      // Update for Memory: '<S70>/last_x'
      memcpy(&full_loop_DW.last_x_PreviousInput[0], &full_loop_B.xk1[0], 20U *
             sizeof(real_T));

      // Update for UnitDelay: '<S70>/last_mv'
      memcpy(&full_loop_DW.last_mv_DSTATE[0], &full_loop_B.u[0], sizeof(real_T) <<
             3U);
    }

    if (rtmIsMajorTimeStep(full_loop_M) &&
        full_loop_M->Timing.TaskCounters.TID[1] == 0) {
      // Update for DiscreteIntegrator: '<S5>/Discrete-Time Integrator1'
      full_loop_DW.DiscreteTimeIntegrator1_DSTATE[0] =
        full_loop_P.DiscreteTimeIntegrator1_gainval * full_loop_B.ubvbwb[0] +
        full_loop_B.BodyPosition[0];
      full_loop_DW.DiscreteTimeIntegrator1_DSTATE[1] =
        full_loop_P.DiscreteTimeIntegrator1_gainval * full_loop_B.ubvbwb[1] +
        full_loop_B.BodyPosition[1];
      full_loop_DW.DiscreteTimeIntegrator1_DSTATE[2] =
        full_loop_P.DiscreteTimeIntegrator1_gainval * full_loop_B.ubvbwb[2] +
        full_loop_B.BodyPosition[2];
    }

    if (rtmIsMajorTimeStep(full_loop_M) &&
        full_loop_M->Timing.TaskCounters.TID[2] == 0) {
      // Update for RandomNumber: '<S65>/White Noise'
      full_loop_DW.NextOutput = rt_nrand_Upu32_Yd_f_pw_snf
        (&full_loop_DW.RandSeed) * full_loop_P.WhiteNoise_StdDev +
        full_loop_P.WhiteNoise_Mean;
    }

    // Update for Integrator: '<S19>/q0 q1 q2 q3'
    full_loop_DW.q0q1q2q3_IWORK = 0;
    if (rtmIsMajorTimeStep(full_loop_M) &&
        full_loop_M->Timing.TaskCounters.TID[1] == 0) {
      // Update for Memory: '<S59>/Memory'
      full_loop_DW.Memory_PreviousInput[0] = full_loop_B.q[0];
      full_loop_DW.Memory_PreviousInput[1] = full_loop_B.q[1];
      full_loop_DW.Memory_PreviousInput[2] = full_loop_B.q[2];
      full_loop_DW.Memory_PreviousInput[3] = full_loop_B.q[3];

      // Update for Memory: '<S4>/Memory5'
      full_loop_DW.Memory5_PreviousInput[0] = full_loop_B.tcount[0];
      full_loop_DW.Memory5_PreviousInput[1] = full_loop_B.tcount[1];
      full_loop_DW.Memory5_PreviousInput[2] = full_loop_B.tcount[2];

      // Update for Memory: '<S4>/Memory3'
      memcpy(&full_loop_DW.Memory3_PreviousInput[0], &full_loop_B.checkedPose[0],
             12U * sizeof(real_T));

      // Update for DiscreteIntegrator: '<S5>/Discrete-Time Integrator'
      full_loop_DW.DiscreteTimeIntegrator_DSTATE[0] =
        full_loop_P.DiscreteTimeIntegrator_gainval * full_loop_B.Sum +
        full_loop_B.WorldPosition[0];
      full_loop_DW.DiscreteTimeIntegrator_DSTATE[1] =
        full_loop_P.DiscreteTimeIntegrator_gainval * full_loop_B.Sum_g +
        full_loop_B.WorldPosition[1];
      full_loop_DW.DiscreteTimeIntegrator_DSTATE[2] =
        full_loop_P.DiscreteTimeIntegrator_gainval * full_loop_B.Sum_e +
        full_loop_B.WorldPosition[2];

      // Update for Memory: '<S6>/Memory'
      full_loop_DW.Memory_PreviousInput_p[0] = full_loop_B.y[0];
      full_loop_DW.Memory_PreviousInput_p[1] = full_loop_B.y[1];
      full_loop_DW.Memory_PreviousInput_p[2] = full_loop_B.y[2];

      // Update for Memory: '<S4>/Memory'
      memcpy(&full_loop_DW.Memory_PreviousInput_m[0], &full_loop_B.Sum_ae[0],
             sizeof(real_T) << 3U);
    }

    if (rtmIsMajorTimeStep(full_loop_M) &&
        full_loop_M->Timing.TaskCounters.TID[2] == 0) {
      // Update for RandomNumber: '<S66>/White Noise'
      full_loop_DW.NextOutput_b = rt_nrand_Upu32_Yd_f_pw_snf
        (&full_loop_DW.RandSeed_k) * full_loop_P.WhiteNoise_StdDev_a +
        full_loop_P.WhiteNoise_Mean_m;
    }

    if (rtmIsMajorTimeStep(full_loop_M) &&
        full_loop_M->Timing.TaskCounters.TID[4] == 0) {
      // Update for Memory: '<S70>/Memory'
      full_loop_DW.Memory_PreviousInput_d[0] = full_loop_B.iAout[0];
      full_loop_DW.Memory_PreviousInput_d[1] = full_loop_B.iAout[1];
      full_loop_DW.Memory_PreviousInput_d[2] = full_loop_B.iAout[2];
      full_loop_DW.Memory_PreviousInput_d[3] = full_loop_B.iAout[3];
    }
  }                                    // end MajorTimeStep

  if (rtmIsMajorTimeStep(full_loop_M)) {
    rt_ertODEUpdateContinuousStates(&full_loop_M->solverInfo);

    // Update absolute time for base rate
    // The "clockTick0" counts the number of times the code of this task has
    //  been executed. The absolute time is the multiplication of "clockTick0"
    //  and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
    //  overflow during the application lifespan selected.

    ++full_loop_M->Timing.clockTick0;
    full_loop_M->Timing.t[0] = rtsiGetSolverStopTime(&full_loop_M->solverInfo);

    {
      // Update absolute timer for sample time: [0.005s, 0.0s]
      // The "clockTick1" counts the number of times the code of this task has
      //  been executed. The resolution of this integer timer is 0.005, which is the step size
      //  of the task. Size of "clockTick1" ensures timer will not overflow during the
      //  application lifespan selected.

      full_loop_M->Timing.clockTick1++;
    }

    if (rtmIsMajorTimeStep(full_loop_M) &&
        full_loop_M->Timing.TaskCounters.TID[4] == 0) {
      // Update absolute timer for sample time: [0.1s, 0.0s]
      // The "clockTick4" counts the number of times the code of this task has
      //  been executed. The resolution of this integer timer is 0.1, which is the step size
      //  of the task. Size of "clockTick4" ensures timer will not overflow during the
      //  application lifespan selected.

      full_loop_M->Timing.clockTick4++;
    }

    rate_scheduler();
  }                                    // end MajorTimeStep
}

// Derivatives for root system: '<Root>'
void full_loop_derivatives(void)
{
  XDot_full_loop_T *_rtXdot;
  _rtXdot = ((XDot_full_loop_T *) full_loop_M->derivs);

  // Derivatives for Integrator: '<S13>/ub,vb,wb'
  _rtXdot->ubvbwb_CSTATE[0] = full_loop_B.Sum_b[0];
  _rtXdot->ubvbwb_CSTATE[1] = full_loop_B.Sum_b[1];
  _rtXdot->ubvbwb_CSTATE[2] = full_loop_B.Sum_b[2];

  // Derivatives for Integrator: '<S19>/q0 q1 q2 q3'
  _rtXdot->q0q1q2q3_CSTATE[0] = full_loop_B.TmpSignalConversionAtq0q1q2q3_c[0];
  _rtXdot->q0q1q2q3_CSTATE[1] = full_loop_B.TmpSignalConversionAtq0q1q2q3_c[1];
  _rtXdot->q0q1q2q3_CSTATE[2] = full_loop_B.TmpSignalConversionAtq0q1q2q3_c[2];
  _rtXdot->q0q1q2q3_CSTATE[3] = full_loop_B.TmpSignalConversionAtq0q1q2q3_c[3];

  // Derivatives for Integrator: '<S13>/p,q,r '
  _rtXdot->pqr_CSTATE[0] = full_loop_B.Product2[0];

  // Derivatives for Integrator: '<S15>/Integrator'
  _rtXdot->Integrator_CSTATE[0] = full_loop_B.ubvbwb[0];

  // Derivatives for Integrator: '<S13>/xe,ye,ze'
  _rtXdot->xeyeze_CSTATE[0] = full_loop_B.Product[0];

  // Derivatives for Integrator: '<S13>/p,q,r '
  _rtXdot->pqr_CSTATE[1] = full_loop_B.Product2[1];

  // Derivatives for Integrator: '<S15>/Integrator'
  _rtXdot->Integrator_CSTATE[1] = full_loop_B.ubvbwb[1];

  // Derivatives for Integrator: '<S13>/xe,ye,ze'
  _rtXdot->xeyeze_CSTATE[1] = full_loop_B.Product[1];

  // Derivatives for Integrator: '<S13>/p,q,r '
  _rtXdot->pqr_CSTATE[2] = full_loop_B.Product2[2];

  // Derivatives for Integrator: '<S15>/Integrator'
  _rtXdot->Integrator_CSTATE[2] = full_loop_B.ubvbwb[2];

  // Derivatives for Integrator: '<S13>/xe,ye,ze'
  _rtXdot->xeyeze_CSTATE[2] = full_loop_B.Product[2];
}

// Model initialize function
void full_loop_initialize(void)
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));

  {
    // Setup solver object
    rtsiSetSimTimeStepPtr(&full_loop_M->solverInfo,
                          &full_loop_M->Timing.simTimeStep);
    rtsiSetTPtr(&full_loop_M->solverInfo, &rtmGetTPtr(full_loop_M));
    rtsiSetStepSizePtr(&full_loop_M->solverInfo, &full_loop_M->Timing.stepSize0);
    rtsiSetdXPtr(&full_loop_M->solverInfo, &full_loop_M->derivs);
    rtsiSetContStatesPtr(&full_loop_M->solverInfo, (real_T **)
                         &full_loop_M->contStates);
    rtsiSetNumContStatesPtr(&full_loop_M->solverInfo,
      &full_loop_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&full_loop_M->solverInfo,
      &full_loop_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&full_loop_M->solverInfo,
      &full_loop_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&full_loop_M->solverInfo,
      &full_loop_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&full_loop_M->solverInfo, (&rtmGetErrorStatus
      (full_loop_M)));
    rtsiSetRTModelPtr(&full_loop_M->solverInfo, full_loop_M);
  }

  rtsiSetSimTimeStep(&full_loop_M->solverInfo, MAJOR_TIME_STEP);
  full_loop_M->intgData.y = full_loop_M->odeY;
  full_loop_M->intgData.f[0] = full_loop_M->odeF[0];
  full_loop_M->intgData.f[1] = full_loop_M->odeF[1];
  full_loop_M->intgData.f[2] = full_loop_M->odeF[2];
  full_loop_M->contStates = ((X_full_loop_T *) &full_loop_X);
  rtsiSetSolverData(&full_loop_M->solverInfo, static_cast<void *>
                    (&full_loop_M->intgData));
  rtsiSetSolverName(&full_loop_M->solverInfo,"ode3");
  rtmSetTPtr(full_loop_M, &full_loop_M->Timing.tArray[0]);
  full_loop_M->Timing.stepSize0 = 0.005;
  rtmSetFirstInitCond(full_loop_M, 1);

  {
    uint32_T tseed;
    int32_T r;
    int32_T t;
    static const real_T tmp[48] = { 0.70710678118654757, -0.70710678118654757,
      0.0, 0.038890872965260115, 0.038890872965260115, -0.34008381319904074,
      0.70710678118654757, 0.70710678118654757, 0.0, -0.038890872965260115,
      0.038890872965260115, -0.34179672321425203, 0.70710678118654757,
      -0.70710678118654757, 0.0, 0.038890872965260115, 0.038890872965260115,
      0.3387462176910615, 0.70710678118654757, 0.70710678118654757, 0.0,
      -0.038890872965260115, 0.038890872965260115, 0.337017803684019, 0.0, 0.0,
      1.0, 0.162, -0.1805, 0.0, 0.0, 0.0, -1.0, -0.162, -0.1825, 0.0, 0.0, 0.0,
      1.0, -0.156, 0.1825, 0.0, 0.0, 0.0, -1.0, 0.156, 0.1805, 0.0 };

    static const real_T tmp_0[8] = { 0.0, 0.0, 0.0, 0.0, -7.1, 6.94, -7.49, 7.65
    };

    static const char_T tmp_1[23] = { '/', 'g', 'a', 'z', 'e', 'b', 'o', '/',
      's', 'e', 't', '_', 'm', 'o', 'd', 'e', 'l', '_', 's', 't', 'a', 't', 'e'
    };

    // Start for If: '<S46>/If'
    full_loop_DW.If_ActiveSubsystem = -1;

    // Start for If: '<S120>/If'
    full_loop_DW.If_ActiveSubsystem_j = -1;

    // Start for FromWorkspace: '<S6>/From Workspace1'
    {
      static real_T pTimeValues0[] = { 0.0, 0.1, 0.2, 0.30000000000000004, 0.4,
        0.5, 0.60000000000000009, 0.70000000000000007, 0.8, 0.9, 1.0, 1.1,
        1.2000000000000002, 1.3, 1.4000000000000001, 1.5, 1.6,
        1.7000000000000002, 1.8, 1.9000000000000001, 2.0, 2.1, 2.2,
        2.3000000000000003, 2.4000000000000004, 2.5, 2.6, 2.7,
        2.8000000000000003, 2.9000000000000004, 3.0, 3.1, 3.2,
        3.3000000000000003, 3.4000000000000004, 3.5, 3.6, 3.7,
        3.8000000000000003, 3.9000000000000004, 4.0, 4.1000000000000005, 4.2,
        4.3, 4.4, 4.5, 4.6000000000000005, 4.7, 4.8000000000000007, 4.9, 5.0,
        5.1000000000000005, 5.2, 5.3000000000000007, 5.4, 5.5,
        5.6000000000000005, 5.7, 5.8000000000000007, 5.9, 6.0,
        6.1000000000000005, 6.2, 6.3000000000000007, 6.4, 6.5,
        6.6000000000000005, 6.7, 6.8000000000000007, 6.9, 7.0,
        7.1000000000000005, 7.2, 7.3000000000000007, 7.4, 7.5,
        7.6000000000000005, 7.7, 7.8000000000000007, 7.9, 8.0, 8.1,
        8.2000000000000011, 8.3, 8.4, 8.5, 8.6, 8.7000000000000011, 8.8, 8.9,
        9.0, 9.1, 9.2000000000000011, 9.3, 9.4, 9.5, 9.6000000000000014,
        9.7000000000000011, 9.8, 9.9, 10.0, 10.100000000000001,
        10.200000000000001, 10.3, 10.4, 10.5, 10.600000000000001,
        10.700000000000001, 10.8, 10.9, 11.0, 11.100000000000001,
        11.200000000000001, 11.3, 11.4, 11.5, 11.600000000000001,
        11.700000000000001, 11.8, 11.9, 12.0, 12.100000000000001,
        12.200000000000001, 12.3, 12.4, 12.5, 12.600000000000001,
        12.700000000000001, 12.8, 12.9, 13.0, 13.100000000000001,
        13.200000000000001, 13.3, 13.4, 13.5, 13.600000000000001,
        13.700000000000001, 13.8, 13.9, 14.0, 14.100000000000001,
        14.200000000000001, 14.3, 14.4, 14.5, 14.600000000000001,
        14.700000000000001, 14.8, 14.9, 15.0, 15.100000000000001,
        15.200000000000001, 15.3, 15.4, 15.5, 15.600000000000001,
        15.700000000000001, 15.8, 15.9, 16.0, 16.1, 16.2, 16.3,
        16.400000000000002, 16.5, 16.6, 16.7, 16.8, 16.900000000000002, 17.0,
        17.1, 17.2, 17.3, 17.400000000000002, 17.5, 17.6, 17.7, 17.8,
        17.900000000000002, 18.0, 18.1, 18.2, 18.3, 18.400000000000002, 18.5,
        18.6, 18.7, 18.8, 18.900000000000002, 19.0, 19.1, 19.200000000000003,
        19.3, 19.400000000000002, 19.5, 19.6, 19.700000000000003, 19.8,
        19.900000000000002, 20.0, 20.1, 20.200000000000003, 20.3,
        20.400000000000002, 20.5, 20.6, 20.700000000000003, 20.8,
        20.900000000000002, 21.0, 21.1, 21.200000000000003, 21.3,
        21.400000000000002, 21.5, 21.6, 21.700000000000003, 21.8,
        21.900000000000002, 22.0, 22.1, 22.200000000000003, 22.3,
        22.400000000000002, 22.5, 22.6, 22.700000000000003, 22.8,
        22.900000000000002, 23.0, 23.1, 23.200000000000003, 23.3,
        23.400000000000002, 23.5, 23.6, 23.700000000000003, 23.8,
        23.900000000000002, 24.0, 24.1, 24.200000000000003, 24.3,
        24.400000000000002, 24.5, 24.6, 24.700000000000003, 24.8,
        24.900000000000002, 25.0, 25.1, 25.200000000000003, 25.3,
        25.400000000000002, 25.5, 25.6, 25.700000000000003, 25.8,
        25.900000000000002, 26.0, 26.1, 26.200000000000003, 26.3,
        26.400000000000002, 26.5, 26.6, 26.700000000000003, 26.8,
        26.900000000000002, 27.0, 27.1, 27.200000000000003, 27.3,
        27.400000000000002, 27.5, 27.6, 27.700000000000003, 27.8,
        27.900000000000002, 28.0, 28.1, 28.200000000000003, 28.3,
        28.400000000000002, 28.5, 28.6, 28.700000000000003, 28.8,
        28.900000000000002, 29.0, 29.1, 29.200000000000003, 29.3,
        29.400000000000002, 29.5, 29.6, 29.700000000000003, 29.8,
        29.900000000000002, 30.0, 30.1, 30.200000000000003, 30.3,
        30.400000000000002, 30.5, 30.6, 30.700000000000003, 30.8,
        30.900000000000002, 31.0, 31.1, 31.200000000000003, 31.3,
        31.400000000000002, 31.5, 31.6, 31.700000000000003, 31.8,
        31.900000000000002, 32.0, 32.1, 32.2, 32.300000000000004, 32.4, 32.5,
        32.6, 32.7, 32.800000000000004, 32.9, 33.0, 33.1, 33.2,
        33.300000000000004, 33.4, 33.5, 33.6, 33.7, 33.800000000000004, 33.9,
        34.0, 34.1, 34.2, 34.300000000000004, 34.4, 34.5, 34.6, 34.7,
        34.800000000000004, 34.9, 35.0, 35.1, 35.2, 35.300000000000004, 35.4,
        35.5, 35.6, 35.7, 35.800000000000004, 35.9, 36.0, 36.1, 36.2,
        36.300000000000004, 36.4, 36.5, 36.6, 36.7, 36.800000000000004, 36.9,
        37.0, 37.1, 37.2, 37.300000000000004, 37.4, 37.5, 37.6, 37.7,
        37.800000000000004, 37.9, 38.0, 38.1, 38.2, 38.300000000000004,
        38.400000000000006, 38.5, 38.6, 38.7, 38.800000000000004,
        38.900000000000006, 39.0, 39.1, 39.2, 39.300000000000004,
        39.400000000000006, 39.5, 39.6, 39.7, 39.800000000000004,
        39.900000000000006, 40.0, 40.1, 40.2, 40.300000000000004,
        40.400000000000006, 40.5, 40.6, 40.7, 40.800000000000004,
        40.900000000000006, 41.0, 41.1, 41.2, 41.300000000000004,
        41.400000000000006, 41.5, 41.6, 41.7, 41.800000000000004,
        41.900000000000006, 42.0, 42.1, 42.2, 42.300000000000004,
        42.400000000000006, 42.5, 42.6, 42.7, 42.800000000000004,
        42.900000000000006, 43.0, 43.1, 43.2, 43.300000000000004,
        43.400000000000006, 43.5, 43.6, 43.7, 43.800000000000004,
        43.900000000000006, 44.0, 44.1, 44.2, 44.300000000000004,
        44.400000000000006, 44.5, 44.6, 44.7, 44.800000000000004,
        44.900000000000006, 45.0, 45.1, 45.2, 45.300000000000004,
        45.400000000000006, 45.5, 45.6, 45.7, 45.800000000000004,
        45.900000000000006, 46.0, 46.1, 46.2, 46.300000000000004,
        46.400000000000006, 46.5, 46.6, 46.7, 46.800000000000004,
        46.900000000000006, 47.0, 47.1, 47.2, 47.300000000000004,
        47.400000000000006, 47.5, 47.6, 47.7, 47.800000000000004,
        47.900000000000006, 48.0, 48.1, 48.2, 48.300000000000004,
        48.400000000000006, 48.5, 48.6, 48.7, 48.800000000000004,
        48.900000000000006, 49.0, 49.1, 49.2, 49.300000000000004,
        49.400000000000006, 49.5, 49.6, 49.7, 49.800000000000004,
        49.900000000000006, 50.0, 50.1, 50.2, 50.300000000000004,
        50.400000000000006, 50.5, 50.6, 50.7, 50.800000000000004,
        50.900000000000006, 51.0, 51.1, 51.2, 51.300000000000004,
        51.400000000000006, 51.5, 51.6, 51.7, 51.800000000000004,
        51.900000000000006, 52.0, 52.1, 52.2, 52.300000000000004,
        52.400000000000006, 52.5, 52.6, 52.7, 52.800000000000004,
        52.900000000000006, 53.0, 53.1, 53.2, 53.300000000000004,
        53.400000000000006, 53.5, 53.6, 53.7, 53.800000000000004,
        53.900000000000006, 54.0, 54.1, 54.2, 54.300000000000004,
        54.400000000000006, 54.5, 54.6, 54.7, 54.800000000000004,
        54.900000000000006, 55.0, 55.1, 55.2, 55.300000000000004,
        55.400000000000006, 55.5, 55.6, 55.7, 55.800000000000004,
        55.900000000000006, 56.0, 56.1, 56.2, 56.300000000000004,
        56.400000000000006, 56.5, 56.6, 56.7, 56.800000000000004,
        56.900000000000006, 57.0, 57.1, 57.2, 57.300000000000004,
        57.400000000000006, 57.5, 57.6, 57.7, 57.800000000000004,
        57.900000000000006, 58.0, 58.1, 58.2, 58.300000000000004,
        58.400000000000006, 58.5, 58.6, 58.7, 58.800000000000004,
        58.900000000000006, 59.0, 59.1, 59.2, 59.300000000000004,
        59.400000000000006, 59.5, 59.6, 59.7, 59.800000000000004,
        59.900000000000006, 60.0, 60.1, 60.2, 60.300000000000004,
        60.400000000000006, 60.5, 60.6, 60.7, 60.800000000000004,
        60.900000000000006, 61.0, 61.1, 61.2, 61.300000000000004,
        61.400000000000006, 61.5, 61.6, 61.7, 61.800000000000004,
        61.900000000000006, 62.0, 62.1, 62.2, 62.300000000000004,
        62.400000000000006, 62.5, 62.6, 62.7, 62.800000000000004,
        62.900000000000006, 63.0, 63.1, 63.2, 63.300000000000004,
        63.400000000000006, 63.5, 63.6, 63.7, 63.800000000000004,
        63.900000000000006, 64.0, 64.100000000000009, 64.2, 64.3, 64.4, 64.5,
        64.600000000000009, 64.7, 64.8, 64.9, 65.0, 65.100000000000009, 65.2,
        65.3, 65.4, 65.5, 65.600000000000009, 65.7, 65.8, 65.9, 66.0,
        66.100000000000009, 66.2, 66.3, 66.4, 66.5, 66.600000000000009, 66.7,
        66.8, 66.9, 67.0, 67.100000000000009, 67.2, 67.3, 67.4, 67.5,
        67.600000000000009, 67.7, 67.8, 67.9, 68.0, 68.100000000000009, 68.2,
        68.3, 68.4, 68.5, 68.600000000000009, 68.7, 68.8, 68.9, 69.0,
        69.100000000000009, 69.2, 69.3, 69.4, 69.5, 69.600000000000009, 69.7,
        69.8, 69.9, 70.0, 70.100000000000009, 70.2, 70.3, 70.4, 70.5,
        70.600000000000009, 70.7, 70.8, 70.9, 71.0, 71.100000000000009, 71.2,
        71.3, 71.4, 71.5, 71.600000000000009, 71.7, 71.8, 71.9, 72.0,
        72.100000000000009, 72.2, 72.3, 72.4, 72.5, 72.600000000000009, 72.7,
        72.8, 72.9, 73.0, 73.100000000000009, 73.2, 73.3, 73.4, 73.5,
        73.600000000000009, 73.7, 73.8, 73.9, 74.0, 74.100000000000009, 74.2,
        74.3, 74.4, 74.5, 74.600000000000009, 74.7, 74.8, 74.9, 75.0,
        75.100000000000009, 75.2, 75.3, 75.4, 75.5, 75.600000000000009, 75.7,
        75.8, 75.9, 76.0, 76.100000000000009, 76.2, 76.3, 76.4, 76.5,
        76.600000000000009, 76.7, 76.800000000000011, 76.9, 77.0,
        77.100000000000009, 77.2, 77.300000000000011, 77.4, 77.5,
        77.600000000000009, 77.7, 77.800000000000011, 77.9, 78.0,
        78.100000000000009, 78.2, 78.300000000000011, 78.4, 78.5,
        78.600000000000009, 78.7, 78.800000000000011, 78.9, 79.0,
        79.100000000000009, 79.2, 79.300000000000011, 79.4, 79.5,
        79.600000000000009, 79.7, 79.800000000000011, 79.9, 80.0,
        80.100000000000009, 80.2, 80.300000000000011, 80.4, 80.5,
        80.600000000000009, 80.7, 80.800000000000011, 80.9, 81.0,
        81.100000000000009, 81.2, 81.300000000000011, 81.4, 81.5,
        81.600000000000009, 81.7, 81.800000000000011, 81.9, 82.0,
        82.100000000000009, 82.2, 82.300000000000011, 82.4, 82.5,
        82.600000000000009, 82.7, 82.800000000000011, 82.9, 83.0,
        83.100000000000009, 83.2, 83.300000000000011, 83.4, 83.5,
        83.600000000000009, 83.7, 83.800000000000011, 83.9, 84.0,
        84.100000000000009, 84.2, 84.300000000000011, 84.4, 84.5,
        84.600000000000009, 84.7, 84.800000000000011, 84.9, 85.0,
        85.100000000000009, 85.2, 85.300000000000011, 85.4, 85.5,
        85.600000000000009, 85.7, 85.800000000000011, 85.9, 86.0,
        86.100000000000009, 86.2, 86.300000000000011, 86.4, 86.5,
        86.600000000000009, 86.7, 86.800000000000011, 86.9, 87.0,
        87.100000000000009, 87.2, 87.300000000000011, 87.4, 87.5,
        87.600000000000009, 87.7, 87.800000000000011, 87.9, 88.0,
        88.100000000000009, 88.2, 88.300000000000011, 88.4, 88.5,
        88.600000000000009, 88.7, 88.800000000000011, 88.9, 89.0,
        89.100000000000009, 89.2, 89.300000000000011, 89.4, 89.5,
        89.600000000000009, 89.7, 89.800000000000011, 89.9, 90.0,
        90.100000000000009, 90.2, 90.300000000000011, 90.4, 90.5,
        90.600000000000009, 90.7, 90.800000000000011, 90.9, 91.0,
        91.100000000000009, 91.2, 91.300000000000011, 91.4, 91.5,
        91.600000000000009, 91.7, 91.800000000000011, 91.9, 92.0,
        92.100000000000009, 92.2, 92.300000000000011, 92.4, 92.5,
        92.600000000000009, 92.7, 92.800000000000011, 92.9, 93.0,
        93.100000000000009, 93.2, 93.300000000000011, 93.4, 93.5,
        93.600000000000009, 93.7, 93.800000000000011, 93.9, 94.0,
        94.100000000000009, 94.2, 94.300000000000011, 94.4, 94.5,
        94.600000000000009, 94.7, 94.800000000000011, 94.9, 95.0,
        95.100000000000009, 95.2, 95.300000000000011, 95.4, 95.5,
        95.600000000000009, 95.7, 95.800000000000011, 95.9, 96.0,
        96.100000000000009, 96.2, 96.300000000000011, 96.4, 96.5,
        96.600000000000009, 96.7, 96.800000000000011, 96.9, 97.0,
        97.100000000000009, 97.2, 97.300000000000011, 97.4, 97.5,
        97.600000000000009, 97.7, 97.800000000000011, 97.9, 98.0,
        98.100000000000009, 98.2, 98.300000000000011, 98.4, 98.5,
        98.600000000000009, 98.7, 98.800000000000011, 98.9, 99.0,
        99.100000000000009, 99.2, 99.300000000000011, 99.4, 99.5,
        99.600000000000009, 99.7, 99.800000000000011, 99.9, 100.0,
        100.10000000000001, 100.2, 100.30000000000001, 100.4, 100.5,
        100.60000000000001, 100.7, 100.80000000000001, 100.9, 101.0,
        101.10000000000001, 101.2, 101.30000000000001, 101.4, 101.5,
        101.60000000000001, 101.7, 101.80000000000001, 101.9, 102.0,
        102.10000000000001, 102.2, 102.30000000000001, 102.4, 102.5,
        102.60000000000001, 102.7, 102.80000000000001, 102.9, 103.0,
        103.10000000000001, 103.2, 103.30000000000001, 103.4, 103.5,
        103.60000000000001, 103.7, 103.80000000000001, 103.9, 104.0,
        104.10000000000001, 104.2, 104.30000000000001, 104.4, 104.5,
        104.60000000000001, 104.7, 104.80000000000001, 104.9, 105.0,
        105.10000000000001, 105.2, 105.30000000000001, 105.4, 105.5,
        105.60000000000001, 105.7, 105.80000000000001, 105.9, 106.0,
        106.10000000000001, 106.2, 106.30000000000001, 106.4, 106.5,
        106.60000000000001, 106.7, 106.80000000000001, 106.9, 107.0,
        107.10000000000001, 107.2, 107.30000000000001, 107.4, 107.5,
        107.60000000000001, 107.7, 107.80000000000001, 107.9, 108.0,
        108.10000000000001, 108.2, 108.30000000000001, 108.4, 108.5,
        108.60000000000001, 108.7, 108.80000000000001, 108.9, 109.0,
        109.10000000000001, 109.2, 109.30000000000001, 109.4, 109.5,
        109.60000000000001, 109.7, 109.80000000000001, 109.9, 110.0,
        110.10000000000001, 110.2, 110.30000000000001, 110.4, 110.5,
        110.60000000000001, 110.7, 110.80000000000001, 110.9, 111.0,
        111.10000000000001, 111.2, 111.30000000000001, 111.4, 111.5,
        111.60000000000001, 111.7, 111.80000000000001, 111.9, 112.0,
        112.10000000000001, 112.2, 112.30000000000001, 112.4, 112.5,
        112.60000000000001, 112.7, 112.80000000000001, 112.9, 113.0,
        113.10000000000001, 113.2, 113.30000000000001, 113.4, 113.5,
        113.60000000000001, 113.7, 113.80000000000001, 113.9, 114.0,
        114.10000000000001, 114.2, 114.30000000000001, 114.4, 114.5,
        114.60000000000001, 114.7, 114.80000000000001, 114.9, 115.0, 115.1,
        115.19999999999999, 115.3, 115.39999999999999, 115.5, 115.6,
        115.69999999999999, 115.8, 115.89999999999999, 116.0, 116.1,
        116.19999999999999, 116.3, 116.39999999999999, 116.5, 116.6,
        116.69999999999999, 116.8, 116.89999999999999, 117.0, 117.1,
        117.19999999999999, 117.3, 117.39999999999999, 117.5, 117.6,
        117.69999999999999, 117.8, 117.89999999999999, 118.0, 118.1,
        118.19999999999999, 118.3, 118.39999999999999, 118.5, 118.6,
        118.69999999999999, 118.8, 118.89999999999999, 119.0, 119.1,
        119.19999999999999, 119.3, 119.39999999999999, 119.5, 119.6,
        119.69999999999999, 119.8, 119.89999999999999, 120.0, 120.1,
        120.19999999999999, 120.3, 120.39999999999999, 120.5, 120.6,
        120.69999999999999, 120.8, 120.89999999999999, 121.0, 121.1,
        121.19999999999999, 121.3, 121.39999999999999, 121.5, 121.6,
        121.69999999999999, 121.8, 121.89999999999999, 122.0, 122.1,
        122.19999999999999, 122.3, 122.39999999999999, 122.5, 122.6,
        122.69999999999999, 122.8, 122.89999999999999, 123.0, 123.1,
        123.19999999999999, 123.3, 123.39999999999999, 123.5, 123.6,
        123.69999999999999, 123.8, 123.89999999999999, 124.0, 124.1,
        124.19999999999999, 124.3, 124.39999999999999, 124.5, 124.6,
        124.69999999999999, 124.8, 124.89999999999999, 125.0, 125.1,
        125.19999999999999, 125.3, 125.39999999999999, 125.5, 125.6,
        125.69999999999999, 125.8, 125.89999999999999, 126.0, 126.1,
        126.19999999999999, 126.3, 126.39999999999999, 126.5, 126.6,
        126.69999999999999, 126.8, 126.89999999999999, 127.0, 127.1,
        127.19999999999999, 127.3, 127.39999999999999, 127.5, 127.6,
        127.69999999999999, 127.8, 127.89999999999999, 128.0, 128.1, 128.2,
        128.3, 128.39999999999998, 128.5, 128.6, 128.7, 128.8,
        128.89999999999998, 129.0, 129.1, 129.2, 129.3, 129.39999999999998,
        129.5, 129.6, 129.7, 129.8, 129.89999999999998, 130.0, 130.1, 130.2,
        130.3, 130.39999999999998, 130.5, 130.6, 130.7, 130.8,
        130.89999999999998, 131.0, 131.1, 131.2, 131.3, 131.39999999999998,
        131.5, 131.6, 131.7, 131.8, 131.89999999999998, 132.0, 132.1, 132.2,
        132.3, 132.39999999999998, 132.5, 132.6, 132.7, 132.8,
        132.89999999999998, 133.0, 133.1, 133.2, 133.3, 133.39999999999998,
        133.5, 133.6, 133.7, 133.8, 133.89999999999998, 134.0, 134.1, 134.2,
        134.3, 134.39999999999998, 134.5, 134.6, 134.7, 134.8,
        134.89999999999998, 135.0, 135.1, 135.2, 135.3, 135.39999999999998,
        135.5, 135.6, 135.7, 135.8, 135.89999999999998, 136.0, 136.1, 136.2,
        136.3, 136.39999999999998, 136.5, 136.6, 136.7, 136.8,
        136.89999999999998, 137.0, 137.1, 137.2, 137.3, 137.39999999999998,
        137.5, 137.6, 137.7, 137.8, 137.89999999999998, 138.0, 138.1, 138.2,
        138.3, 138.39999999999998, 138.5, 138.6, 138.7, 138.8,
        138.89999999999998, 139.0, 139.1, 139.2, 139.3, 139.39999999999998,
        139.5, 139.6, 139.7, 139.8, 139.89999999999998, 140.0, 140.1, 140.2,
        140.3, 140.39999999999998, 140.5, 140.6, 140.7, 140.8,
        140.89999999999998, 141.0, 141.1, 141.2, 141.3, 141.39999999999998,
        141.5, 141.6, 141.7, 141.8, 141.89999999999998, 142.0, 142.1, 142.2,
        142.3, 142.39999999999998, 142.5, 142.6, 142.7, 142.8,
        142.89999999999998, 143.0, 143.1, 143.2, 143.3, 143.39999999999998,
        143.5, 143.6, 143.7, 143.8, 143.89999999999998, 144.0, 144.1, 144.2,
        144.3, 144.39999999999998, 144.5, 144.6, 144.7, 144.8,
        144.89999999999998, 145.0, 145.1, 145.2, 145.3, 145.39999999999998,
        145.5, 145.6, 145.7, 145.8, 145.89999999999998, 146.0, 146.1, 146.2,
        146.3, 146.39999999999998, 146.5, 146.6, 146.7, 146.8,
        146.89999999999998, 147.0, 147.1, 147.2, 147.3, 147.39999999999998,
        147.5, 147.6, 147.7, 147.8, 147.89999999999998, 148.0, 148.1, 148.2,
        148.3, 148.39999999999998, 148.5, 148.6, 148.7, 148.8,
        148.89999999999998, 149.0, 149.1, 149.2, 149.3, 149.39999999999998,
        149.5, 149.6, 149.7, 149.8, 149.89999999999998, 150.0, 150.1, 150.2,
        150.3, 150.39999999999998, 150.5, 150.6, 150.7, 150.8,
        150.89999999999998, 151.0, 151.1, 151.2, 151.3, 151.39999999999998,
        151.5, 151.6, 151.7, 151.8, 151.89999999999998, 152.0, 152.1, 152.2,
        152.3, 152.39999999999998, 152.5, 152.6, 152.7, 152.8,
        152.89999999999998, 153.0, 153.1, 153.2, 153.3, 153.39999999999998,
        153.5, 153.6, 153.7, 153.8, 153.89999999999998, 154.0, 154.1, 154.2,
        154.3, 154.39999999999998, 154.5, 154.6, 154.7, 154.8,
        154.89999999999998, 155.0, 155.1, 155.2, 155.3, 155.39999999999998,
        155.5, 155.6, 155.7, 155.8, 155.89999999999998, 156.0, 156.1, 156.2,
        156.3, 156.39999999999998, 156.5, 156.6, 156.7, 156.8,
        156.89999999999998, 157.0, 157.1, 157.2, 157.3, 157.39999999999998,
        157.5, 157.6, 157.7, 157.8, 157.89999999999998, 158.0, 158.1, 158.2,
        158.3, 158.39999999999998, 158.5, 158.6, 158.7, 158.8,
        158.89999999999998, 159.0, 159.1, 159.2, 159.3, 159.39999999999998,
        159.5, 159.6, 159.7, 159.8, 159.89999999999998, 160.0, 160.1, 160.2,
        160.3, 160.39999999999998, 160.5, 160.6, 160.7, 160.8,
        160.89999999999998, 161.0, 161.1, 161.2, 161.3, 161.39999999999998,
        161.5, 161.6, 161.7, 161.8, 161.89999999999998, 162.0, 162.1, 162.2,
        162.3, 162.39999999999998, 162.5, 162.6, 162.7, 162.8,
        162.89999999999998, 163.0, 163.1, 163.2, 163.3, 163.39999999999998,
        163.5, 163.6, 163.7, 163.8, 163.89999999999998, 164.0, 164.1, 164.2,
        164.3, 164.39999999999998, 164.5, 164.6, 164.7, 164.8,
        164.89999999999998, 165.0, 165.1, 165.2, 165.3, 165.39999999999998,
        165.5, 165.6, 165.7, 165.8, 165.89999999999998, 166.0, 166.1, 166.2,
        166.3, 166.4, 166.5, 166.6, 166.7, 166.8, 166.9, 167.0, 167.1, 167.2,
        167.3, 167.4, 167.5, 167.6, 167.7, 167.8, 167.9, 168.0, 168.1, 168.2,
        168.3, 168.4, 168.5, 168.6, 168.7, 168.8, 168.9, 169.0, 169.1, 169.2,
        169.3, 169.4, 169.5, 169.6, 169.7, 169.8, 169.9, 170.0, 170.1, 170.2,
        170.3, 170.4, 170.5, 170.6, 170.7, 170.8, 170.9, 171.0, 171.1, 171.2,
        171.3, 171.4, 171.5, 171.6, 171.7, 171.8, 171.9, 172.0, 172.1, 172.2,
        172.3, 172.4, 172.5, 172.6, 172.7, 172.8, 172.9, 173.0, 173.1, 173.2,
        173.3, 173.4, 173.5, 173.6, 173.7, 173.8, 173.9, 174.0, 174.1, 174.2,
        174.3, 174.4, 174.5, 174.6, 174.7, 174.8, 174.9, 175.0, 175.1, 175.2,
        175.3, 175.4, 175.5, 175.6, 175.7, 175.8, 175.9, 176.0, 176.1, 176.2,
        176.3, 176.4, 176.5, 176.6, 176.7, 176.8, 176.9, 177.0, 177.1, 177.2,
        177.3, 177.4, 177.5, 177.6, 177.7, 177.8, 177.9, 178.0, 178.1, 178.2,
        178.3, 178.4, 178.5, 178.6, 178.7, 178.8, 178.9, 179.0, 179.1, 179.2,
        179.3, 179.4, 179.5, 179.6, 179.7, 179.8, 179.9, 180.0, 180.1, 180.2,
        180.3, 180.4, 180.5, 180.6, 180.7, 180.8, 180.9, 181.0, 181.1, 181.2,
        181.3, 181.4, 181.5, 181.6, 181.7, 181.8, 181.9, 182.0, 182.1, 182.2,
        182.3, 182.4, 182.5, 182.6, 182.7, 182.8, 182.9, 183.0, 183.1, 183.2,
        183.3, 183.4, 183.5, 183.6, 183.7, 183.8, 183.9, 184.0, 184.1, 184.2,
        184.3, 184.4, 184.5, 184.6, 184.7, 184.8, 184.9, 185.0, 185.1, 185.2,
        185.3, 185.4, 185.5, 185.6, 185.7, 185.8, 185.9, 186.0, 186.1, 186.2,
        186.3, 186.4, 186.5, 186.6, 186.7, 186.8, 186.9, 187.0, 187.1, 187.2,
        187.3, 187.4, 187.5, 187.6, 187.7, 187.8, 187.9, 188.0, 188.1, 188.2,
        188.3, 188.4, 188.5, 188.6, 188.7, 188.8, 188.9, 189.0, 189.1, 189.2,
        189.3, 189.4, 189.5, 189.6, 189.7, 189.8, 189.9, 190.0, 190.1, 190.2,
        190.3, 190.4, 190.5, 190.6, 190.7, 190.8, 190.9, 191.0, 191.1, 191.2,
        191.3, 191.4, 191.5, 191.6, 191.7, 191.8, 191.9, 192.0, 192.1, 192.2,
        192.3, 192.4, 192.5, 192.6, 192.7, 192.8, 192.9, 193.0, 193.1, 193.2,
        193.3, 193.4, 193.5, 193.6, 193.7, 193.8, 193.9, 194.0, 194.1, 194.2,
        194.3, 194.4, 194.5, 194.6, 194.7, 194.8, 194.9, 195.0, 195.1, 195.2,
        195.3, 195.4, 195.5, 195.6, 195.7, 195.8, 195.9, 196.0, 196.1, 196.2,
        196.3, 196.4, 196.5, 196.6, 196.7, 196.8, 196.9, 197.0, 197.1, 197.2,
        197.3, 197.4, 197.5, 197.6, 197.7, 197.8, 197.9, 198.0, 198.1, 198.2,
        198.3, 198.4, 198.5, 198.6, 198.7, 198.8, 198.9, 199.0, 199.1, 199.2,
        199.3, 199.4, 199.5, 199.6, 199.7, 199.8, 199.9, 200.0, 200.1, 200.2,
        200.3, 200.4, 200.5, 200.6, 200.7, 200.8, 200.9, 201.0, 201.1, 201.2,
        201.3, 201.4, 201.5, 201.6, 201.7, 201.8, 201.9, 202.0, 202.1, 202.2,
        202.3, 202.4, 202.5, 202.6, 202.7, 202.8, 202.9, 203.0, 203.1, 203.2,
        203.3, 203.4, 203.5, 203.6, 203.7, 203.8, 203.9, 204.0, 204.1, 204.2,
        204.3, 204.4, 204.5, 204.6, 204.7, 204.8, 204.9, 205.0, 205.1, 205.2,
        205.3, 205.4, 205.5, 205.6, 205.7, 205.8, 205.9, 206.0, 206.1, 206.2,
        206.3, 206.4, 206.5, 206.6, 206.7, 206.8, 206.9, 207.0, 207.1, 207.2,
        207.3, 207.4, 207.5, 207.6, 207.7, 207.8, 207.9, 208.0, 208.1, 208.2,
        208.3, 208.4, 208.5, 208.6, 208.7, 208.8, 208.9, 209.0, 209.1, 209.2,
        209.3, 209.4, 209.5, 209.6, 209.7, 209.8, 209.9, 210.0, 210.1, 210.2,
        210.3, 210.4, 210.5, 210.6, 210.7, 210.8, 210.9, 211.0, 211.1, 211.2,
        211.3, 211.4, 211.5, 211.6, 211.7, 211.8, 211.9, 212.0, 212.1, 212.2,
        212.3, 212.4, 212.5, 212.6, 212.7, 212.8, 212.9, 213.0, 213.1, 213.2,
        213.3, 213.4, 213.5, 213.6, 213.7, 213.8, 213.9, 214.0, 214.1, 214.2,
        214.3, 214.4, 214.5, 214.6, 214.7, 214.8, 214.9, 215.0, 215.1, 215.2,
        215.3, 215.4, 215.5, 215.6, 215.7, 215.8, 215.9, 216.0, 216.1, 216.2,
        216.3, 216.4, 216.5, 216.6, 216.7, 216.8, 216.9, 217.0, 217.1, 217.2,
        217.3, 217.4, 217.5, 217.6, 217.7, 217.8, 217.9, 218.0, 218.1, 218.2,
        218.3, 218.4, 218.5, 218.6, 218.7, 218.8, 218.9, 219.0, 219.1, 219.2,
        219.3, 219.4, 219.5, 219.6, 219.7, 219.8, 219.9, 220.0, 220.1, 220.2,
        220.3, 220.4, 220.5, 220.6, 220.7, 220.8, 220.9, 221.0, 221.1, 221.2,
        221.3, 221.4, 221.5, 221.6, 221.7, 221.8, 221.9, 222.0, 222.1, 222.2,
        222.3, 222.4, 222.5, 222.6, 222.7, 222.8, 222.9, 223.0, 223.1, 223.2,
        223.3, 223.4, 223.5, 223.6, 223.7, 223.8, 223.9, 224.0, 224.1, 224.2,
        224.3, 224.4, 224.5, 224.6, 224.7, 224.8, 224.9, 225.0, 225.1, 225.2,
        225.3, 225.4, 225.5, 225.6, 225.7, 225.8, 225.9, 226.0, 226.1, 226.2,
        226.3, 226.4, 226.5, 226.6, 226.7, 226.8, 226.9, 227.0, 227.1, 227.2,
        227.3, 227.4, 227.5, 227.6, 227.7, 227.8, 227.9, 228.0, 228.1, 228.2,
        228.3, 228.4, 228.5, 228.6, 228.7, 228.8, 228.9, 229.0, 229.1, 229.2,
        229.3, 229.4, 229.5, 229.6, 229.7, 229.8, 229.9, 230.0 } ;

      static real_T pDataValues0[] = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 4.0000000000001709E-6, 3.2000000000000507E-5,
        0.00010800000000000078, 0.00025600000000000069, 0.0005,
        0.00086400000000000626, 0.0013720000000000062, 0.0020480000000000055,
        0.0029160000000000037, 0.004, 0.0053240000000000206,
        0.0069119999999999867, 0.0087880000000000163, 0.01097600000000005,
        0.013500000000000002, 0.016384000000000044, 0.019651999999999975,
        0.023328000000000029, 0.027436000000000092, 0.032, 0.037044000000000077,
        0.042591999999999963, 0.048668000000000051, 0.055296000000000151, 0.0625,
        0.07030400000000013, 0.078731999999999941, 0.08780800000000008,
        0.097556000000000226, 0.10800000000000001, 0.11916400000000017,
        0.13107199999999991, 0.1437480000000001, 0.1572160000000003, 0.1715,
        0.18662400000000023, 0.2026119999999999, 0.21948800000000016,
        0.2372760000000004, 0.256, 0.27568400000000032, 0.29635200000000061,
        0.31802800000000014, 0.34073600000000048, 0.36450000000000005,
        0.38934400000000041, 0.41529200000000077, 0.44236800000000015,
        0.47059600000000062, 0.5, 0.53006775700000042, 0.56027045600000092,
        0.59060723900000023, 0.62107724800000064, 0.651679625,
        0.68241351200000044, 0.71327805100000086, 0.74427238400000018,
        0.77539565300000057, 0.806647, 0.83802556700000042, 0.86953049600000087,
        0.90116092900000022, 0.93291600800000063, 0.96479487499999994,
        0.99679667200000044, 1.0289205410000009, 1.061165624, 1.0935310630000006,
        1.126016, 1.1586195770000005, 1.1913409360000009, 1.2241792190000003,
        1.2571335680000006, 1.290203125, 1.3233870320000003, 1.3566844310000008,
        1.3900944640000001, 1.4236162730000006, 1.4572489999999998,
        1.4909917870000005, 1.5248437760000009, 1.558804109, 1.5928719280000005,
        1.627046375, 1.6613265920000004, 1.6957117210000008, 1.7302009040000002,
        1.7647932830000006, 1.7994879999999998, 1.8342841970000003,
        1.8691810160000009, 1.904177599, 1.9392730880000006, 1.9744666249999998,
        2.0097573520000003, 2.0451444110000008, 2.080626944, 2.1162040930000003,
        2.151875, 2.1876388070000004, 2.2234946560000006, 2.259441689,
        2.2954790480000007, 2.3316058749999997, 2.3678213120000002,
        2.404124501000001, 2.440514584, 2.4769907030000007, 2.513552,
        2.5501976170000002, 2.5869266960000008, 2.623738379, 2.6606318080000007,
        2.6976061249999996, 2.7346604720000003, 2.7717939910000009,
        2.8090058239999998, 2.8462951130000005, 2.8836609999999996,
        2.9211026270000002, 2.9586191360000007, 2.996209669, 3.0338733680000005,
        3.0716093749999995, 3.109416832, 3.1472948810000005, 3.185242664,
        3.223259323, 3.2613439999999994, 3.2994958370000003, 3.3377139760000007,
        3.375997559, 3.4143457280000002, 3.4527576249999994, 3.491232392,
        3.5297691710000008, 3.5683671039999996, 3.607025333, 3.6457429999999995,
        3.684519247, 3.7233532160000009, 3.7622440489999995, 3.8011908880000003,
        3.8401928749999992, 3.879249152, 3.918358861, 3.9575211439999993,
        3.9967351430000004, 4.036, 4.0753148569999995, 4.114678856, 4.154091139,
        4.193550848, 4.2330571249999984, 4.272609112, 4.312205951000001,
        4.3518467839999992, 4.391530753, 4.431257, 4.471024667, 4.510832896,
        4.5506808289999992, 4.5905676080000006, 4.6304923749999993, 4.670454272,
        4.710452441, 4.750486024, 4.790554163, 4.8306559999999994,
        4.8707906770000005, 4.910957336, 4.9511551190000009, 4.9913831679999987,
        5.0316406249999988, 5.0719266319999994, 5.112240331, 5.1525808640000008,
        5.1929473729999982, 5.2333389999999991, 5.273754887, 5.314194176,
        5.354656009, 5.3951395279999987, 5.4356438749999993, 5.476168192,
        5.516711621, 5.5572733040000006, 5.5978523829999984, 5.6384479999999986,
        5.679059297, 5.7196854160000008, 5.760325499, 5.8009786879999981,
        5.8416441249999993, 5.882320952, 5.923008311, 5.963705344000001,
        6.0044111929999984, 6.0451249999999987, 6.0858459069999995, 6.126573056,
        6.1673055890000006, 6.2080426479999984, 6.2487833749999995,
        6.2895269119999995, 6.3302724009999993, 6.3710189840000009,
        6.411765802999998, 6.4525119999999987, 6.4932567169999995,
        6.5339990960000005, 6.574738279, 6.6154734079999979, 6.656203624999999,
        6.6969280719999995, 6.737645891, 6.778356224, 6.8190582129999981,
        6.8597509999999993, 6.9004337269999994, 6.941105536, 6.981765569,
        7.0224129679999985, 7.0630468749999986, 7.1036664319999989, 7.144270781,
        7.184859064, 7.2254304229999988, 7.2659839999999987, 7.306518937,
        7.3470343760000008, 7.3875294590000005, 7.4280033280000017,
        7.4684551249999993, 7.5088839919999986, 7.549289071, 7.5896695040000006,
        7.6300244330000009, 7.6703529999999986, 7.710654347, 7.750927616,
        7.7911719490000007, 7.8313864880000006, 7.8715703749999992,
        7.9117227519999993, 7.951842761, 7.991929544, 8.0319822430000016, 8.072,
        8.112093602, 8.152370016, 8.192822654, 8.233444928, 8.2742302499999987,
        8.315172032, 8.356263686, 8.397498624, 8.4388702580000015, 8.480372,
        8.521997262, 8.563739456, 8.605591994000001, 8.6475482880000012,
        8.68960175, 8.731745792, 8.773973826, 8.816279264, 8.8586555180000026,
        8.901095999999999, 8.943594122, 8.986143296, 9.0287369340000012,
        9.0713684480000012, 9.11403125, 9.156718752, 9.199424366,
        9.242141504000001, 9.2848635780000013, 9.327584, 9.370296182,
        9.412993536, 9.455669474, 9.4983174080000019, 9.54093075, 9.583502912,
        9.626027306000001, 9.668497344, 9.7109064380000021, 9.753248,
        9.795515442, 9.837702176, 9.8798016140000016, 9.921807168, 9.96371225,
        10.005510272, 10.047194646000001, 10.088758784000001, 10.130196098000003,
        10.1715, 10.212663902, 10.253681216, 10.294545354, 10.335249728,
        10.375787749999999, 10.416152832, 10.456338386, 10.496337824000001,
        10.536144558000002, 10.575752, 10.615153562, 10.654342656,
        10.693312694000001, 10.732057088000001, 10.77056925, 10.808842592,
        10.846870526, 10.884646464000001, 10.922163818000001, 10.959416,
        10.996396422, 11.033098496000001, 11.069515634000002, 11.105641248000001,
        11.14146875, 11.176991552, 11.212203066, 11.247096704,
        11.281665878000002, 11.315904, 11.349804482, 11.383360736, 11.416566174,
        11.449414208000002, 11.48189825, 11.514011712, 11.545748006,
        11.577100544, 11.608062738000001, 11.638627999999999, 11.668789742,
        11.698541376000001, 11.727876314000001, 11.756787968000001, 11.78526975,
        11.813315072, 11.840917346000001, 11.868069984000002, 11.894766398000002,
        11.921, 11.946895136, 11.972581888, 11.998062272, 12.023338304000001,
        12.048411999999999, 12.073285376, 12.097960448, 12.122439232,
        12.146723744, 12.170815999999999, 12.194718016, 12.218431808,
        12.241959392, 12.265302784000001, 12.288464, 12.311445056, 12.334247968,
        12.356874752, 12.379327424000001, 12.401608, 12.423718496, 12.445660928,
        12.467437312000001, 12.489049664000001, 12.510499999999999, 12.531790336,
        12.552922688, 12.573899072, 12.594721504, 12.615392, 12.635912575999999,
        12.656285248, 12.676512032, 12.696594944000001, 12.716536,
        12.736337215999999, 12.756000608, 12.775528192, 12.794921984, 12.814184,
        12.833316256, 12.852320768, 12.871199552, 12.889954624000001, 12.908588,
        12.927101696, 12.945497728, 12.963778112, 12.981944864, 13.0,
        13.017970402343749, 13.03588134375, 13.05373242578125, 13.07152325,
        13.089253417968751, 13.10692253125, 13.124530191406251,
        13.142076000000001, 13.159559558593751, 13.17698046875,
        13.194338332031251, 13.21163275, 13.22886332421875, 13.246029656250002,
        13.26313134765625, 13.280168, 13.297139214843751, 13.314044593750001,
        13.330883738281251, 13.34765625, 13.364361730468751, 13.38099978125,
        13.397570003906251, 13.414072, 13.43050537109375, 13.446869718750001,
        13.463164644531251, 13.479389750000001, 13.495544636718751,
        13.51162890625, 13.527642160156251, 13.543584000000001,
        13.559454027343751, 13.575251843750001, 13.59097705078125,
        13.606629250000001, 13.622208042968751, 13.637713031250001,
        13.653143816406251, 13.6685, 13.683781183593752, 13.69898696875,
        13.714116957031251, 13.729170750000002, 13.74414794921875,
        13.759048156250001, 13.773870972656251, 13.788616000000001,
        13.803282839843751, 13.81787109375, 13.832380363281251, 13.84681025,
        13.861160355468751, 13.87543028125, 13.889619628906251,
        13.903728000000001, 13.917754996093752, 13.93170021875,
        13.945563269531252, 13.95934375, 13.973041261718752, 13.986655406250001,
        14.000185785156251, 14.013632000000001, 14.026993652343752,
        14.04027034375, 14.053461675781252, 14.066567250000002,
        14.079586667968751, 14.092519531250002, 14.105365441406251,
        14.118124000000002, 14.130794808593752, 14.143377468750002,
        14.155871582031251, 14.16827675, 14.180592574218752, 14.192818656250001,
        14.204954597656252, 14.217, 14.228965224489796, 14.240858938775512,
        14.252678204081633, 14.264420081632654, 14.276081632653062,
        14.287659918367348, 14.299152000000001, 14.31055493877551,
        14.321865795918368, 14.333081632653062, 14.344199510204083,
        14.35521648979592, 14.366129632653061, 14.376936, 14.387632653061225,
        14.398216653061226, 14.408685061224491, 14.419034938775511,
        14.429263346938777, 14.439367346938775, 14.449344000000002,
        14.45919036734694, 14.468903510204083, 14.478480489795919,
        14.487918367346939, 14.497214204081633, 14.506365061224491, 14.515368,
        14.524220081632654, 14.532918367346939, 14.541459918367348,
        14.549841795918368, 14.558061061224491, 14.566114775510204, 14.574,
        14.581713795918368, 14.589253224489797, 14.596615346938776,
        14.603797224489796, 14.610795918367348, 14.61760848979592,
        14.624232000000001, 14.630663510204082, 14.636900081632653,
        14.642938775510205, 14.648776653061224, 14.654410775510204,
        14.659838204081632, 14.665056, 14.670061224489796, 14.67485093877551,
        14.679422204081632, 14.683772081632654, 14.687897632653062,
        14.691795918367347, 14.695464000000001, 14.69889893877551,
        14.702097795918368, 14.705057632653062, 14.707775510204081,
        14.710248489795919, 14.712473632653062, 14.714448, 14.716168653061224,
        14.717632653061225, 14.718837061224491, 14.71977893877551,
        14.720455346938776, 14.720863346938776, 14.721, 14.720913843750001,
        14.72065575, 14.72022628125, 14.719626, 14.71885546875, 14.71791525,
        14.71680590625, 14.715528, 14.71408209375, 14.71246875, 14.71068853125,
        14.708742, 14.70662971875, 14.70435225, 14.70191015625, 14.699304,
        14.69653434375, 14.693601750000001, 14.69050678125, 14.68725,
        14.68383196875, 14.68025325, 14.67651440625, 14.672616, 14.66855859375,
        14.66434275, 14.65996903125, 14.655438, 14.65075021875, 14.64590625,
        14.64090665625, 14.635752, 14.63044284375, 14.62497975,
        14.619363281250001, 14.613593999999999, 14.60767246875, 14.60159925,
        14.59537490625, 14.589, 14.58247509375, 14.57580075, 14.56897753125,
        14.562006, 14.55488671875, 14.54762025, 14.54020715625, 14.532648,
        14.52494334375, 14.51709375, 14.509099781249999, 14.500962,
        14.492680968750001, 14.48425725, 14.47569140625, 14.466984,
        14.45813559375, 14.44914675, 14.44001803125, 14.43075, 14.42134321875,
        14.41179825, 14.40211565625, 14.392296, 14.38233984375, 14.37224775,
        14.36202028125, 14.351657999999999, 14.34116146875, 14.33053125,
        14.31976790625, 14.308872000000001, 14.29784409375, 14.28668475,
        14.27539453125, 14.263974, 14.25242371875, 14.240744249999999,
        14.22893615625, 14.217, 14.204898116618075, 14.192593912536443,
        14.180089556851311, 14.167387218658892, 14.154489067055394,
        14.141397271137025, 14.128114, 14.114641422740524, 14.10098170845481,
        14.087137026239068, 14.073109545189503, 14.058901434402333,
        14.04451486297376, 14.029952, 14.01521501457726, 14.000306075801749,
        13.985227352769678, 13.969981014577257, 13.954569230320699,
        13.93899416909621, 13.923257999999999, 13.90736289212828,
        13.891311014577258, 13.875104536443148, 13.858745626822158,
        13.842236454810495, 13.825579189504372, 13.808775999999998,
        13.791829055393585, 13.774740524781341, 13.757512577259474,
        13.740147381924197, 13.722647107871719, 13.70501392419825, 13.68725,
        13.669357504373176, 13.651338606413994, 13.633195475218656,
        13.614930279883382, 13.596545189504374, 13.578042373177841, 13.559424,
        13.540692239067054, 13.521849259475218, 13.5028972303207,
        13.483838320699707, 13.464674699708453, 13.445408536443146,
        13.426041999999999, 13.406577259475219, 13.387016483965013,
        13.367361842565597, 13.347615504373175, 13.327779638483964,
        13.30785641399417, 13.287847999999999, 13.267756565597667,
        13.24758427988338, 13.227333311953352, 13.207005830903789,
        13.186604005830901, 13.166130005830903, 13.145585999999998,
        13.124974157434401, 13.104296647230321, 13.083555638483963,
        13.062753300291543, 13.041891801749269, 13.020973311953352, 13.0,
        12.979063663999998, 12.958248511999999, 12.937545327999997,
        12.916944895999999, 12.896438, 12.876015423999998, 12.855667952,
        12.835386367999998, 12.815161455999998, 12.794984, 12.774844783999999,
        12.754734592, 12.734644207999997, 12.714564415999998, 12.694486,
        12.674399743999999, 12.654296431999999, 12.634166847999998,
        12.614001775999999, 12.593792, 12.573528303999998, 12.553201472,
        12.532802287999997, 12.512321535999998, 12.49175, 12.471078463999998,
        12.450297712, 12.429398527999998, 12.408371696, 12.387208,
        12.365898223999999, 12.344433151999999, 12.322803567999998,
        12.301000255999998, 12.279014, 12.256835583999997, 12.234455791999999,
        12.211865407999998, 12.189055215999998, 12.166016, 12.142738543999998,
        12.119213632, 12.095432047999997, 12.071384575999998, 12.047062,
        12.022455103999999, 11.997554672, 11.972351487999997, 11.946836335999999,
        11.921, 11.894766397999996, 11.868069983999998, 11.840917345999996,
        11.813315071999998, 11.78526975, 11.756787967999998, 11.727876313999998,
        11.698541375999996, 11.668789741999998, 11.638627999999999,
        11.608062737999997, 11.577100543999999, 11.545748005999997,
        11.514011711999997, 11.481898249999999, 11.449414207999997,
        11.416566173999998, 11.383360735999995, 11.349804481999998, 11.315904,
        11.281665877999997, 11.247096703999999, 11.212203065999995,
        11.176991551999997, 11.14146875, 11.105641247999996, 11.069515633999998,
        11.033098495999996, 10.996396421999997, 10.959416, 10.922163817999996,
        10.884646463999998, 10.846870525999995, 10.808842591999998, 10.77056925,
        10.732057087999996, 10.693312693999998, 10.654342655999995,
        10.615153561999996, 10.575752, 10.536144557999997, 10.496337823999998,
        10.456338385999995, 10.416152831999996, 10.375787749999999,
        10.335249727999996, 10.294545353999998, 10.253681215999995,
        10.212663901999996, 10.171499999999998, 10.130196097999995,
        10.088758783999998, 10.047194645999994, 10.005510271999997,
        9.9637122499999986, 9.9218071679999955, 9.879801613999998,
        9.8377021759999934, 9.7955154419999957, 9.753248, 9.710906437999995,
        9.6684973439999986, 9.6260273059999939, 9.5835029119999966, 9.54093075,
        9.4983174079999948, 9.4556694739999969, 9.4129935359999948,
        9.370296181999997, 9.3275839999999981, 9.284863577999996,
        9.2421415039999975, 9.1994243659999952, 9.1567187519999962, 9.11403125,
        9.0713684479999959, 9.0287369339999977, 8.9861432959999945,
        8.9435941219999968, 8.901095999999999, 8.8586555179999955,
        8.8162792639999985, 8.7739738259999935, 8.7317457919999963,
        8.6896017499999978, 8.6475482879999959, 8.6055919939999974,
        8.5637394559999933, 8.5219972619999957, 8.480372, 8.4388702579999944,
        8.3974986239999971, 8.3562636859999948, 8.315172031999996,
        8.2742302499999987, 8.2334449279999955, 8.1928226539999969,
        8.1523700159999937, 8.1120936019999963, 8.072, 8.0318827429999953,
        7.9915335439999984, 7.9509562609999946, 7.9101547519999968,
        7.8691328749999991, 7.8278944879999957, 7.7864434489999983,
        7.7447836159999941, 7.7029188469999967, 7.6608529999999995,
        7.6185899329999955, 7.5761335039999977, 7.533487570999994,
        7.4906559919999971, 7.4476426249999994, 7.4044513279999951,
        7.3610859589999977, 7.3175503759999945, 7.2738484369999963,
        7.2299839999999991, 7.1859609229999952, 7.1417830639999975,
        7.0974542809999939, 7.0529784319999962, 7.0083593749999995,
        6.9636009679999953, 6.9187070689999981, 6.8736815359999941,
        6.8285282269999961, 6.783250999999999, 6.7378537129999954,
        6.6923402239999978, 6.6467143909999944, 6.6009800719999969,
        6.5551411249999987, 6.5092014079999956, 6.4631647789999978,
        6.417035095999994, 6.3708162169999962, 6.3245119999999986,
        6.2781263029999952, 6.231662983999998, 6.1851259009999939,
        6.1385189119999968, 6.0918458749999989, 6.0451106479999952,
        5.9983170889999977, 5.9514690559999934, 5.904570406999996,
        5.8576249999999987, 5.8106366929999957, 5.7636093439999971,
        5.7165468109999935, 5.6694529519999968, 5.6223316249999993,
        5.5751866879999952, 5.5280219989999981, 5.4808414159999934,
        5.4336487969999965, 5.386448, 5.3392428829999954, 5.2920373039999982,
        5.2448351209999942, 5.1976401919999962, 5.1504563749999992,
        5.1032875279999956, 5.0561375089999974, 5.0090101759999932,
        4.9619093869999968, 4.9148389999999988, 4.8678028729999951,
        4.8208048639999976, 4.7738488309999934, 4.726938631999996,
        4.6800781249999988, 4.6332711679999949, 4.5865216189999973,
        4.5398333359999938, 4.4932101769999964, 4.4466559999999991,
        4.4001746629999952, 4.3537700239999975, 4.3074459409999939,
        4.2612062719999972, 4.215054874999999, 4.1689956079999959,
        4.1230323289999973, 4.0771688959999945, 4.031409166999997,
        3.9857569999999987, 3.9402162529999947, 3.8947907839999978,
        3.8494844509999941, 3.8043011119999965, 3.7592446249999991,
        3.7143188479999951, 3.6695276389999982, 3.6248748559999937,
        3.580364356999997, 3.5359999999999996, 3.4917856429999956,
        3.4477251439999979, 3.4038223609999942, 3.3600811519999967,
        3.3165053749999993, 3.2730988879999954, 3.2298655489999986,
        3.1868092159999941, 3.1439337469999966, 3.1012429999999993,
        3.0587408329999954, 3.0164311039999978, 2.9743176709999943,
        2.9324043919999969, 2.8906951249999997, 2.8491937279999959,
        2.8079040589999984, 2.7668299759999941, 2.7259753369999968,
        2.6853439999999988, 2.6449398229999961, 2.6047666639999978,
        2.5648283809999946, 2.5251288319999974, 2.4856718749999995,
        2.446461367999996, 2.4075011689999979, 2.3687951359999948,
        2.3303471269999969, 2.2921609999999992, 2.2542406129999959,
        2.2165898239999979, 2.179212490999995, 2.1421124719999973,
        2.1052936249999989, 2.0687598079999967, 2.0325148789999981,
        1.9965626959999945, 1.960907116999997, 1.9255519999999997,
        1.8905012029999968, 1.8557585839999984, 1.821328000999995,
        1.7872133119999969, 1.753418374999999, 1.7199470479999963,
        1.6868031889999981, 1.6539906559999951, 1.6215133069999972,
        1.5893749999999995, 1.5575795930000007, 1.5261309440000028, 1.495032911,
        1.4642893520000015, 1.4339041249999989, 1.4038810880000003,
        1.3742240990000028, 1.3449370160000003, 1.3160236970000012,
        1.2874879999999997, 1.2593337830000007, 1.2315649040000025,
        1.2041852209999995, 1.1771985920000017, 1.1506088749999996,
        1.1244199280000009, 1.0986356090000022, 1.0732597760000004,
        1.0482962870000012, 1.0237489999999996, 0.99962177300000032,
        0.975918464000002, 0.95264293099999975, 0.92979903200000091,
        0.90739062499999967, 0.88542156799999994, 0.86389571900000117,
        0.84281693600000018, 0.82218907700000088, 0.80201599999999829,
        0.78230156300000075, 0.76304962400000242, 0.7442640410000001,
        0.72594867200000124, 0.7081073749999991, 0.69074400800000024,
        0.67386242900000148, 0.65746649599999962, 0.64156006700000034,
        0.62614699999999957, 0.6112311530000003, 0.59681638400000114,
        0.58290655099999977, 0.5695055120000001, 0.55661712499999894,
        0.54424524799999929, 0.53239373899999975, 0.52106645600000068,
        0.51026725700000064, 0.5, 0.49006237500000055, 0.48024900000000109,
        0.4705591250000003, 0.46099200000000079, 0.451546875,
        0.44222300000000053, 0.433019625000001, 0.42393600000000026,
        0.41497137500000075, 0.40612499999999996, 0.39739612500000049,
        0.38878400000000096, 0.38028787500000022, 0.37190700000000065,
        0.363640625, 0.35548800000000047, 0.34744837500000092,
        0.33952100000000018, 0.33170512500000066, 0.32399999999999995,
        0.31640487500000042, 0.30891900000000083, 0.3015416250000002,
        0.29427200000000059, 0.28710937499999994, 0.28005300000000033,
        0.27310212500000075, 0.26625600000000016, 0.25951387500000056,
        0.25287499999999996, 0.24633862500000031, 0.23990400000000067,
        0.23357037500000016, 0.22733700000000051, 0.22120312499999994,
        0.2151680000000003, 0.20923087500000065, 0.2033910000000001,
        0.19764762500000044, 0.19199999999999995, 0.1864473750000003,
        0.18098900000000051, 0.17562412500000013, 0.17035200000000039,
        0.16517187499999997, 0.1600830000000002, 0.15508462500000053,
        0.15017600000000009, 0.14535637500000032, 0.14062499999999994,
        0.1359811250000002, 0.13142400000000043, 0.12695287500000008,
        0.12256700000000031, 0.11826562499999993, 0.1140480000000002,
        0.10991337500000042, 0.10586100000000004, 0.10189012500000033,
        0.097999999999999976, 0.094189875000000145, 0.090459000000000289,
        0.086806625000000026, 0.0832320000000002, 0.079734374999999913,
        0.076313000000000075, 0.072967125000000188, 0.06969599999999998,
        0.066498875000000179, 0.0633749999999999, 0.060323625000000047,
        0.057344000000000173, 0.0544353749999999, 0.051597000000000115,
        0.048828124999999889, 0.046128, 0.043495875000000128,
        0.040930999999999995, 0.038432625000000054, 0.035999999999999865,
        0.033632374999999992, 0.031329000000000162, 0.029089124999999549,
        0.026912000000000325, 0.024796874999999829, 0.022742999999999958,
        0.020749625000000105, 0.018815999999999611, 0.016941375000000258,
        0.015124999999999833, 0.013366124999999895, 0.011664000000000063,
        0.010017874999999676, 0.0084270000000001843, 0.006890624999999817,
        0.0054079999999998574, 0.003978375000000034, 0.0026009999999996869,
        0.0012751250000000991, -2.2204460492503131E-16, -0.0012251250000001601,
        -0.0024010000000000975, -0.0035283750000003611, -0.0046079999999999455,
        -0.0056406250000002878, -0.0066270000000001605, -0.0075678750000001127,
        -0.00846400000000036, -0.0093161250000000084, -0.010125000000000162,
        -0.010891375000000258, -0.011616000000000182, -0.012299625000000258,
        -0.012943000000000149, -0.01354687500000018, -0.014112000000000235,
        -0.014639125000000197, -0.015129000000000281, -0.015582375000000259,
        -0.016000000000000236, -0.016382625000000206, -0.016731000000000273,
        -0.017045875000000321, -0.017328000000000232, -0.017578125000000222,
        -0.017797000000000285, -0.017985375000000303, -0.018144000000000271,
        -0.018273625000000404, -0.018375000000000252, -0.018448875000000364,
        -0.01849600000000029, -0.018517125000000356, -0.018513000000000446,
        -0.01848437500000033, -0.018432000000000337, -0.018356625000000348,
        -0.018259000000000358, -0.018139875000000472, -0.018000000000000238,
        -0.017840125000000429, -0.017661000000000371, -0.017463375000000503,
        -0.017248000000000263, -0.017015625000000423, -0.016767000000000309,
        -0.016502875000000583, -0.016224000000000349, -0.015931125000000379,
        -0.015625000000000444, -0.015306375000000427, -0.014976000000000544,
        -0.014634625000000234, -0.014283000000000379, -0.013921875000000417,
        -0.013552000000000564, -0.013174125000000481, -0.012789000000000383,
        -0.012397375000000599, -0.012000000000000455, -0.011597625000000611,
        -0.011191000000000506, -0.010780875000000245, -0.010368000000000599,
        -0.0099531250000004512, -0.00953700000000024, -0.0091203750000007355,
        -0.0087040000000003781, -0.0082886250000007156, -0.00787500000000041,
        -0.0074638750000003418, -0.0070560000000007284, -0.0066521250000003418,
        -0.00625300000000073, -0.0058593750000006661, -0.0054720000000004765,
        -0.0050916250000009322, -0.0047190000000003618, -0.0043548750000006464,
        -0.00400000000000067, -0.0036551250000005364, -0.0033210000000009066,
        -0.0029983750000003306, -0.0026880000000005788, -0.0023906250000006457,
        -0.0021070000000004141, -0.0018378750000005439, -0.0015840000000004739,
        -0.001346125000000753, -0.0011250000000007088, -0.00092137500000077921,
        -0.000736000000000625, -0.00056962500000068417, -0.00042300000000072835,
        -0.00029687500000064038, -0.00019200000000063611, -0.0001091250000004873,
        -4.9000000000520849E-5, -1.2375000000619529E-5, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -0.00025797200000000735,
        -0.0010269760000000292, -0.0022996440000000655, -0.004068608000000115,
        -0.0063265000000000014, -0.0090659520000000438, -0.012279596000000101,
        -0.01596006400000017, -0.020099988000000252, -0.024692000000000006,
        -0.029728732000000081, -0.035202816000000164, -0.041106884000000267,
        -0.047433568000000377, -0.054175500000000015, -0.061325312000000118,
        -0.06887563600000024, -0.07681910400000036, -0.085148348000000512,
        -0.093856000000000023, -0.10293469200000016, -0.11237705600000029,
        -0.12217572400000046, -0.1323233280000006, -0.14281250000000004,
        -0.1536358720000002, -0.16478607600000036, -0.17625574400000049,
        -0.18803750800000071, -0.20012400000000005, -0.21250785200000022,
        -0.2251816960000004, -0.23813816400000065, -0.25136988800000082,
        -0.26486950000000004, -0.27862963200000024, -0.29264291600000047,
        -0.30690198400000068, -0.32139946800000091, -0.33612800000000009,
        -0.35108021200000028, -0.36624873600000046, -0.38162620400000075,
        -0.39720524800000095, -0.4129785, -0.42893859200000034,
        -0.44507815600000056, -0.46138982400000078, -0.47786622800000106,
        -0.49450000000000016, -0.51128377200000041, -0.52821017600000053,
        -0.54527184400000084, -0.56246140800000111, -0.5797715,
        -0.59719475200000038, -0.6147237960000006, -0.63235126400000086,
        -0.65006978800000115, -0.66787200000000013, -0.68575053200000036,
        -0.7036980160000007, -0.72170708400000094, -0.73977036800000118,
        -0.75788050000000018, -0.77603011200000049, -0.79421183600000067,
        -0.81241830400000092, -0.83064214800000125, -0.84887600000000007,
        -0.86711249200000029, -0.88534425600000077, -0.903563924000001,
        -0.92176412800000118, -0.93993750000000009, -0.95807667200000057,
        -0.97617427600000062, -0.99422294400000089, -1.0122153080000011,
        -1.0301440000000002, -1.0480016520000004, -1.0657808960000008,
        -1.0834743640000011, -1.1010746880000013, -1.1185745000000002,
        -1.1359664320000005, -1.1532431160000007, -1.1703971840000009,
        -1.1874212680000009, -1.2043080000000002, -1.2210500120000003,
        -1.2376399360000006, -1.2540704040000008, -1.2703340480000009,
        -1.2864235000000004, -1.3023313920000006, -1.3180503560000008,
        -1.3335730240000008, -1.348892028000001, -1.364, -1.3788630240000004,
        -1.3934513920000005, -1.4077640480000007, -1.4217999360000009,
        -1.4355580000000001, -1.4490371840000003, -1.4622364320000005,
        -1.4751546880000006, -1.4877908960000008, -1.5001440000000001,
        -1.5122129440000003, -1.5239966720000004, -1.5354941280000007,
        -1.5467042560000008, -1.5576260000000002, -1.5682583040000002,
        -1.5786001120000004, -1.5886503680000006, -1.5984080160000007,
        -1.6078720000000002, -1.6170412640000003, -1.6259147520000004,
        -1.6344914080000006, -1.6427701760000006, -1.6507500000000002,
        -1.6584298240000002, -1.6658085920000003, -1.6728852480000005,
        -1.6796587360000006, -1.686128, -1.6922919840000001, -1.6981496320000002,
        -1.7036998880000005, -1.7089416960000006, -1.7138740000000001,
        -1.7184957440000002, -1.7228058720000003, -1.7268033280000004,
        -1.7304870560000005, -1.7338560000000003, -1.7369091040000004,
        -1.7396453120000004, -1.7420635680000003, -1.7441628160000002,
        -1.7459420000000003, -1.7474000640000003, -1.7485359520000003,
        -1.7493486080000002, -1.7498369760000003, -1.75, -1.74990966015625,
        -1.74963915625, -1.7491892617187499, -1.74856075, -1.74775439453125,
        -1.74677096875, -1.74561124609375, -1.744276, -1.7427660039062498,
        -1.74108203125, -1.73922485546875, -1.7371952499999999,
        -1.73499398828125, -1.7326218437499998, -1.73007958984375, -1.727368,
        -1.72448784765625, -1.7214399062499999, -1.7182249492187498, -1.71484375,
        -1.7112970820312499, -1.7075857187499999, -1.7037104335937499,
        -1.6996719999999998, -1.69547119140625, -1.6911087812499999,
        -1.68658554296875, -1.6819022499999998, -1.6770596757812497,
        -1.67205859375, -1.66689977734375, -1.661584, -1.6561120351562497,
        -1.6504846562499997, -1.64470263671875, -1.63876675, -1.6326777695312498,
        -1.6264364687499997, -1.6200436210937497, -1.6135000000000002,
        -1.6068063789062499, -1.5999635312499998, -1.5929722304687497,
        -1.5858332499999996, -1.5785473632812501, -1.5711153437499998,
        -1.56353796484375, -1.5558159999999996, -1.5479502226562496,
        -1.53994140625, -1.53179032421875, -1.5234977499999998,
        -1.5150644570312497, -1.5064912187499997, -1.49777880859375, -1.488928,
        -1.4799395664062498, -1.4708142812499996, -1.4615529179687496,
        -1.45215625, -1.44262505078125, -1.4329600937499998, -1.4231621523437497,
        -1.4132319999999996, -1.40317041015625, -1.3929781562499999,
        -1.3826560117187499, -1.3722047499999996, -1.3616251445312495,
        -1.3509179687500001, -1.3400839960937498, -1.3291239999999998,
        -1.3180387539062495, -1.3068290312499995, -1.29549560546875, -1.28403925,
        -1.2724607382812498, -1.2607608437499995, -1.2489403398437493, -1.237,
        -1.2248719067055394, -1.212490355685131, -1.1998594402332357,
        -1.1869832536443141, -1.173865889212828, -1.1605114402332362,
        -1.1469239999999996, -1.1331076618075797, -1.1190665189504365,
        -1.1048046647230323, -1.090326192419824, -1.0756351953352767,
        -1.0607357667638488, -1.0456319999999992, -1.0303279883381926,
        -1.014827825072885, -0.99913560349854191, -0.98325541690962148,
        -0.96719135860058225, -0.95094752186588938, -0.93452799999999869,
        -0.9179368862973758, -0.90117827405247874, -0.88425625655976581,
        -0.8671749271137027, -0.84993837900874492, -0.83255070553935817,
        -0.81501600000000063, -0.79733835568513034, -0.77952186588921291,
        -0.761570623906704, -0.74348872303206948, -0.72528025655976736,
        -0.70694931778425563, -0.68850000000000011, -0.6699363965014562,
        -0.65126260058308993, -0.63248270553935915, -0.613600804664722,
        -0.59462099125364443, -0.57554735860058148, -0.55638399999999955,
        -0.53713500874635633, -0.51780447813410968, -0.49839650145772596,
        -0.47891517201166012, -0.45936458309037842, -0.43974882798833881,
        -0.42007199999999889, -0.40033819241982505, -0.38055149854227244,
        -0.360716011661807, -0.3408358250728869, -0.32091503206996974,
        -0.30095772594752179, -0.28096799999999822, -0.2609499475218654,
        -0.24090766180758072, -0.22084523615160245, -0.20076676384839631,
        -0.18067633819241813, -0.1605780524781335, -0.14047600000000049,
        -0.12037427405247692, -0.10027696793002905, -0.080188174927112055,
        -0.060111988338191757, -0.04005250145772643, -0.020013807580173681, 0.0,
        0.019930011718751695, 0.039720718750000564, 0.059373128906249448,
        0.078888250000001117, 0.09826708984375, 0.11751065625000165,
        0.13661995703125054, 0.15559599999999946, 0.17443979296875109,
        0.19315234375, 0.21173466015625161, 0.23018775000000052,
        0.24851262109374953, 0.26671028125000107, 0.28478173828125,
        0.30272800000000155, 0.32055007421875054, 0.33824896874999955,
        0.35582569140625103, 0.37328125, 0.39061665234375148,
        0.40783290625000052, 0.42493101953124951, 0.441912000000001,
        0.45877685546875, 0.47552659375000145, 0.49216222265625054,
        0.50868474999999957, 0.525095183593751, 0.54139453125,
        0.55758380078125136, 0.57366400000000051, 0.58963613671874959,
        0.605501218750001, 0.62126025390625006, 0.63691425000000135,
        0.6524642148437505, 0.66791115624999953, 0.683256082031251,
        0.69850000000000012, 0.71364391796875137, 0.72868884375000054,
        0.74363578515624962, 0.758485750000001, 0.77323974609375,
        0.78789878125000123, 0.80246386328125041, 0.81693599999999966,
        0.83131619921875088, 0.84560546875000009, 0.85980481640625128,
        0.87391525000000059, 0.88793777734374957, 0.90187340625000079,
        0.91572314453125, 0.9294880000000012, 0.94316898046875053,
        0.95676709374999969, 0.97028334765625079, 0.9837187500000002,
        0.99707430859375124, 1.0103510312500004, 1.0235499257812497,
        1.0366720000000009, 1.0497182617187502, 1.0626897187500011,
        1.0755873789062504, 1.0884122500000015, 1.1011653398437506,
        1.11384765625, 1.1264602070312513, 1.1390040000000006,
        1.1514800429687515, 1.1638893437500009, 1.17623291015625,
        1.1885117500000011, 1.2007268710937504, 1.2128792812500016,
        1.2249699882812508, 1.237, 1.2489706822157445, 1.2608805597667643,
        1.2727263790087477, 1.2845048862973769, 1.2962128279883383,
        1.3078469504373189, 1.3194040000000005, 1.3308807230320714,
        1.3422738658892135, 1.3535801749271137, 1.3647963965014589,
        1.3759192769679305, 1.3869455626822171, 1.3978720000000007,
        1.408695335276968, 1.4194123148688056, 1.4300196851311957,
        1.4405141924198264, 1.4508925830903796, 1.4611516034985423,
        1.471288000000001, 1.4812985189504377, 1.4911799067055407,
        1.5009289096209919, 1.5105422740524781, 1.520016746355686,
        1.5293490728862977, 1.538536000000001, 1.5475742740524787,
        1.5564606413994171, 1.5651918483965024, 1.5737646413994173,
        1.5821757667638494, 1.5904219708454816, 1.5985, 1.606406600583091,
        1.6141385189504376, 1.6216925014577268, 1.6290652944606419,
        1.636253644314869, 1.643254297376094, 1.6500640000000002,
        1.6566794985422748, 1.6630975393586009, 1.6693148688046648,
        1.6753282332361521, 1.6811343790087465, 1.6867300524781348,
        1.6921120000000003, 1.697276967930029, 1.702221702623907,
        1.7069429504373179, 1.7114374577259481, 1.7157019708454815,
        1.7197332361516036, 1.7235280000000004, 1.7270830087463558,
        1.730395008746356, 1.7334607463556853, 1.7362769679300292,
        1.7388404198250731, 1.7411478483965015, 1.7431960000000002,
        1.7449816209912539, 1.7465014577259474, 1.747752256559767,
        1.7487307638483967, 1.7494337259475219, 1.749857889212828, 1.75,
        1.7498369759999999, 1.749348608, 1.748535952, 1.747400064, 1.745942,
        1.7441628159999998, 1.7420635679999998, 1.7396453119999997,
        1.7369091039999998, 1.733856, 1.7304870559999996, 1.726803328,
        1.7228058719999995, 1.7184957439999997, 1.7138740000000001,
        1.7089416959999997, 1.7036998879999998, 1.6981496319999994,
        1.6922919839999997, 1.686128, 1.6796587359999995, 1.6728852479999998,
        1.6658085919999992, 1.6584298239999997, 1.65075, 1.6427701759999993,
        1.634491408, 1.625914751999999, 1.6170412639999996, 1.607872,
        1.5984080159999992, 1.5886503679999997, 1.5786001119999988,
        1.5682583039999995, 1.5576260000000002, 1.5467042559999991,
        1.5354941279999998, 1.5239966719999987, 1.5122129439999994,
        1.5001440000000001, 1.487790895999999, 1.4751546879999997,
        1.4622364319999985, 1.4490371839999994, 1.4355580000000001,
        1.4217999359999989, 1.4077640479999998, 1.3934513919999985,
        1.3788630239999993, 1.364, 1.3488920279999987, 1.3335730239999997,
        1.3180503559999983, 1.3023313919999993, 1.2864235000000002,
        1.2703340479999987, 1.2540704039999997, 1.2376399359999981,
        1.2210500119999992, 1.2043080000000002, 1.1874212679999987,
        1.1703971839999996, 1.1532431159999981, 1.1359664319999991, 1.1185745,
        1.1010746879999986, 1.0834743639999997, 1.0657808959999981,
        1.0480016519999991, 1.0301440000000002, 1.0122153079999985,
        0.99422294399999966, 0.97617427599999806, 0.95807667199999913,
        0.93993750000000009, 0.92176412799999863, 0.90356392399999952,
        0.885344255999998, 0.86711249199999907, 0.84887600000000007,
        0.83064214799999858, 0.81241830399999959, 0.794211835999998,
        0.776030111999999, 0.75788050000000007, 0.73977036799999851,
        0.72170708399999961, 0.703698015999998, 0.68575053199999914,
        0.66787200000000013, 0.65006978799999859, 0.63235126399999952,
        0.614723795999998, 0.59719475199999916, 0.57977150000000011,
        0.56246140799999866, 0.54527184399999962, 0.5282101759999982,
        0.51128377199999919, 0.49450000000000016, 0.47786622799999867,
        0.46138982399999962, 0.44507815599999823, 0.42893859199999917,
        0.41297850000000014, 0.39720524799999879, 0.38162620399999969,
        0.3662487359999983, 0.35108021199999939, 0.3361280000000002,
        0.32139946799999897, 0.30690198399999979, 0.29264291599999859,
        0.27862963199999924, 0.26486950000000009, 0.25136988799999904,
        0.23813816399999976, 0.22518169599999882, 0.21250785199999944,
        0.20012400000000019, 0.18803750799999897, 0.17625574399999988,
        0.16478607599999884, 0.15363587199999951, 0.1428125, 0.13232332799999913,
        0.1221757240000001, 0.11237705599999903, 0.10293469199999961,
        0.093856000000000162, 0.085148347999999263, 0.076819103999999916,
        0.068875635999999352, 0.061325311999999688, 0.054175500000000154,
        0.047433567999999759, 0.041106883999999955, 0.035202815999999304,
        0.029728731999999924, 0.024692000000000158, 0.020099987999999902,
        0.015960064000000163, 0.012279595999999726, 0.0090659520000000438,
        0.0063265000000003457, 0.0040686080000000846, 0.0022996440000002671,
        0.0010269760000003458, 0.00025797200000021725, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 9.9777777777777788E-5,
        0.00039822222222222234, 0.00089400000000000026, 0.001585777777777778,
        0.0024722222222222224, 0.0035520000000000009, 0.0048237777777777784,
        0.0062862222222222226, 0.007938, 0.0097777777777777776,
        0.011804222222222223, 0.014016000000000004, 0.016411777777777779,
        0.018990222222222228, 0.021750000000000002, 0.024689777777777783,
        0.027808222222222231, 0.031104000000000007, 0.034575777777777782,
        0.03822222222222222, 0.042042, 0.046033777777777785,
        0.050196222222222232, 0.054528000000000021, 0.059027777777777776,
        0.063694222222222222, 0.068526000000000017, 0.0735217777777778,
        0.078680222222222249, 0.084000000000000019, 0.089479777777777769,
        0.095118222222222215, 0.100914, 0.1068657777777778, 0.11297222222222222,
        0.11923200000000002, 0.1256437777777778, 0.13220622222222222,
        0.13891800000000004, 0.14577777777777778, 0.15278422222222229,
        0.15993600000000002, 0.16723177777777778, 0.17467022222222223,
        0.18224999999999997, 0.18996977777777782, 0.19782822222222224,
        0.20582400000000006, 0.21395577777777783, 0.22222222222222224,
        0.23062200000000005, 0.2391537777777778, 0.2478162222222223,
        0.25660800000000006, 0.26552777777777775, 0.27457422222222222, 0.283746,
        0.29304177777777785, 0.30246022222222224, 0.312, 0.32165977777777782,
        0.33143822222222225, 0.34133400000000008, 0.35134577777777781,
        0.36147222222222219, 0.3717120000000001, 0.38206377777777778,
        0.39252622222222228, 0.403098, 0.41377777777777774, 0.42456422222222223,
        0.435456, 0.44645177777777784, 0.45755022222222225, 0.46875,
        0.48004977777777791, 0.49144822222222223, 0.50294400000000017,
        0.5145357777777777, 0.52622222222222215, 0.53800199999999987,
        0.54987377777777791, 0.56183622222222218, 0.573888, 0.58602777777777781,
        0.59825422222222213, 0.61056600000000016, 0.62296177777777784,
        0.6354402222222223, 0.64800000000000013, 0.66063977777777771,
        0.67335822222222241, 0.686154, 0.69902577777777775, 0.71197222222222212,
        0.72499200000000019, 0.73808377777777789, 0.75124622222222237, 0.764478,
        0.77777777777777779, 0.79114422222222236, 0.80457600000000018,
        0.81807177777777773, 0.83163022222222216, 0.84525000000000006,
        0.8589297777777779, 0.87266822222222218, 0.886464, 0.90031577777777771,
        0.91422222222222216, 0.92818200000000006, 0.94219377777777791,
        0.95625622222222229, 0.970368, 0.98452777777777778, 0.99873422222222241,
        1.012986, 1.0272817777777776, 1.0416202222222222, 1.056,
        1.070419777777778, 1.0848782222222224, 1.099374, 1.1139057777777779,
        1.1284722222222221, 1.143072, 1.1577037777777777, 1.1723662222222222,
        1.187058, 1.2017777777777776, 1.2165242222222223, 1.231296,
        1.2460917777777778, 1.2609102222222222, 1.2757499999999997,
        1.2906097777777779, 1.3054882222222224, 1.320384, 1.3352957777777776,
        1.350222222222222, 1.365162, 1.3801137777777777, 1.3950762222222219,
        1.4100479999999997, 1.4250277777777776, 1.4400142222222223, 1.455006,
        1.4700017777777779, 1.4850002222222223, 1.5, 1.5149980000000003,
        1.5299840000000002, 1.5449460000000002, 1.5598720000000001, 1.57475,
        1.5895680000000003, 1.6043140000000002, 1.6189760000000002, 1.633542,
        1.648, 1.662338, 1.6765439999999998, 1.690606, 1.7045120000000002,
        1.71825, 1.7318080000000002, 1.7451739999999998, 1.7583360000000001,
        1.7712820000000002, 1.784, 1.796478, 1.8087039999999999,
        1.8206660000000001, 1.8323520000000002, 1.84375, 1.854848, 1.865634,
        1.876096, 1.886222, 1.896, 1.905418, 1.914464, 1.923126,
        1.9313920000000002, 1.93925, 1.946688, 1.953694, 1.960256,
        1.9663620000000002, 1.972, 1.977158, 1.981824, 1.985986, 1.989632,
        1.99275, 1.995328, 1.997354, 1.998816, 1.999702, 2.0, 2.00000995,
        2.0000396, 2.00008865, 2.0001568, 2.00024375, 2.0003492, 2.00047285,
        2.0006144, 2.00077355, 2.00095, 2.00114345, 2.0013536, 2.00158015,
        2.0018228, 2.00208125, 2.0023552000000002, 2.00264435, 2.0029484,
        2.00326705, 2.0036, 2.00394695, 2.0043076, 2.00468165, 2.0050688,
        2.00546875, 2.0058812, 2.00630585, 2.0067424, 2.00719055, 2.00765,
        2.00812045, 2.0086016, 2.00909315, 2.0095948, 2.01010625, 2.0106272,
        2.01115735, 2.0116964, 2.01224405, 2.0128, 2.01336395, 2.0139356,
        2.01451465, 2.0151008, 2.01569375, 2.0162932, 2.01689885, 2.0175104,
        2.01812755, 2.01875, 2.01937745, 2.0200096, 2.02064615, 2.0212868,
        2.02193125, 2.0225792, 2.02323035, 2.0238844, 2.02454105, 2.0252,
        2.02586095, 2.0265236, 2.02718765, 2.0278528, 2.02851875, 2.0291852,
        2.02985185, 2.0305184, 2.03118455, 2.03185, 2.03251445, 2.0331776,
        2.03383915, 2.0344988, 2.03515625, 2.0358112, 2.03646335, 2.0371124,
        2.03775805, 2.0384, 2.03903795, 2.0396716, 2.04030065, 2.0409248,
        2.04154375, 2.0421572, 2.04276485, 2.0433664, 2.04396155, 2.04455,
        2.04513145, 2.0457056, 2.04627215, 2.0468308, 2.04738125, 2.0479232,
        2.04845635, 2.0489804, 2.04949505, 2.05, 2.05049495, 2.0509796,
        2.05145365, 2.0519168, 2.05236875, 2.0528092, 2.05323785, 2.0536544,
        2.05405855, 2.05445, 2.05482845, 2.0551936, 2.05554515, 2.0558828,
        2.05620625, 2.0565152, 2.05680935, 2.0570884, 2.05735205, 2.0576,
        2.05783195, 2.0580476, 2.05824665, 2.0584288, 2.05859375, 2.0587412,
        2.05887085, 2.0589824, 2.05907555, 2.05915, 2.05920545, 2.0592416,
        2.05925815, 2.0592548, 2.05923125, 2.0591871999999998, 2.05912235,
        2.0590364, 2.05892905, 2.0588, 2.05864895, 2.0584756, 2.05827965,
        2.0580608, 2.05781875, 2.0575532, 2.05726385, 2.0569504, 2.05661255,
        2.05625, 2.05586245, 2.0554496, 2.05501115, 2.0545468, 2.05405625,
        2.0535392, 2.0529953499999998, 2.0524244, 2.05182605, 2.0512, 2.05054595,
        2.0498636, 2.04915265, 2.0484128, 2.04764375, 2.0468452, 2.04601685,
        2.0451584, 2.04426955, 2.0433499999999998, 2.04239945, 2.0414176,
        2.04040415, 2.0393588, 2.03828125, 2.0371712, 2.03602835, 2.0348524,
        2.0336430500000002, 2.0324, 2.03112295, 2.0298116, 2.02846565, 2.0270848,
        2.02566875, 2.0242172, 2.02272985, 2.0212064, 2.01964655, 2.01805,
        2.01641645, 2.0147456, 2.0130371499999997, 2.0112908, 2.00950625,
        2.0076832, 2.0058213499999997, 2.0039203999999997, 2.00198005, 2.0,
        1.9979690079999999, 1.995876864, 1.9937248159999998, 1.991514112,
        1.989246, 1.986921728, 1.984542544, 1.982109696, 1.9796244319999998,
        1.977088, 1.974501648, 1.971866624, 1.969184176, 1.9664555519999998,
        1.963682, 1.960864768, 1.958005104, 1.9551042559999998,
        1.9521634719999998, 1.949184, 1.946167088, 1.943113984,
        1.9400259359999998, 1.9369041919999999, 1.93375, 1.9305646079999998,
        1.9273492639999998, 1.9241052159999998, 1.9208337119999999, 1.917536,
        1.914213328, 1.910866944, 1.9074980959999999, 1.904108032, 1.900698,
        1.897269248, 1.8938230239999998, 1.8903605759999997, 1.8868831519999998,
        1.883392, 1.879888368, 1.8763735039999998, 1.872848656,
        1.8693150719999998, 1.865774, 1.8622266879999998, 1.858674384,
        1.8551183359999999, 1.8515597919999998, 1.8479999999999999, 1.844440208,
        1.8408816639999999, 1.8373256159999998, 1.8337733119999997, 1.830226,
        1.826684928, 1.8231513439999998, 1.8196264959999997, 1.8161116319999997,
        1.812608, 1.809116848, 1.8056394239999998, 1.8021769759999997,
        1.7987307519999998, 1.795302, 1.7918919679999998, 1.7885019039999999,
        1.7851330559999998, 1.7817866719999997, 1.778464, 1.7751662879999999,
        1.771894784, 1.7686507359999997, 1.7654353919999997, 1.7622499999999999,
        1.7590958079999999, 1.755974064, 1.7528860159999997, 1.7498329119999998,
        1.746816, 1.7438365279999999, 1.740895744, 1.7379948959999998,
        1.7351352319999997, 1.732318, 1.729544448, 1.7268158239999998,
        1.7241333759999997, 1.7214983519999998, 1.718912, 1.716375568,
        1.713890304, 1.7114574559999998, 1.7090782719999997, 1.7067539999999999,
        1.7044858879999998, 1.7022751839999999, 1.7001231359999998,
        1.6980309919999999, 1.696, 1.693905936, 1.691628288, 1.6891738719999998,
        1.6865495039999998, 1.683762, 1.6808181759999998, 1.6777248479999998,
        1.6744888319999998, 1.6711169439999998, 1.667616, 1.663992816,
        1.6602542079999998, 1.6564069919999997, 1.6524579839999998, 1.648414,
        1.6442818559999999, 1.6400683679999999, 1.6357803519999998,
        1.6314246239999997, 1.627008, 1.622537296, 1.618019328,
        1.6134609119999999, 1.6088688639999997, 1.60425, 1.599611136,
        1.594959088, 1.590300672, 1.5856427039999998, 1.580992, 1.576355376,
        1.5717396479999999, 1.5671516319999999, 1.5625981439999999, 1.558086,
        1.553622016, 1.549213008, 1.544865792, 1.5405871839999998, 1.536384,
        1.5322630560000001, 1.528231168, 1.5242951519999999, 1.5204618239999999,
        1.5167380000000001, 1.513130496, 1.509646128, 1.506291712, 1.503074064,
        1.5, 1.4969836796875, 1.4939356874999998, 1.4908574765624998,
        1.4877504999999998, 1.4846162109375, 1.4814560625, 1.4782715078125,
        1.475064, 1.4718349921874998, 1.4685859375, 1.4653182890625, 1.4620335,
        1.4587330234374998, 1.4554183124999998, 1.4520908203125, 1.448752,
        1.4454033046875, 1.4420461875, 1.4386821015624998, 1.4353125,
        1.4319388359375, 1.4285625624999998, 1.4251851328124998,
        1.4218079999999997, 1.4184326171875, 1.4150604375, 1.4116929140624999,
        1.4083314999999998, 1.4049776484374998, 1.4016328125, 1.3982984453125,
        1.394976, 1.3916669296875, 1.3883726874999998, 1.3850947265625,
        1.3818344999999999, 1.3785934609375, 1.3753730624999998,
        1.3721747578124999, 1.369, 1.3658502421875, 1.3627269375,
        1.3596315390624998, 1.3565654999999999, 1.3535302734375, 1.3505273125,
        1.3475580703124999, 1.3446239999999998, 1.3417265546875, 1.3388671875,
        1.3360473515625, 1.3332685, 1.3305320859374998, 1.3278395625,
        1.3251923828125, 1.322592, 1.3200398671875, 1.3175374375,
        1.3150861640624998, 1.3126875, 1.3103428984375, 1.3080538124999999,
        1.3058216953125, 1.303648, 1.3015341796875, 1.2994816875,
        1.2974919765625, 1.2955665, 1.2937067109375, 1.2919140625,
        1.2901900078125, 1.288536, 1.2869534921874999, 1.2854439375,
        1.2840087890625, 1.2826495, 1.2813675234375, 1.2801643125,
        1.2790413203125, 1.278, 1.2769725772594753, 1.2758916384839649,
        1.2747591778425655, 1.273577189504373, 1.2723476676384839,
        1.2710726064139941, 1.269754, 1.2683938425655976, 1.2669941282798833,
        1.2655568513119533, 1.2640840058309037, 1.2625775860058308,
        1.261039586005831, 1.259472, 1.2578768221574343, 1.2562560466472301,
        1.254611667638484, 1.2529456793002915, 1.2512600758017491,
        1.2495568513119535, 1.2478379999999998, 1.2461055160349854,
        1.2443613935860058, 1.2426076268221573, 1.2408462099125364,
        1.2390791370262388, 1.2373084023323615, 1.235536, 1.2337639241982505,
        1.23199416909621, 1.2302287288629736, 1.2284695976676385,
        1.2267187696793003, 1.2249782390670554, 1.22325, 1.2215360466472303,
        1.2198383731778426, 1.2181589737609331, 1.2164998425655975,
        1.2148629737609329, 1.2132503615160348, 1.2116639999999999,
        1.2101058833819243, 1.2085780058309037, 1.2070823615160351,
        1.2056209446064139, 1.204195749271137, 1.2028087696793004, 1.201462,
        1.2001574344023325, 1.1988970670553936, 1.1976828921282798,
        1.1965169037900876, 1.1954010962099124, 1.1943374635568513, 1.193328,
        1.1923746997084548, 1.1914795568513119, 1.1906445655976676,
        1.189871720116618, 1.1891630145772594, 1.188520443148688, 1.187946,
        1.1874416793002915, 1.1870094752186588, 1.1866513819241982,
        1.1863693935860058, 1.1861655043731778, 1.1860417084548105, 1.186,
        1.1860427656249999, 1.186169625, 1.186378421875, 1.186667,
        1.187033203125, 1.187474875, 1.187989859375, 1.1885759999999999,
        1.189231140625, 1.189953125, 1.190739796875, 1.191589, 1.192498578125,
        1.193466375, 1.194490234375, 1.195568, 1.196697515625, 1.197876625,
        1.199103171875, 1.200375, 1.201689953125, 1.203045875, 1.204440609375,
        1.205872, 1.2073378906249999, 1.2088361250000002, 1.210364546875,
        1.211921, 1.213503328125, 1.215109375, 1.2167369843750002, 1.218384,
        1.220048265625, 1.221727625, 1.223419921875, 1.2251230000000002,
        1.226834703125, 1.2285528749999999, 1.230275359375, 1.232,
        1.2337246406250002, 1.235447125, 1.237165296875, 1.238877,
        1.240580078125, 1.2422723750000002, 1.243951734375, 1.245616,
        1.2472630156250002, 1.248890625, 1.2504966718750001, 1.252079,
        1.253635453125, 1.255163875, 1.2566621093750001, 1.2581280000000001,
        1.259559390625, 1.260954125, 1.2623100468750001, 1.263625,
        1.2648968281250001, 1.266123375, 1.267302484375, 1.268432,
        1.269509765625, 1.270533625, 1.271501421875, 1.2724110000000002,
        1.273260203125, 1.274046875, 1.2747688593750002, 1.2754240000000001,
        1.2760101406250002, 1.276525125, 1.276966796875, 1.277333,
        1.277621578125, 1.277830375, 1.277957234375, 1.278, 1.2780923790087464,
        1.2783667871720117, 1.2788191311953354, 1.2794453177842566,
        1.2802412536443148, 1.2812028454810496, 1.282326, 1.2836066239067057,
        1.2850406239067056, 1.2866239067055394, 1.2883523790087466,
        1.2902219475218659, 1.2922285189504377, 1.2943680000000002,
        1.2966362973760934, 1.2990293177842569, 1.3015429679300292,
        1.3041731545189508, 1.30691578425656, 1.3097667638483965,
        1.3127220000000004, 1.3157773994169097, 1.3189288688046652,
        1.3221723148688049, 1.3255036443148689, 1.3289187638483968,
        1.3324135801749273, 1.3359840000000005, 1.3396259300291549,
        1.34333527696793, 1.3471079475218661, 1.3509398483965016,
        1.3548268862973765, 1.3587649679300293, 1.3627500000000001,
        1.3667778892128284, 1.3708445422740527, 1.3749458658892133,
        1.3790777667638487, 1.3832361516034986, 1.3874169271137029,
        1.3916160000000002, 1.3958292769679306, 1.4000526647230322,
        1.4042820699708456, 1.40851339941691, 1.412742559766764,
        1.4169654577259481, 1.4211780000000003, 1.4253760932944606,
        1.4295556443148691, 1.4337125597667639, 1.4378427463556855,
        1.4419421107871724, 1.4460065597667637, 1.4500320000000004,
        1.45401433819242, 1.4579494810495632, 1.4618333352769681,
        1.4656618075801751, 1.4694308046647233, 1.4731362332361517,
        1.4767740000000005, 1.4803400116618077, 1.4838301749271137,
        1.487240396501458, 1.4905665830903791, 1.4938046413994173,
        1.496950478134111, 1.5, 1.5030544640000003, 1.5062149120000001,
        1.5094769280000004, 1.5128360960000002, 1.516288, 1.5198282240000003,
        1.523452352, 1.5271559680000004, 1.5309346560000001, 1.534784,
        1.5386995840000004, 1.542676992, 1.5467118080000004, 1.5507996160000002,
        1.554936, 1.5591165440000003, 1.563336832, 1.5675924480000005,
        1.5718789760000003, 1.576192, 1.5805271040000004, 1.5848798720000001,
        1.5892458880000004, 1.5936207360000003, 1.598, 1.6023792640000003,
        1.6067541120000002, 1.6111201280000005, 1.6154728960000002, 1.619808,
        1.6241210240000004, 1.628407552, 1.6326631680000006, 1.6368834560000003,
        1.641064, 1.6452003840000005, 1.6492881920000002, 1.6533230080000005,
        1.6573004160000002, 1.661216, 1.6650653440000003, 1.6688440320000002,
        1.6725476480000006, 1.6761717760000003, 1.679712, 1.6831639040000004,
        1.6865230720000002, 1.6897850880000005, 1.6929455360000003, 1.696,
        1.6990308920000001, 1.702122336, 1.7052724840000004, 1.708479488,
        1.7117415, 1.7150566720000002, 1.718423156, 1.7218391040000003,
        1.725302668, 1.728812, 1.7323652520000004, 1.735960576,
        1.7395961240000004, 1.743270048, 1.7469805, 1.7507256320000002,
        1.7545035960000002, 1.7583125440000005, 1.762150628, 1.766016,
        1.7699068120000003, 1.773821216, 1.7777573640000004, 1.781713408,
        1.7856874999999999, 1.7896777920000002, 1.793682436, 1.7976995840000005,
        1.8017273880000002, 1.805764, 1.8098075720000002, 1.813856256,
        1.8179082040000003, 1.8219615680000003, 1.8260144999999999,
        1.8300651520000004, 1.834111676, 1.8381522240000003, 1.842184948,
        1.8462079999999998, 1.8502195320000003, 1.854217696, 1.8582006440000005,
        1.8621665280000002, 1.8661135, 1.8700397120000003, 1.873943316,
        1.8778224640000003, 1.8816753080000002, 1.8855, 1.8892946920000002,
        1.8930575360000002, 1.8967866840000003, 1.9004802880000002, 1.9041365,
        1.9077534720000002, 1.911329356, 1.9148623040000003, 1.918350468,
        1.921792, 1.9251850520000002, 1.9285277760000001, 1.9318183240000004,
        1.935054848, 1.9382355, 1.9413584320000004, 1.944421796,
        1.9474237440000004, 1.950362428, 1.953236, 1.9560426120000003,
        1.9587804160000002, 1.9614475640000002, 1.964042208, 1.9665625,
        1.9690065920000002, 1.971372636, 1.9736587840000002, 1.9758631880000002,
        1.977984, 1.980019372, 1.981967456, 1.9838264040000002, 1.985594368,
        1.9872695, 1.988849952, 1.990333876, 1.9917194240000002,
        1.9930047480000002, 1.9941879999999998, 1.995267332, 1.996240896,
        1.9971068440000002, 1.997863328, 1.9985085, 1.999040512, 1.999457516,
        1.999757664, 1.999939108, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0,
        2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0,
        2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0,
        2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0,
        2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0,
        2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0,
        2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0,
        2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0,
        2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0,
        2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0,
        2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0,
        2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0,
        2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0,
        2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0,
        2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0,
        2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0,
        2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0,
        2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0,
        2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0,
        2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0,
        2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0,
        2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0,
        2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0,
        2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0,
        2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0,
        2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0,
        2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0,
        2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0,
        2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0,
        2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0,
        2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0,
        2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0,
        2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0,
        2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0,
        2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0,
        2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0,
        2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0,
        2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0,
        2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0,
        2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0,
        2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0,
        2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0,
        2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0,
        2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0,
        2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0,
        2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0,
        2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0,
        2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0,
        2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0,
        2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0,
        2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0,
        2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0,
        2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0,
        2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0,
        2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0,
        2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0,
        2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0,
        2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0,
        2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0,
        2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0,
        2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0,
        2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0,
        2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0,
        2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0,
        2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0,
        2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0,
        2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0,
        2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0,
        2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0,
        2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0,
        2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0,
        2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0,
        2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0,
        2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0,
        2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0,
        2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0,
        2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0,
        2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0,
        2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0,
        2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0,
        2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0,
        2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0,
        2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0,
        2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0,
        2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0,
        2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0,
        2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0,
        2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0,
        2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0,
        2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0,
        2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0,
        2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0,
        2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0,
        2.0, 2.0, 2.0, 2.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -0.00020403841433610362,
        -0.00081067611601995523, -0.0018116967930648662, -0.0031988841334841473,
        -0.0049640218252909717, -0.007098893556498901, -0.0095952830151211348,
        -0.012444973889170985, -0.015639749866661758, -0.01917139463560651,
        -0.023031691884019049, -0.027212425299912451, -0.031705378571300021,
        -0.036502335386195073, -0.041595079432610559, -0.046975394398560487,
        -0.052635063972057833, -0.058565871841115918, -0.064759601693748031,
        -0.071208037217967035, -0.077902962101787154, -0.084836160033221225,
        -0.0919994147002826, -0.099384509790984579, -0.10698322899333991,
        -0.11478735599536298, -0.12278867448506658, -0.13097896815046403,
        -0.13935002067956861, -0.14789361576039306, -0.1566015370809519,
        -0.16546556832925782, -0.17447749319332412, -0.18362909536116409,
        -0.19291215852079052, -0.20231846636021786, -0.21183980256745885,
        -0.22146795083052684, -0.23119469483743504, -0.24101181827619611,
        -0.25091110483482476, -0.26088433820133367, -0.27092330206373605,
        -0.28101978011004525, -0.29116555602827388, -0.3013524135064366,
        -0.31157213623254615, -0.32181650789461574, -0.33207731218065878,
        -0.34234633277868765, -0.35261535337671734, -0.36287615766276032,
        -0.37312052932482986, -0.38334025205093947, -0.39352710952910147,
        -0.40367288544733082, -0.41376936349364, -0.42380832735604246,
        -0.4337815607225512, -0.44368084728117929, -0.45349797071994097,
        -0.46322471472684923, -0.47285286298991713, -0.48237419919715824,
        -0.49178050703658488, -0.501063570196212, -0.51021517236405189,
        -0.51922709722811811, -0.528091128476424, -0.53679904979698223,
        -0.54534264487780737, -0.5537136974069119, -0.56190399107230937,
        -0.569905309562013, -0.57770943656403539, -0.58530815576639139,
        -0.59269325085709323, -0.59985650552415459, -0.60678970345558869,
        -0.61348462833940831, -0.6199330638636279, -0.6261267937162599,
        -0.632057601585318, -0.63771727115881538, -0.64309758612476486,
        -0.64819033017118066, -0.65298728698607555, -0.65748024025746321,
        -0.66166097367335663, -0.66552127092176883, -0.6690529156907139,
        -0.67224769166820475, -0.67509738254225438, -0.67759377200087667,
        -0.67972864373208441, -0.68149378142389139, -0.6828809687643107,
        -0.68388198944135536, -0.68448862714303926, -0.6846926655573754,
        -0.6840711294413554, -0.68223490142389132, -0.67922655200087634,
        -0.67508865166820431, -0.66986377092176885, -0.66359448025746293,
        -0.65632335017118038, -0.6480929511588146, -0.63894585371625923,
        -0.62892462833940832, -0.61807184552415417, -0.606430075766391,
        -0.594041889562012, -0.580949857406911, -0.56719654979698231,
        -0.55282453722811764, -0.53787639019621136, -0.522394679197157,
        -0.50642197472684813, -0.49000084728117926, -0.47317386735604172,
        -0.45598360544733019, -0.43847263205093812, -0.420683517662759,
        -0.40265883277868775, -0.38444114789461514, -0.366073033506436,
        -0.34759706011004393, -0.32905579820133235, -0.31049181827619615,
        -0.29194769083052619, -0.27346598636021724, -0.25508927536116283,
        -0.23686012832925651, -0.21882111576039304, -0.20101480815046346,
        -0.18348377599536236, -0.1662705897909833, -0.14941782003322002,
        -0.13296803721796702, -0.11696381184111537, -0.10144771439855993,
        -0.086462315386194089, -0.072050185299911584, -0.058253894635606485,
        -0.045116013889170636, -0.03267911355649844, -0.020985764133483409,
        -0.010078536116019388, 0.0, 0.00965622805251692, 0.01932470286376432,
        0.029005110414287574, 0.038697136684632052, 0.048400467655342436,
        0.058114789306965481, 0.067839787620045874, 0.077575148575128969,
        0.087320558152760158, 0.0970757023334841, 0.10684026709784758,
        0.11661393842639527, 0.12639640229967253, 0.13618734469822472,
        0.14598645160259655, 0.15579340899333477, 0.16560790285098403,
        0.17542961915608976, 0.18525824388919729, 0.19509346303085129,
        0.20493496256159857, 0.21478242846198375, 0.22463554671255223,
        0.2344940032938494, 0.24435748418641989, 0.25422567537081053,
        0.26409826282756593, 0.27397493253723149, 0.28385537048035259,
        0.29373926263747385, 0.30362629498914212, 0.31351615351590206,
        0.323408524198299, 0.33330309301687838, 0.34319954595218477,
        0.353097568984765, 0.3629968480951638, 0.37289706926392646,
        0.38279791847159833, 0.39269908169872414, 0.40260024492585067,
        0.41250109413352254, 0.4224013153022852, 0.432300594412684,
        0.44219861744526351, 0.45209507038057062, 0.46198963919915,
        0.47188200988154694, 0.48177186840830682, 0.49165890075997443,
        0.50154279291709647, 0.51142323086021746, 0.52129990056988307,
        0.53117248802663852, 0.54104067921102839, 0.55090416010359955,
        0.5607626166848968, 0.57061573493546525, 0.58046320083585046,
        0.590304700366597, 0.60013991950825174, 0.60996854424135927,
        0.619790260546465, 0.62960475440411423, 0.63941171179485179,
        0.64921081869922426, 0.65900176109777653, 0.66878422497105372,
        0.67855789629960139, 0.68832246106396422, 0.69807760524468887,
        0.70782301482232, 0.71755837577740311, 0.72728337409048349,
        0.73699769574210583, 0.74670102671281691, 0.7563930529831614,
        0.76607346053368464, 0.77574193534493208, 0.78539816339744828,
        0.79511480718166616, 0.80496217531184944, 0.81493642295429336,
        0.82503370527529307, 0.83525017744114283, 0.84558199461813943,
        0.85602531197257714, 0.8665762846707511, 0.87723106787895655,
        0.88798581676348765, 0.89883668649064208, 0.90977983222671177,
        0.92081140913799331, 0.93192757239078361, 0.94312447715137437,
        0.95439827858606419, 0.96574513186114486, 0.97716119214291308,
        0.98864261459766567, 1.0001855543916947, 1.0117861666912982,
        1.0234406066627681, 1.0351450294724014, 1.0468955902864947,
        1.0586884442713398, 1.0705197465932355, 1.0823856524184732,
        1.0942823169133498, 1.106205895244162, 1.1181525425772021,
        1.1301184140787679, 1.1420996649151516, 1.1540924502526497,
        1.1660929252575596, 1.1780972450961724, 1.190101564934787,
        1.2021020399396951, 1.2140948252771933, 1.2260760761135787,
        1.2380419476151427, 1.2499885949481844, 1.2619121732789951,
        1.2738088377738719, 1.2856747435991112, 1.297506045921005,
        1.3092988999058517, 1.3210494607199434, 1.3327538835295767,
        1.3444083235010484, 1.3560089358006502, 1.3675518755946807,
        1.3790332980494318, 1.3904493583312, 1.4017962116062823,
        1.4130700130409704, 1.424266917801563, 1.4353830810543515,
        1.4464146579656332, 1.4573578037017043, 1.4682086734288573,
        1.4789634223133898, 1.4896182055215945, 1.5001691782197679,
        1.5106124955742062, 1.5209443127512019, 1.5311607849170532,
        1.5412580672380523, 1.5512323148804954, 1.5610796830106795,
        1.5707963267948966, 1.5804525548474142, 1.590121029658661,
        1.5998014372091833, 1.6094934634795286, 1.619196794450239,
        1.6289111161018628, 1.6386361144149424, 1.6483714753700249,
        1.6581168849476566, 1.6678720291283806, 1.6776365938927449,
        1.6874102652212919, 1.6971927290945683, 1.7069836714931212,
        1.7167827783974932, 1.726589735788232, 1.7364042296458806,
        1.7462259459509857, 1.7560545706840938, 1.7658897898257477,
        1.7757312893564958, 1.7855787552568803, 1.7954318735074482,
        1.805290330088746, 1.8151538109813163, 1.8250220021657078,
        1.8348945896224624, 1.8447712593321273, 1.8546516972752491,
        1.8645355894323703, 1.8744226217840394, 1.8843124803107987,
        1.8942048509931948, 1.9040994198117749, 1.9139958727470812,
        1.9238938957796621, 1.9337931748900603, 1.9436933960588223,
        1.9535942452664947, 1.9634954084936207, 1.9733965717207478,
        1.9832974209284191, 1.9931976420971809, 2.0030969212075806,
        2.01299494424016, 2.0228913971754676, 2.0327859659940462,
        2.0426783366764427, 2.0525681952032033, 2.0624552275548709,
        2.0723391197119936, 2.0822195576551139, 2.0920962273647787,
        2.101968814821535, 2.1118370060059246, 2.1217004868984968,
        2.131558943479793, 2.1414120617303611, 2.1512595276307467,
        2.1611010271614934, 2.1709362463031487, 2.1807648710362555,
        2.1905865873413606, 2.2004010811990105, 2.210208038589748,
        2.2200071454941215, 2.2297980878926729, 2.2395805517659508,
        2.2493542230944978, 2.2591187878588608, 2.2688739320395861,
        2.2786193416172162, 2.2883547025723, 2.29807970088538,
        2.3077940225370019, 2.3174973535077141, 2.3271893797780576,
        2.3368697873285815, 2.3465382621398283, 2.3561944901923448,
        2.3659111339765633, 2.3757585021067458, 2.3857327497491907,
        2.3958300320701897, 2.4060465042360395, 2.4163783214130365,
        2.4268216387674735, 2.4373726114656487, 2.4480273946738529,
        2.4587821435583841, 2.4696330132855389, 2.4805761590216084,
        2.4916077359328916, 2.50272389918568, 2.513920803946271,
        2.5251946053809609, 2.5365414586560413, 2.5479575189378112,
        2.5594389413925622, 2.570981881186591, 2.5825824934861945,
        2.5942369334576645, 2.6059413562672997, 2.617691917081391,
        2.6294847710662363, 2.6413160733881318, 2.6531819792133695,
        2.6650786437082479, 2.6770022220390586, 2.6889488693720986,
        2.7009147408736647, 2.7128959917100479, 2.7248887770475481,
        2.7368892520524559, 2.748893571891069, 2.7608978917296838,
        2.7728983667345917, 2.7848911520720918, 2.7968724029084751,
        2.8088382744100393, 2.8207849217430812, 2.8327085000738919,
        2.8446051645687698, 2.8564710703940079, 2.8683023727159016,
        2.8800952267007482, 2.89184578751484, 2.9035502103244748,
        2.9152046502959452, 2.926805262595547, 2.9383482023895775,
        2.9498296248443285, 2.961245685126098, 2.9725925384011789,
        2.9838663398358669, 2.9950632445964596, 3.0061794078492481,
        3.0172109847605313, 3.0281541304966009, 3.0390050002237539,
        3.0497597491082864, 3.0604145323164911, 3.0709655050146658,
        3.0814088223691027, 3.0917406395460985, 3.1019571117119495,
        3.112054394032949, 3.1220286416753935, 3.131876009805576,
        3.1415926535897931, 3.1516711897058141, 3.1625784177232776,
        3.1742717671462932, 3.1867086674789649, 3.1998465482253997,
        3.2136428388897067, 3.2280549689759885, 3.2430403679883555,
        3.25855646543091, 3.27456069080776, 3.2910104736230155,
        3.307863243380778, 3.3250764295851578, 3.3426074617402577,
        3.3604137693501861, 3.3784527819190524, 3.3966819289509571,
        3.4150586399500131, 3.4335403444203205, 3.4520844718659891,
        3.4706484517911282, 3.4891897136998384, 3.5076656870962317,
        3.5260338014844095, 3.5442514863684811, 3.562276171252555,
        3.5800652856407327, 3.5975762590371261, 3.6147665209458362,
        3.6315935008709723, 3.6480146283166439, 3.6639873327869514,
        3.6794690437860069, 3.6944171908179122, 3.7087892033867758,
        3.7225425109967061, 3.7356345431518063, 3.7480227293561859,
        3.7596644991139483, 3.7705172819292017, 3.780538507306054,
        3.7896856047486085, 3.7979160037609749, 3.8051871338472569,
        3.8114564245115621, 3.8166813052579984, 3.82081920559067,
        3.8238275550136849, 3.8256637830311488, 3.8262853191471686,
        3.8260812807328324, 3.8254746430311486, 3.8244736223541036,
        3.8230864350136846, 3.8213212973218775, 3.8191864255906696,
        3.8166900361320475, 3.8138403452579976, 3.8106455692805068,
        3.8071139245115622, 3.8032536272631492, 3.799072893847256,
        3.7945799405758684, 3.7897829837609733, 3.7846902397145579,
        3.7793099247486079, 3.7736502551751108, 3.7677194473060522,
        3.7615257174534205, 3.7550772819292018, 3.7483823570453811,
        3.7414491591139472, 3.7342859044468857, 3.726900809356184,
        3.7193020901538287, 3.711497963151805, 3.7034966446621018,
        3.6953063509967041, 3.6869352984676, 3.6783917033867755,
        3.6696837820662163, 3.660819750817911, 3.6518078259538438,
        3.6426562237860045, 3.6333731606263782, 3.62396685278695,
        3.6144455165797096, 3.6048173683166409, 3.5950906243097336,
        3.5852735008709726, 3.575374214312343, 3.5654009809458351,
        3.5553620170834317, 3.5452655390371235, 3.5351197631188946,
        3.524932905640731, 3.5147131829146225, 3.5044688112525519,
        3.49420800696651, 3.4839389863684809, 3.4736699657704504,
        3.4634091614844085, 3.4531647898223379, 3.4429450670962289,
        3.4327582096180671, 3.4226124336998369, 3.4125159556535287,
        3.4024769917911257, 3.3925037584246174, 3.3826044718659896,
        3.3727873484272268, 3.3630606044203195, 3.3534324561572508,
        3.3439111199500102, 3.3345048121105836, 3.3252217489509563,
        3.3160701467831166, 3.30705822191905, 3.2981941906707446,
        3.2894862693501863, 3.2809426742693608, 3.2725716217402567,
        3.2643813280748586, 3.2563800095851558, 3.2485758825831335,
        3.2409771633807769, 3.2335920682900756, 3.2264288136230137,
        3.2194956156915797, 3.2128006908077604, 3.2063522552835404,
        3.2001585254309086, 3.1942277175618505, 3.1885680479883534,
        3.1831877330224039, 3.178094988975988, 3.1732980321610933,
        3.1688050788897053, 3.1646243454738121, 3.1607640482254,
        3.1572324034564545, 3.1540376274789641, 3.1511879366049143,
        3.1486915471462922, 3.1465566754150842, 3.1447915377232771,
        3.1434043503828581, 3.1424033297058132, 3.14179669200413,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
        3.1415926535897931, 3.1415926535897931, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0001200000000000034, 0.00048000000000000511,
        0.0010800000000000052, 0.0019200000000000035, 0.003,
        0.0043200000000000209, 0.005880000000000018, 0.0076800000000000141,
        0.0097200000000000081, 0.012, 0.014520000000000038, 0.017279999999999979,
        0.020280000000000024, 0.023520000000000072, 0.027000000000000003,
        0.030720000000000056, 0.034679999999999968, 0.038880000000000033,
        0.043320000000000095, 0.048, 0.052920000000000071, 0.058079999999999965,
        0.063480000000000036, 0.069120000000000126, 0.075, 0.0811200000000001,
        0.087479999999999947, 0.094080000000000052, 0.10092000000000015,
        0.10800000000000001, 0.1153200000000001, 0.12287999999999993,
        0.13068000000000007, 0.13872000000000018, 0.14700000000000002,
        0.15552000000000013, 0.16427999999999995, 0.17328000000000007,
        0.18252000000000021, 0.192, 0.20172000000000015, 0.21168000000000028,
        0.22188000000000008, 0.23232000000000022, 0.243, 0.25392000000000015,
        0.26508000000000032, 0.27648000000000011, 0.28812000000000026, 0.3,
        0.30135371, 0.30269884, 0.30403539, 0.30536336000000003, 0.30668275,
        0.30799356, 0.30929579, 0.31058944, 0.31187451, 0.31315099999999996,
        0.31441891, 0.31567824, 0.31692898999999997, 0.31817116,
        0.31940474999999996, 0.32062976, 0.32184619, 0.32305404,
        0.32425330999999996, 0.32544399999999996, 0.32662610999999997,
        0.32779964, 0.32896458999999995, 0.33012095999999996,
        0.33126874999999995, 0.33240795999999995, 0.33353858999999997,
        0.33466063999999995, 0.33577410999999996, 0.33687899999999993,
        0.33797531, 0.33906304, 0.34014218999999996, 0.34121275999999995,
        0.34227474999999996, 0.34332815999999994, 0.34437299,
        0.34540923999999995, 0.34643691, 0.34745599999999993,
        0.34846650999999995, 0.34946844, 0.35046178999999994,
        0.35144655999999996, 0.3524227499999999, 0.35339035999999996,
        0.35434938999999993, 0.35529983999999992, 0.35624170999999993,
        0.35717499999999991, 0.35809970999999996, 0.35901584,
        0.35992338999999995, 0.36082235999999995, 0.36171274999999992,
        0.3625945599999999, 0.36346778999999996, 0.36433243999999992,
        0.36518850999999997, 0.36603599999999992, 0.36687490999999994,
        0.36770523999999993, 0.36852698999999994, 0.36934015999999992,
        0.37014474999999991, 0.37094075999999992, 0.37172818999999996,
        0.3725070399999999, 0.37327730999999992, 0.3740389999999999,
        0.3747921099999999, 0.37553663999999992, 0.37627258999999991,
        0.37699995999999991, 0.37771874999999988, 0.37842895999999993,
        0.37913058999999993, 0.37982363999999991, 0.38050810999999995,
        0.38118399999999991, 0.38185130999999994, 0.38251003999999994,
        0.3831601899999999, 0.38380175999999994, 0.38443474999999994,
        0.38505915999999996, 0.38567498999999994, 0.38628223999999989,
        0.38688090999999991, 0.3874709999999999, 0.38805250999999991,
        0.38862543999999993, 0.38918978999999992, 0.38974555999999994,
        0.39029274999999991, 0.39083135999999991, 0.39136138999999992,
        0.3918828399999999, 0.39239570999999995, 0.39289999999999992,
        0.3933957099999999, 0.39388283999999996, 0.39436138999999992,
        0.39483135999999991, 0.39529274999999992, 0.39574555999999994,
        0.39618978999999993, 0.39662543999999988, 0.39705250999999991,
        0.39747099999999991, 0.39788090999999992, 0.39828223999999995,
        0.39867498999999995, 0.39905915999999991, 0.39943474999999995,
        0.3998017599999999, 0.40016018999999992, 0.4005100399999999,
        0.40085130999999996, 0.40118399999999993, 0.40150810999999992,
        0.40182363999999993, 0.40213058999999995, 0.40242895999999989,
        0.4027187499999999, 0.40299995999999993, 0.40327258999999993,
        0.40353663999999995, 0.40379210999999993, 0.40403899999999993,
        0.40427730999999995, 0.40450703999999993, 0.40472818999999993,
        0.4049407599999999, 0.40514474999999994, 0.40534015999999995,
        0.40552698999999992, 0.40570523999999997, 0.40587490999999992,
        0.40603599999999995, 0.40618850999999995, 0.40633243999999996,
        0.40646778999999994, 0.40659455999999994, 0.40671274999999996,
        0.40682235999999994, 0.40692338999999994, 0.40701583999999991,
        0.40709970999999995, 0.40717499999999995, 0.40724171,
        0.40729983999999997, 0.40734938999999992, 0.40739035999999995,
        0.40742274999999994, 0.40744655999999996, 0.40746178999999993,
        0.40746843999999993, 0.40746650999999995, 0.40745599999999993,
        0.40743690999999993, 0.40740923999999995, 0.40737298999999993,
        0.40732815999999994, 0.40727474999999996, 0.40721275999999995,
        0.40714218999999996, 0.40706304, 0.40697531, 0.406879,
        0.40677410999999997, 0.40666063999999996, 0.40653859, 0.40640796,
        0.40626874999999996, 0.40612096, 0.40596458999999996, 0.40579964,
        0.40562611, 0.405444, 0.40525331, 0.40505404, 0.40484619,
        0.40462975999999995, 0.40440475, 0.40417116000000003, 0.40392899,
        0.40367823999999997, 0.40341890999999996, 0.40315100000000004,
        0.40287450999999996, 0.40258943999999997, 0.40229579,
        0.40199355999999997, 0.40168275000000003, 0.40136336, 0.40103539,
        0.40069884, 0.40035371, 0.4, 0.40186106000000005, 0.40365624000000006,
        0.4053855400000001, 0.40704896000000013, 0.4086465, 0.41017816000000007,
        0.4116439400000001, 0.41304384000000011, 0.4143778600000001, 0.415646,
        0.41684826000000008, 0.41798464000000007, 0.4190551400000001,
        0.42005976000000012, 0.42099850000000005, 0.42187136000000003,
        0.42267834000000004, 0.42341944000000009, 0.42409466000000007, 0.424704,
        0.42524746000000008, 0.42572504000000005, 0.42613674000000007,
        0.42648256000000007, 0.42676250000000004, 0.42697656000000006,
        0.42712474000000006, 0.42720704000000004, 0.42722346000000005,
        0.42717400000000005, 0.42705866000000003, 0.42687744000000005,
        0.42663034000000005, 0.42631736000000003, 0.42593850000000005,
        0.42549376000000005, 0.42498314000000004, 0.42440664000000006,
        0.42376426, 0.42305600000000004, 0.42228186000000006, 0.42144184,
        0.42053594, 0.41956416, 0.41852650000000008, 0.41742296000000007,
        0.41625354000000003, 0.41501824, 0.41371705999999997,
        0.41235000000000005, 0.41091706000000006, 0.40941824000000004,
        0.40785353999999996, 0.40622295999999997, 0.40452650000000007,
        0.40276416000000004, 0.40093594, 0.39904184, 0.39708185999999995,
        0.39505600000000007, 0.39296426, 0.39080664, 0.38858313999999994,
        0.38629375999999993, 0.3839385, 0.38151736, 0.37903033999999997,
        0.37647743999999994, 0.3738586599999999, 0.37117400000000006,
        0.36842346000000004, 0.36560704, 0.36272473999999993,
        0.35977655999999986, 0.35676250000000004, 0.35368256,
        0.35053673999999996, 0.34732503999999992, 0.34404745999999986, 0.340704,
        0.33729465999999997, 0.33381943999999997, 0.33027833999999989,
        0.32667135999999986, 0.3229985, 0.31925975999999995, 0.31545513999999991,
        0.31158463999999986, 0.30764825999999978, 0.303646, 0.29957786,
        0.2954438399999999, 0.29124393999999981, 0.28697815999999976, 0.2826465,
        0.27824895999999993, 0.27378553999999988, 0.26925623999999981,
        0.26466105999999973, 0.26, 0.25790608, 0.25583231999999995,
        0.2537787199999999, 0.2517452799999999, 0.249732, 0.24773887999999997,
        0.24576591999999994, 0.24381311999999991, 0.2418804799999999,
        0.23996800000000001, 0.23807567999999998, 0.23620351999999994,
        0.23435151999999992, 0.2325196799999999, 0.230708, 0.22891647999999998,
        0.22714511999999995, 0.22539391999999991, 0.2236628799999999,
        0.22195199999999998, 0.22026127999999998, 0.21859071999999996,
        0.21694031999999991, 0.2153100799999999, 0.2137, 0.21211007999999998,
        0.21054031999999995, 0.20899071999999994, 0.20746127999999991, 0.205952,
        0.20446287999999996, 0.20299391999999994, 0.20154511999999994,
        0.20011647999999993, 0.198708, 0.19731968, 0.19595152,
        0.19460351999999995, 0.19327567999999995, 0.191968, 0.19068047999999999,
        0.18941311999999996, 0.18816591999999996, 0.18693887999999992, 0.185732,
        0.18454527999999998, 0.18337872, 0.18223231999999998,
        0.18110607999999995, 0.18, 0.1794073828125, 0.17881078125,
        0.17821019531249999, 0.177605625, 0.17699707031250003,
        0.17638453125000003, 0.17576800781250004, 0.17514750000000004,
        0.17452300781250005, 0.17389453125000007, 0.17326207031250007,
        0.17262562500000006, 0.17198519531250006, 0.17134078125000007,
        0.1706923828125001, 0.17004000000000011, 0.1693836328125001,
        0.16872328125000011, 0.1680589453125001, 0.16739062500000013,
        0.16671832031250014, 0.16604203125000014, 0.16536175781250012,
        0.16467750000000012, 0.16398925781250015, 0.16329703125000014,
        0.16260082031250014, 0.16190062500000013, 0.16119644531250013,
        0.16048828125000017, 0.15977613281250017, 0.15906000000000015,
        0.15833988281250014, 0.15761578125000014, 0.15688769531250019,
        0.15615562500000019, 0.15541957031250017, 0.15467953125000017,
        0.15393550781250015, 0.1531875000000002, 0.15243550781250018,
        0.15167953125000017, 0.15091957031250014, 0.15015562500000013,
        0.14938769531250018, 0.14861578125000016, 0.14783988281250016,
        0.14706000000000014, 0.14627613281250013, 0.14548828125000018,
        0.14469644531250014, 0.14390062500000014, 0.14310082031250013,
        0.14229703125000012, 0.14148925781250016, 0.14067750000000015,
        0.13986175781250013, 0.13904203125000011, 0.13821832031250009,
        0.13739062500000015, 0.13655894531250012, 0.13572328125000011,
        0.1348836328125001, 0.13404000000000008, 0.13319238281250012,
        0.13234078125000009, 0.13148519531250008, 0.13062562500000005,
        0.12976207031250003, 0.12889453125000008, 0.12802300781250006,
        0.12714750000000002, 0.12626800781250003, 0.12538453125,
        0.12449707031250004, 0.12360562500000002, 0.12271019531249999,
        0.12181078124999997, 0.12090738281249996, 0.12, 0.11929959183673468,
        0.11856979591836732, 0.11781061224489792, 0.11702204081632647,
        0.11620408163265304, 0.11535673469387751, 0.11447999999999994,
        0.11357387755102034, 0.11263836734693869, 0.11167346938775506,
        0.11067918367346927, 0.10965551020408155, 0.10860244897959181,
        0.10751999999999989, 0.10640816326530607, 0.10526693877551005,
        0.10409632653061215, 0.10289632653061223, 0.10166693877551007,
        0.10040816326530606, 0.099119999999999833, 0.097802448979591741,
        0.096455510204081607, 0.095079183673469236, 0.093673469387755032,
        0.092238367346938577, 0.0907738775510203, 0.08927999999999997,
        0.0877567346938774, 0.086204081632652987, 0.084622040816326322,
        0.083010612244897836, 0.081369795918367321, 0.079699591836734529,
        0.077999999999999931, 0.076271020408163054, 0.074512653061224371,
        0.07272489795918366, 0.070907755102040643, 0.069061224489795847,
        0.067185306122448746, 0.065279999999999866, 0.063345306122448958,
        0.061381224489795737, 0.059387755102040751, 0.057364897959183439,
        0.055312653061224362, 0.053231020408163257, 0.051119999999999818,
        0.048979591836734629, 0.046809795918367106, 0.044610612244897832,
        0.042382040816326544, 0.04012408163265288, 0.037836734693877494,
        0.035519999999999746, 0.033173877551020289, 0.03079836734693879,
        0.028393469387754916, 0.025959183673469347, 0.023495510204081374,
        0.021002448979591734, 0.018480000000000052, 0.015928163265305953,
        0.013346938775510159, 0.010736326530612003, 0.0080963265306121662,
        0.0054269387755102594, 0.0027281632653059357, 0.0,
        -0.0017221875000001429, -0.0034387500000000407, -0.00514968749999994,
        -0.0068550000000000824, -0.00855468749999998, -0.010248750000000122,
        -0.011937187500000024, -0.013619999999999922, -0.015297187500000064,
        -0.016968749999999963, -0.018634687500000104, -0.020295000000000007,
        -0.021949687499999909, -0.023598750000000047, -0.02524218749999995,
        -0.026880000000000084, -0.028512187499999991, -0.030138749999999898,
        -0.031759687500000029, -0.033374999999999939, -0.034984687500000076,
        -0.036588749999999982, -0.038187187499999886, -0.039780000000000024,
        -0.04136718749999993, -0.042948750000000063, -0.044524687499999979,
        -0.046094999999999879, -0.047659687500000013, -0.049218749999999929,
        -0.050772187500000052, -0.052319999999999971, -0.053862187499999874,
        -0.05539875000000001, -0.056929687499999923, -0.058455000000000049,
        -0.059974687499999964, -0.061488749999999877, -0.0629971875,
        -0.064499999999999919, -0.065997187500000054, -0.067488749999999958,
        -0.068974687499999882, -0.070455, -0.071929687499999923,
        -0.073398750000000054, -0.074862187499999955, -0.076319999999999874,
        -0.0777721875, -0.079218749999999921, -0.080659687500000049,
        -0.082094999999999974, -0.083524687499999875, -0.08494875,
        -0.086367187499999928, -0.087780000000000039, -0.089187187499999973,
        -0.0905887499999999, -0.091984687500000023, -0.09337499999999993,
        -0.09475968750000005, -0.096138749999999981, -0.0975121874999999,
        -0.098880000000000023, -0.10024218749999994, -0.10159875000000007,
        -0.1029496875, -0.10429500000000011, -0.10563468750000005,
        -0.10696874999999996, -0.10829718750000007, -0.10962000000000001,
        -0.11093718750000013, -0.11224875000000005, -0.11355468749999999,
        -0.11485500000000008, -0.11614968750000002, -0.11743875000000013,
        -0.11872218750000006, -0.12, -0.12203405247813429, -0.12404641399416917,
        -0.12603708454810519, -0.12800606413994184, -0.12995335276967934,
        -0.13187895043731798, -0.13378285714285726, -0.13566507288629764,
        -0.13752559766763867, -0.13936443148688055, -0.14118157434402356,
        -0.14297702623906719, -0.14475078717201195, -0.14650285714285732,
        -0.14823323615160361, -0.14994192419825098, -0.15162892128279898,
        -0.15329422740524812, -0.15493784256559789, -0.15655976676384853,
        -0.15816000000000024, -0.15973854227405265, -0.16129539358600614,
        -0.16283055393586027, -0.16434402332361531, -0.1658358017492714,
        -0.16730588921282818, -0.16875428571428602, -0.17018099125364455,
        -0.17158600583090394, -0.17296932944606441, -0.17433096209912555,
        -0.17567090379008776, -0.17698915451895067, -0.17828571428571444,
        -0.17956058309037926, -0.18081376093294479, -0.18204524781341136,
        -0.18325504373177864, -0.18444314868804679, -0.18560956268221598,
        -0.1867542857142859, -0.18787731778425684, -0.1889786588921285,
        -0.190058309037901, -0.19111626822157457, -0.19215253644314884,
        -0.19316711370262415, -0.19416000000000019, -0.19513119533527709,
        -0.19608069970845501, -0.19700851311953366, -0.19791463556851335,
        -0.19879906705539374, -0.19966180758017504, -0.20050285714285732,
        -0.20132221574344036, -0.20211988338192438, -0.20289586005830917,
        -0.20365014577259483, -0.20438274052478148, -0.20509364431486887,
        -0.20578285714285727, -0.20645037900874647, -0.20709620991253649,
        -0.20772034985422749, -0.20832279883381929, -0.20890355685131207,
        -0.20946262390670559, -0.21, -0.20874207999999989, -0.20757631999999995,
        -0.20650271999999986, -0.20552127999999992, -0.20463199999999998,
        -0.20383487999999991, -0.20312991999999996, -0.20251711999999991,
        -0.20199647999999995, -0.20156799999999997, -0.20123167999999994,
        -0.20098751999999998, -0.20083551999999996, -0.20077567999999996,
        -0.20080799999999996, -0.20093247999999997, -0.20114911999999996,
        -0.20145792, -0.20185888, -0.20235199999999998, -0.20293728000000003,
        -0.20361471999999997, -0.20438432000000006, -0.20524608000000003,
        -0.20619999999999997, -0.20724608000000005, -0.20838432,
        -0.20961472000000012, -0.21093728000000003, -0.21235199999999996,
        -0.21385888000000011, -0.21545792000000002, -0.21714912000000017,
        -0.21893248000000007, -0.22080799999999998, -0.22277568000000014,
        -0.22483552000000004, -0.22698752000000022, -0.2292316800000001,
        -0.231568, -0.2339964800000002, -0.23651712000000005,
        -0.2391299200000003, -0.24183488000000014, -0.24463200000000002,
        -0.24752128000000023, -0.25050272000000007, -0.25357632000000035,
        -0.25674208000000021, -0.26, -0.26466106000000039, -0.26925624000000015,
        -0.27378554000000055, -0.27824896000000027, -0.2826465,
        -0.28697816000000037, -0.29124394000000015, -0.29544384000000051,
        -0.29957786000000025, -0.303646, -0.3076482600000004,
        -0.31158464000000013, -0.31545514000000047, -0.31925976000000028,
        -0.32299850000000008, -0.32667136000000035, -0.33027834000000017,
        -0.33381944000000047, -0.33729466000000025, -0.34070400000000006,
        -0.34404746000000036, -0.34732504000000014, -0.35053674000000046,
        -0.35368256000000026, -0.35676250000000009, -0.35977656000000036,
        -0.36272474000000016, -0.36560704000000038, -0.36842346000000026,
        -0.37117400000000006, -0.37385866000000029, -0.37647744000000016,
        -0.37903034000000035, -0.38151736000000025, -0.38393850000000007,
        -0.38629376000000026, -0.38858314000000016, -0.39080664000000032,
        -0.39296426000000018, -0.39505600000000007, -0.39708186000000029,
        -0.39904184000000015, -0.40093594000000032, -0.4027641600000002,
        -0.40452650000000012, -0.40622296000000024, -0.40785354000000013,
        -0.40941824000000027, -0.41091706000000017, -0.41235000000000011,
        -0.41371706000000019, -0.41501824000000009, -0.41625354000000026,
        -0.41742296000000018, -0.41852650000000008, -0.41956416000000019,
        -0.42053594000000016, -0.42144184000000018, -0.42228186000000012,
        -0.4230560000000001, -0.42376426000000011, -0.42440664000000011,
        -0.42498314000000015, -0.42549376000000011, -0.42593850000000011,
        -0.42631736000000009, -0.42663034000000011, -0.42687744000000011,
        -0.42705866000000015, -0.42717400000000005, -0.42722346000000011,
        -0.42720704000000009, -0.42712474000000011, -0.42697656000000006,
        -0.4267625000000001, -0.42648256000000007, -0.42613674000000007,
        -0.42572504, -0.42524746000000008, -0.42470400000000008, -0.42409466,
        -0.42341944000000004, -0.42267834, -0.42187136000000003,
        -0.42099850000000005, -0.42005976, -0.41905514000000005,
        -0.41798463999999996, -0.41684825999999997, -0.41564600000000007,
        -0.41437786, -0.41304384000000005, -0.41164393999999993,
        -0.41017815999999996, -0.40864650000000008, -0.40704895999999996,
        -0.40538554, -0.40365623999999983, -0.40186105999999994, -0.4,
        -0.40233871000000021, -0.40463884000000011, -0.40690039000000028,
        -0.40912336000000016, -0.41130775, -0.41345356000000022,
        -0.41556079000000007, -0.41762944000000024, -0.41965951000000012,
        -0.421651, -0.42360391000000019, -0.42551824000000005,
        -0.42739399000000022, -0.42923116000000011, -0.43102975,
        -0.43278976000000013, -0.43451119000000005, -0.43619404000000017,
        -0.43783831000000012, -0.439444, -0.44101111000000015,
        -0.44253964000000007, -0.4440295900000002, -0.44548096000000009,
        -0.44689375, -0.44826796000000013, -0.44960359000000005,
        -0.45090064000000019, -0.45215911000000009, -0.45337900000000003,
        -0.45456031000000008, -0.45570304000000006, -0.45680719000000014,
        -0.45787276000000005, -0.45889975, -0.4598881600000001,
        -0.46083799000000003, -0.46174924000000012, -0.46262191000000008,
        -0.463456, -0.46425151000000009, -0.46500844, -0.46572679000000006,
        -0.46640656, -0.46704775, -0.46765036000000004, -0.46821439, -0.46873984,
        -0.46922671000000005, -0.469675, -0.47008471, -0.47045584,
        -0.47078839000000006, -0.47108236000000003, -0.47133775, -0.47155456,
        -0.47173279, -0.47187244, -0.47197351, -0.472036, -0.47205991,
        -0.47204524, -0.47199199, -0.47190016, -0.47176975, -0.47160075999999995,
        -0.47139319, -0.47114703999999996, -0.47086231, -0.470539,
        -0.47017710999999995, -0.46977663999999997, -0.46933758999999992,
        -0.46885995999999996, -0.46834375, -0.46778895999999992, -0.46719559,
        -0.46656363999999989, -0.46589310999999994, -0.465184,
        -0.46443630999999991, -0.46365004, -0.46282518999999989,
        -0.46196175999999994, -0.46105975, -0.46011915999999992,
        -0.45913998999999994, -0.45812223999999985, -0.45706590999999991,
        -0.45597099999999996, -0.45483750999999989, -0.45366544,
        -0.45245478999999983, -0.45120555999999989, -0.44991775,
        -0.44859135999999988, -0.44722638999999992, -0.44582283999999983,
        -0.4443807099999999, -0.44289999999999996, -0.44138070999999984,
        -0.43982283999999994, -0.4382263899999998, -0.43659135999999987,
        -0.43491775, -0.43320555999999982, -0.43145478999999992,
        -0.42966543999999973, -0.42783750999999987, -0.425971,
        -0.42406590999999982, -0.42212223999999993, -0.42013998999999974,
        -0.41811915999999982, -0.41605974999999995, -0.41396175999999985,
        -0.4118251899999999, -0.40965003999999977, -0.40743630999999986,
        -0.405184, -0.40289310999999978, -0.40056363999999994,
        -0.39819558999999971, -0.39578895999999986, -0.39334375,
        -0.39085995999999978, -0.3883375899999999, -0.38577663999999973,
        -0.38317710999999988, -0.380539, -0.37786230999999976,
        -0.37514703999999993, -0.37239318999999971, -0.36960075999999986,
        -0.36676975, -0.36390015999999975, -0.36099198999999993,
        -0.35804523999999965, -0.35505990999999981, -0.352036,
        -0.34897350999999971, -0.34587243999999989, -0.34273278999999962,
        -0.33955455999999984, -0.33633775, -0.33308235999999969,
        -0.32978838999999988, -0.32645583999999961, -0.32308470999999983,
        -0.319675, -0.31622671000000019, -0.31273984000000038,
        -0.30921439000000006, -0.30565036000000029, -0.30204775,
        -0.29840656000000021, -0.2947267900000004, -0.29100844000000009,
        -0.28725151000000032, -0.283456, -0.2796219100000002,
        -0.27574924000000045, -0.27183799000000008, -0.26788816000000032,
        -0.26389975, -0.2598727600000002, -0.25580719000000046,
        -0.2517030400000001, -0.24756031000000034, -0.24337899999999998,
        -0.23915911000000023, -0.23490064000000047, -0.23060359000000011,
        -0.22626796000000035, -0.22189374999999997, -0.21748096000000022,
        -0.21302959000000049, -0.20853964000000011, -0.20401111000000036,
        -0.19944399999999998, -0.19483831000000024, -0.19019404000000051,
        -0.1855111900000001, -0.18078976000000038, -0.17602974999999998,
        -0.17123116000000024, -0.16639399000000052, -0.16151824000000012,
        -0.1566039100000004, -0.15165099999999998, -0.14665951000000027,
        -0.14162944000000055, -0.1365607900000001, -0.13145356000000041,
        -0.12630774999999994, -0.12112336000000029, -0.11590039000000057,
        -0.11063884000000013, -0.10533871000000045, -0.1, -0.098753750000000071,
        -0.097515000000000143, -0.096283750000000043, -0.095060000000000117,
        -0.09384375, -0.092635000000000078, -0.091433750000000147,
        -0.090240000000000042, -0.089053750000000112, -0.087875000000000009,
        -0.086703750000000079, -0.085540000000000144, -0.084383750000000035,
        -0.083235000000000114, -0.082093750000000007, -0.080960000000000074,
        -0.079833750000000134, -0.078715000000000035, -0.07760375000000011,
        -0.076500000000000012, -0.075403750000000075, -0.074315000000000131,
        -0.073233750000000042, -0.0721600000000001, -0.071093750000000011,
        -0.070035000000000069, -0.068983750000000135, -0.067940000000000042,
        -0.0669037500000001, -0.065875000000000017, -0.064853750000000071,
        -0.063840000000000133, -0.062833750000000049, -0.0618350000000001,
        -0.060843750000000016, -0.059860000000000066, -0.05888375000000013,
        -0.057915000000000043, -0.056953750000000095, -0.056000000000000015,
        -0.055053750000000068, -0.054115000000000128, -0.053183750000000043,
        -0.0522600000000001, -0.051343750000000014, -0.05043500000000007,
        -0.049533750000000126, -0.048640000000000044, -0.047753750000000095,
        -0.046875000000000021, -0.046003750000000065, -0.045140000000000118,
        -0.044283750000000045, -0.0434350000000001, -0.04259375000000002,
        -0.041760000000000068, -0.040933750000000116, -0.040115000000000053,
        -0.039303750000000096, -0.03850000000000002, -0.037703750000000071,
        -0.036915000000000114, -0.036133750000000048, -0.035360000000000086,
        -0.03459375000000002, -0.033835000000000073, -0.033083750000000106,
        -0.032340000000000035, -0.031603750000000083, -0.030875000000000027,
        -0.030153750000000062, -0.029440000000000105, -0.028733750000000044,
        -0.028035000000000088, -0.027343750000000014, -0.026660000000000073,
        -0.025983750000000111, -0.025315000000000046, -0.024653750000000085,
        -0.024000000000000021, -0.023353750000000076, -0.02271500000000011,
        -0.022083749999999958, -0.021460000000000173, -0.020843750000000022,
        -0.020235000000000072, -0.019633750000000103, -0.01903999999999996,
        -0.018453750000000158, -0.01787500000000003, -0.017303750000000076,
        -0.016740000000000088, -0.016183749999999969, -0.015635000000000163,
        -0.015093750000000031, -0.014560000000000059, -0.014033750000000081,
        -0.013514999999999971, -0.013003750000000147, -0.012500000000000039,
        -0.012003750000000063, -0.011515000000000081, -0.011033749999999981,
        -0.010560000000000153, -0.01009375000000004, -0.00963500000000006,
        -0.0091837500000000877, -0.0087399999999999978, -0.0083037500000001235,
        -0.0078750000000000347, -0.0074537500000000645, -0.007040000000000074,
        -0.0066337500000000077, -0.0062350000000001154, -0.0058437500000000364,
        -0.005460000000000062, -0.0050837500000000813, -0.0047150000000000108,
        -0.0043537500000001145, -0.0040000000000000452, -0.0036537500000000667,
        -0.0033150000000000818, -0.0029837500000000211, -0.0026600000000001067,
        -0.0023437500000000333, -0.0020350000000000645, -0.0017337500000000755,
        -0.0014400000000000107, -0.0011537500000001061, -0.00087500000000004241,
        -0.00060375000000005563, -0.00034000000000007635, -8.375000000000743E-5,
        0.00016499999999990134, 0.00040624999999995526, 0.00063999999999994617,
        0.00086624999999992958, 0.0010849999999999749, 0.0012962499999999155,
        0.0014999999999999458, 0.0016962499999999409, 0.0018849999999999423,
        0.0020662499999999778, 0.0022399999999999087, 0.0024062499999999432,
        0.0025649999999999423, 0.002716249999999934, 0.00285999999999996,
        0.0029962499999999226, 0.0031249999999999611, 0.0032462499999999367,
        0.0033599999999999325, 0.0034662499999999624, 0.0035649999999999293,
        0.0036562499999999581, 0.0037399999999999517, 0.0038162499999999377,
        0.0038849999999999579, 0.0039462499999999429, 0.003999999999999948,
        0.0040462499999999457, 0.0040849999999999359, 0.0041162499999999463,
        0.0041399999999999493, 0.0041562499999999447, 0.0041649999999999465,
        0.0041662499999999547, 0.0041599999999999415, 0.0041462499999999486,
        0.0041249999999999343, 0.00409624999999994, 0.0040599999999999525,
        0.00401624999999993, 0.0039649999999999547, 0.0039062499999999445,
        0.0038399999999999407, 0.0037662499999999571, 0.0036849999999999244,
        0.0035962499999999537, 0.0034999999999999476, 0.003396249999999934,
        0.0032849999999999546, 0.00316624999999994, 0.0030399999999999733,
        0.0029062499999999436, 0.0027649999999999481, 0.002616249999999945,
        0.0024599999999999206, 0.0022962499999999858, 0.0021249999999999325,
        0.001946249999999955, 0.00175999999999997, 0.0015662499999999219,
        0.0013649999999999912, 0.0011562499999999282, 0.00093999999999995476,
        0.00071624999999997385, 0.00048499999999990218, 0.00024624999999998953,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        -0.0051471600000000742, -0.010220640000000145, -0.015220440000000215,
        -0.020146560000000282, -0.024999000000000004, -0.029777760000000073,
        -0.034482840000000139, -0.0391142400000002, -0.043671960000000266,
        -0.048156000000000011, -0.052566360000000076, -0.056903040000000134,
        -0.0611660400000002, -0.065355360000000251, -0.069471,
        -0.073512960000000072, -0.077481240000000132, -0.081375840000000185,
        -0.085196760000000232, -0.088944000000000023, -0.092617560000000071,
        -0.096217440000000126, -0.099743640000000175, -0.1031961600000002,
        -0.10657500000000002, -0.10988016000000007, -0.11311164000000011,
        -0.11626944000000015, -0.11935356000000021, -0.12236400000000001,
        -0.12530076000000007, -0.12816384000000011, -0.13095324000000014,
        -0.13366896000000017, -0.13631100000000002, -0.13887936000000006,
        -0.14137404000000012, -0.14379504000000015, -0.14614236000000017,
        -0.14841600000000002, -0.15061596000000005, -0.15274224000000008,
        -0.1547948400000001, -0.15677376000000015, -0.15867900000000001,
        -0.16051056000000002, -0.16226844000000007, -0.16395264000000009,
        -0.1655631600000001, -0.16710000000000003, -0.16856316000000005,
        -0.16995264000000007, -0.17126844000000008, -0.17251056000000012,
        -0.17367900000000006, -0.17477376000000006, -0.17579484000000006,
        -0.17674224000000005, -0.17761596000000007, -0.17841600000000002,
        -0.17914236000000006, -0.17979504000000004, -0.18037404000000004,
        -0.18087936000000004, -0.18131100000000003, -0.18166896000000002,
        -0.18195324000000002, -0.18216384000000002, -0.18230076000000003,
        -0.18236400000000003, -0.18235356000000003, -0.18226944,
        -0.18211164000000002, -0.18188016, -0.18157500000000001,
        -0.18119616000000002, -0.18074364, -0.18021744, -0.17961755999999998,
        -0.17894400000000002, -0.17819676, -0.17737584, -0.17648123999999998,
        -0.17551295999999994, -0.17447100000000001, -0.17335536000000001,
        -0.17216604, -0.17090303999999998, -0.16956635999999997, -0.168156,
        -0.16667195999999998, -0.16511423999999997, -0.16348283999999993,
        -0.16177775999999991, -0.15999900000000003, -0.15814656, -0.15622044,
        -0.15422063999999988, -0.15214715999999986, -0.15, -0.14725871999999995,
        -0.14450687999999992, -0.1417444799999999, -0.13897151999999985,
        -0.136188, -0.13339391999999997, -0.13058927999999995,
        -0.1277740799999999, -0.12494831999999986, -0.12211200000000003,
        -0.11926511999999999, -0.11640767999999994, -0.11353967999999991,
        -0.11066111999999986, -0.10777200000000003, -0.10487231999999999,
        -0.10196207999999995, -0.099041279999999912, -0.096109919999999877,
        -0.093168000000000042, -0.09021552, -0.087252479999999952,
        -0.084278879999999917, -0.081294719999999876, -0.07830000000000005,
        -0.07529472, -0.072278879999999962, -0.069252479999999922,
        -0.066215519999999875, -0.063168000000000044, -0.060109920000000011,
        -0.057041279999999958, -0.053962079999999912, -0.050872319999999874,
        -0.047772000000000051, -0.04466112, -0.041539679999999954,
        -0.0384076799999999, -0.035265119999999872, -0.032112000000000043,
        -0.02894832, -0.025774079999999963, -0.022589279999999906,
        -0.01939391999999987, -0.016188000000000036, -0.012971519999999986,
        -0.0097444799999999443, -0.0065068799999998816, -0.003258719999999854,
        0.0, 0.0018055078125000248, 0.0036032812500000496, 0.0053933203125000745,
        0.0071756250000000986, 0.0089501953124999957, 0.010717031250000021,
        0.012476132812500044, 0.014227500000000068, 0.015971132812500094,
        0.017707031249999991, 0.019435195312500014, 0.021155625000000039,
        0.022868320312500062, 0.024573281250000086, 0.026270507812499989,
        0.027960000000000016, 0.029641757812500041, 0.031315781250000056,
        0.032982070312500084, 0.034640624999999987, 0.036291445312500011,
        0.037934531250000035, 0.039569882812500061, 0.041197500000000081,
        0.042817382812499985, 0.044429531250000008, 0.046033945312500033,
        0.047630625000000051, 0.049219570312500079, 0.050800781249999989,
        0.052374257812500005, 0.053940000000000023, 0.055498007812500048,
        0.057048281250000069, 0.058590820312499986, 0.060125625000000009,
        0.061652695312500033, 0.063172031250000038, 0.064683632812500058,
        0.066187499999999982, 0.0676836328125, 0.06917203125000003,
        0.070652695312500055, 0.072125625000000068, 0.073590820312499972,
        0.07504828125, 0.076498007812500018, 0.077940000000000051,
        0.079374257812500071, 0.080800781249999981, 0.08221957031249999,
        0.083630625000000014, 0.085033945312500039, 0.086429531250000066,
        0.087817382812499983, 0.089197500000000013, 0.090569882812500016,
        0.091934531250000034, 0.093291445312500054, 0.094640624999999978,
        0.0959820703125, 0.097315781250000025, 0.09864175781250005,
        0.099960000000000063, 0.10127050781249998, 0.10257328125000001,
        0.10386832031250003, 0.10515562500000004, 0.10643519531250006,
        0.10770703124999999, 0.10897113281250001, 0.11022750000000002,
        0.11147613281250005, 0.11271703125000006, 0.1139501953125, 0.115175625,
        0.11639332031250002, 0.11760328125000005, 0.11880550781250007, 0.12,
        0.12255504373177846, 0.12506915451895051, 0.12754233236151613,
        0.12997457725947537, 0.132365889212828, 0.13471626822157437,
        0.13702571428571436, 0.13929422740524791, 0.14152180758017507,
        0.14370845481049563, 0.1458541690962101, 0.14795895043731785,
        0.15002279883381919, 0.1520457142857144, 0.15402769679300293,
        0.15596874635568531, 0.15786886297376101, 0.15972804664723028,
        0.16154629737609341, 0.16332361516034988, 0.16506000000000015,
        0.16675545189504379, 0.168409970845481, 0.17002355685131207,
        0.17159620991253646, 0.17312793002915466, 0.17461871720116623,
        0.17606857142857141, 0.17747749271137037, 0.17884548104956272,
        0.18017253644314882, 0.18145865889212834, 0.18270384839650144,
        0.1839081049562683, 0.18507142857142861, 0.18619381924198264,
        0.18727527696793009, 0.18831580174927115, 0.18931539358600591,
        0.19027405247813414, 0.1911917784256561, 0.19206857142857148,
        0.19290443148688047, 0.19369935860058318, 0.19445335276967934,
        0.19516641399416917, 0.19583854227405254, 0.19646973760932945,
        0.19706000000000007, 0.19760932944606419, 0.19811772594752194,
        0.19858518950437323, 0.19901172011661811, 0.19939731778425662,
        0.19974198250728867, 0.20004571428571435, 0.20030851311953357,
        0.20053037900874637, 0.20071131195335282, 0.20085131195335282,
        0.2009503790087464, 0.20100851311953358, 0.20102571428571434,
        0.20100198250728868, 0.20093731778425661, 0.2008317201166181,
        0.2006851895043732, 0.20049772594752191, 0.20026932944606418, 0.2,
        0.19860191406249988, 0.19721390624999996, 0.19583597656250004,
        0.19446812499999994, 0.1931103515625, 0.19176265624999989,
        0.19042503906249997, 0.18909750000000006, 0.18778003906249993,
        0.18647265625, 0.1851753515624999, 0.18388812499999999,
        0.18261097656250005, 0.18134390624999994, 0.18008691406250002,
        0.17883999999999992, 0.17760316406249999, 0.17637640625000006,
        0.17515972656249995, 0.17395312500000001, 0.17275660156249992,
        0.17157015625, 0.17039378906250005, 0.16922749999999995,
        0.16807128906250002, 0.16692515624999993, 0.16578910156249999,
        0.16466312500000005, 0.16354722656249995, 0.16244140625000003,
        0.16134566406249992, 0.16025999999999999, 0.15918441406250006,
        0.15811890624999997, 0.15706347656250003, 0.15601812499999992,
        0.1549828515625, 0.15395765625000005, 0.15294253906249997, 0.1519375,
        0.15094253906249994, 0.14995765625, 0.14898285156250005,
        0.14801812499999994, 0.14706347656250002, 0.14611890624999993,
        0.1451844140625, 0.14426000000000005, 0.14334566406249996, 0.14244140625,
        0.14154722656249993, 0.140663125, 0.13978910156250002,
        0.13892515624999996, 0.13807128906250002, 0.13722749999999995,
        0.1363937890625, 0.13557015625000002, 0.13475660156249997, 0.133953125,
        0.13315972656249994, 0.13237640624999997, 0.13160316406250003,
        0.13083999999999996, 0.1300869140625, 0.12934390624999995,
        0.12861097656249998, 0.12788812499999994, 0.12717535156249998,
        0.12647265625, 0.12578003906249996, 0.12509749999999997,
        0.12442503906249992, 0.12376265624999996, 0.1231103515625,
        0.12246812499999994, 0.12183597656249998, 0.12121390624999993,
        0.12060191406249997, 0.12, 0.11940822157434397, 0.11878390670553933,
        0.11812705539358592, 0.11743766763848391, 0.11671574344023324,
        0.11596128279883375, 0.11517428571428569, 0.11435475218658882,
        0.11350268221574339, 0.11261807580174926, 0.11170093294460633,
        0.11075125364431483, 0.10976903790087451, 0.10875428571428565,
        0.1077069970845481, 0.10662717201166171, 0.10551481049562678,
        0.10436991253644301, 0.10319247813411071, 0.10198250728862973,
        0.10073999999999989, 0.099464956268221522, 0.098157376093294307,
        0.096817259475218576, 0.09544460641399416, 0.094039416909620865,
        0.092601690962099081, 0.091131428571428391, 0.089628629737609239,
        0.088093294460641389, 0.086525422740524632, 0.084925014577259428,
        0.083292069970845289, 0.081626588921282689, 0.079928571428571418,
        0.078198017492711214, 0.076434927113702561, 0.074639300291544974,
        0.072811137026238953, 0.070950437317784248, 0.069057201166180582,
        0.067131428571428509, 0.065173119533527446, 0.063182274052478,
        0.061158892128279865, 0.059102973760932757, 0.057014518950437243,
        0.054893527696792746, 0.052739999999999856, 0.0505539358600583,
        0.04833533527696772, 0.046084198250728778, 0.043800524781340833,
        0.041484314868804509, 0.039135568513119515, 0.03675428571428549,
        0.034340466472303127, 0.031894110787171706, 0.029415218658891962,
        0.026903790087463533, 0.02435982507288606, 0.021783323615160263,
        0.019174285714285394, 0.016532711370262215, 0.013858600583090352,
        0.011151953352769445, 0.008412769679300186, 0.0056410495626818685,
        0.0028367930029152832, 0.0, -0.0032587200000002746,
        -0.0065068800000000881, -0.00974448000000036, -0.012971520000000174,
        -0.016187999999999987, -0.019393920000000262, -0.022589280000000076,
        -0.025774080000000345, -0.028948320000000163, -0.032111999999999981,
        -0.035265120000000247, -0.038407680000000062, -0.041539680000000336,
        -0.044661120000000151, -0.047771999999999967, -0.050872320000000242,
        -0.053962080000000065, -0.057041280000000319, -0.060109920000000143,
        -0.063167999999999974, -0.066215520000000236, -0.069252480000000047,
        -0.072278880000000323, -0.075294720000000148, -0.078299999999999967,
        -0.081294720000000223, -0.084278880000000056, -0.087252480000000313,
        -0.090215520000000146, -0.093167999999999973, -0.096109920000000224,
        -0.099041280000000051, -0.1019620800000003, -0.10487232000000014,
        -0.10777199999999998, -0.11066112000000022, -0.11353968000000006,
        -0.1164076800000003, -0.11926512000000014, -0.12211199999999998,
        -0.12494832000000024, -0.12777408000000007, -0.13058928000000031,
        -0.13339392000000014, -0.136188, -0.13897152000000024,
        -0.14174448000000009, -0.14450688000000034, -0.14725872000000015, -0.15,
        -0.15214716000000017, -0.15422064000000005, -0.15622044000000021,
        -0.1581465600000001, -0.159999, -0.16177776000000016,
        -0.16348284000000005, -0.16511424000000019, -0.16667196000000009,
        -0.168156, -0.16956636000000011, -0.17090304000000003,
        -0.17216604000000013, -0.17335536000000007, -0.174471,
        -0.17551296000000008, -0.17648124000000004, -0.17737584000000009,
        -0.17819676000000004, -0.178944, -0.17961756000000006, -0.18021744,
        -0.18074364000000007, -0.18119616000000002, -0.181575, -0.18188016,
        -0.18211164000000002, -0.18226944, -0.18235356, -0.182364, -0.18230076,
        -0.18216384, -0.18195323999999996, -0.18166896, -0.181311,
        -0.18087935999999996, -0.18037403999999999, -0.17979503999999993,
        -0.17914235999999994, -0.178416, -0.17761595999999993,
        -0.17674223999999997, -0.1757948399999999, -0.17477375999999994,
        -0.173679, -0.1725105599999999, -0.17126843999999997,
        -0.16995263999999982, -0.16856315999999991, -0.1671,
        -0.16556315999999985, -0.16395263999999996, -0.16226843999999979,
        -0.16051055999999989, -0.158679, -0.15677375999999982,
        -0.15479483999999993, -0.15274223999999975, -0.15061595999999985,
        -0.148416, -0.14614235999999978, -0.1437950399999999,
        -0.1413740399999997, -0.13887935999999984, -0.136311,
        -0.13366895999999975, -0.13095323999999989, -0.12816383999999967,
        -0.12530075999999982, -0.12236399999999997, -0.11935355999999972,
        -0.11626943999999989, -0.1131116399999996, -0.1098801599999998,
        -0.10657499999999998, -0.10319615999999968, -0.099743639999999884,
        -0.096217439999999557, -0.092617559999999766, -0.088943999999999968,
        -0.085196759999999636, -0.081375839999999866, -0.077481239999999521,
        -0.073512959999999725, -0.069470999999999963, -0.0653553599999996,
        -0.061166039999999852, -0.056903039999999475, -0.052566359999999729,
        -0.048155999999999935, -0.043671959999999538, -0.039114239999999814,
        -0.034482839999999404, -0.029777759999999681, -0.024998999999999966,
        -0.020146559999999536, -0.015220439999999835, -0.010220639999999392,
        -0.0051471599999996231, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0019933333333333335, 0.0039733333333333339,
        0.0059400000000000017, 0.0078933333333333338, 0.0098333333333333328,
        0.011760000000000001, 0.013673333333333334, 0.015573333333333335,
        0.01746, 0.019333333333333334, 0.021193333333333335,
        0.023040000000000005, 0.024873333333333334, 0.026693333333333336,
        0.028499999999999998, 0.030293333333333335, 0.032073333333333336,
        0.03384, 0.035593333333333338, 0.037333333333333336, 0.03906,
        0.040773333333333335, 0.042473333333333335, 0.044160000000000005,
        0.045833333333333337, 0.047493333333333339, 0.04914,
        0.050773333333333344, 0.052393333333333333, 0.053999999999999992,
        0.055593333333333335, 0.057173333333333333, 0.058740000000000007,
        0.060293333333333338, 0.061833333333333337, 0.06336,
        0.064873333333333325, 0.066373333333333326, 0.06786, 0.06933333333333333,
        0.070793333333333347, 0.07224, 0.073673333333333327,
        0.075093333333333345, 0.076500000000000012, 0.077893333333333328,
        0.079273333333333335, 0.08064, 0.081993333333333335,
        0.083333333333333329, 0.084660000000000013, 0.085973333333333346,
        0.087273333333333328, 0.08856, 0.089833333333333321,
        0.091093333333333332, 0.092339999999999992, 0.093573333333333342,
        0.094793333333333341, 0.096, 0.09719333333333334, 0.09837333333333334,
        0.09954, 0.10069333333333333, 0.10183333333333333, 0.10296000000000001,
        0.10407333333333334, 0.10517333333333333, 0.10626, 0.10733333333333332,
        0.10839333333333333, 0.10944, 0.11047333333333334, 0.11149333333333333,
        0.11249999999999999, 0.11349333333333333, 0.11447333333333333,
        0.11543999999999999, 0.11639333333333332, 0.11733333333333332,
        0.11825999999999998, 0.11917333333333334, 0.12007333333333334, 0.12096,
        0.12183333333333334, 0.12269333333333332, 0.12354, 0.12437333333333332,
        0.12519333333333332, 0.126, 0.12679333333333331, 0.12757333333333332,
        0.12833999999999998, 0.12909333333333331, 0.12983333333333333,
        0.13055999999999998, 0.13127333333333333, 0.13197333333333333, 0.13266,
        0.13333333333333333, 0.13399333333333333, 0.13463999999999998,
        0.1352733333333333, 0.13589333333333331, 0.13649999999999998,
        0.13709333333333334, 0.13767333333333334, 0.13824, 0.13879333333333332,
        0.13933333333333331, 0.13985999999999998, 0.14037333333333332,
        0.14087333333333332, 0.14135999999999999, 0.14183333333333331,
        0.14229333333333333, 0.14273999999999998, 0.14317333333333332,
        0.14359333333333332, 0.144, 0.14439333333333332, 0.14477333333333331,
        0.14514, 0.14549333333333331, 0.14583333333333331, 0.14615999999999998,
        0.14647333333333332, 0.14677333333333331, 0.14705999999999997,
        0.14733333333333329, 0.14759333333333333, 0.14783999999999997,
        0.14807333333333331, 0.1482933333333333, 0.14849999999999997,
        0.14869333333333329, 0.1488733333333333, 0.14903999999999998,
        0.14919333333333329, 0.14933333333333332, 0.14945999999999995,
        0.14957333333333331, 0.1496733333333333, 0.14975999999999998,
        0.14983333333333332, 0.1498933333333333, 0.14993999999999996,
        0.14997333333333332, 0.14999333333333331, 0.15, 0.14994, 0.14976,
        0.14945999999999998, 0.14904, 0.1485, 0.14783999999999997, 0.14706,
        0.14615999999999998, 0.14514, 0.144, 0.14273999999999998, 0.14136,
        0.13985999999999998, 0.13823999999999995, 0.13649999999999998,
        0.13463999999999995, 0.13266, 0.13055999999999998, 0.12833999999999995,
        0.126, 0.12353999999999996, 0.12096000000000001, 0.11825999999999998,
        0.11543999999999993, 0.11249999999999999, 0.10943999999999995,
        0.10626000000000002, 0.10295999999999997, 0.09953999999999992,
        0.095999999999999988, 0.09233999999999995, 0.088560000000000028,
        0.084659999999999958, 0.0806399999999999, 0.076499999999999985,
        0.072239999999999929, 0.067860000000000018, 0.063359999999999958,
        0.05873999999999989, 0.053999999999999992, 0.04913999999999992,
        0.044159999999999852, 0.039059999999999956, 0.033839999999999884,
        0.028499999999999998, 0.023039999999999922, 0.017459999999999837,
        0.011759999999999937, 0.0059399999999998621, 0.0, 0.00019850000000000279,
        0.00039400000000000551, 0.00058650000000000141, 0.000776000000000004,
        0.0009625, 0.0011460000000000027, 0.001326500000000005,
        0.0015040000000000012, 0.0016785000000000038, 0.00185,
        0.0020185000000000025, 0.0021840000000000045, 0.0023465000000000014,
        0.0025060000000000035, 0.0026625, 0.0028160000000000021,
        0.0029665000000000043, 0.0031140000000000013, 0.0032585000000000031,
        0.0034000000000000002, 0.0035385000000000021, 0.0036740000000000041,
        0.0038065000000000009, 0.0039360000000000029, 0.0040625,
        0.0041860000000000022, 0.0043065000000000039, 0.0044240000000000008,
        0.0045385000000000017, 0.00465, 0.0047585000000000023,
        0.0048640000000000029, 0.0049665, 0.0050660000000000019,
        0.0051624999999999996, 0.005256000000000002, 0.0053465000000000032,
        0.0054340000000000005, 0.0055185000000000017, 0.0056,
        0.0056785000000000013, 0.0057540000000000022, 0.0058265,
        0.0058960000000000011, 0.0059625, 0.006026000000000001,
        0.0060865000000000025, 0.006144, 0.0061985000000000009, 0.00625,
        0.0062985, 0.0063440000000000007, 0.0063865000000000007, 0.006426,
        0.0064624999999999995, 0.0064960000000000009, 0.0065265,
        0.0065540000000000008, 0.0065785, 0.0065999999999999991,
        0.0066184999999999994, 0.006634, 0.0066465000000000005,
        0.0066560000000000005, 0.0066624999999999992, 0.006666, 0.0066665,
        0.0066639999999999989, 0.0066585, 0.00665, 0.0066384999999999986,
        0.006624, 0.0066064999999999987, 0.0065859999999999981,
        0.0065624999999999989, 0.0065359999999999984, 0.0065064999999999993,
        0.0064739999999999989, 0.006438499999999998, 0.0063999999999999994,
        0.0063584999999999987, 0.0063139999999999976, 0.0062664999999999986,
        0.0062159999999999976, 0.0061625, 0.0061059999999999986,
        0.0060464999999999972, 0.0059839999999999989, 0.0059184999999999975,
        0.0058499999999999993, 0.005778499999999998, 0.0057039999999999964,
        0.0056264999999999987, 0.0055459999999999971, 0.0054625,
        0.005375999999999998, 0.0052864999999999961, 0.005193999999999999,
        0.0050984999999999971, 0.005, 0.0048984999999999983,
        0.0047939999999999962, 0.0046864999999999988, 0.0045759999999999967,
        0.0044624999999999977, 0.0043459999999999983, 0.0042264999999999959,
        0.0041039999999999974, 0.0039784999999999968, 0.0038499999999999984,
        0.0037184999999999957, 0.0035839999999999956, 0.0034464999999999969,
        0.0033059999999999943, 0.0031624999999999982, 0.0030159999999999957,
        0.0028664999999999954, 0.0027139999999999972, 0.0025584999999999944,
        0.0023999999999999985, 0.0022384999999999957, 0.0020739999999999925,
        0.0019064999999999924, 0.0017360000000000016, 0.0015624999999999988,
        0.0013859999999999955, 0.0012064999999999925, 0.0010239999999999891,
        0.00083850000000000211, 0.00064999999999999889, 0.00045849999999999271,
        0.00026399999999999503, 6.6499999999991547E-5, -0.00013400000000000033,
        -0.00033750000000000381, -0.00054400000000000737,
        -0.00075350000000000514, -0.00096600000000000884, -0.0011815,
        -0.0014000000000000037, -0.0016215000000000075, -0.0018460000000000115,
        -0.0020735000000000094, -0.0023039999999999996, -0.0025375000000000033,
        -0.0027740000000000074, -0.0030135000000000118, -0.0032560000000000158,
        -0.003501499999999999, -0.0037500000000000033, -0.0040015000000000077,
        -0.0042560000000000124, -0.0045135000000000166, -0.0047739999999999987,
        -0.0050375000000000029, -0.0053040000000000075, -0.0055735000000000125,
        -0.005846000000000017, -0.0061214999999999985, -0.0064000000000000029,
        -0.0066815000000000077, -0.0069660000000000121, -0.0072535000000000177,
        -0.0075439999999999978, -0.0078375000000000025, -0.0081340000000000075,
        -0.0084335000000000122, -0.0087360000000000181, -0.0090414999999999975,
        -0.0093500000000000024, -0.0096615000000000069, -0.0099760000000000126,
        -0.010293500000000018, -0.010613999999999997, -0.010937500000000003,
        -0.011264000000000008, -0.011593500000000014, -0.011926000000000018,
        -0.012261499999999996, -0.012600000000000002, -0.012941500000000007,
        -0.013286000000000013, -0.013633500000000019, -0.013984000000000024,
        -0.014337500000000001, -0.014694000000000007, -0.015053500000000013,
        -0.01541600000000002, -0.015781500000000025, -0.01615,
        -0.016521500000000008, -0.016896000000000015, -0.017273500000000021,
        -0.017654000000000027, -0.0180375, -0.018424000000000006,
        -0.018813500000000014, -0.019206000000000022, -0.019601500000000025,
        -0.02, -0.020617760000000009, -0.021223040000000019,
        -0.021815840000000027, -0.022396160000000036, -0.022964000000000002,
        -0.02351936000000001, -0.024062240000000019, -0.024592640000000027,
        -0.025110560000000032, -0.025616000000000007, -0.026108960000000014,
        -0.02658944000000002, -0.027057440000000026, -0.027512960000000031,
        -0.027956000000000009, -0.028386560000000012, -0.02880464000000002,
        -0.029210240000000026, -0.02960336000000003, -0.029984000000000011,
        -0.030352160000000013, -0.030707840000000021, -0.031051040000000023,
        -0.031381760000000029, -0.031700000000000006, -0.032005760000000015,
        -0.032299040000000022, -0.03257984000000002, -0.032848160000000029,
        -0.033104000000000008, -0.033347360000000013, -0.033578240000000016,
        -0.033796640000000017, -0.034002560000000022, -0.034196000000000011,
        -0.034376960000000012, -0.034545440000000018, -0.034701440000000021,
        -0.034844960000000022, -0.034976000000000014, -0.035094560000000011,
        -0.035200640000000019, -0.035294240000000018, -0.035375360000000015,
        -0.035444000000000017, -0.035500160000000017, -0.035543840000000014,
        -0.035575040000000016, -0.035593760000000016, -0.035600000000000014,
        -0.035593760000000016, -0.035575040000000009, -0.035543840000000014,
        -0.03550016000000001, -0.035444000000000017, -0.035375360000000008,
        -0.035294240000000011, -0.035200640000000005, -0.035094560000000004,
        -0.034976000000000007, -0.034844960000000008, -0.034701440000000007,
        -0.034545440000000004, -0.03437696, -0.034196000000000011,
        -0.034002560000000008, -0.03379664, -0.03357824, -0.033347359999999993,
        -0.033104000000000008, -0.032848160000000008, -0.03257984,
        -0.032299039999999994, -0.032005759999999994, -0.031700000000000013,
        -0.03138176, -0.03105104, -0.030707839999999997, -0.030352159999999986,
        -0.029984000000000007, -0.029603360000000002, -0.029210239999999991,
        -0.028804639999999989, -0.028386559999999984, -0.027956,
        -0.027512959999999996, -0.027057439999999995, -0.026589439999999982,
        -0.026108959999999976, -0.025616000000000003, -0.025110559999999997,
        -0.024592639999999985, -0.024062239999999981, -0.023519359999999975,
        -0.022964, -0.022396159999999991, -0.021815839999999986,
        -0.021223039999999971, -0.020617759999999964, -0.02,
        -0.021869920000000022, -0.023671680000000046, -0.025405280000000065,
        -0.027070720000000083, -0.028667999999999985, -0.030197120000000004,
        -0.031658080000000019, -0.033050880000000032, -0.034375520000000048,
        -0.035631999999999969, -0.03682031999999999, -0.03794048,
        -0.03899248000000001, -0.039976320000000024, -0.04089199999999997,
        -0.041739519999999974, -0.042518879999999981, -0.04323007999999999,
        -0.043873119999999995, -0.04444799999999996, -0.044954719999999962,
        -0.045393279999999966, -0.045763679999999973, -0.046065919999999969,
        -0.046299999999999952, -0.046465919999999959, -0.046563679999999961,
        -0.046593279999999959, -0.046554719999999952, -0.046447999999999962,
        -0.046273119999999959, -0.046030079999999952, -0.045718879999999948,
        -0.045339519999999939, -0.04489199999999996, -0.044376319999999955,
        -0.043792479999999946, -0.043140479999999939, -0.042420319999999928,
        -0.041631999999999975, -0.040775519999999961, -0.03985087999999995,
        -0.038858079999999934, -0.037797119999999913, -0.036667999999999978,
        -0.035470719999999976, -0.034205279999999949, -0.032871679999999924,
        -0.031469919999999915, -0.03, -0.030323984375, -0.030633437500000006,
        -0.030928359375000009, -0.031208750000000014, -0.031474609375,
        -0.0317259375, -0.031962734375, -0.032185000000000005,
        -0.03239273437500001, -0.032585937499999995, -0.032764609374999996,
        -0.03292875, -0.033078359375000005, -0.033213437500000005,
        -0.033333984374999993, -0.03344, -0.033531484375, -0.0336084375,
        -0.033670859375, -0.03371875, -0.033752109375, -0.033770937499999994,
        -0.033775234375, -0.033764999999999996, -0.033740234375,
        -0.033700937499999993, -0.033647109374999991, -0.033578749999999991,
        -0.033495859374999992, -0.033398437499999996, -0.033286484374999994,
        -0.033159999999999988, -0.033018984374999991, -0.032863437499999988,
        -0.032693359374999995, -0.032508749999999989, -0.032309609374999985,
        -0.032095937499999984, -0.031867734374999984, -0.031624999999999993,
        -0.031367734374999991, -0.031095937499999986, -0.030809609374999984,
        -0.030508749999999977, -0.030193359374999996, -0.029863437499999989,
        -0.029518984374999988, -0.029159999999999981, -0.028786484374999973,
        -0.028398437499999995, -0.027995859374999987, -0.027578749999999985,
        -0.027147109374999978, -0.026700937499999969, -0.026240234374999998,
        -0.025764999999999989, -0.025275234374999983, -0.024770937499999979,
        -0.024252109374999966, -0.023718749999999997, -0.023170859374999988,
        -0.022608437499999981, -0.022031484374999973, -0.021439999999999963,
        -0.020833984375, -0.020213437499999987, -0.019578359374999979,
        -0.018928749999999973, -0.018264609374999959, -0.0175859375,
        -0.016892734374999989, -0.016184999999999977, -0.015462734374999971,
        -0.014725937499999956, -0.013974609375000002, -0.013208749999999991,
        -0.012428359374999979, -0.011633437499999968, -0.010823984374999953,
        -0.01, -0.010545131195335285, -0.01107032069970847,
        -0.011575568513119555, -0.012060874635568541, -0.012526239067055394,
        -0.012971661807580182, -0.013397142857142871, -0.01380268221574346,
        -0.014188279883381947, -0.014553935860058312, -0.014899650145772625,
        -0.015225422740524793, -0.015531253644314864, -0.015817142857142877,
        -0.016083090379008749, -0.016329096209912561, -0.016555160349854235,
        -0.016761282798833817, -0.016947463556851325, -0.017113702623906709,
        -0.017260000000000015, -0.0173863556851312, -0.017492769679300295,
        -0.017579241982507297, -0.017645772594752189, -0.017692361516034993,
        -0.01771900874635569, -0.017725714285714289, -0.017712478134110789,
        -0.017679300291545193, -0.017626180758017491, -0.0175531195335277,
        -0.017460116618075811, -0.017347172011661804, -0.017214285714285717,
        -0.017061457725947513, -0.01688868804664723, -0.016695976676384849,
        -0.01648332361516034, -0.016250728862973768, -0.015998192419825058,
        -0.015725714285714284, -0.015433294460641414, -0.015120932944606402,
        -0.014788629737609336, -0.014436384839650119, -0.01406419825072886,
        -0.0136720699708455, -0.01325999999999998, -0.012827988338192427,
        -0.012376034985422706, -0.011904139941690952, -0.011412303206997102,
        -0.010900524781341082, -0.010368804664723036, -0.0098171428571428142,
        -0.0092455393586005716, -0.0086539941690962317, -0.0080425072886297078,
        -0.0074110787172011715, -0.0067597084548104459, -0.0060883965014577124,
        -0.0053971428571428825, -0.0046859475218658554, -0.0039548104956268291,
        -0.0032037317784255935, -0.002432711370262376, -0.0016417492711370552,
        -0.00083084548104951812, 0.0, 0.00085171875000007247,
        0.0016818750000000247, 0.0024904687499999797, 0.0032775000000000473,
        0.004042968750000004, 0.0047868750000000663, 0.0055092187500000254,
        0.0062099999999999855, 0.0068892187500000446, 0.0075468750000000067,
        0.00818296875000006, 0.0087975000000000258, 0.0093904687499999917,
        0.0099618750000000419, 0.01051171875000001, 0.011040000000000053,
        0.011546718750000025, 0.012031874999999997, 0.012495468750000035,
        0.012937500000000011, 0.013357968750000048, 0.013756875000000024,
        0.014134218750000002, 0.014490000000000032, 0.014824218750000014,
        0.015136875000000037, 0.015427968750000022, 0.015697500000000007,
        0.015945468750000025, 0.016171875000000016, 0.016376718750000033,
        0.016560000000000019, 0.01672171875000001, 0.016861875000000023,
        0.016980468750000016, 0.01707750000000002, 0.017152968750000018,
        0.017206875000000014, 0.017239218750000018, 0.017250000000000015,
        0.017239218750000014, 0.017206875000000014, 0.017152968750000018,
        0.017077500000000013, 0.016980468750000016, 0.016861875000000005,
        0.01672171875000001, 0.016560000000000019, 0.016376718750000005,
        0.016171875000000016, 0.015945468749999997, 0.015697500000000007,
        0.015427968750000021, 0.015136874999999998, 0.014824218750000014,
        0.014489999999999986, 0.014134218750000004, 0.013756875000000023,
        0.013357968749999991, 0.012937500000000011, 0.012495468749999974,
        0.012031874999999997, 0.011546718750000023, 0.011039999999999982,
        0.01051171875000001, 0.0099618749999999638, 0.0093904687499999917,
        0.0087974999999999356, 0.0081829687499999741, 0.0075468750000000067,
        0.0068892187499999518, 0.0062099999999999864, 0.0055092187499999213,
        0.0047868749999999639, 0.0040429687499999971, 0.0032774999999999328,
        0.0024904687499999805, 0.001681874999999912, 0.0008517187499999479, 0.0,
        0.0018407580174928666, 0.0036405830903790586, 0.00539947521865909,
        0.0071174344023324579, 0.0087944606413994167, 0.010430553935860195,
        0.012025714285714329, 0.013579941690962273, 0.015093236151603583,
        0.016565597667638484, 0.017997026239067175, 0.01938752186588925,
        0.020737084548105106, 0.022045714285714359, 0.0233134110787172,
        0.024540174927113804, 0.025726005830903821, 0.026870903790087591,
        0.027974868804664783, 0.029037900874635567, 0.030060000000000083,
        0.031041166180758042, 0.031981399416909723, 0.032880699708454857,
        0.033739067055393583, 0.034556501457726013, 0.035333002915451918,
        0.036068571428571512, 0.036763206997084581, 0.03741690962099125,
        0.038029679300291594, 0.038601516034985441, 0.039132419825072942,
        0.03962239067055396, 0.04007142857142857, 0.040479533527696829,
        0.04084670553935861, 0.041172944606414026, 0.041458250728862986,
        0.041702623906705538, 0.041906064139941704, 0.042068571428571434,
        0.042190145772594764, 0.042270787172011666, 0.04231049562682216,
        0.04230927113702624, 0.042267113702623905, 0.04218402332361515,
        0.042059999999999993, 0.041895043731778429, 0.041689154518950423,
        0.041442332361516024, 0.041154577259475189, 0.040825889212827968,
        0.040456268221574339, 0.040045714285714247, 0.039594227405247796,
        0.039101807580174869, 0.038568454810495596, 0.037994169096209909,
        0.037378950437317732, 0.036722798833819223, 0.0360257142857142,
        0.035287696793002872, 0.034508746355685134, 0.033688862973760864,
        0.032828046647230304, 0.031926297376093191, 0.030983615160349805, 0.03,
        0.031081920000000089, 0.032119680000000032, 0.033113280000000113,
        0.034062720000000053, 0.034968000000000006, 0.035829120000000075,
        0.036646080000000025, 0.037418880000000092, 0.038147520000000046,
        0.038832000000000005, 0.039472320000000061, 0.040068480000000024,
        0.04062048000000007, 0.041128320000000038, 0.041592000000000011,
        0.042011520000000045, 0.042386880000000016, 0.042718080000000047,
        0.043005120000000022, 0.043248000000000009, 0.043446720000000022,
        0.043601280000000013, 0.043711680000000017, 0.043777920000000012,
        0.043800000000000013, 0.043777920000000005, 0.04371168,
        0.043601279999999992, 0.04344672, 0.043248000000000009,
        0.043005119999999987, 0.04271808, 0.042386879999999967,
        0.042011519999999983, 0.041592000000000004, 0.041128319999999968,
        0.040620479999999987, 0.040068479999999948, 0.03947231999999997,
        0.038832000000000005, 0.038147519999999942, 0.037418879999999981,
        0.036646079999999907, 0.035829119999999957, 0.034968,
        0.034062719999999921, 0.033113279999999967, 0.03211967999999988,
        0.03108191999999994, 0.03, 0.03061476000000005, 0.031211040000000016,
        0.031788840000000061, 0.032348160000000029, 0.032889,
        0.033411360000000043, 0.033915240000000013, 0.034400640000000052,
        0.034867560000000027, 0.035316, 0.035745960000000035,
        0.036157440000000013, 0.036550440000000045, 0.036924960000000021,
        0.037281, 0.03761856000000003, 0.037937640000000009,
        0.038238240000000034, 0.038520360000000017, 0.038784,
        0.039029160000000021, 0.039255840000000007, 0.03946404000000002,
        0.03965376000000001, 0.039825, 0.039977760000000015, 0.04011204,
        0.040227840000000015, 0.040325160000000006, 0.040404,
        0.040464360000000005, 0.04050624, 0.040529640000000006, 0.04053456,
        0.040521, 0.04048896, 0.04043844, 0.040369439999999993,
        0.040281959999999992, 0.040176, 0.040051559999999993,
        0.039908639999999995, 0.039747239999999982, 0.039567359999999996,
        0.039369, 0.039152159999999978, 0.038916839999999994,
        0.038663039999999968, 0.038390759999999982, 0.0381, 0.037790759999999972,
        0.037463039999999996, 0.037116839999999963, 0.036752159999999978,
        0.036369000000000005, 0.035967359999999969, 0.035547239999999987,
        0.035108639999999948, 0.034651559999999977, 0.034176,
        0.033681959999999962, 0.033169439999999988, 0.032638439999999942,
        0.032088959999999972, 0.031521, 0.030934559999999951,
        0.030329639999999988, 0.029706239999999932, 0.029064359999999966,
        0.028404000000000006, 0.027725159999999947, 0.027027839999999984,
        0.026312039999999925, 0.025577759999999963, 0.024825,
        0.024053759999999938, 0.023264039999999982, 0.022455839999999908,
        0.02162915999999996, 0.020784000000000004, 0.019920359999999929,
        0.019038239999999981, 0.0181376399999999, 0.017218559999999949,
        0.016281000000000007, 0.015324959999999922, 0.014350439999999982,
        0.013357439999999894, 0.012345959999999937, 0.011316,
        0.010267559999999908, 0.0092006399999999752, 0.0081152399999998778,
        0.0070113599999999422, 0.0058890000000000123, 0.0047481599999999111,
        0.0035888399999999647, 0.0024110399999998609, 0.0012147599999999328, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, -0.0040670744334108666, -0.0080519857469548463,
        -0.011954733940631939, -0.015775319014442141, -0.019513740968385197,
        -0.023169999802461632, -0.026744095516671181, -0.030236028111013842,
        -0.033645797585489613, -0.036973403940098272, -0.040218847174840276,
        -0.0433821272897154, -0.046463244284723627, -0.049462198159864967,
        -0.052378988915139216, -0.055213616550546789, -0.057966081066087478,
        -0.060636382461761271, -0.063224520737568179, -0.065730495893508031,
        -0.068154307929581173, -0.070495956845787425, -0.0727554426421268,
        -0.07493276531859927, -0.077027924875204726, -0.079040921311943443,
        -0.080971754628815257, -0.082820424825820207, -0.084586931902958254,
        -0.0862712758602293, -0.087873456697633578, -0.089393474415170968,
        -0.09083132901284148, -0.0921870204906451, -0.093460548848581737,
        -0.094651914086651578, -0.095761116204854543, -0.096788155203190618,
        -0.097733031081659816, -0.098595743840262054, -0.099376293478997471,
        -0.100074679997866, -0.10069090339686765, -0.10122496367600241,
        -0.10167686083527025, -0.10204659487467124, -0.10233416579420533,
        -0.10253957359387254, -0.10266281827367288, -0.10270389983360631,
        -0.10266281827367287, -0.10253957359387253, -0.1023341657942053,
        -0.1020465948746712, -0.10167686083527025, -0.10122496367600237,
        -0.10069090339686761, -0.10007467999786596, -0.099376293478997416,
        -0.098595743840262068, -0.09773303108165976, -0.096788155203190562,
        -0.095761116204854488, -0.094651914086651523, -0.093460548848581737,
        -0.092187020490645, -0.090831329012841383, -0.08939347441517087,
        -0.087873456697633467, -0.086271275860229313, -0.084586931902958143,
        -0.082820424825820083, -0.080971754628815146, -0.0790409213119433,
        -0.077027924875204726, -0.074932765318599132, -0.072755442642126661,
        -0.070495956845787286, -0.068154307929581034, -0.065730495893508045,
        -0.063224520737568013, -0.0606363824617611, -0.057966081066087291,
        -0.055213616550546595, -0.052378988915139209, -0.049462198159864745,
        -0.0464632442847234, -0.043382127289715161, -0.040218847174840033,
        -0.036973403940098307, -0.033645797585489412, -0.030236028111013634,
        -0.026744095516670965, -0.02316999980246141, -0.019513740968385217,
        -0.015775319014441892, -0.011954733940631682, -0.0080519857469545826,
        -0.004067074433410596, 0.0, 0.012359771493909641, 0.024293838028884192,
        0.035802199604923646, 0.04688485622202801, 0.057541807880196541,
        0.067773054579430753, 0.077578596319729867, 0.0869584331010939,
        0.095912564923522819, 0.10444099178701607, 0.11254371369157486,
        0.12022073063719854, 0.12747204262388714, 0.13429764965164062,
        0.14069755172045861, 0.14667174883034195, 0.15222024098129019,
        0.15734302817330337, 0.16204011040638144, 0.16631148768052412,
        0.17015715999573203, 0.17357712735200487, 0.17657138974934261,
        0.17913994718774523, 0.18128279966721261, 0.18299994718774512,
        0.1842913897493425, 0.18515712735200482, 0.18559715999573204,
        0.18561148768052413, 0.18520011040638118, 0.18436302817330316,
        0.18310024098129, 0.18141174883034175, 0.17929755172045864,
        0.17675764965164026, 0.17379204262388678, 0.17040073063719818,
        0.16658371369157451, 0.16234099178701611, 0.1576725649235223,
        0.15257843310109342, 0.14705859631972937, 0.1411130545794303,
        0.13474180788019657, 0.12794485622202736, 0.12072219960492303,
        0.11307383802888354, 0.10499977149390903, 0.0965, 0.096624037684577946,
        0.096744935174609609, 0.096862692470094991, 0.0969773095710341,
        0.097088786477426928, 0.097197123189273482, 0.097302319706573756,
        0.097404376029327763, 0.09750329215753549, 0.097599068091196936,
        0.0976917038303121, 0.097781199374881, 0.0978675547249036,
        0.097950769880379956, 0.098030844841310014, 0.09810777960769379,
        0.0981815741795313, 0.09825222855682253, 0.098319742739567492,
        0.09838411672776616, 0.098445350521418562, 0.098503444120524683,
        0.098558397525084537, 0.098610210735098111, 0.09865888375056539,
        0.098704416571486417, 0.098746809197861149, 0.098786061629689614,
        0.0988221738669718, 0.0988551459097077, 0.098884977757897341,
        0.098911669411540684, 0.098935220870637761, 0.09895563213518857,
        0.098972903205193086, 0.098987034080651334, 0.0989980247615633,
        0.099005875247929, 0.099010585539748411, 0.099012155637021551,
        0.099010585539748411, 0.099005875247929, 0.0989980247615633,
        0.098987034080651334, 0.098972903205193086, 0.09895563213518857,
        0.098935220870637761, 0.098911669411540684, 0.098884977757897327,
        0.0988551459097077, 0.0988221738669718, 0.098786061629689614,
        0.098746809197861149, 0.0987044165714864, 0.09865888375056539,
        0.0986102107350981, 0.098558397525084537, 0.098503444120524683,
        0.098445350521418562, 0.09838411672776616, 0.098319742739567492,
        0.09825222855682253, 0.0981815741795313, 0.09810777960769379,
        0.098030844841310014, 0.097950769880379943, 0.0978675547249036,
        0.097781199374880987, 0.097691703830312088, 0.097599068091196936,
        0.097503292157535476, 0.097404376029327763, 0.097302319706573756,
        0.097197123189273482, 0.097088786477426928, 0.096977309571034093,
        0.096862692470094991, 0.0967449351746096, 0.096624037684577932, 0.0965,
        0.097826467628179134, 0.0991144869193096, 0.10036405787339138,
        0.10157518049042451, 0.10274785477040888, 0.10388208071334465,
        0.10497785831923176, 0.10603518758807019, 0.10705406851985996,
        0.10803450111460099, 0.10897648537229349, 0.10988002129293717,
        0.11074510887653219, 0.11157174812307867, 0.11235993903257636,
        0.11310968160502549, 0.11382097584042583, 0.11449382173877752,
        0.11512821930008063, 0.11572416852433498, 0.11628166941154074,
        0.11680072196169775, 0.11728132617480611, 0.11772348205086584,
        0.11812718958987685, 0.11849244879183925, 0.11881925965675293,
        0.11910762218461793, 0.11935753637543431, 0.11956900222920197,
        0.119742019745921, 0.11987658892559133, 0.119972709768213,
        0.12003038227378601, 0.12004960644231036, 0.12003038227378601,
        0.119972709768213, 0.11987658892559135, 0.11974201974592098,
        0.11956900222920197, 0.11935753637543427, 0.11910762218461793,
        0.11881925965675293, 0.11849244879183921, 0.11812718958987685,
        0.11772348205086577, 0.11728132617480611, 0.11680072196169775,
        0.11628166941154067, 0.11572416852433498, 0.11512821930008055,
        0.11449382173877753, 0.11382097584042584, 0.11310968160502538,
        0.11235993903257636, 0.11157174812307856, 0.1107451088765322,
        0.10988002129293718, 0.10897648537229335, 0.108034501114601,
        0.10705406851985982, 0.10603518758807012, 0.10497785831923176,
        0.10388208071334457, 0.10274785477040888, 0.10157518049042434,
        0.1003640578733913, 0.0991144869193096, 0.097826467628179051, 0.0965,
        0.096624037684577946, 0.096744935174609609, 0.096862692470094977,
        0.096977309571034093, 0.097088786477426914, 0.097197123189273482,
        0.097302319706573756, 0.097404376029327736, 0.097503292157535476,
        0.097599068091196908, 0.097691703830312088, 0.097781199374880973,
        0.097867554724903577, 0.097950769880379929, 0.098030844841309986,
        0.098107779607693776, 0.098181574179531272, 0.0982522285568225,
        0.098319742739567464, 0.098384116727766133, 0.098445350521418534,
        0.098503444120524655, 0.0985583975250845, 0.098610210735098069,
        0.098658883750565363, 0.098704416571486375, 0.098746809197861107,
        0.098786061629689573, 0.098822173866971758, 0.098855145909707662,
        0.0988849777578973, 0.098911669411540656, 0.098935220870637719,
        0.098955632135188529, 0.098972903205193044, 0.098987034080651293,
        0.098998024761563261, 0.099005875247928962, 0.099010585539748369,
        0.099012155637021509, 0.099010585539748369, 0.099005875247928948,
        0.098998024761563261, 0.098987034080651293, 0.098972903205193044,
        0.098955632135188529, 0.098935220870637719, 0.098911669411540656,
        0.0988849777578973, 0.098855145909707662, 0.098822173866971758,
        0.098786061629689573, 0.098746809197861107, 0.098704416571486375,
        0.098658883750565363, 0.098610210735098069, 0.0985583975250845,
        0.098503444120524655, 0.098445350521418534, 0.098384116727766133,
        0.098319742739567451, 0.0982522285568225, 0.098181574179531272,
        0.098107779607693762, 0.098030844841309986, 0.097950769880379915,
        0.097867554724903577, 0.097781199374880959, 0.097691703830312074,
        0.097599068091196908, 0.097503292157535462, 0.097404376029327749,
        0.097302319706573728, 0.097197123189273468, 0.097088786477426914,
        0.096977309571034079, 0.096862692470094977, 0.096744935174609581,
        0.096624037684577932, 0.0965, 0.097826467628179231, 0.0991144869193096,
        0.10036405787339148, 0.10157518049042451, 0.10274785477040888,
        0.10388208071334473, 0.10497785831923176, 0.10603518758807028,
        0.10705406851985996, 0.10803450111460099, 0.10897648537229349,
        0.10988002129293717, 0.11074510887653231, 0.11157174812307867,
        0.11235993903257636, 0.11310968160502549, 0.11382097584042583,
        0.11449382173877762, 0.11512821930008063, 0.11572416852433498,
        0.11628166941154074, 0.11680072196169775, 0.11728132617480616,
        0.11772348205086584, 0.11812718958987685, 0.11849244879183925,
        0.11881925965675293, 0.11910762218461796, 0.11935753637543431,
        0.11956900222920197, 0.119742019745921, 0.11987658892559133,
        0.11997270976821302, 0.12003038227378601, 0.12004960644231036,
        0.12003038227378601, 0.119972709768213, 0.11987658892559132,
        0.11974201974592098, 0.11956900222920197, 0.11935753637543427,
        0.11910762218461793, 0.11881925965675288, 0.11849244879183921,
        0.11812718958987685, 0.11772348205086577, 0.11728132617480611,
        0.11680072196169769, 0.11628166941154067, 0.11572416852433498,
        0.11512821930008055, 0.11449382173877753, 0.11382097584042575,
        0.11310968160502538, 0.11235993903257636, 0.11157174812307856,
        0.1107451088765322, 0.10988002129293704, 0.10897648537229335,
        0.108034501114601, 0.10705406851985982, 0.10603518758807012,
        0.10497785831923161, 0.10388208071334457, 0.10274785477040888,
        0.10157518049042434, 0.1003640578733913, 0.099114486919309422,
        0.097826467628179051, 0.0965, 0.10499977149391018, 0.1130738380288841,
        0.12072219960492403, 0.12794485622202781, 0.13474180788019657,
        0.14111305457943116, 0.14705859631972978, 0.15257843310109415,
        0.15767256492352266, 0.16234099178701611, 0.16658371369157515,
        0.17040073063719849, 0.17379204262388726, 0.17675764965164048,
        0.17929755172045866, 0.18141174883034211, 0.18310024098129016,
        0.18436302817330336, 0.18520011040638129, 0.18561148768052418,
        0.18559715999573204, 0.18515712735200482, 0.18429138974934242,
        0.18299994718774507, 0.1812827996672127, 0.17913994718774495,
        0.17657138974934244, 0.17357712735200448, 0.17015715999573183,
        0.16631148768052417, 0.16204011040638089, 0.15734302817330306,
        0.1522202409812895, 0.14667174883034162, 0.14069755172045864,
        0.13429764965163973, 0.1274720426238867, 0.12022073063719754,
        0.11254371369157433, 0.10444099178701613, 0.09591256492352164,
        0.08695843310109326, 0.077578596319728535, 0.067773054579430086,
        0.05754180788019661, 0.046884856222026483, 0.035802199604922876,
        0.024293838028882561, 0.012359771493908767, 0.0, -0.0040670744334111537,
        -0.008051985746954848, -0.011954733940632215, -0.015775319014442145,
        -0.0195137409683852, -0.023169999802461896, -0.026744095516671184,
        -0.030236028111014092, -0.03364579758548962, -0.036973403940098272,
        -0.040218847174840505, -0.0433821272897154, -0.046463244284723842,
        -0.049462198159864967, -0.052378988915139216, -0.05521361655054699,
        -0.057966081066087478, -0.060636382461761465, -0.063224520737568179,
        -0.065730495893508045, -0.06815430792958134, -0.070495956845787439,
        -0.072755442642126952, -0.0749327653185993, -0.07702792487520474,
        -0.0790409213119436, -0.080971754628815271, -0.082820424825820346,
        -0.084586931902958254, -0.0862712758602293, -0.087873456697633689,
        -0.089393474415170968, -0.090831329012841577, -0.0921870204906451,
        -0.093460548848581737, -0.094651914086651676, -0.095761116204854543,
        -0.096788155203190687, -0.097733031081659816, -0.098595743840262054,
        -0.099376293478997527, -0.100074679997866, -0.10069090339686769,
        -0.10122496367600241, -0.10167686083527024, -0.10204659487467126,
        -0.10233416579420532, -0.10253957359387256, -0.10266281827367285,
        -0.10270389983360631, -0.10266281827367284, -0.10253957359387253,
        -0.10233416579420528, -0.1020465948746712, -0.10167686083527022,
        -0.10122496367600232, -0.10069090339686759, -0.1000746799978659,
        -0.0993762934789974, -0.098595743840262026, -0.097733031081659663,
        -0.096788155203190521, -0.095761116204854377, -0.094651914086651467,
        -0.093460548848581723, -0.092187020490644866, -0.090831329012841355,
        -0.089393474415170718, -0.08787345669763344, -0.086271275860229257,
        -0.084586931902957976, -0.082820424825820041, -0.080971754628814965,
        -0.079040921311943263, -0.0770279248752047, -0.074932765318598937,
        -0.072755442642126619, -0.070495956845787092, -0.068154307929580979,
        -0.06573049589350799, -0.063224520737567791, -0.060636382461761042,
        -0.057966081066087055, -0.055213616550546539, -0.052378988915139146,
        -0.049462198159864489, -0.046463244284723336, -0.04338212728971489,
        -0.040218847174839971, -0.036973403940098182, -0.033645797585489058,
        -0.030236028111013506, -0.026744095516670598, -0.023169999802461282,
        -0.019513740968385151, -0.015775319014441506, -0.011954733940631615,
        -0.00805198574695418, -0.0040670744334105275, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 } ;

      full_loop_DW.FromWorkspace1_PWORK.TimePtr = static_cast<void *>
        (pTimeValues0);
      full_loop_DW.FromWorkspace1_PWORK.DataPtr = static_cast<void *>
        (pDataValues0);
      full_loop_DW.FromWorkspace1_IWORK.PrevIndex = 0;
    }

    // InitializeConditions for Memory: '<S70>/LastPcov'
    memcpy(&full_loop_DW.LastPcov_PreviousInput[0],
           &full_loop_P.LastPcov_InitialCondition[0], 400U * sizeof(real_T));

    // InitializeConditions for Memory: '<S70>/last_x'
    memcpy(&full_loop_DW.last_x_PreviousInput[0],
           &full_loop_P.last_x_InitialCondition[0], 20U * sizeof(real_T));

    // InitializeConditions for UnitDelay: '<S70>/last_mv'
    memcpy(&full_loop_DW.last_mv_DSTATE[0],
           &full_loop_P.last_mv_InitialCondition[0], sizeof(real_T) << 3U);

    // InitializeConditions for Integrator: '<S13>/ub,vb,wb'
    full_loop_X.ubvbwb_CSTATE[0] = full_loop_P.uDOFEulerAngles_Vm_0[0];

    // InitializeConditions for DiscreteIntegrator: '<S5>/Discrete-Time Integrator1' 
    full_loop_DW.DiscreteTimeIntegrator1_DSTATE[0] =
      full_loop_P.DiscreteTimeIntegrator1_IC;

    // InitializeConditions for Integrator: '<S13>/ub,vb,wb'
    full_loop_X.ubvbwb_CSTATE[1] = full_loop_P.uDOFEulerAngles_Vm_0[1];

    // InitializeConditions for DiscreteIntegrator: '<S5>/Discrete-Time Integrator1' 
    full_loop_DW.DiscreteTimeIntegrator1_DSTATE[1] =
      full_loop_P.DiscreteTimeIntegrator1_IC;

    // InitializeConditions for Integrator: '<S13>/ub,vb,wb'
    full_loop_X.ubvbwb_CSTATE[2] = full_loop_P.uDOFEulerAngles_Vm_0[2];

    // InitializeConditions for DiscreteIntegrator: '<S5>/Discrete-Time Integrator1' 
    full_loop_DW.DiscreteTimeIntegrator1_DSTATE[2] =
      full_loop_P.DiscreteTimeIntegrator1_IC;

    // InitializeConditions for RandomNumber: '<S65>/White Noise'
    full_loop_B.d2 = floor(full_loop_P.BandLimitedWhiteNoise_seed);
    if (rtIsNaN(full_loop_B.d2) || rtIsInf(full_loop_B.d2)) {
      full_loop_B.d2 = 0.0;
    } else {
      full_loop_B.d2 = fmod(full_loop_B.d2, 4.294967296E+9);
    }

    tseed = full_loop_B.d2 < 0.0 ? static_cast<uint32_T>(-static_cast<int32_T>(
      static_cast<uint32_T>(-full_loop_B.d2))) : static_cast<uint32_T>
      (full_loop_B.d2);
    r = static_cast<int32_T>(tseed >> 16U);
    t = static_cast<int32_T>(tseed & 32768U);
    full_loop_DW.RandSeed = ((((tseed - (static_cast<uint32_T>(r) << 16U)) + t) <<
      16U) + t) + r;
    if (full_loop_DW.RandSeed < 1U) {
      full_loop_DW.RandSeed = 1144108930U;
    } else {
      if (full_loop_DW.RandSeed > 2147483646U) {
        full_loop_DW.RandSeed = 2147483646U;
      }
    }

    full_loop_DW.NextOutput = rt_nrand_Upu32_Yd_f_pw_snf(&full_loop_DW.RandSeed)
      * full_loop_P.WhiteNoise_StdDev + full_loop_P.WhiteNoise_Mean;

    // End of InitializeConditions for RandomNumber: '<S65>/White Noise'

    // InitializeConditions for Integrator: '<S19>/q0 q1 q2 q3'
    if (rtmIsFirstInitCond(full_loop_M)) {
      full_loop_X.q0q1q2q3_CSTATE[0] = 0.0;
      full_loop_X.q0q1q2q3_CSTATE[1] = 0.0;
      full_loop_X.q0q1q2q3_CSTATE[2] = 0.0;
      full_loop_X.q0q1q2q3_CSTATE[3] = 0.0;
    }

    full_loop_DW.q0q1q2q3_IWORK = 1;

    // End of InitializeConditions for Integrator: '<S19>/q0 q1 q2 q3'

    // InitializeConditions for Memory: '<S59>/Memory'
    full_loop_DW.Memory_PreviousInput[0] = full_loop_P.Memory_InitialCondition[0];
    full_loop_DW.Memory_PreviousInput[1] = full_loop_P.Memory_InitialCondition[1];
    full_loop_DW.Memory_PreviousInput[2] = full_loop_P.Memory_InitialCondition[2];
    full_loop_DW.Memory_PreviousInput[3] = full_loop_P.Memory_InitialCondition[3];

    // InitializeConditions for RandomNumber: '<S66>/White Noise'
    full_loop_B.d2 = floor(full_loop_P.BandLimitedWhiteNoise1_seed);
    if (rtIsNaN(full_loop_B.d2) || rtIsInf(full_loop_B.d2)) {
      full_loop_B.d2 = 0.0;
    } else {
      full_loop_B.d2 = fmod(full_loop_B.d2, 4.294967296E+9);
    }

    tseed = full_loop_B.d2 < 0.0 ? static_cast<uint32_T>(-static_cast<int32_T>(
      static_cast<uint32_T>(-full_loop_B.d2))) : static_cast<uint32_T>
      (full_loop_B.d2);
    r = static_cast<int32_T>(tseed >> 16U);
    t = static_cast<int32_T>(tseed & 32768U);
    full_loop_DW.RandSeed_k = ((((tseed - (static_cast<uint32_T>(r) << 16U)) + t)
      << 16U) + t) + r;
    if (full_loop_DW.RandSeed_k < 1U) {
      full_loop_DW.RandSeed_k = 1144108930U;
    } else {
      if (full_loop_DW.RandSeed_k > 2147483646U) {
        full_loop_DW.RandSeed_k = 2147483646U;
      }
    }

    full_loop_DW.NextOutput_b = rt_nrand_Upu32_Yd_f_pw_snf
      (&full_loop_DW.RandSeed_k) * full_loop_P.WhiteNoise_StdDev_a +
      full_loop_P.WhiteNoise_Mean_m;

    // End of InitializeConditions for RandomNumber: '<S66>/White Noise'

    // InitializeConditions for Integrator: '<S13>/p,q,r '
    full_loop_X.pqr_CSTATE[0] = full_loop_P.uDOFEulerAngles_pm_0[0];

    // InitializeConditions for Memory: '<S4>/Memory5'
    full_loop_DW.Memory5_PreviousInput[0] =
      full_loop_P.Memory5_InitialCondition[0];

    // InitializeConditions for Integrator: '<S13>/p,q,r '
    full_loop_X.pqr_CSTATE[1] = full_loop_P.uDOFEulerAngles_pm_0[1];

    // InitializeConditions for Memory: '<S4>/Memory5'
    full_loop_DW.Memory5_PreviousInput[1] =
      full_loop_P.Memory5_InitialCondition[1];

    // InitializeConditions for Integrator: '<S13>/p,q,r '
    full_loop_X.pqr_CSTATE[2] = full_loop_P.uDOFEulerAngles_pm_0[2];

    // InitializeConditions for Memory: '<S4>/Memory5'
    full_loop_DW.Memory5_PreviousInput[2] =
      full_loop_P.Memory5_InitialCondition[2];

    // InitializeConditions for Memory: '<S4>/Memory3'
    memcpy(&full_loop_DW.Memory3_PreviousInput[0], &full_loop_P.Xi[0], 12U *
           sizeof(real_T));

    // InitializeConditions for DiscreteIntegrator: '<S5>/Discrete-Time Integrator' 
    full_loop_DW.DiscreteTimeIntegrator_DSTATE[0] =
      full_loop_P.DiscreteTimeIntegrator_IC;

    // InitializeConditions for Memory: '<S6>/Memory'
    full_loop_DW.Memory_PreviousInput_p[0] =
      full_loop_P.Memory_InitialCondition_p;

    // InitializeConditions for DiscreteIntegrator: '<S5>/Discrete-Time Integrator' 
    full_loop_DW.DiscreteTimeIntegrator_DSTATE[1] =
      full_loop_P.DiscreteTimeIntegrator_IC;

    // InitializeConditions for Memory: '<S6>/Memory'
    full_loop_DW.Memory_PreviousInput_p[1] =
      full_loop_P.Memory_InitialCondition_p;

    // InitializeConditions for DiscreteIntegrator: '<S5>/Discrete-Time Integrator' 
    full_loop_DW.DiscreteTimeIntegrator_DSTATE[2] =
      full_loop_P.DiscreteTimeIntegrator_IC;

    // InitializeConditions for Memory: '<S6>/Memory'
    full_loop_DW.Memory_PreviousInput_p[2] =
      full_loop_P.Memory_InitialCondition_p;

    // InitializeConditions for Memory: '<S4>/Memory'
    memcpy(&full_loop_DW.Memory_PreviousInput_m[0], &full_loop_P.Ui[0], sizeof
           (real_T) << 3U);

    // InitializeConditions for Memory: '<S70>/Memory'
    full_loop_DW.Memory_PreviousInput_d[0] =
      full_loop_P.Memory_InitialCondition_a[0];
    full_loop_DW.Memory_PreviousInput_d[1] =
      full_loop_P.Memory_InitialCondition_a[1];
    full_loop_DW.Memory_PreviousInput_d[2] =
      full_loop_P.Memory_InitialCondition_a[2];
    full_loop_DW.Memory_PreviousInput_d[3] =
      full_loop_P.Memory_InitialCondition_a[3];

    // InitializeConditions for Integrator: '<S15>/Integrator'
    full_loop_X.Integrator_CSTATE[0] = full_loop_P.Integrator_IC;

    // InitializeConditions for Integrator: '<S13>/xe,ye,ze'
    full_loop_X.xeyeze_CSTATE[0] = full_loop_P.uDOFEulerAngles_xme_0[0];

    // InitializeConditions for Integrator: '<S15>/Integrator'
    full_loop_X.Integrator_CSTATE[1] = full_loop_P.Integrator_IC;

    // InitializeConditions for Integrator: '<S13>/xe,ye,ze'
    full_loop_X.xeyeze_CSTATE[1] = full_loop_P.uDOFEulerAngles_xme_0[1];

    // InitializeConditions for Integrator: '<S15>/Integrator'
    full_loop_X.Integrator_CSTATE[2] = full_loop_P.Integrator_IC;

    // InitializeConditions for Integrator: '<S13>/xe,ye,ze'
    full_loop_X.xeyeze_CSTATE[2] = full_loop_P.uDOFEulerAngles_xme_0[2];

    // SystemInitialize for Atomic SubSystem: '<S2>/Publish'
    // Start for MATLABSystem: '<S9>/SinkBlock'
    full_loop_DW.obj_k.matlabCodegenIsDeleted = false;
    full_loop_DW.obj_k.isInitialized = 1;
    for (r = 0; r < 23; r++) {
      full_loop_B.cv[r] = tmp_1[r];
    }

    full_loop_B.cv[23] = '\x00';
    Pub_full_loop_206.createPublisher(full_loop_B.cv, 1);
    full_loop_DW.obj_k.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S9>/SinkBlock'
    // End of SystemInitialize for SubSystem: '<S2>/Publish'

    // Start for MATLABSystem: '<S4>/MATLAB System' incorporates:
    //   Constant: '<S4>/Constant'
    //   Constant: '<S4>/Constant2'

    full_loop_DW.obj_c.isInitialized = 1;

    //  Calcule la commande des moteurs pour compenser la force gravitationnelle. Etant donne que le sous marin flotte, la force gravitationelle est une condition non nulle. Il faut la calculer en dehors du controleur 
    //  Matrice Trusters
    //  Matrice Gravite
    //  Force thruster min
    //  Force thruster max
    //  Commande precedente
    //  Pre-computed constants
    //  Initialiser les matrices
    memcpy(&full_loop_DW.obj_c.Aeq[0], &tmp[0], 48U * sizeof(real_T));
    full_loop_Gravity(full_loop_B.checkedPose, full_loop_DW.obj_c.Beq);

    //  condition initial
    // limites thrusters
    memcpy(&full_loop_DW.obj_c.u0[0], &tmp_0[0], sizeof(real_T) << 3U);
    memcpy(&full_loop_DW.obj_c.uMin[0], &full_loop_P.TMIN[0], sizeof(real_T) <<
           3U);
    memcpy(&full_loop_DW.obj_c.uMax[0], &full_loop_P.TMAX[0], sizeof(real_T) <<
           3U);

    // Start for MATLABSystem: '<S4>/MATLAB System1'
    //  Initialize / reset discrete-state properties
    full_loop_DW.obj.isInitialized = 1;

    // Cette fonction linearise le modele en fonctions des etats et de la commande actuelle. 
    //  Matrice A domaine continue
    //  Matrice B domaine continue
    //  Matrice C domaine continue
    //  Matrice D domaine continue
    //  Pre-computed constants
    //  Perform one-time calculations, such as computing constants
    full_loop_AUVStateJacobianFcn(full_loop_B.checkedPose, full_loop_DW.obj.Ac,
      full_loop_DW.obj.Bc, full_loop_DW.obj.Cc, full_loop_DW.obj.Dc);

    //  Initialize / reset discrete-state properties
  }

  // set "at time zero" to false
  if (rtmIsFirstInitCond(full_loop_M)) {
    rtmSetFirstInitCond(full_loop_M, 0);
  }
}

// Model terminate function
void full_loop_terminate(void)
{
  // Terminate for Atomic SubSystem: '<S2>/Publish'
  // Terminate for MATLABSystem: '<S9>/SinkBlock'
  matlabCodegenHandle_matlabCodeg(&full_loop_DW.obj_k);

  // End of Terminate for SubSystem: '<S2>/Publish'
}

//
// File trailer for generated code.
//
// [EOF]
//
