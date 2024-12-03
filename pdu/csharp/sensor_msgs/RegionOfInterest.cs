using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using hakoniwa.pdu.interfaces;

namespace hakoniwa.pdu.msgs.sensor_msgs
{
    public class RegionOfInterest
    {
        protected internal readonly IPdu _pdu;

        public RegionOfInterest(IPdu pdu)
        {
            _pdu = pdu;
        }
        public uint x_offset
        {
            get => _pdu.GetData<uint>("x_offset");
            set => _pdu.SetData("x_offset", value);
        }
        public uint y_offset
        {
            get => _pdu.GetData<uint>("y_offset");
            set => _pdu.SetData("y_offset", value);
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
        public bool do_rectify
        {
            get => _pdu.GetData<bool>("do_rectify");
            set => _pdu.SetData("do_rectify", value);
        }
    }
}
