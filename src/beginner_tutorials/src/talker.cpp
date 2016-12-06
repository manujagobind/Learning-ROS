#include <ros/ros.h>
#include <std_msgs/String.h>
#include <sstream>

int main(int argc, char** argv){

  ros::init(argc, argv, "talker");
  ros::NodeHandle node;

  ros::Publisher chatter_pub = node.advertise<std_msgs::String>("chatter", 100);
  ros::Rate rate(10.0);

  int count=0;
  while(node.ok()){

    std_msgs::String msg;
    std::stringstream ss;

    ss << "hello world" << count;
    msg.data = ss.str();

    ROS_INFO("%s", msg.data.c_str());

    chatter_pub.publish(msg);
    ros::spinOnce();
    rate.sleep();
    ++count;
  }
  return 0;
}
