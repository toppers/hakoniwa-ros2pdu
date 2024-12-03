using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using hakoniwa.pdu.interfaces;
using hakoniwa.pdu.msgs.builtin_interfaces;
using hakoniwa.pdu.msgs.std_msgs;

namespace hakoniwa.pdu.msgs.sensor_msgs
{
    public class JointState
    {
        protected internal readonly IPdu _pdu;

        public JointState(IPdu pdu)
        {
            _pdu = pdu;
        }
        private Header _header;
        public Header header
        {
            get
            {
                if (_header == null)
                {
                    _header = new Header(_pdu.GetData<IPdu>("header"));
                }
                return _header;
            }
            set
            {
                _header = value;
                _pdu.SetData("header", value._pdu);
            }
        }
        public string[] name
        {
            get => _pdu.GetDataArray<string>("name");
            set => _pdu.SetData("name", value);
        }
        public double[] position
        {
            get => _pdu.GetDataArray<double>("position");
            set => _pdu.SetData("position", value);
        }
        public double[] velocity
        {
            get => _pdu.GetDataArray<double>("velocity");
            set => _pdu.SetData("velocity", value);
        }
        public double[] effort
        {
            get => _pdu.GetDataArray<double>("effort");
            set => _pdu.SetData("effort", value);
        }
    }
}
