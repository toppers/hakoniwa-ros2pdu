#!/bin/bash

source /opt/ros/foxy/setup.bash

colcon build --packages-select can_msgs
colcon build --packages-select can_proxy
