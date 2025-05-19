// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from buff_interfaces:msg/Velocity.idl
// generated code does not contain a copyright notice

#ifndef BUFF_INTERFACES__MSG__DETAIL__VELOCITY__TRAITS_HPP_
#define BUFF_INTERFACES__MSG__DETAIL__VELOCITY__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "buff_interfaces/msg/detail/velocity__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"

namespace buff_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const Velocity & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: velocity
  {
    out << "velocity: ";
    rosidl_generator_traits::value_to_yaml(msg.velocity, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Velocity & msg,
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

  // member: velocity
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "velocity: ";
    rosidl_generator_traits::value_to_yaml(msg.velocity, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Velocity & msg, bool use_flow_style = false)
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

}  // namespace buff_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use buff_interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const buff_interfaces::msg::Velocity & msg,
  std::ostream & out, size_t indentation = 0)
{
  buff_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use buff_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const buff_interfaces::msg::Velocity & msg)
{
  return buff_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<buff_interfaces::msg::Velocity>()
{
  return "buff_interfaces::msg::Velocity";
}

template<>
inline const char * name<buff_interfaces::msg::Velocity>()
{
  return "buff_interfaces/msg/Velocity";
}

template<>
struct has_fixed_size<buff_interfaces::msg::Velocity>
  : std::integral_constant<bool, has_fixed_size<std_msgs::msg::Header>::value> {};

template<>
struct has_bounded_size<buff_interfaces::msg::Velocity>
  : std::integral_constant<bool, has_bounded_size<std_msgs::msg::Header>::value> {};

template<>
struct is_message<buff_interfaces::msg::Velocity>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // BUFF_INTERFACES__MSG__DETAIL__VELOCITY__TRAITS_HPP_
