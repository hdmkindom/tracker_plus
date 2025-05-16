#include "rm_auto_record/record.hpp"

namespace rm_auto_record
{
Record::Record(const std::string &uri_, const std::vector<std::string> &topic_name, const std::vector<std::string> &topic_type)
: uri_(uri_), topic_name(topic_name), topic_type(topic_type)
{}






}   //namespace rm_auto_record
