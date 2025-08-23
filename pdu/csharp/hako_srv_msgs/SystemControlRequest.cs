using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using hakoniwa.pdu.interfaces;

namespace hakoniwa.pdu.msgs.hako_srv_msgs
{
    public class SystemControlRequest
    {
        protected internal readonly IPdu _pdu;
        public IPdu GetPdu() { return _pdu; }

        public SystemControlRequest(IPdu pdu)
        {
            _pdu = pdu;
        }
        public uint opcode
        {
            get => _pdu.GetData<uint>("opcode");
            set => _pdu.SetData("opcode", value);
        }
    }
}
