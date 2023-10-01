#ifndef _PDU_CTYPE_CONV_HAKO_satelite_msgs_SateliteImu_HPP_
#define _PDU_CTYPE_CONV_HAKO_satelite_msgs_SateliteImu_HPP_

#include "pdu_primitive_ctypes.h"
#include "ros_primitive_types.hpp"
#include "pdu_primitive_ctypes_conv.hpp"
/*
 * Dependent pdu data
 */
#include "satelite_msgs/pdu_ctype_SateliteImu.h"
/*
 * Dependent ros data
 */
#include "satelite_msgs/msg/satelite_imu.hpp"

/*
 * Dependent Convertors
 */
#include "geometry_msgs/pdu_ctype_conv_Vector3.hpp"

/***************************
 *
 * PDU ==> ROS2
 *
 ***************************/
static inline int hako_convert_pdu2ros_SateliteImu(Hako_SateliteImu &src,  satelite_msgs::msg::SateliteImu &dst)
{
    //struct convert
    hako_convert_pdu2ros_Vector3(src.acc, dst.acc);
    //struct convert
    hako_convert_pdu2ros_Vector3(src.gyro, dst.gyro);
    //struct convert
    hako_convert_pdu2ros_Vector3(src.mag, dst.mag);
    return 0;
}

template<int _src_len, int _dst_len>
int hako_convert_pdu2ros_array_SateliteImu(Hako_SateliteImu src[], std::array<satelite_msgs::msg::SateliteImu, _dst_len> &dst)
{
    int ret = 0;
    int len = _dst_len;
    if (_dst_len > _src_len) {
        len = _src_len;
        ret = -1;
    }
    for (int i = 0; i < len; i++) {
        (void)hako_convert_pdu2ros_SateliteImu(src[i], dst[i]);
    }
    return ret;
}
template<int _src_len, int _dst_len>
int hako_convert_pdu2ros_array_SateliteImu(Hako_SateliteImu src[], std::vector<satelite_msgs::msg::SateliteImu> &dst)
{
    dst.resize(_src_len);
    for (int i = 0; i < _src_len; i++) {
        (void)hako_convert_pdu2ros_SateliteImu(src[i], dst[i]);
    }
    return 0;
}

/***************************
 *
 * ROS2 ==> PDU
 *
 ***************************/
static inline int hako_convert_ros2pdu_SateliteImu(satelite_msgs::msg::SateliteImu &src, Hako_SateliteImu &dst)
{
    //struct convert
    hako_convert_ros2pdu_Vector3(src.acc, dst.acc);
    //struct convert
    hako_convert_ros2pdu_Vector3(src.gyro, dst.gyro);
    //struct convert
    hako_convert_ros2pdu_Vector3(src.mag, dst.mag);
    return 0;
}

template<int _src_len, int _dst_len>
int hako_convert_ros2pdu_array_SateliteImu(std::array<satelite_msgs::msg::SateliteImu, _src_len> &src, Hako_SateliteImu dst[])
{
    int ret = 0;
    int len = _dst_len;
    if (_dst_len > _src_len) {
        len = _src_len;
        ret = -1;
    }
    for (int i = 0; i < len; i++) {
        (void)hako_convert_ros2pdu_SateliteImu(src[i], dst[i]);
    }
    return ret;
}
template<int _src_len, int _dst_len>
int hako_convert_ros2pdu_array_SateliteImu(std::vector<satelite_msgs::msg::SateliteImu> &src, Hako_SateliteImu dst[])
{
    int ret = 0;
    int len = _dst_len;
    if (_dst_len > _src_len) {
        len = _src_len;
        ret = -1;
    }
    for (int i = 0; i < len; i++) {
        (void)hako_convert_ros2pdu_SateliteImu(src[i], dst[i]);
    }
    return ret;
}

#endif /* _PDU_CTYPE_CONV_HAKO_satelite_msgs_SateliteImu_HPP_ */
