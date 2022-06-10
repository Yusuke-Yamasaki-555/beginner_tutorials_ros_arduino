/*License
    SPDX-License-Identifier:MIT
    Copyright (C) 2022 Yusuke Yamasaki. All Rights Reserved.
*/

// エンコーダについては、まだよくわかっていないところがある。要学習

#include "ros/ros.h"
#include "std_msgs/Int32.h"

// SUBSCRIBER
// void encoderCallback(const std_msgs::Int32& sub_encoder_msg){}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "encoder");

    ros NodeHandle n;

    ros::Subscriber sub_color = n.subscribe("encoder_msg", 10, encoderCallback);

    ros::spin();

    return 0;
}