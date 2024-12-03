using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using hakoniwa.pdu.interfaces;
using hakoniwa.pdu.msgs.geometry_msgs;

namespace hakoniwa.pdu.msgs.hako_msgs
{
    public class Collision
    {
        protected internal readonly IPdu _pdu;

        public Collision(IPdu pdu)
        {
            _pdu = pdu;
        }
        public bool collision
        {
            get => _pdu.GetData<bool>("collision");
            set => _pdu.SetData("collision", value);
        }
        public uint contact_num
        {
            get => _pdu.GetData<uint>("contact_num");
            set => _pdu.SetData("contact_num", value);
        }
        private Vector3 _relative_velocity;
        public Vector3 relative_velocity
        {
            get
            {
                if (_relative_velocity == null)
                {
                    _relative_velocity = new Vector3(_pdu.GetData<IPdu>("relative_velocity"));
                }
                return _relative_velocity;
            }
            set
            {
                _relative_velocity = value;
                _pdu.SetData("relative_velocity", value._pdu);
            }
        }
        private Point[] _contact_position;
        public Point[] contact_position
        {
            get
            {
                if (_contact_position == null)
                {
                    var fieldPdus = _pdu.GetDataArray<IPdu>("contact_position");
                    _contact_position = new Point[fieldPdus.Length];
                    Point[] result = new Point[fieldPdus.Length];
                    for (int i = 0; i < fieldPdus.Length; i++)
                    {
                        _contact_position[i] = new Point(fieldPdus[i]);
                    }
                }
                return _contact_position;
            }
            set
            {
                _contact_position = new Point[value.Length];
                IPdu[] fieldPdus = new IPdu[value.Length];
                for (int i = 0; i < value.Length; i++)
                {
                    fieldPdus[i] = value[i]._pdu;
                    _contact_position[i] = value[i];
                }
                _pdu.SetData("contact_position", fieldPdus);
            }
        }
        public double restitution_coefficient
        {
            get => _pdu.GetData<double>("restitution_coefficient");
            set => _pdu.SetData("restitution_coefficient", value);
        }
    }
}
