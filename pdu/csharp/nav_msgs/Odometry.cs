using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using hakoniwa.pdu.interfaces;
using hakoniwa.pdu.msgs.builtin_interfaces;
using hakoniwa.pdu.msgs.geometry_msgs;
using hakoniwa.pdu.msgs.std_msgs;

namespace hakoniwa.pdu.msgs.nav_msgs
{
    public class Odometry
    {
        protected internal readonly IPdu _pdu;

        public Odometry(IPdu pdu)
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
        public string child_frame_id
        {
            get => _pdu.GetData<string>("child_frame_id");
            set => _pdu.SetData("child_frame_id", value);
        }
        private PoseWithCovariance _pose;
        public PoseWithCovariance pose
        {
            get
            {
                if (_pose == null)
                {
                    _pose = new PoseWithCovariance(_pdu.GetData<IPdu>("pose"));
                }
                return _pose;
            }
            set
            {
                _pose = value;
                _pdu.SetData("pose", value._pdu);
            }
        }
        private TwistWithCovariance _twist;
        public TwistWithCovariance twist
        {
            get
            {
                if (_twist == null)
                {
                    _twist = new TwistWithCovariance(_pdu.GetData<IPdu>("twist"));
                }
                return _twist;
            }
            set
            {
                _twist = value;
                _pdu.SetData("twist", value._pdu);
            }
        }
    }
}
