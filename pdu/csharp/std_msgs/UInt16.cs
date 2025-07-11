using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using hakoniwa.pdu.interfaces;

namespace hakoniwa.pdu.msgs.std_msgs
{
    public class UInt16
    {
        protected internal readonly IPdu _pdu;
        public IPdu GetPdu() { return _pdu; }

        public UInt16(IPdu pdu)
        {
            _pdu = pdu;
        }
        public ushort data
        {
            get => _pdu.GetData<ushort>("data");
            set => _pdu.SetData("data", value);
        }
    }
}
