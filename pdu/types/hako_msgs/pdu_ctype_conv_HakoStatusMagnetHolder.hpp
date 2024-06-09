#ifndef _PDU_CTYPE_CONV_HAKO_hako_msgs_HakoStatusMagnetHolder_HPP_
#define _PDU_CTYPE_CONV_HAKO_hako_msgs_HakoStatusMagnetHolder_HPP_

#include "pdu_primitive_ctypes.h"
#include "ros_primitive_types.hpp"
#include "pdu_primitive_ctypes_conv.hpp"
#include "pdu_dynamic_memory.hpp"
/*
 * Dependent pdu data
 */
#include "hako_msgs/pdu_ctype_HakoStatusMagnetHolder.h"
/*
 * Dependent ros data
 */
#include "hako_msgs/msg/hako_status_magnet_holder.hpp"

/*
 * Dependent Convertors
 */

/***************************
 *
 * PDU ==> ROS2
 *
 ***************************/

static inline int _pdu2ros_HakoStatusMagnetHolder(const char* varray_ptr, Hako_HakoStatusMagnetHolder &src, hako_msgs::msg::HakoStatusMagnetHolder &dst)
{
    // primitive convert
    hako_convert_pdu2ros(src.magnet_on, dst.magnet_on);
    // primitive convert
    hako_convert_pdu2ros(src.contact_on, dst.contact_on);
    return 0;
}

static inline int hako_convert_pdu2ros_HakoStatusMagnetHolder(Hako_HakoStatusMagnetHolder &src, hako_msgs::msg::HakoStatusMagnetHolder &dst)
{
    char* base_ptr = (char*)&src;
    HakoPduMetaDataType* meta = (HakoPduMetaDataType*)(base_ptr + sizeof(Hako_HakoStatusMagnetHolder));

    // Validate magic number and version
    if ((meta->magicno != HAKO_PDU_META_DATA_MAGICNO) || (meta->version != HAKO_PDU_META_DATA_VERSION)) {
        return -1; // Invalid PDU metadata
    }
    else {
        char *varray_ptr = base_ptr + sizeof(Hako_HakoStatusMagnetHolder) + sizeof(HakoPduMetaDataType);
        return _pdu2ros_HakoStatusMagnetHolder(varray_ptr, src, dst);
    }
}

/***************************
 *
 * ROS2 ==> PDU
 *
 ***************************/

static inline bool _ros2pdu_HakoStatusMagnetHolder(hako_msgs::msg::HakoStatusMagnetHolder &src, Hako_HakoStatusMagnetHolder &dst, PduDynamicMemory &dynamic_memory)
{
    try {
        // primitive convert
        hako_convert_ros2pdu(src.magnet_on, dst.magnet_on);
        // primitive convert
        hako_convert_ros2pdu(src.contact_on, dst.contact_on);
    } catch (const std::runtime_error& e) {
        std::cerr << "convertor error: " << e.what() << std::endl;
        return false;
    }
    return true;
}

static inline int hako_convert_ros2pdu_HakoStatusMagnetHolder(hako_msgs::msg::HakoStatusMagnetHolder &src, Hako_HakoStatusMagnetHolder** dst)
{
    PduDynamicMemory dynamic_memory;
    Hako_HakoStatusMagnetHolder out;
    if (!_ros2pdu_HakoStatusMagnetHolder(src, out, dynamic_memory)) {
        return -1;
    }
    int total_size = sizeof(Hako_HakoStatusMagnetHolder) + sizeof(HakoPduMetaDataType) + dynamic_memory.get_total_size();

    // Allocate PDU memory
    char* base_ptr = (char*)malloc(total_size);
    if (base_ptr == nullptr) {
        return -1;
    }
    // Copy out on top
    memcpy(base_ptr, (void*)&out, sizeof(Hako_HakoStatusMagnetHolder));

    // Set metadata at the end
    HakoPduMetaDataType* meta = (HakoPduMetaDataType*)(base_ptr + sizeof(Hako_HakoStatusMagnetHolder));
    meta->magicno = HAKO_PDU_META_DATA_MAGICNO;
    meta->version = HAKO_PDU_META_DATA_VERSION;
    meta->top_off = 0;
    meta->total_size = total_size;
    meta->varray_off = sizeof(Hako_HakoStatusMagnetHolder) + sizeof(HakoPduMetaDataType);

    // Copy dynamic part and set offsets
    dynamic_memory.copy_to_pdu(base_ptr + meta->varray_off);

    *dst = (Hako_HakoStatusMagnetHolder*)base_ptr;
    return total_size;
}
static inline Hako_HakoStatusMagnetHolder* hako_create_empty_pdu_HakoStatusMagnetHolder(int heap_size)
{
    int total_size = sizeof(Hako_HakoStatusMagnetHolder) + sizeof(HakoPduMetaDataType) + heap_size;

    // Allocate PDU memory
    char* base_ptr = (char*)malloc(total_size);
    if (base_ptr == nullptr) {
        return nullptr;
    }
    memset(base_ptr, 0, total_size);
    // Set metadata at the end
    HakoPduMetaDataType* meta = (HakoPduMetaDataType*)(base_ptr + sizeof(Hako_HakoStatusMagnetHolder));
    meta->magicno = HAKO_PDU_META_DATA_MAGICNO;
    meta->version = HAKO_PDU_META_DATA_VERSION;
    meta->top_off = 0;
    meta->total_size = total_size;
    meta->varray_off = sizeof(Hako_HakoStatusMagnetHolder) + sizeof(HakoPduMetaDataType);
    return (Hako_HakoStatusMagnetHolder*)base_ptr;
}
#endif /* _PDU_CTYPE_CONV_HAKO_hako_msgs_HakoStatusMagnetHolder_HPP_ */
