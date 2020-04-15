#!/bin/sh

terminator --new-tab -e " source devel/setup.bash; roslaunch turtlebot_gazebo turtlebot_world.launch " &
sleep 5
terminator --new-tab -e " source devel/setup.bash; roslaunch turtlebot_gazebo amcl_demo.launch " &
sleep 5
terminator --new-tab -e " source devel/setup.bash; roslaunch turtlebot_rviz_launchers view_navigation.launch " &
sleep 5
terminator --new-tab -e " source devel/setup.bash; roslaunch add_markers add_markers.launch " &
sleep 5
terminator --new-tab -e " source devel/setup.bash; roslaunch pick_objects pick_objects.launch "
