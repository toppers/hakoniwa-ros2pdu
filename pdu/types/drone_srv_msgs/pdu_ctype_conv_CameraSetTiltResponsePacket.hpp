#ifndef _PDU_CTYPE_CONV_HAKO_drone_srv_msgs_CameraSetTiltResponsePacket_HPP_
#define _PDU_CTYPE_CONV_HAKO_drone_srv_msgs_CameraSetTiltResponsePacket_HPP_

#include "pdu_primitive_ctypes.h"
#include "ros_primitive_types.hpp"
#include "pdu_primitive_ctypes_conv.hpp"
#include "pdu_dynamic_memory.hpp"
/*
 * Dependent pdu data
 */
#include "drone_srv_msgs/pdu_ctype_CameraSetTiltResponsePacket.h"
/*
 * Dependent ros data
 */
#include "drone_srv_msgs/msg/camera_set_tilt_response_packet.hpp"

/*
 * Dependent Convertors
 */
#include "drone_srv_msgs/pdu_ctype_conv_CameraSetTiltResponse.hpp"
#include "hako_srv_msgs/pdu_ctype_conv_ServiceResponseHeader.hpp"

/***************************
 *
 * PDU ==> ROS2
 *
 ***************************/

static inline int _pdu2ros_CameraSetTiltResponsePacket(const char* heap_ptr, Hako_CameraSetTiltResponsePacket &src, drone_srv_msgs::msg::CameraSetTiltResponsePacket &dst)
{
    // Struct convert
    _pdu2ros_ServiceResponseHeader(heap_ptr, src.header, dst.header);
    // Struct convert
    _pdu2ros_CameraSetTiltResponse(heap_ptr, src.body, dst.body);
    (void)heap_ptr;
    return 0;
}

static inline int hako_convert_pdu2ros_CameraSetTiltResponsePacket(Hako_CameraSetTiltResponsePacket &src, drone_srv_msgs::msg::CameraSetTiltResponsePacket &dst)
{
    void* base_ptr = (void*)&src;
    void* heap_ptr = hako_get_heap_ptr_pdu(base_ptr);
    // Validate magic number and version
    if (heap_ptr == nullptr) {
        return -1; // Invalid PDU metadata
    }
    else {
        return _pdu2ros_CameraSetTiltResponsePacket((char*)heap_ptr, src, dst);
    }
}

/***************************
 *
 * ROS2 ==> PDU
 *
 ***************************/

static inline bool _ros2pdu_CameraSetTiltResponsePacket(drone_srv_msgs::msg::CameraSetTiltResponsePacket &src, Hako_CameraSetTiltResponsePacket &dst, PduDynamicMemory &dynamic_memory)
{
    try {
        // struct convert
        _ros2pdu_ServiceResponseHeader(src.header, dst.header, dynamic_memory);
        // struct convert
        _ros2pdu_CameraSetTiltResponse(src.body, dst.body, dynamic_memory);
    } catch (const std::runtime_error& e) {
        std::cerr << "convertor error: " << e.what() << std::endl;
        return false;
    }
    (void)dynamic_memory;
    return true;
}

static inline int hako_convert_ros2pdu_CameraSetTiltResponsePacket(drone_srv_msgs::msg::CameraSetTiltResponsePacket &src, Hako_CameraSetTiltResponsePacket** dst)
{
    PduDynamicMemory dynamic_memory;
    Hako_CameraSetTiltResponsePacket out;
    if (!_ros2pdu_CameraSetTiltResponsePacket(src, out, dynamic_memory)) {
        return -1;
    }
    int heap_size = dynamic_memory.get_total_size();
    void* base_ptr = hako_create_empty_pdu(sizeof(Hako_CameraSetTiltResponsePacket), heap_size);
    if (base_ptr == nullptr) {
        return -1;
    }
    // Copy out on base data
    memcpy(base_ptr, (void*)&out, sizeof(Hako_CameraSetTiltResponsePacket));

    // Copy dynamic part and set offsets
    void* heap_ptr = hako_get_heap_ptr_pdu(base_ptr);
    dynamic_memory.copy_to_pdu((char*)heap_ptr);

    *dst = (Hako_CameraSetTiltResponsePacket*)base_ptr;
    return hako_get_pdu_meta_data(base_ptr)->total_size;
}

static inline Hako_CameraSetTiltResponsePacket* hako_create_empty_pdu_CameraSetTiltResponsePacket(int heap_size)
{
    // Allocate PDU memory
    char* base_ptr = (char*)hako_create_empty_pdu(sizeof(Hako_CameraSetTiltResponsePacket), heap_size);
    if (base_ptr == nullptr) {
        return nullptr;
    }
    return (Hako_CameraSetTiltResponsePacket*)base_ptr;
}
#endif /* _PDU_CTYPE_CONV_HAKO_drone_srv_msgs_CameraSetTiltResponsePacket_HPP_ */
