using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using hakoniwa.pdu.interfaces;

namespace hakoniwa.pdu.msgs.std_msgs
{
    public class ColorRGBA
    {
        protected internal readonly IPdu _pdu;
        public IPdu GetPdu() { return _pdu; }

        public ColorRGBA(IPdu pdu)
        {
            _pdu = pdu;
        }
        public float r
        {
            get => _pdu.GetData<float>("r");
            set => _pdu.SetData("r", value);
        }
        public float g
        {
            get => _pdu.GetData<float>("g");
            set => _pdu.SetData("g", value);
        }
        public float b
        {
            get => _pdu.GetData<float>("b");
            set => _pdu.SetData("b", value);
        }
        public float a
        {
            get => _pdu.GetData<float>("a");
            set => _pdu.SetData("a", value);
        }
    }
}
