#ifndef _PDU_CTYPE_CONV_HAKO_hako_mavlink_msgs_HakoHilSensor_HPP_
#define _PDU_CTYPE_CONV_HAKO_hako_mavlink_msgs_HakoHilSensor_HPP_

#include "pdu_primitive_ctypes.h"
#include "ros_primitive_types.hpp"
#include "pdu_primitive_ctypes_conv.hpp"
/*
 * Dependent pdu data
 */
#include "hako_mavlink_msgs/pdu_ctype_HakoHilSensor.h"
/*
 * Dependent ros data
 */
#include "hako_mavlink_msgs/msg/hako_hil_sensor.hpp"

/*
 * Dependent Convertors
 */

/***************************
 *
 * PDU ==> ROS2
 *
 ***************************/
static inline int hako_convert_pdu2ros_HakoHilSensor(Hako_HakoHilSensor &src,  hako_mavlink_msgs::msg::HakoHilSensor &dst)
{
    //primitive convert
    hako_convert_pdu2ros(src.time_usec, dst.time_usec);
    //primitive convert
    hako_convert_pdu2ros(src.xacc, dst.xacc);
    //primitive convert
    hako_convert_pdu2ros(src.yacc, dst.yacc);
    //primitive convert
    hako_convert_pdu2ros(src.zacc, dst.zacc);
    //primitive convert
    hako_convert_pdu2ros(src.xgyro, dst.xgyro);
    //primitive convert
    hako_convert_pdu2ros(src.ygyro, dst.ygyro);
    //primitive convert
    hako_convert_pdu2ros(src.zgyro, dst.zgyro);
    //primitive convert
    hako_convert_pdu2ros(src.xmag, dst.xmag);
    //primitive convert
    hako_convert_pdu2ros(src.ymag, dst.ymag);
    //primitive convert
    hako_convert_pdu2ros(src.zmag, dst.zmag);
    //primitive convert
    hako_convert_pdu2ros(src.abs_pressure, dst.abs_pressure);
    //primitive convert
    hako_convert_pdu2ros(src.diff_pressure, dst.diff_pressure);
    //primitive convert
    hako_convert_pdu2ros(src.pressure_alt, dst.pressure_alt);
    //primitive convert
    hako_convert_pdu2ros(src.temperature, dst.temperature);
    //primitive convert
    hako_convert_pdu2ros(src.fields_updated, dst.fields_updated);
    //primitive convert
    hako_convert_pdu2ros(src.id, dst.id);
    return 0;
}

template<int _src_len, int _dst_len>
int hako_convert_pdu2ros_array_HakoHilSensor(Hako_HakoHilSensor src[], std::array<hako_mavlink_msgs::msg::HakoHilSensor, _dst_len> &dst)
{
    int ret = 0;
    int len = _dst_len;
    if (_dst_len > _src_len) {
        len = _src_len;
        ret = -1;
    }
    for (int i = 0; i < len; i++) {
        (void)hako_convert_pdu2ros_HakoHilSensor(src[i], dst[i]);
    }
    return ret;
}
template<int _src_len, int _dst_len>
int hako_convert_pdu2ros_array_HakoHilSensor(Hako_HakoHilSensor src[], std::vector<hako_mavlink_msgs::msg::HakoHilSensor> &dst)
{
    dst.resize(_src_len);
    for (int i = 0; i < _src_len; i++) {
        (void)hako_convert_pdu2ros_HakoHilSensor(src[i], dst[i]);
    }
    return 0;
}

/***************************
 *
 * ROS2 ==> PDU
 *
 ***************************/
static inline int hako_convert_ros2pdu_HakoHilSensor(hako_mavlink_msgs::msg::HakoHilSensor &src, Hako_HakoHilSensor &dst)
{
    //primitive convert
    hako_convert_ros2pdu(src.time_usec, dst.time_usec);
    //primitive convert
    hako_convert_ros2pdu(src.xacc, dst.xacc);
    //primitive convert
    hako_convert_ros2pdu(src.yacc, dst.yacc);
    //primitive convert
    hako_convert_ros2pdu(src.zacc, dst.zacc);
    //primitive convert
    hako_convert_ros2pdu(src.xgyro, dst.xgyro);
    //primitive convert
    hako_convert_ros2pdu(src.ygyro, dst.ygyro);
    //primitive convert
    hako_convert_ros2pdu(src.zgyro, dst.zgyro);
    //primitive convert
    hako_convert_ros2pdu(src.xmag, dst.xmag);
    //primitive convert
    hako_convert_ros2pdu(src.ymag, dst.ymag);
    //primitive convert
    hako_convert_ros2pdu(src.zmag, dst.zmag);
    //primitive convert
    hako_convert_ros2pdu(src.abs_pressure, dst.abs_pressure);
    //primitive convert
    hako_convert_ros2pdu(src.diff_pressure, dst.diff_pressure);
    //primitive convert
    hako_convert_ros2pdu(src.pressure_alt, dst.pressure_alt);
    //primitive convert
    hako_convert_ros2pdu(src.temperature, dst.temperature);
    //primitive convert
    hako_convert_ros2pdu(src.fields_updated, dst.fields_updated);
    //primitive convert
    hako_convert_ros2pdu(src.id, dst.id);
    return 0;
}

template<int _src_len, int _dst_len>
int hako_convert_ros2pdu_array_HakoHilSensor(std::array<hako_mavlink_msgs::msg::HakoHilSensor, _src_len> &src, Hako_HakoHilSensor dst[])
{
    int ret = 0;
    int len = _dst_len;
    if (_dst_len > _src_len) {
        len = _src_len;
        ret = -1;
    }
    for (int i = 0; i < len; i++) {
        (void)hako_convert_ros2pdu_HakoHilSensor(src[i], dst[i]);
    }
    return ret;
}
template<int _src_len, int _dst_len>
int hako_convert_ros2pdu_array_HakoHilSensor(std::vector<hako_mavlink_msgs::msg::HakoHilSensor> &src, Hako_HakoHilSensor dst[])
{
    int ret = 0;
    int len = _dst_len;
    if (_dst_len > _src_len) {
        len = _src_len;
        ret = -1;
    }
    for (int i = 0; i < len; i++) {
        (void)hako_convert_ros2pdu_HakoHilSensor(src[i], dst[i]);
    }
    return ret;
}

#endif /* _PDU_CTYPE_CONV_HAKO_hako_mavlink_msgs_HakoHilSensor_HPP_ */
