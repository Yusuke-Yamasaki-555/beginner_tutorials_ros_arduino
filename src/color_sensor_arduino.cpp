/*License
    SPDX-License-Identifier:MIT
    Copyright (C) 2022 Yusuke Yamasaki. All Rights Reserved.
*/

#include "ros/ros.h"
#include "std_msgs/Int32.h"
#include "beginner_tutorials/Data4.h"

void colorCallback(const beginner_tutorials::Data4 &sub_color_msg)
{
    ROS_INFO("COLOR_DATA : R[ %u ], G[ %u ], B[ %u ], IR[ %u ]", sub_color_msg.data1, sub_color_msg.data2, sub_color_msg.data3, sub_color_msg.data4);
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "color_sensor");

    ros::NodeHandle n;

    ros::Subscriber sub_color = n.subscribe("color_msg", 10, colorCallback);

    ros::spin();

    return 0;
}
