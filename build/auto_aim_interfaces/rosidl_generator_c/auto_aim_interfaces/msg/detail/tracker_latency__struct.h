// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from auto_aim_interfaces:msg/TrackerLatency.idl
// generated code does not contain a copyright notice

#ifndef AUTO_AIM_INTERFACES__MSG__DETAIL__TRACKER_LATENCY__STRUCT_H_
#define AUTO_AIM_INTERFACES__MSG__DETAIL__TRACKER_LATENCY__STRUCT_H_

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

/// Struct defined in msg/TrackerLatency in the package auto_aim_interfaces.
typedef struct auto_aim_interfaces__msg__TrackerLatency
{
  std_msgs__msg__Header header;
  double tracker_latency;
} auto_aim_interfaces__msg__TrackerLatency;

// Struct for a sequence of auto_aim_interfaces__msg__TrackerLatency.
typedef struct auto_aim_interfaces__msg__TrackerLatency__Sequence
{
  auto_aim_interfaces__msg__TrackerLatency * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} auto_aim_interfaces__msg__TrackerLatency__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // AUTO_AIM_INTERFACES__MSG__DETAIL__TRACKER_LATENCY__STRUCT_H_
