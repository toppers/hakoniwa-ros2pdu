using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using hakoniwa.pdu.interfaces;
using hakoniwa.pdu.msgs.geometry_msgs;
using hakoniwa.pdu.msgs.hako_msgs;

namespace hakoniwa.pdu.msgs.drone_srv_msgs
{
    public class DroneGetStateResponse
    {
        protected internal readonly IPdu _pdu;
        public IPdu GetPdu() { return _pdu; }

        public DroneGetStateResponse(IPdu pdu)
        {
            _pdu = pdu;
        }
        public bool ok
        {
            get => _pdu.GetData<bool>("ok");
            set => _pdu.SetData("ok", value);
        }
        public bool is_ready
        {
            get => _pdu.GetData<bool>("is_ready");
            set => _pdu.SetData("is_ready", value);
        }
        private Pose _current_pose;
        public Pose current_pose
        {
            get
            {
                if (_current_pose == null)
                {
                    _current_pose = new Pose(_pdu.GetData<IPdu>("current_pose"));
                }
                return _current_pose;
            }
            set
            {
                _current_pose = value;
                _pdu.SetData("current_pose", value.GetPdu());
            }
        }
        private HakoBatteryStatus _battery_status;
        public HakoBatteryStatus battery_status
        {
            get
            {
                if (_battery_status == null)
                {
                    _battery_status = new HakoBatteryStatus(_pdu.GetData<IPdu>("battery_status"));
                }
                return _battery_status;
            }
            set
            {
                _battery_status = value;
                _pdu.SetData("battery_status", value.GetPdu());
            }
        }
        public string mode
        {
            get => _pdu.GetData<string>("mode");
            set => _pdu.SetData("mode", value);
        }
        public string message
        {
            get => _pdu.GetData<string>("message");
            set => _pdu.SetData("message", value);
        }
    }
}
