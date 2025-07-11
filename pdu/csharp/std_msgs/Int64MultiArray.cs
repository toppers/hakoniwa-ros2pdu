using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using hakoniwa.pdu.interfaces;

namespace hakoniwa.pdu.msgs.std_msgs
{
    public class Int64MultiArray
    {
        protected internal readonly IPdu _pdu;
        public IPdu GetPdu() { return _pdu; }

        public Int64MultiArray(IPdu pdu)
        {
            _pdu = pdu;
        }
        private MultiArrayLayout _layout;
        public MultiArrayLayout layout
        {
            get
            {
                if (_layout == null)
                {
                    _layout = new MultiArrayLayout(_pdu.GetData<IPdu>("layout"));
                }
                return _layout;
            }
            set
            {
                _layout = value;
                _pdu.SetData("layout", value.GetPdu());
            }
        }
        public long[] data
        {
            get => _pdu.GetDataArray<long>("data");
            set => _pdu.SetData("data", value);
        }
    }
}
