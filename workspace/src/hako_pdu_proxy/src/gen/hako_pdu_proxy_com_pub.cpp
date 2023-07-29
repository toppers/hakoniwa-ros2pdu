#include "../hako_pdu_proxy_com.hpp"
#include "../hako_pdu_proxy_libs.hpp"
#include "sensor_msgs/pdu_ctype_conv_JointState.hpp"
#include "sensor_msgs/pdu_ctype_conv_Imu.hpp"
#include "nav_msgs/pdu_ctype_conv_Odometry.hpp"
#include "tf2_msgs/pdu_ctype_conv_TFMessage.hpp"
#include "sensor_msgs/pdu_ctype_conv_Image.hpp"
#include "sensor_msgs/pdu_ctype_conv_CompressedImage.hpp"
#include "sensor_msgs/pdu_ctype_conv_CameraInfo.hpp"
#include "sensor_msgs/pdu_ctype_conv_LaserScan.hpp"

static std::shared_ptr<rclcpp::Node> my_node;
DECLARE_PUBLISHER(sensor_msgs::msg::JointState, TB3RoboModel_joint_states);
DECLARE_PUBLISHER(sensor_msgs::msg::Imu, TB3RoboModel_imu);
DECLARE_PUBLISHER(nav_msgs::msg::Odometry, TB3RoboModel_odom);
DECLARE_PUBLISHER(tf2_msgs::msg::TFMessage, TB3RoboModel_tf);
DECLARE_PUBLISHER(sensor_msgs::msg::Image, TB3RoboModel_image);
DECLARE_PUBLISHER(sensor_msgs::msg::CompressedImage, TB3RoboModel_image_compressed);
DECLARE_PUBLISHER(sensor_msgs::msg::CameraInfo, TB3RoboModel_camera_info);
DECLARE_PUBLISHER(sensor_msgs::msg::LaserScan, TB3RoboModel_scan);

void hako_pdu_proxy_com_pub_init(std::shared_ptr<rclcpp::Node> node)
{
    my_node = node;
    CREATE_PUBLISHER(sensor_msgs, JointState, "TB3RoboModel", 1, TB3RoboModel_joint_states);
    CREATE_PUBLISHER(sensor_msgs, Imu, "TB3RoboModel", 2, TB3RoboModel_imu);
    CREATE_PUBLISHER(nav_msgs, Odometry, "TB3RoboModel", 3, TB3RoboModel_odom);
    CREATE_PUBLISHER(tf2_msgs, TFMessage, "TB3RoboModel", 4, TB3RoboModel_tf);
    CREATE_PUBLISHER(sensor_msgs, Image, "TB3RoboModel", 5, TB3RoboModel_image);
    CREATE_PUBLISHER(sensor_msgs, CompressedImage, "TB3RoboModel", 6, TB3RoboModel_image_compressed);
    CREATE_PUBLISHER(sensor_msgs, CameraInfo, "TB3RoboModel", 7, TB3RoboModel_camera_info);
    CREATE_PUBLISHER(sensor_msgs, LaserScan, "TB3RoboModel", 8, TB3RoboModel_scan);

    return;
}

void hako_pdu_proxy_com_publish(void)
{
    PUBLISH_PDU_TOPIC(sensor_msgs, JointState, "TB3RoboModel", 1, TB3RoboModel_joint_states);
    PUBLISH_PDU_TOPIC(sensor_msgs, Imu, "TB3RoboModel", 2, TB3RoboModel_imu);
    PUBLISH_PDU_TOPIC(nav_msgs, Odometry, "TB3RoboModel", 3, TB3RoboModel_odom);
    PUBLISH_PDU_TOPIC(tf2_msgs, TFMessage, "TB3RoboModel", 4, TB3RoboModel_tf);
    PUBLISH_PDU_TOPIC(sensor_msgs, Image, "TB3RoboModel", 5, TB3RoboModel_image);
    PUBLISH_PDU_TOPIC(sensor_msgs, CompressedImage, "TB3RoboModel", 6, TB3RoboModel_image_compressed);
    PUBLISH_PDU_TOPIC(sensor_msgs, CameraInfo, "TB3RoboModel", 7, TB3RoboModel_camera_info);
    PUBLISH_PDU_TOPIC(sensor_msgs, LaserScan, "TB3RoboModel", 8, TB3RoboModel_scan);
    return;
}
