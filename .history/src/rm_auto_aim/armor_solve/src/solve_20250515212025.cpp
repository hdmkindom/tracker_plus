#include "armor_solve/solve.hpp"

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

namespace rm_auto_aim
{
Solve::Solve(const float &k, const int &bias_time, const float &s_bias, const float &z_bias, const float &fire_k)
: k(k), bias_time(bias_time), s_bias(s_bias), z_bias(z_bias), fire_k(fire_k)
{}

void Solve::initVelocity(const auto_aim_interfaces::msg::Velocity::SharedPtr velocity_msg)
{   
    if (!std::isnan(velocity_msg->velocity)) { // 使用 std::isnan 检查是否为 NAN
        current_v = velocity_msg->velocity;
        // current_v = 25.5; // debug
    } else if (current_v <= 5 || current_v >= 30) {
    current_v = 24.0;
    RCLCPP_ERROR(rclcpp::get_logger("armor_solve"), "速度值太小或太大 ");
    } else {
        current_v = 24.0; // 默认值
        RCLCPP_ERROR(rclcpp::get_logger("armor_solve"), "速度值为 Nan ");
    }
}

void Solve::initReceive(const auto_aim_interfaces::msg::Receive::SharedPtr receive_msg)
{
    receive_pitch = receive_msg->pitch;
    receive_yaw = receive_msg->yaw;
    receive_roll = receive_msg->roll;
}

//! 解算四块装甲板位置
/**
 * @brief 根据当前观测到的装甲板信息，计算出来所有装甲板位置
 * 
 * @param auto_aim_interfaces::msg::Target::SharedPtr& msg
 * @param use_1 标志
 * @param use_average_radius 是否使用平均半径
 */
void Solve::calculateArmorPosition(const auto_aim_interfaces::msg::Target::SharedPtr& msg, bool use_1, bool use_average_radius, float tar_yaw) {

    std::vector<float> tmp_yaws; 

    min_yaw_in_cycle = std::numeric_limits<float>::max();   //?何用之有
    max_yaw_in_cycle = std::numeric_limits<float>::min();
    // 对每块装甲板
    for (int i = 0; i < msg->armors_num; i++) {
        // 计算 tmp_yaw,目标yaw换算,并且除以装甲板数量
        float tmp_yaw = tar_yaw + i * 2.0 * PI / msg->armors_num;
        tmp_yaws.push_back(tmp_yaw);
        min_yaw_in_cycle = std::min(min_yaw_in_cycle, tmp_yaw);
        max_yaw_in_cycle = std::max(max_yaw_in_cycle, tmp_yaw);

        // 半径
        float r;
        if (use_average_radius) {
            // 使用两个半径的平均值
            r = (msg->radius_1 + msg->radius_2) / 2;
        } else {
            // 使用r1或r2
            r = use_1 ? msg->radius_1 : msg->radius_2;
        }
        // 简单的三角函数计算,记住四块装甲板位置
        tar_position[i].x = msg->position.x - r * std::cos(tmp_yaw);
        tar_position[i].y = msg->position.y - r * std::sin(tmp_yaw);
        tar_position[i].z = msg->position.z;
        tar_position[i].yaw = tmp_yaw;
        use_1 = !use_1;
    }
}

int Solve::selectArmor(const auto_aim_interfaces::msg::Target::SharedPtr& msg) {
    int selected_armor_idx = 0;

    // 选择离你的机器人最近的装甲板 
    float min_distance = std::sqrt(tar_position[0].x * tar_position[0].x + tar_position[0].y * tar_position[0].y);
    for (int i = 1; i < msg->armors_num; i++) {
        float distance = std::sqrt(tar_position[i].x * tar_position[i].x + tar_position[i].y * tar_position[i].y);
        if (distance < min_distance) {
            min_distance = distance;
            selected_armor_idx = i;
        }
    }

    return selected_armor_idx;
}

//! 解算Pitch && Yaw
/**
 * @brief 
 * 
 * @param idx 最适合开获得装甲板号
 * @param auto_aim_interfaces::msg::Target::SharedPtr& msg 装甲板信息
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
std::pair<float, float> Solve::calculatePitchAndYaw(int idx, const auto_aim_interfaces::msg::Target::SharedPtr& msg, float timeDelay, float s_bias, float z_bias, float current_v, bool use_target_center_for_yaw,float& aim_x, float& aim_y, float& aim_z) {
    
    // 对打击目标xyz进行线性预测,初步的落点
    aim_x = tar_position[idx].x  + msg->velocity.x * timeDelay;
    aim_y = tar_position[idx].y  + msg->velocity.y * timeDelay;
    aim_z = tar_position[idx].z;
    
    // 切换识别装甲板还是robt 中心
    float yaw_x = use_target_center_for_yaw ? msg->position.x : aim_x;
    float yaw_y = use_target_center_for_yaw ? msg->position.y : aim_y;

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

bool Solve::shouldFire(const float send_yaw, const float receive_yaw, const float fire_k, float d_yaw){

    d_yaw = std::abs(send_yaw - receive_yaw);
    is_fire = false;
    if(d_yaw < fire_k){
        is_fire = true;
    }

    return is_fire;
}

}   //namespace rm_auto_aim


