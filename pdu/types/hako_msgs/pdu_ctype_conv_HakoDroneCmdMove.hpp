#ifndef _PDU_CTYPE_CONV_HAKO_hako_msgs_HakoDroneCmdMove_HPP_
#define _PDU_CTYPE_CONV_HAKO_hako_msgs_HakoDroneCmdMove_HPP_

#include "pdu_primitive_ctypes.h"
#include "ros_primitive_types.hpp"
#include "pdu_primitive_ctypes_conv.hpp"
#include "pdu_dynamic_memory.hpp"
/*
 * Dependent pdu data
 */
#include "hako_msgs/pdu_ctype_HakoDroneCmdMove.h"
/*
 * Dependent ros data
 */
#include "hako_msgs/msg/hako_drone_cmd_move.hpp"

/*
 * Dependent Convertors
 */
#include "hako_msgs/pdu_ctype_conv_HakoDroneCmdHeader.hpp"

/***************************
 *
 * PDU ==> ROS2
 *
 ***************************/

static inline int _pdu2ros_HakoDroneCmdMove(const char* varray_ptr, Hako_HakoDroneCmdMove &src, hako_msgs::msg::HakoDroneCmdMove &dst)
{
    // Struct convert
    _pdu2ros_HakoDroneCmdHeader(varray_ptr, src.header, dst.header);
    // primitive convert
    hako_convert_pdu2ros(src.x, dst.x);
    // primitive convert
    hako_convert_pdu2ros(src.y, dst.y);
    // primitive convert
    hako_convert_pdu2ros(src.z, dst.z);
    // primitive convert
    hako_convert_pdu2ros(src.speed, dst.speed);
    // primitive convert
    hako_convert_pdu2ros(src.yaw_deg, dst.yaw_deg);
    return 0;
}

static inline int hako_convert_pdu2ros_HakoDroneCmdMove(Hako_HakoDroneCmdMove &src, hako_msgs::msg::HakoDroneCmdMove &dst)
{
    char* base_ptr = (char*)&src;
    HakoPduMetaDataType* meta = (HakoPduMetaDataType*)(base_ptr + sizeof(Hako_HakoDroneCmdMove));

    // Validate magic number and version
    if ((meta->magicno != HAKO_PDU_META_DATA_MAGICNO) || (meta->version != HAKO_PDU_META_DATA_VERSION)) {
        return -1; // Invalid PDU metadata
    }
    else {
        char *varray_ptr = base_ptr + sizeof(Hako_HakoDroneCmdMove) + sizeof(HakoPduMetaDataType);
        return _pdu2ros_HakoDroneCmdMove(varray_ptr, src, dst);
    }
}

/***************************
 *
 * ROS2 ==> PDU
 *
 ***************************/

static inline bool _ros2pdu_HakoDroneCmdMove(hako_msgs::msg::HakoDroneCmdMove &src, Hako_HakoDroneCmdMove &dst, PduDynamicMemory &dynamic_memory)
{
    try {
        // struct convert
        _ros2pdu_HakoDroneCmdHeader(src.header, dst.header, dynamic_memory);
        // primitive convert
        hako_convert_ros2pdu(src.x, dst.x);
        // primitive convert
        hako_convert_ros2pdu(src.y, dst.y);
        // primitive convert
        hako_convert_ros2pdu(src.z, dst.z);
        // primitive convert
        hako_convert_ros2pdu(src.speed, dst.speed);
        // primitive convert
        hako_convert_ros2pdu(src.yaw_deg, dst.yaw_deg);
    } catch (const std::runtime_error& e) {
        std::cerr << "convertor error: " << e.what() << std::endl;
        return false;
    }
    return true;
}

static inline int hako_convert_ros2pdu_HakoDroneCmdMove(hako_msgs::msg::HakoDroneCmdMove &src, Hako_HakoDroneCmdMove** dst)
{
    PduDynamicMemory dynamic_memory;
    Hako_HakoDroneCmdMove out;
    if (!_ros2pdu_HakoDroneCmdMove(src, out, dynamic_memory)) {
        return -1;
    }
    int total_size = sizeof(Hako_HakoDroneCmdMove) + sizeof(HakoPduMetaDataType) + dynamic_memory.get_total_size();

    // Allocate PDU memory
    char* base_ptr = (char*)malloc(total_size);
    if (base_ptr == nullptr) {
        return -1;
    }
    // Copy out on top
    memcpy(base_ptr, (void*)&out, sizeof(Hako_HakoDroneCmdMove));

    // Set metadata at the end
    HakoPduMetaDataType* meta = (HakoPduMetaDataType*)(base_ptr + sizeof(Hako_HakoDroneCmdMove));
    meta->magicno = HAKO_PDU_META_DATA_MAGICNO;
    meta->version = HAKO_PDU_META_DATA_VERSION;
    meta->top_off = 0;
    meta->total_size = total_size;
    meta->varray_off = sizeof(Hako_HakoDroneCmdMove) + sizeof(HakoPduMetaDataType);

    // Copy dynamic part and set offsets
    dynamic_memory.copy_to_pdu(base_ptr + meta->varray_off);

    *dst = (Hako_HakoDroneCmdMove*)base_ptr;
    return total_size;
}

#endif /* _PDU_CTYPE_CONV_HAKO_hako_msgs_HakoDroneCmdMove_HPP_ */
