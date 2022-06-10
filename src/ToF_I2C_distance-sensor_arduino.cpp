/*License
    SPDX-License-Identifier:MIT
    Copyright (C) 2022 Yusuke Yamasaki. All Rights Reserved.
*/

#include "ros/ros.h"
#include "std_msgs/Int32.h"

void chatterCallback(const std_msgs::Int32 &distance_1_msg)
{
  ROS_INFO("Distance: %d mm", distance_1_msg.data);
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "listener_distance_1");

  ros::NodeHandle n;

  ros::Subscriber sub = n.subscribe("distance_1", 45, chatterCallback);

  ros::spin();

  return 0;
}
