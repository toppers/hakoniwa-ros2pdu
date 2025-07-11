using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using hakoniwa.pdu.interfaces;

namespace hakoniwa.pdu.msgs.hako_mavlink_msgs
{
    public class HakoGLOBAL_POSITION_INT
    {
        protected internal readonly IPdu _pdu;
        public IPdu GetPdu() { return _pdu; }

        public HakoGLOBAL_POSITION_INT(IPdu pdu)
        {
            _pdu = pdu;
        }
        public uint time_boot_ms
        {
            get => _pdu.GetData<uint>("time_boot_ms");
            set => _pdu.SetData("time_boot_ms", value);
        }
        public int lat
        {
            get => _pdu.GetData<int>("lat");
            set => _pdu.SetData("lat", value);
        }
        public int lon
        {
            get => _pdu.GetData<int>("lon");
            set => _pdu.SetData("lon", value);
        }
        public int alt
        {
            get => _pdu.GetData<int>("alt");
            set => _pdu.SetData("alt", value);
        }
        public int relative_alt
        {
            get => _pdu.GetData<int>("relative_alt");
            set => _pdu.SetData("relative_alt", value);
        }
        public short vx
        {
            get => _pdu.GetData<short>("vx");
            set => _pdu.SetData("vx", value);
        }
        public short vy
        {
            get => _pdu.GetData<short>("vy");
            set => _pdu.SetData("vy", value);
        }
        public short vz
        {
            get => _pdu.GetData<short>("vz");
            set => _pdu.SetData("vz", value);
        }
        public ushort hdg
        {
            get => _pdu.GetData<ushort>("hdg");
            set => _pdu.SetData("hdg", value);
        }
    }
}
