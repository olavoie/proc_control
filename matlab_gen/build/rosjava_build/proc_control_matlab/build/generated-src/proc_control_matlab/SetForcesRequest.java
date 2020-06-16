package proc_control_matlab;

public interface SetForcesRequest extends org.ros.internal.message.Message {
  static final java.lang.String _TYPE = "proc_control_matlab/SetForcesRequest";
  static final java.lang.String _DEFINITION = "float64 x\nfloat64 y\nfloat64 z\nfloat64 roll\nfloat64 pitch\nfloat64 yaw\n";
  static final boolean _IS_SERVICE = true;
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
