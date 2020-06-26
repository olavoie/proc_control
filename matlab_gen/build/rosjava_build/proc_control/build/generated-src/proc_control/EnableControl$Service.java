package proc_control;

public interface EnableControl$Service extends org.ros.internal.message.Message {
  static final java.lang.String _TYPE = "proc_control/EnableControl$Service";
  static final java.lang.String _DEFINITION = "int8 DONT_CARE = -1\nint8 ENABLE = 1\nint8 DISABLE = 0\n\nint8 X\nint8 Y\nint8 Z\nint8 ROLL\nint8 PITCH\nint8 YAW\n---";
  static final boolean _IS_SERVICE = true;
  static final boolean _IS_ACTION = false;
}
