#ifndef _PDU_CTYPE_CONV_HAKO_hako_msgs_DisturbanceTemperature_HPP_
#define _PDU_CTYPE_CONV_HAKO_hako_msgs_DisturbanceTemperature_HPP_

#include "pdu_primitive_ctypes.h"
#include "ros_primitive_types.hpp"
#include "pdu_primitive_ctypes_conv.hpp"
/*
 * Dependent pdu data
 */
#include "hako_msgs/pdu_ctype_DisturbanceTemperature.h"
/*
 * Dependent ros data
 */
#include "hako_msgs/msg/disturbance_temperature.hpp"

/*
 * Dependent Convertors
 */

/***************************
 *
 * PDU ==> ROS2
 *
 ***************************/
static inline int hako_convert_pdu2ros_DisturbanceTemperature(Hako_DisturbanceTemperature &src,  hako_msgs::msg::DisturbanceTemperature &dst)
{
    //primitive convert
    hako_convert_pdu2ros(src.value, dst.value);
    return 0;
}

template<int _src_len, int _dst_len>
int hako_convert_pdu2ros_array_DisturbanceTemperature(Hako_DisturbanceTemperature src[], std::array<hako_msgs::msg::DisturbanceTemperature, _dst_len> &dst)
{
    int ret = 0;
    int len = _dst_len;
    if (_dst_len > _src_len) {
        len = _src_len;
        ret = -1;
    }
    for (int i = 0; i < len; i++) {
        (void)hako_convert_pdu2ros_DisturbanceTemperature(src[i], dst[i]);
    }
    return ret;
}
template<int _src_len, int _dst_len>
int hako_convert_pdu2ros_array_DisturbanceTemperature(Hako_DisturbanceTemperature src[], std::vector<hako_msgs::msg::DisturbanceTemperature> &dst)
{
    dst.resize(_src_len);
    for (int i = 0; i < _src_len; i++) {
        (void)hako_convert_pdu2ros_DisturbanceTemperature(src[i], dst[i]);
    }
    return 0;
}

/***************************
 *
 * ROS2 ==> PDU
 *
 ***************************/
static inline int hako_convert_ros2pdu_DisturbanceTemperature(hako_msgs::msg::DisturbanceTemperature &src, Hako_DisturbanceTemperature &dst)
{
    //primitive convert
    hako_convert_ros2pdu(src.value, dst.value);
    return 0;
}

template<int _src_len, int _dst_len>
int hako_convert_ros2pdu_array_DisturbanceTemperature(std::array<hako_msgs::msg::DisturbanceTemperature, _src_len> &src, Hako_DisturbanceTemperature dst[])
{
    int ret = 0;
    int len = _dst_len;
    if (_dst_len > _src_len) {
        len = _src_len;
        ret = -1;
    }
    for (int i = 0; i < len; i++) {
        (void)hako_convert_ros2pdu_DisturbanceTemperature(src[i], dst[i]);
    }
    return ret;
}
template<int _src_len, int _dst_len>
int hako_convert_ros2pdu_array_DisturbanceTemperature(std::vector<hako_msgs::msg::DisturbanceTemperature> &src, Hako_DisturbanceTemperature dst[])
{
    int ret = 0;
    int len = _dst_len;
    if (_dst_len > _src_len) {
        len = _src_len;
        ret = -1;
    }
    for (int i = 0; i < len; i++) {
        (void)hako_convert_ros2pdu_DisturbanceTemperature(src[i], dst[i]);
    }
    return ret;
}

#endif /* _PDU_CTYPE_CONV_HAKO_hako_msgs_DisturbanceTemperature_HPP_ */
