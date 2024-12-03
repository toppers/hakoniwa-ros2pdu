using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using hakoniwa.pdu.interfaces;

namespace hakoniwa.pdu.msgs.geometry_msgs
{
    public class Pose
    {
        protected internal readonly IPdu _pdu;

        public Pose(IPdu pdu)
        {
            _pdu = pdu;
        }
        private Point _position;
        public Point position
        {
            get
            {
                if (_position == null)
                {
                    _position = new Point(_pdu.GetData<IPdu>("position"));
                }
                return _position;
            }
            set
            {
                _position = value;
                _pdu.SetData("position", value._pdu);
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
    }
}
