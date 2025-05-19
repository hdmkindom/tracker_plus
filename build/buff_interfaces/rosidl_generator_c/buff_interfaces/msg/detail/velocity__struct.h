// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from buff_interfaces:msg/Velocity.idl
// generated code does not contain a copyright notice

#ifndef BUFF_INTERFACES__MSG__DETAIL__VELOCITY__STRUCT_H_
#define BUFF_INTERFACES__MSG__DETAIL__VELOCITY__STRUCT_H_

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

/// Struct defined in msg/Velocity in the package buff_interfaces.
typedef struct buff_interfaces__msg__Velocity
{
  std_msgs__msg__Header header;
  double velocity;
} buff_interfaces__msg__Velocity;

// Struct for a sequence of buff_interfaces__msg__Velocity.
typedef struct buff_interfaces__msg__Velocity__Sequence
{
  buff_interfaces__msg__Velocity * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} buff_interfaces__msg__Velocity__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // BUFF_INTERFACES__MSG__DETAIL__VELOCITY__STRUCT_H_
