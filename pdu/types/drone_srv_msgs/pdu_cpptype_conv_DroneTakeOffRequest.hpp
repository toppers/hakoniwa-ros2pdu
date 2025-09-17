#ifndef _PDU_CPPTYPE_CONV_HAKO_drone_srv_msgs_DroneTakeOffRequest_HPP_
#define _PDU_CPPTYPE_CONV_HAKO_drone_srv_msgs_DroneTakeOffRequest_HPP_

#include "pdu_primitive_ctypes.h"
#include "pdu_primitive_ctypes_conv.hpp"
#include "pdu_dynamic_memory.hpp"
/*
 * Dependent pdu data
 */
#include "drone_srv_msgs/pdu_ctype_DroneTakeOffRequest.h"
/*
 * Dependent cpp pdu data
 */
#include "drone_srv_msgs/pdu_cpptype_DroneTakeOffRequest.hpp"

/*
 * Dependent Convertors
 */

/***************************
 *
 * PDU ==> CPP PDU
 *
 ***************************/

static inline int cpp_pdu2cpp_DroneTakeOffRequest(const char* heap_ptr, Hako_DroneTakeOffRequest &src, HakoCpp_DroneTakeOffRequest &dst)
{
    // primitive convert
    hako_convert_pdu2cpp(src.alt_m, dst.alt_m);
    // string convertor
    dst.drone_name = (const char*)src.drone_name;
    (void)heap_ptr;
    return 0;
}

static inline int hako_convert_pdu2cpp_DroneTakeOffRequest(Hako_DroneTakeOffRequest &src, HakoCpp_DroneTakeOffRequest &dst)
{
    void* base_ptr = (void*)&src;
    void* heap_ptr = hako_get_heap_ptr_pdu(base_ptr);
    // Validate magic number and version
    if (heap_ptr == nullptr) {
        return -1; // Invalid PDU metadata
    }
    else {
        return cpp_pdu2cpp_DroneTakeOffRequest((char*)heap_ptr, src, dst);
    }
}

/***************************
 *
 * CPP PDU ==> PDU
 *
 ***************************/

static inline bool cpp_cpp2pdu_DroneTakeOffRequest(HakoCpp_DroneTakeOffRequest &src, Hako_DroneTakeOffRequest &dst, PduDynamicMemory &dynamic_memory)
{
    try {
        // primitive convert
        hako_convert_cpp2pdu(src.alt_m, dst.alt_m);
        // string convertor
        (void)hako_convert_cpp2pdu_array(
            src.drone_name, src.drone_name.length(),
            dst.drone_name, M_ARRAY_SIZE(Hako_DroneTakeOffRequest, char, drone_name));
        dst.drone_name[src.drone_name.length()] = '\0';
    } catch (const std::runtime_error& e) {
        std::cerr << "convertor error: " << e.what() << std::endl;
        return false;
    }
    (void)dynamic_memory;
    return true;
}

static inline int hako_convert_cpp2pdu_DroneTakeOffRequest(HakoCpp_DroneTakeOffRequest &src, Hako_DroneTakeOffRequest** dst)
{
    PduDynamicMemory dynamic_memory;
    Hako_DroneTakeOffRequest out;
    if (!cpp_cpp2pdu_DroneTakeOffRequest(src, out, dynamic_memory)) {
        return -1;
    }
    int heap_size = dynamic_memory.get_total_size();
    void* base_ptr = hako_create_empty_pdu(sizeof(Hako_DroneTakeOffRequest), heap_size);
    if (base_ptr == nullptr) {
        return -1;
    }
    // Copy out on base data
    memcpy(base_ptr, (void*)&out, sizeof(Hako_DroneTakeOffRequest));

    // Copy dynamic part and set offsets
    void* heap_ptr = hako_get_heap_ptr_pdu(base_ptr);
    dynamic_memory.copy_to_pdu((char*)heap_ptr);

    *dst = (Hako_DroneTakeOffRequest*)base_ptr;
    return hako_get_pdu_meta_data(base_ptr)->total_size;
}

static inline Hako_DroneTakeOffRequest* hako_create_empty_pdu_DroneTakeOffRequest(int heap_size)
{
    // Allocate PDU memory
    char* base_ptr = (char*)hako_create_empty_pdu(sizeof(Hako_DroneTakeOffRequest), heap_size);
    if (base_ptr == nullptr) {
        return nullptr;
    }
    return (Hako_DroneTakeOffRequest*)base_ptr;
}
namespace hako::pdu::msgs::drone_srv_msgs
{
class DroneTakeOffRequest
{
public:
    DroneTakeOffRequest() = default;
    ~DroneTakeOffRequest() = default;

    bool pdu2cpp(char* top_ptr, HakoCpp_DroneTakeOffRequest& cppData)
    {
        char* base_ptr = (char*)hako_get_base_ptr_pdu((void*)top_ptr);
        if (base_ptr == nullptr) {
            std::cerr << "[ConvertorError][" << "DroneTakeOffRequest" << "] hako_get_base_ptr_pdu returned null" << std::endl;
            return false;
        } 
        int ret = hako_convert_pdu2cpp_DroneTakeOffRequest(*(Hako_DroneTakeOffRequest*)base_ptr, cppData);
        if (ret != 0) {
            std::cerr << "[ConvertorError][" << "DroneTakeOffRequest" << "] hako_convert_pdu2cpp returned " << ret << std::endl;
            return false;
        }
        return true;
    }

    int cpp2pdu(HakoCpp_DroneTakeOffRequest& cppData, char* pdu_buffer, int buffer_len)
    {
        char* base_ptr = nullptr;
        int pdu_size = hako_convert_cpp2pdu_DroneTakeOffRequest(cppData, (Hako_DroneTakeOffRequest**)&base_ptr);
        if (pdu_size < 0) {
            std::cerr << "[ConvertorError][" << "DroneTakeOffRequest" << "] hako_convert_cpp2pdu returned error code: " << pdu_size << std::endl;
            return -1;
        }
        if (pdu_size > buffer_len) {
            std::cerr << "[ConvertorError][" << "DroneTakeOffRequest" << "] buffer too small. pdu_size=" << pdu_size << " buffer_len=" << buffer_len << std::endl;
            return -1;
        }
        void* top_ptr = hako_get_top_ptr_pdu((void*)base_ptr);
        if (top_ptr == nullptr) {
            std::cerr << "[ConvertorError][" << "DroneTakeOffRequest" << "] hako_get_top_ptr_pdu returned null" << std::endl;
            return -1;
        }
        memcpy(pdu_buffer, top_ptr, pdu_size);
        hako_destroy_pdu((void*)base_ptr);
        return pdu_size;
    }

private:
};
}


#endif /* _PDU_CPPTYPE_CONV_HAKO_drone_srv_msgs_DroneTakeOffRequest_HPP_ */
