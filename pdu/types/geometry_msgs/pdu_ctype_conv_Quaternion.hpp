#ifndef _PDU_CTYPE_CONV_HAKO_geometry_msgs_Quaternion_HPP_
#define _PDU_CTYPE_CONV_HAKO_geometry_msgs_Quaternion_HPP_

#include "pdu_primitive_ctypes.h"
#include "ros_primitive_types.hpp"
#include "pdu_primitive_ctypes_conv.hpp"
#include "pdu_dynamic_memory.hpp"
/*
 * Dependent pdu data
 */
#include "geometry_msgs/pdu_ctype_Quaternion.h"
/*
 * Dependent ros data
 */
#include "geometry_msgs/msg/quaternion.hpp"

/*
 * Dependent Convertors
 */

/***************************
 *
 * PDU ==> ROS2
 *
 ***************************/

static inline int _pdu2ros_Quaternion(const char* heap_ptr, Hako_Quaternion &src, geometry_msgs::msg::Quaternion &dst)
{
    // primitive convert
    hako_convert_pdu2ros(src.x, dst.x);
    // primitive convert
    hako_convert_pdu2ros(src.y, dst.y);
    // primitive convert
    hako_convert_pdu2ros(src.z, dst.z);
    // primitive convert
    hako_convert_pdu2ros(src.w, dst.w);
    (void)heap_ptr;
    return 0;
}

static inline int hako_convert_pdu2ros_Quaternion(Hako_Quaternion &src, geometry_msgs::msg::Quaternion &dst)
{
    void* base_ptr = (void*)&src;
    void* heap_ptr = hako_get_heap_ptr_pdu(base_ptr);
    // Validate magic number and version
    if (heap_ptr == nullptr) {
        return -1; // Invalid PDU metadata
    }
    else {
        return _pdu2ros_Quaternion((char*)heap_ptr, src, dst);
    }
}

/***************************
 *
 * ROS2 ==> PDU
 *
 ***************************/

static inline bool _ros2pdu_Quaternion(geometry_msgs::msg::Quaternion &src, Hako_Quaternion &dst, PduDynamicMemory &dynamic_memory)
{
    try {
        // primitive convert
        hako_convert_ros2pdu(src.x, dst.x);
        // primitive convert
        hako_convert_ros2pdu(src.y, dst.y);
        // primitive convert
        hako_convert_ros2pdu(src.z, dst.z);
        // primitive convert
        hako_convert_ros2pdu(src.w, dst.w);
    } catch (const std::runtime_error& e) {
        std::cerr << "convertor error: " << e.what() << std::endl;
        return false;
    }
    (void)dynamic_memory;
    return true;
}

static inline int hako_convert_ros2pdu_Quaternion(geometry_msgs::msg::Quaternion &src, Hako_Quaternion** dst)
{
    PduDynamicMemory dynamic_memory;
    Hako_Quaternion out;
    if (!_ros2pdu_Quaternion(src, out, dynamic_memory)) {
        return -1;
    }
    int heap_size = dynamic_memory.get_total_size();
    void* base_ptr = hako_create_empty_pdu(sizeof(Hako_Quaternion), heap_size);
    if (base_ptr == nullptr) {
        return -1;
    }
    // Copy out on base data
    memcpy(base_ptr, (void*)&out, sizeof(Hako_Quaternion));

    // Copy dynamic part and set offsets
    void* heap_ptr = hako_get_heap_ptr_pdu(base_ptr);
    dynamic_memory.copy_to_pdu((char*)heap_ptr);

    *dst = (Hako_Quaternion*)base_ptr;
    return hako_get_pdu_meta_data(base_ptr)->total_size;
}

static inline Hako_Quaternion* hako_create_empty_pdu_Quaternion(int heap_size)
{
    // Allocate PDU memory
    char* base_ptr = (char*)hako_create_empty_pdu(sizeof(Hako_Quaternion), heap_size);
    if (base_ptr == nullptr) {
        return nullptr;
    }
    return (Hako_Quaternion*)base_ptr;
}
#endif /* _PDU_CTYPE_CONV_HAKO_geometry_msgs_Quaternion_HPP_ */
