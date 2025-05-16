// ROS
#include <rclcpp/rclcpp.hpp>
#include <rosbag2_cpp/writer.hpp>
#include <rosbag2_cpp/writers/sequential_writer.hpp>

// STD
#include <string>
#include <vector>
#include <cmath>


// msgs

namespace rm_auto_record
{

class Record
{
public:

    void disaster_init(const std::string uri_, const std::vector<std::string> topic_name, const std::vector<std::string> topic_type);

    // 初始化参数
    std::string uri_;

    std::vector<std::string> topic_name;
    std::vector<std::string> topic_type;

    // record
    Record(const std::string &uri_, const std::vector<std::string> &topic_name, const std::vector<std::string> &topic_type);

private:

};

}  // namespace rm_auto_record