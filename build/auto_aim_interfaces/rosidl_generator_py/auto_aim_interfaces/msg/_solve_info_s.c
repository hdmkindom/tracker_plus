// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from auto_aim_interfaces:msg/SolveInfo.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "auto_aim_interfaces/msg/detail/solve_info__struct.h"
#include "auto_aim_interfaces/msg/detail/solve_info__functions.h"

ROSIDL_GENERATOR_C_IMPORT
bool std_msgs__msg__header__convert_from_py(PyObject * _pymsg, void * _ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * std_msgs__msg__header__convert_to_py(void * raw_ros_message);
ROSIDL_GENERATOR_C_IMPORT
bool geometry_msgs__msg__point__convert_from_py(PyObject * _pymsg, void * _ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * geometry_msgs__msg__point__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool auto_aim_interfaces__msg__solve_info__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[46];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("auto_aim_interfaces.msg._solve_info.SolveInfo", full_classname_dest, 45) == 0);
  }
  auto_aim_interfaces__msg__SolveInfo * ros_message = _ros_message;
  {  // header
    PyObject * field = PyObject_GetAttrString(_pymsg, "header");
    if (!field) {
      return false;
    }
    if (!std_msgs__msg__header__convert_from_py(field, &ros_message->header)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // idx
    PyObject * field = PyObject_GetAttrString(_pymsg, "idx");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->idx = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // tar_yaw
    PyObject * field = PyObject_GetAttrString(_pymsg, "tar_yaw");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->tar_yaw = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // is_fire
    PyObject * field = PyObject_GetAttrString(_pymsg, "is_fire");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->is_fire = (Py_True == field);
    Py_DECREF(field);
  }
  {  // aim_x
    PyObject * field = PyObject_GetAttrString(_pymsg, "aim_x");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->aim_x = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // aim_y
    PyObject * field = PyObject_GetAttrString(_pymsg, "aim_y");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->aim_y = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // aim_z
    PyObject * field = PyObject_GetAttrString(_pymsg, "aim_z");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->aim_z = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // aim_position
    PyObject * field = PyObject_GetAttrString(_pymsg, "aim_position");
    if (!field) {
      return false;
    }
    if (!geometry_msgs__msg__point__convert_from_py(field, &ros_message->aim_position)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // d_yaw
    PyObject * field = PyObject_GetAttrString(_pymsg, "d_yaw");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->d_yaw = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * auto_aim_interfaces__msg__solve_info__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of SolveInfo */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("auto_aim_interfaces.msg._solve_info");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "SolveInfo");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  auto_aim_interfaces__msg__SolveInfo * ros_message = (auto_aim_interfaces__msg__SolveInfo *)raw_ros_message;
  {  // header
    PyObject * field = NULL;
    field = std_msgs__msg__header__convert_to_py(&ros_message->header);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "header", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // idx
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->idx);
    {
      int rc = PyObject_SetAttrString(_pymessage, "idx", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // tar_yaw
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->tar_yaw);
    {
      int rc = PyObject_SetAttrString(_pymessage, "tar_yaw", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // is_fire
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->is_fire ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "is_fire", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // aim_x
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->aim_x);
    {
      int rc = PyObject_SetAttrString(_pymessage, "aim_x", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // aim_y
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->aim_y);
    {
      int rc = PyObject_SetAttrString(_pymessage, "aim_y", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // aim_z
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->aim_z);
    {
      int rc = PyObject_SetAttrString(_pymessage, "aim_z", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // aim_position
    PyObject * field = NULL;
    field = geometry_msgs__msg__point__convert_to_py(&ros_message->aim_position);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "aim_position", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // d_yaw
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->d_yaw);
    {
      int rc = PyObject_SetAttrString(_pymessage, "d_yaw", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
