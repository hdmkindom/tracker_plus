// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from auto_aim_interfaces:msg/SolveInfo.idl
// generated code does not contain a copyright notice

#ifndef AUTO_AIM_INTERFACES__MSG__DETAIL__SOLVE_INFO__BUILDER_HPP_
#define AUTO_AIM_INTERFACES__MSG__DETAIL__SOLVE_INFO__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "auto_aim_interfaces/msg/detail/solve_info__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace auto_aim_interfaces
{

namespace msg
{

namespace builder
{

class Init_SolveInfo_d_yaw
{
public:
  explicit Init_SolveInfo_d_yaw(::auto_aim_interfaces::msg::SolveInfo & msg)
  : msg_(msg)
  {}
  ::auto_aim_interfaces::msg::SolveInfo d_yaw(::auto_aim_interfaces::msg::SolveInfo::_d_yaw_type arg)
  {
    msg_.d_yaw = std::move(arg);
    return std::move(msg_);
  }

private:
  ::auto_aim_interfaces::msg::SolveInfo msg_;
};

class Init_SolveInfo_aim_position
{
public:
  explicit Init_SolveInfo_aim_position(::auto_aim_interfaces::msg::SolveInfo & msg)
  : msg_(msg)
  {}
  Init_SolveInfo_d_yaw aim_position(::auto_aim_interfaces::msg::SolveInfo::_aim_position_type arg)
  {
    msg_.aim_position = std::move(arg);
    return Init_SolveInfo_d_yaw(msg_);
  }

private:
  ::auto_aim_interfaces::msg::SolveInfo msg_;
};

class Init_SolveInfo_aim_z
{
public:
  explicit Init_SolveInfo_aim_z(::auto_aim_interfaces::msg::SolveInfo & msg)
  : msg_(msg)
  {}
  Init_SolveInfo_aim_position aim_z(::auto_aim_interfaces::msg::SolveInfo::_aim_z_type arg)
  {
    msg_.aim_z = std::move(arg);
    return Init_SolveInfo_aim_position(msg_);
  }

private:
  ::auto_aim_interfaces::msg::SolveInfo msg_;
};

class Init_SolveInfo_aim_y
{
public:
  explicit Init_SolveInfo_aim_y(::auto_aim_interfaces::msg::SolveInfo & msg)
  : msg_(msg)
  {}
  Init_SolveInfo_aim_z aim_y(::auto_aim_interfaces::msg::SolveInfo::_aim_y_type arg)
  {
    msg_.aim_y = std::move(arg);
    return Init_SolveInfo_aim_z(msg_);
  }

private:
  ::auto_aim_interfaces::msg::SolveInfo msg_;
};

class Init_SolveInfo_aim_x
{
public:
  explicit Init_SolveInfo_aim_x(::auto_aim_interfaces::msg::SolveInfo & msg)
  : msg_(msg)
  {}
  Init_SolveInfo_aim_y aim_x(::auto_aim_interfaces::msg::SolveInfo::_aim_x_type arg)
  {
    msg_.aim_x = std::move(arg);
    return Init_SolveInfo_aim_y(msg_);
  }

private:
  ::auto_aim_interfaces::msg::SolveInfo msg_;
};

class Init_SolveInfo_is_fire
{
public:
  explicit Init_SolveInfo_is_fire(::auto_aim_interfaces::msg::SolveInfo & msg)
  : msg_(msg)
  {}
  Init_SolveInfo_aim_x is_fire(::auto_aim_interfaces::msg::SolveInfo::_is_fire_type arg)
  {
    msg_.is_fire = std::move(arg);
    return Init_SolveInfo_aim_x(msg_);
  }

private:
  ::auto_aim_interfaces::msg::SolveInfo msg_;
};

class Init_SolveInfo_tar_yaw
{
public:
  explicit Init_SolveInfo_tar_yaw(::auto_aim_interfaces::msg::SolveInfo & msg)
  : msg_(msg)
  {}
  Init_SolveInfo_is_fire tar_yaw(::auto_aim_interfaces::msg::SolveInfo::_tar_yaw_type arg)
  {
    msg_.tar_yaw = std::move(arg);
    return Init_SolveInfo_is_fire(msg_);
  }

private:
  ::auto_aim_interfaces::msg::SolveInfo msg_;
};

class Init_SolveInfo_idx
{
public:
  explicit Init_SolveInfo_idx(::auto_aim_interfaces::msg::SolveInfo & msg)
  : msg_(msg)
  {}
  Init_SolveInfo_tar_yaw idx(::auto_aim_interfaces::msg::SolveInfo::_idx_type arg)
  {
    msg_.idx = std::move(arg);
    return Init_SolveInfo_tar_yaw(msg_);
  }

private:
  ::auto_aim_interfaces::msg::SolveInfo msg_;
};

class Init_SolveInfo_header
{
public:
  Init_SolveInfo_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SolveInfo_idx header(::auto_aim_interfaces::msg::SolveInfo::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_SolveInfo_idx(msg_);
  }

private:
  ::auto_aim_interfaces::msg::SolveInfo msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::auto_aim_interfaces::msg::SolveInfo>()
{
  return auto_aim_interfaces::msg::builder::Init_SolveInfo_header();
}

}  // namespace auto_aim_interfaces

#endif  // AUTO_AIM_INTERFACES__MSG__DETAIL__SOLVE_INFO__BUILDER_HPP_
