#ifndef _PDU_CTYPE_CONV_HAKO_pico_msgs_LightSensor_HPP_
#define _PDU_CTYPE_CONV_HAKO_pico_msgs_LightSensor_HPP_

#include "pdu_primitive_ctypes.h"
#include "ros_primitive_types.hpp"
#include "pdu_primitive_ctypes_conv.hpp"
/*
 * Dependent pdu data
 */
#include "pico_msgs/pdu_ctype_LightSensor.h"
/*
 * Dependent ros data
 */
#include "pico_msgs/msg/light_sensor.hpp"

/*
 * Dependent Convertors
 */

/***************************
 *
 * PDU ==> ROS2
 *
 ***************************/
static inline int hako_convert_pdu2ros_LightSensor(Hako_LightSensor &src,  pico_msgs::msg::LightSensor &dst)
{
    //primitive convert
    hako_convert_pdu2ros(src.forward_r, dst.forward_r);
    //primitive convert
    hako_convert_pdu2ros(src.forward_l, dst.forward_l);
    //primitive convert
    hako_convert_pdu2ros(src.left, dst.left);
    //primitive convert
    hako_convert_pdu2ros(src.right, dst.right);
    return 0;
}

template<int _src_len, int _dst_len>
int hako_convert_pdu2ros_array_LightSensor(Hako_LightSensor src[], std::array<pico_msgs::msg::LightSensor, _dst_len> &dst)
{
    int ret = 0;
    int len = _dst_len;
    if (_dst_len > _src_len) {
        len = _src_len;
        ret = -1;
    }
    for (int i = 0; i < len; i++) {
        (void)hako_convert_pdu2ros_LightSensor(src[i], dst[i]);
    }
    return ret;
}
template<int _src_len, int _dst_len>
int hako_convert_pdu2ros_array_LightSensor(Hako_LightSensor src[], std::vector<pico_msgs::msg::LightSensor> &dst)
{
    dst.resize(_src_len);
    for (int i = 0; i < _src_len; i++) {
        (void)hako_convert_pdu2ros_LightSensor(src[i], dst[i]);
    }
    return 0;
}

/***************************
 *
 * ROS2 ==> PDU
 *
 ***************************/
static inline int hako_convert_ros2pdu_LightSensor(pico_msgs::msg::LightSensor &src, Hako_LightSensor &dst)
{
    //primitive convert
    hako_convert_ros2pdu(src.forward_r, dst.forward_r);
    //primitive convert
    hako_convert_ros2pdu(src.forward_l, dst.forward_l);
    //primitive convert
    hako_convert_ros2pdu(src.left, dst.left);
    //primitive convert
    hako_convert_ros2pdu(src.right, dst.right);
    return 0;
}

template<int _src_len, int _dst_len>
int hako_convert_ros2pdu_array_LightSensor(std::array<pico_msgs::msg::LightSensor, _src_len> &src, Hako_LightSensor dst[])
{
    int ret = 0;
    int len = _dst_len;
    if (_dst_len > _src_len) {
        len = _src_len;
        ret = -1;
    }
    for (int i = 0; i < len; i++) {
        (void)hako_convert_ros2pdu_LightSensor(src[i], dst[i]);
    }
    return ret;
}
template<int _src_len, int _dst_len>
int hako_convert_ros2pdu_array_LightSensor(std::vector<pico_msgs::msg::LightSensor> &src, Hako_LightSensor dst[])
{
    int ret = 0;
    int len = _dst_len;
    if (_dst_len > _src_len) {
        len = _src_len;
        ret = -1;
    }
    for (int i = 0; i < len; i++) {
        (void)hako_convert_ros2pdu_LightSensor(src[i], dst[i]);
    }
    return ret;
}

#endif /* _PDU_CTYPE_CONV_HAKO_pico_msgs_LightSensor_HPP_ */
