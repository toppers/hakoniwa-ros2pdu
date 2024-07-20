#ifndef _PDU_CPPTYPE_CONV_HAKO_can_msgs_HakoCan_HPP_
#define _PDU_CPPTYPE_CONV_HAKO_can_msgs_HakoCan_HPP_

#include "pdu_primitive_ctypes.h"
#include "pdu_primitive_ctypes_conv.hpp"
#include "pdu_dynamic_memory.hpp"
/*
 * Dependent pdu data
 */
#include "can_msgs/pdu_ctype_HakoCan.h"
/*
 * Dependent cpp pdu data
 */
#include "can_msgs/pdu_cpptype_HakoCan.hpp"

/*
 * Dependent Convertors
 */
#include "can_msgs/pdu_cpptype_conv_HakoCanBody.hpp"
#include "can_msgs/pdu_cpptype_conv_HakoCanHead.hpp"

/***************************
 *
 * PDU ==> CPP PDU
 *
 ***************************/

static inline int cpp_pdu2cpp_HakoCan(const char* heap_ptr, Hako_HakoCan &src, HakoCpp_HakoCan &dst)
{
    // Struct convert
    cpp_pdu2cpp_HakoCanHead(heap_ptr, src.head, dst.head);
    // Struct convert
    cpp_pdu2cpp_HakoCanBody(heap_ptr, src.body, dst.body);
    (void)heap_ptr;
    return 0;
}

static inline int hako_convert_pdu2cpp_HakoCan(Hako_HakoCan &src, HakoCpp_HakoCan &dst)
{
    void* base_ptr = (void*)&src;
    void* heap_ptr = hako_get_heap_ptr_pdu(base_ptr);
    // Validate magic number and version
    if (heap_ptr == nullptr) {
        return -1; // Invalid PDU metadata
    }
    else {
        return cpp_pdu2cpp_HakoCan((char*)heap_ptr, src, dst);
    }
}

/***************************
 *
 * CPP PDU ==> PDU
 *
 ***************************/

static inline bool cpp_cpp2pdu_HakoCan(HakoCpp_HakoCan &src, Hako_HakoCan &dst, PduDynamicMemory &dynamic_memory)
{
    try {
        // struct convert
        cpp_cpp2pdu_HakoCanHead(src.head, dst.head, dynamic_memory);
        // struct convert
        cpp_cpp2pdu_HakoCanBody(src.body, dst.body, dynamic_memory);
    } catch (const std::runtime_error& e) {
        std::cerr << "convertor error: " << e.what() << std::endl;
        return false;
    }
    (void)dynamic_memory;
    return true;
}

static inline int hako_convert_cpp2pdu_HakoCan(HakoCpp_HakoCan &src, Hako_HakoCan** dst)
{
    PduDynamicMemory dynamic_memory;
    Hako_HakoCan out;
    if (!cpp_cpp2pdu_HakoCan(src, out, dynamic_memory)) {
        return -1;
    }
    int heap_size = dynamic_memory.get_total_size();
    void* base_ptr = hako_create_empty_pdu(sizeof(Hako_HakoCan), heap_size);
    if (base_ptr == nullptr) {
        return -1;
    }
    // Copy out on base data
    memcpy(base_ptr, (void*)&out, sizeof(Hako_HakoCan));

    // Copy dynamic part and set offsets
    void* heap_ptr = hako_get_heap_ptr_pdu(base_ptr);
    dynamic_memory.copy_to_pdu((char*)heap_ptr);

    *dst = (Hako_HakoCan*)base_ptr;
    return hako_get_pdu_meta_data(base_ptr)->total_size;
}

static inline Hako_HakoCan* hako_create_empty_pdu_HakoCan(int heap_size)
{
    // Allocate PDU memory
    char* base_ptr = (char*)hako_create_empty_pdu(sizeof(Hako_HakoCan), heap_size);
    if (base_ptr == nullptr) {
        return nullptr;
    }
    return (Hako_HakoCan*)base_ptr;
}
#endif /* _PDU_CPPTYPE_CONV_HAKO_can_msgs_HakoCan_HPP_ */
