#ifndef _PDU_CTYPE_CONV_HAKO_hako_msgs_HakoDroneCmdTakeoff_HPP_
#define _PDU_CTYPE_CONV_HAKO_hako_msgs_HakoDroneCmdTakeoff_HPP_

#include "pdu_primitive_ctypes.h"
#include "ros_primitive_types.hpp"
#include "pdu_primitive_ctypes_conv.hpp"
/*
 * Dependent pdu data
 */
#include "hako_msgs/pdu_ctype_HakoDroneCmdTakeoff.h"
/*
 * Dependent ros data
 */
#include "hako_msgs/msg/hako_drone_cmd_takeoff.hpp"

/*
 * Dependent Convertors
 */
#include "hako_msgs/pdu_ctype_conv_HakoDroneCmdHeader.hpp"

/***************************
 *
 * PDU ==> ROS2
 *
 ***************************/
static inline int hako_convert_pdu2ros_HakoDroneCmdTakeoff(Hako_HakoDroneCmdTakeoff &src,  hako_msgs::msg::HakoDroneCmdTakeoff &dst)
{
    //struct convert
    hako_convert_pdu2ros_HakoDroneCmdHeader(src.header, dst.header);
    //primitive convert
    hako_convert_pdu2ros(src.height, dst.height);
    //primitive convert
    hako_convert_pdu2ros(src.speed, dst.speed);
    //primitive convert
    hako_convert_pdu2ros(src.yaw_deg, dst.yaw_deg);
    return 0;
}

template<int _src_len, int _dst_len>
int hako_convert_pdu2ros_array_HakoDroneCmdTakeoff(Hako_HakoDroneCmdTakeoff src[], std::array<hako_msgs::msg::HakoDroneCmdTakeoff, _dst_len> &dst)
{
    int ret = 0;
    int len = _dst_len;
    if (_dst_len > _src_len) {
        len = _src_len;
        ret = -1;
    }
    for (int i = 0; i < len; i++) {
        (void)hako_convert_pdu2ros_HakoDroneCmdTakeoff(src[i], dst[i]);
    }
    return ret;
}
template<int _src_len, int _dst_len>
int hako_convert_pdu2ros_array_HakoDroneCmdTakeoff(Hako_HakoDroneCmdTakeoff src[], std::vector<hako_msgs::msg::HakoDroneCmdTakeoff> &dst)
{
    dst.resize(_src_len);
    for (int i = 0; i < _src_len; i++) {
        (void)hako_convert_pdu2ros_HakoDroneCmdTakeoff(src[i], dst[i]);
    }
    return 0;
}

/***************************
 *
 * ROS2 ==> PDU
 *
 ***************************/
static inline int hako_convert_ros2pdu_HakoDroneCmdTakeoff(hako_msgs::msg::HakoDroneCmdTakeoff &src, Hako_HakoDroneCmdTakeoff &dst)
{
    //struct convert
    hako_convert_ros2pdu_HakoDroneCmdHeader(src.header, dst.header);
    //primitive convert
    hako_convert_ros2pdu(src.height, dst.height);
    //primitive convert
    hako_convert_ros2pdu(src.speed, dst.speed);
    //primitive convert
    hako_convert_ros2pdu(src.yaw_deg, dst.yaw_deg);
    return 0;
}

template<int _src_len, int _dst_len>
int hako_convert_ros2pdu_array_HakoDroneCmdTakeoff(std::array<hako_msgs::msg::HakoDroneCmdTakeoff, _src_len> &src, Hako_HakoDroneCmdTakeoff dst[])
{
    int ret = 0;
    int len = _dst_len;
    if (_dst_len > _src_len) {
        len = _src_len;
        ret = -1;
    }
    for (int i = 0; i < len; i++) {
        (void)hako_convert_ros2pdu_HakoDroneCmdTakeoff(src[i], dst[i]);
    }
    return ret;
}
template<int _src_len, int _dst_len>
int hako_convert_ros2pdu_array_HakoDroneCmdTakeoff(std::vector<hako_msgs::msg::HakoDroneCmdTakeoff> &src, Hako_HakoDroneCmdTakeoff dst[])
{
    int ret = 0;
    int len = _dst_len;
    if (_dst_len > _src_len) {
        len = _src_len;
        ret = -1;
    }
    for (int i = 0; i < len; i++) {
        (void)hako_convert_ros2pdu_HakoDroneCmdTakeoff(src[i], dst[i]);
    }
    return ret;
}

#endif /* _PDU_CTYPE_CONV_HAKO_hako_msgs_HakoDroneCmdTakeoff_HPP_ */
