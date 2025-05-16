#include "rm_auto_record/record_node.hpp"

namespace rm_auto_record
{

RecordNode::RecordNode(const rclcpp::NodeOptions & options) : Node("rm_auto_record", options)
{
    RCLCPP_INFO(this->get_logger(), "Starting Record!");

    // 参数准备
    uri_ = this->declare_parameter<std::string>("uri", "/ros_ws/");

    topic_name = this->declare_parameter<std::vector<std::string>>(
        "topic_name", std::vector<std::string>());

    topic_type = this->declare_parameter<std::vector<std::string>>(
        "topic_type", std::vector<std::string>());

    // 智能指针初始化
    record_ = std::make_unique<Record>(uri_,topic_name,topic_type);

    // 灾难处理
    

    // Publisher

    // Subscriber
    record_controller_sub_ = create_subscription<std_msgs::msg ::String>(
        "/record_controller", 10, std::bind(&RecordNode::recordInit, this, std::placeholders::_1));
}

void RecordNode::recordInit(std_msgs::msg::String::SharedPtr msg)
{

}


}  // namespace rm_auto_record

#include "rclcpp_components/register_node_macro.hpp"
RCLCPP_COMPONENTS_REGISTER_NODE(rm_auto_record::RecordNode)