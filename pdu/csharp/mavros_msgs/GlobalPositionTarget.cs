using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using hakoniwa.pdu.interfaces;
using hakoniwa.pdu.msgs.builtin_interfaces;
using hakoniwa.pdu.msgs.geometry_msgs;
using hakoniwa.pdu.msgs.std_msgs;

namespace hakoniwa.pdu.msgs.mavros_msgs
{
    public class GlobalPositionTarget
    {
        protected internal readonly IPdu _pdu;
        public IPdu GetPdu() { return _pdu; }

        public GlobalPositionTarget(IPdu pdu)
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
                _pdu.SetData("header", value.GetPdu());
            }
        }
        public byte coordinate_frame
        {
            get => _pdu.GetData<byte>("coordinate_frame");
            set => _pdu.SetData("coordinate_frame", value);
        }
        public ushort type_mask
        {
            get => _pdu.GetData<ushort>("type_mask");
            set => _pdu.SetData("type_mask", value);
        }
        public double latitude
        {
            get => _pdu.GetData<double>("latitude");
            set => _pdu.SetData("latitude", value);
        }
        public double longitude
        {
            get => _pdu.GetData<double>("longitude");
            set => _pdu.SetData("longitude", value);
        }
        public float altitude
        {
            get => _pdu.GetData<float>("altitude");
            set => _pdu.SetData("altitude", value);
        }
        private Vector3 _velocity;
        public Vector3 velocity
        {
            get
            {
                if (_velocity == null)
                {
                    _velocity = new Vector3(_pdu.GetData<IPdu>("velocity"));
                }
                return _velocity;
            }
            set
            {
                _velocity = value;
                _pdu.SetData("velocity", value.GetPdu());
            }
        }
        private Vector3 _acceleration_or_force;
        public Vector3 acceleration_or_force
        {
            get
            {
                if (_acceleration_or_force == null)
                {
                    _acceleration_or_force = new Vector3(_pdu.GetData<IPdu>("acceleration_or_force"));
                }
                return _acceleration_or_force;
            }
            set
            {
                _acceleration_or_force = value;
                _pdu.SetData("acceleration_or_force", value.GetPdu());
            }
        }
        public float yaw
        {
            get => _pdu.GetData<float>("yaw");
            set => _pdu.SetData("yaw", value);
        }
        public float yaw_rate
        {
            get => _pdu.GetData<float>("yaw_rate");
            set => _pdu.SetData("yaw_rate", value);
        }
    }
}
