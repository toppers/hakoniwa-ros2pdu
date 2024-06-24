#ifndef _PDU_CTYPE_CONV_HAKO_can_msgs_HakoCan_HPP_
#define _PDU_CTYPE_CONV_HAKO_can_msgs_HakoCan_HPP_

#include "pdu_primitive_ctypes.h"
#include "ros_primitive_types.hpp"
#include "pdu_primitive_ctypes_conv.hpp"
#include "pdu_dynamic_memory.hpp"
/*
 * Dependent pdu data
 */
#include "can_msgs/pdu_ctype_HakoCan.h"
/*
 * Dependent ros data
 */
#include "can_msgs/msg/hako_can.hpp"

/*
 * Dependent Convertors
 */
#include "can_msgs/pdu_ctype_conv_HakoCanBody.hpp"
#include "can_msgs/pdu_ctype_conv_HakoCanHead.hpp"

/***************************
 *
 * PDU ==> ROS2
 *
 ***************************/

static inline int _pdu2ros_HakoCan(const char* heap_ptr, Hako_HakoCan &src, can_msgs::msg::HakoCan &dst)
{
    // Struct convert
    _pdu2ros_HakoCanHead(heap_ptr, src.head, dst.head);
    // Struct convert
    _pdu2ros_HakoCanBody(heap_ptr, src.body, dst.body);
    (void)heap_ptr;
    return 0;
}

static inline int hako_convert_pdu2ros_HakoCan(Hako_HakoCan &src, can_msgs::msg::HakoCan &dst)
{
    void* base_ptr = (void*)&src;
    void* heap_ptr = hako_get_heap_ptr_pdu(base_ptr);
    // Validate magic number and version
    if (heap_ptr == nullptr) {
        return -1; // Invalid PDU metadata
    }
    else {
        return _pdu2ros_HakoCan((char*)heap_ptr, src, dst);
    }
}

/***************************
 *
 * ROS2 ==> PDU
 *
 ***************************/

static inline bool _ros2pdu_HakoCan(can_msgs::msg::HakoCan &src, Hako_HakoCan &dst, PduDynamicMemory &dynamic_memory)
{
    try {
        // struct convert
        _ros2pdu_HakoCanHead(src.head, dst.head, dynamic_memory);
        // struct convert
        _ros2pdu_HakoCanBody(src.body, dst.body, dynamic_memory);
    } catch (const std::runtime_error& e) {
        std::cerr << "convertor error: " << e.what() << std::endl;
        return false;
    }
    (void)dynamic_memory;
    return true;
}

static inline int hako_convert_ros2pdu_HakoCan(can_msgs::msg::HakoCan &src, Hako_HakoCan** dst)
{
    PduDynamicMemory dynamic_memory;
    Hako_HakoCan out;
    if (!_ros2pdu_HakoCan(src, out, dynamic_memory)) {
        return -1;
    }
    int heap_size = dynamic_memory.get_total_size();
    void* base_ptr = hako_create_empty_pdu(sizeof(Hako_HakoCan), heap_size);
    if (base_ptr == nullptr) {
        return -1;
    }
    // Copy out on base data
    memcpy(base_ptr, (void*)&out, sizeof(Hako_HakoCan));

    // Copy dynamic part and set offsets
    void* heap_ptr = hako_get_heap_ptr_pdu(base_ptr);
    dynamic_memory.copy_to_pdu((char*)heap_ptr);

    *dst = (Hako_HakoCan*)base_ptr;
    return hako_get_pdu_meta_data(base_ptr)->total_size;
}

static inline Hako_HakoCan* hako_create_empty_pdu_HakoCan(int heap_size)
{
    // Allocate PDU memory
    char* base_ptr = (char*)hako_create_empty_pdu(sizeof(Hako_HakoCan), heap_size);
    if (base_ptr == nullptr) {
        return nullptr;
    }
    return (Hako_HakoCan*)base_ptr;
}
#endif /* _PDU_CTYPE_CONV_HAKO_can_msgs_HakoCan_HPP_ */
