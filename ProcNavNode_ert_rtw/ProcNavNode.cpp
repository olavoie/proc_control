//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: ProcNavNode.cpp
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
#include "ProcNavNode.h"
#include "ProcNavNode_private.h"

// Block signals (default storage)
B_ProcNavNode_T ProcNavNode_B;

// Block states (default storage)
DW_ProcNavNode_T ProcNavNode_DW;

// Real-time model
RT_MODEL_ProcNavNode_T ProcNavNode_M_ = RT_MODEL_ProcNavNode_T();
RT_MODEL_ProcNavNode_T *const ProcNavNode_M = &ProcNavNode_M_;

// Forward declaration for local functions
static void matlabCodegenHandle_matlabCodeg(ros_slros_internal_block_Subs_T *obj);
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

static void matlabCodegenHandle_matlabCodeg(ros_slros_internal_block_Subs_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
  }
}

// Model step function
void ProcNavNode_step(void)
{
  boolean_T x[3];
  int32_T b_k;
  boolean_T b_varargout_1;
  int32_T b_i;
  real_T rtb_qS2W_idx_2;
  real_T rtb_qS2W_idx_3;
  real_T rtb_VectorConcatenate_tmp;
  real_T rtb_VectorConcatenate_tmp_0;
  real_T rtb_VectorConcatenate_tmp_1;
  boolean_T exitg1;

  // Outputs for Atomic SubSystem: '<S1>/Subscribe'
  // MATLABSystem: '<S3>/SourceBlock' incorporates:
  //   Inport: '<S5>/In1'

  b_varargout_1 = Sub_ProcNavNode_795.getLatestMessage
    (&ProcNavNode_B.b_varargout_2_m);

  // Outputs for Enabled SubSystem: '<S3>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S5>/Enable'

  if (b_varargout_1) {
    ProcNavNode_B.In1 = ProcNavNode_B.b_varargout_2_m;
  }

  // End of MATLABSystem: '<S3>/SourceBlock'
  // End of Outputs for SubSystem: '<S3>/Enabled Subsystem'
  // End of Outputs for SubSystem: '<S1>/Subscribe'

  // Gain: '<S2>/Gain1'
  ProcNavNode_B.rtb_qS2W_idx_0 = ProcNavNode_P.Gain1_Gain *
    ProcNavNode_B.In1.Quaternion.W;
  ProcNavNode_B.rtb_qS2W_idx_1 = ProcNavNode_P.Gain1_Gain *
    ProcNavNode_B.In1.Quaternion.X;
  rtb_qS2W_idx_2 = ProcNavNode_P.Gain1_Gain * ProcNavNode_B.In1.Quaternion.Y;
  rtb_qS2W_idx_3 = ProcNavNode_P.Gain1_Gain * ProcNavNode_B.In1.Quaternion.Z;

  // Sqrt: '<S25>/sqrt' incorporates:
  //   Product: '<S26>/Product'
  //   Product: '<S26>/Product1'
  //   Product: '<S26>/Product2'
  //   Product: '<S26>/Product3'
  //   Sum: '<S26>/Sum'

  ProcNavNode_B.Product3 = sqrt(((ProcNavNode_B.rtb_qS2W_idx_0 *
    ProcNavNode_B.rtb_qS2W_idx_0 + ProcNavNode_B.rtb_qS2W_idx_1 *
    ProcNavNode_B.rtb_qS2W_idx_1) + rtb_qS2W_idx_2 * rtb_qS2W_idx_2) +
    rtb_qS2W_idx_3 * rtb_qS2W_idx_3);

  // Product: '<S20>/Product'
  ProcNavNode_B.rtb_qS2W_idx_0 /= ProcNavNode_B.Product3;

  // Product: '<S20>/Product1'
  ProcNavNode_B.rtb_qS2W_idx_1 /= ProcNavNode_B.Product3;

  // Product: '<S20>/Product2'
  rtb_qS2W_idx_2 /= ProcNavNode_B.Product3;

  // Product: '<S20>/Product3'
  ProcNavNode_B.Product3 = rtb_qS2W_idx_3 / ProcNavNode_B.Product3;

  // Fcn: '<S18>/fcn2' incorporates:
  //   Fcn: '<S18>/fcn5'

  rtb_qS2W_idx_3 = ProcNavNode_B.rtb_qS2W_idx_0 * ProcNavNode_B.rtb_qS2W_idx_0;
  rtb_VectorConcatenate_tmp = ProcNavNode_B.rtb_qS2W_idx_1 *
    ProcNavNode_B.rtb_qS2W_idx_1;
  rtb_VectorConcatenate_tmp_0 = rtb_qS2W_idx_2 * rtb_qS2W_idx_2;
  rtb_VectorConcatenate_tmp_1 = ProcNavNode_B.Product3 * ProcNavNode_B.Product3;

  // Trigonometry: '<S19>/Trigonometric Function1' incorporates:
  //   Fcn: '<S18>/fcn1'
  //   Fcn: '<S18>/fcn2'

  ProcNavNode_B.VectorConcatenate[0] = rt_atan2d_snf((rtb_qS2W_idx_2 *
    ProcNavNode_B.Product3 - ProcNavNode_B.rtb_qS2W_idx_0 *
    ProcNavNode_B.rtb_qS2W_idx_1) * -2.0, ((rtb_qS2W_idx_3 -
    rtb_VectorConcatenate_tmp) - rtb_VectorConcatenate_tmp_0) +
    rtb_VectorConcatenate_tmp_1);

  // Fcn: '<S18>/fcn3'
  ProcNavNode_B.fcn3 = (ProcNavNode_B.rtb_qS2W_idx_1 * ProcNavNode_B.Product3 +
                        ProcNavNode_B.rtb_qS2W_idx_0 * rtb_qS2W_idx_2) * 2.0;

  // If: '<S21>/If' incorporates:
  //   Constant: '<S22>/Constant'
  //   Constant: '<S23>/Constant'

  if (ProcNavNode_B.fcn3 > 1.0) {
    ProcNavNode_B.fcn3 = ProcNavNode_P.Constant_Value_m;
  } else {
    if (ProcNavNode_B.fcn3 < -1.0) {
      ProcNavNode_B.fcn3 = ProcNavNode_P.Constant_Value_j;
    }
  }

  // End of If: '<S21>/If'

  // Trigonometry: '<S19>/trigFcn'
  if (ProcNavNode_B.fcn3 > 1.0) {
    ProcNavNode_B.fcn3 = 1.0;
  } else {
    if (ProcNavNode_B.fcn3 < -1.0) {
      ProcNavNode_B.fcn3 = -1.0;
    }
  }

  ProcNavNode_B.VectorConcatenate[1] = asin(ProcNavNode_B.fcn3);

  // End of Trigonometry: '<S19>/trigFcn'

  // Trigonometry: '<S19>/Trigonometric Function3' incorporates:
  //   Fcn: '<S18>/fcn4'
  //   Fcn: '<S18>/fcn5'

  ProcNavNode_B.VectorConcatenate[2] = rt_atan2d_snf
    ((ProcNavNode_B.rtb_qS2W_idx_1 * rtb_qS2W_idx_2 -
      ProcNavNode_B.rtb_qS2W_idx_0 * ProcNavNode_B.Product3) * -2.0,
     ((rtb_qS2W_idx_3 + rtb_VectorConcatenate_tmp) - rtb_VectorConcatenate_tmp_0)
     - rtb_VectorConcatenate_tmp_1);

  // MATLABSystem: '<S9>/MATLAB System2'
  //  Implement algorithm. Calculate y as a function of input u and
  //  discrete states.
  for (b_i = 0; b_i < 3; b_i++) {
    ProcNavNode_B.b_varargout_1[b_i] = ProcNavNode_B.VectorConcatenate[b_i];

    //  compute roll pitch yaw
    //  appliquer la discontinuté actuelle
    if (ProcNavNode_DW.obj.tcount[b_i] > 0.0) {
      ProcNavNode_B.b_varargout_1[b_i] = (ProcNavNode_B.VectorConcatenate[b_i] +
        3.1415926535897931) + 3.1415926535897931 * ProcNavNode_DW.obj.tcount[b_i];
    } else {
      x[0] = (ProcNavNode_DW.obj.tcount[0] < 0.0);
      x[1] = (ProcNavNode_DW.obj.tcount[1] < 0.0);
      x[2] = (ProcNavNode_DW.obj.tcount[2] < 0.0);
      b_varargout_1 = true;
      b_k = 0;
      exitg1 = false;
      while ((!exitg1) && (b_k < 3)) {
        if (!x[b_k]) {
          b_varargout_1 = false;
          exitg1 = true;
        } else {
          b_k++;
        }
      }

      if (b_varargout_1) {
        ProcNavNode_B.b_varargout_1[b_i] = (ProcNavNode_B.VectorConcatenate[b_i]
          - 3.1415926535897931) + 3.1415926535897931 *
          ProcNavNode_DW.obj.tcount[b_i];
      }
    }

    //  calculer la différence entre 2 point
    ProcNavNode_B.Product3 = ProcNavNode_DW.obj.lastAngle[b_i] -
      ProcNavNode_B.b_varargout_1[b_i];

    //  Verifier la discontinuité de laxe
    if (fabs(ProcNavNode_B.Product3) >= 3.1415926535897931) {
      //  Determiner le sens de la discontinuité
      if (ProcNavNode_B.Product3 > 0.0) {
        //  Ajouter un tour
        ProcNavNode_DW.obj.tcount[b_i]++;

        //  Recaluler l'angle
        if (ProcNavNode_DW.obj.tcount[b_i] == 0.0) {
          ProcNavNode_B.b_varargout_1[b_i] = ProcNavNode_B.VectorConcatenate[b_i];
        } else {
          ProcNavNode_B.b_varargout_1[b_i] =
            (ProcNavNode_B.VectorConcatenate[b_i] + 3.1415926535897931) +
            3.1415926535897931 * ProcNavNode_DW.obj.tcount[b_i];
        }
      } else {
        //  Soustraire un tour
        ProcNavNode_DW.obj.tcount[b_i]--;

        //  Recaluler l'angle
        if (ProcNavNode_DW.obj.tcount[b_i] == 0.0) {
          ProcNavNode_B.b_varargout_1[b_i] = ProcNavNode_B.VectorConcatenate[b_i];
        } else {
          ProcNavNode_B.b_varargout_1[b_i] =
            (ProcNavNode_B.VectorConcatenate[b_i] - 3.1415926535897931) +
            3.1415926535897931 * ProcNavNode_DW.obj.tcount[b_i];
        }
      }
    }

    ProcNavNode_DW.obj.lastAngle[b_i] = ProcNavNode_B.b_varargout_1[b_i];
  }

  // End of MATLABSystem: '<S9>/MATLAB System2'

  // Outputs for Atomic SubSystem: '<S1>/Subscribe1'
  // MATLABSystem: '<S4>/SourceBlock'
  Sub_ProcNavNode_796.getLatestMessage(&ProcNavNode_B.b_varargout_2);

  // End of Outputs for SubSystem: '<S1>/Subscribe1'
}

