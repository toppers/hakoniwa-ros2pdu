#ifndef _PDU_CTYPE_CONV_HAKO_hako_msgs_DroneStatus_HPP_
#define _PDU_CTYPE_CONV_HAKO_hako_msgs_DroneStatus_HPP_

#include "pdu_primitive_ctypes.h"
#include "ros_primitive_types.hpp"
#include "pdu_primitive_ctypes_conv.hpp"
#include "pdu_dynamic_memory.hpp"
/*
 * Dependent pdu data
 */
#include "hako_msgs/pdu_ctype_DroneStatus.h"
/*
 * Dependent ros data
 */
#include "hako_msgs/msg/drone_status.hpp"

/*
 * Dependent Convertors
 */
#include "geometry_msgs/pdu_ctype_conv_Vector3.hpp"

/***************************
 *
 * PDU ==> ROS2
 *
 ***************************/

static inline int _pdu2ros_DroneStatus(const char* heap_ptr, Hako_DroneStatus &src, hako_msgs::msg::DroneStatus &dst)
{
    // primitive convert
    hako_convert_pdu2ros(src.flight_mode, dst.flight_mode);
    // primitive convert
    hako_convert_pdu2ros(src.internal_state, dst.internal_state);
    // Struct convert
    _pdu2ros_Vector3(heap_ptr, src.propeller_wind, dst.propeller_wind);
    // primitive convert
    hako_convert_pdu2ros(src.collided_counts, dst.collided_counts);
    (void)heap_ptr;
    return 0;
}

static inline int hako_convert_pdu2ros_DroneStatus(Hako_DroneStatus &src, hako_msgs::msg::DroneStatus &dst)
{
    void* base_ptr = (void*)&src;
    void* heap_ptr = hako_get_heap_ptr_pdu(base_ptr);
    // Validate magic number and version
    if (heap_ptr == nullptr) {
        return -1; // Invalid PDU metadata
    }
    else {
        return _pdu2ros_DroneStatus((char*)heap_ptr, src, dst);
    }
}

/***************************
 *
 * ROS2 ==> PDU
 *
 ***************************/

static inline bool _ros2pdu_DroneStatus(hako_msgs::msg::DroneStatus &src, Hako_DroneStatus &dst, PduDynamicMemory &dynamic_memory)
{
    try {
        // primitive convert
        hako_convert_ros2pdu(src.flight_mode, dst.flight_mode);
        // primitive convert
        hako_convert_ros2pdu(src.internal_state, dst.internal_state);
        // struct convert
        _ros2pdu_Vector3(src.propeller_wind, dst.propeller_wind, dynamic_memory);
        // primitive convert
        hako_convert_ros2pdu(src.collided_counts, dst.collided_counts);
    } catch (const std::runtime_error& e) {
        std::cerr << "convertor error: " << e.what() << std::endl;
        return false;
    }
    (void)dynamic_memory;
    return true;
}

static inline int hako_convert_ros2pdu_DroneStatus(hako_msgs::msg::DroneStatus &src, Hako_DroneStatus** dst)
{
    PduDynamicMemory dynamic_memory;
    Hako_DroneStatus out;
    if (!_ros2pdu_DroneStatus(src, out, dynamic_memory)) {
        return -1;
    }
    int heap_size = dynamic_memory.get_total_size();
    void* base_ptr = hako_create_empty_pdu(sizeof(Hako_DroneStatus), heap_size);
    if (base_ptr == nullptr) {
        return -1;
    }
    // Copy out on base data
    memcpy(base_ptr, (void*)&out, sizeof(Hako_DroneStatus));

    // Copy dynamic part and set offsets
    void* heap_ptr = hako_get_heap_ptr_pdu(base_ptr);
    dynamic_memory.copy_to_pdu((char*)heap_ptr);

    *dst = (Hako_DroneStatus*)base_ptr;
    return hako_get_pdu_meta_data(base_ptr)->total_size;
}

static inline Hako_DroneStatus* hako_create_empty_pdu_DroneStatus(int heap_size)
{
    // Allocate PDU memory
    char* base_ptr = (char*)hako_create_empty_pdu(sizeof(Hako_DroneStatus), heap_size);
    if (base_ptr == nullptr) {
        return nullptr;
    }
    return (Hako_DroneStatus*)base_ptr;
}
#endif /* _PDU_CTYPE_CONV_HAKO_hako_msgs_DroneStatus_HPP_ */
