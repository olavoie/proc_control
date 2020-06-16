package proc_control;

public interface ThrustLogging extends org.ros.internal.message.Message {
  static final java.lang.String _TYPE = "proc_control/ThrustLogging";
  static final java.lang.String _DEFINITION = "float32[] thrust_axe\nfloat32[] thrust_thruster";
  static final boolean _IS_SERVICE = false;
  static final boolean _IS_ACTION = false;
  float[] getThrustAxe();
  void setThrustAxe(float[] value);
  float[] getThrustThruster();
  void setThrustThruster(float[] value);
}
