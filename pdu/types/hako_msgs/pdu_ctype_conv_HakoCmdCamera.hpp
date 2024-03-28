#ifndef _PDU_CTYPE_CONV_HAKO_hako_msgs_HakoCmdCamera_HPP_
#define _PDU_CTYPE_CONV_HAKO_hako_msgs_HakoCmdCamera_HPP_

#include "pdu_primitive_ctypes.h"
#include "ros_primitive_types.hpp"
#include "pdu_primitive_ctypes_conv.hpp"
/*
 * Dependent pdu data
 */
#include "hako_msgs/pdu_ctype_HakoCmdCamera.h"
/*
 * Dependent ros data
 */
#include "hako_msgs/msg/hako_cmd_camera.hpp"

/*
 * Dependent Convertors
 */
#include "hako_msgs/pdu_ctype_conv_HakoCmdHeader.hpp"

/***************************
 *
 * PDU ==> ROS2
 *
 ***************************/
static inline int hako_convert_pdu2ros_HakoCmdCamera(Hako_HakoCmdCamera &src,  hako_msgs::msg::HakoCmdCamera &dst)
{
    //struct convert
    hako_convert_pdu2ros_HakoCmdHeader(src.header, dst.header);
    //primitive convert
    hako_convert_pdu2ros(src.request_id, dst.request_id);
    //primitive convert
    hako_convert_pdu2ros(src.encode_type, dst.encode_type);
    return 0;
}

template<int _src_len, int _dst_len>
int hako_convert_pdu2ros_array_HakoCmdCamera(Hako_HakoCmdCamera src[], std::array<hako_msgs::msg::HakoCmdCamera, _dst_len> &dst)
{
    int ret = 0;
    int len = _dst_len;
    if (_dst_len > _src_len) {
        len = _src_len;
        ret = -1;
    }
    for (int i = 0; i < len; i++) {
        (void)hako_convert_pdu2ros_HakoCmdCamera(src[i], dst[i]);
    }
    return ret;
}
template<int _src_len, int _dst_len>
int hako_convert_pdu2ros_array_HakoCmdCamera(Hako_HakoCmdCamera src[], std::vector<hako_msgs::msg::HakoCmdCamera> &dst)
{
    dst.resize(_src_len);
    for (int i = 0; i < _src_len; i++) {
        (void)hako_convert_pdu2ros_HakoCmdCamera(src[i], dst[i]);
    }
    return 0;
}

/***************************
 *
 * ROS2 ==> PDU
 *
 ***************************/
static inline int hako_convert_ros2pdu_HakoCmdCamera(hako_msgs::msg::HakoCmdCamera &src, Hako_HakoCmdCamera &dst)
{
    //struct convert
    hako_convert_ros2pdu_HakoCmdHeader(src.header, dst.header);
    //primitive convert
    hako_convert_ros2pdu(src.request_id, dst.request_id);
    //primitive convert
    hako_convert_ros2pdu(src.encode_type, dst.encode_type);
    return 0;
}

template<int _src_len, int _dst_len>
int hako_convert_ros2pdu_array_HakoCmdCamera(std::array<hako_msgs::msg::HakoCmdCamera, _src_len> &src, Hako_HakoCmdCamera dst[])
{
    int ret = 0;
    int len = _dst_len;
    if (_dst_len > _src_len) {
        len = _src_len;
        ret = -1;
    }
    for (int i = 0; i < len; i++) {
        (void)hako_convert_ros2pdu_HakoCmdCamera(src[i], dst[i]);
    }
    return ret;
}
template<int _src_len, int _dst_len>
int hako_convert_ros2pdu_array_HakoCmdCamera(std::vector<hako_msgs::msg::HakoCmdCamera> &src, Hako_HakoCmdCamera dst[])
{
    int ret = 0;
    int len = _dst_len;
    if (_dst_len > _src_len) {
        len = _src_len;
        ret = -1;
    }
    for (int i = 0; i < len; i++) {
        (void)hako_convert_ros2pdu_HakoCmdCamera(src[i], dst[i]);
    }
    return ret;
}

#endif /* _PDU_CTYPE_CONV_HAKO_hako_msgs_HakoCmdCamera_HPP_ */
