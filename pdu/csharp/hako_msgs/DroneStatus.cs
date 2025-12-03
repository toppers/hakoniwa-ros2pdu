using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using hakoniwa.pdu.interfaces;
using hakoniwa.pdu.msgs.geometry_msgs;

namespace hakoniwa.pdu.msgs.hako_msgs
{
    public class DroneStatus
    {
        protected internal readonly IPdu _pdu;
        public IPdu GetPdu() { return _pdu; }

        public DroneStatus(IPdu pdu)
        {
            _pdu = pdu;
        }
        public int flight_mode
        {
            get => _pdu.GetData<int>("flight_mode");
            set => _pdu.SetData("flight_mode", value);
        }
        public int internal_state
        {
            get => _pdu.GetData<int>("internal_state");
            set => _pdu.SetData("internal_state", value);
        }
        private Vector3 _propeller_wind;
        public Vector3 propeller_wind
        {
            get
            {
                if (_propeller_wind == null)
                {
                    _propeller_wind = new Vector3(_pdu.GetData<IPdu>("propeller_wind"));
                }
                return _propeller_wind;
            }
            set
            {
                _propeller_wind = value;
                _pdu.SetData("propeller_wind", value.GetPdu());
            }
        }
        public int collided_counts
        {
            get => _pdu.GetData<int>("collided_counts");
            set => _pdu.SetData("collided_counts", value);
        }
    }
}
