#ifndef _PDU_CPPTYPE_CONV_HAKO_std_msgs_Int32MultiArray_HPP_
#define _PDU_CPPTYPE_CONV_HAKO_std_msgs_Int32MultiArray_HPP_

#include "pdu_primitive_ctypes.h"
#include "pdu_primitive_ctypes_conv.hpp"
#include "pdu_dynamic_memory.hpp"
/*
 * Dependent pdu data
 */
#include "std_msgs/pdu_ctype_Int32MultiArray.h"
/*
 * Dependent cpp pdu data
 */
#include "std_msgs/pdu_cpptype_Int32MultiArray.hpp"

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
static inline int cpp_pdu2cpp_primitive_array_Int32MultiArray_data(const char* heap_ptr, Hako_Int32MultiArray &src, HakoCpp_Int32MultiArray &dst)
{
    // Convert using len and off
    int offset = src._data_off;
    int length = src._data_len;
    if (length > 0) {
        dst.data.resize(length);
        memcpy(dst.data.data(), heap_ptr + offset, length * sizeof(Hako_int32));
    }
    return 0;
}

static inline int cpp_pdu2cpp_Int32MultiArray(const char* heap_ptr, Hako_Int32MultiArray &src, HakoCpp_Int32MultiArray &dst)
{
    // Struct convert
    cpp_pdu2cpp_MultiArrayLayout(heap_ptr, src.layout, dst.layout);
    // primitive array convertor
    cpp_pdu2cpp_primitive_array_Int32MultiArray_data(heap_ptr, src, dst);
    (void)heap_ptr;
    return 0;
}

static inline int hako_convert_pdu2cpp_Int32MultiArray(Hako_Int32MultiArray &src, HakoCpp_Int32MultiArray &dst)
{
    void* base_ptr = (void*)&src;
    void* heap_ptr = hako_get_heap_ptr_pdu(base_ptr);
    // Validate magic number and version
    if (heap_ptr == nullptr) {
        return -1; // Invalid PDU metadata
    }
    else {
        return cpp_pdu2cpp_Int32MultiArray((char*)heap_ptr, src, dst);
    }
}

/***************************
 *
 * CPP PDU ==> PDU
 *
 ***************************/
static inline bool cpp_cpp2pdu_primitive_array_Int32MultiArray_data(HakoCpp_Int32MultiArray &src, Hako_Int32MultiArray &dst, PduDynamicMemory &dynamic_memory)
{
    //Copy varray
    dst._data_len = src.data.size();
    if (dst._data_len > 0) {
        void* temp_ptr = dynamic_memory.allocate(dst._data_len, sizeof(Hako_int32));
        memcpy(temp_ptr, src.data.data(), dst._data_len * sizeof(Hako_int32));
        dst._data_off = dynamic_memory.get_offset(temp_ptr);
    }
    else {
        dst._data_off = dynamic_memory.get_total_size();
    }
    return true;
}

static inline bool cpp_cpp2pdu_Int32MultiArray(HakoCpp_Int32MultiArray &src, Hako_Int32MultiArray &dst, PduDynamicMemory &dynamic_memory)
{
    try {
        // struct convert
        cpp_cpp2pdu_MultiArrayLayout(src.layout, dst.layout, dynamic_memory);
        //primitive array copy
        cpp_cpp2pdu_primitive_array_Int32MultiArray_data(src, dst, dynamic_memory);
    } catch (const std::runtime_error& e) {
        std::cerr << "convertor error: " << e.what() << std::endl;
        return false;
    }
    (void)dynamic_memory;
    return true;
}

static inline int hako_convert_cpp2pdu_Int32MultiArray(HakoCpp_Int32MultiArray &src, Hako_Int32MultiArray** dst)
{
    PduDynamicMemory dynamic_memory;
    Hako_Int32MultiArray out;
    if (!cpp_cpp2pdu_Int32MultiArray(src, out, dynamic_memory)) {
        return -1;
    }
    int heap_size = dynamic_memory.get_total_size();
    void* base_ptr = hako_create_empty_pdu(sizeof(Hako_Int32MultiArray), heap_size);
    if (base_ptr == nullptr) {
        return -1;
    }
    // Copy out on base data
    memcpy(base_ptr, (void*)&out, sizeof(Hako_Int32MultiArray));

    // Copy dynamic part and set offsets
    void* heap_ptr = hako_get_heap_ptr_pdu(base_ptr);
    dynamic_memory.copy_to_pdu((char*)heap_ptr);

    *dst = (Hako_Int32MultiArray*)base_ptr;
    return hako_get_pdu_meta_data(base_ptr)->total_size;
}

static inline Hako_Int32MultiArray* hako_create_empty_pdu_Int32MultiArray(int heap_size)
{
    // Allocate PDU memory
    char* base_ptr = (char*)hako_create_empty_pdu(sizeof(Hako_Int32MultiArray), heap_size);
    if (base_ptr == nullptr) {
        return nullptr;
    }
    return (Hako_Int32MultiArray*)base_ptr;
}
namespace hako::pdu::msgs::std_msgs
{
class Int32MultiArray
{
public:
    Int32MultiArray() = default;
    ~Int32MultiArray() = default;

    bool pdu2cpp(char* top_ptr, HakoCpp_Int32MultiArray& cppData)
    {
        char* base_ptr = (char*)hako_get_base_ptr_pdu((void*)top_ptr);
        if (base_ptr == nullptr) {
            std::cerr << "[ConvertorError][" << "Int32MultiArray" << "] hako_get_base_ptr_pdu returned null" << std::endl;
            return false;
        } 
        int ret = hako_convert_pdu2cpp_Int32MultiArray(*(Hako_Int32MultiArray*)base_ptr, cppData);
        if (ret != 0) {
            std::cerr << "[ConvertorError][" << "Int32MultiArray" << "] hako_convert_pdu2cpp returned " << ret << std::endl;
            return false;
        }
        return true;
    }

    int cpp2pdu(HakoCpp_Int32MultiArray& cppData, char* pdu_buffer, int buffer_len)
    {
        char* base_ptr = nullptr;
        int pdu_size = hako_convert_cpp2pdu_Int32MultiArray(cppData, (Hako_Int32MultiArray**)&base_ptr);
        if (pdu_size < 0) {
            std::cerr << "[ConvertorError][" << "Int32MultiArray" << "] hako_convert_cpp2pdu returned error code: " << pdu_size << std::endl;
            return -1;
        }
        if (pdu_size > buffer_len) {
            std::cerr << "[ConvertorError][" << "Int32MultiArray" << "] buffer too small. pdu_size=" << pdu_size << " buffer_len=" << buffer_len << std::endl;
            return -1;
        }
        void* top_ptr = hako_get_top_ptr_pdu((void*)base_ptr);
        if (top_ptr == nullptr) {
            std::cerr << "[ConvertorError][" << "Int32MultiArray" << "] hako_get_top_ptr_pdu returned null" << std::endl;
            return false;
        }
        memcpy(pdu_buffer, top_ptr, pdu_size);
        hako_destroy_pdu((void*)base_ptr);
        return pdu_size;
    }

private:
};
}


#endif /* _PDU_CPPTYPE_CONV_HAKO_std_msgs_Int32MultiArray_HPP_ */
