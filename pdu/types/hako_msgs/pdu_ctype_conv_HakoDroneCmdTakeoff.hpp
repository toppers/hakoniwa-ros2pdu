#ifndef _PDU_CTYPE_CONV_HAKO_hako_msgs_HakoDroneCmdTakeoff_HPP_
#define _PDU_CTYPE_CONV_HAKO_hako_msgs_HakoDroneCmdTakeoff_HPP_

#include "pdu_primitive_ctypes.h"
#include "ros_primitive_types.hpp"
#include "pdu_primitive_ctypes_conv.hpp"
#include "pdu_dynamic_memory.hpp"
/*
 * Dependent pdu data
 */
#include "hako_msgs/pdu_ctype_HakoDroneCmdTakeoff.h"
/*
 * Dependent ros data
 */
#include "hako_msgs/msg/hako_drone_cmd_takeoff.hpp"

/*
 * Dependent Convertors
 */
#include "hako_msgs/pdu_ctype_conv_HakoDroneCmdHeader.hpp"

/***************************
 *
 * PDU ==> ROS2
 *
 ***************************/

static inline int _pdu2ros_HakoDroneCmdTakeoff(const char* heap_ptr, Hako_HakoDroneCmdTakeoff &src, hako_msgs::msg::HakoDroneCmdTakeoff &dst)
{
    // Struct convert
    _pdu2ros_HakoDroneCmdHeader(heap_ptr, src.header, dst.header);
    // primitive convert
    hako_convert_pdu2ros(src.height, dst.height);
    // primitive convert
    hako_convert_pdu2ros(src.speed, dst.speed);
    // primitive convert
    hako_convert_pdu2ros(src.yaw_deg, dst.yaw_deg);
    (void)heap_ptr;
    return 0;
}

static inline int hako_convert_pdu2ros_HakoDroneCmdTakeoff(Hako_HakoDroneCmdTakeoff &src, hako_msgs::msg::HakoDroneCmdTakeoff &dst)
{
    void* base_ptr = (void*)&src;
    void* heap_ptr = hako_get_heap_ptr_pdu(base_ptr);
    // Validate magic number and version
    if (heap_ptr == nullptr) {
        return -1; // Invalid PDU metadata
    }
    else {
        return _pdu2ros_HakoDroneCmdTakeoff((char*)heap_ptr, src, dst);
    }
}

/***************************
 *
 * ROS2 ==> PDU
 *
 ***************************/

static inline bool _ros2pdu_HakoDroneCmdTakeoff(hako_msgs::msg::HakoDroneCmdTakeoff &src, Hako_HakoDroneCmdTakeoff &dst, PduDynamicMemory &dynamic_memory)
{
    try {
        // struct convert
        _ros2pdu_HakoDroneCmdHeader(src.header, dst.header, dynamic_memory);
        // primitive convert
        hako_convert_ros2pdu(src.height, dst.height);
        // primitive convert
        hako_convert_ros2pdu(src.speed, dst.speed);
        // primitive convert
        hako_convert_ros2pdu(src.yaw_deg, dst.yaw_deg);
    } catch (const std::runtime_error& e) {
        std::cerr << "convertor error: " << e.what() << std::endl;
        return false;
    }
    (void)dynamic_memory;
    return true;
}

static inline int hako_convert_ros2pdu_HakoDroneCmdTakeoff(hako_msgs::msg::HakoDroneCmdTakeoff &src, Hako_HakoDroneCmdTakeoff** dst)
{
    PduDynamicMemory dynamic_memory;
    Hako_HakoDroneCmdTakeoff out;
    if (!_ros2pdu_HakoDroneCmdTakeoff(src, out, dynamic_memory)) {
        return -1;
    }
    int heap_size = dynamic_memory.get_total_size();
    void* base_ptr = hako_create_empty_pdu(sizeof(Hako_HakoDroneCmdTakeoff), heap_size);
    if (base_ptr == nullptr) {
        return -1;
    }
    // Copy out on base data
    memcpy(base_ptr, (void*)&out, sizeof(Hako_HakoDroneCmdTakeoff));

    // Copy dynamic part and set offsets
    void* heap_ptr = hako_get_heap_ptr_pdu(base_ptr);
    dynamic_memory.copy_to_pdu((char*)heap_ptr);

    *dst = (Hako_HakoDroneCmdTakeoff*)base_ptr;
    return hako_get_pdu_meta_data(base_ptr)->total_size;
}

static inline Hako_HakoDroneCmdTakeoff* hako_create_empty_pdu_HakoDroneCmdTakeoff(int heap_size)
{
    // Allocate PDU memory
    char* base_ptr = (char*)hako_create_empty_pdu(sizeof(Hako_HakoDroneCmdTakeoff), heap_size);
    if (base_ptr == nullptr) {
        return nullptr;
    }
    return (Hako_HakoDroneCmdTakeoff*)base_ptr;
}
#endif /* _PDU_CTYPE_CONV_HAKO_hako_msgs_HakoDroneCmdTakeoff_HPP_ */
