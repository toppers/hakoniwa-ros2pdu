#ifndef _PDU_CTYPE_CONV_HAKO_hako_mavlink_msgs_HakoSERVO_OUTPUT_RAW_HPP_
#define _PDU_CTYPE_CONV_HAKO_hako_mavlink_msgs_HakoSERVO_OUTPUT_RAW_HPP_

#include "pdu_primitive_ctypes.h"
#include "ros_primitive_types.hpp"
#include "pdu_primitive_ctypes_conv.hpp"
#include "pdu_dynamic_memory.hpp"
/*
 * Dependent pdu data
 */
#include "hako_mavlink_msgs/pdu_ctype_HakoSERVO_OUTPUT_RAW.h"
/*
 * Dependent ros data
 */
#include "hako_mavlink_msgs/msg/hako_s_e_r_v_o__o_u_t_p_u_t__r_a_w.hpp"

/*
 * Dependent Convertors
 */

/***************************
 *
 * PDU ==> ROS2
 *
 ***************************/

static inline int _pdu2ros_HakoSERVO_OUTPUT_RAW(const char* heap_ptr, Hako_HakoSERVO_OUTPUT_RAW &src, hako_mavlink_msgs::msg::HakoSERVO_OUTPUT_RAW &dst)
{
    // primitive convert
    hako_convert_pdu2ros(src.time_usec, dst.time_usec);
    // primitive convert
    hako_convert_pdu2ros(src.port, dst.port);
    // primitive convert
    hako_convert_pdu2ros(src.servo1_raw, dst.servo1_raw);
    // primitive convert
    hako_convert_pdu2ros(src.servo2_raw, dst.servo2_raw);
    // primitive convert
    hako_convert_pdu2ros(src.servo3_raw, dst.servo3_raw);
    // primitive convert
    hako_convert_pdu2ros(src.servo4_raw, dst.servo4_raw);
    // primitive convert
    hako_convert_pdu2ros(src.servo5_raw, dst.servo5_raw);
    // primitive convert
    hako_convert_pdu2ros(src.servo6_raw, dst.servo6_raw);
    // primitive convert
    hako_convert_pdu2ros(src.servo7_raw, dst.servo7_raw);
    // primitive convert
    hako_convert_pdu2ros(src.servo8_raw, dst.servo8_raw);
    (void)heap_ptr;
    return 0;
}

static inline int hako_convert_pdu2ros_HakoSERVO_OUTPUT_RAW(Hako_HakoSERVO_OUTPUT_RAW &src, hako_mavlink_msgs::msg::HakoSERVO_OUTPUT_RAW &dst)
{
    void* base_ptr = (void*)&src;
    void* heap_ptr = hako_get_heap_ptr_pdu(base_ptr);
    // Validate magic number and version
    if (heap_ptr == nullptr) {
        return -1; // Invalid PDU metadata
    }
    else {
        return _pdu2ros_HakoSERVO_OUTPUT_RAW((char*)heap_ptr, src, dst);
    }
}

/***************************
 *
 * ROS2 ==> PDU
 *
 ***************************/

static inline bool _ros2pdu_HakoSERVO_OUTPUT_RAW(hako_mavlink_msgs::msg::HakoSERVO_OUTPUT_RAW &src, Hako_HakoSERVO_OUTPUT_RAW &dst, PduDynamicMemory &dynamic_memory)
{
    try {
        // primitive convert
        hako_convert_ros2pdu(src.time_usec, dst.time_usec);
        // primitive convert
        hako_convert_ros2pdu(src.port, dst.port);
        // primitive convert
        hako_convert_ros2pdu(src.servo1_raw, dst.servo1_raw);
        // primitive convert
        hako_convert_ros2pdu(src.servo2_raw, dst.servo2_raw);
        // primitive convert
        hako_convert_ros2pdu(src.servo3_raw, dst.servo3_raw);
        // primitive convert
        hako_convert_ros2pdu(src.servo4_raw, dst.servo4_raw);
        // primitive convert
        hako_convert_ros2pdu(src.servo5_raw, dst.servo5_raw);
        // primitive convert
        hako_convert_ros2pdu(src.servo6_raw, dst.servo6_raw);
        // primitive convert
        hako_convert_ros2pdu(src.servo7_raw, dst.servo7_raw);
        // primitive convert
        hako_convert_ros2pdu(src.servo8_raw, dst.servo8_raw);
    } catch (const std::runtime_error& e) {
        std::cerr << "convertor error: " << e.what() << std::endl;
        return false;
    }
    (void)dynamic_memory;
    return true;
}

static inline int hako_convert_ros2pdu_HakoSERVO_OUTPUT_RAW(hako_mavlink_msgs::msg::HakoSERVO_OUTPUT_RAW &src, Hako_HakoSERVO_OUTPUT_RAW** dst)
{
    PduDynamicMemory dynamic_memory;
    Hako_HakoSERVO_OUTPUT_RAW out;
    if (!_ros2pdu_HakoSERVO_OUTPUT_RAW(src, out, dynamic_memory)) {
        return -1;
    }
    int heap_size = dynamic_memory.get_total_size();
    void* base_ptr = hako_create_empty_pdu(sizeof(Hako_HakoSERVO_OUTPUT_RAW), heap_size);
    if (base_ptr == nullptr) {
        return -1;
    }
    // Copy out on base data
    memcpy(base_ptr, (void*)&out, sizeof(Hako_HakoSERVO_OUTPUT_RAW));

    // Copy dynamic part and set offsets
    void* heap_ptr = hako_get_heap_ptr_pdu(base_ptr);
    dynamic_memory.copy_to_pdu((char*)heap_ptr);

    *dst = (Hako_HakoSERVO_OUTPUT_RAW*)base_ptr;
    return hako_get_pdu_meta_data(base_ptr)->total_size;
}

static inline Hako_HakoSERVO_OUTPUT_RAW* hako_create_empty_pdu_HakoSERVO_OUTPUT_RAW(int heap_size)
{
    // Allocate PDU memory
    char* base_ptr = (char*)hako_create_empty_pdu(sizeof(Hako_HakoSERVO_OUTPUT_RAW), heap_size);
    if (base_ptr == nullptr) {
        return nullptr;
    }
    return (Hako_HakoSERVO_OUTPUT_RAW*)base_ptr;
}
#endif /* _PDU_CTYPE_CONV_HAKO_hako_mavlink_msgs_HakoSERVO_OUTPUT_RAW_HPP_ */
