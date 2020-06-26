package proc_control;

public interface EnableThrustersRequest extends org.ros.internal.message.Message {
  static final java.lang.String _TYPE = "proc_control/EnableThrustersRequest";
  static final java.lang.String _DEFINITION = "bool isEnable\n";
  static final boolean _IS_SERVICE = true;
  static final boolean _IS_ACTION = false;
  boolean getIsEnable();
  void setIsEnable(boolean value);
}
