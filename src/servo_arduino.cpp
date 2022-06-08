#include "ros/ros.h"
#include "std_msgs/Int32.h"
#include <stdio.h>

std_msgs::Int32 msg;  // 初期値のpublishに使用
std_msgs::Int32 hoge;  // hoge

// servoの動作制御。publishが来たら実行。subscribeした値をtriggerとし、サーボの角度をpublishする
void servoCallback(const std_msgs::Int32 &msg)  // Topic : dir_ang(pub), now_ang(sub)
{
    printf("Now servo: [%d]\n", msg.data);  // subした値をターミナル出力

    msg.data = rand() % 180 + 1;  // 1~180の間で乱数を生成

    ROS_INFO("PubData [%d]", msg.data);  // 生成した乱数をターミナル出力

    servo_pub.publish(msg);  // サーボの角度をpublish

    loop_rate.sleep();  // 周期合わせのsleep
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "servo_node");
    ros::NodeHandle n;

    ros::Publisher servo_pub = n.advertise<std_msgs::Int32>("dir_ang", 10);  // サーボの角度制御opic
    ros::Subscriber servo_sub = n.subscribe("now_ang", 10, servoCallback);  // サーボの角度確認topic

    ros::Rate loop_rate(16000000);  // arduinoに合わせた周期(モータ制御のnodeに合わせた。値の根拠不明)

    // サーボからの確認topicをtriggerとして制御が行われるため、サーボ側が出力する角度の初期値を与える
    msg.data = 0;  // 初期値の設定
    ROS_INFO("Set Servo\n");
    servo_pub.publish(msg);  // 制御の初期値をpub
    loop_rate.sleep();  // 周期合わせ

    ros::spin();  // 以後、サーボからの確認topic待ち
    
    return 0;
}