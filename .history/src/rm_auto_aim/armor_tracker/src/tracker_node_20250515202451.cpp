#include "armor_tracker/tracker_node.hpp"

// STD
#include <auto_aim_interfaces/msg/detail/all_latency__struct.hpp>
#include <cmath>
#include <iostream>
#include <memory>
#include <vector>

namespace rm_auto_aim
{
ArmorTrackerNode::ArmorTrackerNode(const rclcpp::NodeOptions & options)
: Node("armor_tracker", options)
{
    RCLCPP_INFO(this->get_logger(), "Starting TrackerNode!");

    //! 参数部分
    // Maximum allowable armor distance in the XOY plane
    max_armor_distance_ = this->declare_parameter("max_armor_distance", 10.0);

    // Tracker 参数
    double max_match_distance = this->declare_parameter("tracker.max_match_distance", 0.15);
    double max_match_yaw_diff = this->declare_parameter("tracker.max_match_yaw_diff", 1.0);
    tracker_ = std::make_unique<Tracker>(max_match_distance, max_match_yaw_diff);
    tracker_->tracking_thres = this->declare_parameter("tracker.tracking_thres", 5);
    lost_time_thres_ = this->declare_parameter("tracker.lost_time_thres", 0.3);

    // update_Q - process noise covariance matrix
    s2qxyz_max_ = declare_parameter("ekf.sigma2_q_xyz_max", 0.1);
    s2qxyz_min_ = declare_parameter("ekf.sigma2_q_xyz_min", 0.05);
    s2qyaw_max_ = declare_parameter("ekf.sigma2_q_yaw_max", 10.0);
    s2qyaw_min_ = declare_parameter("ekf.sigma2_q_yaw_min", 0.01);
    s2qr_ = declare_parameter("ekf.sigma2_q_r", 80.0);

    //! EKF






}

//! armorsCallback

//! Makers

}  // namespace rm_auto_aim

#include "rclcpp_components/register_node_macro.hpp"

// Register the component with class_loader.
// This acts as a sort of entry point, allowing the component to be discoverable when its library
// is being loaded into a running process.
RCLCPP_COMPONENTS_REGISTER_NODE(rm_auto_aim::ArmorTrackerNode)