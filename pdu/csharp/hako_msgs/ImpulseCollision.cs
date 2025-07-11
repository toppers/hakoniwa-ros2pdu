using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using hakoniwa.pdu.interfaces;
using hakoniwa.pdu.msgs.geometry_msgs;

namespace hakoniwa.pdu.msgs.hako_msgs
{
    public class ImpulseCollision
    {
        protected internal readonly IPdu _pdu;
        public IPdu GetPdu() { return _pdu; }

        public ImpulseCollision(IPdu pdu)
        {
            _pdu = pdu;
        }
        public bool collision
        {
            get => _pdu.GetData<bool>("collision");
            set => _pdu.SetData("collision", value);
        }
        public bool is_target_static
        {
            get => _pdu.GetData<bool>("is_target_static");
            set => _pdu.SetData("is_target_static", value);
        }
        public double restitution_coefficient
        {
            get => _pdu.GetData<double>("restitution_coefficient");
            set => _pdu.SetData("restitution_coefficient", value);
        }
        private Point _self_contact_vector;
        public Point self_contact_vector
        {
            get
            {
                if (_self_contact_vector == null)
                {
                    _self_contact_vector = new Point(_pdu.GetData<IPdu>("self_contact_vector"));
                }
                return _self_contact_vector;
            }
            set
            {
                _self_contact_vector = value;
                _pdu.SetData("self_contact_vector", value.GetPdu());
            }
        }
        private Vector3 _normal;
        public Vector3 normal
        {
            get
            {
                if (_normal == null)
                {
                    _normal = new Vector3(_pdu.GetData<IPdu>("normal"));
                }
                return _normal;
            }
            set
            {
                _normal = value;
                _pdu.SetData("normal", value.GetPdu());
            }
        }
        private Point _target_contact_vector;
        public Point target_contact_vector
        {
            get
            {
                if (_target_contact_vector == null)
                {
                    _target_contact_vector = new Point(_pdu.GetData<IPdu>("target_contact_vector"));
                }
                return _target_contact_vector;
            }
            set
            {
                _target_contact_vector = value;
                _pdu.SetData("target_contact_vector", value.GetPdu());
            }
        }
        private Vector3 _target_velocity;
        public Vector3 target_velocity
        {
            get
            {
                if (_target_velocity == null)
                {
                    _target_velocity = new Vector3(_pdu.GetData<IPdu>("target_velocity"));
                }
                return _target_velocity;
            }
            set
            {
                _target_velocity = value;
                _pdu.SetData("target_velocity", value.GetPdu());
            }
        }
        private Vector3 _target_angular_velocity;
        public Vector3 target_angular_velocity
        {
            get
            {
                if (_target_angular_velocity == null)
                {
                    _target_angular_velocity = new Vector3(_pdu.GetData<IPdu>("target_angular_velocity"));
                }
                return _target_angular_velocity;
            }
            set
            {
                _target_angular_velocity = value;
                _pdu.SetData("target_angular_velocity", value.GetPdu());
            }
        }
        private Vector3 _target_euler;
        public Vector3 target_euler
        {
            get
            {
                if (_target_euler == null)
                {
                    _target_euler = new Vector3(_pdu.GetData<IPdu>("target_euler"));
                }
                return _target_euler;
            }
            set
            {
                _target_euler = value;
                _pdu.SetData("target_euler", value.GetPdu());
            }
        }
        private Vector3 _target_inertia;
        public Vector3 target_inertia
        {
            get
            {
                if (_target_inertia == null)
                {
                    _target_inertia = new Vector3(_pdu.GetData<IPdu>("target_inertia"));
                }
                return _target_inertia;
            }
            set
            {
                _target_inertia = value;
                _pdu.SetData("target_inertia", value.GetPdu());
            }
        }
        public double target_mass
        {
            get => _pdu.GetData<double>("target_mass");
            set => _pdu.SetData("target_mass", value);
        }
    }
}
