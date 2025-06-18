#ifndef _PDU_CTYPE_CONV_HAKO_hako_msgs_DisturbanceBoundary_HPP_
#define _PDU_CTYPE_CONV_HAKO_hako_msgs_DisturbanceBoundary_HPP_

#include "pdu_primitive_ctypes.h"
#include "ros_primitive_types.hpp"
#include "pdu_primitive_ctypes_conv.hpp"
#include "pdu_dynamic_memory.hpp"
/*
 * Dependent pdu data
 */
#include "hako_msgs/pdu_ctype_DisturbanceBoundary.h"
/*
 * Dependent ros data
 */
#include "hako_msgs/msg/disturbance_boundary.hpp"

/*
 * Dependent Convertors
 */
#include "geometry_msgs/pdu_ctype_conv_Point.hpp"
#include "geometry_msgs/pdu_ctype_conv_Vector3.hpp"

/***************************
 *
 * PDU ==> ROS2
 *
 ***************************/

static inline int _pdu2ros_DisturbanceBoundary(const char* heap_ptr, Hako_DisturbanceBoundary &src, hako_msgs::msg::DisturbanceBoundary &dst)
{
    // Struct convert
    _pdu2ros_Point(heap_ptr, src.boundary_point, dst.boundary_point);
    // Struct convert
    _pdu2ros_Vector3(heap_ptr, src.boundary_normal, dst.boundary_normal);
    (void)heap_ptr;
    return 0;
}

static inline int hako_convert_pdu2ros_DisturbanceBoundary(Hako_DisturbanceBoundary &src, hako_msgs::msg::DisturbanceBoundary &dst)
{
    void* base_ptr = (void*)&src;
    void* heap_ptr = hako_get_heap_ptr_pdu(base_ptr);
    // Validate magic number and version
    if (heap_ptr == nullptr) {
        return -1; // Invalid PDU metadata
    }
    else {
        return _pdu2ros_DisturbanceBoundary((char*)heap_ptr, src, dst);
    }
}

/***************************
 *
 * ROS2 ==> PDU
 *
 ***************************/

static inline bool _ros2pdu_DisturbanceBoundary(hako_msgs::msg::DisturbanceBoundary &src, Hako_DisturbanceBoundary &dst, PduDynamicMemory &dynamic_memory)
{
    try {
        // struct convert
        _ros2pdu_Point(src.boundary_point, dst.boundary_point, dynamic_memory);
        // struct convert
        _ros2pdu_Vector3(src.boundary_normal, dst.boundary_normal, dynamic_memory);
    } catch (const std::runtime_error& e) {
        std::cerr << "convertor error: " << e.what() << std::endl;
        return false;
    }
    (void)dynamic_memory;
    return true;
}

static inline int hako_convert_ros2pdu_DisturbanceBoundary(hako_msgs::msg::DisturbanceBoundary &src, Hako_DisturbanceBoundary** dst)
{
    PduDynamicMemory dynamic_memory;
    Hako_DisturbanceBoundary out;
    if (!_ros2pdu_DisturbanceBoundary(src, out, dynamic_memory)) {
        return -1;
    }
    int heap_size = dynamic_memory.get_total_size();
    void* base_ptr = hako_create_empty_pdu(sizeof(Hako_DisturbanceBoundary), heap_size);
    if (base_ptr == nullptr) {
        return -1;
    }
    // Copy out on base data
    memcpy(base_ptr, (void*)&out, sizeof(Hako_DisturbanceBoundary));

    // Copy dynamic part and set offsets
    void* heap_ptr = hako_get_heap_ptr_pdu(base_ptr);
    dynamic_memory.copy_to_pdu((char*)heap_ptr);

    *dst = (Hako_DisturbanceBoundary*)base_ptr;
    return hako_get_pdu_meta_data(base_ptr)->total_size;
}

static inline Hako_DisturbanceBoundary* hako_create_empty_pdu_DisturbanceBoundary(int heap_size)
{
    // Allocate PDU memory
    char* base_ptr = (char*)hako_create_empty_pdu(sizeof(Hako_DisturbanceBoundary), heap_size);
    if (base_ptr == nullptr) {
        return nullptr;
    }
    return (Hako_DisturbanceBoundary*)base_ptr;
}
#endif /* _PDU_CTYPE_CONV_HAKO_hako_msgs_DisturbanceBoundary_HPP_ */
