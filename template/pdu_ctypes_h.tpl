#ifndef _pdu_ctype_{{container.pkg_name}}_{{container.msg_type_name}}_H_
#define _pdu_ctype_{{container.pkg_name}}_{{container.msg_type_name}}_H_

#include "pdu_primitive_ctypes.h"
{%- for item in container.includes %}
#include "{{item}}"
{%- endfor %}

typedef struct {
{%- for item in container.json_data["fields"] %}
{%-     if container.is_primitive(item["type"]) %}
        Hako_{{container.get_msg_type(item["type"])}} {{item["name"]}};
{%-     elif container.is_string(item["type"]) %}
        char {{item["name"]}}[HAKO_STRING_SIZE];
{%-     elif container.is_primitive_array(item["type"]) %}
{%-         set array_size = container.get_array_size(item["name"], item["type"]) %}
{%-         if array_size is none %}
        // {{container.get_array_type(item["type"])}} {{item["name"]}}[]
        int _{{item["name"]}}_len;
        int _{{item["name"]}}_off;
{%-         else %}
        Hako_{{container.get_msg_type(container.get_array_type(item["type"]))}} {{item["name"]}}[{{array_size}}];
{%-         endif %}
{%-     elif container.is_string_array(item["type"]) %}
{%-         set array_size = container.get_array_size(item["name"], item["type"]) %}
{%-         if array_size is none %}
        // {{container.get_array_type(item["type"])}} {{item["name"]}}[]
        int _{{item["name"]}}_len;
        int _{{item["name"]}}_off;
{%-         else %}
        Hako_cstring {{item["name"]}}[{{array_size}}];
{%-         endif %}
{%-     elif container.is_array(item["type"]) %}
{%-         set array_size = container.get_array_size(item["name"], item["type"]) %}
{%-         if array_size is none %}
        // {{container.get_array_type(item["type"])}} {{item["name"]}}[]
        int _{{item["name"]}}_len;
        int _{{item["name"]}}_off;
{%-         else %}
        Hako_{{container.get_msg_type(container.get_array_type(item["type"]))}} {{item["name"]}}[{{array_size}}];
{%-         endif %}
{%-     else %}
        Hako_{{container.get_msg_type(item["type"])}} {{item["name"]}};
{%-     endif %}
{%- endfor %}
} Hako_{{container.msg_type_name}};

#endif /* _pdu_ctype_{{container.pkg_name}}_{{container.msg_type_name}}_H_ */
