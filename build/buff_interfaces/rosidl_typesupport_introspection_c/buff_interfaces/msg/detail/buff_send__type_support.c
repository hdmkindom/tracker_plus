// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from buff_interfaces:msg/BuffSend.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "buff_interfaces/msg/detail/buff_send__rosidl_typesupport_introspection_c.h"
#include "buff_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "buff_interfaces/msg/detail/buff_send__functions.h"
#include "buff_interfaces/msg/detail/buff_send__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"
// Member `position`
#include "geometry_msgs/msg/point.h"
// Member `position`
#include "geometry_msgs/msg/detail/point__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void buff_interfaces__msg__BuffSend__rosidl_typesupport_introspection_c__BuffSend_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  buff_interfaces__msg__BuffSend__init(message_memory);
}

void buff_interfaces__msg__BuffSend__rosidl_typesupport_introspection_c__BuffSend_fini_function(void * message_memory)
{
  buff_interfaces__msg__BuffSend__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember buff_interfaces__msg__BuffSend__rosidl_typesupport_introspection_c__BuffSend_message_member_array[5] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(buff_interfaces__msg__BuffSend, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "is_fire",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(buff_interfaces__msg__BuffSend, is_fire),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "position",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(buff_interfaces__msg__BuffSend, position),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "pitch",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(buff_interfaces__msg__BuffSend, pitch),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "yaw",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(buff_interfaces__msg__BuffSend, yaw),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers buff_interfaces__msg__BuffSend__rosidl_typesupport_introspection_c__BuffSend_message_members = {
  "buff_interfaces__msg",  // message namespace
  "BuffSend",  // message name
  5,  // number of fields
  sizeof(buff_interfaces__msg__BuffSend),
  buff_interfaces__msg__BuffSend__rosidl_typesupport_introspection_c__BuffSend_message_member_array,  // message members
  buff_interfaces__msg__BuffSend__rosidl_typesupport_introspection_c__BuffSend_init_function,  // function to initialize message memory (memory has to be allocated)
  buff_interfaces__msg__BuffSend__rosidl_typesupport_introspection_c__BuffSend_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t buff_interfaces__msg__BuffSend__rosidl_typesupport_introspection_c__BuffSend_message_type_support_handle = {
  0,
  &buff_interfaces__msg__BuffSend__rosidl_typesupport_introspection_c__BuffSend_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_buff_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, buff_interfaces, msg, BuffSend)() {
  buff_interfaces__msg__BuffSend__rosidl_typesupport_introspection_c__BuffSend_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  buff_interfaces__msg__BuffSend__rosidl_typesupport_introspection_c__BuffSend_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Point)();
  if (!buff_interfaces__msg__BuffSend__rosidl_typesupport_introspection_c__BuffSend_message_type_support_handle.typesupport_identifier) {
    buff_interfaces__msg__BuffSend__rosidl_typesupport_introspection_c__BuffSend_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &buff_interfaces__msg__BuffSend__rosidl_typesupport_introspection_c__BuffSend_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
