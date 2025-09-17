#ifndef _PDU_CPPTYPE_CONV_HAKO_drone_srv_msgs_CameraCaptureImageResponse_HPP_
#define _PDU_CPPTYPE_CONV_HAKO_drone_srv_msgs_CameraCaptureImageResponse_HPP_

#include "pdu_primitive_ctypes.h"
#include "pdu_primitive_ctypes_conv.hpp"
#include "pdu_dynamic_memory.hpp"
/*
 * Dependent pdu data
 */
#include "drone_srv_msgs/pdu_ctype_CameraCaptureImageResponse.h"
/*
 * Dependent cpp pdu data
 */
#include "drone_srv_msgs/pdu_cpptype_CameraCaptureImageResponse.hpp"

/*
 * Dependent Convertors
 */

/***************************
 *
 * PDU ==> CPP PDU
 *
 ***************************/
static inline int cpp_pdu2cpp_primitive_array_CameraCaptureImageResponse_data(const char* heap_ptr, Hako_CameraCaptureImageResponse &src, HakoCpp_CameraCaptureImageResponse &dst)
{
    // Convert using len and off
    int offset = src._data_off;
    int length = src._data_len;
    if (length > 0) {
        dst.data.resize(length);
        memcpy(dst.data.data(), heap_ptr + offset, length * sizeof(Hako_uint8));
    }
    return 0;
}

static inline int cpp_pdu2cpp_CameraCaptureImageResponse(const char* heap_ptr, Hako_CameraCaptureImageResponse &src, HakoCpp_CameraCaptureImageResponse &dst)
{
    // primitive convert
    hako_convert_pdu2cpp(src.ok, dst.ok);
    // primitive array convertor
    cpp_pdu2cpp_primitive_array_CameraCaptureImageResponse_data(heap_ptr, src, dst);
    // string convertor
    dst.message = (const char*)src.message;
    (void)heap_ptr;
    return 0;
}

static inline int hako_convert_pdu2cpp_CameraCaptureImageResponse(Hako_CameraCaptureImageResponse &src, HakoCpp_CameraCaptureImageResponse &dst)
{
    void* base_ptr = (void*)&src;
    void* heap_ptr = hako_get_heap_ptr_pdu(base_ptr);
    // Validate magic number and version
    if (heap_ptr == nullptr) {
        return -1; // Invalid PDU metadata
    }
    else {
        return cpp_pdu2cpp_CameraCaptureImageResponse((char*)heap_ptr, src, dst);
    }
}

/***************************
 *
 * CPP PDU ==> PDU
 *
 ***************************/
static inline bool cpp_cpp2pdu_primitive_array_CameraCaptureImageResponse_data(HakoCpp_CameraCaptureImageResponse &src, Hako_CameraCaptureImageResponse &dst, PduDynamicMemory &dynamic_memory)
{
    //Copy varray
    dst._data_len = src.data.size();
    if (dst._data_len > 0) {
        void* temp_ptr = dynamic_memory.allocate(dst._data_len, sizeof(Hako_uint8));
        memcpy(temp_ptr, src.data.data(), dst._data_len * sizeof(Hako_uint8));
        dst._data_off = dynamic_memory.get_offset(temp_ptr);
    }
    else {
        dst._data_off = dynamic_memory.get_total_size();
    }
    return true;
}

static inline bool cpp_cpp2pdu_CameraCaptureImageResponse(HakoCpp_CameraCaptureImageResponse &src, Hako_CameraCaptureImageResponse &dst, PduDynamicMemory &dynamic_memory)
{
    try {
        // primitive convert
        hako_convert_cpp2pdu(src.ok, dst.ok);
        //primitive array copy
        cpp_cpp2pdu_primitive_array_CameraCaptureImageResponse_data(src, dst, dynamic_memory);
        // string convertor
        (void)hako_convert_cpp2pdu_array(
            src.message, src.message.length(),
            dst.message, M_ARRAY_SIZE(Hako_CameraCaptureImageResponse, char, message));
        dst.message[src.message.length()] = '\0';
    } catch (const std::runtime_error& e) {
        std::cerr << "convertor error: " << e.what() << std::endl;
        return false;
    }
    (void)dynamic_memory;
    return true;
}

