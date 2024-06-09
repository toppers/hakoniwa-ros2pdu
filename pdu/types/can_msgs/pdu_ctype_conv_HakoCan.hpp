#ifndef _PDU_CTYPE_CONV_HAKO_can_msgs_HakoCan_HPP_
#define _PDU_CTYPE_CONV_HAKO_can_msgs_HakoCan_HPP_

#include "pdu_primitive_ctypes.h"
#include "ros_primitive_types.hpp"
#include "pdu_primitive_ctypes_conv.hpp"
#include "pdu_dynamic_memory.hpp"
/*
 * Dependent pdu data
 */
#include "can_msgs/pdu_ctype_HakoCan.h"
/*
 * Dependent ros data
 */
#include "can_msgs/msg/hako_can.hpp"

/*
 * Dependent Convertors
 */
#include "can_msgs/pdu_ctype_conv_HakoCanBody.hpp"
#include "can_msgs/pdu_ctype_conv_HakoCanHead.hpp"

/***************************
 *
 * PDU ==> ROS2
 *
 ***************************/

static inline int _pdu2ros_HakoCan(const char* varray_ptr, Hako_HakoCan &src, can_msgs::msg::HakoCan &dst)
{
    // Struct convert
    _pdu2ros_HakoCanHead(varray_ptr, src.head, dst.head);
    // Struct convert
    _pdu2ros_HakoCanBody(varray_ptr, src.body, dst.body);
    (void)varray_ptr;
    return 0;
}

static inline int hako_convert_pdu2ros_HakoCan(Hako_HakoCan &src, can_msgs::msg::HakoCan &dst)
{
    char* base_ptr = (char*)&src;
    HakoPduMetaDataType* meta = (HakoPduMetaDataType*)(base_ptr + sizeof(Hako_HakoCan));

    // Validate magic number and version
    if ((meta->magicno != HAKO_PDU_META_DATA_MAGICNO) || (meta->version != HAKO_PDU_META_DATA_VERSION)) {
        return -1; // Invalid PDU metadata
    }
    else {
        char *varray_ptr = base_ptr + sizeof(Hako_HakoCan) + sizeof(HakoPduMetaDataType);
        return _pdu2ros_HakoCan(varray_ptr, src, dst);
    }
}

/***************************
 *
 * ROS2 ==> PDU
 *
 ***************************/

static inline bool _ros2pdu_HakoCan(can_msgs::msg::HakoCan &src, Hako_HakoCan &dst, PduDynamicMemory &dynamic_memory)
{
    try {
        // struct convert
        _ros2pdu_HakoCanHead(src.head, dst.head, dynamic_memory);
        // struct convert
        _ros2pdu_HakoCanBody(src.body, dst.body, dynamic_memory);
    } catch (const std::runtime_error& e) {
        std::cerr << "convertor error: " << e.what() << std::endl;
        return false;
    }
    (void)dynamic_memory;
    return true;
}

static inline int hako_convert_ros2pdu_HakoCan(can_msgs::msg::HakoCan &src, Hako_HakoCan** dst)
{
    PduDynamicMemory dynamic_memory;
    Hako_HakoCan out;
    if (!_ros2pdu_HakoCan(src, out, dynamic_memory)) {
        return -1;
    }
    int total_size = sizeof(Hako_HakoCan) + sizeof(HakoPduMetaDataType) + dynamic_memory.get_total_size();

    // Allocate PDU memory
    char* base_ptr = (char*)malloc(total_size);
    if (base_ptr == nullptr) {
        return -1;
    }
    // Copy out on top
    memcpy(base_ptr, (void*)&out, sizeof(Hako_HakoCan));

    // Set metadata at the end
    HakoPduMetaDataType* meta = (HakoPduMetaDataType*)(base_ptr + sizeof(Hako_HakoCan));
    meta->magicno = HAKO_PDU_META_DATA_MAGICNO;
    meta->version = HAKO_PDU_META_DATA_VERSION;
    meta->top_off = 0;
    meta->total_size = total_size;
    meta->varray_off = sizeof(Hako_HakoCan) + sizeof(HakoPduMetaDataType);

    // Copy dynamic part and set offsets
    dynamic_memory.copy_to_pdu(base_ptr + meta->varray_off);

    *dst = (Hako_HakoCan*)base_ptr;
    return total_size;
}
static inline Hako_HakoCan* hako_create_empty_pdu_HakoCan(int heap_size)
{
    int total_size = sizeof(Hako_HakoCan) + sizeof(HakoPduMetaDataType) + heap_size;

    // Allocate PDU memory
    char* base_ptr = (char*)malloc(total_size);
    if (base_ptr == nullptr) {
        return nullptr;
    }
    memset(base_ptr, 0, total_size);
    // Set metadata at the end
    HakoPduMetaDataType* meta = (HakoPduMetaDataType*)(base_ptr + sizeof(Hako_HakoCan));
    meta->magicno = HAKO_PDU_META_DATA_MAGICNO;
    meta->version = HAKO_PDU_META_DATA_VERSION;
    meta->top_off = 0;
    meta->total_size = total_size;
    meta->varray_off = sizeof(Hako_HakoCan) + sizeof(HakoPduMetaDataType);
    return (Hako_HakoCan*)base_ptr;
}
#endif /* _PDU_CTYPE_CONV_HAKO_can_msgs_HakoCan_HPP_ */
