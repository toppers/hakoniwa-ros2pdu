#ifndef _PDU_CTYPE_CONV_HAKO_pico_msgs_PicoSensor_HPP_
#define _PDU_CTYPE_CONV_HAKO_pico_msgs_PicoSensor_HPP_

#include "pdu_primitive_ctypes.h"
#include "ros_primitive_types.hpp"
#include "pdu_primitive_ctypes_conv.hpp"
/*
 * Dependent pdu data
 */
#include "pico_msgs/pdu_ctype_PicoSensor.h"
/*
 * Dependent ros data
 */
#include "pico_msgs/msg/pico_sensor.hpp"

/*
 * Dependent Convertors
 */

/***************************
 *
 * PDU ==> ROS2
 *
 ***************************/
static inline int hako_convert_pdu2ros_PicoSensor(Hako_PicoSensor &src,  pico_msgs::msg::PicoSensor &dst)
{
    //primitive convert
    hako_convert_pdu2ros(src.detect_f, dst.detect_f);
    //primitive convert
    hako_convert_pdu2ros(src.detect_r, dst.detect_r);
    //primitive convert
    hako_convert_pdu2ros(src.detect_l, dst.detect_l);
    //primitive convert
    hako_convert_pdu2ros(src.detect_b, dst.detect_b);
    return 0;
}

template<int _src_len, int _dst_len>
int hako_convert_pdu2ros_array_PicoSensor(Hako_PicoSensor src[], std::array<pico_msgs::msg::PicoSensor, _dst_len> &dst)
{
    int ret = 0;
    int len = _dst_len;
    if (_dst_len > _src_len) {
        len = _src_len;
        ret = -1;
    }
    for (int i = 0; i < len; i++) {
        (void)hako_convert_pdu2ros_PicoSensor(src[i], dst[i]);
    }
    return ret;
}
template<int _src_len, int _dst_len>
int hako_convert_pdu2ros_array_PicoSensor(Hako_PicoSensor src[], std::vector<pico_msgs::msg::PicoSensor> &dst)
{
    dst.resize(_src_len);
    for (int i = 0; i < _src_len; i++) {
        (void)hako_convert_pdu2ros_PicoSensor(src[i], dst[i]);
    }
    return 0;
}

/***************************
 *
 * ROS2 ==> PDU
 *
 ***************************/
static inline int hako_convert_ros2pdu_PicoSensor(pico_msgs::msg::PicoSensor &src, Hako_PicoSensor &dst)
{
    //primitive convert
    hako_convert_ros2pdu(src.detect_f, dst.detect_f);
    //primitive convert
    hako_convert_ros2pdu(src.detect_r, dst.detect_r);
    //primitive convert
    hako_convert_ros2pdu(src.detect_l, dst.detect_l);
    //primitive convert
    hako_convert_ros2pdu(src.detect_b, dst.detect_b);
    return 0;
}

template<int _src_len, int _dst_len>
int hako_convert_ros2pdu_array_PicoSensor(std::array<pico_msgs::msg::PicoSensor, _src_len> &src, Hako_PicoSensor dst[])
{
    int ret = 0;
    int len = _dst_len;
    if (_dst_len > _src_len) {
        len = _src_len;
        ret = -1;
    }
    for (int i = 0; i < len; i++) {
        (void)hako_convert_ros2pdu_PicoSensor(src[i], dst[i]);
    }
    return ret;
}
template<int _src_len, int _dst_len>
int hako_convert_ros2pdu_array_PicoSensor(std::vector<pico_msgs::msg::PicoSensor> &src, Hako_PicoSensor dst[])
{
    int ret = 0;
    int len = _dst_len;
    if (_dst_len > _src_len) {
        len = _src_len;
        ret = -1;
    }
    for (int i = 0; i < len; i++) {
        (void)hako_convert_ros2pdu_PicoSensor(src[i], dst[i]);
    }
    return ret;
}

#endif /* _PDU_CTYPE_CONV_HAKO_pico_msgs_PicoSensor_HPP_ */
