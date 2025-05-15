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







}

//! armorsCallback

//! Makers

}  // namespace rm_auto_aim

#include "rclcpp_components/register_node_macro.hpp"

// Register the component with class_loader.
// This acts as a sort of entry point, allowing the component to be discoverable when its library
// is being loaded into a running process.
RCLCPP_COMPONENTS_REGISTER_NODE(rm_auto_aim::ArmorTrackerNode)