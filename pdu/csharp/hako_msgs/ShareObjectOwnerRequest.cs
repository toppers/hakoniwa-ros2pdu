using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using hakoniwa.pdu.interfaces;

namespace hakoniwa.pdu.msgs.hako_msgs
{
    public class ShareObjectOwnerRequest
    {
        protected internal readonly IPdu _pdu;

        public ShareObjectOwnerRequest(IPdu pdu)
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
        public uint new_owner_id
        {
            get => _pdu.GetData<uint>("new_owner_id");
            set => _pdu.SetData("new_owner_id", value);
        }
        public ulong request_time
        {
            get => _pdu.GetData<ulong>("request_time");
            set => _pdu.SetData("request_time", value);
        }
    }
}
