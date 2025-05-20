// ROS
#include <message_filters/subscriber.h>
#include <tf2_ros/buffer.h>
#include <tf2_ros/create_timer_ros.h>
#include <tf2_ros/message_filter.h>
#include <tf2_ros/transform_listener.h>

#include <buff_interfaces/msg/detail/blade_array__struct.hpp>
#include <buff_interfaces/msg/detail/buff_send__struct.hpp>
#include <buff_interfaces/msg/detail/velocity__struct.hpp>
#include <rclcpp/rclcpp.hpp>
#include <std_srvs/srv/trigger.hpp>
#include <tf2_geometry_msgs/tf2_geometry_msgs.hpp>
#include <visualization_msgs/msg/marker_array.hpp>

// STD
#include <memory>
#include <string>
#include <vector>

#include "buff_solve/solve.hpp"
#include "buff_interfaces/msg/blade_array.hpp"
#include "buff_interfaces/msg/buff_send.hpp"


namespace rm_buff
{
class BuffSolveNode : public rclcpp::Node
{
public:
    explicit BuffSolveNode(const rclcpp::NodeOptions & options);

private:
    void velocityCallback(const buff_interfaces::msg::Velocity::SharedPtr velocity_msg);
    void bladeCallback(const buff_interfaces::msg::BladeArray::SharedPtr blade_array_msg);

    // solve
    std::unique_ptr<Solve> solve_;

    // solve parameter
    float k;
    int bias_time;
    float s_bias;
    float z_bias;

    // init velocity
    float current_v;

    // Publisher
    rclcpp::Publisher<buff_interfaces::msg::BuffSend>::SharedPtr buff_send_pub_;
    
    // Subscriber
    rclcpp::Subscription<buff_interfaces::msg::BladeArray>::SharedPtr blade_array_sub_;
    rclcpp::Subscription<buff_interfaces::msg::Velocity>::SharedPtr buff_velocity_sub_;
};
}   // namespace rm_buff