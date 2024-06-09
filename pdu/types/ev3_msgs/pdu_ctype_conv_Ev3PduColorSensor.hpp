#ifndef _PDU_CTYPE_CONV_HAKO_ev3_msgs_Ev3PduColorSensor_HPP_
#define _PDU_CTYPE_CONV_HAKO_ev3_msgs_Ev3PduColorSensor_HPP_

#include "pdu_primitive_ctypes.h"
#include "ros_primitive_types.hpp"
#include "pdu_primitive_ctypes_conv.hpp"
#include "pdu_dynamic_memory.hpp"
/*
 * Dependent pdu data
 */
#include "ev3_msgs/pdu_ctype_Ev3PduColorSensor.h"
/*
 * Dependent ros data
 */
#include "ev3_msgs/msg/ev3_pdu_color_sensor.hpp"

/*
 * Dependent Convertors
 */

/***************************
 *
 * PDU ==> ROS2
 *
 ***************************/

static inline int _pdu2ros_Ev3PduColorSensor(const char* heap_ptr, Hako_Ev3PduColorSensor &src, ev3_msgs::msg::Ev3PduColorSensor &dst)
{
    // primitive convert
    hako_convert_pdu2ros(src.color, dst.color);
    // primitive convert
    hako_convert_pdu2ros(src.reflect, dst.reflect);
    // primitive convert
    hako_convert_pdu2ros(src.rgb_r, dst.rgb_r);
    // primitive convert
    hako_convert_pdu2ros(src.rgb_g, dst.rgb_g);
    // primitive convert
    hako_convert_pdu2ros(src.rgb_b, dst.rgb_b);
    (void)heap_ptr;
    return 0;
}

static inline int hako_convert_pdu2ros_Ev3PduColorSensor(Hako_Ev3PduColorSensor &src, ev3_msgs::msg::Ev3PduColorSensor &dst)
{
    void* base_ptr = (void*)&src;
    void* heap_ptr = hako_get_heap_ptr_pdu(base_ptr);
    // Validate magic number and version
    if (heap_ptr == nullptr) {
        return -1; // Invalid PDU metadata
    }
    else {
        return _pdu2ros_Ev3PduColorSensor((char*)heap_ptr, src, dst);
    }
}

/***************************
 *
 * ROS2 ==> PDU
 *
 ***************************/

static inline bool _ros2pdu_Ev3PduColorSensor(ev3_msgs::msg::Ev3PduColorSensor &src, Hako_Ev3PduColorSensor &dst, PduDynamicMemory &dynamic_memory)
{
    try {
        // primitive convert
        hako_convert_ros2pdu(src.color, dst.color);
        // primitive convert
        hako_convert_ros2pdu(src.reflect, dst.reflect);
        // primitive convert
        hako_convert_ros2pdu(src.rgb_r, dst.rgb_r);
        // primitive convert
        hako_convert_ros2pdu(src.rgb_g, dst.rgb_g);
        // primitive convert
        hako_convert_ros2pdu(src.rgb_b, dst.rgb_b);
    } catch (const std::runtime_error& e) {
        std::cerr << "convertor error: " << e.what() << std::endl;
        return false;
    }
    (void)dynamic_memory;
    return true;
}

static inline int hako_convert_ros2pdu_Ev3PduColorSensor(ev3_msgs::msg::Ev3PduColorSensor &src, Hako_Ev3PduColorSensor** dst)
{
    PduDynamicMemory dynamic_memory;
    Hako_Ev3PduColorSensor out;
    if (!_ros2pdu_Ev3PduColorSensor(src, out, dynamic_memory)) {
        return -1;
    }
    int heap_size = dynamic_memory.get_total_size();
    void* base_ptr = hako_create_empty_pdu(sizeof(Hako_Ev3PduColorSensor), heap_size);
    if (base_ptr == nullptr) {
        return -1;
    }
    // Copy out on base data
    memcpy(base_ptr, (void*)&out, sizeof(Hako_Ev3PduColorSensor));

    // Copy dynamic part and set offsets
    void* heap_ptr = hako_get_heap_ptr_pdu(base_ptr);
    dynamic_memory.copy_to_pdu((char*)heap_ptr);

    *dst = (Hako_Ev3PduColorSensor*)base_ptr;
    return hako_get_pdu_meta_data(base_ptr)->total_size;
}

static inline Hako_Ev3PduColorSensor* hako_create_empty_pdu_Ev3PduColorSensor(int heap_size)
{
    // Allocate PDU memory
    char* base_ptr = (char*)hako_create_empty_pdu(sizeof(Hako_Ev3PduColorSensor), heap_size);
    if (base_ptr == nullptr) {
        return nullptr;
    }
    return (Hako_Ev3PduColorSensor*)base_ptr;
}
#endif /* _PDU_CTYPE_CONV_HAKO_ev3_msgs_Ev3PduColorSensor_HPP_ */
