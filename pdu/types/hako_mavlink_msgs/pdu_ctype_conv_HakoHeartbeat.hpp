#ifndef _PDU_CTYPE_CONV_HAKO_hako_mavlink_msgs_HakoHeartbeat_HPP_
#define _PDU_CTYPE_CONV_HAKO_hako_mavlink_msgs_HakoHeartbeat_HPP_

#include "pdu_primitive_ctypes.h"
#include "ros_primitive_types.hpp"
#include "pdu_primitive_ctypes_conv.hpp"
#include "pdu_dynamic_memory.hpp"
/*
 * Dependent pdu data
 */
#include "hako_mavlink_msgs/pdu_ctype_HakoHeartbeat.h"
/*
 * Dependent ros data
 */
#include "hako_mavlink_msgs/msg/hako_heartbeat.hpp"

/*
 * Dependent Convertors
 */

/***************************
 *
 * PDU ==> ROS2
 *
 ***************************/

static inline int _pdu2ros_HakoHeartbeat(const char* heap_ptr, Hako_HakoHeartbeat &src, hako_mavlink_msgs::msg::HakoHeartbeat &dst)
{
    // primitive convert
    hako_convert_pdu2ros(src.type, dst.type);
    // primitive convert
    hako_convert_pdu2ros(src.autopilot, dst.autopilot);
    // primitive convert
    hako_convert_pdu2ros(src.base_mode, dst.base_mode);
    // primitive convert
    hako_convert_pdu2ros(src.custom_mode, dst.custom_mode);
    // primitive convert
    hako_convert_pdu2ros(src.system_status, dst.system_status);
    // primitive convert
    hako_convert_pdu2ros(src.mavlink_version, dst.mavlink_version);
    (void)heap_ptr;
    return 0;
}

static inline int hako_convert_pdu2ros_HakoHeartbeat(Hako_HakoHeartbeat &src, hako_mavlink_msgs::msg::HakoHeartbeat &dst)
{
    void* base_ptr = (void*)&src;
    void* heap_ptr = hako_get_heap_ptr_pdu(base_ptr);
    // Validate magic number and version
    if (heap_ptr == nullptr) {
        return -1; // Invalid PDU metadata
    }
    else {
        return _pdu2ros_HakoHeartbeat((char*)heap_ptr, src, dst);
    }
}

/***************************
 *
 * ROS2 ==> PDU
 *
 ***************************/

static inline bool _ros2pdu_HakoHeartbeat(hako_mavlink_msgs::msg::HakoHeartbeat &src, Hako_HakoHeartbeat &dst, PduDynamicMemory &dynamic_memory)
{
    try {
        // primitive convert
        hako_convert_ros2pdu(src.type, dst.type);
        // primitive convert
        hako_convert_ros2pdu(src.autopilot, dst.autopilot);
        // primitive convert
        hako_convert_ros2pdu(src.base_mode, dst.base_mode);
        // primitive convert
        hako_convert_ros2pdu(src.custom_mode, dst.custom_mode);
        // primitive convert
        hako_convert_ros2pdu(src.system_status, dst.system_status);
        // primitive convert
        hako_convert_ros2pdu(src.mavlink_version, dst.mavlink_version);
    } catch (const std::runtime_error& e) {
        std::cerr << "convertor error: " << e.what() << std::endl;
        return false;
    }
    (void)dynamic_memory;
    return true;
}

static inline int hako_convert_ros2pdu_HakoHeartbeat(hako_mavlink_msgs::msg::HakoHeartbeat &src, Hako_HakoHeartbeat** dst)
{
    PduDynamicMemory dynamic_memory;
    Hako_HakoHeartbeat out;
    if (!_ros2pdu_HakoHeartbeat(src, out, dynamic_memory)) {
        return -1;
    }
    int heap_size = dynamic_memory.get_total_size();
    void* base_ptr = hako_create_empty_pdu(sizeof(Hako_HakoHeartbeat), heap_size);
    if (base_ptr == nullptr) {
        return -1;
    }
    // Copy out on base data
    memcpy(base_ptr, (void*)&out, sizeof(Hako_HakoHeartbeat));

    // Copy dynamic part and set offsets
    void* heap_ptr = hako_get_heap_ptr_pdu(base_ptr);
    dynamic_memory.copy_to_pdu((char*)heap_ptr);

    *dst = (Hako_HakoHeartbeat*)base_ptr;
    return hako_get_pdu_meta_data(base_ptr)->total_size;
}

static inline Hako_HakoHeartbeat* hako_create_empty_pdu_HakoHeartbeat(int heap_size)
{
    // Allocate PDU memory
    char* base_ptr = (char*)hako_create_empty_pdu(sizeof(Hako_HakoHeartbeat), heap_size);
    if (base_ptr == nullptr) {
        return nullptr;
    }
    return (Hako_HakoHeartbeat*)base_ptr;
}
#endif /* _PDU_CTYPE_CONV_HAKO_hako_mavlink_msgs_HakoHeartbeat_HPP_ */