// Model initialize function
void ProcNavNode_initialize(void)
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));

  {
    char_T tmp[23];
    char_T tmp_0[27];
    int32_T i;
    static const char_T tmp_1[22] = { '/', 'p', 'r', 'o', 'v', 'i', 'd', 'e',
      'r', '_', 'i', 'm', 'u', '/', 'i', 'm', 'u', '_', 'i', 'n', 'f', 'o' };

    static const char_T tmp_2[26] = { '/', 'p', 'r', 'o', 'v', 'i', 'd', 'e',
      'r', '_', 'd', 'v', 'l', '/', 'd', 'v', 'l', '_', 'v', 'e', 'l', 'o', 'c',
      'i', 't', 'y' };

    // SystemInitialize for Atomic SubSystem: '<S1>/Subscribe'
    // SystemInitialize for Enabled SubSystem: '<S3>/Enabled Subsystem'
    // SystemInitialize for Outport: '<S5>/Out1'
    ProcNavNode_B.In1 = ProcNavNode_P.Out1_Y0_h;

    // End of SystemInitialize for SubSystem: '<S3>/Enabled Subsystem'

    // Start for MATLABSystem: '<S3>/SourceBlock'
    ProcNavNode_DW.obj_b.matlabCodegenIsDeleted = false;
    ProcNavNode_DW.obj_b.isInitialized = 1;
    for (i = 0; i < 22; i++) {
      tmp[i] = tmp_1[i];
    }

    tmp[22] = '\x00';
    Sub_ProcNavNode_795.createSubscriber(tmp, 1);
    ProcNavNode_DW.obj_b.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S3>/SourceBlock'
    // End of SystemInitialize for SubSystem: '<S1>/Subscribe'

    // SystemInitialize for Atomic SubSystem: '<S1>/Subscribe1'
    // Start for MATLABSystem: '<S4>/SourceBlock'
    ProcNavNode_DW.obj_i.matlabCodegenIsDeleted = false;
    ProcNavNode_DW.obj_i.isInitialized = 1;
    for (i = 0; i < 26; i++) {
      tmp_0[i] = tmp_2[i];
    }

    tmp_0[26] = '\x00';
    Sub_ProcNavNode_796.createSubscriber(tmp_0, 1);
    ProcNavNode_DW.obj_i.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S4>/SourceBlock'
    // End of SystemInitialize for SubSystem: '<S1>/Subscribe1'

    // Start for MATLABSystem: '<S9>/MATLAB System2'
    //  Cette fonction vérifie et corrige au besoin la discontinuite des angles de rotation. 
    //
    //  Nombre de tours
    //  Dernière de Position
    //  Pre-computed constants
    //  Perform one-time calculations, such as computing constants
    ProcNavNode_DW.obj.tcount[0] = 0.0;
    ProcNavNode_DW.obj.lastAngle[0] = 0.0;
    ProcNavNode_DW.obj.tcount[1] = 0.0;
    ProcNavNode_DW.obj.lastAngle[1] = 0.0;
    ProcNavNode_DW.obj.tcount[2] = 0.0;
    ProcNavNode_DW.obj.lastAngle[2] = 0.0;

    //  Initialize / reset discrete-state properties
  }
}

// Model terminate function
void ProcNavNode_terminate(void)
{
  // Terminate for Atomic SubSystem: '<S1>/Subscribe'
  // Terminate for MATLABSystem: '<S3>/SourceBlock'
  matlabCodegenHandle_matlabCodeg(&ProcNavNode_DW.obj_b);

  // End of Terminate for SubSystem: '<S1>/Subscribe'

  // Terminate for Atomic SubSystem: '<S1>/Subscribe1'
  // Terminate for MATLABSystem: '<S4>/SourceBlock'
  matlabCodegenHandle_matlabCodeg(&ProcNavNode_DW.obj_i);

  // End of Terminate for SubSystem: '<S1>/Subscribe1'
}

//
// File trailer for generated code.
//
// [EOF]
//
