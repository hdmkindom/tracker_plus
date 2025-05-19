// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from auto_aim_interfaces:msg/Receive.idl
// generated code does not contain a copyright notice

#ifndef AUTO_AIM_INTERFACES__MSG__DETAIL__RECEIVE__BUILDER_HPP_
#define AUTO_AIM_INTERFACES__MSG__DETAIL__RECEIVE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "auto_aim_interfaces/msg/detail/receive__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace auto_aim_interfaces
{

namespace msg
{

namespace builder
{

class Init_Receive_roll
{
public:
  explicit Init_Receive_roll(::auto_aim_interfaces::msg::Receive & msg)
  : msg_(msg)
  {}
  ::auto_aim_interfaces::msg::Receive roll(::auto_aim_interfaces::msg::Receive::_roll_type arg)
  {
    msg_.roll = std::move(arg);
    return std::move(msg_);
  }

private:
  ::auto_aim_interfaces::msg::Receive msg_;
};

class Init_Receive_yaw
{
public:
  explicit Init_Receive_yaw(::auto_aim_interfaces::msg::Receive & msg)
  : msg_(msg)
  {}
  Init_Receive_roll yaw(::auto_aim_interfaces::msg::Receive::_yaw_type arg)
  {
    msg_.yaw = std::move(arg);
    return Init_Receive_roll(msg_);
  }

private:
  ::auto_aim_interfaces::msg::Receive msg_;
};

class Init_Receive_pitch
{
public:
  explicit Init_Receive_pitch(::auto_aim_interfaces::msg::Receive & msg)
  : msg_(msg)
  {}
  Init_Receive_yaw pitch(::auto_aim_interfaces::msg::Receive::_pitch_type arg)
  {
    msg_.pitch = std::move(arg);
    return Init_Receive_yaw(msg_);
  }

private:
  ::auto_aim_interfaces::msg::Receive msg_;
};

class Init_Receive_header
{
public:
  Init_Receive_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Receive_pitch header(::auto_aim_interfaces::msg::Receive::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_Receive_pitch(msg_);
  }

private:
  ::auto_aim_interfaces::msg::Receive msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::auto_aim_interfaces::msg::Receive>()
{
  return auto_aim_interfaces::msg::builder::Init_Receive_header();
}

}  // namespace auto_aim_interfaces

#endif  // AUTO_AIM_INTERFACES__MSG__DETAIL__RECEIVE__BUILDER_HPP_
