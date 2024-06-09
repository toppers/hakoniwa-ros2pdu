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
    if (length > 0) {
        dst.{{item["name"]}}.resize(length);
        memcpy(dst.{{item["name"]}}.data(), varray_ptr + offset, length * sizeof(Hako_{{container.get_msg_type(container.get_array_type(item["type"]))}});
    }
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
        if ((meta->magicno != HAKO_PDU_META_DATA_MAGICNO) || (meta->version != HAKO_PDU_META_DATA_VERSION)) {
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
{%- for item in container.json_data["fields"] %}
{%-     if (container.is_primitive_array(item["type"])) %}
static inline bool _ros2pdu_primitive_array_{{container.msg_type_name}}_{{item["name"]}}({{container.pkg_name}}::msg::{{container.msg_type_name}} &src, Hako_{{container.msg_type_name}} &dst, PduDynamicMemory &dynamic_memory)
{
{%-     set array_size = container.get_array_size(item["name"], item["type"]) %}
{%-     if array_size is none %}
    //Copy varray
    dst._{{item["name"]}}_len = src.{{item["name"]}}.size();
    if (dst._{{item["name"]}}_len > 0) {
        void* temp_ptr = dynamic_memory.allocate(dst._{{item["name"]}}_len, sizeof(Hako_{{container.get_msg_type(container.get_array_type(item["type"]))}}));
        memcpy(temp_ptr, src.{{item["name"]}}.data(), dst._{{item["name"]}}_len * sizeof(Hako_{{container.get_msg_type(container.get_array_type(item["type"]))}}));
        dst._{{item["name"]}}_off = dynamic_memory.get_offset(temp_ptr);
    }
    else {
        dst._{{item["name"]}}_off = dynamic_memory.get_total_size();
    }
{%-     else %}
    //Copy fixed array {{array_size}}
    (void)hako_convert_ros2pdu_array(
        src.{{item["name"]}}, src.{{item["name"]}}.size(),
        dst.{{item["name"]}}, M_ARRAY_SIZE(Hako_{{container.msg_type_name}}, Hako_{{container.get_array_type(item["type"])}}, {{item["name"]}}));
{%-     endif %}
    return true;
}
{%-     elif (container.is_string_array(item["type"])) %}
static inline bool _ros2pdu_string_array_{{container.msg_type_name}}_{{item["name"]}}({{container.pkg_name}}::msg::{{container.msg_type_name}} &src, Hako_{{container.msg_type_name}} &dst, PduDynamicMemory &dynamic_memory)
{
{%-     set array_size = container.get_array_size(item["name"], item["type"]) %}
{%-     if array_size is none %}
    //Copy varray string
    dst._{{item["name"]}}_len = src.{{item["name"]}}.size();
    if (dst._{{item["name"]}}_len > 0) {
        Hako_cstring* temp_ptr = (Hako_cstring*)dynamic_memory.allocate(dst._{{item["name"]}}_len, sizeof(Hako_cstring));
        (void)hako_convert_ros2pdu_array_string_varray(src.{{item["name"]}}, (Hako_cstring[])temp_ptr);
        dst._{{item["name"]}}_off = dynamic_memory.get_offset(temp_ptr);
    }
    else {
        dst._{{item["name"]}}_off = dynamic_memory.get_total_size();
    }
{%-     else %}
    //Copy fixed string {{array_size}}
    (void)hako_convert_ros2pdu_array_string<{{container.get_array_size(item["name"], item["type"])}}, M_ARRAY_SIZE(Hako_{{container.msg_type_name}}, Hako_cstring, {{item["name"]}})>(
        src.{{item["name"]}}, dst.{{item["name"]}});
{%-     endif %}
    return true;
}

{%-     elif (container.is_array(item["type"])) %}
static inline bool _ros2pdu_struct_array_{{container.msg_type_name}}_{{item["name"]}}({{container.pkg_name}}::msg::{{container.msg_type_name}} &src, Hako_{{container.msg_type_name}} &dst, PduDynamicMemory &dynamic_memory)
{
    // array struct
{%-     set array_size = container.get_array_size(item["name"], item["type"]) %}
{%-     if array_size is none %}
    dst._{{item["name"]}}_len = src.{{item["name"]}}.size();
    if (dst._{{item["name"]}}_len > 0) {
        Hako_{{container.get_msg_type(container.get_array_type(item["type"]))}}* temp_struct_ptr = dynamic_memory.allocate(dst._{{item["name"]}}_len, sizeof(Hako_{{container.get_msg_type(container.get_array_type(item["type"]))}}));
        dst._{{item["name"]}}_off = dynamic_memory.get_offset(temp_struct_ptr);
        for (int i = 0; i < dst._{{item["name"]}}_len; ++i) {
            _ros2pdu_{{container.get_msg_type(container.get_array_type(item["type"]))}}(src.{{item["name"]}}[i], *temp_struct_ptr, dynamic_memory);
            temp_struct_ptr++;
        }
    }
    else {
        dst._{{item["name"]}}_off = dynamic_memory.get_total_size();
    }
{%-     else %}
    //array size is fixed
    for (int i = 0; i < {{array_size}}; ++i) {
        _ros2pdu_{{container.get_msg_type(container.get_array_type(item["type"]))}}(src.{{item["name"]}}[i], dst.{{item["name"]}}[i], dynamic_memory);
    }
{%-     endif %}
    return true;
}
{%- endif %}
{%- endfor %}

static inline bool _ros2pdu_{{container.msg_type_name}}({{container.pkg_name}}::msg::{{container.msg_type_name}} &src, Hako_{{container.msg_type_name}} &dst, PduDynamicMemory &dynamic_memory)
{
    try {
{%- for item in container.json_data["fields"] %}
{%-     if (container.is_primitive(item["type"])) %}
        // primitive convert
        hako_convert_ros2pdu(src.{{item["name"]}}, dst.{{item["name"]}});
{%-     elif (container.is_string(item["type"])) %}
        // string convertor
        (void)hako_convert_ros2pdu_array(
            src.{{item["name"]}}, src.{{item["name"]}}.length(),
            dst.{{item["name"]}}, M_ARRAY_SIZE(Hako_{{container.msg_type_name}}, char, {{item["name"]}}));        
{%-     elif (container.is_primitive_array(item["type"])) %}
        //primitive array copy
        _ros2pdu_primitive_array_{{container.msg_type_name}}_{{item["name"]}}(src, dst, dynamic_memory);
{%-     elif (container.is_string_array(item["type"])) %}
        // string array convert
        _ros2pdu_string_array_{{container.msg_type_name}}_{{item["name"]}}(src, dst, dynamic_memory);
{%-     elif (container.is_array(item["type"])) %}
        //struct array convert
        _ros2pdu_struct_array_{{container.msg_type_name}}_{{item["name"]}}(src, dst, dynamic_memory);
{%-     else %}
        // struct convert
        _ros2pdu_{{container.get_msg_type(item["type"])}}(src.{{item["name"]}}, dst.{{item["name"]}}, dynamic_memory);
{%-     endif %}
{%- endfor %}
    } catch (const std::runtime_error& e) {
        std::cerr << "convertor error: " << e.what() << std::endl;
        return false;
    }
    return true;
}

static inline int hako_convert_ros2pdu_{{container.msg_type_name}}({{container.pkg_name}}::msg::{{container.msg_type_name}} &src, Hako_{{container.msg_type_name}}** dst)
{
    PduDynamicMemory dynamic_memory;
    Hako_{{container.msg_type_name}} out;
    if (!_ros2pdu_{{container.msg_type_name}}(src, out, dynamic_memory)) {
        return -1;
    }
    int total_size = sizeof(Hako_{{container.msg_type_name}}) + sizeof(HakoPduMetaDataType) + dynamic_memory.get_total_size();

    // Allocate PDU memory
    char* base_ptr = (Hako_{{container.msg_type_name}}*)malloc(total_size);
    if (base_ptr == nullptr) {
        return -1;
    }
    // Copy out on top
    memcpy(base_ptr, (void*)&out, sizeof(Hako_{{container.msg_type_name}}));

    // Set metadata at the end
    HakoPduMetaDataType* meta = (HakoPduMetaDataType*)(base_ptr + sizeof(Hako_{{container.msg_type_name}}));
    meta->magicno = HAKO_PDU_META_DATA_MAGICNO;
    meta->version = HAKO_PDU_META_DATA_VERSION;
    meta->top_off = 0;
    meta->total_size = total_size;
    meta->varray_off = sizeof(Hako_{{container.msg_type_name}}) + sizeof(HakoPduMetaDataType);

    // Copy dynamic part and set offsets
    dynamic_memory.copy_to_pdu(base_ptr + meta->varray_off);

    *dst = base_ptr;
    return total_size;
}

#endif /* _PDU_CTYPE_CONV_HAKO_{{container.pkg_name}}_{{container.msg_type_name}}_HPP_ */
