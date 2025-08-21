#ifndef _PDU_CTYPE_CONV_HAKO_hako_srv_msgs_RegisterClientResponsePacket_HPP_
#define _PDU_CTYPE_CONV_HAKO_hako_srv_msgs_RegisterClientResponsePacket_HPP_

#include "pdu_primitive_ctypes.h"
#include "ros_primitive_types.hpp"
#include "pdu_primitive_ctypes_conv.hpp"
#include "pdu_dynamic_memory.hpp"
/*
 * Dependent pdu data
 */
#include "hako_srv_msgs/pdu_ctype_RegisterClientResponsePacket.h"
/*
 * Dependent ros data
 */
#include "hako_srv_msgs/msg/register_client_response_packet.hpp"

/*
 * Dependent Convertors
 */
#include "hako_srv_msgs/pdu_ctype_conv_RegisterClientResponse.hpp"
#include "hako_srv_msgs/pdu_ctype_conv_ServiceResponseHeader.hpp"

/***************************
 *
 * PDU ==> ROS2
 *
 ***************************/

static inline int _pdu2ros_RegisterClientResponsePacket(const char* heap_ptr, Hako_RegisterClientResponsePacket &src, hako_srv_msgs::msg::RegisterClientResponsePacket &dst)
{
    // Struct convert
    _pdu2ros_ServiceResponseHeader(heap_ptr, src.header, dst.header);
    // Struct convert
    _pdu2ros_RegisterClientResponse(heap_ptr, src.body, dst.body);
    (void)heap_ptr;
    return 0;
}

static inline int hako_convert_pdu2ros_RegisterClientResponsePacket(Hako_RegisterClientResponsePacket &src, hako_srv_msgs::msg::RegisterClientResponsePacket &dst)
{
    void* base_ptr = (void*)&src;
    void* heap_ptr = hako_get_heap_ptr_pdu(base_ptr);
    // Validate magic number and version
    if (heap_ptr == nullptr) {
        return -1; // Invalid PDU metadata
    }
    else {
        return _pdu2ros_RegisterClientResponsePacket((char*)heap_ptr, src, dst);
    }
}

/***************************
 *
 * ROS2 ==> PDU
 *
 ***************************/

static inline bool _ros2pdu_RegisterClientResponsePacket(hako_srv_msgs::msg::RegisterClientResponsePacket &src, Hako_RegisterClientResponsePacket &dst, PduDynamicMemory &dynamic_memory)
{
    try {
        // struct convert
        _ros2pdu_ServiceResponseHeader(src.header, dst.header, dynamic_memory);
        // struct convert
        _ros2pdu_RegisterClientResponse(src.body, dst.body, dynamic_memory);
    } catch (const std::runtime_error& e) {
        std::cerr << "convertor error: " << e.what() << std::endl;
        return false;
    }
    (void)dynamic_memory;
    return true;
}

static inline int hako_convert_ros2pdu_RegisterClientResponsePacket(hako_srv_msgs::msg::RegisterClientResponsePacket &src, Hako_RegisterClientResponsePacket** dst)
{
    PduDynamicMemory dynamic_memory;
    Hako_RegisterClientResponsePacket out;
    if (!_ros2pdu_RegisterClientResponsePacket(src, out, dynamic_memory)) {
        return -1;
    }
    int heap_size = dynamic_memory.get_total_size();
    void* base_ptr = hako_create_empty_pdu(sizeof(Hako_RegisterClientResponsePacket), heap_size);
    if (base_ptr == nullptr) {
        return -1;
    }
    // Copy out on base data
    memcpy(base_ptr, (void*)&out, sizeof(Hako_RegisterClientResponsePacket));

    // Copy dynamic part and set offsets
    void* heap_ptr = hako_get_heap_ptr_pdu(base_ptr);
    dynamic_memory.copy_to_pdu((char*)heap_ptr);

    *dst = (Hako_RegisterClientResponsePacket*)base_ptr;
    return hako_get_pdu_meta_data(base_ptr)->total_size;
}

static inline Hako_RegisterClientResponsePacket* hako_create_empty_pdu_RegisterClientResponsePacket(int heap_size)
{
    // Allocate PDU memory
    char* base_ptr = (char*)hako_create_empty_pdu(sizeof(Hako_RegisterClientResponsePacket), heap_size);
    if (base_ptr == nullptr) {
        return nullptr;
    }
    return (Hako_RegisterClientResponsePacket*)base_ptr;
}
#endif /* _PDU_CTYPE_CONV_HAKO_hako_srv_msgs_RegisterClientResponsePacket_HPP_ */
