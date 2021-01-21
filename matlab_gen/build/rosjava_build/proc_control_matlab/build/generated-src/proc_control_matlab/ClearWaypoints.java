package proc_control_matlab;

public interface ClearWaypoints extends org.ros.internal.message.Message {
  static final java.lang.String _TYPE = "proc_control_matlab/ClearWaypoints";
  static final java.lang.String _DEFINITION = "bool clear";
  static final boolean _IS_SERVICE = false;
  static final boolean _IS_ACTION = false;
  boolean getClear();
  void setClear(boolean value);
}
