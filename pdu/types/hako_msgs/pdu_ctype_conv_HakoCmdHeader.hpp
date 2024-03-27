#ifndef _PDU_CTYPE_CONV_HAKO_hako_msgs_HakoCmdHeader_HPP_
#define _PDU_CTYPE_CONV_HAKO_hako_msgs_HakoCmdHeader_HPP_

#include "pdu_primitive_ctypes.h"
#include "ros_primitive_types.hpp"
#include "pdu_primitive_ctypes_conv.hpp"
/*
 * Dependent pdu data
 */
#include "hako_msgs/pdu_ctype_HakoCmdHeader.h"
/*
 * Dependent ros data
 */
#include "hako_msgs/msg/hako_cmd_header.hpp"

/*
 * Dependent Convertors
 */

/***************************
 *
 * PDU ==> ROS2
 *
 ***************************/
static inline int hako_convert_pdu2ros_HakoCmdHeader(Hako_HakoCmdHeader &src,  hako_msgs::msg::HakoCmdHeader &dst)
{
    //primitive convert
    hako_convert_pdu2ros(src.request, dst.request);
    //primitive convert
    hako_convert_pdu2ros(src.result, dst.result);
    //primitive convert
    hako_convert_pdu2ros(src.result_code, dst.result_code);
    return 0;
}

template<int _src_len, int _dst_len>
int hako_convert_pdu2ros_array_HakoCmdHeader(Hako_HakoCmdHeader src[], std::array<hako_msgs::msg::HakoCmdHeader, _dst_len> &dst)
{
    int ret = 0;
    int len = _dst_len;
    if (_dst_len > _src_len) {
        len = _src_len;
        ret = -1;
    }
    for (int i = 0; i < len; i++) {
        (void)hako_convert_pdu2ros_HakoCmdHeader(src[i], dst[i]);
    }
    return ret;
}
template<int _src_len, int _dst_len>
int hako_convert_pdu2ros_array_HakoCmdHeader(Hako_HakoCmdHeader src[], std::vector<hako_msgs::msg::HakoCmdHeader> &dst)
{
    dst.resize(_src_len);
    for (int i = 0; i < _src_len; i++) {
        (void)hako_convert_pdu2ros_HakoCmdHeader(src[i], dst[i]);
    }
    return 0;
}

/***************************
 *
 * ROS2 ==> PDU
 *
 ***************************/
static inline int hako_convert_ros2pdu_HakoCmdHeader(hako_msgs::msg::HakoCmdHeader &src, Hako_HakoCmdHeader &dst)
{
    //primitive convert
    hako_convert_ros2pdu(src.request, dst.request);
    //primitive convert
    hako_convert_ros2pdu(src.result, dst.result);
    //primitive convert
    hako_convert_ros2pdu(src.result_code, dst.result_code);
    return 0;
}

template<int _src_len, int _dst_len>
int hako_convert_ros2pdu_array_HakoCmdHeader(std::array<hako_msgs::msg::HakoCmdHeader, _src_len> &src, Hako_HakoCmdHeader dst[])
{
    int ret = 0;
    int len = _dst_len;
    if (_dst_len > _src_len) {
        len = _src_len;
        ret = -1;
    }
    for (int i = 0; i < len; i++) {
        (void)hako_convert_ros2pdu_HakoCmdHeader(src[i], dst[i]);
    }
    return ret;
}
template<int _src_len, int _dst_len>
int hako_convert_ros2pdu_array_HakoCmdHeader(std::vector<hako_msgs::msg::HakoCmdHeader> &src, Hako_HakoCmdHeader dst[])
{
    int ret = 0;
    int len = _dst_len;
    if (_dst_len > _src_len) {
        len = _src_len;
        ret = -1;
    }
    for (int i = 0; i < len; i++) {
        (void)hako_convert_ros2pdu_HakoCmdHeader(src[i], dst[i]);
    }
    return ret;
}

#endif /* _PDU_CTYPE_CONV_HAKO_hako_msgs_HakoCmdHeader_HPP_ */
