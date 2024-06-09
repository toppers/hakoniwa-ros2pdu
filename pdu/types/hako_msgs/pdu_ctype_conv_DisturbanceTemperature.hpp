#ifndef _PDU_CTYPE_CONV_HAKO_hako_msgs_DisturbanceTemperature_HPP_
#define _PDU_CTYPE_CONV_HAKO_hako_msgs_DisturbanceTemperature_HPP_

#include "pdu_primitive_ctypes.h"
#include "ros_primitive_types.hpp"
#include "pdu_primitive_ctypes_conv.hpp"
#include "pdu_dynamic_memory.hpp"
/*
 * Dependent pdu data
 */
#include "hako_msgs/pdu_ctype_DisturbanceTemperature.h"
/*
 * Dependent ros data
 */
#include "hako_msgs/msg/disturbance_temperature.hpp"

/*
 * Dependent Convertors
 */

/***************************
 *
 * PDU ==> ROS2
 *
 ***************************/

static inline int _pdu2ros_DisturbanceTemperature(const char* heap_ptr, Hako_DisturbanceTemperature &src, hako_msgs::msg::DisturbanceTemperature &dst)
{
    // primitive convert
    hako_convert_pdu2ros(src.value, dst.value);
    (void)heap_ptr;
    return 0;
}

static inline int hako_convert_pdu2ros_DisturbanceTemperature(Hako_DisturbanceTemperature &src, hako_msgs::msg::DisturbanceTemperature &dst)
{
    void* base_ptr = (void*)&src;
    void* heap_ptr = hako_get_heap_ptr_pdu(base_ptr);
    // Validate magic number and version
    if (heap_ptr == nullptr) {
        return -1; // Invalid PDU metadata
    }
    else {
        return _pdu2ros_DisturbanceTemperature((char*)heap_ptr, src, dst);
    }
}

/***************************
 *
 * ROS2 ==> PDU
 *
 ***************************/

static inline bool _ros2pdu_DisturbanceTemperature(hako_msgs::msg::DisturbanceTemperature &src, Hako_DisturbanceTemperature &dst, PduDynamicMemory &dynamic_memory)
{
    try {
        // primitive convert
        hako_convert_ros2pdu(src.value, dst.value);
    } catch (const std::runtime_error& e) {
        std::cerr << "convertor error: " << e.what() << std::endl;
        return false;
    }
    (void)dynamic_memory;
    return true;
}

static inline int hako_convert_ros2pdu_DisturbanceTemperature(hako_msgs::msg::DisturbanceTemperature &src, Hako_DisturbanceTemperature** dst)
{
    PduDynamicMemory dynamic_memory;
    Hako_DisturbanceTemperature out;
    if (!_ros2pdu_DisturbanceTemperature(src, out, dynamic_memory)) {
        return -1;
    }
    int heap_size = dynamic_memory.get_total_size();
    void* base_ptr = hako_create_empty_pdu(sizeof(Hako_DisturbanceTemperature), heap_size);
    if (base_ptr == nullptr) {
        return -1;
    }
    // Copy out on base data
    memcpy(base_ptr, (void*)&out, sizeof(Hako_DisturbanceTemperature));

    // Copy dynamic part and set offsets
    void* heap_ptr = hako_get_heap_ptr_pdu(base_ptr);
    dynamic_memory.copy_to_pdu((char*)heap_ptr);

    *dst = (Hako_DisturbanceTemperature*)base_ptr;
    return hako_get_pdu_meta_data(base_ptr)->total_size;
}

static inline Hako_DisturbanceTemperature* hako_create_empty_pdu_DisturbanceTemperature(int heap_size)
{
    // Allocate PDU memory
    char* base_ptr = (char*)hako_create_empty_pdu(sizeof(Hako_DisturbanceTemperature), heap_size);
    if (base_ptr == nullptr) {
        return nullptr;
    }
    return (Hako_DisturbanceTemperature*)base_ptr;
}
#endif /* _PDU_CTYPE_CONV_HAKO_hako_msgs_DisturbanceTemperature_HPP_ */
