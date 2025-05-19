// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from auto_aim_interfaces:msg/TrackerLatency.idl
// generated code does not contain a copyright notice

#ifndef AUTO_AIM_INTERFACES__MSG__DETAIL__TRACKER_LATENCY__BUILDER_HPP_
#define AUTO_AIM_INTERFACES__MSG__DETAIL__TRACKER_LATENCY__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "auto_aim_interfaces/msg/detail/tracker_latency__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace auto_aim_interfaces
{

namespace msg
{

namespace builder
{

class Init_TrackerLatency_tracker_latency
{
public:
  explicit Init_TrackerLatency_tracker_latency(::auto_aim_interfaces::msg::TrackerLatency & msg)
  : msg_(msg)
  {}
  ::auto_aim_interfaces::msg::TrackerLatency tracker_latency(::auto_aim_interfaces::msg::TrackerLatency::_tracker_latency_type arg)
  {
    msg_.tracker_latency = std::move(arg);
    return std::move(msg_);
  }

private:
  ::auto_aim_interfaces::msg::TrackerLatency msg_;
};

class Init_TrackerLatency_header
{
public:
  Init_TrackerLatency_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_TrackerLatency_tracker_latency header(::auto_aim_interfaces::msg::TrackerLatency::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_TrackerLatency_tracker_latency(msg_);
  }

private:
  ::auto_aim_interfaces::msg::TrackerLatency msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::auto_aim_interfaces::msg::TrackerLatency>()
{
  return auto_aim_interfaces::msg::builder::Init_TrackerLatency_header();
}

}  // namespace auto_aim_interfaces

#endif  // AUTO_AIM_INTERFACES__MSG__DETAIL__TRACKER_LATENCY__BUILDER_HPP_
