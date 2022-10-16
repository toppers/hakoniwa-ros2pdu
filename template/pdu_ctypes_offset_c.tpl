#include "pdu_primitive_ctypes.h"
{%- for item in container.includes: %}
#include "{{item}}"
{%- endfor %}

#include "{{container.pkg_name}}/pdu_ctype_{{container.msg_type_name}}.h"
#include <stddef.h>
#include <stdio.h>

static void hako_pdu_offset_{{container.msg_type_name}}(void)
{
{%- for item in container.json_data["fields"]: %}
        //{{item["name"]}}
{%-	    if (container.is_primitive(item["type"])): %}
        printf("single:");
        printf("primitive:");
        printf("{{item["name"]}}:");
        printf("{{item["type"]}}:");
        printf("%ld", offsetof(Hako_{{container.msg_type_name}}, {{item["name"]}}));
{%-	    elif (container.is_string(item["type"])): %}
        printf("single:");
        printf("primitive:");
        printf("{{item["name"]}}:");
        printf("string:");
        printf("%ld", offsetof(Hako_{{container.msg_type_name}}, {{item["name"]}}));
{%-	    elif (container.is_primitive_array(item["type"])): %}
        printf("array:");
        printf("primitive:");
        printf("{{item["name"]}}:");
        printf("{{container.get_msg_type(container.get_array_type(item["type"]))}}:");
        printf("%ld:", offsetof(Hako_{{container.msg_type_name}}, {{item["name"]}}));
        printf("{{container.get_array_size(item["name"], item["type"])}}");
{%-	    elif (container.is_array(item["type"])): %}
        printf("array:");
        printf("struct:");
        printf("{{item["name"]}}:");
        printf("{{container.get_msg_type(container.get_array_type(item["type"]))}}:");
        printf("%ld:", offsetof(Hako_{{container.msg_type_name}}, {{item["name"]}}));
        printf("{{container.get_array_size(item["name"], item["type"])}}");
{%-	    else: %}
        printf("single:");
        printf("struct:");
        printf("{{item["name"]}}:");
        printf("{{item["type"]}}:");
        printf("%ld", offsetof(Hako_{{container.msg_type_name}}, {{item["name"]}}));
{%-		endif %}
        printf("\n");
{%- endfor %}
}

int main(int argc, const char* argv[])
{
        hako_pdu_offset_{{container.msg_type_name}}();
        return 0;
}
