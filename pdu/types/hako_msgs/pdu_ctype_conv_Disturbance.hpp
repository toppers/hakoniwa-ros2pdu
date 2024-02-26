#ifndef _PDU_CTYPE_CONV_HAKO_hako_msgs_Disturbance_HPP_
#define _PDU_CTYPE_CONV_HAKO_hako_msgs_Disturbance_HPP_

#include "pdu_primitive_ctypes.h"
#include "ros_primitive_types.hpp"
#include "pdu_primitive_ctypes_conv.hpp"
/*
 * Dependent pdu data
 */
#include "hako_msgs/pdu_ctype_Disturbance.h"
/*
 * Dependent ros data
 */
#include "hako_msgs/msg/disturbance.hpp"

/*
 * Dependent Convertors
 */
#include "hako_msgs/pdu_ctype_conv_DisturbanceTemperature.hpp"

/***************************
 *
 * PDU ==> ROS2
 *
 ***************************/
static inline int hako_convert_pdu2ros_Disturbance(Hako_Disturbance &src,  hako_msgs::msg::Disturbance &dst)
{
    //struct convert
    hako_convert_pdu2ros_DisturbanceTemperature(src.d_temp, dst.d_temp);
    return 0;
}

template<int _src_len, int _dst_len>
int hako_convert_pdu2ros_array_Disturbance(Hako_Disturbance src[], std::array<hako_msgs::msg::Disturbance, _dst_len> &dst)
{
    int ret = 0;
    int len = _dst_len;
    if (_dst_len > _src_len) {
        len = _src_len;
        ret = -1;
    }
    for (int i = 0; i < len; i++) {
        (void)hako_convert_pdu2ros_Disturbance(src[i], dst[i]);
    }
    return ret;
}
template<int _src_len, int _dst_len>
int hako_convert_pdu2ros_array_Disturbance(Hako_Disturbance src[], std::vector<hako_msgs::msg::Disturbance> &dst)
{
    dst.resize(_src_len);
    for (int i = 0; i < _src_len; i++) {
        (void)hako_convert_pdu2ros_Disturbance(src[i], dst[i]);
    }
    return 0;
}

/***************************
 *
 * ROS2 ==> PDU
 *
 ***************************/
static inline int hako_convert_ros2pdu_Disturbance(hako_msgs::msg::Disturbance &src, Hako_Disturbance &dst)
{
    //struct convert
    hako_convert_ros2pdu_DisturbanceTemperature(src.d_temp, dst.d_temp);
    return 0;
}

template<int _src_len, int _dst_len>
int hako_convert_ros2pdu_array_Disturbance(std::array<hako_msgs::msg::Disturbance, _src_len> &src, Hako_Disturbance dst[])
{
    int ret = 0;
    int len = _dst_len;
    if (_dst_len > _src_len) {
        len = _src_len;
        ret = -1;
    }
    for (int i = 0; i < len; i++) {
        (void)hako_convert_ros2pdu_Disturbance(src[i], dst[i]);
    }
    return ret;
}
template<int _src_len, int _dst_len>
int hako_convert_ros2pdu_array_Disturbance(std::vector<hako_msgs::msg::Disturbance> &src, Hako_Disturbance dst[])
{
    int ret = 0;
    int len = _dst_len;
    if (_dst_len > _src_len) {
        len = _src_len;
        ret = -1;
    }
    for (int i = 0; i < len; i++) {
        (void)hako_convert_ros2pdu_Disturbance(src[i], dst[i]);
    }
    return ret;
}

#endif /* _PDU_CTYPE_CONV_HAKO_hako_msgs_Disturbance_HPP_ */
