using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using hakoniwa.pdu.interfaces;

namespace hakoniwa.pdu.msgs.hako_msgs
{
    public class MetaPdu
    {
        protected internal readonly IPdu _pdu;
        public IPdu GetPdu() { return _pdu; }

        public MetaPdu(IPdu pdu)
        {
            _pdu = pdu;
        }
        public uint total_len
        {
            get => _pdu.GetData<uint>("total_len");
            set => _pdu.SetData("total_len", value);
        }
        public uint magicno
        {
            get => _pdu.GetData<uint>("magicno");
            set => _pdu.SetData("magicno", value);
        }
        public ushort version
        {
            get => _pdu.GetData<ushort>("version");
            set => _pdu.SetData("version", value);
        }
        public ushort flags
        {
            get => _pdu.GetData<ushort>("flags");
            set => _pdu.SetData("flags", value);
        }
        public uint meta_request_type
        {
            get => _pdu.GetData<uint>("meta_request_type");
            set => _pdu.SetData("meta_request_type", value);
        }
        public ulong hako_time_us
        {
            get => _pdu.GetData<ulong>("hako_time_us");
            set => _pdu.SetData("hako_time_us", value);
        }
        public ulong asset_time_us
        {
            get => _pdu.GetData<ulong>("asset_time_us");
            set => _pdu.SetData("asset_time_us", value);
        }
        public ulong real_time_us
        {
            get => _pdu.GetData<ulong>("real_time_us");
            set => _pdu.SetData("real_time_us", value);
        }
        public string robot_name
        {
            get => _pdu.GetData<string>("robot_name");
            set => _pdu.SetData("robot_name", value);
        }
        public int channel_id
        {
            get => _pdu.GetData<int>("channel_id");
            set => _pdu.SetData("channel_id", value);
        }
        public uint body_len
        {
            get => _pdu.GetData<uint>("body_len");
            set => _pdu.SetData("body_len", value);
        }
    }
}
