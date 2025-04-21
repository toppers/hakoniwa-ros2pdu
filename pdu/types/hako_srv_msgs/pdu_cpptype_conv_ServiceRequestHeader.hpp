#ifndef _PDU_CPPTYPE_CONV_HAKO_hako_srv_msgs_ServiceRequestHeader_HPP_
#define _PDU_CPPTYPE_CONV_HAKO_hako_srv_msgs_ServiceRequestHeader_HPP_

#include "pdu_primitive_ctypes.h"
#include "pdu_primitive_ctypes_conv.hpp"
#include "pdu_dynamic_memory.hpp"
/*
 * Dependent pdu data
 */
#include "hako_srv_msgs/pdu_ctype_ServiceRequestHeader.h"
/*
 * Dependent cpp pdu data
 */
#include "hako_srv_msgs/pdu_cpptype_ServiceRequestHeader.hpp"

/*
 * Dependent Convertors
 */

/***************************
 *
 * PDU ==> CPP PDU
 *
 ***************************/

static inline int cpp_pdu2cpp_ServiceRequestHeader(const char* heap_ptr, Hako_ServiceRequestHeader &src, HakoCpp_ServiceRequestHeader &dst)
{
    // primitive convert
    hako_convert_pdu2cpp(src.request_id, dst.request_id);
    // string convertor
    dst.service_name = (const char*)src.service_name;
    // string convertor
    dst.client_name = (const char*)src.client_name;
    // primitive convert
    hako_convert_pdu2cpp(src.opcode, dst.opcode);
    // primitive convert
    hako_convert_pdu2cpp(src.status_poll_interval_msec, dst.status_poll_interval_msec);
    (void)heap_ptr;
    return 0;
}

static inline int hako_convert_pdu2cpp_ServiceRequestHeader(Hako_ServiceRequestHeader &src, HakoCpp_ServiceRequestHeader &dst)
{
    void* base_ptr = (void*)&src;
    void* heap_ptr = hako_get_heap_ptr_pdu(base_ptr);
    // Validate magic number and version
    if (heap_ptr == nullptr) {
        return -1; // Invalid PDU metadata
    }
    else {
        return cpp_pdu2cpp_ServiceRequestHeader((char*)heap_ptr, src, dst);
    }
}

/***************************
 *
 * CPP PDU ==> PDU
 *
 ***************************/

static inline bool cpp_cpp2pdu_ServiceRequestHeader(HakoCpp_ServiceRequestHeader &src, Hako_ServiceRequestHeader &dst, PduDynamicMemory &dynamic_memory)
{
    try {
        // primitive convert
        hako_convert_cpp2pdu(src.request_id, dst.request_id);
        // string convertor
        (void)hako_convert_cpp2pdu_array(
            src.service_name, src.service_name.length(),
            dst.service_name, M_ARRAY_SIZE(Hako_ServiceRequestHeader, char, service_name));
        dst.service_name[src.service_name.length()] = '\0';
        // string convertor
        (void)hako_convert_cpp2pdu_array(
            src.client_name, src.client_name.length(),
            dst.client_name, M_ARRAY_SIZE(Hako_ServiceRequestHeader, char, client_name));
        dst.client_name[src.client_name.length()] = '\0';
        // primitive convert
        hako_convert_cpp2pdu(src.opcode, dst.opcode);
        // primitive convert
        hako_convert_cpp2pdu(src.status_poll_interval_msec, dst.status_poll_interval_msec);
    } catch (const std::runtime_error& e) {
        std::cerr << "convertor error: " << e.what() << std::endl;
        return false;
    }
    (void)dynamic_memory;
    return true;
}

static inline int hako_convert_cpp2pdu_ServiceRequestHeader(HakoCpp_ServiceRequestHeader &src, Hako_ServiceRequestHeader** dst)
{
    PduDynamicMemory dynamic_memory;
    Hako_ServiceRequestHeader out;
    if (!cpp_cpp2pdu_ServiceRequestHeader(src, out, dynamic_memory)) {
        return -1;
    }
    int heap_size = dynamic_memory.get_total_size();
    void* base_ptr = hako_create_empty_pdu(sizeof(Hako_ServiceRequestHeader), heap_size);
    if (base_ptr == nullptr) {
        return -1;
    }
    // Copy out on base data
    memcpy(base_ptr, (void*)&out, sizeof(Hako_ServiceRequestHeader));

    // Copy dynamic part and set offsets
    void* heap_ptr = hako_get_heap_ptr_pdu(base_ptr);
    dynamic_memory.copy_to_pdu((char*)heap_ptr);

    *dst = (Hako_ServiceRequestHeader*)base_ptr;
    return hako_get_pdu_meta_data(base_ptr)->total_size;
}

static inline Hako_ServiceRequestHeader* hako_create_empty_pdu_ServiceRequestHeader(int heap_size)
{
    // Allocate PDU memory
    char* base_ptr = (char*)hako_create_empty_pdu(sizeof(Hako_ServiceRequestHeader), heap_size);
    if (base_ptr == nullptr) {
        return nullptr;
    }
    return (Hako_ServiceRequestHeader*)base_ptr;
}
namespace hako::pdu::msgs::hako_srv_msgs
{
class ServiceRequestHeader
{
public:
    ServiceRequestHeader() = default;
    ~ServiceRequestHeader() = default;

    bool pdu2cpp(char* top_ptr, HakoCpp_ServiceRequestHeader& cppData)
    {
        char* base_ptr = (char*)hako_get_base_ptr_pdu((void*)top_ptr);
        if (base_ptr == nullptr) {
            std::cerr << "[ConvertorError][" << "ServiceRequestHeader" << "] hako_get_base_ptr_pdu returned null" << std::endl;
            return false;
        } 
        int ret = hako_convert_pdu2cpp_ServiceRequestHeader(*(Hako_ServiceRequestHeader*)base_ptr, cppData);
        if (ret != 0) {
            std::cerr << "[ConvertorError][" << "ServiceRequestHeader" << "] hako_convert_pdu2cpp returned " << ret << std::endl;
            return false;
        }
        return true;
    }

    int cpp2pdu(HakoCpp_ServiceRequestHeader& cppData, char* pdu_buffer, int buffer_len)
    {
        char* base_ptr = nullptr;
        int pdu_size = hako_convert_cpp2pdu_ServiceRequestHeader(cppData, (Hako_ServiceRequestHeader**)&base_ptr);
        if (pdu_size < 0) {
            std::cerr << "[ConvertorError][" << "ServiceRequestHeader" << "] hako_convert_cpp2pdu returned error code: " << pdu_size << std::endl;
            return -1;
        }
        if (pdu_size > buffer_len) {
            std::cerr << "[ConvertorError][" << "ServiceRequestHeader" << "] buffer too small. pdu_size=" << pdu_size << " buffer_len=" << buffer_len << std::endl;
            return -1;
        }
        void* top_ptr = hako_get_top_ptr_pdu((void*)base_ptr);
        if (top_ptr == nullptr) {
            std::cerr << "[ConvertorError][" << "ServiceRequestHeader" << "] hako_get_top_ptr_pdu returned null" << std::endl;
            return false;
        }
        memcpy(pdu_buffer, top_ptr, pdu_size);
        hako_destroy_pdu((void*)base_ptr);
        return pdu_size;
    }

private:
};
}


#endif /* _PDU_CPPTYPE_CONV_HAKO_hako_srv_msgs_ServiceRequestHeader_HPP_ */
