using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using hakoniwa.pdu.interfaces;

namespace hakoniwa.pdu.msgs.ev3_msgs
{
    public class Ev3PduSensorHeader
    {
        protected internal readonly IPdu _pdu;
        public IPdu GetPdu() { return _pdu; }

        public Ev3PduSensorHeader(IPdu pdu)
        {
            _pdu = pdu;
        }
        public string name
        {
            get => _pdu.GetData<string>("name");
            set => _pdu.SetData("name", value);
        }
        public uint version
        {
            get => _pdu.GetData<uint>("version");
            set => _pdu.SetData("version", value);
        }
        public long hakoniwa_time
        {
            get => _pdu.GetData<long>("hakoniwa_time");
            set => _pdu.SetData("hakoniwa_time", value);
        }
        public uint ext_off
        {
            get => _pdu.GetData<uint>("ext_off");
            set => _pdu.SetData("ext_off", value);
        }
        public uint ext_size
        {
            get => _pdu.GetData<uint>("ext_size");
            set => _pdu.SetData("ext_size", value);
        }
    }
}
