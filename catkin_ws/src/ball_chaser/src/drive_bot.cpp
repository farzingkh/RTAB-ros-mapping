#include "ball_chaser/DriveToTarget.h"
#include "geometry_msgs/Twist.h"
#include "ros/ros.h"

ros::Publisher motor_command_publisher;

bool handle_drive(ball_chaser::DriveToTarget::Request &req, ball_chaser::DriveToTarget::Response &res)
{

    ROS_INFO("Drive command request received - linear_X:%1.2f, angular_Z:%1.2f", (float)req.linear_x, (float)req.angular_z);

    // create Twist velocity command
    geometry_msgs::Twist cmd;
    // copy req data
    cmd.linear.x = req.linear_x;
    cmd.angular.z = req.angular_z;
    // publish the command
    motor_command_publisher.publish(cmd);

    res.msg_feedback = "Linear X is set to: " + std::to_string(cmd.linear.x) + ", Angular Z is set to: " + std::to_string(cmd.angular.z);
    ROS_INFO_STREAM(res.msg_feedback);

    return true;
}

int main(int argc, char **argv)
{
    //initialize a ROS node
    ros::init(argc, argv, "drive_bot");

    // create a ros nodehandle object
    ros::NodeHandle n;

    // inform ROS of what commands will be published by publisher
    motor_command_publisher = n.advertise<geometry_msgs::Twist>("/cmd_vel", 1);
    // create a service called command_bot service with handle_drive call back
    ros::ServiceServer service = n.advertiseService("/ball_chaser/command_bot", handle_drive);

    ROS_INFO("Ready to send velocity commands");

    // handle ROS communication events
    ros::spin();

    return 0;
}