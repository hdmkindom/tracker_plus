// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from buff_interfaces:msg/Velocity.idl
// generated code does not contain a copyright notice
#include "buff_interfaces/msg/detail/velocity__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"

bool
buff_interfaces__msg__Velocity__init(buff_interfaces__msg__Velocity * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    buff_interfaces__msg__Velocity__fini(msg);
    return false;
  }
  // velocity
  return true;
}

void
buff_interfaces__msg__Velocity__fini(buff_interfaces__msg__Velocity * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // velocity
}

bool
buff_interfaces__msg__Velocity__are_equal(const buff_interfaces__msg__Velocity * lhs, const buff_interfaces__msg__Velocity * rhs)
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
  // velocity
  if (lhs->velocity != rhs->velocity) {
    return false;
  }
  return true;
}

bool
buff_interfaces__msg__Velocity__copy(
  const buff_interfaces__msg__Velocity * input,
  buff_interfaces__msg__Velocity * output)
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
  // velocity
  output->velocity = input->velocity;
  return true;
}

buff_interfaces__msg__Velocity *
buff_interfaces__msg__Velocity__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  buff_interfaces__msg__Velocity * msg = (buff_interfaces__msg__Velocity *)allocator.allocate(sizeof(buff_interfaces__msg__Velocity), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(buff_interfaces__msg__Velocity));
  bool success = buff_interfaces__msg__Velocity__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
buff_interfaces__msg__Velocity__destroy(buff_interfaces__msg__Velocity * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    buff_interfaces__msg__Velocity__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
buff_interfaces__msg__Velocity__Sequence__init(buff_interfaces__msg__Velocity__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  buff_interfaces__msg__Velocity * data = NULL;

  if (size) {
    data = (buff_interfaces__msg__Velocity *)allocator.zero_allocate(size, sizeof(buff_interfaces__msg__Velocity), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = buff_interfaces__msg__Velocity__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        buff_interfaces__msg__Velocity__fini(&data[i - 1]);
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
buff_interfaces__msg__Velocity__Sequence__fini(buff_interfaces__msg__Velocity__Sequence * array)
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
      buff_interfaces__msg__Velocity__fini(&array->data[i]);
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

buff_interfaces__msg__Velocity__Sequence *
buff_interfaces__msg__Velocity__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  buff_interfaces__msg__Velocity__Sequence * array = (buff_interfaces__msg__Velocity__Sequence *)allocator.allocate(sizeof(buff_interfaces__msg__Velocity__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = buff_interfaces__msg__Velocity__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
buff_interfaces__msg__Velocity__Sequence__destroy(buff_interfaces__msg__Velocity__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    buff_interfaces__msg__Velocity__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
buff_interfaces__msg__Velocity__Sequence__are_equal(const buff_interfaces__msg__Velocity__Sequence * lhs, const buff_interfaces__msg__Velocity__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!buff_interfaces__msg__Velocity__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
buff_interfaces__msg__Velocity__Sequence__copy(
  const buff_interfaces__msg__Velocity__Sequence * input,
  buff_interfaces__msg__Velocity__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(buff_interfaces__msg__Velocity);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    buff_interfaces__msg__Velocity * data =
      (buff_interfaces__msg__Velocity *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!buff_interfaces__msg__Velocity__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          buff_interfaces__msg__Velocity__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!buff_interfaces__msg__Velocity__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
