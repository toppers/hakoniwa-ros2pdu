using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using hakoniwa.pdu.interfaces;
using hakoniwa.pdu.msgs.builtin_interfaces;
using hakoniwa.pdu.msgs.geometry_msgs;
using hakoniwa.pdu.msgs.sensor_msgs;
using hakoniwa.pdu.msgs.std_msgs;

namespace hakoniwa.pdu.msgs.drone_srv_msgs
{
    public class LiDARScanResponse
    {
        protected internal readonly IPdu _pdu;
        public IPdu GetPdu() { return _pdu; }

        public LiDARScanResponse(IPdu pdu)
        {
            _pdu = pdu;
        }
        public bool ok
        {
            get => _pdu.GetData<bool>("ok");
            set => _pdu.SetData("ok", value);
        }
        private PointCloud2 _point_cloud;
        public PointCloud2 point_cloud
        {
            get
            {
                if (_point_cloud == null)
                {
                    _point_cloud = new PointCloud2(_pdu.GetData<IPdu>("point_cloud"));
                }
                return _point_cloud;
            }
            set
            {
                _point_cloud = value;
                _pdu.SetData("point_cloud", value.GetPdu());
            }
        }
        private Pose _lidar_pose;
        public Pose lidar_pose
        {
            get
            {
                if (_lidar_pose == null)
                {
                    _lidar_pose = new Pose(_pdu.GetData<IPdu>("lidar_pose"));
                }
                return _lidar_pose;
            }
            set
            {
                _lidar_pose = value;
                _pdu.SetData("lidar_pose", value.GetPdu());
            }
        }
        public string message
        {
            get => _pdu.GetData<string>("message");
            set => _pdu.SetData("message", value);
        }
    }
}
