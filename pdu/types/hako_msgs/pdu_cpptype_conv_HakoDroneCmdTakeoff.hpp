#ifndef _PDU_CPPTYPE_CONV_HAKO_hako_msgs_HakoDroneCmdTakeoff_HPP_
#define _PDU_CPPTYPE_CONV_HAKO_hako_msgs_HakoDroneCmdTakeoff_HPP_

#include "pdu_primitive_ctypes.h"
#include "pdu_primitive_ctypes_conv.hpp"
#include "pdu_dynamic_memory.hpp"
/*
 * Dependent pdu data
 */
#include "hako_msgs/pdu_ctype_HakoDroneCmdTakeoff.h"
/*
 * Dependent cpp pdu data
 */
#include "hako_msgs/pdu_cpptype_HakoDroneCmdTakeoff.hpp"

/*
 * Dependent Convertors
 */
#include "hako_msgs/pdu_cpptype_conv_HakoDroneCmdHeader.hpp"

/***************************
 *
 * PDU ==> CPP PDU
 *
 ***************************/

static inline int cpp_pdu2cpp_HakoDroneCmdTakeoff(const char* heap_ptr, Hako_HakoDroneCmdTakeoff &src, HakoCpp_HakoDroneCmdTakeoff &dst)
{
    // Struct convert
    cpp_pdu2cpp_HakoDroneCmdHeader(heap_ptr, src.header, dst.header);
    // primitive convert
    hako_convert_pdu2cpp(src.height, dst.height);
    // primitive convert
    hako_convert_pdu2cpp(src.speed, dst.speed);
    // primitive convert
    hako_convert_pdu2cpp(src.yaw_deg, dst.yaw_deg);
    (void)heap_ptr;
    return 0;
}

static inline int hako_convert_pdu2cpp_HakoDroneCmdTakeoff(Hako_HakoDroneCmdTakeoff &src, HakoCpp_HakoDroneCmdTakeoff &dst)
{
    void* base_ptr = (void*)&src;
    void* heap_ptr = hako_get_heap_ptr_pdu(base_ptr);
    // Validate magic number and version
    if (heap_ptr == nullptr) {
        return -1; // Invalid PDU metadata
    }
    else {
        return cpp_pdu2cpp_HakoDroneCmdTakeoff((char*)heap_ptr, src, dst);
    }
}

/***************************
 *
 * CPP PDU ==> PDU
 *
 ***************************/

static inline bool cpp_cpp2pdu_HakoDroneCmdTakeoff(HakoCpp_HakoDroneCmdTakeoff &src, Hako_HakoDroneCmdTakeoff &dst, PduDynamicMemory &dynamic_memory)
{
    try {
        // struct convert
        cpp_cpp2pdu_HakoDroneCmdHeader(src.header, dst.header, dynamic_memory);
        // primitive convert
        hako_convert_cpp2pdu(src.height, dst.height);
        // primitive convert
        hako_convert_cpp2pdu(src.speed, dst.speed);
        // primitive convert
        hako_convert_cpp2pdu(src.yaw_deg, dst.yaw_deg);
    } catch (const std::runtime_error& e) {
        std::cerr << "convertor error: " << e.what() << std::endl;
        return false;
    }
    (void)dynamic_memory;
    return true;
}

static inline int hako_convert_cpp2pdu_HakoDroneCmdTakeoff(HakoCpp_HakoDroneCmdTakeoff &src, Hako_HakoDroneCmdTakeoff** dst)
{
    PduDynamicMemory dynamic_memory;
    Hako_HakoDroneCmdTakeoff out;
    if (!cpp_cpp2pdu_HakoDroneCmdTakeoff(src, out, dynamic_memory)) {
        return -1;
    }
    int heap_size = dynamic_memory.get_total_size();
    void* base_ptr = hako_create_empty_pdu(sizeof(Hako_HakoDroneCmdTakeoff), heap_size);
    if (base_ptr == nullptr) {
        return -1;
    }
    // Copy out on base data
    memcpy(base_ptr, (void*)&out, sizeof(Hako_HakoDroneCmdTakeoff));

    // Copy dynamic part and set offsets
    void* heap_ptr = hako_get_heap_ptr_pdu(base_ptr);
    dynamic_memory.copy_to_pdu((char*)heap_ptr);

    *dst = (Hako_HakoDroneCmdTakeoff*)base_ptr;
    return hako_get_pdu_meta_data(base_ptr)->total_size;
}

static inline Hako_HakoDroneCmdTakeoff* hako_create_empty_pdu_HakoDroneCmdTakeoff(int heap_size)
{
    // Allocate PDU memory
    char* base_ptr = (char*)hako_create_empty_pdu(sizeof(Hako_HakoDroneCmdTakeoff), heap_size);
    if (base_ptr == nullptr) {
        return nullptr;
    }
    return (Hako_HakoDroneCmdTakeoff*)base_ptr;
}
namespace hako::pdu::msgs::hako_msgs
{
class HakoDroneCmdTakeoff
{
public:
    HakoDroneCmdTakeoff() = default;
    ~HakoDroneCmdTakeoff() = default;

    bool pdu2cpp(char* top_ptr, HakoCpp_HakoDroneCmdTakeoff& cppData)
    {
        char* base_ptr = (char*)hako_get_base_ptr_pdu((void*)top_ptr);
        if (base_ptr == nullptr) {
            std::cerr << "[ConvertorError][" << "HakoDroneCmdTakeoff" << "] hako_get_base_ptr_pdu returned null" << std::endl;
            return false;
        } 
        int ret = hako_convert_pdu2cpp_HakoDroneCmdTakeoff(*(Hako_HakoDroneCmdTakeoff*)base_ptr, cppData);
        if (ret != 0) {
            std::cerr << "[ConvertorError][" << "HakoDroneCmdTakeoff" << "] hako_convert_pdu2cpp returned " << ret << std::endl;
            return false;
        }
        return true;
    }

    int cpp2pdu(HakoCpp_HakoDroneCmdTakeoff& cppData, char* pdu_buffer, int buffer_len)
    {
        char* base_ptr = nullptr;
        int pdu_size = hako_convert_cpp2pdu_HakoDroneCmdTakeoff(cppData, (Hako_HakoDroneCmdTakeoff**)&base_ptr);
        if (pdu_size < 0) {
            std::cerr << "[ConvertorError][" << "HakoDroneCmdTakeoff" << "] hako_convert_cpp2pdu returned error code: " << pdu_size << std::endl;
            return -1;
        }
        if (pdu_size > buffer_len) {
            std::cerr << "[ConvertorError][" << "HakoDroneCmdTakeoff" << "] buffer too small. pdu_size=" << pdu_size << " buffer_len=" << buffer_len << std::endl;
            return -1;
        }
        void* top_ptr = hako_get_top_ptr_pdu((void*)base_ptr);
        if (top_ptr == nullptr) {
            std::cerr << "[ConvertorError][" << "HakoDroneCmdTakeoff" << "] hako_get_top_ptr_pdu returned null" << std::endl;
            return false;
        }
        memcpy(pdu_buffer, top_ptr, pdu_size);
        hako_destroy_pdu((void*)base_ptr);
        return pdu_size;
    }

private:
};
}


#endif /* _PDU_CPPTYPE_CONV_HAKO_hako_msgs_HakoDroneCmdTakeoff_HPP_ */
