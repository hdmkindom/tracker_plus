// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from auto_aim_interfaces:msg/DetectorLatency.idl
// generated code does not contain a copyright notice

#ifndef AUTO_AIM_INTERFACES__MSG__DETAIL__DETECTOR_LATENCY__BUILDER_HPP_
#define AUTO_AIM_INTERFACES__MSG__DETAIL__DETECTOR_LATENCY__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "auto_aim_interfaces/msg/detail/detector_latency__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace auto_aim_interfaces
{

namespace msg
{

namespace builder
{

class Init_DetectorLatency_detector_latency
{
public:
  explicit Init_DetectorLatency_detector_latency(::auto_aim_interfaces::msg::DetectorLatency & msg)
  : msg_(msg)
  {}
  ::auto_aim_interfaces::msg::DetectorLatency detector_latency(::auto_aim_interfaces::msg::DetectorLatency::_detector_latency_type arg)
  {
    msg_.detector_latency = std::move(arg);
    return std::move(msg_);
  }

private:
  ::auto_aim_interfaces::msg::DetectorLatency msg_;
};

class Init_DetectorLatency_header
{
public:
  Init_DetectorLatency_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_DetectorLatency_detector_latency header(::auto_aim_interfaces::msg::DetectorLatency::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_DetectorLatency_detector_latency(msg_);
  }

private:
  ::auto_aim_interfaces::msg::DetectorLatency msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::auto_aim_interfaces::msg::DetectorLatency>()
{
  return auto_aim_interfaces::msg::builder::Init_DetectorLatency_header();
}

}  // namespace auto_aim_interfaces

#endif  // AUTO_AIM_INTERFACES__MSG__DETAIL__DETECTOR_LATENCY__BUILDER_HPP_
