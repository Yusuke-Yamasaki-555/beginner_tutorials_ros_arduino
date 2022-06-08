#include "ros/ros.h"
#include "std_msgs/Int32.h"
#include <stdio.h>

std_msgs::Int32 msg;
std_msgs::Int32 hoge;

void servoCallback(const std_msgs::Int32 &msg)
{
    printf("Now servo: [%d]\n", msg.data);

    msg.data = rand() % 180 + 1;

    ROS_INFO("PubData [%d]", msg.data);

    servo_pub.publish(msg);

    loop_rate.sleep();
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "servo_node");
    ros::NodeHandle n;

    ros::Publisher servo_pub = n.advertise<std_msgs::Int32>("dir_ang", 10);
    ros::Subscriber servo_sub = n.subscribe("now_ang", 10, servoCallback);

    ros::Rate loop_rate(16000000);

    msg.data = 0;
    ROS_INFO("Set Servo\n");
    servo_pub.publish(msg);
    loop_rate.sleep();

    ros::spin();
    
    return 0;
}