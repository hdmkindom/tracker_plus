// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from auto_aim_interfaces:msg/SolveInfo.idl
// generated code does not contain a copyright notice

#ifndef AUTO_AIM_INTERFACES__MSG__DETAIL__SOLVE_INFO__STRUCT_HPP_
#define AUTO_AIM_INTERFACES__MSG__DETAIL__SOLVE_INFO__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.hpp"
// Member 'aim_position'
#include "geometry_msgs/msg/detail/point__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__auto_aim_interfaces__msg__SolveInfo __attribute__((deprecated))
#else
# define DEPRECATED__auto_aim_interfaces__msg__SolveInfo __declspec(deprecated)
#endif

namespace auto_aim_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct SolveInfo_
{
  using Type = SolveInfo_<ContainerAllocator>;

  explicit SolveInfo_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init),
    aim_position(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->idx = 0l;
      this->tar_yaw = 0.0;
      this->is_fire = false;
      this->aim_x = 0.0;
      this->aim_y = 0.0;
      this->aim_z = 0.0;
      this->d_yaw = 0.0;
    }
  }

  explicit SolveInfo_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init),
    aim_position(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->idx = 0l;
      this->tar_yaw = 0.0;
      this->is_fire = false;
      this->aim_x = 0.0;
      this->aim_y = 0.0;
      this->aim_z = 0.0;
      this->d_yaw = 0.0;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _idx_type =
    int32_t;
  _idx_type idx;
  using _tar_yaw_type =
    double;
  _tar_yaw_type tar_yaw;
  using _is_fire_type =
    bool;
  _is_fire_type is_fire;
  using _aim_x_type =
    double;
  _aim_x_type aim_x;
  using _aim_y_type =
    double;
  _aim_y_type aim_y;
  using _aim_z_type =
    double;
  _aim_z_type aim_z;
  using _aim_position_type =
    geometry_msgs::msg::Point_<ContainerAllocator>;
  _aim_position_type aim_position;
  using _d_yaw_type =
    double;
  _d_yaw_type d_yaw;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__idx(
    const int32_t & _arg)
  {
    this->idx = _arg;
    return *this;
  }
  Type & set__tar_yaw(
    const double & _arg)
  {
    this->tar_yaw = _arg;
    return *this;
  }
  Type & set__is_fire(
    const bool & _arg)
  {
    this->is_fire = _arg;
    return *this;
  }
  Type & set__aim_x(
    const double & _arg)
  {
    this->aim_x = _arg;
    return *this;
  }
  Type & set__aim_y(
    const double & _arg)
  {
    this->aim_y = _arg;
    return *this;
  }
  Type & set__aim_z(
    const double & _arg)
  {
    this->aim_z = _arg;
    return *this;
  }
  Type & set__aim_position(
    const geometry_msgs::msg::Point_<ContainerAllocator> & _arg)
  {
    this->aim_position = _arg;
    return *this;
  }
  Type & set__d_yaw(
    const double & _arg)
  {
    this->d_yaw = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    auto_aim_interfaces::msg::SolveInfo_<ContainerAllocator> *;
  using ConstRawPtr =
    const auto_aim_interfaces::msg::SolveInfo_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<auto_aim_interfaces::msg::SolveInfo_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<auto_aim_interfaces::msg::SolveInfo_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      auto_aim_interfaces::msg::SolveInfo_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<auto_aim_interfaces::msg::SolveInfo_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      auto_aim_interfaces::msg::SolveInfo_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<auto_aim_interfaces::msg::SolveInfo_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<auto_aim_interfaces::msg::SolveInfo_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<auto_aim_interfaces::msg::SolveInfo_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__auto_aim_interfaces__msg__SolveInfo
    std::shared_ptr<auto_aim_interfaces::msg::SolveInfo_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__auto_aim_interfaces__msg__SolveInfo
    std::shared_ptr<auto_aim_interfaces::msg::SolveInfo_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SolveInfo_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->idx != other.idx) {
      return false;
    }
    if (this->tar_yaw != other.tar_yaw) {
      return false;
    }
    if (this->is_fire != other.is_fire) {
      return false;
    }
    if (this->aim_x != other.aim_x) {
      return false;
    }
    if (this->aim_y != other.aim_y) {
      return false;
    }
    if (this->aim_z != other.aim_z) {
      return false;
    }
    if (this->aim_position != other.aim_position) {
      return false;
    }
    if (this->d_yaw != other.d_yaw) {
      return false;
    }
    return true;
  }
  bool operator!=(const SolveInfo_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SolveInfo_

// alias to use template instance with default allocator
using SolveInfo =
  auto_aim_interfaces::msg::SolveInfo_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace auto_aim_interfaces

#endif  // AUTO_AIM_INTERFACES__MSG__DETAIL__SOLVE_INFO__STRUCT_HPP_
