// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from auto_aim_interfaces:msg/SolveInfo.idl
// generated code does not contain a copyright notice

#ifndef AUTO_AIM_INTERFACES__MSG__DETAIL__SOLVE_INFO__TRAITS_HPP_
#define AUTO_AIM_INTERFACES__MSG__DETAIL__SOLVE_INFO__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "auto_aim_interfaces/msg/detail/solve_info__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"
// Member 'aim_position'
#include "geometry_msgs/msg/detail/point__traits.hpp"

namespace auto_aim_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const SolveInfo & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: idx
  {
    out << "idx: ";
    rosidl_generator_traits::value_to_yaml(msg.idx, out);
    out << ", ";
  }

  // member: tar_yaw
  {
    out << "tar_yaw: ";
    rosidl_generator_traits::value_to_yaml(msg.tar_yaw, out);
    out << ", ";
  }

  // member: is_fire
  {
    out << "is_fire: ";
    rosidl_generator_traits::value_to_yaml(msg.is_fire, out);
    out << ", ";
  }

  // member: aim_x
  {
    out << "aim_x: ";
    rosidl_generator_traits::value_to_yaml(msg.aim_x, out);
    out << ", ";
  }

  // member: aim_y
  {
    out << "aim_y: ";
    rosidl_generator_traits::value_to_yaml(msg.aim_y, out);
    out << ", ";
  }

  // member: aim_z
  {
    out << "aim_z: ";
    rosidl_generator_traits::value_to_yaml(msg.aim_z, out);
    out << ", ";
  }

  // member: aim_position
  {
    out << "aim_position: ";
    to_flow_style_yaml(msg.aim_position, out);
    out << ", ";
  }

  // member: d_yaw
  {
    out << "d_yaw: ";
    rosidl_generator_traits::value_to_yaml(msg.d_yaw, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SolveInfo & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: header
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "header:\n";
    to_block_style_yaml(msg.header, out, indentation + 2);
  }

  // member: idx
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "idx: ";
    rosidl_generator_traits::value_to_yaml(msg.idx, out);
    out << "\n";
  }

  // member: tar_yaw
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "tar_yaw: ";
    rosidl_generator_traits::value_to_yaml(msg.tar_yaw, out);
    out << "\n";
  }

  // member: is_fire
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "is_fire: ";
    rosidl_generator_traits::value_to_yaml(msg.is_fire, out);
    out << "\n";
  }

  // member: aim_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "aim_x: ";
    rosidl_generator_traits::value_to_yaml(msg.aim_x, out);
    out << "\n";
  }

  // member: aim_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "aim_y: ";
    rosidl_generator_traits::value_to_yaml(msg.aim_y, out);
    out << "\n";
  }

  // member: aim_z
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "aim_z: ";
    rosidl_generator_traits::value_to_yaml(msg.aim_z, out);
    out << "\n";
  }

  // member: aim_position
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "aim_position:\n";
    to_block_style_yaml(msg.aim_position, out, indentation + 2);
  }

  // member: d_yaw
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "d_yaw: ";
    rosidl_generator_traits::value_to_yaml(msg.d_yaw, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SolveInfo & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace auto_aim_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use auto_aim_interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const auto_aim_interfaces::msg::SolveInfo & msg,
  std::ostream & out, size_t indentation = 0)
{
  auto_aim_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use auto_aim_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const auto_aim_interfaces::msg::SolveInfo & msg)
{
  return auto_aim_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<auto_aim_interfaces::msg::SolveInfo>()
{
  return "auto_aim_interfaces::msg::SolveInfo";
}

template<>
inline const char * name<auto_aim_interfaces::msg::SolveInfo>()
{
  return "auto_aim_interfaces/msg/SolveInfo";
}

template<>
struct has_fixed_size<auto_aim_interfaces::msg::SolveInfo>
  : std::integral_constant<bool, has_fixed_size<geometry_msgs::msg::Point>::value && has_fixed_size<std_msgs::msg::Header>::value> {};

template<>
struct has_bounded_size<auto_aim_interfaces::msg::SolveInfo>
  : std::integral_constant<bool, has_bounded_size<geometry_msgs::msg::Point>::value && has_bounded_size<std_msgs::msg::Header>::value> {};

template<>
struct is_message<auto_aim_interfaces::msg::SolveInfo>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // AUTO_AIM_INTERFACES__MSG__DETAIL__SOLVE_INFO__TRAITS_HPP_
