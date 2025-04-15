#ifndef _PDU_CPPTYPE_CONV_HAKO_ev3_msgs_Ev3PduSensor_HPP_
#define _PDU_CPPTYPE_CONV_HAKO_ev3_msgs_Ev3PduSensor_HPP_

#include "pdu_primitive_ctypes.h"
#include "pdu_primitive_ctypes_conv.hpp"
#include "pdu_dynamic_memory.hpp"
/*
 * Dependent pdu data
 */
#include "ev3_msgs/pdu_ctype_Ev3PduSensor.h"
/*
 * Dependent cpp pdu data
 */
#include "ev3_msgs/pdu_cpptype_Ev3PduSensor.hpp"

/*
 * Dependent Convertors
 */
#include "ev3_msgs/pdu_cpptype_conv_Ev3PduColorSensor.hpp"
#include "ev3_msgs/pdu_cpptype_conv_Ev3PduSensorHeader.hpp"
#include "ev3_msgs/pdu_cpptype_conv_Ev3PduTouchSensor.hpp"

/***************************
 *
 * PDU ==> CPP PDU
 *
 ***************************/
static inline int cpp_pdu2cpp_primitive_array_Ev3PduSensor_buttons(const char* heap_ptr, Hako_Ev3PduSensor &src, HakoCpp_Ev3PduSensor &dst)
{
    // Fixed size array convertor
    (void)heap_ptr;
    for (int i = 0; i < 1; ++i) {
        hako_convert_pdu2cpp(src.buttons[i], dst.buttons[i]);
    }
    return 0;
}
static inline int cpp_pdu2cpp_struct_array_Ev3PduSensor_color_sensors(const char* heap_ptr, Hako_Ev3PduSensor &src, HakoCpp_Ev3PduSensor &dst)
{
    // Fixed size array convertor
    for (int i = 0; i < 2; ++i) {
        cpp_pdu2cpp_Ev3PduColorSensor(heap_ptr, src.color_sensors[i], dst.color_sensors[i]);
    }
    return 0;
}
static inline int cpp_pdu2cpp_struct_array_Ev3PduSensor_touch_sensors(const char* heap_ptr, Hako_Ev3PduSensor &src, HakoCpp_Ev3PduSensor &dst)
{
    // Fixed size array convertor
    for (int i = 0; i < 2; ++i) {
        cpp_pdu2cpp_Ev3PduTouchSensor(heap_ptr, src.touch_sensors[i], dst.touch_sensors[i]);
    }
    return 0;
}
static inline int cpp_pdu2cpp_primitive_array_Ev3PduSensor_motor_angle(const char* heap_ptr, Hako_Ev3PduSensor &src, HakoCpp_Ev3PduSensor &dst)
{
    // Fixed size array convertor
    (void)heap_ptr;
    for (int i = 0; i < 3; ++i) {
        hako_convert_pdu2cpp(src.motor_angle[i], dst.motor_angle[i]);
    }
    return 0;
}

static inline int cpp_pdu2cpp_Ev3PduSensor(const char* heap_ptr, Hako_Ev3PduSensor &src, HakoCpp_Ev3PduSensor &dst)
{
    // Struct convert
    cpp_pdu2cpp_Ev3PduSensorHeader(heap_ptr, src.head, dst.head);
    // primitive array convertor
    cpp_pdu2cpp_primitive_array_Ev3PduSensor_buttons(heap_ptr, src, dst);
    // struct array convertor
    cpp_pdu2cpp_struct_array_Ev3PduSensor_color_sensors(heap_ptr, src, dst);
    // struct array convertor
    cpp_pdu2cpp_struct_array_Ev3PduSensor_touch_sensors(heap_ptr, src, dst);
    // primitive array convertor
    cpp_pdu2cpp_primitive_array_Ev3PduSensor_motor_angle(heap_ptr, src, dst);
    // primitive convert
    hako_convert_pdu2cpp(src.gyro_degree, dst.gyro_degree);
    // primitive convert
    hako_convert_pdu2cpp(src.gyro_degree_rate, dst.gyro_degree_rate);
    // primitive convert
    hako_convert_pdu2cpp(src.sensor_ultrasonic, dst.sensor_ultrasonic);
    // primitive convert
    hako_convert_pdu2cpp(src.gps_lat, dst.gps_lat);
    // primitive convert
    hako_convert_pdu2cpp(src.gps_lon, dst.gps_lon);
    (void)heap_ptr;
    return 0;
}

