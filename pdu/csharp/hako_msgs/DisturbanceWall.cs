using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using hakoniwa.pdu.interfaces;
using hakoniwa.pdu.msgs.geometry_msgs;

namespace hakoniwa.pdu.msgs.hako_msgs
{
    public class DisturbanceWall
    {
        protected internal readonly IPdu _pdu;

        public DisturbanceWall(IPdu pdu)
        {
            _pdu = pdu;
        }
        private Point _wall_point;
        public Point wall_point
        {
            get
            {
                if (_wall_point == null)
                {
                    _wall_point = new Point(_pdu.GetData<IPdu>("wall_point"));
                }
                return _wall_point;
            }
            set
            {
                _wall_point = value;
                _pdu.SetData("wall_point", value._pdu);
            }
        }
        private Vector3 _wall_normal;
        public Vector3 wall_normal
        {
            get
            {
                if (_wall_normal == null)
                {
                    _wall_normal = new Vector3(_pdu.GetData<IPdu>("wall_normal"));
                }
                return _wall_normal;
            }
            set
            {
                _wall_normal = value;
                _pdu.SetData("wall_normal", value._pdu);
            }
        }
    }
}
