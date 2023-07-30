#ifndef _PDU_CTYPE_CONV_HAKO_ev3_msgs_Ev3PduColorSensor_HPP_
#define _PDU_CTYPE_CONV_HAKO_ev3_msgs_Ev3PduColorSensor_HPP_

#include "pdu_primitive_ctypes.h"
#include "ros_primitive_types.hpp"
#include "pdu_primitive_ctypes_conv.hpp"
/*
 * Dependent pdu data
 */
#include "ev3_msgs/pdu_ctype_Ev3PduColorSensor.h"
/*
 * Dependent ros data
 */
#include "ev3_msgs/msg/ev3_pdu_color_sensor.hpp"

/*
 * Dependent Convertors
 */

/***************************
 *
 * PDU ==> ROS2
 *
 ***************************/
static inline int hako_convert_pdu2ros_Ev3PduColorSensor(Hako_Ev3PduColorSensor &src,  ev3_msgs::msg::Ev3PduColorSensor &dst)
{
    //primitive convert
    hako_convert_pdu2ros(src.color, dst.color);
    //primitive convert
    hako_convert_pdu2ros(src.reflect, dst.reflect);
    //primitive convert
    hako_convert_pdu2ros(src.rgb_r, dst.rgb_r);
    //primitive convert
    hako_convert_pdu2ros(src.rgb_g, dst.rgb_g);
    //primitive convert
    hako_convert_pdu2ros(src.rgb_b, dst.rgb_b);
    return 0;
}

template<int _src_len, int _dst_len>
int hako_convert_pdu2ros_array_Ev3PduColorSensor(Hako_Ev3PduColorSensor src[], std::array<ev3_msgs::msg::Ev3PduColorSensor, _dst_len> &dst)
{
    int ret = 0;
    int len = _dst_len;
    if (_dst_len > _src_len) {
        len = _src_len;
        ret = -1;
    }
    for (int i = 0; i < len; i++) {
        (void)hako_convert_pdu2ros_Ev3PduColorSensor(src[i], dst[i]);
    }
    return ret;
}
template<int _src_len, int _dst_len>
int hako_convert_pdu2ros_array_Ev3PduColorSensor(Hako_Ev3PduColorSensor src[], std::vector<ev3_msgs::msg::Ev3PduColorSensor> &dst)
{
    dst.resize(_src_len);
    for (int i = 0; i < _src_len; i++) {
        (void)hako_convert_pdu2ros_Ev3PduColorSensor(src[i], dst[i]);
    }
    return 0;
}

/***************************
 *
 * ROS2 ==> PDU
 *
 ***************************/
static inline int hako_convert_ros2pdu_Ev3PduColorSensor(ev3_msgs::msg::Ev3PduColorSensor &src, Hako_Ev3PduColorSensor &dst)
{
    //primitive convert
    hako_convert_ros2pdu(src.color, dst.color);
    //primitive convert
    hako_convert_ros2pdu(src.reflect, dst.reflect);
    //primitive convert
    hako_convert_ros2pdu(src.rgb_r, dst.rgb_r);
    //primitive convert
    hako_convert_ros2pdu(src.rgb_g, dst.rgb_g);
    //primitive convert
    hako_convert_ros2pdu(src.rgb_b, dst.rgb_b);
    return 0;
}

template<int _src_len, int _dst_len>
int hako_convert_ros2pdu_array_Ev3PduColorSensor(std::array<ev3_msgs::msg::Ev3PduColorSensor, _src_len> &src, Hako_Ev3PduColorSensor dst[])
{
    int ret = 0;
    int len = _dst_len;
    if (_dst_len > _src_len) {
        len = _src_len;
        ret = -1;
    }
    for (int i = 0; i < len; i++) {
        (void)hako_convert_ros2pdu_Ev3PduColorSensor(src[i], dst[i]);
    }
    return ret;
}
template<int _src_len, int _dst_len>
int hako_convert_ros2pdu_array_Ev3PduColorSensor(std::vector<ev3_msgs::msg::Ev3PduColorSensor> &src, Hako_Ev3PduColorSensor dst[])
{
    int ret = 0;
    int len = _dst_len;
    if (_dst_len > _src_len) {
        len = _src_len;
        ret = -1;
    }
    for (int i = 0; i < len; i++) {
        (void)hako_convert_ros2pdu_Ev3PduColorSensor(src[i], dst[i]);
    }
    return ret;
}

#endif /* _PDU_CTYPE_CONV_HAKO_ev3_msgs_Ev3PduColorSensor_HPP_ */
