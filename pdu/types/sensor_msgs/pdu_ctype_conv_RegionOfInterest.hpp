#ifndef _PDU_CTYPE_CONV_HAKO_sensor_msgs_RegionOfInterest_HPP_
#define _PDU_CTYPE_CONV_HAKO_sensor_msgs_RegionOfInterest_HPP_

#include "pdu_primitive_ctypes.h"
#include "ros_primitive_types.hpp"
#include "pdu_primitive_ctypes_conv.hpp"
/*
 * Dependent pdu data
 */
#include "sensor_msgs/pdu_ctype_RegionOfInterest.h"
/*
 * Dependent ros data
 */
#include "sensor_msgs/msg/region_of_interest.hpp"

/*
 * Dependent Convertors
 */

/***************************
 *
 * PDU ==> ROS2
 *
 ***************************/
static inline int hako_convert_pdu2ros_RegionOfInterest(Hako_RegionOfInterest &src,  sensor_msgs::msg::RegionOfInterest &dst)
{
    //primitive convert
    hako_convert_pdu2ros(src.x_offset, dst.x_offset);
    //primitive convert
    hako_convert_pdu2ros(src.y_offset, dst.y_offset);
    //primitive convert
    hako_convert_pdu2ros(src.height, dst.height);
    //primitive convert
    hako_convert_pdu2ros(src.width, dst.width);
    //primitive convert
    hako_convert_pdu2ros(src.do_rectify, dst.do_rectify);
    return 0;
}

template<int _src_len, int _dst_len>
int hako_convert_pdu2ros_array_RegionOfInterest(Hako_RegionOfInterest src[], std::array<sensor_msgs::msg::RegionOfInterest, _dst_len> &dst)
{
    int ret = 0;
    int len = _dst_len;
    if (_dst_len > _src_len) {
        len = _src_len;
        ret = -1;
    }
    for (int i = 0; i < len; i++) {
        (void)hako_convert_pdu2ros_RegionOfInterest(src[i], dst[i]);
    }
    return ret;
}
template<int _src_len, int _dst_len>
int hako_convert_pdu2ros_array_RegionOfInterest(Hako_RegionOfInterest src[], std::vector<sensor_msgs::msg::RegionOfInterest> &dst)
{
    dst.resize(_src_len);
    for (int i = 0; i < _src_len; i++) {
        (void)hako_convert_pdu2ros_RegionOfInterest(src[i], dst[i]);
    }
    return 0;
}

/***************************
 *
 * ROS2 ==> PDU
 *
 ***************************/
static inline int hako_convert_ros2pdu_RegionOfInterest(sensor_msgs::msg::RegionOfInterest &src, Hako_RegionOfInterest &dst)
{
    //primitive convert
    hako_convert_ros2pdu(src.x_offset, dst.x_offset);
    //primitive convert
    hako_convert_ros2pdu(src.y_offset, dst.y_offset);
    //primitive convert
    hako_convert_ros2pdu(src.height, dst.height);
    //primitive convert
    hako_convert_ros2pdu(src.width, dst.width);
    //primitive convert
    hako_convert_ros2pdu(src.do_rectify, dst.do_rectify);
    return 0;
}

template<int _src_len, int _dst_len>
int hako_convert_ros2pdu_array_RegionOfInterest(std::array<sensor_msgs::msg::RegionOfInterest, _src_len> &src, Hako_RegionOfInterest dst[])
{
    int ret = 0;
    int len = _dst_len;
    if (_dst_len > _src_len) {
        len = _src_len;
        ret = -1;
    }
    for (int i = 0; i < len; i++) {
        (void)hako_convert_ros2pdu_RegionOfInterest(src[i], dst[i]);
    }
    return ret;
}
template<int _src_len, int _dst_len>
int hako_convert_ros2pdu_array_RegionOfInterest(std::vector<sensor_msgs::msg::RegionOfInterest> &src, Hako_RegionOfInterest dst[])
{
    int ret = 0;
    int len = _dst_len;
    if (_dst_len > _src_len) {
        len = _src_len;
        ret = -1;
    }
    for (int i = 0; i < len; i++) {
        (void)hako_convert_ros2pdu_RegionOfInterest(src[i], dst[i]);
    }
    return ret;
}

#endif /* _PDU_CTYPE_CONV_HAKO_sensor_msgs_RegionOfInterest_HPP_ */
