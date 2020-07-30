#include "ros/ros.h"
#include "ball_chaser/DriveToTarget.h"
#include <sensor_msgs/Image.h>

class ProcessAndDrive
{
private:
    enum direction
    {
        forward,
        right,
        left,
        backward,
        stop
    };

    ros::ServiceClient client__;
    ros::NodeHandle n__;
    ros::Subscriber sub__;

public:
    ProcessAndDrive()
    {
        // wait for service to be advertized
        ros::service::waitForService("/ball_chaser/command_bot");
        // initialize service client
        client__ = n__.serviceClient<ball_chaser::DriveToTarget>("/ball_chaser/command_bot");
        // initialize subscriber
        sub__ = n__.subscribe("/camera/rgb/image_raw", 2, &ProcessAndDrive::process_image_callback, this);
    }

    // process image for ball position
    void process_image_callback(const sensor_msgs::Image img)
    {
        direction dir;

        int WhitePixelsRight = 0;
        int WhitePixelsLeft = 0;
        int WhitePixelsForward = 0;

        int h = img.height;
        int w = img.width;
        int sec = img.step / 3;
        int threshold = (sec * h) / 4;
        int white_pixel = 255;

        // check image for white pixels and send service calls accordingly
        for (int i = 0; i < (h * img.step); i += 3)
        {
            // check if the pixel is white
            if (img.data[i] == white_pixel && img.data[i + 1] == white_pixel && img.data[i + 2] == white_pixel)
            {
                if ((i % img.step) < sec)
                {
                    WhitePixelsLeft++;
                }

                else if ((i % img.step) > 2 * sec)
                {
                    WhitePixelsRight++;
                }
                else
                {
                    WhitePixelsForward++;
                }
            }
        }

        // set direction of movement based on the ball position
        if (WhitePixelsRight > WhitePixelsForward)
        {
            dir = direction::right;
        }
        else if (WhitePixelsLeft > WhitePixelsForward)
        {
            dir = direction::left;
        }
        else if (WhitePixelsForward > WhitePixelsLeft && WhitePixelsForward > WhitePixelsRight)
        {
            dir = direction::forward;
        }
        else if (WhitePixelsForward > threshold || WhitePixelsLeft > threshold || WhitePixelsRight > threshold)
        {
            // set the direction backwards if the ball occupies the whole third of camera view
            dir = direction::stop;
        }
        else if (WhitePixelsForward == 0 && WhitePixelsLeft == 0 && WhitePixelsRight == 0)
        {
            dir = direction::stop;
        }
        else
        {
            dir = direction::stop;
        }

        // call service base on direction
        switch (dir)
        {
        case direction::right:
            drive_robot(0.1, -0.1);
            break;
        case direction::left:
            drive_robot(0.1, 0.1);
            break;
        case direction::forward:
            drive_robot(0.1, 0);
            break;
        case direction::backward:
            drive_robot(-0.1, 0);
            break;
        case direction::stop:
            drive_robot(0, 0);
        }
    }

    // drive robot by call drive_bot service
    void
    drive_robot(float lin_x, float ang_z)
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
            ROS_INFO("Failed to call service DriveToTarget, reinitializing...");
            // wait for service and reinitialize
            ros::service::waitForService("/ball_chaser/command_bot");
            client__ = n__.serviceClient<ball_chaser::DriveToTarget>("/ball_chaser/command_bot");
        }
    }
};

int main(int argc, char **argv)
{
    ros::init(argc, argv, "process_image");
    ProcessAndDrive pad;
    ros::spin();
    return 0;
}
