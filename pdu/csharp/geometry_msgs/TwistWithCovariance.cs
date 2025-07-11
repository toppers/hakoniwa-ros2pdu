using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using hakoniwa.pdu.interfaces;

namespace hakoniwa.pdu.msgs.geometry_msgs
{
    public class TwistWithCovariance
    {
        protected internal readonly IPdu _pdu;
        public IPdu GetPdu() { return _pdu; }

        public TwistWithCovariance(IPdu pdu)
        {
            _pdu = pdu;
        }
        private Twist _twist;
        public Twist twist
        {
            get
            {
                if (_twist == null)
                {
                    _twist = new Twist(_pdu.GetData<IPdu>("twist"));
                }
                return _twist;
            }
            set
            {
                _twist = value;
                _pdu.SetData("twist", value.GetPdu());
            }
        }
        public double[] covariance
        {
            get => _pdu.GetDataArray<double>("covariance");
            set => _pdu.SetData("covariance", value);
        }
    }
}
