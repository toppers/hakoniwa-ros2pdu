#ifndef _PDU_CTYPE_CONV_HAKO_hako_mavlink_msgs_HakoHilActuatorControls_HPP_
#define _PDU_CTYPE_CONV_HAKO_hako_mavlink_msgs_HakoHilActuatorControls_HPP_

#include "pdu_primitive_ctypes.h"
#include "ros_primitive_types.hpp"
#include "pdu_primitive_ctypes_conv.hpp"
/*
 * Dependent pdu data
 */
#include "hako_mavlink_msgs/pdu_ctype_HakoHilActuatorControls.h"
/*
 * Dependent ros data
 */
#include "hako_mavlink_msgs/msg/hako_hil_actuator_controls.hpp"

/*
 * Dependent Convertors
 */

/***************************
 *
 * PDU ==> ROS2
 *
 ***************************/
static inline int hako_convert_pdu2ros_HakoHilActuatorControls(Hako_HakoHilActuatorControls &src,  hako_mavlink_msgs::msg::HakoHilActuatorControls &dst)
{
    //primitive convert
    hako_convert_pdu2ros(src.time_usec, dst.time_usec);
    //primitive array convertor
    (void)hako_convert_pdu2ros_array(
        src.controls, M_ARRAY_SIZE(Hako_HakoHilActuatorControls, Hako_float32, controls),
        dst.controls, dst.controls.size());
    //primitive convert
    hako_convert_pdu2ros(src.mode, dst.mode);
    //primitive convert
    hako_convert_pdu2ros(src.flags, dst.flags);
    return 0;
}

template<int _src_len, int _dst_len>
int hako_convert_pdu2ros_array_HakoHilActuatorControls(Hako_HakoHilActuatorControls src[], std::array<hako_mavlink_msgs::msg::HakoHilActuatorControls, _dst_len> &dst)
{
    int ret = 0;
    int len = _dst_len;
    if (_dst_len > _src_len) {
        len = _src_len;
        ret = -1;
    }
    for (int i = 0; i < len; i++) {
        (void)hako_convert_pdu2ros_HakoHilActuatorControls(src[i], dst[i]);
    }
    return ret;
}
template<int _src_len, int _dst_len>
int hako_convert_pdu2ros_array_HakoHilActuatorControls(Hako_HakoHilActuatorControls src[], std::vector<hako_mavlink_msgs::msg::HakoHilActuatorControls> &dst)
{
    dst.resize(_src_len);
    for (int i = 0; i < _src_len; i++) {
        (void)hako_convert_pdu2ros_HakoHilActuatorControls(src[i], dst[i]);
    }
    return 0;
}

/***************************
 *
 * ROS2 ==> PDU
 *
 ***************************/
static inline int hako_convert_ros2pdu_HakoHilActuatorControls(hako_mavlink_msgs::msg::HakoHilActuatorControls &src, Hako_HakoHilActuatorControls &dst)
{
    //primitive convert
    hako_convert_ros2pdu(src.time_usec, dst.time_usec);
    //primitive array convertor
    (void)hako_convert_ros2pdu_array(
        src.controls, src.controls.size(),
        dst.controls, M_ARRAY_SIZE(Hako_HakoHilActuatorControls, Hako_float32, controls));
    //primitive convert
    hako_convert_ros2pdu(src.mode, dst.mode);
    //primitive convert
    hako_convert_ros2pdu(src.flags, dst.flags);
    return 0;
}

template<int _src_len, int _dst_len>
int hako_convert_ros2pdu_array_HakoHilActuatorControls(std::array<hako_mavlink_msgs::msg::HakoHilActuatorControls, _src_len> &src, Hako_HakoHilActuatorControls dst[])
{
    int ret = 0;
    int len = _dst_len;
    if (_dst_len > _src_len) {
        len = _src_len;
        ret = -1;
    }
    for (int i = 0; i < len; i++) {
        (void)hako_convert_ros2pdu_HakoHilActuatorControls(src[i], dst[i]);
    }
    return ret;
}
template<int _src_len, int _dst_len>
int hako_convert_ros2pdu_array_HakoHilActuatorControls(std::vector<hako_mavlink_msgs::msg::HakoHilActuatorControls> &src, Hako_HakoHilActuatorControls dst[])
{
    int ret = 0;
    int len = _dst_len;
    if (_dst_len > _src_len) {
        len = _src_len;
        ret = -1;
    }
    for (int i = 0; i < len; i++) {
        (void)hako_convert_ros2pdu_HakoHilActuatorControls(src[i], dst[i]);
    }
    return ret;
}

#endif /* _PDU_CTYPE_CONV_HAKO_hako_mavlink_msgs_HakoHilActuatorControls_HPP_ */
