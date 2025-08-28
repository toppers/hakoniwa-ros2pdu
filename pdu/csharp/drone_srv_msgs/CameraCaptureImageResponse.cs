using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using hakoniwa.pdu.interfaces;

namespace hakoniwa.pdu.msgs.drone_srv_msgs
{
    public class CameraCaptureImageResponse
    {
        protected internal readonly IPdu _pdu;
        public IPdu GetPdu() { return _pdu; }

        public CameraCaptureImageResponse(IPdu pdu)
        {
            _pdu = pdu;
        }
        public bool ok
        {
            get => _pdu.GetData<bool>("ok");
            set => _pdu.SetData("ok", value);
        }
        public byte[] data
        {
            get => _pdu.GetDataArray<byte>("data");
            set => _pdu.SetData("data", value);
        }
        public string message
        {
            get => _pdu.GetData<string>("message");
            set => _pdu.SetData("message", value);
        }
    }
}
