#ifndef _PDU_CTYPE_CONV_HAKO_hako_msgs_HakoStatusMagnetHolder_HPP_
#define _PDU_CTYPE_CONV_HAKO_hako_msgs_HakoStatusMagnetHolder_HPP_

#include "pdu_primitive_ctypes.h"
#include "ros_primitive_types.hpp"
#include "pdu_primitive_ctypes_conv.hpp"
/*
 * Dependent pdu data
 */
#include "hako_msgs/pdu_ctype_HakoStatusMagnetHolder.h"
/*
 * Dependent ros data
 */
#include "hako_msgs/msg/hako_status_magnet_holder.hpp"

/*
 * Dependent Convertors
 */

/***************************
 *
 * PDU ==> ROS2
 *
 ***************************/
static inline int hako_convert_pdu2ros_HakoStatusMagnetHolder(Hako_HakoStatusMagnetHolder &src,  hako_msgs::msg::HakoStatusMagnetHolder &dst)
{
    //primitive convert
    hako_convert_pdu2ros(src.magnet_on, dst.magnet_on);
    //primitive convert
    hako_convert_pdu2ros(src.contact_on, dst.contact_on);
    return 0;
}

template<int _src_len, int _dst_len>
int hako_convert_pdu2ros_array_HakoStatusMagnetHolder(Hako_HakoStatusMagnetHolder src[], std::array<hako_msgs::msg::HakoStatusMagnetHolder, _dst_len> &dst)
{
    int ret = 0;
    int len = _dst_len;
    if (_dst_len > _src_len) {
        len = _src_len;
        ret = -1;
    }
    for (int i = 0; i < len; i++) {
        (void)hako_convert_pdu2ros_HakoStatusMagnetHolder(src[i], dst[i]);
    }
    return ret;
}
template<int _src_len, int _dst_len>
int hako_convert_pdu2ros_array_HakoStatusMagnetHolder(Hako_HakoStatusMagnetHolder src[], std::vector<hako_msgs::msg::HakoStatusMagnetHolder> &dst)
{
    dst.resize(_src_len);
    for (int i = 0; i < _src_len; i++) {
        (void)hako_convert_pdu2ros_HakoStatusMagnetHolder(src[i], dst[i]);
    }
    return 0;
}

/***************************
 *
 * ROS2 ==> PDU
 *
 ***************************/
static inline int hako_convert_ros2pdu_HakoStatusMagnetHolder(hako_msgs::msg::HakoStatusMagnetHolder &src, Hako_HakoStatusMagnetHolder &dst)
{
    //primitive convert
    hako_convert_ros2pdu(src.magnet_on, dst.magnet_on);
    //primitive convert
    hako_convert_ros2pdu(src.contact_on, dst.contact_on);
    return 0;
}

template<int _src_len, int _dst_len>
int hako_convert_ros2pdu_array_HakoStatusMagnetHolder(std::array<hako_msgs::msg::HakoStatusMagnetHolder, _src_len> &src, Hako_HakoStatusMagnetHolder dst[])
{
    int ret = 0;
    int len = _dst_len;
    if (_dst_len > _src_len) {
        len = _src_len;
        ret = -1;
    }
    for (int i = 0; i < len; i++) {
        (void)hako_convert_ros2pdu_HakoStatusMagnetHolder(src[i], dst[i]);
    }
    return ret;
}
template<int _src_len, int _dst_len>
int hako_convert_ros2pdu_array_HakoStatusMagnetHolder(std::vector<hako_msgs::msg::HakoStatusMagnetHolder> &src, Hako_HakoStatusMagnetHolder dst[])
{
    int ret = 0;
    int len = _dst_len;
    if (_dst_len > _src_len) {
        len = _src_len;
        ret = -1;
    }
    for (int i = 0; i < len; i++) {
        (void)hako_convert_ros2pdu_HakoStatusMagnetHolder(src[i], dst[i]);
    }
    return ret;
}

#endif /* _PDU_CTYPE_CONV_HAKO_hako_msgs_HakoStatusMagnetHolder_HPP_ */
