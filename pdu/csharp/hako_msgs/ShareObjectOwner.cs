using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using hakoniwa.pdu.interfaces;
using hakoniwa.pdu.msgs.geometry_msgs;

namespace hakoniwa.pdu.msgs.hako_msgs
{
    public class ShareObjectOwner
    {
        protected internal readonly IPdu _pdu;
        public IPdu GetPdu() { return _pdu; }

        public ShareObjectOwner(IPdu pdu)
        {
            _pdu = pdu;
        }
        public string object_name
        {
            get => _pdu.GetData<string>("object_name");
            set => _pdu.SetData("object_name", value);
        }
        public uint owner_id
        {
            get => _pdu.GetData<uint>("owner_id");
            set => _pdu.SetData("owner_id", value);
        }
        public ulong last_update
        {
            get => _pdu.GetData<ulong>("last_update");
            set => _pdu.SetData("last_update", value);
        }
        private Twist _pos;
        public Twist pos
        {
            get
            {
                if (_pos == null)
                {
                    _pos = new Twist(_pdu.GetData<IPdu>("pos"));
                }
                return _pos;
            }
            set
            {
                _pos = value;
                _pdu.SetData("pos", value.GetPdu());
            }
        }
    }
}