static inline int hako_convert_cpp2pdu_CameraCaptureImageResponse(HakoCpp_CameraCaptureImageResponse &src, Hako_CameraCaptureImageResponse** dst)
{
    PduDynamicMemory dynamic_memory;
    Hako_CameraCaptureImageResponse out;
    if (!cpp_cpp2pdu_CameraCaptureImageResponse(src, out, dynamic_memory)) {
        return -1;
    }
    int heap_size = dynamic_memory.get_total_size();
    void* base_ptr = hako_create_empty_pdu(sizeof(Hako_CameraCaptureImageResponse), heap_size);
    if (base_ptr == nullptr) {
        return -1;
    }
    // Copy out on base data
    memcpy(base_ptr, (void*)&out, sizeof(Hako_CameraCaptureImageResponse));

    // Copy dynamic part and set offsets
    void* heap_ptr = hako_get_heap_ptr_pdu(base_ptr);
    dynamic_memory.copy_to_pdu((char*)heap_ptr);

    *dst = (Hako_CameraCaptureImageResponse*)base_ptr;
    return hako_get_pdu_meta_data(base_ptr)->total_size;
}

static inline Hako_CameraCaptureImageResponse* hako_create_empty_pdu_CameraCaptureImageResponse(int heap_size)
{
    // Allocate PDU memory
    char* base_ptr = (char*)hako_create_empty_pdu(sizeof(Hako_CameraCaptureImageResponse), heap_size);
    if (base_ptr == nullptr) {
        return nullptr;
    }
    return (Hako_CameraCaptureImageResponse*)base_ptr;
}
namespace hako::pdu::msgs::drone_srv_msgs
{
class CameraCaptureImageResponse
{
public:
    CameraCaptureImageResponse() = default;
    ~CameraCaptureImageResponse() = default;

    bool pdu2cpp(char* top_ptr, HakoCpp_CameraCaptureImageResponse& cppData)
    {
        char* base_ptr = (char*)hako_get_base_ptr_pdu((void*)top_ptr);
        if (base_ptr == nullptr) {
            std::cerr << "[ConvertorError][" << "CameraCaptureImageResponse" << "] hako_get_base_ptr_pdu returned null" << std::endl;
            return false;
        } 
        int ret = hako_convert_pdu2cpp_CameraCaptureImageResponse(*(Hako_CameraCaptureImageResponse*)base_ptr, cppData);
        if (ret != 0) {
            std::cerr << "[ConvertorError][" << "CameraCaptureImageResponse" << "] hako_convert_pdu2cpp returned " << ret << std::endl;
            return false;
        }
        return true;
    }

    int cpp2pdu(HakoCpp_CameraCaptureImageResponse& cppData, char* pdu_buffer, int buffer_len)
    {
        char* base_ptr = nullptr;
        int pdu_size = hako_convert_cpp2pdu_CameraCaptureImageResponse(cppData, (Hako_CameraCaptureImageResponse**)&base_ptr);
        if (pdu_size < 0) {
            std::cerr << "[ConvertorError][" << "CameraCaptureImageResponse" << "] hako_convert_cpp2pdu returned error code: " << pdu_size << std::endl;
            return -1;
        }
        if (pdu_size > buffer_len) {
            std::cerr << "[ConvertorError][" << "CameraCaptureImageResponse" << "] buffer too small. pdu_size=" << pdu_size << " buffer_len=" << buffer_len << std::endl;
            return -1;
        }
        void* top_ptr = hako_get_top_ptr_pdu((void*)base_ptr);
        if (top_ptr == nullptr) {
            std::cerr << "[ConvertorError][" << "CameraCaptureImageResponse" << "] hako_get_top_ptr_pdu returned null" << std::endl;
            return -1;
        }
        memcpy(pdu_buffer, top_ptr, pdu_size);
        hako_destroy_pdu((void*)base_ptr);
        return pdu_size;
    }

private:
};
}


#endif /* _PDU_CPPTYPE_CONV_HAKO_drone_srv_msgs_CameraCaptureImageResponse_HPP_ */
