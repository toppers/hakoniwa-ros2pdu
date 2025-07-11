using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using hakoniwa.pdu.interfaces;

namespace hakoniwa.pdu.msgs.can_msgs
{
    public class HakoCanHead
    {
        protected internal readonly IPdu _pdu;
        public IPdu GetPdu() { return _pdu; }

        public HakoCanHead(IPdu pdu)
        {
            _pdu = pdu;
        }
        public uint channel
        {
            get => _pdu.GetData<uint>("channel");
            set => _pdu.SetData("channel", value);
        }
        public uint ide
        {
            get => _pdu.GetData<uint>("ide");
            set => _pdu.SetData("ide", value);
        }
        public uint rtr
        {
            get => _pdu.GetData<uint>("rtr");
            set => _pdu.SetData("rtr", value);
        }
        public uint dlc
        {
            get => _pdu.GetData<uint>("dlc");
            set => _pdu.SetData("dlc", value);
        }
        public uint canid
        {
            get => _pdu.GetData<uint>("canid");
            set => _pdu.SetData("canid", value);
        }
    }
}
