using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using hakoniwa.pdu.interfaces;

namespace hakoniwa.pdu.msgs.hako_msgs
{
    public class HakoCmdMagnetHolder
    {
        protected internal readonly IPdu _pdu;

        public HakoCmdMagnetHolder(IPdu pdu)
        {
            _pdu = pdu;
        }
        private HakoCmdHeader _header;
        public HakoCmdHeader header
        {
            get
            {
                if (_header == null)
                {
                    _header = new HakoCmdHeader(_pdu.GetData<IPdu>("header"));
                }
                return _header;
            }
            set
            {
                _header = value;
                _pdu.SetData("header", value._pdu);
            }
        }
        public bool magnet_on
        {
            get => _pdu.GetData<bool>("magnet_on");
            set => _pdu.SetData("magnet_on", value);
        }
    }
}
