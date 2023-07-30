#ifndef _PDU_CTYPE_CONV_HAKO_builtin_interfaces_Time_HPP_
#define _PDU_CTYPE_CONV_HAKO_builtin_interfaces_Time_HPP_

#include "pdu_primitive_ctypes.h"
#include "ros_primitive_types.hpp"
#include "pdu_primitive_ctypes_conv.hpp"
/*
 * Dependent pdu data
 */
#include "builtin_interfaces/pdu_ctype_Time.h"
/*
 * Dependent ros data
 */
#include "builtin_interfaces/msg/time.hpp"

/*
 * Dependent Convertors
 */

/***************************
 *
 * PDU ==> ROS2
 *
 ***************************/
static inline int hako_convert_pdu2ros_Time(Hako_Time &src,  builtin_interfaces::msg::Time &dst)
{
    //primitive convert
    hako_convert_pdu2ros(src.sec, dst.sec);
    //primitive convert
    hako_convert_pdu2ros(src.nanosec, dst.nanosec);
    return 0;
}

template<int _src_len, int _dst_len>
int hako_convert_pdu2ros_array_Time(Hako_Time src[], std::array<builtin_interfaces::msg::Time, _dst_len> &dst)
{
    int ret = 0;
    int len = _dst_len;
    if (_dst_len > _src_len) {
        len = _src_len;
        ret = -1;
    }
    for (int i = 0; i < len; i++) {
        (void)hako_convert_pdu2ros_Time(src[i], dst[i]);
    }
    return ret;
}
template<int _src_len, int _dst_len>
int hako_convert_pdu2ros_array_Time(Hako_Time src[], std::vector<builtin_interfaces::msg::Time> &dst)
{
    dst.resize(_src_len);
    for (int i = 0; i < _src_len; i++) {
        (void)hako_convert_pdu2ros_Time(src[i], dst[i]);
    }
    return 0;
}

/***************************
 *
 * ROS2 ==> PDU
 *
 ***************************/
static inline int hako_convert_ros2pdu_Time(builtin_interfaces::msg::Time &src, Hako_Time &dst)
{
    //primitive convert
    hako_convert_ros2pdu(src.sec, dst.sec);
    //primitive convert
    hako_convert_ros2pdu(src.nanosec, dst.nanosec);
    return 0;
}

template<int _src_len, int _dst_len>
int hako_convert_ros2pdu_array_Time(std::array<builtin_interfaces::msg::Time, _src_len> &src, Hako_Time dst[])
{
    int ret = 0;
    int len = _dst_len;
    if (_dst_len > _src_len) {
        len = _src_len;
        ret = -1;
    }
    for (int i = 0; i < len; i++) {
        (void)hako_convert_ros2pdu_Time(src[i], dst[i]);
    }
    return ret;
}
template<int _src_len, int _dst_len>
int hako_convert_ros2pdu_array_Time(std::vector<builtin_interfaces::msg::Time> &src, Hako_Time dst[])
{
    int ret = 0;
    int len = _dst_len;
    if (_dst_len > _src_len) {
        len = _src_len;
        ret = -1;
    }
    for (int i = 0; i < len; i++) {
        (void)hako_convert_ros2pdu_Time(src[i], dst[i]);
    }
    return ret;
}

#endif /* _PDU_CTYPE_CONV_HAKO_builtin_interfaces_Time_HPP_ */
