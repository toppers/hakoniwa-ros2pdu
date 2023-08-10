#include "../hako_pdu_proxy_com.hpp"
#include "../hako_pdu_proxy_libs.hpp"

{%- for robo in container.json_data["robots"]: %}
{%-     for item in robo["rpc_pdu_readers"]: %}
#include "{{container.get_pkg(item)}}/pdu_ctype_conv_{{container.get_type(item)}}.hpp"
{%-     endfor %}
{%-     for item in robo["shm_pdu_readers"]: %}
#include "{{container.get_pkg(item)}}/pdu_ctype_conv_{{container.get_type(item)}}.hpp"
{%-     endfor %}
{%- endfor %}

static ROS_NODE_TYPE my_node;

{%- for robo in container.json_data["robots"]: %}
{%-     for item in robo["rpc_pdu_readers"]: %}
DECLARE_SUBSCRIBER({{container.get_pkg(item)}}::msg::{{container.get_type(item)}}, {{container.get_topic_name(item)}});
DEFINE_SUB_CALLBACK({{container.get_pkg(item)}}, {{container.get_type(item)}}, "{{robo["name"]}}", {{container.get_channel(item)}}, {{container.get_topic_name(item)}})
{%-     endfor %}
{%-     for item in robo["shm_pdu_readers"]: %}
DECLARE_SUBSCRIBER({{container.get_pkg(item)}}::msg::{{container.get_type(item)}}, {{container.get_topic_name(item)}});
DEFINE_SUB_CALLBACK({{container.get_pkg(item)}}, {{container.get_type(item)}}, "{{robo["name"]}}", {{container.get_channel(item)}}, {{container.get_topic_name(item)}})
{%-     endfor %}
{%- endfor %}

void hako_pdu_proxy_com_sub_init(ROS_NODE_TYPE node)
{
    my_node = node;
 
{%- for robo in container.json_data["robots"]: %}
{%-     for item in robo["rpc_pdu_readers"]: %}
    CREATE_SUBSCRIBER({{container.get_pkg(item)}}, {{container.get_type(item)}}, "{{robo["name"]}}", {{container.get_channel(item)}}, {{container.get_topic_name(item)}});
{%-     endfor %}
{%-     for item in robo["shm_pdu_readers"]: %}
    CREATE_SUBSCRIBER({{container.get_pkg(item)}}, {{container.get_type(item)}}, "{{robo["name"]}}", {{container.get_channel(item)}}, {{container.get_topic_name(item)}});
{%-     endfor %}
{%- endfor %}

    return;
}

