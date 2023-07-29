#include "../hako_pdu_proxy_com.hpp"
#include "../hako_pdu_proxy_libs.hpp"
#include "sensor_msgs/pdu_ctype_conv_JointState.hpp"
#include "sensor_msgs/pdu_ctype_conv_CompressedImage.hpp"
#include "sensor_msgs/pdu_ctype_conv_LaserScan.hpp"

static std::shared_ptr<rclcpp::Node> my_node;
DECLARE_PUBLISHER(sensor_msgs::msg::JointState, TB3RoboModel_joint);
DECLARE_PUBLISHER(sensor_msgs::msg::CompressedImage, TB3RoboModel_image_comressed);
DECLARE_PUBLISHER(sensor_msgs::msg::LaserScan, TB3RoboModel_scan);

void hako_pdu_proxy_com_pub_init(std::shared_ptr<rclcpp::Node> node)
{
    my_node = node;
    CREATE_PUBLISHER(sensor_msgs, JointState, "TB3RoboModel", 6, TB3RoboModel_joint);
    CREATE_PUBLISHER(sensor_msgs, CompressedImage, "TB3RoboModel", 7, TB3RoboModel_image_comressed);
    CREATE_PUBLISHER(sensor_msgs, LaserScan, "TB3RoboModel", 8, TB3RoboModel_scan);

    return;
}

void hako_pdu_proxy_com_publish(void)
{
    PUBLISH_PDU_TOPIC(sensor_msgs, JointState, "TB3RoboModel", 6, TB3RoboModel_joint);
    PUBLISH_PDU_TOPIC(sensor_msgs, CompressedImage, "TB3RoboModel", 7, TB3RoboModel_image_comressed);
    PUBLISH_PDU_TOPIC(sensor_msgs, LaserScan, "TB3RoboModel", 8, TB3RoboModel_scan);
    return;
}
