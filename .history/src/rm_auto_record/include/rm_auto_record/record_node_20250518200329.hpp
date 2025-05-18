

// ROS
#include <rclcpp/node.hpp>
#include <rclcpp/rclcpp.hpp>
#include <rosbag2_cpp/writers/sequential_writer.hpp>
#include <rosbag2_storage/storage_options.hpp>
#include <sensor_msgs/msg/detail/compressed_image__struct.hpp>
#include <std_msgs/msg/string.hpp>
#include <sensor_msgs/msg/camera_info.hpp>

#include <rclcpp/generic_subscription.hpp>
#include <rclcpp/serialized_message.hpp>

#include <rosbag2_cpp/writer.hpp>
#include <rosbag2_cpp/writers/sequential_writer.hpp>

// STD

// 子包含
#include "record.hpp"



namespace rm_auto_record
{
class RecordNode : public rclcpp::Node
{

public:
    explicit RecordNode(const rclcpp::NodeOptions & options);
    ~RecordNode();

private:
    void recordInit();

    void write(std::shared_ptr<rclcpp::SerializedMessage> msg, int index);



    // 参数
    std::string uri_;

    std::vector<std::string> topic_name;
    std::vector<std::string> topic_type;

    // 指针
    std::unique_ptr<Record> record_;

    // Publisher

    // Subscriber
    rclcpp::Subscription<std_msgs::msg ::String>::SharedPtr record_controller_sub_;
    rclcpp::Subscription<sensor_msgs::msg::CompressedImage>::SharedPtr image_sub_;
    rclcpp::Subscription<sensor_msgs::msg::CameraInfo>::SharedPtr camera_info_sub_;

    std::shared_ptr<rosbag2_cpp::writers::SequentialWriter> writer_;

    struct TopicInfo
    {
        std::string topic_name;
        std::string topic_type;
    };

    std::vector<TopicInfo> topic_info_;



};


}   // namespace rm_auto_record