using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using hakoniwa.pdu.interfaces;

namespace hakoniwa.pdu.msgs.hako_msgs
{
    public class HakoStatusMagnetHolder
    {
        protected internal readonly IPdu _pdu;
        public IPdu GetPdu() { return _pdu; }

        public HakoStatusMagnetHolder(IPdu pdu)
        {
            _pdu = pdu;
        }
        public bool magnet_on
        {
            get => _pdu.GetData<bool>("magnet_on");
            set => _pdu.SetData("magnet_on", value);
        }
        public bool contact_on
        {
            get => _pdu.GetData<bool>("contact_on");
            set => _pdu.SetData("contact_on", value);
        }
    }
}
