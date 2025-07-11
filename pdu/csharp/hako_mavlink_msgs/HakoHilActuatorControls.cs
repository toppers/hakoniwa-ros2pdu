using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using hakoniwa.pdu.interfaces;

namespace hakoniwa.pdu.msgs.hako_mavlink_msgs
{
    public class HakoHilActuatorControls
    {
        protected internal readonly IPdu _pdu;
        public IPdu GetPdu() { return _pdu; }

        public HakoHilActuatorControls(IPdu pdu)
        {
            _pdu = pdu;
        }
        public ulong time_usec
        {
            get => _pdu.GetData<ulong>("time_usec");
            set => _pdu.SetData("time_usec", value);
        }
        public float[] controls
        {
            get => _pdu.GetDataArray<float>("controls");
            set => _pdu.SetData("controls", value);
        }
        public byte mode
        {
            get => _pdu.GetData<byte>("mode");
            set => _pdu.SetData("mode", value);
        }
        public ulong flags
        {
            get => _pdu.GetData<ulong>("flags");
            set => _pdu.SetData("flags", value);
        }
    }
}
