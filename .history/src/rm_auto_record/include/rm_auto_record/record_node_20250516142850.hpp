#include <rclcpp/node.hpp>
#include <rclcpp/rclcpp.hpp>

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



};


}   // namespace rm_auto_record