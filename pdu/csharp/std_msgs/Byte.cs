using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using hakoniwa.pdu.interfaces;

namespace hakoniwa.pdu.msgs.std_msgs
{
    public class Byte
    {
        protected internal readonly IPdu _pdu;
        public IPdu GetPdu() { return _pdu; }

        public Byte(IPdu pdu)
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
