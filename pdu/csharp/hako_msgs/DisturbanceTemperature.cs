using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using hakoniwa.pdu.interfaces;

namespace hakoniwa.pdu.msgs.hako_msgs
{
    public class DisturbanceTemperature
    {
        protected internal readonly IPdu _pdu;

        public DisturbanceTemperature(IPdu pdu)
        {
            _pdu = pdu;
        }
        public double value
        {
            get => _pdu.GetData<double>("value");
            set => _pdu.SetData("value", value);
        }
    }
}
