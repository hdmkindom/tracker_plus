// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from auto_aim_interfaces:msg/SolveInfo.idl
// generated code does not contain a copyright notice

#ifndef AUTO_AIM_INTERFACES__MSG__DETAIL__SOLVE_INFO__STRUCT_H_
#define AUTO_AIM_INTERFACES__MSG__DETAIL__SOLVE_INFO__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"
// Member 'aim_position'
#include "geometry_msgs/msg/detail/point__struct.h"

/// Struct defined in msg/SolveInfo in the package auto_aim_interfaces.
typedef struct auto_aim_interfaces__msg__SolveInfo
{
  std_msgs__msg__Header header;
  int32_t idx;
  double tar_yaw;
  bool is_fire;
  double aim_x;
  double aim_y;
  double aim_z;
  geometry_msgs__msg__Point aim_position;
  /// abds(send_yaw - receive_yaw)
  double d_yaw;
} auto_aim_interfaces__msg__SolveInfo;

// Struct for a sequence of auto_aim_interfaces__msg__SolveInfo.
typedef struct auto_aim_interfaces__msg__SolveInfo__Sequence
{
  auto_aim_interfaces__msg__SolveInfo * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} auto_aim_interfaces__msg__SolveInfo__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // AUTO_AIM_INTERFACES__MSG__DETAIL__SOLVE_INFO__STRUCT_H_
