

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
#include "auto_aim_interfaces/msg/armors.hpp"
#include "auto_aim_interfaces/msg/target.hpp"
#include "auto_aim_interfaces/msg/velocity.hpp"
#include "auto_aim_interfaces/msg/receive.hpp"

namespace rm_auto_aim
{
class Solve
{
public:

    //用于存储目标装甲板的信息
    struct tar_pos
    {
        float x;           //装甲板在世界坐标系下的x
        float y;           //装甲板在世界坐标系下的y
        float z;           //装甲板在世界坐标系下的z
        float yaw;         //装甲板坐标系相对于世界坐标系的yaw角
    };

    void initVelocity(const auto_aim_interfaces::msg::Velocity::SharedPtr velocity_msg);
    void initReceive(const auto_aim_interfaces::msg::Receive::SharedPtr receive_msg);
    void calculateArmorPosition(const auto_aim_interfaces::msg::Target::SharedPtr msg, bool use_1, bool use_average_radius);
    int selectArmor(const auto_aim_interfaces::msg::Target::SharedPtr& msg);

    std::pair<float, float> calculatePitchAndYaw(int idx, const auto_aim_interfaces::msg::Target::SharedPtr& msg, float timeDelay, float s_bias, float z_bias, float current_v, bool use_target_center_for_yaw,float& aim_x, float& aim_y, float& aim_z);
    
    float Solve::pitchTrajectoryCompensation(float s, float z, float v);
    // initVelocity
    float current_v;

    // initReceive
    float receive_pitch;
    float receive_yaw;
    float receive_roll;

    //飞行时间
    float ftime = 0.11;    

    // 目标信息
    struct tar_pos tar_position[4];

private:

};
} // namespace rm_auto_aim
