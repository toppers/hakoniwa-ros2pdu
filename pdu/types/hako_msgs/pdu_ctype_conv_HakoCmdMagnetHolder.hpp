#ifndef _PDU_CTYPE_CONV_HAKO_hako_msgs_HakoCmdMagnetHolder_HPP_
#define _PDU_CTYPE_CONV_HAKO_hako_msgs_HakoCmdMagnetHolder_HPP_

#include "pdu_primitive_ctypes.h"
#include "ros_primitive_types.hpp"
#include "pdu_primitive_ctypes_conv.hpp"
/*
 * Dependent pdu data
 */
#include "hako_msgs/pdu_ctype_HakoCmdMagnetHolder.h"
/*
 * Dependent ros data
 */
#include "hako_msgs/msg/hako_cmd_magnet_holder.hpp"

/*
 * Dependent Convertors
 */
#include "hako_msgs/pdu_ctype_conv_HakoCmdHeader.hpp"

/***************************
 *
 * PDU ==> ROS2
 *
 ***************************/
static inline int hako_convert_pdu2ros_HakoCmdMagnetHolder(Hako_HakoCmdMagnetHolder &src,  hako_msgs::msg::HakoCmdMagnetHolder &dst)
{
    //struct convert
    hako_convert_pdu2ros_HakoCmdHeader(src.header, dst.header);
    //primitive convert
    hako_convert_pdu2ros(src.magnet_on, dst.magnet_on);
    return 0;
}

template<int _src_len, int _dst_len>
int hako_convert_pdu2ros_array_HakoCmdMagnetHolder(Hako_HakoCmdMagnetHolder src[], std::array<hako_msgs::msg::HakoCmdMagnetHolder, _dst_len> &dst)
{
    int ret = 0;
    int len = _dst_len;
    if (_dst_len > _src_len) {
        len = _src_len;
        ret = -1;
    }
    for (int i = 0; i < len; i++) {
        (void)hako_convert_pdu2ros_HakoCmdMagnetHolder(src[i], dst[i]);
    }
    return ret;
}
template<int _src_len, int _dst_len>
int hako_convert_pdu2ros_array_HakoCmdMagnetHolder(Hako_HakoCmdMagnetHolder src[], std::vector<hako_msgs::msg::HakoCmdMagnetHolder> &dst)
{
    dst.resize(_src_len);
    for (int i = 0; i < _src_len; i++) {
        (void)hako_convert_pdu2ros_HakoCmdMagnetHolder(src[i], dst[i]);
    }
    return 0;
}

/***************************
 *
 * ROS2 ==> PDU
 *
 ***************************/
static inline int hako_convert_ros2pdu_HakoCmdMagnetHolder(hako_msgs::msg::HakoCmdMagnetHolder &src, Hako_HakoCmdMagnetHolder &dst)
{
    //struct convert
    hako_convert_ros2pdu_HakoCmdHeader(src.header, dst.header);
    //primitive convert
    hako_convert_ros2pdu(src.magnet_on, dst.magnet_on);
    return 0;
}

template<int _src_len, int _dst_len>
int hako_convert_ros2pdu_array_HakoCmdMagnetHolder(std::array<hako_msgs::msg::HakoCmdMagnetHolder, _src_len> &src, Hako_HakoCmdMagnetHolder dst[])
{
    int ret = 0;
    int len = _dst_len;
    if (_dst_len > _src_len) {
        len = _src_len;
        ret = -1;
    }
    for (int i = 0; i < len; i++) {
        (void)hako_convert_ros2pdu_HakoCmdMagnetHolder(src[i], dst[i]);
    }
    return ret;
}
template<int _src_len, int _dst_len>
int hako_convert_ros2pdu_array_HakoCmdMagnetHolder(std::vector<hako_msgs::msg::HakoCmdMagnetHolder> &src, Hako_HakoCmdMagnetHolder dst[])
{
    int ret = 0;
    int len = _dst_len;
    if (_dst_len > _src_len) {
        len = _src_len;
        ret = -1;
    }
    for (int i = 0; i < len; i++) {
        (void)hako_convert_ros2pdu_HakoCmdMagnetHolder(src[i], dst[i]);
    }
    return ret;
}

#endif /* _PDU_CTYPE_CONV_HAKO_hako_msgs_HakoCmdMagnetHolder_HPP_ */
