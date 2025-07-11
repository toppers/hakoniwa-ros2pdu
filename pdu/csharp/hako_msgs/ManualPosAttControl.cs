using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using hakoniwa.pdu.interfaces;
using hakoniwa.pdu.msgs.geometry_msgs;

namespace hakoniwa.pdu.msgs.hako_msgs
{
    public class ManualPosAttControl
    {
        protected internal readonly IPdu _pdu;
        public IPdu GetPdu() { return _pdu; }

        public ManualPosAttControl(IPdu pdu)
        {
            _pdu = pdu;
        }
        public bool do_operation
        {
            get => _pdu.GetData<bool>("do_operation");
            set => _pdu.SetData("do_operation", value);
        }
        private Twist _posatt;
        public Twist posatt
        {
            get
            {
                if (_posatt == null)
                {
                    _posatt = new Twist(_pdu.GetData<IPdu>("posatt"));
                }
                return _posatt;
            }
            set
            {
                _posatt = value;
                _pdu.SetData("posatt", value.GetPdu());
            }
        }
    }
}
