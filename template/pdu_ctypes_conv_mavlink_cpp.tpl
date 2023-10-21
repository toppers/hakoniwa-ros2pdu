#ifndef _PDU_CTYPE_CONV_HAKO_MAVLINK_{{container.pkg_name}}_{{container.msg_type_name}}_HPP_
#define _PDU_CTYPE_CONV_HAKO_MAVLINK_{{container.pkg_name}}_{{container.msg_type_name}}_HPP_

#include "pdu_primitive_ctypes.h"
#include "ros_primitive_types.hpp"
#include "pdu_primitive_ctypes_conv.hpp"
/*
 * Dependent pdu data
 */
#include "{{container.pkg_name}}/pdu_ctype_{{container.msg_type_name}}.h"
/*
 * Dependent mavlink data
 */
#include "mavlink.h"


/***************************
 *
 * PDU ==> MAVLINK
 *
 ***************************/
static inline int hako_convert_pdu2mavlink_{{container.msg_type_name}}(Hako_{{container.msg_type_name}} &src,  mavlink_{{container.convert_snake(container.msg_type_name).replace('hako_', '')}}_t &dst)
{
{%- for item in container.json_data["fields"]: -%}
{%-	    if (container.is_primitive(item["type"])): %}
    //primitive convert
    dst.{{item["name"]}} = src.{{item["name"]}};
{%-	    elif (container.is_primitive_array(item["type"])): %}
    //primitive array convertor
    for (int i = 0; i < (int)M_ARRAY_SIZE(Hako_{{container.msg_type_name}}, Hako_{{container.get_array_type(item["type"])}}, {{item["name"]}}); i++) {
        dst.{{item["name"]}}[i] = src.{{item["name"]}}[i];
    }
{%-	    else: %}
    //ERROR: not supported types..
{%-         endif %}
{%- endfor %}
    return 0;
}

/***************************
 *
 * MAVLINK ==> PDU
 *
 ***************************/
static inline int hako_convert_mavlink2pdu_{{container.msg_type_name}}(mavlink_{{container.convert_snake(container.msg_type_name).replace('hako_', '')}}_t &src, Hako_{{container.msg_type_name}} &dst)
{
{%- for item in container.json_data["fields"]: -%}
{%-	    if (container.is_primitive(item["type"])): %}
    //primitive convert
    dst.{{item["name"]}} = src.{{item["name"]}};
{%-	    elif (container.is_primitive_array(item["type"])): %}
    //primitive array convertor
    for (int i = 0; i < (int)M_ARRAY_SIZE(Hako_{{container.msg_type_name}}, Hako_{{container.get_array_type(item["type"])}}, {{item["name"]}}); i++) {
        dst.{{item["name"]}}[i] = src.{{item["name"]}}[i];
    }
{%-	    else: %}
    //ERROR: not supported types..
{%-         endif %}
{%- endfor %}
    return 0;
}


#endif /* _PDU_CTYPE_CONV_HAKO_MAVLINK_{{container.pkg_name}}_{{container.msg_type_name}}_HPP_ */