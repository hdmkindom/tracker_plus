
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

namespace rm_buff
{
class Solve
{
public:

    Solve(const float &k, const int &bias_time, const float &s_bias, const float &z_bias);

private:

};
} // namespace rm_buff
