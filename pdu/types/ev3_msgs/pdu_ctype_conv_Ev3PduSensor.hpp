#ifndef _PDU_CTYPE_CONV_HAKO_ev3_msgs_Ev3PduSensor_HPP_
#define _PDU_CTYPE_CONV_HAKO_ev3_msgs_Ev3PduSensor_HPP_

#include "pdu_primitive_ctypes.h"
#include "ros_primitive_types.hpp"
#include "pdu_primitive_ctypes_conv.hpp"
/*
 * Dependent pdu data
 */
#include "ev3_msgs/pdu_ctype_Ev3PduSensor.h"
/*
 * Dependent ros data
 */
#include "ev3_msgs/msg/ev3_pdu_sensor.hpp"

/*
 * Dependent Convertors
 */
#include "pdu_ctype_conv_Ev3PduColorSensor.hpp"
#include "pdu_ctype_conv_Ev3PduSensorHeader.hpp"
#include "pdu_ctype_conv_Ev3PduTouchSensor.hpp"

/***************************
 *
 * PDU ==> ROS2
 *
 ***************************/
static inline int hako_convert_pdu2ros_Ev3PduSensor(Hako_Ev3PduSensor &src,  ev3_msgs::msg::Ev3PduSensor &dst)
{
    //struct convert
    hako_convert_pdu2ros_Ev3PduSensorHeader(src.head, dst.head);
    //primitive array convertor
    (void)hako_convert_pdu2ros_array(
        src.buttons, M_ARRAY_SIZE(Hako_Ev3PduSensor, Hako_uint8, buttons),
        dst.buttons, 1);
    //struct array convertor
    (void)hako_convert_pdu2ros_array_Ev3PduColorSensor<M_ARRAY_SIZE(Hako_Ev3PduSensor, Hako_Ev3PduColorSensor, color_sensors), 2>(
        src.color_sensors, dst.color_sensors);
    //struct array convertor
    (void)hako_convert_pdu2ros_array_Ev3PduTouchSensor<M_ARRAY_SIZE(Hako_Ev3PduSensor, Hako_Ev3PduTouchSensor, touch_sensors), 2>(
        src.touch_sensors, dst.touch_sensors);
    //primitive array convertor
    (void)hako_convert_pdu2ros_array(
        src.motor_angle, M_ARRAY_SIZE(Hako_Ev3PduSensor, Hako_uint32, motor_angle),
        dst.motor_angle, 3);
    //primitive convert
    hako_convert_pdu2ros(src.gyro_degree, dst.gyro_degree);
    //primitive convert
    hako_convert_pdu2ros(src.gyro_degree_rate, dst.gyro_degree_rate);
    //primitive convert
    hako_convert_pdu2ros(src.sensor_ultrasonic, dst.sensor_ultrasonic);
    //primitive convert
    hako_convert_pdu2ros(src.gps_lat, dst.gps_lat);
    //primitive convert
    hako_convert_pdu2ros(src.gps_lon, dst.gps_lon);
    return 0;
}

template<int _src_len, int _dst_len>
int hako_convert_pdu2ros_array_Ev3PduSensor(Hako_Ev3PduSensor src[], std::array<ev3_msgs::msg::Ev3PduSensor, _dst_len> &dst)
{
    int ret = 0;
    int len = _dst_len;
    if (_dst_len < _src_len) {
        len = _src_len;
        ret = -1;
    }
    for (int i = 0; i < len; i++) {
        (void)hako_convert_pdu2ros_Ev3PduSensor(src[i], dst[i]);
    }
    return ret;
}

/***************************
 *
 * ROS2 ==> PDU
 *
 ***************************/
static inline int hako_convert_ros2pdu_Ev3PduSensor(ev3_msgs::msg::Ev3PduSensor &src, Hako_Ev3PduSensor &dst)
{
    //struct convert
    hako_convert_ros2pdu_Ev3PduSensorHeader(src.head, dst.head);
    //primitive array convertor
    (void)hako_convert_ros2pdu_array(
        src.buttons, 1,
        dst.buttons, M_ARRAY_SIZE(Hako_Ev3PduSensor, Hako_uint8, buttons));
    //struct array convertor
    (void)hako_convert_ros2pdu_array_Ev3PduColorSensor<2, M_ARRAY_SIZE(Hako_Ev3PduSensor, Hako_Ev3PduColorSensor, color_sensors)>(
        src.color_sensors, dst.color_sensors);
    //struct array convertor
    (void)hako_convert_ros2pdu_array_Ev3PduTouchSensor<2, M_ARRAY_SIZE(Hako_Ev3PduSensor, Hako_Ev3PduTouchSensor, touch_sensors)>(
        src.touch_sensors, dst.touch_sensors);
    //primitive array convertor
    (void)hako_convert_ros2pdu_array(
        src.motor_angle, 3,
        dst.motor_angle, M_ARRAY_SIZE(Hako_Ev3PduSensor, Hako_uint32, motor_angle));
    //primitive convert
    hako_convert_ros2pdu(src.gyro_degree, dst.gyro_degree);
    //primitive convert
    hako_convert_ros2pdu(src.gyro_degree_rate, dst.gyro_degree_rate);
    //primitive convert
    hako_convert_ros2pdu(src.sensor_ultrasonic, dst.sensor_ultrasonic);
    //primitive convert
    hako_convert_ros2pdu(src.gps_lat, dst.gps_lat);
    //primitive convert
    hako_convert_ros2pdu(src.gps_lon, dst.gps_lon);
    return 0;
}

template<int _src_len, int _dst_len>
int hako_convert_ros2pdu_array_Ev3PduSensor(std::array<ev3_msgs::msg::Ev3PduSensor, _src_len> &src, Hako_Ev3PduSensor dst[])
{
    int ret = 0;
    int len = _dst_len;
    if (_dst_len < _src_len) {
        len = _src_len;
        ret = -1;
    }
    for (int i = 0; i < len; i++) {
        (void)hako_convert_ros2pdu_Ev3PduSensor(src[i], dst[i]);
    }
    return ret;
}
#endif /* _PDU_CTYPE_CONV_HAKO_ev3_msgs_Ev3PduSensor_HPP_ */
