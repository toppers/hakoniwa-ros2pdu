#ifndef _PDU_CTYPE_CONV_HAKO_sensor_msgs_Image_HPP_
#define _PDU_CTYPE_CONV_HAKO_sensor_msgs_Image_HPP_

#include "pdu_primitive_ctypes.h"
#include "ros_primitive_types.hpp"
#include "pdu_primitive_ctypes_conv.hpp"
/*
 * Dependent pdu data
 */
#include "sensor_msgs/pdu_ctype_Image.h"
/*
 * Dependent ros data
 */
#include "sensor_msgs/msg/image.hpp"

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
static inline int hako_convert_pdu2ros_Image(Hako_Image &src,  sensor_msgs::msg::Image &dst)
{
    //struct convert
    hako_convert_pdu2ros_Header(src.header, dst.header);
    //primitive convert
    hako_convert_pdu2ros(src.height, dst.height);
    //primitive convert
    hako_convert_pdu2ros(src.width, dst.width);
    //string convertor
    dst.encoding = (const char*)src.encoding;
    //primitive convert
    hako_convert_pdu2ros(src.is_bigendian, dst.is_bigendian);
    //primitive convert
    hako_convert_pdu2ros(src.step, dst.step);
    //primitive array convertor
    (void)hako_convert_pdu2ros_array(
        src.data, M_ARRAY_SIZE(Hako_Image, Hako_uint8, data),
        dst.data, dst.data.size());
    return 0;
}

template<int _src_len, int _dst_len>
int hako_convert_pdu2ros_array_Image(Hako_Image src[], std::array<sensor_msgs::msg::Image, _dst_len> &dst)
{
    int ret = 0;
    int len = _dst_len;
    if (_dst_len > _src_len) {
        len = _src_len;
        ret = -1;
    }
    for (int i = 0; i < len; i++) {
        (void)hako_convert_pdu2ros_Image(src[i], dst[i]);
    }
    return ret;
}
template<int _src_len, int _dst_len>
int hako_convert_pdu2ros_array_Image(Hako_Image src[], std::vector<sensor_msgs::msg::Image> &dst)
{
    dst.resize(_src_len);
    for (int i = 0; i < _src_len; i++) {
        (void)hako_convert_pdu2ros_Image(src[i], dst[i]);
    }
    return 0;
}

/***************************
 *
 * ROS2 ==> PDU
 *
 ***************************/
static inline int hako_convert_ros2pdu_Image(sensor_msgs::msg::Image &src, Hako_Image &dst)
{
    //struct convert
    hako_convert_ros2pdu_Header(src.header, dst.header);
    //primitive convert
    hako_convert_ros2pdu(src.height, dst.height);
    //primitive convert
    hako_convert_ros2pdu(src.width, dst.width);
    //string convertor
    (void)hako_convert_ros2pdu_array(
        src.encoding, src.encoding.length(),
        dst.encoding, M_ARRAY_SIZE(Hako_Image, char, encoding));
    //primitive convert
    hako_convert_ros2pdu(src.is_bigendian, dst.is_bigendian);
    //primitive convert
    hako_convert_ros2pdu(src.step, dst.step);
    //primitive array convertor
    (void)hako_convert_ros2pdu_array(
        src.data, src.data.size(),
        dst.data, M_ARRAY_SIZE(Hako_Image, Hako_uint8, data));
    return 0;
}

template<int _src_len, int _dst_len>
int hako_convert_ros2pdu_array_Image(std::array<sensor_msgs::msg::Image, _src_len> &src, Hako_Image dst[])
{
    int ret = 0;
    int len = _dst_len;
    if (_dst_len > _src_len) {
        len = _src_len;
        ret = -1;
    }
    for (int i = 0; i < len; i++) {
        (void)hako_convert_ros2pdu_Image(src[i], dst[i]);
    }
    return ret;
}
template<int _src_len, int _dst_len>
int hako_convert_ros2pdu_array_Image(std::vector<sensor_msgs::msg::Image> &src, Hako_Image dst[])
{
    int ret = 0;
    int len = _dst_len;
    if (_dst_len > _src_len) {
        len = _src_len;
        ret = -1;
    }
    for (int i = 0; i < len; i++) {
        (void)hako_convert_ros2pdu_Image(src[i], dst[i]);
    }
    return ret;
}

#endif /* _PDU_CTYPE_CONV_HAKO_sensor_msgs_Image_HPP_ */
