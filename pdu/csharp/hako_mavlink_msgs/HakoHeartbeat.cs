using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using hakoniwa.pdu.interfaces;

namespace hakoniwa.pdu.msgs.hako_mavlink_msgs
{
    public class HakoHeartbeat
    {
        protected internal readonly IPdu _pdu;

        public HakoHeartbeat(IPdu pdu)
        {
            _pdu = pdu;
        }
        public byte type
        {
            get => _pdu.GetData<byte>("type");
            set => _pdu.SetData("type", value);
        }
        public byte autopilot
        {
            get => _pdu.GetData<byte>("autopilot");
            set => _pdu.SetData("autopilot", value);
        }
        public byte base_mode
        {
            get => _pdu.GetData<byte>("base_mode");
            set => _pdu.SetData("base_mode", value);
        }
        public uint custom_mode
        {
            get => _pdu.GetData<uint>("custom_mode");
            set => _pdu.SetData("custom_mode", value);
        }
        public byte system_status
        {
            get => _pdu.GetData<byte>("system_status");
            set => _pdu.SetData("system_status", value);
        }
        public byte mavlink_version
        {
            get => _pdu.GetData<byte>("mavlink_version");
            set => _pdu.SetData("mavlink_version", value);
        }
    }
}
