#include "armor_solve/solve_node.hpp"

//STD

#include <algorithm>
#include <auto_aim_interfaces/msg/detail/send__struct.hpp>
#include <auto_aim_interfaces/msg/detail/target__struct.hpp>
#include <cmath>
#include <cstddef>
#include <functional>
#include <vector>
#include <iostream>

namespace rm_auto_aim
{
ArmorSolveNode::ArmorSolveNode(const rclcpp::NodeOptions & options)
: Node("armor_solve", options)
{
    RCLCPP_INFO(this->get_logger(), "Starting SolveNode!");

    // 用于弹道解算的k值具体计算在git
    k = this->declare_parameter("solve.k", 0.092);
    bias_time = this->declare_parameter("solve.bias_time", 100);
    s_bias = this->declare_parameter("solve.s_bias", 0.18375);
    z_bias = this->declare_parameter("solve.z_bias", 0.196);

    // 
    v_top = this->declare_parameter("solve.v_top", 24);

    // Publisher

    send_pub_ = this->create_publisher<auto_aim_interfaces::msg::Send>(
        "/solve/send", rclcpp::SensorDataQoS());

    // Subscriber
    receive_sub_ = this->create_subscription<auto_aim_interfaces::msg::Receive>(
        "/solve/receive", rclcpp::QoS(rclcpp::QoSInitialization::from_rmw(rmw_qos_profile_sensor_data)),
        std::bind(&ArmorSolveNode::receiveCallback, this, std::placeholders::_1));

    velocity_sub_ = this->create_subscription<auto_aim_interfaces::msg::Velocity>(
        "/current_velocity", rclcpp::QoS(rclcpp::QoSInitialization::from_rmw(rmw_qos_profile_sensor_data)),
        std::bind(&ArmorSolveNode::velocityCallback, this, std::placeholders::_1));
    
    target_sub_ = this->create_subscription<auto_aim_interfaces::msg::Target>(
        "/solve/target", rclcpp::QoS(rclcpp::QoSInitialization::from_rmw(rmw_qos_profile_sensor_data)),
        std::bind(&ArmorSolveNode::targetCallback, this, std::placeholders::_1));


    // marker
    marker_pub_ = this->create_publisher<visualization_msgs::msg::MarkerArray>("/solve/marker", 10);
}

void ArmorSolveNode::velocityCallback(const auto_aim_interfaces::msg::Velocity::SharedPtr velocity_msg)
{

    solve_ -> initVelocity(velocity_msg);

}

void ArmorSolveNode::receiveCallback(const auto_aim_interfaces::msg::Receive::SharedPtr receive_msg)
{
    solve_ -> initReceive(receive_msg);
}

void ArmorSolveNode::targetCallback(const auto_aim_interfaces::msg::Target::SharedPtr target_msg)
{
    auto solve_latency_start = this->get_clock()->now();

    // Init message
    tar_yaw = target_msg->yaw;
    int idx = 0;
    bool is_fire = false;

    //计算四块装甲板的位置
    //装甲板id顺序，以四块装甲板为例，逆时针编号
    //      2
    //   3     1
    //      0
    
    // 对于 平衡步兵 
    if (target_msg->armors_num  == ARMOR_NUM_BALANCE) {
        solve_ -> calculateArmorPosition(target_msg , true, false);
        idx = solve_ -> selectArmor(target_msg);
    // 对于 前哨站
    } else if (target_msg->armors_num == ARMOR_NUM_OUTPOST) {
        solve_ -> calculateArmorPosition(target_msg, false, true);
        idx = solve_ -> selectArmor(target_msg);
        }
    // 对于普通装甲板 
    else {
        //* 解算装甲板位置 注意 use_1 以及 use_average_radius
        solve_ -> calculateArmorPosition(target_msg, false, false);

        // 切换看应不应该开火
        // 找到四块装甲板中最适合开火的那一块 idx ,并且如果都不适合就以最后一块也就是当前追踪的装甲板为准
        idx = solve_ -> selectArmor(target_msg);
    }

    std::pair<float, float> pitch_and_yaw;

    pitch_and_yaw = calculatePitchAndYaw(idx, target_msg, timeDelay, s_bias, z_bias, current_v, false, aim_x, aim_y, aim_z);

    // 使用 pitch_and_yaw 的值
    float send_pitch = pitch_and_yaw.first;
    float send_yaw = pitch_and_yaw.second;

    // publish

}



}  // namespace rm_auto_aim