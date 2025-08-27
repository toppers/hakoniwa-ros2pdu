using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using hakoniwa.pdu.interfaces;
using hakoniwa.pdu.msgs.geometry_msgs;

namespace hakoniwa.pdu.msgs.drone_srv_msgs
{
    public class DroneGoToRequest
    {
        protected internal readonly IPdu _pdu;
        public IPdu GetPdu() { return _pdu; }

        public DroneGoToRequest(IPdu pdu)
        {
            _pdu = pdu;
        }
        public string drone_name
        {
            get => _pdu.GetData<string>("drone_name");
            set => _pdu.SetData("drone_name", value);
        }
        private Vector3 _target_pose;
        public Vector3 target_pose
        {
            get
            {
                if (_target_pose == null)
                {
                    _target_pose = new Vector3(_pdu.GetData<IPdu>("target_pose"));
                }
                return _target_pose;
            }
            set
            {
                _target_pose = value;
                _pdu.SetData("target_pose", value.GetPdu());
            }
        }
        public float speed_m_s
        {
            get => _pdu.GetData<float>("speed_m_s");
            set => _pdu.SetData("speed_m_s", value);
        }
        public float yaw_deg
        {
            get => _pdu.GetData<float>("yaw_deg");
            set => _pdu.SetData("yaw_deg", value);
        }
        public float tolerance_m
        {
            get => _pdu.GetData<float>("tolerance_m");
            set => _pdu.SetData("tolerance_m", value);
        }
        public float timeout_sec
        {
            get => _pdu.GetData<float>("timeout_sec");
            set => _pdu.SetData("timeout_sec", value);
        }
    }
}
