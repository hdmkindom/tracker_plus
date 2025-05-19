// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from auto_aim_interfaces:msg/SolveInfo.idl
// generated code does not contain a copyright notice
#include "auto_aim_interfaces/msg/detail/solve_info__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `aim_position`
#include "geometry_msgs/msg/detail/point__functions.h"

bool
auto_aim_interfaces__msg__SolveInfo__init(auto_aim_interfaces__msg__SolveInfo * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    auto_aim_interfaces__msg__SolveInfo__fini(msg);
    return false;
  }
  // idx
  // tar_yaw
  // is_fire
  // aim_x
  // aim_y
  // aim_z
  // aim_position
  if (!geometry_msgs__msg__Point__init(&msg->aim_position)) {
    auto_aim_interfaces__msg__SolveInfo__fini(msg);
    return false;
  }
  // d_yaw
  return true;
}

void
auto_aim_interfaces__msg__SolveInfo__fini(auto_aim_interfaces__msg__SolveInfo * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // idx
  // tar_yaw
  // is_fire
  // aim_x
  // aim_y
  // aim_z
  // aim_position
  geometry_msgs__msg__Point__fini(&msg->aim_position);
  // d_yaw
}

bool
auto_aim_interfaces__msg__SolveInfo__are_equal(const auto_aim_interfaces__msg__SolveInfo * lhs, const auto_aim_interfaces__msg__SolveInfo * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__are_equal(
      &(lhs->header), &(rhs->header)))
  {
    return false;
  }
  // idx
  if (lhs->idx != rhs->idx) {
    return false;
  }
  // tar_yaw
  if (lhs->tar_yaw != rhs->tar_yaw) {
    return false;
  }
  // is_fire
  if (lhs->is_fire != rhs->is_fire) {
    return false;
  }
  // aim_x
  if (lhs->aim_x != rhs->aim_x) {
    return false;
  }
  // aim_y
  if (lhs->aim_y != rhs->aim_y) {
    return false;
  }
  // aim_z
  if (lhs->aim_z != rhs->aim_z) {
    return false;
  }
  // aim_position
  if (!geometry_msgs__msg__Point__are_equal(
      &(lhs->aim_position), &(rhs->aim_position)))
  {
    return false;
  }
  // d_yaw
  if (lhs->d_yaw != rhs->d_yaw) {
    return false;
  }
  return true;
}

bool
auto_aim_interfaces__msg__SolveInfo__copy(
  const auto_aim_interfaces__msg__SolveInfo * input,
  auto_aim_interfaces__msg__SolveInfo * output)
{
  if (!input || !output) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__copy(
      &(input->header), &(output->header)))
  {
    return false;
  }
  // idx
  output->idx = input->idx;
  // tar_yaw
  output->tar_yaw = input->tar_yaw;
  // is_fire
  output->is_fire = input->is_fire;
  // aim_x
  output->aim_x = input->aim_x;
  // aim_y
  output->aim_y = input->aim_y;
  // aim_z
  output->aim_z = input->aim_z;
  // aim_position
  if (!geometry_msgs__msg__Point__copy(
      &(input->aim_position), &(output->aim_position)))
  {
    return false;
  }
  // d_yaw
  output->d_yaw = input->d_yaw;
  return true;
}

auto_aim_interfaces__msg__SolveInfo *
auto_aim_interfaces__msg__SolveInfo__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  auto_aim_interfaces__msg__SolveInfo * msg = (auto_aim_interfaces__msg__SolveInfo *)allocator.allocate(sizeof(auto_aim_interfaces__msg__SolveInfo), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(auto_aim_interfaces__msg__SolveInfo));
  bool success = auto_aim_interfaces__msg__SolveInfo__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
auto_aim_interfaces__msg__SolveInfo__destroy(auto_aim_interfaces__msg__SolveInfo * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    auto_aim_interfaces__msg__SolveInfo__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
auto_aim_interfaces__msg__SolveInfo__Sequence__init(auto_aim_interfaces__msg__SolveInfo__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  auto_aim_interfaces__msg__SolveInfo * data = NULL;

  if (size) {
    data = (auto_aim_interfaces__msg__SolveInfo *)allocator.zero_allocate(size, sizeof(auto_aim_interfaces__msg__SolveInfo), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = auto_aim_interfaces__msg__SolveInfo__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        auto_aim_interfaces__msg__SolveInfo__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
auto_aim_interfaces__msg__SolveInfo__Sequence__fini(auto_aim_interfaces__msg__SolveInfo__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      auto_aim_interfaces__msg__SolveInfo__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

auto_aim_interfaces__msg__SolveInfo__Sequence *
auto_aim_interfaces__msg__SolveInfo__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  auto_aim_interfaces__msg__SolveInfo__Sequence * array = (auto_aim_interfaces__msg__SolveInfo__Sequence *)allocator.allocate(sizeof(auto_aim_interfaces__msg__SolveInfo__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = auto_aim_interfaces__msg__SolveInfo__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
auto_aim_interfaces__msg__SolveInfo__Sequence__destroy(auto_aim_interfaces__msg__SolveInfo__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    auto_aim_interfaces__msg__SolveInfo__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
auto_aim_interfaces__msg__SolveInfo__Sequence__are_equal(const auto_aim_interfaces__msg__SolveInfo__Sequence * lhs, const auto_aim_interfaces__msg__SolveInfo__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!auto_aim_interfaces__msg__SolveInfo__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
auto_aim_interfaces__msg__SolveInfo__Sequence__copy(
  const auto_aim_interfaces__msg__SolveInfo__Sequence * input,
  auto_aim_interfaces__msg__SolveInfo__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(auto_aim_interfaces__msg__SolveInfo);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    auto_aim_interfaces__msg__SolveInfo * data =
      (auto_aim_interfaces__msg__SolveInfo *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!auto_aim_interfaces__msg__SolveInfo__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          auto_aim_interfaces__msg__SolveInfo__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!auto_aim_interfaces__msg__SolveInfo__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
