#ifndef _PDU_CPPTYPE_CONV_HAKO_mavros_msgs_GlobalPositionTarget_HPP_
#define _PDU_CPPTYPE_CONV_HAKO_mavros_msgs_GlobalPositionTarget_HPP_

#include "pdu_primitive_ctypes.h"
#include "pdu_primitive_ctypes_conv.hpp"
#include "pdu_dynamic_memory.hpp"
/*
 * Dependent pdu data
 */
#include "mavros_msgs/pdu_ctype_GlobalPositionTarget.h"
/*
 * Dependent cpp pdu data
 */
#include "mavros_msgs/pdu_cpptype_GlobalPositionTarget.hpp"

/*
 * Dependent Convertors
 */
#include "builtin_interfaces/pdu_cpptype_conv_Time.hpp"
#include "geometry_msgs/pdu_cpptype_conv_Vector3.hpp"
#include "std_msgs/pdu_cpptype_conv_Header.hpp"

/***************************
 *
 * PDU ==> CPP PDU
 *
 ***************************/

static inline int cpp_pdu2cpp_GlobalPositionTarget(const char* heap_ptr, Hako_GlobalPositionTarget &src, HakoCpp_GlobalPositionTarget &dst)
{
    // Struct convert
    cpp_pdu2cpp_Header(heap_ptr, src.header, dst.header);
    // primitive convert
    hako_convert_pdu2cpp(src.coordinate_frame, dst.coordinate_frame);
    // primitive convert
    hako_convert_pdu2cpp(src.type_mask, dst.type_mask);
    // primitive convert
    hako_convert_pdu2cpp(src.latitude, dst.latitude);
    // primitive convert
    hako_convert_pdu2cpp(src.longitude, dst.longitude);
    // primitive convert
    hako_convert_pdu2cpp(src.altitude, dst.altitude);
    // Struct convert
    cpp_pdu2cpp_Vector3(heap_ptr, src.velocity, dst.velocity);
    // Struct convert
    cpp_pdu2cpp_Vector3(heap_ptr, src.acceleration_or_force, dst.acceleration_or_force);
    // primitive convert
    hako_convert_pdu2cpp(src.yaw, dst.yaw);
    // primitive convert
    hako_convert_pdu2cpp(src.yaw_rate, dst.yaw_rate);
    (void)heap_ptr;
    return 0;
}

static inline int hako_convert_pdu2cpp_GlobalPositionTarget(Hako_GlobalPositionTarget &src, HakoCpp_GlobalPositionTarget &dst)
{
    void* base_ptr = (void*)&src;
    void* heap_ptr = hako_get_heap_ptr_pdu(base_ptr);
    // Validate magic number and version
    if (heap_ptr == nullptr) {
        return -1; // Invalid PDU metadata
    }
    else {
        return cpp_pdu2cpp_GlobalPositionTarget((char*)heap_ptr, src, dst);
    }
}

/***************************
 *
 * CPP PDU ==> PDU
 *
 ***************************/

static inline bool cpp_cpp2pdu_GlobalPositionTarget(HakoCpp_GlobalPositionTarget &src, Hako_GlobalPositionTarget &dst, PduDynamicMemory &dynamic_memory)
{
    try {
        // struct convert
        cpp_cpp2pdu_Header(src.header, dst.header, dynamic_memory);
        // primitive convert
        hako_convert_cpp2pdu(src.coordinate_frame, dst.coordinate_frame);
        // primitive convert
        hako_convert_cpp2pdu(src.type_mask, dst.type_mask);
        // primitive convert
        hako_convert_cpp2pdu(src.latitude, dst.latitude);
        // primitive convert
        hako_convert_cpp2pdu(src.longitude, dst.longitude);
        // primitive convert
        hako_convert_cpp2pdu(src.altitude, dst.altitude);
        // struct convert
        cpp_cpp2pdu_Vector3(src.velocity, dst.velocity, dynamic_memory);
        // struct convert
        cpp_cpp2pdu_Vector3(src.acceleration_or_force, dst.acceleration_or_force, dynamic_memory);
        // primitive convert
        hako_convert_cpp2pdu(src.yaw, dst.yaw);
        // primitive convert
        hako_convert_cpp2pdu(src.yaw_rate, dst.yaw_rate);
    } catch (const std::runtime_error& e) {
        std::cerr << "convertor error: " << e.what() << std::endl;
        return false;
    }
    (void)dynamic_memory;
    return true;
}

