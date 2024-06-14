#ifndef _PDU_CTYPE_CONV_HAKO_can_msgs_HakoCanHead_HPP_
#define _PDU_CTYPE_CONV_HAKO_can_msgs_HakoCanHead_HPP_

#include "pdu_primitive_ctypes.h"
#include "ros_primitive_types.hpp"
#include "pdu_primitive_ctypes_conv.hpp"
#include "pdu_dynamic_memory.hpp"
/*
 * Dependent pdu data
 */
#include "can_msgs/pdu_ctype_HakoCanHead.h"
/*
 * Dependent ros data
 */
#include "can_msgs/msg/hako_can_head.hpp"

/*
 * Dependent Convertors
 */

/***************************
 *
 * PDU ==> ROS2
 *
 ***************************/

static inline int _pdu2ros_HakoCanHead(const char* heap_ptr, Hako_HakoCanHead &src, can_msgs::msg::HakoCanHead &dst)
{
    // primitive convert
    hako_convert_pdu2ros(src.channel, dst.channel);
    // primitive convert
    hako_convert_pdu2ros(src.ide, dst.ide);
    // primitive convert
    hako_convert_pdu2ros(src.rtr, dst.rtr);
    // primitive convert
    hako_convert_pdu2ros(src.dlc, dst.dlc);
    // primitive convert
    hako_convert_pdu2ros(src.canid, dst.canid);
    (void)heap_ptr;
    return 0;
}

static inline int hako_convert_pdu2ros_HakoCanHead(Hako_HakoCanHead &src, can_msgs::msg::HakoCanHead &dst)
{
    void* base_ptr = (void*)&src;
    void* heap_ptr = hako_get_heap_ptr_pdu(base_ptr);
    // Validate magic number and version
    if (heap_ptr == nullptr) {
        return -1; // Invalid PDU metadata
    }
    else {
        return _pdu2ros_HakoCanHead((char*)heap_ptr, src, dst);
    }
}

/***************************
 *
 * ROS2 ==> PDU
 *
 ***************************/

static inline bool _ros2pdu_HakoCanHead(can_msgs::msg::HakoCanHead &src, Hako_HakoCanHead &dst, PduDynamicMemory &dynamic_memory)
{
    try {
        // primitive convert
        hako_convert_ros2pdu(src.channel, dst.channel);
        // primitive convert
        hako_convert_ros2pdu(src.ide, dst.ide);
        // primitive convert
        hako_convert_ros2pdu(src.rtr, dst.rtr);
        // primitive convert
        hako_convert_ros2pdu(src.dlc, dst.dlc);
        // primitive convert
        hako_convert_ros2pdu(src.canid, dst.canid);
    } catch (const std::runtime_error& e) {
        std::cerr << "convertor error: " << e.what() << std::endl;
        return false;
    }
    (void)dynamic_memory;
    return true;
}

static inline int hako_convert_ros2pdu_HakoCanHead(can_msgs::msg::HakoCanHead &src, Hako_HakoCanHead** dst)
{
    PduDynamicMemory dynamic_memory;
    Hako_HakoCanHead out;
    if (!_ros2pdu_HakoCanHead(src, out, dynamic_memory)) {
        return -1;
    }
    int heap_size = dynamic_memory.get_total_size();
    void* base_ptr = hako_create_empty_pdu(sizeof(Hako_HakoCanHead), heap_size);
    if (base_ptr == nullptr) {
        return -1;
    }
    // Copy out on base data
    memcpy(base_ptr, (void*)&out, sizeof(Hako_HakoCanHead));

    // Copy dynamic part and set offsets
    void* heap_ptr = hako_get_heap_ptr_pdu(base_ptr);
    dynamic_memory.copy_to_pdu((char*)heap_ptr);

    *dst = (Hako_HakoCanHead*)base_ptr;
    return hako_get_pdu_meta_data(base_ptr)->total_size;
}

static inline Hako_HakoCanHead* hako_create_empty_pdu_HakoCanHead(int heap_size)
{
    // Allocate PDU memory
    char* base_ptr = (char*)hako_create_empty_pdu(sizeof(Hako_HakoCanHead), heap_size);
    if (base_ptr == nullptr) {
        return nullptr;
    }
    return (Hako_HakoCanHead*)base_ptr;
}
#endif /* _PDU_CTYPE_CONV_HAKO_can_msgs_HakoCanHead_HPP_ */
