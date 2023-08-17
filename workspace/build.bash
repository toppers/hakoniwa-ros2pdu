#!/bin/bash

source /opt/ros/foxy/setup.bash

colcon build --packages-select can_msgs
#colcon build --packages-select can_proxy
colcon build --packages-select ev3_msgs
colcon build --packages-select hako_pdu_proxy
#colcon build --packages-select msg_conv_test
