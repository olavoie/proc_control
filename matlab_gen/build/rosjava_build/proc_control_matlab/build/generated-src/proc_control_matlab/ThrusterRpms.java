package proc_control_matlab;

public interface ThrusterRpms extends org.ros.internal.message.Message {
  static final java.lang.String _TYPE = "proc_control_matlab/ThrusterRpms";
  static final java.lang.String _DEFINITION = "int32 T1_Rpm\nint32 T2_Rpm\nint32 T3_Rpm\nint32 T4_Rpm\nint32 T5_Rpm\nint32 T6_Rpm\nint32 T7_Rpm\nint32 T8_Rpm";
  static final boolean _IS_SERVICE = false;
  static final boolean _IS_ACTION = false;
  int getT1Rpm();
  void setT1Rpm(int value);
  int getT2Rpm();
  void setT2Rpm(int value);
  int getT3Rpm();
  void setT3Rpm(int value);
  int getT4Rpm();
  void setT4Rpm(int value);
  int getT5Rpm();
  void setT5Rpm(int value);
  int getT6Rpm();
  void setT6Rpm(int value);
  int getT7Rpm();
  void setT7Rpm(int value);
  int getT8Rpm();
  void setT8Rpm(int value);
}
