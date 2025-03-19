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
    public class MonitorCameraData
    {
        protected internal readonly IPdu _pdu;

        public MonitorCameraData(IPdu pdu)
        {
            _pdu = pdu;
        }
        public int request_id
        {
            get => _pdu.GetData<int>("request_id");
            set => _pdu.SetData("request_id", value);
        }
        public int image_data_length
        {
            get => _pdu.GetData<int>("image_data_length");
            set => _pdu.SetData("image_data_length", value);
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
                _pdu.SetData("image", value._pdu);
            }
        }
    }
}
