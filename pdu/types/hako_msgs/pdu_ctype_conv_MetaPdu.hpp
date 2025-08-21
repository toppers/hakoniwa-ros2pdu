#ifndef _PDU_CTYPE_CONV_HAKO_hako_msgs_MetaPdu_HPP_
#define _PDU_CTYPE_CONV_HAKO_hako_msgs_MetaPdu_HPP_

#include "pdu_primitive_ctypes.h"
#include "ros_primitive_types.hpp"
#include "pdu_primitive_ctypes_conv.hpp"
#include "pdu_dynamic_memory.hpp"
/*
 * Dependent pdu data
 */
#include "hako_msgs/pdu_ctype_MetaPdu.h"
/*
 * Dependent ros data
 */
#include "hako_msgs/msg/meta_pdu.hpp"

/*
 * Dependent Convertors
 */

/***************************
 *
 * PDU ==> ROS2
 *
 ***************************/

static inline int _pdu2ros_MetaPdu(const char* heap_ptr, Hako_MetaPdu &src, hako_msgs::msg::MetaPdu &dst)
{
    // primitive convert
    hako_convert_pdu2ros(src.total_len, dst.total_len);
    // primitive convert
    hako_convert_pdu2ros(src.magicno, dst.magicno);
    // primitive convert
    hako_convert_pdu2ros(src.version, dst.version);
    // primitive convert
    hako_convert_pdu2ros(src.flags, dst.flags);
    // primitive convert
    hako_convert_pdu2ros(src.meta_request_type, dst.meta_request_type);
    // primitive convert
    hako_convert_pdu2ros(src.hako_time_us, dst.hako_time_us);
    // primitive convert
    hako_convert_pdu2ros(src.asset_time_us, dst.asset_time_us);
    // primitive convert
    hako_convert_pdu2ros(src.real_time_us, dst.real_time_us);
    // string convertor
    dst.robot_name = (const char*)src.robot_name;
    // primitive convert
    hako_convert_pdu2ros(src.channel_id, dst.channel_id);
    // primitive convert
    hako_convert_pdu2ros(src.body_len, dst.body_len);
    (void)heap_ptr;
    return 0;
}

static inline int hako_convert_pdu2ros_MetaPdu(Hako_MetaPdu &src, hako_msgs::msg::MetaPdu &dst)
{
    void* base_ptr = (void*)&src;
    void* heap_ptr = hako_get_heap_ptr_pdu(base_ptr);
    // Validate magic number and version
    if (heap_ptr == nullptr) {
        return -1; // Invalid PDU metadata
    }
    else {
        return _pdu2ros_MetaPdu((char*)heap_ptr, src, dst);
    }
}

/***************************
 *
 * ROS2 ==> PDU
 *
 ***************************/

static inline bool _ros2pdu_MetaPdu(hako_msgs::msg::MetaPdu &src, Hako_MetaPdu &dst, PduDynamicMemory &dynamic_memory)
{
    try {
        // primitive convert
        hako_convert_ros2pdu(src.total_len, dst.total_len);
        // primitive convert
        hako_convert_ros2pdu(src.magicno, dst.magicno);
        // primitive convert
        hako_convert_ros2pdu(src.version, dst.version);
        // primitive convert
        hako_convert_ros2pdu(src.flags, dst.flags);
        // primitive convert
        hako_convert_ros2pdu(src.meta_request_type, dst.meta_request_type);
        // primitive convert
        hako_convert_ros2pdu(src.hako_time_us, dst.hako_time_us);
        // primitive convert
        hako_convert_ros2pdu(src.asset_time_us, dst.asset_time_us);
        // primitive convert
        hako_convert_ros2pdu(src.real_time_us, dst.real_time_us);
        // string convertor
        (void)hako_convert_ros2pdu_array(
            src.robot_name, src.robot_name.length(),
            dst.robot_name, M_ARRAY_SIZE(Hako_MetaPdu, char, robot_name));
        dst.robot_name[src.robot_name.length()] = '\0';
        // primitive convert
        hako_convert_ros2pdu(src.channel_id, dst.channel_id);
        // primitive convert
        hako_convert_ros2pdu(src.body_len, dst.body_len);
    } catch (const std::runtime_error& e) {
        std::cerr << "convertor error: " << e.what() << std::endl;
        return false;
    }
    (void)dynamic_memory;
    return true;
}

static inline int hako_convert_ros2pdu_MetaPdu(hako_msgs::msg::MetaPdu &src, Hako_MetaPdu** dst)
{
    PduDynamicMemory dynamic_memory;
    Hako_MetaPdu out;
    if (!_ros2pdu_MetaPdu(src, out, dynamic_memory)) {
        return -1;
    }
    int heap_size = dynamic_memory.get_total_size();
    void* base_ptr = hako_create_empty_pdu(sizeof(Hako_MetaPdu), heap_size);
    if (base_ptr == nullptr) {
        return -1;
    }
    // Copy out on base data
    memcpy(base_ptr, (void*)&out, sizeof(Hako_MetaPdu));

    // Copy dynamic part and set offsets
    void* heap_ptr = hako_get_heap_ptr_pdu(base_ptr);
    dynamic_memory.copy_to_pdu((char*)heap_ptr);

    *dst = (Hako_MetaPdu*)base_ptr;
    return hako_get_pdu_meta_data(base_ptr)->total_size;
}

static inline Hako_MetaPdu* hako_create_empty_pdu_MetaPdu(int heap_size)
{
    // Allocate PDU memory
    char* base_ptr = (char*)hako_create_empty_pdu(sizeof(Hako_MetaPdu), heap_size);
    if (base_ptr == nullptr) {
        return nullptr;
    }
    return (Hako_MetaPdu*)base_ptr;
}
#endif /* _PDU_CTYPE_CONV_HAKO_hako_msgs_MetaPdu_HPP_ */
