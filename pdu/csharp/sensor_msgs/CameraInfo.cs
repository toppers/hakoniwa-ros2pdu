using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using hakoniwa.pdu.interfaces;
using hakoniwa.pdu.msgs.builtin_interfaces;
using hakoniwa.pdu.msgs.std_msgs;

namespace hakoniwa.pdu.msgs.sensor_msgs
{
    public class CameraInfo
    {
        protected internal readonly IPdu _pdu;
        public IPdu GetPdu() { return _pdu; }

        public CameraInfo(IPdu pdu)
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
        public uint height
        {
            get => _pdu.GetData<uint>("height");
            set => _pdu.SetData("height", value);
        }
        public uint width
        {
            get => _pdu.GetData<uint>("width");
            set => _pdu.SetData("width", value);
        }
        public string distortion_model
        {
            get => _pdu.GetData<string>("distortion_model");
            set => _pdu.SetData("distortion_model", value);
        }
        public double[] d
        {
            get => _pdu.GetDataArray<double>("d");
            set => _pdu.SetData("d", value);
        }
        public double[] k
        {
            get => _pdu.GetDataArray<double>("k");
            set => _pdu.SetData("k", value);
        }
        public double[] r
        {
            get => _pdu.GetDataArray<double>("r");
            set => _pdu.SetData("r", value);
        }
        public double[] p
        {
            get => _pdu.GetDataArray<double>("p");
            set => _pdu.SetData("p", value);
        }
        public uint binning_x
        {
            get => _pdu.GetData<uint>("binning_x");
            set => _pdu.SetData("binning_x", value);
        }
        public uint binning_y
        {
            get => _pdu.GetData<uint>("binning_y");
            set => _pdu.SetData("binning_y", value);
        }
        private RegionOfInterest _roi;
        public RegionOfInterest roi
        {
            get
            {
                if (_roi == null)
                {
                    _roi = new RegionOfInterest(_pdu.GetData<IPdu>("roi"));
                }
                return _roi;
            }
            set
            {
                _roi = value;
                _pdu.SetData("roi", value.GetPdu());
            }
        }
    }
}
