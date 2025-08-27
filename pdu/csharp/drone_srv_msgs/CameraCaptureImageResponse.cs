using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using hakoniwa.pdu.interfaces;
using hakoniwa.pdu.msgs.builtin_interfaces;
using hakoniwa.pdu.msgs.sensor_msgs;
using hakoniwa.pdu.msgs.std_msgs;

namespace hakoniwa.pdu.msgs.drone_srv_msgs
{
    public class CameraCaptureImageResponse
    {
        protected internal readonly IPdu _pdu;
        public IPdu GetPdu() { return _pdu; }

        public CameraCaptureImageResponse(IPdu pdu)
        {
            _pdu = pdu;
        }
        public bool ok
        {
            get => _pdu.GetData<bool>("ok");
            set => _pdu.SetData("ok", value);
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
        public string message
        {
            get => _pdu.GetData<string>("message");
            set => _pdu.SetData("message", value);
        }
    }
}
