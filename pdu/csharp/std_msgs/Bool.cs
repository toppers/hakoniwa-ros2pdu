using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using hakoniwa.pdu.interfaces;

namespace hakoniwa.pdu.msgs.std_msgs
{
    public class Bool
    {
        protected internal readonly IPdu _pdu;

        public Bool(IPdu pdu)
        {
            _pdu = pdu;
        }
        public bool data
        {
            get => _pdu.GetData<bool>("data");
            set => _pdu.SetData("data", value);
        }
    }
}
