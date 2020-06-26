package proc_control;

public interface TargetReached extends org.ros.internal.message.Message {
  static final java.lang.String _TYPE = "proc_control/TargetReached";
  static final java.lang.String _DEFINITION = "uint8 target_is_reached\n";
  static final boolean _IS_SERVICE = false;
  static final boolean _IS_ACTION = false;
  byte getTargetIsReached();
  void setTargetIsReached(byte value);
}
