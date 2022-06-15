/*License
    SPDX-License-Identifier:MIT
    Copyright (C) 2022 Yusuke Yamasaki. All Rights Reserved.
*/

// 独自message_fileを作成して、RGBの値を別々に送る。
// default 
// message_name : ColorRGB
// message_data : Int32 red , Int32 green , Int32 blue

#include "ros/ros.h"
#include "std_msgs/Int32.h"
// #include "message/ColorRGB" こういう書き方で良いかは知らん

// SUBSCRIBER
// void colorCallback(const <ココに型定義>& sub_color_msg){}
/*
int main(int argc, char **argv)
{
    ros::init(argc, argv, "color_sensor");

    ros NodeHandle n;

    ros::Subscriber sub_color = n.subscribe("color_msg", 10, colorCallback);

    ros::spin();

    return 0;
}
*/