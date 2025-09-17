#ifndef _PDU_CPPTYPE_CONV_HAKO_hako_msgs_MetaPdu_HPP_
#define _PDU_CPPTYPE_CONV_HAKO_hako_msgs_MetaPdu_HPP_

#include "pdu_primitive_ctypes.h"
#include "pdu_primitive_ctypes_conv.hpp"
#include "pdu_dynamic_memory.hpp"
/*
 * Dependent pdu data
 */
#include "hako_msgs/pdu_ctype_MetaPdu.h"
/*
 * Dependent cpp pdu data
 */
#include "hako_msgs/pdu_cpptype_MetaPdu.hpp"

/*
 * Dependent Convertors
 */

/***************************
 *
 * PDU ==> CPP PDU
 *
 ***************************/

static inline int cpp_pdu2cpp_MetaPdu(const char* heap_ptr, Hako_MetaPdu &src, HakoCpp_MetaPdu &dst)
{
    // primitive convert
    hako_convert_pdu2cpp(src.total_len, dst.total_len);
    // primitive convert
    hako_convert_pdu2cpp(src.magicno, dst.magicno);
    // primitive convert
    hako_convert_pdu2cpp(src.version, dst.version);
    // primitive convert
    hako_convert_pdu2cpp(src.flags, dst.flags);
    // primitive convert
    hako_convert_pdu2cpp(src.meta_request_type, dst.meta_request_type);
    // primitive convert
    hako_convert_pdu2cpp(src.hako_time_us, dst.hako_time_us);
    // primitive convert
    hako_convert_pdu2cpp(src.asset_time_us, dst.asset_time_us);
    // primitive convert
    hako_convert_pdu2cpp(src.real_time_us, dst.real_time_us);
    // string convertor
    dst.robot_name = (const char*)src.robot_name;
    // primitive convert
    hako_convert_pdu2cpp(src.channel_id, dst.channel_id);
    // primitive convert
    hako_convert_pdu2cpp(src.body_len, dst.body_len);
    (void)heap_ptr;
    return 0;
}

static inline int hako_convert_pdu2cpp_MetaPdu(Hako_MetaPdu &src, HakoCpp_MetaPdu &dst)
{
    void* base_ptr = (void*)&src;
    void* heap_ptr = hako_get_heap_ptr_pdu(base_ptr);
    // Validate magic number and version
    if (heap_ptr == nullptr) {
        return -1; // Invalid PDU metadata
    }
    else {
        return cpp_pdu2cpp_MetaPdu((char*)heap_ptr, src, dst);
    }
}

/***************************
 *
 * CPP PDU ==> PDU
 *
 ***************************/

static inline bool cpp_cpp2pdu_MetaPdu(HakoCpp_MetaPdu &src, Hako_MetaPdu &dst, PduDynamicMemory &dynamic_memory)
{
    try {
        // primitive convert
        hako_convert_cpp2pdu(src.total_len, dst.total_len);
        // primitive convert
        hako_convert_cpp2pdu(src.magicno, dst.magicno);
        // primitive convert
        hako_convert_cpp2pdu(src.version, dst.version);
        // primitive convert
        hako_convert_cpp2pdu(src.flags, dst.flags);
        // primitive convert
        hako_convert_cpp2pdu(src.meta_request_type, dst.meta_request_type);
        // primitive convert
        hako_convert_cpp2pdu(src.hako_time_us, dst.hako_time_us);
        // primitive convert
        hako_convert_cpp2pdu(src.asset_time_us, dst.asset_time_us);
        // primitive convert
        hako_convert_cpp2pdu(src.real_time_us, dst.real_time_us);
        // string convertor
        (void)hako_convert_cpp2pdu_array(
            src.robot_name, src.robot_name.length(),
            dst.robot_name, M_ARRAY_SIZE(Hako_MetaPdu, char, robot_name));
        dst.robot_name[src.robot_name.length()] = '\0';
        // primitive convert
        hako_convert_cpp2pdu(src.channel_id, dst.channel_id);
        // primitive convert
        hako_convert_cpp2pdu(src.body_len, dst.body_len);
    } catch (const std::runtime_error& e) {
        std::cerr << "convertor error: " << e.what() << std::endl;
        return false;
    }
    (void)dynamic_memory;
    return true;
}

