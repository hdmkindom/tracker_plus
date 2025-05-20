
#ifndef TF2_GEOMETRY_MSGS_HPP
#define TF2_GEOMETRY_MSGS_HPP
#include <tf2_geometry_msgs/tf2_geometry_msgs.hpp>
#endif
#define PI 3.1415926535f
#define GRAVITY 9.78

// Eigen
#include <Eigen/Eigen>

// ROS
#include <geometry_msgs/msg/point.hpp>
#include <geometry_msgs/msg/quaternion.hpp>
#include <geometry_msgs/msg/vector3.hpp>

// STD
#include <memory>
#include <string>

// 自定义 msg
#include <buff_interfaces/msg/blade.hpp>
#include <buff_interfaces/msg/blade_array.hpp>
#include <buff_interfaces/msg/velocity.hpp>

namespace rm_buff
{
class Solve
{
public:

    Solve(const float &k, const int &bias_time, const float &s_bias, const float &z_bias);

    void initVelocity(const buff_interfaces::msg::Velocity::SharedPtr velocity_msg);
    void calculateArmorPosition(const buff_interfaces::msg::BladeArray::SharedPtr& msg, bool use_1, bool use_average_radius, float tar_yaw);
    std::pair<float, float> calculatePitchAndYaw(
        int idx, const buff_interfaces::msg::Blade& msg, float timeDelay, float s_bias, float z_bias, float current_v, bool use_target_center_for_yaw,float& aim_x, float& aim_y, float& aim_z);
    float pitchTrajectoryCompensation(float s, float z, float v);
    float monoDirectionalAirResistanceModel(float s, float v, float angle);
    float calculateFlyTime(float s, float v, float angle);

    // initVelocity
    float current_v;

    //飞行时间
    float ftime = 0.11; 

    // 初始化 参数
    float k;
    int bias_time;
    float s_bias;
    float z_bias;

private:


};
} // namespace rm_buff
