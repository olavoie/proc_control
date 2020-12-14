# proc_control
Ros node to drive SONIA's control system

# Use the control
- Open Matlab;
- In a terminal, start a roscore;
- Run main.m Matlab script;

You can now send messages to the control using a rostopic command.

# Example 
### Set mode
`rosservice call /proc_control_matlab/set_mode "Mode: 2"`

### Add pose
`rosservice call /proc_control_matlab/add_pose '{X: 0, Y: 0, Z: 0, Roll: 0, Pitch: 0, Yaw: 0, Frame: 0, ZoneData: 0}'`

### Compute trajectory
`rosservice call /proc_control_matlab/compute_trajectory`

### Clear waypoints
`rosservice call /proc_control_matlab/clear_waypoints`


You can also receive messages from the RosNode.

# Example
### Pose
`rostopic echo /proc_control_matlab/pose`

### Thrusters rpms

### Thrusters forces

### Thrusters currents


# How to generate custom messages
- Follow this procedure to generate a new .srv or .msg file for ROS: https://wiki.ros.org/ROS/Tutorials/CreatingMsgAndSrv
- Don't forget to compile after adding a new custom message.
- Follow this procedure to generate custom message for Matlab: https://www.mathworks.com/help/ros/ug/ros-custom-message-support.html
- Use `rosgenmsg` function: https://www.mathworks.com/help/ros/ref/rosgenmsg.html
