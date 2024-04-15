#ifndef _PDU_CTYPE_CONV_HAKO_sensor_msgs_PointField_HPP_
#define _PDU_CTYPE_CONV_HAKO_sensor_msgs_PointField_HPP_

#include "pdu_primitive_ctypes.h"
#include "ros_primitive_types.hpp"
#include "pdu_primitive_ctypes_conv.hpp"
/*
 * Dependent pdu data
 */
#include "sensor_msgs/pdu_ctype_PointField.h"
/*
 * Dependent ros data
 */
#include "sensor_msgs/msg/point_field.hpp"

/*
 * Dependent Convertors
 */

/***************************
 *
 * PDU ==> ROS2
 *
 ***************************/
static inline int hako_convert_pdu2ros_PointField(Hako_PointField &src,  sensor_msgs::msg::PointField &dst)
{
    //string convertor
    dst.name = (const char*)src.name;
    //primitive convert
    hako_convert_pdu2ros(src.offset, dst.offset);
    //primitive convert
    hako_convert_pdu2ros(src.datatype, dst.datatype);
    //primitive convert
    hako_convert_pdu2ros(src.count, dst.count);
    return 0;
}

template<int _src_len, int _dst_len>
int hako_convert_pdu2ros_array_PointField(Hako_PointField src[], std::array<sensor_msgs::msg::PointField, _dst_len> &dst)
{
    int ret = 0;
    int len = _dst_len;
    if (_dst_len > _src_len) {
        len = _src_len;
        ret = -1;
    }
    for (int i = 0; i < len; i++) {
        (void)hako_convert_pdu2ros_PointField(src[i], dst[i]);
    }
    return ret;
}
template<int _src_len, int _dst_len>
int hako_convert_pdu2ros_array_PointField(Hako_PointField src[], std::vector<sensor_msgs::msg::PointField> &dst)
{
    dst.resize(_src_len);
    for (int i = 0; i < _src_len; i++) {
        (void)hako_convert_pdu2ros_PointField(src[i], dst[i]);
    }
    return 0;
}

/***************************
 *
 * ROS2 ==> PDU
 *
 ***************************/
static inline int hako_convert_ros2pdu_PointField(sensor_msgs::msg::PointField &src, Hako_PointField &dst)
{
    //string convertor
    (void)hako_convert_ros2pdu_array(
        src.name, src.name.length(),
        dst.name, M_ARRAY_SIZE(Hako_PointField, char, name));
    //primitive convert
    hako_convert_ros2pdu(src.offset, dst.offset);
    //primitive convert
    hako_convert_ros2pdu(src.datatype, dst.datatype);
    //primitive convert
    hako_convert_ros2pdu(src.count, dst.count);
    return 0;
}

template<int _src_len, int _dst_len>
int hako_convert_ros2pdu_array_PointField(std::array<sensor_msgs::msg::PointField, _src_len> &src, Hako_PointField dst[])
{
    int ret = 0;
    int len = _dst_len;
    if (_dst_len > _src_len) {
        len = _src_len;
        ret = -1;
    }
    for (int i = 0; i < len; i++) {
        (void)hako_convert_ros2pdu_PointField(src[i], dst[i]);
    }
    return ret;
}
template<int _src_len, int _dst_len>
int hako_convert_ros2pdu_array_PointField(std::vector<sensor_msgs::msg::PointField> &src, Hako_PointField dst[])
{
    int ret = 0;
    int len = _dst_len;
    if (_dst_len > _src_len) {
        len = _src_len;
        ret = -1;
    }
    for (int i = 0; i < len; i++) {
        (void)hako_convert_ros2pdu_PointField(src[i], dst[i]);
    }
    return ret;
}

#endif /* _PDU_CTYPE_CONV_HAKO_sensor_msgs_PointField_HPP_ */
