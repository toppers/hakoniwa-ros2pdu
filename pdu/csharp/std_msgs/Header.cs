using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using hakoniwa.pdu.interfaces;
using hakoniwa.pdu.msgs.builtin_interfaces;

namespace hakoniwa.pdu.msgs.std_msgs
{
    public class Header
    {
        protected internal readonly IPdu _pdu;

        public Header(IPdu pdu)
        {
            _pdu = pdu;
        }
        private Time _stamp;
        public Time stamp
        {
            get
            {
                if (_stamp == null)
                {
                    _stamp = new Time(_pdu.GetData<IPdu>("stamp"));
                }
                return _stamp;
            }
            set
            {
                _stamp = value;
                _pdu.SetData("stamp", value._pdu);
            }
        }
        public string frame_id
        {
            get => _pdu.GetData<string>("frame_id");
            set => _pdu.SetData("frame_id", value);
        }
    }
}
