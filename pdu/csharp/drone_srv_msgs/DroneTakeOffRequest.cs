using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using hakoniwa.pdu.interfaces;

namespace hakoniwa.pdu.msgs.drone_srv_msgs
{
    public class DroneTakeOffRequest
    {
        protected internal readonly IPdu _pdu;
        public IPdu GetPdu() { return _pdu; }

        public DroneTakeOffRequest(IPdu pdu)
        {
            _pdu = pdu;
        }
        public double alt_m
        {
            get => _pdu.GetData<double>("alt_m");
            set => _pdu.SetData("alt_m", value);
        }
        public string drone_name
        {
            get => _pdu.GetData<string>("drone_name");
            set => _pdu.SetData("drone_name", value);
        }
    }
}
