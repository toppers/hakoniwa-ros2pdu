#ifndef _PDU_CTYPE_CONV_HAKO_ev3_msgs_Ev3PduSensor_HPP_
#define _PDU_CTYPE_CONV_HAKO_ev3_msgs_Ev3PduSensor_HPP_

#include "pdu_primitive_ctypes.h"
#include "ros_primitive_types.hpp"
#include "pdu_primitive_ctypes_conv.hpp"
#include "pdu_dynamic_memory.hpp"
/*
 * Dependent pdu data
 */
#include "ev3_msgs/pdu_ctype_Ev3PduSensor.h"
/*
 * Dependent ros data
 */
#include "ev3_msgs/msg/ev3_pdu_sensor.hpp"

/*
 * Dependent Convertors
 */
#include "ev3_msgs/pdu_ctype_conv_Ev3PduColorSensor.hpp"
#include "ev3_msgs/pdu_ctype_conv_Ev3PduSensorHeader.hpp"
#include "ev3_msgs/pdu_ctype_conv_Ev3PduTouchSensor.hpp"

/***************************
 *
 * PDU ==> ROS2
 *
 ***************************/
static inline int _pdu2ros_primitive_array_Ev3PduSensor_buttons(const char* varray_ptr, Hako_Ev3PduSensor &src, ev3_msgs::msg::Ev3PduSensor &dst)
{
    // Fixed size array convertor
    (void)varray_ptr;
    for (int i = 0; i < 1; ++i) {
        hako_convert_pdu2ros(src.buttons[i], dst.buttons[i]);
    }
    return 0;
}
static inline int _pdu2ros_struct_array_Ev3PduSensor_color_sensors(const char* varray_ptr, Hako_Ev3PduSensor &src, ev3_msgs::msg::Ev3PduSensor &dst)
{
    // Fixed size array convertor
    for (int i = 0; i < 2; ++i) {
        _pdu2ros_Ev3PduColorSensor(varray_ptr, src.color_sensors[i], dst.color_sensors[i]);
    }
    return 0;
}
static inline int _pdu2ros_struct_array_Ev3PduSensor_touch_sensors(const char* varray_ptr, Hako_Ev3PduSensor &src, ev3_msgs::msg::Ev3PduSensor &dst)
{
    // Fixed size array convertor
    for (int i = 0; i < 2; ++i) {
        _pdu2ros_Ev3PduTouchSensor(varray_ptr, src.touch_sensors[i], dst.touch_sensors[i]);
    }
    return 0;
}
static inline int _pdu2ros_primitive_array_Ev3PduSensor_motor_angle(const char* varray_ptr, Hako_Ev3PduSensor &src, ev3_msgs::msg::Ev3PduSensor &dst)
{
    // Fixed size array convertor
    (void)varray_ptr;
    for (int i = 0; i < 3; ++i) {
        hako_convert_pdu2ros(src.motor_angle[i], dst.motor_angle[i]);
    }
    return 0;
}

static inline int _pdu2ros_Ev3PduSensor(const char* varray_ptr, Hako_Ev3PduSensor &src, ev3_msgs::msg::Ev3PduSensor &dst)
{
    // Struct convert
    _pdu2ros_Ev3PduSensorHeader(varray_ptr, src.head, dst.head);
    // primitive array convertor
    _pdu2ros_primitive_array_Ev3PduSensor_buttons(varray_ptr, src, dst);
    // struct array convertor
    _pdu2ros_struct_array_Ev3PduSensor_color_sensors(varray_ptr, src, dst);
    // struct array convertor
    _pdu2ros_struct_array_Ev3PduSensor_touch_sensors(varray_ptr, src, dst);
    // primitive array convertor
    _pdu2ros_primitive_array_Ev3PduSensor_motor_angle(varray_ptr, src, dst);
    // primitive convert
    hako_convert_pdu2ros(src.gyro_degree, dst.gyro_degree);
    // primitive convert
    hako_convert_pdu2ros(src.gyro_degree_rate, dst.gyro_degree_rate);
    // primitive convert
    hako_convert_pdu2ros(src.sensor_ultrasonic, dst.sensor_ultrasonic);
    // primitive convert
    hako_convert_pdu2ros(src.gps_lat, dst.gps_lat);
    // primitive convert
    hako_convert_pdu2ros(src.gps_lon, dst.gps_lon);
    return 0;
}

static inline int hako_convert_pdu2ros_Ev3PduSensor(Hako_Ev3PduSensor &src, ev3_msgs::msg::Ev3PduSensor &dst)
{
    char* base_ptr = (char*)&src;
    HakoPduMetaDataType* meta = (HakoPduMetaDataType*)(base_ptr + sizeof(Hako_Ev3PduSensor));

    // Validate magic number and version
    if ((meta->magicno != HAKO_PDU_META_DATA_MAGICNO) || (meta->version != HAKO_PDU_META_DATA_VERSION)) {
        return -1; // Invalid PDU metadata
    }
    else {
        char *varray_ptr = base_ptr + sizeof(Hako_Ev3PduSensor) + sizeof(HakoPduMetaDataType);
        return _pdu2ros_Ev3PduSensor(varray_ptr, src, dst);
    }
}

/***************************
 *
 * ROS2 ==> PDU
 *
 ***************************/
