#ifndef _PDU_CPPTYPE_CONV_HAKO_hako_msgs_HakoCmdCameraMove_HPP_
#define _PDU_CPPTYPE_CONV_HAKO_hako_msgs_HakoCmdCameraMove_HPP_

#include "pdu_primitive_ctypes.h"
#include "pdu_primitive_ctypes_conv.hpp"
#include "pdu_dynamic_memory.hpp"
/*
 * Dependent pdu data
 */
#include "hako_msgs/pdu_ctype_HakoCmdCameraMove.h"
/*
 * Dependent cpp pdu data
 */
#include "hako_msgs/pdu_cpptype_HakoCmdCameraMove.hpp"

/*
 * Dependent Convertors
 */
#include "geometry_msgs/pdu_cpptype_conv_Vector3.hpp"
#include "hako_msgs/pdu_cpptype_conv_HakoCmdHeader.hpp"

/***************************
 *
 * PDU ==> CPP PDU
 *
 ***************************/

static inline int cpp_pdu2cpp_HakoCmdCameraMove(const char* heap_ptr, Hako_HakoCmdCameraMove &src, HakoCpp_HakoCmdCameraMove &dst)
{
    // Struct convert
    cpp_pdu2cpp_HakoCmdHeader(heap_ptr, src.header, dst.header);
    // primitive convert
    hako_convert_pdu2cpp(src.request_id, dst.request_id);
    // Struct convert
    cpp_pdu2cpp_Vector3(heap_ptr, src.angle, dst.angle);
    (void)heap_ptr;
    return 0;
}

static inline int hako_convert_pdu2cpp_HakoCmdCameraMove(Hako_HakoCmdCameraMove &src, HakoCpp_HakoCmdCameraMove &dst)
{
    void* base_ptr = (void*)&src;
    void* heap_ptr = hako_get_heap_ptr_pdu(base_ptr);
    // Validate magic number and version
    if (heap_ptr == nullptr) {
        return -1; // Invalid PDU metadata
    }
    else {
        return cpp_pdu2cpp_HakoCmdCameraMove((char*)heap_ptr, src, dst);
    }
}

/***************************
 *
 * CPP PDU ==> PDU
 *
 ***************************/

static inline bool cpp_cpp2pdu_HakoCmdCameraMove(HakoCpp_HakoCmdCameraMove &src, Hako_HakoCmdCameraMove &dst, PduDynamicMemory &dynamic_memory)
{
    try {
        // struct convert
        cpp_cpp2pdu_HakoCmdHeader(src.header, dst.header, dynamic_memory);
        // primitive convert
        hako_convert_cpp2pdu(src.request_id, dst.request_id);
        // struct convert
        cpp_cpp2pdu_Vector3(src.angle, dst.angle, dynamic_memory);
    } catch (const std::runtime_error& e) {
        std::cerr << "convertor error: " << e.what() << std::endl;
        return false;
    }
    (void)dynamic_memory;
    return true;
}

static inline int hako_convert_cpp2pdu_HakoCmdCameraMove(HakoCpp_HakoCmdCameraMove &src, Hako_HakoCmdCameraMove** dst)
{
    PduDynamicMemory dynamic_memory;
    Hako_HakoCmdCameraMove out;
    if (!cpp_cpp2pdu_HakoCmdCameraMove(src, out, dynamic_memory)) {
        return -1;
    }
    int heap_size = dynamic_memory.get_total_size();
    void* base_ptr = hako_create_empty_pdu(sizeof(Hako_HakoCmdCameraMove), heap_size);
    if (base_ptr == nullptr) {
        return -1;
    }
    // Copy out on base data
    memcpy(base_ptr, (void*)&out, sizeof(Hako_HakoCmdCameraMove));

    // Copy dynamic part and set offsets
    void* heap_ptr = hako_get_heap_ptr_pdu(base_ptr);
    dynamic_memory.copy_to_pdu((char*)heap_ptr);

    *dst = (Hako_HakoCmdCameraMove*)base_ptr;
    return hako_get_pdu_meta_data(base_ptr)->total_size;
}

static inline Hako_HakoCmdCameraMove* hako_create_empty_pdu_HakoCmdCameraMove(int heap_size)
{
    // Allocate PDU memory
    char* base_ptr = (char*)hako_create_empty_pdu(sizeof(Hako_HakoCmdCameraMove), heap_size);
    if (base_ptr == nullptr) {
        return nullptr;
    }
    return (Hako_HakoCmdCameraMove*)base_ptr;
}
#endif /* _PDU_CPPTYPE_CONV_HAKO_hako_msgs_HakoCmdCameraMove_HPP_ */
