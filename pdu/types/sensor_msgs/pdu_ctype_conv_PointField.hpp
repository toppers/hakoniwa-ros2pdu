#ifndef _PDU_CTYPE_CONV_HAKO_sensor_msgs_PointField_HPP_
#define _PDU_CTYPE_CONV_HAKO_sensor_msgs_PointField_HPP_

#include "pdu_primitive_ctypes.h"
#include "ros_primitive_types.hpp"
#include "pdu_primitive_ctypes_conv.hpp"
#include "pdu_dynamic_memory.hpp"
/*
 * Dependent pdu data
 */
#include "sensor_msgs/pdu_ctype_PointField.h"
/*
 * Dependent ros data
 */
#include "sensor_msgs/msg/point_field.hpp"

/*
 * Dependent Convertors
 */

/***************************
 *
 * PDU ==> ROS2
 *
 ***************************/

static inline int _pdu2ros_PointField(const char* varray_ptr, Hako_PointField &src, sensor_msgs::msg::PointField &dst)
{
    // string convertor
    dst.name = (const char*)src.name;
    // primitive convert
    hako_convert_pdu2ros(src.offset, dst.offset);
    // primitive convert
    hako_convert_pdu2ros(src.datatype, dst.datatype);
    // primitive convert
    hako_convert_pdu2ros(src.count, dst.count);
    return 0;
}

static inline int hako_convert_pdu2ros_PointField(Hako_PointField &src, sensor_msgs::msg::PointField &dst)
{
    char* base_ptr = (char*)&src;
    HakoPduMetaDataType* meta = (HakoPduMetaDataType*)(base_ptr + sizeof(Hako_PointField));

    // Validate magic number and version
    if ((meta->magicno != HAKO_PDU_META_DATA_MAGICNO) || (meta->version != HAKO_PDU_META_DATA_VERSION)) {
        return -1; // Invalid PDU metadata
    }
    else {
        char *varray_ptr = base_ptr + sizeof(Hako_PointField) + sizeof(HakoPduMetaDataType);
        return _pdu2ros_PointField(varray_ptr, src, dst);
    }
}

/***************************
 *
 * ROS2 ==> PDU
 *
 ***************************/

static inline bool _ros2pdu_PointField(sensor_msgs::msg::PointField &src, Hako_PointField &dst, PduDynamicMemory &dynamic_memory)
{
    try {
        // string convertor
        (void)hako_convert_ros2pdu_array(
            src.name, src.name.length(),
            dst.name, M_ARRAY_SIZE(Hako_PointField, char, name));
        // primitive convert
        hako_convert_ros2pdu(src.offset, dst.offset);
        // primitive convert
        hako_convert_ros2pdu(src.datatype, dst.datatype);
        // primitive convert
        hako_convert_ros2pdu(src.count, dst.count);
    } catch (const std::runtime_error& e) {
        std::cerr << "convertor error: " << e.what() << std::endl;
        return false;
    }
    return true;
}

static inline int hako_convert_ros2pdu_PointField(sensor_msgs::msg::PointField &src, Hako_PointField** dst)
{
    PduDynamicMemory dynamic_memory;
    Hako_PointField out;
    if (!_ros2pdu_PointField(src, out, dynamic_memory)) {
        return -1;
    }
    int total_size = sizeof(Hako_PointField) + sizeof(HakoPduMetaDataType) + dynamic_memory.get_total_size();

    // Allocate PDU memory
    char* base_ptr = (char*)malloc(total_size);
    if (base_ptr == nullptr) {
        return -1;
    }
    // Copy out on top
    memcpy(base_ptr, (void*)&out, sizeof(Hako_PointField));

    // Set metadata at the end
    HakoPduMetaDataType* meta = (HakoPduMetaDataType*)(base_ptr + sizeof(Hako_PointField));
    meta->magicno = HAKO_PDU_META_DATA_MAGICNO;
    meta->version = HAKO_PDU_META_DATA_VERSION;
    meta->top_off = 0;
    meta->total_size = total_size;
    meta->varray_off = sizeof(Hako_PointField) + sizeof(HakoPduMetaDataType);

    // Copy dynamic part and set offsets
    dynamic_memory.copy_to_pdu(base_ptr + meta->varray_off);

    *dst = (Hako_PointField*)base_ptr;
    return total_size;
}
static inline Hako_PointField* hako_create_empty_pdu_PointField(int heap_size)
{
    int total_size = sizeof(Hako_PointField) + sizeof(HakoPduMetaDataType) + heap_size;

    // Allocate PDU memory
    char* base_ptr = (char*)malloc(total_size);
    if (base_ptr == nullptr) {
        return nullptr;
    }
    memset(base_ptr, 0, total_size);
    // Set metadata at the end
    HakoPduMetaDataType* meta = (HakoPduMetaDataType*)(base_ptr + sizeof(Hako_PointField));
    meta->magicno = HAKO_PDU_META_DATA_MAGICNO;
    meta->version = HAKO_PDU_META_DATA_VERSION;
    meta->top_off = 0;
    meta->total_size = total_size;
    meta->varray_off = sizeof(Hako_PointField) + sizeof(HakoPduMetaDataType);
    return (Hako_PointField*)base_ptr;
}
#endif /* _PDU_CTYPE_CONV_HAKO_sensor_msgs_PointField_HPP_ */
