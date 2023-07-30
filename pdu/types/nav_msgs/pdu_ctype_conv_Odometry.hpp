#ifndef _PDU_CTYPE_CONV_HAKO_nav_msgs_Odometry_HPP_
#define _PDU_CTYPE_CONV_HAKO_nav_msgs_Odometry_HPP_

#include "pdu_primitive_ctypes.h"
#include "ros_primitive_types.hpp"
#include "pdu_primitive_ctypes_conv.hpp"
/*
 * Dependent pdu data
 */
#include "nav_msgs/pdu_ctype_Odometry.h"
/*
 * Dependent ros data
 */
#include "nav_msgs/msg/odometry.hpp"

/*
 * Dependent Convertors
 */
#include "builtin_interfaces/pdu_ctype_conv_Time.hpp"
#include "geometry_msgs/pdu_ctype_conv_Point.hpp"
#include "geometry_msgs/pdu_ctype_conv_Pose.hpp"
#include "geometry_msgs/pdu_ctype_conv_PoseWithCovariance.hpp"
#include "geometry_msgs/pdu_ctype_conv_Quaternion.hpp"
#include "geometry_msgs/pdu_ctype_conv_Twist.hpp"
#include "geometry_msgs/pdu_ctype_conv_TwistWithCovariance.hpp"
#include "geometry_msgs/pdu_ctype_conv_Vector3.hpp"
#include "std_msgs/pdu_ctype_conv_Header.hpp"

/***************************
 *
 * PDU ==> ROS2
 *
 ***************************/
static inline int hako_convert_pdu2ros_Odometry(Hako_Odometry &src,  nav_msgs::msg::Odometry &dst)
{
    //struct convert
    hako_convert_pdu2ros_Header(src.header, dst.header);
    //string convertor
    dst.child_frame_id = (const char*)src.child_frame_id;
    //struct convert
    hako_convert_pdu2ros_PoseWithCovariance(src.pose, dst.pose);
    //struct convert
    hako_convert_pdu2ros_TwistWithCovariance(src.twist, dst.twist);
    return 0;
}

template<int _src_len, int _dst_len>
int hako_convert_pdu2ros_array_Odometry(Hako_Odometry src[], std::array<nav_msgs::msg::Odometry, _dst_len> &dst)
{
    int ret = 0;
    int len = _dst_len;
    if (_dst_len > _src_len) {
        len = _src_len;
        ret = -1;
    }
    for (int i = 0; i < len; i++) {
        (void)hako_convert_pdu2ros_Odometry(src[i], dst[i]);
    }
    return ret;
}
template<int _src_len, int _dst_len>
int hako_convert_pdu2ros_array_Odometry(Hako_Odometry src[], std::vector<nav_msgs::msg::Odometry> &dst)
{
    dst.resize(_src_len);
    for (int i = 0; i < _src_len; i++) {
        (void)hako_convert_pdu2ros_Odometry(src[i], dst[i]);
    }
    return 0;
}

/***************************
 *
 * ROS2 ==> PDU
 *
 ***************************/
static inline int hako_convert_ros2pdu_Odometry(nav_msgs::msg::Odometry &src, Hako_Odometry &dst)
{
    //struct convert
    hako_convert_ros2pdu_Header(src.header, dst.header);
    //string convertor
    (void)hako_convert_ros2pdu_array(
        src.child_frame_id, src.child_frame_id.length(),
        dst.child_frame_id, M_ARRAY_SIZE(Hako_Odometry, char, child_frame_id));
    //struct convert
    hako_convert_ros2pdu_PoseWithCovariance(src.pose, dst.pose);
    //struct convert
    hako_convert_ros2pdu_TwistWithCovariance(src.twist, dst.twist);
    return 0;
}

template<int _src_len, int _dst_len>
int hako_convert_ros2pdu_array_Odometry(std::array<nav_msgs::msg::Odometry, _src_len> &src, Hako_Odometry dst[])
{
    int ret = 0;
    int len = _dst_len;
    if (_dst_len > _src_len) {
        len = _src_len;
        ret = -1;
    }
    for (int i = 0; i < len; i++) {
        (void)hako_convert_ros2pdu_Odometry(src[i], dst[i]);
    }
    return ret;
}
template<int _src_len, int _dst_len>
int hako_convert_ros2pdu_array_Odometry(std::vector<nav_msgs::msg::Odometry> &src, Hako_Odometry dst[])
{
    int ret = 0;
    int len = _dst_len;
    if (_dst_len > _src_len) {
        len = _src_len;
        ret = -1;
    }
    for (int i = 0; i < len; i++) {
        (void)hako_convert_ros2pdu_Odometry(src[i], dst[i]);
    }
    return ret;
}

#endif /* _PDU_CTYPE_CONV_HAKO_nav_msgs_Odometry_HPP_ */
