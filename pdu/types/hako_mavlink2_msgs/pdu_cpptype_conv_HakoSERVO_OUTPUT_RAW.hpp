#ifndef _PDU_CPPTYPE_CONV_HAKO_hako_mavlink2_msgs_HakoSERVO_OUTPUT_RAW_HPP_
#define _PDU_CPPTYPE_CONV_HAKO_hako_mavlink2_msgs_HakoSERVO_OUTPUT_RAW_HPP_

#include "pdu_primitive_ctypes.h"
#include "pdu_primitive_ctypes_conv.hpp"
#include "pdu_dynamic_memory.hpp"
/*
 * Dependent pdu data
 */
#include "hako_mavlink2_msgs/pdu_ctype_HakoSERVO_OUTPUT_RAW.h"
/*
 * Dependent cpp pdu data
 */
#include "hako_mavlink2_msgs/pdu_cpptype_HakoSERVO_OUTPUT_RAW.hpp"

/*
 * Dependent Convertors
 */

/***************************
 *
 * PDU ==> CPP PDU
 *
 ***************************/

static inline int cpp_pdu2cpp_HakoSERVO_OUTPUT_RAW(const char* heap_ptr, Hako_HakoSERVO_OUTPUT_RAW &src, HakoCpp_HakoSERVO_OUTPUT_RAW &dst)
{
    // primitive convert
    hako_convert_pdu2cpp(src.time_usec, dst.time_usec);
    // primitive convert
    hako_convert_pdu2cpp(src.port, dst.port);
    // primitive convert
    hako_convert_pdu2cpp(src.servo1_raw, dst.servo1_raw);
    // primitive convert
    hako_convert_pdu2cpp(src.servo2_raw, dst.servo2_raw);
    // primitive convert
    hako_convert_pdu2cpp(src.servo3_raw, dst.servo3_raw);
    // primitive convert
    hako_convert_pdu2cpp(src.servo4_raw, dst.servo4_raw);
    // primitive convert
    hako_convert_pdu2cpp(src.servo5_raw, dst.servo5_raw);
    // primitive convert
    hako_convert_pdu2cpp(src.servo6_raw, dst.servo6_raw);
    // primitive convert
    hako_convert_pdu2cpp(src.servo7_raw, dst.servo7_raw);
    // primitive convert
    hako_convert_pdu2cpp(src.servo8_raw, dst.servo8_raw);
    // primitive convert
    hako_convert_pdu2cpp(src.servo9_raw, dst.servo9_raw);
    // primitive convert
    hako_convert_pdu2cpp(src.servo10_raw, dst.servo10_raw);
    // primitive convert
    hako_convert_pdu2cpp(src.servo11_raw, dst.servo11_raw);
    // primitive convert
    hako_convert_pdu2cpp(src.servo12_raw, dst.servo12_raw);
    // primitive convert
    hako_convert_pdu2cpp(src.servo13_raw, dst.servo13_raw);
    // primitive convert
    hako_convert_pdu2cpp(src.servo14_raw, dst.servo14_raw);
    // primitive convert
    hako_convert_pdu2cpp(src.servo15_raw, dst.servo15_raw);
    // primitive convert
    hako_convert_pdu2cpp(src.servo16_raw, dst.servo16_raw);
    (void)heap_ptr;
    return 0;
}

static inline int hako_convert_pdu2cpp_HakoSERVO_OUTPUT_RAW(Hako_HakoSERVO_OUTPUT_RAW &src, HakoCpp_HakoSERVO_OUTPUT_RAW &dst)
{
    void* base_ptr = (void*)&src;
    void* heap_ptr = hako_get_heap_ptr_pdu(base_ptr);
    // Validate magic number and version
    if (heap_ptr == nullptr) {
        return -1; // Invalid PDU metadata
    }
    else {
        return cpp_pdu2cpp_HakoSERVO_OUTPUT_RAW((char*)heap_ptr, src, dst);
    }
}

/***************************
 *
 * CPP PDU ==> PDU
 *
 ***************************/

static inline bool cpp_cpp2pdu_HakoSERVO_OUTPUT_RAW(HakoCpp_HakoSERVO_OUTPUT_RAW &src, Hako_HakoSERVO_OUTPUT_RAW &dst, PduDynamicMemory &dynamic_memory)
{
    try {
        // primitive convert
        hako_convert_cpp2pdu(src.time_usec, dst.time_usec);
        // primitive convert
        hako_convert_cpp2pdu(src.port, dst.port);
        // primitive convert
        hako_convert_cpp2pdu(src.servo1_raw, dst.servo1_raw);
        // primitive convert
        hako_convert_cpp2pdu(src.servo2_raw, dst.servo2_raw);
        // primitive convert
        hako_convert_cpp2pdu(src.servo3_raw, dst.servo3_raw);
        // primitive convert
        hako_convert_cpp2pdu(src.servo4_raw, dst.servo4_raw);
        // primitive convert
        hako_convert_cpp2pdu(src.servo5_raw, dst.servo5_raw);
        // primitive convert
        hako_convert_cpp2pdu(src.servo6_raw, dst.servo6_raw);
        // primitive convert
        hako_convert_cpp2pdu(src.servo7_raw, dst.servo7_raw);
        // primitive convert
        hako_convert_cpp2pdu(src.servo8_raw, dst.servo8_raw);
        // primitive convert
        hako_convert_cpp2pdu(src.servo9_raw, dst.servo9_raw);
        // primitive convert
        hako_convert_cpp2pdu(src.servo10_raw, dst.servo10_raw);
        // primitive convert
        hako_convert_cpp2pdu(src.servo11_raw, dst.servo11_raw);
        // primitive convert
        hako_convert_cpp2pdu(src.servo12_raw, dst.servo12_raw);
        // primitive convert
        hako_convert_cpp2pdu(src.servo13_raw, dst.servo13_raw);
        // primitive convert
        hako_convert_cpp2pdu(src.servo14_raw, dst.servo14_raw);
        // primitive convert
        hako_convert_cpp2pdu(src.servo15_raw, dst.servo15_raw);
        // primitive convert
        hako_convert_cpp2pdu(src.servo16_raw, dst.servo16_raw);
    } catch (const std::runtime_error& e) {
        std::cerr << "convertor error: " << e.what() << std::endl;
        return false;
    }
    (void)dynamic_memory;
    return true;
}

