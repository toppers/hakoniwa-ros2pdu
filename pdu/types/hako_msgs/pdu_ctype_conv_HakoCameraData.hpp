#ifndef _PDU_CTYPE_CONV_HAKO_hako_msgs_HakoCameraData_HPP_
#define _PDU_CTYPE_CONV_HAKO_hako_msgs_HakoCameraData_HPP_

#include "pdu_primitive_ctypes.h"
#include "ros_primitive_types.hpp"
#include "pdu_primitive_ctypes_conv.hpp"
#include "pdu_dynamic_memory.hpp"
/*
 * Dependent pdu data
 */
#include "hako_msgs/pdu_ctype_HakoCameraData.h"
/*
 * Dependent ros data
 */
#include "hako_msgs/msg/hako_camera_data.hpp"

/*
 * Dependent Convertors
 */
#include "builtin_interfaces/pdu_ctype_conv_Time.hpp"
#include "sensor_msgs/pdu_ctype_conv_CompressedImage.hpp"
#include "std_msgs/pdu_ctype_conv_Header.hpp"

/***************************
 *
 * PDU ==> ROS2
 *
 ***************************/

static inline int _pdu2ros_HakoCameraData(const char* varray_ptr, Hako_HakoCameraData &src, hako_msgs::msg::HakoCameraData &dst)
{
    // primitive convert
    hako_convert_pdu2ros(src.request_id, dst.request_id);
    // Struct convert
    _pdu2ros_CompressedImage(varray_ptr, src.image, dst.image);
    (void)varray_ptr;
    return 0;
}

static inline int hako_convert_pdu2ros_HakoCameraData(Hako_HakoCameraData &src, hako_msgs::msg::HakoCameraData &dst)
{
    char* base_ptr = (char*)&src;
    HakoPduMetaDataType* meta = (HakoPduMetaDataType*)(base_ptr + sizeof(Hako_HakoCameraData));

    // Validate magic number and version
    if ((meta->magicno != HAKO_PDU_META_DATA_MAGICNO) || (meta->version != HAKO_PDU_META_DATA_VERSION)) {
        return -1; // Invalid PDU metadata
    }
    else {
        char *varray_ptr = base_ptr + sizeof(Hako_HakoCameraData) + sizeof(HakoPduMetaDataType);
        return _pdu2ros_HakoCameraData(varray_ptr, src, dst);
    }
}

/***************************
 *
 * ROS2 ==> PDU
 *
 ***************************/

static inline bool _ros2pdu_HakoCameraData(hako_msgs::msg::HakoCameraData &src, Hako_HakoCameraData &dst, PduDynamicMemory &dynamic_memory)
{
    try {
        // primitive convert
        hako_convert_ros2pdu(src.request_id, dst.request_id);
        // struct convert
        _ros2pdu_CompressedImage(src.image, dst.image, dynamic_memory);
    } catch (const std::runtime_error& e) {
        std::cerr << "convertor error: " << e.what() << std::endl;
        return false;
    }
    (void)dynamic_memory;
    return true;
}

static inline int hako_convert_ros2pdu_HakoCameraData(hako_msgs::msg::HakoCameraData &src, Hako_HakoCameraData** dst)
{
    PduDynamicMemory dynamic_memory;
    Hako_HakoCameraData out;
    if (!_ros2pdu_HakoCameraData(src, out, dynamic_memory)) {
        return -1;
    }
    int total_size = sizeof(Hako_HakoCameraData) + sizeof(HakoPduMetaDataType) + dynamic_memory.get_total_size();

    // Allocate PDU memory
    char* base_ptr = (char*)malloc(total_size);
    if (base_ptr == nullptr) {
        return -1;
    }
    // Copy out on top
    memcpy(base_ptr, (void*)&out, sizeof(Hako_HakoCameraData));

    // Set metadata at the end
    HakoPduMetaDataType* meta = (HakoPduMetaDataType*)(base_ptr + sizeof(Hako_HakoCameraData));
    meta->magicno = HAKO_PDU_META_DATA_MAGICNO;
    meta->version = HAKO_PDU_META_DATA_VERSION;
    meta->top_off = 0;
    meta->total_size = total_size;
    meta->varray_off = sizeof(Hako_HakoCameraData) + sizeof(HakoPduMetaDataType);

    // Copy dynamic part and set offsets
    dynamic_memory.copy_to_pdu(base_ptr + meta->varray_off);

    *dst = (Hako_HakoCameraData*)base_ptr;
    return total_size;
}
static inline Hako_HakoCameraData* hako_create_empty_pdu_HakoCameraData(int heap_size)
{
    int total_size = sizeof(Hako_HakoCameraData) + sizeof(HakoPduMetaDataType) + heap_size;

    // Allocate PDU memory
    char* base_ptr = (char*)malloc(total_size);
    if (base_ptr == nullptr) {
        return nullptr;
    }
    memset(base_ptr, 0, total_size);
    // Set metadata at the end
    HakoPduMetaDataType* meta = (HakoPduMetaDataType*)(base_ptr + sizeof(Hako_HakoCameraData));
    meta->magicno = HAKO_PDU_META_DATA_MAGICNO;
    meta->version = HAKO_PDU_META_DATA_VERSION;
    meta->top_off = 0;
    meta->total_size = total_size;
    meta->varray_off = sizeof(Hako_HakoCameraData) + sizeof(HakoPduMetaDataType);
    return (Hako_HakoCameraData*)base_ptr;
}
#endif /* _PDU_CTYPE_CONV_HAKO_hako_msgs_HakoCameraData_HPP_ */
