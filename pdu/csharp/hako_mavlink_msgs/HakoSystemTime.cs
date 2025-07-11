using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using hakoniwa.pdu.interfaces;

namespace hakoniwa.pdu.msgs.hako_mavlink_msgs
{
    public class HakoSystemTime
    {
        protected internal readonly IPdu _pdu;
        public IPdu GetPdu() { return _pdu; }

        public HakoSystemTime(IPdu pdu)
        {
            _pdu = pdu;
        }
        public ulong time_unix_usec
        {
            get => _pdu.GetData<ulong>("time_unix_usec");
            set => _pdu.SetData("time_unix_usec", value);
        }
        public ulong time_boot_ms
        {
            get => _pdu.GetData<ulong>("time_boot_ms");
            set => _pdu.SetData("time_boot_ms", value);
        }
    }
}
