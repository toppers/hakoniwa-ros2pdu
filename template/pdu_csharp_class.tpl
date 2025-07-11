using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using hakoniwa.pdu.interfaces;

{%- for item in container.csharp_includes %}
using hakoniwa.pdu.msgs.{{item}};
{%- endfor %}

namespace hakoniwa.pdu.msgs.{{ container.pkg_name }}
{
    public class {{ container.msg_type_name }}
    {
        protected internal readonly IPdu _pdu;
        public IPdu GetPdu() { return _pdu; }

        public {{ container.msg_type_name }}(IPdu pdu)
        {
            _pdu = pdu;
        }
        {%- for item in container.json_data["fields"] %}
            {%- if container.is_primitive(item["type"]) %}
        public {{ container.get_csharp_type(item["type"]) }} {{ item["name"] }}
        {
            get => _pdu.GetData<{{ container.get_csharp_type(item["type"]) }}>("{{ item["name"] }}");
            set => _pdu.SetData("{{ item["name"] }}", value);
        }
            {%- elif container.is_string(item["type"]) %}
        public string {{ item["name"] }}
        {
            get => _pdu.GetData<string>("{{ item["name"] }}");
            set => _pdu.SetData("{{ item["name"] }}", value);
        }
            {%- elif container.is_string_array(item["type"]) %}
        public string[] {{ item["name"] }}
        {
            get => _pdu.GetDataArray<string>("{{ item["name"] }}");
            set => _pdu.SetData("{{ item["name"] }}", value);
        }
            {%- elif container.is_primitive_array(item["type"]) %}
        public {{ container.get_csharp_type(container.get_array_type(item["type"])) }}[] {{ item["name"] }}
        {
            get => _pdu.GetDataArray<{{ container.get_csharp_type(container.get_array_type(item["type"])) }}>("{{ item["name"] }}");
            set => _pdu.SetData("{{ item["name"] }}", value);
        }
            {%- elif container.is_array(item["type"]) %}
        private {{ container.get_msg_type(container.get_array_type(item["type"])) }}[] _{{ item["name"] }};
        public {{ container.get_msg_type(container.get_array_type(item["type"])) }}[] {{ item["name"] }}
        {
            get
            {
                if (_{{ item["name"] }} == null)
                {
                    var fieldPdus = _pdu.GetDataArray<IPdu>("{{ item["name"] }}");
                    _{{ item["name"] }} = new {{ container.get_msg_type(container.get_array_type(item["type"])) }}[fieldPdus.Length];
                    {{ container.get_msg_type(container.get_array_type(item["type"])) }}[] result = new {{ container.get_msg_type(container.get_array_type(item["type"])) }}[fieldPdus.Length];
                    for (int i = 0; i < fieldPdus.Length; i++)
                    {
                        _{{ item["name"] }}[i] = new {{ container.get_msg_type(container.get_array_type(item["type"])) }}(fieldPdus[i]);
                    }
                }
                return _{{ item["name"] }};
            }
            set
            {
                _{{ item["name"] }} = new {{ container.get_msg_type(container.get_array_type(item["type"])) }}[value.Length];
                IPdu[] fieldPdus = new IPdu[value.Length];
                for (int i = 0; i < value.Length; i++)
                {
                    fieldPdus[i] = value[i].GetPdu();
                    _{{ item["name"] }}[i] = value[i];
                }
                _pdu.SetData("{{ item["name"] }}", fieldPdus);
            }
        }
        {%- else %}
        private {{ container.get_msg_type(item["type"]) }} _{{ item["name"] }};
        public {{ container.get_msg_type(item["type"]) }} {{ item["name"] }}
        {
            get
            {
                if (_{{ item["name"] }} == null)
                {
                    _{{ item["name"] }} = new {{ container.get_msg_type(item["type"]) }}(_pdu.GetData<IPdu>("{{ item["name"] }}"));
                }
                return _{{ item["name"] }};
            }
            set
            {
                _{{ item["name"] }} = value;
                _pdu.SetData("{{ item["name"] }}", value.GetPdu());
            }
        }
            {%- endif %}
        {%- endfor %}
    }
}
