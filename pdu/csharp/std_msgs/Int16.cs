using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using hakoniwa.pdu.interfaces;

namespace hakoniwa.pdu.msgs.std_msgs
{
    public class Int16
    {
        protected internal readonly IPdu _pdu;
        public IPdu GetPdu() { return _pdu; }

        public Int16(IPdu pdu)
        {
            _pdu = pdu;
        }
        public short data
        {
            get => _pdu.GetData<short>("data");
            set => _pdu.SetData("data", value);
        }
    }
}
