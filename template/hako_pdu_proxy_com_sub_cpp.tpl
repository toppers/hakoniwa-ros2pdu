#include "../hako_pdu_proxy_com.hpp"
#include "../hako_pdu_proxy_libs.hpp"

{%- for item in container.json_data["fields"]: %}
{%-     if container.is_sub(item): %}
#include "{{container.get_pkg(item)}}/pdu_ctype_conv_{{container.get_type(item)}}.hpp"
{%-     endif %}
{%- endfor %}

static std::shared_ptr<rclcpp::Node> my_node;

{%- for item in container.json_data["fields"]: %}
{%-     if container.is_sub(item): %}
DECLARE_SUBSCRIBER({{container.get_pkg(item)}}::msg::{{container.get_type(item)}}, {{item["topic_message_name"]}});
DEFINE_SUB_CALLBACK({{container.get_pkg(item)}}, {{container.get_type(item)}}, {{container.get_index(item)}}, {{item["topic_message_name"]}})
{%-     endif %}
{%- endfor %}

void hako_pdu_proxy_com_sub_init(std::shared_ptr<rclcpp::Node> node)
{
    my_node = node;
 
{%- for item in container.json_data["fields"]: %}
{%-     if container.is_sub(item): %}
    CREATE_SUBSCRIBER({{container.get_pkg(item)}}::msg::{{container.get_type(item)}}, {{item["topic_message_name"]}});
{%-     endif %}
{%- endfor %}

    return;
}

