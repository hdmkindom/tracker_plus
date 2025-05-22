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
        "/buff_detector/buffsend", 10);

    // Subscriber
    buff_velocity_sub_ = this->create_subscription<buff_interfaces::msg::Velocity>(
        "/buff_current_velocity", 10,
        std::bind(&BuffSolveNode::velocityCallback, this, std::placeholders::_1));
    
    blade_array_sub_ = this->create_subscription<buff_interfaces::msg::BladeArray>(
        "/detector/blade_array", 10,
        std::bind(&BuffSolveNode::bladeCallback, this, std::placeholders::_1));

    // Subscriber with tf2 message_filter
    // tf2 relevant
    tf2_buffer_ = std::make_shared<tf2_ros::Buffer>(this->get_clock());
    // Create the timer interface before call to waitForTransform,
    // to avoid a tf2_ros::CreateTimerInterfaceException exception
    auto timer_interface = std::make_shared<tf2_ros::CreateTimerROS>(
        this->get_node_base_interface(), this->get_node_timers_interface());
    tf2_buffer_->setCreateTimerInterface(timer_interface);
    tf2_listener_ = std::make_shared<tf2_ros::TransformListener>(*tf2_buffer_);
    // subscriber and filter
    blades_sub_.subscribe(this, "/detector/blade_array", rmw_qos_profile_sensor_data);
    tf2_filter_ = std::make_shared<tf2_filter>(
        blades_sub_, *tf2_buffer_, target_frame_, 10, this->get_node_logging_interface(),
        this->get_node_clock_interface(), std::chrono::duration<int>(1));
    // Register a callback with tf2_ros::MessageFilter to be called when
    // transforms are available
    tf2_filter_->registerCallback(&BuffTrackerNode::bladesCallback, this);
}

void BuffSolveNode::velocityCallback(
    const buff_interfaces::msg::Velocity::SharedPtr velocity_msg)
{
    solve_->initVelocity(velocity_msg);
}

void BuffSolveNode::bladeCallback(
    const buff_interfaces::msg::BladeArray::SharedPtr Blade_Array_msg)
{
    RCLCPP_INFO(this->get_logger(), "bladeCallback has been TRIGGERED!"); // <--- 添加这行
    std::cout<<"+++++++++++++++++++++++++++"<<std::endl;

    auto solve_latency_start = this->get_clock()->now();

    // Init message
    buff_interfaces::msg::Blade::SharedPtr blade_msg = 
        std::make_shared<buff_interfaces::msg::Blade>(Blade_Array_msg->blades[0]);

    bool is_fire = false;

    float aim_x = 0;
    float aim_y = 0;
    float aim_z = 0;

    int idx = 0;

    rclcpp::Time time = Blade_Array_msg->header.stamp;
    buff_interfaces::msg::BuffSend send_msg;

    send_msg.header.stamp = time;

    // 填充打符数据
    if (!Blade_Array_msg || Blade_Array_msg->blades.empty()){
        aim_x = 2;
        aim_y = 2;
        aim_z = 2;
    }


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
#include "rclcpp_components/register_node_macro.hpp"

// Register the component with class_loader.
// This acts as a sort of entry point, allowing the component to be discoverable when its library
// is being loaded into a running process.
RCLCPP_COMPONENTS_REGISTER_NODE(rm_buff::BuffSolveNode)