using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using hakoniwa.pdu.interfaces;

namespace hakoniwa.pdu.msgs.hako_msgs
{
    public class HakoDroneCmdLand
    {
        protected internal readonly IPdu _pdu;

        public HakoDroneCmdLand(IPdu pdu)
        {
            _pdu = pdu;
        }
        private HakoDroneCmdHeader _header;
        public HakoDroneCmdHeader header
        {
            get
            {
                if (_header == null)
                {
                    _header = new HakoDroneCmdHeader(_pdu.GetData<IPdu>("header"));
                }
                return _header;
            }
            set
            {
                _header = value;
                _pdu.SetData("header", value._pdu);
            }
        }
        public double height
        {
            get => _pdu.GetData<double>("height");
            set => _pdu.SetData("height", value);
        }
        public double speed
        {
            get => _pdu.GetData<double>("speed");
            set => _pdu.SetData("speed", value);
        }
        public double yaw_deg
        {
            get => _pdu.GetData<double>("yaw_deg");
            set => _pdu.SetData("yaw_deg", value);
        }
    }
}
