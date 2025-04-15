#ifndef _PDU_CPPTYPE_CONV_HAKO_ev3_msgs_Ev3PduActuator_HPP_
#define _PDU_CPPTYPE_CONV_HAKO_ev3_msgs_Ev3PduActuator_HPP_

#include "pdu_primitive_ctypes.h"
#include "pdu_primitive_ctypes_conv.hpp"
#include "pdu_dynamic_memory.hpp"
/*
 * Dependent pdu data
 */
#include "ev3_msgs/pdu_ctype_Ev3PduActuator.h"
/*
 * Dependent cpp pdu data
 */
#include "ev3_msgs/pdu_cpptype_Ev3PduActuator.hpp"

/*
 * Dependent Convertors
 */
#include "ev3_msgs/pdu_cpptype_conv_Ev3PduActuatorHeader.hpp"
#include "ev3_msgs/pdu_cpptype_conv_Ev3PduMotor.hpp"

/***************************
 *
 * PDU ==> CPP PDU
 *
 ***************************/
static inline int cpp_pdu2cpp_primitive_array_Ev3PduActuator_leds(const char* heap_ptr, Hako_Ev3PduActuator &src, HakoCpp_Ev3PduActuator &dst)
{
    // Fixed size array convertor
    (void)heap_ptr;
    for (int i = 0; i < 1; ++i) {
        hako_convert_pdu2cpp(src.leds[i], dst.leds[i]);
    }
    return 0;
}
static inline int cpp_pdu2cpp_struct_array_Ev3PduActuator_motors(const char* heap_ptr, Hako_Ev3PduActuator &src, HakoCpp_Ev3PduActuator &dst)
{
    // Fixed size array convertor
    for (int i = 0; i < 3; ++i) {
        cpp_pdu2cpp_Ev3PduMotor(heap_ptr, src.motors[i], dst.motors[i]);
    }
    return 0;
}

static inline int cpp_pdu2cpp_Ev3PduActuator(const char* heap_ptr, Hako_Ev3PduActuator &src, HakoCpp_Ev3PduActuator &dst)
{
    // Struct convert
    cpp_pdu2cpp_Ev3PduActuatorHeader(heap_ptr, src.head, dst.head);
    // primitive array convertor
    cpp_pdu2cpp_primitive_array_Ev3PduActuator_leds(heap_ptr, src, dst);
    // struct array convertor
    cpp_pdu2cpp_struct_array_Ev3PduActuator_motors(heap_ptr, src, dst);
    // primitive convert
    hako_convert_pdu2cpp(src.gyro_reset, dst.gyro_reset);
    (void)heap_ptr;
    return 0;
}

static inline int hako_convert_pdu2cpp_Ev3PduActuator(Hako_Ev3PduActuator &src, HakoCpp_Ev3PduActuator &dst)
{
    void* base_ptr = (void*)&src;
    void* heap_ptr = hako_get_heap_ptr_pdu(base_ptr);
    // Validate magic number and version
    if (heap_ptr == nullptr) {
        return -1; // Invalid PDU metadata
    }
    else {
        return cpp_pdu2cpp_Ev3PduActuator((char*)heap_ptr, src, dst);
    }
}

/***************************
 *
 * CPP PDU ==> PDU
 *
 ***************************/
static inline bool cpp_cpp2pdu_primitive_array_Ev3PduActuator_leds(HakoCpp_Ev3PduActuator &src, Hako_Ev3PduActuator &dst, PduDynamicMemory &dynamic_memory)
{
    //Copy fixed array 1
    (void)dynamic_memory;
    (void)hako_convert_cpp2pdu_array(
        src.leds, src.leds.size(),
        dst.leds, M_ARRAY_SIZE(Hako_Ev3PduActuator, Hako_uint8, leds));
    return true;
}
static inline bool cpp_cpp2pdu_struct_array_Ev3PduActuator_motors(HakoCpp_Ev3PduActuator &src, Hako_Ev3PduActuator &dst, PduDynamicMemory &dynamic_memory)
{
    // array struct
    //array size is fixed
    for (int i = 0; i < 3; ++i) {
        cpp_cpp2pdu_Ev3PduMotor(src.motors[i], dst.motors[i], dynamic_memory);
    }
    return true;
}

