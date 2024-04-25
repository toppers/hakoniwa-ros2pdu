#ifndef _PDU_CTYPE_CONV_HAKO_hako_msgs_HakoDroneCmdLand_HPP_
#define _PDU_CTYPE_CONV_HAKO_hako_msgs_HakoDroneCmdLand_HPP_

#include "pdu_primitive_ctypes.h"
#include "ros_primitive_types.hpp"
#include "pdu_primitive_ctypes_conv.hpp"
/*
 * Dependent pdu data
 */
#include "hako_msgs/pdu_ctype_HakoDroneCmdLand.h"
/*
 * Dependent ros data
 */
#include "hako_msgs/msg/hako_drone_cmd_land.hpp"

/*
 * Dependent Convertors
 */
#include "hako_msgs/pdu_ctype_conv_HakoDroneCmdHeader.hpp"

/***************************
 *
 * PDU ==> ROS2
 *
 ***************************/
static inline int hako_convert_pdu2ros_HakoDroneCmdLand(Hako_HakoDroneCmdLand &src,  hako_msgs::msg::HakoDroneCmdLand &dst)
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
int hako_convert_pdu2ros_array_HakoDroneCmdLand(Hako_HakoDroneCmdLand src[], std::array<hako_msgs::msg::HakoDroneCmdLand, _dst_len> &dst)
{
    int ret = 0;
    int len = _dst_len;
    if (_dst_len > _src_len) {
        len = _src_len;
        ret = -1;
    }
    for (int i = 0; i < len; i++) {
        (void)hako_convert_pdu2ros_HakoDroneCmdLand(src[i], dst[i]);
    }
    return ret;
}
template<int _src_len, int _dst_len>
int hako_convert_pdu2ros_array_HakoDroneCmdLand(Hako_HakoDroneCmdLand src[], std::vector<hako_msgs::msg::HakoDroneCmdLand> &dst)
{
    dst.resize(_src_len);
    for (int i = 0; i < _src_len; i++) {
        (void)hako_convert_pdu2ros_HakoDroneCmdLand(src[i], dst[i]);
    }
    return 0;
}

/***************************
 *
 * ROS2 ==> PDU
 *
 ***************************/
static inline int hako_convert_ros2pdu_HakoDroneCmdLand(hako_msgs::msg::HakoDroneCmdLand &src, Hako_HakoDroneCmdLand &dst)
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
int hako_convert_ros2pdu_array_HakoDroneCmdLand(std::array<hako_msgs::msg::HakoDroneCmdLand, _src_len> &src, Hako_HakoDroneCmdLand dst[])
{
    int ret = 0;
    int len = _dst_len;
    if (_dst_len > _src_len) {
        len = _src_len;
        ret = -1;
    }
    for (int i = 0; i < len; i++) {
        (void)hako_convert_ros2pdu_HakoDroneCmdLand(src[i], dst[i]);
    }
    return ret;
}
template<int _src_len, int _dst_len>
int hako_convert_ros2pdu_array_HakoDroneCmdLand(std::vector<hako_msgs::msg::HakoDroneCmdLand> &src, Hako_HakoDroneCmdLand dst[])
{
    int ret = 0;
    int len = _dst_len;
    if (_dst_len > _src_len) {
        len = _src_len;
        ret = -1;
    }
    for (int i = 0; i < len; i++) {
        (void)hako_convert_ros2pdu_HakoDroneCmdLand(src[i], dst[i]);
    }
    return ret;
}

#endif /* _PDU_CTYPE_CONV_HAKO_hako_msgs_HakoDroneCmdLand_HPP_ */
