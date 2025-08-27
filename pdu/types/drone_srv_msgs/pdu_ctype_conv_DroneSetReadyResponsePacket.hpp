#ifndef _PDU_CTYPE_CONV_HAKO_drone_srv_msgs_DroneSetReadyResponsePacket_HPP_
#define _PDU_CTYPE_CONV_HAKO_drone_srv_msgs_DroneSetReadyResponsePacket_HPP_

#include "pdu_primitive_ctypes.h"
#include "ros_primitive_types.hpp"
#include "pdu_primitive_ctypes_conv.hpp"
#include "pdu_dynamic_memory.hpp"
/*
 * Dependent pdu data
 */
#include "drone_srv_msgs/pdu_ctype_DroneSetReadyResponsePacket.h"
/*
 * Dependent ros data
 */
#include "drone_srv_msgs/msg/drone_set_ready_response_packet.hpp"

/*
 * Dependent Convertors
 */
#include "drone_srv_msgs/pdu_ctype_conv_DroneSetReadyResponse.hpp"
#include "hako_srv_msgs/pdu_ctype_conv_ServiceResponseHeader.hpp"

/***************************
 *
 * PDU ==> ROS2
 *
 ***************************/

static inline int _pdu2ros_DroneSetReadyResponsePacket(const char* heap_ptr, Hako_DroneSetReadyResponsePacket &src, drone_srv_msgs::msg::DroneSetReadyResponsePacket &dst)
{
    // Struct convert
    _pdu2ros_ServiceResponseHeader(heap_ptr, src.header, dst.header);
    // Struct convert
    _pdu2ros_DroneSetReadyResponse(heap_ptr, src.body, dst.body);
    (void)heap_ptr;
    return 0;
}

static inline int hako_convert_pdu2ros_DroneSetReadyResponsePacket(Hako_DroneSetReadyResponsePacket &src, drone_srv_msgs::msg::DroneSetReadyResponsePacket &dst)
{
    void* base_ptr = (void*)&src;
    void* heap_ptr = hako_get_heap_ptr_pdu(base_ptr);
    // Validate magic number and version
    if (heap_ptr == nullptr) {
        return -1; // Invalid PDU metadata
    }
    else {
        return _pdu2ros_DroneSetReadyResponsePacket((char*)heap_ptr, src, dst);
    }
}

/***************************
 *
 * ROS2 ==> PDU
 *
 ***************************/

static inline bool _ros2pdu_DroneSetReadyResponsePacket(drone_srv_msgs::msg::DroneSetReadyResponsePacket &src, Hako_DroneSetReadyResponsePacket &dst, PduDynamicMemory &dynamic_memory)
{
    try {
        // struct convert
        _ros2pdu_ServiceResponseHeader(src.header, dst.header, dynamic_memory);
        // struct convert
        _ros2pdu_DroneSetReadyResponse(src.body, dst.body, dynamic_memory);
    } catch (const std::runtime_error& e) {
        std::cerr << "convertor error: " << e.what() << std::endl;
        return false;
    }
    (void)dynamic_memory;
    return true;
}

static inline int hako_convert_ros2pdu_DroneSetReadyResponsePacket(drone_srv_msgs::msg::DroneSetReadyResponsePacket &src, Hako_DroneSetReadyResponsePacket** dst)
{
    PduDynamicMemory dynamic_memory;
    Hako_DroneSetReadyResponsePacket out;
    if (!_ros2pdu_DroneSetReadyResponsePacket(src, out, dynamic_memory)) {
        return -1;
    }
    int heap_size = dynamic_memory.get_total_size();
    void* base_ptr = hako_create_empty_pdu(sizeof(Hako_DroneSetReadyResponsePacket), heap_size);
    if (base_ptr == nullptr) {
        return -1;
    }
    // Copy out on base data
    memcpy(base_ptr, (void*)&out, sizeof(Hako_DroneSetReadyResponsePacket));

    // Copy dynamic part and set offsets
    void* heap_ptr = hako_get_heap_ptr_pdu(base_ptr);
    dynamic_memory.copy_to_pdu((char*)heap_ptr);

    *dst = (Hako_DroneSetReadyResponsePacket*)base_ptr;
    return hako_get_pdu_meta_data(base_ptr)->total_size;
}

static inline Hako_DroneSetReadyResponsePacket* hako_create_empty_pdu_DroneSetReadyResponsePacket(int heap_size)
{
    // Allocate PDU memory
    char* base_ptr = (char*)hako_create_empty_pdu(sizeof(Hako_DroneSetReadyResponsePacket), heap_size);
    if (base_ptr == nullptr) {
        return nullptr;
    }
    return (Hako_DroneSetReadyResponsePacket*)base_ptr;
}
#endif /* _PDU_CTYPE_CONV_HAKO_drone_srv_msgs_DroneSetReadyResponsePacket_HPP_ */
