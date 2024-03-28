#ifndef _PDU_CTYPE_CONV_HAKO_hako_msgs_HakoCameraData_HPP_
#define _PDU_CTYPE_CONV_HAKO_hako_msgs_HakoCameraData_HPP_

#include "pdu_primitive_ctypes.h"
#include "ros_primitive_types.hpp"
#include "pdu_primitive_ctypes_conv.hpp"
/*
 * Dependent pdu data
 */
#include "hako_msgs/pdu_ctype_HakoCameraData.h"
/*
 * Dependent ros data
 */
#include "hako_msgs/msg/hako_camera_data.hpp"

/*
 * Dependent Convertors
 */
#include "builtin_interfaces/pdu_ctype_conv_Time.hpp"
#include "sensor_msgs/pdu_ctype_conv_CompressedImage.hpp"
#include "std_msgs/pdu_ctype_conv_Header.hpp"

/***************************
 *
 * PDU ==> ROS2
 *
 ***************************/
static inline int hako_convert_pdu2ros_HakoCameraData(Hako_HakoCameraData &src,  hako_msgs::msg::HakoCameraData &dst)
{
    //primitive convert
    hako_convert_pdu2ros(src.request_id, dst.request_id);
    //struct convert
    hako_convert_pdu2ros_CompressedImage(src.image, dst.image);
    return 0;
}

template<int _src_len, int _dst_len>
int hako_convert_pdu2ros_array_HakoCameraData(Hako_HakoCameraData src[], std::array<hako_msgs::msg::HakoCameraData, _dst_len> &dst)
{
    int ret = 0;
    int len = _dst_len;
    if (_dst_len > _src_len) {
        len = _src_len;
        ret = -1;
    }
    for (int i = 0; i < len; i++) {
        (void)hako_convert_pdu2ros_HakoCameraData(src[i], dst[i]);
    }
    return ret;
}
template<int _src_len, int _dst_len>
int hako_convert_pdu2ros_array_HakoCameraData(Hako_HakoCameraData src[], std::vector<hako_msgs::msg::HakoCameraData> &dst)
{
    dst.resize(_src_len);
    for (int i = 0; i < _src_len; i++) {
        (void)hako_convert_pdu2ros_HakoCameraData(src[i], dst[i]);
    }
    return 0;
}

/***************************
 *
 * ROS2 ==> PDU
 *
 ***************************/
static inline int hako_convert_ros2pdu_HakoCameraData(hako_msgs::msg::HakoCameraData &src, Hako_HakoCameraData &dst)
{
    //primitive convert
    hako_convert_ros2pdu(src.request_id, dst.request_id);
    //struct convert
    hako_convert_ros2pdu_CompressedImage(src.image, dst.image);
    return 0;
}

template<int _src_len, int _dst_len>
int hako_convert_ros2pdu_array_HakoCameraData(std::array<hako_msgs::msg::HakoCameraData, _src_len> &src, Hako_HakoCameraData dst[])
{
    int ret = 0;
    int len = _dst_len;
    if (_dst_len > _src_len) {
        len = _src_len;
        ret = -1;
    }
    for (int i = 0; i < len; i++) {
        (void)hako_convert_ros2pdu_HakoCameraData(src[i], dst[i]);
    }
    return ret;
}
template<int _src_len, int _dst_len>
int hako_convert_ros2pdu_array_HakoCameraData(std::vector<hako_msgs::msg::HakoCameraData> &src, Hako_HakoCameraData dst[])
{
    int ret = 0;
    int len = _dst_len;
    if (_dst_len > _src_len) {
        len = _src_len;
        ret = -1;
    }
    for (int i = 0; i < len; i++) {
        (void)hako_convert_ros2pdu_HakoCameraData(src[i], dst[i]);
    }
    return ret;
}

#endif /* _PDU_CTYPE_CONV_HAKO_hako_msgs_HakoCameraData_HPP_ */
