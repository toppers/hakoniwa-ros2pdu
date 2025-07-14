using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using hakoniwa.pdu.interfaces;

namespace hakoniwa.pdu.msgs.hako_msgs
{
    public class HakoCmdCamera
    {
        protected internal readonly IPdu _pdu;
        public IPdu GetPdu() { return _pdu; }

        public HakoCmdCamera(IPdu pdu)
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
                _pdu.SetData("header", value.GetPdu());
            }
        }
        public int request_id
        {
            get => _pdu.GetData<int>("request_id");
            set => _pdu.SetData("request_id", value);
        }
        public int encode_type
        {
            get => _pdu.GetData<int>("encode_type");
            set => _pdu.SetData("encode_type", value);
        }
    }
}
