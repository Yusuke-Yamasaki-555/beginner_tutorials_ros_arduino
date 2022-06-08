#include "ros/ros.h"
#include "std_msgs/Int32.h"
#include <stdio.h>

std_msgs::Int32 msg;
std_msgs::Int32 hoge;

void servoCallback(const std_msgs::Int32& msg)
{
    printf("Now servo: [%d]\n", msg.data);
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "servo_node");

    ros::NodeHandle n;

    ros::Publisher servo_pub = n.advertise<std_msgs::Int32>("dir_ang", 1000);

    ros::Rate loop_rate(100);

    ros::Subscriber servo_sub = n.subscribe("now_ang", 1000, servoCallback);

    while(ros::ok()){
        printf("hoge");
        ros::spinOnce();
        sleep(1000);
    }

    while(ros::ok()){

        msg.data = rand() % 180 + 1;

        ROS_INFO("PubData [%d]", msg.data);

        servo_pub.publish(msg);

        loop_rate.sleep();
    }


    return 0;
}