static inline int hako_convert_cpp2pdu_MetaPdu(HakoCpp_MetaPdu &src, Hako_MetaPdu** dst)
{
    PduDynamicMemory dynamic_memory;
    Hako_MetaPdu out;
    if (!cpp_cpp2pdu_MetaPdu(src, out, dynamic_memory)) {
        return -1;
    }
    int heap_size = dynamic_memory.get_total_size();
    void* base_ptr = hako_create_empty_pdu(sizeof(Hako_MetaPdu), heap_size);
    if (base_ptr == nullptr) {
        return -1;
    }
    // Copy out on base data
    memcpy(base_ptr, (void*)&out, sizeof(Hako_MetaPdu));

    // Copy dynamic part and set offsets
    void* heap_ptr = hako_get_heap_ptr_pdu(base_ptr);
    dynamic_memory.copy_to_pdu((char*)heap_ptr);

    *dst = (Hako_MetaPdu*)base_ptr;
    return hako_get_pdu_meta_data(base_ptr)->total_size;
}

static inline Hako_MetaPdu* hako_create_empty_pdu_MetaPdu(int heap_size)
{
    // Allocate PDU memory
    char* base_ptr = (char*)hako_create_empty_pdu(sizeof(Hako_MetaPdu), heap_size);
    if (base_ptr == nullptr) {
        return nullptr;
    }
    return (Hako_MetaPdu*)base_ptr;
}
namespace hako::pdu::msgs::hako_msgs
{
class MetaPdu
{
public:
    MetaPdu() = default;
    ~MetaPdu() = default;

    bool pdu2cpp(char* top_ptr, HakoCpp_MetaPdu& cppData)
    {
        char* base_ptr = (char*)hako_get_base_ptr_pdu((void*)top_ptr);
        if (base_ptr == nullptr) {
            std::cerr << "[ConvertorError][" << "MetaPdu" << "] hako_get_base_ptr_pdu returned null" << std::endl;
            return false;
        } 
        int ret = hako_convert_pdu2cpp_MetaPdu(*(Hako_MetaPdu*)base_ptr, cppData);
        if (ret != 0) {
            std::cerr << "[ConvertorError][" << "MetaPdu" << "] hako_convert_pdu2cpp returned " << ret << std::endl;
            return false;
        }
        return true;
    }

    int cpp2pdu(HakoCpp_MetaPdu& cppData, char* pdu_buffer, int buffer_len)
    {
        char* base_ptr = nullptr;
        int pdu_size = hako_convert_cpp2pdu_MetaPdu(cppData, (Hako_MetaPdu**)&base_ptr);
        if (pdu_size < 0) {
            std::cerr << "[ConvertorError][" << "MetaPdu" << "] hako_convert_cpp2pdu returned error code: " << pdu_size << std::endl;
            return -1;
        }
        if (pdu_size > buffer_len) {
            std::cerr << "[ConvertorError][" << "MetaPdu" << "] buffer too small. pdu_size=" << pdu_size << " buffer_len=" << buffer_len << std::endl;
            return -1;
        }
        void* top_ptr = hako_get_top_ptr_pdu((void*)base_ptr);
        if (top_ptr == nullptr) {
            std::cerr << "[ConvertorError][" << "MetaPdu" << "] hako_get_top_ptr_pdu returned null" << std::endl;
            return -1;
        }
        memcpy(pdu_buffer, top_ptr, pdu_size);
        hako_destroy_pdu((void*)base_ptr);
        return pdu_size;
    }

private:
};
}


#endif /* _PDU_CPPTYPE_CONV_HAKO_hako_msgs_MetaPdu_HPP_ */
