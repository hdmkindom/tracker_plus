// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from buff_interfaces:msg/Velocity.idl
// generated code does not contain a copyright notice

#ifndef BUFF_INTERFACES__MSG__DETAIL__VELOCITY__STRUCT_HPP_
#define BUFF_INTERFACES__MSG__DETAIL__VELOCITY__STRUCT_HPP_

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

#ifndef _WIN32
# define DEPRECATED__buff_interfaces__msg__Velocity __attribute__((deprecated))
#else
# define DEPRECATED__buff_interfaces__msg__Velocity __declspec(deprecated)
#endif

namespace buff_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Velocity_
{
  using Type = Velocity_<ContainerAllocator>;

  explicit Velocity_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->velocity = 0.0;
    }
  }

  explicit Velocity_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->velocity = 0.0;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _velocity_type =
    double;
  _velocity_type velocity;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__velocity(
    const double & _arg)
  {
    this->velocity = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    buff_interfaces::msg::Velocity_<ContainerAllocator> *;
  using ConstRawPtr =
    const buff_interfaces::msg::Velocity_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<buff_interfaces::msg::Velocity_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<buff_interfaces::msg::Velocity_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      buff_interfaces::msg::Velocity_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<buff_interfaces::msg::Velocity_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      buff_interfaces::msg::Velocity_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<buff_interfaces::msg::Velocity_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<buff_interfaces::msg::Velocity_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<buff_interfaces::msg::Velocity_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__buff_interfaces__msg__Velocity
    std::shared_ptr<buff_interfaces::msg::Velocity_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__buff_interfaces__msg__Velocity
    std::shared_ptr<buff_interfaces::msg::Velocity_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Velocity_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->velocity != other.velocity) {
      return false;
    }
    return true;
  }
  bool operator!=(const Velocity_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Velocity_

// alias to use template instance with default allocator
using Velocity =
  buff_interfaces::msg::Velocity_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace buff_interfaces

#endif  // BUFF_INTERFACES__MSG__DETAIL__VELOCITY__STRUCT_HPP_
