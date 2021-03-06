#include <ros/ros.h>
#include <visualization_msgs/Marker.h>
#include <nav_msgs/Odometry.h>
#include <std_msgs/String.h>

// class Item{
// public:
//     Item(){
visualization_msgs::Marker marker;
//   ros::NodeHandle n;
  ros::Publisher marker_pub;

//     }

// };

void check_position_callback(const nav_msgs::Odometry::ConstPtr& msg){
    ROS_INFO("checking Position");
    ROS_INFO("x: [%f]  y: [%f]", msg->pose.pose.position.x, msg->pose.pose.position.y);
    ros::Duration(.5).sleep();
}

void check_job_callback(const std_msgs::String::ConstPtr& msg){

    ROS_INFO("msg: [%s]" ,msg->data.c_str());
    if (msg->data == "dropping off"){
        ROS_INFO("made it to drop off point!!!");
        marker.pose.position.x = 3;
        marker.pose.position.y = -1;
        // marker.action = visualization_msgs::Marker::ADD;
        // marker_pub.publish(marker);
    uint32_t shape = visualization_msgs::Marker::CUBE;

//   while (ros::ok())
//   {
    visualization_msgs::Marker marker;
    // Set the frame ID and timestamp.  See the TF tutorials for information on these.
    marker.header.frame_id = "/map";
    marker.header.stamp = ros::Time::now();

    // Set the namespace and id for this marker.  This serves to create a unique ID
    // Any marker sent with the same namespace and id will overwrite the old one
    marker.ns = "add_marker";
    marker.id = 0;

    // Set the marker type.  Initially this is CUBE, and cycles between that and SPHERE, ARROW, and CYLINDER
    marker.type = shape;

    // Set the marker action.  Options are ADD, DELETE, and new in ROS Indigo: 3 (DELETEALL)
    marker.action = visualization_msgs::Marker::ADD;

    // Set the pose of the marker.  This is a full 6DOF pose relative to the frame/time specified in the header
        marker.pose.position.x = 3;
        marker.pose.position.y = 0;
    marker.pose.position.z = 0;
    marker.pose.orientation.x = 0.0;
    marker.pose.orientation.y = 0.0;
    marker.pose.orientation.z = 0.0;
    marker.pose.orientation.w = 1.0;

    // Set the scale of the marker -- 1x1x1 here means 1m on a side
    marker.scale.x = 0.25;
    marker.scale.y = 0.25;
    marker.scale.z = 0.25;

    // Set the color -- be sure to set alpha to something non-zero!
    marker.color.r = 0.0f;
    marker.color.g = 1.0f;
    marker.color.b = 0.0f;
    marker.color.a = 1.0;

    marker.lifetime = ros::Duration();

    // Publish the marker
    while (marker_pub.getNumSubscribers() < 1)
    {
      if (!ros::ok())
      {
        // return 0;
      }
      ROS_WARN_ONCE("Please create a subscriber to the marker");
      sleep(1);
    }
    ROS_INFO("Publishing");
    marker_pub.publish(marker);
    }
    else if (msg->data == "picking up")
    {
        ROS_INFO("made it to pickup point");
            // ros::Duration(5).sleep();
    marker.action = visualization_msgs::Marker::DELETEALL;
    marker_pub.publish(marker);

    // ros::Duration(5).sleep();
    }
    
        // ROS_INFO("dose not match");
}

int main( int argc, char** argv )
{
  ros::init(argc, argv, "add_markers");
//   Item my_item;
  ros::NodeHandle n;
  ros::Rate r(1);
  marker_pub = n.advertise<visualization_msgs::Marker>("visualization_marker", 1);

    // ros::Subscriber sub1 = n.subscribe("/odom", 10, check_position_callback);
    ros::Subscriber sub2 = n.subscribe("/pick_objects/current_job", 10, check_job_callback);
  // Set our initial shape type to be a cube
  uint32_t shape = visualization_msgs::Marker::CUBE;

//   while (ros::ok())
//   {
    visualization_msgs::Marker marker;
    // Set the frame ID and timestamp.  See the TF tutorials for information on these.
    marker.header.frame_id = "/map";
    marker.header.stamp = ros::Time::now();

    // Set the namespace and id for this marker.  This serves to create a unique ID
    // Any marker sent with the same namespace and id will overwrite the old one
    marker.ns = "add_marker";
    marker.id = 0;

    // Set the marker type.  Initially this is CUBE, and cycles between that and SPHERE, ARROW, and CYLINDER
    marker.type = shape;

    // Set the marker action.  Options are ADD, DELETE, and new in ROS Indigo: 3 (DELETEALL)
    marker.action = visualization_msgs::Marker::ADD;

    // Set the pose of the marker.  This is a full 6DOF pose relative to the frame/time specified in the header
    marker.pose.position.x = 1;
    marker.pose.position.y = 0;
    marker.pose.position.z = 0;
    marker.pose.orientation.x = 0.0;
    marker.pose.orientation.y = 0.0;
    marker.pose.orientation.z = 0.0;
    marker.pose.orientation.w = 1.0;

    // Set the scale of the marker -- 1x1x1 here means 1m on a side
    marker.scale.x = 0.25;
    marker.scale.y = 0.25;
    marker.scale.z = 0.25;

    // Set the color -- be sure to set alpha to something non-zero!
    marker.color.r = 0.0f;
    marker.color.g = 1.0f;
    marker.color.b = 0.0f;
    marker.color.a = 1.0;

    marker.lifetime = ros::Duration();

    // Publish the marker
    while (marker_pub.getNumSubscribers() < 1)
    {
      if (!ros::ok())
      {
        return 0;
      }
      ROS_WARN_ONCE("Please create a subscriber to the marker");
      sleep(1);
    }
    ROS_INFO("Publishing");
    marker_pub.publish(marker);

    // Cycle between different shapes
    // switch (shape)
    // {
    // case visualization_msgs::Marker::CUBE:
    //   shape = visualization_msgs::Marker::SPHERE;
    //   break;
    // case visualization_msgs::Marker::SPHERE:
    //   shape = visualization_msgs::Marker::ARROW;
    //   break;
    // case visualization_msgs::Marker::ARROW:
    //   shape = visualization_msgs::Marker::CYLINDER;
    //   break;
    // case visualization_msgs::Marker::CYLINDER:
    //   shape = visualization_msgs::Marker::CUBE;
    //   break;
    // }

    r.sleep();

    // ros::Duration(5).sleep();
    // marker.action = visualization_msgs::Marker::DELETEALL;
    // marker_pub.publish(marker);

    // ros::Duration(5).sleep();
    // marker.pose.position.x = 3;
    // marker.pose.position.y = -.2;
    // marker.action = visualization_msgs::Marker::ADD;
    // marker_pub.publish(marker);

    ros::spin();
//   }
}