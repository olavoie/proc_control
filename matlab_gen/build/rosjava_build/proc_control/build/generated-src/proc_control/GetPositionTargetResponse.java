package proc_control;

public interface GetPositionTargetResponse extends org.ros.internal.message.Message {
  static final java.lang.String _TYPE = "proc_control/GetPositionTargetResponse";
  static final java.lang.String _DEFINITION = "\nfloat64 X\nfloat64 Y\nfloat64 Z\nfloat64 ROLL\nfloat64 PITCH\nfloat64 YAW";
  static final boolean _IS_SERVICE = true;
  static final boolean _IS_ACTION = false;
  double getX();
  void setX(double value);
  double getY();
  void setY(double value);
  double getZ();
  void setZ(double value);
  double getROLL();
  void setROLL(double value);
  double getPITCH();
  void setPITCH(double value);
  double getYAW();
  void setYAW(double value);
}
