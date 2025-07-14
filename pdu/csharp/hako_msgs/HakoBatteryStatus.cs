using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using hakoniwa.pdu.interfaces;

namespace hakoniwa.pdu.msgs.hako_msgs
{
    public class HakoBatteryStatus
    {
        protected internal readonly IPdu _pdu;
        public IPdu GetPdu() { return _pdu; }

        public HakoBatteryStatus(IPdu pdu)
        {
            _pdu = pdu;
        }
        public double full_voltage
        {
            get => _pdu.GetData<double>("full_voltage");
            set => _pdu.SetData("full_voltage", value);
        }
        public double curr_voltage
        {
            get => _pdu.GetData<double>("curr_voltage");
            set => _pdu.SetData("curr_voltage", value);
        }
        public double curr_temp
        {
            get => _pdu.GetData<double>("curr_temp");
            set => _pdu.SetData("curr_temp", value);
        }
        public uint status
        {
            get => _pdu.GetData<uint>("status");
            set => _pdu.SetData("status", value);
        }
        public uint cycles
        {
            get => _pdu.GetData<uint>("cycles");
            set => _pdu.SetData("cycles", value);
        }
    }
}
