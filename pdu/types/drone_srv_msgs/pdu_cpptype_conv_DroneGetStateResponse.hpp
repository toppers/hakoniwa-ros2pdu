#ifndef _PDU_CPPTYPE_CONV_HAKO_drone_srv_msgs_DroneGetStateResponse_HPP_
#define _PDU_CPPTYPE_CONV_HAKO_drone_srv_msgs_DroneGetStateResponse_HPP_

#include "pdu_primitive_ctypes.h"
#include "pdu_primitive_ctypes_conv.hpp"
#include "pdu_dynamic_memory.hpp"
/*
 * Dependent pdu data
 */
#include "drone_srv_msgs/pdu_ctype_DroneGetStateResponse.h"
/*
 * Dependent cpp pdu data
 */
#include "drone_srv_msgs/pdu_cpptype_DroneGetStateResponse.hpp"

/*
 * Dependent Convertors
 */
#include "geometry_msgs/pdu_cpptype_conv_Point.hpp"
#include "geometry_msgs/pdu_cpptype_conv_Pose.hpp"
#include "geometry_msgs/pdu_cpptype_conv_Quaternion.hpp"
#include "hako_msgs/pdu_cpptype_conv_HakoBatteryStatus.hpp"

/***************************
 *
 * PDU ==> CPP PDU
 *
 ***************************/

static inline int cpp_pdu2cpp_DroneGetStateResponse(const char* heap_ptr, Hako_DroneGetStateResponse &src, HakoCpp_DroneGetStateResponse &dst)
{
    // primitive convert
    hako_convert_pdu2cpp(src.ok, dst.ok);
    // primitive convert
    hako_convert_pdu2cpp(src.is_ready, dst.is_ready);
    // Struct convert
    cpp_pdu2cpp_Pose(heap_ptr, src.current_pose, dst.current_pose);
    // Struct convert
    cpp_pdu2cpp_HakoBatteryStatus(heap_ptr, src.battery_status, dst.battery_status);
    // string convertor
    dst.mode = (const char*)src.mode;
    // string convertor
    dst.message = (const char*)src.message;
    (void)heap_ptr;
    return 0;
}

static inline int hako_convert_pdu2cpp_DroneGetStateResponse(Hako_DroneGetStateResponse &src, HakoCpp_DroneGetStateResponse &dst)
{
    void* base_ptr = (void*)&src;
    void* heap_ptr = hako_get_heap_ptr_pdu(base_ptr);
    // Validate magic number and version
    if (heap_ptr == nullptr) {
        return -1; // Invalid PDU metadata
    }
    else {
        return cpp_pdu2cpp_DroneGetStateResponse((char*)heap_ptr, src, dst);
    }
}

/***************************
 *
 * CPP PDU ==> PDU
 *
 ***************************/

static inline bool cpp_cpp2pdu_DroneGetStateResponse(HakoCpp_DroneGetStateResponse &src, Hako_DroneGetStateResponse &dst, PduDynamicMemory &dynamic_memory)
{
    try {
        // primitive convert
        hako_convert_cpp2pdu(src.ok, dst.ok);
        // primitive convert
        hako_convert_cpp2pdu(src.is_ready, dst.is_ready);
        // struct convert
        cpp_cpp2pdu_Pose(src.current_pose, dst.current_pose, dynamic_memory);
        // struct convert
        cpp_cpp2pdu_HakoBatteryStatus(src.battery_status, dst.battery_status, dynamic_memory);
        // string convertor
        (void)hako_convert_cpp2pdu_array(
            src.mode, src.mode.length(),
            dst.mode, M_ARRAY_SIZE(Hako_DroneGetStateResponse, char, mode));
        dst.mode[src.mode.length()] = '\0';
        // string convertor
        (void)hako_convert_cpp2pdu_array(
            src.message, src.message.length(),
            dst.message, M_ARRAY_SIZE(Hako_DroneGetStateResponse, char, message));
        dst.message[src.message.length()] = '\0';
    } catch (const std::runtime_error& e) {
        std::cerr << "convertor error: " << e.what() << std::endl;
        return false;
    }
    (void)dynamic_memory;
    return true;
}

