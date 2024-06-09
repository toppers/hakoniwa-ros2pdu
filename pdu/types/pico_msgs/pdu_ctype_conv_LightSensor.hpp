#ifndef _PDU_CTYPE_CONV_HAKO_pico_msgs_LightSensor_HPP_
#define _PDU_CTYPE_CONV_HAKO_pico_msgs_LightSensor_HPP_

#include "pdu_primitive_ctypes.h"
#include "ros_primitive_types.hpp"
#include "pdu_primitive_ctypes_conv.hpp"
#include "pdu_dynamic_memory.hpp"
/*
 * Dependent pdu data
 */
#include "pico_msgs/pdu_ctype_LightSensor.h"
/*
 * Dependent ros data
 */
#include "pico_msgs/msg/light_sensor.hpp"

/*
 * Dependent Convertors
 */

/***************************
 *
 * PDU ==> ROS2
 *
 ***************************/

static inline int _pdu2ros_LightSensor(const char* heap_ptr, Hako_LightSensor &src, pico_msgs::msg::LightSensor &dst)
{
    // primitive convert
    hako_convert_pdu2ros(src.forward_r, dst.forward_r);
    // primitive convert
    hako_convert_pdu2ros(src.forward_l, dst.forward_l);
    // primitive convert
    hako_convert_pdu2ros(src.left, dst.left);
    // primitive convert
    hako_convert_pdu2ros(src.right, dst.right);
    (void)heap_ptr;
    return 0;
}

static inline int hako_convert_pdu2ros_LightSensor(Hako_LightSensor &src, pico_msgs::msg::LightSensor &dst)
{
    void* base_ptr = (void*)&src;
    void* heap_ptr = hako_get_heap_ptr_pdu(base_ptr);
    // Validate magic number and version
    if (heap_ptr == nullptr) {
        return -1; // Invalid PDU metadata
    }
    else {
        return _pdu2ros_LightSensor((char*)heap_ptr, src, dst);
    }
}

/***************************
 *
 * ROS2 ==> PDU
 *
 ***************************/

static inline bool _ros2pdu_LightSensor(pico_msgs::msg::LightSensor &src, Hako_LightSensor &dst, PduDynamicMemory &dynamic_memory)
{
    try {
        // primitive convert
        hako_convert_ros2pdu(src.forward_r, dst.forward_r);
        // primitive convert
        hako_convert_ros2pdu(src.forward_l, dst.forward_l);
        // primitive convert
        hako_convert_ros2pdu(src.left, dst.left);
        // primitive convert
        hako_convert_ros2pdu(src.right, dst.right);
    } catch (const std::runtime_error& e) {
        std::cerr << "convertor error: " << e.what() << std::endl;
        return false;
    }
    (void)dynamic_memory;
    return true;
}

static inline int hako_convert_ros2pdu_LightSensor(pico_msgs::msg::LightSensor &src, Hako_LightSensor** dst)
{
    PduDynamicMemory dynamic_memory;
    Hako_LightSensor out;
    if (!_ros2pdu_LightSensor(src, out, dynamic_memory)) {
        return -1;
    }
    int heap_size = dynamic_memory.get_total_size();
    void* base_ptr = hako_create_empty_pdu(sizeof(Hako_LightSensor), heap_size);
    if (base_ptr == nullptr) {
        return -1;
    }
    // Copy out on base data
    memcpy(base_ptr, (void*)&out, sizeof(Hako_LightSensor));

    // Copy dynamic part and set offsets
    void* heap_ptr = hako_get_heap_ptr_pdu(base_ptr);
    dynamic_memory.copy_to_pdu((char*)heap_ptr);

    *dst = (Hako_LightSensor*)base_ptr;
    return hako_get_pdu_meta_data(base_ptr)->total_size;
}

static inline Hako_LightSensor* hako_create_empty_pdu_LightSensor(int heap_size)
{
    // Allocate PDU memory
    char* base_ptr = (char*)hako_create_empty_pdu(sizeof(Hako_LightSensor), heap_size);
    if (base_ptr == nullptr) {
        return nullptr;
    }
    return (Hako_LightSensor*)base_ptr;
}
#endif /* _PDU_CTYPE_CONV_HAKO_pico_msgs_LightSensor_HPP_ */
