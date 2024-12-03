using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using hakoniwa.pdu.interfaces;

namespace hakoniwa.pdu.msgs.can_msgs
{
    public class HakoCanBody
    {
        protected internal readonly IPdu _pdu;

        public HakoCanBody(IPdu pdu)
        {
            _pdu = pdu;
        }
        public byte[] data
        {
            get => _pdu.GetDataArray<byte>("data");
            set => _pdu.SetData("data", value);
        }
    }
}
