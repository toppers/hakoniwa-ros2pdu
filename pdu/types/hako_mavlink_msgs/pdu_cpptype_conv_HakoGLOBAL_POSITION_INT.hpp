#ifndef _PDU_CPPTYPE_CONV_HAKO_hako_mavlink_msgs_HakoGLOBAL_POSITION_INT_HPP_
#define _PDU_CPPTYPE_CONV_HAKO_hako_mavlink_msgs_HakoGLOBAL_POSITION_INT_HPP_

#include "pdu_primitive_ctypes.h"
#include "pdu_primitive_ctypes_conv.hpp"
#include "pdu_dynamic_memory.hpp"
/*
 * Dependent pdu data
 */
#include "hako_mavlink_msgs/pdu_ctype_HakoGLOBAL_POSITION_INT.h"
/*
 * Dependent cpp pdu data
 */
#include "hako_mavlink_msgs/pdu_cpptype_HakoGLOBAL_POSITION_INT.hpp"

/*
 * Dependent Convertors
 */

/***************************
 *
 * PDU ==> CPP PDU
 *
 ***************************/

static inline int cpp_pdu2cpp_HakoGLOBAL_POSITION_INT(const char* heap_ptr, Hako_HakoGLOBAL_POSITION_INT &src, HakoCpp_HakoGLOBAL_POSITION_INT &dst)
{
    // primitive convert
    hako_convert_pdu2cpp(src.time_boot_ms, dst.time_boot_ms);
    // primitive convert
    hako_convert_pdu2cpp(src.lat, dst.lat);
    // primitive convert
    hako_convert_pdu2cpp(src.lon, dst.lon);
    // primitive convert
    hako_convert_pdu2cpp(src.alt, dst.alt);
    // primitive convert
    hako_convert_pdu2cpp(src.relative_alt, dst.relative_alt);
    // primitive convert
    hako_convert_pdu2cpp(src.vx, dst.vx);
    // primitive convert
    hako_convert_pdu2cpp(src.vy, dst.vy);
    // primitive convert
    hako_convert_pdu2cpp(src.vz, dst.vz);
    // primitive convert
    hako_convert_pdu2cpp(src.hdg, dst.hdg);
    (void)heap_ptr;
    return 0;
}

static inline int hako_convert_pdu2cpp_HakoGLOBAL_POSITION_INT(Hako_HakoGLOBAL_POSITION_INT &src, HakoCpp_HakoGLOBAL_POSITION_INT &dst)
{
    void* base_ptr = (void*)&src;
    void* heap_ptr = hako_get_heap_ptr_pdu(base_ptr);
    // Validate magic number and version
    if (heap_ptr == nullptr) {
        return -1; // Invalid PDU metadata
    }
    else {
        return cpp_pdu2cpp_HakoGLOBAL_POSITION_INT((char*)heap_ptr, src, dst);
    }
}

/***************************
 *
 * CPP PDU ==> PDU
 *
 ***************************/

static inline bool cpp_cpp2pdu_HakoGLOBAL_POSITION_INT(HakoCpp_HakoGLOBAL_POSITION_INT &src, Hako_HakoGLOBAL_POSITION_INT &dst, PduDynamicMemory &dynamic_memory)
{
    try {
        // primitive convert
        hako_convert_cpp2pdu(src.time_boot_ms, dst.time_boot_ms);
        // primitive convert
        hako_convert_cpp2pdu(src.lat, dst.lat);
        // primitive convert
        hako_convert_cpp2pdu(src.lon, dst.lon);
        // primitive convert
        hako_convert_cpp2pdu(src.alt, dst.alt);
        // primitive convert
        hako_convert_cpp2pdu(src.relative_alt, dst.relative_alt);
        // primitive convert
        hako_convert_cpp2pdu(src.vx, dst.vx);
        // primitive convert
        hako_convert_cpp2pdu(src.vy, dst.vy);
        // primitive convert
        hako_convert_cpp2pdu(src.vz, dst.vz);
        // primitive convert
        hako_convert_cpp2pdu(src.hdg, dst.hdg);
    } catch (const std::runtime_error& e) {
        std::cerr << "convertor error: " << e.what() << std::endl;
        return false;
    }
    (void)dynamic_memory;
    return true;
}

static inline int hako_convert_cpp2pdu_HakoGLOBAL_POSITION_INT(HakoCpp_HakoGLOBAL_POSITION_INT &src, Hako_HakoGLOBAL_POSITION_INT** dst)
{
    PduDynamicMemory dynamic_memory;
    Hako_HakoGLOBAL_POSITION_INT out;
    if (!cpp_cpp2pdu_HakoGLOBAL_POSITION_INT(src, out, dynamic_memory)) {
        return -1;
    }
    int heap_size = dynamic_memory.get_total_size();
    void* base_ptr = hako_create_empty_pdu(sizeof(Hako_HakoGLOBAL_POSITION_INT), heap_size);
    if (base_ptr == nullptr) {
        return -1;
    }
    // Copy out on base data
    memcpy(base_ptr, (void*)&out, sizeof(Hako_HakoGLOBAL_POSITION_INT));

    // Copy dynamic part and set offsets
    void* heap_ptr = hako_get_heap_ptr_pdu(base_ptr);
    dynamic_memory.copy_to_pdu((char*)heap_ptr);

    *dst = (Hako_HakoGLOBAL_POSITION_INT*)base_ptr;
    return hako_get_pdu_meta_data(base_ptr)->total_size;
}

static inline Hako_HakoGLOBAL_POSITION_INT* hako_create_empty_pdu_HakoGLOBAL_POSITION_INT(int heap_size)
{
    // Allocate PDU memory
    char* base_ptr = (char*)hako_create_empty_pdu(sizeof(Hako_HakoGLOBAL_POSITION_INT), heap_size);
    if (base_ptr == nullptr) {
        return nullptr;
    }
    return (Hako_HakoGLOBAL_POSITION_INT*)base_ptr;
}
#endif /* _PDU_CPPTYPE_CONV_HAKO_hako_mavlink_msgs_HakoGLOBAL_POSITION_INT_HPP_ */
