#ifndef _PDU_CTYPE_CONV_HAKO_geometry_msgs_Point_HPP_
#define _PDU_CTYPE_CONV_HAKO_geometry_msgs_Point_HPP_

#include "pdu_primitive_ctypes.h"
#include "ros_primitive_types.hpp"
#include "pdu_primitive_ctypes_conv.hpp"
#include "pdu_dynamic_memory.hpp"
/*
 * Dependent pdu data
 */
#include "geometry_msgs/pdu_ctype_Point.h"
/*
 * Dependent ros data
 */
#include "geometry_msgs/msg/point.hpp"

/*
 * Dependent Convertors
 */

/***************************
 *
 * PDU ==> ROS2
 *
 ***************************/

static inline int _pdu2ros_Point(const char* varray_ptr, Hako_Point &src, geometry_msgs::msg::Point &dst)
{
    // primitive convert
    hako_convert_pdu2ros(src.x, dst.x);
    // primitive convert
    hako_convert_pdu2ros(src.y, dst.y);
    // primitive convert
    hako_convert_pdu2ros(src.z, dst.z);
    return 0;
}

static inline int hako_convert_pdu2ros_Point(Hako_Point &src, geometry_msgs::msg::Point &dst)
{
    char* base_ptr = (char*)&src;
    HakoPduMetaDataType* meta = (HakoPduMetaDataType*)(base_ptr + sizeof(Hako_Point));

    // Validate magic number and version
    if ((meta->magicno != HAKO_PDU_META_DATA_MAGICNO) || (meta->version != HAKO_PDU_META_DATA_VERSION)) {
        return -1; // Invalid PDU metadata
    }
    else {
        char *varray_ptr = base_ptr + sizeof(Hako_Point) + sizeof(HakoPduMetaDataType);
        return _pdu2ros_Point(varray_ptr, src, dst);
    }
}

/***************************
 *
 * ROS2 ==> PDU
 *
 ***************************/

static inline bool _ros2pdu_Point(geometry_msgs::msg::Point &src, Hako_Point &dst, PduDynamicMemory &dynamic_memory)
{
    try {
        // primitive convert
        hako_convert_ros2pdu(src.x, dst.x);
        // primitive convert
        hako_convert_ros2pdu(src.y, dst.y);
        // primitive convert
        hako_convert_ros2pdu(src.z, dst.z);
    } catch (const std::runtime_error& e) {
        std::cerr << "convertor error: " << e.what() << std::endl;
        return false;
    }
    return true;
}

static inline int hako_convert_ros2pdu_Point(geometry_msgs::msg::Point &src, Hako_Point** dst)
{
    PduDynamicMemory dynamic_memory;
    Hako_Point out;
    if (!_ros2pdu_Point(src, out, dynamic_memory)) {
        return -1;
    }
    int total_size = sizeof(Hako_Point) + sizeof(HakoPduMetaDataType) + dynamic_memory.get_total_size();

    // Allocate PDU memory
    char* base_ptr = (char*)malloc(total_size);
    if (base_ptr == nullptr) {
        return -1;
    }
    // Copy out on top
    memcpy(base_ptr, (void*)&out, sizeof(Hako_Point));

    // Set metadata at the end
    HakoPduMetaDataType* meta = (HakoPduMetaDataType*)(base_ptr + sizeof(Hako_Point));
    meta->magicno = HAKO_PDU_META_DATA_MAGICNO;
    meta->version = HAKO_PDU_META_DATA_VERSION;
    meta->top_off = 0;
    meta->total_size = total_size;
    meta->varray_off = sizeof(Hako_Point) + sizeof(HakoPduMetaDataType);

    // Copy dynamic part and set offsets
    dynamic_memory.copy_to_pdu(base_ptr + meta->varray_off);

    *dst = (Hako_Point*)base_ptr;
    return total_size;
}

#endif /* _PDU_CTYPE_CONV_HAKO_geometry_msgs_Point_HPP_ */
