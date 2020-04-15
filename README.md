# Home Service Robot
This is a robot that can navigate around an unknown area. It collects an item from one location and drops it at another. 

## Packages
* turtlebot - used as the base robot for the project
* turtlebot_simulator - turtlebot_gazebo - used the 3 different launch files in here 
    amcl_demo to test the amcl functionality used for localization
    gmapping_demo to test gmapping used for mapping an unknown environment 
    turtlebot_world it the base that everything is focused on

* pick_objects - allows the robot the drive to a specific location
* add_markers - removes the markers when the robot reaches a specified location

## Scripts
* test_slam.sh - test the slam functionality of turtlebot
* test_slam_my_robot.sh - working on integrating my robot into this projects
* test_navigation.sh - tests the navigational functionality of the turtlebot
* add_markers.sh - adds the item to the map receives a signal when the robot arrives at the location then removes the item.  When the robot arrives at the drop off location the item appears there
* pick_objects - navigates that robot to the pickup location, waits 5 seconds then moves the robot the the drop off location. 
* home_service.sh - runs all the required nodes in order to navigate the robot to the pickup location retrieves the item then move to the drop off location.
