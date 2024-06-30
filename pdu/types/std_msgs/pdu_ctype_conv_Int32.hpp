#ifndef _PDU_CTYPE_CONV_HAKO_std_msgs_Int32_HPP_
#define _PDU_CTYPE_CONV_HAKO_std_msgs_Int32_HPP_

#include "pdu_primitive_ctypes.h"
#include "ros_primitive_types.hpp"
#include "pdu_primitive_ctypes_conv.hpp"
#include "pdu_dynamic_memory.hpp"
/*
 * Dependent pdu data
 */
#include "std_msgs/pdu_ctype_Int32.h"
/*
 * Dependent ros data
 */
#include "std_msgs/msg/int32.hpp"

/*
 * Dependent Convertors
 */

/***************************
 *
 * PDU ==> ROS2
 *
 ***************************/

static inline int _pdu2ros_Int32(const char* heap_ptr, Hako_Int32 &src, std_msgs::msg::Int32 &dst)
{
    // primitive convert
    hako_convert_pdu2ros(src.data, dst.data);
    (void)heap_ptr;
    return 0;
}

static inline int hako_convert_pdu2ros_Int32(Hako_Int32 &src, std_msgs::msg::Int32 &dst)
{
    void* base_ptr = (void*)&src;
    void* heap_ptr = hako_get_heap_ptr_pdu(base_ptr);
    // Validate magic number and version
    if (heap_ptr == nullptr) {
        return -1; // Invalid PDU metadata
    }
    else {
        return _pdu2ros_Int32((char*)heap_ptr, src, dst);
    }
}

/***************************
 *
 * ROS2 ==> PDU
 *
 ***************************/

static inline bool _ros2pdu_Int32(std_msgs::msg::Int32 &src, Hako_Int32 &dst, PduDynamicMemory &dynamic_memory)
{
    try {
        // primitive convert
        hako_convert_ros2pdu(src.data, dst.data);
    } catch (const std::runtime_error& e) {
        std::cerr << "convertor error: " << e.what() << std::endl;
        return false;
    }
    (void)dynamic_memory;
    return true;
}

static inline int hako_convert_ros2pdu_Int32(std_msgs::msg::Int32 &src, Hako_Int32** dst)
{
    PduDynamicMemory dynamic_memory;
    Hako_Int32 out;
    if (!_ros2pdu_Int32(src, out, dynamic_memory)) {
        return -1;
    }
    int heap_size = dynamic_memory.get_total_size();
    void* base_ptr = hako_create_empty_pdu(sizeof(Hako_Int32), heap_size);
    if (base_ptr == nullptr) {
        return -1;
    }
    // Copy out on base data
    memcpy(base_ptr, (void*)&out, sizeof(Hako_Int32));

    // Copy dynamic part and set offsets
    void* heap_ptr = hako_get_heap_ptr_pdu(base_ptr);
    dynamic_memory.copy_to_pdu((char*)heap_ptr);

    *dst = (Hako_Int32*)base_ptr;
    return hako_get_pdu_meta_data(base_ptr)->total_size;
}

static inline Hako_Int32* hako_create_empty_pdu_Int32(int heap_size)
{
    // Allocate PDU memory
    char* base_ptr = (char*)hako_create_empty_pdu(sizeof(Hako_Int32), heap_size);
    if (base_ptr == nullptr) {
        return nullptr;
    }
    return (Hako_Int32*)base_ptr;
}
#endif /* _PDU_CTYPE_CONV_HAKO_std_msgs_Int32_HPP_ */
