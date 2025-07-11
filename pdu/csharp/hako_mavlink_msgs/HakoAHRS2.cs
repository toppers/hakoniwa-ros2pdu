using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using hakoniwa.pdu.interfaces;

namespace hakoniwa.pdu.msgs.hako_mavlink_msgs
{
    public class HakoAHRS2
    {
        protected internal readonly IPdu _pdu;
        public IPdu GetPdu() { return _pdu; }

        public HakoAHRS2(IPdu pdu)
        {
            _pdu = pdu;
        }
        public float roll
        {
            get => _pdu.GetData<float>("roll");
            set => _pdu.SetData("roll", value);
        }
        public float pitch
        {
            get => _pdu.GetData<float>("pitch");
            set => _pdu.SetData("pitch", value);
        }
        public float yaw
        {
            get => _pdu.GetData<float>("yaw");
            set => _pdu.SetData("yaw", value);
        }
        public float altitude
        {
            get => _pdu.GetData<float>("altitude");
            set => _pdu.SetData("altitude", value);
        }
        public int lat
        {
            get => _pdu.GetData<int>("lat");
            set => _pdu.SetData("lat", value);
        }
        public int lng
        {
            get => _pdu.GetData<int>("lng");
            set => _pdu.SetData("lng", value);
        }
    }
}
