using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using hakoniwa.pdu.interfaces;

namespace hakoniwa.pdu.msgs.drone_srv_msgs
{
    public class DroneLandRequest
    {
        protected internal readonly IPdu _pdu;
        public IPdu GetPdu() { return _pdu; }

        public DroneLandRequest(IPdu pdu)
        {
            _pdu = pdu;
        }
        public string drone_name
        {
            get => _pdu.GetData<string>("drone_name");
            set => _pdu.SetData("drone_name", value);
        }
    }
}
