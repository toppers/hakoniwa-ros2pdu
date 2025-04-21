#ifndef _PDU_CPPTYPE_CONV_HAKO_{{container.pkg_name}}_{{container.msg_type_name}}_HPP_
#define _PDU_CPPTYPE_CONV_HAKO_{{container.pkg_name}}_{{container.msg_type_name}}_HPP_

#include "pdu_primitive_ctypes.h"
#include "pdu_primitive_ctypes_conv.hpp"
#include "pdu_dynamic_memory.hpp"
/*
 * Dependent pdu data
 */
#include "{{container.pkg_name}}/pdu_ctype_{{container.msg_type_name}}.h"
/*
 * Dependent cpp pdu data
 */
#include "{{container.pkg_name}}/pdu_cpptype_{{container.msg_type_name}}.hpp"

/*
 * Dependent Convertors
 */
{%- for item in container.conv_cpp_includes %}
#include "{{item}}"
{%- endfor %}

/***************************
 *
 * PDU ==> CPP PDU
 *
 ***************************/
{%- for item in container.json_data["fields"] %}
{%-     if (container.is_primitive_array(item["type"])) %}
static inline int cpp_pdu2cpp_primitive_array_{{container.msg_type_name}}_{{item["name"]}}(const char* heap_ptr, Hako_{{container.msg_type_name}} &src, HakoCpp_{{container.msg_type_name}} &dst)
{
{%-         set array_size = container.get_array_size(item["name"], item["type"]) %}
{%-         if array_size is none %}
    // Convert using len and off
    int offset = src._{{item["name"]}}_off;
    int length = src._{{item["name"]}}_len;
    if (length > 0) {
        dst.{{item["name"]}}.resize(length);
        memcpy(dst.{{item["name"]}}.data(), heap_ptr + offset, length * sizeof(Hako_{{container.get_msg_type(container.get_array_type(item["type"]))}}));
    }
{%-         else %}
    // Fixed size array convertor
    (void)heap_ptr;
    for (int i = 0; i < {{array_size}}; ++i) {
        hako_convert_pdu2cpp(src.{{item["name"]}}[i], dst.{{item["name"]}}[i]);
    }
{%-         endif %}
    return 0;
}
{%-     elif (container.is_string_array(item["type"])) %}
static inline int cpp_pdu2cpp_string_array_{{container.msg_type_name}}_{{item["name"]}}(const char* heap_ptr, Hako_{{container.msg_type_name}} &src, HakoCpp_{{container.msg_type_name}} &dst)
{
{%-         set array_size = container.get_array_size(item["name"], item["type"]) %}
{%-         if array_size is none %}
    // Convert using len and off
    int offset = src._{{item["name"]}}_off;
    int length = src._{{item["name"]}}_len;
    if (length > 0) {
        Hako_cstring *temp_struct_ptr = (Hako_cstring *)(heap_ptr + offset);
        hako_convert_pdu2cpp_array_string_varray(temp_struct_ptr, dst.{{item["name"]}}, length);
    }
{%-         else %}
    // Fixed size array convertor
    (void)heap_ptr;
    (void)hako_convert_pdu2cpp_array_string<M_ARRAY_SIZE(Hako_{{container.msg_type_name}}, Hako_cstring, {{item["name"]}}), {{container.get_array_size(item["name"], item["type"])}}>(
        src.{{item["name"]}}, dst.{{item["name"]}});
{%-         endif %}
    return 0;
}
{%-     elif (container.is_array(item["type"])) %}
static inline int cpp_pdu2cpp_struct_array_{{container.msg_type_name}}_{{item["name"]}}(const char* heap_ptr, Hako_{{container.msg_type_name}} &src, HakoCpp_{{container.msg_type_name}} &dst)
{
{%-         set array_size = container.get_array_size(item["name"], item["type"]) %}
{%-         if array_size is none %}
    // Convert using len and off
    int offset = src._{{item["name"]}}_off;
    int length = src._{{item["name"]}}_len;
    if (length > 0) {
        dst.{{item["name"]}}.resize(length);
        Hako_{{container.get_msg_type(container.get_array_type(item["type"]))}} *temp_struct_ptr = (Hako_{{container.get_msg_type(container.get_array_type(item["type"]))}} *)(heap_ptr + offset);
        for (int i = 0; i < length; ++i) {
            cpp_pdu2cpp_{{container.get_msg_type(container.get_array_type(item["type"]))}}(heap_ptr, *temp_struct_ptr, dst.{{item["name"]}}[i]);
            temp_struct_ptr++;
        }
    }
{%-         else %}
    // Fixed size array convertor
    for (int i = 0; i < {{array_size}}; ++i) {
        cpp_pdu2cpp_{{container.get_msg_type(container.get_array_type(item["type"]))}}(heap_ptr, src.{{item["name"]}}[i], dst.{{item["name"]}}[i]);
    }
{%-         endif %}
    return 0;
}
{%-     endif %}
{%- endfor %}

