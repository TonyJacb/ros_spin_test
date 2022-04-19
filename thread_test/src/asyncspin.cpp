/*A simple C++ ROS Node with 2 subscriber
callbacks with a ros::AsyncSpinner() thread spinning model

Author: Tony Jacob*/

#include "ros/ros.h"
#include "ros/console.h"
#include "std_msgs/String.h"
#include "std_msgs/Int16.h"
#include <time.h>

class ThreadChecker {
    private:
        ros::Subscriber stringsub;
        ros::Subscriber intsub;
    
    public:
        ThreadChecker(ros::NodeHandle *nh){
            ROS_INFO("[Async] Node Started");
            stringsub = nh->subscribe("/string",10, &ThreadChecker::callback_string, this );
            intsub = nh->subscribe("/int",10,&ThreadChecker::callback_int, this);
        }

        void callback_string(const std_msgs::String &msg){
            int timer = 8;
            ROS_INFO("[Async] Received string, Sleeping for %d seconds", timer);
            sleep(timer);
            ROS_INFO("[Async] String thread opened from sleep");
        }

        void callback_int(const std_msgs::Int16 &msg){
            int timer = 10;
            ROS_INFO("[Async] Received Int, Sleeping for %d seconds", timer);
            sleep(timer);
            ROS_INFO("[Async] Int thread opened from sleep");
        }

};

int main(int argc, char **argv)
{
    ros::init(argc, argv, "async_threadchecker");
    ros::NodeHandle nh;
    ThreadChecker tc = ThreadChecker(&nh);
    ros::AsyncSpinner spinner(2);
    spinner.start();
    ros::waitForShutdown();
}