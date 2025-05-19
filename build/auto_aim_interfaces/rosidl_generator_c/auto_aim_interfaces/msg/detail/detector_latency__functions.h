// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from auto_aim_interfaces:msg/DetectorLatency.idl
// generated code does not contain a copyright notice

#ifndef AUTO_AIM_INTERFACES__MSG__DETAIL__DETECTOR_LATENCY__FUNCTIONS_H_
#define AUTO_AIM_INTERFACES__MSG__DETAIL__DETECTOR_LATENCY__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "auto_aim_interfaces/msg/rosidl_generator_c__visibility_control.h"

#include "auto_aim_interfaces/msg/detail/detector_latency__struct.h"

/// Initialize msg/DetectorLatency message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * auto_aim_interfaces__msg__DetectorLatency
 * )) before or use
 * auto_aim_interfaces__msg__DetectorLatency__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_auto_aim_interfaces
bool
auto_aim_interfaces__msg__DetectorLatency__init(auto_aim_interfaces__msg__DetectorLatency * msg);

/// Finalize msg/DetectorLatency message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_auto_aim_interfaces
void
auto_aim_interfaces__msg__DetectorLatency__fini(auto_aim_interfaces__msg__DetectorLatency * msg);

/// Create msg/DetectorLatency message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * auto_aim_interfaces__msg__DetectorLatency__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_auto_aim_interfaces
auto_aim_interfaces__msg__DetectorLatency *
auto_aim_interfaces__msg__DetectorLatency__create();

/// Destroy msg/DetectorLatency message.
/**
 * It calls
 * auto_aim_interfaces__msg__DetectorLatency__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_auto_aim_interfaces
void
auto_aim_interfaces__msg__DetectorLatency__destroy(auto_aim_interfaces__msg__DetectorLatency * msg);

/// Check for msg/DetectorLatency message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_auto_aim_interfaces
bool
auto_aim_interfaces__msg__DetectorLatency__are_equal(const auto_aim_interfaces__msg__DetectorLatency * lhs, const auto_aim_interfaces__msg__DetectorLatency * rhs);

/// Copy a msg/DetectorLatency message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_auto_aim_interfaces
bool
auto_aim_interfaces__msg__DetectorLatency__copy(
  const auto_aim_interfaces__msg__DetectorLatency * input,
  auto_aim_interfaces__msg__DetectorLatency * output);

/// Initialize array of msg/DetectorLatency messages.
/**
 * It allocates the memory for the number of elements and calls
 * auto_aim_interfaces__msg__DetectorLatency__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_auto_aim_interfaces
bool
auto_aim_interfaces__msg__DetectorLatency__Sequence__init(auto_aim_interfaces__msg__DetectorLatency__Sequence * array, size_t size);

/// Finalize array of msg/DetectorLatency messages.
/**
 * It calls
 * auto_aim_interfaces__msg__DetectorLatency__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_auto_aim_interfaces
void
auto_aim_interfaces__msg__DetectorLatency__Sequence__fini(auto_aim_interfaces__msg__DetectorLatency__Sequence * array);

/// Create array of msg/DetectorLatency messages.
/**
 * It allocates the memory for the array and calls
 * auto_aim_interfaces__msg__DetectorLatency__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_auto_aim_interfaces
auto_aim_interfaces__msg__DetectorLatency__Sequence *
auto_aim_interfaces__msg__DetectorLatency__Sequence__create(size_t size);

/// Destroy array of msg/DetectorLatency messages.
/**
 * It calls
 * auto_aim_interfaces__msg__DetectorLatency__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_auto_aim_interfaces
void
auto_aim_interfaces__msg__DetectorLatency__Sequence__destroy(auto_aim_interfaces__msg__DetectorLatency__Sequence * array);

/// Check for msg/DetectorLatency message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_auto_aim_interfaces
bool
auto_aim_interfaces__msg__DetectorLatency__Sequence__are_equal(const auto_aim_interfaces__msg__DetectorLatency__Sequence * lhs, const auto_aim_interfaces__msg__DetectorLatency__Sequence * rhs);

/// Copy an array of msg/DetectorLatency messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_auto_aim_interfaces
bool
auto_aim_interfaces__msg__DetectorLatency__Sequence__copy(
  const auto_aim_interfaces__msg__DetectorLatency__Sequence * input,
  auto_aim_interfaces__msg__DetectorLatency__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // AUTO_AIM_INTERFACES__MSG__DETAIL__DETECTOR_LATENCY__FUNCTIONS_H_
