using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using hakoniwa.pdu.interfaces;
using hakoniwa.pdu.msgs.builtin_interfaces;
using hakoniwa.pdu.msgs.sensor_msgs;
using hakoniwa.pdu.msgs.std_msgs;

namespace hakoniwa.pdu.msgs.hako_msgs
{
    public class HakoCameraData
    {
        protected internal readonly IPdu _pdu;
        public IPdu GetPdu() { return _pdu; }

        public HakoCameraData(IPdu pdu)
        {
            _pdu = pdu;
        }
        public int request_id
        {
            get => _pdu.GetData<int>("request_id");
            set => _pdu.SetData("request_id", value);
        }
        private CompressedImage _image;
        public CompressedImage image
        {
            get
            {
                if (_image == null)
                {
                    _image = new CompressedImage(_pdu.GetData<IPdu>("image"));
                }
                return _image;
            }
            set
            {
                _image = value;
                _pdu.SetData("image", value.GetPdu());
            }
        }
    }
}