static inline int hako_convert_cpp2pdu_GlobalPositionTarget(HakoCpp_GlobalPositionTarget &src, Hako_GlobalPositionTarget** dst)
{
    PduDynamicMemory dynamic_memory;
    Hako_GlobalPositionTarget out;
    if (!cpp_cpp2pdu_GlobalPositionTarget(src, out, dynamic_memory)) {
        return -1;
    }
    int heap_size = dynamic_memory.get_total_size();
    void* base_ptr = hako_create_empty_pdu(sizeof(Hako_GlobalPositionTarget), heap_size);
    if (base_ptr == nullptr) {
        return -1;
    }
    // Copy out on base data
    memcpy(base_ptr, (void*)&out, sizeof(Hako_GlobalPositionTarget));

    // Copy dynamic part and set offsets
    void* heap_ptr = hako_get_heap_ptr_pdu(base_ptr);
    dynamic_memory.copy_to_pdu((char*)heap_ptr);

    *dst = (Hako_GlobalPositionTarget*)base_ptr;
    return hako_get_pdu_meta_data(base_ptr)->total_size;
}

static inline Hako_GlobalPositionTarget* hako_create_empty_pdu_GlobalPositionTarget(int heap_size)
{
    // Allocate PDU memory
    char* base_ptr = (char*)hako_create_empty_pdu(sizeof(Hako_GlobalPositionTarget), heap_size);
    if (base_ptr == nullptr) {
        return nullptr;
    }
    return (Hako_GlobalPositionTarget*)base_ptr;
}
namespace hako::pdu::msgs::mavros_msgs
{
class GlobalPositionTarget
{
public:
    GlobalPositionTarget() = default;
    ~GlobalPositionTarget() = default;

    bool pdu2cpp(char* top_ptr, HakoCpp_GlobalPositionTarget& cppData)
    {
        char* base_ptr = (char*)hako_get_base_ptr_pdu((void*)top_ptr);
        if (base_ptr == nullptr) {
            std::cerr << "[ConvertorError][" << "GlobalPositionTarget" << "] hako_get_base_ptr_pdu returned null" << std::endl;
            return false;
        } 
        int ret = hako_convert_pdu2cpp_GlobalPositionTarget(*(Hako_GlobalPositionTarget*)base_ptr, cppData);
        if (ret != 0) {
            std::cerr << "[ConvertorError][" << "GlobalPositionTarget" << "] hako_convert_pdu2cpp returned " << ret << std::endl;
            return false;
        }
        return true;
    }

    int cpp2pdu(HakoCpp_GlobalPositionTarget& cppData, char* pdu_buffer, int buffer_len)
    {
        char* base_ptr = nullptr;
        int pdu_size = hako_convert_cpp2pdu_GlobalPositionTarget(cppData, (Hako_GlobalPositionTarget**)&base_ptr);
        if (pdu_size < 0) {
            std::cerr << "[ConvertorError][" << "GlobalPositionTarget" << "] hako_convert_cpp2pdu returned error code: " << pdu_size << std::endl;
            return -1;
        }
        if (pdu_size > buffer_len) {
            std::cerr << "[ConvertorError][" << "GlobalPositionTarget" << "] buffer too small. pdu_size=" << pdu_size << " buffer_len=" << buffer_len << std::endl;
            return -1;
        }
        void* top_ptr = hako_get_top_ptr_pdu((void*)base_ptr);
        if (top_ptr == nullptr) {
            std::cerr << "[ConvertorError][" << "GlobalPositionTarget" << "] hako_get_top_ptr_pdu returned null" << std::endl;
            return false;
        }
        memcpy(pdu_buffer, top_ptr, pdu_size);
        hako_destroy_pdu((void*)base_ptr);
        return pdu_size;
    }

private:
};
}


#endif /* _PDU_CPPTYPE_CONV_HAKO_mavros_msgs_GlobalPositionTarget_HPP_ */
