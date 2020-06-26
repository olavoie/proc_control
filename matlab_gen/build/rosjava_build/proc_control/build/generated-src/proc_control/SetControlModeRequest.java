package proc_control;

public interface SetControlModeRequest extends org.ros.internal.message.Message {
  static final java.lang.String _TYPE = "proc_control/SetControlModeRequest";
  static final java.lang.String _DEFINITION = "int8 PositionModePID = 0\nint8 PositionModePPI = 1\nint8 VelocityModeB   = 2\n\nint8 mode\n";
  static final boolean _IS_SERVICE = true;
  static final boolean _IS_ACTION = false;
  static final byte PositionModePID = 0;
  static final byte PositionModePPI = 1;
  static final byte VelocityModeB = 2;
  byte getMode();
  void setMode(byte value);
}
