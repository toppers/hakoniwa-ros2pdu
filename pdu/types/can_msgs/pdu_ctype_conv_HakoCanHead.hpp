#ifndef _PDU_CTYPE_CONV_HAKO_can_msgs_HakoCanHead_HPP_
#define _PDU_CTYPE_CONV_HAKO_can_msgs_HakoCanHead_HPP_

#include "pdu_primitive_ctypes.h"
#include "ros_primitive_types.hpp"
#include "pdu_primitive_ctypes_conv.hpp"
#include "pdu_dynamic_memory.hpp"
/*
 * Dependent pdu data
 */
#include "can_msgs/pdu_ctype_HakoCanHead.h"
/*
 * Dependent ros data
 */
#include "can_msgs/msg/hako_can_head.hpp"

/*
 * Dependent Convertors
 */

/***************************
 *
 * PDU ==> ROS2
 *
 ***************************/

static inline int _pdu2ros_HakoCanHead(const char* varray_ptr, Hako_HakoCanHead &src, can_msgs::msg::HakoCanHead &dst)
{
    // primitive convert
    hako_convert_pdu2ros(src.channel, dst.channel);
    // primitive convert
    hako_convert_pdu2ros(src.ide, dst.ide);
    // primitive convert
    hako_convert_pdu2ros(src.rtr, dst.rtr);
    // primitive convert
    hako_convert_pdu2ros(src.dlc, dst.dlc);
    // primitive convert
    hako_convert_pdu2ros(src.canid, dst.canid);
    return 0;
}

static inline int hako_convert_pdu2ros_HakoCanHead(Hako_HakoCanHead &src, can_msgs::msg::HakoCanHead &dst)
{
    char* base_ptr = (char*)&src;
    HakoPduMetaDataType* meta = (HakoPduMetaDataType*)(base_ptr + sizeof(Hako_HakoCanHead));

    // Validate magic number and version
    if ((meta->magicno != HAKO_PDU_META_DATA_MAGICNO) || (meta->version != HAKO_PDU_META_DATA_VERSION)) {
        return -1; // Invalid PDU metadata
    }
    else {
        char *varray_ptr = base_ptr + sizeof(Hako_HakoCanHead) + sizeof(HakoPduMetaDataType);
        return _pdu2ros_HakoCanHead(varray_ptr, src, dst);
    }
}

/***************************
 *
 * ROS2 ==> PDU
 *
 ***************************/

static inline bool _ros2pdu_HakoCanHead(can_msgs::msg::HakoCanHead &src, Hako_HakoCanHead &dst, PduDynamicMemory &dynamic_memory)
{
    try {
        // primitive convert
        hako_convert_ros2pdu(src.channel, dst.channel);
        // primitive convert
        hako_convert_ros2pdu(src.ide, dst.ide);
        // primitive convert
        hako_convert_ros2pdu(src.rtr, dst.rtr);
        // primitive convert
        hako_convert_ros2pdu(src.dlc, dst.dlc);
        // primitive convert
        hako_convert_ros2pdu(src.canid, dst.canid);
    } catch (const std::runtime_error& e) {
        std::cerr << "convertor error: " << e.what() << std::endl;
        return false;
    }
    return true;
}

static inline int hako_convert_ros2pdu_HakoCanHead(can_msgs::msg::HakoCanHead &src, Hako_HakoCanHead** dst)
{
    PduDynamicMemory dynamic_memory;
    Hako_HakoCanHead out;
    if (!_ros2pdu_HakoCanHead(src, out, dynamic_memory)) {
        return -1;
    }
    int total_size = sizeof(Hako_HakoCanHead) + sizeof(HakoPduMetaDataType) + dynamic_memory.get_total_size();

    // Allocate PDU memory
    char* base_ptr = (char*)malloc(total_size);
    if (base_ptr == nullptr) {
        return -1;
    }
    // Copy out on top
    memcpy(base_ptr, (void*)&out, sizeof(Hako_HakoCanHead));

    // Set metadata at the end
    HakoPduMetaDataType* meta = (HakoPduMetaDataType*)(base_ptr + sizeof(Hako_HakoCanHead));
    meta->magicno = HAKO_PDU_META_DATA_MAGICNO;
    meta->version = HAKO_PDU_META_DATA_VERSION;
    meta->top_off = 0;
    meta->total_size = total_size;
    meta->varray_off = sizeof(Hako_HakoCanHead) + sizeof(HakoPduMetaDataType);

    // Copy dynamic part and set offsets
    dynamic_memory.copy_to_pdu(base_ptr + meta->varray_off);

    *dst = (Hako_HakoCanHead*)base_ptr;
    return total_size;
}
static inline Hako_HakoCanHead* hako_create_empty_pdu_HakoCanHead(int heap_size)
{
    int total_size = sizeof(Hako_HakoCanHead) + sizeof(HakoPduMetaDataType) + heap_size;

    // Allocate PDU memory
    char* base_ptr = (char*)malloc(total_size);
    if (base_ptr == nullptr) {
        return nullptr;
    }
    memset(base_ptr, 0, total_size);
    // Set metadata at the end
    HakoPduMetaDataType* meta = (HakoPduMetaDataType*)(base_ptr + sizeof(Hako_HakoCanHead));
    meta->magicno = HAKO_PDU_META_DATA_MAGICNO;
    meta->version = HAKO_PDU_META_DATA_VERSION;
    meta->top_off = 0;
    meta->total_size = total_size;
    meta->varray_off = sizeof(Hako_HakoCanHead) + sizeof(HakoPduMetaDataType);
    return (Hako_HakoCanHead*)base_ptr;
}
#endif /* _PDU_CTYPE_CONV_HAKO_can_msgs_HakoCanHead_HPP_ */
