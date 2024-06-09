#ifndef _PDU_CTYPE_CONV_HAKO_ev3_msgs_Ev3PduActuator_HPP_
#define _PDU_CTYPE_CONV_HAKO_ev3_msgs_Ev3PduActuator_HPP_

#include "pdu_primitive_ctypes.h"
#include "ros_primitive_types.hpp"
#include "pdu_primitive_ctypes_conv.hpp"
#include "pdu_dynamic_memory.hpp"
/*
 * Dependent pdu data
 */
#include "ev3_msgs/pdu_ctype_Ev3PduActuator.h"
/*
 * Dependent ros data
 */
#include "ev3_msgs/msg/ev3_pdu_actuator.hpp"

/*
 * Dependent Convertors
 */
#include "ev3_msgs/pdu_ctype_conv_Ev3PduActuatorHeader.hpp"
#include "ev3_msgs/pdu_ctype_conv_Ev3PduMotor.hpp"

/***************************
 *
 * PDU ==> ROS2
 *
 ***************************/
static inline int _pdu2ros_primitive_array_Ev3PduActuator_leds(const char* varray_ptr, Hako_Ev3PduActuator &src, ev3_msgs::msg::Ev3PduActuator &dst)
{
    // Fixed size array convertor
    (void)varray_ptr;
    for (int i = 0; i < 1; ++i) {
        hako_convert_pdu2ros(src.leds[i], dst.leds[i]);
    }
    return 0;
}
static inline int _pdu2ros_struct_array_Ev3PduActuator_motors(const char* varray_ptr, Hako_Ev3PduActuator &src, ev3_msgs::msg::Ev3PduActuator &dst)
{
    // Fixed size array convertor
    for (int i = 0; i < 3; ++i) {
        _pdu2ros_Ev3PduMotor(varray_ptr, src.motors[i], dst.motors[i]);
    }
    return 0;
}

static inline int _pdu2ros_Ev3PduActuator(const char* varray_ptr, Hako_Ev3PduActuator &src, ev3_msgs::msg::Ev3PduActuator &dst)
{
    // Struct convert
    _pdu2ros_Ev3PduActuatorHeader(varray_ptr, src.head, dst.head);
    // primitive array convertor
    _pdu2ros_primitive_array_Ev3PduActuator_leds(varray_ptr, src, dst);
    // struct array convertor
    _pdu2ros_struct_array_Ev3PduActuator_motors(varray_ptr, src, dst);
    // primitive convert
    hako_convert_pdu2ros(src.gyro_reset, dst.gyro_reset);
    (void)varray_ptr;
    return 0;
}

static inline int hako_convert_pdu2ros_Ev3PduActuator(Hako_Ev3PduActuator &src, ev3_msgs::msg::Ev3PduActuator &dst)
{
    char* base_ptr = (char*)&src;
    HakoPduMetaDataType* meta = (HakoPduMetaDataType*)(base_ptr + sizeof(Hako_Ev3PduActuator));

    // Validate magic number and version
    if ((meta->magicno != HAKO_PDU_META_DATA_MAGICNO) || (meta->version != HAKO_PDU_META_DATA_VERSION)) {
        return -1; // Invalid PDU metadata
    }
    else {
        char *varray_ptr = base_ptr + sizeof(Hako_Ev3PduActuator) + sizeof(HakoPduMetaDataType);
        return _pdu2ros_Ev3PduActuator(varray_ptr, src, dst);
    }
}

/***************************
 *
 * ROS2 ==> PDU
 *
 ***************************/
static inline bool _ros2pdu_primitive_array_Ev3PduActuator_leds(ev3_msgs::msg::Ev3PduActuator &src, Hako_Ev3PduActuator &dst, PduDynamicMemory &dynamic_memory)
{
    //Copy fixed array 1
    (void)dynamic_memory;
    (void)hako_convert_ros2pdu_array(
        src.leds, src.leds.size(),
        dst.leds, M_ARRAY_SIZE(Hako_Ev3PduActuator, Hako_uint8, leds));
    return true;
}
static inline bool _ros2pdu_struct_array_Ev3PduActuator_motors(ev3_msgs::msg::Ev3PduActuator &src, Hako_Ev3PduActuator &dst, PduDynamicMemory &dynamic_memory)
{
    // array struct
    //array size is fixed
    for (int i = 0; i < 3; ++i) {
        _ros2pdu_Ev3PduMotor(src.motors[i], dst.motors[i], dynamic_memory);
    }
    return true;
}

