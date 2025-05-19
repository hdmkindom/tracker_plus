// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from buff_interfaces:msg/BuffSend.idl
// generated code does not contain a copyright notice

#ifndef BUFF_INTERFACES__MSG__DETAIL__BUFF_SEND__TRAITS_HPP_
#define BUFF_INTERFACES__MSG__DETAIL__BUFF_SEND__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "buff_interfaces/msg/detail/buff_send__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"
// Member 'position'
#include "geometry_msgs/msg/detail/point__traits.hpp"

namespace buff_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const BuffSend & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: is_fire
  {
    out << "is_fire: ";
    rosidl_generator_traits::value_to_yaml(msg.is_fire, out);
    out << ", ";
  }

  // member: position
  {
    out << "position: ";
    to_flow_style_yaml(msg.position, out);
    out << ", ";
  }

  // member: pitch
  {
    out << "pitch: ";
    rosidl_generator_traits::value_to_yaml(msg.pitch, out);
    out << ", ";
  }

  // member: yaw
  {
    out << "yaw: ";
    rosidl_generator_traits::value_to_yaml(msg.yaw, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const BuffSend & msg,
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

  // member: is_fire
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "is_fire: ";
    rosidl_generator_traits::value_to_yaml(msg.is_fire, out);
    out << "\n";
  }

  // member: position
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "position:\n";
    to_block_style_yaml(msg.position, out, indentation + 2);
  }

  // member: pitch
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pitch: ";
    rosidl_generator_traits::value_to_yaml(msg.pitch, out);
    out << "\n";
  }

  // member: yaw
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "yaw: ";
    rosidl_generator_traits::value_to_yaml(msg.yaw, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const BuffSend & msg, bool use_flow_style = false)
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
  const buff_interfaces::msg::BuffSend & msg,
  std::ostream & out, size_t indentation = 0)
{
  buff_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use buff_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const buff_interfaces::msg::BuffSend & msg)
{
  return buff_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<buff_interfaces::msg::BuffSend>()
{
  return "buff_interfaces::msg::BuffSend";
}

template<>
inline const char * name<buff_interfaces::msg::BuffSend>()
{
  return "buff_interfaces/msg/BuffSend";
}

template<>
struct has_fixed_size<buff_interfaces::msg::BuffSend>
  : std::integral_constant<bool, has_fixed_size<geometry_msgs::msg::Point>::value && has_fixed_size<std_msgs::msg::Header>::value> {};

template<>
struct has_bounded_size<buff_interfaces::msg::BuffSend>
  : std::integral_constant<bool, has_bounded_size<geometry_msgs::msg::Point>::value && has_bounded_size<std_msgs::msg::Header>::value> {};

template<>
struct is_message<buff_interfaces::msg::BuffSend>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // BUFF_INTERFACES__MSG__DETAIL__BUFF_SEND__TRAITS_HPP_
