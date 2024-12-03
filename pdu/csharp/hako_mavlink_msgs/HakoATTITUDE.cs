using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using hakoniwa.pdu.interfaces;

namespace hakoniwa.pdu.msgs.hako_mavlink_msgs
{
    public class HakoATTITUDE
    {
        protected internal readonly IPdu _pdu;

        public HakoATTITUDE(IPdu pdu)
        {
            _pdu = pdu;
        }
        public uint time_boot_ms
        {
            get => _pdu.GetData<uint>("time_boot_ms");
            set => _pdu.SetData("time_boot_ms", value);
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
        public float rollspeed
        {
            get => _pdu.GetData<float>("rollspeed");
            set => _pdu.SetData("rollspeed", value);
        }
        public float pitchspeed
        {
            get => _pdu.GetData<float>("pitchspeed");
            set => _pdu.SetData("pitchspeed", value);
        }
        public float yawspeed
        {
            get => _pdu.GetData<float>("yawspeed");
            set => _pdu.SetData("yawspeed", value);
        }
    }
}
