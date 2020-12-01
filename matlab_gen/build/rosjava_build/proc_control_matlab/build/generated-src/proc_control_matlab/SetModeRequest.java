package proc_control_matlab;

public interface SetModeRequest extends org.ros.internal.message.Message {
  static final java.lang.String _TYPE = "proc_control_matlab/SetModeRequest";
  static final java.lang.String _DEFINITION = "int64 Mode\n";
  static final boolean _IS_SERVICE = true;
  static final boolean _IS_ACTION = false;
  long getMode();
  void setMode(long value);
}
