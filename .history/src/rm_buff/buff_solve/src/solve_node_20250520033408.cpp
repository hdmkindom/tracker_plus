#include "buff_solve/solve_node.hpp"

//STD

#include <algorithm>
#include <cmath>
#include <cstddef>
#include <functional>
#include <vector>
#include <iostream>

namespace rm_buff
{
BuffSolveNode::BuffSolveNode(const rclcpp::NodeOptions & options)
: Node("buff_solve", options)
{
    RCLCPP_INFO(this->get_logger(), "Starting BuffSolveNode!");

    // 用于弹道解算的k值具体计算在git
    k = this->declare_parameter("k", 0.038);
    bias_time = this->declare_parameter("bias_time", 100);
    s_bias = this->declare_parameter("s_bias", 0.18375);
    z_bias = this->declare_parameter("z_bias", 0.196);

    // 解算的智能指针
    solve_ = std::make_unique<Solve>(k, bias_time, s_bias, z_bias);

    // Publisher
    send_pub_ = this->create_publisher<auto_aim_interfaces::msg::Send>(
        "/solve/send", rclcpp::SensorDataQoS());

    solve_info_ = this->create_publisher<auto_aim_interfaces::msg::SolveInfo>(
        "/solve/info", rclcpp::SensorDataQoS());

    aim_point_pub_ = this->create_publisher<visualization_msgs::msg::Marker>(
        "/solve/marker", rclcpp::SensorDataQoS());

//     // Subscriber
//     receive_sub_ = this->create_subscription<auto_aim_interfaces::msg::Receive>(
//         "/receive", rclcpp::QoS(rclcpp::QoSInitialization::from_rmw(rmw_qos_profile_sensor_data)),
//         std::bind(&BuffSolveNode::receiveCallback, this, std::placeholders::_1));

//     velocity_sub_ = this->create_subscription<auto_aim_interfaces::msg::Velocity>(
//         "/current_velocity", rclcpp::QoS(rclcpp::QoSInitialization::from_rmw(rmw_qos_profile_sensor_data)),
//         std::bind(&BuffSolveNode::velocityCallback, this, std::placeholders::_1));
    
//     target_sub_ = this->create_subscription<auto_aim_interfaces::msg::Target>(
//         "/tracker/target", rclcpp::QoS(rclcpp::QoSInitialization::from_rmw(rmw_qos_profile_sensor_data)),
//         std::bind(&BuffSolveNode::targetCallback, this, std::placeholders::_1));

//     detector_latency_sub_ = this->create_subscription<auto_aim_interfaces::msg::DetectorLatency>(
//         "/detector/Latency", rclcpp::QoS(rclcpp::QoSInitialization::from_rmw(rmw_qos_profile_sensor_data)),
//         std::bind(&BuffSolveNode::detectorLatencyCallback, this, std::placeholders::_1));

//     tracker_latency_sub_ = this->create_subscription<auto_aim_interfaces::msg::TrackerLatency>(
//         "/tracker/latency", rclcpp::QoS(rclcpp::QoSInitialization::from_rmw(rmw_qos_profile_sensor_data)),
//         std::bind(&BuffSolveNode::trackerLatencyCallback, this, std::placeholders::_1));


//     // Visualization marker
//     // See http://wiki.ros.org/rviz/DisplayTypes/Marker
//     aim_point_marker_.ns = "aim_point";
//     aim_point_marker_.action = visualization_msgs::msg::Marker::ADD;
//     aim_point_marker_.type = visualization_msgs::msg::Marker::SPHERE;  // 球
//     aim_point_marker_.scale.x = 0.1;  // 球的直径
//     aim_point_marker_.scale.y = 0.1;
//     aim_point_marker_.scale.z = 0.1;
//     aim_point_marker_.color.a = 1.0;  // 不透明
//     aim_point_marker_.color.r = 1.0;  // 橙色的红色分量
//     aim_point_marker_.color.g = 0.5;  // 橙色的绿色分量
//     aim_point_marker_.color.b = 0.0;  // 橙色的蓝色分量
//     aim_point_marker_.lifetime = rclcpp::Duration::from_seconds(0.1);
// }

// void BuffSolveNode::velocityCallback(
//     const auto_aim_interfaces::msg::Velocity::SharedPtr velocity_msg)
// {
//     solve_->initVelocity(velocity_msg);
// }

// void BuffSolveNode::receiveCallback(
//     const auto_aim_interfaces::msg::Receive::SharedPtr receive_msg)
// {
//     solve_ -> initReceive(receive_msg);
// }

// void BuffSolveNode::detectorLatencyCallback(
//     const auto_aim_interfaces::msg::DetectorLatency::SharedPtr detector_latency)
// {
//     det_latency = detector_latency->detector_latency;
// }

// void BuffSolveNode::trackerLatencyCallback(
//     const auto_aim_interfaces::msg::TrackerLatency::SharedPtr tracker_latency)
// {
//     tra_latency = tracker_latency->tracker_latency;
// }

// void BuffSolveNode::targetCallback(
//     const auto_aim_interfaces::msg::Target::SharedPtr target_msg)
// {
//     auto solve_latency_start = this->get_clock()->now();

//     // Init message
//     tar_yaw = target_msg->yaw;
//     int idx = 0;
//     bool is_fire = false;

//     float aim_x = 0;
//     float aim_y = 0;
//     float aim_z = 0;

//     float d_yaw = 0;

//     rclcpp::Time time = target_msg->header.stamp;
//     auto_aim_interfaces::msg::Send send_msg;
//     auto_aim_interfaces::msg::SolveInfo solve_info_msg;

//     send_msg.header.stamp = time;
//     solve_info_msg.header = target_msg->header;

//     // 发弹时间线性预测
//     int delay_time = bias_time + det_latency + tra_latency;
//     // int delay_time = bias_time;

//     float time_delay = delay_time/1000.0 + solve_->ftime;  // 改为 测距 所用时间 

//     tar_yaw += target_msg->v_yaw * time_delay;

//     //计算四块装甲板的位置
//     //装甲板id顺序，以四块装甲板为例，逆时针编号
//     //      2
//     //   3     1
//     //      0
//     if (target_msg->buffs_num == ARMOR_NUM_OUTPOST) {
//         solve_ -> calculateArmorPosition(target_msg, false, true, tar_yaw);
//     }
//     // 对于普通装甲板 
//     else {
//         //* 解算装甲板位置 注意 use_1 以及 use_average_radius
//         solve_ -> calculateArmorPosition(target_msg, false, false, tar_yaw);
//     }
//         // 找到四块装甲板中最适合开火的那一块 idx ,并且如果都不适合就以最后一块也就是当前追踪的装甲板为准
//         idx = solve_ -> selectArmor(target_msg);

//     std::pair<float, float> pitch_and_yaw;

//     pitch_and_yaw = solve_ -> calculatePitchAndYaw(idx, target_msg, time_delay, s_bias, z_bias, current_v, false, aim_x, aim_y, aim_z);

//     // 使用 pitch_and_yaw 的值
//     float send_pitch = pitch_and_yaw.first;
//     float send_yaw = pitch_and_yaw.second;

//     // 开火控制
//     is_fire = solve_->shouldFire(send_msg.yaw, solve_->receive_yaw, fire_k, d_yaw);

//     // 发布传参
//     send_msg.pitch = send_pitch;
//     send_msg.yaw = send_yaw;
//     send_msg.is_fire = is_fire;

//     solve_info_msg.tar_yaw = tar_yaw;
//     solve_info_msg.idx = idx;
//     solve_info_msg.aim_position.x = aim_x;
//     solve_info_msg.aim_position.y = aim_y;
//     solve_info_msg.aim_position.z = aim_z;
//     solve_info_msg.d_yaw = d_yaw;

//     // publish
//     send_pub_->publish(send_msg);
//     solve_info_->publish(solve_info_msg);

//     publishMarker(solve_info_msg);
// }

// void BuffSolveNode::publishMarker(const auto_aim_interfaces::msg::SolveInfo & solve_info_msg){
//     aim_point_marker_.header = solve_info_msg.header;
//     aim_point_marker_.pose.position = solve_info_msg.aim_position;
//     aim_point_pub_->publish(aim_point_marker_);
// }
}
}  // namespace rm_buff