#include <rclcpp/rclcpp.hpp>
#include <dbot_control_lib/robot_lib.hpp>

using namespace dbot_control_lib;

int main(int argc, char** argv)
{
    // Init Node
    rclcpp::init(argc, argv);
    std::string node_name{"dbot_control_node"};
    rclcpp::NodeOptions node_options;
    node_options.automatically_declare_parameters_from_overrides(true);
    std::shared_ptr<rclcpp::Node> dbot_control_node = rclcpp::Node::make_shared(node_name, node_options);
    rclcpp::Logger logger = rclcpp::get_logger(node_name);

    // Set
    RCLCPP_INFO(logger, "DBOT CONTROL NODE. . .");
    DbotControl d;
    auto s = d.debug();
    RCLCPP_INFO(logger, s.c_str());
    RCLCPP_INFO(logger, d.to_string().c_str());

    // Test dbot robot
    RCLCPP_INFO(logger, "DBOT ROBOT BUILD TEST. . .");
    RobotBuilder rb;
    Robot dbot = rb.build_dbot_robot();
    RCLCPP_INFO(logger, dbot.to_string().c_str());

    // Spin
    rclcpp::executors::SingleThreadedExecutor executor;
    executor.add_node(dbot_control_node);
    executor.spin();

    // Cleanup
    rclcpp::shutdown();
    return 0;
}