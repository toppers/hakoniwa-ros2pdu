#ifndef _PDU_CTYPE_CONV_HAKO_{{container.pkg_name}}_{{container.msg_type_name}}_HPP_
#define _PDU_CTYPE_CONV_HAKO_{{container.pkg_name}}_{{container.msg_type_name}}_HPP_

#include "pdu_primitive_ctypes.h"
#include "ros_primitive_types.hpp"
#include "pdu_primitive_ctypes_conv.hpp"
#include "pdu_dynamic_memory.hpp"
/*
 * Dependent pdu data
 */
#include "{{container.pkg_name}}/pdu_ctype_{{container.msg_type_name}}.h"
/*
 * Dependent ros data
 */
#include "{{container.pkg_name}}/msg/{{container.convert_snake(container.msg_type_name)}}.hpp"

/*
 * Dependent Convertors
 */
{%- for item in container.conv_includes %}
#include "{{item}}"
{%- endfor %}

/***************************
 *
 * PDU ==> ROS2
 *
 ***************************/
static inline int _pdu2ros_{{container.msg_type_name}}(char* varray_ptr, Hako_{{container.msg_type_name}} &src, {{container.pkg_name}}::msg::{{container.msg_type_name}} &dst)
{
{%- for item in container.json_data["fields"] %}
{%-     if (container.is_primitive(item["type"])) %}
    // primitive convert
    hako_convert_pdu2ros(src.{{item["name"]}}, dst.{{item["name"]}});
{%-     elif (container.is_string(item["type"])) %}
    // string convertor
    dst.{{item["name"]}} = (const char*)src.{{item["name"]}};
{%-     elif (container.is_primitive_array(item["type"]) or container.is_string_array(item["type"]) or container.is_array(item["type"])) %}
{%-         set array_size = container.get_array_size(item["name"], item["type"]) %}
{%-         if array_size is none %}
    // Convert using len and off
    int offset = src._{{item["name"]}}_off;
    int length = src._{{item["name"]}}_len;
    dst.{{item["name"]}}.resize(length);
    memcpy(dst.{{item["name"]}}.data(), varray_ptr + offset, length * sizeof(src.{{item["name"]}}[0]));
{%-         else %}
    // Fixed size array convertor
    for (int i = 0; i < {{array_size}}; ++i) {
        hako_convert_pdu2ros(src.{{item["name"]}}[i], dst.{{item["name"]}}[i]);
    }
{%-         endif %}
{%-     else %}
    // Struct convert
    _pdu2ros_{{container.get_msg_type(item["type"])}}(base_ptr, src.{{item["name"]}}, dst.{{item["name"]}});
{%-     endif %}
{%- endfor %}
    return 0;
}

static inline int hako_convert_pdu2ros_{{container.msg_type_name}}(int total_size, Hako_{{container.msg_type_name}} &src, {{container.pkg_name}}::msg::{{container.msg_type_name}} &dst)
{
    if (total_size > 0) {
        char* base_ptr = (char*)&src;
        HakoPduMetaDataType* meta = (HakoPduMetaDataType*)(base_ptr + total_size - sizeof(HakoPduMetaDataType));

        // Validate magic number and version
        if (meta->magicno != HAKO_PDU_META_DATA_MAGICNO || meta->version != HAKO_PDU_META_DATA_VERSION) {
            return -1; // Invalid PDU metadata
        }

        return _pdu2ros_{{container.msg_type_name}}(base_ptr + sizeof(Hako_{{container.msg_type_name}}), src, dst);
    }
    else {
        return -1; // Invalid total size
    }
}

/***************************
 *
 * ROS2 ==> PDU
 *
 ***************************/
static inline bool _ros2pdu_{{container.msg_type_name}}({{container.pkg_name}}::msg::{{container.msg_type_name}} &src, Hako_{{container.msg_type_name}} &dst, PduDynamicMemory &dynamic_memory)
{
    try {
{%- for item in container.json_data["fields"] %}
{%-     if (container.is_primitive(item["type"])) %}
        // primitive convert
        hako_convert_ros2pdu(src.{{item["name"]}}, dst.{{item["name"]}});
{%-     elif (container.is_string(item["type"])) %}
        // string convertor
        strncpy(dst.{{item["name"]}}, src.{{item["name"]}}.c_str(), sizeof(dst.{{item["name"]}}));
{%-     elif (container.is_primitive_array(item["type"]) or container.is_string_array(item["type"]) or container.is_array(item["type"])) %}
{%-         set array_size = container.get_array_size(item["name"], item["type"]) %}
{%-         if array_size is none %}
        // Phase 1: Allocate memory and set length
        dst._{{item["name"]}}_len = src.{{item["name"]}}.size();
        void* temp_ptr = dynamic_memory.allocate(dst._{{item["name"]}}_len, sizeof(src.{{item["name"]}}[0]));
        memcpy(temp_ptr, src.{{item["name"]}}.data(), dst._{{item["name"]}}_len * sizeof(src.{{item["name"]}}[0]));
        dst._{{item["name"]}}_off = dynamic_memory.get_offset(temp_ptr);
{%-         else %}
        // Fixed size array convertor
        for (int i = 0; i < {{array_size}}; ++i) {
            hako_convert_ros2pdu(src.{{item["name"]}}[i], dst.{{item["name"]}}[i]);
        }
{%-         endif %}
{%-     else %}
        // Struct convert
        hako_convert_ros2pdu{{container.get_msg_type(item["type"])}}(false, src.{{item["name"]}}, dst.{{item["name"]}}, dynamic_memory);
{%-     endif %}
{%- endfor %}
    } catch (const std::runtime_error& e) {
        std::cerr << "Phase 1 error: " << e.what() << std::endl;
        return false;
    }
    return true;
}


static inline int hako_convert_ros2pdu_{{container.msg_type_name}}(bool root, {{container.pkg_name}}::msg::{{container.msg_type_name}} &src, Hako_{{container.msg_type_name}}** dst, PduDynamicMemory &dynamic_memory)
{
    if (!_ros2pdu_{{container.msg_type_name}}(src, *dst, dynamic_memory)) {
        return -1;
    }
    if (root) {
        int total_size = sizeof(Hako_{{container.msg_type_name}}) + dynamic_memory.get_total_size() + sizeof(HakoPduMetaDataType);

        // Allocate PDU memory
        char* base_ptr = (Hako_{{container.msg_type_name}}*)malloc(total_size);
        if (base_ptr == nullptr) {
            return -1;
        }
        // Copy dynamic part and set offsets
        dynamic_memory.copy_to_pdu(base_ptr + sizeof(Hako_{{container.msg_type_name}}));

        // Set metadata at the end
        HakoPduMetaDataType* meta = (HakoPduMetaDataType*)(base_ptr + total_size - sizeof(HakoPduMetaDataType));
        meta->magicno = HAKO_PDU_META_DATA_MAGICNO;
        meta->version = HAKO_PDU_META_DATA_VERSION;
        meta->top_off = 0;
        meta->total_size = total_size;
        meta->varray_off = sizeof(Hako_{{container.msg_type_name}});

        *dst = base_ptr;
        return total_size;
    }

    return 0;
}

#endif /* _PDU_CTYPE_CONV_HAKO_{{container.pkg_name}}_{{container.msg_type_name}}_HPP_ */
