#include "armor_tracker/tracker_node.hpp"

// STD
#include <auto_aim_interfaces/msg/detail/all_latency__struct.hpp>
#include <cmath>
#include <iostream>
#include <memory>
#include <vector>

namespace rm_auto_aim
{
ArmorTrackerNode::ArmorTrackerNode(const rclcpp::NodeOptions & options)
: Node("armor_tracker", options)
{
    RCLCPP_INFO(this->get_logger(), "Starting TrackerNode!");

    //! 参数部分
    // Maximum allowable armor distance in the XOY plane
    max_armor_distance_ = this->declare_parameter("max_armor_distance", 10.0);

    // Tracker 参数
    double max_match_distance = this->declare_parameter("tracker.max_match_distance", 0.15);
    double max_match_yaw_diff = this->declare_parameter("tracker.max_match_yaw_diff", 1.0);
    tracker_ = std::make_unique<Tracker>(max_match_distance, max_match_yaw_diff);
    tracker_->tracking_thres = this->declare_parameter("tracker.tracking_thres", 5);
    lost_time_thres_ = this->declare_parameter("tracker.lost_time_thres", 0.3);

    // update_Q - process noise covariance matrix
    s2qxyz_max_ = declare_parameter("ekf.sigma2_q_xyz_max", 0.1);
    s2qxyz_min_ = declare_parameter("ekf.sigma2_q_xyz_min", 0.05);
    s2qyaw_max_ = declare_parameter("ekf.sigma2_q_yaw_max", 10.0);
    s2qyaw_min_ = declare_parameter("ekf.sigma2_q_yaw_min", 0.01);
    s2qr_ = declare_parameter("ekf.sigma2_q_r", 80.0);

    //! EKF 初始化函数部分

    //? 四个基础函数 f, j_f, h, J_h
    
    auto f = [this](const Eigen::VectorXd & x) {
        Eigen::VectorXd x_new = x;
        x_new(0) += x(1) * dt_;
        x_new(2) += x(3) * dt_;
        x_new(4) += x(5) * dt_;
        // yaw 的状态转移
        x_new(6) += x(7) * dt_ + 0.5 * x(8) * dt_ * dt_ ;
        x_new(7) += x(8) * dt_;
        x_new(8) = x(8);  // 加速度恒定 
        // r 的状态转移
        x_new(9) = x(9);

        return x_new;
    };

    auto j_f = [this](const Eigen::VectorXd &) {
        Eigen::MatrixXd f(10, 10);
        f.setIdentity();
        for (int i = 0; i < 3; ++i) {
            int base = 2 * i;
            f(base, base + 1) = dt_;
        }
        // yaw 的雅可比矩阵
        f(6, 7) = dt_;
        f(6, 8) = 0.5 * dt_ * dt_;
        f(7, 8) = dt_;
        // r 的雅可比矩阵
        f(9,9) = 1;
        return f;
    };

    auto h = [](const Eigen::VectorXd & x) {
        Eigen::VectorXd z(4);
        double xc = x(0), yc = x(2), yaw = x(6), r = x(9);
        z(0) = xc - r * cos(yaw);  // xa
        z(1) = yc - r * sin(yaw);  // ya
        z(2) = x(4);               // za
        z(3) = x(6);               // yaw
        return z;
    };

    auto j_h = [](const Eigen::VectorXd & x) {
        Eigen::MatrixXd h(4, 10);
        double yaw = x(6), r = x(9);
        // clang-format off
        //    xc   v_xc yc   v_yc za   v_za yaw          v_yaw  a_yaw    r
        h <<  1,   0,   0,   0,   0,   0,   r*sin(yaw),  0,    0,    -cos(yaw),
            0,   0,   1,   0,   0,   0,   -r*cos(yaw), 0,    0,    -sin(yaw),
            0,   0,   0,   0,   1,   0,   0,              0,    0,    0,
            0,   0,   0,   0,   0,   0,   1,              0,    0,    0;
        // clang-format on
        return h;
    };

    auto u_q = [this](const Eigen::VectorXd & innovation) {
        Eigen::MatrixXd q(10, 10);
        //* 创新向量 自适应参数
        // 提取平移部分 (xyz)
        Eigen::VectorXd innovation_xyz = innovation.segment(0, 6);  // 提取索引 [0, 1, 2, 3, 4, 5]
        // 提取旋转部分 (yaw)
        Eigen::VectorXd innovation_yaw = innovation.segment(6, 3);  // 提取索引 [6, 7, 8]

        // 计算平移和旋转的范数
        double norm_xyz = innovation_xyz.norm();
        double norm_yaw = innovation_yaw.norm();

        // 动态调整因子
        double adaptive_factor_xyz = std::min(1.0, std::max(0.1, norm_xyz / 10.0));
        double adaptive_factor_yaw = std::min(1.0, std::max(0.1, norm_yaw / 10.0));

        double x, y;
        
        x = adaptive_factor_xyz * (s2qxyz_max_ - s2qxyz_min_) + s2qxyz_min_;
        y = adaptive_factor_yaw * (s2qyaw_max_ - s2qyaw_min_) + s2qyaw_min_;

        double t = dt_, r = s2qr_;
        double q_x_x = pow(t, 4) / 4 * x, q_x_vx = pow(t, 3) / 2 * x, q_vx_vx = pow(t, 2) * x;
        // double q_y_y = pow(t, 4) / 4 * y, q_y_vy = pow(t, 3) / 2 * x, q_vy_vy = pow(t, 2) * y;
        double q_y_y = pow(t, 6) / 36.0 * y,q_y_vy = pow(t, 5) / 12.0 * y, q_y_ay = pow(t, 4) / 6.0 * y;
        double q_vy_vy = pow(t, 4) / 4 * y, q_vy_ay = pow(t, 3) / 2 * y;
        double q_ay_ay = pow(t, 2) * y;
        double q_r = pow(t, 4) / 4 * r;
        // clang-format off
        //    xc      v_xc    yc      v_yc    za      v_za    yaw     v_yaw    a_yaw    r
        q <<  q_x_x,  q_x_vx, 0,      0,      0,      0,      0,      0,       0,       0,
            q_x_vx, q_vx_vx,0,      0,      0,      0,      0,      0,       0,       0,
            0,      0,      q_x_x,  q_x_vx, 0,      0,      0,      0,       0,       0,
            0,      0,      q_x_vx, q_vx_vx,0,      0,      0,      0,       0,       0,
            0,      0,      0,      0,      q_x_x,  q_x_vx, 0,      0,       0,       0,
            0,      0,      0,      0,      q_x_vx, q_vx_vx,0,      0,       0,       0,
            0,      0,      0,      0,      0,      0,      q_y_y,  q_y_vy,  q_y_ay,  0,
            0,      0,      0,      0,      0,      0,      q_y_vy, q_vy_vy, q_vy_ay, 0,
            0,      0,      0,      0,      0,      0,      q_y_ay, q_vy_ay, q_ay_ay, 0,
            0,      0,      0,      0,      0,      0,      0,      0,       0,       q_r;
        // clang-format on
        return q;
    };

    // update_R - measurement noise covariance matrix
    r_xyz_factor = declare_parameter("ekf.r_xyz_factor", 0.05);
    r_yaw = declare_parameter("ekf.r_yaw", 0.02);
    auto u_r = [this](const Eigen::VectorXd & z) {
        Eigen::DiagonalMatrix<double, 4> r;
        double x = r_xyz_factor;
        r.diagonal() << abs(x * z[0]), abs(x * z[1]), abs(x * z[2]), r_yaw;
        return r;
    };

    // P - error estimate covariance matrix
    Eigen::DiagonalMatrix<double, 10> p0;
    p0.setIdentity();
    
    tracker_->ekf = ExtendedKalmanFilter{f, h, j_f, j_h, u_q, u_r, p0};

    //! 服务器设置
    // Reset tracker service
    using std::placeholders::_1;
    using std::placeholders::_2;
    using std::placeholders::_3;
    reset_tracker_srv_ = this->create_service<std_srvs::srv::Trigger>(
        "/tracker/reset", [this](
                            const std_srvs::srv::Trigger::Request::SharedPtr,
                            std_srvs::srv::Trigger::Response::SharedPtr response) {
        tracker_->tracker_state = Tracker::LOST; 
        response->success = true;
        RCLCPP_INFO(this->get_logger(), "Tracker reset!");
        return;
        });

    // Change target service
    change_target_srv_ = this->create_service<std_srvs::srv::Trigger>(
        "/tracker/change", [this](
                            const std_srvs::srv::Trigger::Request::SharedPtr,
                            std_srvs::srv::Trigger::Response::SharedPtr response) {
        tracker_->tracker_state = Tracker::CHANGE_TARGET;
        response->success = true;
        RCLCPP_INFO(this->get_logger(), "Target change!");
        return;
        });

    //! 坐标转换设置
    // Subscriber with tf2 message_filter
    // tf2 relevant
    tf2_buffer_ = std::make_shared<tf2_ros::Buffer>(this->get_clock());
    // Create the timer interface before call to waitForTransform,
    // to avoid a tf2_ros::CreateTimerInterfaceException exception
    auto timer_interface = std::make_shared<tf2_ros::CreateTimerROS>(
        this->get_node_base_interface(), this->get_node_timers_interface());
    tf2_buffer_->setCreateTimerInterface(timer_interface);
    tf2_listener_ = std::make_shared<tf2_ros::TransformListener>(*tf2_buffer_);

    //! Receive
    
    // 
    detctor_sub_= this->create_subscription<auto_aim_interfaces::msg::AllLatency>(
        "/detector/Latency", rclcpp::QoS(rclcpp::QoSInitialization::from_rmw(rmw_qos_profile_sensor_data)),
        std::bind(&ArmorTrackerNode::latencyCallback, this, std::placeholders::_1));

    // subscriber and filter
    armors_sub_.subscribe(this, "/detector/armors", rmw_qos_profile_sensor_data);
    target_frame_ = this->declare_parameter("target_frame", "odom");
    tf2_filter_ = std::make_shared<tf2_filter>(
        armors_sub_, *tf2_buffer_, target_frame_, 10, this->get_node_logging_interface(),
        this->get_node_clock_interface(), std::chrono::duration<int>(1));
    // Register a callback with tf2_ros::MessageFilter to be called when transforms are available
    tf2_filter_->registerCallback(&ArmorTrackerNode::armorsCallback, this);

    //! Publisher
    target_pub_ = this->create_publisher<auto_aim_interfaces::msg::Target>(
        "/tracker/target", rclcpp::SensorDataQoS());

    tracker_latency_pub_ = this->create_publisher<auto_aim_interfaces::msg::AllLatency>(
        "/tracker/latency", rclcpp::SensorDataQoS());

    info_pub_ = this->create_publisher<auto_aim_interfaces::msg::TrackerInfo>(
        "/tracker/info", 10);

    
    // Visualization Marker Publisher
    // See http://wiki.ros.org/rviz/DisplayTypes/Marker
    position_marker_.ns = "position";
    position_marker_.type = visualization_msgs::msg::Marker::SPHERE;
    position_marker_.scale.x = position_marker_.scale.y = position_marker_.scale.z = 0.1;
    position_marker_.color.a = 1.0;
    position_marker_.color.g = 1.0;
    linear_v_marker_.type = visualization_msgs::msg::Marker::ARROW;
    linear_v_marker_.ns = "linear_v";
    linear_v_marker_.scale.x = 0.03;
    linear_v_marker_.scale.y = 0.05;
    linear_v_marker_.color.a = 1.0;
    linear_v_marker_.color.r = 1.0;
    linear_v_marker_.color.g = 1.0;
    angular_v_marker_.type = visualization_msgs::msg::Marker::ARROW;
    angular_v_marker_.ns = "angular_v";
    angular_v_marker_.scale.x = 0.03;
    angular_v_marker_.scale.y = 0.05;
    angular_v_marker_.color.a = 1.0;
    angular_v_marker_.color.b = 1.0;
    angular_v_marker_.color.g = 1.0;
    armor_marker_.ns = "armors";
    armor_marker_.type = visualization_msgs::msg::Marker::CUBE;
    armor_marker_.scale.x = 0.03;
    armor_marker_.scale.z = 0.125;
    armor_marker_.color.a = 1.0;
    armor_marker_.color.r = 1.0;

    trackered_armor_marker_.ns = "trackered_armor";
    trackered_armor_marker_.type = visualization_msgs::msg::Marker::CUBE;
    trackered_armor_marker_.scale.x = 0.03;
    trackered_armor_marker_.scale.z = 0.125;
    trackered_armor_marker_.color.a = 1.0;
    trackered_armor_marker_.color.g = 1.0;

    aiming_point_.ns = "aiming_point";
    aiming_point_.type = visualization_msgs::msg::Marker::SPHERE;
    aiming_point_.scale.x = aiming_point_.scale.y = aiming_point_.scale.z = 0.12;
    aiming_point_.color.r = 1.0;
    aiming_point_.color.g = 1.0;
    aiming_point_.color.b = 1.0;
    aiming_point_.color.a = 1.0;
    // aiming_point_.lifetime = rclcpp::Duration::from_seconds(0.1);

    marker_pub_ = this->create_publisher<visualization_msgs::msg::MarkerArray>("/tracker/marker", 10);
}

//! armorsCallback

//! Makers

}  // namespace rm_auto_aim

#include "rclcpp_components/register_node_macro.hpp"

// Register the component with class_loader.
// This acts as a sort of entry point, allowing the component to be discoverable when its library
// is being loaded into a running process.
RCLCPP_COMPONENTS_REGISTER_NODE(rm_auto_aim::ArmorTrackerNode)