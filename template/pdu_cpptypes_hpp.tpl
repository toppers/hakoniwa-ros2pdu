#ifndef _pdu_cpptype_{{container.pkg_name}}_{{container.msg_type_name}}_HPP_
#define _pdu_cpptype_{{container.pkg_name}}_{{container.msg_type_name}}_HPP_

#include "pdu_primitive_ctypes.h"
#include <vector>
#include <array>
{%- for item in container.cpp_includes %}
#include "{{item}}"
{%- endfor %}

typedef struct {
{%- for item in container.json_data["fields"] %}
{%-     if container.is_primitive(item["type"]) %}
        Hako_{{container.get_msg_type(item["type"])}} {{item["name"]}};
{%-     elif container.is_string(item["type"]) %}
        std::string {{item["name"]}};
{%-     elif container.is_primitive_array(item["type"]) %}
{%-         set array_size = container.get_array_size(item["name"], item["type"]) %}
{%-         if array_size is none %}
        std::vector<Hako_{{container.get_msg_type(container.get_array_type(item["type"]))}}> {{item["name"]}};
{%-         else %}
        std::array<Hako_{{container.get_msg_type(container.get_array_type(item["type"]))}}, {{array_size}}> {{item["name"]}};
{%-         endif %}
{%-     elif container.is_string_array(item["type"]) %}
{%-         set array_size = container.get_array_size(item["name"], item["type"]) %}
{%-         if array_size is none %}
        std::vector<std::string> {{item["name"]}};
{%-         else %}
        std::array<std::string, {{array_size}}> {{item["name"]}};
{%-         endif %}
{%-     elif container.is_array(item["type"]) %}
{%-         set array_size = container.get_array_size(item["name"], item["type"]) %}
{%-         if array_size is none %}
        std::vector<HakoCpp_{{container.get_msg_type(container.get_array_type(item["type"]))}}> {{item["name"]}};
{%-         else %}
        std::array<HakoCpp_{{container.get_msg_type(container.get_array_type(item["type"]))}}, {{array_size}}> {{item["name"]}};
{%-         endif %}
{%-     else %}
        HakoCpp_{{container.get_msg_type(item["type"])}} {{item["name"]}};
{%-     endif %}
{%- endfor %}
} HakoCpp_{{container.msg_type_name}};

#endif /* _pdu_cpptype_{{container.pkg_name}}_{{container.msg_type_name}}_HPP_ */
