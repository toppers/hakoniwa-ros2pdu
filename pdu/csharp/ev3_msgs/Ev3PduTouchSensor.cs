using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using hakoniwa.pdu.interfaces;

namespace hakoniwa.pdu.msgs.ev3_msgs
{
    public class Ev3PduTouchSensor
    {
        protected internal readonly IPdu _pdu;

        public Ev3PduTouchSensor(IPdu pdu)
        {
            _pdu = pdu;
        }
        public uint value
        {
            get => _pdu.GetData<uint>("value");
            set => _pdu.SetData("value", value);
        }
    }
}
