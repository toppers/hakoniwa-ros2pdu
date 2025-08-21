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
        public string service_name
        {
            get => _pdu.GetData<string>("service_name");
            set => _pdu.SetData("service_name", value);
        }
        public string client_name
        {
            get => _pdu.GetData<string>("client_name");
            set => _pdu.SetData("client_name", value);
        }
    }
}
