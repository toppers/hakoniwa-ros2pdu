#ifndef _PDU_CTYPE_CONV_HAKO_drone_srv_msgs_DroneSetReadyResponse_HPP_
#define _PDU_CTYPE_CONV_HAKO_drone_srv_msgs_DroneSetReadyResponse_HPP_

#include "pdu_primitive_ctypes.h"
#include "ros_primitive_types.hpp"
#include "pdu_primitive_ctypes_conv.hpp"
#include "pdu_dynamic_memory.hpp"
/*
 * Dependent pdu data
 */
#include "drone_srv_msgs/pdu_ctype_DroneSetReadyResponse.h"
/*
 * Dependent ros data
 */
#include "drone_srv_msgs/msg/drone_set_ready_response.hpp"

/*
 * Dependent Convertors
 */

/***************************
 *
 * PDU ==> ROS2
 *
 ***************************/

static inline int _pdu2ros_DroneSetReadyResponse(const char* heap_ptr, Hako_DroneSetReadyResponse &src, drone_srv_msgs::msg::DroneSetReadyResponse &dst)
{
    // primitive convert
    hako_convert_pdu2ros(src.ok, dst.ok);
    // string convertor
    dst.message = (const char*)src.message;
    (void)heap_ptr;
    return 0;
}

static inline int hako_convert_pdu2ros_DroneSetReadyResponse(Hako_DroneSetReadyResponse &src, drone_srv_msgs::msg::DroneSetReadyResponse &dst)
{
    void* base_ptr = (void*)&src;
    void* heap_ptr = hako_get_heap_ptr_pdu(base_ptr);
    // Validate magic number and version
    if (heap_ptr == nullptr) {
        return -1; // Invalid PDU metadata
    }
    else {
        return _pdu2ros_DroneSetReadyResponse((char*)heap_ptr, src, dst);
    }
}

/***************************
 *
 * ROS2 ==> PDU
 *
 ***************************/

static inline bool _ros2pdu_DroneSetReadyResponse(drone_srv_msgs::msg::DroneSetReadyResponse &src, Hako_DroneSetReadyResponse &dst, PduDynamicMemory &dynamic_memory)
{
    try {
        // primitive convert
        hako_convert_ros2pdu(src.ok, dst.ok);
        // string convertor
        (void)hako_convert_ros2pdu_array(
            src.message, src.message.length(),
            dst.message, M_ARRAY_SIZE(Hako_DroneSetReadyResponse, char, message));
        dst.message[src.message.length()] = '\0';
    } catch (const std::runtime_error& e) {
        std::cerr << "convertor error: " << e.what() << std::endl;
        return false;
    }
    (void)dynamic_memory;
    return true;
}

static inline int hako_convert_ros2pdu_DroneSetReadyResponse(drone_srv_msgs::msg::DroneSetReadyResponse &src, Hako_DroneSetReadyResponse** dst)
{
    PduDynamicMemory dynamic_memory;
    Hako_DroneSetReadyResponse out;
    if (!_ros2pdu_DroneSetReadyResponse(src, out, dynamic_memory)) {
        return -1;
    }
    int heap_size = dynamic_memory.get_total_size();
    void* base_ptr = hako_create_empty_pdu(sizeof(Hako_DroneSetReadyResponse), heap_size);
    if (base_ptr == nullptr) {
        return -1;
    }
    // Copy out on base data
    memcpy(base_ptr, (void*)&out, sizeof(Hako_DroneSetReadyResponse));

    // Copy dynamic part and set offsets
    void* heap_ptr = hako_get_heap_ptr_pdu(base_ptr);
    dynamic_memory.copy_to_pdu((char*)heap_ptr);

    *dst = (Hako_DroneSetReadyResponse*)base_ptr;
    return hako_get_pdu_meta_data(base_ptr)->total_size;
}

static inline Hako_DroneSetReadyResponse* hako_create_empty_pdu_DroneSetReadyResponse(int heap_size)
{
    // Allocate PDU memory
    char* base_ptr = (char*)hako_create_empty_pdu(sizeof(Hako_DroneSetReadyResponse), heap_size);
    if (base_ptr == nullptr) {
        return nullptr;
    }
    return (Hako_DroneSetReadyResponse*)base_ptr;
}
#endif /* _PDU_CTYPE_CONV_HAKO_drone_srv_msgs_DroneSetReadyResponse_HPP_ */
