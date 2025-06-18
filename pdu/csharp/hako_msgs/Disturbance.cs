using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using hakoniwa.pdu.interfaces;
using hakoniwa.pdu.msgs.geometry_msgs;

namespace hakoniwa.pdu.msgs.hako_msgs
{
    public class Disturbance
    {
        protected internal readonly IPdu _pdu;

        public Disturbance(IPdu pdu)
        {
            _pdu = pdu;
        }
        private DisturbanceTemperature _d_temp;
        public DisturbanceTemperature d_temp
        {
            get
            {
                if (_d_temp == null)
                {
                    _d_temp = new DisturbanceTemperature(_pdu.GetData<IPdu>("d_temp"));
                }
                return _d_temp;
            }
            set
            {
                _d_temp = value;
                _pdu.SetData("d_temp", value._pdu);
            }
        }
        private DisturbanceWind _d_wind;
        public DisturbanceWind d_wind
        {
            get
            {
                if (_d_wind == null)
                {
                    _d_wind = new DisturbanceWind(_pdu.GetData<IPdu>("d_wind"));
                }
                return _d_wind;
            }
            set
            {
                _d_wind = value;
                _pdu.SetData("d_wind", value._pdu);
            }
        }
        private DisturbanceAtm _d_atm;
        public DisturbanceAtm d_atm
        {
            get
            {
                if (_d_atm == null)
                {
                    _d_atm = new DisturbanceAtm(_pdu.GetData<IPdu>("d_atm"));
                }
                return _d_atm;
            }
            set
            {
                _d_atm = value;
                _pdu.SetData("d_atm", value._pdu);
            }
        }
        private DisturbanceBoundary _d_boundary;
        public DisturbanceBoundary d_boundary
        {
            get
            {
                if (_d_boundary == null)
                {
                    _d_boundary = new DisturbanceBoundary(_pdu.GetData<IPdu>("d_boundary"));
                }
                return _d_boundary;
            }
            set
            {
                _d_boundary = value;
                _pdu.SetData("d_boundary", value._pdu);
            }
        }
    }
}
