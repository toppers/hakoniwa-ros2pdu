#ifndef _PDU_CTYPE_CONV_HAKO_sensor_msgs_Imu_HPP_
#define _PDU_CTYPE_CONV_HAKO_sensor_msgs_Imu_HPP_

#include "pdu_primitive_ctypes.h"
#include "ros_primitive_types.hpp"
#include "pdu_primitive_ctypes_conv.hpp"
/*
 * Dependent pdu data
 */
#include "sensor_msgs/pdu_ctype_Imu.h"
/*
 * Dependent ros data
 */
#include "sensor_msgs/msg/imu.hpp"

/*
 * Dependent Convertors
 */
#include "builtin_interfaces/pdu_ctype_conv_Time.hpp"
#include "geometry_msgs/pdu_ctype_conv_Quaternion.hpp"
#include "geometry_msgs/pdu_ctype_conv_Vector3.hpp"
#include "std_msgs/pdu_ctype_conv_Header.hpp"

/***************************
 *
 * PDU ==> ROS2
 *
 ***************************/
static inline int hako_convert_pdu2ros_Imu(Hako_Imu &src,  sensor_msgs::msg::Imu &dst)
{
    //struct convert
    hako_convert_pdu2ros_Header(src.header, dst.header);
    //struct convert
    hako_convert_pdu2ros_Quaternion(src.orientation, dst.orientation);
    //primitive array convertor
    (void)hako_convert_pdu2ros_array(
        src.orientation_covariance, M_ARRAY_SIZE(Hako_Imu, Hako_float64, orientation_covariance),
        dst.orientation_covariance, dst.orientation_covariance.size());
    //struct convert
    hako_convert_pdu2ros_Vector3(src.angular_velocity, dst.angular_velocity);
    //primitive array convertor
    (void)hako_convert_pdu2ros_array(
        src.angular_velocity_covariance, M_ARRAY_SIZE(Hako_Imu, Hako_float64, angular_velocity_covariance),
        dst.angular_velocity_covariance, dst.angular_velocity_covariance.size());
    //struct convert
    hako_convert_pdu2ros_Vector3(src.linear_acceleration, dst.linear_acceleration);
    //primitive array convertor
    (void)hako_convert_pdu2ros_array(
        src.linear_acceleration_covariance, M_ARRAY_SIZE(Hako_Imu, Hako_float64, linear_acceleration_covariance),
        dst.linear_acceleration_covariance, dst.linear_acceleration_covariance.size());
    return 0;
}

template<int _src_len, int _dst_len>
int hako_convert_pdu2ros_array_Imu(Hako_Imu src[], std::array<sensor_msgs::msg::Imu, _dst_len> &dst)
{
    int ret = 0;
    int len = _dst_len;
    if (_dst_len > _src_len) {
        len = _src_len;
        ret = -1;
    }
    for (int i = 0; i < len; i++) {
        (void)hako_convert_pdu2ros_Imu(src[i], dst[i]);
    }
    return ret;
}
template<int _src_len, int _dst_len>
int hako_convert_pdu2ros_array_Imu(Hako_Imu src[], std::vector<sensor_msgs::msg::Imu> &dst)
{
    dst.resize(_src_len);
    for (int i = 0; i < _src_len; i++) {
        (void)hako_convert_pdu2ros_Imu(src[i], dst[i]);
    }
    return 0;
}

/***************************
 *
 * ROS2 ==> PDU
 *
 ***************************/
static inline int hako_convert_ros2pdu_Imu(sensor_msgs::msg::Imu &src, Hako_Imu &dst)
{
    //struct convert
    hako_convert_ros2pdu_Header(src.header, dst.header);
    //struct convert
    hako_convert_ros2pdu_Quaternion(src.orientation, dst.orientation);
    //primitive array convertor
    (void)hako_convert_ros2pdu_array(
        src.orientation_covariance, src.orientation_covariance.size(),
        dst.orientation_covariance, M_ARRAY_SIZE(Hako_Imu, Hako_float64, orientation_covariance));
    //struct convert
    hako_convert_ros2pdu_Vector3(src.angular_velocity, dst.angular_velocity);
    //primitive array convertor
    (void)hako_convert_ros2pdu_array(
        src.angular_velocity_covariance, src.angular_velocity_covariance.size(),
        dst.angular_velocity_covariance, M_ARRAY_SIZE(Hako_Imu, Hako_float64, angular_velocity_covariance));
    //struct convert
    hako_convert_ros2pdu_Vector3(src.linear_acceleration, dst.linear_acceleration);
    //primitive array convertor
    (void)hako_convert_ros2pdu_array(
        src.linear_acceleration_covariance, src.linear_acceleration_covariance.size(),
        dst.linear_acceleration_covariance, M_ARRAY_SIZE(Hako_Imu, Hako_float64, linear_acceleration_covariance));
    return 0;
}

template<int _src_len, int _dst_len>
int hako_convert_ros2pdu_array_Imu(std::array<sensor_msgs::msg::Imu, _src_len> &src, Hako_Imu dst[])
{
    int ret = 0;
    int len = _dst_len;
    if (_dst_len > _src_len) {
        len = _src_len;
        ret = -1;
    }
    for (int i = 0; i < len; i++) {
        (void)hako_convert_ros2pdu_Imu(src[i], dst[i]);
    }
    return ret;
}
template<int _src_len, int _dst_len>
int hako_convert_ros2pdu_array_Imu(std::vector<sensor_msgs::msg::Imu> &src, Hako_Imu dst[])
{
    int ret = 0;
    int len = _dst_len;
    if (_dst_len > _src_len) {
        len = _src_len;
        ret = -1;
    }
    for (int i = 0; i < len; i++) {
        (void)hako_convert_ros2pdu_Imu(src[i], dst[i]);
    }
    return ret;
}

#endif /* _PDU_CTYPE_CONV_HAKO_sensor_msgs_Imu_HPP_ */
