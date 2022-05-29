#include <ros/ros.h>
#include <std_msgs/Int32.h>

std_msgs::Int32 led_msg;
std_msgs::Int32 pub_msg;

int main(int argc, char **argv)
{
    ros::init(argc, argv, "talker_arduino");
    ros::NodeHandle nh;
    ros::Publisher pub_led = nh.advertise<std_msgs::Int32>("led", 10);
    ros::Rate loop_rate(16000000); // 単位：Hz_ここの値が、arduinoとの同期周期の定義になる。

    led_msg.data = 1;

    while(ros::ok())
    {
        ROS_INFO("I heard: [%d]", led_msg.data);
        pub_msg = led_msg;
        //pub_msg.data = pub_msg.data % 2;
        pub_led.publish(pub_msg);
        loop_rate.sleep(); // ここでsleepしているが、同期周期を刻んでいると判断するべき。
        //led_msg.data += 1;
    }
    return 0;
}