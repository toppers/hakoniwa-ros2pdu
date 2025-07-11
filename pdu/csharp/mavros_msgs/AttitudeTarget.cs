using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using hakoniwa.pdu.interfaces;
using hakoniwa.pdu.msgs.builtin_interfaces;
using hakoniwa.pdu.msgs.geometry_msgs;
using hakoniwa.pdu.msgs.std_msgs;

namespace hakoniwa.pdu.msgs.mavros_msgs
{
    public class AttitudeTarget
    {
        protected internal readonly IPdu _pdu;
        public IPdu GetPdu() { return _pdu; }

        public AttitudeTarget(IPdu pdu)
        {
            _pdu = pdu;
        }
        private Header _header;
        public Header header
        {
            get
            {
                if (_header == null)
                {
                    _header = new Header(_pdu.GetData<IPdu>("header"));
                }
                return _header;
            }
            set
            {
                _header = value;
                _pdu.SetData("header", value.GetPdu());
            }
        }
        public byte type_mask
        {
            get => _pdu.GetData<byte>("type_mask");
            set => _pdu.SetData("type_mask", value);
        }
        private Quaternion _orientation;
        public Quaternion orientation
        {
            get
            {
                if (_orientation == null)
                {
                    _orientation = new Quaternion(_pdu.GetData<IPdu>("orientation"));
                }
                return _orientation;
            }
            set
            {
                _orientation = value;
                _pdu.SetData("orientation", value.GetPdu());
            }
        }
        private Vector3 _body_rate;
        public Vector3 body_rate
        {
            get
            {
                if (_body_rate == null)
                {
                    _body_rate = new Vector3(_pdu.GetData<IPdu>("body_rate"));
                }
                return _body_rate;
            }
            set
            {
                _body_rate = value;
                _pdu.SetData("body_rate", value.GetPdu());
            }
        }
        public float thrust
        {
            get => _pdu.GetData<float>("thrust");
            set => _pdu.SetData("thrust", value);
        }
    }
}
