#ifndef _PDU_CPPTYPE_CONV_HAKO_nav_msgs_Odometry_HPP_
#define _PDU_CPPTYPE_CONV_HAKO_nav_msgs_Odometry_HPP_

#include "pdu_primitive_ctypes.h"
#include "pdu_primitive_ctypes_conv.hpp"
#include "pdu_dynamic_memory.hpp"
/*
 * Dependent pdu data
 */
#include "nav_msgs/pdu_ctype_Odometry.h"
/*
 * Dependent cpp pdu data
 */
#include "nav_msgs/pdu_cpptype_Odometry.hpp"

/*
 * Dependent Convertors
 */
#include "builtin_interfaces/pdu_cpptype_conv_Time.hpp"
#include "geometry_msgs/pdu_cpptype_conv_Point.hpp"
#include "geometry_msgs/pdu_cpptype_conv_Pose.hpp"
#include "geometry_msgs/pdu_cpptype_conv_PoseWithCovariance.hpp"
#include "geometry_msgs/pdu_cpptype_conv_Quaternion.hpp"
#include "geometry_msgs/pdu_cpptype_conv_Twist.hpp"
#include "geometry_msgs/pdu_cpptype_conv_TwistWithCovariance.hpp"
#include "geometry_msgs/pdu_cpptype_conv_Vector3.hpp"
#include "std_msgs/pdu_cpptype_conv_Header.hpp"

/***************************
 *
 * PDU ==> CPP PDU
 *
 ***************************/

static inline int cpp_pdu2cpp_Odometry(const char* heap_ptr, Hako_Odometry &src, HakoCpp_Odometry &dst)
{
    // Struct convert
    cpp_pdu2cpp_Header(heap_ptr, src.header, dst.header);
    // string convertor
    dst.child_frame_id = (const char*)src.child_frame_id;
    // Struct convert
    cpp_pdu2cpp_PoseWithCovariance(heap_ptr, src.pose, dst.pose);
    // Struct convert
    cpp_pdu2cpp_TwistWithCovariance(heap_ptr, src.twist, dst.twist);
    (void)heap_ptr;
    return 0;
}

static inline int hako_convert_pdu2cpp_Odometry(Hako_Odometry &src, HakoCpp_Odometry &dst)
{
    void* base_ptr = (void*)&src;
    void* heap_ptr = hako_get_heap_ptr_pdu(base_ptr);
    // Validate magic number and version
    if (heap_ptr == nullptr) {
        return -1; // Invalid PDU metadata
    }
    else {
        return cpp_pdu2cpp_Odometry((char*)heap_ptr, src, dst);
    }
}

/***************************
 *
 * CPP PDU ==> PDU
 *
 ***************************/

static inline bool cpp_cpp2pdu_Odometry(HakoCpp_Odometry &src, Hako_Odometry &dst, PduDynamicMemory &dynamic_memory)
{
    try {
        // struct convert
        cpp_cpp2pdu_Header(src.header, dst.header, dynamic_memory);
        // string convertor
        (void)hako_convert_cpp2pdu_array(
            src.child_frame_id, src.child_frame_id.length(),
            dst.child_frame_id, M_ARRAY_SIZE(Hako_Odometry, char, child_frame_id));
        dst.child_frame_id[src.child_frame_id.length()] = '\0';
        // struct convert
        cpp_cpp2pdu_PoseWithCovariance(src.pose, dst.pose, dynamic_memory);
        // struct convert
        cpp_cpp2pdu_TwistWithCovariance(src.twist, dst.twist, dynamic_memory);
    } catch (const std::runtime_error& e) {
        std::cerr << "convertor error: " << e.what() << std::endl;
        return false;
    }
    (void)dynamic_memory;
    return true;
}

static inline int hako_convert_cpp2pdu_Odometry(HakoCpp_Odometry &src, Hako_Odometry** dst)
{
    PduDynamicMemory dynamic_memory;
    Hako_Odometry out;
    if (!cpp_cpp2pdu_Odometry(src, out, dynamic_memory)) {
        return -1;
    }
    int heap_size = dynamic_memory.get_total_size();
    void* base_ptr = hako_create_empty_pdu(sizeof(Hako_Odometry), heap_size);
    if (base_ptr == nullptr) {
        return -1;
    }
    // Copy out on base data
    memcpy(base_ptr, (void*)&out, sizeof(Hako_Odometry));

    // Copy dynamic part and set offsets
    void* heap_ptr = hako_get_heap_ptr_pdu(base_ptr);
    dynamic_memory.copy_to_pdu((char*)heap_ptr);

    *dst = (Hako_Odometry*)base_ptr;
    return hako_get_pdu_meta_data(base_ptr)->total_size;
}

static inline Hako_Odometry* hako_create_empty_pdu_Odometry(int heap_size)
{
    // Allocate PDU memory
    char* base_ptr = (char*)hako_create_empty_pdu(sizeof(Hako_Odometry), heap_size);
    if (base_ptr == nullptr) {
        return nullptr;
    }
    return (Hako_Odometry*)base_ptr;
}
namespace hako::pdu::msgs::nav_msgs
{
class Odometry
{
public:
    Odometry() = default;
    ~Odometry() = default;

    bool pdu2cpp(char* top_ptr, HakoCpp_Odometry& cppData)
    {
        char* base_ptr = (char*)hako_get_base_ptr_pdu((void*)top_ptr);
        if (base_ptr == nullptr) {
            std::cerr << "[ConvertorError][" << "Odometry" << "] hako_get_base_ptr_pdu returned null" << std::endl;
            return false;
        } 
        int ret = hako_convert_pdu2cpp_Odometry(*(Hako_Odometry*)base_ptr, cppData);
        if (ret != 0) {
            std::cerr << "[ConvertorError][" << "Odometry" << "] hako_convert_pdu2cpp returned " << ret << std::endl;
            return false;
        }
        return true;
    }

    int cpp2pdu(HakoCpp_Odometry& cppData, char* pdu_buffer, int buffer_len)
    {
        char* base_ptr = nullptr;
        int pdu_size = hako_convert_cpp2pdu_Odometry(cppData, (Hako_Odometry**)&base_ptr);
        if (pdu_size < 0) {
            std::cerr << "[ConvertorError][" << "Odometry" << "] hako_convert_cpp2pdu returned error code: " << pdu_size << std::endl;
            return -1;
        }
        if (pdu_size > buffer_len) {
            std::cerr << "[ConvertorError][" << "Odometry" << "] buffer too small. pdu_size=" << pdu_size << " buffer_len=" << buffer_len << std::endl;
            return -1;
        }
        void* top_ptr = hako_get_top_ptr_pdu((void*)base_ptr);
        if (top_ptr == nullptr) {
            std::cerr << "[ConvertorError][" << "Odometry" << "] hako_get_top_ptr_pdu returned null" << std::endl;
            return false;
        }
        memcpy(pdu_buffer, top_ptr, pdu_size);
        hako_destroy_pdu((void*)base_ptr);
        return pdu_size;
    }

private:
};
}


#endif /* _PDU_CPPTYPE_CONV_HAKO_nav_msgs_Odometry_HPP_ */
