

// ROS
#include <rclcpp/node.hpp>
#include <rclcpp/rclcpp.hpp>
#include <rosbag2_storage/storage_options.hpp>
#include <std_msgs/msg/string.hpp>
#include <sensor_msgs/msg/camera_info.hpp>

// STD

// 子包含
#include "record.hpp"



namespace rm_auto_record
{
class RecordNode : public rclcpp::Node
{

public:
    explicit RecordNode(const rclcpp::NodeOptions & options);

private:
    void recordInit(std_msgs::msg::String::SharedPtr msg);



    // 参数
    std::string uri_;

    std::vector<std::string> topic_name;
    std::vector<std::string> topic_type;

    // 指针
    std::unique_ptr<Record> record_;

    // Publisher


    // Subscriber
    rclcpp::Subscription<std_msgs::msg ::String>::SharedPtr record_controller_sub_;



};


}   // namespace rm_auto_record