static inline int hako_convert_pdu2cpp_Ev3PduSensor(Hako_Ev3PduSensor &src, HakoCpp_Ev3PduSensor &dst)
{
    void* base_ptr = (void*)&src;
    void* heap_ptr = hako_get_heap_ptr_pdu(base_ptr);
    // Validate magic number and version
    if (heap_ptr == nullptr) {
        return -1; // Invalid PDU metadata
    }
    else {
        return cpp_pdu2cpp_Ev3PduSensor((char*)heap_ptr, src, dst);
    }
}

/***************************
 *
 * CPP PDU ==> PDU
 *
 ***************************/
static inline bool cpp_cpp2pdu_primitive_array_Ev3PduSensor_buttons(HakoCpp_Ev3PduSensor &src, Hako_Ev3PduSensor &dst, PduDynamicMemory &dynamic_memory)
{
    //Copy fixed array 1
    (void)dynamic_memory;
    (void)hako_convert_cpp2pdu_array(
        src.buttons, src.buttons.size(),
        dst.buttons, M_ARRAY_SIZE(Hako_Ev3PduSensor, Hako_uint8, buttons));
    return true;
}
static inline bool cpp_cpp2pdu_struct_array_Ev3PduSensor_color_sensors(HakoCpp_Ev3PduSensor &src, Hako_Ev3PduSensor &dst, PduDynamicMemory &dynamic_memory)
{
    // array struct
    //array size is fixed
    for (int i = 0; i < 2; ++i) {
        cpp_cpp2pdu_Ev3PduColorSensor(src.color_sensors[i], dst.color_sensors[i], dynamic_memory);
    }
    return true;
}
static inline bool cpp_cpp2pdu_struct_array_Ev3PduSensor_touch_sensors(HakoCpp_Ev3PduSensor &src, Hako_Ev3PduSensor &dst, PduDynamicMemory &dynamic_memory)
{
    // array struct
    //array size is fixed
    for (int i = 0; i < 2; ++i) {
        cpp_cpp2pdu_Ev3PduTouchSensor(src.touch_sensors[i], dst.touch_sensors[i], dynamic_memory);
    }
    return true;
}
static inline bool cpp_cpp2pdu_primitive_array_Ev3PduSensor_motor_angle(HakoCpp_Ev3PduSensor &src, Hako_Ev3PduSensor &dst, PduDynamicMemory &dynamic_memory)
{
    //Copy fixed array 3
    (void)dynamic_memory;
    (void)hako_convert_cpp2pdu_array(
        src.motor_angle, src.motor_angle.size(),
        dst.motor_angle, M_ARRAY_SIZE(Hako_Ev3PduSensor, Hako_uint32, motor_angle));
    return true;
}

static inline bool cpp_cpp2pdu_Ev3PduSensor(HakoCpp_Ev3PduSensor &src, Hako_Ev3PduSensor &dst, PduDynamicMemory &dynamic_memory)
{
    try {
        // struct convert
        cpp_cpp2pdu_Ev3PduSensorHeader(src.head, dst.head, dynamic_memory);
        //primitive array copy
        cpp_cpp2pdu_primitive_array_Ev3PduSensor_buttons(src, dst, dynamic_memory);
        //struct array convert
        cpp_cpp2pdu_struct_array_Ev3PduSensor_color_sensors(src, dst, dynamic_memory);
        //struct array convert
        cpp_cpp2pdu_struct_array_Ev3PduSensor_touch_sensors(src, dst, dynamic_memory);
        //primitive array copy
        cpp_cpp2pdu_primitive_array_Ev3PduSensor_motor_angle(src, dst, dynamic_memory);
        // primitive convert
        hako_convert_cpp2pdu(src.gyro_degree, dst.gyro_degree);
        // primitive convert
        hako_convert_cpp2pdu(src.gyro_degree_rate, dst.gyro_degree_rate);
        // primitive convert
        hako_convert_cpp2pdu(src.sensor_ultrasonic, dst.sensor_ultrasonic);
        // primitive convert
        hako_convert_cpp2pdu(src.gps_lat, dst.gps_lat);
        // primitive convert
        hako_convert_cpp2pdu(src.gps_lon, dst.gps_lon);
    } catch (const std::runtime_error& e) {
        std::cerr << "convertor error: " << e.what() << std::endl;
        return false;
    }
    (void)dynamic_memory;
    return true;
}

