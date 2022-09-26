#include "pdu_primitive_ctypes.h"
#include "ros_primitive_types.h"
#include "{{container.pkg_name}}/pdu_ctype_{{container.msg_type_name}}.h"
#include "{{container.pkg_name}}/msg/{{container.convert_snake(container.msg_type_name)}}.hpp"

void hako_convert_pdu2ros_{{container.msg_type_name}}(Hako_{{container.msg_type_name}} &src,  {{container.pkg_name}}::msg::{{container.msg_type_name}} &dst)
{
{%- for item in container.json_data["fields"]: -%}
{%-	    if (container.is_primitive(item["type"])): %}
        //primitive convert
        hako_convert_pdu2ros(src.{{item["name"]}}, dst.{{item["name"]}});
{%-	    elif (container.is_string(item["type"])): %}
        //TODO string convertor
{%-	    elif (container.is_primitive_array(item["type"])): %}
        //TODO primitive array convertor
{%-	    elif (container.is_array(item["type"])): %}
        //TODO struct array convertor
{%-	    else: %}
        //struct convert
        hako_convert_pdu2ros_{{container.get_msg_type(item["type"])}}(src.{{item["name"]}}, dst.{{item["name"]}});
{%-         endif %}
{%- endfor %}
        return;
}