static inline bool _ros2pdu_Ev3PduActuator(ev3_msgs::msg::Ev3PduActuator &src, Hako_Ev3PduActuator &dst, PduDynamicMemory &dynamic_memory)
{
    try {
        // struct convert
        _ros2pdu_Ev3PduActuatorHeader(src.head, dst.head, dynamic_memory);
        //primitive array copy
        _ros2pdu_primitive_array_Ev3PduActuator_leds(src, dst, dynamic_memory);
        //struct array convert
        _ros2pdu_struct_array_Ev3PduActuator_motors(src, dst, dynamic_memory);
        // primitive convert
        hako_convert_ros2pdu(src.gyro_reset, dst.gyro_reset);
    } catch (const std::runtime_error& e) {
        std::cerr << "convertor error: " << e.what() << std::endl;
        return false;
    }
    (void)dynamic_memory;
    return true;
}

static inline int hako_convert_ros2pdu_Ev3PduActuator(ev3_msgs::msg::Ev3PduActuator &src, Hako_Ev3PduActuator** dst)
{
    PduDynamicMemory dynamic_memory;
    Hako_Ev3PduActuator out;
    if (!_ros2pdu_Ev3PduActuator(src, out, dynamic_memory)) {
        return -1;
    }
    int total_size = sizeof(Hako_Ev3PduActuator) + sizeof(HakoPduMetaDataType) + dynamic_memory.get_total_size();

    // Allocate PDU memory
    char* base_ptr = (char*)malloc(total_size);
    if (base_ptr == nullptr) {
        return -1;
    }
    // Copy out on top
    memcpy(base_ptr, (void*)&out, sizeof(Hako_Ev3PduActuator));

    // Set metadata at the end
    HakoPduMetaDataType* meta = (HakoPduMetaDataType*)(base_ptr + sizeof(Hako_Ev3PduActuator));
    meta->magicno = HAKO_PDU_META_DATA_MAGICNO;
    meta->version = HAKO_PDU_META_DATA_VERSION;
    meta->top_off = 0;
    meta->total_size = total_size;
    meta->varray_off = sizeof(Hako_Ev3PduActuator) + sizeof(HakoPduMetaDataType);

    // Copy dynamic part and set offsets
    dynamic_memory.copy_to_pdu(base_ptr + meta->varray_off);

    *dst = (Hako_Ev3PduActuator*)base_ptr;
    return total_size;
}
static inline Hako_Ev3PduActuator* hako_create_empty_pdu_Ev3PduActuator(int heap_size)
{
    int total_size = sizeof(Hako_Ev3PduActuator) + sizeof(HakoPduMetaDataType) + heap_size;

    // Allocate PDU memory
    char* base_ptr = (char*)malloc(total_size);
    if (base_ptr == nullptr) {
        return nullptr;
    }
    memset(base_ptr, 0, total_size);
    // Set metadata at the end
    HakoPduMetaDataType* meta = (HakoPduMetaDataType*)(base_ptr + sizeof(Hako_Ev3PduActuator));
    meta->magicno = HAKO_PDU_META_DATA_MAGICNO;
    meta->version = HAKO_PDU_META_DATA_VERSION;
    meta->top_off = 0;
    meta->total_size = total_size;
    meta->varray_off = sizeof(Hako_Ev3PduActuator) + sizeof(HakoPduMetaDataType);
    return (Hako_Ev3PduActuator*)base_ptr;
}
#endif /* _PDU_CTYPE_CONV_HAKO_ev3_msgs_Ev3PduActuator_HPP_ */
