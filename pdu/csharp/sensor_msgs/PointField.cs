using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using hakoniwa.pdu.interfaces;

namespace hakoniwa.pdu.msgs.sensor_msgs
{
    public class PointField
    {
        protected internal readonly IPdu _pdu;

        public PointField(IPdu pdu)
        {
            _pdu = pdu;
        }
        public string name
        {
            get => _pdu.GetData<string>("name");
            set => _pdu.SetData("name", value);
        }
        public uint offset
        {
            get => _pdu.GetData<uint>("offset");
            set => _pdu.SetData("offset", value);
        }
        public byte datatype
        {
            get => _pdu.GetData<byte>("datatype");
            set => _pdu.SetData("datatype", value);
        }
        public uint count
        {
            get => _pdu.GetData<uint>("count");
            set => _pdu.SetData("count", value);
        }
    }
}
