# generated from rosidl_generator_py/resource/_idl.py.em
# with input from auto_aim_interfaces:msg/SolveInfo.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_SolveInfo(type):
    """Metaclass of message 'SolveInfo'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('auto_aim_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'auto_aim_interfaces.msg.SolveInfo')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__solve_info
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__solve_info
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__solve_info
            cls._TYPE_SUPPORT = module.type_support_msg__msg__solve_info
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__solve_info

            from geometry_msgs.msg import Point
            if Point.__class__._TYPE_SUPPORT is None:
                Point.__class__.__import_type_support__()

            from std_msgs.msg import Header
            if Header.__class__._TYPE_SUPPORT is None:
                Header.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class SolveInfo(metaclass=Metaclass_SolveInfo):
    """Message class 'SolveInfo'."""

    __slots__ = [
        '_header',
        '_idx',
        '_tar_yaw',
        '_is_fire',
        '_aim_x',
        '_aim_y',
        '_aim_z',
        '_aim_position',
        '_d_yaw',
    ]

    _fields_and_field_types = {
        'header': 'std_msgs/Header',
        'idx': 'int32',
        'tar_yaw': 'double',
        'is_fire': 'boolean',
        'aim_x': 'double',
        'aim_y': 'double',
        'aim_z': 'double',
        'aim_position': 'geometry_msgs/Point',
        'd_yaw': 'double',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['std_msgs', 'msg'], 'Header'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Point'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from std_msgs.msg import Header
        self.header = kwargs.get('header', Header())
        self.idx = kwargs.get('idx', int())
        self.tar_yaw = kwargs.get('tar_yaw', float())
        self.is_fire = kwargs.get('is_fire', bool())
        self.aim_x = kwargs.get('aim_x', float())
        self.aim_y = kwargs.get('aim_y', float())
        self.aim_z = kwargs.get('aim_z', float())
        from geometry_msgs.msg import Point
        self.aim_position = kwargs.get('aim_position', Point())
        self.d_yaw = kwargs.get('d_yaw', float())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.header != other.header:
            return False
        if self.idx != other.idx:
            return False
        if self.tar_yaw != other.tar_yaw:
            return False
        if self.is_fire != other.is_fire:
            return False
        if self.aim_x != other.aim_x:
            return False
        if self.aim_y != other.aim_y:
            return False
        if self.aim_z != other.aim_z:
            return False
        if self.aim_position != other.aim_position:
            return False
        if self.d_yaw != other.d_yaw:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def header(self):
        """Message field 'header'."""
        return self._header

    @header.setter
    def header(self, value):
        if __debug__:
            from std_msgs.msg import Header
            assert \
                isinstance(value, Header), \
                "The 'header' field must be a sub message of type 'Header'"
        self._header = value

    @builtins.property
    def idx(self):
        """Message field 'idx'."""
        return self._idx

    @idx.setter
    def idx(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'idx' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'idx' field must be an integer in [-2147483648, 2147483647]"
        self._idx = value

    @builtins.property
    def tar_yaw(self):
        """Message field 'tar_yaw'."""
        return self._tar_yaw

    @tar_yaw.setter
    def tar_yaw(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'tar_yaw' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'tar_yaw' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._tar_yaw = value

    @builtins.property
    def is_fire(self):
        """Message field 'is_fire'."""
        return self._is_fire

    @is_fire.setter
    def is_fire(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'is_fire' field must be of type 'bool'"
        self._is_fire = value

    @builtins.property
    def aim_x(self):
        """Message field 'aim_x'."""
        return self._aim_x

    @aim_x.setter
    def aim_x(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'aim_x' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'aim_x' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._aim_x = value

    @builtins.property
    def aim_y(self):
        """Message field 'aim_y'."""
        return self._aim_y

    @aim_y.setter
    def aim_y(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'aim_y' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'aim_y' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._aim_y = value

    @builtins.property
    def aim_z(self):
        """Message field 'aim_z'."""
        return self._aim_z

    @aim_z.setter
    def aim_z(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'aim_z' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'aim_z' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._aim_z = value

    @builtins.property
    def aim_position(self):
        """Message field 'aim_position'."""
        return self._aim_position

    @aim_position.setter
    def aim_position(self, value):
        if __debug__:
            from geometry_msgs.msg import Point
            assert \
                isinstance(value, Point), \
                "The 'aim_position' field must be a sub message of type 'Point'"
        self._aim_position = value

    @builtins.property
    def d_yaw(self):
        """Message field 'd_yaw'."""
        return self._d_yaw

    @d_yaw.setter
    def d_yaw(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'd_yaw' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'd_yaw' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._d_yaw = value