static inline bool _ros2pdu_primitive_array_Ev3PduSensor_buttons(ev3_msgs::msg::Ev3PduSensor &src, Hako_Ev3PduSensor &dst, PduDynamicMemory &dynamic_memory)
{
    //Copy fixed array 1
    (void)dynamic_memory;
    (void)hako_convert_ros2pdu_array(
        src.buttons, src.buttons.size(),
        dst.buttons, M_ARRAY_SIZE(Hako_Ev3PduSensor, Hako_uint8, buttons));
    return true;
}
static inline bool _ros2pdu_struct_array_Ev3PduSensor_color_sensors(ev3_msgs::msg::Ev3PduSensor &src, Hako_Ev3PduSensor &dst, PduDynamicMemory &dynamic_memory)
{
    // array struct
    //array size is fixed
    for (int i = 0; i < 2; ++i) {
        _ros2pdu_Ev3PduColorSensor(src.color_sensors[i], dst.color_sensors[i], dynamic_memory);
    }
    return true;
}
static inline bool _ros2pdu_struct_array_Ev3PduSensor_touch_sensors(ev3_msgs::msg::Ev3PduSensor &src, Hako_Ev3PduSensor &dst, PduDynamicMemory &dynamic_memory)
{
    // array struct
    //array size is fixed
    for (int i = 0; i < 2; ++i) {
        _ros2pdu_Ev3PduTouchSensor(src.touch_sensors[i], dst.touch_sensors[i], dynamic_memory);
    }
    return true;
}
static inline bool _ros2pdu_primitive_array_Ev3PduSensor_motor_angle(ev3_msgs::msg::Ev3PduSensor &src, Hako_Ev3PduSensor &dst, PduDynamicMemory &dynamic_memory)
{
    //Copy fixed array 3
    (void)dynamic_memory;
    (void)hako_convert_ros2pdu_array(
        src.motor_angle, src.motor_angle.size(),
        dst.motor_angle, M_ARRAY_SIZE(Hako_Ev3PduSensor, Hako_uint32, motor_angle));
    return true;
}

static inline bool _ros2pdu_Ev3PduSensor(ev3_msgs::msg::Ev3PduSensor &src, Hako_Ev3PduSensor &dst, PduDynamicMemory &dynamic_memory)
{
    try {
        // struct convert
        _ros2pdu_Ev3PduSensorHeader(src.head, dst.head, dynamic_memory);
        //primitive array copy
        _ros2pdu_primitive_array_Ev3PduSensor_buttons(src, dst, dynamic_memory);
        //struct array convert
        _ros2pdu_struct_array_Ev3PduSensor_color_sensors(src, dst, dynamic_memory);
        //struct array convert
        _ros2pdu_struct_array_Ev3PduSensor_touch_sensors(src, dst, dynamic_memory);
        //primitive array copy
        _ros2pdu_primitive_array_Ev3PduSensor_motor_angle(src, dst, dynamic_memory);
        // primitive convert
        hako_convert_ros2pdu(src.gyro_degree, dst.gyro_degree);
        // primitive convert
        hako_convert_ros2pdu(src.gyro_degree_rate, dst.gyro_degree_rate);
        // primitive convert
        hako_convert_ros2pdu(src.sensor_ultrasonic, dst.sensor_ultrasonic);
        // primitive convert
        hako_convert_ros2pdu(src.gps_lat, dst.gps_lat);
        // primitive convert
        hako_convert_ros2pdu(src.gps_lon, dst.gps_lon);
    } catch (const std::runtime_error& e) {
        std::cerr << "convertor error: " << e.what() << std::endl;
        return false;
    }
    return true;
}

static inline int hako_convert_ros2pdu_Ev3PduSensor(ev3_msgs::msg::Ev3PduSensor &src, Hako_Ev3PduSensor** dst)
{
    PduDynamicMemory dynamic_memory;
    Hako_Ev3PduSensor out;
    if (!_ros2pdu_Ev3PduSensor(src, out, dynamic_memory)) {
        return -1;
    }
    int total_size = sizeof(Hako_Ev3PduSensor) + sizeof(HakoPduMetaDataType) + dynamic_memory.get_total_size();

    // Allocate PDU memory
    char* base_ptr = (char*)malloc(total_size);
    if (base_ptr == nullptr) {
        return -1;
    }
    // Copy out on top
    memcpy(base_ptr, (void*)&out, sizeof(Hako_Ev3PduSensor));

    // Set metadata at the end
    HakoPduMetaDataType* meta = (HakoPduMetaDataType*)(base_ptr + sizeof(Hako_Ev3PduSensor));
    meta->magicno = HAKO_PDU_META_DATA_MAGICNO;
    meta->version = HAKO_PDU_META_DATA_VERSION;
    meta->top_off = 0;
    meta->total_size = total_size;
    meta->varray_off = sizeof(Hako_Ev3PduSensor) + sizeof(HakoPduMetaDataType);

    // Copy dynamic part and set offsets
    dynamic_memory.copy_to_pdu(base_ptr + meta->varray_off);

    *dst = (Hako_Ev3PduSensor*)base_ptr;
    return total_size;
}
static inline Hako_Ev3PduSensor* hako_create_empty_pdu_Ev3PduSensor(int heap_size)
{
    int total_size = sizeof(Hako_Ev3PduSensor) + sizeof(HakoPduMetaDataType) + heap_size;

    // Allocate PDU memory
    char* base_ptr = (char*)malloc(total_size);
    if (base_ptr == nullptr) {
        return nullptr;
    }
    memset(base_ptr, 0, total_size);
    // Set metadata at the end
    HakoPduMetaDataType* meta = (HakoPduMetaDataType*)(base_ptr + sizeof(Hako_Ev3PduSensor));
    meta->magicno = HAKO_PDU_META_DATA_MAGICNO;
    meta->version = HAKO_PDU_META_DATA_VERSION;
    meta->top_off = 0;
    meta->total_size = total_size;
    meta->varray_off = sizeof(Hako_Ev3PduSensor) + sizeof(HakoPduMetaDataType);
    return (Hako_Ev3PduSensor*)base_ptr;
}
#endif /* _PDU_CTYPE_CONV_HAKO_ev3_msgs_Ev3PduSensor_HPP_ */
