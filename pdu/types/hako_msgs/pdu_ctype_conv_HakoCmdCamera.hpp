#ifndef _PDU_CTYPE_CONV_HAKO_hako_msgs_HakoCmdCamera_HPP_
#define _PDU_CTYPE_CONV_HAKO_hako_msgs_HakoCmdCamera_HPP_

#include "pdu_primitive_ctypes.h"
#include "ros_primitive_types.hpp"
#include "pdu_primitive_ctypes_conv.hpp"
#include "pdu_dynamic_memory.hpp"
/*
 * Dependent pdu data
 */
#include "hako_msgs/pdu_ctype_HakoCmdCamera.h"
/*
 * Dependent ros data
 */
#include "hako_msgs/msg/hako_cmd_camera.hpp"

/*
 * Dependent Convertors
 */
#include "hako_msgs/pdu_ctype_conv_HakoCmdHeader.hpp"

/***************************
 *
 * PDU ==> ROS2
 *
 ***************************/

static inline int _pdu2ros_HakoCmdCamera(const char* varray_ptr, Hako_HakoCmdCamera &src, hako_msgs::msg::HakoCmdCamera &dst)
{
    // Struct convert
    _pdu2ros_HakoCmdHeader(varray_ptr, src.header, dst.header);
    // primitive convert
    hako_convert_pdu2ros(src.request_id, dst.request_id);
    // primitive convert
    hako_convert_pdu2ros(src.encode_type, dst.encode_type);
    return 0;
}

static inline int hako_convert_pdu2ros_HakoCmdCamera(Hako_HakoCmdCamera &src, hako_msgs::msg::HakoCmdCamera &dst)
{
    char* base_ptr = (char*)&src;
    HakoPduMetaDataType* meta = (HakoPduMetaDataType*)(base_ptr + sizeof(Hako_HakoCmdCamera));

    // Validate magic number and version
    if ((meta->magicno != HAKO_PDU_META_DATA_MAGICNO) || (meta->version != HAKO_PDU_META_DATA_VERSION)) {
        return -1; // Invalid PDU metadata
    }
    else {
        char *varray_ptr = base_ptr + sizeof(Hako_HakoCmdCamera) + sizeof(HakoPduMetaDataType);
        return _pdu2ros_HakoCmdCamera(varray_ptr, src, dst);
    }
}

/***************************
 *
 * ROS2 ==> PDU
 *
 ***************************/

static inline bool _ros2pdu_HakoCmdCamera(hako_msgs::msg::HakoCmdCamera &src, Hako_HakoCmdCamera &dst, PduDynamicMemory &dynamic_memory)
{
    try {
        // struct convert
        _ros2pdu_HakoCmdHeader(src.header, dst.header, dynamic_memory);
        // primitive convert
        hako_convert_ros2pdu(src.request_id, dst.request_id);
        // primitive convert
        hako_convert_ros2pdu(src.encode_type, dst.encode_type);
    } catch (const std::runtime_error& e) {
        std::cerr << "convertor error: " << e.what() << std::endl;
        return false;
    }
    return true;
}

static inline int hako_convert_ros2pdu_HakoCmdCamera(hako_msgs::msg::HakoCmdCamera &src, Hako_HakoCmdCamera** dst)
{
    PduDynamicMemory dynamic_memory;
    Hako_HakoCmdCamera out;
    if (!_ros2pdu_HakoCmdCamera(src, out, dynamic_memory)) {
        return -1;
    }
    int total_size = sizeof(Hako_HakoCmdCamera) + sizeof(HakoPduMetaDataType) + dynamic_memory.get_total_size();

    // Allocate PDU memory
    char* base_ptr = (char*)malloc(total_size);
    if (base_ptr == nullptr) {
        return -1;
    }
    // Copy out on top
    memcpy(base_ptr, (void*)&out, sizeof(Hako_HakoCmdCamera));

    // Set metadata at the end
    HakoPduMetaDataType* meta = (HakoPduMetaDataType*)(base_ptr + sizeof(Hako_HakoCmdCamera));
    meta->magicno = HAKO_PDU_META_DATA_MAGICNO;
    meta->version = HAKO_PDU_META_DATA_VERSION;
    meta->top_off = 0;
    meta->total_size = total_size;
    meta->varray_off = sizeof(Hako_HakoCmdCamera) + sizeof(HakoPduMetaDataType);

    // Copy dynamic part and set offsets
    dynamic_memory.copy_to_pdu(base_ptr + meta->varray_off);

    *dst = (Hako_HakoCmdCamera*)base_ptr;
    return total_size;
}

#endif /* _PDU_CTYPE_CONV_HAKO_hako_msgs_HakoCmdCamera_HPP_ */
