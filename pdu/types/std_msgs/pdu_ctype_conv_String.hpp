#ifndef _PDU_CTYPE_CONV_HAKO_std_msgs_String_HPP_
#define _PDU_CTYPE_CONV_HAKO_std_msgs_String_HPP_

#include "pdu_primitive_ctypes.h"
#include "ros_primitive_types.hpp"
#include "pdu_primitive_ctypes_conv.hpp"
#include "pdu_dynamic_memory.hpp"
/*
 * Dependent pdu data
 */
#include "std_msgs/pdu_ctype_String.h"
/*
 * Dependent ros data
 */
#include "std_msgs/msg/string.hpp"

/*
 * Dependent Convertors
 */

/***************************
 *
 * PDU ==> ROS2
 *
 ***************************/

static inline int _pdu2ros_String(const char* varray_ptr, Hako_String &src, std_msgs::msg::String &dst)
{
    // string convertor
    dst.data = (const char*)src.data;
    return 0;
}

static inline int hako_convert_pdu2ros_String(Hako_String &src, std_msgs::msg::String &dst)
{
    char* base_ptr = (char*)&src;
    HakoPduMetaDataType* meta = (HakoPduMetaDataType*)(base_ptr + sizeof(Hako_String));

    // Validate magic number and version
    if ((meta->magicno != HAKO_PDU_META_DATA_MAGICNO) || (meta->version != HAKO_PDU_META_DATA_VERSION)) {
        return -1; // Invalid PDU metadata
    }
    else {
        char *varray_ptr = base_ptr + sizeof(Hako_String) + sizeof(HakoPduMetaDataType);
        return _pdu2ros_String(varray_ptr, src, dst);
    }
}

/***************************
 *
 * ROS2 ==> PDU
 *
 ***************************/

static inline bool _ros2pdu_String(std_msgs::msg::String &src, Hako_String &dst, PduDynamicMemory &dynamic_memory)
{
    try {
        // string convertor
        (void)hako_convert_ros2pdu_array(
            src.data, src.data.length(),
            dst.data, M_ARRAY_SIZE(Hako_String, char, data));
    } catch (const std::runtime_error& e) {
        std::cerr << "convertor error: " << e.what() << std::endl;
        return false;
    }
    return true;
}

static inline int hako_convert_ros2pdu_String(std_msgs::msg::String &src, Hako_String** dst)
{
    PduDynamicMemory dynamic_memory;
    Hako_String out;
    if (!_ros2pdu_String(src, out, dynamic_memory)) {
        return -1;
    }
    int total_size = sizeof(Hako_String) + sizeof(HakoPduMetaDataType) + dynamic_memory.get_total_size();

    // Allocate PDU memory
    char* base_ptr = (char*)malloc(total_size);
    if (base_ptr == nullptr) {
        return -1;
    }
    // Copy out on top
    memcpy(base_ptr, (void*)&out, sizeof(Hako_String));

    // Set metadata at the end
    HakoPduMetaDataType* meta = (HakoPduMetaDataType*)(base_ptr + sizeof(Hako_String));
    meta->magicno = HAKO_PDU_META_DATA_MAGICNO;
    meta->version = HAKO_PDU_META_DATA_VERSION;
    meta->top_off = 0;
    meta->total_size = total_size;
    meta->varray_off = sizeof(Hako_String) + sizeof(HakoPduMetaDataType);

    // Copy dynamic part and set offsets
    dynamic_memory.copy_to_pdu(base_ptr + meta->varray_off);

    *dst = (Hako_String*)base_ptr;
    return total_size;
}

#endif /* _PDU_CTYPE_CONV_HAKO_std_msgs_String_HPP_ */
