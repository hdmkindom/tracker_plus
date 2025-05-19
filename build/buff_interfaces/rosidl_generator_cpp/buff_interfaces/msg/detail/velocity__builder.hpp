// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from buff_interfaces:msg/Velocity.idl
// generated code does not contain a copyright notice

#ifndef BUFF_INTERFACES__MSG__DETAIL__VELOCITY__BUILDER_HPP_
#define BUFF_INTERFACES__MSG__DETAIL__VELOCITY__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "buff_interfaces/msg/detail/velocity__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace buff_interfaces
{

namespace msg
{

namespace builder
{

class Init_Velocity_velocity
{
public:
  explicit Init_Velocity_velocity(::buff_interfaces::msg::Velocity & msg)
  : msg_(msg)
  {}
  ::buff_interfaces::msg::Velocity velocity(::buff_interfaces::msg::Velocity::_velocity_type arg)
  {
    msg_.velocity = std::move(arg);
    return std::move(msg_);
  }

private:
  ::buff_interfaces::msg::Velocity msg_;
};

class Init_Velocity_header
{
public:
  Init_Velocity_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Velocity_velocity header(::buff_interfaces::msg::Velocity::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_Velocity_velocity(msg_);
  }

private:
  ::buff_interfaces::msg::Velocity msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::buff_interfaces::msg::Velocity>()
{
  return buff_interfaces::msg::builder::Init_Velocity_header();
}

}  // namespace buff_interfaces

#endif  // BUFF_INTERFACES__MSG__DETAIL__VELOCITY__BUILDER_HPP_
