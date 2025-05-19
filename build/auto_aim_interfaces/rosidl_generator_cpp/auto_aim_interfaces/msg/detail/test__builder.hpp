// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from auto_aim_interfaces:msg/Test.idl
// generated code does not contain a copyright notice

#ifndef AUTO_AIM_INTERFACES__MSG__DETAIL__TEST__BUILDER_HPP_
#define AUTO_AIM_INTERFACES__MSG__DETAIL__TEST__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "auto_aim_interfaces/msg/detail/test__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace auto_aim_interfaces
{

namespace msg
{

namespace builder
{

class Init_Test_d_yaw
{
public:
  explicit Init_Test_d_yaw(::auto_aim_interfaces::msg::Test & msg)
  : msg_(msg)
  {}
  ::auto_aim_interfaces::msg::Test d_yaw(::auto_aim_interfaces::msg::Test::_d_yaw_type arg)
  {
    msg_.d_yaw = std::move(arg);
    return std::move(msg_);
  }

private:
  ::auto_aim_interfaces::msg::Test msg_;
};

class Init_Test_yaw
{
public:
  explicit Init_Test_yaw(::auto_aim_interfaces::msg::Test & msg)
  : msg_(msg)
  {}
  Init_Test_d_yaw yaw(::auto_aim_interfaces::msg::Test::_yaw_type arg)
  {
    msg_.yaw = std::move(arg);
    return Init_Test_d_yaw(msg_);
  }

private:
  ::auto_aim_interfaces::msg::Test msg_;
};

class Init_Test_header
{
public:
  Init_Test_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Test_yaw header(::auto_aim_interfaces::msg::Test::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_Test_yaw(msg_);
  }

private:
  ::auto_aim_interfaces::msg::Test msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::auto_aim_interfaces::msg::Test>()
{
  return auto_aim_interfaces::msg::builder::Init_Test_header();
}

}  // namespace auto_aim_interfaces

#endif  // AUTO_AIM_INTERFACES__MSG__DETAIL__TEST__BUILDER_HPP_
