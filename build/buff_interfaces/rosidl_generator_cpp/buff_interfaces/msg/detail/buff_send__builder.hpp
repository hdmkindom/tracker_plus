// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from buff_interfaces:msg/BuffSend.idl
// generated code does not contain a copyright notice

#ifndef BUFF_INTERFACES__MSG__DETAIL__BUFF_SEND__BUILDER_HPP_
#define BUFF_INTERFACES__MSG__DETAIL__BUFF_SEND__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "buff_interfaces/msg/detail/buff_send__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace buff_interfaces
{

namespace msg
{

namespace builder
{

class Init_BuffSend_yaw
{
public:
  explicit Init_BuffSend_yaw(::buff_interfaces::msg::BuffSend & msg)
  : msg_(msg)
  {}
  ::buff_interfaces::msg::BuffSend yaw(::buff_interfaces::msg::BuffSend::_yaw_type arg)
  {
    msg_.yaw = std::move(arg);
    return std::move(msg_);
  }

private:
  ::buff_interfaces::msg::BuffSend msg_;
};

class Init_BuffSend_pitch
{
public:
  explicit Init_BuffSend_pitch(::buff_interfaces::msg::BuffSend & msg)
  : msg_(msg)
  {}
  Init_BuffSend_yaw pitch(::buff_interfaces::msg::BuffSend::_pitch_type arg)
  {
    msg_.pitch = std::move(arg);
    return Init_BuffSend_yaw(msg_);
  }

private:
  ::buff_interfaces::msg::BuffSend msg_;
};

class Init_BuffSend_position
{
public:
  explicit Init_BuffSend_position(::buff_interfaces::msg::BuffSend & msg)
  : msg_(msg)
  {}
  Init_BuffSend_pitch position(::buff_interfaces::msg::BuffSend::_position_type arg)
  {
    msg_.position = std::move(arg);
    return Init_BuffSend_pitch(msg_);
  }

private:
  ::buff_interfaces::msg::BuffSend msg_;
};

class Init_BuffSend_is_fire
{
public:
  explicit Init_BuffSend_is_fire(::buff_interfaces::msg::BuffSend & msg)
  : msg_(msg)
  {}
  Init_BuffSend_position is_fire(::buff_interfaces::msg::BuffSend::_is_fire_type arg)
  {
    msg_.is_fire = std::move(arg);
    return Init_BuffSend_position(msg_);
  }

private:
  ::buff_interfaces::msg::BuffSend msg_;
};

class Init_BuffSend_header
{
public:
  Init_BuffSend_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_BuffSend_is_fire header(::buff_interfaces::msg::BuffSend::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_BuffSend_is_fire(msg_);
  }

private:
  ::buff_interfaces::msg::BuffSend msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::buff_interfaces::msg::BuffSend>()
{
  return buff_interfaces::msg::builder::Init_BuffSend_header();
}

}  // namespace buff_interfaces

#endif  // BUFF_INTERFACES__MSG__DETAIL__BUFF_SEND__BUILDER_HPP_
