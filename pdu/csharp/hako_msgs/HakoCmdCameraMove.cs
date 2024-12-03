using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using hakoniwa.pdu.interfaces;
using hakoniwa.pdu.msgs.geometry_msgs;

namespace hakoniwa.pdu.msgs.hako_msgs
{
    public class HakoCmdCameraMove
    {
        protected internal readonly IPdu _pdu;

        public HakoCmdCameraMove(IPdu pdu)
        {
            _pdu = pdu;
        }
        private HakoCmdHeader _header;
        public HakoCmdHeader header
        {
            get
            {
                if (_header == null)
                {
                    _header = new HakoCmdHeader(_pdu.GetData<IPdu>("header"));
                }
                return _header;
            }
            set
            {
                _header = value;
                _pdu.SetData("header", value._pdu);
            }
        }
        public int request_id
        {
            get => _pdu.GetData<int>("request_id");
            set => _pdu.SetData("request_id", value);
        }
        private Vector3 _angle;
        public Vector3 angle
        {
            get
            {
                if (_angle == null)
                {
                    _angle = new Vector3(_pdu.GetData<IPdu>("angle"));
                }
                return _angle;
            }
            set
            {
                _angle = value;
                _pdu.SetData("angle", value._pdu);
            }
        }
    }
}
