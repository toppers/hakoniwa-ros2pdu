#ifndef _PDU_CTYPE_CONV_HAKO_sensor_msgs_LaserScan_HPP_
#define _PDU_CTYPE_CONV_HAKO_sensor_msgs_LaserScan_HPP_

#include "pdu_primitive_ctypes.h"
#include "ros_primitive_types.hpp"
#include "pdu_primitive_ctypes_conv.hpp"
/*
 * Dependent pdu data
 */
#include "sensor_msgs/pdu_ctype_LaserScan.h"
/*
 * Dependent ros data
 */
#include "sensor_msgs/msg/laser_scan.hpp"

/*
 * Dependent Convertors
 */
#include "builtin_interfaces/pdu_ctype_conv_Time.hpp"
#include "std_msgs/pdu_ctype_conv_Header.hpp"

/***************************
 *
 * PDU ==> ROS2
 *
 ***************************/
static inline int hako_convert_pdu2ros_LaserScan(Hako_LaserScan &src,  sensor_msgs::msg::LaserScan &dst)
{
    //struct convert
    hako_convert_pdu2ros_Header(src.header, dst.header);
    //primitive convert
    hako_convert_pdu2ros(src.angle_min, dst.angle_min);
    //primitive convert
    hako_convert_pdu2ros(src.angle_max, dst.angle_max);
    //primitive convert
    hako_convert_pdu2ros(src.angle_increment, dst.angle_increment);
    //primitive convert
    hako_convert_pdu2ros(src.time_increment, dst.time_increment);
    //primitive convert
    hako_convert_pdu2ros(src.scan_time, dst.scan_time);
    //primitive convert
    hako_convert_pdu2ros(src.range_min, dst.range_min);
    //primitive convert
    hako_convert_pdu2ros(src.range_max, dst.range_max);
    //primitive array convertor
    (void)hako_convert_pdu2ros_array(
        src.ranges, M_ARRAY_SIZE(Hako_LaserScan, Hako_float32, ranges),
        dst.ranges, dst.ranges.size());
    //primitive array convertor
    (void)hako_convert_pdu2ros_array(
        src.intensities, M_ARRAY_SIZE(Hako_LaserScan, Hako_float32, intensities),
        dst.intensities, dst.intensities.size());
    return 0;
}

template<int _src_len, int _dst_len>
int hako_convert_pdu2ros_array_LaserScan(Hako_LaserScan src[], std::array<sensor_msgs::msg::LaserScan, _dst_len> &dst)
{
    int ret = 0;
    int len = _dst_len;
    if (_dst_len > _src_len) {
        len = _src_len;
        ret = -1;
    }
    for (int i = 0; i < len; i++) {
        (void)hako_convert_pdu2ros_LaserScan(src[i], dst[i]);
    }
    return ret;
}
template<int _src_len, int _dst_len>
int hako_convert_pdu2ros_array_LaserScan(Hako_LaserScan src[], std::vector<sensor_msgs::msg::LaserScan> &dst)
{
    dst.resize(_src_len);
    for (int i = 0; i < _src_len; i++) {
        (void)hako_convert_pdu2ros_LaserScan(src[i], dst[i]);
    }
    return 0;
}

/***************************
 *
 * ROS2 ==> PDU
 *
 ***************************/
static inline int hako_convert_ros2pdu_LaserScan(sensor_msgs::msg::LaserScan &src, Hako_LaserScan &dst)
{
    //struct convert
    hako_convert_ros2pdu_Header(src.header, dst.header);
    //primitive convert
    hako_convert_ros2pdu(src.angle_min, dst.angle_min);
    //primitive convert
    hako_convert_ros2pdu(src.angle_max, dst.angle_max);
    //primitive convert
    hako_convert_ros2pdu(src.angle_increment, dst.angle_increment);
    //primitive convert
    hako_convert_ros2pdu(src.time_increment, dst.time_increment);
    //primitive convert
    hako_convert_ros2pdu(src.scan_time, dst.scan_time);
    //primitive convert
    hako_convert_ros2pdu(src.range_min, dst.range_min);
    //primitive convert
    hako_convert_ros2pdu(src.range_max, dst.range_max);
    //primitive array convertor
    (void)hako_convert_ros2pdu_array(
        src.ranges, src.ranges.size(),
        dst.ranges, M_ARRAY_SIZE(Hako_LaserScan, Hako_float32, ranges));
    //primitive array convertor
    (void)hako_convert_ros2pdu_array(
        src.intensities, src.intensities.size(),
        dst.intensities, M_ARRAY_SIZE(Hako_LaserScan, Hako_float32, intensities));
    return 0;
}

template<int _src_len, int _dst_len>
int hako_convert_ros2pdu_array_LaserScan(std::array<sensor_msgs::msg::LaserScan, _src_len> &src, Hako_LaserScan dst[])
{
    int ret = 0;
    int len = _dst_len;
    if (_dst_len > _src_len) {
        len = _src_len;
        ret = -1;
    }
    for (int i = 0; i < len; i++) {
        (void)hako_convert_ros2pdu_LaserScan(src[i], dst[i]);
    }
    return ret;
}
template<int _src_len, int _dst_len>
int hako_convert_ros2pdu_array_LaserScan(std::vector<sensor_msgs::msg::LaserScan> &src, Hako_LaserScan dst[])
{
    int ret = 0;
    int len = _dst_len;
    if (_dst_len > _src_len) {
        len = _src_len;
        ret = -1;
    }
    for (int i = 0; i < len; i++) {
        (void)hako_convert_ros2pdu_LaserScan(src[i], dst[i]);
    }
    return ret;
}

#endif /* _PDU_CTYPE_CONV_HAKO_sensor_msgs_LaserScan_HPP_ */
