#ifndef _PDU_CPPTYPE_CONV_HAKO_drone_srv_msgs_DroneGoToRequest_HPP_
#define _PDU_CPPTYPE_CONV_HAKO_drone_srv_msgs_DroneGoToRequest_HPP_

#include "pdu_primitive_ctypes.h"
#include "pdu_primitive_ctypes_conv.hpp"
#include "pdu_dynamic_memory.hpp"
/*
 * Dependent pdu data
 */
#include "drone_srv_msgs/pdu_ctype_DroneGoToRequest.h"
/*
 * Dependent cpp pdu data
 */
#include "drone_srv_msgs/pdu_cpptype_DroneGoToRequest.hpp"

/*
 * Dependent Convertors
 */
#include "geometry_msgs/pdu_cpptype_conv_Vector3.hpp"

/***************************
 *
 * PDU ==> CPP PDU
 *
 ***************************/

static inline int cpp_pdu2cpp_DroneGoToRequest(const char* heap_ptr, Hako_DroneGoToRequest &src, HakoCpp_DroneGoToRequest &dst)
{
    // string convertor
    dst.drone_name = (const char*)src.drone_name;
    // Struct convert
    cpp_pdu2cpp_Vector3(heap_ptr, src.target_pose, dst.target_pose);
    // primitive convert
    hako_convert_pdu2cpp(src.speed_m_s, dst.speed_m_s);
    // primitive convert
    hako_convert_pdu2cpp(src.yaw_deg, dst.yaw_deg);
    // primitive convert
    hako_convert_pdu2cpp(src.tolerance_m, dst.tolerance_m);
    // primitive convert
    hako_convert_pdu2cpp(src.timeout_sec, dst.timeout_sec);
    (void)heap_ptr;
    return 0;
}

static inline int hako_convert_pdu2cpp_DroneGoToRequest(Hako_DroneGoToRequest &src, HakoCpp_DroneGoToRequest &dst)
{
    void* base_ptr = (void*)&src;
    void* heap_ptr = hako_get_heap_ptr_pdu(base_ptr);
    // Validate magic number and version
    if (heap_ptr == nullptr) {
        return -1; // Invalid PDU metadata
    }
    else {
        return cpp_pdu2cpp_DroneGoToRequest((char*)heap_ptr, src, dst);
    }
}

/***************************
 *
 * CPP PDU ==> PDU
 *
 ***************************/

static inline bool cpp_cpp2pdu_DroneGoToRequest(HakoCpp_DroneGoToRequest &src, Hako_DroneGoToRequest &dst, PduDynamicMemory &dynamic_memory)
{
    try {
        // string convertor
        (void)hako_convert_cpp2pdu_array(
            src.drone_name, src.drone_name.length(),
            dst.drone_name, M_ARRAY_SIZE(Hako_DroneGoToRequest, char, drone_name));
        dst.drone_name[src.drone_name.length()] = '\0';
        // struct convert
        cpp_cpp2pdu_Vector3(src.target_pose, dst.target_pose, dynamic_memory);
        // primitive convert
        hako_convert_cpp2pdu(src.speed_m_s, dst.speed_m_s);
        // primitive convert
        hako_convert_cpp2pdu(src.yaw_deg, dst.yaw_deg);
        // primitive convert
        hako_convert_cpp2pdu(src.tolerance_m, dst.tolerance_m);
        // primitive convert
        hako_convert_cpp2pdu(src.timeout_sec, dst.timeout_sec);
    } catch (const std::runtime_error& e) {
        std::cerr << "convertor error: " << e.what() << std::endl;
        return false;
    }
    (void)dynamic_memory;
    return true;
}

static inline int hako_convert_cpp2pdu_DroneGoToRequest(HakoCpp_DroneGoToRequest &src, Hako_DroneGoToRequest** dst)
{
    PduDynamicMemory dynamic_memory;
    Hako_DroneGoToRequest out;
    if (!cpp_cpp2pdu_DroneGoToRequest(src, out, dynamic_memory)) {
        return -1;
    }
    int heap_size = dynamic_memory.get_total_size();
    void* base_ptr = hako_create_empty_pdu(sizeof(Hako_DroneGoToRequest), heap_size);
    if (base_ptr == nullptr) {
        return -1;
    }
    // Copy out on base data
    memcpy(base_ptr, (void*)&out, sizeof(Hako_DroneGoToRequest));

    // Copy dynamic part and set offsets
    void* heap_ptr = hako_get_heap_ptr_pdu(base_ptr);
    dynamic_memory.copy_to_pdu((char*)heap_ptr);

    *dst = (Hako_DroneGoToRequest*)base_ptr;
    return hako_get_pdu_meta_data(base_ptr)->total_size;
}

static inline Hako_DroneGoToRequest* hako_create_empty_pdu_DroneGoToRequest(int heap_size)
{
    // Allocate PDU memory
    char* base_ptr = (char*)hako_create_empty_pdu(sizeof(Hako_DroneGoToRequest), heap_size);
    if (base_ptr == nullptr) {
        return nullptr;
    }
    return (Hako_DroneGoToRequest*)base_ptr;
}
namespace hako::pdu::msgs::drone_srv_msgs
{
class DroneGoToRequest
{
public:
    DroneGoToRequest() = default;
    ~DroneGoToRequest() = default;

    bool pdu2cpp(char* top_ptr, HakoCpp_DroneGoToRequest& cppData)
    {
        char* base_ptr = (char*)hako_get_base_ptr_pdu((void*)top_ptr);
        if (base_ptr == nullptr) {
            std::cerr << "[ConvertorError][" << "DroneGoToRequest" << "] hako_get_base_ptr_pdu returned null" << std::endl;
            return false;
        } 
        int ret = hako_convert_pdu2cpp_DroneGoToRequest(*(Hako_DroneGoToRequest*)base_ptr, cppData);
        if (ret != 0) {
            std::cerr << "[ConvertorError][" << "DroneGoToRequest" << "] hako_convert_pdu2cpp returned " << ret << std::endl;
            return false;
        }
        return true;
    }

    int cpp2pdu(HakoCpp_DroneGoToRequest& cppData, char* pdu_buffer, int buffer_len)
    {
        char* base_ptr = nullptr;
        int pdu_size = hako_convert_cpp2pdu_DroneGoToRequest(cppData, (Hako_DroneGoToRequest**)&base_ptr);
        if (pdu_size < 0) {
            std::cerr << "[ConvertorError][" << "DroneGoToRequest" << "] hako_convert_cpp2pdu returned error code: " << pdu_size << std::endl;
            return -1;
        }
        if (pdu_size > buffer_len) {
            std::cerr << "[ConvertorError][" << "DroneGoToRequest" << "] buffer too small. pdu_size=" << pdu_size << " buffer_len=" << buffer_len << std::endl;
            return -1;
        }
        void* top_ptr = hako_get_top_ptr_pdu((void*)base_ptr);
        if (top_ptr == nullptr) {
            std::cerr << "[ConvertorError][" << "DroneGoToRequest" << "] hako_get_top_ptr_pdu returned null" << std::endl;
            return -1;
        }
        memcpy(pdu_buffer, top_ptr, pdu_size);
        hako_destroy_pdu((void*)base_ptr);
        return pdu_size;
    }

private:
};
}


#endif /* _PDU_CPPTYPE_CONV_HAKO_drone_srv_msgs_DroneGoToRequest_HPP_ */
