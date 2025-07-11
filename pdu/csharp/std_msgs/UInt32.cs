using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using hakoniwa.pdu.interfaces;

namespace hakoniwa.pdu.msgs.std_msgs
{
    public class UInt32
    {
        protected internal readonly IPdu _pdu;
        public IPdu GetPdu() { return _pdu; }

        public UInt32(IPdu pdu)
        {
            _pdu = pdu;
        }
        public uint data
        {
            get => _pdu.GetData<uint>("data");
            set => _pdu.SetData("data", value);
        }
    }
}
