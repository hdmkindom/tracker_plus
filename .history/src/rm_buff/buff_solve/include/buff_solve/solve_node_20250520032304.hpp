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

#include "armor_solve/solve.hpp"
#include "auto_aim_interfaces/msg/armors.hpp"
#include "auto_aim_interfaces/msg/target.hpp"
#include "auto_aim_interfaces/msg/send.hpp"
#include "auto_aim_interfaces/msg/velocity.hpp"
#include "auto_aim_interfaces/msg/tracker_info.hpp"
#include "auto_aim_interfaces/msg/receive.hpp"

#include "auto_aim_interfaces/msg/detector_latency.hpp"
#include "auto_aim_interfaces/msg/tracker_latency.hpp"

#include "std_msgs/msg/float64.hpp"
#include "auto_aim_interfaces/msg/test.hpp"

#include "auto_aim_interfaces/msg/solve_info.hpp"

namespace rm_buff
{
class BuffSolveNode : public rclcpp::Node
{
public:

    enum ARMOR_NUM
    {
        ARMOR_NUM_BALANCE = 2,
        ARMOR_NUM_OUTPOST = 3,
        ARMOR_NUM_NORMAL = 4
    };

    explicit BuffSolveNode(const rclcpp::NodeOptions & options);

    float tar_yaw;        //目标yaw
    
private:
    void velocityCallback(const auto_aim_interfaces::msg::Velocity::SharedPtr velocity_msg);
    void receiveCallback(const auto_aim_interfaces::msg::Receive::SharedPtr receive_msg);
    void targetCallback(const auto_aim_interfaces::msg::Target::SharedPtr target_msg);
    void publishMarker(const auto_aim_interfaces::msg::SolveInfo & solve_info_msg);
    void detectorLatencyCallback(const auto_aim_interfaces::msg::DetectorLatency::SharedPtr detector_latency);
    void trackerLatencyCallback(const auto_aim_interfaces::msg::TrackerLatency::SharedPtr tracker_latency);

    // solve
    std::unique_ptr<Solve> solve_;

    // solve parameter
    float k;
    int bias_time;
    float s_bias;
    float z_bias;
    float fire_k;   // 开火yaw范围

    float v_top;

    float det_latency;
    float tra_latency;

    // init velocity
    float current_v;

    // Publisher
    rclcpp::Publisher<auto_aim_interfaces::msg::Send>::SharedPtr send_pub_;
    rclcpp::Publisher<auto_aim_interfaces::msg::SolveInfo>::SharedPtr solve_info_;

    rclcpp::Publisher<visualization_msgs::msg::Marker>::SharedPtr aim_point_pub_;

    // Subscriber 
    rclcpp::Subscription<auto_aim_interfaces::msg::Target>::SharedPtr target_sub_;
    rclcpp::Subscription<auto_aim_interfaces::msg::Velocity>::SharedPtr velocity_sub_;
    rclcpp::Subscription<auto_aim_interfaces::msg::Receive>::SharedPtr receive_sub_;
    rclcpp::Subscription<auto_aim_interfaces::msg::DetectorLatency>::SharedPtr detector_latency_sub_;
    rclcpp::Subscription<auto_aim_interfaces::msg::TrackerLatency>::SharedPtr tracker_latency_sub_;

    // Visualization marker
    visualization_msgs::msg::Marker aim_point_marker_;


};
}   // namespace rm_buff