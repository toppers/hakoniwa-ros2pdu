using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using hakoniwa.pdu.interfaces;

namespace hakoniwa.pdu.msgs.hako_mavlink_msgs
{
    public class HakoHilGps
    {
        protected internal readonly IPdu _pdu;
        public IPdu GetPdu() { return _pdu; }

        public HakoHilGps(IPdu pdu)
        {
            _pdu = pdu;
        }
        public ulong time_usec
        {
            get => _pdu.GetData<ulong>("time_usec");
            set => _pdu.SetData("time_usec", value);
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
        public ushort eph
        {
            get => _pdu.GetData<ushort>("eph");
            set => _pdu.SetData("eph", value);
        }
        public ushort epv
        {
            get => _pdu.GetData<ushort>("epv");
            set => _pdu.SetData("epv", value);
        }
        public ushort vel
        {
            get => _pdu.GetData<ushort>("vel");
            set => _pdu.SetData("vel", value);
        }
        public short vn
        {
            get => _pdu.GetData<short>("vn");
            set => _pdu.SetData("vn", value);
        }
        public short ve
        {
            get => _pdu.GetData<short>("ve");
            set => _pdu.SetData("ve", value);
        }
        public short vd
        {
            get => _pdu.GetData<short>("vd");
            set => _pdu.SetData("vd", value);
        }
        public ushort cog
        {
            get => _pdu.GetData<ushort>("cog");
            set => _pdu.SetData("cog", value);
        }
        public byte satellites_visible
        {
            get => _pdu.GetData<byte>("satellites_visible");
            set => _pdu.SetData("satellites_visible", value);
        }
        public byte id
        {
            get => _pdu.GetData<byte>("id");
            set => _pdu.SetData("id", value);
        }
        public byte yaw
        {
            get => _pdu.GetData<byte>("yaw");
            set => _pdu.SetData("yaw", value);
        }
        public byte fix_type
        {
            get => _pdu.GetData<byte>("fix_type");
            set => _pdu.SetData("fix_type", value);
        }
    }
}
