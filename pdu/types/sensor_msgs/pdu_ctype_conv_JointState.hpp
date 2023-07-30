#ifndef _PDU_CTYPE_CONV_HAKO_sensor_msgs_JointState_HPP_
#define _PDU_CTYPE_CONV_HAKO_sensor_msgs_JointState_HPP_

#include "pdu_primitive_ctypes.h"
#include "ros_primitive_types.hpp"
#include "pdu_primitive_ctypes_conv.hpp"
/*
 * Dependent pdu data
 */
#include "sensor_msgs/pdu_ctype_JointState.h"
/*
 * Dependent ros data
 */
#include "sensor_msgs/msg/joint_state.hpp"

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
static inline int hako_convert_pdu2ros_JointState(Hako_JointState &src,  sensor_msgs::msg::JointState &dst)
{
    //struct convert
    hako_convert_pdu2ros_Header(src.header, dst.header);
    //string array convertor
    (void)hako_convert_pdu2ros_array_string<M_ARRAY_SIZE(Hako_JointState, Hako_cstring, name), 2>(
        src.name, dst.name);
    //primitive array convertor
    (void)hako_convert_pdu2ros_array(
        src.position, M_ARRAY_SIZE(Hako_JointState, Hako_float64, position),
        dst.position, dst.position.size());
    //primitive array convertor
    (void)hako_convert_pdu2ros_array(
        src.velocity, M_ARRAY_SIZE(Hako_JointState, Hako_float64, velocity),
        dst.velocity, dst.velocity.size());
    //primitive array convertor
    (void)hako_convert_pdu2ros_array(
        src.effort, M_ARRAY_SIZE(Hako_JointState, Hako_float64, effort),
        dst.effort, dst.effort.size());
    return 0;
}

template<int _src_len, int _dst_len>
int hako_convert_pdu2ros_array_JointState(Hako_JointState src[], std::array<sensor_msgs::msg::JointState, _dst_len> &dst)
{
    int ret = 0;
    int len = _dst_len;
    if (_dst_len > _src_len) {
        len = _src_len;
        ret = -1;
    }
    for (int i = 0; i < len; i++) {
        (void)hako_convert_pdu2ros_JointState(src[i], dst[i]);
    }
    return ret;
}
template<int _src_len, int _dst_len>
int hako_convert_pdu2ros_array_JointState(Hako_JointState src[], std::vector<sensor_msgs::msg::JointState> &dst)
{
    dst.resize(_src_len);
    for (int i = 0; i < _src_len; i++) {
        (void)hako_convert_pdu2ros_JointState(src[i], dst[i]);
    }
    return 0;
}

/***************************
 *
 * ROS2 ==> PDU
 *
 ***************************/
static inline int hako_convert_ros2pdu_JointState(sensor_msgs::msg::JointState &src, Hako_JointState &dst)
{
    //struct convert
    hako_convert_ros2pdu_Header(src.header, dst.header);
    //string array convertor
    (void)hako_convert_ros2pdu_array_string<2, M_ARRAY_SIZE(Hako_JointState, Hako_cstring, name)>(
        src.name, dst.name);
    //primitive array convertor
    (void)hako_convert_ros2pdu_array(
        src.position, src.position.size(),
        dst.position, M_ARRAY_SIZE(Hako_JointState, Hako_float64, position));
    //primitive array convertor
    (void)hako_convert_ros2pdu_array(
        src.velocity, src.velocity.size(),
        dst.velocity, M_ARRAY_SIZE(Hako_JointState, Hako_float64, velocity));
    //primitive array convertor
    (void)hako_convert_ros2pdu_array(
        src.effort, src.effort.size(),
        dst.effort, M_ARRAY_SIZE(Hako_JointState, Hako_float64, effort));
    return 0;
}

template<int _src_len, int _dst_len>
int hako_convert_ros2pdu_array_JointState(std::array<sensor_msgs::msg::JointState, _src_len> &src, Hako_JointState dst[])
{
    int ret = 0;
    int len = _dst_len;
    if (_dst_len > _src_len) {
        len = _src_len;
        ret = -1;
    }
    for (int i = 0; i < len; i++) {
        (void)hako_convert_ros2pdu_JointState(src[i], dst[i]);
    }
    return ret;
}
template<int _src_len, int _dst_len>
int hako_convert_ros2pdu_array_JointState(std::vector<sensor_msgs::msg::JointState> &src, Hako_JointState dst[])
{
    int ret = 0;
    int len = _dst_len;
    if (_dst_len > _src_len) {
        len = _src_len;
        ret = -1;
    }
    for (int i = 0; i < len; i++) {
        (void)hako_convert_ros2pdu_JointState(src[i], dst[i]);
    }
    return ret;
}

#endif /* _PDU_CTYPE_CONV_HAKO_sensor_msgs_JointState_HPP_ */
