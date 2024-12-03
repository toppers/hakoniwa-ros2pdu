using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using hakoniwa.pdu.interfaces;

namespace hakoniwa.pdu.msgs.std_msgs
{
    public class MultiArrayDimension
    {
        protected internal readonly IPdu _pdu;

        public MultiArrayDimension(IPdu pdu)
        {
            _pdu = pdu;
        }
        public string label
        {
            get => _pdu.GetData<string>("label");
            set => _pdu.SetData("label", value);
        }
        public uint size
        {
            get => _pdu.GetData<uint>("size");
            set => _pdu.SetData("size", value);
        }
        public uint stride
        {
            get => _pdu.GetData<uint>("stride");
            set => _pdu.SetData("stride", value);
        }
    }
}
