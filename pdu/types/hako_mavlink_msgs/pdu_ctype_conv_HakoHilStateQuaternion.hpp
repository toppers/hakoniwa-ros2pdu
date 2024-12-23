#ifndef _PDU_CTYPE_CONV_HAKO_hako_mavlink_msgs_HakoHilStateQuaternion_HPP_
#define _PDU_CTYPE_CONV_HAKO_hako_mavlink_msgs_HakoHilStateQuaternion_HPP_

#include "pdu_primitive_ctypes.h"
#include "ros_primitive_types.hpp"
#include "pdu_primitive_ctypes_conv.hpp"
#include "pdu_dynamic_memory.hpp"
/*
 * Dependent pdu data
 */
#include "hako_mavlink_msgs/pdu_ctype_HakoHilStateQuaternion.h"
/*
 * Dependent ros data
 */
#include "hako_mavlink_msgs/msg/hako_hil_state_quaternion.hpp"

/*
 * Dependent Convertors
 */

/***************************
 *
 * PDU ==> ROS2
 *
 ***************************/
static inline int _pdu2ros_primitive_array_HakoHilStateQuaternion_attitude_quaternion(const char* heap_ptr, Hako_HakoHilStateQuaternion &src, hako_mavlink_msgs::msg::HakoHilStateQuaternion &dst)
{
    // Fixed size array convertor
    (void)heap_ptr;
    for (int i = 0; i < 4; ++i) {
        hako_convert_pdu2ros(src.attitude_quaternion[i], dst.attitude_quaternion[i]);
    }
    return 0;
}

static inline int _pdu2ros_HakoHilStateQuaternion(const char* heap_ptr, Hako_HakoHilStateQuaternion &src, hako_mavlink_msgs::msg::HakoHilStateQuaternion &dst)
{
    // primitive convert
    hako_convert_pdu2ros(src.time_usec, dst.time_usec);
    // primitive array convertor
    _pdu2ros_primitive_array_HakoHilStateQuaternion_attitude_quaternion(heap_ptr, src, dst);
    // primitive convert
    hako_convert_pdu2ros(src.rollspeed, dst.rollspeed);
    // primitive convert
    hako_convert_pdu2ros(src.pitchspeed, dst.pitchspeed);
    // primitive convert
    hako_convert_pdu2ros(src.yawspeed, dst.yawspeed);
    // primitive convert
    hako_convert_pdu2ros(src.lat, dst.lat);
    // primitive convert
    hako_convert_pdu2ros(src.lon, dst.lon);
    // primitive convert
    hako_convert_pdu2ros(src.alt, dst.alt);
    // primitive convert
    hako_convert_pdu2ros(src.vx, dst.vx);
    // primitive convert
    hako_convert_pdu2ros(src.vy, dst.vy);
    // primitive convert
    hako_convert_pdu2ros(src.vz, dst.vz);
    // primitive convert
    hako_convert_pdu2ros(src.ind_airspeed, dst.ind_airspeed);
    // primitive convert
    hako_convert_pdu2ros(src.true_airspeed, dst.true_airspeed);
    // primitive convert
    hako_convert_pdu2ros(src.xacc, dst.xacc);
    // primitive convert
    hako_convert_pdu2ros(src.yacc, dst.yacc);
    // primitive convert
    hako_convert_pdu2ros(src.zacc, dst.zacc);
    (void)heap_ptr;
    return 0;
}

static inline int hako_convert_pdu2ros_HakoHilStateQuaternion(Hako_HakoHilStateQuaternion &src, hako_mavlink_msgs::msg::HakoHilStateQuaternion &dst)
{
    void* base_ptr = (void*)&src;
    void* heap_ptr = hako_get_heap_ptr_pdu(base_ptr);
    // Validate magic number and version
    if (heap_ptr == nullptr) {
        return -1; // Invalid PDU metadata
    }
    else {
        return _pdu2ros_HakoHilStateQuaternion((char*)heap_ptr, src, dst);
    }
}

/***************************
 *
 * ROS2 ==> PDU
 *
 ***************************/
