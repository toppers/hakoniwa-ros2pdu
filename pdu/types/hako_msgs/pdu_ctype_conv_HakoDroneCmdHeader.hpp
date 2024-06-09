#ifndef _PDU_CTYPE_CONV_HAKO_hako_msgs_HakoDroneCmdHeader_HPP_
#define _PDU_CTYPE_CONV_HAKO_hako_msgs_HakoDroneCmdHeader_HPP_

#include "pdu_primitive_ctypes.h"
#include "ros_primitive_types.hpp"
#include "pdu_primitive_ctypes_conv.hpp"
#include "pdu_dynamic_memory.hpp"
/*
 * Dependent pdu data
 */
#include "hako_msgs/pdu_ctype_HakoDroneCmdHeader.h"
/*
 * Dependent ros data
 */
#include "hako_msgs/msg/hako_drone_cmd_header.hpp"

/*
 * Dependent Convertors
 */

/***************************
 *
 * PDU ==> ROS2
 *
 ***************************/

static inline int _pdu2ros_HakoDroneCmdHeader(const char* varray_ptr, Hako_HakoDroneCmdHeader &src, hako_msgs::msg::HakoDroneCmdHeader &dst)
{
    // primitive convert
    hako_convert_pdu2ros(src.request, dst.request);
    // primitive convert
    hako_convert_pdu2ros(src.result, dst.result);
    // primitive convert
    hako_convert_pdu2ros(src.result_code, dst.result_code);
    return 0;
}

static inline int hako_convert_pdu2ros_HakoDroneCmdHeader(Hako_HakoDroneCmdHeader &src, hako_msgs::msg::HakoDroneCmdHeader &dst)
{
    char* base_ptr = (char*)&src;
    HakoPduMetaDataType* meta = (HakoPduMetaDataType*)(base_ptr + sizeof(Hako_HakoDroneCmdHeader));

    // Validate magic number and version
    if ((meta->magicno != HAKO_PDU_META_DATA_MAGICNO) || (meta->version != HAKO_PDU_META_DATA_VERSION)) {
        return -1; // Invalid PDU metadata
    }
    else {
        char *varray_ptr = base_ptr + sizeof(Hako_HakoDroneCmdHeader) + sizeof(HakoPduMetaDataType);
        return _pdu2ros_HakoDroneCmdHeader(varray_ptr, src, dst);
    }
}

/***************************
 *
 * ROS2 ==> PDU
 *
 ***************************/

static inline bool _ros2pdu_HakoDroneCmdHeader(hako_msgs::msg::HakoDroneCmdHeader &src, Hako_HakoDroneCmdHeader &dst, PduDynamicMemory &dynamic_memory)
{
    try {
        // primitive convert
        hako_convert_ros2pdu(src.request, dst.request);
        // primitive convert
        hako_convert_ros2pdu(src.result, dst.result);
        // primitive convert
        hako_convert_ros2pdu(src.result_code, dst.result_code);
    } catch (const std::runtime_error& e) {
        std::cerr << "convertor error: " << e.what() << std::endl;
        return false;
    }
    return true;
}

static inline int hako_convert_ros2pdu_HakoDroneCmdHeader(hako_msgs::msg::HakoDroneCmdHeader &src, Hako_HakoDroneCmdHeader** dst)
{
    PduDynamicMemory dynamic_memory;
    Hako_HakoDroneCmdHeader out;
    if (!_ros2pdu_HakoDroneCmdHeader(src, out, dynamic_memory)) {
        return -1;
    }
    int total_size = sizeof(Hako_HakoDroneCmdHeader) + sizeof(HakoPduMetaDataType) + dynamic_memory.get_total_size();

    // Allocate PDU memory
    char* base_ptr = (char*)malloc(total_size);
    if (base_ptr == nullptr) {
        return -1;
    }
    // Copy out on top
    memcpy(base_ptr, (void*)&out, sizeof(Hako_HakoDroneCmdHeader));

    // Set metadata at the end
    HakoPduMetaDataType* meta = (HakoPduMetaDataType*)(base_ptr + sizeof(Hako_HakoDroneCmdHeader));
    meta->magicno = HAKO_PDU_META_DATA_MAGICNO;
    meta->version = HAKO_PDU_META_DATA_VERSION;
    meta->top_off = 0;
    meta->total_size = total_size;
    meta->varray_off = sizeof(Hako_HakoDroneCmdHeader) + sizeof(HakoPduMetaDataType);

    // Copy dynamic part and set offsets
    dynamic_memory.copy_to_pdu(base_ptr + meta->varray_off);

    *dst = (Hako_HakoDroneCmdHeader*)base_ptr;
    return total_size;
}
static inline Hako_HakoDroneCmdHeader* hako_create_empty_pdu_HakoDroneCmdHeader(int heap_size)
{
    int total_size = sizeof(Hako_HakoDroneCmdHeader) + sizeof(HakoPduMetaDataType) + heap_size;

    // Allocate PDU memory
    char* base_ptr = (char*)malloc(total_size);
    if (base_ptr == nullptr) {
        return nullptr;
    }
    memset(base_ptr, 0, total_size);
    // Set metadata at the end
    HakoPduMetaDataType* meta = (HakoPduMetaDataType*)(base_ptr + sizeof(Hako_HakoDroneCmdHeader));
    meta->magicno = HAKO_PDU_META_DATA_MAGICNO;
    meta->version = HAKO_PDU_META_DATA_VERSION;
    meta->top_off = 0;
    meta->total_size = total_size;
    meta->varray_off = sizeof(Hako_HakoDroneCmdHeader) + sizeof(HakoPduMetaDataType);
    return (Hako_HakoDroneCmdHeader*)base_ptr;
}
#endif /* _PDU_CTYPE_CONV_HAKO_hako_msgs_HakoDroneCmdHeader_HPP_ */
