#ifndef _PDU_CTYPE_CONV_HAKO_can_msgs_HakoCanBody_HPP_
#define _PDU_CTYPE_CONV_HAKO_can_msgs_HakoCanBody_HPP_

#include "pdu_primitive_ctypes.h"
#include "ros_primitive_types.hpp"
#include "pdu_primitive_ctypes_conv.hpp"
#include "pdu_dynamic_memory.hpp"
/*
 * Dependent pdu data
 */
#include "can_msgs/pdu_ctype_HakoCanBody.h"
/*
 * Dependent ros data
 */
#include "can_msgs/msg/hako_can_body.hpp"

/*
 * Dependent Convertors
 */

/***************************
 *
 * PDU ==> ROS2
 *
 ***************************/
static inline int _pdu2ros_primitive_array_HakoCanBody_data(const char* heap_ptr, Hako_HakoCanBody &src, can_msgs::msg::HakoCanBody &dst)
{
    // Fixed size array convertor
    (void)heap_ptr;
    for (int i = 0; i < 8; ++i) {
        hako_convert_pdu2ros(src.data[i], dst.data[i]);
    }
    return 0;
}

static inline int _pdu2ros_HakoCanBody(const char* heap_ptr, Hako_HakoCanBody &src, can_msgs::msg::HakoCanBody &dst)
{
    // primitive array convertor
    _pdu2ros_primitive_array_HakoCanBody_data(heap_ptr, src, dst);
    (void)heap_ptr;
    return 0;
}

static inline int hako_convert_pdu2ros_HakoCanBody(Hako_HakoCanBody &src, can_msgs::msg::HakoCanBody &dst)
{
    void* base_ptr = (void*)&src;
    void* heap_ptr = hako_get_heap_ptr_pdu(base_ptr);
    // Validate magic number and version
    if (heap_ptr == nullptr) {
        return -1; // Invalid PDU metadata
    }
    else {
        return _pdu2ros_HakoCanBody((char*)heap_ptr, src, dst);
    }
}

/***************************
 *
 * ROS2 ==> PDU
 *
 ***************************/
static inline bool _ros2pdu_primitive_array_HakoCanBody_data(can_msgs::msg::HakoCanBody &src, Hako_HakoCanBody &dst, PduDynamicMemory &dynamic_memory)
{
    //Copy fixed array 8
    (void)dynamic_memory;
    (void)hako_convert_ros2pdu_array(
        src.data, src.data.size(),
        dst.data, M_ARRAY_SIZE(Hako_HakoCanBody, Hako_uint8, data));
    return true;
}

static inline bool _ros2pdu_HakoCanBody(can_msgs::msg::HakoCanBody &src, Hako_HakoCanBody &dst, PduDynamicMemory &dynamic_memory)
{
    try {
        //primitive array copy
        _ros2pdu_primitive_array_HakoCanBody_data(src, dst, dynamic_memory);
    } catch (const std::runtime_error& e) {
        std::cerr << "convertor error: " << e.what() << std::endl;
        return false;
    }
    (void)dynamic_memory;
    return true;
}

static inline int hako_convert_ros2pdu_HakoCanBody(can_msgs::msg::HakoCanBody &src, Hako_HakoCanBody** dst)
{
    PduDynamicMemory dynamic_memory;
    Hako_HakoCanBody out;
    if (!_ros2pdu_HakoCanBody(src, out, dynamic_memory)) {
        return -1;
    }
    int heap_size = dynamic_memory.get_total_size();
    void* base_ptr = hako_create_empty_pdu(sizeof(Hako_HakoCanBody), heap_size);
    if (base_ptr == nullptr) {
        return -1;
    }
    // Copy out on base data
    memcpy(base_ptr, (void*)&out, sizeof(Hako_HakoCanBody));

    // Copy dynamic part and set offsets
    void* heap_ptr = hako_get_heap_ptr_pdu(base_ptr);
    dynamic_memory.copy_to_pdu((char*)heap_ptr);

    *dst = (Hako_HakoCanBody*)base_ptr;
    return hako_get_pdu_meta_data(base_ptr)->total_size;
}

static inline Hako_HakoCanBody* hako_create_empty_pdu_HakoCanBody(int heap_size)
{
    // Allocate PDU memory
    char* base_ptr = (char*)hako_create_empty_pdu(sizeof(Hako_HakoCanBody), heap_size);
    if (base_ptr == nullptr) {
        return nullptr;
    }
    return (Hako_HakoCanBody*)base_ptr;
}
#endif /* _PDU_CTYPE_CONV_HAKO_can_msgs_HakoCanBody_HPP_ */
