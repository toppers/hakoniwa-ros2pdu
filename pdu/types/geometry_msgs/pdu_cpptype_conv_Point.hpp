#ifndef _PDU_CPPTYPE_CONV_HAKO_geometry_msgs_Point_HPP_
#define _PDU_CPPTYPE_CONV_HAKO_geometry_msgs_Point_HPP_

#include "pdu_primitive_ctypes.h"
#include "pdu_primitive_ctypes_conv.hpp"
#include "pdu_dynamic_memory.hpp"
/*
 * Dependent pdu data
 */
#include "geometry_msgs/pdu_ctype_Point.h"
/*
 * Dependent cpp pdu data
 */
#include "geometry_msgs/pdu_cpptype_Point.hpp"

/*
 * Dependent Convertors
 */

/***************************
 *
 * PDU ==> CPP PDU
 *
 ***************************/

static inline int cpp_pdu2cpp_Point(const char* heap_ptr, Hako_Point &src, HakoCpp_Point &dst)
{
    // primitive convert
    hako_convert_pdu2cpp(src.x, dst.x);
    // primitive convert
    hako_convert_pdu2cpp(src.y, dst.y);
    // primitive convert
    hako_convert_pdu2cpp(src.z, dst.z);
    (void)heap_ptr;
    return 0;
}

static inline int hako_convert_pdu2cpp_Point(Hako_Point &src, HakoCpp_Point &dst)
{
    void* base_ptr = (void*)&src;
    void* heap_ptr = hako_get_heap_ptr_pdu(base_ptr);
    // Validate magic number and version
    if (heap_ptr == nullptr) {
        return -1; // Invalid PDU metadata
    }
    else {
        return cpp_pdu2cpp_Point((char*)heap_ptr, src, dst);
    }
}

/***************************
 *
 * CPP PDU ==> PDU
 *
 ***************************/

static inline bool cpp_cpp2pdu_Point(HakoCpp_Point &src, Hako_Point &dst, PduDynamicMemory &dynamic_memory)
{
    try {
        // primitive convert
        hako_convert_cpp2pdu(src.x, dst.x);
        // primitive convert
        hako_convert_cpp2pdu(src.y, dst.y);
        // primitive convert
        hako_convert_cpp2pdu(src.z, dst.z);
    } catch (const std::runtime_error& e) {
        std::cerr << "convertor error: " << e.what() << std::endl;
        return false;
    }
    (void)dynamic_memory;
    return true;
}

static inline int hako_convert_cpp2pdu_Point(HakoCpp_Point &src, Hako_Point** dst)
{
    PduDynamicMemory dynamic_memory;
    Hako_Point out;
    if (!cpp_cpp2pdu_Point(src, out, dynamic_memory)) {
        return -1;
    }
    int heap_size = dynamic_memory.get_total_size();
    void* base_ptr = hako_create_empty_pdu(sizeof(Hako_Point), heap_size);
    if (base_ptr == nullptr) {
        return -1;
    }
    // Copy out on base data
    memcpy(base_ptr, (void*)&out, sizeof(Hako_Point));

    // Copy dynamic part and set offsets
    void* heap_ptr = hako_get_heap_ptr_pdu(base_ptr);
    dynamic_memory.copy_to_pdu((char*)heap_ptr);

    *dst = (Hako_Point*)base_ptr;
    return hako_get_pdu_meta_data(base_ptr)->total_size;
}

static inline Hako_Point* hako_create_empty_pdu_Point(int heap_size)
{
    // Allocate PDU memory
    char* base_ptr = (char*)hako_create_empty_pdu(sizeof(Hako_Point), heap_size);
    if (base_ptr == nullptr) {
        return nullptr;
    }
    return (Hako_Point*)base_ptr;
}
#endif /* _PDU_CPPTYPE_CONV_HAKO_geometry_msgs_Point_HPP_ */
