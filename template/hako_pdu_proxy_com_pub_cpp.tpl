#include "../hako_pdu_proxy_com.hpp"
#include "../hako_pdu_proxy_libs.hpp"

{%- for robo in container.json_data["robots"]: %}
{%-     for item in robo["rpc_pdu_writers"]: %}
#include "{{container.get_pkg(item)}}/pdu_ctype_conv_{{container.get_type(item)}}.hpp"
{%-     endfor %}
{%-     for item in robo["shm_pdu_writers"]: %}
#include "{{container.get_pkg(item)}}/pdu_ctype_conv_{{container.get_type(item)}}.hpp"
{%-     endfor %}
{%- endfor %}

static ROS_NODE_TYPE my_node;

{%- for robo in container.json_data["robots"]: %}
{%-     for item in robo["rpc_pdu_writers"]: %}
DECLARE_PUBLISHER({{container.get_pkg(item)}}::msg::{{container.get_type(item)}}, {{container.get_topic_name(item)}});
{%-     endfor %}
{%-     for item in robo["shm_pdu_writers"]: %}
DECLARE_PUBLISHER({{container.get_pkg(item)}}::msg::{{container.get_type(item)}}, {{container.get_topic_name(item)}});
{%-     endfor %}
{%- endfor %}

void hako_pdu_proxy_com_pub_init(ROS_NODE_TYPE node)
{
    my_node = node;

{%- for robo in container.json_data["robots"]: %}
{%-     for item in robo["rpc_pdu_writers"]: %}
    CREATE_PUBLISHER({{container.get_pkg(item)}}, {{container.get_type(item)}}, "{{robo["name"]}}", {{container.get_channel(item)}}, {{container.get_topic_name(item)}});
{%-     endfor %}
{%-     for item in robo["shm_pdu_writers"]: %}
    CREATE_PUBLISHER({{container.get_pkg(item)}}, {{container.get_type(item)}}, "{{robo["name"]}}", {{container.get_channel(item)}}, {{container.get_topic_name(item)}});
{%-     endfor %}
{%- endfor %}

    return;
}

void hako_pdu_proxy_com_publish(void)
{
    static unsigned long long count = 0;
{%- for robo in container.json_data["robots"]: %}
{%-     for item in robo["rpc_pdu_writers"]: %}
    PUBLISH_PDU_TOPIC({{container.get_pkg(item)}}, {{container.get_type(item)}}, "{{robo["name"]}}", {{container.get_channel(item)}}, {{container.get_topic_name(item)}}, count, {{item["write_cycle"]}});
{%-     endfor %}
{%-     for item in robo["shm_pdu_writers"]: %}
    PUBLISH_PDU_TOPIC({{container.get_pkg(item)}}, {{container.get_type(item)}}, "{{robo["name"]}}", {{container.get_channel(item)}}, {{container.get_topic_name(item)}}, count, {{item["write_cycle"]}});
{%-     endfor %}
{%- endfor %}
    count++;
    return;
}
