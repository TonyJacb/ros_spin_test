#!/usr/bin/env python3

#   A simple python ROS node with 2 subscribers
#   with rospy.spin() thread spinning model.
#   Author : Tony Jacob

import rospy
from std_msgs.msg import String, Int16
import time

class ThreadChecker:
    def __init__(self):
        rospy.init_node("python_threadchecker")
        rospy.Subscriber("/string",String, callback=self.StringCB)
        rospy.Subscriber("/int",Int16,callback=self.IntCB)
        rospy.loginfo("[Python] Node Started")

    def StringCB(self,msg):
        timer = 8
        rospy.loginfo(f"[Python] Received string, Sleeping for {timer} seconds")
        time.sleep(timer)
        rospy.loginfo("[Python] String thread opened from sleep")
    
    def IntCB(self,msg):
        timer = 10
        rospy.loginfo(f"[Python] Received Int, Sleeping for {timer} seconds")
        time.sleep(timer)
        rospy.loginfo("[Python] Int thread opened from sleep")

ThreadChecker()
rospy.spin()