using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using hakoniwa.pdu.interfaces;

namespace hakoniwa.pdu.msgs.can_msgs
{
    public class HakoCan
    {
        protected internal readonly IPdu _pdu;

        public HakoCan(IPdu pdu)
        {
            _pdu = pdu;
        }
        private HakoCanHead _head;
        public HakoCanHead head
        {
            get
            {
                if (_head == null)
                {
                    _head = new HakoCanHead(_pdu.GetData<IPdu>("head"));
                }
                return _head;
            }
            set
            {
                _head = value;
                _pdu.SetData("head", value._pdu);
            }
        }
        private HakoCanBody _body;
        public HakoCanBody body
        {
            get
            {
                if (_body == null)
                {
                    _body = new HakoCanBody(_pdu.GetData<IPdu>("body"));
                }
                return _body;
            }
            set
            {
                _body = value;
                _pdu.SetData("body", value._pdu);
            }
        }
    }
}