static inline int hako_convert_cpp2pdu_Ev3PduSensor(HakoCpp_Ev3PduSensor &src, Hako_Ev3PduSensor** dst)
{
    PduDynamicMemory dynamic_memory;
    Hako_Ev3PduSensor out;
    if (!cpp_cpp2pdu_Ev3PduSensor(src, out, dynamic_memory)) {
        return -1;
    }
    int heap_size = dynamic_memory.get_total_size();
    void* base_ptr = hako_create_empty_pdu(sizeof(Hako_Ev3PduSensor), heap_size);
    if (base_ptr == nullptr) {
        return -1;
    }
    // Copy out on base data
    memcpy(base_ptr, (void*)&out, sizeof(Hako_Ev3PduSensor));

    // Copy dynamic part and set offsets
    void* heap_ptr = hako_get_heap_ptr_pdu(base_ptr);
    dynamic_memory.copy_to_pdu((char*)heap_ptr);

    *dst = (Hako_Ev3PduSensor*)base_ptr;
    return hako_get_pdu_meta_data(base_ptr)->total_size;
}

static inline Hako_Ev3PduSensor* hako_create_empty_pdu_Ev3PduSensor(int heap_size)
{
    // Allocate PDU memory
    char* base_ptr = (char*)hako_create_empty_pdu(sizeof(Hako_Ev3PduSensor), heap_size);
    if (base_ptr == nullptr) {
        return nullptr;
    }
    return (Hako_Ev3PduSensor*)base_ptr;
}
namespace hako::pdu::msgs::ev3_msgs
{
class Ev3PduSensor
{
public:
    Ev3PduSensor() = default;
    ~Ev3PduSensor() = default;

    bool pdu2cpp(char* top_ptr, HakoCpp_Ev3PduSensor& cppData)
    {
        char* base_ptr = (char*)hako_get_base_ptr_pdu((void*)top_ptr);
        if (base_ptr == nullptr) {
            std::cerr << "[ConvertorError][" << "Ev3PduSensor" << "] hako_get_base_ptr_pdu returned null" << std::endl;
            return false;
        } 
        int ret = hako_convert_pdu2cpp_Ev3PduSensor(*(Hako_Ev3PduSensor*)base_ptr, cppData);
        if (ret != 0) {
            std::cerr << "[ConvertorError][" << "Ev3PduSensor" << "] hako_convert_pdu2cpp returned " << ret << std::endl;
            return false;
        }
        return true;
    }

    int cpp2pdu(HakoCpp_Ev3PduSensor& cppData, char* pdu_buffer, int buffer_len)
    {
        char* base_ptr = nullptr;
        int pdu_size = hako_convert_cpp2pdu_Ev3PduSensor(cppData, (Hako_Ev3PduSensor**)&base_ptr);
        if (pdu_size < 0) {
            std::cerr << "[ConvertorError][" << "Ev3PduSensor" << "] hako_convert_cpp2pdu returned error code: " << pdu_size << std::endl;
            return -1;
        }
        if (pdu_size > buffer_len) {
            std::cerr << "[ConvertorError][" << "Ev3PduSensor" << "] buffer too small. pdu_size=" << pdu_size << " buffer_len=" << buffer_len << std::endl;
            return -1;
        }
        void* top_ptr = hako_get_top_ptr_pdu((void*)base_ptr);
        if (top_ptr == nullptr) {
            std::cerr << "[ConvertorError][" << "Ev3PduSensor" << "] hako_get_top_ptr_pdu returned null" << std::endl;
            return false;
        }
        memcpy(pdu_buffer, top_ptr, pdu_size);
        hako_destroy_pdu((void*)base_ptr);
        return pdu_size;
    }

private:
};
}


#endif /* _PDU_CPPTYPE_CONV_HAKO_ev3_msgs_Ev3PduSensor_HPP_ */
