#ifndef _PDU_CTYPE_CONV_HAKO_drone_srv_msgs_MagnetGrabRequest_HPP_
#define _PDU_CTYPE_CONV_HAKO_drone_srv_msgs_MagnetGrabRequest_HPP_

#include "pdu_primitive_ctypes.h"
#include "ros_primitive_types.hpp"
#include "pdu_primitive_ctypes_conv.hpp"
#include "pdu_dynamic_memory.hpp"
/*
 * Dependent pdu data
 */
#include "drone_srv_msgs/pdu_ctype_MagnetGrabRequest.h"
/*
 * Dependent ros data
 */
#include "drone_srv_msgs/msg/magnet_grab_request.hpp"

/*
 * Dependent Convertors
 */

/***************************
 *
 * PDU ==> ROS2
 *
 ***************************/

static inline int _pdu2ros_MagnetGrabRequest(const char* heap_ptr, Hako_MagnetGrabRequest &src, drone_srv_msgs::msg::MagnetGrabRequest &dst)
{
    // string convertor
    dst.drone_name = (const char*)src.drone_name;
    // primitive convert
    hako_convert_pdu2ros(src.grab_on, dst.grab_on);
    // primitive convert
    hako_convert_pdu2ros(src.timeout_sec, dst.timeout_sec);
    (void)heap_ptr;
    return 0;
}

static inline int hako_convert_pdu2ros_MagnetGrabRequest(Hako_MagnetGrabRequest &src, drone_srv_msgs::msg::MagnetGrabRequest &dst)
{
    void* base_ptr = (void*)&src;
    void* heap_ptr = hako_get_heap_ptr_pdu(base_ptr);
    // Validate magic number and version
    if (heap_ptr == nullptr) {
        return -1; // Invalid PDU metadata
    }
    else {
        return _pdu2ros_MagnetGrabRequest((char*)heap_ptr, src, dst);
    }
}

/***************************
 *
 * ROS2 ==> PDU
 *
 ***************************/

static inline bool _ros2pdu_MagnetGrabRequest(drone_srv_msgs::msg::MagnetGrabRequest &src, Hako_MagnetGrabRequest &dst, PduDynamicMemory &dynamic_memory)
{
    try {
        // string convertor
        (void)hako_convert_ros2pdu_array(
            src.drone_name, src.drone_name.length(),
            dst.drone_name, M_ARRAY_SIZE(Hako_MagnetGrabRequest, char, drone_name));
        dst.drone_name[src.drone_name.length()] = '\0';
        // primitive convert
        hako_convert_ros2pdu(src.grab_on, dst.grab_on);
        // primitive convert
        hako_convert_ros2pdu(src.timeout_sec, dst.timeout_sec);
    } catch (const std::runtime_error& e) {
        std::cerr << "convertor error: " << e.what() << std::endl;
        return false;
    }
    (void)dynamic_memory;
    return true;
}

static inline int hako_convert_ros2pdu_MagnetGrabRequest(drone_srv_msgs::msg::MagnetGrabRequest &src, Hako_MagnetGrabRequest** dst)
{
    PduDynamicMemory dynamic_memory;
    Hako_MagnetGrabRequest out;
    if (!_ros2pdu_MagnetGrabRequest(src, out, dynamic_memory)) {
        return -1;
    }
    int heap_size = dynamic_memory.get_total_size();
    void* base_ptr = hako_create_empty_pdu(sizeof(Hako_MagnetGrabRequest), heap_size);
    if (base_ptr == nullptr) {
        return -1;
    }
    // Copy out on base data
    memcpy(base_ptr, (void*)&out, sizeof(Hako_MagnetGrabRequest));

    // Copy dynamic part and set offsets
    void* heap_ptr = hako_get_heap_ptr_pdu(base_ptr);
    dynamic_memory.copy_to_pdu((char*)heap_ptr);

    *dst = (Hako_MagnetGrabRequest*)base_ptr;
    return hako_get_pdu_meta_data(base_ptr)->total_size;
}

static inline Hako_MagnetGrabRequest* hako_create_empty_pdu_MagnetGrabRequest(int heap_size)
{
    // Allocate PDU memory
    char* base_ptr = (char*)hako_create_empty_pdu(sizeof(Hako_MagnetGrabRequest), heap_size);
    if (base_ptr == nullptr) {
        return nullptr;
    }
    return (Hako_MagnetGrabRequest*)base_ptr;
}
#endif /* _PDU_CTYPE_CONV_HAKO_drone_srv_msgs_MagnetGrabRequest_HPP_ */
