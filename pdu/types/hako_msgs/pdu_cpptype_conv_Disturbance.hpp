#ifndef _PDU_CPPTYPE_CONV_HAKO_hako_msgs_Disturbance_HPP_
#define _PDU_CPPTYPE_CONV_HAKO_hako_msgs_Disturbance_HPP_

#include "pdu_primitive_ctypes.h"
#include "pdu_primitive_ctypes_conv.hpp"
#include "pdu_dynamic_memory.hpp"
/*
 * Dependent pdu data
 */
#include "hako_msgs/pdu_ctype_Disturbance.h"
/*
 * Dependent cpp pdu data
 */
#include "hako_msgs/pdu_cpptype_Disturbance.hpp"

/*
 * Dependent Convertors
 */
#include "hako_msgs/pdu_cpptype_conv_DisturbanceTemperature.hpp"

/***************************
 *
 * PDU ==> CPP PDU
 *
 ***************************/

static inline int cpp_pdu2cpp_Disturbance(const char* heap_ptr, Hako_Disturbance &src, HakoCpp_Disturbance &dst)
{
    // Struct convert
    cpp_pdu2cpp_DisturbanceTemperature(heap_ptr, src.d_temp, dst.d_temp);
    (void)heap_ptr;
    return 0;
}

static inline int hako_convert_pdu2cpp_Disturbance(Hako_Disturbance &src, HakoCpp_Disturbance &dst)
{
    void* base_ptr = (void*)&src;
    void* heap_ptr = hako_get_heap_ptr_pdu(base_ptr);
    // Validate magic number and version
    if (heap_ptr == nullptr) {
        return -1; // Invalid PDU metadata
    }
    else {
        return cpp_pdu2cpp_Disturbance((char*)heap_ptr, src, dst);
    }
}

/***************************
 *
 * CPP PDU ==> PDU
 *
 ***************************/

static inline bool cpp_cpp2pdu_Disturbance(HakoCpp_Disturbance &src, Hako_Disturbance &dst, PduDynamicMemory &dynamic_memory)
{
    try {
        // struct convert
        cpp_cpp2pdu_DisturbanceTemperature(src.d_temp, dst.d_temp, dynamic_memory);
    } catch (const std::runtime_error& e) {
        std::cerr << "convertor error: " << e.what() << std::endl;
        return false;
    }
    (void)dynamic_memory;
    return true;
}

static inline int hako_convert_cpp2pdu_Disturbance(HakoCpp_Disturbance &src, Hako_Disturbance** dst)
{
    PduDynamicMemory dynamic_memory;
    Hako_Disturbance out;
    if (!cpp_cpp2pdu_Disturbance(src, out, dynamic_memory)) {
        return -1;
    }
    int heap_size = dynamic_memory.get_total_size();
    void* base_ptr = hako_create_empty_pdu(sizeof(Hako_Disturbance), heap_size);
    if (base_ptr == nullptr) {
        return -1;
    }
    // Copy out on base data
    memcpy(base_ptr, (void*)&out, sizeof(Hako_Disturbance));

    // Copy dynamic part and set offsets
    void* heap_ptr = hako_get_heap_ptr_pdu(base_ptr);
    dynamic_memory.copy_to_pdu((char*)heap_ptr);

    *dst = (Hako_Disturbance*)base_ptr;
    return hako_get_pdu_meta_data(base_ptr)->total_size;
}

static inline Hako_Disturbance* hako_create_empty_pdu_Disturbance(int heap_size)
{
    // Allocate PDU memory
    char* base_ptr = (char*)hako_create_empty_pdu(sizeof(Hako_Disturbance), heap_size);
    if (base_ptr == nullptr) {
        return nullptr;
    }
    return (Hako_Disturbance*)base_ptr;
}
#endif /* _PDU_CPPTYPE_CONV_HAKO_hako_msgs_Disturbance_HPP_ */
