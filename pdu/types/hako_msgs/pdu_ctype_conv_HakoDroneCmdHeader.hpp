#ifndef _PDU_CTYPE_CONV_HAKO_hako_msgs_HakoDroneCmdHeader_HPP_
#define _PDU_CTYPE_CONV_HAKO_hako_msgs_HakoDroneCmdHeader_HPP_

#include "pdu_primitive_ctypes.h"
#include "ros_primitive_types.hpp"
#include "pdu_primitive_ctypes_conv.hpp"
/*
 * Dependent pdu data
 */
#include "hako_msgs/pdu_ctype_HakoDroneCmdHeader.h"
/*
 * Dependent ros data
 */
#include "hako_msgs/msg/hako_drone_cmd_header.hpp"

/*
 * Dependent Convertors
 */

/***************************
 *
 * PDU ==> ROS2
 *
 ***************************/
static inline int hako_convert_pdu2ros_HakoDroneCmdHeader(Hako_HakoDroneCmdHeader &src,  hako_msgs::msg::HakoDroneCmdHeader &dst)
{
    //primitive convert
    hako_convert_pdu2ros(src.has_result, dst.has_result);
    //primitive convert
    hako_convert_pdu2ros(src.result_code, dst.result_code);
    return 0;
}

template<int _src_len, int _dst_len>
int hako_convert_pdu2ros_array_HakoDroneCmdHeader(Hako_HakoDroneCmdHeader src[], std::array<hako_msgs::msg::HakoDroneCmdHeader, _dst_len> &dst)
{
    int ret = 0;
    int len = _dst_len;
    if (_dst_len > _src_len) {
        len = _src_len;
        ret = -1;
    }
    for (int i = 0; i < len; i++) {
        (void)hako_convert_pdu2ros_HakoDroneCmdHeader(src[i], dst[i]);
    }
    return ret;
}
template<int _src_len, int _dst_len>
int hako_convert_pdu2ros_array_HakoDroneCmdHeader(Hako_HakoDroneCmdHeader src[], std::vector<hako_msgs::msg::HakoDroneCmdHeader> &dst)
{
    dst.resize(_src_len);
    for (int i = 0; i < _src_len; i++) {
        (void)hako_convert_pdu2ros_HakoDroneCmdHeader(src[i], dst[i]);
    }
    return 0;
}

/***************************
 *
 * ROS2 ==> PDU
 *
 ***************************/
static inline int hako_convert_ros2pdu_HakoDroneCmdHeader(hako_msgs::msg::HakoDroneCmdHeader &src, Hako_HakoDroneCmdHeader &dst)
{
    //primitive convert
    hako_convert_ros2pdu(src.has_result, dst.has_result);
    //primitive convert
    hako_convert_ros2pdu(src.result_code, dst.result_code);
    return 0;
}

template<int _src_len, int _dst_len>
int hako_convert_ros2pdu_array_HakoDroneCmdHeader(std::array<hako_msgs::msg::HakoDroneCmdHeader, _src_len> &src, Hako_HakoDroneCmdHeader dst[])
{
    int ret = 0;
    int len = _dst_len;
    if (_dst_len > _src_len) {
        len = _src_len;
        ret = -1;
    }
    for (int i = 0; i < len; i++) {
        (void)hako_convert_ros2pdu_HakoDroneCmdHeader(src[i], dst[i]);
    }
    return ret;
}
template<int _src_len, int _dst_len>
int hako_convert_ros2pdu_array_HakoDroneCmdHeader(std::vector<hako_msgs::msg::HakoDroneCmdHeader> &src, Hako_HakoDroneCmdHeader dst[])
{
    int ret = 0;
    int len = _dst_len;
    if (_dst_len > _src_len) {
        len = _src_len;
        ret = -1;
    }
    for (int i = 0; i < len; i++) {
        (void)hako_convert_ros2pdu_HakoDroneCmdHeader(src[i], dst[i]);
    }
    return ret;
}

#endif /* _PDU_CTYPE_CONV_HAKO_hako_msgs_HakoDroneCmdHeader_HPP_ */
