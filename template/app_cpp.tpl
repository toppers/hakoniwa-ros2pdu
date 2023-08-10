{%- for robo in container.json_data["robots"]: %}
{%-     for item in robo["shm_pdu_writers"]: %}
mros2::Publisher pub = node.create_publisher<{{container.get_pkg(item)}}::msg::{{container.get_type(item)}}>("xxx", xx);
{%-     endfor %}
{%- endfor %}

{%- for robo in container.json_data["robots"]: %}
{%-     for item in robo["shm_pdu_readers"]: %}
mros2::Subscriber sub = node.create_subscription<{{container.get_pkg(item)}}::msg::{{container.get_type(item)}}>("xxx", xx, xxx);
{%-     endfor %}
{%- endfor %}
