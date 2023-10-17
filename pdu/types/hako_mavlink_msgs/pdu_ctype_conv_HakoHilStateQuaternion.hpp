#ifndef _PDU_CTYPE_CONV_HAKO_hako_mavlink_msgs_HakoHilStateQuaternion_HPP_
#define _PDU_CTYPE_CONV_HAKO_hako_mavlink_msgs_HakoHilStateQuaternion_HPP_

#include "pdu_primitive_ctypes.h"
#include "ros_primitive_types.hpp"
#include "pdu_primitive_ctypes_conv.hpp"
/*
 * Dependent pdu data
 */
#include "hako_mavlink_msgs/pdu_ctype_HakoHilStateQuaternion.h"
/*
 * Dependent ros data
 */
#include "hako_mavlink_msgs/msg/hako_hil_state_quaternion.hpp"

/*
 * Dependent Convertors
 */

/***************************
 *
 * PDU ==> ROS2
 *
 ***************************/
static inline int hako_convert_pdu2ros_HakoHilStateQuaternion(Hako_HakoHilStateQuaternion &src,  hako_mavlink_msgs::msg::HakoHilStateQuaternion &dst)
{
    //primitive convert
    hako_convert_pdu2ros(src.time_usec, dst.time_usec);
    //primitive array convertor
    (void)hako_convert_pdu2ros_array(
        src.attitude_quaternion, M_ARRAY_SIZE(Hako_HakoHilStateQuaternion, Hako_float32, attitude_quaternion),
        dst.attitude_quaternion, dst.attitude_quaternion.size());
    //primitive convert
    hako_convert_pdu2ros(src.rollspeed, dst.rollspeed);
    //primitive convert
    hako_convert_pdu2ros(src.pitchspeed, dst.pitchspeed);
    //primitive convert
    hako_convert_pdu2ros(src.yawspeed, dst.yawspeed);
    //primitive convert
    hako_convert_pdu2ros(src.lat, dst.lat);
    //primitive convert
    hako_convert_pdu2ros(src.lon, dst.lon);
    //primitive convert
    hako_convert_pdu2ros(src.alt, dst.alt);
    //primitive convert
    hako_convert_pdu2ros(src.vx, dst.vx);
    //primitive convert
    hako_convert_pdu2ros(src.vy, dst.vy);
    //primitive convert
    hako_convert_pdu2ros(src.vz, dst.vz);
    //primitive convert
    hako_convert_pdu2ros(src.ind_airspeed, dst.ind_airspeed);
    //primitive convert
    hako_convert_pdu2ros(src.true_airspeed, dst.true_airspeed);
    //primitive convert
    hako_convert_pdu2ros(src.xacc, dst.xacc);
    //primitive convert
    hako_convert_pdu2ros(src.yacc, dst.yacc);
    //primitive convert
    hako_convert_pdu2ros(src.zacc, dst.zacc);
    return 0;
}

template<int _src_len, int _dst_len>
int hako_convert_pdu2ros_array_HakoHilStateQuaternion(Hako_HakoHilStateQuaternion src[], std::array<hako_mavlink_msgs::msg::HakoHilStateQuaternion, _dst_len> &dst)
{
    int ret = 0;
    int len = _dst_len;
    if (_dst_len > _src_len) {
        len = _src_len;
        ret = -1;
    }
    for (int i = 0; i < len; i++) {
        (void)hako_convert_pdu2ros_HakoHilStateQuaternion(src[i], dst[i]);
    }
    return ret;
}
template<int _src_len, int _dst_len>
int hako_convert_pdu2ros_array_HakoHilStateQuaternion(Hako_HakoHilStateQuaternion src[], std::vector<hako_mavlink_msgs::msg::HakoHilStateQuaternion> &dst)
{
    dst.resize(_src_len);
    for (int i = 0; i < _src_len; i++) {
        (void)hako_convert_pdu2ros_HakoHilStateQuaternion(src[i], dst[i]);
    }
    return 0;
}

/***************************
 *
 * ROS2 ==> PDU
 *
 ***************************/
static inline int hako_convert_ros2pdu_HakoHilStateQuaternion(hako_mavlink_msgs::msg::HakoHilStateQuaternion &src, Hako_HakoHilStateQuaternion &dst)
{
    //primitive convert
    hako_convert_ros2pdu(src.time_usec, dst.time_usec);
    //primitive array convertor
    (void)hako_convert_ros2pdu_array(
        src.attitude_quaternion, src.attitude_quaternion.size(),
        dst.attitude_quaternion, M_ARRAY_SIZE(Hako_HakoHilStateQuaternion, Hako_float32, attitude_quaternion));
    //primitive convert
    hako_convert_ros2pdu(src.rollspeed, dst.rollspeed);
    //primitive convert
    hako_convert_ros2pdu(src.pitchspeed, dst.pitchspeed);
    //primitive convert
    hako_convert_ros2pdu(src.yawspeed, dst.yawspeed);
    //primitive convert
    hako_convert_ros2pdu(src.lat, dst.lat);
    //primitive convert
    hako_convert_ros2pdu(src.lon, dst.lon);
    //primitive convert
    hako_convert_ros2pdu(src.alt, dst.alt);
    //primitive convert
    hako_convert_ros2pdu(src.vx, dst.vx);
    //primitive convert
    hako_convert_ros2pdu(src.vy, dst.vy);
    //primitive convert
    hako_convert_ros2pdu(src.vz, dst.vz);
    //primitive convert
    hako_convert_ros2pdu(src.ind_airspeed, dst.ind_airspeed);
    //primitive convert
    hako_convert_ros2pdu(src.true_airspeed, dst.true_airspeed);
    //primitive convert
    hako_convert_ros2pdu(src.xacc, dst.xacc);
    //primitive convert
    hako_convert_ros2pdu(src.yacc, dst.yacc);
    //primitive convert
    hako_convert_ros2pdu(src.zacc, dst.zacc);
    return 0;
}

template<int _src_len, int _dst_len>
int hako_convert_ros2pdu_array_HakoHilStateQuaternion(std::array<hako_mavlink_msgs::msg::HakoHilStateQuaternion, _src_len> &src, Hako_HakoHilStateQuaternion dst[])
{
    int ret = 0;
    int len = _dst_len;
    if (_dst_len > _src_len) {
        len = _src_len;
        ret = -1;
    }
    for (int i = 0; i < len; i++) {
        (void)hako_convert_ros2pdu_HakoHilStateQuaternion(src[i], dst[i]);
    }
    return ret;
}
template<int _src_len, int _dst_len>
int hako_convert_ros2pdu_array_HakoHilStateQuaternion(std::vector<hako_mavlink_msgs::msg::HakoHilStateQuaternion> &src, Hako_HakoHilStateQuaternion dst[])
{
    int ret = 0;
    int len = _dst_len;
    if (_dst_len > _src_len) {
        len = _src_len;
        ret = -1;
    }
    for (int i = 0; i < len; i++) {
        (void)hako_convert_ros2pdu_HakoHilStateQuaternion(src[i], dst[i]);
    }
    return ret;
}

#endif /* _PDU_CTYPE_CONV_HAKO_hako_mavlink_msgs_HakoHilStateQuaternion_HPP_ */