static inline int hako_convert_cpp2pdu_HakoSERVO_OUTPUT_RAW(HakoCpp_HakoSERVO_OUTPUT_RAW &src, Hako_HakoSERVO_OUTPUT_RAW** dst)
{
    PduDynamicMemory dynamic_memory;
    Hako_HakoSERVO_OUTPUT_RAW out;
    if (!cpp_cpp2pdu_HakoSERVO_OUTPUT_RAW(src, out, dynamic_memory)) {
        return -1;
    }
    int heap_size = dynamic_memory.get_total_size();
    void* base_ptr = hako_create_empty_pdu(sizeof(Hako_HakoSERVO_OUTPUT_RAW), heap_size);
    if (base_ptr == nullptr) {
        return -1;
    }
    // Copy out on base data
    memcpy(base_ptr, (void*)&out, sizeof(Hako_HakoSERVO_OUTPUT_RAW));

    // Copy dynamic part and set offsets
    void* heap_ptr = hako_get_heap_ptr_pdu(base_ptr);
    dynamic_memory.copy_to_pdu((char*)heap_ptr);

    *dst = (Hako_HakoSERVO_OUTPUT_RAW*)base_ptr;
    return hako_get_pdu_meta_data(base_ptr)->total_size;
}

static inline Hako_HakoSERVO_OUTPUT_RAW* hako_create_empty_pdu_HakoSERVO_OUTPUT_RAW(int heap_size)
{
    // Allocate PDU memory
    char* base_ptr = (char*)hako_create_empty_pdu(sizeof(Hako_HakoSERVO_OUTPUT_RAW), heap_size);
    if (base_ptr == nullptr) {
        return nullptr;
    }
    return (Hako_HakoSERVO_OUTPUT_RAW*)base_ptr;
}
namespace hako::pdu::msgs::hako_mavlink2_msgs
{
class HakoSERVO_OUTPUT_RAW
{
public:
    HakoSERVO_OUTPUT_RAW() = default;
    ~HakoSERVO_OUTPUT_RAW() = default;

    bool pdu2cpp(char* top_ptr, HakoCpp_HakoSERVO_OUTPUT_RAW& cppData)
    {
        char* base_ptr = (char*)hako_get_base_ptr_pdu((void*)top_ptr);
        if (base_ptr == nullptr) {
            std::cerr << "[ConvertorError][" << "HakoSERVO_OUTPUT_RAW" << "] hako_get_base_ptr_pdu returned null" << std::endl;
            return false;
        } 
        int ret = hako_convert_pdu2cpp_HakoSERVO_OUTPUT_RAW(*(Hako_HakoSERVO_OUTPUT_RAW*)base_ptr, cppData);
        if (ret != 0) {
            std::cerr << "[ConvertorError][" << "HakoSERVO_OUTPUT_RAW" << "] hako_convert_pdu2cpp returned " << ret << std::endl;
            return false;
        }
        return true;
    }

    int cpp2pdu(HakoCpp_HakoSERVO_OUTPUT_RAW& cppData, char* pdu_buffer, int buffer_len)
    {
        char* base_ptr = nullptr;
        int pdu_size = hako_convert_cpp2pdu_HakoSERVO_OUTPUT_RAW(cppData, (Hako_HakoSERVO_OUTPUT_RAW**)&base_ptr);
        if (pdu_size < 0) {
            std::cerr << "[ConvertorError][" << "HakoSERVO_OUTPUT_RAW" << "] hako_convert_cpp2pdu returned error code: " << pdu_size << std::endl;
            return -1;
        }
        if (pdu_size > buffer_len) {
            std::cerr << "[ConvertorError][" << "HakoSERVO_OUTPUT_RAW" << "] buffer too small. pdu_size=" << pdu_size << " buffer_len=" << buffer_len << std::endl;
            return -1;
        }
        void* top_ptr = hako_get_top_ptr_pdu((void*)base_ptr);
        if (top_ptr == nullptr) {
            std::cerr << "[ConvertorError][" << "HakoSERVO_OUTPUT_RAW" << "] hako_get_top_ptr_pdu returned null" << std::endl;
            return false;
        }
        memcpy(pdu_buffer, top_ptr, pdu_size);
        hako_destroy_pdu((void*)base_ptr);
        return pdu_size;
    }

private:
};
}


#endif /* _PDU_CPPTYPE_CONV_HAKO_hako_mavlink2_msgs_HakoSERVO_OUTPUT_RAW_HPP_ */
