#include <stdio.h>

#include "can_msgs/msg/hako_can.hpp"
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

using namespace std::chrono_literals;

int main(int argc, char **argv) {

  rclcpp::init(argc, argv);

  auto node = rclcpp::Node::make_shared("can_proxy_node");

  rclcpp::WallRate rate(5ms);

  rclcpp::shutdown();
  return 0;
}