static inline bool cpp_cpp2pdu_Ev3PduActuator(HakoCpp_Ev3PduActuator &src, Hako_Ev3PduActuator &dst, PduDynamicMemory &dynamic_memory)
{
    try {
        // struct convert
        cpp_cpp2pdu_Ev3PduActuatorHeader(src.head, dst.head, dynamic_memory);
        //primitive array copy
        cpp_cpp2pdu_primitive_array_Ev3PduActuator_leds(src, dst, dynamic_memory);
        //struct array convert
        cpp_cpp2pdu_struct_array_Ev3PduActuator_motors(src, dst, dynamic_memory);
        // primitive convert
        hako_convert_cpp2pdu(src.gyro_reset, dst.gyro_reset);
    } catch (const std::runtime_error& e) {
        std::cerr << "convertor error: " << e.what() << std::endl;
        return false;
    }
    (void)dynamic_memory;
    return true;
}

static inline int hako_convert_cpp2pdu_Ev3PduActuator(HakoCpp_Ev3PduActuator &src, Hako_Ev3PduActuator** dst)
{
    PduDynamicMemory dynamic_memory;
    Hako_Ev3PduActuator out;
    if (!cpp_cpp2pdu_Ev3PduActuator(src, out, dynamic_memory)) {
        return -1;
    }
    int heap_size = dynamic_memory.get_total_size();
    void* base_ptr = hako_create_empty_pdu(sizeof(Hako_Ev3PduActuator), heap_size);
    if (base_ptr == nullptr) {
        return -1;
    }
    // Copy out on base data
    memcpy(base_ptr, (void*)&out, sizeof(Hako_Ev3PduActuator));

    // Copy dynamic part and set offsets
    void* heap_ptr = hako_get_heap_ptr_pdu(base_ptr);
    dynamic_memory.copy_to_pdu((char*)heap_ptr);

    *dst = (Hako_Ev3PduActuator*)base_ptr;
    return hako_get_pdu_meta_data(base_ptr)->total_size;
}

static inline Hako_Ev3PduActuator* hako_create_empty_pdu_Ev3PduActuator(int heap_size)
{
    // Allocate PDU memory
    char* base_ptr = (char*)hako_create_empty_pdu(sizeof(Hako_Ev3PduActuator), heap_size);
    if (base_ptr == nullptr) {
        return nullptr;
    }
    return (Hako_Ev3PduActuator*)base_ptr;
}
namespace hako::pdu::msgs::ev3_msgs
{
class Ev3PduActuator
{
public:
    Ev3PduActuator() = default;
    ~Ev3PduActuator() = default;

    bool pdu2cpp(char* top_ptr, HakoCpp_Ev3PduActuator& cppData)
    {
        char* base_ptr = (char*)hako_get_base_ptr_pdu((void*)top_ptr);
        if (base_ptr == nullptr) {
            std::cerr << "[ConvertorError][" << "Ev3PduActuator" << "] hako_get_base_ptr_pdu returned null" << std::endl;
            return false;
        } 
        int ret = hako_convert_pdu2cpp_Ev3PduActuator(*(Hako_Ev3PduActuator*)base_ptr, cppData);
        if (ret != 0) {
            std::cerr << "[ConvertorError][" << "Ev3PduActuator" << "] hako_convert_pdu2cpp returned " << ret << std::endl;
            return false;
        }
        return true;
    }

    int cpp2pdu(HakoCpp_Ev3PduActuator& cppData, char* pdu_buffer, int buffer_len)
    {
        char* base_ptr = nullptr;
        int pdu_size = hako_convert_cpp2pdu_Ev3PduActuator(cppData, (Hako_Ev3PduActuator**)&base_ptr);
        if (pdu_size < 0) {
            std::cerr << "[ConvertorError][" << "Ev3PduActuator" << "] hako_convert_cpp2pdu returned error code: " << pdu_size << std::endl;
            return -1;
        }
        if (pdu_size > buffer_len) {
            std::cerr << "[ConvertorError][" << "Ev3PduActuator" << "] buffer too small. pdu_size=" << pdu_size << " buffer_len=" << buffer_len << std::endl;
            return -1;
        }
        void* top_ptr = hako_get_top_ptr_pdu((void*)base_ptr);
        if (top_ptr == nullptr) {
            std::cerr << "[ConvertorError][" << "Ev3PduActuator" << "] hako_get_top_ptr_pdu returned null" << std::endl;
            return false;
        }
        memcpy(pdu_buffer, top_ptr, pdu_size);
        hako_destroy_pdu((void*)base_ptr);
        return pdu_size;
    }

private:
};
}


#endif /* _PDU_CPPTYPE_CONV_HAKO_ev3_msgs_Ev3PduActuator_HPP_ */
