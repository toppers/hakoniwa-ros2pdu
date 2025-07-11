using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using hakoniwa.pdu.interfaces;

namespace hakoniwa.pdu.msgs.hako_mavlink_msgs
{
    public class HakoHilStateQuaternion
    {
        protected internal readonly IPdu _pdu;
        public IPdu GetPdu() { return _pdu; }

        public HakoHilStateQuaternion(IPdu pdu)
        {
            _pdu = pdu;
        }
        public ulong time_usec
        {
            get => _pdu.GetData<ulong>("time_usec");
            set => _pdu.SetData("time_usec", value);
        }
        public float[] attitude_quaternion
        {
            get => _pdu.GetDataArray<float>("attitude_quaternion");
            set => _pdu.SetData("attitude_quaternion", value);
        }
        public float rollspeed
        {
            get => _pdu.GetData<float>("rollspeed");
            set => _pdu.SetData("rollspeed", value);
        }
        public float pitchspeed
        {
            get => _pdu.GetData<float>("pitchspeed");
            set => _pdu.SetData("pitchspeed", value);
        }
        public float yawspeed
        {
            get => _pdu.GetData<float>("yawspeed");
            set => _pdu.SetData("yawspeed", value);
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
        public ushort ind_airspeed
        {
            get => _pdu.GetData<ushort>("ind_airspeed");
            set => _pdu.SetData("ind_airspeed", value);
        }
        public ushort true_airspeed
        {
            get => _pdu.GetData<ushort>("true_airspeed");
            set => _pdu.SetData("true_airspeed", value);
        }
        public short xacc
        {
            get => _pdu.GetData<short>("xacc");
            set => _pdu.SetData("xacc", value);
        }
        public short yacc
        {
            get => _pdu.GetData<short>("yacc");
            set => _pdu.SetData("yacc", value);
        }
        public short zacc
        {
            get => _pdu.GetData<short>("zacc");
            set => _pdu.SetData("zacc", value);
        }
    }
}
