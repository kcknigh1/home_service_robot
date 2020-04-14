#!/bin/sh

terminator --new-tab -e " source devel/setup.bash; roslaunch turtlebot_gazebo turtlebot_world.launch " &
sleep 5
terminator --new-tab -e " source devel/setup.bash; roslaunch turtlebot_gazebo amcl_demo.launch " &
sleep 5
terminator --new-tab -e " source devel/setup.bash; roslaunch turtlebot_rviz_launchers view_navigation.launch " &
