#ifndef _PDU_CTYPE_CONV_HAKO_geometry_msgs_Transform_HPP_
#define _PDU_CTYPE_CONV_HAKO_geometry_msgs_Transform_HPP_

#include "pdu_primitive_ctypes.h"
#include "ros_primitive_types.hpp"
#include "pdu_primitive_ctypes_conv.hpp"
#include "pdu_dynamic_memory.hpp"
/*
 * Dependent pdu data
 */
#include "geometry_msgs/pdu_ctype_Transform.h"
/*
 * Dependent ros data
 */
#include "geometry_msgs/msg/transform.hpp"

/*
 * Dependent Convertors
 */
#include "geometry_msgs/pdu_ctype_conv_Quaternion.hpp"
#include "geometry_msgs/pdu_ctype_conv_Vector3.hpp"

/***************************
 *
 * PDU ==> ROS2
 *
 ***************************/

static inline int _pdu2ros_Transform(const char* heap_ptr, Hako_Transform &src, geometry_msgs::msg::Transform &dst)
{
    // Struct convert
    _pdu2ros_Vector3(heap_ptr, src.translation, dst.translation);
    // Struct convert
    _pdu2ros_Quaternion(heap_ptr, src.rotation, dst.rotation);
    (void)heap_ptr;
    return 0;
}

static inline int hako_convert_pdu2ros_Transform(Hako_Transform &src, geometry_msgs::msg::Transform &dst)
{
    void* base_ptr = (void*)&src;
    void* heap_ptr = hako_get_heap_ptr_pdu(base_ptr);
    // Validate magic number and version
    if (heap_ptr == nullptr) {
        return -1; // Invalid PDU metadata
    }
    else {
        return _pdu2ros_Transform((char*)heap_ptr, src, dst);
    }
}

/***************************
 *
 * ROS2 ==> PDU
 *
 ***************************/

static inline bool _ros2pdu_Transform(geometry_msgs::msg::Transform &src, Hako_Transform &dst, PduDynamicMemory &dynamic_memory)
{
    try {
        // struct convert
        _ros2pdu_Vector3(src.translation, dst.translation, dynamic_memory);
        // struct convert
        _ros2pdu_Quaternion(src.rotation, dst.rotation, dynamic_memory);
    } catch (const std::runtime_error& e) {
        std::cerr << "convertor error: " << e.what() << std::endl;
        return false;
    }
    (void)dynamic_memory;
    return true;
}

static inline int hako_convert_ros2pdu_Transform(geometry_msgs::msg::Transform &src, Hako_Transform** dst)
{
    PduDynamicMemory dynamic_memory;
    Hako_Transform out;
    if (!_ros2pdu_Transform(src, out, dynamic_memory)) {
        return -1;
    }
    int heap_size = dynamic_memory.get_total_size();
    void* base_ptr = hako_create_empty_pdu(sizeof(Hako_Transform), heap_size);
    if (base_ptr == nullptr) {
        return -1;
    }
    // Copy out on base data
    memcpy(base_ptr, (void*)&out, sizeof(Hako_Transform));

    // Copy dynamic part and set offsets
    void* heap_ptr = hako_get_heap_ptr_pdu(base_ptr);
    dynamic_memory.copy_to_pdu((char*)heap_ptr);

    *dst = (Hako_Transform*)base_ptr;
    return hako_get_pdu_meta_data(base_ptr)->total_size;
}

static inline Hako_Transform* hako_create_empty_pdu_Transform(int heap_size)
{
    // Allocate PDU memory
    char* base_ptr = (char*)hako_create_empty_pdu(sizeof(Hako_Transform), heap_size);
    if (base_ptr == nullptr) {
        return nullptr;
    }
    return (Hako_Transform*)base_ptr;
}
#endif /* _PDU_CTYPE_CONV_HAKO_geometry_msgs_Transform_HPP_ */
