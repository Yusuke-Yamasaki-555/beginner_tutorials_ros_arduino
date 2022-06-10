/*License
    SPDX-License-Identifier:MIT
    Copyright (C) 2022 Yusuke Yamasaki. All Rights Reserved.
*/

#include "ros/ros.h"
#include "std_msgs/Int32.h"
//#include <stdio.h>

std_msgs::Int32 msg;  // 初期値のpublishに使用
std_msgs::Int32 hoge;  // hoge

// servoの動作制御。publishが来たら実行。subscribeした値をtriggerとし、サーボの角度をpublishする
void servoCallback(const std_msgs::Int32& msg)  // Topic : dir_ang(pub), now_ang(sub)
{    
    ros::NodeHandle n;

    ros::Publisher servo_pub = n.advertise<std_msgs::Int32>("dir_ang", 10);  // サーボの角度制御opic

    ros::Rate loop_rate(16000000);  // arduinoに合わせた周期(モータ制御のnodeに合わせた。値の根拠不明)
    
    printf("Now servo: [%d]\n", msg.data);  // subした値をターミナル出力

    hoge.data = rand() % 180 + 1;  // 1~180の間で乱数を生成

    ROS_INFO("PubData [%d]", hoge.data);  // 生成した乱数をターミナル出力

    servo_pub.publish(hoge);  // サーボの角度をpublish

    loop_rate.sleep();  // 周期合わせのsleep
}

//ros::Subscriber servo_sub = n.subscribe("now_ang", 10, servoCallback);  // サーボの角度確認topic

int main(int argc, char **argv)
{
    ros::init(argc, argv, "servo_node");

    ros::NodeHandle n;

    //ros::Rate loop_rate(16000000);  // arduinoに合わせた周期(モータ制御のnodeに合わせた。値の根拠不明)
    ros::Rate loop_rate(0.5); 

    ros::Publisher servo_pub = n.advertise<std_msgs::Int32>("dir_ang", 10);  // サーボの角度制御opic
    ros::Subscriber servo_sub = n.subscribe("now_ang", 10, servoCallback);  // サーボの角度確認topic

    // サーボからの確認topicをtriggerとして制御が行われるため、サーボ側が出力する角度の初期値を与える
    hoge.data = 180;  // 初期値の設定
    ROS_INFO("Set Servo\n");
    servo_pub.publish(hoge);  // 制御の初期値をpub
    //loop_rate.sleep();  // 周期合わせ

    //ROS_INFO("Waiting...");

    while(ros::ok()){
        hoge.data = rand() % 180 + 1;  // 1~180の間で乱数を生成

        ROS_INFO("PubData [%d]", hoge.data);  // 生成した乱数をターミナル出力

        servo_pub.publish(hoge);  // サーボの角度をpublish

        loop_rate.sleep();  // 周期合わせのsleep
        //ros::spinOnce();  // 以後、サーボからの確認topic待ち
        //loop_rate.sleep();
    }

    return 0;
}