static inline int cpp_pdu2cpp_{{container.msg_type_name}}(const char* heap_ptr, Hako_{{container.msg_type_name}} &src, HakoCpp_{{container.msg_type_name}} &dst)
{
{%- for item in container.json_data["fields"] %}
{%-     if (container.is_primitive(item["type"])) %}
    // primitive convert
    hako_convert_pdu2cpp(src.{{item["name"]}}, dst.{{item["name"]}});
{%-     elif (container.is_string(item["type"])) %}
    // string convertor
    dst.{{item["name"]}} = (const char*)src.{{item["name"]}};
{%-     elif (container.is_primitive_array(item["type"])) %}
    // primitive array convertor
    cpp_pdu2cpp_primitive_array_{{container.msg_type_name}}_{{item["name"]}}(heap_ptr, src, dst);
{%-     elif (container.is_string_array(item["type"])) %}
    // string array convertor
    cpp_pdu2cpp_string_array_{{container.msg_type_name}}_{{item["name"]}}(heap_ptr, src, dst);
{%-     elif (container.is_array(item["type"])) %}
    // struct array convertor
    cpp_pdu2cpp_struct_array_{{container.msg_type_name}}_{{item["name"]}}(heap_ptr, src, dst);
{%-     else %}
    // Struct convert
    cpp_pdu2cpp_{{container.get_msg_type(item["type"])}}(heap_ptr, src.{{item["name"]}}, dst.{{item["name"]}});
{%-     endif %}
{%- endfor %}
    (void)heap_ptr;
    return 0;
}

static inline int hako_convert_pdu2cpp_{{container.msg_type_name}}(Hako_{{container.msg_type_name}} &src, HakoCpp_{{container.msg_type_name}} &dst)
{
    void* base_ptr = (void*)&src;
    void* heap_ptr = hako_get_heap_ptr_pdu(base_ptr);
    // Validate magic number and version
    if (heap_ptr == nullptr) {
        return -1; // Invalid PDU metadata
    }
    else {
        return cpp_pdu2cpp_{{container.msg_type_name}}((char*)heap_ptr, src, dst);
    }
}

/***************************
 *
 * CPP PDU ==> PDU
 *
 ***************************/
{%- for item in container.json_data["fields"] %}
{%-     if (container.is_primitive_array(item["type"])) %}
static inline bool cpp_cpp2pdu_primitive_array_{{container.msg_type_name}}_{{item["name"]}}(HakoCpp_{{container.msg_type_name}} &src, Hako_{{container.msg_type_name}} &dst, PduDynamicMemory &dynamic_memory)
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
    (void)dynamic_memory;
    (void)hako_convert_cpp2pdu_array(
        src.{{item["name"]}}, src.{{item["name"]}}.size(),
        dst.{{item["name"]}}, M_ARRAY_SIZE(Hako_{{container.msg_type_name}}, Hako_{{container.get_array_type(item["type"])}}, {{item["name"]}}));
{%-     endif %}
    return true;
}
{%-     elif (container.is_string_array(item["type"])) %}
static inline bool cpp_cpp2pdu_string_array_{{container.msg_type_name}}_{{item["name"]}}(HakoCpp_{{container.msg_type_name}} &src, Hako_{{container.msg_type_name}} &dst, PduDynamicMemory &dynamic_memory)
{
{%-     set array_size = container.get_array_size(item["name"], item["type"]) %}
{%-     if array_size is none %}
    //Copy varray string
    dst._{{item["name"]}}_len = src.{{item["name"]}}.size();
    if (dst._{{item["name"]}}_len > 0) {
        Hako_cstring* temp_ptr = (Hako_cstring*)dynamic_memory.allocate(dst._{{item["name"]}}_len, sizeof(Hako_cstring));
        (void)hako_convert_cpp2pdu_array_string_varray(src.{{item["name"]}}, temp_ptr);
        dst._{{item["name"]}}_off = dynamic_memory.get_offset(temp_ptr);
    }
    else {
        dst._{{item["name"]}}_off = dynamic_memory.get_total_size();
    }
{%-     else %}
    //Copy fixed string {{array_size}}
    (void)dynamic_memory;
    (void)hako_convert_cpu2pdu_array_string<{{container.get_array_size(item["name"], item["type"])}}, M_ARRAY_SIZE(Hako_{{container.msg_type_name}}, Hako_cstring, {{item["name"]}})>(
        src.{{item["name"]}}, dst.{{item["name"]}});
{%-     endif %}
    return true;
}

