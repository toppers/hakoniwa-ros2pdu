using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using hakoniwa.pdu.interfaces;

namespace hakoniwa.pdu.msgs.geometry_msgs
{
    public class Transform
    {
        protected internal readonly IPdu _pdu;
        public IPdu GetPdu() { return _pdu; }

        public Transform(IPdu pdu)
        {
            _pdu = pdu;
        }
        private Vector3 _translation;
        public Vector3 translation
        {
            get
            {
                if (_translation == null)
                {
                    _translation = new Vector3(_pdu.GetData<IPdu>("translation"));
                }
                return _translation;
            }
            set
            {
                _translation = value;
                _pdu.SetData("translation", value.GetPdu());
            }
        }
        private Quaternion _rotation;
        public Quaternion rotation
        {
            get
            {
                if (_rotation == null)
                {
                    _rotation = new Quaternion(_pdu.GetData<IPdu>("rotation"));
                }
                return _rotation;
            }
            set
            {
                _rotation = value;
                _pdu.SetData("rotation", value.GetPdu());
            }
        }
    }
}
