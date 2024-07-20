#ifndef _PDU_CPPTYPE_CONV_HAKO_std_msgs_ByteMultiArray_HPP_
#define _PDU_CPPTYPE_CONV_HAKO_std_msgs_ByteMultiArray_HPP_

#include "pdu_primitive_ctypes.h"
#include "pdu_primitive_ctypes_conv.hpp"
#include "pdu_dynamic_memory.hpp"
/*
 * Dependent pdu data
 */
#include "std_msgs/pdu_ctype_ByteMultiArray.h"
/*
 * Dependent cpp pdu data
 */
#include "std_msgs/pdu_cpptype_ByteMultiArray.hpp"

/*
 * Dependent Convertors
 */
#include "std_msgs/pdu_cpptype_conv_MultiArrayDimension.hpp"
#include "std_msgs/pdu_cpptype_conv_MultiArrayLayout.hpp"

/***************************
 *
 * PDU ==> CPP PDU
 *
 ***************************/
static inline int cpp_pdu2cpp_struct_array_ByteMultiArray_data(const char* heap_ptr, Hako_ByteMultiArray &src, HakoCpp_ByteMultiArray &dst)
{
    // Convert using len and off
    int offset = src._data_off;
    int length = src._data_len;
    if (length > 0) {
        dst.data.resize(length);
        Hako_byte *temp_struct_ptr = (Hako_byte *)(heap_ptr + offset);
        for (int i = 0; i < length; ++i) {
            cpp_pdu2cpp_byte(heap_ptr, *temp_struct_ptr, dst.data[i]);
            temp_struct_ptr++;
        }
    }
    return 0;
}

static inline int cpp_pdu2cpp_ByteMultiArray(const char* heap_ptr, Hako_ByteMultiArray &src, HakoCpp_ByteMultiArray &dst)
{
    // Struct convert
    cpp_pdu2cpp_MultiArrayLayout(heap_ptr, src.layout, dst.layout);
    // struct array convertor
    cpp_pdu2cpp_struct_array_ByteMultiArray_data(heap_ptr, src, dst);
    (void)heap_ptr;
    return 0;
}

static inline int hako_convert_pdu2cpp_ByteMultiArray(Hako_ByteMultiArray &src, HakoCpp_ByteMultiArray &dst)
{
    void* base_ptr = (void*)&src;
    void* heap_ptr = hako_get_heap_ptr_pdu(base_ptr);
    // Validate magic number and version
    if (heap_ptr == nullptr) {
        return -1; // Invalid PDU metadata
    }
    else {
        return cpp_pdu2cpp_ByteMultiArray((char*)heap_ptr, src, dst);
    }
}

/***************************
 *
 * CPP PDU ==> PDU
 *
 ***************************/
static inline bool cpp_cpp2pdu_struct_array_ByteMultiArray_data(HakoCpp_ByteMultiArray &src, Hako_ByteMultiArray &dst, PduDynamicMemory &dynamic_memory)
{
    // array struct
    dst._data_len = src.data.size();
    if (dst._data_len > 0) {
        Hako_byte* temp_struct_ptr = (Hako_byte*)dynamic_memory.allocate(dst._data_len, sizeof(Hako_byte));
        dst._data_off = dynamic_memory.get_offset(temp_struct_ptr);
        for (int i = 0; i < dst._data_len; ++i) {
            cpp_cpp2pdu_byte(src.data[i], *temp_struct_ptr, dynamic_memory);
            temp_struct_ptr++;
        }
    }
    else {
        dst._data_off = dynamic_memory.get_total_size();
    }
    return true;
}

static inline bool cpp_cpp2pdu_ByteMultiArray(HakoCpp_ByteMultiArray &src, Hako_ByteMultiArray &dst, PduDynamicMemory &dynamic_memory)
{
    try {
        // struct convert
        cpp_cpp2pdu_MultiArrayLayout(src.layout, dst.layout, dynamic_memory);
        //struct array convert
        cpp_cpp2pdu_struct_array_ByteMultiArray_data(src, dst, dynamic_memory);
    } catch (const std::runtime_error& e) {
        std::cerr << "convertor error: " << e.what() << std::endl;
        return false;
    }
    (void)dynamic_memory;
    return true;
}

static inline int hako_convert_cpp2pdu_ByteMultiArray(HakoCpp_ByteMultiArray &src, Hako_ByteMultiArray** dst)
{
    PduDynamicMemory dynamic_memory;
    Hako_ByteMultiArray out;
    if (!cpp_cpp2pdu_ByteMultiArray(src, out, dynamic_memory)) {
        return -1;
    }
    int heap_size = dynamic_memory.get_total_size();
    void* base_ptr = hako_create_empty_pdu(sizeof(Hako_ByteMultiArray), heap_size);
    if (base_ptr == nullptr) {
        return -1;
    }
    // Copy out on base data
    memcpy(base_ptr, (void*)&out, sizeof(Hako_ByteMultiArray));

    // Copy dynamic part and set offsets
    void* heap_ptr = hako_get_heap_ptr_pdu(base_ptr);
    dynamic_memory.copy_to_pdu((char*)heap_ptr);

    *dst = (Hako_ByteMultiArray*)base_ptr;
    return hako_get_pdu_meta_data(base_ptr)->total_size;
}

static inline Hako_ByteMultiArray* hako_create_empty_pdu_ByteMultiArray(int heap_size)
{
    // Allocate PDU memory
    char* base_ptr = (char*)hako_create_empty_pdu(sizeof(Hako_ByteMultiArray), heap_size);
    if (base_ptr == nullptr) {
        return nullptr;
    }
    return (Hako_ByteMultiArray*)base_ptr;
}
#endif /* _PDU_CPPTYPE_CONV_HAKO_std_msgs_ByteMultiArray_HPP_ */
