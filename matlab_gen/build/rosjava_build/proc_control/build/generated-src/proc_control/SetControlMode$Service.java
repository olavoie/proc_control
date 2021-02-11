package proc_control;

public interface SetControlMode$Service extends org.ros.internal.message.Message {
  static final java.lang.String _TYPE = "proc_control/SetControlMode$Service";
  static final java.lang.String _DEFINITION = "int8 PositionModePID = 0\nint8 PositionModePPI = 1\nint8 VelocityModeB   = 2\n\nint8 mode\n---";
  static final boolean _IS_SERVICE = true;
  static final boolean _IS_ACTION = false;
}
