#include <rclcpp/node.hpp>
#include <rclcpp/rclcpp.hpp>

// ROS
#include <rosbag2_storage/storage_options.hpp>
#include <std_msgs/msg/string.hpp>
#include <sensor_msgs/msg/camera_info.hpp>


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

    // 
    rclcpp::Subscription<std_msgs::msg ::String> record_controller_sub_;



};


}   // namespace rm_auto_record