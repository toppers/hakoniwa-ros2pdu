using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using hakoniwa.pdu.interfaces;

namespace hakoniwa.pdu.msgs.std_msgs
{
    public class UInt8
    {
        protected internal readonly IPdu _pdu;

        public UInt8(IPdu pdu)
        {
            _pdu = pdu;
        }
        public byte data
        {
            get => _pdu.GetData<byte>("data");
            set => _pdu.SetData("data", value);
        }
    }
}
