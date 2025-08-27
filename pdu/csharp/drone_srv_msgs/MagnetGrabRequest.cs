using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using hakoniwa.pdu.interfaces;

namespace hakoniwa.pdu.msgs.drone_srv_msgs
{
    public class MagnetGrabRequest
    {
        protected internal readonly IPdu _pdu;
        public IPdu GetPdu() { return _pdu; }

        public MagnetGrabRequest(IPdu pdu)
        {
            _pdu = pdu;
        }
        public string drone_name
        {
            get => _pdu.GetData<string>("drone_name");
            set => _pdu.SetData("drone_name", value);
        }
        public bool grab_on
        {
            get => _pdu.GetData<bool>("grab_on");
            set => _pdu.SetData("grab_on", value);
        }
        public float timeout_sec
        {
            get => _pdu.GetData<float>("timeout_sec");
            set => _pdu.SetData("timeout_sec", value);
        }
    }
}
