// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from buff_interfaces:msg/BuffSend.idl
// generated code does not contain a copyright notice

#ifndef BUFF_INTERFACES__MSG__DETAIL__BUFF_SEND__STRUCT_H_
#define BUFF_INTERFACES__MSG__DETAIL__BUFF_SEND__STRUCT_H_

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
// Member 'position'
#include "geometry_msgs/msg/detail/point__struct.h"

/// Struct defined in msg/BuffSend in the package buff_interfaces.
typedef struct buff_interfaces__msg__BuffSend
{
  std_msgs__msg__Header header;
  bool is_fire;
  geometry_msgs__msg__Point position;
  double pitch;
  double yaw;
} buff_interfaces__msg__BuffSend;

// Struct for a sequence of buff_interfaces__msg__BuffSend.
typedef struct buff_interfaces__msg__BuffSend__Sequence
{
  buff_interfaces__msg__BuffSend * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} buff_interfaces__msg__BuffSend__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // BUFF_INTERFACES__MSG__DETAIL__BUFF_SEND__STRUCT_H_
