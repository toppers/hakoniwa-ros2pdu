using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using hakoniwa.pdu.interfaces;

namespace hakoniwa.pdu.msgs.hako_srv_msgs
{
    public class RegisterClientRequest
    {
        protected internal readonly IPdu _pdu;
        public IPdu GetPdu() { return _pdu; }

        public RegisterClientRequest(IPdu pdu)
        {
            _pdu = pdu;
        }
        public uint dummy
        {
            get => _pdu.GetData<uint>("dummy");
            set => _pdu.SetData("dummy", value);
        }
    }
}
