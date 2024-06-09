#ifndef _PDU_CTYPE_CONV_HAKO_geometry_msgs_Twist_HPP_
#define _PDU_CTYPE_CONV_HAKO_geometry_msgs_Twist_HPP_

#include "pdu_primitive_ctypes.h"
#include "ros_primitive_types.hpp"
#include "pdu_primitive_ctypes_conv.hpp"
#include "pdu_dynamic_memory.hpp"
/*
 * Dependent pdu data
 */
#include "geometry_msgs/pdu_ctype_Twist.h"
/*
 * Dependent ros data
 */
#include "geometry_msgs/msg/twist.hpp"

/*
 * Dependent Convertors
 */
#include "geometry_msgs/pdu_ctype_conv_Vector3.hpp"

/***************************
 *
 * PDU ==> ROS2
 *
 ***************************/

static inline int _pdu2ros_Twist(const char* varray_ptr, Hako_Twist &src, geometry_msgs::msg::Twist &dst)
{
    // Struct convert
    _pdu2ros_Vector3(varray_ptr, src.linear, dst.linear);
    // Struct convert
    _pdu2ros_Vector3(varray_ptr, src.angular, dst.angular);
    (void)varray_ptr;
    return 0;
}

static inline int hako_convert_pdu2ros_Twist(Hako_Twist &src, geometry_msgs::msg::Twist &dst)
{
    char* base_ptr = (char*)&src;
    HakoPduMetaDataType* meta = (HakoPduMetaDataType*)(base_ptr + sizeof(Hako_Twist));

    // Validate magic number and version
    if ((meta->magicno != HAKO_PDU_META_DATA_MAGICNO) || (meta->version != HAKO_PDU_META_DATA_VERSION)) {
        return -1; // Invalid PDU metadata
    }
    else {
        char *varray_ptr = base_ptr + sizeof(Hako_Twist) + sizeof(HakoPduMetaDataType);
        return _pdu2ros_Twist(varray_ptr, src, dst);
    }
}

/***************************
 *
 * ROS2 ==> PDU
 *
 ***************************/

static inline bool _ros2pdu_Twist(geometry_msgs::msg::Twist &src, Hako_Twist &dst, PduDynamicMemory &dynamic_memory)
{
    try {
        // struct convert
        _ros2pdu_Vector3(src.linear, dst.linear, dynamic_memory);
        // struct convert
        _ros2pdu_Vector3(src.angular, dst.angular, dynamic_memory);
    } catch (const std::runtime_error& e) {
        std::cerr << "convertor error: " << e.what() << std::endl;
        return false;
    }
    (void)dynamic_memory;
    return true;
}

static inline int hako_convert_ros2pdu_Twist(geometry_msgs::msg::Twist &src, Hako_Twist** dst)
{
    PduDynamicMemory dynamic_memory;
    Hako_Twist out;
    if (!_ros2pdu_Twist(src, out, dynamic_memory)) {
        return -1;
    }
    int total_size = sizeof(Hako_Twist) + sizeof(HakoPduMetaDataType) + dynamic_memory.get_total_size();

    // Allocate PDU memory
    char* base_ptr = (char*)malloc(total_size);
    if (base_ptr == nullptr) {
        return -1;
    }
    // Copy out on top
    memcpy(base_ptr, (void*)&out, sizeof(Hako_Twist));

    // Set metadata at the end
    HakoPduMetaDataType* meta = (HakoPduMetaDataType*)(base_ptr + sizeof(Hako_Twist));
    meta->magicno = HAKO_PDU_META_DATA_MAGICNO;
    meta->version = HAKO_PDU_META_DATA_VERSION;
    meta->top_off = 0;
    meta->total_size = total_size;
    meta->varray_off = sizeof(Hako_Twist) + sizeof(HakoPduMetaDataType);

    // Copy dynamic part and set offsets
    dynamic_memory.copy_to_pdu(base_ptr + meta->varray_off);

    *dst = (Hako_Twist*)base_ptr;
    return total_size;
}
static inline Hako_Twist* hako_create_empty_pdu_Twist(int heap_size)
{
    int total_size = sizeof(Hako_Twist) + sizeof(HakoPduMetaDataType) + heap_size;

    // Allocate PDU memory
    char* base_ptr = (char*)malloc(total_size);
    if (base_ptr == nullptr) {
        return nullptr;
    }
    memset(base_ptr, 0, total_size);
    // Set metadata at the end
    HakoPduMetaDataType* meta = (HakoPduMetaDataType*)(base_ptr + sizeof(Hako_Twist));
    meta->magicno = HAKO_PDU_META_DATA_MAGICNO;
    meta->version = HAKO_PDU_META_DATA_VERSION;
    meta->top_off = 0;
    meta->total_size = total_size;
    meta->varray_off = sizeof(Hako_Twist) + sizeof(HakoPduMetaDataType);
    return (Hako_Twist*)base_ptr;
}
#endif /* _PDU_CTYPE_CONV_HAKO_geometry_msgs_Twist_HPP_ */
