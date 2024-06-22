#include "pdu_primitive_ctypes.h"
{%- for item in container.includes %}
#include "{{item}}"
{%- endfor %}

#include "{{container.pkg_name}}/pdu_ctype_{{container.msg_type_name}}.h"
#include <stddef.h>
#include <stdio.h>

static void hako_pdu_offset_{{container.msg_type_name}}(void)
{
{%- for item in container.json_data["fields"] %}
        //{{item["name"]}}
{%-     if container.is_primitive(item["type"]) %}
        printf("single:primitive:{{item["name"]}}:{{item["type"]}}:%ld:%ld\n", offsetof(Hako_{{container.msg_type_name}}, {{item["name"]}}), sizeof(((Hako_{{container.msg_type_name}} *)0)->{{item["name"]}}));
{%-     elif container.is_string(item["type"]) %}
        printf("single:primitive:{{item["name"]}}:string:%ld:%ld\n", offsetof(Hako_{{container.msg_type_name}}, {{item["name"]}}), sizeof(((Hako_{{container.msg_type_name}} *)0)->{{item["name"]}}));
{%-     elif container.is_primitive_array(item["type"]) %}
{%-         set array_size = container.get_array_size(item["name"], item["type"]) %}
{%-         if array_size is none %}
        //printf("varray:primitive:_{{item["name"]}}_len:int32:%ld:%ld\n", offsetof(Hako_{{container.msg_type_name}}, _{{item["name"]}}_len), sizeof(int));
        //printf("single:primitive:_{{item["name"]}}_off:int32:%ld:%ld\n", offsetof(Hako_{{container.msg_type_name}}, _{{item["name"]}}_off), sizeof(int));
        printf("varray:primitive:{{item["name"]}}:{{container.get_msg_type(container.get_array_type(item["type"]))}}:%ld:%ld:%d\n", offsetof(Hako_{{container.msg_type_name}}, _{{item["name"]}}_len), sizeof(Hako_{{container.get_msg_type(container.get_struct_array_type(item["type"]))}}), 8);
{%-         else %}
        printf("array:primitive:{{item["name"]}}:{{container.get_msg_type(container.get_array_type(item["type"]))}}:%ld:%ld:%d\n", offsetof(Hako_{{container.msg_type_name}}, {{item["name"]}}), sizeof(((Hako_{{container.msg_type_name}} *)0)->{{item["name"]}}), {{array_size}});
{%-         endif %}
{%-     elif container.is_string_array(item["type"]) %}
{%-         set array_size = container.get_array_size(item["name"], item["type"]) %}
{%-         if array_size is none %}
        //printf("single:primitive:_{{item["name"]}}_len:int32:%ld:%ld\n", offsetof(Hako_{{container.msg_type_name}}, _{{item["name"]}}_len), sizeof(int));
        //printf("single:primitive:_{{item["name"]}}_off:int32:%ld:%ld\n", offsetof(Hako_{{container.msg_type_name}}, _{{item["name"]}}_off), sizeof(int));
        printf("varray:primitive:{{item["name"]}}:{{container.get_msg_type(container.get_array_type(item["type"]))}}:%ld:%ld:%d\n", offsetof(Hako_{{container.msg_type_name}}, _{{item["name"]}}_len), sizeof(Hako_cstring), 8);
{%-         else %}
        printf("array:primitive:{{item["name"]}}:{{container.get_msg_type(container.get_array_type(item["type"]))}}:%ld:%ld:%d\n", offsetof(Hako_{{container.msg_type_name}}, {{item["name"]}}), sizeof(((Hako_{{container.msg_type_name}} *)0)->{{item["name"]}}), {{array_size}});
{%-         endif %}
{%-     elif container.is_array(item["type"]) %}
{%-         set array_size = container.get_array_size(item["name"], item["type"]) %}
{%-         if array_size is none %}
        //printf("single:struct:_{{item["name"]}}_len:int32:%ld:%ld\n", offsetof(Hako_{{container.msg_type_name}}, _{{item["name"]}}_len), sizeof(int));
        //printf("single:struct:_{{item["name"]}}_off:int32:%ld:%ld\n", offsetof(Hako_{{container.msg_type_name}}, _{{item["name"]}}_off), sizeof(int));
        printf("varray:struct:{{item["name"]}}:{{container.get_type(container.get_struct_array_type(item["type"]))}}:%ld:%ld:%d\n", offsetof(Hako_{{container.msg_type_name}}, _{{item["name"]}}_len), sizeof(Hako_{{container.get_msg_type(container.get_struct_array_type(item["type"]))}}), 8);
{%-         else %}
        printf("array:struct:{{item["name"]}}:{{container.get_type(container.get_struct_array_type(item["type"]))}}:%ld:%ld:%d\n", offsetof(Hako_{{container.msg_type_name}}, {{item["name"]}}), sizeof(((Hako_{{container.msg_type_name}} *)0)->{{item["name"]}}), {{array_size}});
{%-         endif %}
{%-     else %}
        printf("single:struct:{{item["name"]}}:{{item["type"]}}:%ld:%ld\n", offsetof(Hako_{{container.msg_type_name}}, {{item["name"]}}), sizeof(((Hako_{{container.msg_type_name}} *)0)->{{item["name"]}}));
{%-     endif %}
{%- endfor %}
}

int main(int argc, const char* argv[])
{
    hako_pdu_offset_{{container.msg_type_name}}();
    return 0;
}
