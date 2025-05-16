#include "rm_auto_record/record_node.hpp"

namespace rm_auto_record
{

RecordNode::RecordNode(const rclcpp::NodeOptions & options) : Node("rm_auto_record", options)
{
    RCLCPP_INFO(this->get_logger(), "Starting Record!");




}

}  // namespace rm_auto_record

#include "rclcpp_components/register_node_macro.hpp"
RCLCPP_COMPONENTS_REGISTER_NODE(rm_auto_record::RecordNode)