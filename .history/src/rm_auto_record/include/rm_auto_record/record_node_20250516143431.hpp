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

    topic_name;



};


}   // namespace rm_auto_record