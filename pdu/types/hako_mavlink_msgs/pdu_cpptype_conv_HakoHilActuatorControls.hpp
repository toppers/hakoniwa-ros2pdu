#ifndef _PDU_CPPTYPE_CONV_HAKO_hako_mavlink_msgs_HakoHilActuatorControls_HPP_
#define _PDU_CPPTYPE_CONV_HAKO_hako_mavlink_msgs_HakoHilActuatorControls_HPP_

#include "pdu_primitive_ctypes.h"
#include "pdu_primitive_ctypes_conv.hpp"
#include "pdu_dynamic_memory.hpp"
/*
 * Dependent pdu data
 */
#include "hako_mavlink_msgs/pdu_ctype_HakoHilActuatorControls.h"
/*
 * Dependent cpp pdu data
 */
#include "hako_mavlink_msgs/pdu_cpptype_HakoHilActuatorControls.hpp"

/*
 * Dependent Convertors
 */

/***************************
 *
 * PDU ==> CPP PDU
 *
 ***************************/
static inline int cpp_pdu2cpp_primitive_array_HakoHilActuatorControls_controls(const char* heap_ptr, Hako_HakoHilActuatorControls &src, HakoCpp_HakoHilActuatorControls &dst)
{
    // Fixed size array convertor
    (void)heap_ptr;
    for (int i = 0; i < 16; ++i) {
        hako_convert_pdu2cpp(src.controls[i], dst.controls[i]);
    }
    return 0;
}

static inline int cpp_pdu2cpp_HakoHilActuatorControls(const char* heap_ptr, Hako_HakoHilActuatorControls &src, HakoCpp_HakoHilActuatorControls &dst)
{
    // primitive convert
    hako_convert_pdu2cpp(src.time_usec, dst.time_usec);
    // primitive array convertor
    cpp_pdu2cpp_primitive_array_HakoHilActuatorControls_controls(heap_ptr, src, dst);
    // primitive convert
    hako_convert_pdu2cpp(src.mode, dst.mode);
    // primitive convert
    hako_convert_pdu2cpp(src.flags, dst.flags);
    (void)heap_ptr;
    return 0;
}

static inline int hako_convert_pdu2cpp_HakoHilActuatorControls(Hako_HakoHilActuatorControls &src, HakoCpp_HakoHilActuatorControls &dst)
{
    void* base_ptr = (void*)&src;
    void* heap_ptr = hako_get_heap_ptr_pdu(base_ptr);
    // Validate magic number and version
    if (heap_ptr == nullptr) {
        return -1; // Invalid PDU metadata
    }
    else {
        return cpp_pdu2cpp_HakoHilActuatorControls((char*)heap_ptr, src, dst);
    }
}

/***************************
 *
 * CPP PDU ==> PDU
 *
 ***************************/
static inline bool cpp_cpp2pdu_primitive_array_HakoHilActuatorControls_controls(HakoCpp_HakoHilActuatorControls &src, Hako_HakoHilActuatorControls &dst, PduDynamicMemory &dynamic_memory)
{
    //Copy fixed array 16
    (void)dynamic_memory;
    (void)hako_convert_cpp2pdu_array(
        src.controls, src.controls.size(),
        dst.controls, M_ARRAY_SIZE(Hako_HakoHilActuatorControls, Hako_float32, controls));
    return true;
}

static inline bool cpp_cpp2pdu_HakoHilActuatorControls(HakoCpp_HakoHilActuatorControls &src, Hako_HakoHilActuatorControls &dst, PduDynamicMemory &dynamic_memory)
{
    try {
        // primitive convert
        hako_convert_cpp2pdu(src.time_usec, dst.time_usec);
        //primitive array copy
        cpp_cpp2pdu_primitive_array_HakoHilActuatorControls_controls(src, dst, dynamic_memory);
        // primitive convert
        hako_convert_cpp2pdu(src.mode, dst.mode);
        // primitive convert
        hako_convert_cpp2pdu(src.flags, dst.flags);
    } catch (const std::runtime_error& e) {
        std::cerr << "convertor error: " << e.what() << std::endl;
        return false;
    }
    (void)dynamic_memory;
    return true;
}

static inline int hako_convert_cpp2pdu_HakoHilActuatorControls(HakoCpp_HakoHilActuatorControls &src, Hako_HakoHilActuatorControls** dst)
{
    PduDynamicMemory dynamic_memory;
    Hako_HakoHilActuatorControls out;
    if (!cpp_cpp2pdu_HakoHilActuatorControls(src, out, dynamic_memory)) {
        return -1;
    }
    int heap_size = dynamic_memory.get_total_size();
    void* base_ptr = hako_create_empty_pdu(sizeof(Hako_HakoHilActuatorControls), heap_size);
    if (base_ptr == nullptr) {
        return -1;
    }
    // Copy out on base data
    memcpy(base_ptr, (void*)&out, sizeof(Hako_HakoHilActuatorControls));

    // Copy dynamic part and set offsets
    void* heap_ptr = hako_get_heap_ptr_pdu(base_ptr);
    dynamic_memory.copy_to_pdu((char*)heap_ptr);

    *dst = (Hako_HakoHilActuatorControls*)base_ptr;
    return hako_get_pdu_meta_data(base_ptr)->total_size;
}

static inline Hako_HakoHilActuatorControls* hako_create_empty_pdu_HakoHilActuatorControls(int heap_size)
{
    // Allocate PDU memory
    char* base_ptr = (char*)hako_create_empty_pdu(sizeof(Hako_HakoHilActuatorControls), heap_size);
    if (base_ptr == nullptr) {
        return nullptr;
    }
    return (Hako_HakoHilActuatorControls*)base_ptr;
}
#endif /* _PDU_CPPTYPE_CONV_HAKO_hako_mavlink_msgs_HakoHilActuatorControls_HPP_ */
