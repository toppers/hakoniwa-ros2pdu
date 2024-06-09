#ifndef _PDU_CTYPE_CONV_HAKO_hako_msgs_ManualPosAttControl_HPP_
#define _PDU_CTYPE_CONV_HAKO_hako_msgs_ManualPosAttControl_HPP_

#include "pdu_primitive_ctypes.h"
#include "ros_primitive_types.hpp"
#include "pdu_primitive_ctypes_conv.hpp"
#include "pdu_dynamic_memory.hpp"
/*
 * Dependent pdu data
 */
#include "hako_msgs/pdu_ctype_ManualPosAttControl.h"
/*
 * Dependent ros data
 */
#include "hako_msgs/msg/manual_pos_att_control.hpp"

/*
 * Dependent Convertors
 */
#include "geometry_msgs/pdu_ctype_conv_Twist.hpp"
#include "geometry_msgs/pdu_ctype_conv_Vector3.hpp"

/***************************
 *
 * PDU ==> ROS2
 *
 ***************************/

static inline int _pdu2ros_ManualPosAttControl(const char* varray_ptr, Hako_ManualPosAttControl &src, hako_msgs::msg::ManualPosAttControl &dst)
{
    // primitive convert
    hako_convert_pdu2ros(src.do_operation, dst.do_operation);
    // Struct convert
    _pdu2ros_Twist(varray_ptr, src.posatt, dst.posatt);
    (void)varray_ptr;
    return 0;
}

static inline int hako_convert_pdu2ros_ManualPosAttControl(Hako_ManualPosAttControl &src, hako_msgs::msg::ManualPosAttControl &dst)
{
    char* base_ptr = (char*)&src;
    HakoPduMetaDataType* meta = (HakoPduMetaDataType*)(base_ptr + sizeof(Hako_ManualPosAttControl));

    // Validate magic number and version
    if ((meta->magicno != HAKO_PDU_META_DATA_MAGICNO) || (meta->version != HAKO_PDU_META_DATA_VERSION)) {
        return -1; // Invalid PDU metadata
    }
    else {
        char *varray_ptr = base_ptr + sizeof(Hako_ManualPosAttControl) + sizeof(HakoPduMetaDataType);
        return _pdu2ros_ManualPosAttControl(varray_ptr, src, dst);
    }
}

/***************************
 *
 * ROS2 ==> PDU
 *
 ***************************/

static inline bool _ros2pdu_ManualPosAttControl(hako_msgs::msg::ManualPosAttControl &src, Hako_ManualPosAttControl &dst, PduDynamicMemory &dynamic_memory)
{
    try {
        // primitive convert
        hako_convert_ros2pdu(src.do_operation, dst.do_operation);
        // struct convert
        _ros2pdu_Twist(src.posatt, dst.posatt, dynamic_memory);
    } catch (const std::runtime_error& e) {
        std::cerr << "convertor error: " << e.what() << std::endl;
        return false;
    }
    (void)dynamic_memory;
    return true;
}

static inline int hako_convert_ros2pdu_ManualPosAttControl(hako_msgs::msg::ManualPosAttControl &src, Hako_ManualPosAttControl** dst)
{
    PduDynamicMemory dynamic_memory;
    Hako_ManualPosAttControl out;
    if (!_ros2pdu_ManualPosAttControl(src, out, dynamic_memory)) {
        return -1;
    }
    int total_size = sizeof(Hako_ManualPosAttControl) + sizeof(HakoPduMetaDataType) + dynamic_memory.get_total_size();

    // Allocate PDU memory
    char* base_ptr = (char*)malloc(total_size);
    if (base_ptr == nullptr) {
        return -1;
    }
    // Copy out on top
    memcpy(base_ptr, (void*)&out, sizeof(Hako_ManualPosAttControl));

    // Set metadata at the end
    HakoPduMetaDataType* meta = (HakoPduMetaDataType*)(base_ptr + sizeof(Hako_ManualPosAttControl));
    meta->magicno = HAKO_PDU_META_DATA_MAGICNO;
    meta->version = HAKO_PDU_META_DATA_VERSION;
    meta->top_off = 0;
    meta->total_size = total_size;
    meta->varray_off = sizeof(Hako_ManualPosAttControl) + sizeof(HakoPduMetaDataType);

    // Copy dynamic part and set offsets
    dynamic_memory.copy_to_pdu(base_ptr + meta->varray_off);

    *dst = (Hako_ManualPosAttControl*)base_ptr;
    return total_size;
}
static inline Hako_ManualPosAttControl* hako_create_empty_pdu_ManualPosAttControl(int heap_size)
{
    int total_size = sizeof(Hako_ManualPosAttControl) + sizeof(HakoPduMetaDataType) + heap_size;

    // Allocate PDU memory
    char* base_ptr = (char*)malloc(total_size);
    if (base_ptr == nullptr) {
        return nullptr;
    }
    memset(base_ptr, 0, total_size);
    // Set metadata at the end
    HakoPduMetaDataType* meta = (HakoPduMetaDataType*)(base_ptr + sizeof(Hako_ManualPosAttControl));
    meta->magicno = HAKO_PDU_META_DATA_MAGICNO;
    meta->version = HAKO_PDU_META_DATA_VERSION;
    meta->top_off = 0;
    meta->total_size = total_size;
    meta->varray_off = sizeof(Hako_ManualPosAttControl) + sizeof(HakoPduMetaDataType);
    return (Hako_ManualPosAttControl*)base_ptr;
}
#endif /* _PDU_CTYPE_CONV_HAKO_hako_msgs_ManualPosAttControl_HPP_ */
