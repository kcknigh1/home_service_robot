#!/bin/sh

terminator --new-tab -e " source devel/setup.bash; roslaunch my_robot world.launch " &
sleep 5
terminator --new-tab -e " source devel/setup.bash; roslaunch my_robot mapping.launch " &
sleep 5
terminator --new-tab -e " source devel/setup.bash; rosrun teleop_twist_keyboard teleop_twist_keyboard.py " &
