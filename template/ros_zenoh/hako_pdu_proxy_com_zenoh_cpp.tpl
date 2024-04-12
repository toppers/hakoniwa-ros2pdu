#include "../com_ros2/ros2/hako_ros_proxy_com_ros2_pub.hpp"
#include "../com_zenoh/hako_ros_proxy_com_zenoh_sub.hpp"

{%- for robo in container.json_data["robots"]: %}
{%-     for item in robo["rpc_pdu_writers"]: %}
#include "{{container.get_pkg(item)}}/pdu_ctype_conv_{{container.get_type(item)}}.hpp"
{%-     endfor %}
{%-     for item in robo["shm_pdu_writers"]: %}
#include "{{container.get_pkg(item)}}/pdu_ctype_conv_{{container.get_type(item)}}.hpp"
{%-     endfor %}
{%- endfor %}

/*
 * ZenohSide:
 */
{%- for robo in container.json_data["robots"]: %}
{%-     for item in robo["rpc_pdu_writers"]: %}
ROS_PROXY_DECLARE_PUBLISHER({{container.get_pkg(item)}}::msg::{{container.get_type(item)}}, {{container.get_topic_name(item)}});
ZENOH_DECLARE_SUBSCRIBER({{container.get_topic_name(item)}});
ZENOH_DEFINE_SUB_CALLBACK({{container.get_pkg(item)}}, {{container.get_type(item)}}, {{container.get_topic_name(item)}})
{%-     endfor %}
{%-     for item in robo["shm_pdu_writers"]: %}
ROS_PROXY_DECLARE_PUBLISHER({{container.get_pkg(item)}}::msg::{{container.get_type(item)}}, {{container.get_topic_name(item)}});
ZENOH_DECLARE_SUBSCRIBER({{container.get_topic_name(item)}});
ZENOH_DEFINE_SUB_CALLBACK({{container.get_pkg(item)}}, {{container.get_type(item)}}, {{container.get_topic_name(item)}})
{%-     endfor %}
{%- endfor %}

void hako_ros_proxy_com_zenoh_init(ROS_NODE_TYPE node)
{
{%- for robo in container.json_data["robots"]: %}
{%-     for item in robo["rpc_pdu_writers"]: %}
    ROS_PROXY_CREATE_PUBLISHER(node, {{container.get_pkg(item)}}, {{container.get_type(item)}}, {{container.get_topic_name(item)}});
    ZENOH_CREATE_SUBSCRIBER({{container.get_topic_name(item)}});
{%-     endfor %}
{%-     for item in robo["shm_pdu_writers"]: %}
    ROS_PROXY_CREATE_PUBLISHER(node, {{container.get_pkg(item)}}, {{container.get_type(item)}}, {{container.get_topic_name(item)}});
    ZENOH_CREATE_SUBSCRIBER({{container.get_topic_name(item)}});
{%-     endfor %}
{%- endfor %}
    return;
}
