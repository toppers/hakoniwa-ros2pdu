using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using hakoniwa.pdu.interfaces;

namespace hakoniwa.pdu.msgs.hako_msgs
{
    public class ShareObjectOwnerResponse
    {
        protected internal readonly IPdu _pdu;
        public IPdu GetPdu() { return _pdu; }

        public ShareObjectOwnerResponse(IPdu pdu)
        {
            _pdu = pdu;
        }
        public string object_name
        {
            get => _pdu.GetData<string>("object_name");
            set => _pdu.SetData("object_name", value);
        }
        public uint request_type
        {
            get => _pdu.GetData<uint>("request_type");
            set => _pdu.SetData("request_type", value);
        }
        public uint owner_id
        {
            get => _pdu.GetData<uint>("owner_id");
            set => _pdu.SetData("owner_id", value);
        }
        public bool accepted
        {
            get => _pdu.GetData<bool>("accepted");
            set => _pdu.SetData("accepted", value);
        }
    }
}
