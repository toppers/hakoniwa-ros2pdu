#ifndef _PDU_CTYPE_CONV_HAKO_hako_msgs_HakoCmdCamera_HPP_
#define _PDU_CTYPE_CONV_HAKO_hako_msgs_HakoCmdCamera_HPP_

#include "pdu_primitive_ctypes.h"
#include "ros_primitive_types.hpp"
#include "pdu_primitive_ctypes_conv.hpp"
#include "pdu_dynamic_memory.hpp"
/*
 * Dependent pdu data
 */
#include "hako_msgs/pdu_ctype_HakoCmdCamera.h"
/*
 * Dependent ros data
 */
#include "hako_msgs/msg/hako_cmd_camera.hpp"

/*
 * Dependent Convertors
 */
#include "hako_msgs/pdu_ctype_conv_HakoCmdHeader.hpp"

/***************************
 *
 * PDU ==> ROS2
 *
 ***************************/

static inline int _pdu2ros_HakoCmdCamera(const char* heap_ptr, Hako_HakoCmdCamera &src, hako_msgs::msg::HakoCmdCamera &dst)
{
    // Struct convert
    _pdu2ros_HakoCmdHeader(heap_ptr, src.header, dst.header);
    // primitive convert
    hako_convert_pdu2ros(src.request_id, dst.request_id);
    // primitive convert
    hako_convert_pdu2ros(src.encode_type, dst.encode_type);
    (void)heap_ptr;
    return 0;
}

static inline int hako_convert_pdu2ros_HakoCmdCamera(Hako_HakoCmdCamera &src, hako_msgs::msg::HakoCmdCamera &dst)
{
    void* base_ptr = (void*)&src;
    void* heap_ptr = hako_get_heap_ptr_pdu(base_ptr);
    // Validate magic number and version
    if (heap_ptr == nullptr) {
        return -1; // Invalid PDU metadata
    }
    else {
        return _pdu2ros_HakoCmdCamera((char*)heap_ptr, src, dst);
    }
}

/***************************
 *
 * ROS2 ==> PDU
 *
 ***************************/

static inline bool _ros2pdu_HakoCmdCamera(hako_msgs::msg::HakoCmdCamera &src, Hako_HakoCmdCamera &dst, PduDynamicMemory &dynamic_memory)
{
    try {
        // struct convert
        _ros2pdu_HakoCmdHeader(src.header, dst.header, dynamic_memory);
        // primitive convert
        hako_convert_ros2pdu(src.request_id, dst.request_id);
        // primitive convert
        hako_convert_ros2pdu(src.encode_type, dst.encode_type);
    } catch (const std::runtime_error& e) {
        std::cerr << "convertor error: " << e.what() << std::endl;
        return false;
    }
    (void)dynamic_memory;
    return true;
}

static inline int hako_convert_ros2pdu_HakoCmdCamera(hako_msgs::msg::HakoCmdCamera &src, Hako_HakoCmdCamera** dst)
{
    PduDynamicMemory dynamic_memory;
    Hako_HakoCmdCamera out;
    if (!_ros2pdu_HakoCmdCamera(src, out, dynamic_memory)) {
        return -1;
    }
    int heap_size = dynamic_memory.get_total_size();
    void* base_ptr = hako_create_empty_pdu(sizeof(Hako_HakoCmdCamera), heap_size);
    if (base_ptr == nullptr) {
        return -1;
    }
    // Copy out on base data
    memcpy(base_ptr, (void*)&out, sizeof(Hako_HakoCmdCamera));

    // Copy dynamic part and set offsets
    void* heap_ptr = hako_get_heap_ptr_pdu(base_ptr);
    dynamic_memory.copy_to_pdu((char*)heap_ptr);

    *dst = (Hako_HakoCmdCamera*)base_ptr;
    return hako_get_pdu_meta_data(base_ptr)->total_size;
}

static inline Hako_HakoCmdCamera* hako_create_empty_pdu_HakoCmdCamera(int heap_size)
{
    // Allocate PDU memory
    char* base_ptr = (char*)hako_create_empty_pdu(sizeof(Hako_HakoCmdCamera), heap_size);
    if (base_ptr == nullptr) {
        return nullptr;
    }
    return (Hako_HakoCmdCamera*)base_ptr;
}
#endif /* _PDU_CTYPE_CONV_HAKO_hako_msgs_HakoCmdCamera_HPP_ */
