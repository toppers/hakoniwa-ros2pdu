using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using hakoniwa.pdu.interfaces;

namespace hakoniwa.pdu.msgs.std_msgs
{
    public class Int16MultiArray
    {
        protected internal readonly IPdu _pdu;

        public Int16MultiArray(IPdu pdu)
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
                _pdu.SetData("layout", value._pdu);
            }
        }
        public short[] data
        {
            get => _pdu.GetDataArray<short>("data");
            set => _pdu.SetData("data", value);
        }
    }
}
