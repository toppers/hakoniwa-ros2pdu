using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using hakoniwa.pdu.interfaces;

namespace hakoniwa.pdu.msgs.hako_mavlink_msgs
{
    public class HakoHilSensor
    {
        protected internal readonly IPdu _pdu;
        public IPdu GetPdu() { return _pdu; }

        public HakoHilSensor(IPdu pdu)
        {
            _pdu = pdu;
        }
        public ulong time_usec
        {
            get => _pdu.GetData<ulong>("time_usec");
            set => _pdu.SetData("time_usec", value);
        }
        public float xacc
        {
            get => _pdu.GetData<float>("xacc");
            set => _pdu.SetData("xacc", value);
        }
        public float yacc
        {
            get => _pdu.GetData<float>("yacc");
            set => _pdu.SetData("yacc", value);
        }
        public float zacc
        {
            get => _pdu.GetData<float>("zacc");
            set => _pdu.SetData("zacc", value);
        }
        public float xgyro
        {
            get => _pdu.GetData<float>("xgyro");
            set => _pdu.SetData("xgyro", value);
        }
        public float ygyro
        {
            get => _pdu.GetData<float>("ygyro");
            set => _pdu.SetData("ygyro", value);
        }
        public float zgyro
        {
            get => _pdu.GetData<float>("zgyro");
            set => _pdu.SetData("zgyro", value);
        }
        public float xmag
        {
            get => _pdu.GetData<float>("xmag");
            set => _pdu.SetData("xmag", value);
        }
        public float ymag
        {
            get => _pdu.GetData<float>("ymag");
            set => _pdu.SetData("ymag", value);
        }
        public float zmag
        {
            get => _pdu.GetData<float>("zmag");
            set => _pdu.SetData("zmag", value);
        }
        public float abs_pressure
        {
            get => _pdu.GetData<float>("abs_pressure");
            set => _pdu.SetData("abs_pressure", value);
        }
        public float diff_pressure
        {
            get => _pdu.GetData<float>("diff_pressure");
            set => _pdu.SetData("diff_pressure", value);
        }
        public float pressure_alt
        {
            get => _pdu.GetData<float>("pressure_alt");
            set => _pdu.SetData("pressure_alt", value);
        }
        public float temperature
        {
            get => _pdu.GetData<float>("temperature");
            set => _pdu.SetData("temperature", value);
        }
        public uint fields_updated
        {
            get => _pdu.GetData<uint>("fields_updated");
            set => _pdu.SetData("fields_updated", value);
        }
        public byte id
        {
            get => _pdu.GetData<byte>("id");
            set => _pdu.SetData("id", value);
        }
    }
}
