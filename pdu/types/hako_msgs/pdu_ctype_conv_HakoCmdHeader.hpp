#ifndef _PDU_CTYPE_CONV_HAKO_hako_msgs_HakoCmdHeader_HPP_
#define _PDU_CTYPE_CONV_HAKO_hako_msgs_HakoCmdHeader_HPP_

#include "pdu_primitive_ctypes.h"
#include "ros_primitive_types.hpp"
#include "pdu_primitive_ctypes_conv.hpp"
#include "pdu_dynamic_memory.hpp"
/*
 * Dependent pdu data
 */
#include "hako_msgs/pdu_ctype_HakoCmdHeader.h"
/*
 * Dependent ros data
 */
#include "hako_msgs/msg/hako_cmd_header.hpp"

/*
 * Dependent Convertors
 */

/***************************
 *
 * PDU ==> ROS2
 *
 ***************************/

static inline int _pdu2ros_HakoCmdHeader(const char* heap_ptr, Hako_HakoCmdHeader &src, hako_msgs::msg::HakoCmdHeader &dst)
{
    // primitive convert
    hako_convert_pdu2ros(src.request, dst.request);
    // primitive convert
    hako_convert_pdu2ros(src.result, dst.result);
    // primitive convert
    hako_convert_pdu2ros(src.result_code, dst.result_code);
    (void)heap_ptr;
    return 0;
}

static inline int hako_convert_pdu2ros_HakoCmdHeader(Hako_HakoCmdHeader &src, hako_msgs::msg::HakoCmdHeader &dst)
{
    void* base_ptr = (void*)&src;
    void* heap_ptr = hako_get_heap_ptr_pdu(base_ptr);
    // Validate magic number and version
    if (heap_ptr == nullptr) {
        return -1; // Invalid PDU metadata
    }
    else {
        return _pdu2ros_HakoCmdHeader((char*)heap_ptr, src, dst);
    }
}

/***************************
 *
 * ROS2 ==> PDU
 *
 ***************************/

static inline bool _ros2pdu_HakoCmdHeader(hako_msgs::msg::HakoCmdHeader &src, Hako_HakoCmdHeader &dst, PduDynamicMemory &dynamic_memory)
{
    try {
        // primitive convert
        hako_convert_ros2pdu(src.request, dst.request);
        // primitive convert
        hako_convert_ros2pdu(src.result, dst.result);
        // primitive convert
        hako_convert_ros2pdu(src.result_code, dst.result_code);
    } catch (const std::runtime_error& e) {
        std::cerr << "convertor error: " << e.what() << std::endl;
        return false;
    }
    (void)dynamic_memory;
    return true;
}

static inline int hako_convert_ros2pdu_HakoCmdHeader(hako_msgs::msg::HakoCmdHeader &src, Hako_HakoCmdHeader** dst)
{
    PduDynamicMemory dynamic_memory;
    Hako_HakoCmdHeader out;
    if (!_ros2pdu_HakoCmdHeader(src, out, dynamic_memory)) {
        return -1;
    }
    int heap_size = dynamic_memory.get_total_size();
    void* base_ptr = hako_create_empty_pdu(sizeof(Hako_HakoCmdHeader), heap_size);
    if (base_ptr == nullptr) {
        return -1;
    }
    // Copy out on base data
    memcpy(base_ptr, (void*)&out, sizeof(Hako_HakoCmdHeader));

    // Copy dynamic part and set offsets
    void* heap_ptr = hako_get_heap_ptr_pdu(base_ptr);
    dynamic_memory.copy_to_pdu((char*)heap_ptr);

    *dst = (Hako_HakoCmdHeader*)base_ptr;
    return hako_get_pdu_meta_data(base_ptr)->total_size;
}

static inline Hako_HakoCmdHeader* hako_create_empty_pdu_HakoCmdHeader(int heap_size)
{
    // Allocate PDU memory
    char* base_ptr = (char*)hako_create_empty_pdu(sizeof(Hako_HakoCmdHeader), heap_size);
    if (base_ptr == nullptr) {
        return nullptr;
    }
    return (Hako_HakoCmdHeader*)base_ptr;
}
#endif /* _PDU_CTYPE_CONV_HAKO_hako_msgs_HakoCmdHeader_HPP_ */
