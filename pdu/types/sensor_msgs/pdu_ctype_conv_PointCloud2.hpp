#ifndef _PDU_CTYPE_CONV_HAKO_sensor_msgs_PointCloud2_HPP_
#define _PDU_CTYPE_CONV_HAKO_sensor_msgs_PointCloud2_HPP_

#include "pdu_primitive_ctypes.h"
#include "ros_primitive_types.hpp"
#include "pdu_primitive_ctypes_conv.hpp"
/*
 * Dependent pdu data
 */
#include "sensor_msgs/pdu_ctype_PointCloud2.h"
/*
 * Dependent ros data
 */
#include "sensor_msgs/msg/point_cloud2.hpp"

/*
 * Dependent Convertors
 */
#include "builtin_interfaces/pdu_ctype_conv_Time.hpp"
#include "sensor_msgs/pdu_ctype_conv_PointField.hpp"
#include "std_msgs/pdu_ctype_conv_Header.hpp"

/***************************
 *
 * PDU ==> ROS2
 *
 ***************************/
static inline int hako_convert_pdu2ros_PointCloud2(Hako_PointCloud2 &src,  sensor_msgs::msg::PointCloud2 &dst)
{
    //struct convert
    hako_convert_pdu2ros_Header(src.header, dst.header);
    //primitive convert
    hako_convert_pdu2ros(src.height, dst.height);
    //primitive convert
    hako_convert_pdu2ros(src.width, dst.width);
    //struct array convertor
    (void)hako_convert_pdu2ros_array_PointField<M_ARRAY_SIZE(Hako_PointCloud2, Hako_PointField, fields), 4>(
        src.fields, dst.fields);
    //primitive convert
    hako_convert_pdu2ros(src.is_bigendian, dst.is_bigendian);
    //primitive convert
    hako_convert_pdu2ros(src.point_step, dst.point_step);
    //primitive convert
    hako_convert_pdu2ros(src.row_step, dst.row_step);
    //primitive array convertor
    (void)hako_convert_pdu2ros_array(
        src.data, M_ARRAY_SIZE(Hako_PointCloud2, Hako_uint8, data),
        dst.data, dst.data.size());
    //primitive convert
    hako_convert_pdu2ros(src.is_dense, dst.is_dense);
    return 0;
}

template<int _src_len, int _dst_len>
int hako_convert_pdu2ros_array_PointCloud2(Hako_PointCloud2 src[], std::array<sensor_msgs::msg::PointCloud2, _dst_len> &dst)
{
    int ret = 0;
    int len = _dst_len;
    if (_dst_len > _src_len) {
        len = _src_len;
        ret = -1;
    }
    for (int i = 0; i < len; i++) {
        (void)hako_convert_pdu2ros_PointCloud2(src[i], dst[i]);
    }
    return ret;
}
template<int _src_len, int _dst_len>
int hako_convert_pdu2ros_array_PointCloud2(Hako_PointCloud2 src[], std::vector<sensor_msgs::msg::PointCloud2> &dst)
{
    dst.resize(_src_len);
    for (int i = 0; i < _src_len; i++) {
        (void)hako_convert_pdu2ros_PointCloud2(src[i], dst[i]);
    }
    return 0;
}

/***************************
 *
 * ROS2 ==> PDU
 *
 ***************************/
static inline int hako_convert_ros2pdu_PointCloud2(sensor_msgs::msg::PointCloud2 &src, Hako_PointCloud2 &dst)
{
    //struct convert
    hako_convert_ros2pdu_Header(src.header, dst.header);
    //primitive convert
    hako_convert_ros2pdu(src.height, dst.height);
    //primitive convert
    hako_convert_ros2pdu(src.width, dst.width);
    //struct array convertor
    (void)hako_convert_ros2pdu_array_PointField<4, M_ARRAY_SIZE(Hako_PointCloud2, Hako_PointField, fields)>(
        src.fields, dst.fields);
    //primitive convert
    hako_convert_ros2pdu(src.is_bigendian, dst.is_bigendian);
    //primitive convert
    hako_convert_ros2pdu(src.point_step, dst.point_step);
    //primitive convert
    hako_convert_ros2pdu(src.row_step, dst.row_step);
    //primitive array convertor
    (void)hako_convert_ros2pdu_array(
        src.data, src.data.size(),
        dst.data, M_ARRAY_SIZE(Hako_PointCloud2, Hako_uint8, data));
    //primitive convert
    hako_convert_ros2pdu(src.is_dense, dst.is_dense);
    return 0;
}

template<int _src_len, int _dst_len>
int hako_convert_ros2pdu_array_PointCloud2(std::array<sensor_msgs::msg::PointCloud2, _src_len> &src, Hako_PointCloud2 dst[])
{
    int ret = 0;
    int len = _dst_len;
    if (_dst_len > _src_len) {
        len = _src_len;
        ret = -1;
    }
    for (int i = 0; i < len; i++) {
        (void)hako_convert_ros2pdu_PointCloud2(src[i], dst[i]);
    }
    return ret;
}
template<int _src_len, int _dst_len>
int hako_convert_ros2pdu_array_PointCloud2(std::vector<sensor_msgs::msg::PointCloud2> &src, Hako_PointCloud2 dst[])
{
    int ret = 0;
    int len = _dst_len;
    if (_dst_len > _src_len) {
        len = _src_len;
        ret = -1;
    }
    for (int i = 0; i < len; i++) {
        (void)hako_convert_ros2pdu_PointCloud2(src[i], dst[i]);
    }
    return ret;
}

#endif /* _PDU_CTYPE_CONV_HAKO_sensor_msgs_PointCloud2_HPP_ */
