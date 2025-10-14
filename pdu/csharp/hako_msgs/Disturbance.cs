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
        public IPdu GetPdu() { return _pdu; }

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
                _pdu.SetData("d_temp", value.GetPdu());
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
                _pdu.SetData("d_wind", value.GetPdu());
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
                _pdu.SetData("d_atm", value.GetPdu());
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
                _pdu.SetData("d_boundary", value.GetPdu());
            }
        }
        private DisturbanceUserCustom[] _d_user_custom;
        public DisturbanceUserCustom[] d_user_custom
        {
            get
            {
                if (_d_user_custom == null)
                {
                    var fieldPdus = _pdu.GetDataArray<IPdu>("d_user_custom");
                    _d_user_custom = new DisturbanceUserCustom[fieldPdus.Length];
                    DisturbanceUserCustom[] result = new DisturbanceUserCustom[fieldPdus.Length];
                    for (int i = 0; i < fieldPdus.Length; i++)
                    {
                        _d_user_custom[i] = new DisturbanceUserCustom(fieldPdus[i]);
                    }
                }
                return _d_user_custom;
            }
            set
            {
                _d_user_custom = new DisturbanceUserCustom[value.Length];
                IPdu[] fieldPdus = new IPdu[value.Length];
                for (int i = 0; i < value.Length; i++)
                {
                    fieldPdus[i] = value[i].GetPdu();
                    _d_user_custom[i] = value[i];
                }
                _pdu.SetData("d_user_custom", fieldPdus);
            }
        }
    }
}
