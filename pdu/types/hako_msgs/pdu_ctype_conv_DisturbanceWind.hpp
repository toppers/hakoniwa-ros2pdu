#ifndef _PDU_CTYPE_CONV_HAKO_hako_msgs_DisturbanceWind_HPP_
#define _PDU_CTYPE_CONV_HAKO_hako_msgs_DisturbanceWind_HPP_

#include "pdu_primitive_ctypes.h"
#include "ros_primitive_types.hpp"
#include "pdu_primitive_ctypes_conv.hpp"
#include "pdu_dynamic_memory.hpp"
/*
 * Dependent pdu data
 */
#include "hako_msgs/pdu_ctype_DisturbanceWind.h"
/*
 * Dependent ros data
 */
#include "hako_msgs/msg/disturbance_wind.hpp"

/*
 * Dependent Convertors
 */
#include "geometry_msgs/pdu_ctype_conv_Vector3.hpp"

/***************************
 *
 * PDU ==> ROS2
 *
 ***************************/

static inline int _pdu2ros_DisturbanceWind(const char* heap_ptr, Hako_DisturbanceWind &src, hako_msgs::msg::DisturbanceWind &dst)
{
    // Struct convert
    _pdu2ros_Vector3(heap_ptr, src.value, dst.value);
    (void)heap_ptr;
    return 0;
}

static inline int hako_convert_pdu2ros_DisturbanceWind(Hako_DisturbanceWind &src, hako_msgs::msg::DisturbanceWind &dst)
{
    void* base_ptr = (void*)&src;
    void* heap_ptr = hako_get_heap_ptr_pdu(base_ptr);
    // Validate magic number and version
    if (heap_ptr == nullptr) {
        return -1; // Invalid PDU metadata
    }
    else {
        return _pdu2ros_DisturbanceWind((char*)heap_ptr, src, dst);
    }
}

/***************************
 *
 * ROS2 ==> PDU
 *
 ***************************/

static inline bool _ros2pdu_DisturbanceWind(hako_msgs::msg::DisturbanceWind &src, Hako_DisturbanceWind &dst, PduDynamicMemory &dynamic_memory)
{
    try {
        // struct convert
        _ros2pdu_Vector3(src.value, dst.value, dynamic_memory);
    } catch (const std::runtime_error& e) {
        std::cerr << "convertor error: " << e.what() << std::endl;
        return false;
    }
    (void)dynamic_memory;
    return true;
}

static inline int hako_convert_ros2pdu_DisturbanceWind(hako_msgs::msg::DisturbanceWind &src, Hako_DisturbanceWind** dst)
{
    PduDynamicMemory dynamic_memory;
    Hako_DisturbanceWind out;
    if (!_ros2pdu_DisturbanceWind(src, out, dynamic_memory)) {
        return -1;
    }
    int heap_size = dynamic_memory.get_total_size();
    void* base_ptr = hako_create_empty_pdu(sizeof(Hako_DisturbanceWind), heap_size);
    if (base_ptr == nullptr) {
        return -1;
    }
    // Copy out on base data
    memcpy(base_ptr, (void*)&out, sizeof(Hako_DisturbanceWind));

    // Copy dynamic part and set offsets
    void* heap_ptr = hako_get_heap_ptr_pdu(base_ptr);
    dynamic_memory.copy_to_pdu((char*)heap_ptr);

    *dst = (Hako_DisturbanceWind*)base_ptr;
    return hako_get_pdu_meta_data(base_ptr)->total_size;
}

static inline Hako_DisturbanceWind* hako_create_empty_pdu_DisturbanceWind(int heap_size)
{
    // Allocate PDU memory
    char* base_ptr = (char*)hako_create_empty_pdu(sizeof(Hako_DisturbanceWind), heap_size);
    if (base_ptr == nullptr) {
        return nullptr;
    }
    return (Hako_DisturbanceWind*)base_ptr;
}
#endif /* _PDU_CTYPE_CONV_HAKO_hako_msgs_DisturbanceWind_HPP_ */
