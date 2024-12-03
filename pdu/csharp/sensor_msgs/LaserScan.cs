using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using hakoniwa.pdu.interfaces;
using hakoniwa.pdu.msgs.builtin_interfaces;
using hakoniwa.pdu.msgs.std_msgs;

namespace hakoniwa.pdu.msgs.sensor_msgs
{
    public class LaserScan
    {
        protected internal readonly IPdu _pdu;

        public LaserScan(IPdu pdu)
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
        public float angle_min
        {
            get => _pdu.GetData<float>("angle_min");
            set => _pdu.SetData("angle_min", value);
        }
        public float angle_max
        {
            get => _pdu.GetData<float>("angle_max");
            set => _pdu.SetData("angle_max", value);
        }
        public float angle_increment
        {
            get => _pdu.GetData<float>("angle_increment");
            set => _pdu.SetData("angle_increment", value);
        }
        public float time_increment
        {
            get => _pdu.GetData<float>("time_increment");
            set => _pdu.SetData("time_increment", value);
        }
        public float scan_time
        {
            get => _pdu.GetData<float>("scan_time");
            set => _pdu.SetData("scan_time", value);
        }
        public float range_min
        {
            get => _pdu.GetData<float>("range_min");
            set => _pdu.SetData("range_min", value);
        }
        public float range_max
        {
            get => _pdu.GetData<float>("range_max");
            set => _pdu.SetData("range_max", value);
        }
        public float[] ranges
        {
            get => _pdu.GetDataArray<float>("ranges");
            set => _pdu.SetData("ranges", value);
        }
        public float[] intensities
        {
            get => _pdu.GetDataArray<float>("intensities");
            set => _pdu.SetData("intensities", value);
        }
    }
}
