using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using hakoniwa.pdu.interfaces;

namespace hakoniwa.pdu.msgs.hako_msgs
{
    public class DisturbanceAtm
    {
        protected internal readonly IPdu _pdu;

        public DisturbanceAtm(IPdu pdu)
        {
            _pdu = pdu;
        }
        public double sea_level_atm
        {
            get => _pdu.GetData<double>("sea_level_atm");
            set => _pdu.SetData("sea_level_atm", value);
        }
    }
}
