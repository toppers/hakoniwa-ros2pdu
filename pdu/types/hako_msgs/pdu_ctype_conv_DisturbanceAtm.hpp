#ifndef _PDU_CTYPE_CONV_HAKO_hako_msgs_DisturbanceAtm_HPP_
#define _PDU_CTYPE_CONV_HAKO_hako_msgs_DisturbanceAtm_HPP_

#include "pdu_primitive_ctypes.h"
#include "ros_primitive_types.hpp"
#include "pdu_primitive_ctypes_conv.hpp"
#include "pdu_dynamic_memory.hpp"
/*
 * Dependent pdu data
 */
#include "hako_msgs/pdu_ctype_DisturbanceAtm.h"
/*
 * Dependent ros data
 */
#include "hako_msgs/msg/disturbance_atm.hpp"

/*
 * Dependent Convertors
 */

/***************************
 *
 * PDU ==> ROS2
 *
 ***************************/

static inline int _pdu2ros_DisturbanceAtm(const char* heap_ptr, Hako_DisturbanceAtm &src, hako_msgs::msg::DisturbanceAtm &dst)
{
    // primitive convert
    hako_convert_pdu2ros(src.sea_level_atm, dst.sea_level_atm);
    (void)heap_ptr;
    return 0;
}

static inline int hako_convert_pdu2ros_DisturbanceAtm(Hako_DisturbanceAtm &src, hako_msgs::msg::DisturbanceAtm &dst)
{
    void* base_ptr = (void*)&src;
    void* heap_ptr = hako_get_heap_ptr_pdu(base_ptr);
    // Validate magic number and version
    if (heap_ptr == nullptr) {
        return -1; // Invalid PDU metadata
    }
    else {
        return _pdu2ros_DisturbanceAtm((char*)heap_ptr, src, dst);
    }
}

/***************************
 *
 * ROS2 ==> PDU
 *
 ***************************/

static inline bool _ros2pdu_DisturbanceAtm(hako_msgs::msg::DisturbanceAtm &src, Hako_DisturbanceAtm &dst, PduDynamicMemory &dynamic_memory)
{
    try {
        // primitive convert
        hako_convert_ros2pdu(src.sea_level_atm, dst.sea_level_atm);
    } catch (const std::runtime_error& e) {
        std::cerr << "convertor error: " << e.what() << std::endl;
        return false;
    }
    (void)dynamic_memory;
    return true;
}

static inline int hako_convert_ros2pdu_DisturbanceAtm(hako_msgs::msg::DisturbanceAtm &src, Hako_DisturbanceAtm** dst)
{
    PduDynamicMemory dynamic_memory;
    Hako_DisturbanceAtm out;
    if (!_ros2pdu_DisturbanceAtm(src, out, dynamic_memory)) {
        return -1;
    }
    int heap_size = dynamic_memory.get_total_size();
    void* base_ptr = hako_create_empty_pdu(sizeof(Hako_DisturbanceAtm), heap_size);
    if (base_ptr == nullptr) {
        return -1;
    }
    // Copy out on base data
    memcpy(base_ptr, (void*)&out, sizeof(Hako_DisturbanceAtm));

    // Copy dynamic part and set offsets
    void* heap_ptr = hako_get_heap_ptr_pdu(base_ptr);
    dynamic_memory.copy_to_pdu((char*)heap_ptr);

    *dst = (Hako_DisturbanceAtm*)base_ptr;
    return hako_get_pdu_meta_data(base_ptr)->total_size;
}

static inline Hako_DisturbanceAtm* hako_create_empty_pdu_DisturbanceAtm(int heap_size)
{
    // Allocate PDU memory
    char* base_ptr = (char*)hako_create_empty_pdu(sizeof(Hako_DisturbanceAtm), heap_size);
    if (base_ptr == nullptr) {
        return nullptr;
    }
    return (Hako_DisturbanceAtm*)base_ptr;
}
#endif /* _PDU_CTYPE_CONV_HAKO_hako_msgs_DisturbanceAtm_HPP_ */
