using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using hakoniwa.pdu.interfaces;

namespace hakoniwa.pdu.msgs.hako_mavlink_msgs
{
    public class HakoSERVO_OUTPUT_RAW
    {
        protected internal readonly IPdu _pdu;

        public HakoSERVO_OUTPUT_RAW(IPdu pdu)
        {
            _pdu = pdu;
        }
        public uint time_usec
        {
            get => _pdu.GetData<uint>("time_usec");
            set => _pdu.SetData("time_usec", value);
        }
        public byte port
        {
            get => _pdu.GetData<byte>("port");
            set => _pdu.SetData("port", value);
        }
        public ushort servo1_raw
        {
            get => _pdu.GetData<ushort>("servo1_raw");
            set => _pdu.SetData("servo1_raw", value);
        }
        public ushort servo2_raw
        {
            get => _pdu.GetData<ushort>("servo2_raw");
            set => _pdu.SetData("servo2_raw", value);
        }
        public ushort servo3_raw
        {
            get => _pdu.GetData<ushort>("servo3_raw");
            set => _pdu.SetData("servo3_raw", value);
        }
        public ushort servo4_raw
        {
            get => _pdu.GetData<ushort>("servo4_raw");
            set => _pdu.SetData("servo4_raw", value);
        }
        public ushort servo5_raw
        {
            get => _pdu.GetData<ushort>("servo5_raw");
            set => _pdu.SetData("servo5_raw", value);
        }
        public ushort servo6_raw
        {
            get => _pdu.GetData<ushort>("servo6_raw");
            set => _pdu.SetData("servo6_raw", value);
        }
        public ushort servo7_raw
        {
            get => _pdu.GetData<ushort>("servo7_raw");
            set => _pdu.SetData("servo7_raw", value);
        }
        public ushort servo8_raw
        {
            get => _pdu.GetData<ushort>("servo8_raw");
            set => _pdu.SetData("servo8_raw", value);
        }
    }
}
