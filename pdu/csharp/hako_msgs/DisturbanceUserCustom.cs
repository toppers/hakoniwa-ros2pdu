using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using hakoniwa.pdu.interfaces;

namespace hakoniwa.pdu.msgs.hako_msgs
{
    public class DisturbanceUserCustom
    {
        protected internal readonly IPdu _pdu;
        public IPdu GetPdu() { return _pdu; }

        public DisturbanceUserCustom(IPdu pdu)
        {
            _pdu = pdu;
        }
        public double[] data
        {
            get => _pdu.GetDataArray<double>("data");
            set => _pdu.SetData("data", value);
        }
    }
}
