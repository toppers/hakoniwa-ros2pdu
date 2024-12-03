using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using hakoniwa.pdu.interfaces;
using hakoniwa.pdu.msgs.builtin_interfaces;
using hakoniwa.pdu.msgs.std_msgs;

namespace hakoniwa.pdu.msgs.sensor_msgs
{
    public class Image
    {
        protected internal readonly IPdu _pdu;

        public Image(IPdu pdu)
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
        public string encoding
        {
            get => _pdu.GetData<string>("encoding");
            set => _pdu.SetData("encoding", value);
        }
        public byte is_bigendian
        {
            get => _pdu.GetData<byte>("is_bigendian");
            set => _pdu.SetData("is_bigendian", value);
        }
        public uint step
        {
            get => _pdu.GetData<uint>("step");
            set => _pdu.SetData("step", value);
        }
        public byte[] data
        {
            get => _pdu.GetDataArray<byte>("data");
            set => _pdu.SetData("data", value);
        }
    }
}
