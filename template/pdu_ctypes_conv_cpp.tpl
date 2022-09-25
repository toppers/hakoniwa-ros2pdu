//TODO includes

void hako_convert_pdu2ros_{{container.msg_type_name}}(Hako_{{container.msg_type_name}} &src,  {{container.pkg_name}}::msg::{{container.msg_type_name}} &dst)
{
{%- for item in container.json_data["fields"]: -%}
{%-	    if (container.is_primitive(item["type"])): %}
        //primitive convert
        hako_convert_pdu2ros(src, dst);
{%-	    elif (container.is_string(item["type"])): %}
        //TODO string convertor
{%-	    elif (container.is_primitive_array(item["type"])): %}
        //TODO primitive array convertor
{%-	    elif (container.is_array(item["type"])): %}
        //TODO struct array convertor
{%-	    else: %}
        //struct convert
        hako_convert_pdu2ros_{{container.get_msg_type(item["type"])}}(
                Hako_{{container.get_msg_type(item["type"])}} src.{{item["name"]}},
                {{container.get_msg_pkg(item["type"])}}::msg::{{container.get_msg_type(item["type"])}} dst.{{item["name"]}});
{%-         endif %}
{%- endfor %}
        return;
}
