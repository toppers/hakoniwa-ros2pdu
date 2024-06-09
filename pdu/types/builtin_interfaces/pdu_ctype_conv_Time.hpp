#ifndef _PDU_CTYPE_CONV_HAKO_builtin_interfaces_Time_HPP_
#define _PDU_CTYPE_CONV_HAKO_builtin_interfaces_Time_HPP_

#include "pdu_primitive_ctypes.h"
#include "ros_primitive_types.hpp"
#include "pdu_primitive_ctypes_conv.hpp"
#include "pdu_dynamic_memory.hpp"
/*
 * Dependent pdu data
 */
#include "builtin_interfaces/pdu_ctype_Time.h"
/*
 * Dependent ros data
 */
#include "builtin_interfaces/msg/time.hpp"

/*
 * Dependent Convertors
 */

/***************************
 *
 * PDU ==> ROS2
 *
 ***************************/

static inline int _pdu2ros_Time(const char* varray_ptr, Hako_Time &src, builtin_interfaces::msg::Time &dst)
{
    // primitive convert
    hako_convert_pdu2ros(src.sec, dst.sec);
    // primitive convert
    hako_convert_pdu2ros(src.nanosec, dst.nanosec);
    return 0;
}

static inline int hako_convert_pdu2ros_Time(Hako_Time &src, builtin_interfaces::msg::Time &dst)
{
    char* base_ptr = (char*)&src;
    HakoPduMetaDataType* meta = (HakoPduMetaDataType*)(base_ptr + sizeof(Hako_Time));

    // Validate magic number and version
    if ((meta->magicno != HAKO_PDU_META_DATA_MAGICNO) || (meta->version != HAKO_PDU_META_DATA_VERSION)) {
        return -1; // Invalid PDU metadata
    }
    else {
        char *varray_ptr = base_ptr + sizeof(Hako_Time) + sizeof(HakoPduMetaDataType);
        return _pdu2ros_Time(varray_ptr, src, dst);
    }
}

/***************************
 *
 * ROS2 ==> PDU
 *
 ***************************/

static inline bool _ros2pdu_Time(builtin_interfaces::msg::Time &src, Hako_Time &dst, PduDynamicMemory &dynamic_memory)
{
    try {
        // primitive convert
        hako_convert_ros2pdu(src.sec, dst.sec);
        // primitive convert
        hako_convert_ros2pdu(src.nanosec, dst.nanosec);
    } catch (const std::runtime_error& e) {
        std::cerr << "convertor error: " << e.what() << std::endl;
        return false;
    }
    return true;
}

static inline int hako_convert_ros2pdu_Time(builtin_interfaces::msg::Time &src, Hako_Time** dst)
{
    PduDynamicMemory dynamic_memory;
    Hako_Time out;
    if (!_ros2pdu_Time(src, out, dynamic_memory)) {
        return -1;
    }
    int total_size = sizeof(Hako_Time) + sizeof(HakoPduMetaDataType) + dynamic_memory.get_total_size();

    // Allocate PDU memory
    char* base_ptr = (char*)malloc(total_size);
    if (base_ptr == nullptr) {
        return -1;
    }
    // Copy out on top
    memcpy(base_ptr, (void*)&out, sizeof(Hako_Time));

    // Set metadata at the end
    HakoPduMetaDataType* meta = (HakoPduMetaDataType*)(base_ptr + sizeof(Hako_Time));
    meta->magicno = HAKO_PDU_META_DATA_MAGICNO;
    meta->version = HAKO_PDU_META_DATA_VERSION;
    meta->top_off = 0;
    meta->total_size = total_size;
    meta->varray_off = sizeof(Hako_Time) + sizeof(HakoPduMetaDataType);

    // Copy dynamic part and set offsets
    dynamic_memory.copy_to_pdu(base_ptr + meta->varray_off);

    *dst = (Hako_Time*)base_ptr;
    return total_size;
}

#endif /* _PDU_CTYPE_CONV_HAKO_builtin_interfaces_Time_HPP_ */
