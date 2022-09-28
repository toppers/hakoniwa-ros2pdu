#include "pdu_primitive_ctypes.h"
#include "ros_primitive_types.h"
#include "{{container.pkg_name}}/pdu_ctype_{{container.msg_type_name}}.h"
#include "{{container.pkg_name}}/msg/{{container.convert_snake(container.msg_type_name)}}.hpp"

#define M_SIZE(type, mem)   sizeof(((type *)0)->mem)
#define M_ARRAY_SIZE(type, mem_type, mem)       (M_SIZE(type, mem) / sizeof(mem_type))


int hako_convert_pdu2ros_{{container.msg_type_name}}(Hako_{{container.msg_type_name}} &src,  {{container.pkg_name}}::msg::{{container.msg_type_name}} &dst)
{
{%- for item in container.json_data["fields"]: -%}
{%-	    if (container.is_primitive(item["type"])): %}
    //primitive convert
    hako_convert_pdu2ros(src.{{item["name"]}}, dst.{{item["name"]}});
{%-	    elif (container.is_string(item["type"])): %}
    //string convertor
    (void)hako_convert_pdu2ros_array(
        src.{{item["name"]}}, M_ARRAY_SIZE(Hako_{{container.msg_type_name}}, Hako_{{container.get_array_type(item["type"])}}, {{item["name"]}}),
        dst.{{item["name"]}}, dst.{{item["name"]}}.length());
{%-	    elif (container.is_primitive_array(item["type"])): %}
    //primitive array convertor
    (void)hako_convert_pdu2ros_array(
        src.{{item["name"]}}, M_ARRAY_SIZE(Hako_{{container.msg_type_name}}, Hako_{{container.get_array_type(item["type"])}}, {{item["name"]}}),
        dst.{{item["name"]}}, {{container.get_array_size(item["type"])}});
{%-	    elif (container.is_array(item["type"])): %}
    //struct array convertor
    (void)hako_convert_pdu2ros_{{container.get_array_type(item["type"])}}(
        src.{{item["name"]}}, M_ARRAY_SIZE(Hako_{{container.msg_type_name}}, Hako_{{container.get_array_type(item["type"])}}, {{item["name"]}}),
        dst.{{item["name"]}}, {{container.get_array_size(item["type"])}});
{%-	    else: %}
    //struct convert
    hako_convert_pdu2ros_{{container.get_msg_type(item["type"])}}(src.{{item["name"]}}, dst.{{item["name"]}});
{%-         endif %}
{%- endfor %}
    return 0;
}

int hako_convert_pdu2ros_array_{{container.msg_type_name}}(Hako_{{container.msg_type_name}} src[], int src_len, {{container.pkg_name}}::msg::{{container.msg_type_name}} dst[], int dst_len)
{
    int ret = 0;
    int len = dst_len;
    if (dst_len < src_len) {
        dst_len = src_len;
        ret = -1;
    }
    for (int i = 0; i < len; i++) {
        (void)hako_convert_pdu2ros_{{container.msg_type_name}}(src[i], dst[i]);
    }
    return ret;
}