static inline int hako_convert_cpp2pdu_DroneGetStateResponse(HakoCpp_DroneGetStateResponse &src, Hako_DroneGetStateResponse** dst)
{
    PduDynamicMemory dynamic_memory;
    Hako_DroneGetStateResponse out;
    if (!cpp_cpp2pdu_DroneGetStateResponse(src, out, dynamic_memory)) {
        return -1;
    }
    int heap_size = dynamic_memory.get_total_size();
    void* base_ptr = hako_create_empty_pdu(sizeof(Hako_DroneGetStateResponse), heap_size);
    if (base_ptr == nullptr) {
        return -1;
    }
    // Copy out on base data
    memcpy(base_ptr, (void*)&out, sizeof(Hako_DroneGetStateResponse));

    // Copy dynamic part and set offsets
    void* heap_ptr = hako_get_heap_ptr_pdu(base_ptr);
    dynamic_memory.copy_to_pdu((char*)heap_ptr);

    *dst = (Hako_DroneGetStateResponse*)base_ptr;
    return hako_get_pdu_meta_data(base_ptr)->total_size;
}

static inline Hako_DroneGetStateResponse* hako_create_empty_pdu_DroneGetStateResponse(int heap_size)
{
    // Allocate PDU memory
    char* base_ptr = (char*)hako_create_empty_pdu(sizeof(Hako_DroneGetStateResponse), heap_size);
    if (base_ptr == nullptr) {
        return nullptr;
    }
    return (Hako_DroneGetStateResponse*)base_ptr;
}
namespace hako::pdu::msgs::drone_srv_msgs
{
class DroneGetStateResponse
{
public:
    DroneGetStateResponse() = default;
    ~DroneGetStateResponse() = default;

    bool pdu2cpp(char* top_ptr, HakoCpp_DroneGetStateResponse& cppData)
    {
        char* base_ptr = (char*)hako_get_base_ptr_pdu((void*)top_ptr);
        if (base_ptr == nullptr) {
            std::cerr << "[ConvertorError][" << "DroneGetStateResponse" << "] hako_get_base_ptr_pdu returned null" << std::endl;
            return false;
        } 
        int ret = hako_convert_pdu2cpp_DroneGetStateResponse(*(Hako_DroneGetStateResponse*)base_ptr, cppData);
        if (ret != 0) {
            std::cerr << "[ConvertorError][" << "DroneGetStateResponse" << "] hako_convert_pdu2cpp returned " << ret << std::endl;
            return false;
        }
        return true;
    }

    int cpp2pdu(HakoCpp_DroneGetStateResponse& cppData, char* pdu_buffer, int buffer_len)
    {
        char* base_ptr = nullptr;
        int pdu_size = hako_convert_cpp2pdu_DroneGetStateResponse(cppData, (Hako_DroneGetStateResponse**)&base_ptr);
        if (pdu_size < 0) {
            std::cerr << "[ConvertorError][" << "DroneGetStateResponse" << "] hako_convert_cpp2pdu returned error code: " << pdu_size << std::endl;
            return -1;
        }
        if (pdu_size > buffer_len) {
            std::cerr << "[ConvertorError][" << "DroneGetStateResponse" << "] buffer too small. pdu_size=" << pdu_size << " buffer_len=" << buffer_len << std::endl;
            return -1;
        }
        void* top_ptr = hako_get_top_ptr_pdu((void*)base_ptr);
        if (top_ptr == nullptr) {
            std::cerr << "[ConvertorError][" << "DroneGetStateResponse" << "] hako_get_top_ptr_pdu returned null" << std::endl;
            return -1;
        }
        memcpy(pdu_buffer, top_ptr, pdu_size);
        hako_destroy_pdu((void*)base_ptr);
        return pdu_size;
    }

private:
};
}


#endif /* _PDU_CPPTYPE_CONV_HAKO_drone_srv_msgs_DroneGetStateResponse_HPP_ */
