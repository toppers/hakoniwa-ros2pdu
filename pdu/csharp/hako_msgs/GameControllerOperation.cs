using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using hakoniwa.pdu.interfaces;

namespace hakoniwa.pdu.msgs.hako_msgs
{
    public class GameControllerOperation
    {
        protected internal readonly IPdu _pdu;

        public GameControllerOperation(IPdu pdu)
        {
            _pdu = pdu;
        }
        public double[] axis
        {
            get => _pdu.GetDataArray<double>("axis");
            set => _pdu.SetData("axis", value);
        }
        public bool[] button
        {
            get => _pdu.GetDataArray<bool>("button");
            set => _pdu.SetData("button", value);
        }
    }
}
