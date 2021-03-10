#!/usr/bin/env python

import rospy

from proc_control_matlab.msg import AddPose, ClearWaypoints, ComputeTrajectory
import time

class TrajectoryTest():
    def __init__(self):
        rospy.init_node('trajectory_test', anonymous=True)
        self.clear_trajectory_pub = rospy.Publisher("/proc_control_matlab/clear_waypoints", ClearWaypoints, queue_size=10)
        self.compute_trajectory_pub = rospy.Publisher("/proc_control_matlab/compute_trajectory", ComputeTrajectory, queue_size=10)
        self.add_pose_pub = rospy.Publisher("/proc_control_matlab/add_pose", AddPose, queue_size=10)
        self.waypoints = [  [14, 0, 2, 180, 90, 0]]
                            
        time.sleep(1)
        

    def send(self, delay_value):
        for wpt in self.waypoints:
            print(wpt)
            self.add_pose_pub.publish(wpt[0], wpt[1], wpt[2], wpt[3], wpt[4], wpt[5])
            self.compute_trajectory_pub.publish(True)
            time.sleep(delay_value)
        print("Waypoints published")

        print("Compute trajectory")
        #self.compute_trajectory_pub.publish(True)
        #time.sleep(delay_value)
        
        #print("Clear waypoints")
        #self.clear_trajectory_pub.publish(True)

if __name__ == '__main__':
    traj = TrajectoryTest()
    traj.send(5)
