/*License
    SPDX-License-Identifier:MIT
    Copyright (C) 2022 Yusuke Yamasaki. All Rights Reserved.
*/

#include "ros/ros.h"
#include "std_msgs/Int32.h"
#include "beginner_tutorials/Data4.h"

void encoderCallback(const beginner_tutorials::Data4 &sub_encoder_msg)
{
    ROS_INFO("ENCODER_DATA : L[ %d ], R[ %d ]", sub_encoder_msg.data1, sub_encoder_msg.data2);
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "encoder");

    ros::NodeHandle n;

    ros::Subscriber sub_encoder = n.subscribe("encoder_msg", 10, encoderCallback);

    ros::spin();

    return 0;
}
