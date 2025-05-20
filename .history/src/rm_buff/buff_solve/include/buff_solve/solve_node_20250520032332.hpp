// ROS
#include <message_filters/subscriber.h>
#include <tf2_ros/buffer.h>
#include <tf2_ros/create_timer_ros.h>
#include <tf2_ros/message_filter.h>
#include <tf2_ros/transform_listener.h>

#include <rclcpp/rclcpp.hpp>
#include <std_srvs/srv/trigger.hpp>
#include <tf2_geometry_msgs/tf2_geometry_msgs.hpp>
#include <visualization_msgs/msg/marker_array.hpp>

// STD
#include <memory>
#include <string>
#include <vector>

#include "armor_solve/solve.hpp"
#include "auto_aim_interfaces/msg/armors.hpp"
#include "auto_aim_interfaces/msg/target.hpp"
#include "auto_aim_interfaces/msg/send.hpp"
#include "auto_aim_interfaces/msg/velocity.hpp"
#include "auto_aim_interfaces/msg/tracker_info.hpp"
#include "auto_aim_interfaces/msg/receive.hpp"

#include "auto_aim_interfaces/msg/detector_latency.hpp"
#include "auto_aim_interfaces/msg/tracker_latency.hpp"

#include "std_msgs/msg/float64.hpp"
#include "auto_aim_interfaces/msg/test.hpp"

#include "auto_aim_interfaces/msg/solve_info.hpp"

namespace rm_buff
{
class BuffSolveNode : public rclcpp::Node
{
public:

private:

};
}   // namespace rm_buff