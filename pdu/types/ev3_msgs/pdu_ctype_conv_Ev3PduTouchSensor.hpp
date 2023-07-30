#ifndef _PDU_CTYPE_CONV_HAKO_ev3_msgs_Ev3PduTouchSensor_HPP_
#define _PDU_CTYPE_CONV_HAKO_ev3_msgs_Ev3PduTouchSensor_HPP_

#include "pdu_primitive_ctypes.h"
#include "ros_primitive_types.hpp"
#include "pdu_primitive_ctypes_conv.hpp"
/*
 * Dependent pdu data
 */
#include "ev3_msgs/pdu_ctype_Ev3PduTouchSensor.h"
/*
 * Dependent ros data
 */
#include "ev3_msgs/msg/ev3_pdu_touch_sensor.hpp"

/*
 * Dependent Convertors
 */

/***************************
 *
 * PDU ==> ROS2
 *
 ***************************/
static inline int hako_convert_pdu2ros_Ev3PduTouchSensor(Hako_Ev3PduTouchSensor &src,  ev3_msgs::msg::Ev3PduTouchSensor &dst)
{
    //primitive convert
    hako_convert_pdu2ros(src.value, dst.value);
    return 0;
}

template<int _src_len, int _dst_len>
int hako_convert_pdu2ros_array_Ev3PduTouchSensor(Hako_Ev3PduTouchSensor src[], std::array<ev3_msgs::msg::Ev3PduTouchSensor, _dst_len> &dst)
{
    int ret = 0;
    int len = _dst_len;
    if (_dst_len > _src_len) {
        len = _src_len;
        ret = -1;
    }
    for (int i = 0; i < len; i++) {
        (void)hako_convert_pdu2ros_Ev3PduTouchSensor(src[i], dst[i]);
    }
    return ret;
}
template<int _src_len, int _dst_len>
int hako_convert_pdu2ros_array_Ev3PduTouchSensor(Hako_Ev3PduTouchSensor src[], std::vector<ev3_msgs::msg::Ev3PduTouchSensor> &dst)
{
    dst.resize(_src_len);
    for (int i = 0; i < _src_len; i++) {
        (void)hako_convert_pdu2ros_Ev3PduTouchSensor(src[i], dst[i]);
    }
    return 0;
}

/***************************
 *
 * ROS2 ==> PDU
 *
 ***************************/
static inline int hako_convert_ros2pdu_Ev3PduTouchSensor(ev3_msgs::msg::Ev3PduTouchSensor &src, Hako_Ev3PduTouchSensor &dst)
{
    //primitive convert
    hako_convert_ros2pdu(src.value, dst.value);
    return 0;
}

template<int _src_len, int _dst_len>
int hako_convert_ros2pdu_array_Ev3PduTouchSensor(std::array<ev3_msgs::msg::Ev3PduTouchSensor, _src_len> &src, Hako_Ev3PduTouchSensor dst[])
{
    int ret = 0;
    int len = _dst_len;
    if (_dst_len > _src_len) {
        len = _src_len;
        ret = -1;
    }
    for (int i = 0; i < len; i++) {
        (void)hako_convert_ros2pdu_Ev3PduTouchSensor(src[i], dst[i]);
    }
    return ret;
}
template<int _src_len, int _dst_len>
int hako_convert_ros2pdu_array_Ev3PduTouchSensor(std::vector<ev3_msgs::msg::Ev3PduTouchSensor> &src, Hako_Ev3PduTouchSensor dst[])
{
    int ret = 0;
    int len = _dst_len;
    if (_dst_len > _src_len) {
        len = _src_len;
        ret = -1;
    }
    for (int i = 0; i < len; i++) {
        (void)hako_convert_ros2pdu_Ev3PduTouchSensor(src[i], dst[i]);
    }
    return ret;
}

#endif /* _PDU_CTYPE_CONV_HAKO_ev3_msgs_Ev3PduTouchSensor_HPP_ */
