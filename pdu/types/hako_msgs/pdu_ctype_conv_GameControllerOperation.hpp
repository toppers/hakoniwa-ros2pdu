#ifndef _PDU_CTYPE_CONV_HAKO_hako_msgs_GameControllerOperation_HPP_
#define _PDU_CTYPE_CONV_HAKO_hako_msgs_GameControllerOperation_HPP_

#include "pdu_primitive_ctypes.h"
#include "ros_primitive_types.hpp"
#include "pdu_primitive_ctypes_conv.hpp"
/*
 * Dependent pdu data
 */
#include "hako_msgs/pdu_ctype_GameControllerOperation.h"
/*
 * Dependent ros data
 */
#include "hako_msgs/msg/game_controller_operation.hpp"

/*
 * Dependent Convertors
 */

/***************************
 *
 * PDU ==> ROS2
 *
 ***************************/
static inline int hako_convert_pdu2ros_GameControllerOperation(Hako_GameControllerOperation &src,  hako_msgs::msg::GameControllerOperation &dst)
{
    //primitive convert
    hako_convert_pdu2ros(src.axis[4], dst.axis[4]);
    //primitive convert
    hako_convert_pdu2ros(src.button[4], dst.button[4]);
    return 0;
}

template<int _src_len, int _dst_len>
int hako_convert_pdu2ros_array_GameControllerOperation(Hako_GameControllerOperation src[], std::array<hako_msgs::msg::GameControllerOperation, _dst_len> &dst)
{
    int ret = 0;
    int len = _dst_len;
    if (_dst_len > _src_len) {
        len = _src_len;
        ret = -1;
    }
    for (int i = 0; i < len; i++) {
        (void)hako_convert_pdu2ros_GameControllerOperation(src[i], dst[i]);
    }
    return ret;
}
template<int _src_len, int _dst_len>
int hako_convert_pdu2ros_array_GameControllerOperation(Hako_GameControllerOperation src[], std::vector<hako_msgs::msg::GameControllerOperation> &dst)
{
    dst.resize(_src_len);
    for (int i = 0; i < _src_len; i++) {
        (void)hako_convert_pdu2ros_GameControllerOperation(src[i], dst[i]);
    }
    return 0;
}

/***************************
 *
 * ROS2 ==> PDU
 *
 ***************************/
static inline int hako_convert_ros2pdu_GameControllerOperation(hako_msgs::msg::GameControllerOperation &src, Hako_GameControllerOperation &dst)
{
    //primitive convert
    hako_convert_ros2pdu(src.axis[4], dst.axis[4]);
    //primitive convert
    hako_convert_ros2pdu(src.button[4], dst.button[4]);
    return 0;
}

template<int _src_len, int _dst_len>
int hako_convert_ros2pdu_array_GameControllerOperation(std::array<hako_msgs::msg::GameControllerOperation, _src_len> &src, Hako_GameControllerOperation dst[])
{
    int ret = 0;
    int len = _dst_len;
    if (_dst_len > _src_len) {
        len = _src_len;
        ret = -1;
    }
    for (int i = 0; i < len; i++) {
        (void)hako_convert_ros2pdu_GameControllerOperation(src[i], dst[i]);
    }
    return ret;
}
template<int _src_len, int _dst_len>
int hako_convert_ros2pdu_array_GameControllerOperation(std::vector<hako_msgs::msg::GameControllerOperation> &src, Hako_GameControllerOperation dst[])
{
    int ret = 0;
    int len = _dst_len;
    if (_dst_len > _src_len) {
        len = _src_len;
        ret = -1;
    }
    for (int i = 0; i < len; i++) {
        (void)hako_convert_ros2pdu_GameControllerOperation(src[i], dst[i]);
    }
    return ret;
}

#endif /* _PDU_CTYPE_CONV_HAKO_hako_msgs_GameControllerOperation_HPP_ */
