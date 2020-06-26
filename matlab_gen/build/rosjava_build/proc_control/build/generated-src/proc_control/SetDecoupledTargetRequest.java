package proc_control;

public interface SetDecoupledTargetRequest extends org.ros.internal.message.Message {
  static final java.lang.String _TYPE = "proc_control/SetDecoupledTargetRequest";
  static final java.lang.String _DEFINITION = "float64 X\nfloat64 Y\nfloat64 Z\nfloat64 ROLL\nfloat64 PITCH\nfloat64 YAW\n\nbool keepX\nbool keepY\nbool keepZ\nbool keepROLL\nbool keepPITCH\nbool keepYAW\n\n";
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
  boolean getKeepX();
  void setKeepX(boolean value);
  boolean getKeepY();
  void setKeepY(boolean value);
  boolean getKeepZ();
  void setKeepZ(boolean value);
  boolean getKeepROLL();
  void setKeepROLL(boolean value);
  boolean getKeepPITCH();
  void setKeepPITCH(boolean value);
  boolean getKeepYAW();
  void setKeepYAW(boolean value);
}
