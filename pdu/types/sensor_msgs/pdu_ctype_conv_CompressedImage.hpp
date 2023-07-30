#ifndef _PDU_CTYPE_CONV_HAKO_sensor_msgs_CompressedImage_HPP_
#define _PDU_CTYPE_CONV_HAKO_sensor_msgs_CompressedImage_HPP_

#include "pdu_primitive_ctypes.h"
#include "ros_primitive_types.hpp"
#include "pdu_primitive_ctypes_conv.hpp"
/*
 * Dependent pdu data
 */
#include "sensor_msgs/pdu_ctype_CompressedImage.h"
/*
 * Dependent ros data
 */
#include "sensor_msgs/msg/compressed_image.hpp"

/*
 * Dependent Convertors
 */
#include "builtin_interfaces/pdu_ctype_conv_Time.hpp"
#include "std_msgs/pdu_ctype_conv_Header.hpp"

/***************************
 *
 * PDU ==> ROS2
 *
 ***************************/
static inline int hako_convert_pdu2ros_CompressedImage(Hako_CompressedImage &src,  sensor_msgs::msg::CompressedImage &dst)
{
    //struct convert
    hako_convert_pdu2ros_Header(src.header, dst.header);
    //string convertor
    dst.format = (const char*)src.format;
    //primitive array convertor
    (void)hako_convert_pdu2ros_array(
        src.data, M_ARRAY_SIZE(Hako_CompressedImage, Hako_uint8, data),
        dst.data, dst.data.size());
    return 0;
}

template<int _src_len, int _dst_len>
int hako_convert_pdu2ros_array_CompressedImage(Hako_CompressedImage src[], std::array<sensor_msgs::msg::CompressedImage, _dst_len> &dst)
{
    int ret = 0;
    int len = _dst_len;
    if (_dst_len > _src_len) {
        len = _src_len;
        ret = -1;
    }
    for (int i = 0; i < len; i++) {
        (void)hako_convert_pdu2ros_CompressedImage(src[i], dst[i]);
    }
    return ret;
}
template<int _src_len, int _dst_len>
int hako_convert_pdu2ros_array_CompressedImage(Hako_CompressedImage src[], std::vector<sensor_msgs::msg::CompressedImage> &dst)
{
    dst.resize(_src_len);
    for (int i = 0; i < _src_len; i++) {
        (void)hako_convert_pdu2ros_CompressedImage(src[i], dst[i]);
    }
    return 0;
}

/***************************
 *
 * ROS2 ==> PDU
 *
 ***************************/
static inline int hako_convert_ros2pdu_CompressedImage(sensor_msgs::msg::CompressedImage &src, Hako_CompressedImage &dst)
{
    //struct convert
    hako_convert_ros2pdu_Header(src.header, dst.header);
    //string convertor
    (void)hako_convert_ros2pdu_array(
        src.format, src.format.length(),
        dst.format, M_ARRAY_SIZE(Hako_CompressedImage, char, format));
    //primitive array convertor
    (void)hako_convert_ros2pdu_array(
        src.data, src.data.size(),
        dst.data, M_ARRAY_SIZE(Hako_CompressedImage, Hako_uint8, data));
    return 0;
}

template<int _src_len, int _dst_len>
int hako_convert_ros2pdu_array_CompressedImage(std::array<sensor_msgs::msg::CompressedImage, _src_len> &src, Hako_CompressedImage dst[])
{
    int ret = 0;
    int len = _dst_len;
    if (_dst_len > _src_len) {
        len = _src_len;
        ret = -1;
    }
    for (int i = 0; i < len; i++) {
        (void)hako_convert_ros2pdu_CompressedImage(src[i], dst[i]);
    }
    return ret;
}
template<int _src_len, int _dst_len>
int hako_convert_ros2pdu_array_CompressedImage(std::vector<sensor_msgs::msg::CompressedImage> &src, Hako_CompressedImage dst[])
{
    int ret = 0;
    int len = _dst_len;
    if (_dst_len > _src_len) {
        len = _src_len;
        ret = -1;
    }
    for (int i = 0; i < len; i++) {
        (void)hako_convert_ros2pdu_CompressedImage(src[i], dst[i]);
    }
    return ret;
}

#endif /* _PDU_CTYPE_CONV_HAKO_sensor_msgs_CompressedImage_HPP_ */
