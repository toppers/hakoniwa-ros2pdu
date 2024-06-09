#ifndef _PDU_CTYPE_CONV_HAKO_std_msgs_Header_HPP_
#define _PDU_CTYPE_CONV_HAKO_std_msgs_Header_HPP_

#include "pdu_primitive_ctypes.h"
#include "ros_primitive_types.hpp"
#include "pdu_primitive_ctypes_conv.hpp"
#include "pdu_dynamic_memory.hpp"
/*
 * Dependent pdu data
 */
#include "std_msgs/pdu_ctype_Header.h"
/*
 * Dependent ros data
 */
#include "std_msgs/msg/header.hpp"

/*
 * Dependent Convertors
 */
#include "builtin_interfaces/pdu_ctype_conv_Time.hpp"

/***************************
 *
 * PDU ==> ROS2
 *
 ***************************/

static inline int _pdu2ros_Header(const char* varray_ptr, Hako_Header &src, std_msgs::msg::Header &dst)
{
    // Struct convert
    _pdu2ros_Time(varray_ptr, src.stamp, dst.stamp);
    // string convertor
    dst.frame_id = (const char*)src.frame_id;
    (void)varray_ptr;
    return 0;
}

static inline int hako_convert_pdu2ros_Header(Hako_Header &src, std_msgs::msg::Header &dst)
{
    char* base_ptr = (char*)&src;
    HakoPduMetaDataType* meta = (HakoPduMetaDataType*)(base_ptr + sizeof(Hako_Header));

    // Validate magic number and version
    if ((meta->magicno != HAKO_PDU_META_DATA_MAGICNO) || (meta->version != HAKO_PDU_META_DATA_VERSION)) {
        return -1; // Invalid PDU metadata
    }
    else {
        char *varray_ptr = base_ptr + sizeof(Hako_Header) + sizeof(HakoPduMetaDataType);
        return _pdu2ros_Header(varray_ptr, src, dst);
    }
}

/***************************
 *
 * ROS2 ==> PDU
 *
 ***************************/

static inline bool _ros2pdu_Header(std_msgs::msg::Header &src, Hako_Header &dst, PduDynamicMemory &dynamic_memory)
{
    try {
        // struct convert
        _ros2pdu_Time(src.stamp, dst.stamp, dynamic_memory);
        // string convertor
        (void)hako_convert_ros2pdu_array(
            src.frame_id, src.frame_id.length(),
            dst.frame_id, M_ARRAY_SIZE(Hako_Header, char, frame_id));
    } catch (const std::runtime_error& e) {
        std::cerr << "convertor error: " << e.what() << std::endl;
        return false;
    }
    (void)dynamic_memory;
    return true;
}

static inline int hako_convert_ros2pdu_Header(std_msgs::msg::Header &src, Hako_Header** dst)
{
    PduDynamicMemory dynamic_memory;
    Hako_Header out;
    if (!_ros2pdu_Header(src, out, dynamic_memory)) {
        return -1;
    }
    int total_size = sizeof(Hako_Header) + sizeof(HakoPduMetaDataType) + dynamic_memory.get_total_size();

    // Allocate PDU memory
    char* base_ptr = (char*)malloc(total_size);
    if (base_ptr == nullptr) {
        return -1;
    }
    // Copy out on top
    memcpy(base_ptr, (void*)&out, sizeof(Hako_Header));

    // Set metadata at the end
    HakoPduMetaDataType* meta = (HakoPduMetaDataType*)(base_ptr + sizeof(Hako_Header));
    meta->magicno = HAKO_PDU_META_DATA_MAGICNO;
    meta->version = HAKO_PDU_META_DATA_VERSION;
    meta->top_off = 0;
    meta->total_size = total_size;
    meta->varray_off = sizeof(Hako_Header) + sizeof(HakoPduMetaDataType);

    // Copy dynamic part and set offsets
    dynamic_memory.copy_to_pdu(base_ptr + meta->varray_off);

    *dst = (Hako_Header*)base_ptr;
    return total_size;
}
static inline Hako_Header* hako_create_empty_pdu_Header(int heap_size)
{
    int total_size = sizeof(Hako_Header) + sizeof(HakoPduMetaDataType) + heap_size;

    // Allocate PDU memory
    char* base_ptr = (char*)malloc(total_size);
    if (base_ptr == nullptr) {
        return nullptr;
    }
    memset(base_ptr, 0, total_size);
    // Set metadata at the end
    HakoPduMetaDataType* meta = (HakoPduMetaDataType*)(base_ptr + sizeof(Hako_Header));
    meta->magicno = HAKO_PDU_META_DATA_MAGICNO;
    meta->version = HAKO_PDU_META_DATA_VERSION;
    meta->top_off = 0;
    meta->total_size = total_size;
    meta->varray_off = sizeof(Hako_Header) + sizeof(HakoPduMetaDataType);
    return (Hako_Header*)base_ptr;
}
#endif /* _PDU_CTYPE_CONV_HAKO_std_msgs_Header_HPP_ */
