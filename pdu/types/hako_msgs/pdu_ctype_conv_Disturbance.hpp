#ifndef _PDU_CTYPE_CONV_HAKO_hako_msgs_Disturbance_HPP_
#define _PDU_CTYPE_CONV_HAKO_hako_msgs_Disturbance_HPP_

#include "pdu_primitive_ctypes.h"
#include "ros_primitive_types.hpp"
#include "pdu_primitive_ctypes_conv.hpp"
#include "pdu_dynamic_memory.hpp"
/*
 * Dependent pdu data
 */
#include "hako_msgs/pdu_ctype_Disturbance.h"
/*
 * Dependent ros data
 */
#include "hako_msgs/msg/disturbance.hpp"

/*
 * Dependent Convertors
 */
#include "hako_msgs/pdu_ctype_conv_DisturbanceTemperature.hpp"

/***************************
 *
 * PDU ==> ROS2
 *
 ***************************/

static inline int _pdu2ros_Disturbance(const char* varray_ptr, Hako_Disturbance &src, hako_msgs::msg::Disturbance &dst)
{
    // Struct convert
    _pdu2ros_DisturbanceTemperature(varray_ptr, src.d_temp, dst.d_temp);
    return 0;
}

static inline int hako_convert_pdu2ros_Disturbance(Hako_Disturbance &src, hako_msgs::msg::Disturbance &dst)
{
    char* base_ptr = (char*)&src;
    HakoPduMetaDataType* meta = (HakoPduMetaDataType*)(base_ptr + sizeof(Hako_Disturbance));

    // Validate magic number and version
    if ((meta->magicno != HAKO_PDU_META_DATA_MAGICNO) || (meta->version != HAKO_PDU_META_DATA_VERSION)) {
        return -1; // Invalid PDU metadata
    }
    else {
        char *varray_ptr = base_ptr + sizeof(Hako_Disturbance) + sizeof(HakoPduMetaDataType);
        return _pdu2ros_Disturbance(varray_ptr, src, dst);
    }
}

/***************************
 *
 * ROS2 ==> PDU
 *
 ***************************/

static inline bool _ros2pdu_Disturbance(hako_msgs::msg::Disturbance &src, Hako_Disturbance &dst, PduDynamicMemory &dynamic_memory)
{
    try {
        // struct convert
        _ros2pdu_DisturbanceTemperature(src.d_temp, dst.d_temp, dynamic_memory);
    } catch (const std::runtime_error& e) {
        std::cerr << "convertor error: " << e.what() << std::endl;
        return false;
    }
    return true;
}

static inline int hako_convert_ros2pdu_Disturbance(hako_msgs::msg::Disturbance &src, Hako_Disturbance** dst)
{
    PduDynamicMemory dynamic_memory;
    Hako_Disturbance out;
    if (!_ros2pdu_Disturbance(src, out, dynamic_memory)) {
        return -1;
    }
    int total_size = sizeof(Hako_Disturbance) + sizeof(HakoPduMetaDataType) + dynamic_memory.get_total_size();

    // Allocate PDU memory
    char* base_ptr = (char*)malloc(total_size);
    if (base_ptr == nullptr) {
        return -1;
    }
    // Copy out on top
    memcpy(base_ptr, (void*)&out, sizeof(Hako_Disturbance));

    // Set metadata at the end
    HakoPduMetaDataType* meta = (HakoPduMetaDataType*)(base_ptr + sizeof(Hako_Disturbance));
    meta->magicno = HAKO_PDU_META_DATA_MAGICNO;
    meta->version = HAKO_PDU_META_DATA_VERSION;
    meta->top_off = 0;
    meta->total_size = total_size;
    meta->varray_off = sizeof(Hako_Disturbance) + sizeof(HakoPduMetaDataType);

    // Copy dynamic part and set offsets
    dynamic_memory.copy_to_pdu(base_ptr + meta->varray_off);

    *dst = (Hako_Disturbance*)base_ptr;
    return total_size;
}
static inline Hako_Disturbance* hako_create_empty_pdu_Disturbance(int heap_size)
{
    int total_size = sizeof(Hako_Disturbance) + sizeof(HakoPduMetaDataType) + heap_size;

    // Allocate PDU memory
    char* base_ptr = (char*)malloc(total_size);
    if (base_ptr == nullptr) {
        return nullptr;
    }
    memset(base_ptr, 0, total_size);
    // Set metadata at the end
    HakoPduMetaDataType* meta = (HakoPduMetaDataType*)(base_ptr + sizeof(Hako_Disturbance));
    meta->magicno = HAKO_PDU_META_DATA_MAGICNO;
    meta->version = HAKO_PDU_META_DATA_VERSION;
    meta->top_off = 0;
    meta->total_size = total_size;
    meta->varray_off = sizeof(Hako_Disturbance) + sizeof(HakoPduMetaDataType);
    return (Hako_Disturbance*)base_ptr;
}
#endif /* _PDU_CTYPE_CONV_HAKO_hako_msgs_Disturbance_HPP_ */
