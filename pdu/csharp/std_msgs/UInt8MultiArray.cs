using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using hakoniwa.pdu.interfaces;

namespace hakoniwa.pdu.msgs.std_msgs
{
    public class UInt8MultiArray
    {
        protected internal readonly IPdu _pdu;

        public UInt8MultiArray(IPdu pdu)
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
        public byte[] data
        {
            get => _pdu.GetDataArray<byte>("data");
            set => _pdu.SetData("data", value);
        }
    }
}