{%-     elif (container.is_array(item["type"])) %}
static inline bool cpp_cpp2pdu_struct_array_{{container.msg_type_name}}_{{item["name"]}}(HakoCpp_{{container.msg_type_name}} &src, Hako_{{container.msg_type_name}} &dst, PduDynamicMemory &dynamic_memory)
{
    // array struct
{%-     set array_size = container.get_array_size(item["name"], item["type"]) %}
{%-     if array_size is none %}
    dst._{{item["name"]}}_len = src.{{item["name"]}}.size();
    if (dst._{{item["name"]}}_len > 0) {
        Hako_{{container.get_msg_type(container.get_array_type(item["type"]))}}* temp_struct_ptr = (Hako_{{container.get_msg_type(container.get_array_type(item["type"]))}}*)dynamic_memory.allocate(dst._{{item["name"]}}_len, sizeof(Hako_{{container.get_msg_type(container.get_array_type(item["type"]))}}));
        dst._{{item["name"]}}_off = dynamic_memory.get_offset(temp_struct_ptr);
        for (int i = 0; i < dst._{{item["name"]}}_len; ++i) {
            cpp_cpp2pdu_{{container.get_msg_type(container.get_array_type(item["type"]))}}(src.{{item["name"]}}[i], *temp_struct_ptr, dynamic_memory);
            temp_struct_ptr++;
        }
    }
    else {
        dst._{{item["name"]}}_off = dynamic_memory.get_total_size();
    }
{%-     else %}
    //array size is fixed
    for (int i = 0; i < {{array_size}}; ++i) {
        cpp_cpp2pdu_{{container.get_msg_type(container.get_array_type(item["type"]))}}(src.{{item["name"]}}[i], dst.{{item["name"]}}[i], dynamic_memory);
    }
{%-     endif %}
    return true;
}
{%- endif %}
{%- endfor %}

static inline bool cpp_cpp2pdu_{{container.msg_type_name}}(HakoCpp_{{container.msg_type_name}} &src, Hako_{{container.msg_type_name}} &dst, PduDynamicMemory &dynamic_memory)
{
    try {
{%- for item in container.json_data["fields"] %}
{%-     if (container.is_primitive(item["type"])) %}
        // primitive convert
        hako_convert_cpp2pdu(src.{{item["name"]}}, dst.{{item["name"]}});
{%-     elif (container.is_string(item["type"])) %}
        // string convertor
        (void)hako_convert_cpp2pdu_array(
            src.{{item["name"]}}, src.{{item["name"]}}.length(),
            dst.{{item["name"]}}, M_ARRAY_SIZE(Hako_{{container.msg_type_name}}, char, {{item["name"]}}));
        dst.{{item["name"]}}[src.{{item["name"]}}.length()] = '\0';
{%-     elif (container.is_primitive_array(item["type"])) %}
        //primitive array copy
        cpp_cpp2pdu_primitive_array_{{container.msg_type_name}}_{{item["name"]}}(src, dst, dynamic_memory);
{%-     elif (container.is_string_array(item["type"])) %}
        // string array convert
        cpp_cpp2pdu_string_array_{{container.msg_type_name}}_{{item["name"]}}(src, dst, dynamic_memory);
{%-     elif (container.is_array(item["type"])) %}
        //struct array convert
        cpp_cpp2pdu_struct_array_{{container.msg_type_name}}_{{item["name"]}}(src, dst, dynamic_memory);
{%-     else %}
        // struct convert
        cpp_cpp2pdu_{{container.get_msg_type(item["type"])}}(src.{{item["name"]}}, dst.{{item["name"]}}, dynamic_memory);
{%-     endif %}
{%- endfor %}
    } catch (const std::runtime_error& e) {
        std::cerr << "convertor error: " << e.what() << std::endl;
        return false;
    }
    (void)dynamic_memory;
    return true;
}

