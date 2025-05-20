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

#include "buff_solve/solve.hpp"

namespace rm_buff
{
Solve::Solve(const float &k, const int &bias_time, const float &s_bias, const float &z_bias)
: k(k), bias_time(bias_time), s_bias(s_bias), z_bias(z_bias)
{}

void Solve::initVelocity(const buff_interfaces::msg::Velocity::SharedPtr velocity_msg)
{   
    if (!std::isnan(velocity_msg->velocity)) { // 使用 std::isnan 检查是否为 NAN
        current_v = velocity_msg->velocity;
        // current_v = 25.5; // debug
    } else {
        current_v = 25.5; // 默认值
        std::cout << "电控没有给你传速度,我给设置成25.5了" << std::endl;
    }
}

//! 解算Pitch && Yaw
/**
 * @brief 
 * 
 * @param idx 最适合开获得装甲板号
 * @param Buff_interfaces::msg::Blade::SharedPtr& msg 装甲板信息
 * @param timeDelay 延迟时间
 * @param s_bias 枪口前推偏置
 * @param z_bias z偏置
 * @param current_v 弹速
 * @param use_target_center_for_yaw 是否使用角度选板逻辑
 * @param aim_x x打击落点
 * @param aim_y y打击落点
 * @param aim_z z打击落点
 * @return std::pair<float, float> 
 */
std::pair<float, float> Solve::calculatePitchAndYaw(int idx, const buff_interfaces::msg::Blade& msg, float timeDelay, float s_bias, float z_bias, float current_v, bool use_target_center_for_yaw,float& aim_x, float& aim_y, float& aim_z) {
    

    // 无用的部分
    idx = 0;
    timeDelay = 0;
    use_target_center_for_yaw = 0;

    // 对打击目标xyz进行线性预测,初步的落点
    aim_x = msg->pose.position.x;
    aim_y = msg->pose.position.y;
    aim_z = msg->pose.position.z;
    
    // 切换识别装甲板还是robt 中心
    float yaw_x = aim_x;
    float yaw_y = aim_y;

    //* 真正的 pitch轴 解算
    float send_pitch = pitchTrajectoryCompensation(std::sqrt((aim_x) * (aim_x) + (aim_y) * (aim_y)) - s_bias,
            aim_z + z_bias, current_v);
    
    // yaw轴解算
    float send_yaw = (float)(std::atan2(yaw_y, yaw_x));

    return std::make_pair(send_pitch, send_yaw);
}

//! pitch轴解算
/** 
* @brief pitch轴解算 一般全解算次数在20 - 27 之间,修改for范围
* @param s:m 距离
* @param z:m 高度
* @param v:m/s
* @return angle_pitch:rad
*/
float Solve::pitchTrajectoryCompensation(float s, float z, float v) {
    // 初始
    float z_temp = z;
    float angle_pitch = 0.0f;
    int num = 0;

    // 迭代求解 send_pitch 注意看图
    for (int i = 0; i < 22; i++) {
        angle_pitch = std::atan2(z_temp, s);
        //* 单方向空气阻力模型
        float z_actual = monoDirectionalAirResistanceModel(s, v, angle_pitch);
        float dz = 0.3f * (z - z_actual);
        z_temp += dz;
        num++;

        if (std::fabs(dz) < 0.00001f) {
            break;
        }
    }
    // std::cout << "pitch解算数:" << num << std::endl;

    ftime = calculateFlyTime(s, v, angle_pitch);
    
    // std::cout << "ftime +: " << ff << std::endl;
    return angle_pitch;
}

//! 单方向空气阻力弹道模型
/*
@brief 简单物理模型自己去推导
@param s:m 距离
@param v:m/s 速度
@param angle:rachouxiang
@return z:m
*/
float Solve::monoDirectionalAirResistanceModel(float s, float v, float angle)
{
    float z,t;
    //t为给定v与angle时的飞行时间
    t = calculateFlyTime(s, v, angle);

    //z为给定v与angle时的高度
    z = (float)(v * std::sin(angle) * t - GRAVITY * t * t / 2);

    return z;
}

/**
 * @brief 根据距离、速度和角度计算飞行时间
 * @param s 距离 (m)
 * @param v 初速度 (m/s)
 * @param angle 发射角度 (rad)
 * @return 飞行时间 (s)
 */
float Solve::calculateFlyTime(float s, float v, float angle) {
    return (std::exp(k * s) - 1) / (k * v * std::cos(angle));
}




}   //namespace rm_buff


