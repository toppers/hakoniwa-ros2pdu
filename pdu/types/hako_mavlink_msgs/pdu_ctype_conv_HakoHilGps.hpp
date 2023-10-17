#ifndef _PDU_CTYPE_CONV_HAKO_hako_mavlink_msgs_HakoHilGps_HPP_
#define _PDU_CTYPE_CONV_HAKO_hako_mavlink_msgs_HakoHilGps_HPP_

#include "pdu_primitive_ctypes.h"
#include "ros_primitive_types.hpp"
#include "pdu_primitive_ctypes_conv.hpp"
/*
 * Dependent pdu data
 */
#include "hako_mavlink_msgs/pdu_ctype_HakoHilGps.h"
/*
 * Dependent ros data
 */
#include "hako_mavlink_msgs/msg/hako_hil_gps.hpp"

/*
 * Dependent Convertors
 */

/***************************
 *
 * PDU ==> ROS2
 *
 ***************************/
static inline int hako_convert_pdu2ros_HakoHilGps(Hako_HakoHilGps &src,  hako_mavlink_msgs::msg::HakoHilGps &dst)
{
    //primitive convert
    hako_convert_pdu2ros(src.time_usec, dst.time_usec);
    //primitive convert
    hako_convert_pdu2ros(src.lat, dst.lat);
    //primitive convert
    hako_convert_pdu2ros(src.lon, dst.lon);
    //primitive convert
    hako_convert_pdu2ros(src.alt, dst.alt);
    //primitive convert
    hako_convert_pdu2ros(src.eph, dst.eph);
    //primitive convert
    hako_convert_pdu2ros(src.epv, dst.epv);
    //primitive convert
    hako_convert_pdu2ros(src.vel, dst.vel);
    //primitive convert
    hako_convert_pdu2ros(src.vn, dst.vn);
    //primitive convert
    hako_convert_pdu2ros(src.ve, dst.ve);
    //primitive convert
    hako_convert_pdu2ros(src.vd, dst.vd);
    //primitive convert
    hako_convert_pdu2ros(src.cog, dst.cog);
    //primitive convert
    hako_convert_pdu2ros(src.satelites_visible, dst.satelites_visible);
    //primitive convert
    hako_convert_pdu2ros(src.id, dst.id);
    //primitive convert
    hako_convert_pdu2ros(src.yaw, dst.yaw);
    //primitive convert
    hako_convert_pdu2ros(src.fix_type, dst.fix_type);
    return 0;
}

template<int _src_len, int _dst_len>
int hako_convert_pdu2ros_array_HakoHilGps(Hako_HakoHilGps src[], std::array<hako_mavlink_msgs::msg::HakoHilGps, _dst_len> &dst)
{
    int ret = 0;
    int len = _dst_len;
    if (_dst_len > _src_len) {
        len = _src_len;
        ret = -1;
    }
    for (int i = 0; i < len; i++) {
        (void)hako_convert_pdu2ros_HakoHilGps(src[i], dst[i]);
    }
    return ret;
}
template<int _src_len, int _dst_len>
int hako_convert_pdu2ros_array_HakoHilGps(Hako_HakoHilGps src[], std::vector<hako_mavlink_msgs::msg::HakoHilGps> &dst)
{
    dst.resize(_src_len);
    for (int i = 0; i < _src_len; i++) {
        (void)hako_convert_pdu2ros_HakoHilGps(src[i], dst[i]);
    }
    return 0;
}

/***************************
 *
 * ROS2 ==> PDU
 *
 ***************************/
static inline int hako_convert_ros2pdu_HakoHilGps(hako_mavlink_msgs::msg::HakoHilGps &src, Hako_HakoHilGps &dst)
{
    //primitive convert
    hako_convert_ros2pdu(src.time_usec, dst.time_usec);
    //primitive convert
    hako_convert_ros2pdu(src.lat, dst.lat);
    //primitive convert
    hako_convert_ros2pdu(src.lon, dst.lon);
    //primitive convert
    hako_convert_ros2pdu(src.alt, dst.alt);
    //primitive convert
    hako_convert_ros2pdu(src.eph, dst.eph);
    //primitive convert
    hako_convert_ros2pdu(src.epv, dst.epv);
    //primitive convert
    hako_convert_ros2pdu(src.vel, dst.vel);
    //primitive convert
    hako_convert_ros2pdu(src.vn, dst.vn);
    //primitive convert
    hako_convert_ros2pdu(src.ve, dst.ve);
    //primitive convert
    hako_convert_ros2pdu(src.vd, dst.vd);
    //primitive convert
    hako_convert_ros2pdu(src.cog, dst.cog);
    //primitive convert
    hako_convert_ros2pdu(src.satelites_visible, dst.satelites_visible);
    //primitive convert
    hako_convert_ros2pdu(src.id, dst.id);
    //primitive convert
    hako_convert_ros2pdu(src.yaw, dst.yaw);
    //primitive convert
    hako_convert_ros2pdu(src.fix_type, dst.fix_type);
    return 0;
}

template<int _src_len, int _dst_len>
int hako_convert_ros2pdu_array_HakoHilGps(std::array<hako_mavlink_msgs::msg::HakoHilGps, _src_len> &src, Hako_HakoHilGps dst[])
{
    int ret = 0;
    int len = _dst_len;
    if (_dst_len > _src_len) {
        len = _src_len;
        ret = -1;
    }
    for (int i = 0; i < len; i++) {
        (void)hako_convert_ros2pdu_HakoHilGps(src[i], dst[i]);
    }
    return ret;
}
template<int _src_len, int _dst_len>
int hako_convert_ros2pdu_array_HakoHilGps(std::vector<hako_mavlink_msgs::msg::HakoHilGps> &src, Hako_HakoHilGps dst[])
{
    int ret = 0;
    int len = _dst_len;
    if (_dst_len > _src_len) {
        len = _src_len;
        ret = -1;
    }
    for (int i = 0; i < len; i++) {
        (void)hako_convert_ros2pdu_HakoHilGps(src[i], dst[i]);
    }
    return ret;
}

#endif /* _PDU_CTYPE_CONV_HAKO_hako_mavlink_msgs_HakoHilGps_HPP_ */
