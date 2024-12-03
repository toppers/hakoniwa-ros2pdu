using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using hakoniwa.pdu.interfaces;
using hakoniwa.pdu.msgs.builtin_interfaces;
using hakoniwa.pdu.msgs.std_msgs;

namespace hakoniwa.pdu.msgs.geometry_msgs
{
    public class TransformStamped
    {
        protected internal readonly IPdu _pdu;

        public TransformStamped(IPdu pdu)
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
                _pdu.SetData("header", value._pdu);
            }
        }
        public string child_frame_id
        {
            get => _pdu.GetData<string>("child_frame_id");
            set => _pdu.SetData("child_frame_id", value);
        }
        private Transform _transform;
        public Transform transform
        {
            get
            {
                if (_transform == null)
                {
                    _transform = new Transform(_pdu.GetData<IPdu>("transform"));
                }
                return _transform;
            }
            set
            {
                _transform = value;
                _pdu.SetData("transform", value._pdu);
            }
        }
    }
}
