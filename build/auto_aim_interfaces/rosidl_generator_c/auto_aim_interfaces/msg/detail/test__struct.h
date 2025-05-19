// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from auto_aim_interfaces:msg/Test.idl
// generated code does not contain a copyright notice

#ifndef AUTO_AIM_INTERFACES__MSG__DETAIL__TEST__STRUCT_H_
#define AUTO_AIM_INTERFACES__MSG__DETAIL__TEST__STRUCT_H_

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

/// Struct defined in msg/Test in the package auto_aim_interfaces.
typedef struct auto_aim_interfaces__msg__Test
{
  std_msgs__msg__Header header;
  double yaw;
  double d_yaw;
} auto_aim_interfaces__msg__Test;

// Struct for a sequence of auto_aim_interfaces__msg__Test.
typedef struct auto_aim_interfaces__msg__Test__Sequence
{
  auto_aim_interfaces__msg__Test * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} auto_aim_interfaces__msg__Test__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // AUTO_AIM_INTERFACES__MSG__DETAIL__TEST__STRUCT_H_
