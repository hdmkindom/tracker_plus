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

    // 初始化
    record_ = std::make_unique<Record>(uri_,topic_name,topic_type);

    // 灾难处理
    record_->disaster_init(uri_, topic_name, topic_type);

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

    // open
    rosbag2_storage::StorageOptions storage_options;
    storage_options.uri = uri_ + bag_name;
    storage_options.storage_id = "sqlite3";

    storage_options.max_bagfile_duration = 30;  // 30s
    const rosbag2_cpp::ConverterOptions converter_options(
        {rmw_get_serialization_format(), rmw_get_serialization_format()});

    writer_ = std::make_unique<rosbag2_cpp::writers::SequentialWriter>();
    writer_->open(storage_options, converter_options);

    // 
    for (const auto& topic_info : topic_info_) {
        writer_->create_topic(
        {topic_info.topic_name, topic_info.topic_type, rmw_get_serialization_format(), ""});
    }
    RCLCPP_INFO(get_logger(), "Start recording, saving to: %s", storage_options.uri.c_str());

    // Publisher

    // Subscriber

    image_sub_ = this->create_generic_subscription<rclcpp::SerializedMessage>(
        topic_info_[0].topic_name, topic_info_[0].topic_type, rclcpp::SensorDataQoS(),
        [this](std::shared_ptr<rclcpp::SerializedMessage> msg) { write(msg, 0); });

    camera_info_sub_ = this->create_generic_subscription<rclcpp::SerializedMessage>(
        topic_info_[1].topic_name,  topic_info_[1].topic_type, rclcpp::SensorDataQoS(),
        [this](std::shared_ptr<rclcpp::SerializedMessage> msg) { write(msg, 1); });
}


void RecordNode::write(std::shared_ptr<rclcpp::SerializedMessage> msg, int index)
{
    rcutils_time_point_value_t time_stamp;
    if (rcutils_system_time_now(&time_stamp) != RCUTILS_RET_OK) {
        RCLCPP_ERROR(get_logger(), "Error getting current time: %s", rcutils_get_error_string().str);
    }

    if (msg->get_rcl_serialized_message().buffer_length == 0) {
        RCLCPP_ERROR(get_logger(), "Empty message.");
        return;
    }

    auto bag_message = std::make_shared<rosbag2_storage::SerializedBagMessage>();

    bag_message->serialized_data = std::shared_ptr<rcutils_uint8_array_t>(
        new rcutils_uint8_array_t, [this](rcutils_uint8_array_t * msg) {
        auto fini_return = rcutils_uint8_array_fini(msg);
        delete msg;
        if (fini_return != RCUTILS_RET_OK) {
            RCLCPP_ERROR(
            get_logger(), "Failed to destroy serialized message %s", rcutils_get_error_string().str);
        }
        });
    *bag_message->serialized_data = msg->release_rcl_serialized_message();

    bag_message->topic_name = topic_info_[index].topic_name;

    bag_message->time_stamp = time_stamp;

    writer_->write(bag_message);

    RCLCPP_DEBUG(get_logger(), "Message written to bag.");
}


// 处理最后的退出
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