#include <angles/angles.h>
#include <tf2/LinearMath/Matrix3x3.h>
#include <tf2/LinearMath/Quaternion.h>
#include <tf2/convert.h>

#include <rclcpp/logger.hpp>
#include <tf2_geometry_msgs/tf2_geometry_msgs.hpp>

// STD
#include <cfloat>
#include <memory>
#include <string>

namespace rm_buff
{
Solve::Solve(const float &k, const int &bias_time, const float &s_bias, const float &z_bias)
: k(k), bias_time(bias_time), s_bias(s_bias), z_bias(z_bias)
{}

void BuffSolveTrajectory::init(const buff_interfaces::msg::Velocity::SharedPtr velocity_msg)
{   
    if (!std::isnan(velocity_msg->velocity)) { // 使用 std::isnan 检查是否为 NAN
        current_v = velocity_msg->velocity;
        // current_v = 25.5; // debug
    } else {
        current_v = 25.5; // 默认值
        std::cout << "电控没有给你传速度,我给设置成25.5了" << std::endl;
    }
}

}   //namespace rm_buff


