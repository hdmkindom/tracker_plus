// ROS

// STD
#include <string>
#include <vector>

// msgs

namespace rm_auto_record
{

class Record
{
public:

    // 初始化参数
    std::string uri_;

    std::vector<std::string> topic_name;
    std::vector<std::string> topic_type;

    // record
    Record(const &string uri_, const vector<std::string> &topic_name, const vector<std::string> &topic_type);

private:

};

}  // namespace rm_auto_record