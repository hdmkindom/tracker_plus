#include "rm_auto_record/record.hpp"

namespace rm_auto_record
{
Record::Record(const std::string &uri_, const std::vector<std::string> &topic_name, const std::vector<std::string> &topic_type)
: uri_(uri_), topic_name(topic_name), topic_type(topic_type)
{}

// init Disaster
void disaster_init(const std::string uri_, const std::vector<std::string> topic_name, const std::vector<std::string> topic_type){
    if (topic_name.size() != topic_type.size()) {
    RCLCPP_ERROR(get_logger(), "Topic name and type size not match.");
    return;
    }
}






}   //namespace rm_auto_record
