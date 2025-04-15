#ifndef _PDU_CPPTYPE_CONV_HAKO_hako_mavlink_msgs_HakoHilSensor_HPP_
#define _PDU_CPPTYPE_CONV_HAKO_hako_mavlink_msgs_HakoHilSensor_HPP_

#include "pdu_primitive_ctypes.h"
#include "pdu_primitive_ctypes_conv.hpp"
#include "pdu_dynamic_memory.hpp"
/*
 * Dependent pdu data
 */
#include "hako_mavlink_msgs/pdu_ctype_HakoHilSensor.h"
/*
 * Dependent cpp pdu data
 */
#include "hako_mavlink_msgs/pdu_cpptype_HakoHilSensor.hpp"

/*
 * Dependent Convertors
 */

/***************************
 *
 * PDU ==> CPP PDU
 *
 ***************************/

static inline int cpp_pdu2cpp_HakoHilSensor(const char* heap_ptr, Hako_HakoHilSensor &src, HakoCpp_HakoHilSensor &dst)
{
    // primitive convert
    hako_convert_pdu2cpp(src.time_usec, dst.time_usec);
    // primitive convert
    hako_convert_pdu2cpp(src.xacc, dst.xacc);
    // primitive convert
    hako_convert_pdu2cpp(src.yacc, dst.yacc);
    // primitive convert
    hako_convert_pdu2cpp(src.zacc, dst.zacc);
    // primitive convert
    hako_convert_pdu2cpp(src.xgyro, dst.xgyro);
    // primitive convert
    hako_convert_pdu2cpp(src.ygyro, dst.ygyro);
    // primitive convert
    hako_convert_pdu2cpp(src.zgyro, dst.zgyro);
    // primitive convert
    hako_convert_pdu2cpp(src.xmag, dst.xmag);
    // primitive convert
    hako_convert_pdu2cpp(src.ymag, dst.ymag);
    // primitive convert
    hako_convert_pdu2cpp(src.zmag, dst.zmag);
    // primitive convert
    hako_convert_pdu2cpp(src.abs_pressure, dst.abs_pressure);
    // primitive convert
    hako_convert_pdu2cpp(src.diff_pressure, dst.diff_pressure);
    // primitive convert
    hako_convert_pdu2cpp(src.pressure_alt, dst.pressure_alt);
    // primitive convert
    hako_convert_pdu2cpp(src.temperature, dst.temperature);
    // primitive convert
    hako_convert_pdu2cpp(src.fields_updated, dst.fields_updated);
    // primitive convert
    hako_convert_pdu2cpp(src.id, dst.id);
    (void)heap_ptr;
    return 0;
}

static inline int hako_convert_pdu2cpp_HakoHilSensor(Hako_HakoHilSensor &src, HakoCpp_HakoHilSensor &dst)
{
    void* base_ptr = (void*)&src;
    void* heap_ptr = hako_get_heap_ptr_pdu(base_ptr);
    // Validate magic number and version
    if (heap_ptr == nullptr) {
        return -1; // Invalid PDU metadata
    }
    else {
        return cpp_pdu2cpp_HakoHilSensor((char*)heap_ptr, src, dst);
    }
}

/***************************
 *
 * CPP PDU ==> PDU
 *
 ***************************/

static inline bool cpp_cpp2pdu_HakoHilSensor(HakoCpp_HakoHilSensor &src, Hako_HakoHilSensor &dst, PduDynamicMemory &dynamic_memory)
{
    try {
        // primitive convert
        hako_convert_cpp2pdu(src.time_usec, dst.time_usec);
        // primitive convert
        hako_convert_cpp2pdu(src.xacc, dst.xacc);
        // primitive convert
        hako_convert_cpp2pdu(src.yacc, dst.yacc);
        // primitive convert
        hako_convert_cpp2pdu(src.zacc, dst.zacc);
        // primitive convert
        hako_convert_cpp2pdu(src.xgyro, dst.xgyro);
        // primitive convert
        hako_convert_cpp2pdu(src.ygyro, dst.ygyro);
        // primitive convert
        hako_convert_cpp2pdu(src.zgyro, dst.zgyro);
        // primitive convert
        hako_convert_cpp2pdu(src.xmag, dst.xmag);
        // primitive convert
        hako_convert_cpp2pdu(src.ymag, dst.ymag);
        // primitive convert
        hako_convert_cpp2pdu(src.zmag, dst.zmag);
        // primitive convert
        hako_convert_cpp2pdu(src.abs_pressure, dst.abs_pressure);
        // primitive convert
        hako_convert_cpp2pdu(src.diff_pressure, dst.diff_pressure);
        // primitive convert
        hako_convert_cpp2pdu(src.pressure_alt, dst.pressure_alt);
        // primitive convert
        hako_convert_cpp2pdu(src.temperature, dst.temperature);
        // primitive convert
        hako_convert_cpp2pdu(src.fields_updated, dst.fields_updated);
        // primitive convert
        hako_convert_cpp2pdu(src.id, dst.id);
    } catch (const std::runtime_error& e) {
        std::cerr << "convertor error: " << e.what() << std::endl;
        return false;
    }
    (void)dynamic_memory;
    return true;
}

