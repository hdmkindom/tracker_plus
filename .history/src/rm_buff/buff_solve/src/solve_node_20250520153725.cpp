#include "buff_solve/solve_node.hpp"

//STD

#include <algorithm>
#include <buff_interfaces/msg/detail/blade_array__struct.hpp>
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
    buff_send_pub_ = this->create_publisher<buff_interfaces::msg::BuffSend>(
        "/buffsolve/send", rclcpp::SensorDataQoS());

    // Subscriber

    buff_velocity_sub_ = this->create_subscription<buff_interfaces::msg::Velocity>(
        "/buff_current_velocity", rclcpp::QoS(rclcpp::QoSInitialization::from_rmw(rmw_qos_profile_sensor_data)),
        std::bind(&BuffSolveNode::velocityCallback, this, std::placeholders::_1));
    
    blade_array_sub_ = this->create_subscription<buff_interfaces::msg::BladeArray>(
        "/detector/blade_array", 10,
        std::bind(&BuffSolveNode::bladeCallback, this, std::placeholders::_1));

}

void BuffSolveNode::velocityCallback(
    const buff_interfaces::msg::Velocity::SharedPtr velocity_msg)
{
    solve_->initVelocity(velocity_msg);
}

void BuffSolveNode::bladeCallback(
    const buff_interfaces::msg::BladeArray::SharedPtr Blade_Array_msg)
{
    auto solve_latency_start = this->get_clock()->now();

    // Init message
    auto blade_msg = Blade_Array_msg->blades[0];

    bool is_fire = false;

    float aim_x = 0;
    float aim_y = 0;
    float aim_z = 0;

    int idx = 0;

    rclcpp::Time time = Blade_Array_msg->header.stamp;
    buff_interfaces::msg::BuffSend send_msg;

    send_msg.header.stamp = time;

    // 发弹时间线性预测
    int delay_time = bias_time;

    float time_delay = delay_time/1000.0 + solve_->ftime;  // 改为 测距 所用时间 

    std::pair<float, float> pitch_and_yaw;

    pitch_and_yaw = solve_ -> calculatePitchAndYaw(idx, blade_msg, time_delay, s_bias, z_bias, current_v, false, aim_x, aim_y, aim_z);

    // 使用 pitch_and_yaw 的值
    float send_pitch = pitch_and_yaw.first;
    float send_yaw = pitch_and_yaw.second;

    // 发布传参
    send_msg.pitch = send_pitch;
    send_msg.yaw = send_yaw;
    send_msg.is_fire = is_fire;

    // publish
    buff_send_pub_->publish(send_msg);
}

// void BuffSolveNode::publishMarker(const buff_interfaces::msg::SolveInfo & solve_info_msg){
//     aim_point_marker_.header = solve_info_msg.header;
//     aim_point_marker_.pose.position = solve_info_msg.aim_position;
//     aim_point_pub_->publish(aim_point_marker_);
// }
}  // namespace rm_buff