using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using hakoniwa.pdu.interfaces;

namespace hakoniwa.pdu.msgs.std_msgs
{
    public class UInt64
    {
        protected internal readonly IPdu _pdu;

        public UInt64(IPdu pdu)
        {
            _pdu = pdu;
        }
        public ulong data
        {
            get => _pdu.GetData<ulong>("data");
            set => _pdu.SetData("data", value);
        }
    }
}
