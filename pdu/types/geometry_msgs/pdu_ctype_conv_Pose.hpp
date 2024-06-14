#ifndef _PDU_CTYPE_CONV_HAKO_geometry_msgs_Pose_HPP_
#define _PDU_CTYPE_CONV_HAKO_geometry_msgs_Pose_HPP_

#include "pdu_primitive_ctypes.h"
#include "ros_primitive_types.hpp"
#include "pdu_primitive_ctypes_conv.hpp"
#include "pdu_dynamic_memory.hpp"
/*
 * Dependent pdu data
 */
#include "geometry_msgs/pdu_ctype_Pose.h"
/*
 * Dependent ros data
 */
#include "geometry_msgs/msg/pose.hpp"

/*
 * Dependent Convertors
 */
#include "geometry_msgs/pdu_ctype_conv_Point.hpp"
#include "geometry_msgs/pdu_ctype_conv_Quaternion.hpp"

/***************************
 *
 * PDU ==> ROS2
 *
 ***************************/

static inline int _pdu2ros_Pose(const char* heap_ptr, Hako_Pose &src, geometry_msgs::msg::Pose &dst)
{
    // Struct convert
    _pdu2ros_Point(heap_ptr, src.position, dst.position);
    // Struct convert
    _pdu2ros_Quaternion(heap_ptr, src.orientation, dst.orientation);
    (void)heap_ptr;
    return 0;
}

static inline int hako_convert_pdu2ros_Pose(Hako_Pose &src, geometry_msgs::msg::Pose &dst)
{
    void* base_ptr = (void*)&src;
    void* heap_ptr = hako_get_heap_ptr_pdu(base_ptr);
    // Validate magic number and version
    if (heap_ptr == nullptr) {
        return -1; // Invalid PDU metadata
    }
    else {
        return _pdu2ros_Pose((char*)heap_ptr, src, dst);
    }
}

/***************************
 *
 * ROS2 ==> PDU
 *
 ***************************/

static inline bool _ros2pdu_Pose(geometry_msgs::msg::Pose &src, Hako_Pose &dst, PduDynamicMemory &dynamic_memory)
{
    try {
        // struct convert
        _ros2pdu_Point(src.position, dst.position, dynamic_memory);
        // struct convert
        _ros2pdu_Quaternion(src.orientation, dst.orientation, dynamic_memory);
    } catch (const std::runtime_error& e) {
        std::cerr << "convertor error: " << e.what() << std::endl;
        return false;
    }
    (void)dynamic_memory;
    return true;
}

static inline int hako_convert_ros2pdu_Pose(geometry_msgs::msg::Pose &src, Hako_Pose** dst)
{
    PduDynamicMemory dynamic_memory;
    Hako_Pose out;
    if (!_ros2pdu_Pose(src, out, dynamic_memory)) {
        return -1;
    }
    int heap_size = dynamic_memory.get_total_size();
    void* base_ptr = hako_create_empty_pdu(sizeof(Hako_Pose), heap_size);
    if (base_ptr == nullptr) {
        return -1;
    }
    // Copy out on base data
    memcpy(base_ptr, (void*)&out, sizeof(Hako_Pose));

    // Copy dynamic part and set offsets
    void* heap_ptr = hako_get_heap_ptr_pdu(base_ptr);
    dynamic_memory.copy_to_pdu((char*)heap_ptr);

    *dst = (Hako_Pose*)base_ptr;
    return hako_get_pdu_meta_data(base_ptr)->total_size;
}

static inline Hako_Pose* hako_create_empty_pdu_Pose(int heap_size)
{
    // Allocate PDU memory
    char* base_ptr = (char*)hako_create_empty_pdu(sizeof(Hako_Pose), heap_size);
    if (base_ptr == nullptr) {
        return nullptr;
    }
    return (Hako_Pose*)base_ptr;
}
#endif /* _PDU_CTYPE_CONV_HAKO_geometry_msgs_Pose_HPP_ */
