using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using hakoniwa.pdu.interfaces;

namespace hakoniwa.pdu.msgs.hako_srv_msgs
{
    public class SystemControlResponse
    {
        protected internal readonly IPdu _pdu;
        public IPdu GetPdu() { return _pdu; }

        public SystemControlResponse(IPdu pdu)
        {
            _pdu = pdu;
        }
        public uint status_code
        {
            get => _pdu.GetData<uint>("status_code");
            set => _pdu.SetData("status_code", value);
        }
        public string message
        {
            get => _pdu.GetData<string>("message");
            set => _pdu.SetData("message", value);
        }
    }
}
