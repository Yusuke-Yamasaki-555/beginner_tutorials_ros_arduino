// 独自message_fileを作成して、RGBの値を別々に送る。
// default 
// message_name : ColorRGB
// message_data : Int32 red , Int32 green , Int32 blue

#include <ros/ros.h>
#include <std_msgs/Int32.h>
// #include "message/ColorRGB"

// SUBSCRIBER

// void colorCallback(){}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "color_sensor");

    ros NodeHandle n;

    ros::Subscriber sub_color = n.subscribe("color_msg", 10, colorCallback);

    ros::spin();

    return 0;
}