using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using hakoniwa.pdu.interfaces;

namespace hakoniwa.pdu.msgs.hako_srv_msgs
{
    public class AddTwoIntsResponse
    {
        protected internal readonly IPdu _pdu;
        public IPdu GetPdu() { return _pdu; }

        public AddTwoIntsResponse(IPdu pdu)
        {
            _pdu = pdu;
        }
        public long sum
        {
            get => _pdu.GetData<long>("sum");
            set => _pdu.SetData("sum", value);
        }
    }
}