static inline bool _ros2pdu_primitive_array_HakoHilStateQuaternion_attitude_quaternion(hako_mavlink_msgs::msg::HakoHilStateQuaternion &src, Hako_HakoHilStateQuaternion &dst, PduDynamicMemory &dynamic_memory)
{
    //Copy fixed array 4
    (void)dynamic_memory;
    (void)hako_convert_ros2pdu_array(
        src.attitude_quaternion, src.attitude_quaternion.size(),
        dst.attitude_quaternion, M_ARRAY_SIZE(Hako_HakoHilStateQuaternion, Hako_float32, attitude_quaternion));
    return true;
}

static inline bool _ros2pdu_HakoHilStateQuaternion(hako_mavlink_msgs::msg::HakoHilStateQuaternion &src, Hako_HakoHilStateQuaternion &dst, PduDynamicMemory &dynamic_memory)
{
    try {
        // primitive convert
        hako_convert_ros2pdu(src.time_usec, dst.time_usec);
        //primitive array copy
        _ros2pdu_primitive_array_HakoHilStateQuaternion_attitude_quaternion(src, dst, dynamic_memory);
        // primitive convert
        hako_convert_ros2pdu(src.rollspeed, dst.rollspeed);
        // primitive convert
        hako_convert_ros2pdu(src.pitchspeed, dst.pitchspeed);
        // primitive convert
        hako_convert_ros2pdu(src.yawspeed, dst.yawspeed);
        // primitive convert
        hako_convert_ros2pdu(src.lat, dst.lat);
        // primitive convert
        hako_convert_ros2pdu(src.lon, dst.lon);
        // primitive convert
        hako_convert_ros2pdu(src.alt, dst.alt);
        // primitive convert
        hako_convert_ros2pdu(src.vx, dst.vx);
        // primitive convert
        hako_convert_ros2pdu(src.vy, dst.vy);
        // primitive convert
        hako_convert_ros2pdu(src.vz, dst.vz);
        // primitive convert
        hako_convert_ros2pdu(src.ind_airspeed, dst.ind_airspeed);
        // primitive convert
        hako_convert_ros2pdu(src.true_airspeed, dst.true_airspeed);
        // primitive convert
        hako_convert_ros2pdu(src.xacc, dst.xacc);
        // primitive convert
        hako_convert_ros2pdu(src.yacc, dst.yacc);
        // primitive convert
        hako_convert_ros2pdu(src.zacc, dst.zacc);
    } catch (const std::runtime_error& e) {
        std::cerr << "convertor error: " << e.what() << std::endl;
        return false;
    }
    (void)dynamic_memory;
    return true;
}

static inline int hako_convert_ros2pdu_HakoHilStateQuaternion(hako_mavlink_msgs::msg::HakoHilStateQuaternion &src, Hako_HakoHilStateQuaternion** dst)
{
    PduDynamicMemory dynamic_memory;
    Hako_HakoHilStateQuaternion out;
    if (!_ros2pdu_HakoHilStateQuaternion(src, out, dynamic_memory)) {
        return -1;
    }
    int heap_size = dynamic_memory.get_total_size();
    void* base_ptr = hako_create_empty_pdu(sizeof(Hako_HakoHilStateQuaternion), heap_size);
    if (base_ptr == nullptr) {
        return -1;
    }
    // Copy out on base data
    memcpy(base_ptr, (void*)&out, sizeof(Hako_HakoHilStateQuaternion));

    // Copy dynamic part and set offsets
    void* heap_ptr = hako_get_heap_ptr_pdu(base_ptr);
    dynamic_memory.copy_to_pdu((char*)heap_ptr);

    *dst = (Hako_HakoHilStateQuaternion*)base_ptr;
    return hako_get_pdu_meta_data(base_ptr)->total_size;
}

static inline Hako_HakoHilStateQuaternion* hako_create_empty_pdu_HakoHilStateQuaternion(int heap_size)
{
    // Allocate PDU memory
    char* base_ptr = (char*)hako_create_empty_pdu(sizeof(Hako_HakoHilStateQuaternion), heap_size);
    if (base_ptr == nullptr) {
        return nullptr;
    }
    return (Hako_HakoHilStateQuaternion*)base_ptr;
}
#endif /* _PDU_CTYPE_CONV_HAKO_hako_mavlink_msgs_HakoHilStateQuaternion_HPP_ */
