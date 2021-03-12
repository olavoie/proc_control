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
        self.waypoints = [{'position': [0, 0, 1.5], 'orientation': [0, 0, 0], 'frame': 1, 'speed': 1, 'fine': 0},
                          {'position': [0.5, 0, 2], 'orientation': [0, 0, 0], 'frame': 1, 'speed': 1, 'fine': 0},
                          {'position': [8.072, 0, 2], 'orientation': [0, 0, 0], 'frame': 1, 'speed': 1, 'fine': 0},
                          {'position': [11.921, -1.364, 1.696], 'orientation': [0, 0, -39.23], 'frame': 1, 'speed': 1, 'fine': 0},
                          {'position': [13, -1.75, 1.5], 'orientation': [0, 0, 0], 'frame': 1, 'speed': 1, 'fine': 0},
                          {'position': [14.217, -1.237, 1.278], 'orientation': [0, 0, 45], 'frame': 1, 'speed': 1, 'fine': 0},
                          {'position': [14.721, 0, 1.186], 'orientation': [0, 0, 90], 'frame': 1, 'speed': 1, 'fine': 0},
                          {'position': [14.217, 1.237, 1.278], 'orientation': [0, 0, 135], 'frame': 1, 'speed': 1, 'fine': 0},
                          {'position': [13, 1.75, 1.5], 'orientation': [0, 0, 180], 'frame': 1, 'speed': 1, 'fine': 0},
                          {'position': [11.921, 1.364, 1.696], 'orientation': [0, 0, (180+39.23)], 'frame': 1, 'speed': 1, 'fine': 0},
                          {'position': [8.072, 0, 2], 'orientation': [0, 0, 180], 'frame': 1, 'speed': 1, 'fine': 0},
                          {'position': [0.5, 0, 2], 'orientation': [0, 0, 180], 'frame': 1, 'speed': 1, 'fine': 0},
                          {'position': [0, 0, 2], 'orientation': [0, 0, 180], 'frame': 1, 'speed': 1, 'fine': 0} ]
        time.sleep(1)
        

    def send(self, delay_value):
        for wpt in self.waypoints:
            print(wpt)
            self.add_pose_pub.publish(wpt['position'], wpt['orientation'], wpt['frame'], wpt['speed'], wpt['fine'])
            time.sleep(delay_value)
        print("Waypoints published")

        print("Compute trajectory")
        self.compute_trajectory_pub.publish(True)
        time.sleep(delay_value)
        
        #print("Clear waypoints")
        #self.clear_trajectory_pub.publish(True)

if __name__ == '__main__':
    traj = TrajectoryTest()
    traj.send(0.2)
