#include "rm_auto_record/record.hpp"


namespace rm_auto_record
{
Record::Record(const std::string &uri_, const std::vector<std::string> &topic_name, const std::vector<std::string> &topic_type)
: uri_(uri_), topic_name(topic_name), topic_type(topic_type)
{}

// init Disaster
void disaster_init(const std::string uri_, const std::vector<std::string> topic_name, const std::vector<std::string> topic_type){
    if (topic_name.size() != topic_type.size()) {
    RCLCPP_ERROR(rclcpp::get_logger("rm_auto_record"), "Topic name and type size not match.");
    return;
    }
}

// init time

// 

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







}   //namespace rm_auto_record
