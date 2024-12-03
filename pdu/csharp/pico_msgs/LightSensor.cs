using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using hakoniwa.pdu.interfaces;

namespace hakoniwa.pdu.msgs.pico_msgs
{
    public class LightSensor
    {
        protected internal readonly IPdu _pdu;

        public LightSensor(IPdu pdu)
        {
            _pdu = pdu;
        }
        public short forward_r
        {
            get => _pdu.GetData<short>("forward_r");
            set => _pdu.SetData("forward_r", value);
        }
        public short forward_l
        {
            get => _pdu.GetData<short>("forward_l");
            set => _pdu.SetData("forward_l", value);
        }
        public short left
        {
            get => _pdu.GetData<short>("left");
            set => _pdu.SetData("left", value);
        }
        public short right
        {
            get => _pdu.GetData<short>("right");
            set => _pdu.SetData("right", value);
        }
    }
}
