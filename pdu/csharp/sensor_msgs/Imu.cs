using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using hakoniwa.pdu.interfaces;
using hakoniwa.pdu.msgs.builtin_interfaces;
using hakoniwa.pdu.msgs.geometry_msgs;
using hakoniwa.pdu.msgs.std_msgs;

namespace hakoniwa.pdu.msgs.sensor_msgs
{
    public class Imu
    {
        protected internal readonly IPdu _pdu;

        public Imu(IPdu pdu)
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
        private Quaternion _orientation;
        public Quaternion orientation
        {
            get
            {
                if (_orientation == null)
                {
                    _orientation = new Quaternion(_pdu.GetData<IPdu>("orientation"));
                }
                return _orientation;
            }
            set
            {
                _orientation = value;
                _pdu.SetData("orientation", value._pdu);
            }
        }
        public double[] orientation_covariance
        {
            get => _pdu.GetDataArray<double>("orientation_covariance");
            set => _pdu.SetData("orientation_covariance", value);
        }
        private Vector3 _angular_velocity;
        public Vector3 angular_velocity
        {
            get
            {
                if (_angular_velocity == null)
                {
                    _angular_velocity = new Vector3(_pdu.GetData<IPdu>("angular_velocity"));
                }
                return _angular_velocity;
            }
            set
            {
                _angular_velocity = value;
                _pdu.SetData("angular_velocity", value._pdu);
            }
        }
        public double[] angular_velocity_covariance
        {
            get => _pdu.GetDataArray<double>("angular_velocity_covariance");
            set => _pdu.SetData("angular_velocity_covariance", value);
        }
        private Vector3 _linear_acceleration;
        public Vector3 linear_acceleration
        {
            get
            {
                if (_linear_acceleration == null)
                {
                    _linear_acceleration = new Vector3(_pdu.GetData<IPdu>("linear_acceleration"));
                }
                return _linear_acceleration;
            }
            set
            {
                _linear_acceleration = value;
                _pdu.SetData("linear_acceleration", value._pdu);
            }
        }
        public double[] linear_acceleration_covariance
        {
            get => _pdu.GetDataArray<double>("linear_acceleration_covariance");
            set => _pdu.SetData("linear_acceleration_covariance", value);
        }
    }
}
