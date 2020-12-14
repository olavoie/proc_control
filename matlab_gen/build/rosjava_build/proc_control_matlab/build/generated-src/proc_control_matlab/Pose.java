package proc_control_matlab;

public interface Pose extends org.ros.internal.message.Message {
  static final java.lang.String _TYPE = "proc_control_matlab/Pose";
  static final java.lang.String _DEFINITION = "float64 X\nfloat64 Y\nfloat64 Z\nfloat64 Roll\nfloat64 Pitch\nfloat64 Yaw";
  static final boolean _IS_SERVICE = false;
  static final boolean _IS_ACTION = false;
  double getX();
  void setX(double value);
  double getY();
  void setY(double value);
  double getZ();
  void setZ(double value);
  double getRoll();
  void setRoll(double value);
  double getPitch();
  void setPitch(double value);
  double getYaw();
  void setYaw(double value);
}
