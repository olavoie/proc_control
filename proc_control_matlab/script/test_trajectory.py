#!/usr/bin/env python

import rospy

from geometry_msgs.msg import Point, Vector3
from std_msgs.msg import Bool
from proc_control_matlab.msg import AddPose
import time

class TrajectoryTest():
    def __init__(self):
        rospy.init_node('trajectory_test', anonymous=True)
        self.clear_trajectory_pub = rospy.Publisher("/proc_control_matlab/clear_waypoints", Bool, queue_size=10)
        self.compute_trajectory_pub = rospy.Publisher("/proc_control_matlab/compute_trajectory", Bool, queue_size=10)
        self.add_pose_pub = rospy.Publisher("/proc_control_matlab/add_pose", AddPose, queue_size=10)
        self.waypoints = [{'position': Point(0, 0, 1.5), 'orientation': Vector3(0, 0, 0), 'frame': 1, 'speed': 1, 'fine': 0},
                          {'position': Point(0.5, 0, 2), 'orientation': Vector3(0, 0, 0), 'frame': 1, 'speed': 1, 'fine': 0},
                          {'position': Point(8.072, 0, 2), 'orientation': Vector3(0, 0, 0), 'frame': 1, 'speed': 1, 'fine': 0},
                          {'position': Point(11.921, -1.364, 1.696), 'orientation': Vector3(0, 0, -39.23), 'frame': 1, 'speed': 1, 'fine': 0},
                          {'position': Point(13, -1.75, 1.5), 'orientation': Vector3(0, 0, 0), 'frame': 1, 'speed': 1, 'fine': 0},
                          {'position': Point(14.217, -1.237, 1.278), 'orientation': Vector3(0, 0, 45), 'frame': 1, 'speed': 1, 'fine': 0},
                          {'position': Point(14.721, 0, 1.186), 'orientation': Vector3(0, 0, 90), 'frame': 1, 'speed': 1, 'fine': 0},
                          {'position': Point(14.217, 1.237, 1.278), 'orientation': Vector3(0, 0, 135), 'frame': 1, 'speed': 1, 'fine': 0},
                          {'position': Point(13, 1.75, 1.5), 'orientation': Vector3(0, 0, 180), 'frame': 1, 'speed': 1, 'fine': 0},
                          {'position': Point(11.921, 1.364, 1.696), 'orientation': Vector3(0, 0, (180+39.23)), 'frame': 1, 'speed': 1, 'fine': 0},
                          {'position': Point(8.072, 0, 2), 'orientation': Vector3(0, 0, 180), 'frame': 1, 'speed': 1, 'fine': 0},
                          {'position': Point(0.5, 0, 2), 'orientation': Vector3(0, 0, 180), 'frame': 1, 'speed': 1, 'fine': 0},
                          {'position': Point(0, 0, 2), 'orientation': Vector3(0, 0, 180), 'frame': 1, 'speed': 1, 'fine': 0} ]
        time.sleep(1)
        

    def send(self, delay_value):
        for wpt in self.waypoints:
            print(wpt)
            #self.add_pose_pub.publish(wpt['position'], wpt['orientation'], wpt['frame'], wpt['speed'], wpt['fine'])
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
