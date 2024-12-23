#ifndef _PDU_CTYPE_CONV_HAKO_hako_mavlink_msgs_HakoHilSensor_HPP_
#define _PDU_CTYPE_CONV_HAKO_hako_mavlink_msgs_HakoHilSensor_HPP_

#include "pdu_primitive_ctypes.h"
#include "ros_primitive_types.hpp"
#include "pdu_primitive_ctypes_conv.hpp"
#include "pdu_dynamic_memory.hpp"
/*
 * Dependent pdu data
 */
#include "hako_mavlink_msgs/pdu_ctype_HakoHilSensor.h"
/*
 * Dependent ros data
 */
#include "hako_mavlink_msgs/msg/hako_hil_sensor.hpp"

/*
 * Dependent Convertors
 */

/***************************
 *
 * PDU ==> ROS2
 *
 ***************************/

static inline int _pdu2ros_HakoHilSensor(const char* heap_ptr, Hako_HakoHilSensor &src, hako_mavlink_msgs::msg::HakoHilSensor &dst)
{
    // primitive convert
    hako_convert_pdu2ros(src.time_usec, dst.time_usec);
    // primitive convert
    hako_convert_pdu2ros(src.xacc, dst.xacc);
    // primitive convert
    hako_convert_pdu2ros(src.yacc, dst.yacc);
    // primitive convert
    hako_convert_pdu2ros(src.zacc, dst.zacc);
    // primitive convert
    hako_convert_pdu2ros(src.xgyro, dst.xgyro);
    // primitive convert
    hako_convert_pdu2ros(src.ygyro, dst.ygyro);
    // primitive convert
    hako_convert_pdu2ros(src.zgyro, dst.zgyro);
    // primitive convert
    hako_convert_pdu2ros(src.xmag, dst.xmag);
    // primitive convert
    hako_convert_pdu2ros(src.ymag, dst.ymag);
    // primitive convert
    hako_convert_pdu2ros(src.zmag, dst.zmag);
    // primitive convert
    hako_convert_pdu2ros(src.abs_pressure, dst.abs_pressure);
    // primitive convert
    hako_convert_pdu2ros(src.diff_pressure, dst.diff_pressure);
    // primitive convert
    hako_convert_pdu2ros(src.pressure_alt, dst.pressure_alt);
    // primitive convert
    hako_convert_pdu2ros(src.temperature, dst.temperature);
    // primitive convert
    hako_convert_pdu2ros(src.fields_updated, dst.fields_updated);
    // primitive convert
    hako_convert_pdu2ros(src.id, dst.id);
    (void)heap_ptr;
    return 0;
}

static inline int hako_convert_pdu2ros_HakoHilSensor(Hako_HakoHilSensor &src, hako_mavlink_msgs::msg::HakoHilSensor &dst)
{
    void* base_ptr = (void*)&src;
    void* heap_ptr = hako_get_heap_ptr_pdu(base_ptr);
    // Validate magic number and version
    if (heap_ptr == nullptr) {
        return -1; // Invalid PDU metadata
    }
    else {
        return _pdu2ros_HakoHilSensor((char*)heap_ptr, src, dst);
    }
}

/***************************
 *
 * ROS2 ==> PDU
 *
 ***************************/

static inline bool _ros2pdu_HakoHilSensor(hako_mavlink_msgs::msg::HakoHilSensor &src, Hako_HakoHilSensor &dst, PduDynamicMemory &dynamic_memory)
{
    try {
        // primitive convert
        hako_convert_ros2pdu(src.time_usec, dst.time_usec);
        // primitive convert
        hako_convert_ros2pdu(src.xacc, dst.xacc);
        // primitive convert
        hako_convert_ros2pdu(src.yacc, dst.yacc);
        // primitive convert
        hako_convert_ros2pdu(src.zacc, dst.zacc);
        // primitive convert
        hako_convert_ros2pdu(src.xgyro, dst.xgyro);
        // primitive convert
        hako_convert_ros2pdu(src.ygyro, dst.ygyro);
        // primitive convert
        hako_convert_ros2pdu(src.zgyro, dst.zgyro);
        // primitive convert
        hako_convert_ros2pdu(src.xmag, dst.xmag);
        // primitive convert
        hako_convert_ros2pdu(src.ymag, dst.ymag);
        // primitive convert
        hako_convert_ros2pdu(src.zmag, dst.zmag);
        // primitive convert
        hako_convert_ros2pdu(src.abs_pressure, dst.abs_pressure);
        // primitive convert
        hako_convert_ros2pdu(src.diff_pressure, dst.diff_pressure);
        // primitive convert
        hako_convert_ros2pdu(src.pressure_alt, dst.pressure_alt);
        // primitive convert
        hako_convert_ros2pdu(src.temperature, dst.temperature);
        // primitive convert
        hako_convert_ros2pdu(src.fields_updated, dst.fields_updated);
        // primitive convert
        hako_convert_ros2pdu(src.id, dst.id);
    } catch (const std::runtime_error& e) {
        std::cerr << "convertor error: " << e.what() << std::endl;
        return false;
    }
    (void)dynamic_memory;
    return true;
}

static inline int hako_convert_ros2pdu_HakoHilSensor(hako_mavlink_msgs::msg::HakoHilSensor &src, Hako_HakoHilSensor** dst)
{
    PduDynamicMemory dynamic_memory;
    Hako_HakoHilSensor out;
    if (!_ros2pdu_HakoHilSensor(src, out, dynamic_memory)) {
        return -1;
    }
    int heap_size = dynamic_memory.get_total_size();
    void* base_ptr = hako_create_empty_pdu(sizeof(Hako_HakoHilSensor), heap_size);
    if (base_ptr == nullptr) {
        return -1;
    }
    // Copy out on base data
    memcpy(base_ptr, (void*)&out, sizeof(Hako_HakoHilSensor));

    // Copy dynamic part and set offsets
    void* heap_ptr = hako_get_heap_ptr_pdu(base_ptr);
    dynamic_memory.copy_to_pdu((char*)heap_ptr);

    *dst = (Hako_HakoHilSensor*)base_ptr;
    return hako_get_pdu_meta_data(base_ptr)->total_size;
}

static inline Hako_HakoHilSensor* hako_create_empty_pdu_HakoHilSensor(int heap_size)
{
    // Allocate PDU memory
    char* base_ptr = (char*)hako_create_empty_pdu(sizeof(Hako_HakoHilSensor), heap_size);
    if (base_ptr == nullptr) {
        return nullptr;
    }
    return (Hako_HakoHilSensor*)base_ptr;
}
#endif /* _PDU_CTYPE_CONV_HAKO_hako_mavlink_msgs_HakoHilSensor_HPP_ */
