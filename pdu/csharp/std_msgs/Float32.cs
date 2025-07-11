using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using hakoniwa.pdu.interfaces;

namespace hakoniwa.pdu.msgs.std_msgs
{
    public class Float32
    {
        protected internal readonly IPdu _pdu;
        public IPdu GetPdu() { return _pdu; }

        public Float32(IPdu pdu)
        {
            _pdu = pdu;
        }
        public float data
        {
            get => _pdu.GetData<float>("data");
            set => _pdu.SetData("data", value);
        }
    }
}
