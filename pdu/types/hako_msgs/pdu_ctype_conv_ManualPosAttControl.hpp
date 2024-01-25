#ifndef _PDU_CTYPE_CONV_HAKO_hako_msgs_ManualPosAttControl_HPP_
#define _PDU_CTYPE_CONV_HAKO_hako_msgs_ManualPosAttControl_HPP_

#include "pdu_primitive_ctypes.h"
#include "ros_primitive_types.hpp"
#include "pdu_primitive_ctypes_conv.hpp"
/*
 * Dependent pdu data
 */
#include "hako_msgs/pdu_ctype_ManualPosAttControl.h"
/*
 * Dependent ros data
 */
#include "hako_msgs/msg/manual_pos_att_control.hpp"

/*
 * Dependent Convertors
 */
#include "geometry_msgs/pdu_ctype_conv_Twist.hpp"
#include "geometry_msgs/pdu_ctype_conv_Vector3.hpp"

/***************************
 *
 * PDU ==> ROS2
 *
 ***************************/
static inline int hako_convert_pdu2ros_ManualPosAttControl(Hako_ManualPosAttControl &src,  hako_msgs::msg::ManualPosAttControl &dst)
{
    //primitive convert
    hako_convert_pdu2ros(src.do_operation, dst.do_operation);
    //struct convert
    hako_convert_pdu2ros_Twist(src.posatt, dst.posatt);
    return 0;
}

template<int _src_len, int _dst_len>
int hako_convert_pdu2ros_array_ManualPosAttControl(Hako_ManualPosAttControl src[], std::array<hako_msgs::msg::ManualPosAttControl, _dst_len> &dst)
{
    int ret = 0;
    int len = _dst_len;
    if (_dst_len > _src_len) {
        len = _src_len;
        ret = -1;
    }
    for (int i = 0; i < len; i++) {
        (void)hako_convert_pdu2ros_ManualPosAttControl(src[i], dst[i]);
    }
    return ret;
}
template<int _src_len, int _dst_len>
int hako_convert_pdu2ros_array_ManualPosAttControl(Hako_ManualPosAttControl src[], std::vector<hako_msgs::msg::ManualPosAttControl> &dst)
{
    dst.resize(_src_len);
    for (int i = 0; i < _src_len; i++) {
        (void)hako_convert_pdu2ros_ManualPosAttControl(src[i], dst[i]);
    }
    return 0;
}

/***************************
 *
 * ROS2 ==> PDU
 *
 ***************************/
static inline int hako_convert_ros2pdu_ManualPosAttControl(hako_msgs::msg::ManualPosAttControl &src, Hako_ManualPosAttControl &dst)
{
    //primitive convert
    hako_convert_ros2pdu(src.do_operation, dst.do_operation);
    //struct convert
    hako_convert_ros2pdu_Twist(src.posatt, dst.posatt);
    return 0;
}

template<int _src_len, int _dst_len>
int hako_convert_ros2pdu_array_ManualPosAttControl(std::array<hako_msgs::msg::ManualPosAttControl, _src_len> &src, Hako_ManualPosAttControl dst[])
{
    int ret = 0;
    int len = _dst_len;
    if (_dst_len > _src_len) {
        len = _src_len;
        ret = -1;
    }
    for (int i = 0; i < len; i++) {
        (void)hako_convert_ros2pdu_ManualPosAttControl(src[i], dst[i]);
    }
    return ret;
}
template<int _src_len, int _dst_len>
int hako_convert_ros2pdu_array_ManualPosAttControl(std::vector<hako_msgs::msg::ManualPosAttControl> &src, Hako_ManualPosAttControl dst[])
{
    int ret = 0;
    int len = _dst_len;
    if (_dst_len > _src_len) {
        len = _src_len;
        ret = -1;
    }
    for (int i = 0; i < len; i++) {
        (void)hako_convert_ros2pdu_ManualPosAttControl(src[i], dst[i]);
    }
    return ret;
}

#endif /* _PDU_CTYPE_CONV_HAKO_hako_msgs_ManualPosAttControl_HPP_ */
