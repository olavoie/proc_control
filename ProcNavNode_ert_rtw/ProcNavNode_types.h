//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: ProcNavNode_types.h
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
#ifndef RTW_HEADER_ProcNavNode_types_h_
#define RTW_HEADER_ProcNavNode_types_h_
#include "rtwtypes.h"

// Model Code Variants
#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_ProcNavNode_geometry_msgs_Quaternion_
#define DEFINED_TYPEDEF_FOR_SL_Bus_ProcNavNode_geometry_msgs_Quaternion_

// MsgType=geometry_msgs/Quaternion
typedef struct {
  real_T X;
  real_T Y;
  real_T Z;
  real_T W;
} SL_Bus_ProcNavNode_geometry_msgs_Quaternion;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_ProcNavNode_geometry_msgs_Vector3_
#define DEFINED_TYPEDEF_FOR_SL_Bus_ProcNavNode_geometry_msgs_Vector3_

// MsgType=geometry_msgs/Vector3
typedef struct {
  real_T X;
  real_T Y;
  real_T Z;
} SL_Bus_ProcNavNode_geometry_msgs_Vector3;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_ProcNavNode_geometry_msgs_Accel_
#define DEFINED_TYPEDEF_FOR_SL_Bus_ProcNavNode_geometry_msgs_Accel_

// MsgType=geometry_msgs/Accel
typedef struct {
  // MsgType=geometry_msgs/Vector3
  SL_Bus_ProcNavNode_geometry_msgs_Vector3 Linear;

  // MsgType=geometry_msgs/Vector3
  SL_Bus_ProcNavNode_geometry_msgs_Vector3 Angular;
} SL_Bus_ProcNavNode_geometry_msgs_Accel;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_ProcNavNode_sonia_common_ImuInformation_
#define DEFINED_TYPEDEF_FOR_SL_Bus_ProcNavNode_sonia_common_ImuInformation_

// MsgType=sonia_common/ImuInformation
typedef struct {
  // MsgType=geometry_msgs/Quaternion
  SL_Bus_ProcNavNode_geometry_msgs_Quaternion Quaternion;

  // MsgType=geometry_msgs/Accel
  SL_Bus_ProcNavNode_geometry_msgs_Accel Acceleration;

  // MsgType=geometry_msgs/Vector3
  SL_Bus_ProcNavNode_geometry_msgs_Vector3 Magnetometer;
} SL_Bus_ProcNavNode_sonia_common_ImuInformation;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_ROSVariableLengthArrayInfo_
#define DEFINED_TYPEDEF_FOR_SL_Bus_ROSVariableLengthArrayInfo_

typedef struct {
  uint32_T CurrentLength;
  uint32_T ReceivedLength;
} SL_Bus_ROSVariableLengthArrayInfo;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_ProcNavNode_ros_time_Time_
#define DEFINED_TYPEDEF_FOR_SL_Bus_ProcNavNode_ros_time_Time_

// MsgType=ros_time/Time
typedef struct {
  real_T Sec;
  real_T Nsec;
} SL_Bus_ProcNavNode_ros_time_Time;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_ProcNavNode_std_msgs_Header_
#define DEFINED_TYPEDEF_FOR_SL_Bus_ProcNavNode_std_msgs_Header_

// MsgType=std_msgs/Header
typedef struct {
  uint32_T Seq;

  // PrimitiveROSType=string:IsVarLen=1:VarLenCategory=data:VarLenElem=FrameId_SL_Info:TruncateAction=warn 
  uint8_T FrameId[128];

  // IsVarLen=1:VarLenCategory=length:VarLenElem=FrameId
  SL_Bus_ROSVariableLengthArrayInfo FrameId_SL_Info;

  // MsgType=ros_time/Time
  SL_Bus_ProcNavNode_ros_time_Time Stamp;
} SL_Bus_ProcNavNode_std_msgs_Header;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_ProcNavNode_sonia_common_BodyVelocityDVL_
#define DEFINED_TYPEDEF_FOR_SL_Bus_ProcNavNode_sonia_common_BodyVelocityDVL_

// MsgType=sonia_common/BodyVelocityDVL
typedef struct {
  real_T XVelBtm;
  real_T YVelBtm;
  real_T ZVelBtm;
  real_T EVelBtm;

  // MsgType=std_msgs/Header
  SL_Bus_ProcNavNode_std_msgs_Header Header;
} SL_Bus_ProcNavNode_sonia_common_BodyVelocityDVL;

#endif

#ifndef struct_tag_9SewJ4y3IXNs5GrZti8qkG
#define struct_tag_9SewJ4y3IXNs5GrZti8qkG

struct tag_9SewJ4y3IXNs5GrZti8qkG
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
};

#endif                                 //struct_tag_9SewJ4y3IXNs5GrZti8qkG

#ifndef typedef_ros_slros_internal_block_Subs_T
#define typedef_ros_slros_internal_block_Subs_T

typedef struct tag_9SewJ4y3IXNs5GrZti8qkG ros_slros_internal_block_Subs_T;

#endif                                 //typedef_ros_slros_internal_block_Subs_T

#ifndef struct_tag_6H4JrUjkWPrBy6FZW4fMiE
#define struct_tag_6H4JrUjkWPrBy6FZW4fMiE

struct tag_6H4JrUjkWPrBy6FZW4fMiE
{
  real_T tcount[3];
  real_T lastAngle[3];
};

#endif                                 //struct_tag_6H4JrUjkWPrBy6FZW4fMiE

#ifndef typedef_DiscontinuityCheck_ProcNavNod_T
#define typedef_DiscontinuityCheck_ProcNavNod_T

typedef struct tag_6H4JrUjkWPrBy6FZW4fMiE DiscontinuityCheck_ProcNavNod_T;

#endif                                 //typedef_DiscontinuityCheck_ProcNavNod_T

// Parameters (default storage)
typedef struct P_ProcNavNode_T_ P_ProcNavNode_T;

// Forward declaration for rtModel
typedef struct tag_RTM_ProcNavNode_T RT_MODEL_ProcNavNode_T;

#endif                                 // RTW_HEADER_ProcNavNode_types_h_

//
// File trailer for generated code.
//
// [EOF]
//
