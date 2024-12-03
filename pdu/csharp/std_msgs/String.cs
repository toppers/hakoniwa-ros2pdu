using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using hakoniwa.pdu.interfaces;

namespace hakoniwa.pdu.msgs.std_msgs
{
    public class String
    {
        protected internal readonly IPdu _pdu;

        public String(IPdu pdu)
        {
            _pdu = pdu;
        }
        public string data
        {
            get => _pdu.GetData<string>("data");
            set => _pdu.SetData("data", value);
        }
    }
}
