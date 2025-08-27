#ifndef _PDU_CTYPE_CONV_HAKO_drone_srv_msgs_DroneGetStateResponse_HPP_
#define _PDU_CTYPE_CONV_HAKO_drone_srv_msgs_DroneGetStateResponse_HPP_

#include "pdu_primitive_ctypes.h"
#include "ros_primitive_types.hpp"
#include "pdu_primitive_ctypes_conv.hpp"
#include "pdu_dynamic_memory.hpp"
/*
 * Dependent pdu data
 */
#include "drone_srv_msgs/pdu_ctype_DroneGetStateResponse.h"
/*
 * Dependent ros data
 */
#include "drone_srv_msgs/msg/drone_get_state_response.hpp"

/*
 * Dependent Convertors
 */
#include "geometry_msgs/pdu_ctype_conv_Point.hpp"
#include "geometry_msgs/pdu_ctype_conv_Pose.hpp"
#include "geometry_msgs/pdu_ctype_conv_Quaternion.hpp"
#include "hako_msgs/pdu_ctype_conv_HakoBatteryStatus.hpp"

/***************************
 *
 * PDU ==> ROS2
 *
 ***************************/

static inline int _pdu2ros_DroneGetStateResponse(const char* heap_ptr, Hako_DroneGetStateResponse &src, drone_srv_msgs::msg::DroneGetStateResponse &dst)
{
    // primitive convert
    hako_convert_pdu2ros(src.ok, dst.ok);
    // primitive convert
    hako_convert_pdu2ros(src.is_ready, dst.is_ready);
    // Struct convert
    _pdu2ros_Pose(heap_ptr, src.current_pose, dst.current_pose);
    // Struct convert
    _pdu2ros_HakoBatteryStatus(heap_ptr, src.battery_status, dst.battery_status);
    // string convertor
    dst.mode = (const char*)src.mode;
    // string convertor
    dst.message = (const char*)src.message;
    (void)heap_ptr;
    return 0;
}

static inline int hako_convert_pdu2ros_DroneGetStateResponse(Hako_DroneGetStateResponse &src, drone_srv_msgs::msg::DroneGetStateResponse &dst)
{
    void* base_ptr = (void*)&src;
    void* heap_ptr = hako_get_heap_ptr_pdu(base_ptr);
    // Validate magic number and version
    if (heap_ptr == nullptr) {
        return -1; // Invalid PDU metadata
    }
    else {
        return _pdu2ros_DroneGetStateResponse((char*)heap_ptr, src, dst);
    }
}

/***************************
 *
 * ROS2 ==> PDU
 *
 ***************************/

static inline bool _ros2pdu_DroneGetStateResponse(drone_srv_msgs::msg::DroneGetStateResponse &src, Hako_DroneGetStateResponse &dst, PduDynamicMemory &dynamic_memory)
{
    try {
        // primitive convert
        hako_convert_ros2pdu(src.ok, dst.ok);
        // primitive convert
        hako_convert_ros2pdu(src.is_ready, dst.is_ready);
        // struct convert
        _ros2pdu_Pose(src.current_pose, dst.current_pose, dynamic_memory);
        // struct convert
        _ros2pdu_HakoBatteryStatus(src.battery_status, dst.battery_status, dynamic_memory);
        // string convertor
        (void)hako_convert_ros2pdu_array(
            src.mode, src.mode.length(),
            dst.mode, M_ARRAY_SIZE(Hako_DroneGetStateResponse, char, mode));
        dst.mode[src.mode.length()] = '\0';
        // string convertor
        (void)hako_convert_ros2pdu_array(
            src.message, src.message.length(),
            dst.message, M_ARRAY_SIZE(Hako_DroneGetStateResponse, char, message));
        dst.message[src.message.length()] = '\0';
    } catch (const std::runtime_error& e) {
        std::cerr << "convertor error: " << e.what() << std::endl;
        return false;
    }
    (void)dynamic_memory;
    return true;
}

static inline int hako_convert_ros2pdu_DroneGetStateResponse(drone_srv_msgs::msg::DroneGetStateResponse &src, Hako_DroneGetStateResponse** dst)
{
    PduDynamicMemory dynamic_memory;
    Hako_DroneGetStateResponse out;
    if (!_ros2pdu_DroneGetStateResponse(src, out, dynamic_memory)) {
        return -1;
    }
    int heap_size = dynamic_memory.get_total_size();
    void* base_ptr = hako_create_empty_pdu(sizeof(Hako_DroneGetStateResponse), heap_size);
    if (base_ptr == nullptr) {
        return -1;
    }
    // Copy out on base data
    memcpy(base_ptr, (void*)&out, sizeof(Hako_DroneGetStateResponse));

    // Copy dynamic part and set offsets
    void* heap_ptr = hako_get_heap_ptr_pdu(base_ptr);
    dynamic_memory.copy_to_pdu((char*)heap_ptr);

    *dst = (Hako_DroneGetStateResponse*)base_ptr;
    return hako_get_pdu_meta_data(base_ptr)->total_size;
}

static inline Hako_DroneGetStateResponse* hako_create_empty_pdu_DroneGetStateResponse(int heap_size)
{
    // Allocate PDU memory
    char* base_ptr = (char*)hako_create_empty_pdu(sizeof(Hako_DroneGetStateResponse), heap_size);
    if (base_ptr == nullptr) {
        return nullptr;
    }
    return (Hako_DroneGetStateResponse*)base_ptr;
}
#endif /* _PDU_CTYPE_CONV_HAKO_drone_srv_msgs_DroneGetStateResponse_HPP_ */
