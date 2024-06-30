#ifndef _PDU_CTYPE_CONV_HAKO_std_msgs_UInt16MultiArray_HPP_
#define _PDU_CTYPE_CONV_HAKO_std_msgs_UInt16MultiArray_HPP_

#include "pdu_primitive_ctypes.h"
#include "ros_primitive_types.hpp"
#include "pdu_primitive_ctypes_conv.hpp"
#include "pdu_dynamic_memory.hpp"
/*
 * Dependent pdu data
 */
#include "std_msgs/pdu_ctype_UInt16MultiArray.h"
/*
 * Dependent ros data
 */
#include "std_msgs/msg/u_int16_multi_array.hpp"

/*
 * Dependent Convertors
 */
#include "std_msgs/pdu_ctype_conv_MultiArrayDimension.hpp"
#include "std_msgs/pdu_ctype_conv_MultiArrayLayout.hpp"

/***************************
 *
 * PDU ==> ROS2
 *
 ***************************/
static inline int _pdu2ros_primitive_array_UInt16MultiArray_data(const char* heap_ptr, Hako_UInt16MultiArray &src, std_msgs::msg::UInt16MultiArray &dst)
{
    // Convert using len and off
    int offset = src._data_off;
    int length = src._data_len;
    if (length > 0) {
        dst.data.resize(length);
        memcpy(dst.data.data(), heap_ptr + offset, length * sizeof(Hako_uint16));
    }
    return 0;
}

static inline int _pdu2ros_UInt16MultiArray(const char* heap_ptr, Hako_UInt16MultiArray &src, std_msgs::msg::UInt16MultiArray &dst)
{
    // Struct convert
    _pdu2ros_MultiArrayLayout(heap_ptr, src.layout, dst.layout);
    // primitive array convertor
    _pdu2ros_primitive_array_UInt16MultiArray_data(heap_ptr, src, dst);
    (void)heap_ptr;
    return 0;
}

static inline int hako_convert_pdu2ros_UInt16MultiArray(Hako_UInt16MultiArray &src, std_msgs::msg::UInt16MultiArray &dst)
{
    void* base_ptr = (void*)&src;
    void* heap_ptr = hako_get_heap_ptr_pdu(base_ptr);
    // Validate magic number and version
    if (heap_ptr == nullptr) {
        return -1; // Invalid PDU metadata
    }
    else {
        return _pdu2ros_UInt16MultiArray((char*)heap_ptr, src, dst);
    }
}

/***************************
 *
 * ROS2 ==> PDU
 *
 ***************************/
static inline bool _ros2pdu_primitive_array_UInt16MultiArray_data(std_msgs::msg::UInt16MultiArray &src, Hako_UInt16MultiArray &dst, PduDynamicMemory &dynamic_memory)
{
    //Copy varray
    dst._data_len = src.data.size();
    if (dst._data_len > 0) {
        void* temp_ptr = dynamic_memory.allocate(dst._data_len, sizeof(Hako_uint16));
        memcpy(temp_ptr, src.data.data(), dst._data_len * sizeof(Hako_uint16));
        dst._data_off = dynamic_memory.get_offset(temp_ptr);
    }
    else {
        dst._data_off = dynamic_memory.get_total_size();
    }
    return true;
}

static inline bool _ros2pdu_UInt16MultiArray(std_msgs::msg::UInt16MultiArray &src, Hako_UInt16MultiArray &dst, PduDynamicMemory &dynamic_memory)
{
    try {
        // struct convert
        _ros2pdu_MultiArrayLayout(src.layout, dst.layout, dynamic_memory);
        //primitive array copy
        _ros2pdu_primitive_array_UInt16MultiArray_data(src, dst, dynamic_memory);
    } catch (const std::runtime_error& e) {
        std::cerr << "convertor error: " << e.what() << std::endl;
        return false;
    }
    (void)dynamic_memory;
    return true;
}

static inline int hako_convert_ros2pdu_UInt16MultiArray(std_msgs::msg::UInt16MultiArray &src, Hako_UInt16MultiArray** dst)
{
    PduDynamicMemory dynamic_memory;
    Hako_UInt16MultiArray out;
    if (!_ros2pdu_UInt16MultiArray(src, out, dynamic_memory)) {
        return -1;
    }
    int heap_size = dynamic_memory.get_total_size();
    void* base_ptr = hako_create_empty_pdu(sizeof(Hako_UInt16MultiArray), heap_size);
    if (base_ptr == nullptr) {
        return -1;
    }
    // Copy out on base data
    memcpy(base_ptr, (void*)&out, sizeof(Hako_UInt16MultiArray));

    // Copy dynamic part and set offsets
    void* heap_ptr = hako_get_heap_ptr_pdu(base_ptr);
    dynamic_memory.copy_to_pdu((char*)heap_ptr);

    *dst = (Hako_UInt16MultiArray*)base_ptr;
    return hako_get_pdu_meta_data(base_ptr)->total_size;
}

static inline Hako_UInt16MultiArray* hako_create_empty_pdu_UInt16MultiArray(int heap_size)
{
    // Allocate PDU memory
    char* base_ptr = (char*)hako_create_empty_pdu(sizeof(Hako_UInt16MultiArray), heap_size);
    if (base_ptr == nullptr) {
        return nullptr;
    }
    return (Hako_UInt16MultiArray*)base_ptr;
}
#endif /* _PDU_CTYPE_CONV_HAKO_std_msgs_UInt16MultiArray_HPP_ */
