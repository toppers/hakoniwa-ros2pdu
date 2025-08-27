using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using hakoniwa.pdu.interfaces;

namespace hakoniwa.pdu.msgs.drone_srv_msgs
{
    public class CameraCaptureImageRequest
    {
        protected internal readonly IPdu _pdu;
        public IPdu GetPdu() { return _pdu; }

        public CameraCaptureImageRequest(IPdu pdu)
        {
            _pdu = pdu;
        }
        public string drone_name
        {
            get => _pdu.GetData<string>("drone_name");
            set => _pdu.SetData("drone_name", value);
        }
        public string image_type
        {
            get => _pdu.GetData<string>("image_type");
            set => _pdu.SetData("image_type", value);
        }
    }
}
