using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using hakoniwa.pdu.interfaces;

namespace hakoniwa.pdu.msgs.hako_srv_msgs
{
    public class ServiceRequestHeader
    {
        protected internal readonly IPdu _pdu;

        public ServiceRequestHeader(IPdu pdu)
        {
            _pdu = pdu;
        }
        public uint request_id
        {
            get => _pdu.GetData<uint>("request_id");
            set => _pdu.SetData("request_id", value);
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
        public byte opcode
        {
            get => _pdu.GetData<byte>("opcode");
            set => _pdu.SetData("opcode", value);
        }
        public int status_poll_interval_msec
        {
            get => _pdu.GetData<int>("status_poll_interval_msec");
            set => _pdu.SetData("status_poll_interval_msec", value);
        }
    }
}
