using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using hakoniwa.pdu.interfaces;

namespace hakoniwa.pdu.msgs.builtin_interfaces
{
    public class Time
    {
        protected internal readonly IPdu _pdu;
        public IPdu GetPdu() { return _pdu; }

        public Time(IPdu pdu)
        {
            _pdu = pdu;
        }
        public int sec
        {
            get => _pdu.GetData<int>("sec");
            set => _pdu.SetData("sec", value);
        }
        public uint nanosec
        {
            get => _pdu.GetData<uint>("nanosec");
            set => _pdu.SetData("nanosec", value);
        }
    }
}
