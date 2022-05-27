#include <ros/ros.h>
#include <std_msgs/Int32.h>

std_msgs::Int32 led_msg;

int main(int argc, char **argv)
{
    ros::init(argc, argv, "talker_arduino");
    ros::NodeHandle nh;
    ros::Publisher pub_led = nh.advertise<std_msgs::Int32>("led", 10);
    ros::Rate loop_rate(0.1);

    led_msg.data = 1;

    while(ros::ok())
    {
        ROS_INFO("I heard: [%d]", led_msg.data);
        pub_led.publish(led_msg);
        ros::spinOnce();
        loop_rate.sleep();
    }
    return 0;
}