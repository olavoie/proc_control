package proc_control_matlab;

public interface ComputeTrajectory extends org.ros.internal.message.Message {
  static final java.lang.String _TYPE = "proc_control_matlab/ComputeTrajectory";
  static final java.lang.String _DEFINITION = "bool compute";
  static final boolean _IS_SERVICE = false;
  static final boolean _IS_ACTION = false;
  boolean getCompute();
  void setCompute(boolean value);
}
