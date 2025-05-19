// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from buff_interfaces:msg/BuffSend.idl
// generated code does not contain a copyright notice

#ifndef BUFF_INTERFACES__MSG__DETAIL__BUFF_SEND__STRUCT_HPP_
#define BUFF_INTERFACES__MSG__DETAIL__BUFF_SEND__STRUCT_HPP_

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
// Member 'position'
#include "geometry_msgs/msg/detail/point__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__buff_interfaces__msg__BuffSend __attribute__((deprecated))
#else
# define DEPRECATED__buff_interfaces__msg__BuffSend __declspec(deprecated)
#endif

namespace buff_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct BuffSend_
{
  using Type = BuffSend_<ContainerAllocator>;

  explicit BuffSend_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init),
    position(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->is_fire = false;
      this->pitch = 0.0;
      this->yaw = 0.0;
    }
  }

  explicit BuffSend_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init),
    position(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->is_fire = false;
      this->pitch = 0.0;
      this->yaw = 0.0;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _is_fire_type =
    bool;
  _is_fire_type is_fire;
  using _position_type =
    geometry_msgs::msg::Point_<ContainerAllocator>;
  _position_type position;
  using _pitch_type =
    double;
  _pitch_type pitch;
  using _yaw_type =
    double;
  _yaw_type yaw;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__is_fire(
    const bool & _arg)
  {
    this->is_fire = _arg;
    return *this;
  }
  Type & set__position(
    const geometry_msgs::msg::Point_<ContainerAllocator> & _arg)
  {
    this->position = _arg;
    return *this;
  }
  Type & set__pitch(
    const double & _arg)
  {
    this->pitch = _arg;
    return *this;
  }
  Type & set__yaw(
    const double & _arg)
  {
    this->yaw = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    buff_interfaces::msg::BuffSend_<ContainerAllocator> *;
  using ConstRawPtr =
    const buff_interfaces::msg::BuffSend_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<buff_interfaces::msg::BuffSend_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<buff_interfaces::msg::BuffSend_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      buff_interfaces::msg::BuffSend_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<buff_interfaces::msg::BuffSend_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      buff_interfaces::msg::BuffSend_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<buff_interfaces::msg::BuffSend_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<buff_interfaces::msg::BuffSend_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<buff_interfaces::msg::BuffSend_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__buff_interfaces__msg__BuffSend
    std::shared_ptr<buff_interfaces::msg::BuffSend_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__buff_interfaces__msg__BuffSend
    std::shared_ptr<buff_interfaces::msg::BuffSend_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const BuffSend_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->is_fire != other.is_fire) {
      return false;
    }
    if (this->position != other.position) {
      return false;
    }
    if (this->pitch != other.pitch) {
      return false;
    }
    if (this->yaw != other.yaw) {
      return false;
    }
    return true;
  }
  bool operator!=(const BuffSend_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct BuffSend_

// alias to use template instance with default allocator
using BuffSend =
  buff_interfaces::msg::BuffSend_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace buff_interfaces

#endif  // BUFF_INTERFACES__MSG__DETAIL__BUFF_SEND__STRUCT_HPP_
