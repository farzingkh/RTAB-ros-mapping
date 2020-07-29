#include "ros/ros.h"
#include "ball_chaser/DriveToTarget.h"
#include <sensor_msgs/Image.h>

class ProcessAndDrive
{
private:
    ros::ServiceClient client__;
    ros::NodeHandle n__;
    ros::Subscriber sub__;

public:
    ProcessAndDrive()
    {
        // initialize service client
        client__ = n__.serviceClient<ball_chaser::DriveToTarget>("/ball_chaser/command_robot");
        // initialize subscriber
        sub__ = n__.subscribe("/camera/rgd/image_raw", 10, &ProcessAndDrive::process_image_callback, this);
    }

    // process image for ball position
    void process_image_callback(const sensor_msgs::Image img)
    {
        int h = img.height;
        int w = img.width;
        auto data = img.data;

        int white_pixel = 255;
        // check image for white pixels and send service calls accordingly
        for (int i = 0; i < h * w; ++i)
        {

            if (data[i] == white_pixel)
            {
                if ((i % w) <= ((img.width) / 3))
                {
                    ROS_INFO("Ball detected at left, moving left!");
                    // move forward and rotate left
                    drive_robot(0.5, 0.5);
                }
                else if (((img.width) / 3) < (i % w) <= 2 * ((img.width) / 3))
                {
                    ROS_INFO("Ball detected in the middle, moving forward!");
                    // move forward
                    drive_robot(0.5, 0.0);
                }
                else if ((i % w) > 2 * ((img.width) / 3))
                {
                    ROS_INFO("Ball detected at right, moving right!");
                    // move forward and rotate right
                    drive_robot(0.5, -0.5);
                }
            }
            else
            {
                ROS_INFO("No ball detected! stopped!");
                // stop
                drive_robot(0.0, 0.0);
            }
        }
    }

    // drive robot by call drive_bot service
    void drive_robot(float lin_x, float ang_z)
    {
        // create a service of DriveToTarget
        ball_chaser::DriveToTarget srv;
        // input data to service request
        srv.request.linear_x = lin_x;
        srv.request.angular_z = ang_z;
        // check if client is ok
        if (client__.call(srv))
        {

            ROS_INFO_STREAM(srv.response.msg_feedback);
        }
        else
        {
            ROS_INFO("Failed to call service DriveToTarget");
        }
    }
};

int main(int argc, char **argv)
{
    ros::init(argc, argv, "proces_image");
    ProcessAndDrive pad;
    ros::spin();

    return 0;
}
