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
    record_->disaster_init(uri_, topic_name, topic_type);

    // init 
    recordInit();


    // Publisher

    // Subscriber
}

void RecordNode::recordInit()
{

    // time
    auto now = std::chrono::system_clock::now();
    auto now_c = std::chrono::system_clock::to_time_t(now);

    now_c += 8 * 3600;  // UTC+8
    auto yyyy_mm_dd_hh_mm_ss = std::localtime(&now_c);
    std::string bag_name = "record_" + std::to_string(yyyy_mm_dd_hh_mm_ss->tm_year + 1900) + "_" +
                            std::to_string(yyyy_mm_dd_hh_mm_ss->tm_mon + 1) + "_" +
                            std::to_string(yyyy_mm_dd_hh_mm_ss->tm_mday) + "_" +
                            std::to_string(yyyy_mm_dd_hh_mm_ss->tm_hour) + "_" +
                            std::to_string(yyyy_mm_dd_hh_mm_ss->tm_min) + "_" +
                            std::to_string(yyyy_mm_dd_hh_mm_ss->tm_sec);

    // 填充 topic_info_
    for (size_t i = 0; i < topic_name.size(); i++) {
        TopicInfo topic_info;
        topic_info.topic_name = topic_name[i];
        topic_info.topic_type = topic_type[i];
        RCLCPP_INFO(
        get_logger(), "Record topic: %s, type: %s", topic_info.topic_name.c_str(),
        topic_info.topic_type.c_str());
        topic_info_.push_back(topic_info);
    }

    // 

    //

}

RecordNode::~RecordNode()
{
    if (writer_) {
        writer_->close();
        RCLCPP_INFO(get_logger(), "Bag file closed on shutdown.");
    }
}


}  // namespace rm_auto_record

#include "rclcpp_components/register_node_macro.hpp"
RCLCPP_COMPONENTS_REGISTER_NODE(rm_auto_record::RecordNode)