using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using hakoniwa.pdu.interfaces;

namespace hakoniwa.pdu.msgs.std_msgs
{
    public class Int32
    {
        protected internal readonly IPdu _pdu;
        public IPdu GetPdu() { return _pdu; }

        public Int32(IPdu pdu)
        {
            _pdu = pdu;
        }
        public int data
        {
            get => _pdu.GetData<int>("data");
            set => _pdu.SetData("data", value);
        }
    }
}
