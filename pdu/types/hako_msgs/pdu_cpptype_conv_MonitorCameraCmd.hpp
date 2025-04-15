#ifndef _PDU_CPPTYPE_CONV_HAKO_hako_msgs_MonitorCameraCmd_HPP_
#define _PDU_CPPTYPE_CONV_HAKO_hako_msgs_MonitorCameraCmd_HPP_

#include "pdu_primitive_ctypes.h"
#include "pdu_primitive_ctypes_conv.hpp"
#include "pdu_dynamic_memory.hpp"
/*
 * Dependent pdu data
 */
#include "hako_msgs/pdu_ctype_MonitorCameraCmd.h"
/*
 * Dependent cpp pdu data
 */
#include "hako_msgs/pdu_cpptype_MonitorCameraCmd.hpp"

/*
 * Dependent Convertors
 */
#include "hako_msgs/pdu_cpptype_conv_HakoCmdHeader.hpp"

/***************************
 *
 * PDU ==> CPP PDU
 *
 ***************************/

static inline int cpp_pdu2cpp_MonitorCameraCmd(const char* heap_ptr, Hako_MonitorCameraCmd &src, HakoCpp_MonitorCameraCmd &dst)
{
    // Struct convert
    cpp_pdu2cpp_HakoCmdHeader(heap_ptr, src.header, dst.header);
    // primitive convert
    hako_convert_pdu2cpp(src.request_id, dst.request_id);
    // primitive convert
    hako_convert_pdu2cpp(src.encode_type, dst.encode_type);
    // primitive convert
    hako_convert_pdu2cpp(src.request_type, dst.request_type);
    (void)heap_ptr;
    return 0;
}

static inline int hako_convert_pdu2cpp_MonitorCameraCmd(Hako_MonitorCameraCmd &src, HakoCpp_MonitorCameraCmd &dst)
{
    void* base_ptr = (void*)&src;
    void* heap_ptr = hako_get_heap_ptr_pdu(base_ptr);
    // Validate magic number and version
    if (heap_ptr == nullptr) {
        return -1; // Invalid PDU metadata
    }
    else {
        return cpp_pdu2cpp_MonitorCameraCmd((char*)heap_ptr, src, dst);
    }
}

/***************************
 *
 * CPP PDU ==> PDU
 *
 ***************************/

static inline bool cpp_cpp2pdu_MonitorCameraCmd(HakoCpp_MonitorCameraCmd &src, Hako_MonitorCameraCmd &dst, PduDynamicMemory &dynamic_memory)
{
    try {
        // struct convert
        cpp_cpp2pdu_HakoCmdHeader(src.header, dst.header, dynamic_memory);
        // primitive convert
        hako_convert_cpp2pdu(src.request_id, dst.request_id);
        // primitive convert
        hako_convert_cpp2pdu(src.encode_type, dst.encode_type);
        // primitive convert
        hako_convert_cpp2pdu(src.request_type, dst.request_type);
    } catch (const std::runtime_error& e) {
        std::cerr << "convertor error: " << e.what() << std::endl;
        return false;
    }
    (void)dynamic_memory;
    return true;
}

static inline int hako_convert_cpp2pdu_MonitorCameraCmd(HakoCpp_MonitorCameraCmd &src, Hako_MonitorCameraCmd** dst)
{
    PduDynamicMemory dynamic_memory;
    Hako_MonitorCameraCmd out;
    if (!cpp_cpp2pdu_MonitorCameraCmd(src, out, dynamic_memory)) {
        return -1;
    }
    int heap_size = dynamic_memory.get_total_size();
    void* base_ptr = hako_create_empty_pdu(sizeof(Hako_MonitorCameraCmd), heap_size);
    if (base_ptr == nullptr) {
        return -1;
    }
    // Copy out on base data
    memcpy(base_ptr, (void*)&out, sizeof(Hako_MonitorCameraCmd));

    // Copy dynamic part and set offsets
    void* heap_ptr = hako_get_heap_ptr_pdu(base_ptr);
    dynamic_memory.copy_to_pdu((char*)heap_ptr);

    *dst = (Hako_MonitorCameraCmd*)base_ptr;
    return hako_get_pdu_meta_data(base_ptr)->total_size;
}

static inline Hako_MonitorCameraCmd* hako_create_empty_pdu_MonitorCameraCmd(int heap_size)
{
    // Allocate PDU memory
    char* base_ptr = (char*)hako_create_empty_pdu(sizeof(Hako_MonitorCameraCmd), heap_size);
    if (base_ptr == nullptr) {
        return nullptr;
    }
    return (Hako_MonitorCameraCmd*)base_ptr;
}
namespace hako::pdu::msgs::hako_msgs
{
class MonitorCameraCmd
{
public:
    MonitorCameraCmd() = default;
    ~MonitorCameraCmd() = default;

    bool pdu2cpp(char* top_ptr, HakoCpp_MonitorCameraCmd& cppData)
    {
        char* base_ptr = (char*)hako_get_base_ptr_pdu((void*)top_ptr);
        if (base_ptr == nullptr) {
            std::cerr << "[ConvertorError][" << "MonitorCameraCmd" << "] hako_get_base_ptr_pdu returned null" << std::endl;
            return false;
        } 
        int ret = hako_convert_pdu2cpp_MonitorCameraCmd(*(Hako_MonitorCameraCmd*)base_ptr, cppData);
        if (ret != 0) {
            std::cerr << "[ConvertorError][" << "MonitorCameraCmd" << "] hako_convert_pdu2cpp returned " << ret << std::endl;
            return false;
        }
        return true;
    }

    int cpp2pdu(HakoCpp_MonitorCameraCmd& cppData, char* pdu_buffer, int buffer_len)
    {
        char* base_ptr = nullptr;
        int pdu_size = hako_convert_cpp2pdu_MonitorCameraCmd(cppData, (Hako_MonitorCameraCmd**)&base_ptr);
        if (pdu_size < 0) {
            std::cerr << "[ConvertorError][" << "MonitorCameraCmd" << "] hako_convert_cpp2pdu returned error code: " << pdu_size << std::endl;
            return -1;
        }
        if (pdu_size > buffer_len) {
            std::cerr << "[ConvertorError][" << "MonitorCameraCmd" << "] buffer too small. pdu_size=" << pdu_size << " buffer_len=" << buffer_len << std::endl;
            return -1;
        }
        void* top_ptr = hako_get_top_ptr_pdu((void*)base_ptr);
        if (top_ptr == nullptr) {
            std::cerr << "[ConvertorError][" << "MonitorCameraCmd" << "] hako_get_top_ptr_pdu returned null" << std::endl;
            return false;
        }
        memcpy(pdu_buffer, top_ptr, pdu_size);
        hako_destroy_pdu((void*)base_ptr);
        return pdu_size;
    }

private:
};
}


#endif /* _PDU_CPPTYPE_CONV_HAKO_hako_msgs_MonitorCameraCmd_HPP_ */
