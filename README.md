# proc_control
Ros node to drive SONIA's control system

# Installation
ROS Toolbox interface for ROS Custom Messages

# Use the control
- Open Matlab;
- In a terminal, start a roscore;
- Run main.m Matlab script;

You can now send messages to the control using a rostopic command.

# Example 
### Set mode
`rosservice call /proc_control_matlab/set_mode "Mode: 2"`

### Add pose
`rostopic pub /proc_control_matlab/add_pose proc_control_matlab/AddPose "{X: 1.0, Y: 0.0, Z: 0.0, Roll: 0.0, Pitch: 0.0, Yaw: 0.0}"`

### Compute trajectory
`rostopic pub /proc_control_matlab/compute_trajectory proc_control_matlab/ComputeTrajectory '{compute: true}'`

### Clear waypoints
`rostopic pub /proc_control_matlab/clear_waypoints proc_control_matlab/ClearTrajectory '{clear: true}'`


You can also receive messages from the RosNode.

# Example
### Pose
`rostopic echo /proc_control_matlab/pose`

### Thrusters rpms
`rostopic echo /proc_control_matlab/thruster_rpms`

### Thrusters forces
`rostopic echo /proc_control_matlab/thruster_forces`

### Thrusters currents
`rostopic echo /proc_control_matlab/thruster_currents`

# How to generate custom messages
- Follow this procedure to generate a new .srv or .msg file for ROS: https://wiki.ros.org/ROS/Tutorials/CreatingMsgAndSrv
- Don't forget to compile after adding a new custom message.
- Follow this procedure to generate custom message for Matlab: https://www.mathworks.com/help/ros/ug/ros-custom-message-support.html
- Use `rosgenmsg` function: https://www.mathworks.com/help/ros/ref/rosgenmsg.html

# Problem with geometry_msg and IMU messages.
https://www.mathworks.com/matlabcentral/answers/553828-having-trouble-building-custom-ros-msgs-in-matlab-2020a

# Warning at compilation phase
set_param('TrajectoryGeneratorASYNC', 'ModelReferenceSymbolNameMessage', 'none')
