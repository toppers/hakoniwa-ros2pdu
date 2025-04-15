#ifndef _PDU_CPPTYPE_CONV_HAKO_ev3_msgs_Ev3PduColorSensor_HPP_
#define _PDU_CPPTYPE_CONV_HAKO_ev3_msgs_Ev3PduColorSensor_HPP_

#include "pdu_primitive_ctypes.h"
#include "pdu_primitive_ctypes_conv.hpp"
#include "pdu_dynamic_memory.hpp"
/*
 * Dependent pdu data
 */
#include "ev3_msgs/pdu_ctype_Ev3PduColorSensor.h"
/*
 * Dependent cpp pdu data
 */
#include "ev3_msgs/pdu_cpptype_Ev3PduColorSensor.hpp"

/*
 * Dependent Convertors
 */

/***************************
 *
 * PDU ==> CPP PDU
 *
 ***************************/

static inline int cpp_pdu2cpp_Ev3PduColorSensor(const char* heap_ptr, Hako_Ev3PduColorSensor &src, HakoCpp_Ev3PduColorSensor &dst)
{
    // primitive convert
    hako_convert_pdu2cpp(src.color, dst.color);
    // primitive convert
    hako_convert_pdu2cpp(src.reflect, dst.reflect);
    // primitive convert
    hako_convert_pdu2cpp(src.rgb_r, dst.rgb_r);
    // primitive convert
    hako_convert_pdu2cpp(src.rgb_g, dst.rgb_g);
    // primitive convert
    hako_convert_pdu2cpp(src.rgb_b, dst.rgb_b);
    (void)heap_ptr;
    return 0;
}

static inline int hako_convert_pdu2cpp_Ev3PduColorSensor(Hako_Ev3PduColorSensor &src, HakoCpp_Ev3PduColorSensor &dst)
{
    void* base_ptr = (void*)&src;
    void* heap_ptr = hako_get_heap_ptr_pdu(base_ptr);
    // Validate magic number and version
    if (heap_ptr == nullptr) {
        return -1; // Invalid PDU metadata
    }
    else {
        return cpp_pdu2cpp_Ev3PduColorSensor((char*)heap_ptr, src, dst);
    }
}

/***************************
 *
 * CPP PDU ==> PDU
 *
 ***************************/

static inline bool cpp_cpp2pdu_Ev3PduColorSensor(HakoCpp_Ev3PduColorSensor &src, Hako_Ev3PduColorSensor &dst, PduDynamicMemory &dynamic_memory)
{
    try {
        // primitive convert
        hako_convert_cpp2pdu(src.color, dst.color);
        // primitive convert
        hako_convert_cpp2pdu(src.reflect, dst.reflect);
        // primitive convert
        hako_convert_cpp2pdu(src.rgb_r, dst.rgb_r);
        // primitive convert
        hako_convert_cpp2pdu(src.rgb_g, dst.rgb_g);
        // primitive convert
        hako_convert_cpp2pdu(src.rgb_b, dst.rgb_b);
    } catch (const std::runtime_error& e) {
        std::cerr << "convertor error: " << e.what() << std::endl;
        return false;
    }
    (void)dynamic_memory;
    return true;
}

static inline int hako_convert_cpp2pdu_Ev3PduColorSensor(HakoCpp_Ev3PduColorSensor &src, Hako_Ev3PduColorSensor** dst)
{
    PduDynamicMemory dynamic_memory;
    Hako_Ev3PduColorSensor out;
    if (!cpp_cpp2pdu_Ev3PduColorSensor(src, out, dynamic_memory)) {
        return -1;
    }
    int heap_size = dynamic_memory.get_total_size();
    void* base_ptr = hako_create_empty_pdu(sizeof(Hako_Ev3PduColorSensor), heap_size);
    if (base_ptr == nullptr) {
        return -1;
    }
    // Copy out on base data
    memcpy(base_ptr, (void*)&out, sizeof(Hako_Ev3PduColorSensor));

    // Copy dynamic part and set offsets
    void* heap_ptr = hako_get_heap_ptr_pdu(base_ptr);
    dynamic_memory.copy_to_pdu((char*)heap_ptr);

    *dst = (Hako_Ev3PduColorSensor*)base_ptr;
    return hako_get_pdu_meta_data(base_ptr)->total_size;
}

static inline Hako_Ev3PduColorSensor* hako_create_empty_pdu_Ev3PduColorSensor(int heap_size)
{
    // Allocate PDU memory
    char* base_ptr = (char*)hako_create_empty_pdu(sizeof(Hako_Ev3PduColorSensor), heap_size);
    if (base_ptr == nullptr) {
        return nullptr;
    }
    return (Hako_Ev3PduColorSensor*)base_ptr;
}
namespace hako::pdu::msgs::ev3_msgs
{
class Ev3PduColorSensor
{
public:
    Ev3PduColorSensor() = default;
    ~Ev3PduColorSensor() = default;

    bool pdu2cpp(char* top_ptr, HakoCpp_Ev3PduColorSensor& cppData)
    {
        char* base_ptr = (char*)hako_get_base_ptr_pdu((void*)top_ptr);
        if (base_ptr == nullptr) {
            std::cerr << "[ConvertorError][" << "Ev3PduColorSensor" << "] hako_get_base_ptr_pdu returned null" << std::endl;
            return false;
        } 
        int ret = hako_convert_pdu2cpp_Ev3PduColorSensor(*(Hako_Ev3PduColorSensor*)base_ptr, cppData);
        if (ret != 0) {
            std::cerr << "[ConvertorError][" << "Ev3PduColorSensor" << "] hako_convert_pdu2cpp returned " << ret << std::endl;
            return false;
        }
        return true;
    }

    int cpp2pdu(HakoCpp_Ev3PduColorSensor& cppData, char* pdu_buffer, int buffer_len)
    {
        char* base_ptr = nullptr;
        int pdu_size = hako_convert_cpp2pdu_Ev3PduColorSensor(cppData, (Hako_Ev3PduColorSensor**)&base_ptr);
        if (pdu_size < 0) {
            std::cerr << "[ConvertorError][" << "Ev3PduColorSensor" << "] hako_convert_cpp2pdu returned error code: " << pdu_size << std::endl;
            return -1;
        }
        if (pdu_size > buffer_len) {
            std::cerr << "[ConvertorError][" << "Ev3PduColorSensor" << "] buffer too small. pdu_size=" << pdu_size << " buffer_len=" << buffer_len << std::endl;
            return -1;
        }
        void* top_ptr = hako_get_top_ptr_pdu((void*)base_ptr);
        if (top_ptr == nullptr) {
            std::cerr << "[ConvertorError][" << "Ev3PduColorSensor" << "] hako_get_top_ptr_pdu returned null" << std::endl;
            return false;
        }
        memcpy(pdu_buffer, top_ptr, pdu_size);
        hako_destroy_pdu((void*)base_ptr);
        return pdu_size;
    }

private:
};
}


#endif /* _PDU_CPPTYPE_CONV_HAKO_ev3_msgs_Ev3PduColorSensor_HPP_ */
