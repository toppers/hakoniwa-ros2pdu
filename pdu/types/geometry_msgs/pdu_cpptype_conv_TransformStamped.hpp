#ifndef _PDU_CPPTYPE_CONV_HAKO_geometry_msgs_TransformStamped_HPP_
#define _PDU_CPPTYPE_CONV_HAKO_geometry_msgs_TransformStamped_HPP_

#include "pdu_primitive_ctypes.h"
#include "pdu_primitive_ctypes_conv.hpp"
#include "pdu_dynamic_memory.hpp"
/*
 * Dependent pdu data
 */
#include "geometry_msgs/pdu_ctype_TransformStamped.h"
/*
 * Dependent cpp pdu data
 */
#include "geometry_msgs/pdu_cpptype_TransformStamped.hpp"

/*
 * Dependent Convertors
 */
#include "builtin_interfaces/pdu_cpptype_conv_Time.hpp"
#include "geometry_msgs/pdu_cpptype_conv_Quaternion.hpp"
#include "geometry_msgs/pdu_cpptype_conv_Transform.hpp"
#include "geometry_msgs/pdu_cpptype_conv_Vector3.hpp"
#include "std_msgs/pdu_cpptype_conv_Header.hpp"

/***************************
 *
 * PDU ==> CPP PDU
 *
 ***************************/

static inline int cpp_pdu2cpp_TransformStamped(const char* heap_ptr, Hako_TransformStamped &src, HakoCpp_TransformStamped &dst)
{
    // Struct convert
    cpp_pdu2cpp_Header(heap_ptr, src.header, dst.header);
    // string convertor
    dst.child_frame_id = (const char*)src.child_frame_id;
    // Struct convert
    cpp_pdu2cpp_Transform(heap_ptr, src.transform, dst.transform);
    (void)heap_ptr;
    return 0;
}

static inline int hako_convert_pdu2cpp_TransformStamped(Hako_TransformStamped &src, HakoCpp_TransformStamped &dst)
{
    void* base_ptr = (void*)&src;
    void* heap_ptr = hako_get_heap_ptr_pdu(base_ptr);
    // Validate magic number and version
    if (heap_ptr == nullptr) {
        return -1; // Invalid PDU metadata
    }
    else {
        return cpp_pdu2cpp_TransformStamped((char*)heap_ptr, src, dst);
    }
}

/***************************
 *
 * CPP PDU ==> PDU
 *
 ***************************/

static inline bool cpp_cpp2pdu_TransformStamped(HakoCpp_TransformStamped &src, Hako_TransformStamped &dst, PduDynamicMemory &dynamic_memory)
{
    try {
        // struct convert
        cpp_cpp2pdu_Header(src.header, dst.header, dynamic_memory);
        // string convertor
        (void)hako_convert_cpp2pdu_array(
            src.child_frame_id, src.child_frame_id.length(),
            dst.child_frame_id, M_ARRAY_SIZE(Hako_TransformStamped, char, child_frame_id));
        dst.child_frame_id[src.child_frame_id.length()] = '\0';
        // struct convert
        cpp_cpp2pdu_Transform(src.transform, dst.transform, dynamic_memory);
    } catch (const std::runtime_error& e) {
        std::cerr << "convertor error: " << e.what() << std::endl;
        return false;
    }
    (void)dynamic_memory;
    return true;
}

static inline int hako_convert_cpp2pdu_TransformStamped(HakoCpp_TransformStamped &src, Hako_TransformStamped** dst)
{
    PduDynamicMemory dynamic_memory;
    Hako_TransformStamped out;
    if (!cpp_cpp2pdu_TransformStamped(src, out, dynamic_memory)) {
        return -1;
    }
    int heap_size = dynamic_memory.get_total_size();
    void* base_ptr = hako_create_empty_pdu(sizeof(Hako_TransformStamped), heap_size);
    if (base_ptr == nullptr) {
        return -1;
    }
    // Copy out on base data
    memcpy(base_ptr, (void*)&out, sizeof(Hako_TransformStamped));

    // Copy dynamic part and set offsets
    void* heap_ptr = hako_get_heap_ptr_pdu(base_ptr);
    dynamic_memory.copy_to_pdu((char*)heap_ptr);

    *dst = (Hako_TransformStamped*)base_ptr;
    return hako_get_pdu_meta_data(base_ptr)->total_size;
}

static inline Hako_TransformStamped* hako_create_empty_pdu_TransformStamped(int heap_size)
{
    // Allocate PDU memory
    char* base_ptr = (char*)hako_create_empty_pdu(sizeof(Hako_TransformStamped), heap_size);
    if (base_ptr == nullptr) {
        return nullptr;
    }
    return (Hako_TransformStamped*)base_ptr;
}
namespace hako::pdu::msgs::geometry_msgs
{
class TransformStamped
{
public:
    TransformStamped() = default;
    ~TransformStamped() = default;

    bool pdu2cpp(char* top_ptr, HakoCpp_TransformStamped& cppData)
    {
        char* base_ptr = (char*)hako_get_base_ptr_pdu((void*)top_ptr);
        if (base_ptr == nullptr) {
            std::cerr << "[ConvertorError][" << "TransformStamped" << "] hako_get_base_ptr_pdu returned null" << std::endl;
            return false;
        } 
        int ret = hako_convert_pdu2cpp_TransformStamped(*(Hako_TransformStamped*)base_ptr, cppData);
        if (ret != 0) {
            std::cerr << "[ConvertorError][" << "TransformStamped" << "] hako_convert_pdu2cpp returned " << ret << std::endl;
            return false;
        }
        return true;
    }

    int cpp2pdu(HakoCpp_TransformStamped& cppData, char* pdu_buffer, int buffer_len)
    {
        char* base_ptr = nullptr;
        int pdu_size = hako_convert_cpp2pdu_TransformStamped(cppData, (Hako_TransformStamped**)&base_ptr);
        if (pdu_size < 0) {
            std::cerr << "[ConvertorError][" << "TransformStamped" << "] hako_convert_cpp2pdu returned error code: " << pdu_size << std::endl;
            return -1;
        }
        if (pdu_size > buffer_len) {
            std::cerr << "[ConvertorError][" << "TransformStamped" << "] buffer too small. pdu_size=" << pdu_size << " buffer_len=" << buffer_len << std::endl;
            return -1;
        }
        void* top_ptr = hako_get_top_ptr_pdu((void*)base_ptr);
        if (top_ptr == nullptr) {
            std::cerr << "[ConvertorError][" << "TransformStamped" << "] hako_get_top_ptr_pdu returned null" << std::endl;
            return false;
        }
        memcpy(pdu_buffer, top_ptr, pdu_size);
        hako_destroy_pdu((void*)base_ptr);
        return pdu_size;
    }

private:
};
}


#endif /* _PDU_CPPTYPE_CONV_HAKO_geometry_msgs_TransformStamped_HPP_ */
