// ROS
#include <message_filters/subscriber.h>
#include <tf2_ros/buffer.h>
#include <tf2_ros/create_timer_ros.h>
#include <tf2_ros/message_filter.h>
#include <tf2_ros/transform_listener.h>

#include <rclcpp/rclcpp.hpp>
#include <std_srvs/srv/trigger.hpp>
#include <tf2_geometry_msgs/tf2_geometry_msgs.hpp>
#include <visualization_msgs/msg/marker_array.hpp>

// STD
#include <memory>
#include <string>
#include <vector>

#include "buff_solve/solve.hpp"
// #include "buff_interfaces/"


namespace rm_buff
{
class BuffSolveNode : public rclcpp::Node
{
public:
    explicit BuffSolveNode(const rclcpp::NodeOptions & options);

private:

    // solve
    std::unique_ptr<Solve> solve_;

    // solve parameter
    float k;
    int bias_time;
    float s_bias;
    float z_bias;

};
}   // namespace rm_buff