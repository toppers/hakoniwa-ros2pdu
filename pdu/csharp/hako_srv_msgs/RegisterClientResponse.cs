using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using hakoniwa.pdu.interfaces;

namespace hakoniwa.pdu.msgs.hako_srv_msgs
{
    public class RegisterClientResponse
    {
        protected internal readonly IPdu _pdu;
        public IPdu GetPdu() { return _pdu; }

        public RegisterClientResponse(IPdu pdu)
        {
            _pdu = pdu;
        }
        public uint service_id
        {
            get => _pdu.GetData<uint>("service_id");
            set => _pdu.SetData("service_id", value);
        }
        public uint client_id
        {
            get => _pdu.GetData<uint>("client_id");
            set => _pdu.SetData("client_id", value);
        }
        public uint request_channel_id
        {
            get => _pdu.GetData<uint>("request_channel_id");
            set => _pdu.SetData("request_channel_id", value);
        }
        public uint response_channel_id
        {
            get => _pdu.GetData<uint>("response_channel_id");
            set => _pdu.SetData("response_channel_id", value);
        }
    }
}
