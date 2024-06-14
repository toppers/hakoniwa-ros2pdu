#ifndef _CAN_PROXY_COM_ROS2_HPP_
#define _CAN_PROXY_COM_ROS2_HPP_

#include "rclcpp/rclcpp.hpp"

extern void hako_pdu_proxy_com_pub_init(std::shared_ptr<rclcpp::Node> node);
extern void hako_pdu_proxy_com_sub_init(std::shared_ptr<rclcpp::Node> node);

#define DECLARE_PUBLISHER(type, topic_name) \
    static std::shared_ptr<rclcpp::Publisher<type>> publisher_ ##topic_name

#define PUBLISH_TOPIC(topic_name, msg)   \
do {    \
        PUBLISHER(topic_name)->publish(msg);    \
} while (0)

#define DECLARE_SUBSCRIBER(type, topic_name) \
    static std::shared_ptr<rclcpp::Subscription<type>> subscriber_ ##topic_name

#define DEFINE_SUB_CALLBACK(pkg, ros_type, robo_name, channel_id, topic_name) \
static void SUB_CALLBACK_NAME(topic_name)(const pkg::msg::ros_type::SharedPtr ros_msg) \
{   \
    Hako_ ##ros_type *pdu_msg;   \
    int total_size = hako_convert_ros2pdu_ ##ros_type (*ros_msg, &pdu_msg); \
    hako_pdu_proxy_tx_data(robo_name, (channel_id), (char*)pdu_msg, total_size);    \
    hako_destroy_pdu(pdu_msg); \
}

#define ROS_NODE_TYPE std::shared_ptr<rclcpp::Node>

using namespace std::chrono_literals;


static inline ROS_NODE_TYPE hako_pdu_proxy_ros_init(int argc, char** argv, const char* node_name)
{
    rclcpp::init(argc, argv);
    return rclcpp::Node::make_shared(node_name);
}
#define HAKO_PDU_PROXY_ROS_WALL_RATE(var, rate) do { ¥
    rclcpp::WallRate var(rate); ¥
} while (0)

#define HAKO_PDU_PROXY_ROS_WALL_RATE_sleep(var) do { ¥
    var.sleep();
} while (0)

static inline bool hako_pdu_proxy_ros_ok()
{
    return rclcpp::ok();
}

static inline void hako_pdu_proxy_ros_shutdown()
{
    rclcpp::shutdown();
}

static inline void hako_pdu_proxy_ros_spin(ROS_NODE_TYPE node)
{
    rclcpp::spin_some(node);
}

#endif /* _CAN_PROXY_COM_ROS2_HPP_ */