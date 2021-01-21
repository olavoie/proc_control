package proc_control_matlab;

public interface ThrusterForces extends org.ros.internal.message.Message {
  static final java.lang.String _TYPE = "proc_control_matlab/ThrusterForces";
  static final java.lang.String _DEFINITION = "int32 T1_Force\nint32 T2_Force\nint32 T3_Force\nint32 T4_Force\nint32 T5_Force\nint32 T6_Force\nint32 T7_Force\nint32 T8_Force";
  static final boolean _IS_SERVICE = false;
  static final boolean _IS_ACTION = false;
  int getT1Force();
  void setT1Force(int value);
  int getT2Force();
  void setT2Force(int value);
  int getT3Force();
  void setT3Force(int value);
  int getT4Force();
  void setT4Force(int value);
  int getT5Force();
  void setT5Force(int value);
  int getT6Force();
  void setT6Force(int value);
  int getT7Force();
  void setT7Force(int value);
  int getT8Force();
  void setT8Force(int value);
}
