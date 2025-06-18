using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using hakoniwa.pdu.interfaces;
using hakoniwa.pdu.msgs.geometry_msgs;

namespace hakoniwa.pdu.msgs.hako_msgs
{
    public class DisturbanceBoundary
    {
        protected internal readonly IPdu _pdu;

        public DisturbanceBoundary(IPdu pdu)
        {
            _pdu = pdu;
        }
        private Point _boundary_point;
        public Point boundary_point
        {
            get
            {
                if (_boundary_point == null)
                {
                    _boundary_point = new Point(_pdu.GetData<IPdu>("boundary_point"));
                }
                return _boundary_point;
            }
            set
            {
                _boundary_point = value;
                _pdu.SetData("boundary_point", value._pdu);
            }
        }
        private Vector3 _boundary_normal;
        public Vector3 boundary_normal
        {
            get
            {
                if (_boundary_normal == null)
                {
                    _boundary_normal = new Vector3(_pdu.GetData<IPdu>("boundary_normal"));
                }
                return _boundary_normal;
            }
            set
            {
                _boundary_normal = value;
                _pdu.SetData("boundary_normal", value._pdu);
            }
        }
    }
}
