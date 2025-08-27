using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using hakoniwa.pdu.interfaces;
using hakoniwa.pdu.msgs.hako_srv_msgs;

namespace hakoniwa.pdu.msgs.drone_srv_msgs
{
    public class LiDARScanRequestPacket
    {
        protected internal readonly IPdu _pdu;
        public IPdu GetPdu() { return _pdu; }

        public LiDARScanRequestPacket(IPdu pdu)
        {
            _pdu = pdu;
        }
        private ServiceRequestHeader _header;
        public ServiceRequestHeader header
        {
            get
            {
                if (_header == null)
                {
                    _header = new ServiceRequestHeader(_pdu.GetData<IPdu>("header"));
                }
                return _header;
            }
            set
            {
                _header = value;
                _pdu.SetData("header", value.GetPdu());
            }
        }
        private LiDARScanRequest _body;
        public LiDARScanRequest body
        {
            get
            {
                if (_body == null)
                {
                    _body = new LiDARScanRequest(_pdu.GetData<IPdu>("body"));
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
