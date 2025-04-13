using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using hakoniwa.pdu.interfaces;

namespace hakoniwa.pdu.msgs.hako_srv_msgs
{
    public class AddTwoIntsRequest
    {
        protected internal readonly IPdu _pdu;

        public AddTwoIntsRequest(IPdu pdu)
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
                _pdu.SetData("header", value._pdu);
            }
        }
        public long a
        {
            get => _pdu.GetData<long>("a");
            set => _pdu.SetData("a", value);
        }
        public long b
        {
            get => _pdu.GetData<long>("b");
            set => _pdu.SetData("b", value);
        }
    }
}