static inline int hako_convert_cpp2pdu_HakoHilSensor(HakoCpp_HakoHilSensor &src, Hako_HakoHilSensor** dst)
{
    PduDynamicMemory dynamic_memory;
    Hako_HakoHilSensor out;
    if (!cpp_cpp2pdu_HakoHilSensor(src, out, dynamic_memory)) {
        return -1;
    }
    int heap_size = dynamic_memory.get_total_size();
    void* base_ptr = hako_create_empty_pdu(sizeof(Hako_HakoHilSensor), heap_size);
    if (base_ptr == nullptr) {
        return -1;
    }
    // Copy out on base data
    memcpy(base_ptr, (void*)&out, sizeof(Hako_HakoHilSensor));

    // Copy dynamic part and set offsets
    void* heap_ptr = hako_get_heap_ptr_pdu(base_ptr);
    dynamic_memory.copy_to_pdu((char*)heap_ptr);

    *dst = (Hako_HakoHilSensor*)base_ptr;
    return hako_get_pdu_meta_data(base_ptr)->total_size;
}

static inline Hako_HakoHilSensor* hako_create_empty_pdu_HakoHilSensor(int heap_size)
{
    // Allocate PDU memory
    char* base_ptr = (char*)hako_create_empty_pdu(sizeof(Hako_HakoHilSensor), heap_size);
    if (base_ptr == nullptr) {
        return nullptr;
    }
    return (Hako_HakoHilSensor*)base_ptr;
}
namespace hako::pdu::msgs::hako_mavlink_msgs
{
class HakoHilSensor
{
public:
    HakoHilSensor() = default;
    ~HakoHilSensor() = default;

    bool pdu2cpp(char* top_ptr, HakoCpp_HakoHilSensor& cppData)
    {
        char* base_ptr = (char*)hako_get_base_ptr_pdu((void*)top_ptr);
        if (base_ptr == nullptr) {
            std::cerr << "[ConvertorError][" << "HakoHilSensor" << "] hako_get_base_ptr_pdu returned null" << std::endl;
            return false;
        } 
        int ret = hako_convert_pdu2cpp_HakoHilSensor(*(Hako_HakoHilSensor*)base_ptr, cppData);
        if (ret != 0) {
            std::cerr << "[ConvertorError][" << "HakoHilSensor" << "] hako_convert_pdu2cpp returned " << ret << std::endl;
            return false;
        }
        return true;
    }

    int cpp2pdu(HakoCpp_HakoHilSensor& cppData, char* pdu_buffer, int buffer_len)
    {
        char* base_ptr = nullptr;
        int pdu_size = hako_convert_cpp2pdu_HakoHilSensor(cppData, (Hako_HakoHilSensor**)&base_ptr);
        if (pdu_size < 0) {
            std::cerr << "[ConvertorError][" << "HakoHilSensor" << "] hako_convert_cpp2pdu returned error code: " << pdu_size << std::endl;
            return -1;
        }
        if (pdu_size > buffer_len) {
            std::cerr << "[ConvertorError][" << "HakoHilSensor" << "] buffer too small. pdu_size=" << pdu_size << " buffer_len=" << buffer_len << std::endl;
            return -1;
        }
        void* top_ptr = hako_get_top_ptr_pdu((void*)base_ptr);
        if (top_ptr == nullptr) {
            std::cerr << "[ConvertorError][" << "HakoHilSensor" << "] hako_get_top_ptr_pdu returned null" << std::endl;
            return false;
        }
        memcpy(pdu_buffer, top_ptr, pdu_size);
        hako_destroy_pdu((void*)base_ptr);
        return pdu_size;
    }

private:
};
}


#endif /* _PDU_CPPTYPE_CONV_HAKO_hako_mavlink_msgs_HakoHilSensor_HPP_ */
