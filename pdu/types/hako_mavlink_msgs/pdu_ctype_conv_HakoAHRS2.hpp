#ifndef _PDU_CTYPE_CONV_HAKO_hako_mavlink_msgs_HakoAHRS2_HPP_
#define _PDU_CTYPE_CONV_HAKO_hako_mavlink_msgs_HakoAHRS2_HPP_

#include "pdu_primitive_ctypes.h"
#include "ros_primitive_types.hpp"
#include "pdu_primitive_ctypes_conv.hpp"
#include "pdu_dynamic_memory.hpp"
/*
 * Dependent pdu data
 */
#include "hako_mavlink_msgs/pdu_ctype_HakoAHRS2.h"
/*
 * Dependent ros data
 */
#include "hako_mavlink_msgs/msg/hako_a_h_r_s2.hpp"

/*
 * Dependent Convertors
 */

/***************************
 *
 * PDU ==> ROS2
 *
 ***************************/

static inline int _pdu2ros_HakoAHRS2(const char* heap_ptr, Hako_HakoAHRS2 &src, hako_mavlink_msgs::msg::HakoAHRS2 &dst)
{
    // primitive convert
    hako_convert_pdu2ros(src.roll, dst.roll);
    // primitive convert
    hako_convert_pdu2ros(src.pitch, dst.pitch);
    // primitive convert
    hako_convert_pdu2ros(src.yaw, dst.yaw);
    // primitive convert
    hako_convert_pdu2ros(src.altitude, dst.altitude);
    // primitive convert
    hako_convert_pdu2ros(src.lat, dst.lat);
    // primitive convert
    hako_convert_pdu2ros(src.lng, dst.lng);
    (void)heap_ptr;
    return 0;
}

static inline int hako_convert_pdu2ros_HakoAHRS2(Hako_HakoAHRS2 &src, hako_mavlink_msgs::msg::HakoAHRS2 &dst)
{
    void* base_ptr = (void*)&src;
    void* heap_ptr = hako_get_heap_ptr_pdu(base_ptr);
    // Validate magic number and version
    if (heap_ptr == nullptr) {
        return -1; // Invalid PDU metadata
    }
    else {
        return _pdu2ros_HakoAHRS2((char*)heap_ptr, src, dst);
    }
}

/***************************
 *
 * ROS2 ==> PDU
 *
 ***************************/

static inline bool _ros2pdu_HakoAHRS2(hako_mavlink_msgs::msg::HakoAHRS2 &src, Hako_HakoAHRS2 &dst, PduDynamicMemory &dynamic_memory)
{
    try {
        // primitive convert
        hako_convert_ros2pdu(src.roll, dst.roll);
        // primitive convert
        hako_convert_ros2pdu(src.pitch, dst.pitch);
        // primitive convert
        hako_convert_ros2pdu(src.yaw, dst.yaw);
        // primitive convert
        hako_convert_ros2pdu(src.altitude, dst.altitude);
        // primitive convert
        hako_convert_ros2pdu(src.lat, dst.lat);
        // primitive convert
        hako_convert_ros2pdu(src.lng, dst.lng);
    } catch (const std::runtime_error& e) {
        std::cerr << "convertor error: " << e.what() << std::endl;
        return false;
    }
    (void)dynamic_memory;
    return true;
}

static inline int hako_convert_ros2pdu_HakoAHRS2(hako_mavlink_msgs::msg::HakoAHRS2 &src, Hako_HakoAHRS2** dst)
{
    PduDynamicMemory dynamic_memory;
    Hako_HakoAHRS2 out;
    if (!_ros2pdu_HakoAHRS2(src, out, dynamic_memory)) {
        return -1;
    }
    int heap_size = dynamic_memory.get_total_size();
    void* base_ptr = hako_create_empty_pdu(sizeof(Hako_HakoAHRS2), heap_size);
    if (base_ptr == nullptr) {
        return -1;
    }
    // Copy out on base data
    memcpy(base_ptr, (void*)&out, sizeof(Hako_HakoAHRS2));

    // Copy dynamic part and set offsets
    void* heap_ptr = hako_get_heap_ptr_pdu(base_ptr);
    dynamic_memory.copy_to_pdu((char*)heap_ptr);

    *dst = (Hako_HakoAHRS2*)base_ptr;
    return hako_get_pdu_meta_data(base_ptr)->total_size;
}

static inline Hako_HakoAHRS2* hako_create_empty_pdu_HakoAHRS2(int heap_size)
{
    // Allocate PDU memory
    char* base_ptr = (char*)hako_create_empty_pdu(sizeof(Hako_HakoAHRS2), heap_size);
    if (base_ptr == nullptr) {
        return nullptr;
    }
    return (Hako_HakoAHRS2*)base_ptr;
}
#endif /* _PDU_CTYPE_CONV_HAKO_hako_mavlink_msgs_HakoAHRS2_HPP_ */
