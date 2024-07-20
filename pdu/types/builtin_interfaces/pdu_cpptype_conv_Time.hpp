#ifndef _PDU_CPPTYPE_CONV_HAKO_builtin_interfaces_Time_HPP_
#define _PDU_CPPTYPE_CONV_HAKO_builtin_interfaces_Time_HPP_

#include "pdu_primitive_ctypes.h"
#include "pdu_primitive_ctypes_conv.hpp"
#include "pdu_dynamic_memory.hpp"
/*
 * Dependent pdu data
 */
#include "builtin_interfaces/pdu_ctype_Time.h"
/*
 * Dependent cpp pdu data
 */
#include "builtin_interfaces/pdu_cpptype_Time.hpp"

/*
 * Dependent Convertors
 */

/***************************
 *
 * PDU ==> CPP PDU
 *
 ***************************/

static inline int cpp_pdu2cpp_Time(const char* heap_ptr, Hako_Time &src, HakoCpp_Time &dst)
{
    // primitive convert
    hako_convert_pdu2cpp(src.sec, dst.sec);
    // primitive convert
    hako_convert_pdu2cpp(src.nanosec, dst.nanosec);
    (void)heap_ptr;
    return 0;
}

static inline int hako_convert_pdu2cpp_Time(Hako_Time &src, HakoCpp_Time &dst)
{
    void* base_ptr = (void*)&src;
    void* heap_ptr = hako_get_heap_ptr_pdu(base_ptr);
    // Validate magic number and version
    if (heap_ptr == nullptr) {
        return -1; // Invalid PDU metadata
    }
    else {
        return cpp_pdu2cpp_Time((char*)heap_ptr, src, dst);
    }
}

/***************************
 *
 * CPP PDU ==> PDU
 *
 ***************************/

static inline bool cpp_cpp2pdu_Time(HakoCpp_Time &src, Hako_Time &dst, PduDynamicMemory &dynamic_memory)
{
    try {
        // primitive convert
        hako_convert_cpp2pdu(src.sec, dst.sec);
        // primitive convert
        hako_convert_cpp2pdu(src.nanosec, dst.nanosec);
    } catch (const std::runtime_error& e) {
        std::cerr << "convertor error: " << e.what() << std::endl;
        return false;
    }
    (void)dynamic_memory;
    return true;
}

static inline int hako_convert_cpp2pdu_Time(HakoCpp_Time &src, Hako_Time** dst)
{
    PduDynamicMemory dynamic_memory;
    Hako_Time out;
    if (!cpp_cpp2pdu_Time(src, out, dynamic_memory)) {
        return -1;
    }
    int heap_size = dynamic_memory.get_total_size();
    void* base_ptr = hako_create_empty_pdu(sizeof(Hako_Time), heap_size);
    if (base_ptr == nullptr) {
        return -1;
    }
    // Copy out on base data
    memcpy(base_ptr, (void*)&out, sizeof(Hako_Time));

    // Copy dynamic part and set offsets
    void* heap_ptr = hako_get_heap_ptr_pdu(base_ptr);
    dynamic_memory.copy_to_pdu((char*)heap_ptr);

    *dst = (Hako_Time*)base_ptr;
    return hako_get_pdu_meta_data(base_ptr)->total_size;
}

static inline Hako_Time* hako_create_empty_pdu_Time(int heap_size)
{
    // Allocate PDU memory
    char* base_ptr = (char*)hako_create_empty_pdu(sizeof(Hako_Time), heap_size);
    if (base_ptr == nullptr) {
        return nullptr;
    }
    return (Hako_Time*)base_ptr;
}
#endif /* _PDU_CPPTYPE_CONV_HAKO_builtin_interfaces_Time_HPP_ */
