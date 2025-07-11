using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using hakoniwa.pdu.interfaces;

namespace hakoniwa.pdu.msgs.hako_srv_msgs
{
    public class ServiceResponseHeader
    {
        protected internal readonly IPdu _pdu;
        public IPdu GetPdu() { return _pdu; }

        public ServiceResponseHeader(IPdu pdu)
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
        public byte status
        {
            get => _pdu.GetData<byte>("status");
            set => _pdu.SetData("status", value);
        }
        public byte processing_percentage
        {
            get => _pdu.GetData<byte>("processing_percentage");
            set => _pdu.SetData("processing_percentage", value);
        }
        public int result_code
        {
            get => _pdu.GetData<int>("result_code");
            set => _pdu.SetData("result_code", value);
        }
    }
}
