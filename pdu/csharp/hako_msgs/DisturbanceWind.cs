using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using hakoniwa.pdu.interfaces;
using hakoniwa.pdu.msgs.geometry_msgs;

namespace hakoniwa.pdu.msgs.hako_msgs
{
    public class DisturbanceWind
    {
        protected internal readonly IPdu _pdu;
        public IPdu GetPdu() { return _pdu; }

        public DisturbanceWind(IPdu pdu)
        {
            _pdu = pdu;
        }
        private Vector3 _value;
        public Vector3 value
        {
            get
            {
                if (_value == null)
                {
                    _value = new Vector3(_pdu.GetData<IPdu>("value"));
                }
                return _value;
            }
            set
            {
                _value = value;
                _pdu.SetData("value", value.GetPdu());
            }
        }
    }
}
