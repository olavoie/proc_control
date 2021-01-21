package proc_control_matlab;

public interface ThrusterCurrents extends org.ros.internal.message.Message {
  static final java.lang.String _TYPE = "proc_control_matlab/ThrusterCurrents";
  static final java.lang.String _DEFINITION = "int32 T1_Current\nint32 T2_Current\nint32 T3_Current\nint32 T4_Current\nint32 T5_Current\nint32 T6_Current\nint32 T7_Current\nint32 T8_Current";
  static final boolean _IS_SERVICE = false;
  static final boolean _IS_ACTION = false;
  int getT1Current();
  void setT1Current(int value);
  int getT2Current();
  void setT2Current(int value);
  int getT3Current();
  void setT3Current(int value);
  int getT4Current();
  void setT4Current(int value);
  int getT5Current();
  void setT5Current(int value);
  int getT6Current();
  void setT6Current(int value);
  int getT7Current();
  void setT7Current(int value);
  int getT8Current();
  void setT8Current(int value);
}
