using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using hakoniwa.pdu.interfaces;

namespace hakoniwa.pdu.msgs.std_msgs
{
    public class Float64
    {
        protected internal readonly IPdu _pdu;
        public IPdu GetPdu() { return _pdu; }

        public Float64(IPdu pdu)
        {
            _pdu = pdu;
        }
        public double data
        {
            get => _pdu.GetData<double>("data");
            set => _pdu.SetData("data", value);
        }
    }
}
