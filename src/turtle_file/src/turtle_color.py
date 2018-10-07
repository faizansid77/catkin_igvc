#!usr/bin/env python
import rospy
from turtlesim import *

def color():
    rospy.init_node('color',anonymous=True)
    rospy.Subscriber('/turtle1/color_sensor',)