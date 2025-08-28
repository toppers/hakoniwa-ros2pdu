using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using hakoniwa.pdu.interfaces;
using hakoniwa.pdu.msgs.hako_srv_msgs;

namespace hakoniwa.pdu.msgs.drone_srv_msgs
{
    public class CameraCaptureImageResponsePacket
    {
        protected internal readonly IPdu _pdu;
        public IPdu GetPdu() { return _pdu; }

        public CameraCaptureImageResponsePacket(IPdu pdu)
        {
            _pdu = pdu;
        }
        private ServiceResponseHeader _header;
        public ServiceResponseHeader header
        {
            get
            {
                if (_header == null)
                {
                    _header = new ServiceResponseHeader(_pdu.GetData<IPdu>("header"));
                }
                return _header;
            }
            set
            {
                _header = value;
                _pdu.SetData("header", value.GetPdu());
            }
        }
        private CameraCaptureImageResponse _body;
        public CameraCaptureImageResponse body
        {
            get
            {
                if (_body == null)
                {
                    _body = new CameraCaptureImageResponse(_pdu.GetData<IPdu>("body"));
                }
                return _body;
            }
            set
            {
                _body = value;
                _pdu.SetData("body", value.GetPdu());
            }
        }
    }
}
