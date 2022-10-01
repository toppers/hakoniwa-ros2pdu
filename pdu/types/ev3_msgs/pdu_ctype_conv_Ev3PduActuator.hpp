#ifndef _PDU_CTYPE_CONV_HAKO_ev3_msgs_Ev3PduActuator_HPP_
#define _PDU_CTYPE_CONV_HAKO_ev3_msgs_Ev3PduActuator_HPP_

#include "pdu_primitive_ctypes.h"
#include "ros_primitive_types.hpp"
#include "pdu_primitive_ctypes_conv.hpp"
/*
 * Dependent pdu data
 */
#include "ev3_msgs/pdu_ctype_Ev3PduActuator.h"
/*
 * Dependent ros data
 */
#include "ev3_msgs/msg/ev3_pdu_actuator.hpp"

/*
 * Dependent Convertors
 */
#include "pdu_ctype_conv_Ev3PduActuatorHeader.hpp"
#include "pdu_ctype_conv_Ev3PduMotor.hpp"

/***************************
 *
 * PDU ==> ROS2
 *
 ***************************/
static inline int hako_convert_pdu2ros_Ev3PduActuator(Hako_Ev3PduActuator &src,  ev3_msgs::msg::Ev3PduActuator &dst)
{
    //struct convert
    hako_convert_pdu2ros_Ev3PduActuatorHeader(src.head, dst.head);
    //primitive array convertor
    (void)hako_convert_pdu2ros_array(
        src.leds, M_ARRAY_SIZE(Hako_Ev3PduActuator, Hako_uint8, leds),
        dst.leds, 1);
    //struct array convertor
    (void)hako_convert_pdu2ros_array_Ev3PduMotor<M_ARRAY_SIZE(Hako_Ev3PduActuator, Hako_Ev3PduMotor, motors), 3>(
        src.motors, dst.motors);
    //primitive convert
    hako_convert_pdu2ros(src.gyro_reset, dst.gyro_reset);
    return 0;
}

template<int _src_len, int _dst_len>
int hako_convert_pdu2ros_array_Ev3PduActuator(Hako_Ev3PduActuator src[], std::array<ev3_msgs::msg::Ev3PduActuator, _dst_len> &dst)
{
    int ret = 0;
    int len = _dst_len;
    if (_dst_len < _src_len) {
        len = _src_len;
        ret = -1;
    }
    for (int i = 0; i < len; i++) {
        (void)hako_convert_pdu2ros_Ev3PduActuator(src[i], dst[i]);
    }
    return ret;
}

/***************************
 *
 * ROS2 ==> PDU
 *
 ***************************/
static inline int hako_convert_ros2pdu_Ev3PduActuator(ev3_msgs::msg::Ev3PduActuator &src, Hako_Ev3PduActuator &dst)
{
    //struct convert
    hako_convert_ros2pdu_Ev3PduActuatorHeader(src.head, dst.head);
    //primitive array convertor
    (void)hako_convert_ros2pdu_array(
        src.leds, 1,
        dst.leds, M_ARRAY_SIZE(Hako_Ev3PduActuator, Hako_uint8, leds));
    //struct array convertor
    (void)hako_convert_ros2pdu_array_Ev3PduMotor<3, M_ARRAY_SIZE(Hako_Ev3PduActuator, Hako_Ev3PduMotor, motors)>(
        src.motors, dst.motors);
    //primitive convert
    hako_convert_ros2pdu(src.gyro_reset, dst.gyro_reset);
    return 0;
}

template<int _src_len, int _dst_len>
int hako_convert_ros2pdu_array_Ev3PduActuator(std::array<ev3_msgs::msg::Ev3PduActuator, _src_len> &src, Hako_Ev3PduActuator dst[])
{
    int ret = 0;
    int len = _dst_len;
    if (_dst_len < _src_len) {
        len = _src_len;
        ret = -1;
    }
    for (int i = 0; i < len; i++) {
        (void)hako_convert_ros2pdu_Ev3PduActuator(src[i], dst[i]);
    }
    return ret;
}
#endif /* _PDU_CTYPE_CONV_HAKO_ev3_msgs_Ev3PduActuator_HPP_ */
