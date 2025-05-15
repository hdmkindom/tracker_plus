#include "armor_tracker/tracker_node.hpp"

// STD
#include <auto_aim_interfaces/msg/detail/all_latency__struct.hpp>
#include <cmath>
#include <iostream>
#include <memory>
#include <vector>

namespace rm_auto_aim
{


}  // namespace rm_auto_aim

#include "rclcpp_components/register_node_macro.hpp"

// Register the component with class_loader.
// This acts as a sort of entry point, allowing the component to be discoverable when its library
// is being loaded into a running process.
RCLCPP_COMPONENTS_REGISTER_NODE(rm_auto_aim::ArmorTrackerNode)