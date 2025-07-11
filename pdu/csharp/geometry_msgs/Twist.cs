using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using hakoniwa.pdu.interfaces;

namespace hakoniwa.pdu.msgs.geometry_msgs
{
    public class Twist
    {
        protected internal readonly IPdu _pdu;
        public IPdu GetPdu() { return _pdu; }

        public Twist(IPdu pdu)
        {
            _pdu = pdu;
        }
        private Vector3 _linear;
        public Vector3 linear
        {
            get
            {
                if (_linear == null)
                {
                    _linear = new Vector3(_pdu.GetData<IPdu>("linear"));
                }
                return _linear;
            }
            set
            {
                _linear = value;
                _pdu.SetData("linear", value.GetPdu());
            }
        }
        private Vector3 _angular;
        public Vector3 angular
        {
            get
            {
                if (_angular == null)
                {
                    _angular = new Vector3(_pdu.GetData<IPdu>("angular"));
                }
                return _angular;
            }
            set
            {
                _angular = value;
                _pdu.SetData("angular", value.GetPdu());
            }
        }
    }
}
