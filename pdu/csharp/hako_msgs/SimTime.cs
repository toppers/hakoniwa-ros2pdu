using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using hakoniwa.pdu.interfaces;

namespace hakoniwa.pdu.msgs.hako_msgs
{
    public class SimTime
    {
        protected internal readonly IPdu _pdu;

        public SimTime(IPdu pdu)
        {
            _pdu = pdu;
        }
        public ulong time_usec
        {
            get => _pdu.GetData<ulong>("time_usec");
            set => _pdu.SetData("time_usec", value);
        }
    }
}