static inline int hako_convert_cpp2pdu_{{container.msg_type_name}}(HakoCpp_{{container.msg_type_name}} &src, Hako_{{container.msg_type_name}}** dst)
{
    PduDynamicMemory dynamic_memory;
    Hako_{{container.msg_type_name}} out;
    if (!cpp_cpp2pdu_{{container.msg_type_name}}(src, out, dynamic_memory)) {
        return -1;
    }
    int heap_size = dynamic_memory.get_total_size();
    void* base_ptr = hako_create_empty_pdu(sizeof(Hako_{{container.msg_type_name}}), heap_size);
    if (base_ptr == nullptr) {
        return -1;
    }
    // Copy out on base data
    memcpy(base_ptr, (void*)&out, sizeof(Hako_{{container.msg_type_name}}));

    // Copy dynamic part and set offsets
    void* heap_ptr = hako_get_heap_ptr_pdu(base_ptr);
    dynamic_memory.copy_to_pdu((char*)heap_ptr);

    *dst = (Hako_{{container.msg_type_name}}*)base_ptr;
    return hako_get_pdu_meta_data(base_ptr)->total_size;
}

static inline Hako_{{container.msg_type_name}}* hako_create_empty_pdu_{{container.msg_type_name}}(int heap_size)
{
    // Allocate PDU memory
    char* base_ptr = (char*)hako_create_empty_pdu(sizeof(Hako_{{container.msg_type_name}}), heap_size);
    if (base_ptr == nullptr) {
        return nullptr;
    }
    return (Hako_{{container.msg_type_name}}*)base_ptr;
}
namespace hako::pdu::msgs::{{container.pkg_name}}
{
class {{container.msg_type_name}}
{
public:
    {{container.msg_type_name}}() = default;
    ~{{container.msg_type_name}}() = default;

    bool pdu2cpp(char* top_ptr, HakoCpp_{{container.msg_type_name}}& cppData)
    {
        char* base_ptr = (char*)hako_get_base_ptr_pdu((void*)top_ptr);
        if (base_ptr == nullptr) {
            std::cerr << "[ConvertorError][" << "{{container.msg_type_name}}" << "] hako_get_base_ptr_pdu returned null" << std::endl;
            return false;
        } 
        int ret = hako_convert_pdu2cpp_{{container.msg_type_name}}(*(Hako_{{container.msg_type_name}}*)base_ptr, cppData);
        if (ret != 0) {
            std::cerr << "[ConvertorError][" << "{{container.msg_type_name}}" << "] hako_convert_pdu2cpp returned " << ret << std::endl;
            return false;
        }
        return true;
    }

    int cpp2pdu(HakoCpp_{{container.msg_type_name}}& cppData, char* pdu_buffer, int buffer_len)
    {
        char* base_ptr = nullptr;
        int pdu_size = hako_convert_cpp2pdu_{{container.msg_type_name}}(cppData, (Hako_{{container.msg_type_name}}**)&base_ptr);
        if (pdu_size < 0) {
            std::cerr << "[ConvertorError][" << "{{container.msg_type_name}}" << "] hako_convert_cpp2pdu returned error code: " << pdu_size << std::endl;
            return -1;
        }
        if (pdu_size > buffer_len) {
            std::cerr << "[ConvertorError][" << "{{container.msg_type_name}}" << "] buffer too small. pdu_size=" << pdu_size << " buffer_len=" << buffer_len << std::endl;
            return -1;
        }
        void* top_ptr = hako_get_top_ptr_pdu((void*)base_ptr);
        if (top_ptr == nullptr) {
            std::cerr << "[ConvertorError][" << "{{container.msg_type_name}}" << "] hako_get_top_ptr_pdu returned null" << std::endl;
            return false;
        }
        memcpy(pdu_buffer, top_ptr, pdu_size);
        hako_destroy_pdu((void*)base_ptr);
        return pdu_size;
    }

private:
};
}


#endif /* _PDU_CPPTYPE_CONV_HAKO_{{container.pkg_name}}_{{container.msg_type_name}}_HPP_ */
