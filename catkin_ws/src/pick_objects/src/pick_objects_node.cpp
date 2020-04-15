#include <ros/ros.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>
#include <std_msgs/String.h>
// #include <rospy

// Define a client for to send goal requests to the move_base server through a SimpleActionClient
typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;

int main(int argc, char** argv){
  // Initialize the simple_navigation_goals node
//   ros::init(argc, argv, "simple_navigation_goals"); 
  ros::init(argc, argv, "pick_objects");

  ros::NodeHandle n;

  ros::Publisher current_job = n.advertise<std_msgs::String>("/pick_objects/current_job", 10);
  //tell the action client that we want to spin a thread by default
  MoveBaseClient ac("move_base", true);

  // Wait 5 sec for move_base action server to come up
  while(!ac.waitForServer(ros::Duration(5.0))){
    ROS_INFO("Waiting for the move_base action server to come up");
  }

  move_base_msgs::MoveBaseGoal goal;

  // set up the frame parameters
//   goal.target_pose.header.frame_id = "base_link";
  goal.target_pose.header.frame_id = "map";
  goal.target_pose.header.stamp = ros::Time::now();

  // Define a position and orientation for the robot to reach
  goal.target_pose.pose.position.x = 1.0;
  goal.target_pose.pose.orientation.w = 1.0;

   // Send the goal position and orientation for the robot to reach
  ROS_INFO("Sending goal");
  ac.sendGoal(goal);

  // Wait an infinite time for the results
  ac.waitForResult();

  // Check if the robot reached its goal
  if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED){
    ROS_INFO("Hooray, the base to the pickup location");
    std_msgs::String job;
    job.data = "picking up";
    current_job.publish(job);
  }
  else
    ROS_INFO("The base failed to move to the pickup location");

  ROS_INFO("start sleep");
  ros::Duration(5.0).sleep();
  ROS_INFO("end sleep");


  // Define a position and orientation for the robot to reach
  goal.target_pose.pose.position.x = 3.0;
  goal.target_pose.pose.orientation.w = 2.0;

   // Send the goal position and orientation for the robot to reach
  ROS_INFO("Sending goal");
  ac.sendGoal(goal);

  // Wait an infinite time for the results
  ac.waitForResult();



  // Check if the robot reached its goal
  if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED){
    ROS_INFO("Hooray, the base to the dropoff location");
    std_msgs::String job;
    job.data = "dropping off";
    current_job.publish(job);
  }
  else
    ROS_INFO("The base failed to move to the dropoff location");
  
  return 0;
}