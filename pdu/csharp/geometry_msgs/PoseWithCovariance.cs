using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using hakoniwa.pdu.interfaces;

namespace hakoniwa.pdu.msgs.geometry_msgs
{
    public class PoseWithCovariance
    {
        protected internal readonly IPdu _pdu;

        public PoseWithCovariance(IPdu pdu)
        {
            _pdu = pdu;
        }
        private Pose _pose;
        public Pose pose
        {
            get
            {
                if (_pose == null)
                {
                    _pose = new Pose(_pdu.GetData<IPdu>("pose"));
                }
                return _pose;
            }
            set
            {
                _pose = value;
                _pdu.SetData("pose", value._pdu);
            }
        }
        public double[] covariance
        {
            get => _pdu.GetDataArray<double>("covariance");
            set => _pdu.SetData("covariance", value);
        }
    }
}
