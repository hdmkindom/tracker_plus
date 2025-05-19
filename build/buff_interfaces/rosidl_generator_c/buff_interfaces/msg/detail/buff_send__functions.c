// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from buff_interfaces:msg/BuffSend.idl
// generated code does not contain a copyright notice
#include "buff_interfaces/msg/detail/buff_send__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `position`
#include "geometry_msgs/msg/detail/point__functions.h"

bool
buff_interfaces__msg__BuffSend__init(buff_interfaces__msg__BuffSend * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    buff_interfaces__msg__BuffSend__fini(msg);
    return false;
  }
  // is_fire
  // position
  if (!geometry_msgs__msg__Point__init(&msg->position)) {
    buff_interfaces__msg__BuffSend__fini(msg);
    return false;
  }
  // pitch
  // yaw
  return true;
}

void
buff_interfaces__msg__BuffSend__fini(buff_interfaces__msg__BuffSend * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // is_fire
  // position
  geometry_msgs__msg__Point__fini(&msg->position);
  // pitch
  // yaw
}

bool
buff_interfaces__msg__BuffSend__are_equal(const buff_interfaces__msg__BuffSend * lhs, const buff_interfaces__msg__BuffSend * rhs)
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
  // is_fire
  if (lhs->is_fire != rhs->is_fire) {
    return false;
  }
  // position
  if (!geometry_msgs__msg__Point__are_equal(
      &(lhs->position), &(rhs->position)))
  {
    return false;
  }
  // pitch
  if (lhs->pitch != rhs->pitch) {
    return false;
  }
  // yaw
  if (lhs->yaw != rhs->yaw) {
    return false;
  }
  return true;
}

bool
buff_interfaces__msg__BuffSend__copy(
  const buff_interfaces__msg__BuffSend * input,
  buff_interfaces__msg__BuffSend * output)
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
  // is_fire
  output->is_fire = input->is_fire;
  // position
  if (!geometry_msgs__msg__Point__copy(
      &(input->position), &(output->position)))
  {
    return false;
  }
  // pitch
  output->pitch = input->pitch;
  // yaw
  output->yaw = input->yaw;
  return true;
}

buff_interfaces__msg__BuffSend *
buff_interfaces__msg__BuffSend__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  buff_interfaces__msg__BuffSend * msg = (buff_interfaces__msg__BuffSend *)allocator.allocate(sizeof(buff_interfaces__msg__BuffSend), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(buff_interfaces__msg__BuffSend));
  bool success = buff_interfaces__msg__BuffSend__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
buff_interfaces__msg__BuffSend__destroy(buff_interfaces__msg__BuffSend * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    buff_interfaces__msg__BuffSend__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
buff_interfaces__msg__BuffSend__Sequence__init(buff_interfaces__msg__BuffSend__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  buff_interfaces__msg__BuffSend * data = NULL;

  if (size) {
    data = (buff_interfaces__msg__BuffSend *)allocator.zero_allocate(size, sizeof(buff_interfaces__msg__BuffSend), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = buff_interfaces__msg__BuffSend__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        buff_interfaces__msg__BuffSend__fini(&data[i - 1]);
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
buff_interfaces__msg__BuffSend__Sequence__fini(buff_interfaces__msg__BuffSend__Sequence * array)
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
      buff_interfaces__msg__BuffSend__fini(&array->data[i]);
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

buff_interfaces__msg__BuffSend__Sequence *
buff_interfaces__msg__BuffSend__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  buff_interfaces__msg__BuffSend__Sequence * array = (buff_interfaces__msg__BuffSend__Sequence *)allocator.allocate(sizeof(buff_interfaces__msg__BuffSend__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = buff_interfaces__msg__BuffSend__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
buff_interfaces__msg__BuffSend__Sequence__destroy(buff_interfaces__msg__BuffSend__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    buff_interfaces__msg__BuffSend__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
buff_interfaces__msg__BuffSend__Sequence__are_equal(const buff_interfaces__msg__BuffSend__Sequence * lhs, const buff_interfaces__msg__BuffSend__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!buff_interfaces__msg__BuffSend__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
buff_interfaces__msg__BuffSend__Sequence__copy(
  const buff_interfaces__msg__BuffSend__Sequence * input,
  buff_interfaces__msg__BuffSend__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(buff_interfaces__msg__BuffSend);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    buff_interfaces__msg__BuffSend * data =
      (buff_interfaces__msg__BuffSend *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!buff_interfaces__msg__BuffSend__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          buff_interfaces__msg__BuffSend__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!buff_interfaces__msg__BuffSend__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
