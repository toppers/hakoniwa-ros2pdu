using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using hakoniwa.pdu.interfaces;

namespace hakoniwa.pdu.msgs.drone_srv_msgs
{
    public class CameraSetTiltRequest
    {
        protected internal readonly IPdu _pdu;
        public IPdu GetPdu() { return _pdu; }

        public CameraSetTiltRequest(IPdu pdu)
        {
            _pdu = pdu;
        }
        public string drone_name
        {
            get => _pdu.GetData<string>("drone_name");
            set => _pdu.SetData("drone_name", value);
        }
        public float tilt_angle_deg
        {
            get => _pdu.GetData<float>("tilt_angle_deg");
            set => _pdu.SetData("tilt_angle_deg", value);
        }
    }
}
