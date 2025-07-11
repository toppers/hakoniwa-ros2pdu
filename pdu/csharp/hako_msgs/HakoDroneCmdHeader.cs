using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using hakoniwa.pdu.interfaces;

namespace hakoniwa.pdu.msgs.hako_msgs
{
    public class HakoDroneCmdHeader
    {
        protected internal readonly IPdu _pdu;
        public IPdu GetPdu() { return _pdu; }

        public HakoDroneCmdHeader(IPdu pdu)
        {
            _pdu = pdu;
        }
        public bool request
        {
            get => _pdu.GetData<bool>("request");
            set => _pdu.SetData("request", value);
        }
        public bool result
        {
            get => _pdu.GetData<bool>("result");
            set => _pdu.SetData("result", value);
        }
        public int result_code
        {
            get => _pdu.GetData<int>("result_code");
            set => _pdu.SetData("result_code", value);
        }
    }
}
