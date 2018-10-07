#include "ros/ros.h"
#include "turtlesim/SetPen.h"
#include "turtlesim/TeleportAbsolute.h"
#include <cstdlib>
#include <cmath>


int main(int argc, char **argv)
{
  ros::init(argc, argv, "turtle_pen");
  ros::NodeHandle n;
  ros::ServiceClient client1 = n.serviceClient<turtlesim::SetPen>("/turtle1/set_pen");
  ros::ServiceClient client2 = n.serviceClient<turtlesim::TeleportAbsolute>("/turtle1/teleport_absolute");
  turtlesim::SetPen srvp;
  turtlesim::TeleportAbsolute srvt;
  for(float i=0.0;i<8.0;i=i+0.003){
    srvp.request.r = 255-i*255/8.0;
    srvp.request.g = 255-i*255/8.0;
    srvp.request.b = 255-i*255/8.0;
    srvp.request.width = 12;
    srvp.request.off = 0;
    srvt.request.x=5.54+i*cos((1700.0)*i*3.14159/180.0);
    srvt.request.y=5.54+i*sin((1700.0)*i*3.14159/180.0);
    if (client1.call(srvp) & client2.call(srvt))
    {
      ROS_INFO("Done");
    }
    else
    {
      ROS_ERROR("Failed");
      return 1;
    }
  }

  return 0;
}