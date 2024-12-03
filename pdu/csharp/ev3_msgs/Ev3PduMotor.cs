using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using hakoniwa.pdu.interfaces;

namespace hakoniwa.pdu.msgs.ev3_msgs
{
    public class Ev3PduMotor
    {
        protected internal readonly IPdu _pdu;

        public Ev3PduMotor(IPdu pdu)
        {
            _pdu = pdu;
        }
        public int power
        {
            get => _pdu.GetData<int>("power");
            set => _pdu.SetData("power", value);
        }
        public uint stop
        {
            get => _pdu.GetData<uint>("stop");
            set => _pdu.SetData("stop", value);
        }
        public uint reset_angle
        {
            get => _pdu.GetData<uint>("reset_angle");
            set => _pdu.SetData("reset_angle", value);
        }
    }
}
