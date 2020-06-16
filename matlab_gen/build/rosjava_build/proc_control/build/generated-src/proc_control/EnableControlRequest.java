package proc_control;

public interface EnableControlRequest extends org.ros.internal.message.Message {
  static final java.lang.String _TYPE = "proc_control/EnableControlRequest";
  static final java.lang.String _DEFINITION = "int8 DONT_CARE = -1\nint8 ENABLE = 1\nint8 DISABLE = 0\n\nint8 X\nint8 Y\nint8 Z\nint8 ROLL\nint8 PITCH\nint8 YAW\n";
  static final boolean _IS_SERVICE = true;
  static final boolean _IS_ACTION = false;
  static final byte DONT_CARE = -1;
  static final byte ENABLE = 1;
  static final byte DISABLE = 0;
  byte getX();
  void setX(byte value);
  byte getY();
  void setY(byte value);
  byte getZ();
  void setZ(byte value);
  byte getROLL();
  void setROLL(byte value);
  byte getPITCH();
  void setPITCH(byte value);
  byte getYAW();
  void setYAW(byte value);
}
