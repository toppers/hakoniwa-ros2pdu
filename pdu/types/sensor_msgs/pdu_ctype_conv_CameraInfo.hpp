#ifndef _PDU_CTYPE_CONV_HAKO_sensor_msgs_CameraInfo_HPP_
#define _PDU_CTYPE_CONV_HAKO_sensor_msgs_CameraInfo_HPP_

#include "pdu_primitive_ctypes.h"
#include "ros_primitive_types.hpp"
#include "pdu_primitive_ctypes_conv.hpp"
/*
 * Dependent pdu data
 */
#include "sensor_msgs/pdu_ctype_CameraInfo.h"
/*
 * Dependent ros data
 */
#include "sensor_msgs/msg/camera_info.hpp"

/*
 * Dependent Convertors
 */
#include "builtin_interfaces/pdu_ctype_conv_Time.hpp"
#include "sensor_msgs/pdu_ctype_conv_RegionOfInterest.hpp"
#include "std_msgs/pdu_ctype_conv_Header.hpp"

/***************************
 *
 * PDU ==> ROS2
 *
 ***************************/
static inline int hako_convert_pdu2ros_CameraInfo(Hako_CameraInfo &src,  sensor_msgs::msg::CameraInfo &dst)
{
    //struct convert
    hako_convert_pdu2ros_Header(src.header, dst.header);
    //primitive convert
    hako_convert_pdu2ros(src.height, dst.height);
    //primitive convert
    hako_convert_pdu2ros(src.width, dst.width);
    //string convertor
    dst.distortion_model = (const char*)src.distortion_model;
    //primitive array convertor
    (void)hako_convert_pdu2ros_array(
        src.d, M_ARRAY_SIZE(Hako_CameraInfo, Hako_float64, d),
        dst.d, dst.d.size());
    //primitive array convertor
    (void)hako_convert_pdu2ros_array(
        src.k, M_ARRAY_SIZE(Hako_CameraInfo, Hako_float64, k),
        dst.k, dst.k.size());
    //primitive array convertor
    (void)hako_convert_pdu2ros_array(
        src.r, M_ARRAY_SIZE(Hako_CameraInfo, Hako_float64, r),
        dst.r, dst.r.size());
    //primitive array convertor
    (void)hako_convert_pdu2ros_array(
        src.p, M_ARRAY_SIZE(Hako_CameraInfo, Hako_float64, p),
        dst.p, dst.p.size());
    //primitive convert
    hako_convert_pdu2ros(src.binning_x, dst.binning_x);
    //primitive convert
    hako_convert_pdu2ros(src.binning_y, dst.binning_y);
    //struct convert
    hako_convert_pdu2ros_RegionOfInterest(src.roi, dst.roi);
    return 0;
}

template<int _src_len, int _dst_len>
int hako_convert_pdu2ros_array_CameraInfo(Hako_CameraInfo src[], std::array<sensor_msgs::msg::CameraInfo, _dst_len> &dst)
{
    int ret = 0;
    int len = _dst_len;
    if (_dst_len > _src_len) {
        len = _src_len;
        ret = -1;
    }
    for (int i = 0; i < len; i++) {
        (void)hako_convert_pdu2ros_CameraInfo(src[i], dst[i]);
    }
    return ret;
}
template<int _src_len, int _dst_len>
int hako_convert_pdu2ros_array_CameraInfo(Hako_CameraInfo src[], std::vector<sensor_msgs::msg::CameraInfo> &dst)
{
    dst.resize(_src_len);
    for (int i = 0; i < _src_len; i++) {
        (void)hako_convert_pdu2ros_CameraInfo(src[i], dst[i]);
    }
    return 0;
}

/***************************
 *
 * ROS2 ==> PDU
 *
 ***************************/
static inline int hako_convert_ros2pdu_CameraInfo(sensor_msgs::msg::CameraInfo &src, Hako_CameraInfo &dst)
{
    //struct convert
    hako_convert_ros2pdu_Header(src.header, dst.header);
    //primitive convert
    hako_convert_ros2pdu(src.height, dst.height);
    //primitive convert
    hako_convert_ros2pdu(src.width, dst.width);
    //string convertor
    (void)hako_convert_ros2pdu_array(
        src.distortion_model, src.distortion_model.length(),
        dst.distortion_model, M_ARRAY_SIZE(Hako_CameraInfo, char, distortion_model));
    //primitive array convertor
    (void)hako_convert_ros2pdu_array(
        src.d, src.d.size(),
        dst.d, M_ARRAY_SIZE(Hako_CameraInfo, Hako_float64, d));
    //primitive array convertor
    (void)hako_convert_ros2pdu_array(
        src.k, src.k.size(),
        dst.k, M_ARRAY_SIZE(Hako_CameraInfo, Hako_float64, k));
    //primitive array convertor
    (void)hako_convert_ros2pdu_array(
        src.r, src.r.size(),
        dst.r, M_ARRAY_SIZE(Hako_CameraInfo, Hako_float64, r));
    //primitive array convertor
    (void)hako_convert_ros2pdu_array(
        src.p, src.p.size(),
        dst.p, M_ARRAY_SIZE(Hako_CameraInfo, Hako_float64, p));
    //primitive convert
    hako_convert_ros2pdu(src.binning_x, dst.binning_x);
    //primitive convert
    hako_convert_ros2pdu(src.binning_y, dst.binning_y);
    //struct convert
    hako_convert_ros2pdu_RegionOfInterest(src.roi, dst.roi);
    return 0;
}

template<int _src_len, int _dst_len>
int hako_convert_ros2pdu_array_CameraInfo(std::array<sensor_msgs::msg::CameraInfo, _src_len> &src, Hako_CameraInfo dst[])
{
    int ret = 0;
    int len = _dst_len;
    if (_dst_len > _src_len) {
        len = _src_len;
        ret = -1;
    }
    for (int i = 0; i < len; i++) {
        (void)hako_convert_ros2pdu_CameraInfo(src[i], dst[i]);
    }
    return ret;
}
template<int _src_len, int _dst_len>
int hako_convert_ros2pdu_array_CameraInfo(std::vector<sensor_msgs::msg::CameraInfo> &src, Hako_CameraInfo dst[])
{
    int ret = 0;
    int len = _dst_len;
    if (_dst_len > _src_len) {
        len = _src_len;
        ret = -1;
    }
    for (int i = 0; i < len; i++) {
        (void)hako_convert_ros2pdu_CameraInfo(src[i], dst[i]);
    }
    return ret;
}

#endif /* _PDU_CTYPE_CONV_HAKO_sensor_msgs_CameraInfo_HPP_ */
