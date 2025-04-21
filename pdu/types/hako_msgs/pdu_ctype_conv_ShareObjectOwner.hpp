#ifndef _PDU_CTYPE_CONV_HAKO_hako_msgs_ShareObjectOwner_HPP_
#define _PDU_CTYPE_CONV_HAKO_hako_msgs_ShareObjectOwner_HPP_

#include "pdu_primitive_ctypes.h"
#include "ros_primitive_types.hpp"
#include "pdu_primitive_ctypes_conv.hpp"
#include "pdu_dynamic_memory.hpp"
/*
 * Dependent pdu data
 */
#include "hako_msgs/pdu_ctype_ShareObjectOwner.h"
/*
 * Dependent ros data
 */
#include "hako_msgs/msg/share_object_owner.hpp"

/*
 * Dependent Convertors
 */
#include "geometry_msgs/pdu_ctype_conv_Twist.hpp"
#include "geometry_msgs/pdu_ctype_conv_Vector3.hpp"

/***************************
 *
 * PDU ==> ROS2
 *
 ***************************/

static inline int _pdu2ros_ShareObjectOwner(const char* heap_ptr, Hako_ShareObjectOwner &src, hako_msgs::msg::ShareObjectOwner &dst)
{
    // string convertor
    dst.object_name = (const char*)src.object_name;
    // primitive convert
    hako_convert_pdu2ros(src.owner_id, dst.owner_id);
    // primitive convert
    hako_convert_pdu2ros(src.last_update, dst.last_update);
    // Struct convert
    _pdu2ros_Twist(heap_ptr, src.pos, dst.pos);
    (void)heap_ptr;
    return 0;
}

static inline int hako_convert_pdu2ros_ShareObjectOwner(Hako_ShareObjectOwner &src, hako_msgs::msg::ShareObjectOwner &dst)
{
    void* base_ptr = (void*)&src;
    void* heap_ptr = hako_get_heap_ptr_pdu(base_ptr);
    // Validate magic number and version
    if (heap_ptr == nullptr) {
        return -1; // Invalid PDU metadata
    }
    else {
        return _pdu2ros_ShareObjectOwner((char*)heap_ptr, src, dst);
    }
}

/***************************
 *
 * ROS2 ==> PDU
 *
 ***************************/

static inline bool _ros2pdu_ShareObjectOwner(hako_msgs::msg::ShareObjectOwner &src, Hako_ShareObjectOwner &dst, PduDynamicMemory &dynamic_memory)
{
    try {
        // string convertor
        (void)hako_convert_ros2pdu_array(
            src.object_name, src.object_name.length(),
            dst.object_name, M_ARRAY_SIZE(Hako_ShareObjectOwner, char, object_name));
        dst.object_name[src.object_name.length()] = '\0';
        // primitive convert
        hako_convert_ros2pdu(src.owner_id, dst.owner_id);
        // primitive convert
        hako_convert_ros2pdu(src.last_update, dst.last_update);
        // struct convert
        _ros2pdu_Twist(src.pos, dst.pos, dynamic_memory);
    } catch (const std::runtime_error& e) {
        std::cerr << "convertor error: " << e.what() << std::endl;
        return false;
    }
    (void)dynamic_memory;
    return true;
}

static inline int hako_convert_ros2pdu_ShareObjectOwner(hako_msgs::msg::ShareObjectOwner &src, Hako_ShareObjectOwner** dst)
{
    PduDynamicMemory dynamic_memory;
    Hako_ShareObjectOwner out;
    if (!_ros2pdu_ShareObjectOwner(src, out, dynamic_memory)) {
        return -1;
    }
    int heap_size = dynamic_memory.get_total_size();
    void* base_ptr = hako_create_empty_pdu(sizeof(Hako_ShareObjectOwner), heap_size);
    if (base_ptr == nullptr) {
        return -1;
    }
    // Copy out on base data
    memcpy(base_ptr, (void*)&out, sizeof(Hako_ShareObjectOwner));

    // Copy dynamic part and set offsets
    void* heap_ptr = hako_get_heap_ptr_pdu(base_ptr);
    dynamic_memory.copy_to_pdu((char*)heap_ptr);

    *dst = (Hako_ShareObjectOwner*)base_ptr;
    return hako_get_pdu_meta_data(base_ptr)->total_size;
}

static inline Hako_ShareObjectOwner* hako_create_empty_pdu_ShareObjectOwner(int heap_size)
{
    // Allocate PDU memory
    char* base_ptr = (char*)hako_create_empty_pdu(sizeof(Hako_ShareObjectOwner), heap_size);
    if (base_ptr == nullptr) {
        return nullptr;
    }
    return (Hako_ShareObjectOwner*)base_ptr;
}
#endif /* _PDU_CTYPE_CONV_HAKO_hako_msgs_ShareObjectOwner_HPP_ */
